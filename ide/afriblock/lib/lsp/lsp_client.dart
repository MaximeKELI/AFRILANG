import 'dart:async';
import 'dart:convert';
import 'dart:io';

import '../models/problem_item.dart';
import '../services/process_env.dart';

/// Minimal JSON-RPC LSP client over `afrilang lsp` stdio (Phase B).
class LspClient {
  Process? _proc;
  final _buffer = StringBuffer();
  final _pending = <int, Completer<Map<String, dynamic>>>{};
  int _nextId = 1;
  bool ready = false;
  String? lastError;
  final void Function(List<ProblemItem> problems)? onDiagnostics;
  final void Function(String line)? onTrace;

  LspClient({this.onDiagnostics, this.onTrace});

  bool get isRunning => _proc != null;

  Future<void> start(String binary, {String? rootUri}) async {
    await stop();
    _proc = await Process.start(
      binary,
      ['lsp'],
      environment: ProcessEnv.forHostToolchain(),
    );
    _proc!.stdout.listen(_onData);
    _proc!.stderr.listen((d) {
      onTrace?.call(utf8.decode(d, allowMalformed: true));
    });
    _proc!.exitCode.then((code) {
      ready = false;
      _proc = null;
      onTrace?.call('LSP exited: $code\n');
    });

    await _request('initialize', {
      'processId': pid,
      'rootUri': rootUri,
      'capabilities': {
        'textDocument': {
          'synchronization': {'didSave': true},
          'publishDiagnostics': {},
          'completion': {},
          'hover': {},
          'definition': {},
          'references': {},
          'documentSymbol': {},
          'formatting': {},
        },
      },
    });
    _notify('initialized', {});
    ready = true;
  }

  Future<void> stop() async {
    if (_proc == null) return;
    try {
      await _request('shutdown', null).timeout(const Duration(seconds: 2));
      _notify('exit', null);
    } catch (_) {}
    _proc?.kill();
    _proc = null;
    ready = false;
  }

  Future<void> didOpen(String uri, String text) async {
    if (!ready) return;
    _notify('textDocument/didOpen', {
      'textDocument': {
        'uri': uri,
        'languageId': 'afrilang',
        'version': 1,
        'text': text,
      },
    });
  }

  Future<void> didChange(String uri, String text, int version) async {
    if (!ready) return;
    _notify('textDocument/didChange', {
      'textDocument': {'uri': uri, 'version': version},
      'contentChanges': [
        {'text': text},
      ],
    });
  }

  Future<void> didClose(String uri) async {
    if (!ready) return;
    _notify('textDocument/didClose', {
      'textDocument': {'uri': uri},
    });
  }

  Future<List<Map<String, dynamic>>> documentSymbol(String uri) async {
    if (!ready) return [];
    try {
      final res = await _request('textDocument/documentSymbol', {
        'textDocument': {'uri': uri},
      });
      final result = res['result'];
      if (result is List) {
        return result.whereType<Map>().map((e) => Map<String, dynamic>.from(e)).toList();
      }
    } catch (e) {
      lastError = '$e';
    }
    return [];
  }

  Future<String?> formatDocument(String uri, String text) async {
    if (!ready) return null;
    try {
      final res = await _request('textDocument/formatting', {
        'textDocument': {'uri': uri},
        'options': {'tabSize': 4, 'insertSpaces': true},
      });
      final edits = res['result'];
      if (edits is List && edits.isNotEmpty) {
        // Best-effort: if single full-doc edit, return new text.
        final first = edits.first;
        if (first is Map && first['newText'] is String) {
          return first['newText'] as String;
        }
      }
    } catch (_) {}
    return null;
  }

  void _notify(String method, Object? params) {
    _send({'jsonrpc': '2.0', 'method': method, 'params': ?params});
  }

  Future<Map<String, dynamic>> _request(String method, Object? params) {
    final id = _nextId++;
    final c = Completer<Map<String, dynamic>>();
    _pending[id] = c;
    _send({
      'jsonrpc': '2.0',
      'id': id,
      'method': method,
      'params': ?params,
    });
    return c.future.timeout(const Duration(seconds: 8), onTimeout: () {
      _pending.remove(id);
      return {'error': 'timeout'};
    });
  }

  void _send(Map<String, dynamic> msg) {
    final body = jsonEncode(msg);
    final payload = 'Content-Length: ${utf8.encode(body).length}\r\n\r\n$body';
    _proc?.stdin.add(utf8.encode(payload));
  }

  void _onData(List<int> data) {
    _buffer.write(utf8.decode(data, allowMalformed: true));
    while (true) {
      final raw = _buffer.toString();
      final sep = raw.indexOf('\r\n\r\n');
      if (sep < 0) return;
      final header = raw.substring(0, sep);
      final m = RegExp(r'Content-Length:\s*(\d+)', caseSensitive: false)
          .firstMatch(header);
      if (m == null) {
        _buffer.clear();
        return;
      }
      final len = int.parse(m.group(1)!);
      final start = sep + 4;
      if (raw.length < start + len) return;
      final body = raw.substring(start, start + len);
      _buffer.clear();
      _buffer.write(raw.substring(start + len));
      _handleMessage(body);
    }
  }

  void _handleMessage(String body) {
    Map<String, dynamic> msg;
    try {
      msg = jsonDecode(body) as Map<String, dynamic>;
    } catch (_) {
      return;
    }
    onTrace?.call('← ${msg['method'] ?? msg['id']}\n');

    if (msg['method'] == 'textDocument/publishDiagnostics') {
      final params = msg['params'] as Map<String, dynamic>?;
      if (params != null && onDiagnostics != null) {
        final uri = params['uri']?.toString() ?? '';
        final path = uri.startsWith('file://') ? Uri.parse(uri).toFilePath() : uri;
        final diags = (params['diagnostics'] as List?) ?? [];
        final items = <ProblemItem>[];
        for (final d in diags) {
          if (d is! Map) continue;
          final range = d['range'] as Map?;
          final start = range?['start'] as Map?;
          final line = (start?['line'] as num?)?.toInt();
          final col = (start?['character'] as num?)?.toInt();
          final sevNum = d['severity'];
          final sev = switch (sevNum) {
            1 => ProblemSeverity.error,
            2 => ProblemSeverity.warning,
            _ => ProblemSeverity.info,
          };
          items.add(ProblemItem(
            message: d['message']?.toString() ?? '',
            path: path,
            line: line == null ? null : line + 1,
            column: col == null ? null : col + 1,
            severity: sev,
          ));
        }
        onDiagnostics!(items);
      }
      return;
    }

    final id = msg['id'];
    if (id is int && _pending.containsKey(id)) {
      _pending.remove(id)!.complete(msg);
    }
  }
}

/// Local outline fallback when LSP symbols are empty.
class SymbolIndex {
  static List<OutlineSymbol> scan(String text) {
    final out = <OutlineSymbol>[];
    final lines = text.split('\n');
    final re = RegExp(
      r'^\s*(?:function|fonction|class|classe|module)\s+([A-Za-z_][A-Za-z0-9_]*)',
      caseSensitive: false,
    );
    for (var i = 0; i < lines.length; i++) {
      final m = re.firstMatch(lines[i]);
      if (m != null) {
        out.add(OutlineSymbol(name: m.group(1)!, line: i + 1, kind: lines[i]));
      }
    }
    return out;
  }
}

class OutlineSymbol {
  OutlineSymbol({required this.name, required this.line, required this.kind});
  final String name;
  final int line;
  final String kind;
}
