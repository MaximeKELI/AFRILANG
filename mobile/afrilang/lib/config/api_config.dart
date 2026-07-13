/// Configuration API — même backend Django que le site web.
///
/// Émulateur Android : `http://10.0.2.2:8000`
/// iOS simulateur / desktop : `http://127.0.0.1:8000`
/// Device physique : IP LAN de la machine (ex. `http://192.168.1.10:8000`)
/// Override : `--dart-define=AFRILANG_API_BASE=http://…`
library;

import 'dart:io' show Platform;

import 'package:flutter/foundation.dart' show kIsWeb;

class ApiConfig {
  static String get baseUrl {
    const fromEnv = String.fromEnvironment('AFRILANG_API_BASE');
    if (fromEnv.isNotEmpty) return fromEnv.replaceAll(RegExp(r'/$'), '');
    if (kIsWeb) return 'http://127.0.0.1:8000';
    try {
      if (Platform.isAndroid) return 'http://10.0.2.2:8000';
    } catch (_) {}
    return 'http://127.0.0.1:8000';
  }
}
