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
import '../widgets/editor_overlays.dart';
import '../widgets/new_item_dialogs.dart';
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
        const SingleActivator(LogicalKeyboardKey.f5): () {
          if (wb.debug.paused) {
            wb.debugContinue();
          } else if (wb.cliRunning || wb.busy) {
            wb.stopCli();
          } else {
            wb.runActive();
          }
        },
        const SingleActivator(LogicalKeyboardKey.f5, shift: true): () => wb.stopCli(),
        const SingleActivator(LogicalKeyboardKey.f6): () => wb.startDebug(),
        const SingleActivator(LogicalKeyboardKey.f10): () => wb.debugStepOver(),
        const SingleActivator(LogicalKeyboardKey.f11): () => wb.debugStepInto(),
        const SingleActivator(LogicalKeyboardKey.f11, shift: true): () => wb.debugStepOut(),
        const SingleActivator(LogicalKeyboardKey.f2): () => promptRenameSymbol(context),
        const SingleActivator(LogicalKeyboardKey.f12): () => wb.goToDefinitionAtCaret(),
        const SingleActivator(LogicalKeyboardKey.keyB, control: true, shift: true):
            () => wb.buildActiveTarget(),
        const SingleActivator(LogicalKeyboardKey.keyB, meta: true, shift: true):
            () => wb.buildActiveTarget(),
        const SingleActivator(LogicalKeyboardKey.keyJ, control: true):
            () => wb.togglePanel(),
        const SingleActivator(LogicalKeyboardKey.keyJ, meta: true):
            () => wb.togglePanel(),
        const SingleActivator(LogicalKeyboardKey.keyF, control: true):
            () => wb.showOverlay(OverlayMode.findReplace),
        const SingleActivator(LogicalKeyboardKey.keyF, meta: true):
            () => wb.showOverlay(OverlayMode.findReplace),
        const SingleActivator(LogicalKeyboardKey.keyG, control: true):
            () => wb.showOverlay(OverlayMode.goToLine),
        const SingleActivator(LogicalKeyboardKey.keyG, meta: true):
            () => wb.showOverlay(OverlayMode.goToLine),
        const SingleActivator(LogicalKeyboardKey.f4): () => wb.toggleSplit(),
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
            if (wb.overlay == OverlayMode.findReplace) const FindReplaceOverlay(),
            if (wb.overlay == OverlayMode.goToLine) const GoToLineOverlay(),
            if (wb.overlay == OverlayMode.snippets) const SnippetsOverlay(),
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
          const CreateActionsRow(compact: true),
          const SizedBox(width: 8),
          _MenuBtn(label: 'File', items: [
            _MenuAction('Nouveau projet…', () => promptNewProject(context)),
            _MenuAction('Nouveau fichier…', () => promptCreateFile(context)),
            _MenuAction('Nouveau dossier…', () => promptCreateFolder(context)),
            _MenuAction('Ouvrir un dossier…', () => promptOpenFolder(context)),
            _MenuAction('Save', () => wb.saveActive()),
            _MenuAction('Discard Changes', () => wb.discardActiveChanges()),
            _MenuAction('Close Editor', () => wb.closeActiveTab()),
          ]),
          _MenuBtn(label: 'Edit', items: [
            _MenuAction('Find…', () => wb.showOverlay(OverlayMode.findReplace)),
            _MenuAction('Go to Line…', () => wb.showOverlay(OverlayMode.goToLine)),
            _MenuAction('Insert Snippet…', () => wb.showOverlay(OverlayMode.snippets)),
            _MenuAction('Duplicate Line', () => wb.duplicateActiveLine()),
            _MenuAction('Toggle Comment', () => wb.toggleActiveComment()),
            _MenuAction('Format Document', () => wb.formatActive()),
          ]),
          _MenuBtn(label: 'Run', items: [
            _MenuAction('Build', () => wb.buildActiveTarget()),
            _MenuAction('Run', () => wb.runActive()),
            _MenuAction('Stop', () => wb.stopCli()),
            _MenuAction('Check', () => wb.checkActive()),
            _MenuAction('Lint', () => wb.lintWorkspace()),
            _MenuAction('Debug', () => wb.startDebug()),
            _MenuAction('Test', () => wb.runTests()),
          ]),
          _MenuBtn(label: 'View', items: [
            _MenuAction('Command Palette…', () => wb.showOverlay(OverlayMode.commandPalette)),
            _MenuAction('Go to File…', () => wb.showOverlay(OverlayMode.quickOpen)),
            _MenuAction('Go to Definition', () => wb.goToDefinitionAtCaret()),
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
            tooltip: 'Nouveau projet',
            iconSize: 18,
            onPressed: () => promptNewProject(context),
            icon: const Icon(Icons.rocket_launch_outlined, color: AfriblockColors.accent),
          ),
          IconButton(
            tooltip: 'Nouveau fichier',
            iconSize: 18,
            onPressed: () => promptCreateFile(context),
            icon: const Icon(Icons.note_add_outlined),
          ),
          IconButton(
            tooltip: 'Nouveau dossier',
            iconSize: 18,
            onPressed: () => promptCreateFolder(context),
            icon: const Icon(Icons.create_new_folder_outlined),
          ),
          IconButton(
            tooltip: 'Build',
            iconSize: 18,
            onPressed: wb.busy ? null : wb.buildActiveTarget,
            icon: const Icon(Icons.handyman_outlined),
          ),
          IconButton(
            tooltip: wb.cliRunning || wb.busy ? 'Stop (Shift+F5)' : 'Run (F5)',
            iconSize: 18,
            onPressed: wb.cliRunning || wb.busy ? wb.stopCli : wb.runActive,
            icon: Icon(
              wb.cliRunning || wb.busy ? Icons.stop : Icons.play_arrow,
              color: wb.cliRunning || wb.busy ? AfriblockColors.error : null,
            ),
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
