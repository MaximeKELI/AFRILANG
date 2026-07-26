import 'dart:convert';
import 'dart:io';

import '../models/problem_item.dart';
import 'process_env.dart';

class CliResult {
  CliResult({
    required this.exitCode,
    required this.stdout,
    required this.stderr,
    required this.problems,
    required this.commandLine,
  });

  final int exitCode;
  final String stdout;
  final String stderr;
  final List<ProblemItem> problems;
  final String commandLine;

  String get combinedOutput {
    final buf = StringBuffer();
    buf.writeln('\$ $commandLine');
    if (stdout.isNotEmpty) buf.writeln(stdout.trimRight());
    if (stderr.isNotEmpty) buf.writeln(stderr.trimRight());
    buf.writeln('[exit $exitCode]');
    return buf.toString();
  }
}

class AfrilangCli {
  AfrilangCli({required this.resolveBinary});

  final Future<String?> Function() resolveBinary;

  Future<CliResult> runFile(String filePath, {String? workingDirectory}) {
    return _exec(['run', filePath], filePath, workingDirectory: workingDirectory);
  }

  Future<CliResult> checkFile(String filePath, {String? workingDirectory}) {
    return _exec(['check', filePath], filePath, workingDirectory: workingDirectory);
  }

  Future<CliResult> _exec(
    List<String> args,
    String filePath, {
    String? workingDirectory,
  }) async {
    final bin = await resolveBinary();
    if (bin == null) {
      return CliResult(
        exitCode: 127,
        stdout: '',
        stderr:
            'afrilang binary not found. Set AFRIBLOCK_AFRILANG or Preferences → afrilang path.\n',
        problems: [
          ProblemItem(
            message: 'afrilang binary not found',
            path: filePath,
            severity: ProblemSeverity.error,
          ),
        ],
        commandLine: 'afrilang ${args.join(' ')}',
      );
    }

    final proc = await Process.run(
      bin,
      args,
      workingDirectory: workingDirectory,
      environment: ProcessEnv.forHostToolchain(),
      stdoutEncoding: utf8,
      stderrEncoding: utf8,
    );
    final out = proc.stdout as String;
    final err = proc.stderr as String;
    final problems = parseDiagnostics('$out\n$err', fallbackPath: filePath);
    return CliResult(
      exitCode: proc.exitCode,
      stdout: out,
      stderr: err,
      problems: problems,
      commandLine: '$bin ${args.join(' ')}',
    );
  }

  /// Best-effort parse of compiler/LSP-ish diagnostic lines.
  static List<ProblemItem> parseDiagnostics(
    String text, {
    required String fallbackPath,
  }) {
    final items = <ProblemItem>[];
    final re = RegExp(
      r'(?:^|\n)(?<path>[^\n:]+):(?<line>\d+)(?::(?<col>\d+))?:\s*(?<sev>error|warning|info|note)?\s*:?\s*(?<msg>.+)',
      multiLine: true,
      caseSensitive: false,
    );
    for (final m in re.allMatches(text)) {
      final path = (m.namedGroup('path') ?? fallbackPath).trim();
      final line = int.tryParse(m.namedGroup('line') ?? '');
      final col = int.tryParse(m.namedGroup('col') ?? '');
      final sevRaw = (m.namedGroup('sev') ?? 'error').toLowerCase();
      final sev = switch (sevRaw) {
        'warning' || 'note' => ProblemSeverity.warning,
        'info' => ProblemSeverity.info,
        _ => ProblemSeverity.error,
      };
      items.add(ProblemItem(
        message: (m.namedGroup('msg') ?? '').trim(),
        path: path,
        line: line,
        column: col,
        severity: sev,
      ));
    }

    // Fallback: if check failed with no structured lines, keep stderr snippet.
    if (items.isEmpty && text.trim().isNotEmpty) {
      final lower = text.toLowerCase();
      if (lower.contains('error') || lower.contains('failed')) {
        final first = text
            .split('\n')
            .map((l) => l.trim())
            .firstWhere((l) => l.isNotEmpty, orElse: () => text.trim());
        items.add(ProblemItem(
          message: first.length > 200 ? '${first.substring(0, 200)}…' : first,
          path: fallbackPath,
          severity: ProblemSeverity.error,
        ));
      }
    }
    return items;
  }
}
