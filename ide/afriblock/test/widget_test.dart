import 'package:flutter_test/flutter_test.dart';

import 'package:afriblock/app.dart';
import 'package:afriblock/services/afrilang_cli.dart';

void main() {
  testWidgets('AFRIBLOCK welcome shows brand', (tester) async {
    await tester.pumpWidget(const AfriblockApp());
    await tester.pump(); // init async
    await tester.pump(const Duration(milliseconds: 100));
    expect(find.text('AFRIBLOCK'), findsWidgets);
    expect(find.text('Open Folder'), findsOneWidget);
  });

  test('diagnostic parser extracts path:line', () {
    const text = 'examples/hello.afr:12:3: error: unknown name x\n';
    final items = AfrilangCli.parseDiagnostics(text, fallbackPath: 'x.afr');
    expect(items, isNotEmpty);
    expect(items.first.line, 12);
    expect(items.first.message.toLowerCase(), contains('unknown'));
  });
}
