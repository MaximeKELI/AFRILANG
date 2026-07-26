import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';
import 'settings_dialog.dart';

class ActivityBar extends StatelessWidget {
  const ActivityBar({super.key});

  @override
  Widget build(BuildContext context) {
    final wb = context.watch<WorkbenchController>();
    Widget item(IconData icon, String tip, SidebarView view) {
      final selected = wb.sidebarVisible && wb.sidebarView == view;
      return Tooltip(
        message: tip,
        child: InkWell(
          onTap: () => wb.setSidebarView(view),
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

    return Container(
      width: 48,
      color: AfriblockColors.activityBar,
      child: Column(
        children: [
          const SizedBox(height: 8),
          item(Icons.folder_outlined, 'Explorer', SidebarView.explorer),
          item(Icons.search, 'Search', SidebarView.search),
          item(Icons.source_outlined, 'Source Control', SidebarView.scm),
          item(Icons.play_circle_outline, 'Run', SidebarView.run),
          item(Icons.bug_report_outlined, 'Run & Debug', SidebarView.debug),
          item(Icons.science_outlined, 'Testing', SidebarView.test),
          item(Icons.hub_outlined, 'AFRILANG', SidebarView.afrilang),
          item(Icons.auto_awesome, 'AI Assist', SidebarView.ai),
          item(Icons.extension_outlined, 'Extensions', SidebarView.extensions),
          const Spacer(),
          Tooltip(
            message: 'Settings',
            child: InkWell(
              onTap: () => showAfriblockSettings(context),
              child: const SizedBox(
                width: 48,
                height: 44,
                child: Icon(Icons.settings_outlined, size: 22, color: AfriblockColors.textMuted),
              ),
            ),
          ),
          const SizedBox(height: 8),
        ],
      ),
    );
  }
}
