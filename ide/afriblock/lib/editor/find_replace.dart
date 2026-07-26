/// Pure find / replace helpers for the editor (unit-tested).
class FindMatch {
  const FindMatch({required this.start, required this.end, required this.line});
  final int start;
  final int end;
  final int line;
}

class FindReplaceEngine {
  static List<FindMatch> findAll(
    String text,
    String query, {
    bool caseSensitive = false,
    bool wholeWord = false,
  }) {
    if (query.isEmpty) return const [];
    final src = caseSensitive ? text : text.toLowerCase();
    final q = caseSensitive ? query : query.toLowerCase();
    final matches = <FindMatch>[];
    var from = 0;
    while (true) {
      final idx = src.indexOf(q, from);
      if (idx < 0) break;
      if (wholeWord && !_isWholeWord(text, idx, q.length)) {
        from = idx + 1;
        continue;
      }
      matches.add(FindMatch(
        start: idx,
        end: idx + query.length,
        line: _lineOf(text, idx),
      ));
      from = idx + q.length;
    }
    return matches;
  }

  static String replaceAll(
    String text,
    String query,
    String replacement, {
    bool caseSensitive = false,
    bool wholeWord = false,
  }) {
    final matches = findAll(
      text,
      query,
      caseSensitive: caseSensitive,
      wholeWord: wholeWord,
    );
    if (matches.isEmpty) return text;
    final buf = StringBuffer();
    var cursor = 0;
    for (final m in matches) {
      buf.write(text.substring(cursor, m.start));
      buf.write(replacement);
      cursor = m.end;
    }
    buf.write(text.substring(cursor));
    return buf.toString();
  }

  static String replaceFirst(
    String text,
    String query,
    String replacement, {
    bool caseSensitive = false,
    int from = 0,
  }) {
    final matches = findAll(text, query, caseSensitive: caseSensitive)
        .where((m) => m.start >= from)
        .toList();
    if (matches.isEmpty) return text;
    final m = matches.first;
    return text.substring(0, m.start) + replacement + text.substring(m.end);
  }

  static int offsetForLine(String text, int line1Based) {
    if (line1Based <= 1) return 0;
    var line = 1;
    for (var i = 0; i < text.length; i++) {
      if (text[i] == '\n') {
        line++;
        if (line == line1Based) return i + 1;
      }
    }
    return text.length;
  }

  static int _lineOf(String text, int offset) {
    var line = 1;
    final end = offset.clamp(0, text.length);
    for (var i = 0; i < end; i++) {
      if (text[i] == '\n') line++;
    }
    return line;
  }

  static bool _isWholeWord(String text, int start, int len) {
    bool wordChar(int i) {
      if (i < 0 || i >= text.length) return false;
      final c = text.codeUnitAt(i);
      return (c >= 65 && c <= 90) ||
          (c >= 97 && c <= 122) ||
          (c >= 48 && c <= 57) ||
          c == 95;
    }

    return !wordChar(start - 1) && !wordChar(start + len);
  }
}
