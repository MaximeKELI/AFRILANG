import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

import '../state/app_state.dart';
import 'packages_examples.dart';
import 'stdlib_screen.dart';

/// Hub Écosystème : Paquets · Exemples · Stdlib (comme le site).
class ExploreScreen extends StatefulWidget {
  const ExploreScreen({super.key, this.initialTab = 0});
  final int initialTab;


  @override
  State<ExploreScreen> createState() => _ExploreScreenState();
}

class _ExploreScreenState extends State<ExploreScreen> with SingleTickerProviderStateMixin {
  late final TabController _tabs;

  @override
  void initState() {
    super.initState();
    _tabs = TabController(length: 3, vsync: this, initialIndex: widget.initialTab.clamp(0, 2));
  }

  @override
  void dispose() {
    _tabs.dispose();
    super.dispose();
  }

  @override
  Widget build(BuildContext context) {
    final app = context.watch<AppState>();
    return Column(
      children: [
        TabBar(
          controller: _tabs,
          labelColor: Theme.of(context).colorScheme.primary,
          unselectedLabelColor: Theme.of(context).colorScheme.onSurface.withValues(alpha: 0.55),
          indicatorColor: Theme.of(context).colorScheme.primary,
          tabs: [
            Tab(text: app.t('nav_packages', 'Paquets')),
            Tab(text: app.t('nav_examples', 'Exemples')),
            Tab(text: app.t('nav_stdlib', 'Stdlib')),
          ],
        ),
        Expanded(
          child: TabBarView(
            controller: _tabs,
            children: const [
              PackagesScreen(),
              ExamplesScreen(),
              StdlibScreen(),
            ],
          ),
        ),
      ],
    );
  }
}
