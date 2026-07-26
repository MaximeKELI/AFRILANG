import 'dart:io';

import 'package:path/path.dart' as p;

class TestItem {
  TestItem({
    required this.path,
    required this.name,
    required this.line,
    this.status = TestStatus.unknown,
  });

  final String path;
  final String name;
  final int line;
  TestStatus status;
}

enum TestStatus { unknown, passed, failed, running }

class TestExplorerService {
  final items = <TestItem>[];

  Future<void> discover(String? root) async {
    items.clear();
    if (root == null) return;
    final dir = Directory(root);
    await for (final ent in dir.list(recursive: true, followLinks: false)) {
      if (ent is! File || !ent.path.endsWith('.afr')) continue;
      if (ent.path.contains('${p.separator}build${p.separator}')) continue;
      String text;
      try {
        text = await ent.readAsString();
      } catch (_) {
        continue;
      }
      final lines = text.split('\n');
      for (var i = 0; i < lines.length; i++) {
        final line = lines[i];
        // AFRILANG test blocks / assert-ish markers
        final m = RegExp(
          r'^\s*test\s+([A-Za-z_][A-Za-z0-9_]*)?',
          caseSensitive: false,
        ).firstMatch(line);
        if (m != null) {
          items.add(TestItem(
            path: ent.path,
            name: m.group(1) ?? 'test@${i + 1}',
            line: i + 1,
          ));
        }
      }
    }
  }
}
