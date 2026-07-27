import 'package:flutter_test/flutter_test.dart';
import 'package:afriblock/ai/ai_assist_service.dart';
import 'package:afriblock/ai/ai_project_context.dart';
import 'package:afriblock/ai/local_afr_suggest.dart';
import 'package:afriblock/models/editor_tab.dart';
import 'package:afriblock/models/problem_item.dart';
import 'package:afriblock/project/project_service.dart';

void main() {
  group('AiProjectContext', () {
    test('includes project toml fields and open tabs', () {
      final ctx = AiProjectContext.build(
        project: AfrilangProject(
          root: '/tmp/p',
          name: 'demo',
          main: 'src/main.afr',
          version: '0.1.0',
        ),
        tomlSnippet: 'name = "demo"\nmain = "src/main.afr"\n',
        openTabs: [
          EditorTab(path: '/tmp/p/src/main.afr', content: 'say "hi"\n'),
        ],
        activePath: '/tmp/p/src/main.afr',
        problems: const [
          ProblemItem(
            message: 'expected then',
            path: '/tmp/p/src/main.afr',
            line: 2,
            severity: ProblemSeverity.error,
          ),
        ],
      );
      expect(ctx, contains('demo'));
      expect(ctx, contains('afrilang.toml'));
      expect(ctx, contains('say "hi"'));
      expect(ctx, contains('expected then'));
    });
  });

  group('LocalAfrSuggest explain/fix', () {
    test('explainError mentions then/do when expected', () {
      final r = LocalAfrSuggest.explainError('error: expected then after if');
      expect(r.toLowerCase(), contains('then'));
    });

    test('suggestFix adds then after if line', () {
      const src = 'if x greater than 0\n    say x\nend\n';
      final r = LocalAfrSuggest.suggestFix(
        'expected then',
        src,
        line: 1,
      );
      expect(r, isNotNull);
      expect(r!, contains('```afrilang'));
      expect(r, contains('then'));
    });
  });

  group('AiAssistService helpers', () {
    test('looksLikeFullFile', () {
      expect(
        AiAssistService.looksLikeFullFile(
          'function main()\n    say 1\nend\n',
          'say 1\n',
        ),
        isTrue,
      );
      expect(AiAssistService.looksLikeFullFile('x', 'yyyyyyyy'), isFalse);
    });
  });
}
