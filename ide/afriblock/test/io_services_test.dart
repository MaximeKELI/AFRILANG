import 'dart:io';

import 'package:flutter_test/flutter_test.dart';
import 'package:path/path.dart' as p;
import 'package:afriblock/search/search_service.dart';
import 'package:afriblock/project/test_explorer.dart';
import 'package:afriblock/services/file_service.dart';

void main() {
  late Directory tmp;

  setUp(() async {
    tmp = await Directory.systemTemp.createTemp('afriblock_test_');
  });

  tearDown(() async {
    if (await tmp.exists()) await tmp.delete(recursive: true);
  });

  test('SearchService Dart walk finds matches', () async {
    final f = File(p.join(tmp.path, 'hello.afr'));
    await f.writeAsString('say "needle"\nsay "other"\n');
    final hits = await SearchService().findInFiles(
      root: tmp.path,
      query: 'needle',
    );
    expect(hits, isNotEmpty);
    expect(hits.first.line, 1);
    expect(hits.first.preview, contains('needle'));
  });

  test('TestExplorer discovers test blocks', () async {
    final f = File(p.join(tmp.path, 'suite.afr'));
    await f.writeAsString('test alpha\n  assert true\nend\ntest\nend\n');
    final explorer = TestExplorerService();
    await explorer.discover(tmp.path);
    expect(explorer.items.length, greaterThanOrEqualTo(1));
    expect(explorer.items.first.name, 'alpha');
  });

  test('FileService loadTree ignores build', () async {
    await Directory(p.join(tmp.path, 'build')).create();
    await File(p.join(tmp.path, 'build', 'x.o')).writeAsString('o');
    await File(p.join(tmp.path, 'main.afr')).writeAsString('say 1');
    final tree = await FileService().loadTree(tmp.path);
    expect(tree.children.any((c) => c.name == 'build'), isFalse);
    expect(tree.children.any((c) => c.name == 'main.afr'), isTrue);
  });
}
