import 'package:afriblock/ai/ai_assist_service.dart';
import 'package:afriblock/ai/ai_completion_parse.dart';
import 'package:afriblock/ai/local_afr_suggest.dart';
import 'package:flutter_test/flutter_test.dart';

void main() {
  group('stripCompletionFences', () {
    test('strips fenced block', () {
      expect(
        stripCompletionFences('```afrilang\nsay "hi"\n```'),
        'say "hi"',
      );
    });

    test('passes through plain text', () {
      expect(stripCompletionFences('  say ""\n'), 'say ""');
    });
  });

  group('continuationOnly', () {
    test('drops echoed prefix', () {
      expect(
        continuationOnly('create x = ', 'create x = 1'),
        '1',
      );
    });

    test('drops echoed last line', () {
      expect(
        continuationOnly('say "a"\nset y = ', 'set y = 2'),
        '2',
      );
    });

    test('keeps pure continuation', () {
      expect(continuationOnly('say ', '"hello"'), '"hello"');
    });
  });

  group('shouldTriggerInlineSuggest', () {
    test('true at end of word', () {
      expect(shouldTriggerInlineSuggest('say', 3), isTrue);
    });

    test('false mid-word when more letters follow', () {
      expect(shouldTriggerInlineSuggest('say hello', 2), isFalse);
    });

    test('true before newline', () {
      expect(shouldTriggerInlineSuggest('say\n', 3), isTrue);
    });
  });

  group('LocalAfrSuggest', () {
    test('completes keyword prefix', () {
      expect(LocalAfrSuggest.suggest('sa', 2), 'y');
    });

    test('expands snippet after full prefix', () {
      final s = LocalAfrSuggest.suggest('say', 3);
      expect(s, isNotNull);
      expect(s!, isNot(isEmpty));
    });

    test('offers starter after newline', () {
      expect(LocalAfrSuggest.suggest('\n', 1), 'say ""\n');
    });
  });

  group('AiAssistService.extractCodeBlock', () {
    test('extracts afrilang fence', () {
      const reply = 'Here:\n```afrilang\nsay "ok"\n```\nDone.';
      expect(AiAssistService.extractCodeBlock(reply), 'say "ok"');
    });
  });
}
