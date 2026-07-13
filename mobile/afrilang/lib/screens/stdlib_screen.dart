import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

import '../state/app_state.dart';
import '../theme/afrilang_theme.dart';
import '../widgets/common.dart';
import 'home_screen.dart' show HtmlBlock;

class StdlibScreen extends StatefulWidget {
  const StdlibScreen({super.key});

  @override
  State<StdlibScreen> createState() => _StdlibScreenState();
}

class _StdlibScreenState extends State<StdlibScreen> {
  final _q = TextEditingController();
  List<dynamic> _mods = [];
  bool _coreOnly = true;
  bool _loading = true;
  String? _error;

  @override
  void initState() {
    super.initState();
    _load();
  }

  @override
  void dispose() {
    _q.dispose();
    super.dispose();
  }

  Future<void> _load() async {
    final app = context.read<AppState>();
    setState(() {
      _loading = true;
      _error = null;
    });
    try {
      final data = await app.api.stdlib(
        lang: app.lang,
        q: _q.text.trim(),
        coreOnly: _coreOnly,
        experimental: !_coreOnly,
      );
      if (!mounted) return;
      setState(() {
        _mods = (data['modules'] as List?) ?? [];
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
    return Column(
      children: [
        Padding(
          padding: const EdgeInsets.fromLTRB(16, 12, 16, 4),
          child: TextField(
            controller: _q,
            decoration: InputDecoration(
              hintText: app.lang == 'en' ? 'Search modules…' : 'Rechercher un module…',
              prefixIcon: const Icon(Icons.search_rounded),
            ),
            onSubmitted: (_) => _load(),
          ),
        ),
        Padding(
          padding: const EdgeInsets.symmetric(horizontal: 12),
          child: Row(
            children: [
              FilterChip(
                label: Text(app.lang == 'en' ? 'Core' : 'Cœur'),
                selected: _coreOnly,
                onSelected: (_) {
                  setState(() => _coreOnly = true);
                  _load();
                },
              ),
              const SizedBox(width: 8),
              FilterChip(
                label: Text(app.lang == 'en' ? 'All / experimental' : 'Tout / expérimental'),
                selected: !_coreOnly,
                onSelected: (_) {
                  setState(() => _coreOnly = false);
                  _load();
                },
              ),
              const Spacer(),
              Text('${_mods.length}', style: const TextStyle(color: AfrColors.textSecondary)),
            ],
          ),
        ),
        Expanded(
          child: _loading
              ? const Center(child: CircularProgressIndicator())
              : _error != null
                  ? EmptyError(message: _error!, onRetry: _load)
                  : RefreshIndicator(
                      onRefresh: _load,
                      child: ListView.builder(
                        padding: const EdgeInsets.fromLTRB(16, 8, 16, 24),
                        itemCount: _mods.length,
                        itemBuilder: (context, i) {
                          final m = _mods[i] as Map<String, dynamic>;
                          return Card(
                            margin: const EdgeInsets.only(bottom: 8),
                            child: ListTile(
                              title: Text(m['name']?.toString() ?? '', style: const TextStyle(fontWeight: FontWeight.w700)),
                              subtitle: Text(
                                m['summary']?.toString().isNotEmpty == true
                                    ? m['summary'].toString()
                                    : (m['description']?.toString() ?? m['import_path']?.toString() ?? ''),
                                maxLines: 2,
                                overflow: TextOverflow.ellipsis,
                              ),
                              trailing: Chip(
                                label: Text(m['tier']?.toString() ?? '', style: const TextStyle(fontSize: 11)),
                                visualDensity: VisualDensity.compact,
                                padding: EdgeInsets.zero,
                              ),
                              onTap: () => Navigator.of(context).push(
                                MaterialPageRoute(
                                  builder: (_) => StdlibDetailScreen(name: m['name'] as String),
                                ),
                              ),
                            ),
                          );
                        },
                      ),
                    ),
        ),
      ],
    );
  }
}

class StdlibDetailScreen extends StatefulWidget {
  const StdlibDetailScreen({super.key, required this.name});
  final String name;

  @override
  State<StdlibDetailScreen> createState() => _StdlibDetailScreenState();
}

class _StdlibDetailScreenState extends State<StdlibDetailScreen> {
  Map<String, dynamic>? _m;
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
      final data = await app.api.stdlibDetail(widget.name, app.lang);
      if (!mounted) return;
      setState(() {
        _m = data;
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
      appBar: AppBar(title: Text(widget.name)),
      body: _loading
          ? const Center(child: CircularProgressIndicator())
          : _error != null
              ? EmptyError(message: _error!, onRetry: _load)
              : ListView(
                  padding: const EdgeInsets.all(20),
                  children: [
                    if (_m!['import_path'] != null)
                      CodePanel(code: 'use ${_m!['use_name'] ?? widget.name}', filename: 'import'),
                    const SizedBox(height: 12),
                    if ((_m!['overview'] as String?)?.isNotEmpty == true)
                      Text(_m!['overview'] as String, style: const TextStyle(height: 1.5)),
                    if ((_m!['description'] as String?)?.isNotEmpty == true) ...[
                      const SizedBox(height: 8),
                      Text(_m!['description'] as String),
                    ],
                    if ((_m!['wasm_note'] as String?)?.isNotEmpty == true) ...[
                      const SizedBox(height: 12),
                      Container(
                        padding: const EdgeInsets.all(12),
                        decoration: BoxDecoration(
                          color: AfrColors.accent.withValues(alpha: 0.08),
                          borderRadius: BorderRadius.circular(10),
                          border: const Border(left: BorderSide(color: AfrColors.accent, width: 3)),
                        ),
                        child: Text(_m!['wasm_note'] as String),
                      ),
                    ],
                    const SizedBox(height: 20),
                    Text('API', style: Theme.of(context).textTheme.titleMedium?.copyWith(fontWeight: FontWeight.w800)),
                    const SizedBox(height: 8),
                    ...((( _m!['functions'] as List?) ?? []).map((f) {
                      final fn = f as Map<String, dynamic>;
                      return Card(
                        margin: const EdgeInsets.only(bottom: 8),
                        child: ListTile(
                          title: Text(fn['name']?.toString() ?? '', style: afrMono(fontSize: 13, color: AfrColors.primary)),
                          subtitle: Text(fn['signature']?.toString() ?? fn['doc']?.toString() ?? ''),
                        ),
                      );
                    })),
                    if ((_m!['example'] as String?)?.isNotEmpty == true) ...[
                      const SizedBox(height: 16),
                      Text('Exemple', style: Theme.of(context).textTheme.titleMedium?.copyWith(fontWeight: FontWeight.w800)),
                      const SizedBox(height: 8),
                      CodePanel(code: _m!['example'] as String, filename: 'example.afr'),
                    ],
                    if ((_m!['doc_body'] as String?)?.isNotEmpty == true) ...[
                      const SizedBox(height: 16),
                      HtmlBlock(_m!['doc_body'] as String),
                    ],
                    if ((_m!['source'] as String?)?.isNotEmpty == true) ...[
                      const SizedBox(height: 16),
                      Text(_m!['source_label']?.toString() ?? 'Source',
                          style: Theme.of(context).textTheme.titleMedium?.copyWith(fontWeight: FontWeight.w800)),
                      if ((_m!['source_note'] as String?)?.isNotEmpty == true)
                        Padding(
                          padding: const EdgeInsets.only(top: 4, bottom: 8),
                          child: Text(_m!['source_note'] as String, style: const TextStyle(fontSize: 13)),
                        ),
                      CodePanel(code: _m!['source'] as String, filename: '${widget.name}.afr', maxHeight: 360),
                    ],
                  ],
                ),
    );
  }
}
