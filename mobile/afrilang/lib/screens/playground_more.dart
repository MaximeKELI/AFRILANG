import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

import '../state/app_state.dart';
import '../theme/afrilang_theme.dart';
import '../widgets/common.dart';

const _defaultSource = '''create name text = "AFRILANG"
say "Hello, {name}!"

function greet(who text) returns text
    return "Hello, " + who
end

say greet(name)
''';

class PlaygroundScreen extends StatefulWidget {
  const PlaygroundScreen({super.key});

  @override
  State<PlaygroundScreen> createState() => _PlaygroundScreenState();
}

class _PlaygroundScreenState extends State<PlaygroundScreen> {
  late final TextEditingController _src;
  String _output = '';
  bool _busy = false;

  @override
  void initState() {
    super.initState();
    _src = TextEditingController(text: _defaultSource);
  }

  @override
  void dispose() {
    _src.dispose();
    super.dispose();
  }

  Future<void> _run() async {
    setState(() => _busy = true);
    try {
      final res = await context.read<AppState>().api.run(_src.text);
      if (!mounted) return;
      setState(() => _output = res['output']?.toString() ?? '');
    } catch (e) {
      if (!mounted) return;
      setState(() => _output = e.toString());
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
      setState(() => _output = res['output']?.toString() ?? (res['ok'] == true ? 'Formatted.' : 'Format failed'));
    } catch (e) {
      if (!mounted) return;
      setState(() => _output = e.toString());
    } finally {
      if (mounted) setState(() => _busy = false);
    }
  }

  Future<void> _check() async {
    setState(() => _busy = true);
    try {
      final res = await context.read<AppState>().api.check(_src.text);
      if (!mounted) return;
      setState(() => _output = res['output']?.toString() ?? res.toString());
    } catch (e) {
      if (!mounted) return;
      setState(() => _output = e.toString());
    } finally {
      if (mounted) setState(() => _busy = false);
    }
  }

  @override
  Widget build(BuildContext context) {
    final app = context.watch<AppState>();
    return Column(
      children: [
        Padding(
          padding: const EdgeInsets.fromLTRB(12, 8, 12, 4),
          child: Row(
            children: [
              Expanded(
                child: Text(
                  app.t('nav_playground', 'Playground'),
                  style: Theme.of(context).textTheme.titleLarge?.copyWith(fontWeight: FontWeight.w800),
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
                    ? const SizedBox(width: 14, height: 14, child: CircularProgressIndicator(strokeWidth: 2, color: Colors.white))
                    : const Icon(Icons.play_arrow_rounded),
                label: const Text('Run'),
              ),
            ],
          ),
        ),
        Expanded(
          flex: 3,
          child: Container(
            margin: const EdgeInsets.symmetric(horizontal: 12),
            decoration: BoxDecoration(
              color: AfrColors.codeBg,
              borderRadius: BorderRadius.circular(14),
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
          ),
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
              border: Border.all(color: AfrColors.border),
            ),
            child: Column(
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Text('Output', style: TextStyle(fontWeight: FontWeight.w700, color: AfrColors.primary)),
                const SizedBox(height: 8),
                Expanded(
                  child: SingleChildScrollView(
                    child: SelectableText(
                      _output.isEmpty ? (app.lang == 'en' ? 'Run to see output…' : 'Lancez pour voir la sortie…') : _output,
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

class TutorialScreen extends StatefulWidget {
  const TutorialScreen({super.key});

  @override
  State<TutorialScreen> createState() => _TutorialScreenState();
}

class _TutorialScreenState extends State<TutorialScreen> {
  List<dynamic> _lessons = [];
  bool _loading = true;
  String? _error;

  @override
  void initState() {
    super.initState();
    _load();
  }

  Future<void> _load() async {
    final app = context.read<AppState>();
    try {
      final data = await app.api.tutorial(app.lang);
      if (!mounted) return;
      setState(() {
        _lessons = (data['lessons'] as List?) ?? [];
        _loading = false;
      });
    } catch (e) {
      if (!mounted) return;
      setState(() {
        _error = e.toString();
        _loading = false;
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    if (_loading) return const Center(child: CircularProgressIndicator());
    if (_error != null) return EmptyError(message: _error!, onRetry: _load);
    return ListView.builder(
      padding: const EdgeInsets.all(16),
      itemCount: _lessons.length,
      itemBuilder: (context, i) {
        final l = _lessons[i] as Map<String, dynamic>;
        return Card(
          margin: const EdgeInsets.only(bottom: 10),
          child: ListTile(
            leading: CircleAvatar(
              backgroundColor: AfrColors.primary.withValues(alpha: 0.12),
              foregroundColor: AfrColors.primary,
              child: Text('${l['step']}'),
            ),
            title: Text(l['title']?.toString() ?? '', style: const TextStyle(fontWeight: FontWeight.w700)),
            subtitle: Text(l['summary']?.toString() ?? ''),
            trailing: Text('${l['duration_min'] ?? 5} min', style: const TextStyle(fontSize: 12)),
            onTap: () => Navigator.of(context).push(
              MaterialPageRoute(builder: (_) => TutorialStepScreen(step: l['step'] as int)),
            ),
          ),
        );
      },
    );
  }
}

class TutorialStepScreen extends StatefulWidget {
  const TutorialStepScreen({super.key, required this.step});
  final int step;

  @override
  State<TutorialStepScreen> createState() => _TutorialStepScreenState();
}

class _TutorialStepScreenState extends State<TutorialStepScreen> {
  Map<String, dynamic>? _lesson;
  int _total = 1;
  bool _loading = true;
  String? _error;
  String? _output;

  @override
  void initState() {
    super.initState();
    _load();
  }

  Future<void> _load() async {
    final app = context.read<AppState>();
    try {
      final data = await app.api.tutorialStep(widget.step, app.lang);
      if (!mounted) return;
      setState(() {
        _lesson = data['lesson'] as Map<String, dynamic>?;
        _total = data['total_steps'] as int? ?? 1;
        _loading = false;
      });
    } catch (e) {
      if (!mounted) return;
      setState(() {
        _error = e.toString();
        _loading = false;
      });
    }
  }

  Future<void> _run() async {
    final code = _lesson?['code']?.toString() ?? '';
    try {
      final res = await context.read<AppState>().api.run(code);
      if (!mounted) return;
      setState(() => _output = res['output']?.toString());
    } catch (e) {
      if (!mounted) return;
      setState(() => _output = e.toString());
    }
  }

  @override
  Widget build(BuildContext context) {
    final title = _lesson?['title']?.toString() ?? 'Step ${widget.step}';
    return Scaffold(
      appBar: AppBar(title: Text('${widget.step}/$_total · $title')),
      body: _loading
          ? const Center(child: CircularProgressIndicator())
          : _error != null
              ? EmptyError(message: _error!, onRetry: _load)
              : ListView(
                  padding: const EdgeInsets.all(20),
                  children: [
                    Text(_lesson?['summary']?.toString() ?? '', style: const TextStyle(fontSize: 16, height: 1.5)),
                    const SizedBox(height: 12),
                    Text(_lesson?['content']?.toString() ?? ''),
                    if ((_lesson?['objectives'] as List?)?.isNotEmpty == true) ...[
                      const SizedBox(height: 16),
                      const Text('Objectifs', style: TextStyle(fontWeight: FontWeight.w800)),
                      ...(_lesson!['objectives'] as List).map((o) => Text('• $o')),
                    ],
                    const SizedBox(height: 16),
                    CodePanel(code: _lesson?['code']?.toString() ?? '', filename: 'lesson.afr'),
                    const SizedBox(height: 12),
                    ElevatedButton.icon(onPressed: _run, icon: const Icon(Icons.play_arrow), label: const Text('Run')),
                    if (_output != null) ...[
                      const SizedBox(height: 12),
                      CodePanel(code: _output!, filename: 'output'),
                    ],
                    if ((_lesson?['challenge'] as String?)?.isNotEmpty == true) ...[
                      const SizedBox(height: 16),
                      Container(
                        padding: const EdgeInsets.all(12),
                        decoration: BoxDecoration(
                          color: AfrColors.primary.withValues(alpha: 0.06),
                          borderRadius: BorderRadius.circular(10),
                        ),
                        child: Text(_lesson!['challenge'] as String),
                      ),
                    ],
                    const SizedBox(height: 20),
                    Row(
                      children: [
                        if (widget.step > 1)
                          OutlinedButton(
                            onPressed: () {
                              Navigator.of(context).pushReplacement(
                                MaterialPageRoute(builder: (_) => TutorialStepScreen(step: widget.step - 1)),
                              );
                            },
                            child: const Text('←'),
                          ),
                        const Spacer(),
                        if (widget.step < _total)
                          ElevatedButton(
                            onPressed: () {
                              Navigator.of(context).pushReplacement(
                                MaterialPageRoute(builder: (_) => TutorialStepScreen(step: widget.step + 1)),
                              );
                            },
                            child: const Text('→'),
                          ),
                      ],
                    ),
                  ],
                ),
    );
  }
}

class MoreScreen extends StatelessWidget {
  const MoreScreen({super.key, this.onOpenTutorial});
  final VoidCallback? onOpenTutorial;

  @override
  Widget build(BuildContext context) {
    final app = context.watch<AppState>();
    return ListView(
      padding: const EdgeInsets.all(16),
      children: [
        const AfrBrandMark(size: 26),
        const SizedBox(height: 8),
        Text(app.t('footer_tagline', 'Codez en phrases, déployez en natif.')),
        const SizedBox(height: 20),
        ListTile(
          leading: const Icon(Icons.school_rounded, color: AfrColors.primary),
          title: Text(app.t('nav_tutorial', 'Tutoriel')),
          onTap: () => Navigator.of(context).push(MaterialPageRoute(builder: (_) => const TutorialScreen())),
        ),
        ListTile(
          leading: const Icon(Icons.new_releases_outlined, color: AfrColors.primary),
          title: Text(app.lang == 'en' ? 'Releases' : 'Versions'),
          onTap: () => Navigator.of(context).push(MaterialPageRoute(builder: (_) => const ReleasesScreen())),
        ),
        const Divider(),
        SwitchListTile(
          secondary: const Icon(Icons.dark_mode_outlined),
          title: Text(app.lang == 'en' ? 'Dark mode' : 'Mode sombre'),
          value: app.darkMode,
          onChanged: (_) => app.toggleDark(),
        ),
        ListTile(
          leading: const Icon(Icons.language_rounded),
          title: Text(app.lang == 'en' ? 'Language' : 'Langue'),
          subtitle: Text(app.lang == 'en' ? 'English' : 'Français'),
          trailing: SegmentedButton<String>(
            segments: const [
              ButtonSegment(value: 'fr', label: Text('FR')),
              ButtonSegment(value: 'en', label: Text('EN')),
            ],
            selected: {app.lang},
            onSelectionChanged: (s) => app.setLang(s.first),
          ),
        ),
        const Divider(),
        ListTile(
          leading: const Icon(Icons.dns_outlined),
          title: const Text('API'),
          subtitle: Text(app.api.baseUrl, style: afrMono(fontSize: 11, color: AfrColors.textSecondary)),
        ),
      ],
    );
  }
}

class ReleasesScreen extends StatefulWidget {
  const ReleasesScreen({super.key});

  @override
  State<ReleasesScreen> createState() => _ReleasesScreenState();
}

class _ReleasesScreenState extends State<ReleasesScreen> {
  List<dynamic> _items = [];
  bool _loading = true;
  String? _error;

  @override
  void initState() {
    super.initState();
    _load();
  }

  Future<void> _load() async {
    try {
      final data = await context.read<AppState>().api.releases();
      if (!mounted) return;
      setState(() {
        _items = (data['releases'] as List?) ?? [];
        _loading = false;
      });
    } catch (e) {
      if (!mounted) return;
      setState(() {
        _error = e.toString();
        _loading = false;
      });
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(title: Text(context.watch<AppState>().lang == 'en' ? 'Releases' : 'Versions')),
      body: _loading
          ? const Center(child: CircularProgressIndicator())
          : _error != null
              ? EmptyError(message: _error!, onRetry: _load)
              : ListView.builder(
                  padding: const EdgeInsets.all(16),
                  itemCount: _items.length,
                  itemBuilder: (context, i) {
                    final r = _items[i] as Map<String, dynamic>;
                    return Card(
                      margin: const EdgeInsets.only(bottom: 10),
                      child: ExpansionTile(
                        title: Text('v${r['version']}', style: const TextStyle(fontWeight: FontWeight.w800)),
                        subtitle: Text('${r['title'] ?? ''} · ${r['date'] ?? ''}'),
                        children: [
                          Padding(
                            padding: const EdgeInsets.all(16),
                            child: Text(r['body']?.toString() ?? ''),
                          ),
                        ],
                      ),
                    );
                  },
                ),
    );
  }
}
