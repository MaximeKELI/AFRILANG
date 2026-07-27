import 'dart:async';
import 'dart:io';

import 'package:file_picker/file_picker.dart';
import 'package:flutter/foundation.dart';
import 'package:path/path.dart' as p;

import '../ai/ai_assist_service.dart';
import '../ai/local_afr_suggest.dart';
import '../core/command_bus.dart';
import '../core/event_bus.dart';
import '../debug/debug_service.dart';
import '../editor/find_replace.dart';
import '../editor/path_name_rules.dart';
import '../editor/snippets.dart';
import '../editor/text_ops.dart';
import '../git/git_service.dart';
import '../lsp/lsp_client.dart';
import '../models/editor_tab.dart';
import '../models/problem_item.dart';
import '../models/workspace_node.dart';
import '../plugins/plugin_host.dart';
import '../project/project_service.dart';
import '../project/project_templates.dart';
import '../project/test_explorer.dart';
import '../project/workspace_model.dart';
import '../search/search_service.dart';
import '../services/afrilang_cli.dart';
import '../services/build_service.dart';
import '../services/file_service.dart';
import '../services/output_buffer.dart';
import '../services/process_env.dart';
import '../services/settings_store.dart';
import '../services/workspace_paths.dart';
import '../terminal/terminal_service.dart';
import '../theme/afriblock_theme.dart';

enum SidebarView {
  explorer,
  search,
  scm,
  run,
  debug,
  test,
  extensions,
  afrilang,
  ai,
}

enum BottomTab { problems, output, debugConsole, terminal, testResults }

enum OverlayMode { none, commandPalette, quickOpen, findReplace, goToLine, snippets }

class WorkbenchController extends ChangeNotifier {
  WorkbenchController({
    FileService? fileService,
    SettingsStore? settings,
  })  : files = fileService ?? FileService(),
        settings = settings ?? SettingsStore() {
    final store = this.settings;
    cli = AfrilangCli(resolveBinary: () => store.resolveAfrilangBinary());
    build = BuildService(resolveBinary: () => store.resolveAfrilangBinary());
    lsp = LspClient(
      onDiagnostics: (items) {
        problems
          ..clear()
          ..addAll(items);
        notifyListeners();
      },
      onTrace: (line) {
        if (store.lspTrace) appendOutput(line, channel: 'lsp');
      },
    );
  }

  final FileService files;
  final SettingsStore settings;
  final EventBus events = EventBus();
  final CommandBus commands = CommandBus();
  final ProjectService projects = ProjectService();
  final TestExplorerService tests = TestExplorerService();
  final GitService git = GitService();
  final SearchService search = SearchService();
  final DebugService debug = DebugService();
  final TerminalService terminals = TerminalService();
  final PluginHost plugins = PluginHost();
  final AiAssistService ai = AiAssistService();
  final WorkspaceModel workspace = WorkspaceModel();

  late final AfrilangCli cli;
  late final BuildService build;
  late final LspClient lsp;

  String? ghostSuggestion;
  int editorCaret = 0;
  Timer? _aiDebounce;
  int _aiSuggestGen = 0;

  bool ready = false;
  String? workspaceRoot;
  WorkspaceNode? rootNode;
  List<WorkspaceNode> folderRoots = [];
  bool blameEnabled = false;
  List<GitBlameLine> blameLines = [];
  Set<int> dirtyLines = {};
  List<SearchHit> referenceHits = [];
  String? gitCommitMessage;
  /// Last clicked explorer path (file or folder) — used as create target.
  String? explorerSelection;
  final List<EditorTab> tabs = [];
  int? activeTabIndex;

  /// Phase F: optional second editor group (split).
  bool splitEditor = false;
  int? secondaryTabIndex;

  SidebarView sidebarView = SidebarView.explorer;
  bool sidebarVisible = true;
  double sidebarWidth = 280;

  bool panelVisible = true;
  double panelHeight = 200;
  BottomTab bottomTab = BottomTab.output;

  final List<ProblemItem> problems = [];
  final OutputBuffer outputLog = OutputBuffer();
  final OutputBuffer lspLog = OutputBuffer();

  bool busy = false;
  /// Hover markdown/plaintext from LSP (shown above the editor).
  String? hoverInfo;
  Timer? _hoverDebounce;
  String? statusMessage;
  String? toolchainVersion;
  OverlayMode overlay = OverlayMode.none;

  String activeTargetId = 'debug';
  List<BuildTarget> get availableTargets => projects.targetsFor(projects.project);

  BuildTarget get activeTarget {
    final list = availableTargets;
    return list.firstWhere(
      (t) => t.id == activeTargetId,
      orElse: () => list.first,
    );
  }

  AfriThemeMode themeMode = AfriThemeMode.dark;

  List<OutlineSymbol> outline = [];
  List<SearchHit> searchHits = [];
  String searchQuery = '';

  /// In-file find state
  String findQuery = '';
  String replaceQuery = '';
  List<FindMatch> findMatches = [];
  int findIndex = 0;
  int? goToLineRequest;
  int? goToColumnRequest;

  final List<String> workspaceFiles = [];
  final List<String> recentFiles = [];

  EditorTab? get activeTab =>
      activeTabIndex == null || activeTabIndex! >= tabs.length
          ? null
          : tabs[activeTabIndex!];

  String get lspState => !lsp.isRunning
      ? 'LSP off'
      : (lsp.ready ? 'LSP ready' : 'LSP…');

  String get aiStatusLabel {
    if (!settings.aiEnabled) return 'AI off';
    if (ai.lastError != null) return 'AI err';
    if (ai.busy) return 'AI…';
    return 'AI on';
  }

  Future<void> init() async {
    debug.onChanged = () {
      notifyListeners();
    };
    await settings.load();
    themeMode = settings.themeMode;
    syncAiConfig();
    _registerCommands();
    plugins
      ..register(BuiltinAfrilangPlugin())
      ..register(BuiltinGitPlugin())
      ..register(BuiltinTerminalPlugin());
    await plugins.activateAll(PluginContext(commands: commands, workbench: this));
    await _probeToolchain();
    statusMessage = 'Ready';
    ready = true;
    notifyListeners();
  }

  void syncAiConfig() {
    ai.updateConfig(AiAssistConfig(
      enabled: settings.aiEnabled,
      inlineSuggest: settings.aiInlineSuggest,
      baseUrl: settings.aiBaseUrl,
      apiKey: settings.aiApiKey,
      model: settings.aiModel,
    ));
  }

  Future<void> enableLocalAi() async {
    settings.aiEnabled = true;
    settings.aiInlineSuggest = true;
    settings.aiModel = LocalAfrSuggest.modelId;
    await settings.saveAiSettings();
    syncAiConfig();
    statusMessage = 'IA locale afrilang-local activée';
    notifyListeners();
    scheduleInlineSuggest(immediate: true);
  }

  void _registerCommands() {
    commands.registerAll([
      IdeCommandDef(
        id: 'file.openFolder',
        label: 'File: Open Folder…',
        shortcut: 'Ctrl+K Ctrl+O',
        category: 'File',
        run: (wb) => wb.openFolder(),
      ),
      IdeCommandDef(
        id: 'file.openExamples',
        label: 'File: Open AFRILANG Examples',
        category: 'File',
        run: (wb) => wb.openAfrilangExamples(),
      ),
      IdeCommandDef(
        id: 'file.save',
        label: 'File: Save',
        shortcut: 'Ctrl+S',
        category: 'File',
        run: (wb) => wb.saveActive(),
      ),
      IdeCommandDef(
        id: 'file.newProject',
        label: 'File: New Project…',
        category: 'File',
        run: (wb) async {
          wb.statusMessage = 'Utilisez le bouton Nouveau projet (toolbar / welcome)';
          wb.notifyListeners();
        },
      ),
      IdeCommandDef(
        id: 'file.newAfr',
        label: 'File: New File…',
        category: 'File',
        run: (wb) async {
          wb.statusMessage = 'Utilisez le bouton Nouveau fichier (toolbar)';
          wb.notifyListeners();
        },
      ),
      IdeCommandDef(
        id: 'file.newFolder',
        label: 'File: New Folder…',
        category: 'File',
        run: (wb) async {
          wb.statusMessage = 'Utilisez le bouton Nouveau dossier (toolbar)';
          wb.notifyListeners();
        },
      ),
      IdeCommandDef(
        id: 'file.quickOpen',
        label: 'Go to File…',
        shortcut: 'Ctrl+P',
        category: 'Navigation',
        run: (wb) async => wb.showOverlay(OverlayMode.quickOpen),
      ),
      IdeCommandDef(
        id: 'edit.find',
        label: 'Edit: Find…',
        shortcut: 'Ctrl+F',
        category: 'Edit',
        run: (wb) async => wb.showOverlay(OverlayMode.findReplace),
      ),
      IdeCommandDef(
        id: 'edit.goToLine',
        label: 'Go to Line…',
        shortcut: 'Ctrl+G',
        category: 'Navigation',
        run: (wb) async => wb.showOverlay(OverlayMode.goToLine),
      ),
      IdeCommandDef(
        id: 'edit.snippets',
        label: 'Insert Snippet…',
        category: 'Edit',
        run: (wb) async => wb.showOverlay(OverlayMode.snippets),
      ),
      IdeCommandDef(
        id: 'edit.duplicateLine',
        label: 'Edit: Duplicate Line',
        category: 'Edit',
        run: (wb) async => wb.duplicateActiveLine(),
      ),
      IdeCommandDef(
        id: 'edit.toggleComment',
        label: 'Edit: Toggle Line Comment',
        category: 'Edit',
        run: (wb) async => wb.toggleActiveComment(),
      ),
      IdeCommandDef(
        id: 'afrilang.fmt',
        label: 'AFRILANG: Format Document',
        category: 'AFRILANG',
        run: (wb) => wb.formatActive(),
      ),
      IdeCommandDef(
        id: 'afrilang.lint',
        label: 'AFRILANG: Lint Workspace',
        category: 'AFRILANG',
        run: (wb) => wb.lintWorkspace(),
      ),
      IdeCommandDef(
        id: 'workbench.commandPalette',
        label: 'Show Command Palette',
        shortcut: 'Ctrl+Shift+P',
        category: 'View',
        run: (wb) async => wb.showOverlay(OverlayMode.commandPalette),
      ),
      IdeCommandDef(
        id: 'afrilang.build',
        label: 'AFRILANG: Build Active Target',
        shortcut: 'Ctrl+Shift+B',
        category: 'AFRILANG',
        run: (wb) => wb.buildActiveTarget(),
      ),
      IdeCommandDef(
        id: 'afrilang.run',
        label: 'AFRILANG: Run',
        shortcut: 'F5',
        category: 'AFRILANG',
        run: (wb) => wb.runActive(),
      ),
      IdeCommandDef(
        id: 'afrilang.stop',
        label: 'AFRILANG: Stop',
        shortcut: 'Shift+F5',
        category: 'AFRILANG',
        run: (wb) => wb.stopCli(),
      ),
      IdeCommandDef(
        id: 'afrilang.check',
        label: 'AFRILANG: Check File',
        category: 'AFRILANG',
        run: (wb) => wb.checkActive(),
      ),
      IdeCommandDef(
        id: 'afrilang.debug',
        label: 'AFRILANG: Start Debugging',
        shortcut: 'F6',
        category: 'AFRILANG',
        run: (wb) => wb.startDebug(),
      ),
      IdeCommandDef(
        id: 'debug.continue',
        label: 'Debug: Continue',
        shortcut: 'F5',
        category: 'Debug',
        run: (wb) => wb.debugContinue(),
      ),
      IdeCommandDef(
        id: 'debug.stepOver',
        label: 'Debug: Step Over',
        shortcut: 'F10',
        category: 'Debug',
        run: (wb) => wb.debugStepOver(),
      ),
      IdeCommandDef(
        id: 'debug.stepInto',
        label: 'Debug: Step Into',
        shortcut: 'F11',
        category: 'Debug',
        run: (wb) => wb.debugStepInto(),
      ),
      IdeCommandDef(
        id: 'debug.stepOut',
        label: 'Debug: Step Out',
        shortcut: 'Shift+F11',
        category: 'Debug',
        run: (wb) => wb.debugStepOut(),
      ),
      IdeCommandDef(
        id: 'debug.stop',
        label: 'Debug: Stop',
        category: 'Debug',
        run: (wb) => wb.stopDebug(),
      ),
      IdeCommandDef(
        id: 'editor.gotoDefinition',
        label: 'Go to Definition',
        shortcut: 'F12',
        category: 'Navigation',
        run: (wb) => wb.goToDefinitionAtCaret(),
      ),
      IdeCommandDef(
        id: 'editor.renameSymbol',
        label: 'Rename Symbol…',
        shortcut: 'F2',
        category: 'Edit',
        run: (wb) async {
          wb.statusMessage = 'Utilisez F2 / Edit → Rename Symbol';
          wb.notifyListeners();
        },
      ),
      IdeCommandDef(
        id: 'editor.findReferences',
        label: 'Find References',
        category: 'Navigation',
        run: (wb) => wb.findReferencesAtCaret(),
      ),
      IdeCommandDef(
        id: 'git.commit',
        label: 'Git: Commit',
        category: 'Git',
        run: (wb) async {
          final msg = wb.gitCommitMessage?.trim() ?? '';
          if (msg.isEmpty) {
            wb.statusMessage = 'Entrez un message de commit dans Source Control';
            wb.notifyListeners();
            return;
          }
          await wb.commitWithMessage(msg);
        },
      ),
      IdeCommandDef(
        id: 'git.showDiff',
        label: 'Git: Show Diff',
        category: 'Git',
        run: (wb) => wb.showActiveDiff(),
      ),
      IdeCommandDef(
        id: 'git.toggleBlame',
        label: 'Git: Toggle Blame',
        category: 'Git',
        run: (wb) => wb.toggleBlame(),
      ),
      IdeCommandDef(
        id: 'file.addFolderToWorkspace',
        label: 'File: Add Folder to Workspace…',
        category: 'File',
        run: (wb) => wb.addFolderToWorkspace(),
      ),
      IdeCommandDef(
        id: 'editor.showHover',
        label: 'Show Hover Info',
        category: 'Navigation',
        run: (wb) async => wb.refreshHoverAtCaret(immediate: true),
      ),
      IdeCommandDef(
        id: 'view.togglePanel',
        label: 'View: Toggle Panel',
        shortcut: 'Ctrl+J',
        category: 'View',
        run: (wb) async => wb.togglePanel(),
      ),
      IdeCommandDef(
        id: 'view.splitEditor',
        label: 'View: Split Editor',
        category: 'View',
        run: (wb) async => wb.toggleSplit(),
      ),
      IdeCommandDef(
        id: 'view.closeEditor',
        label: 'View: Close Editor',
        shortcut: 'Ctrl+W',
        category: 'View',
        run: (wb) async => wb.closeActiveTab(),
      ),
      IdeCommandDef(
        id: 'terminal.new',
        label: 'Terminal: Create New Terminal',
        category: 'Terminal',
        run: (wb) async => wb.openTerminal(),
      ),
      IdeCommandDef(
        id: 'theme.toggle',
        label: 'Preferences: Toggle Color Theme',
        category: 'Preferences',
        run: (wb) async => wb.cycleTheme(),
      ),
      IdeCommandDef(
        id: 'preferences.toolchain',
        label: 'Preferences: AFRILANG Toolchain…',
        category: 'Preferences',
        run: (wb) async {
          wb.statusMessage = 'Open Settings from the gear / toolbar';
          wb.notifyListeners();
        },
      ),
      IdeCommandDef(
        id: 'ai.triggerSuggest',
        label: 'AI: Trigger Inline Suggest',
        category: 'AI',
        run: (wb) async => wb.triggerInlineSuggest(immediate: true),
      ),
      IdeCommandDef(
        id: 'ai.accept',
        label: 'AI: Accept Suggestion',
        shortcut: 'Tab',
        category: 'AI',
        run: (wb) async => wb.acceptGhostSuggestion(),
      ),
      IdeCommandDef(
        id: 'ai.reject',
        label: 'AI: Reject Suggestion',
        shortcut: 'Esc',
        category: 'AI',
        run: (wb) async => wb.rejectGhostSuggestion(),
      ),
      IdeCommandDef(
        id: 'ai.toggleChat',
        label: 'AI: Toggle Chat',
        category: 'AI',
        run: (wb) async => wb.toggleAiChat(),
      ),
    ]);
  }

  Future<void> refreshToolchain() async {
    await _probeToolchain();
    notifyListeners();
  }

  Future<void> _probeToolchain() async {
    final bin = await settings.resolveAfrilangBinary();
    if (bin == null) {
      toolchainVersion = null;
      return;
    }
    try {
      final r = await Process.run(
        bin,
        ['version'],
        environment: ProcessEnv.forHostToolchain(),
      );
      toolchainVersion = ((r.stdout as String) + (r.stderr as String))
          .trim()
          .split('\n')
          .first;
    } catch (_) {
      toolchainVersion = bin;
    }
  }

  void showOverlay(OverlayMode mode) {
    overlay = mode;
    notifyListeners();
  }

  void hideOverlay() {
    overlay = OverlayMode.none;
    notifyListeners();
  }

  /// Public UI refresh for widgets (notifyListeners is protected).
  void refresh() => notifyListeners();

  void setSidebarView(SidebarView view) {
    if (sidebarView == view && sidebarVisible) {
      sidebarVisible = false;
    } else {
      sidebarView = view;
      sidebarVisible = true;
    }
    notifyListeners();
  }

  void setSidebarWidth(double w) {
    sidebarWidth = w.clamp(180, 520);
    notifyListeners();
  }

  void setPanelHeight(double h) {
    panelHeight = h.clamp(120, 520);
    notifyListeners();
  }

  void togglePanel() {
    panelVisible = !panelVisible;
    notifyListeners();
  }

  void setBottomTab(BottomTab tab) {
    bottomTab = tab;
    panelVisible = true;
    notifyListeners();
  }

  void setActiveTarget(String id) {
    activeTargetId = id;
    notifyListeners();
  }

  void toggleSplit() {
    splitEditor = !splitEditor;
    if (splitEditor && secondaryTabIndex == null && tabs.isNotEmpty) {
      secondaryTabIndex = activeTabIndex;
    }
    notifyListeners();
  }

  void setSecondaryTab(int index) {
    secondaryTabIndex = index;
    notifyListeners();
  }

  Future<void> refreshTests() async {
    await tests.discover(workspaceRoot);
    notifyListeners();
  }

  void cycleTheme() {
    themeMode = switch (themeMode) {
      AfriThemeMode.dark => AfriThemeMode.light,
      AfriThemeMode.light => AfriThemeMode.highContrast,
      AfriThemeMode.highContrast => AfriThemeMode.dark,
    };
    settings.themeMode = themeMode;
    settings.saveTheme();
    notifyListeners();
  }

  Future<void> openFolder([String? path]) async {
    String? folder = path;
    if (folder != null && folder.isNotEmpty) {
      final dir = Directory(folder);
      if (!await dir.exists()) {
        statusMessage = 'Dossier introuvable: $folder';
        notifyListeners();
        return;
      }
    } else {
      folder = await FilePicker.platform.getDirectoryPath(
        dialogTitle: 'Open Folder — AFRIBLOCK',
      );
    }
    if (folder == null) return;

    final picked = folder;
    folder = await resolveWorkspacePath(folder);
    final portal = isDocumentPortalPath(picked) || isDocumentPortalPath(folder);

    try {
      final loaded = await WorkspaceModel.loadBeside(folder);
      if (loaded != null && loaded.folders.isNotEmpty) {
        workspace.folders
          ..clear()
          ..addAll(loaded.folders);
        workspace.activeIndex = loaded.activeIndex.clamp(0, loaded.folders.length - 1);
      } else {
        workspace.replaceAll([folder]);
      }
      await _reloadFolderRoots();
      workspaceRoot = workspace.primaryPath;
      explorerSelection = workspaceRoot;
      final primary = workspaceRoot!;
      await projects.detect(primary);
      try {
        await settings.pushRecent(primary);
      } catch (_) {
        // SharedPreferences unavailable in some test / headless contexts.
      }
      await _indexAllFolders();
      await tests.discover(primary);
      await git.refresh(primary);
      await _startLsp(primary);
      await workspace.save();
      events.emit(WorkspaceOpenedEvent(primary));
      final proj = projects.project;
      statusMessage = proj == null
          ? 'Opened $primary (no afrilang.toml)'
          : 'Project ${proj.name} — ${proj.main ?? "no main"}';
      appendOutput(
        proj == null
            ? 'Opened workspace: $primary\n'
            : 'Opened project ${proj.name} ($primary)\nmain=${proj.main} output=${proj.output}\n',
      );
      if (portal) {
        final examples = suggestAfrilangExamplesDir(
          await settings.resolveAfrilangBinary(),
        );
        appendOutput(
          'Attention: ce dossier passe par le portail documents '
          '(/run/user/.../doc/) — chemins éphémères, builds souvent cassés.\n'
          'Préférez un chemin réel (ex. ${examples ?? "~/…/AFRILANG/examples"}).\n',
        );
        statusMessage =
            'Portail documents détecté — ouvrez le vrai dossier examples';
      }
      notifyListeners();
    } catch (e) {
      statusMessage = 'Open failed: $e';
      appendOutput('Open failed: $e\n');
      notifyListeners();
    }
  }

  Future<void> _reloadFolderRoots() async {
    final trees = <WorkspaceNode>[];
    for (final f in workspace.folders) {
      try {
        trees.add(await files.loadTree(f.path));
      } catch (_) {}
    }
    folderRoots = trees;
    rootNode = trees.isEmpty ? null : trees.first;
    workspaceRoot = workspace.primaryPath;
  }

  Future<void> _indexAllFolders() async {
    workspaceFiles.clear();
    for (final f in workspace.folders) {
      await _indexFiles(f.path, append: true);
    }
  }

  Future<void> addFolderToWorkspace([String? path]) async {
    String? folder = path;
    if (folder == null || folder.isEmpty) {
      folder = await FilePicker.platform.getDirectoryPath(
        dialogTitle: 'Add Folder to Workspace — AFRIBLOCK',
      );
    }
    if (folder == null) return;
    folder = await resolveWorkspacePath(folder);
    if (!await Directory(folder).exists()) {
      statusMessage = 'Dossier introuvable: $folder';
      notifyListeners();
      return;
    }
    if (workspace.isEmpty) {
      await openFolder(folder);
      return;
    }
    workspace.addFolder(folder);
    await _reloadFolderRoots();
    await _indexAllFolders();
    await workspace.save();
    statusMessage = 'Added folder ${p.basename(folder)}';
    notifyListeners();
  }

  Future<void> saveWorkspace() async {
    await workspace.save();
    statusMessage = 'Workspace saved';
    notifyListeners();
  }

  /// Opens the toolchain `examples/` directory (real path, not portal).
  Future<void> openAfrilangExamples() async {
    final bin = await settings.resolveAfrilangBinary();
    final examples = suggestAfrilangExamplesDir(bin);
    if (examples == null) {
      statusMessage =
          'Dossier examples introuvable. Définissez le chemin afrilang.';
      notifyListeners();
      return;
    }
    await openFolder(examples);
  }

  /// Creates `parent/name/` with afrilang.toml + src/main.afr, then opens it.
  Future<String> createNewProject({
    required String name,
    required String parentDir,
    String templateId = 'app',
  }) async {
    final err = PathNameRules.validateSegment(name, isFolder: true);
    if (err != null) throw StateError(err);
    final parent = Directory(parentDir);
    if (!await parent.exists()) {
      await parent.create(recursive: true);
    }
    final root = p.normalize(p.join(parentDir, name));
    if (await Directory(root).exists()) {
      throw StateError('Le dossier existe déjà: $root');
    }
    await Directory(p.join(root, 'src')).create(recursive: true);
    final tmpl = projectTemplateById(templateId);
    final toml = '''
name = "$name"
version = "0.1.0"
main = "src/main.afr"
output = "build/$name"
description = "Projet créé avec AFRIBLOCK"
${tmpl.tomlExtra}''';
    await files.writeFile(p.join(root, 'afrilang.toml'), toml);
    await files.writeFile(
      p.join(root, 'src', 'main.afr'),
      expandProjectTemplate(tmpl.mainSource, name),
    );
    if (tmpl.id == 'test') {
      await Directory(p.join(root, 'tests')).create(recursive: true);
      await files.writeFile(
        p.join(root, 'tests', 'smoke.afr'),
        '// smoke\nsay add(1, 1)\n',
      );
    }
    await openFolder(root);
    statusMessage = 'Projet créé: $name (${tmpl.label})';
    notifyListeners();
    return root;
  }

  /// In-memory buffer (not yet on disk). Save will ask to materialize.
  void openUntitledBuffer() {
    final path = p.join(
      workspaceRoot ?? Directory.systemTemp.path,
      'untitled_${DateTime.now().millisecondsSinceEpoch}.afr',
    );
    final tab = EditorTab(
      path: path,
      content: '// Untitled\nsay "Hello AFRIBLOCK"\n',
    );
    // Keep dirty so user must save intentionally.
    tab.savedContent = '';
    tab.dirty = true;
    tabs.add(tab);
    activeTabIndex = tabs.length - 1;
    statusMessage = 'Fichier temporaire — enregistrez avec Ctrl+S';
    notifyListeners();
  }

  Future<void> _indexFiles(String root, {bool append = false}) async {
    if (!append) workspaceFiles.clear();
    final dir = Directory(root);
    await for (final ent in dir.list(recursive: true, followLinks: false)) {
      if (ent is! File) continue;
      final path = ent.path;
      if (path.contains('${p.separator}.git${p.separator}')) continue;
      if (path.contains('${p.separator}build${p.separator}')) continue;
      if (path.contains('${p.separator}.dart_tool${p.separator}')) continue;
      workspaceFiles.add(path);
      if (workspaceFiles.length > 8000) break;
    }
  }

  Future<void> _startLsp(String root) async {
    final bin = await settings.resolveAfrilangBinary();
    if (bin == null) return;
    try {
      await lsp.start(bin, rootUri: Directory(root).uri.toString());
      statusMessage = 'LSP started';
    } catch (e) {
      appendOutput('LSP failed to start: $e\n', channel: 'lsp');
    }
  }

  void toggleExpand(WorkspaceNode node) {
    if (!node.isDirectory) return;
    node.expanded = !node.expanded;
    explorerSelection = node.path;
    notifyListeners();
  }

  void selectExplorerPath(String path, {required bool isDirectory}) {
    explorerSelection = path;
    notifyListeners();
  }

  /// Directory where New File / New Folder should land.
  String createTargetDirectory() {
    final root = workspaceRoot;
    if (root == null) return '.';
    final sel = explorerSelection;
    if (sel == null) return root;
    final asDir = Directory(sel);
    if (asDir.existsSync()) return sel;
    return File(sel).parent.path;
  }

  Future<void> refreshExplorer() async {
    if (workspace.folders.isEmpty) {
      final root = workspaceRoot;
      if (root == null) return;
      workspace.replaceAll([root]);
    }
    final expanded = <String>{};
    void collect(WorkspaceNode? n) {
      if (n == null) return;
      if (n.isDirectory && n.expanded) expanded.add(n.path);
      for (final c in n.children) {
        collect(c);
      }
    }

    for (final r in folderRoots) {
      collect(r);
    }
    collect(rootNode);
    await _reloadFolderRoots();
    void restore(WorkspaceNode n) {
      if (expanded.contains(n.path)) n.expanded = true;
      for (final c in n.children) {
        restore(c);
      }
    }

    for (final r in folderRoots) {
      restore(r);
    }
    await _indexAllFolders();
    notifyListeners();
  }

  Future<void> createFileInWorkspace(
    String rawName, {
    String? parentDir,
    bool preferAfr = true,
  }) async {
    final root = workspaceRoot;
    if (root == null) throw StateError('Open a folder first');
    final parent = parentDir ?? createTargetDirectory();
    final err = PathNameRules.validateSegment(rawName, isFolder: false);
    if (err != null) throw StateError(err);
    final name = PathNameRules.ensureAfrExtension(rawName, forceAfr: preferAfr);
    final path = PathNameRules.joinUnder(parent, name);
    final normRoot = p.normalize(root);
    final normPath = p.normalize(path);
    if (!normPath.startsWith('$normRoot${p.separator}') && normPath != normRoot) {
      throw StateError('Path outside workspace');
    }
    const starter = '// New AFRILANG file\nsay "Hello AFRIBLOCK"\n';
    final content = name.endsWith('.afr') ? starter : '';
    await files.createFile(path, content: content);
    await refreshExplorer();
    await openFile(path);
    statusMessage = 'Created ${relativePath(path)}';
    notifyListeners();
  }

  Future<void> createFolderInWorkspace(String rawName, {String? parentDir}) async {
    final root = workspaceRoot;
    if (root == null) throw StateError('Open a folder first');
    final parent = parentDir ?? createTargetDirectory();
    final err = PathNameRules.validateSegment(rawName, isFolder: true);
    if (err != null) throw StateError(err);
    final path = PathNameRules.joinUnder(parent, rawName);
    final normRoot = p.normalize(root);
    final normPath = p.normalize(path);
    if (!normPath.startsWith(normRoot + p.separator) && normPath != normRoot) {
      throw StateError('Path outside workspace');
    }
    await files.createDirectory(path);
    explorerSelection = path;
    await refreshExplorer();
    statusMessage = 'Created folder ${relativePath(path)}';
    notifyListeners();
  }

  @Deprecated('Use createFileInWorkspace via dialog')
  Future<void> createNewAfrFile() async {
    await createFileInWorkspace('untitled.afr');
  }

  Future<void> openFile(String path, {int? line, int? column}) async {
    var resolved = path;
    if (!p.isAbsolute(resolved) && workspaceRoot != null) {
      resolved = p.normalize(p.join(workspaceRoot!, resolved));
    }
    final existing = tabs.indexWhere((t) => t.path == resolved);
    if (existing >= 0) {
      activeTabIndex = existing;
    } else {
      try {
        final content = await files.readFile(resolved);
        final tab = EditorTab(path: resolved, content: content)..markSaved();
        tabs.add(tab);
        activeTabIndex = tabs.length - 1;
        await lsp.didOpen(File(resolved).uri.toString(), content);
      } catch (e) {
        statusMessage = 'Cannot open: $e';
        notifyListeners();
        return;
      }
    }
    await refreshOutline();
    recentFiles
      ..remove(resolved)
      ..insert(0, resolved);
    if (recentFiles.length > 20) {
      recentFiles.removeRange(20, recentFiles.length);
    }
    if (line != null) {
      goToLineRequest = line;
      goToColumnRequest = column;
    }
    statusMessage = line == null ? resolved : '$resolved:$line';
    notifyListeners();
  }

  Future<void> refreshOutline() async {
    final tab = activeTab;
    if (tab == null) {
      outline = [];
      return;
    }
    final uri = File(tab.path).uri.toString();
    final symbols = await lsp.documentSymbol(uri);
    if (symbols.isNotEmpty) {
      outline = symbols.map((s) {
        final name = s['name']?.toString() ?? '?';
        final range = (s['range'] ?? s['location']?['range']) as Map?;
        final start = range?['start'] as Map?;
        final line = ((start?['line'] as num?)?.toInt() ?? 0) + 1;
        return OutlineSymbol(name: name, line: line, kind: s['kind']?.toString() ?? '');
      }).toList();
    } else {
      outline = SymbolIndex.scan(tab.content);
    }
  }

  void selectTab(int index) {
    if (index < 0 || index >= tabs.length) return;
    activeTabIndex = index;
    refreshOutline();
    notifyListeners();
  }

  void closeTab(int index) {
    if (index < 0 || index >= tabs.length) return;
    final path = tabs[index].path;
    lsp.didClose(File(path).uri.toString());
    tabs.removeAt(index);
    if (tabs.isEmpty) {
      activeTabIndex = null;
      outline = [];
    } else if (activeTabIndex != null) {
      if (activeTabIndex! >= tabs.length) {
        activeTabIndex = tabs.length - 1;
      } else if (index < activeTabIndex!) {
        activeTabIndex = activeTabIndex! - 1;
      }
    }
    notifyListeners();
  }

  void closeActiveTab() {
    if (activeTabIndex != null) closeTab(activeTabIndex!);
  }

  void updateActiveContent(String content, {bool external = false}) {
    final tab = activeTab;
    if (tab == null) return;
    final wasDirty = tab.dirty;
    final hadGhost = ghostSuggestion != null;
    if (external) {
      tab.applyExternalEdit(content);
    } else {
      tab.applyEdit(content);
    }
    lsp.didChange(
      File(tab.path).uri.toString(),
      content,
      DateTime.now().millisecondsSinceEpoch,
    );
    ghostSuggestion = null;
    // Avoid rebuild-on-every-keystroke (was racing the TextField and wiping edits).
    if (external || wasDirty != tab.dirty || hadGhost) {
      notifyListeners();
    }
    scheduleInlineSuggest();
  }

  void onEditorCaretChanged(int offset) {
    editorCaret = offset;
    scheduleInlineSuggest();
    refreshHoverAtCaret();
  }

  void refreshHoverAtCaret({bool immediate = false}) {
    _hoverDebounce?.cancel();
    void run() async {
      final tab = activeTab;
      if (tab == null || !tab.path.toLowerCase().endsWith('.afr')) {
        if (hoverInfo != null) {
          hoverInfo = null;
          notifyListeners();
        }
        return;
      }
      final pos = TextOps.lineColAt(tab.content, editorCaret);
      String? text;
      if (lsp.ready) {
        text = await lsp.hover(
          File(tab.path).uri.toString(),
          pos.line,
          pos.character,
        );
      }
      if (text == null || text.isEmpty) {
        final word = TextOps.wordAt(tab.content, editorCaret);
        if (word.isNotEmpty) {
          final local = SymbolIndex.scan(tab.content)
              .where((s) => s.name == word)
              .toList();
          if (local.isNotEmpty) {
            text = '**${local.first.name}** — ${local.first.kind.trim()} (line ${local.first.line})';
          }
        }
      }
      if (hoverInfo != text) {
        hoverInfo = text;
        notifyListeners();
      }
    }

    if (immediate) {
      run();
    } else {
      _hoverDebounce = Timer(const Duration(milliseconds: 350), run);
    }
  }

  Future<void> goToDefinitionAtCaret() async {
    final tab = activeTab;
    if (tab == null) return;
    final pos = TextOps.lineColAt(tab.content, editorCaret);
    LspLocation? loc;
    if (lsp.ready) {
      loc = await lsp.definition(
        File(tab.path).uri.toString(),
        pos.line,
        pos.character,
      );
    }
    if (loc != null) {
      final path = loc.uri.startsWith('file://')
          ? Uri.parse(loc.uri).toFilePath()
          : loc.uri;
      await openFile(path, line: loc.line, column: loc.column);
      statusMessage = 'Definition → ${relativePath(path)}:${loc.line}';
      notifyListeners();
      return;
    }
    final word = TextOps.wordAt(tab.content, editorCaret);
    if (word.isEmpty) {
      statusMessage = 'No definition';
      notifyListeners();
      return;
    }
    await refreshOutline();
    final hit = outline.where((s) => s.name == word).toList();
    if (hit.isEmpty) {
      statusMessage = 'No definition for "$word"';
      notifyListeners();
      return;
    }
    requestGoToLine(hit.first.line);
    statusMessage = 'Definition → ${hit.first.name}:${hit.first.line}';
    notifyListeners();
  }

  bool get cliRunning => build.isRunning;

  Future<void> stopCli() async {
    if (!build.isRunning && !busy) {
      statusMessage = 'Nothing to stop';
      notifyListeners();
      return;
    }
    statusMessage = 'Stopping…';
    notifyListeners();
    await build.cancel();
  }

  /// Send a line to the active Run/Build process stdin.
  void writeCliStdin(String line) {
    if (!build.writeStdin(line)) {
      statusMessage = 'No running process for stdin';
      notifyListeners();
      return;
    }
    outputLog.writeln('← $line');
    notifyListeners();
  }

  void clearGhostSuggestion({bool notify = true}) {
    if (ghostSuggestion == null) return;
    ghostSuggestion = null;
    if (notify) notifyListeners();
  }

  void rejectGhostSuggestion() {
    clearGhostSuggestion();
  }

  /// Accept ghost when triggered from command palette (editor Tab handles insert itself).
  void acceptGhostSuggestion() {
    final ghost = ghostSuggestion;
    final tab = activeTab;
    if (ghost == null || ghost.isEmpty || tab == null) return;
    final content = tab.content;
    final c = editorCaret.clamp(0, content.length);
    final next = content.substring(0, c) + ghost + content.substring(c);
    editorCaret = c + ghost.length;
    ghostSuggestion = null;
    tab.applyExternalEdit(next);
    lsp.didChange(
      File(tab.path).uri.toString(),
      next,
      DateTime.now().millisecondsSinceEpoch,
    );
    notifyListeners();
    scheduleInlineSuggest();
  }

  void onGhostAcceptedFromEditor() {
    clearGhostSuggestion();
  }

  void toggleAiChat() {
    if (sidebarView == SidebarView.ai && sidebarVisible) {
      sidebarVisible = false;
    } else {
      sidebarView = SidebarView.ai;
      sidebarVisible = true;
    }
    notifyListeners();
  }

  void scheduleInlineSuggest({bool immediate = false}) {
    _aiDebounce?.cancel();
    if (!settings.aiEnabled || !settings.aiInlineSuggest) {
      clearGhostSuggestion();
      return;
    }
    final delay = immediate ? Duration.zero : const Duration(milliseconds: 400);
    _aiDebounce = Timer(delay, () => unawaited(triggerInlineSuggest()));
  }

  Future<void> triggerInlineSuggest({bool immediate = false}) async {
    if (immediate) {
      _aiDebounce?.cancel();
    }
    final tab = activeTab;
    if (tab == null || !settings.aiEnabled || !settings.aiInlineSuggest) {
      clearGhostSuggestion();
      return;
    }
    final gen = ++_aiSuggestGen;
    final path = tab.path;
    final content = tab.content;
    final caret = editorCaret.clamp(0, content.length);
    final suggestion = await ai.propose(path: path, content: content, caret: caret);
    if (gen != _aiSuggestGen) return;
    if (activeTab?.path != path) return;
    ghostSuggestion = (suggestion == null || suggestion.isEmpty) ? null : suggestion;
    notifyListeners();
  }

  Future<void> sendAiChat(String message, {bool includeFile = false}) async {
    final tab = activeTab;
    final ctx = includeFile && tab != null
        ? 'File: ${tab.path}\n${tab.content}'
        : null;
    try {
      await ai.chat(message, fileContext: ctx);
      statusMessage = 'AI reply ready';
    } catch (e) {
      statusMessage = 'AI: $e';
    }
    notifyListeners();
  }

  void insertAiCodeIntoEditor(String code) {
    final tab = activeTab;
    if (tab == null) return;
    final content = tab.content;
    final c = editorCaret.clamp(0, content.length);
    final insert = code.endsWith('\n') ? code : '$code\n';
    final next = content.substring(0, c) + insert + content.substring(c);
    editorCaret = c + insert.length;
    tab.applyExternalEdit(next);
    lsp.didChange(
      File(tab.path).uri.toString(),
      next,
      DateTime.now().millisecondsSinceEpoch,
    );
    ghostSuggestion = null;
    notifyListeners();
    scheduleInlineSuggest();
  }

  Future<void> saveActive({bool format = true}) async {
    final tab = activeTab;
    if (tab == null) return;
    try {
      // Materialize untitled into workspace if needed.
      if (workspaceRoot != null &&
          !p.isWithin(workspaceRoot!, tab.path) &&
          tab.path.contains('untitled_')) {
        final dest = p.join(workspaceRoot!, p.basename(tab.path));
        await files.writeFile(dest, tab.content);
        final saved = await files.readFile(dest);
        final idx = activeTabIndex!;
        tabs[idx] = EditorTab(path: dest, content: saved)..markSaved();
        await refreshExplorer();
        statusMessage = 'Saved ${p.basename(dest)}';
        notifyListeners();
        return;
      }
      if (format && tab.path.endsWith('.afr') && settings.formatOnSave) {
        await _formatTab(tab);
      }
      await files.writeFile(tab.path, tab.content);
      tab.markSaved();
      statusMessage = 'Saved ${tab.name}';
      notifyListeners();
    } catch (e) {
      statusMessage = 'Save failed: $e';
      notifyListeners();
    }
  }

  Future<void> _formatTab(EditorTab tab) async {
    final bin = await settings.resolveAfrilangBinary();
    if (bin == null) return;
    final tmp = tab.path;
    await files.writeFile(tmp, tab.content);
    final r = await Process.run(
      bin,
      ['fmt', tmp, '-w'],
      workingDirectory: workspaceRoot,
      environment: ProcessEnv.forHostToolchain(),
    );
    if (r.exitCode == 0) {
      final formatted = await files.readFile(tmp);
      if (formatted != tab.content) {
        tab.applyExternalEdit(formatted);
      }
    }
  }

  void appendOutput(String text, {String channel = 'output'}) {
    if (channel == 'lsp') {
      lspLog.write(text);
    } else {
      outputLog.write(text);
    }
    if (!text.endsWith('\n')) {
      if (channel == 'lsp') {
        lspLog.writeln();
      } else {
        outputLog.writeln();
      }
    }
    notifyListeners();
  }

  void clearOutput() {
    outputLog.clear();
    notifyListeners();
  }

  void clearDebugConsole() {
    debug.console.clear();
    notifyListeners();
  }

  void clearProblems() {
    problems.clear();
    notifyListeners();
  }

  Future<void> buildActiveTarget() async {
    final t = activeTarget;
    var args = List<String>.from(t.args);
    if (t.id == 'check' && activeTab != null) {
      args = ['check', activeTab!.path];
    } else if (t.id == 'debug' || t.id == 'release') {
      args = ['build'];
      if (workspaceRoot != null &&
          !await File(p.join(workspaceRoot!, 'afrilang.toml')).exists() &&
          activeTab != null) {
        args = ['check', activeTab!.path];
      }
    }
    await _streamCli(args, revealProblems: true);
  }

  Future<void> runActive() async {
    final tab = activeTab;
    final main = resolveRunSource(
      activePath: tab?.path,
      projectMain: projects.project?.mainAbsolute,
    );
    if (main == null) {
      statusMessage = 'No file / main to run';
      notifyListeners();
      return;
    }
    // Always flush the buffer of the file we run (don't trust dirty alone —
    // a stale dirty flag used to skip save and execute the old on-disk source).
    if (tab != null && p.equals(tab.path, main)) {
      await saveActive(format: false);
    } else if (tab?.dirty == true) {
      await saveActive(format: false);
    }
    await _streamCli(['run', main]);
  }

  Future<void> checkActive() async {
    final tab = activeTab;
    if (tab == null) {
      statusMessage = 'No file open';
      notifyListeners();
      return;
    }
    await saveActive(format: false);
    await _streamCli(['check', tab.path], revealProblems: true);
  }

  Future<void> runTests() async {
    setBottomTab(BottomTab.testResults);
    await _streamCli(['test'], revealProblems: true);
    await tests.discover(workspaceRoot);
    notifyListeners();
  }

  Future<void> startDebug() async {
    final bin = await settings.resolveAfrilangBinary();
    if (bin == null) {
      statusMessage = 'afrilang not found';
      notifyListeners();
      return;
    }
    final tab = activeTab;
    if (tab != null && tab.path.toLowerCase().endsWith('.afr')) {
      await saveActive(format: false);
    }
    // Auto-build before debug (Code::Blocks pattern).
    await buildActiveTarget();
    // Prefer active .afr (same as Run); fall back to project main / built output.
    final target = resolveRunSource(
          activePath: activeTab?.path,
          projectMain: projects.project?.mainAbsolute,
        ) ??
        projects.project?.outputAbsolute;
    if (target == null) {
      statusMessage = 'Nothing to debug';
      notifyListeners();
      return;
    }
    setBottomTab(BottomTab.debugConsole);
    sidebarView = SidebarView.debug;
    sidebarVisible = true;
    debug.onChanged = () {
      notifyListeners();
      if (debug.paused && debug.frames.isNotEmpty) {
        final top = debug.frames.first;
        if (top.file.isNotEmpty) {
          openFile(top.file, line: top.line);
        }
      }
    };
    notifyListeners();
    await debug.launch(
      binary: bin,
      programOrSource: target,
      workingDirectory: workspaceRoot,
      onOutput: (c) {
        debug.console.write(c);
        notifyListeners();
      },
    );
    notifyListeners();
  }

  Future<void> debugContinue() async {
    await debug.continueExec();
    notifyListeners();
    await _openTopDebugFrameIfPaused();
  }

  Future<void> debugStepOver() async {
    await debug.stepOver();
    notifyListeners();
    await _openTopDebugFrameIfPaused();
  }

  Future<void> debugStepInto() async {
    await debug.stepInto();
    notifyListeners();
    await _openTopDebugFrameIfPaused();
  }

  Future<void> debugStepOut() async {
    await debug.stepOut();
    notifyListeners();
    await _openTopDebugFrameIfPaused();
  }

  Future<void> stopDebug() async {
    await debug.stop();
    notifyListeners();
  }

  Future<void> _openTopDebugFrameIfPaused() async {
    if (!debug.paused || debug.frames.isEmpty) return;
    final top = debug.frames.first;
    if (top.file.isEmpty) return;
    await openFile(top.file, line: top.line);
  }

  void toggleBreakpointAt(String path, int line) {
    debug.toggleBreakpoint(path, line);
    notifyListeners();
  }

  Future<void> showActiveDiff() async {
    final root = workspaceRoot;
    if (root == null) {
      statusMessage = 'No workspace';
      notifyListeners();
      return;
    }
    final file = activeTab?.path;
    final text = await git.diff(root, file: file);
    setBottomTab(BottomTab.output);
    appendOutput(text.isEmpty ? '(no diff)\n' : '$text\n');
    statusMessage = file == null ? 'Diff (workspace)' : 'Diff ${relativePath(file)}';
    notifyListeners();
  }

  Future<void> commitWithMessage(String msg) async {
    final root = workspaceRoot;
    if (root == null) {
      statusMessage = 'No workspace';
      notifyListeners();
      return;
    }
    final trimmed = msg.trim();
    if (trimmed.isEmpty) {
      statusMessage = 'Empty commit message';
      notifyListeners();
      return;
    }
    gitCommitMessage = trimmed;
    final code = await git.commit(root, trimmed);
    await git.refresh(root);
    statusMessage = code == 0 ? 'Committed' : 'Commit failed (exit $code)';
    if (code == 0) gitCommitMessage = null;
    notifyListeners();
  }

  Future<void> stagePath(String path) async {
    final root = workspaceRoot;
    if (root == null) return;
    await git.stage(root, path);
    await git.refresh(root);
    statusMessage = 'Staged ${relativePath(path)}';
    notifyListeners();
  }

  Future<void> toggleBlame() async {
    blameEnabled = !blameEnabled;
    if (blameEnabled) {
      await refreshBlameForActive();
    } else {
      blameLines = [];
      notifyListeners();
    }
  }

  Future<void> refreshBlameForActive() async {
    final root = workspaceRoot;
    final tab = activeTab;
    if (!blameEnabled || root == null || tab == null) {
      blameLines = [];
      notifyListeners();
      return;
    }
    blameLines = await git.blame(root, tab.path);
    notifyListeners();
  }

  Future<void> refreshDirtyLinesForActive() async {
    final root = workspaceRoot;
    final tab = activeTab;
    if (root == null || tab == null) {
      dirtyLines = {};
      notifyListeners();
      return;
    }
    dirtyLines = await git.changedLines(root, tab.path);
    notifyListeners();
  }

  Future<void> renameSymbolAtCaret(String newName) async {
    final tab = activeTab;
    final name = newName.trim();
    if (tab == null || name.isEmpty) return;
    if (!lsp.ready) {
      statusMessage = 'LSP not ready for rename';
      notifyListeners();
      return;
    }
    final pos = TextOps.lineColAt(tab.content, editorCaret);
    final edit = await lsp.rename(
      File(tab.path).uri.toString(),
      pos.line,
      pos.character,
      name,
    );
    if (edit == null || edit.changes.isEmpty) {
      statusMessage =
          'Rename failed${lsp.lastError != null ? ": ${lsp.lastError}" : ""}';
      notifyListeners();
      return;
    }
    for (final entry in edit.changes.entries) {
      final path = entry.key.startsWith('file://')
          ? Uri.parse(entry.key).toFilePath()
          : entry.key;
      final openIdx = tabs.indexWhere((t) => p.equals(t.path, path));
      if (openIdx >= 0) {
        final t = tabs[openIdx];
        final next = _applyLspEdits(t.content, entry.value);
        t.applyExternalEdit(next);
        await files.writeFile(t.path, t.content);
        t.markSaved();
        await lsp.didChange(File(t.path).uri.toString(), t.content, t.contentRevision);
      } else if (await File(path).exists()) {
        final content = await files.readFile(path);
        final next = _applyLspEdits(content, entry.value);
        await files.writeFile(path, next);
      }
    }
    statusMessage = 'Renamed → $name';
    notifyListeners();
  }

  static String _applyLspEdits(String content, List<LspTextEdit> edits) {
    final sorted = List<LspTextEdit>.from(edits)
      ..sort((a, b) {
        final byLine = b.endLine.compareTo(a.endLine);
        if (byLine != 0) return byLine;
        return b.endCharacter.compareTo(a.endCharacter);
      });
    var out = content;
    for (final e in sorted) {
      final start = TextOps.offsetAtLine(out, e.startLine, column: e.startCharacter);
      final end = TextOps.offsetAtLine(out, e.endLine, column: e.endCharacter);
      final s = start.clamp(0, out.length);
      final en = end.clamp(s, out.length);
      out = out.substring(0, s) + e.newText + out.substring(en);
    }
    return out;
  }

  Future<void> findReferencesAtCaret() async {
    final tab = activeTab;
    if (tab == null) return;
    final pos = TextOps.lineColAt(tab.content, editorCaret);
    final locs = lsp.ready
        ? await lsp.references(
            File(tab.path).uri.toString(),
            pos.line,
            pos.character,
          )
        : <LspLocation>[];
    final hits = <SearchHit>[];
    for (final loc in locs) {
      final path = loc.uri.startsWith('file://')
          ? Uri.parse(loc.uri).toFilePath()
          : loc.uri;
      hits.add(SearchHit(
        path: path,
        line: loc.line,
        column: loc.column ?? 1,
        preview: '${p.basename(path)}:${loc.line}',
      ));
    }
    if (hits.isEmpty) {
      final word = TextOps.wordAt(tab.content, editorCaret);
      statusMessage = word.isEmpty ? 'No references' : 'No references for "$word"';
      referenceHits = [];
      notifyListeners();
      return;
    }
    referenceHits = hits;
    searchHits = hits;
    searchQuery = TextOps.wordAt(tab.content, editorCaret);
    sidebarView = SidebarView.search;
    sidebarVisible = true;
    statusMessage = '${hits.length} reference(s)';
    notifyListeners();
  }

  Future<void> _streamCli(List<String> args, {bool revealProblems = false}) async {
    if (build.isRunning) {
      statusMessage = 'Already running — Stop first (Shift+F5)';
      notifyListeners();
      return;
    }
    busy = true;
    statusMessage = 'Running ${args.first}…';
    bottomTab = BottomTab.output;
    panelVisible = true;
    notifyListeners();
    try {
      final result = await build.runStreaming(
        args: args,
        workingDirectory: workspaceRoot,
        onChunk: (c) {
          outputLog.write(c);
          notifyListeners();
        },
      );
      problems
        ..clear()
        ..addAll(result.problems.where((p) => p.path.isNotEmpty || p.message.isNotEmpty));
      if (revealProblems && problems.isNotEmpty) {
        bottomTab = BottomTab.problems;
      }
      events.emit(BuildFinishedEvent(exitCode: result.exitCode, targetId: activeTargetId));
      statusMessage = result.exitCode == -1
          ? 'Stopped'
          : result.exitCode == 0
              ? 'Done'
              : 'Exit ${result.exitCode}';
    } catch (e) {
      appendOutput('Error: $e\n');
      statusMessage = 'Failed';
    } finally {
      busy = false;
      notifyListeners();
    }
  }

  Future<void> runSearch(String query) async {
    searchQuery = query;
    if (workspaceRoot == null || query.trim().isEmpty) {
      searchHits = [];
      notifyListeners();
      return;
    }
    searchHits = await search.findInFiles(root: workspaceRoot!, query: query);
    notifyListeners();
  }

  Future<void> refreshGit() async {
    await git.refresh(workspaceRoot);
    notifyListeners();
  }

  void openTerminal() {
    terminals.create(cwd: workspaceRoot);
    setBottomTab(BottomTab.terminal);
    notifyListeners();
  }

  List<String> quickOpenMatches(String query) {
    final q = query.trim().toLowerCase();
    final pool = <String>[
      ...recentFiles,
      ...workspaceFiles.where((f) => !recentFiles.contains(f)),
    ];
    final effective = pool.isEmpty ? tabs.map((t) => t.path).toList() : pool;
    if (q.isEmpty) return effective.take(40).toList();
    return effective
        .where((f) =>
            p.basename(f).toLowerCase().contains(q) || f.toLowerCase().contains(q))
        .take(60)
        .toList();
  }

  String relativePath(String absolute) {
    final normAbs = p.normalize(absolute);
    for (final f in workspace.folders) {
      final normRoot = p.normalize(f.path);
      if (normAbs == normRoot ||
          normAbs.startsWith('$normRoot${p.separator}')) {
        return p.relative(absolute, from: f.path);
      }
    }
    final root = workspaceRoot;
    if (root == null) return absolute;
    return p.relative(absolute, from: root);
  }

  List<String> breadcrumbsForActive() {
    final tab = activeTab;
    if (tab == null) return const [];
    return TextOps.breadcrumbs(relativePath(tab.path));
  }

  void updateFindQuery(String query) {
    findQuery = query;
    final tab = activeTab;
    if (tab == null) {
      findMatches = [];
      findIndex = 0;
      notifyListeners();
      return;
    }
    findMatches = FindReplaceEngine.findAll(tab.content, query);
    findIndex = findMatches.isEmpty ? 0 : findIndex.clamp(0, findMatches.length - 1);
    notifyListeners();
  }

  void findNext() {
    if (findMatches.isEmpty) return;
    findIndex = (findIndex + 1) % findMatches.length;
    notifyListeners();
  }

  void findPrev() {
    if (findMatches.isEmpty) return;
    findIndex = (findIndex - 1 + findMatches.length) % findMatches.length;
    notifyListeners();
  }

  void replaceCurrent() {
    final tab = activeTab;
    if (tab == null || findMatches.isEmpty) return;
    final next = FindReplaceEngine.replaceFirst(
      tab.content,
      findQuery,
      replaceQuery,
      from: findMatches[findIndex].start,
    );
    updateActiveContent(next, external: true);
    updateFindQuery(findQuery);
  }

  void replaceAllInFile() {
    final tab = activeTab;
    if (tab == null || findQuery.isEmpty) return;
    final next = FindReplaceEngine.replaceAll(tab.content, findQuery, replaceQuery);
    updateActiveContent(next, external: true);
    updateFindQuery(findQuery);
  }

  void requestGoToLine(int line, {int? column}) {
    goToLineRequest = line;
    goToColumnRequest = column;
    hideOverlay();
    notifyListeners();
  }

  void clearGoToLineRequest() {
    goToLineRequest = null;
    goToColumnRequest = null;
  }

  void insertSnippet(AfrilangSnippet snippet) {
    final tab = activeTab;
    if (tab == null) return;
    final expanded = expandSnippet(snippet.body);
    updateActiveContent(
      tab.content + (tab.content.endsWith('\n') ? '' : '\n') + expanded,
      external: true,
    );
    hideOverlay();
    statusMessage = 'Inserted snippet ${snippet.label}';
    notifyListeners();
  }

  void duplicateActiveLine() {
    final tab = activeTab;
    if (tab == null) return;
    // caret unknown → duplicate last line
    final offset = tab.content.length;
    updateActiveContent(TextOps.duplicateLine(tab.content, offset), external: true);
  }

  void toggleActiveComment() {
    final tab = activeTab;
    if (tab == null) return;
    final offset = tab.content.isEmpty ? 0 : tab.content.length - 1;
    updateActiveContent(
      TextOps.toggleLineComment(tab.content, offset),
      external: true,
    );
  }

  Future<void> formatActive() async {
    final tab = activeTab;
    if (tab == null) return;
    await _formatTab(tab);
    tab.markSaved();
    await files.writeFile(tab.path, tab.content);
    statusMessage = 'Formatted ${tab.name}';
    notifyListeners();
  }

  Future<void> lintWorkspace() async {
    if (workspaceRoot == null) {
      statusMessage = 'No workspace';
      notifyListeners();
      return;
    }
    await _streamCli(['lint'], revealProblems: true);
  }

  Future<void> discardActiveChanges() async {
    final tab = activeTab;
    if (tab == null || !tab.dirty) return;
    tab.applyExternalEdit(tab.savedContent);
    tab.dirty = false;
    statusMessage = 'Discarded changes in ${tab.name}';
    notifyListeners();
  }

  @override
  void dispose() {
    _aiDebounce?.cancel();
    _hoverDebounce?.cancel();
    ai.updateConfig(const AiAssistConfig());
    lsp.stop();
    terminals.disposeAll();
    debug.stop();
    build.cancel();
    super.dispose();
  }
}
