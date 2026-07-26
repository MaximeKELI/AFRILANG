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
