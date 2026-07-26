import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';
import '../widgets/activity_bar.dart';
import '../widgets/bottom_panel.dart';
import '../widgets/command_palette.dart';
import '../widgets/editor_area.dart';
import '../widgets/settings_dialog.dart';
import '../widgets/sidebar_explorer.dart';
import '../widgets/status_bar.dart';

class WorkbenchShell extends StatelessWidget {
  const WorkbenchShell({super.key});

  @override
  Widget build(BuildContext context) {
    final wb = context.watch<WorkbenchController>();
    return CallbackShortcuts(
      bindings: <ShortcutActivator, VoidCallback>{
        const SingleActivator(LogicalKeyboardKey.keyP, control: true, shift: true):
            () => wb.showOverlay(OverlayMode.commandPalette),
        const SingleActivator(LogicalKeyboardKey.keyP, meta: true, shift: true):
            () => wb.showOverlay(OverlayMode.commandPalette),
        const SingleActivator(LogicalKeyboardKey.keyP, control: true):
            () => wb.showOverlay(OverlayMode.quickOpen),
        const SingleActivator(LogicalKeyboardKey.keyP, meta: true):
            () => wb.showOverlay(OverlayMode.quickOpen),
        const SingleActivator(LogicalKeyboardKey.keyS, control: true):
            () => wb.saveActive(),
        const SingleActivator(LogicalKeyboardKey.keyS, meta: true):
            () => wb.saveActive(),
        const SingleActivator(LogicalKeyboardKey.keyW, control: true):
            () => wb.closeActiveTab(),
        const SingleActivator(LogicalKeyboardKey.keyW, meta: true):
            () => wb.closeActiveTab(),
        const SingleActivator(LogicalKeyboardKey.f5): () => wb.runActive(),
        const SingleActivator(LogicalKeyboardKey.f6): () => wb.startDebug(),
        const SingleActivator(LogicalKeyboardKey.keyB, control: true, shift: true):
            () => wb.buildActiveTarget(),
        const SingleActivator(LogicalKeyboardKey.keyB, meta: true, shift: true):
            () => wb.buildActiveTarget(),
        const SingleActivator(LogicalKeyboardKey.keyJ, control: true):
            () => wb.togglePanel(),
        const SingleActivator(LogicalKeyboardKey.keyJ, meta: true):
            () => wb.togglePanel(),
        const SingleActivator(LogicalKeyboardKey.backslash, control: true):
            () => wb.toggleSplit(),
        const SingleActivator(LogicalKeyboardKey.backslash, meta: true):
            () => wb.toggleSplit(),
        const SingleActivator(LogicalKeyboardKey.escape): () {
          if (wb.overlay != OverlayMode.none) wb.hideOverlay();
        },
      },
      child: Focus(
        autofocus: true,
        child: Stack(
          children: [
            Column(
              children: [
                _TitleBar(wb: wb),
                _BuildToolbar(wb: wb),
                Expanded(
                  child: Row(
                    children: [
                      const ActivityBar(),
                      if (wb.sidebarVisible) ...[
                        SizedBox(width: wb.sidebarWidth, child: const SidebarExplorer()),
                        _ResizeHandle(
                          horizontal: true,
                          onDrag: (dx) => wb.setSidebarWidth(wb.sidebarWidth + dx),
                        ),
                      ],
                      const Expanded(child: EditorArea()),
                    ],
                  ),
                ),
                if (wb.panelVisible) ...[
                  _ResizeHandle(
                    horizontal: false,
                    onDrag: (dy) => wb.setPanelHeight(wb.panelHeight - dy),
                  ),
                  SizedBox(height: wb.panelHeight, child: const BottomPanel()),
                ],
                const StatusBar(),
              ],
            ),
            if (wb.overlay == OverlayMode.commandPalette) const CommandPalette(),
            if (wb.overlay == OverlayMode.quickOpen) const QuickOpenOverlay(),
          ],
        ),
      ),
    );
  }
}

class _TitleBar extends StatelessWidget {
  const _TitleBar({required this.wb});
  final WorkbenchController wb;

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 36,
      color: AfriblockColors.surface,
      padding: const EdgeInsets.symmetric(horizontal: 12),
      child: Row(
        children: [
          Text(
            'AFRIBLOCK',
            style: GoogleFonts.plusJakartaSans(
              fontWeight: FontWeight.w800,
              fontSize: 13,
              letterSpacing: 0.4,
            ),
          ),
          const SizedBox(width: 16),
          _MenuBtn(label: 'File', items: [
            _MenuAction('Open Folder…', () => wb.openFolder()),
            _MenuAction('Save', () => wb.saveActive()),
            _MenuAction('Close Editor', () => wb.closeActiveTab()),
          ]),
          _MenuBtn(label: 'Run', items: [
            _MenuAction('Build', () => wb.buildActiveTarget()),
            _MenuAction('Run', () => wb.runActive()),
            _MenuAction('Check', () => wb.checkActive()),
            _MenuAction('Debug', () => wb.startDebug()),
            _MenuAction('Test', () => wb.runTests()),
          ]),
          _MenuBtn(label: 'View', items: [
            _MenuAction('Command Palette…', () => wb.showOverlay(OverlayMode.commandPalette)),
            _MenuAction('Go to File…', () => wb.showOverlay(OverlayMode.quickOpen)),
            _MenuAction('Toggle Panel', () => wb.togglePanel()),
            _MenuAction('Split Editor', () => wb.toggleSplit()),
            _MenuAction('Toggle Theme', () => wb.cycleTheme()),
          ]),
          const Spacer(),
          if (wb.projects.project != null)
            Text(
              wb.projects.project!.name,
              style: GoogleFonts.plusJakartaSans(
                fontSize: 12,
                color: AfriblockColors.accent,
                fontWeight: FontWeight.w600,
              ),
            ),
        ],
      ),
    );
  }
}

class _BuildToolbar extends StatelessWidget {
  const _BuildToolbar({required this.wb});
  final WorkbenchController wb;

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 34,
      color: AfriblockColors.panel,
      padding: const EdgeInsets.symmetric(horizontal: 8),
      child: Row(
        children: [
          SizedBox(
            width: 140,
            child: DropdownButtonHideUnderline(
              child: DropdownButton<String>(
                isExpanded: true,
                value: wb.availableTargets.any((t) => t.id == wb.activeTargetId)
                    ? wb.activeTargetId
                    : wb.availableTargets.first.id,
                items: [
                  for (final t in wb.availableTargets)
                    DropdownMenuItem(value: t.id, child: Text(t.label, style: const TextStyle(fontSize: 13))),
                ],
                onChanged: (v) {
                  if (v != null) wb.setActiveTarget(v);
                },
              ),
            ),
          ),
          IconButton(
            tooltip: 'Build',
            iconSize: 18,
            onPressed: wb.busy ? null : wb.buildActiveTarget,
            icon: const Icon(Icons.handyman_outlined),
          ),
          IconButton(
            tooltip: 'Run',
            iconSize: 18,
            onPressed: wb.busy ? null : wb.runActive,
            icon: const Icon(Icons.play_arrow),
          ),
          IconButton(
            tooltip: 'Debug',
            iconSize: 18,
            onPressed: wb.busy ? null : wb.startDebug,
            icon: const Icon(Icons.bug_report_outlined),
          ),
          IconButton(
            tooltip: 'Settings',
            iconSize: 18,
            onPressed: () => showAfriblockSettings(context),
            icon: const Icon(Icons.settings_outlined),
          ),
          const Spacer(),
          Text(
            wb.lspState,
            style: afriblockMono(fontSize: 11, color: AfriblockColors.textMuted),
          ),
        ],
      ),
    );
  }
}

class _MenuAction {
  const _MenuAction(this.label, this.onTap);
  final String label;
  final VoidCallback onTap;
}

class _MenuBtn extends StatelessWidget {
  const _MenuBtn({required this.label, required this.items});
  final String label;
  final List<_MenuAction> items;

  @override
  Widget build(BuildContext context) {
    return PopupMenuButton<_MenuAction>(
      tooltip: label,
      offset: const Offset(0, 28),
      color: AfriblockColors.panelElevated,
      onSelected: (a) => a.onTap(),
      itemBuilder: (context) => [
        for (final a in items) PopupMenuItem(value: a, child: Text(a.label)),
      ],
      child: Padding(
        padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 8),
        child: Text(label, style: GoogleFonts.plusJakartaSans(fontSize: 13)),
      ),
    );
  }
}

class _ResizeHandle extends StatelessWidget {
  const _ResizeHandle({required this.horizontal, required this.onDrag});
  final bool horizontal;
  final ValueChanged<double> onDrag;

  @override
  Widget build(BuildContext context) {
    return MouseRegion(
      cursor: horizontal ? SystemMouseCursors.resizeColumn : SystemMouseCursors.resizeRow,
      child: GestureDetector(
        behavior: HitTestBehavior.opaque,
        onHorizontalDragUpdate: horizontal ? (d) => onDrag(d.delta.dx) : null,
        onVerticalDragUpdate: horizontal ? null : (d) => onDrag(d.delta.dy),
        child: Container(
          width: horizontal ? 4 : null,
          height: horizontal ? null : 4,
          color: AfriblockColors.border.withValues(alpha: 0.35),
        ),
      ),
    );
  }
}
