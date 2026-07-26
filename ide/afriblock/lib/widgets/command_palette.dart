import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';

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

  @override
  Widget build(BuildContext context) {
    final wb = context.watch<WorkbenchController>();
    final items = wb.commands.filter(_filter.text);
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
                      border: OutlineInputBorder(borderRadius: BorderRadius.circular(8)),
                    ),
                    onChanged: (_) => setState(() => _index = 0),
                    onSubmitted: (_) async {
                      if (items.isEmpty) return;
                      wb.hideOverlay();
                      await items[_index].run(wb);
                    },
                  ),
                ),
                Flexible(
                  child: KeyboardListener(
                    focusNode: FocusNode(),
                    onKeyEvent: (e) {
                      if (e is! KeyDownEvent) return;
                      if (e.logicalKey == LogicalKeyboardKey.escape) wb.hideOverlay();
                      if (e.logicalKey == LogicalKeyboardKey.arrowDown) {
                        setState(() => _index = (_index + 1).clamp(0, items.length - 1));
                      }
                      if (e.logicalKey == LogicalKeyboardKey.arrowUp) {
                        setState(() => _index = (_index - 1).clamp(0, items.length - 1));
                      }
                    },
                    child: ListView.builder(
                      shrinkWrap: true,
                      itemCount: items.length,
                      itemBuilder: (context, i) {
                        final cmd = items[i];
                        return MouseRegion(
                          onEnter: (_) => setState(() => _index = i),
                          child: ListTile(
                            dense: true,
                            selected: i == _index,
                            selectedTileColor:
                                AfriblockColors.primaryDeep.withValues(alpha: 0.35),
                            title: Text(cmd.label, style: GoogleFonts.plusJakartaSans(fontSize: 13.5)),
                            subtitle: Text(cmd.category,
                                style: afriblockMono(fontSize: 10, color: AfriblockColors.textMuted)),
                            trailing: cmd.shortcut == null
                                ? null
                                : Text(cmd.shortcut!,
                                    style: afriblockMono(
                                        fontSize: 11, color: AfriblockColors.textMuted)),
                            onTap: () async {
                              wb.hideOverlay();
                              await cmd.run(wb);
                            },
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

class QuickOpenOverlay extends StatefulWidget {
  const QuickOpenOverlay({super.key});

  @override
  State<QuickOpenOverlay> createState() => _QuickOpenOverlayState();
}

class _QuickOpenOverlayState extends State<QuickOpenOverlay> {
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

  @override
  Widget build(BuildContext context) {
    final wb = context.watch<WorkbenchController>();
    final items = wb.quickOpenMatches(_filter.text);
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
              children: [
                Padding(
                  padding: const EdgeInsets.all(12),
                  child: TextField(
                    controller: _filter,
                    focusNode: _focus,
                    decoration: const InputDecoration(
                      hintText: 'Go to File',
                      prefixIcon: Icon(Icons.file_open),
                      border: OutlineInputBorder(),
                    ),
                    onChanged: (_) => setState(() => _index = 0),
                    onSubmitted: (_) async {
                      if (items.isEmpty) return;
                      wb.hideOverlay();
                      await wb.openFile(items[_index]);
                    },
                  ),
                ),
                Expanded(
                  child: ListView.builder(
                    itemCount: items.length,
                    itemBuilder: (context, i) {
                      final path = items[i];
                      return ListTile(
                        dense: true,
                        selected: i == _index,
                        title: Text(wb.relativePath(path), style: afriblockMono(fontSize: 12)),
                        onTap: () async {
                          wb.hideOverlay();
                          await wb.openFile(path);
                        },
                      );
                    },
                  ),
                ),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
