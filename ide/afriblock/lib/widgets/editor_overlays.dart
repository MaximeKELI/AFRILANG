import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

import '../editor/snippets.dart';
import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';

class FindReplaceOverlay extends StatefulWidget {
  const FindReplaceOverlay({super.key});

  @override
  State<FindReplaceOverlay> createState() => _FindReplaceOverlayState();
}

class _FindReplaceOverlayState extends State<FindReplaceOverlay> {
  late final TextEditingController _find;
  late final TextEditingController _replace;
  final _focus = FocusNode();

  @override
  void initState() {
    super.initState();
    _find = TextEditingController();
    _replace = TextEditingController();
    WidgetsBinding.instance.addPostFrameCallback((_) {
      if (!mounted) return;
      final wb = context.read<WorkbenchController>();
      _find.text = wb.findQuery;
      _replace.text = wb.replaceQuery;
      _focus.requestFocus();
    });
  }

  @override
  void dispose() {
    _find.dispose();
    _replace.dispose();
    _focus.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    final wb = context.watch<WorkbenchController>();
    return Material(
      color: Colors.black54,
      child: Align(
        alignment: Alignment.topCenter,
        child: Padding(
          padding: const EdgeInsets.only(top: 72),
          child: Material(
            color: AfriblockColors.panelElevated,
            elevation: 10,
            borderRadius: BorderRadius.circular(10),
            child: SizedBox(
              width: 480,
              child: Padding(
                padding: const EdgeInsets.all(12),
                child: Column(
                  mainAxisSize: MainAxisSize.min,
                  children: [
                    Row(
                      children: [
                        Expanded(
                          child: TextField(
                            controller: _find,
                            focusNode: _focus,
                            decoration: const InputDecoration(
                              labelText: 'Find',
                              isDense: true,
                              border: OutlineInputBorder(),
                            ),
                            onChanged: wb.updateFindQuery,
                            onSubmitted: (_) => wb.findNext(),
                          ),
                        ),
                        const SizedBox(width: 8),
                        Text(
                          wb.findMatches.isEmpty
                              ? '0'
                              : '${wb.findIndex + 1}/${wb.findMatches.length}',
                          style: afriblockMono(fontSize: 12, color: AfriblockColors.textMuted),
                        ),
                      ],
                    ),
                    const SizedBox(height: 8),
                    TextField(
                      controller: _replace,
                      decoration: const InputDecoration(
                        labelText: 'Replace',
                        isDense: true,
                        border: OutlineInputBorder(),
                      ),
                      onChanged: (v) {
                        wb.replaceQuery = v;
                      },
                    ),
                    const SizedBox(height: 10),
                    Row(
                      children: [
                        TextButton(onPressed: wb.findPrev, child: const Text('Prev')),
                        TextButton(onPressed: wb.findNext, child: const Text('Next')),
                        TextButton(onPressed: wb.replaceCurrent, child: const Text('Replace')),
                        TextButton(onPressed: wb.replaceAllInFile, child: const Text('All')),
                        const Spacer(),
                        TextButton(
                          onPressed: wb.hideOverlay,
                          child: const Text('Close'),
                        ),
                      ],
                    ),
                  ],
                ),
              ),
            ),
          ),
        ),
      ),
    );
  }
}

class GoToLineOverlay extends StatefulWidget {
  const GoToLineOverlay({super.key});

  @override
  State<GoToLineOverlay> createState() => _GoToLineOverlayState();
}

class _GoToLineOverlayState extends State<GoToLineOverlay> {
  final _ctrl = TextEditingController();
  final _focus = FocusNode();

  @override
  void initState() {
    super.initState();
    WidgetsBinding.instance.addPostFrameCallback((_) => _focus.requestFocus());
  }

  @override
  void dispose() {
    _ctrl.dispose();
    _focus.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    final wb = context.read<WorkbenchController>();
    return Material(
      color: Colors.black54,
      child: Center(
        child: Material(
          color: AfriblockColors.panelElevated,
          borderRadius: BorderRadius.circular(10),
          child: SizedBox(
            width: 280,
            child: Padding(
              padding: const EdgeInsets.all(16),
              child: Column(
                mainAxisSize: MainAxisSize.min,
                children: [
                  Text('Go to Line', style: GoogleFonts.plusJakartaSans(fontWeight: FontWeight.w700)),
                  const SizedBox(height: 12),
                  TextField(
                    controller: _ctrl,
                    focusNode: _focus,
                    keyboardType: TextInputType.number,
                    inputFormatters: [FilteringTextInputFormatter.digitsOnly],
                    decoration: const InputDecoration(
                      hintText: 'Line number',
                      border: OutlineInputBorder(),
                    ),
                    onSubmitted: (v) {
                      final n = int.tryParse(v);
                      if (n != null && n > 0) wb.requestGoToLine(n);
                    },
                  ),
                  const SizedBox(height: 12),
                  Row(
                    mainAxisAlignment: MainAxisAlignment.end,
                    children: [
                      TextButton(onPressed: wb.hideOverlay, child: const Text('Cancel')),
                      FilledButton(
                        onPressed: () {
                          final n = int.tryParse(_ctrl.text);
                          if (n != null && n > 0) wb.requestGoToLine(n);
                        },
                        child: const Text('Go'),
                      ),
                    ],
                  ),
                ],
              ),
            ),
          ),
        ),
      ),
    );
  }
}

class SnippetsOverlay extends StatefulWidget {
  const SnippetsOverlay({super.key});

  @override
  State<SnippetsOverlay> createState() => _SnippetsOverlayState();
}

class _SnippetsOverlayState extends State<SnippetsOverlay> {
  final _filter = TextEditingController();
  final _focus = FocusNode();

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
    final items = filterSnippets(_filter.text);
    return Material(
      color: Colors.black54,
      child: Center(
        child: ConstrainedBox(
          constraints: const BoxConstraints(maxWidth: 480, maxHeight: 420),
          child: Material(
            color: AfriblockColors.panelElevated,
            borderRadius: BorderRadius.circular(10),
            child: Column(
              children: [
                Padding(
                  padding: const EdgeInsets.all(12),
                  child: TextField(
                    controller: _filter,
                    focusNode: _focus,
                    decoration: const InputDecoration(
                      hintText: 'Filter snippets…',
                      prefixIcon: Icon(Icons.code),
                      border: OutlineInputBorder(),
                    ),
                    onChanged: (_) => setState(() {}),
                  ),
                ),
                Expanded(
                  child: ListView.builder(
                    itemCount: items.length,
                    itemBuilder: (context, i) {
                      final s = items[i];
                      return ListTile(
                        title: Text(s.label),
                        subtitle: Text(s.prefix, style: afriblockMono(fontSize: 11)),
                        onTap: () => wb.insertSnippet(s),
                      );
                    },
                  ),
                ),
                TextButton(onPressed: wb.hideOverlay, child: const Text('Close')),
              ],
            ),
          ),
        ),
      ),
    );
  }
}
