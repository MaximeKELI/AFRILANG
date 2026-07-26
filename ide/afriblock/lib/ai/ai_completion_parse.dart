/// Pure helpers for AI completion text (unit-tested).
library;

/// Strips markdown fences and leading/trailing whitespace from model output.
String stripCompletionFences(String raw) {
  var t = raw.trim();
  final fenced = RegExp(
    r'^```(?:\w+)?\s*\n([\s\S]*?)\n```\s*$',
    multiLine: true,
  );
  final m = fenced.firstMatch(t);
  if (m != null) {
    t = (m.group(1) ?? '').trimRight();
  } else if (t.startsWith('```')) {
    final lines = t.split('\n');
    if (lines.isNotEmpty && lines.first.startsWith('```')) {
      lines.removeAt(0);
    }
    if (lines.isNotEmpty && lines.last.trim() == '```') {
      lines.removeLast();
    }
    t = lines.join('\n');
  }
  return t;
}

/// Keeps only the suffix that continues [prefix] (drops accidental echo).
String continuationOnly(String prefix, String completion) {
  final c = stripCompletionFences(completion);
  if (c.isEmpty) return '';
  if (prefix.isNotEmpty && c.startsWith(prefix)) {
    return c.substring(prefix.length);
  }
  // If model repeated the last line, strip it.
  final lastNl = prefix.lastIndexOf('\n');
  final lineStart = lastNl < 0 ? 0 : lastNl + 1;
  final linePrefix = prefix.substring(lineStart);
  if (linePrefix.isNotEmpty && c.startsWith(linePrefix)) {
    return c.substring(linePrefix.length);
  }
  return c;
}

/// True when caret is at end of a line or after a word (good suggest moment).
bool shouldTriggerInlineSuggest(String content, int caret) {
  if (caret < 0 || caret > content.length) return false;
  if (caret < content.length) {
    final ch = content[caret];
    if (ch != '\n' && ch != ' ' && ch != '\t') return false;
  }
  if (caret == 0) return false;
  final prev = content[caret - 1];
  return prev.trim().isNotEmpty || prev == '\n';
}
