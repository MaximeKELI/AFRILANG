import 'package:flutter/material.dart';
import 'package:flutter_test/flutter_test.dart';

import 'package:afriblock/app.dart';
import 'package:afriblock/project/project_service.dart';
import 'package:afriblock/services/afrilang_cli.dart';

void main() {
  testWidgets('AFRIBLOCK welcome shows brand', (tester) async {
    await tester.binding.setSurfaceSize(const Size(1280, 800));
    addTearDown(() => tester.binding.setSurfaceSize(null));
    await tester.pumpWidget(const AfriblockApp());
    await tester.pump();
    await tester.pump(const Duration(milliseconds: 100));
    expect(find.text('AFRIBLOCK'), findsWidgets);
    expect(find.textContaining('Desktop IDE'), findsOneWidget);
  });

  test('diagnostic parser extracts path:line', () {
    const text = 'examples/hello.afr:12:3: error: unknown name x\n';
    final items = AfrilangCli.parseDiagnostics(text, fallbackPath: 'x.afr');
    expect(items, isNotEmpty);
    expect(items.first.line, 12);
    expect(items.first.message.toLowerCase(), contains('unknown'));
  });

  test('default targets include debug and wasm32', () {
    expect(
      kDefaultTargets.map((t) => t.id),
      containsAll(['debug', 'test', 'wasm32']),
    );
  });
}
