import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

import '../ai/ai_assist_service.dart';
import '../models/workspace_node.dart';
import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';
import 'new_item_dialogs.dart';

class SidebarExplorer extends StatelessWidget {
  const SidebarExplorer({super.key});

  @override
  Widget build(BuildContext context) {
    final wb = context.watch<WorkbenchController>();
    return ColoredBox(
      color: AfriblockColors.panel,
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          _Header(title: _title(wb.sidebarView)),
          Expanded(child: _body(context, wb)),
        ],
      ),
    );
  }

  String _title(SidebarView v) => switch (v) {
        SidebarView.explorer => 'EXPLORER',
        SidebarView.search => 'SEARCH',
        SidebarView.scm => 'SOURCE CONTROL',
        SidebarView.run => 'RUN',
        SidebarView.debug => 'RUN AND DEBUG',
        SidebarView.test => 'TEST EXPLORER',
        SidebarView.extensions => 'EXTENSIONS',
        SidebarView.afrilang => 'AFRILANG',
        SidebarView.ai => 'AI ASSIST',
      };

  Widget _body(BuildContext context, WorkbenchController wb) {
    switch (wb.sidebarView) {
      case SidebarView.explorer:
        return _ExplorerBody(wb: wb);
      case SidebarView.search:
        return _SearchPanel(wb: wb);
      case SidebarView.scm:
        return _ScmPanel(wb: wb);
      case SidebarView.run:
        return _RunPanel(wb: wb);
      case SidebarView.debug:
        return _DebugPanel(wb: wb);
      case SidebarView.test:
        return _TestPanel(wb: wb);
      case SidebarView.extensions:
        return _ExtensionsPanel(wb: wb);
      case SidebarView.afrilang:
        return _AfrilangHub(wb: wb);
      case SidebarView.ai:
        return _AiChatPanel(wb: wb);
    }
  }
}

class _Header extends StatelessWidget {
  const _Header({required this.title});
  final String title;

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 36,
      padding: const EdgeInsets.symmetric(horizontal: 14),
      alignment: Alignment.centerLeft,
      decoration: const BoxDecoration(
        border: Border(bottom: BorderSide(color: AfriblockColors.border)),
      ),
      child: Text(
        title,
        style: GoogleFonts.plusJakartaSans(
          fontSize: 11,
          fontWeight: FontWeight.w700,
          letterSpacing: 1.1,
          color: AfriblockColors.textMuted,
        ),
      ),
    );
  }
}

class _ExplorerBody extends StatelessWidget {
  const _ExplorerBody({required this.wb});
  final WorkbenchController wb;

  @override
  Widget build(BuildContext context) {
    final proj = wb.projects.project;
    if (wb.rootNode == null) {
      return Padding(
        padding: const EdgeInsets.all(12),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.stretch,
          children: [
            const ExplorerCreateBar(),
            const SizedBox(height: 12),
            Text(
              'Pas encore de projet ouvert.',
              style: GoogleFonts.plusJakartaSans(color: AfriblockColors.textMuted),
            ),
            const SizedBox(height: 12),
            FilledButton.icon(
              onPressed: () => promptNewProject(context),
              icon: const Icon(Icons.rocket_launch),
              label: const Text('Nouveau projet'),
              style: FilledButton.styleFrom(backgroundColor: AfriblockColors.accent, foregroundColor: Colors.black),
            ),
            const SizedBox(height: 8),
            OutlinedButton.icon(
              onPressed: () => promptOpenFolder(context),
              icon: const Icon(Icons.folder_open),
              label: const Text('Ouvrir un dossier'),
            ),
          ],
        ),
      );
    }
    final root = wb.rootNode!;
    return Column(
      crossAxisAlignment: CrossAxisAlignment.stretch,
      children: [
        const ExplorerCreateBar(),
        if (proj != null)
          Padding(
            padding: const EdgeInsets.fromLTRB(12, 4, 12, 4),
            child: Text(
              '${proj.name}  ·  ${proj.version ?? ""}',
              style: GoogleFonts.plusJakartaSans(
                fontSize: 12,
                fontWeight: FontWeight.w600,
                color: AfriblockColors.accent,
              ),
            ),
          ),
        Expanded(
          child: ListView(
            padding: const EdgeInsets.symmetric(vertical: 4),
            children: [
              Padding(
                padding: const EdgeInsets.fromLTRB(12, 6, 12, 8),
                child: Text(
                  root.name.toUpperCase(),
                  style: GoogleFonts.plusJakartaSans(
                    fontSize: 11,
                    fontWeight: FontWeight.w700,
                    color: AfriblockColors.textMuted,
                  ),
                ),
              ),
              if (wb.outline.isNotEmpty) ...[
                Padding(
                  padding: const EdgeInsets.fromLTRB(12, 4, 12, 4),
                  child: Text(
                    'OUTLINE',
                    style: GoogleFonts.plusJakartaSans(
                      fontSize: 10,
                      fontWeight: FontWeight.w700,
                      color: AfriblockColors.textMuted,
                    ),
                  ),
                ),
                ...wb.outline.map(
                  (s) => ListTile(
                    dense: true,
                    leading: const Icon(Icons.code, size: 14),
                    title: Text(s.name, style: afriblockMono(fontSize: 12)),
                    subtitle: Text(
                      'L${s.line}',
                      style: afriblockMono(fontSize: 10, color: AfriblockColors.textMuted),
                    ),
                    onTap: () => wb.openFile(wb.activeTab!.path, line: s.line),
                  ),
                ),
                const Divider(color: AfriblockColors.border),
              ],
              ...root.children.map((c) => _TreeTile(node: c, depth: 0)),
            ],
          ),
        ),
      ],
    );
  }
}

class _TreeTile extends StatelessWidget {
  const _TreeTile({required this.node, required this.depth});
  final WorkspaceNode node;
  final int depth;

  Future<void> _showContext(BuildContext context) async {
    final wb = context.read<WorkbenchController>();
    wb.selectExplorerPath(node.path, isDirectory: node.isDirectory);
    final parentForCreate = node.isDirectory ? node.path : null;
    final box = context.findRenderObject() as RenderBox?;
    final pos = box?.localToGlobal(Offset.zero) ?? Offset.zero;
    final selected = await showMenu<String>(
      context: context,
      position: RelativeRect.fromLTRB(pos.dx + 40, pos.dy + 20, pos.dx + 40, pos.dy),
      color: AfriblockColors.panelElevated,
      items: [
        if (node.isDirectory) ...[
          const PopupMenuItem(value: 'new_file', child: Text('New File…')),
          const PopupMenuItem(value: 'new_folder', child: Text('New Folder…')),
        ] else ...[
          const PopupMenuItem(value: 'new_file_here', child: Text('New File Here…')),
          const PopupMenuItem(value: 'new_folder_here', child: Text('New Folder Here…')),
        ],
        const PopupMenuItem(value: 'reveal', child: Text('Select')),
      ],
    );
    if (!context.mounted) return;
    switch (selected) {
      case 'new_file':
        await promptCreateFile(context, parentDir: parentForCreate);
      case 'new_folder':
        await promptCreateFolder(context, parentDir: parentForCreate);
      case 'new_file_here':
        await promptCreateFile(context, parentDir: FileParent.of(node.path));
      case 'new_folder_here':
        await promptCreateFolder(context, parentDir: FileParent.of(node.path));
      default:
        break;
    }
  }

  @override
  Widget build(BuildContext context) {
    final wb = context.watch<WorkbenchController>();
    final active = wb.activeTab?.path == node.path;
    final selected = wb.explorerSelection == node.path;
    return Column(
      crossAxisAlignment: CrossAxisAlignment.stretch,
      children: [
        GestureDetector(
          onSecondaryTap: () => _showContext(context),
          onLongPress: () => _showContext(context),
          child: InkWell(
            onTap: () {
              wb.selectExplorerPath(node.path, isDirectory: node.isDirectory);
              if (node.isDirectory) {
                wb.toggleExpand(node);
              } else {
                wb.openFile(node.path);
              }
            },
            child: Container(
              color: (active || selected)
                  ? AfriblockColors.primaryDeep.withValues(alpha: 0.25)
                  : Colors.transparent,
              padding: EdgeInsets.only(left: 8.0 + depth * 12, right: 8, top: 3, bottom: 3),
              child: Row(
                children: [
                  Icon(
                    node.isDirectory
                        ? (node.expanded
                            ? Icons.keyboard_arrow_down
                            : Icons.keyboard_arrow_right)
                        : Icons.insert_drive_file_outlined,
                    size: 16,
                    color: node.isDirectory
                        ? AfriblockColors.accent
                        : (node.name.endsWith('.afr')
                            ? AfriblockColors.primary
                            : AfriblockColors.textMuted),
                  ),
                  const SizedBox(width: 6),
                  Expanded(
                    child: Text(
                      node.name,
                      overflow: TextOverflow.ellipsis,
                      style: GoogleFonts.plusJakartaSans(fontSize: 13),
                    ),
                  ),
                ],
              ),
            ),
          ),
        ),
        if (node.isDirectory && node.expanded)
          ...node.children.map((c) => _TreeTile(node: c, depth: depth + 1)),
      ],
    );
  }
}

class FileParent {
  static String of(String path) {
    final i = path.replaceAll('\\', '/').lastIndexOf('/');
    if (i <= 0) return path;
    return path.substring(0, i);
  }
}

class _SearchPanel extends StatefulWidget {
  const _SearchPanel({required this.wb});
  final WorkbenchController wb;

  @override
  State<_SearchPanel> createState() => _SearchPanelState();
}

class _SearchPanelState extends State<_SearchPanel> {
  final _ctrl = TextEditingController();

  @override
  void dispose() {
    _ctrl.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    final wb = widget.wb;
    return Column(
      children: [
        Padding(
          padding: const EdgeInsets.all(8),
          child: TextField(
            controller: _ctrl,
            decoration: const InputDecoration(
              hintText: 'Search in files',
              isDense: true,
              border: OutlineInputBorder(),
            ),
            onSubmitted: wb.runSearch,
          ),
        ),
        Expanded(
          child: ListView.builder(
            itemCount: wb.searchHits.length,
            itemBuilder: (context, i) {
              final h = wb.searchHits[i];
              return ListTile(
                dense: true,
                title: Text(h.preview, style: afriblockMono(fontSize: 12), maxLines: 1, overflow: TextOverflow.ellipsis),
                subtitle: Text('${wb.relativePath(h.path)}:${h.line}',
                    style: afriblockMono(fontSize: 10, color: AfriblockColors.textMuted)),
                onTap: () => wb.openFile(h.path, line: h.line),
              );
            },
          ),
        ),
      ],
    );
  }
}

class _ScmPanel extends StatelessWidget {
  const _ScmPanel({required this.wb});
  final WorkbenchController wb;

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        ListTile(
          dense: true,
          title: Text(wb.git.branch ?? 'Not a git repo',
              style: GoogleFonts.plusJakartaSans(fontWeight: FontWeight.w600)),
          trailing: IconButton(
            icon: const Icon(Icons.refresh, size: 18),
            onPressed: wb.refreshGit,
          ),
        ),
        if (wb.git.lastError != null)
          Padding(
            padding: const EdgeInsets.all(8),
            child: Text(wb.git.lastError!, style: afriblockMono(fontSize: 11, color: AfriblockColors.error)),
          ),
        Expanded(
          child: ListView.builder(
            itemCount: wb.git.entries.length,
            itemBuilder: (context, i) {
              final e = wb.git.entries[i];
              return ListTile(
                dense: true,
                leading: Text(e.code, style: afriblockMono(fontSize: 11, color: AfriblockColors.accent)),
                title: Text(wb.relativePath(e.path), style: afriblockMono(fontSize: 12)),
                onTap: () => wb.openFile(e.path),
              );
            },
          ),
        ),
      ],
    );
  }
}

class _RunPanel extends StatelessWidget {
  const _RunPanel({required this.wb});
  final WorkbenchController wb;

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.all(12),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          DropdownButtonFormField<String>(
            initialValue: wb.activeTargetId,
            decoration: const InputDecoration(labelText: 'Build target', border: OutlineInputBorder()),
            items: [
              for (final t in wb.availableTargets)
                DropdownMenuItem(value: t.id, child: Text(t.label)),
            ],
            onChanged: (v) {
              if (v != null) wb.setActiveTarget(v);
            },
          ),
          const SizedBox(height: 12),
          FilledButton.icon(
            onPressed: wb.busy ? null : wb.buildActiveTarget,
            icon: const Icon(Icons.handyman),
            label: const Text('Build'),
          ),
          const SizedBox(height: 8),
          FilledButton.icon(
            onPressed: wb.busy ? null : wb.runActive,
            icon: const Icon(Icons.play_arrow),
            label: const Text('Run'),
            style: FilledButton.styleFrom(backgroundColor: AfriblockColors.primaryDeep),
          ),
          const SizedBox(height: 8),
          OutlinedButton.icon(
            onPressed: wb.busy ? null : wb.checkActive,
            icon: const Icon(Icons.fact_check_outlined),
            label: const Text('Check'),
          ),
        ],
      ),
    );
  }
}

class _DebugPanel extends StatelessWidget {
  const _DebugPanel({required this.wb});
  final WorkbenchController wb;

  @override
  Widget build(BuildContext context) {
    return ListView(
      padding: const EdgeInsets.all(12),
      children: [
        FilledButton.icon(
          onPressed: wb.debug.running ? null : wb.startDebug,
          icon: const Icon(Icons.bug_report),
          label: const Text('Start Debugging'),
        ),
        const SizedBox(height: 8),
        OutlinedButton.icon(
          onPressed: wb.debug.running ? wb.debug.stop : null,
          icon: const Icon(Icons.stop),
          label: const Text('Stop'),
        ),
        const SizedBox(height: 12),
        Text('Breakpoints', style: GoogleFonts.plusJakartaSans(fontWeight: FontWeight.w700)),
        ...wb.debug.breakpoints.map(
          (b) => ListTile(
            dense: true,
            title: Text('${wb.relativePath(b.path)}:${b.line}', style: afriblockMono(fontSize: 12)),
            trailing: IconButton(
              icon: const Icon(Icons.close, size: 16),
              onPressed: () {
                wb.toggleBreakpointAt(b.path, b.line);
              },
            ),
          ),
        ),
        if (wb.debug.status != null)
          Text(wb.debug.status!, style: afriblockMono(fontSize: 11, color: AfriblockColors.textMuted)),
      ],
    );
  }
}

class _TestPanel extends StatelessWidget {
  const _TestPanel({required this.wb});
  final WorkbenchController wb;

  @override
  Widget build(BuildContext context) {
    return Column(
      children: [
        Padding(
          padding: const EdgeInsets.all(8),
          child: Row(
            children: [
              FilledButton(
                onPressed: wb.busy ? null : wb.runTests,
                child: const Text('Run Tests'),
              ),
              const SizedBox(width: 8),
              OutlinedButton(
                onPressed: wb.refreshTests,
                child: const Text('Refresh'),
              ),
            ],
          ),
        ),
        Expanded(
          child: ListView.builder(
            itemCount: wb.tests.items.length,
            itemBuilder: (context, i) {
              final t = wb.tests.items[i];
              return ListTile(
                dense: true,
                leading: const Icon(Icons.science_outlined, size: 16),
                title: Text(t.name, style: afriblockMono(fontSize: 12)),
                subtitle: Text('${wb.relativePath(t.path)}:${t.line}',
                    style: afriblockMono(fontSize: 10, color: AfriblockColors.textMuted)),
                onTap: () => wb.openFile(t.path, line: t.line),
              );
            },
          ),
        ),
      ],
    );
  }
}

class _ExtensionsPanel extends StatelessWidget {
  const _ExtensionsPanel({required this.wb});
  final WorkbenchController wb;

  @override
  Widget build(BuildContext context) {
    return ListView(
      children: [
        for (final p in wb.plugins.plugins)
          ListTile(
            leading: const Icon(Icons.extension),
            title: Text(p.name),
            subtitle: Text(p.description),
            trailing: Text(p.id, style: afriblockMono(fontSize: 10, color: AfriblockColors.textMuted)),
          ),
      ],
    );
  }
}

class _AfrilangHub extends StatelessWidget {
  const _AfrilangHub({required this.wb});
  final WorkbenchController wb;

  @override
  Widget build(BuildContext context) {
    final proj = wb.projects.project;
    return ListView(
      padding: const EdgeInsets.all(12),
      children: [
        Text('Project', style: GoogleFonts.plusJakartaSans(fontWeight: FontWeight.w700)),
        Text(proj == null ? 'No afrilang.toml detected' : '${proj.name}\n${proj.description ?? ""}'),
        const SizedBox(height: 12),
        FilledButton(
          onPressed: () => wb.build.runStreaming(
            args: ['pkg', 'list'],
            workingDirectory: wb.workspaceRoot,
            onChunk: wb.appendOutput,
          ),
          child: const Text('pkg list'),
        ),
        const SizedBox(height: 8),
        OutlinedButton(
          onPressed: () => wb.build.runStreaming(
            args: ['pkg', 'sync'],
            workingDirectory: wb.workspaceRoot,
            onChunk: wb.appendOutput,
          ),
          child: const Text('pkg sync'),
        ),
        const SizedBox(height: 16),
        Text('See docs/AFRIBLOCK_ARCHITECTURE.md for Hub roadmap.',
            style: GoogleFonts.plusJakartaSans(fontSize: 12, color: AfriblockColors.textMuted)),
      ],
    );
  }
}

class _AiChatPanel extends StatefulWidget {
  const _AiChatPanel({required this.wb});
  final WorkbenchController wb;

  @override
  State<_AiChatPanel> createState() => _AiChatPanelState();
}

class _AiChatPanelState extends State<_AiChatPanel> {
  final _input = TextEditingController();
  bool _sending = false;

  @override
  void dispose() {
    _input.dispose();
    super.dispose();
  }

  Future<void> _send({bool includeFile = false}) async {
    final text = _input.text.trim();
    if (text.isEmpty || _sending) return;
    setState(() => _sending = true);
    _input.clear();
    try {
      await widget.wb.sendAiChat(text, includeFile: includeFile);
    } finally {
      if (mounted) setState(() => _sending = false);
    }
  }

  Future<void> _explainFile() async {
    final tab = widget.wb.activeTab;
    if (tab == null) {
      widget.wb.statusMessage = 'Open a file to explain';
      widget.wb.notifyListeners();
      return;
    }
    setState(() => _sending = true);
    try {
      await widget.wb.sendAiChat(
        'Explain this AFRILANG file briefly. Highlight structure and any issues.',
        includeFile: true,
      );
    } finally {
      if (mounted) setState(() => _sending = false);
    }
  }

  @override
  Widget build(BuildContext context) {
    final wb = widget.wb;
    final messages = wb.ai.chatLog.where((m) => m.role != 'system').toList();
    return Column(
      crossAxisAlignment: CrossAxisAlignment.stretch,
      children: [
        Padding(
          padding: const EdgeInsets.fromLTRB(12, 8, 12, 4),
          child: Text(
            wb.settings.aiEnabled
                ? 'Model: ${wb.settings.aiModel}'
                : 'AI disabled — enable in Settings',
            style: GoogleFonts.plusJakartaSans(
              fontSize: 11,
              color: AfriblockColors.textMuted,
            ),
          ),
        ),
        Padding(
          padding: const EdgeInsets.symmetric(horizontal: 8),
          child: Wrap(
            spacing: 6,
            runSpacing: 4,
            children: [
              OutlinedButton(
                onPressed: _sending ? null : _explainFile,
                child: const Text('Expliquer le fichier'),
              ),
              TextButton(
                onPressed: () {
                  wb.ai.clearChat();
                  wb.notifyListeners();
                },
                child: const Text('Clear'),
              ),
            ],
          ),
        ),
        Expanded(
          child: ListView.builder(
            padding: const EdgeInsets.all(10),
            itemCount: messages.length,
            itemBuilder: (context, i) {
              final m = messages[i];
              final isUser = m.role == 'user';
              final code = !isUser ? AiAssistService.extractCodeBlock(m.content) : null;
              return Container(
                margin: const EdgeInsets.only(bottom: 10),
                padding: const EdgeInsets.all(10),
                decoration: BoxDecoration(
                  color: isUser
                      ? AfriblockColors.panelElevated
                      : AfriblockColors.surface,
                  borderRadius: BorderRadius.circular(8),
                  border: Border.all(color: AfriblockColors.border),
                ),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.stretch,
                  children: [
                    Text(
                      isUser ? 'You' : 'Assistant',
                      style: GoogleFonts.plusJakartaSans(
                        fontSize: 10,
                        fontWeight: FontWeight.w700,
                        color: AfriblockColors.accent,
                      ),
                    ),
                    const SizedBox(height: 4),
                    SelectableText(
                      m.content,
                      style: afriblockMono(fontSize: 11.5),
                    ),
                    if (code != null && code.isNotEmpty) ...[
                      const SizedBox(height: 8),
                      Align(
                        alignment: Alignment.centerLeft,
                        child: FilledButton.tonal(
                          onPressed: () => wb.insertAiCodeIntoEditor(code),
                          child: const Text('Insert code'),
                        ),
                      ),
                    ],
                  ],
                ),
              );
            },
          ),
        ),
        if (wb.ai.lastError != null)
          Padding(
            padding: const EdgeInsets.symmetric(horizontal: 12),
            child: Text(
              wb.ai.lastError!,
              style: GoogleFonts.plusJakartaSans(
                fontSize: 11,
                color: AfriblockColors.error,
              ),
            ),
          ),
        Padding(
          padding: const EdgeInsets.fromLTRB(8, 4, 8, 10),
          child: Row(
            children: [
              Expanded(
                child: TextField(
                  controller: _input,
                  minLines: 1,
                  maxLines: 4,
                  enabled: !_sending && wb.settings.aiEnabled,
                  decoration: const InputDecoration(
                    hintText: 'Ask about AFRILANG…',
                    border: OutlineInputBorder(),
                    isDense: true,
                  ),
                  style: afriblockMono(fontSize: 12),
                  onSubmitted: (_) => _send(includeFile: true),
                ),
              ),
              const SizedBox(width: 6),
              IconButton.filled(
                onPressed: (_sending || !wb.settings.aiEnabled)
                    ? null
                    : () => _send(includeFile: true),
                icon: _sending
                    ? const SizedBox(
                        width: 18,
                        height: 18,
                        child: CircularProgressIndicator(strokeWidth: 2),
                      )
                    : const Icon(Icons.send, size: 18),
              ),
            ],
          ),
        ),
      ],
    );
  }
}

