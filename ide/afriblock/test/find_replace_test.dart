import 'package:flutter_test/flutter_test.dart';
import 'package:afriblock/editor/find_replace.dart';

void main() {
  group('FindReplaceEngine', () {
    test('findAll finds multiple occurrences', () {
      const text = 'say hello\nsay world\nsay hello';
      final m = FindReplaceEngine.findAll(text, 'say');
      expect(m.length, 3);
      expect(m.first.line, 1);
      expect(m.last.line, 3);
    });

    test('findAll is case-insensitive by default', () {
      final m = FindReplaceEngine.findAll('Hello HELLO hello', 'hello');
      expect(m.length, 3);
    });

    test('findAll caseSensitive', () {
      final m = FindReplaceEngine.findAll(
        'Hello HELLO hello',
        'hello',
        caseSensitive: true,
      );
      expect(m.length, 1);
    });

    test('wholeWord respects boundaries', () {
      final m = FindReplaceEngine.findAll(
        'cat catalog cat',
        'cat',
        wholeWord: true,
      );
      expect(m.length, 2);
    });

    test('replaceAll', () {
      final out = FindReplaceEngine.replaceAll('a-b-a', 'a', 'x');
      expect(out, 'x-b-x');
    });

    test('replaceFirst from offset', () {
      final out = FindReplaceEngine.replaceFirst('aa aa', 'aa', 'bb', from: 1);
      expect(out, 'aa bb');
    });

    test('offsetForLine', () {
      const text = 'one\ntwo\nthree';
      expect(FindReplaceEngine.offsetForLine(text, 1), 0);
      expect(FindReplaceEngine.offsetForLine(text, 2), 4);
      expect(FindReplaceEngine.offsetForLine(text, 3), 8);
    });

    test('empty query yields no matches', () {
      expect(FindReplaceEngine.findAll('abc', ''), isEmpty);
    });
  });
}
