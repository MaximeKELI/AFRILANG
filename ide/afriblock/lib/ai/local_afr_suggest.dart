import '../editor/snippets.dart';
import 'ai_completion_parse.dart';

/// Offline AFRILANG-aware inline suggestions (snippets + keywords).
class LocalAfrSuggest {
  static const _keywords = <String>[
    'create',
    'set',
    'say',
    'dire',
    'function',
    'fonction',
    'returns',
    'retourne',
    'end',
    'fin',
    'if',
    'si',
    'then',
    'alors',
    'else',
    'sinon',
    'while',
    'for',
    'pour',
    'in',
    'dans',
    'class',
    'classe',
    'import',
    'use',
    'match',
    'case',
    'async',
    'await',
    'return',
    'true',
    'false',
    'null',
  ];

  /// Returns text to insert *after* [caret], or null.
  static String? suggest(String content, int caret) {
    if (!shouldTriggerInlineSuggest(content, caret) &&
        caret == content.length) {
      // Allow mid-word keyword completion at EOF.
    } else if (!shouldTriggerInlineSuggest(content, caret) &&
        caret < content.length) {
      return null;
    }

    final before = content.substring(0, caret.clamp(0, content.length));
    final word = _currentWord(before);
    if (word.isEmpty) {
      // After newline or space — offer a common starter.
      if (before.endsWith('\n') || before.isEmpty) {
        return 'say ""\n';
      }
      return null;
    }

    // Snippet by prefix
    for (final snip in kAfrilangSnippets) {
      if (snip.prefix.isNotEmpty &&
          snip.prefix.startsWith(word) &&
          snip.prefix != word) {
        final body = expandSnippet(snip.body);
        // Replace partial word: return suffix after word.
        return body.substring(word.length.clamp(0, body.length));
      }
      if (snip.prefix == word) {
        final body = expandSnippet(snip.body);
        // Word already typed equals prefix — expand rest of snippet.
        if (body.startsWith(word)) {
          return body.substring(word.length);
        }
        return body;
      }
    }

    // Keyword completion
    final matches = _keywords
        .where((k) => k.startsWith(word.toLowerCase()) && k != word.toLowerCase())
        .toList();
    if (matches.isEmpty) return null;
    matches.sort((a, b) => a.length.compareTo(b.length));
    final best = matches.first;
    return best.substring(word.length);
  }

  static String _currentWord(String before) {
    if (before.isEmpty) return '';
    final m = RegExp(r'[A-Za-z_][A-Za-z0-9_]*$').firstMatch(before);
    return m?.group(0) ?? '';
  }
}
