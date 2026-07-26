import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

import '../models/workspace_node.dart';
import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';

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
      return Center(
        child: FilledButton(
          onPressed: () => wb.openFolder(),
          child: const Text('Open Folder'),
        ),
      );
    }
    final root = wb.rootNode!;
    return ListView(
      padding: const EdgeInsets.symmetric(vertical: 4),
      children: [
        if (proj != null)
          Padding(
            padding: const EdgeInsets.fromLTRB(12, 8, 12, 4),
            child: Text(
              '${proj.name}  ·  ${proj.version ?? ""}',
              style: GoogleFonts.plusJakartaSans(
                fontSize: 12,
                fontWeight: FontWeight.w600,
                color: AfriblockColors.accent,
              ),
            ),
          ),
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
        // Outline for active file
        if (wb.outline.isNotEmpty) ...[
          Padding(
            padding: const EdgeInsets.fromLTRB(12, 4, 12, 4),
            child: Text('OUTLINE',
                style: GoogleFonts.plusJakartaSans(
                    fontSize: 10,
                    fontWeight: FontWeight.w700,
                    color: AfriblockColors.textMuted)),
          ),
          ...wb.outline.map(
            (s) => ListTile(
              dense: true,
              leading: const Icon(Icons.code, size: 14),
              title: Text(s.name, style: afriblockMono(fontSize: 12)),
              subtitle: Text('L${s.line}', style: afriblockMono(fontSize: 10, color: AfriblockColors.textMuted)),
              onTap: () => wb.openFile(wb.activeTab!.path, line: s.line),
            ),
          ),
          const Divider(color: AfriblockColors.border),
        ],
        ...root.children.map((c) => _TreeTile(node: c, depth: 0)),
      ],
    );
  }
}

class _TreeTile extends StatelessWidget {
  const _TreeTile({required this.node, required this.depth});
  final WorkspaceNode node;
  final int depth;

  @override
  Widget build(BuildContext context) {
    final wb = context.read<WorkbenchController>();
    final active = wb.activeTab?.path == node.path;
    return Column(
      crossAxisAlignment: CrossAxisAlignment.stretch,
      children: [
        InkWell(
          onTap: () {
            if (node.isDirectory) {
              wb.toggleExpand(node);
            } else {
              wb.openFile(node.path);
            }
          },
          child: Container(
            color: active
                ? AfriblockColors.primaryDeep.withValues(alpha: 0.25)
                : Colors.transparent,
            padding: EdgeInsets.only(left: 8.0 + depth * 12, right: 8, top: 3, bottom: 3),
            child: Row(
              children: [
                Icon(
                  node.isDirectory
                      ? (node.expanded ? Icons.keyboard_arrow_down : Icons.keyboard_arrow_right)
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
        if (node.isDirectory && node.expanded)
          ...node.children.map((c) => _TreeTile(node: c, depth: depth + 1)),
      ],
    );
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
