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

  test('smoke: diagnostics + targets still wired', () {
    final items = AfrilangCli.parseDiagnostics(
      'a.afr:1:1: error: x\n',
      fallbackPath: 'a.afr',
    );
    expect(items.single.line, 1);
    expect(kDefaultTargets, isNotEmpty);
  });
}
