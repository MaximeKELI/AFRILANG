import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:provider/provider.dart';

import '../state/app_state.dart';
import '../theme/afrilang_theme.dart';
import '../widgets/common.dart';

class PackagesScreen extends StatefulWidget {
  const PackagesScreen({super.key});

  @override
  State<PackagesScreen> createState() => _PackagesScreenState();
}

class _PackagesScreenState extends State<PackagesScreen> {
  final _q = TextEditingController();
  List<dynamic> _pkgs = [];
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

  Future<void> _load([String query = '']) async {
    final app = context.read<AppState>();
    setState(() {
      _loading = true;
      _error = null;
    });
    try {
      final data = await app.api.packages(q: query, lang: app.lang);
      if (!mounted) return;
      setState(() {
        _pkgs = (data['packages'] as List?) ?? [];
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
          padding: const EdgeInsets.fromLTRB(16, 12, 16, 8),
          child: TextField(
            controller: _q,
            decoration: InputDecoration(
              hintText: app.lang == 'en' ? 'Search packages…' : 'Rechercher un paquet…',
              prefixIcon: const Icon(Icons.search_rounded),
              suffixIcon: IconButton(
                icon: const Icon(Icons.clear),
                onPressed: () {
                  _q.clear();
                  _load();
                },
              ),
            ),
            onSubmitted: _load,
          ),
        ),
        Expanded(
          child: _loading
              ? const Center(child: CircularProgressIndicator())
              : _error != null
                  ? EmptyError(message: _error!, onRetry: () => _load(_q.text))
                  : RefreshIndicator(
                      onRefresh: () => _load(_q.text),
                      child: ListView.builder(
                        padding: const EdgeInsets.fromLTRB(16, 0, 16, 24),
                        itemCount: _pkgs.length,
                        itemBuilder: (context, i) {
                          final p = _pkgs[i] as Map<String, dynamic>;
                          return FadeSlideIn(
                            delay: Duration(milliseconds: 30 * (i % 12)),
                            child: Card(
                              margin: const EdgeInsets.only(bottom: 10),
                              child: ListTile(
                                leading: Icon(
                                  p['blessed'] == true ? Icons.verified_rounded : Icons.inventory_2_outlined,
                                  color: AfrColors.primary,
                                ),
                                title: Text('${p['name']}', style: const TextStyle(fontWeight: FontWeight.w700)),
                                subtitle: Text(
                                  'v${p['version']} — ${p['description'] ?? ''}',
                                  maxLines: 2,
                                  overflow: TextOverflow.ellipsis,
                                ),
                                onTap: () => Navigator.of(context).push(
                                  MaterialPageRoute(
                                    builder: (_) => PackageDetailScreen(name: p['name'] as String),
                                  ),
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

class PackageDetailScreen extends StatefulWidget {
  const PackageDetailScreen({super.key, required this.name});
  final String name;

  @override
  State<PackageDetailScreen> createState() => _PackageDetailScreenState();
}

class _PackageDetailScreenState extends State<PackageDetailScreen> {
  Map<String, dynamic>? _pkg;
  bool _loading = true;
  String? _error;

  @override
  void initState() {
    super.initState();
    _load();
  }

  Future<void> _load() async {
    try {
      final data = await context.read<AppState>().api.packageDetail(widget.name);
      if (!mounted) return;
      setState(() {
        _pkg = data;
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
                    Row(
                      children: [
                        if (_pkg!['blessed'] == true)
                          const Padding(
                            padding: EdgeInsets.only(right: 8),
                            child: Icon(Icons.verified_rounded, color: AfrColors.primary),
                          ),
                        Text(
                          'v${_pkg!['version']}',
                          style: const TextStyle(fontWeight: FontWeight.w700, color: AfrColors.primary),
                        ),
                      ],
                    ),
                    const SizedBox(height: 12),
                    Text(_pkg!['description']?.toString() ?? ''),
                    const SizedBox(height: 20),
                    CodePanel(
                      code: _pkg!['install']?.toString() ?? 'afrilang pkg add ${widget.name}',
                      filename: 'install.sh',
                    ),
                    if ((_pkg!['readme'] as String?)?.isNotEmpty == true) ...[
                      const SizedBox(height: 24),
                      Text('README', style: Theme.of(context).textTheme.titleMedium?.copyWith(fontWeight: FontWeight.w800)),
                      const SizedBox(height: 8),
                      SelectableText(_pkg!['readme'] as String),
                    ],
                  ],
                ),
    );
  }
}

class ExamplesScreen extends StatefulWidget {
  const ExamplesScreen({super.key});

  @override
  State<ExamplesScreen> createState() => _ExamplesScreenState();
}

class _ExamplesScreenState extends State<ExamplesScreen> {
  List<dynamic> _items = [];
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
      final data = await app.api.examples(lang: app.lang);
      if (!mounted) return;
      setState(() {
        _items = (data['examples'] as List?) ?? [];
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
    return RefreshIndicator(
      onRefresh: _load,
      child: ListView.builder(
        padding: const EdgeInsets.all(16),
        itemCount: _items.length,
        itemBuilder: (context, i) {
          final e = _items[i] as Map<String, dynamic>;
          return FadeSlideIn(
            delay: Duration(milliseconds: 25 * (i % 15)),
            child: Card(
              margin: const EdgeInsets.only(bottom: 10),
              child: ListTile(
                leading: const Icon(Icons.code_rounded, color: AfrColors.primary),
                title: Text(e['title']?.toString() ?? e['slug']?.toString() ?? '', style: const TextStyle(fontWeight: FontWeight.w700)),
                subtitle: Text(
                  e['source_preview']?.toString() ?? '',
                  maxLines: 2,
                  overflow: TextOverflow.ellipsis,
                  style: afrMono(fontSize: 11, color: AfrColors.textSecondary),
                ),
                onTap: () => Navigator.of(context).push(
                  MaterialPageRoute(builder: (_) => ExampleDetailScreen(slug: e['slug'] as String)),
                ),
              ),
            ),
          );
        },
      ),
    );
  }
}

class ExampleDetailScreen extends StatefulWidget {
  const ExampleDetailScreen({super.key, required this.slug});
  final String slug;

  @override
  State<ExampleDetailScreen> createState() => _ExampleDetailScreenState();
}

class _ExampleDetailScreenState extends State<ExampleDetailScreen> {
  Map<String, dynamic>? _ex;
  bool _loading = true;
  String? _error;
  String? _output;
  bool _running = false;

  @override
  void initState() {
    super.initState();
    _load();
  }

  Future<void> _load() async {
    try {
      final data = await context.read<AppState>().api.example(widget.slug);
      if (!mounted) return;
      setState(() {
        _ex = data;
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
    final src = _ex?['source']?.toString() ?? '';
    setState(() => _running = true);
    try {
      final res = await context.read<AppState>().api.run(src);
      if (!mounted) return;
      setState(() => _output = res['output']?.toString() ?? '');
    } catch (e) {
      if (!mounted) return;
      setState(() => _output = e.toString());
    } finally {
      if (mounted) setState(() => _running = false);
    }
  }

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: Text(_ex?['title']?.toString() ?? widget.slug),
        actions: [
          IconButton(
            icon: const Icon(Icons.copy_rounded),
            onPressed: () {
              Clipboard.setData(ClipboardData(text: _ex?['source']?.toString() ?? ''));
            },
          ),
        ],
      ),
      body: _loading
          ? const Center(child: CircularProgressIndicator())
          : _error != null
              ? EmptyError(message: _error!, onRetry: _load)
              : ListView(
                  padding: const EdgeInsets.all(16),
                  children: [
                    CodePanel(code: _ex!['source']?.toString() ?? '', filename: '${widget.slug}.afr'),
                    const SizedBox(height: 16),
                    ElevatedButton.icon(
                      onPressed: _running ? null : _run,
                      icon: _running
                          ? const SizedBox(width: 16, height: 16, child: CircularProgressIndicator(strokeWidth: 2, color: Colors.white))
                          : const Icon(Icons.play_arrow_rounded),
                      label: Text(_running ? '…' : 'Run'),
                    ),
                    if (_output != null) ...[
                      const SizedBox(height: 16),
                      CodePanel(code: _output!, filename: 'output'),
                    ],
                  ],
                ),
    );
  }
}
