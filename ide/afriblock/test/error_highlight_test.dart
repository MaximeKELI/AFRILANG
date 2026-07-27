import 'package:flutter_test/flutter_test.dart';
import 'package:afriblock/models/problem_item.dart';
import 'package:path/path.dart' as p;

/// Mirrors WorkbenchController path matching for diagnostics ↔ editor.
bool problemPathMatches(String problemPath, String editorPath) {
  if (problemPath.isEmpty) return false;
  if (p.equals(problemPath, editorPath)) return true;
  if (editorPath.endsWith(problemPath) ||
      problemPath.endsWith(p.basename(editorPath))) {
    return p.basename(problemPath) == p.basename(editorPath);
  }
  return p.basename(problemPath) == p.basename(editorPath);
}

Set<int> errorLinesFrom(
  List<ProblemItem> problems,
  String editorPath,
) {
  final out = <int>{};
  for (final item in problems) {
    if (item.line == null || item.severity != ProblemSeverity.error) continue;
    if (!problemPathMatches(item.path, editorPath)) continue;
    out.add(item.line!);
  }
  return out;
}

void main() {
  test('problemPathMatches absolute and basename', () {
    expect(
      problemPathMatches('/home/u/proj/src/main.afr', '/home/u/proj/src/main.afr'),
      isTrue,
    );
    expect(
      problemPathMatches('src/main.afr', '/home/u/proj/src/main.afr'),
      isTrue,
    );
    expect(
      problemPathMatches('other.afr', '/home/u/proj/src/main.afr'),
      isFalse,
    );
  });

  test('errorLinesFrom collects error lines only', () {
    final lines = errorLinesFrom(
      const [
        ProblemItem(
          message: 'boom',
          path: 'main.afr',
          line: 3,
          severity: ProblemSeverity.error,
        ),
        ProblemItem(
          message: 'warn',
          path: 'main.afr',
          line: 5,
          severity: ProblemSeverity.warning,
        ),
      ],
      '/tmp/main.afr',
    );
    expect(lines, {3});
  });
}
