import 'package:flutter/material.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:provider/provider.dart';

import '../state/app_state.dart';
import '../theme/afrilang_theme.dart';
import '../widgets/common.dart';
import 'docs_screen.dart';
import 'home_screen.dart';
import 'packages_examples.dart';
import 'playground_more.dart';
import 'stdlib_screen.dart';

class ShellScreen extends StatefulWidget {
  const ShellScreen({super.key});

  @override
  State<ShellScreen> createState() => _ShellScreenState();
}

class _ShellScreenState extends State<ShellScreen> {
  int _index = 0;

  void _go(int i) => setState(() => _index = i);

  @override
  Widget build(BuildContext context) {
    final app = context.watch<AppState>();

    if (app.loading && app.bootstrap == null) {
      return Scaffold(
        body: Center(
          child: Column(
            mainAxisSize: MainAxisSize.min,
            children: [
              const AfrBrandMark(size: 32)
                  .animate()
                  .fadeIn(duration: 600.ms)
                  .scale(begin: const Offset(0.9, 0.9), end: const Offset(1, 1)),
              const SizedBox(height: 24),
              const CircularProgressIndicator(),
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
      HomeScreen(onNavigate: _go),
      const DocsScreen(),
      const PackagesScreen(),
      const ExamplesScreen(),
      const StdlibScreen(),
      const PlaygroundScreen(),
      const MoreScreen(),
    ];

    return Scaffold(
      appBar: AppBar(
        title: Row(
          children: [
            const AfrBrandMark(size: 18),
            const SizedBox(width: 10),
            Flexible(
              child: Text(
                _title(app, _index),
                overflow: TextOverflow.ellipsis,
                style: const TextStyle(fontWeight: FontWeight.w600, fontSize: 16),
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
          TextButton(
            onPressed: () => app.setLang(app.lang == 'fr' ? 'en' : 'fr'),
            child: Text(app.lang.toUpperCase()),
          ),
        ],
      ),
      body: IndexedStack(index: _index, children: pages),
      bottomNavigationBar: NavigationBar(
        selectedIndex: _index,
        onDestinationSelected: _go,
        height: 68,
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
            icon: const Icon(Icons.inventory_2_outlined),
            selectedIcon: const Icon(Icons.inventory_2_rounded),
            label: app.t('nav_packages', 'Pkgs'),
          ),
          NavigationDestination(
            icon: const Icon(Icons.code_outlined),
            selectedIcon: const Icon(Icons.code_rounded),
            label: app.t('nav_examples', 'Ex.'),
          ),
          NavigationDestination(
            icon: const Icon(Icons.library_books_outlined),
            selectedIcon: const Icon(Icons.library_books_rounded),
            label: app.t('nav_stdlib', 'Std'),
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
        return app.t('nav_packages', 'Paquets');
      case 3:
        return app.t('nav_examples', 'Exemples');
      case 4:
        return app.t('nav_stdlib', 'Stdlib');
      case 5:
        return app.t('nav_playground', 'Playground');
      default:
        return app.t('nav_more', 'Plus');
    }
  }
}
