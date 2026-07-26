import 'dart:convert';
import 'dart:io';

import 'package:flutter/foundation.dart';
import 'package:flutter_pty/flutter_pty.dart';
import 'package:xterm/xterm.dart';

import '../services/process_env.dart';

class TerminalSession {
  TerminalSession({required this.id, required this.title})
      : terminal = Terminal(maxLines: 10000);

  final String id;
  String title;
  final Terminal terminal;
  Pty? pty;

  void dispose() {
    pty?.kill();
    pty = null;
  }
}

class TerminalService extends ChangeNotifier {
  final sessions = <TerminalSession>[];
  String? activeId;

  TerminalSession? get active {
    if (activeId == null) return null;
    try {
      return sessions.firstWhere((s) => s.id == activeId);
    } catch (_) {
      return null;
    }
  }

  TerminalSession create({String? cwd, String? title}) {
    final id = 'term-${DateTime.now().microsecondsSinceEpoch}';
    final session = TerminalSession(id: id, title: title ?? 'Terminal');
    final shell = Platform.isWindows
        ? (Platform.environment['COMSPEC'] ?? 'cmd.exe')
        : (Platform.environment['SHELL'] ?? '/bin/bash');
    try {
      final pty = Pty.start(
        shell,
        workingDirectory: cwd,
        environment: ProcessEnv.forHostToolchain(),
      );
      session.pty = pty;
      pty.output
          .cast<List<int>>()
          .transform(const Utf8Decoder())
          .listen(session.terminal.write);
      session.terminal.onOutput = (data) {
        pty.write(const Utf8Encoder().convert(data));
      };
      pty.exitCode.then((_) {
        session.terminal.write('\r\n[process exited]\r\n');
        notifyListeners();
      });
    } catch (e) {
      session.terminal.write('PTY unavailable: $e\r\n');
    }
    sessions.add(session);
    activeId = id;
    notifyListeners();
    return session;
  }

  void select(String id) {
    activeId = id;
    notifyListeners();
  }

  void close(String id) {
    final i = sessions.indexWhere((s) => s.id == id);
    if (i < 0) return;
    sessions[i].dispose();
    sessions.removeAt(i);
    if (activeId == id) {
      activeId = sessions.isEmpty ? null : sessions.last.id;
    }
    notifyListeners();
  }

  void disposeAll() {
    for (final s in sessions) {
      s.dispose();
    }
    sessions.clear();
    activeId = null;
  }
}
