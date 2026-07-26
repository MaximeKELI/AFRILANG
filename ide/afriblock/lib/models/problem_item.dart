enum ProblemSeverity { error, warning, info }

class ProblemItem {
  const ProblemItem({
    required this.message,
    required this.path,
    this.line,
    this.column,
    this.severity = ProblemSeverity.error,
  });

  final String message;
  final String path;
  final int? line;
  final int? column;
  final ProblemSeverity severity;
}
