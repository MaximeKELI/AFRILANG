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
    if (wb.tabs.isEmpty) return const WelcomePage();

    Widget editorStack(int? index) {
      final i = index ?? 0;
      return Column(
        children: [
          _TabBar(wb: wb, groupIndex: index),
          Expanded(
            child: IndexedStack(
              index: i.clamp(0, wb.tabs.length - 1),
              children: [
                for (final tab in wb.tabs)
                  CodeEditor(
                    key: ValueKey('${tab.path}-${index ?? 0}'),
                    path: tab.path,
                    initialContent: tab.content,
                    onChanged: (v) {
                      if (wb.activeTab?.path == tab.path) {
                        wb.updateActiveContent(v);
                      } else {
                        tab.applyEdit(v);
                      }
                    },
                    onToggleBreakpoint: (line) => wb.toggleBreakpointAt(tab.path, line),
                    breakpoints: wb.debug.breakpoints
                        .where((b) => b.path == tab.path)
                        .map((b) => b.line)
                        .toSet(),
                  ),
              ],
            ),
          ),
        ],
      );
    }

    if (!wb.splitEditor) {
      return editorStack(wb.activeTabIndex);
    }

    return Row(
      children: [
        Expanded(child: editorStack(wb.activeTabIndex)),
        Container(width: 1, color: AfriblockColors.border),
        Expanded(
          child: editorStack(wb.secondaryTabIndex ?? wb.activeTabIndex),
        ),
      ],
    );
  }
}

class _TabBar extends StatelessWidget {
  const _TabBar({required this.wb, this.groupIndex});
  final WorkbenchController wb;
  final int? groupIndex;

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
          final active = i == (groupIndex ?? wb.activeTabIndex);
          return InkWell(
            onTap: () {
              wb.selectTab(i);
              if (wb.splitEditor && groupIndex != null && groupIndex != wb.activeTabIndex) {
                wb.setSecondaryTab(i);
              }
            },
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
                    child: const Icon(Icons.close, size: 14, color: AfriblockColors.textMuted),
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
