import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';
import 'package:xterm/xterm.dart';

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
                _TabChip(
                  label: 'DEBUG CONSOLE',
                  selected: wb.bottomTab == BottomTab.debugConsole,
                  onTap: () => wb.setBottomTab(BottomTab.debugConsole),
                ),
                _TabChip(
                  label: 'TERMINAL',
                  selected: wb.bottomTab == BottomTab.terminal,
                  onTap: () {
                    if (wb.terminals.sessions.isEmpty) wb.openTerminal();
                    wb.setBottomTab(BottomTab.terminal);
                  },
                ),
                _TabChip(
                  label: 'TEST',
                  selected: wb.bottomTab == BottomTab.testResults,
                  onTap: () => wb.setBottomTab(BottomTab.testResults),
                ),
                const Spacer(),
                if (wb.cliRunning || wb.busy)
                  IconButton(
                    tooltip: 'Stop (Shift+F5)',
                    iconSize: 16,
                    onPressed: wb.stopCli,
                    icon: const Icon(Icons.stop, color: AfriblockColors.error),
                  ),
                IconButton(
                  tooltip: 'Clear',
                  iconSize: 16,
                  onPressed: () {
                    if (wb.bottomTab == BottomTab.output) wb.clearOutput();
                    if (wb.bottomTab == BottomTab.problems) wb.clearProblems();
                    if (wb.bottomTab == BottomTab.debugConsole) {
                      wb.clearDebugConsole();
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
          Expanded(child: _content(wb)),
        ],
      ),
    );
  }

  Widget _content(WorkbenchController wb) {
    switch (wb.bottomTab) {
      case BottomTab.problems:
        return _ProblemsList(wb: wb);
      case BottomTab.output:
        return _OutputPane(wb: wb);
      case BottomTab.debugConsole:
        return _OutputView(text: wb.debug.console.toString());
      case BottomTab.terminal:
        return _TerminalView(wb: wb);
      case BottomTab.testResults:
        return _OutputView(
          text: wb.tests.items.isEmpty
              ? 'No tests discovered. Open a project and refresh Test Explorer.'
              : wb.tests.items.map((t) => '${t.name}  ${t.path}:${t.line}').join('\n'),
        );
    }
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
        padding: const EdgeInsets.symmetric(horizontal: 10),
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
                letterSpacing: 0.6,
                color: selected ? Colors.white : AfriblockColors.textMuted,
              ),
            ),
            if (badge != null && badge! > 0) ...[
              const SizedBox(width: 6),
              Text('$badge', style: afriblockMono(fontSize: 10, color: AfriblockColors.error)),
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
        child: Text('No problems', style: GoogleFonts.plusJakartaSans(color: AfriblockColors.textMuted)),
      );
    }
    return ListView.builder(
      itemCount: wb.problems.length,
      itemBuilder: (context, i) {
        final p = wb.problems[i];
        final color = switch (p.severity) {
          ProblemSeverity.error => AfriblockColors.error,
          ProblemSeverity.warning => AfriblockColors.warning,
          ProblemSeverity.info => AfriblockColors.primary,
        };
        return ListTile(
          dense: true,
          leading: Icon(Icons.error_outline, color: color, size: 18),
          title: Text(p.message, style: afriblockMono(fontSize: 12)),
          subtitle: Text(
            [
              if (p.path.isNotEmpty) wb.relativePath(p.path),
              if (p.line != null) ':${p.line}',
              if (p.column != null) ':${p.column}',
            ].join(),
            style: afriblockMono(fontSize: 11, color: AfriblockColors.textMuted),
          ),
          trailing: Row(
            mainAxisSize: MainAxisSize.min,
            children: [
              IconButton(
                tooltip: 'Explain with AI',
                iconSize: 18,
                onPressed: () => wb.explainProblem(p),
                icon: const Icon(Icons.auto_awesome, size: 18),
              ),
              IconButton(
                tooltip: 'Fix with AI',
                iconSize: 18,
                onPressed: () => wb.fixProblemWithAi(p),
                icon: const Icon(Icons.auto_fix_high, size: 18),
              ),
            ],
          ),
          onTap: p.path.isEmpty
              ? null
              : () => wb.openFile(p.path, line: p.line, column: p.column),
        );
      },
    );
  }
}

class _OutputPane extends StatelessWidget {
  const _OutputPane({required this.wb});
  final WorkbenchController wb;

  @override
  Widget build(BuildContext context) {
    return Column(
      crossAxisAlignment: CrossAxisAlignment.stretch,
      children: [
        Expanded(child: _OutputView(text: wb.outputLog.toString())),
        if (wb.cliRunning) const _StdinBar(),
      ],
    );
  }
}

class _StdinBar extends StatefulWidget {
  const _StdinBar();

  @override
  State<_StdinBar> createState() => _StdinBarState();
}

class _StdinBarState extends State<_StdinBar> {
  final _ctrl = TextEditingController();
  final _focus = FocusNode();

  @override
  void dispose() {
    _ctrl.dispose();
    _focus.dispose();
    super.dispose();
  }

  void _submit(WorkbenchController wb) {
    final line = _ctrl.text;
    wb.writeCliStdin(line);
    _ctrl.clear();
    _focus.requestFocus();
  }

  @override
  Widget build(BuildContext context) {
    final wb = context.read<WorkbenchController>();
    return Container(
      height: 36,
      decoration: const BoxDecoration(
        border: Border(top: BorderSide(color: AfriblockColors.border)),
        color: AfriblockColors.panelElevated,
      ),
      padding: const EdgeInsets.symmetric(horizontal: 8),
      child: Row(
        children: [
          Text('stdin ›', style: afriblockMono(fontSize: 11, color: AfriblockColors.accent)),
          const SizedBox(width: 8),
          Expanded(
            child: TextField(
              controller: _ctrl,
              focusNode: _focus,
              style: afriblockMono(fontSize: 12),
              decoration: const InputDecoration(
                hintText: 'Send input to running program…',
                isDense: true,
                border: InputBorder.none,
              ),
              onSubmitted: (_) => _submit(wb),
            ),
          ),
          IconButton(
            tooltip: 'Send',
            iconSize: 16,
            onPressed: () => _submit(wb),
            icon: const Icon(Icons.send, size: 16),
          ),
        ],
      ),
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
        child: Text('Output appears after Build / Run / Check',
            style: GoogleFonts.plusJakartaSans(color: AfriblockColors.textMuted)),
      );
    }
    return SingleChildScrollView(
      padding: const EdgeInsets.all(10),
      reverse: true,
      child: SelectableText(text, style: afriblockMono(fontSize: 12, height: 1.45)),
    );
  }
}

class _TerminalView extends StatelessWidget {
  const _TerminalView({required this.wb});
  final WorkbenchController wb;

  @override
  Widget build(BuildContext context) {
    final sessions = wb.terminals.sessions;
    final active = wb.terminals.active;
    return Column(
      children: [
        SizedBox(
          height: 28,
          child: Row(
            children: [
              for (final s in sessions)
                InkWell(
                  onTap: () => wb.terminals.select(s.id),
                  child: Container(
                    padding: const EdgeInsets.symmetric(horizontal: 10),
                    color: s.id == active?.id
                        ? AfriblockColors.panelElevated
                        : Colors.transparent,
                    child: Text(s.title, style: GoogleFonts.plusJakartaSans(fontSize: 12)),
                  ),
                ),
              IconButton(
                iconSize: 16,
                onPressed: wb.openTerminal,
                icon: const Icon(Icons.add),
              ),
            ],
          ),
        ),
        Expanded(
          child: active == null
              ? Center(
                  child: TextButton(
                    onPressed: wb.openTerminal,
                    child: const Text('Create Terminal'),
                  ),
                )
              : TerminalView(active.terminal),
        ),
      ],
    );
  }
}
