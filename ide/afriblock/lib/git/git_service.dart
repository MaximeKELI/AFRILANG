import 'dart:io';

import 'package:path/path.dart' as p;

class GitStatusEntry {
  GitStatusEntry({required this.path, required this.code});
  final String path;
  final String code; // XY from git status --porcelain
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
        final path = line.substring(3).trim();
        entries.add(GitStatusEntry(path: p.normalize(p.join(root, path)), code: code));
      }
    } catch (e) {
      lastError = '$e';
    }
  }

  Future<String> diff(String root, {bool staged = false}) async {
    final args = staged ? ['diff', '--cached'] : ['diff'];
    final r = await Process.run('git', args, workingDirectory: root);
    return '${r.stdout}${r.stderr}';
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
