import 'package:flutter_test/flutter_test.dart';
import 'package:afriblock/core/command_bus.dart';
import 'package:afriblock/core/event_bus.dart';
import 'package:afriblock/models/editor_tab.dart';
import 'package:afriblock/lsp/lsp_client.dart';
import 'package:afriblock/services/afrilang_cli.dart';
import 'package:afriblock/debug/debug_service.dart';
import 'package:afriblock/models/problem_item.dart';

void main() {
  group('CommandBus', () {
    test('register and filter', () {
      final bus = CommandBus();
      bus.register(IdeCommandDef(
        id: 'a.run',
        label: 'AFRILANG: Run',
        category: 'AFRILANG',
        run: (_) async {},
      ));
      bus.register(IdeCommandDef(
        id: 'f.save',
        label: 'File: Save',
        category: 'File',
        run: (_) async {},
      ));
      expect(bus.filter('run').single.id, 'a.run');
      expect(bus.filter('file').single.id, 'f.save');
      expect(bus['a.run']?.label, 'AFRILANG: Run');
    });
  });

  group('EventBus', () {
    test('emits to typed handlers', () {
      final bus = EventBus();
      WorkspaceOpenedEvent? got;
      bus.on<WorkspaceOpenedEvent>((e) => got = e);
      bus.emit(WorkspaceOpenedEvent('/tmp/ws'));
      expect(got?.root, '/tmp/ws');
    });
  });

  group('EditorTab', () {
    test('dirty tracking', () {
      final tab = EditorTab(path: '/a.afr', content: 'say 1')..markSaved();
      expect(tab.dirty, isFalse);
      expect(tab.name, 'a.afr');
      tab.applyEdit('say 2');
      expect(tab.dirty, isTrue);
      tab.markSaved();
      expect(tab.dirty, isFalse);
    });
  });

  group('SymbolIndex', () {
    test('scans functions and classes', () {
      const src = '''
function hello()
end

class Foo
end

fonction bar()
fin
''';
      final symbols = SymbolIndex.scan(src);
      expect(symbols.map((s) => s.name), containsAll(['hello', 'Foo', 'bar']));
      expect(symbols.first.line, 1);
    });
  });

  group('AfrilangCli.parseDiagnostics', () {
    test('parses path:line:col', () {
      const text = 'src/main.afr:10:2: error: boom\n';
      final items = AfrilangCli.parseDiagnostics(text, fallbackPath: 'x.afr');
      expect(items.single.line, 10);
      expect(items.single.column, 2);
      expect(items.single.severity, ProblemSeverity.error);
    });

    test('fallback on unstructured error', () {
      final items = AfrilangCli.parseDiagnostics(
        'compilation failed badly',
        fallbackPath: 'x.afr',
      );
      expect(items, isNotEmpty);
      expect(items.first.path, 'x.afr');
    });

    test('missing binary CliResult', () async {
      final cli = AfrilangCli(resolveBinary: () async => null);
      final r = await cli.checkFile('a.afr');
      expect(r.exitCode, 127);
      expect(r.problems, isNotEmpty);
    });
  });

  group('DebugService', () {
    test('toggle breakpoints', () {
      final d = DebugService();
      d.toggleBreakpoint('/a.afr', 3);
      expect(d.hasBreakpoint('/a.afr', 3), isTrue);
      d.toggleBreakpoint('/a.afr', 3);
      expect(d.hasBreakpoint('/a.afr', 3), isFalse);
    });
  });
}
