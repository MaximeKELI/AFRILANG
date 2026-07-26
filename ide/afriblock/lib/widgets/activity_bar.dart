import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';

class ActivityBar extends StatelessWidget {
  const ActivityBar({super.key});

  @override
  Widget build(BuildContext context) {
    final wb = context.watch<WorkbenchController>();
    return Container(
      width: 48,
      color: AfriblockColors.activityBar,
      child: Column(
        children: [
          const SizedBox(height: 8),
          _Item(
            icon: Icons.folder_outlined,
            tooltip: 'Explorer',
            selected: wb.sidebarVisible && wb.sidebarView == SidebarView.explorer,
            onTap: () => wb.setSidebarView(SidebarView.explorer),
          ),
          _Item(
            icon: Icons.search,
            tooltip: 'Search (soon)',
            selected: wb.sidebarVisible && wb.sidebarView == SidebarView.search,
            onTap: () => wb.setSidebarView(SidebarView.search),
          ),
          _Item(
            icon: Icons.play_circle_outline,
            tooltip: 'Run',
            selected: wb.sidebarVisible && wb.sidebarView == SidebarView.run,
            onTap: () => wb.setSidebarView(SidebarView.run),
          ),
          _Item(
            icon: Icons.extension_outlined,
            tooltip: 'Extensions (soon)',
            selected: wb.sidebarVisible && wb.sidebarView == SidebarView.extensions,
            onTap: () => wb.setSidebarView(SidebarView.extensions),
          ),
          const Spacer(),
          _Item(
            icon: Icons.settings_outlined,
            tooltip: 'About / settings',
            selected: false,
            onTap: () => _showAbout(context, wb),
          ),
          const SizedBox(height: 8),
        ],
      ),
    );
  }

  Future<void> _showAbout(BuildContext context, WorkbenchController wb) async {
    final bin = await wb.settings.resolveAfrilangBinary();
    if (!context.mounted) return;
    await showDialog<void>(
      context: context,
      builder: (ctx) => AlertDialog(
        backgroundColor: AfriblockColors.panelElevated,
        title: const Text('AFRIBLOCK'),
        content: Text(
          'IDE desktop Flutter pour AFRILANG — v0.1\n\n'
          'afrilang: ${bin ?? "(not found)"}\n\n'
          'Phase 2: LSP, terminal PTY, Git.',
          style: afriblockMono(fontSize: 12),
        ),
        actions: [
          TextButton(
            onPressed: () => Navigator.pop(ctx),
            child: const Text('OK'),
          ),
        ],
      ),
    );
  }
}

class _Item extends StatelessWidget {
  const _Item({
    required this.icon,
    required this.tooltip,
    required this.selected,
    required this.onTap,
  });

  final IconData icon;
  final String tooltip;
  final bool selected;
  final VoidCallback onTap;

  @override
  Widget build(BuildContext context) {
    return Tooltip(
      message: tooltip,
      child: InkWell(
        onTap: onTap,
        child: Container(
          width: 48,
          height: 44,
          decoration: BoxDecoration(
            border: Border(
              left: BorderSide(
                color: selected ? AfriblockColors.primary : Colors.transparent,
                width: 2,
              ),
            ),
            color: selected
                ? AfriblockColors.panel.withValues(alpha: 0.6)
                : Colors.transparent,
          ),
          child: Icon(
            icon,
            size: 22,
            color: selected ? Colors.white : AfriblockColors.textMuted,
          ),
        ),
      ),
    );
  }
}
