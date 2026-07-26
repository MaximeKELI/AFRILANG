import 'dart:io';

import 'package:path/path.dart' as p;

class SearchHit {
  SearchHit({
    required this.path,
    required this.line,
    required this.column,
    required this.preview,
  });
  final String path;
  final int line;
  final int column;
  final String preview;
}

class SearchService {
  Future<List<SearchHit>> findInFiles({
    required String root,
    required String query,
    bool caseSensitive = false,
    Set<String> extensions = const {'.afr', '.toml', '.md', '.txt'},
  }) async {
    if (query.isEmpty) return [];
    // Prefer ripgrep when available.
    try {
      final args = <String>[
        '--line-number',
        '--column',
        '--no-heading',
        '--color',
        'never',
        if (!caseSensitive) '-i',
        '-g',
        '*.afr',
        '-g',
        '*.toml',
        query,
        root,
      ];
      final r = await Process.run('rg', args);
      if (r.exitCode == 0 || r.exitCode == 1) {
        return _parseRg(r.stdout as String);
      }
    } catch (_) {}
    return _walkDart(root, query, caseSensitive, extensions);
  }

  List<SearchHit> _parseRg(String out) {
    final hits = <SearchHit>[];
    for (final line in out.split('\n')) {
      if (line.isEmpty) continue;
      final m = RegExp(r'^(.*?):(\d+):(\d+):(.*)$').firstMatch(line);
      if (m == null) continue;
      hits.add(SearchHit(
        path: m.group(1)!,
        line: int.parse(m.group(2)!),
        column: int.parse(m.group(3)!),
        preview: m.group(4)!.trim(),
      ));
    }
    return hits;
  }

  Future<List<SearchHit>> _walkDart(
    String root,
    String query,
    bool caseSensitive,
    Set<String> extensions,
  ) async {
    final q = caseSensitive ? query : query.toLowerCase();
    final hits = <SearchHit>[];
    final dir = Directory(root);
    await for (final ent in dir.list(recursive: true, followLinks: false)) {
      if (ent is! File) continue;
      final name = p.basename(ent.path);
      if (name.startsWith('.')) continue;
      if (ent.path.contains('${p.separator}build${p.separator}')) continue;
      if (ent.path.contains('${p.separator}.git${p.separator}')) continue;
      final ext = p.extension(ent.path);
      if (!extensions.contains(ext)) continue;
      String text;
      try {
        text = await ent.readAsString();
      } catch (_) {
        continue;
      }
      final lines = text.split('\n');
      for (var i = 0; i < lines.length; i++) {
        final src = caseSensitive ? lines[i] : lines[i].toLowerCase();
        final idx = src.indexOf(q);
        if (idx >= 0) {
          hits.add(SearchHit(
            path: ent.path,
            line: i + 1,
            column: idx + 1,
            preview: lines[i].trim(),
          ));
          if (hits.length >= 500) return hits;
        }
      }
    }
    return hits;
  }
}
