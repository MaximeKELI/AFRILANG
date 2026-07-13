import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

import '../state/app_state.dart';
import '../theme/afrilang_theme.dart';
import '../widgets/common.dart';
import '../widgets/motion.dart';

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
        return FadeSlideIn(
          delay: Duration(milliseconds: 40 * i),
          child: SoftPress(
            onTap: () => Navigator.of(context).push(
              MaterialPageRoute(builder: (_) => TutorialStepScreen(step: l['step'] as int)),
            ),
            child: Card(
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
              ),
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
  bool? _ok;

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
      setState(() {
        _output = res['output']?.toString();
        _ok = res['ok'] == true;
      });
    } catch (e) {
      if (!mounted) return;
      setState(() {
        _output = e.toString();
        _ok = false;
      });
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
                      CodePanel(code: _output!, filename: _ok == true ? 'output ✓' : 'output ✗'),
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
  const MoreScreen({super.key, this.onOpenExplore, this.onOpenPlay, this.onOpenDocs});

  final void Function(int exploreTab)? onOpenExplore;
  final VoidCallback? onOpenPlay;
  final VoidCallback? onOpenDocs;

  @override
  Widget build(BuildContext context) {
    final app = context.watch<AppState>();
    return ListView(
      padding: const EdgeInsets.all(16),
      children: [
        const AfrBrandMark(size: 28),
        const SizedBox(height: 8),
        Text(
          app.t('footer_tagline', 'Codez en phrases, déployez en natif.'),
          style: TextStyle(color: Theme.of(context).colorScheme.onSurface.withValues(alpha: 0.7)),
        ),
        const SizedBox(height: 20),
        _HubTile(
          icon: Icons.school_rounded,
          title: app.t('nav_tutorial', 'Tutoriel'),
          subtitle: app.lang == 'en' ? 'Interactive lessons' : 'Leçons interactives',
          onTap: () => Navigator.of(context).push(MaterialPageRoute(builder: (_) => const TutorialScreen())),
        ),
        _HubTile(
          icon: Icons.inventory_2_outlined,
          title: app.t('nav_packages', 'Paquets'),
          onTap: () => onOpenExplore?.call(0),
        ),
        _HubTile(
          icon: Icons.code_rounded,
          title: app.t('nav_examples', 'Exemples'),
          onTap: () => onOpenExplore?.call(1),
        ),
        _HubTile(
          icon: Icons.library_books_outlined,
          title: app.t('nav_stdlib', 'Stdlib'),
          onTap: () => onOpenExplore?.call(2),
        ),
        _HubTile(
          icon: Icons.play_circle_outline,
          title: app.t('nav_playground', 'Playground'),
          onTap: onOpenPlay,
        ),
        _HubTile(
          icon: Icons.menu_book_outlined,
          title: app.t('nav_docs', 'Documentation'),
          onTap: onOpenDocs,
        ),
        _HubTile(
          icon: Icons.new_releases_outlined,
          title: app.lang == 'en' ? 'Releases' : 'Versions',
          onTap: () => Navigator.of(context).push(MaterialPageRoute(builder: (_) => const ReleasesScreen())),
        ),
        const Divider(height: 32),
        SwitchListTile(
          secondary: const Icon(Icons.dark_mode_outlined),
          title: Text(app.lang == 'en' ? 'Dark mode' : 'Mode sombre'),
          value: app.darkMode,
          onChanged: (_) => app.toggleDark(),
        ),
        ListTile(
          leading: const Icon(Icons.language_rounded),
          title: Text(app.lang == 'en' ? 'Language' : 'Langue'),
          trailing: SegmentedButton<String>(
            segments: const [
              ButtonSegment(value: 'fr', label: Text('FR')),
              ButtonSegment(value: 'en', label: Text('EN')),
            ],
            selected: {app.lang},
            onSelectionChanged: (s) => app.setLang(s.first),
          ),
        ),
        ListTile(
          leading: const Icon(Icons.dns_outlined),
          title: const Text('API'),
          subtitle: Text(app.api.baseUrl, style: afrMono(fontSize: 11, color: AfrColors.textSecondary)),
        ),
        const SizedBox(height: 12),
        Text(
          app.t('footer_desc', ''),
          style: TextStyle(fontSize: 12, color: Theme.of(context).colorScheme.onSurface.withValues(alpha: 0.5)),
        ),
      ],
    );
  }
}

class _HubTile extends StatelessWidget {
  const _HubTile({
    required this.icon,
    required this.title,
    this.subtitle,
    this.onTap,
  });

  final IconData icon;
  final String title;
  final String? subtitle;
  final VoidCallback? onTap;

  @override
  Widget build(BuildContext context) {
    return SoftPress(
      onTap: onTap,
      child: Card(
        margin: const EdgeInsets.only(bottom: 8),
        child: ListTile(
          leading: Icon(icon, color: AfrColors.primary),
          title: Text(title, style: const TextStyle(fontWeight: FontWeight.w700)),
          subtitle: subtitle == null ? null : Text(subtitle!),
          trailing: const Icon(Icons.chevron_right_rounded),
        ),
      ),
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
