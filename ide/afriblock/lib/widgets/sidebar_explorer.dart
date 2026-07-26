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
          _Header(
            title: switch (wb.sidebarView) {
              SidebarView.explorer => 'EXPLORER',
              SidebarView.search => 'SEARCH',
              SidebarView.run => 'RUN',
              SidebarView.extensions => 'EXTENSIONS',
            },
          ),
          Expanded(child: _body(context, wb)),
        ],
      ),
    );
  }

  Widget _body(BuildContext context, WorkbenchController wb) {
    switch (wb.sidebarView) {
      case SidebarView.explorer:
        return _ExplorerBody(wb: wb);
      case SidebarView.search:
        return _Soon(message: 'Search — phase 2');
      case SidebarView.run:
        return _RunPanel(wb: wb);
      case SidebarView.extensions:
        return _Soon(message: 'Extensions — phase 2');
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

class _Soon extends StatelessWidget {
  const _Soon({required this.message});
  final String message;

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Padding(
        padding: const EdgeInsets.all(16),
        child: Text(
          message,
          textAlign: TextAlign.center,
          style: GoogleFonts.plusJakartaSans(
            color: AfriblockColors.textMuted,
            fontSize: 13,
          ),
        ),
      ),
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
          Text(
            wb.activeTab?.name ?? 'No file open',
            style: GoogleFonts.plusJakartaSans(
              fontWeight: FontWeight.w600,
              fontSize: 13,
            ),
          ),
          const SizedBox(height: 12),
          FilledButton.icon(
            onPressed: wb.busy ? null : wb.runActive,
            icon: const Icon(Icons.play_arrow, size: 18),
            label: const Text('Run'),
            style: FilledButton.styleFrom(
              backgroundColor: AfriblockColors.primaryDeep,
              foregroundColor: Colors.white,
            ),
          ),
          const SizedBox(height: 8),
          OutlinedButton.icon(
            onPressed: wb.busy ? null : wb.checkActive,
            icon: const Icon(Icons.fact_check_outlined, size: 18),
            label: const Text('Check'),
            style: OutlinedButton.styleFrom(
              foregroundColor: AfriblockColors.text,
              side: const BorderSide(color: AfriblockColors.border),
            ),
          ),
        ],
      ),
    );
  }
}

class _ExplorerBody extends StatelessWidget {
  const _ExplorerBody({required this.wb});
  final WorkbenchController wb;

  @override
  Widget build(BuildContext context) {
    if (wb.rootNode == null) {
      return Center(
        child: Padding(
          padding: const EdgeInsets.all(16),
          child: Column(
            mainAxisSize: MainAxisSize.min,
            children: [
              Text(
                'No folder opened',
                style: GoogleFonts.plusJakartaSans(
                  color: AfriblockColors.textMuted,
                ),
              ),
              const SizedBox(height: 12),
              FilledButton(
                onPressed: () => wb.openFolder(),
                style: FilledButton.styleFrom(
                  backgroundColor: AfriblockColors.primaryDeep,
                ),
                child: const Text('Open Folder'),
              ),
            ],
          ),
        ),
      );
    }

    final root = wb.rootNode!;
    return ListView(
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
              letterSpacing: 0.6,
            ),
          ),
        ),
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
                    style: GoogleFonts.plusJakartaSans(
                      fontSize: 13,
                      color: active ? Colors.white : AfriblockColors.text,
                    ),
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
