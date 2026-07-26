import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';
import 'code_editor.dart';
import 'welcome_page.dart';

class EditorArea extends StatelessWidget {
  const EditorArea({super.key});

  @override
  Widget build(BuildContext context) {
    final wb = context.watch<WorkbenchController>();
    if (wb.tabs.isEmpty) {
      return const WelcomePage();
    }
    return Column(
      children: [
        _TabBar(wb: wb),
        Expanded(
          child: IndexedStack(
            index: wb.activeTabIndex ?? 0,
            children: [
              for (final tab in wb.tabs)
                CodeEditor(
                  key: ValueKey(tab.path),
                  path: tab.path,
                  initialContent: tab.content,
                  onChanged: (v) {
                    if (wb.activeTab?.path == tab.path) {
                      wb.updateActiveContent(v);
                    } else {
                      tab.applyEdit(v);
                    }
                  },
                ),
            ],
          ),
        ),
      ],
    );
  }
}

class _TabBar extends StatelessWidget {
  const _TabBar({required this.wb});
  final WorkbenchController wb;

  @override
  Widget build(BuildContext context) {
    return Container(
      height: 36,
      color: AfriblockColors.surface,
      child: ListView.builder(
        scrollDirection: Axis.horizontal,
        itemCount: wb.tabs.length,
        itemBuilder: (context, i) {
          final tab = wb.tabs[i];
          final active = i == wb.activeTabIndex;
          return InkWell(
            onTap: () => wb.selectTab(i),
            child: Container(
              constraints: const BoxConstraints(minWidth: 120, maxWidth: 220),
              padding: const EdgeInsets.symmetric(horizontal: 10),
              decoration: BoxDecoration(
                color: active ? AfriblockColors.tabActive : AfriblockColors.tabInactive,
                border: Border(
                  right: const BorderSide(color: AfriblockColors.border),
                  top: BorderSide(
                    color: active ? AfriblockColors.primary : Colors.transparent,
                    width: 2,
                  ),
                ),
              ),
              child: Row(
                children: [
                  Icon(
                    tab.name.endsWith('.afr')
                        ? Icons.code
                        : Icons.insert_drive_file_outlined,
                    size: 14,
                    color: AfriblockColors.textMuted,
                  ),
                  const SizedBox(width: 6),
                  Expanded(
                    child: Text(
                      '${tab.dirty ? '● ' : ''}${tab.name}',
                      overflow: TextOverflow.ellipsis,
                      style: GoogleFonts.plusJakartaSans(
                        fontSize: 12.5,
                        fontWeight: active ? FontWeight.w600 : FontWeight.w400,
                        color: active ? Colors.white : AfriblockColors.textMuted,
                      ),
                    ),
                  ),
                  InkWell(
                    onTap: () => wb.closeTab(i),
                    child: const Padding(
                      padding: EdgeInsets.all(4),
                      child: Icon(Icons.close, size: 14, color: AfriblockColors.textMuted),
                    ),
                  ),
                ],
              ),
            ),
          );
        },
      ),
    );
  }
}
