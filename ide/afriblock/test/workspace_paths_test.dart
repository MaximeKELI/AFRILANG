import 'dart:io';

import 'package:flutter_test/flutter_test.dart';
import 'package:path/path.dart' as p;
import 'package:afriblock/services/workspace_paths.dart';

void main() {
  group('isDocumentPortalPath', () {
    test('detects xdg document portal mounts', () {
      expect(
        isDocumentPortalPath('/run/user/1000/doc/d43be2d9/examples'),
        isTrue,
      );
      expect(isDocumentPortalPath('/run/user/1000/doc/abc'), isTrue);
    });

    test('rejects normal paths', () {
      expect(isDocumentPortalPath('/home/u/AFRILANG/examples'), isFalse);
      expect(isDocumentPortalPath('/tmp/examples'), isFalse);
      expect(isDocumentPortalPath('/run/user/1000/other'), isFalse);
    });
  });

  group('suggestAfrilangExamplesDir', () {
    test('resolves examples next to build/afrilang', () {
      final repo = Directory.current.path.contains('ide/afriblock')
          ? p.normalize(p.join(Directory.current.path, '../..'))
          : Directory.current.path;
      final bin = p.join(repo, 'build', 'afrilang');
      final examples = suggestAfrilangExamplesDir(bin);
      if (Directory(p.join(repo, 'examples')).existsSync()) {
        expect(examples, p.join(repo, 'examples'));
        expect(isDocumentPortalPath(examples!), isFalse);
      }
    });

    test('returns null for unknown binary layout', () {
      expect(suggestAfrilangExamplesDir('/no/such/afrilang'), isNull);
      expect(suggestAfrilangExamplesDir(null), isNull);
    });
  });

  test('resolveWorkspacePath normalizes existing dirs', () async {
    final tmp = await Directory.systemTemp.createTemp('afriblock_ws_');
    addTearDown(() => tmp.delete(recursive: true));
    final resolved = await resolveWorkspacePath(tmp.path);
    expect(resolved, isNotEmpty);
    expect(await Directory(resolved).exists(), isTrue);
  });
}
