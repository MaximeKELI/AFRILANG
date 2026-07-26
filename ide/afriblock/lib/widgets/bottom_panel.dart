import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

import '../models/problem_item.dart';
import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';

class BottomPanel extends StatelessWidget {
  const BottomPanel({super.key});

  @override
  Widget build(BuildContext context) {
    final wb = context.watch<WorkbenchController>();
    return ColoredBox(
      color: AfriblockColors.panel,
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          SizedBox(
            height: 32,
            child: Row(
              children: [
                _TabChip(
                  label: 'PROBLEMS',
                  selected: wb.bottomTab == BottomTab.problems,
                  badge: wb.problems.length,
                  onTap: () => wb.setBottomTab(BottomTab.problems),
                ),
                _TabChip(
                  label: 'OUTPUT',
                  selected: wb.bottomTab == BottomTab.output,
                  onTap: () => wb.setBottomTab(BottomTab.output),
                ),
                const Spacer(),
                IconButton(
                  tooltip: 'Clear',
                  iconSize: 16,
                  onPressed: () {
                    if (wb.bottomTab == BottomTab.output) {
                      wb.clearOutput();
                    } else {
                      wb.clearProblems();
                    }
                  },
                  icon: const Icon(Icons.delete_outline, color: AfriblockColors.textMuted),
                ),
                IconButton(
                  tooltip: 'Hide panel',
                  iconSize: 16,
                  onPressed: wb.togglePanel,
                  icon: const Icon(Icons.expand_more, color: AfriblockColors.textMuted),
                ),
              ],
            ),
          ),
          const Divider(height: 1, color: AfriblockColors.border),
          Expanded(
            child: wb.bottomTab == BottomTab.problems
                ? _ProblemsList(wb: wb)
                : _OutputView(text: wb.outputLog.toString()),
          ),
        ],
      ),
    );
  }
}

class _TabChip extends StatelessWidget {
  const _TabChip({
    required this.label,
    required this.selected,
    required this.onTap,
    this.badge,
  });

  final String label;
  final bool selected;
  final VoidCallback onTap;
  final int? badge;

  @override
  Widget build(BuildContext context) {
    return InkWell(
      onTap: onTap,
      child: Container(
        padding: const EdgeInsets.symmetric(horizontal: 12),
        alignment: Alignment.center,
        decoration: BoxDecoration(
          border: Border(
            bottom: BorderSide(
              color: selected ? AfriblockColors.primary : Colors.transparent,
              width: 2,
            ),
          ),
        ),
        child: Row(
          children: [
            Text(
              label,
              style: GoogleFonts.plusJakartaSans(
                fontSize: 11,
                fontWeight: FontWeight.w700,
                letterSpacing: 0.8,
                color: selected ? Colors.white : AfriblockColors.textMuted,
              ),
            ),
            if (badge != null && badge! > 0) ...[
              const SizedBox(width: 6),
              Container(
                padding: const EdgeInsets.symmetric(horizontal: 6, vertical: 1),
                decoration: BoxDecoration(
                  color: AfriblockColors.error.withValues(alpha: 0.25),
                  borderRadius: BorderRadius.circular(8),
                ),
                child: Text(
                  '$badge',
                  style: afriblockMono(fontSize: 10, color: AfriblockColors.error),
                ),
              ),
            ],
          ],
        ),
      ),
    );
  }
}

class _ProblemsList extends StatelessWidget {
  const _ProblemsList({required this.wb});
  final WorkbenchController wb;

  @override
  Widget build(BuildContext context) {
    if (wb.problems.isEmpty) {
      return Center(
        child: Text(
          'No problems',
          style: GoogleFonts.plusJakartaSans(color: AfriblockColors.textMuted),
        ),
      );
    }
    return ListView.builder(
      itemCount: wb.problems.length,
      itemBuilder: (context, i) {
        final p = wb.problems[i];
        final icon = switch (p.severity) {
          ProblemSeverity.error => Icons.error_outline,
          ProblemSeverity.warning => Icons.warning_amber_outlined,
          ProblemSeverity.info => Icons.info_outline,
        };
        final color = switch (p.severity) {
          ProblemSeverity.error => AfriblockColors.error,
          ProblemSeverity.warning => AfriblockColors.warning,
          ProblemSeverity.info => AfriblockColors.primary,
        };
        return ListTile(
          dense: true,
          leading: Icon(icon, color: color, size: 18),
          title: Text(p.message, style: afriblockMono(fontSize: 12)),
          subtitle: Text(
            [
              wb.relativePath(p.path),
              if (p.line != null) ':${p.line}',
              if (p.column != null) ':${p.column}',
            ].join(),
            style: afriblockMono(fontSize: 11, color: AfriblockColors.textMuted),
          ),
          onTap: () => wb.openFile(p.path),
        );
      },
    );
  }
}

class _OutputView extends StatelessWidget {
  const _OutputView({required this.text});
  final String text;

  @override
  Widget build(BuildContext context) {
    if (text.trim().isEmpty) {
      return Center(
        child: Text(
          'Output appears here after Run / Check',
          style: GoogleFonts.plusJakartaSans(color: AfriblockColors.textMuted),
        ),
      );
    }
    return SingleChildScrollView(
      padding: const EdgeInsets.all(10),
      reverse: true,
      child: SelectableText(
        text,
        style: afriblockMono(fontSize: 12, height: 1.45),
      ),
    );
  }
}
