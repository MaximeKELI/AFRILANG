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
      expect(LocalAfrSuggest.suggest('whi', 3), 'le');
    });

    test('snippet wins over bare keyword when prefix matches', () {
      final s = LocalAfrSuggest.suggest('sa', 2);
      expect(s, isNotNull);
      expect(s!.startsWith('y'), isTrue);
    });

    test('expands snippet after full prefix', () {
      final s = LocalAfrSuggest.suggest('say', 3);
      expect(s, isNotNull);
      expect(s!, isNot(isEmpty));
    });

    test('offers starter after newline', () {
      expect(
        LocalAfrSuggest.suggest('\n', 1),
        'say "Hello AFRILANG"\n',
      );
    });

    test('create context completes as text', () {
      const src = 'create score';
      expect(
        LocalAfrSuggest.suggest(src, src.length),
        ' as text = ""',
      );
    });

    test('set uses harvested identifier', () {
      const src = 'create score as number = 0\nset';
      final s = LocalAfrSuggest.suggest(src, src.length);
      expect(s, ' score = ');
    });

    test('say after space suggests string', () {
      const src = 'say';
      // word "say" → snippet; use "say " for context
      const withSpace = 'say ';
      expect(
        LocalAfrSuggest.suggest(withSpace, withSpace.length),
        ' ""',
      );
    });

    test('harvestIdentifiers finds create/set names', () {
      final ids = LocalAfrSuggest.harvestIdentifiers(
        'create a as text = ""\nset b = 1\nfunction main()\nend\n',
      );
      expect(ids, containsAll(['a', 'b', 'main']));
    });

    test('explainFile summarizes symbols', () {
      final out = LocalAfrSuggest.explainFile(
        'function hello()\n    say "x"\nend\n',
      );
      expect(out, contains('hello'));
      expect(out, contains('Analyse locale'));
    });

    test('chatReply offline explain', () {
      final reply = LocalAfrSuggest.chatReply(
        'explique ce fichier',
        fileContext: 'create x as number = 1\nsay x\n',
      );
      expect(reply, contains('Analyse locale'));
      expect(reply, contains('x'));
    });
  });

  group('AiAssistConfig', () {
    test('afrilang-local disables remote', () {
      const c = AiAssistConfig(enabled: true, model: 'afrilang-local');
      expect(c.hasRemote, isFalse);
    });

    test('llama model enables remote', () {
      const c = AiAssistConfig(enabled: true, model: 'llama3.2');
      expect(c.hasRemote, isTrue);
    });
  });

  group('AiAssistService local chat', () {
    test('chat works without remote', () async {
      final svc = AiAssistService()
        ..updateConfig(const AiAssistConfig(
          enabled: true,
          model: LocalAfrSuggest.modelId,
        ));
      final reply = await svc.chat('fonction');
      expect(reply, contains('```afrilang'));
      expect(svc.chatLog.where((m) => m.role == 'assistant'), isNotEmpty);
    });
  });

  group('AiAssistService.extractCodeBlock', () {
    test('extracts afrilang fence', () {
      const reply = 'Here:\n```afrilang\nsay "ok"\n```\nDone.';
      expect(AiAssistService.extractCodeBlock(reply), 'say "ok"');
    });
  });
}
