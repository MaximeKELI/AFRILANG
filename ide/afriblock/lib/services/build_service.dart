import 'dart:async';
import 'dart:convert';
import 'dart:io';

import '../models/problem_item.dart';
import 'afrilang_cli.dart';
import 'process_env.dart';

class StreamedCliResult {
  StreamedCliResult({
    required this.exitCode,
    required this.combined,
    required this.problems,
    required this.commandLine,
  });

  final int exitCode;
  final String combined;
  final List<ProblemItem> problems;
  final String commandLine;
}

/// Runs `afrilang` with streamed stdout/stderr (Phase A build UX).
class BuildService {
  BuildService({required this.resolveBinary});

  final Future<String?> Function() resolveBinary;
  Process? _active;

  bool get isRunning => _active != null;

  Future<void> cancel() async {
    _active?.kill(ProcessSignal.sigterm);
    _active = null;
  }

  Future<StreamedCliResult> runStreaming({
    required List<String> args,
    String? workingDirectory,
    required void Function(String chunk) onChunk,
  }) async {
    final bin = await resolveBinary();
    final cmdLine = '${bin ?? 'afrilang'} ${args.join(' ')}';
    if (bin == null) {
      const msg =
          'afrilang binary not found. Set AFRIBLOCK_AFRILANG or Preferences.\n';
      onChunk(msg);
      return StreamedCliResult(
        exitCode: 127,
        combined: msg,
        problems: [
          const ProblemItem(
            message: 'afrilang binary not found',
            path: '',
            severity: ProblemSeverity.error,
          ),
        ],
        commandLine: cmdLine,
      );
    }

    onChunk('\$ $cmdLine\n');
    final sw = Stopwatch()..start();
    final proc = await Process.start(
      bin,
      args,
      workingDirectory: workingDirectory,
      environment: ProcessEnv.forHostToolchain(),
      runInShell: false,
    );
    _active = proc;

    final buf = StringBuffer();
    void handle(List<int> data) {
      final s = utf8.decode(data, allowMalformed: true);
      buf.write(s);
      onChunk(s);
    }

    final subOut = proc.stdout.listen(handle);
    final subErr = proc.stderr.listen(handle);
    final code = await proc.exitCode;
    await subOut.cancel();
    await subErr.cancel();
    _active = null;
    sw.stop();
    onChunk('\n[exit $code — ${sw.elapsedMilliseconds} ms]\n');

    final combined = buf.toString();
    final fallback = args.length > 1 ? args.last : (workingDirectory ?? '');
    final problems =
        AfrilangCli.parseDiagnostics(combined, fallbackPath: fallback);
    return StreamedCliResult(
      exitCode: code,
      combined: combined,
      problems: problems,
      commandLine: cmdLine,
    );
  }
}
