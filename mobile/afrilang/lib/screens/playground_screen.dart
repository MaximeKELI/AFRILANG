import 'dart:async';

import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:provider/provider.dart';

import '../services/workspace_store.dart';
import '../state/app_state.dart';
import '../theme/afrilang_theme.dart';
import '../widgets/motion.dart';

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
  (
    'Multi-file',
    '''import "helpers.afr"

say sum2(20, 22)
'''
  ),
];

const _helpersSnippet = '''function sum2(a number, b number) returns number
    return a + b
end
''';

class PlaygroundScreen extends StatefulWidget {
  const PlaygroundScreen({super.key});

  @override
  State<PlaygroundScreen> createState() => _PlaygroundScreenState();
}

class _PlaygroundScreenState extends State<PlaygroundScreen> {
  late final TextEditingController _src;
  final _ws = WorkspaceStore();
  String _output = '';
  bool? _ok;
  bool _busy = false;
  bool _ready = false;
  Timer? _persistTimer;

  @override
  void initState() {
    super.initState();
    _src = TextEditingController();
    _restore();
    _src.addListener(_persistDebounced);
  }

  void _persistDebounced() {
    _persistTimer?.cancel();
    _persistTimer = Timer(const Duration(milliseconds: 600), _persist);
  }

  Future<void> _restore() async {
    await _ws.load();
    if (!mounted) return;
    _src.text = _ws.activeSource;
    setState(() => _ready = true);
  }

  Future<void> _persist() async {
    _ws.setActiveSource(_src.text);
    await _ws.persist();
  }

  Future<void> _flush() async {
    _ws.setActiveSource(_src.text);
    await _ws.persist();
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
    final api = context.read<AppState>().api;
    await _flush();
    if (!mounted) return;
    setState(() {
      _busy = true;
      _ok = null;
    });
    try {
      final payload = _ws.runPayload();
      final res = await api.run(
            _src.text,
            entry: payload['entry'] as String,
            files: Map<String, String>.from(payload['files'] as Map),
          );
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
    final api = context.read<AppState>().api;
    setState(() => _busy = true);
    try {
      final res = await api.fmt(_src.text);
      if (!mounted) return;
      if (res['ok'] == true && res['source'] != null) {
        _src.text = res['source'].toString();
        await _flush();
      }
      if (!mounted) return;
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
    final api = context.read<AppState>().api;
    await _flush();
    if (!mounted) return;
    setState(() => _busy = true);
    try {
      final payload = _ws.runPayload();
      final res = await api.check(
            _src.text,
            entry: payload['entry'] as String,
            files: Map<String, String>.from(payload['files'] as Map),
          );
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

  Future<void> _openPath(String path) async {
    await _flush();
    _ws.openFile(path);
    _src.text = _ws.activeSource;
    await _ws.persist();
    setState(() {});
  }

  Future<void> _promptNewFile() async {
    final app = context.read<AppState>();
    final controller = TextEditingController(
      text: _ws.activePath?.contains('/') == true
          ? '${_ws.activePath!.substring(0, _ws.activePath!.lastIndexOf('/') + 1)}main.afr'
          : 'Mes projets/main.afr',
    );
    final path = await showDialog<String>(
      context: context,
      builder: (ctx) => AlertDialog(
        title: Text(app.lang == 'en' ? 'New file' : 'Nouveau fichier'),
        content: TextField(
          controller: controller,
          decoration: const InputDecoration(hintText: 'Mes projets/main.afr'),
          autofocus: true,
        ),
        actions: [
          TextButton(onPressed: () => Navigator.pop(ctx), child: Text(app.lang == 'en' ? 'Cancel' : 'Annuler')),
          FilledButton(
            onPressed: () => Navigator.pop(ctx, controller.text.trim()),
            child: Text(app.lang == 'en' ? 'Create' : 'Créer'),
          ),
        ],
      ),
    );
    if (path == null || path.isEmpty) return;
    try {
      await _flush();
      _ws.createFile(path);
      _src.text = _ws.activeSource;
      await _ws.persist();
      setState(() {});
    } catch (e) {
      if (!mounted) return;
      ScaffoldMessenger.of(context).showSnackBar(SnackBar(content: Text('$e')));
    }
  }

  Future<void> _promptNewFolder() async {
    final app = context.read<AppState>();
    final controller = TextEditingController(text: 'Mes projets/mon_jeu');
    final path = await showDialog<String>(
      context: context,
      builder: (ctx) => AlertDialog(
        title: Text(app.lang == 'en' ? 'New folder' : 'Nouveau dossier'),
        content: TextField(controller: controller, autofocus: true),
        actions: [
          TextButton(onPressed: () => Navigator.pop(ctx), child: Text(app.lang == 'en' ? 'Cancel' : 'Annuler')),
          FilledButton(
            onPressed: () => Navigator.pop(ctx, controller.text.trim()),
            child: Text(app.lang == 'en' ? 'Create' : 'Créer'),
          ),
        ],
      ),
    );
    if (path == null || path.isEmpty) return;
    try {
      _ws.createFolder(path);
      await _ws.persist();
      setState(() {});
    } catch (e) {
      if (!mounted) return;
      ScaffoldMessenger.of(context).showSnackBar(SnackBar(content: Text('$e')));
    }
  }

  Future<void> _deletePath(String path) async {
    final app = context.read<AppState>();
    final ok = await showDialog<bool>(
      context: context,
      builder: (ctx) => AlertDialog(
        title: Text(app.lang == 'en' ? 'Delete?' : 'Supprimer ?'),
        content: Text(path),
        actions: [
          TextButton(onPressed: () => Navigator.pop(ctx, false), child: Text(app.lang == 'en' ? 'Cancel' : 'Annuler')),
          FilledButton(onPressed: () => Navigator.pop(ctx, true), child: Text(app.lang == 'en' ? 'Delete' : 'Supprimer')),
        ],
      ),
    );
    if (ok != true) return;
    await _flush();
    _ws.deletePath(path);
    _src.text = _ws.activeSource;
    await _ws.persist();
    setState(() {});
  }

  Future<void> _loadSnippet(String name, String code) async {
    await _flush();
    if (name == 'Multi-file') {
      _ws.files['Mes projets/helpers.afr'] = _helpersSnippet;
      _ws.files['Mes projets/main.afr'] = code;
      _ws.folders.add('Mes projets');
      _ws.activePath = 'Mes projets/main.afr';
    } else {
      _ws.copySnippet(name, code);
    }
    _src.text = _ws.activeSource;
    await _ws.persist();
    setState(() {
      _output = '';
      _ok = null;
    });
  }

  Future<void> _openFilesSheet() async {
    final app = context.read<AppState>();
    await showModalBottomSheet<void>(
      context: context,
      isScrollControlled: true,
      showDragHandle: true,
      builder: (ctx) {
        return DraggableScrollableSheet(
          expand: false,
          initialChildSize: 0.65,
          minChildSize: 0.4,
          maxChildSize: 0.92,
          builder: (_, scrollController) {
            return StatefulBuilder(
              builder: (ctx, setModal) {
                final folders = _ws.sortedFolders();
                final files = _ws.sortedPaths();
                return Column(
                  children: [
                    Padding(
                      padding: const EdgeInsets.fromLTRB(16, 4, 16, 8),
                      child: Row(
                        children: [
                          Expanded(
                            child: Text(
                              app.lang == 'en' ? 'My files' : 'Mes fichiers',
                              style: const TextStyle(fontWeight: FontWeight.w800, fontSize: 16),
                            ),
                          ),
                          TextButton(onPressed: () async {
                            Navigator.pop(ctx);
                            await _promptNewFile();
                          }, child: Text(app.lang == 'en' ? '+ .afr' : '+ .afr')),
                          TextButton(onPressed: () async {
                            Navigator.pop(ctx);
                            await _promptNewFolder();
                          }, child: Text(app.lang == 'en' ? '+ folder' : '+ dossier')),
                        ],
                      ),
                    ),
                    Expanded(
                      child: ListView(
                        controller: scrollController,
                        children: [
                          for (final folder in folders)
                            ListTile(
                              dense: true,
                              leading: const Icon(Icons.folder_outlined, size: 20),
                              title: Text(folder, style: const TextStyle(fontSize: 13)),
                              trailing: IconButton(
                                icon: const Icon(Icons.delete_outline, size: 18),
                                onPressed: () async {
                                  await _deletePath(folder);
                                  setModal(() {});
                                },
                              ),
                            ),
                          for (final path in files)
                            ListTile(
                              dense: true,
                              selected: path == _ws.activePath,
                              leading: const Icon(Icons.description_outlined, size: 20),
                              title: Text(path, style: const TextStyle(fontSize: 13)),
                              onTap: () async {
                                await _openPath(path);
                                if (ctx.mounted) Navigator.pop(ctx);
                              },
                              trailing: IconButton(
                                icon: const Icon(Icons.delete_outline, size: 18),
                                onPressed: () async {
                                  await _deletePath(path);
                                  setModal(() {});
                                },
                              ),
                            ),
                        ],
                      ),
                    ),
                    Padding(
                      padding: const EdgeInsets.all(12),
                      child: Text(
                        app.lang == 'en'
                            ? 'Run sends the active file + whole project (relative imports).'
                            : 'Run envoie le fichier actif + tout le projet (imports relatifs).',
                        style: TextStyle(
                          fontSize: 12,
                          color: Theme.of(context).colorScheme.onSurface.withValues(alpha: 0.6),
                        ),
                      ),
                    ),
                  ],
                );
              },
            );
          },
        );
      },
    );
    if (mounted) setState(() {});
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
          padding: const EdgeInsets.fromLTRB(4, 8, 12, 4),
          child: Row(
            children: [
              IconButton(
                tooltip: app.lang == 'en' ? 'Files' : 'Fichiers',
                onPressed: _openFilesSheet,
                icon: const Icon(Icons.folder_open_rounded),
              ),
              Expanded(
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    Row(
                      children: [
                        Text(
                          app.t('nav_playground', 'Playground'),
                          style: Theme.of(context).textTheme.titleLarge?.copyWith(fontWeight: FontWeight.w800),
                        ),
                        const SizedBox(width: 8),
                        if (_busy) const PulsingDot(),
                      ],
                    ),
                    Text(
                      _ws.activePath ?? '',
                      maxLines: 1,
                      overflow: TextOverflow.ellipsis,
                      style: TextStyle(
                        fontSize: 11,
                        fontFamily: 'JetBrains Mono',
                        color: Theme.of(context).colorScheme.onSurface.withValues(alpha: 0.55),
                      ),
                    ),
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
                    onPressed: () => _loadSnippet(s.$1, s.$2),
                    avatar: const Icon(Icons.bolt_rounded, size: 16),
                  ),
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
