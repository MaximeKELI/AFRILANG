import 'dart:async';
import 'dart:convert';
import 'dart:io';

import 'package:path/path.dart' as p;

import '../services/process_env.dart';

class DebugBreakpoint {
  DebugBreakpoint({required this.path, required this.line, this.enabled = true});
  final String path;
  int line;
  bool enabled;
}

class DebugStackFrame {
  DebugStackFrame({
    required this.id,
    required this.function,
    required this.file,
    required this.line,
  });
  final int id;
  final String function;
  final String file;
  final int line;
}

class DebugVariable {
  DebugVariable({required this.name, required this.value, this.type});
  final String name;
  final String value;
  final String? type;
}

/// GDB/MI-backed debug session (inspired by vscode-afrilang/debugAdapter.js).
class DebugService {
  Process? _proc;
  final breakpoints = <DebugBreakpoint>[];
  final StringBuffer console = StringBuffer();
  bool running = false;
  bool paused = false;
  bool usingGdb = false;
  String? status;
  String? sourceFile;
  String? executable;
  final frames = <DebugStackFrame>[];
  final variables = <DebugVariable>[];
  int selectedFrameId = 0;

  void Function()? onChanged;
  void Function(String)? onOutput;

  final _gdbBuf = StringBuffer();
  final _pending = <int, Completer<Map<String, dynamic>>>{};
  int _token = 1;
  Map<String, dynamic>? _debugMeta;
  String? _lastMiBlob;

  void _emit() => onChanged?.call();

  void toggleBreakpoint(String path, int line) {
    final i = breakpoints.indexWhere((b) => b.path == path && b.line == line);
    if (i >= 0) {
      breakpoints.removeAt(i);
    } else {
      breakpoints.add(DebugBreakpoint(path: path, line: line));
    }
    _emit();
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
    this.onOutput = onOutput;
    running = true;
    paused = false;
    usingGdb = false;
    status = 'Launching…';
    frames.clear();
    variables.clear();
    console.clear();
    sourceFile = programOrSource;
    _emit();

    final cwd = workingDirectory ?? p.dirname(programOrSource);
    final base = p.basenameWithoutExtension(programOrSource);
    executable = p.join(cwd, base);

    final gdbOk = await _gdbAvailable();
    if (gdbOk && programOrSource.toLowerCase().endsWith('.afr')) {
      try {
        await _compileEmit(binary, programOrSource, cwd, onOutput);
        await _loadDebugMeta('$executable.afr.debug.json');
        await _startGdb(cwd, onOutput);
        return 0;
      } catch (e) {
        onOutput('GDB session failed ($e) — falling back to afrilang debug\n');
        await stop();
        running = true;
      }
    }

    return _launchAfrilangDebug(binary, programOrSource, cwd, onOutput);
  }

  Future<bool> _gdbAvailable() async {
    try {
      final r = await Process.run('gdb', ['--version']);
      return r.exitCode == 0;
    } catch (_) {
      return false;
    }
  }

  Future<void> _compileEmit(
    String binary,
    String source,
    String cwd,
    void Function(String) onOutput,
  ) async {
    onOutput('\$ $binary run $source --emit\n');
    final r = await Process.run(
      binary,
      ['run', source, '--emit'],
      workingDirectory: cwd,
      environment: ProcessEnv.forHostToolchain(),
    );
    final out = '${r.stdout}${r.stderr}';
    if (out.trim().isNotEmpty) onOutput(out);
    if (r.exitCode != 0) {
      throw StateError('Compilation failed (exit ${r.exitCode})');
    }
    if (!await File(executable!).exists()) {
      final alt = p.join(cwd, 'build', p.basename(executable!));
      if (await File(alt).exists()) {
        executable = alt;
      } else {
        throw StateError('Executable not found: $executable');
      }
    }
  }

  Future<void> _loadDebugMeta(String path) async {
    _debugMeta = null;
    final f = File(path);
    if (!await f.exists()) return;
    try {
      _debugMeta = jsonDecode(await f.readAsString()) as Map<String, dynamic>;
    } catch (_) {
      _debugMeta = null;
    }
  }

  Future<void> _startGdb(String cwd, void Function(String) onOutput) async {
    usingGdb = true;
    status = 'Starting GDB…';
    _emit();
    onOutput('\$ gdb --interpreter=mi2 -q $executable\n');
    _proc = await Process.start(
      'gdb',
      ['--interpreter=mi2', '-q', executable!],
      workingDirectory: cwd,
      environment: ProcessEnv.forHostToolchain(),
    );
    _proc!.stdout.listen((d) => _onGdbData(utf8.decode(d, allowMalformed: true)));
    _proc!.stderr.listen((d) {
      final t = utf8.decode(d, allowMalformed: true);
      console.write(t);
      onOutput(t);
    });
    _proc!.exitCode.then((code) {
      running = false;
      paused = false;
      usingGdb = false;
      status = 'Exited $code';
      _proc = null;
      onOutput('\n[debug exit $code]\n');
      _emit();
    });

    await _gdbCommand('-gdb-version');
    for (final bp in breakpoints.where((b) => b.enabled)) {
      try {
        await _gdbCommand('-break-insert ${bp.path}:${bp.line}');
      } catch (_) {}
    }
    status = 'Running';
    _emit();
    unawaited(_gdbCommand('-exec-run').catchError((_) => <String, dynamic>{}));
  }

  Future<int> _launchAfrilangDebug(
    String binary,
    String programOrSource,
    String cwd,
    void Function(String) onOutput,
  ) async {
    usingGdb = false;
    status = 'afrilang debug…';
    _emit();
    final args = ['debug', programOrSource];
    onOutput('\$ $binary ${args.join(' ')}\n');
    try {
      _proc = await Process.start(
        binary,
        args,
        workingDirectory: cwd,
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
      paused = false;
      status = 'Exited $code';
      _proc = null;
      onOutput('\n[debug exit $code]\n');
      _emit();
      return code;
    } catch (e) {
      running = false;
      status = 'Failed: $e';
      onOutput('Debug failed: $e\n');
      _emit();
      return 1;
    }
  }

  Future<void> continueExec() async {
    if (!usingGdb || !running) return;
    paused = false;
    status = 'Running';
    _emit();
    await _gdbCommand('-exec-continue');
  }

  Future<void> stepOver() async {
    if (!usingGdb || !running) return;
    await _gdbCommand('-exec-next');
  }

  Future<void> stepInto() async {
    if (!usingGdb || !running) return;
    await _gdbCommand('-exec-step');
  }

  Future<void> stepOut() async {
    if (!usingGdb || !running) return;
    await _gdbCommand('-exec-finish');
  }

  Future<void> selectFrame(int id) async {
    selectedFrameId = id;
    await refreshVariables();
    _emit();
  }

  Future<void> refreshStack() async {
    if (!usingGdb || !running) return;
    try {
      await _gdbCommand('-stack-list-frames');
    } catch (_) {}
    frames
      ..clear()
      ..addAll(_extractFrames(_lastMiBlob ?? ''));
    if (frames.isNotEmpty && selectedFrameId >= frames.length) {
      selectedFrameId = 0;
    }
    _emit();
  }

  static List<DebugStackFrame> _extractFrames(String raw) {
    final out = <DebugStackFrame>[];
    final re = RegExp(
      r'frame=\{[^}]*func="([^"]*)"[^}]*?(?:fullname|file)="([^"]*)"[^}]*line="(\d+)"'
      r'|frame=\{[^}]*?(?:fullname|file)="([^"]*)"[^}]*line="(\d+)"[^}]*func="([^"]*)"',
    );
    var id = 0;
    for (final m in re.allMatches(raw)) {
      final func = m.group(1) ?? m.group(6) ?? '?';
      final file = m.group(2) ?? m.group(4) ?? '';
      final line = int.tryParse(m.group(3) ?? m.group(5) ?? '1') ?? 1;
      out.add(DebugStackFrame(id: id++, function: func, file: file, line: line));
    }
    return out;
  }

  Future<void> refreshVariables() async {
    if (!usingGdb || !running) return;
    variables.clear();
    try {
      await _gdbCommand(
        '-stack-list-variables --thread 1 --frame $selectedFrameId --simple-values',
      );
      final rawBlob = _lastMiBlob ?? '';
      final nameRe = RegExp(r'name="([^"]+)",value="([^"]*)"');
      for (final m in nameRe.allMatches(rawBlob)) {
        variables.add(DebugVariable(name: m.group(1)!, value: m.group(2) ?? '?'));
      }
    } catch (_) {}

    final metaVars = _debugMeta?['variables'];
    if (metaVars is List && variables.isEmpty) {
      for (final entry in metaVars) {
        if (entry is! Map) continue;
        final name = entry['name']?.toString();
        if (name == null || name.isEmpty) continue;
        try {
          await _gdbCommand('-data-evaluate-expression $name');
          final blob = _lastMiBlob ?? '';
          final vm = RegExp(r'value="([^"]*)"').firstMatch(blob);
          variables.add(DebugVariable(
            name: name,
            value: vm?.group(1) ?? '?',
            type: entry['type']?.toString(),
          ));
        } catch (_) {
          variables.add(DebugVariable(
            name: name,
            value: '?',
            type: entry['type']?.toString(),
          ));
        }
      }
    }
    _emit();
  }

  Future<void> stop() async {
    final proc = _proc;
    _proc = null;
    if (proc != null) {
      try {
        if (usingGdb) proc.stdin.writeln('-gdb-exit');
      } catch (_) {}
      try {
        proc.kill();
      } catch (_) {}
    }
    for (final c in _pending.values) {
      if (!c.isCompleted) c.completeError('stopped');
    }
    _pending.clear();
    running = false;
    paused = false;
    usingGdb = false;
    status = 'Stopped';
    frames.clear();
    variables.clear();
    _emit();
  }

  void _onGdbData(String text) {
    _gdbBuf.write(text);
    var raw = _gdbBuf.toString();
    while (true) {
      final idx = raw.indexOf('\n');
      if (idx < 0) {
        _gdbBuf
          ..clear()
          ..write(raw);
        return;
      }
      final line = raw.substring(0, idx);
      raw = raw.substring(idx + 1);
      _handleGdbLine(line);
    }
  }

  void _handleGdbLine(String line) {
    if (line.startsWith('~') || line.startsWith('@') || line.startsWith('&')) {
      final msg = line.length > 2 ? line.substring(2) : line;
      final cleaned = msg
          .replaceAll(r'\n', '\n')
          .replaceAll(RegExp(r'^"|"$'), '');
      if (cleaned.trim().isNotEmpty) {
        console.write(cleaned.endsWith('\n') ? cleaned : '$cleaned\n');
        onOutput?.call(cleaned.endsWith('\n') ? cleaned : '$cleaned\n');
      }
      return;
    }
    if (line.startsWith('*stopped')) {
      paused = true;
      status = line.contains('breakpoint-hit')
          ? 'Breakpoint hit'
          : line.contains('end-stepping-range')
              ? 'Stepped'
              : 'Paused';
      _emit();
      unawaited(() async {
        await refreshStack();
        await refreshVariables();
        if (frames.isNotEmpty) {
          final top = frames.first;
          onOutput?.call('→ ${top.function} at ${top.file}:${top.line}\n');
        }
      }());
      return;
    }
    final match = RegExp(r'^(\d+)\^').firstMatch(line);
    if (match != null) {
      final token = int.parse(match.group(1)!);
      final pending = _pending.remove(token);
      if (pending == null) return;
      _lastMiBlob = line;
      if (line.contains(',error,') || line.startsWith('${token}^error')) {
        pending.completeError(line);
      } else {
        pending.complete({'_raw': line});
      }
    }
  }

  Future<Map<String, dynamic>> _gdbCommand(String cmd) {
    final proc = _proc;
    if (proc == null) return Future.error(StateError('GDB not started'));
    final id = _token++;
    final c = Completer<Map<String, dynamic>>();
    _pending[id] = c;
    proc.stdin.writeln('$id$cmd');
    return c.future.timeout(const Duration(seconds: 12), onTimeout: () {
      _pending.remove(id);
      throw TimeoutException('GDB timeout: $cmd');
    });
  }
}
