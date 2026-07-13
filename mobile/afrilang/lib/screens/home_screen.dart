import 'package:flutter/material.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:flutter_html/flutter_html.dart';
import 'package:provider/provider.dart';

import '../state/app_state.dart';
import '../theme/afrilang_theme.dart';
import '../widgets/common.dart';

class HomeScreen extends StatefulWidget {
  const HomeScreen({super.key, this.onNavigate});
  final void Function(int tab)? onNavigate;

  @override
  State<HomeScreen> createState() => _HomeScreenState();
}

class _HomeScreenState extends State<HomeScreen> {
  Map<String, dynamic>? _home;
  String? _error;
  bool _loading = true;

  @override
  void initState() {
    super.initState();
    _load();
  }

  Future<void> _load() async {
    final app = context.read<AppState>();
    setState(() {
      _loading = true;
      _error = null;
    });
    try {
      final data = await app.api.home(app.lang);
      if (!mounted) return;
      setState(() {
        _home = data;
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

  String _h(String key, [String fb = '']) {
    final home = _home?['home'];
    if (home is Map && home[key] is String) return home[key] as String;
    return context.read<AppState>().home(key, fb);
  }

  @override
  Widget build(BuildContext context) {
    final app = context.watch<AppState>();
    if (_loading) {
      return const Center(child: CircularProgressIndicator());
    }
    if (_error != null) {
      return EmptyError(message: _error!, onRetry: _load);
    }

    final packages = (_home?['packages'] as List?) ?? [];
    final heroCode = _home?['hero_code'] as String? ?? '';
    final stats = app.stats;

    return RefreshIndicator(
      onRefresh: () async {
        await app.refreshBootstrap();
        await _load();
      },
      child: CustomScrollView(
        physics: const AlwaysScrollableScrollPhysics(),
        slivers: [
          SliverToBoxAdapter(
            child: HeroMeshBackground(
              child: Padding(
                padding: const EdgeInsets.fromLTRB(20, 28, 20, 32),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    FadeSlideIn(
                      child: Column(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        children: [
                          const AfrBrandMark(size: 28),
                          const SizedBox(height: 10),
                          Container(
                            padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 5),
                            decoration: BoxDecoration(
                              color: AfrColors.primary.withValues(alpha: 0.1),
                              borderRadius: BorderRadius.circular(999),
                            ),
                            child: Text(
                              'v${stats['version'] ?? '1.0'} · ${_h('badge', 'Open source · MIT')}',
                              style: const TextStyle(fontSize: 12, fontWeight: FontWeight.w600),
                            ),
                          ),
                          const SizedBox(height: 18),
                          Text.rich(
                            TextSpan(
                              style: Theme.of(context).textTheme.headlineMedium?.copyWith(
                                    fontWeight: FontWeight.w800,
                                    height: 1.15,
                                  ),
                              children: [
                                TextSpan(text: '${_h('hero_h1_a', 'Codez en')} '),
                                TextSpan(
                                  text: _h('hero_h1_b', 'langage naturel'),
                                  style: const TextStyle(color: AfrColors.primary),
                                ),
                                TextSpan(text: ',\n${_h('hero_h1_c', 'compilez en natif.')}'),
                              ],
                            ),
                          ),
                          const SizedBox(height: 12),
                          Text(
                            _h('hero_lead'),
                            style: TextStyle(
                              fontSize: 16,
                              height: 1.5,
                              color: Theme.of(context).colorScheme.onSurface.withValues(alpha: 0.7),
                            ),
                          ),
                          const SizedBox(height: 20),
                          Wrap(
                            spacing: 10,
                            runSpacing: 10,
                            children: [
                              AfrPrimaryButton(
                                label: _h('btn_start', 'Commencer'),
                                icon: Icons.rocket_launch_rounded,
                                onPressed: () => widget.onNavigate?.call(1),
                              ),
                              OutlinedButton.icon(
                                onPressed: () => widget.onNavigate?.call(5),
                                icon: const Icon(Icons.play_arrow_rounded),
                                label: Text(_h('btn_try', 'Playground')),
                              ),
                            ],
                          ),
                          const SizedBox(height: 10),
                          Text(
                            _h('hero_compat', 'LSP · REPL · WASM · cross-compilation'),
                            style: TextStyle(
                              fontSize: 12,
                              color: Theme.of(context).colorScheme.onSurface.withValues(alpha: 0.5),
                            ),
                          ),
                        ],
                      ),
                    ),
                    const SizedBox(height: 28),
                    FadeSlideIn(
                      delay: 120.ms,
                      child: CodePanel(code: heroCode),
                    ),
                  ],
                ),
              ),
            ),
          ),
          SliverPadding(
            padding: const EdgeInsets.fromLTRB(20, 8, 20, 40),
            sliver: SliverList(
              delegate: SliverChildListDelegate([
                StatRow(items: [
                  ('${stats['examples'] ?? 0}+', _h('stat_examples', 'Exemples')),
                  ('${stats['stdlib_modules'] ?? 0}', _h('stat_stdlib', 'Modules stdlib')),
                  ('${stats['blessed_packages'] ?? 0}', _h('stat_packages', 'Paquets certifiés')),
                  ('v${stats['compiler_version'] ?? '1.0'}', app.lang == 'en' ? 'Compiler' : 'Compilateur'),
                ]),
                const SizedBox(height: 36),
                FadeSlideIn(
                  child: Column(
                    crossAxisAlignment: CrossAxisAlignment.start,
                    children: [
                      SectionLabel(_h('why_label', 'Pourquoi AFRILANG')),
                      const SizedBox(height: 8),
                      Text(
                        _h('why_title'),
                        style: Theme.of(context).textTheme.titleLarge?.copyWith(fontWeight: FontWeight.w800),
                      ),
                      const SizedBox(height: 8),
                      Text(
                        _h('why_desc'),
                        style: TextStyle(color: Theme.of(context).colorScheme.onSurface.withValues(alpha: 0.65)),
                      ),
                    ],
                  ),
                ),
                const SizedBox(height: 16),
                _FeatureCard(
                  title: _stripHtml(_h('feat_natural_title', 'Syntaxe naturelle')),
                  body: _stripHtml(_h('feat_natural')),
                  icon: Icons.chat_bubble_outline_rounded,
                  delay: 0,
                ),
                _FeatureCard(
                  title: _stripHtml(_h('feat_perf_title', 'Performance native')),
                  body: _stripHtml(_h('feat_perf')),
                  icon: Icons.speed_rounded,
                  delay: 80,
                ),
                _FeatureCard(
                  title: _stripHtml(_h('feat_tools_title', 'Toolchain intégrée')),
                  body: _stripHtml(_h('feat_tools')),
                  icon: Icons.build_circle_outlined,
                  delay: 160,
                ),
                const SizedBox(height: 28),
                FadeSlideIn(
                  child: Row(
                    children: [
                      Expanded(
                        child: Column(
                          crossAxisAlignment: CrossAxisAlignment.start,
                          children: [
                            SectionLabel(_h('packages_label', 'Écosystème')),
                            Text(
                              _h('packages_title', 'Paquets certifiés'),
                              style: Theme.of(context).textTheme.titleLarge?.copyWith(fontWeight: FontWeight.w800),
                            ),
                          ],
                        ),
                      ),
                      TextButton(
                        onPressed: () => widget.onNavigate?.call(2),
                        child: Text(_h('packages_all', 'Voir tout →')),
                      ),
                    ],
                  ),
                ),
                const SizedBox(height: 8),
                if (packages.isEmpty)
                  Text(_stripHtml(_h('packages_empty', 'Registre vide')))
                else
                  ...packages.take(6).map((p) {
                    final m = p as Map<String, dynamic>;
                    return Card(
                      margin: const EdgeInsets.only(bottom: 10),
                      child: ListTile(
                        leading: Icon(
                          m['blessed'] == true ? Icons.verified_rounded : Icons.inventory_2_outlined,
                          color: AfrColors.primary,
                        ),
                        title: Text('${m['name']} · v${m['version']}'),
                        subtitle: Text(
                          (m['description'] as String?) ?? '',
                          maxLines: 2,
                          overflow: TextOverflow.ellipsis,
                        ),
                        onTap: () => widget.onNavigate?.call(2),
                      ),
                    ).animate().fadeIn(duration: 400.ms).slideX(begin: 0.04, end: 0);
                  }),
                const SizedBox(height: 24),
                FadeSlideIn(
                  child: Container(
                    width: double.infinity,
                    padding: const EdgeInsets.all(22),
                    decoration: BoxDecoration(
                      gradient: const LinearGradient(
                        colors: [AfrColors.primary, AfrColors.primaryDark],
                      ),
                      borderRadius: BorderRadius.circular(18),
                    ),
                    child: Column(
                      crossAxisAlignment: CrossAxisAlignment.start,
                      children: [
                        Text(
                          _h('cta_title', 'Prêt à écrire votre premier programme ?'),
                          style: const TextStyle(
                            color: Colors.white,
                            fontSize: 20,
                            fontWeight: FontWeight.w800,
                          ),
                        ),
                        const SizedBox(height: 8),
                        Text(
                          _h('cta_desc'),
                          style: TextStyle(color: Colors.white.withValues(alpha: 0.85)),
                        ),
                        const SizedBox(height: 16),
                        Wrap(
                          spacing: 8,
                          runSpacing: 8,
                          children: [
                            FilledButton(
                              style: FilledButton.styleFrom(backgroundColor: Colors.white, foregroundColor: AfrColors.primary),
                              onPressed: () => widget.onNavigate?.call(1),
                              child: Text(_h('cta_guide', 'Guide de démarrage')),
                            ),
                            OutlinedButton(
                              style: OutlinedButton.styleFrom(
                                foregroundColor: Colors.white,
                                side: const BorderSide(color: Colors.white70),
                              ),
                              onPressed: () => widget.onNavigate?.call(5),
                              child: Text(_h('cta_play', 'Playground')),
                            ),
                          ],
                        ),
                      ],
                    ),
                  ),
                ),
              ]),
            ),
          ),
        ],
      ),
    );
  }

  String _stripHtml(String s) => s
      .replaceAll(RegExp(r'<[^>]*>'), '')
      .replaceAll('&nbsp;', ' ')
      .replaceAll('&amp;', '&');
}

class _FeatureCard extends StatelessWidget {
  const _FeatureCard({
    required this.title,
    required this.body,
    required this.icon,
    required this.delay,
  });

  final String title;
  final String body;
  final IconData icon;
  final int delay;

  @override
  Widget build(BuildContext context) {
    return FadeSlideIn(
      delay: delay.ms,
      child: Card(
        margin: const EdgeInsets.only(bottom: 12),
        child: Padding(
          padding: const EdgeInsets.all(16),
          child: Row(
            crossAxisAlignment: CrossAxisAlignment.start,
            children: [
              Container(
                padding: const EdgeInsets.all(10),
                decoration: BoxDecoration(
                  color: AfrColors.primary.withValues(alpha: 0.1),
                  borderRadius: BorderRadius.circular(12),
                ),
                child: Icon(icon, color: AfrColors.primary),
              ),
              const SizedBox(width: 14),
              Expanded(
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Text(title, style: const TextStyle(fontWeight: FontWeight.w700, fontSize: 16)),
                    const SizedBox(height: 6),
                    Text(body, style: TextStyle(color: Theme.of(context).colorScheme.onSurface.withValues(alpha: 0.7))),
                  ],
                ),
              ),
            ],
          ),
        ),
      ),
    );
  }
}

/// Renders simple HTML snippets from docs blocks.
class HtmlBlock extends StatelessWidget {
  const HtmlBlock(this.html, {super.key});
  final String html;

  @override
  Widget build(BuildContext context) {
    return Html(
      data: html,
      style: {
        'body': Style(
          margin: Margins.zero,
          padding: HtmlPaddings.zero,
          fontSize: FontSize(15),
          lineHeight: const LineHeight(1.55),
        ),
        'code': Style(
          backgroundColor: AfrColors.bgSubtle,
          fontFamily: 'JetBrains Mono',
          fontSize: FontSize(13),
        ),
      },
    );
  }
}
