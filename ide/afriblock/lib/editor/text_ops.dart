/// Pure text operations used by editor commands.
class TextOps {
  static String duplicateLine(String text, int caretOffset) {
    final lineStart = _lineStart(text, caretOffset);
    final lineEnd = _lineEnd(text, caretOffset);
    final line = text.substring(lineStart, lineEnd);
    if (lineEnd < text.length && text[lineEnd] == '\n') {
      return '${text.substring(0, lineEnd + 1)}$line\n${text.substring(lineEnd + 1)}';
    }
    return '${text.substring(0, lineEnd)}\n$line${text.substring(lineEnd)}';
  }

  static String deleteLine(String text, int caretOffset) {
    final lineStart = _lineStart(text, caretOffset);
    var lineEnd = _lineEnd(text, caretOffset);
    if (lineEnd < text.length && text[lineEnd] == '\n') lineEnd++;
    return text.substring(0, lineStart) + text.substring(lineEnd);
  }

  static String toggleLineComment(String text, int caretOffset) {
    final lineStart = _lineStart(text, caretOffset);
    final lineEnd = _lineEnd(text, caretOffset);
    final line = text.substring(lineStart, lineEnd);
    final trimmed = line.trimLeft();
    final indent = line.substring(0, line.length - trimmed.length);
    final String next;
    if (trimmed.startsWith('//')) {
      next = indent + trimmed.replaceFirst(RegExp(r'^//\s?'), '');
    } else {
      next = '$indent// $trimmed';
    }
    return text.substring(0, lineStart) + next + text.substring(lineEnd);
  }

  static String insertAt(String text, int offset, String insertion) {
    final o = offset.clamp(0, text.length);
    return text.substring(0, o) + insertion + text.substring(o);
  }

  static List<String> breadcrumbs(String path) {
    final norm = path.replaceAll('\\', '/');
    return norm.split('/').where((p) => p.isNotEmpty).toList();
  }

  /// 1-based line → UTF-16 offset at start of that line (clamped).
  static int offsetAtLine(String text, int line, {int column = 1}) {
    if (line < 1) line = 1;
    if (column < 1) column = 1;
    var current = 1;
    var i = 0;
    while (i < text.length && current < line) {
      if (text[i] == '\n') current++;
      i++;
    }
    final lineStart = i;
    final lineEnd = _lineEnd(text, lineStart);
    final colOff = (column - 1).clamp(0, lineEnd - lineStart);
    return lineStart + colOff;
  }

  /// 0-based LSP line/character from a caret offset.
  static ({int line, int character}) lineColAt(String text, int offset) {
    final o = offset.clamp(0, text.length);
    var line = 0;
    var last = 0;
    for (var i = 0; i < o; i++) {
      if (text[i] == '\n') {
        line++;
        last = i + 1;
      }
    }
    return (line: line, character: o - last);
  }

  /// Identifier under [offset] (letters, digits, `_`).
  static String wordAt(String text, int offset) {
    if (text.isEmpty) return '';
    final o = offset.clamp(0, text.length);
    var start = o;
    while (start > 0 && _isIdentChar(text[start - 1])) {
      start--;
    }
    var end = o;
    while (end < text.length && _isIdentChar(text[end])) {
      end++;
    }
    if (start == end && start > 0 && _isIdentChar(text[start - 1])) {
      start--;
      while (start > 0 && _isIdentChar(text[start - 1])) {
        start--;
      }
    }
    return text.substring(start, end);
  }

  static bool _isIdentChar(String ch) {
    if (ch.isEmpty) return false;
    final c = ch.codeUnitAt(0);
    return (c >= 65 && c <= 90) ||
        (c >= 97 && c <= 122) ||
        (c >= 48 && c <= 57) ||
        c == 95;
  }

  static int _lineStart(String text, int offset) {
    final o = offset.clamp(0, text.length);
    final i = text.lastIndexOf('\n', o == 0 ? 0 : o - 1);
    return i < 0 ? 0 : i + 1;
  }

  static int _lineEnd(String text, int offset) {
    final o = offset.clamp(0, text.length);
    final i = text.indexOf('\n', o);
    return i < 0 ? text.length : i;
  }
}
