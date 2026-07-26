import 'package:flutter_test/flutter_test.dart';
import 'package:afriblock/editor/text_ops.dart';

void main() {
  group('TextOps', () {
    test('duplicateLine', () {
      const text = 'a\nb\nc';
      final out = TextOps.duplicateLine(text, 2); // on line b
      expect(out.split('\n'), ['a', 'b', 'b', 'c']);
    });

    test('deleteLine', () {
      const text = 'a\nb\nc';
      final out = TextOps.deleteLine(text, 2);
      expect(out, 'a\nc');
    });

    test('toggleLineComment add/remove', () {
      const text = 'say "hi"';
      final commented = TextOps.toggleLineComment(text, 0);
      expect(commented.startsWith('// '), isTrue);
      final uncommented = TextOps.toggleLineComment(commented, 0);
      expect(uncommented, 'say "hi"');
    });

    test('insertAt', () {
      expect(TextOps.insertAt('abc', 1, 'X'), 'aXbc');
    });

    test('breadcrumbs', () {
      expect(
        TextOps.breadcrumbs('/home/u/proj/src/main.afr'),
        ['home', 'u', 'proj', 'src', 'main.afr'],
      );
    });
  });
}
