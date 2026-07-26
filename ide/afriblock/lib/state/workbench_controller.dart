import 'package:file_picker/file_picker.dart';
import 'package:flutter/foundation.dart';
import 'package:path/path.dart' as p;

import '../models/editor_tab.dart';
import '../models/problem_item.dart';
import '../models/workspace_node.dart';
import '../services/afrilang_cli.dart';
import '../services/file_service.dart';
import '../services/settings_store.dart';

enum SidebarView { explorer, search, run, extensions }

enum BottomTab { problems, output }

class WorkbenchController extends ChangeNotifier {
  WorkbenchController({
    FileService? fileService,
    SettingsStore? settings,
    AfrilangCli? cli,
  })  : files = fileService ?? FileService(),
        settings = settings ?? SettingsStore() {
    this.cli = cli ??
        AfrilangCli(resolveBinary: () => this.settings.resolveAfrilangBinary());
  }

  final FileService files;
  final SettingsStore settings;
  late final AfrilangCli cli;

  bool ready = false;
  String? workspaceRoot;
  WorkspaceNode? rootNode;
  final List<EditorTab> tabs = [];
  int? activeTabIndex;

  SidebarView sidebarView = SidebarView.explorer;
  bool sidebarVisible = true;
  double sidebarWidth = 260;

  bool panelVisible = true;
  double panelHeight = 180;
  BottomTab bottomTab = BottomTab.output;

  final List<ProblemItem> problems = [];
  final StringBuffer outputLog = StringBuffer();
  bool busy = false;
  String? statusMessage;
  bool commandPaletteOpen = false;

  EditorTab? get activeTab =>
      activeTabIndex == null || activeTabIndex! >= tabs.length
          ? null
          : tabs[activeTabIndex!];

  Future<void> init() async {
    await settings.load();
    statusMessage = 'Ready';
    ready = true;
    notifyListeners();
  }

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
    sidebarWidth = w.clamp(160, 480);
    notifyListeners();
  }

  void setPanelHeight(double h) {
    panelHeight = h.clamp(100, 480);
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

  void toggleCommandPalette([bool? open]) {
    commandPaletteOpen = open ?? !commandPaletteOpen;
    notifyListeners();
  }

  Future<void> openFolder([String? path]) async {
    String? folder = path;
    if (folder == null) {
      folder = await FilePicker.platform.getDirectoryPath(
        dialogTitle: 'Open Folder — AFRIBLOCK',
      );
    }
    if (folder == null) return;

    try {
      rootNode = await files.loadTree(folder);
      workspaceRoot = folder;
      await settings.pushRecent(folder);
      statusMessage = 'Opened $folder';
      appendOutput('Opened workspace: $folder\n');
      notifyListeners();
    } catch (e) {
      statusMessage = 'Open failed: $e';
      appendOutput('Open failed: $e\n');
      notifyListeners();
    }
  }

  void toggleExpand(WorkspaceNode node) {
    if (!node.isDirectory) return;
    node.expanded = !node.expanded;
    notifyListeners();
  }

  Future<void> openFile(String path) async {
    final existing = tabs.indexWhere((t) => t.path == path);
    if (existing >= 0) {
      activeTabIndex = existing;
      notifyListeners();
      return;
    }
    try {
      final content = await files.readFile(path);
      final tab = EditorTab(path: path, content: content)..markSaved();
      tabs.add(tab);
      activeTabIndex = tabs.length - 1;
      statusMessage = path;
      notifyListeners();
    } catch (e) {
      statusMessage = 'Cannot open: $e';
      notifyListeners();
    }
  }

  void selectTab(int index) {
    if (index < 0 || index >= tabs.length) return;
    activeTabIndex = index;
    notifyListeners();
  }

  void closeTab(int index) {
    if (index < 0 || index >= tabs.length) return;
    tabs.removeAt(index);
    if (tabs.isEmpty) {
      activeTabIndex = null;
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

  void updateActiveContent(String content) {
    final tab = activeTab;
    if (tab == null) return;
    tab.applyEdit(content);
    notifyListeners();
  }

  Future<void> saveActive() async {
    final tab = activeTab;
    if (tab == null) return;
    try {
      await files.writeFile(tab.path, tab.content);
      tab.markSaved();
      statusMessage = 'Saved ${tab.name}';
      notifyListeners();
    } catch (e) {
      statusMessage = 'Save failed: $e';
      notifyListeners();
    }
  }

  void appendOutput(String text) {
    outputLog.write(text);
    if (!text.endsWith('\n')) outputLog.writeln();
    notifyListeners();
  }

  void clearOutput() {
    outputLog.clear();
    notifyListeners();
  }

  void clearProblems() {
    problems.clear();
    notifyListeners();
  }

  Future<void> runActive() async {
    final tab = activeTab;
    if (tab == null) {
      statusMessage = 'No file open';
      notifyListeners();
      return;
    }
    if (tab.dirty) await saveActive();
    await _runCli((bin) => cli.runFile(tab.path, workingDirectory: workspaceRoot));
  }

  Future<void> checkActive() async {
    final tab = activeTab;
    if (tab == null) {
      statusMessage = 'No file open';
      notifyListeners();
      return;
    }
    if (tab.dirty) await saveActive();
    await _runCli((bin) => cli.checkFile(tab.path, workingDirectory: workspaceRoot));
  }

  Future<void> _runCli(Future<CliResult> Function(AfrilangCli) action) async {
    busy = true;
    statusMessage = 'Running…';
    bottomTab = BottomTab.output;
    panelVisible = true;
    notifyListeners();
    try {
      final result = await action(cli);
      appendOutput(result.combinedOutput);
      problems
        ..clear()
        ..addAll(result.problems);
      if (result.problems.isNotEmpty) {
        bottomTab = BottomTab.problems;
      }
      statusMessage = result.exitCode == 0 ? 'Done' : 'Exit ${result.exitCode}';
    } catch (e) {
      appendOutput('Error: $e\n');
      statusMessage = 'Failed';
    } finally {
      busy = false;
      notifyListeners();
    }
  }

  String relativePath(String absolute) {
    final root = workspaceRoot;
    if (root == null) return absolute;
    return p.relative(absolute, from: root);
  }
}
