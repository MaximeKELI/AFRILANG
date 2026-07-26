import 'dart:io';

import 'package:flutter_test/flutter_test.dart';
import 'package:path/path.dart' as p;
import 'package:afriblock/editor/path_name_rules.dart';
import 'package:afriblock/services/file_service.dart';

void main() {
  group('PathNameRules', () {
    test('rejects empty and separators', () {
      expect(PathNameRules.validateSegment('', isFolder: false), isNotNull);
      expect(PathNameRules.validateSegment('a/b', isFolder: false), isNotNull);
      expect(PathNameRules.validateSegment('..', isFolder: true), isNotNull);
    });

    test('accepts simple names', () {
      expect(PathNameRules.validateSegment('main.afr', isFolder: false), isNull);
      expect(PathNameRules.validateSegment('src', isFolder: true), isNull);
    });

    test('ensureAfrExtension', () {
      expect(PathNameRules.ensureAfrExtension('hello', forceAfr: true), 'hello.afr');
      expect(PathNameRules.ensureAfrExtension('readme.md', forceAfr: true), 'readme.md');
      expect(PathNameRules.ensureAfrExtension('x.afr', forceAfr: true), 'x.afr');
    });
  });

  group('FileService create', () {
    late Directory tmp;

    setUp(() async {
      tmp = await Directory.systemTemp.createTemp('afriblock_create_');
    });

    tearDown(() async {
      if (await tmp.exists()) await tmp.delete(recursive: true);
    });

    test('createFile and createDirectory', () async {
      final fs = FileService();
      final dir = p.join(tmp.path, 'pkg');
      await fs.createDirectory(dir);
      expect(await Directory(dir).exists(), isTrue);

      final file = p.join(dir, 'main.afr');
      await fs.createFile(file, content: 'say 1\n');
      expect(await File(file).readAsString(), 'say 1\n');

      expect(
        () => fs.createFile(file, content: 'x'),
        throwsA(isA<StateError>()),
      );
    });
  });
}
