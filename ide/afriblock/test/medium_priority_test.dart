import 'package:flutter_test/flutter_test.dart';
import 'package:afriblock/debug/debug_service.dart';
import 'package:afriblock/lsp/lsp_client.dart';
import 'package:afriblock/project/project_templates.dart';
import 'package:afriblock/project/workspace_model.dart';

void main() {
  group('WorkspaceModel', () {
    test('json roundtrip', () {
      final m = WorkspaceModel(
        folders: [
          WorkspaceFolder(path: '/a/proj1', name: 'proj1'),
          WorkspaceFolder(path: '/b/proj2'),
        ],
        activeIndex: 1,
      );
      final json = m.toJson();
      final back = WorkspaceModel.fromJson(json);
      expect(back.folders.length, 2);
      expect(back.folders[0].path, '/a/proj1');
      expect(back.folders[0].name, 'proj1');
      expect(back.folders[1].name, 'proj2');
      expect(back.activeIndex, 1);
      expect(back.primaryPath, '/b/proj2');
      expect(back.isMultiRoot, isTrue);
    });

    test('replaceAll and addFolder', () {
      final m = WorkspaceModel();
      m.replaceAll(['/one']);
      expect(m.primaryPath, '/one');
      m.addFolder('/two');
      expect(m.folders.length, 2);
      m.addFolder('/two');
      expect(m.folders.length, 2);
    });
  });

  group('project templates', () {
    test('expandProjectTemplate replaces name', () {
      final t = projectTemplateById('app');
      final src = expandProjectTemplate(t.mainSource, 'demo');
      expect(src.contains('demo'), isTrue);
      expect(src.contains('{{name}}'), isFalse);
    });

    test('test template has tomlExtra', () {
      final t = projectTemplateById('test');
      expect(t.tomlExtra.contains('smoke.afr'), isTrue);
      expect(projectTemplateById('missing').id, 'app');
    });
  });

  group('LspClient.parseWorkspaceEdit', () {
    test('parses changes map', () {
      final edit = LspClient.parseWorkspaceEdit({
        'changes': {
          'file:///tmp/a.afr': [
            {
              'range': {
                'start': {'line': 0, 'character': 0},
                'end': {'line': 0, 'character': 3},
              },
              'newText': 'foo',
            },
          ],
        },
      });
      expect(edit, isNotNull);
      expect(edit!.changes.length, 1);
      final e = edit.changes.values.first.single;
      expect(e.startLine, 1);
      expect(e.startCharacter, 1);
      expect(e.endLine, 1);
      expect(e.endCharacter, 4);
      expect(e.newText, 'foo');
    });

    test('null on empty', () {
      expect(LspClient.parseWorkspaceEdit(null), isNull);
      expect(LspClient.parseWorkspaceEdit({'changes': {}}), isNull);
    });
  });

  group('Git changedLines hunk parser', () {
    test('parses unified -U0 hunks', () {
      const stdout = '''
diff --git a/x.afr b/x.afr
@@ -1,0 +2,3 @@
+a
+b
+c
@@ -10 +20 @@
+x
''';
      final out = <int>{};
      final re = RegExp(r'^@@ -\d+(?:,\d+)? \+(\d+)(?:,(\d+))? @@', multiLine: true);
      for (final m in re.allMatches(stdout)) {
        final start = int.tryParse(m.group(1) ?? '') ?? 0;
        final count = int.tryParse(m.group(2) ?? '1') ?? 1;
        if (start <= 0) continue;
        for (var i = 0; i < (count < 1 ? 1 : count); i++) {
          out.add(start + i);
        }
      }
      expect(out, containsAll([2, 3, 4, 20]));
    });
  });

  group('DebugStackFrame', () {
    test('smoke model', () {
      final f = DebugStackFrame(
        id: 0,
        function: 'main',
        file: '/tmp/main.afr',
        line: 12,
      );
      expect(f.function, 'main');
      expect(f.line, 12);
      final v = DebugVariable(name: 'x', value: '1', type: 'number');
      expect(v.name, 'x');
    });
  });
}
