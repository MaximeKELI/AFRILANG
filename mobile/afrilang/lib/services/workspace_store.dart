import 'dart:convert';
import 'dart:io';

import 'package:path_provider/path_provider.dart';
import 'package:shared_preferences/shared_preferences.dart';

const _defaultFile = 'Mes projets/hello.afr';
const _defaultSource = '''say "Bonjour depuis mon projet!"

create name text = "AFRILANG"
say "Hello, {name}!"
''';

/// Local multi-file workspace persisted as JSON under app documents.
class WorkspaceStore {
  WorkspaceStore();

  final Map<String, String> files = {};
  final Set<String> folders = {};
  String? activePath;
  File? _file;

  Future<void> load() async {
    final dir = await getApplicationDocumentsDirectory();
    _file = File('${dir.path}/afrilang_workspace.json');

    if (await _file!.exists()) {
      final raw = jsonDecode(await _file!.readAsString());
      if (raw is Map) {
        final f = raw['files'];
        if (f is Map) {
          f.forEach((k, v) {
            if (k is String && v is String) files[k] = v;
          });
        }
        final dirs = raw['folders'];
        if (dirs is List) {
          for (final d in dirs) {
            if (d is String && d.isNotEmpty) folders.add(d);
          }
        }
        final active = raw['activePath'];
        if (active is String && files.containsKey(active)) {
          activePath = active;
        }
      }
    }

    // Migrate legacy single-buffer prefs once.
    if (files.isEmpty) {
      final prefs = await SharedPreferences.getInstance();
      final legacy = prefs.getString('playground_source');
      if (legacy != null && legacy.trim().isNotEmpty) {
        files['Mes projets/scratch.afr'] = legacy;
        folders.add('Mes projets');
        activePath = 'Mes projets/scratch.afr';
        await prefs.remove('playground_source');
      }
    }

    if (files.isEmpty) {
      files[_defaultFile] = _defaultSource;
      folders.add('Mes projets');
      activePath = _defaultFile;
    }

    activePath ??= files.keys.first;
    _deriveFolders();
    await persist();
  }

  void _deriveFolders() {
    for (final path in files.keys) {
      final parts = path.split('/');
      for (var i = 1; i < parts.length; i++) {
        folders.add(parts.sublist(0, i).join('/'));
      }
    }
  }

  Future<void> persist() async {
    _file ??= File(
      '${(await getApplicationDocumentsDirectory()).path}/afrilang_workspace.json',
    );
    final payload = {
      'files': files,
      'folders': folders.toList()..sort(),
      'activePath': activePath,
    };
    await _file!.writeAsString(const JsonEncoder.withIndent('  ').convert(payload));
  }

  String get activeSource => files[activePath] ?? '';

  void setActiveSource(String code) {
    if (activePath == null) return;
    files[activePath!] = code;
  }

  void openFile(String path) {
    final p = _norm(path);
    if (!files.containsKey(p)) {
      throw StateError('Fichier introuvable');
    }
    activePath = p;
  }

  void createFolder(String path) {
    final p = _norm(path, allowFile: false);
    if (p.isEmpty) throw ArgumentError('Nom de dossier requis');
    folders.add(p);
  }

  void createFile(String path, {String? content}) {
    var p = _norm(path);
    if (!p.toLowerCase().endsWith('.afr')) p = '$p.afr';
    if (files.containsKey(p)) throw StateError('Le fichier existe déjà');
    final dir = _parent(p);
    if (dir != null) folders.add(dir);
    files[p] = content ?? 'say "Nouveau fichier: $p"\n';
    activePath = p;
  }

  void deletePath(String path) {
    final p = _norm(path, allowFile: false);
    if (files.containsKey(p) || p.toLowerCase().endsWith('.afr')) {
      final key = files.containsKey(p) ? p : (p.toLowerCase().endsWith('.afr') ? p : '$p.afr');
      files.remove(key);
      if (activePath == key) {
        activePath = files.keys.isEmpty ? null : (files.keys.toList()..sort()).first;
      }
    } else {
      folders.removeWhere((f) => f == p || f.startsWith('$p/'));
      files.removeWhere((k, _) => k == p || k.startsWith('$p/'));
      if (activePath != null && (activePath == p || activePath!.startsWith('$p/'))) {
        activePath = files.keys.isEmpty ? null : (files.keys.toList()..sort()).first;
      }
    }
    if (files.isEmpty) {
      files[_defaultFile] = _defaultSource;
      folders
        ..clear()
        ..add('Mes projets');
      activePath = _defaultFile;
    }
  }

  String copySnippet(String name, String source) {
    var path = 'Mes projets/${_safeName(name)}.afr';
    var n = 2;
    while (files.containsKey(path)) {
      path = 'Mes projets/${_safeName(name)}_$n.afr';
      n++;
    }
    folders.add('Mes projets');
    files[path] = source;
    activePath = path;
    return path;
  }

  Map<String, dynamic> runPayload() {
    if (activePath == null || !files.containsKey(activePath)) {
      throw StateError('Aucun fichier actif');
    }
    return {
      'entry': activePath,
      'files': Map<String, String>.from(files),
    };
  }

  List<String> sortedPaths() {
    final list = files.keys.toList()..sort();
    return list;
  }

  List<String> sortedFolders() {
    final list = folders.toList()..sort();
    return list;
  }

  static String _safeName(String name) {
    return name.replaceAll(RegExp(r'[^a-zA-Z0-9_-]+'), '_').replaceAll(RegExp(r'^_+|_+$'), '');
  }

  static String? _parent(String path) {
    final i = path.lastIndexOf('/');
    if (i <= 0) return null;
    return path.substring(0, i);
  }

  static String _norm(String raw, {bool allowFile = true}) {
    var p = raw.replaceAll('\\', '/').replaceAll(RegExp(r'^/+'), '').trim();
    final parts = p.split('/').where((x) => x.isNotEmpty && x != '.').toList();
    if (parts.any((x) => x == '..' || x.startsWith('.'))) {
      throw ArgumentError('Chemin invalide');
    }
    return parts.join('/');
  }
}
