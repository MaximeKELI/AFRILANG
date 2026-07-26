import 'package:flutter_test/flutter_test.dart';
import 'package:afriblock/editor/snippets.dart';

void main() {
  test('expandSnippet replaces placeholders', () {
    final out = expandSnippet('function \${1:name}()\n    \${0}\nend\n');
    expect(out, contains('function name()'));
    expect(out, isNot(contains('\${')));
  });

  test('filterSnippets by prefix', () {
    final hits = filterSnippets('si');
    expect(hits.any((s) => s.id == 'si'), isTrue);
  });

  test('filterSnippets empty returns all', () {
    expect(filterSnippets(''), kAfrilangSnippets);
  });

  test('builtin snippets include function and match', () {
    expect(kAfrilangSnippets.map((s) => s.id), containsAll(['fn', 'match', 'say']));
  });
}
