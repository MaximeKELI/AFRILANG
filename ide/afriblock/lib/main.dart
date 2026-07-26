import 'package:flutter/material.dart';
import 'package:flutter/foundation.dart';

import 'app.dart';

void main() {
  WidgetsFlutterBinding.ensureInitialized();
  // Desktop-first; web/mobile not a v0.1 target.
  if (kIsWeb) {
    debugPrint('AFRIBLOCK targets desktop (linux/windows/macos).');
  }
  runApp(const AfriblockApp());
}
