import 'package:flutter_test/flutter_test.dart';
import 'package:afriblock/editor/text_ops.dart';
import 'package:afriblock/lsp/lsp_client.dart';
import 'package:afriblock/services/output_buffer.dart';

void main() {
  group('OutputBuffer', () {
    test('truncates oldest content when over maxChars', () {
      final buf = OutputBuffer(maxChars: 80);
      buf.write('A' * 40);
      buf.write('B' * 60);
      final s = buf.toString();
      expect(s.startsWith('…[output truncated]\n'), isTrue);
      expect(s.length, lessThanOrEqualTo(80));
      expect(s.contains('B'), isTrue);
    });

    test('clear empties buffer', () {
      final buf = OutputBuffer();
      buf.writeln('hello');
      buf.clear();
      expect(buf.toString(), isEmpty);
    });
  });

  group('TextOps navigation', () {
    test('offsetAtLine and lineColAt round-trip', () {
      const text = 'one\ntwo\nthree';
      expect(TextOps.offsetAtLine(text, 1), 0);
      expect(TextOps.offsetAtLine(text, 2), 4);
      expect(TextOps.offsetAtLine(text, 3, column: 2), 9);
      final pos = TextOps.lineColAt(text, 9);
      expect(pos.line, 2);
      expect(pos.character, 1);
    });

    test('wordAt extracts identifier', () {
      const text = 'say hello(world)';
      expect(TextOps.wordAt(text, 6), 'hello');
      expect(TextOps.wordAt(text, 12), 'world');
    });
  });

  group('LspClient parsers', () {
    test('parseHoverContents', () {
      expect(LspClient.parseHoverContents(null), isNull);
      expect(
        LspClient.parseHoverContents({
          'contents': {'kind': 'markdown', 'value': '**foo**'},
        }),
        '**foo**',
      );
      expect(LspClient.parseHoverContents({'contents': 'plain'}), 'plain');
    });

    test('parseDefinitionResult', () {
      final loc = LspClient.parseDefinitionResult({
        'uri': 'file:///tmp/a.afr',
        'range': {
          'start': {'line': 4, 'character': 2},
          'end': {'line': 4, 'character': 6},
        },
      });
      expect(loc?.uri, 'file:///tmp/a.afr');
      expect(loc?.line, 5);
      expect(loc?.column, 3);
    });
  });
}
