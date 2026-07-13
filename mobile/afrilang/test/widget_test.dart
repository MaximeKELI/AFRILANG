import 'package:flutter_test/flutter_test.dart';

import 'package:afrilang/main.dart';

void main() {
  testWidgets('AFRILANG app boots', (tester) async {
    await tester.pumpWidget(const AfrilangApp());
    await tester.pump(const Duration(milliseconds: 100));
    expect(find.textContaining('AFRILANG'), findsWidgets);
  });
}
