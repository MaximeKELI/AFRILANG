import 'dart:io';

import 'package:path/path.dart' as p;

class GitStatusEntry {
  GitStatusEntry({required this.path, required this.code});
  final String path;
  final String code; // XY from git status --porcelain
}

class GitBlameLine {
  GitBlameLine({
    required this.line,
    required this.hash,
    required this.author,
    required this.summary,
  });
  final int line;
  final String hash;
  final String author;
  final String summary;
}

class GitService {
  String? branch;
  final entries = <GitStatusEntry>[];
  String? lastError;

  Future<void> refresh(String? root) async {
    entries.clear();
    branch = null;
    lastError = null;
    if (root == null) return;
    try {
      final b = await Process.run(
        'git',
        ['rev-parse', '--abbrev-ref', 'HEAD'],
        workingDirectory: root,
      );
      if (b.exitCode == 0) {
        branch = (b.stdout as String).trim();
      }
      final s = await Process.run(
        'git',
        ['status', '--porcelain'],
        workingDirectory: root,
      );
      if (s.exitCode != 0) {
        lastError = (s.stderr as String).trim();
        return;
      }
      for (final line in (s.stdout as String).split('\n')) {
        if (line.length < 4) continue;
        final code = line.substring(0, 2);
        var path = line.substring(3).trim();
        if (path.contains(' -> ')) {
          path = path.split(' -> ').last.trim();
        }
        entries.add(GitStatusEntry(path: p.normalize(p.join(root, path)), code: code));
      }
    } catch (e) {
      lastError = '$e';
    }
  }

  Future<String> diff(String root, {bool staged = false, String? file}) async {
    final args = <String>['diff'];
    if (staged) args.add('--cached');
    if (file != null) {
      args.add('--');
      args.add(file);
    }
    final r = await Process.run('git', args, workingDirectory: root);
    return '${r.stdout}${r.stderr}';
  }

  /// Changed line numbers (1-based) from unified diff -U0 for [file].
  Future<Set<int>> changedLines(String root, String file) async {
    final r = await Process.run(
      'git',
      ['diff', '-U0', '--', file],
      workingDirectory: root,
    );
    final out = <int>{};
    final re = RegExp(r'^@@ -\d+(?:,\d+)? \+(\d+)(?:,(\d+))? @@', multiLine: true);
    for (final m in re.allMatches(r.stdout as String)) {
      final start = int.tryParse(m.group(1) ?? '') ?? 0;
      final count = int.tryParse(m.group(2) ?? '1') ?? 1;
      if (start <= 0) continue;
      for (var i = 0; i < (count < 1 ? 1 : count); i++) {
        out.add(start + i);
      }
    }
    return out;
  }

  Future<List<GitBlameLine>> blame(String root, String file) async {
    final r = await Process.run(
      'git',
      ['blame', '--line-porcelain', '--', file],
      workingDirectory: root,
    );
    if (r.exitCode != 0) return [];
    final lines = <GitBlameLine>[];
    String? hash;
    String author = '';
    String summary = '';
    for (final line in (r.stdout as String).split('\n')) {
      if (line.isEmpty) continue;
      if (RegExp(r'^[0-9a-f]{7,} ').hasMatch(line)) {
        final parts = line.split(' ');
        hash = parts.first;
        final lineNo = int.tryParse(parts.length > 2 ? parts[2] : '') ?? (lines.length + 1);
        // defer until content line
        lines.add(GitBlameLine(
          line: lineNo,
          hash: hash ?? '',
          author: author,
          summary: summary,
        ));
        // Will patch author/summary on following headers — keep last incomplete
        continue;
      }
      if (line.startsWith('author ')) {
        author = line.substring(7);
        if (lines.isNotEmpty) {
          final last = lines.removeLast();
          lines.add(GitBlameLine(
            line: last.line,
            hash: last.hash,
            author: author,
            summary: last.summary,
          ));
        }
      } else if (line.startsWith('summary ')) {
        summary = line.substring(8);
        if (lines.isNotEmpty) {
          final last = lines.removeLast();
          lines.add(GitBlameLine(
            line: last.line,
            hash: last.hash,
            author: last.author,
            summary: summary,
          ));
        }
      }
    }
    return lines;
  }

  Future<int> stage(String root, String file) async {
    final r = await Process.run('git', ['add', '--', file], workingDirectory: root);
    return r.exitCode;
  }

  Future<int> unstage(String root, String file) async {
    final r = await Process.run(
      'git',
      ['restore', '--staged', '--', file],
      workingDirectory: root,
    );
    return r.exitCode;
  }

  Future<int> commit(String root, String message) async {
    final add = await Process.run('git', ['add', '-A'], workingDirectory: root);
    if (add.exitCode != 0) return add.exitCode;
    final c = await Process.run(
      'git',
      ['commit', '-m', message],
      workingDirectory: root,
    );
    return c.exitCode;
  }
}
