import 'dart:async';

import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:provider/provider.dart';
import 'package:shared_preferences/shared_preferences.dart';

import '../state/app_state.dart';
import '../theme/afrilang_theme.dart';
import '../widgets/motion.dart';

const _defaultSource = '''create name text = "AFRILANG"
say "Hello, {name}!"

function greet(who text) returns text
    return "Hello, " + who
end

say greet(name)
''';

const _snippets = <(String, String)>[
  (
    'Hello',
    '''create name text = "AFRILANG"
say "Hello, {name}!"
'''
  ),
  (
    'If / else',
    '''create score number = 95
if score is greater than or equal to 90 then
    say "Excellent!"
else
    say "Keep learning"
end
'''
  ),
  (
    'Function',
    '''function greet(who text) returns text
    return "Hello, " + who
end

say greet("World")
'''
  ),
  (
    'Loop',
    '''create i number = 1
while i is less than or equal to 5 then
    say "tick " + i
    set i = i + 1
end
'''
  ),
];

class PlaygroundScreen extends StatefulWidget {
  const PlaygroundScreen({super.key});

  @override
  State<PlaygroundScreen> createState() => _PlaygroundScreenState();
}

class _PlaygroundScreenState extends State<PlaygroundScreen> {
  late final TextEditingController _src;
  String _output = '';
  bool? _ok;
  bool _busy = false;
  bool _ready = false;
  Timer? _persistTimer;

  @override
  void initState() {
    super.initState();
    _src = TextEditingController(text: _defaultSource);
    _restore();
    _src.addListener(_persistDebounced);
  }

  void _persistDebounced() {
    _persistTimer?.cancel();
    _persistTimer = Timer(const Duration(milliseconds: 600), _persist);
  }

  Future<void> _restore() async {
    final prefs = await SharedPreferences.getInstance();
    final saved = prefs.getString('playground_source');
    if (saved != null && saved.trim().isNotEmpty && mounted) {
      _src.text = saved;
    }
    if (mounted) setState(() => _ready = true);
  }

  Future<void> _persist() async {
    final prefs = await SharedPreferences.getInstance();
    await prefs.setString('playground_source', _src.text);
  }

  @override
  void dispose() {
    _persistTimer?.cancel();
    _src.removeListener(_persistDebounced);
    _src.dispose();
    super.dispose();
  }

  Future<void> _run() async {
    HapticFeedback.mediumImpact();
    setState(() {
      _busy = true;
      _ok = null;
    });
    try {
      final res = await context.read<AppState>().api.run(_src.text);
      if (!mounted) return;
      setState(() {
        _output = res['output']?.toString() ?? '';
        _ok = res['ok'] == true;
      });
      HapticFeedback.lightImpact();
    } catch (e) {
      if (!mounted) return;
      setState(() {
        _output = e.toString();
        _ok = false;
      });
    } finally {
      if (mounted) setState(() => _busy = false);
    }
  }

  Future<void> _fmt() async {
    setState(() => _busy = true);
    try {
      final res = await context.read<AppState>().api.fmt(_src.text);
      if (!mounted) return;
      if (res['ok'] == true && res['source'] != null) {
        _src.text = res['source'].toString();
      }
      setState(() {
        _output = res['output']?.toString() ?? (res['ok'] == true ? 'Formatted ✓' : 'Format failed');
        _ok = res['ok'] == true;
      });
    } catch (e) {
      if (!mounted) return;
      setState(() {
        _output = e.toString();
        _ok = false;
      });
    } finally {
      if (mounted) setState(() => _busy = false);
    }
  }

  Future<void> _check() async {
    setState(() => _busy = true);
    try {
      final res = await context.read<AppState>().api.check(_src.text);
      if (!mounted) return;
      setState(() {
        _output = res['output']?.toString() ?? res.toString();
        _ok = res['ok'] == true || res['errors'] == 0;
      });
    } catch (e) {
      if (!mounted) return;
      setState(() {
        _output = e.toString();
        _ok = false;
      });
    } finally {
      if (mounted) setState(() => _busy = false);
    }
  }

  void _loadSnippet(String code) {
    setState(() {
      _src.text = code;
      _output = '';
      _ok = null;
    });
  }

  @override
  Widget build(BuildContext context) {
    final app = context.watch<AppState>();
    if (!_ready) return const Center(child: CircularProgressIndicator());

    final outColor = _ok == null
        ? Theme.of(context).colorScheme.onSurface
        : (_ok! ? const Color(0xFF16A34A) : const Color(0xFFDC2626));

    return Column(
      children: [
        Padding(
          padding: const EdgeInsets.fromLTRB(12, 8, 12, 4),
          child: Row(
            children: [
              Expanded(
                child: Row(
                  children: [
                    Text(
                      app.t('nav_playground', 'Playground'),
                      style: Theme.of(context).textTheme.titleLarge?.copyWith(fontWeight: FontWeight.w800),
                    ),
                    const SizedBox(width: 8),
                    if (_busy) const PulsingDot(),
                  ],
                ),
              ),
              IconButton(
                tooltip: 'Format',
                onPressed: _busy ? null : _fmt,
                icon: const Icon(Icons.format_align_left_rounded),
              ),
              IconButton(
                tooltip: 'Check',
                onPressed: _busy ? null : _check,
                icon: const Icon(Icons.fact_check_outlined),
              ),
              FilledButton.icon(
                onPressed: _busy ? null : _run,
                icon: _busy
                    ? const SizedBox(
                        width: 14,
                        height: 14,
                        child: CircularProgressIndicator(strokeWidth: 2, color: Colors.white),
                      )
                    : const Icon(Icons.play_arrow_rounded),
                label: const Text('Run'),
              ),
            ],
          ),
        ),
        SizedBox(
          height: 40,
          child: ListView(
            scrollDirection: Axis.horizontal,
            padding: const EdgeInsets.symmetric(horizontal: 12),
            children: [
              for (final s in _snippets)
                Padding(
                  padding: const EdgeInsets.only(right: 8),
                  child: ActionChip(
                    label: Text(s.$1),
                    onPressed: () => _loadSnippet(s.$2),
                    avatar: const Icon(Icons.bolt_rounded, size: 16),
                  ),
                ),
              ActionChip(
                label: Text(app.lang == 'en' ? 'Reset' : 'Réinitialiser'),
                onPressed: () => _loadSnippet(_defaultSource),
                avatar: const Icon(Icons.restart_alt_rounded, size: 16),
              ),
            ],
          ),
        ),
        const SizedBox(height: 6),
        Expanded(
          flex: 3,
          child: Container(
            margin: const EdgeInsets.symmetric(horizontal: 12),
            decoration: BoxDecoration(
              color: AfrColors.codeBg,
              borderRadius: BorderRadius.circular(14),
              border: Border.all(color: AfrColors.primary.withValues(alpha: 0.25)),
            ),
            child: TextField(
              controller: _src,
              maxLines: null,
              expands: true,
              style: afrMono(),
              cursorColor: AfrColors.accent,
              decoration: const InputDecoration(
                border: InputBorder.none,
                contentPadding: EdgeInsets.all(14),
                filled: true,
                fillColor: Colors.transparent,
              ),
            ),
          ).animate().fadeIn(duration: 350.ms),
        ),
        const SizedBox(height: 10),
        Expanded(
          flex: 2,
          child: Container(
            width: double.infinity,
            margin: const EdgeInsets.fromLTRB(12, 0, 12, 12),
            padding: const EdgeInsets.all(12),
            decoration: BoxDecoration(
              color: Theme.of(context).cardColor,
              borderRadius: BorderRadius.circular(14),
              border: Border.all(
                color: _ok == null
                    ? AfrColors.border
                    : (_ok! ? const Color(0xFF86EFAC) : const Color(0xFFFECACA)),
                width: 1.5,
              ),
            ),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Row(
                  children: [
                    Icon(
                      _ok == null
                          ? Icons.terminal_rounded
                          : (_ok! ? Icons.check_circle_rounded : Icons.error_outline_rounded),
                      size: 18,
                      color: outColor,
                    ),
                    const SizedBox(width: 8),
                    Text('Output', style: TextStyle(fontWeight: FontWeight.w700, color: outColor)),
                  ],
                ),
                const SizedBox(height: 8),
                Expanded(
                  child: SingleChildScrollView(
                    child: SelectableText(
                      _output.isEmpty
                          ? (app.lang == 'en' ? 'Run to see output…' : 'Lancez pour voir la sortie…')
                          : _output,
                      style: afrMono(color: Theme.of(context).colorScheme.onSurface),
                    ),
                  ),
                ),
              ],
            ),
          ),
        ),
      ],
    );
  }
}
