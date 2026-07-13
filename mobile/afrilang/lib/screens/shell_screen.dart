import 'package:flutter/material.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:provider/provider.dart';

import '../state/app_state.dart';
import '../theme/afrilang_theme.dart';
import '../widgets/common.dart';
import 'docs_screen.dart';
import 'explore_screen.dart';
import 'home_screen.dart';
import 'more_screen.dart';
import 'playground_screen.dart';

class ShellScreen extends StatefulWidget {
  const ShellScreen({super.key});

  @override
  State<ShellScreen> createState() => _ShellScreenState();
}

class _ShellScreenState extends State<ShellScreen> {
  int _index = 0;
  int _exploreTab = 0;
  Key _exploreKey = UniqueKey();

  void _go(int i, {int? exploreTab}) {
    setState(() {
      if (exploreTab != null) {
        _exploreTab = exploreTab;
        _exploreKey = UniqueKey();
      }
      _index = i;
    });
  }

  @override
  Widget build(BuildContext context) {
    final app = context.watch<AppState>();

    if (app.loading && app.bootstrap == null) {
      return Scaffold(
        body: Center(
          child: Column(
            mainAxisSize: MainAxisSize.min,
            children: [
              const AfrBrandMark(size: 36)
                  .animate(onPlay: (c) => c.repeat(reverse: true))
                  .fadeIn(duration: 500.ms)
                  .scale(begin: const Offset(0.92, 0.92), end: const Offset(1.04, 1.04), duration: 1400.ms),
              const SizedBox(height: 28),
              const SizedBox(width: 28, height: 28, child: CircularProgressIndicator(strokeWidth: 2.5)),
              if (app.error != null) ...[
                const SizedBox(height: 16),
                Padding(
                  padding: const EdgeInsets.symmetric(horizontal: 32),
                  child: Text(app.error!, textAlign: TextAlign.center, style: const TextStyle(fontSize: 13)),
                ),
                TextButton(onPressed: app.refreshBootstrap, child: const Text('Réessayer')),
              ],
            ],
          ),
        ),
      );
    }

    final pages = [
      HomeScreen(onNavigate: (tab, {exploreTab}) => _go(tab, exploreTab: exploreTab)),
      const DocsScreen(),
      ExploreScreen(key: _exploreKey, initialTab: _exploreTab),
      const PlaygroundScreen(),
      MoreScreen(
        onOpenExplore: (t) => _go(2, exploreTab: t),
        onOpenPlay: () => _go(3),
        onOpenDocs: () => _go(1),
      ),
    ];

    return Scaffold(
      appBar: AppBar(
        title: Row(
          children: [
            GestureDetector(
              onTap: () => _go(0),
              child: const AfrBrandMark(size: 18),
            ),
            const SizedBox(width: 10),
            Flexible(
              child: AnimatedSwitcher(
                duration: const Duration(milliseconds: 220),
                child: Text(
                  _title(app, _index),
                  key: ValueKey(_index),
                  overflow: TextOverflow.ellipsis,
                  style: const TextStyle(fontWeight: FontWeight.w600, fontSize: 16),
                ),
              ),
            ),
          ],
        ),
        actions: [
          if (app.error != null)
            IconButton(
              tooltip: 'Reconnect',
              onPressed: app.refreshBootstrap,
              icon: const Icon(Icons.refresh_rounded, color: AfrColors.accent),
            ),
          Padding(
            padding: const EdgeInsets.only(right: 8),
            child: SegmentedButton<String>(
              style: const ButtonStyle(
                visualDensity: VisualDensity.compact,
                tapTargetSize: MaterialTapTargetSize.shrinkWrap,
              ),
              segments: const [
                ButtonSegment(value: 'fr', label: Text('FR', style: TextStyle(fontSize: 12))),
                ButtonSegment(value: 'en', label: Text('EN', style: TextStyle(fontSize: 12))),
              ],
              selected: {app.lang},
              onSelectionChanged: (s) => app.setLang(s.first),
            ),
          ),
        ],
      ),
      body: AnimatedSwitcher(
        duration: const Duration(milliseconds: 280),
        switchInCurve: Curves.easeOutCubic,
        switchOutCurve: Curves.easeInCubic,
        transitionBuilder: (child, anim) {
          return FadeTransition(
            opacity: anim,
            child: SlideTransition(
              position: Tween<Offset>(begin: const Offset(0.03, 0), end: Offset.zero).animate(anim),
              child: child,
            ),
          );
        },
        child: KeyedSubtree(
          key: ValueKey(_index),
          child: pages[_index],
        ),
      ),
      bottomNavigationBar: NavigationBar(
        selectedIndex: _index,
        onDestinationSelected: (i) => _go(i),
        height: 70,
        destinations: [
          NavigationDestination(
            icon: const Icon(Icons.home_outlined),
            selectedIcon: const Icon(Icons.home_rounded),
            label: app.lang == 'en' ? 'Home' : 'Accueil',
          ),
          NavigationDestination(
            icon: const Icon(Icons.menu_book_outlined),
            selectedIcon: const Icon(Icons.menu_book_rounded),
            label: app.t('nav_docs', 'Docs'),
          ),
          NavigationDestination(
            icon: const Icon(Icons.explore_outlined),
            selectedIcon: const Icon(Icons.explore_rounded),
            label: app.lang == 'en' ? 'Explore' : 'Explorer',
          ),
          NavigationDestination(
            icon: const Icon(Icons.play_circle_outline),
            selectedIcon: const Icon(Icons.play_circle_filled),
            label: app.t('nav_playground', 'Play'),
          ),
          NavigationDestination(
            icon: const Icon(Icons.more_horiz),
            selectedIcon: const Icon(Icons.more_horiz),
            label: app.t('nav_more', 'Plus'),
          ),
        ],
      ),
    );
  }

  String _title(AppState app, int i) {
    switch (i) {
      case 0:
        return 'AFRILANG';
      case 1:
        return app.t('nav_docs', 'Documentation');
      case 2:
        return app.lang == 'en' ? 'Explore' : 'Explorer';
      case 3:
        return app.t('nav_playground', 'Playground');
      default:
        return app.t('nav_more', 'Plus');
    }
  }
}
