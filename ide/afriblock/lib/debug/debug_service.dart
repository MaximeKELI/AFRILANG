import 'dart:async';
import 'dart:convert';
import 'dart:io';

import '../services/process_env.dart';

class DebugBreakpoint {
  DebugBreakpoint({required this.path, required this.line, this.enabled = true});
  final String path;
  int line;
  bool enabled;
}

/// Debug session facade — launches `afrilang debug` / GDB-oriented flow (Phase D).
/// Full DAP MI parsing can deepen later; UI + process orchestration ship here.
class DebugService {
  Process? _proc;
  final breakpoints = <DebugBreakpoint>[];
  final StringBuffer console = StringBuffer();
  bool running = false;
  String? status;

  void toggleBreakpoint(String path, int line) {
    final i = breakpoints.indexWhere((b) => b.path == path && b.line == line);
    if (i >= 0) {
      breakpoints.removeAt(i);
    } else {
      breakpoints.add(DebugBreakpoint(path: path, line: line));
    }
  }

  bool hasBreakpoint(String path, int line) =>
      breakpoints.any((b) => b.path == path && b.line == line && b.enabled);

  Future<int> launch({
    required String binary,
    required String programOrSource,
    String? workingDirectory,
    required void Function(String) onOutput,
  }) async {
    await stop();
    running = true;
    status = 'Launching…';
    console.clear();
    final args = ['debug', programOrSource];
    onOutput('\$ $binary ${args.join(' ')}\n');
    try {
      _proc = await Process.start(
        binary,
        args,
        workingDirectory: workingDirectory,
        environment: ProcessEnv.forHostToolchain(),
      );
      void pipe(Stream<List<int>> s) {
        s.listen((d) {
          final t = utf8.decode(d, allowMalformed: true);
          console.write(t);
          onOutput(t);
        });
      }

      pipe(_proc!.stdout);
      pipe(_proc!.stderr);
      final code = await _proc!.exitCode;
      running = false;
      status = 'Exited $code';
      _proc = null;
      onOutput('\n[debug exit $code]\n');
      return code;
    } catch (e) {
      running = false;
      status = 'Failed: $e';
      onOutput('Debug failed: $e\n');
      return 1;
    }
  }

  Future<void> stop() async {
    _proc?.kill();
    _proc = null;
    running = false;
    status = 'Stopped';
  }
}
