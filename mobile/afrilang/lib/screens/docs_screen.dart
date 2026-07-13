import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

import '../state/app_state.dart';
import '../theme/afrilang_theme.dart';
import '../widgets/common.dart';
import 'home_screen.dart' show HtmlBlock;

class DocsScreen extends StatefulWidget {
  const DocsScreen({super.key});

  @override
  State<DocsScreen> createState() => _DocsScreenState();
}

class _DocsScreenState extends State<DocsScreen> {
  List<dynamic> _pages = [];
  bool _loading = true;
  String? _error;

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
      final data = await app.api.docsIndex(app.lang);
      if (!mounted) return;
      setState(() {
        _pages = (data['pages'] as List?) ?? [];
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
    final app = context.watch<AppState>();
    if (_loading) return const Center(child: CircularProgressIndicator());
    if (_error != null) return EmptyError(message: _error!, onRetry: _load);

    return RefreshIndicator(
      onRefresh: _load,
      child: ListView.builder(
        padding: const EdgeInsets.fromLTRB(16, 12, 16, 32),
        itemCount: _pages.length + 1,
        itemBuilder: (context, i) {
          if (i == 0) {
            return Padding(
              padding: const EdgeInsets.only(bottom: 16),
              child: FadeSlideIn(
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Text(
                      app.t('nav_docs', 'Documentation'),
                      style: Theme.of(context).textTheme.headlineSmall?.copyWith(fontWeight: FontWeight.w800),
                    ),
                    const SizedBox(height: 6),
                    Text(
                      app.lang == 'en'
                          ? 'Official AFRILANG documentation — same content as the website.'
                          : 'Documentation officielle AFRILANG — même contenu que le site.',
                      style: TextStyle(color: Theme.of(context).colorScheme.onSurface.withValues(alpha: 0.65)),
                    ),
                  ],
                ),
              ),
            );
          }
          final p = _pages[i - 1] as Map<String, dynamic>;
          return FadeSlideIn(
            delay: Duration(milliseconds: 40 * i),
            child: Card(
              margin: const EdgeInsets.only(bottom: 10),
              child: ListTile(
                contentPadding: const EdgeInsets.symmetric(horizontal: 16, vertical: 8),
                leading: CircleAvatar(
                  backgroundColor: AfrColors.primary.withValues(alpha: 0.12),
                  foregroundColor: AfrColors.primary,
                  child: Text('$i', style: const TextStyle(fontWeight: FontWeight.w700, fontSize: 13)),
                ),
                title: Text(p['title']?.toString() ?? '', style: const TextStyle(fontWeight: FontWeight.w700)),
                subtitle: Text(
                  (p['description'] ?? p['lead'] ?? '').toString(),
                  maxLines: 2,
                  overflow: TextOverflow.ellipsis,
                ),
                trailing: const Icon(Icons.chevron_right_rounded),
                onTap: () {
                  Navigator.of(context).push(
                    MaterialPageRoute(
                      builder: (_) => DocsDetailScreen(slug: p['slug'] as String),
                    ),
                  );
                },
              ),
            ),
          );
        },
      ),
    );
  }
}

class DocsDetailScreen extends StatefulWidget {
  const DocsDetailScreen({super.key, required this.slug});
  final String slug;

  @override
  State<DocsDetailScreen> createState() => _DocsDetailScreenState();
}

class _DocsDetailScreenState extends State<DocsDetailScreen> {
  Map<String, dynamic>? _page;
  bool _loading = true;
  String? _error;

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
      final data = await app.api.docsPage(widget.slug, app.lang);
      if (!mounted) return;
      setState(() {
        _page = data;
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
      appBar: AppBar(title: Text(_page?['title']?.toString() ?? widget.slug)),
      body: _loading
          ? const Center(child: CircularProgressIndicator())
          : _error != null
              ? EmptyError(message: _error!, onRetry: _load)
              : ListView(
                  padding: const EdgeInsets.fromLTRB(20, 12, 20, 40),
                  children: [
                    if ((_page?['lead'] as String?)?.isNotEmpty == true)
                      Padding(
                        padding: const EdgeInsets.only(bottom: 16),
                        child: Text(
                          _page!['lead'] as String,
                          style: TextStyle(
                            fontSize: 16,
                            height: 1.5,
                            color: Theme.of(context).colorScheme.onSurface.withValues(alpha: 0.75),
                          ),
                        ),
                      ),
                    ...((_page?['blocks'] as List?) ?? []).map(_buildBlock),
                  ],
                ),
    );
  }

  Widget _buildBlock(dynamic raw) {
    final b = raw as Map<String, dynamic>;
    switch (b['type']) {
      case 'h2':
        return Padding(
          padding: const EdgeInsets.only(top: 22, bottom: 8),
          child: Text(
            b['text']?.toString() ?? '',
            style: Theme.of(context).textTheme.titleLarge?.copyWith(fontWeight: FontWeight.w800),
          ),
        );
      case 'h3':
        return Padding(
          padding: const EdgeInsets.only(top: 16, bottom: 6),
          child: Text(
            b['text']?.toString() ?? '',
            style: Theme.of(context).textTheme.titleMedium?.copyWith(fontWeight: FontWeight.w700),
          ),
        );
      case 'p':
        return Padding(
          padding: const EdgeInsets.only(bottom: 10),
          child: HtmlBlock(b['html']?.toString() ?? ''),
        );
      case 'code':
        return Padding(
          padding: const EdgeInsets.symmetric(vertical: 10),
          child: CodePanel(
            code: b['text']?.toString() ?? '',
            filename: b['header']?.toString() ?? 'example.afr',
          ),
        );
      case 'ul':
        final items = (b['items'] as List?) ?? [];
        return Padding(
          padding: const EdgeInsets.only(bottom: 12),
          child: Column(
            children: items
                .map((e) => Padding(
                      padding: const EdgeInsets.only(bottom: 6),
                      child: Row(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        children: [
                          const Text('•  ', style: TextStyle(color: AfrColors.primary, fontWeight: FontWeight.bold)),
                          Expanded(child: HtmlBlock(e.toString())),
                        ],
                      ),
                    ))
                .toList(),
          ),
        );
      case 'callout':
        return Container(
          width: double.infinity,
          margin: const EdgeInsets.symmetric(vertical: 10),
          padding: const EdgeInsets.all(14),
          decoration: BoxDecoration(
            color: AfrColors.primary.withValues(alpha: 0.06),
            borderRadius: BorderRadius.circular(12),
            border: const Border(left: BorderSide(color: AfrColors.primary, width: 3)),
          ),
          child: HtmlBlock(b['html']?.toString() ?? ''),
        );
      case 'table':
        final headers = (b['headers'] as List?) ?? [];
        final rows = (b['rows'] as List?) ?? [];
        return SingleChildScrollView(
          scrollDirection: Axis.horizontal,
          child: DataTable(
            columns: headers.map((h) => DataColumn(label: Text(h.toString(), style: const TextStyle(fontWeight: FontWeight.w700)))).toList(),
            rows: rows.map((r) {
              final cells = r is List ? r : [r];
              return DataRow(cells: cells.map((c) => DataCell(Text(c.toString()))).toList());
            }).toList(),
          ),
        );
      default:
        return const SizedBox.shrink();
    }
  }
}
