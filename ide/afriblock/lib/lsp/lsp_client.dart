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
          'rename': {},
          'references': {},
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

  /// [line] / [character] are 0-based (LSP).
  Future<String?> hover(String uri, int line, int character) async {
    if (!ready) return null;
    try {
      final res = await _request('textDocument/hover', {
        'textDocument': {'uri': uri},
        'position': {'line': line, 'character': character},
      });
      return parseHoverContents(res['result']);
    } catch (e) {
      lastError = '$e';
      return null;
    }
  }

  /// [line] / [character] are 0-based (LSP).
  Future<LspLocation?> definition(String uri, int line, int character) async {
    if (!ready) return null;
    try {
      final res = await _request('textDocument/definition', {
        'textDocument': {'uri': uri},
        'position': {'line': line, 'character': character},
      });
      return parseDefinitionResult(res['result']);
    } catch (e) {
      lastError = '$e';
      return null;
    }
  }

  Future<List<LspLocation>> references(String uri, int line, int character) async {
    if (!ready) return [];
    try {
      final res = await _request('textDocument/references', {
        'textDocument': {'uri': uri},
        'position': {'line': line, 'character': character},
        'context': {'includeDeclaration': true},
      });
      final result = res['result'];
      if (result is! List) return [];
      final out = <LspLocation>[];
      for (final e in result) {
        if (e is Map) {
          final loc = parseDefinitionResult(e);
          if (loc != null) out.add(loc);
        }
      }
      return out;
    } catch (e) {
      lastError = '$e';
      return [];
    }
  }

  Future<LspWorkspaceEdit?> rename(
    String uri,
    int line,
    int character,
    String newName,
  ) async {
    if (!ready) return null;
    try {
      final res = await _request('textDocument/rename', {
        'textDocument': {'uri': uri},
        'position': {'line': line, 'character': character},
        'newName': newName,
      });
      return parseWorkspaceEdit(res['result']);
    } catch (e) {
      lastError = '$e';
      return null;
    }
  }

  static LspWorkspaceEdit? parseWorkspaceEdit(Object? result) {
    if (result is! Map) return null;
    final changes = <String, List<LspTextEdit>>{};
    final rawChanges = result['changes'];
    if (rawChanges is Map) {
      rawChanges.forEach((uri, edits) {
        if (edits is! List) return;
        final list = <LspTextEdit>[];
        for (final e in edits) {
          if (e is! Map) continue;
          final range = e['range'] as Map?;
          final start = range?['start'] as Map?;
          final end = range?['end'] as Map?;
          list.add(LspTextEdit(
            startLine: ((start?['line'] as num?)?.toInt() ?? 0) + 1,
            startCharacter: ((start?['character'] as num?)?.toInt() ?? 0) + 1,
            endLine: ((end?['line'] as num?)?.toInt() ?? 0) + 1,
            endCharacter: ((end?['character'] as num?)?.toInt() ?? 0) + 1,
            newText: e['newText']?.toString() ?? '',
          ));
        }
        changes[uri.toString()] = list;
      });
    }
    if (changes.isEmpty) return null;
    return LspWorkspaceEdit(changes: changes);
  }

  /// Extract markdown/plaintext from a Hover result.
  static String? parseHoverContents(Object? result) {
    if (result == null) return null;
    if (result is String) return result.trim().isEmpty ? null : result.trim();
    if (result is! Map) return null;
    final contents = result['contents'];
    if (contents is String) {
      return contents.trim().isEmpty ? null : contents.trim();
    }
    if (contents is Map) {
      final v = contents['value']?.toString() ?? contents['language']?.toString();
      if (v == null || v.trim().isEmpty) return null;
      return v.trim();
    }
    if (contents is List) {
      final parts = <String>[];
      for (final c in contents) {
        if (c is String && c.trim().isNotEmpty) {
          parts.add(c.trim());
        } else if (c is Map) {
          final v = c['value']?.toString();
          if (v != null && v.trim().isNotEmpty) parts.add(v.trim());
        }
      }
      if (parts.isEmpty) return null;
      return parts.join('\n\n');
    }
    return null;
  }

  static LspLocation? parseDefinitionResult(Object? result) {
    if (result == null) return null;
    if (result is Map) {
      return _locationFromMap(Map<String, dynamic>.from(result));
    }
    if (result is List && result.isNotEmpty) {
      final first = result.first;
      if (first is Map) {
        return _locationFromMap(Map<String, dynamic>.from(first));
      }
    }
    return null;
  }

  static LspLocation? _locationFromMap(Map<String, dynamic> m) {
    // LocationLink uses targetUri / targetRange; Location uses uri / range.
    final uri = (m['uri'] ?? m['targetUri'])?.toString();
    if (uri == null || uri.isEmpty) return null;
    final range = (m['range'] ?? m['targetSelectionRange'] ?? m['targetRange']) as Map?;
    final start = range?['start'] as Map?;
    final line = (start?['line'] as num?)?.toInt();
    final col = (start?['character'] as num?)?.toInt();
    return LspLocation(
      uri: uri,
      line: line == null ? 1 : line + 1,
      column: col == null ? 1 : col + 1,
    );
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

class LspLocation {
  LspLocation({required this.uri, required this.line, this.column});
  final String uri;
  final int line;
  final int? column;
}

class LspTextEdit {
  LspTextEdit({
    required this.startLine,
    required this.startCharacter,
    required this.endLine,
    required this.endCharacter,
    required this.newText,
  });
  final int startLine;
  final int startCharacter;
  final int endLine;
  final int endCharacter;
  final String newText;
}

class LspWorkspaceEdit {
  LspWorkspaceEdit({required this.changes});
  final Map<String, List<LspTextEdit>> changes;
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
