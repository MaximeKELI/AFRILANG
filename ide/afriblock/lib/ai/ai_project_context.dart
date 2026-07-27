import '../models/problem_item.dart';
import '../models/editor_tab.dart';
import '../project/project_service.dart';

/// Builds compact context for AI chat / fix prompts.
class AiProjectContext {
  /// Soft size caps so prompts stay usable for local models.
  static const maxFileChars = 4000;
  static const maxOpenFiles = 6;
  static const maxProblems = 12;

  static String build({
    AfrilangProject? project,
    String? tomlSnippet,
    List<EditorTab> openTabs = const [],
    String? activePath,
    List<ProblemItem> problems = const [],
    ProblemItem? focusProblem,
  }) {
    final buf = StringBuffer();

    if (project != null) {
      buf.writeln('## Project (afrilang.toml)');
      buf.writeln('name: ${project.name}');
      if (project.version != null) buf.writeln('version: ${project.version}');
      if (project.main != null) buf.writeln('main: ${project.main}');
      if (project.output != null) buf.writeln('output: ${project.output}');
      if (project.description != null && project.description!.isNotEmpty) {
        buf.writeln('description: ${project.description}');
      }
      buf.writeln();
    }

    if (tomlSnippet != null && tomlSnippet.trim().isNotEmpty) {
      buf.writeln('## afrilang.toml');
      buf.writeln(_truncate(tomlSnippet.trim(), 1200));
      buf.writeln();
    }

    if (focusProblem != null) {
      buf.writeln('## Focus diagnostic');
      buf.writeln(_formatProblem(focusProblem));
      buf.writeln();
    } else if (problems.isNotEmpty) {
      buf.writeln('## Diagnostics (${problems.length})');
      for (final p in problems.take(maxProblems)) {
        buf.writeln('- ${_formatProblem(p)}');
      }
      buf.writeln();
    }

    final tabs = openTabs.take(maxOpenFiles).toList();
    if (tabs.isNotEmpty) {
      buf.writeln('## Open editors');
      for (final t in tabs) {
        final mark = t.path == activePath ? ' (active)' : '';
        buf.writeln('### ${t.path}$mark');
        buf.writeln(_truncate(t.content, maxFileChars));
        buf.writeln();
      }
    }

    return buf.toString().trim();
  }

  static String _formatProblem(ProblemItem p) {
    final loc = [
      if (p.path.isNotEmpty) p.path,
      if (p.line != null) '${p.line}',
      if (p.column != null) '${p.column}',
    ].join(':');
    return '${p.severity.name}${loc.isEmpty ? '' : ' at $loc'}: ${p.message}';
  }

  static String _truncate(String s, int max) {
    if (s.length <= max) return s;
    return '${s.substring(0, max)}\n…[truncated]';
  }
}
