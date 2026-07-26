import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';

class IdeCommand {
  const IdeCommand({
    required this.id,
    required this.label,
    required this.run,
    this.shortcut,
  });

  final String id;
  final String label;
  final String? shortcut;
  final Future<void> Function(WorkbenchController wb) run;
}

List<IdeCommand> buildCommands() => [
      IdeCommand(
        id: 'openFolder',
        label: 'File: Open Folder…',
        shortcut: 'Ctrl+K Ctrl+O',
        run: (wb) => wb.openFolder(),
      ),
      IdeCommand(
        id: 'save',
        label: 'File: Save',
        shortcut: 'Ctrl+S',
        run: (wb) => wb.saveActive(),
      ),
      IdeCommand(
        id: 'run',
        label: 'AFRILANG: Run File',
        shortcut: 'F5',
        run: (wb) => wb.runActive(),
      ),
      IdeCommand(
        id: 'check',
        label: 'AFRILANG: Check File',
        shortcut: 'Ctrl+Shift+B',
        run: (wb) => wb.checkActive(),
      ),
      IdeCommand(
        id: 'togglePanel',
        label: 'View: Toggle Panel',
        run: (wb) async => wb.togglePanel(),
      ),
      IdeCommand(
        id: 'closeTab',
        label: 'View: Close Editor',
        shortcut: 'Ctrl+W',
        run: (wb) async => wb.closeActiveTab(),
      ),
      IdeCommand(
        id: 'about',
        label: 'Help: About AFRIBLOCK',
        run: (wb) async {
          wb.appendOutput(
            'AFRIBLOCK v0.1 — Flutter desktop IDE for AFRILANG\n'
            'Phase 2: LSP, terminal, Git.\n',
          );
          wb.setBottomTab(BottomTab.output);
        },
      ),
    ];

class CommandPalette extends StatefulWidget {
  const CommandPalette({super.key});

  @override
  State<CommandPalette> createState() => _CommandPaletteState();
}

class _CommandPaletteState extends State<CommandPalette> {
  final _filter = TextEditingController();
  final _focus = FocusNode();
  int _index = 0;

  @override
  void initState() {
    super.initState();
    WidgetsBinding.instance.addPostFrameCallback((_) => _focus.requestFocus());
  }

  @override
  void dispose() {
    _filter.dispose();
    _focus.dispose();
    super.dispose();
  }

  List<IdeCommand> _filtered() {
    final q = _filter.text.trim().toLowerCase();
    final all = buildCommands();
    if (q.isEmpty) return all;
    return all.where((c) => c.label.toLowerCase().contains(q)).toList();
  }

  Future<void> _run(IdeCommand cmd) async {
    final wb = context.read<WorkbenchController>();
    wb.toggleCommandPalette(false);
    await cmd.run(wb);
  }

  @override
  Widget build(BuildContext context) {
    final items = _filtered();
    if (_index >= items.length) _index = items.isEmpty ? 0 : items.length - 1;

    return Material(
      color: Colors.black54,
      child: Center(
        child: ConstrainedBox(
          constraints: const BoxConstraints(maxWidth: 560, maxHeight: 420),
          child: Material(
            color: AfriblockColors.panelElevated,
            elevation: 12,
            borderRadius: BorderRadius.circular(10),
            child: Column(
              mainAxisSize: MainAxisSize.min,
              children: [
                Padding(
                  padding: const EdgeInsets.fromLTRB(12, 12, 12, 8),
                  child: TextField(
                    controller: _filter,
                    focusNode: _focus,
                    style: GoogleFonts.plusJakartaSans(fontSize: 15),
                    decoration: InputDecoration(
                      hintText: 'Type a command…',
                      prefixIcon: const Icon(Icons.search, size: 20),
                      filled: true,
                      fillColor: AfriblockColors.panel,
                      border: OutlineInputBorder(
                        borderRadius: BorderRadius.circular(8),
                        borderSide: const BorderSide(color: AfriblockColors.border),
                      ),
                      contentPadding: const EdgeInsets.symmetric(horizontal: 12),
                    ),
                    onChanged: (_) => setState(() => _index = 0),
                    onSubmitted: (_) {
                      if (items.isNotEmpty) _run(items[_index]);
                    },
                  ),
                ),
                Flexible(
                  child: KeyboardListener(
                    focusNode: FocusNode(),
                    onKeyEvent: (e) {
                      if (e is! KeyDownEvent) return;
                      if (e.logicalKey == LogicalKeyboardKey.arrowDown) {
                        setState(() => _index = (_index + 1).clamp(0, items.length - 1));
                      } else if (e.logicalKey == LogicalKeyboardKey.arrowUp) {
                        setState(() => _index = (_index - 1).clamp(0, items.length - 1));
                      } else if (e.logicalKey == LogicalKeyboardKey.escape) {
                        context.read<WorkbenchController>().toggleCommandPalette(false);
                      }
                    },
                    child: ListView.builder(
                      shrinkWrap: true,
                      itemCount: items.length,
                      itemBuilder: (context, i) {
                        final cmd = items[i];
                        final selected = i == _index;
                        return MouseRegion(
                          onEnter: (_) => setState(() => _index = i),
                          child: ListTile(
                            dense: true,
                            selected: selected,
                            selectedTileColor:
                                AfriblockColors.primaryDeep.withValues(alpha: 0.35),
                            title: Text(
                              cmd.label,
                              style: GoogleFonts.plusJakartaSans(fontSize: 13.5),
                            ),
                            trailing: cmd.shortcut == null
                                ? null
                                : Text(
                                    cmd.shortcut!,
                                    style: afriblockMono(
                                      fontSize: 11,
                                      color: AfriblockColors.textMuted,
                                    ),
                                  ),
                            onTap: () => _run(cmd),
                          ),
                        );
                      },
                    ),
                  ),
                ),
                const SizedBox(height: 8),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
