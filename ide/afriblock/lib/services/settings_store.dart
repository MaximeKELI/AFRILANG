import 'dart:convert';
import 'dart:io';

import 'package:path/path.dart' as p;
import 'package:shared_preferences/shared_preferences.dart';

class SettingsStore {
  static const _keyAfrilang = 'afrilang_path';
  static const _keyRecent = 'recent_folders';

  String? afrilangPath;
  List<String> recentFolders = [];

  Future<void> load() async {
    final prefs = await SharedPreferences.getInstance();
    afrilangPath = prefs.getString(_keyAfrilang);
    recentFolders = prefs.getStringList(_keyRecent) ?? [];
  }

  Future<void> setAfrilangPath(String? path) async {
    afrilangPath = path;
    final prefs = await SharedPreferences.getInstance();
    if (path == null || path.isEmpty) {
      await prefs.remove(_keyAfrilang);
    } else {
      await prefs.setString(_keyAfrilang, path);
    }
  }

  Future<void> pushRecent(String folder) async {
    recentFolders = [
      folder,
      ...recentFolders.where((e) => e != folder),
    ].take(8).toList();
    final prefs = await SharedPreferences.getInstance();
    await prefs.setStringList(_keyRecent, recentFolders);
  }

  /// Resolve `afrilang` binary: env, settings, relative monorepo build, PATH.
  Future<String?> resolveAfrilangBinary() async {
    final env = Platform.environment['AFRIBLOCK_AFRILANG'];
    if (env != null && env.isNotEmpty && await File(env).exists()) return env;

    if (afrilangPath != null &&
        afrilangPath!.isNotEmpty &&
        await File(afrilangPath!).exists()) {
      return afrilangPath;
    }

    // From ide/afriblock → ../../build/afrilang
    final cwd = Directory.current.path;
    final candidates = <String>[
      p.normalize(p.join(cwd, '..', '..', 'build', 'afrilang')),
      p.normalize(p.join(cwd, 'build', 'afrilang')),
      p.normalize(p.join(cwd, '..', 'build', 'afrilang')),
    ];
    if (Platform.isWindows) {
      candidates.addAll(candidates.map((c) => '$c.exe').toList());
    }
    for (final c in candidates) {
      if (await File(c).exists()) return c;
    }

    // PATH lookup
    try {
      final which = Platform.isWindows ? 'where' : 'which';
      final r = await Process.run(which, ['afrilang']);
      if (r.exitCode == 0) {
        final line = (r.stdout as String).trim().split('\n').first.trim();
        if (line.isNotEmpty && await File(line).exists()) return line;
      }
    } catch (_) {}
    return null;
  }

  Map<String, dynamic> toDebugJson() => {
        'afrilangPath': afrilangPath,
        'recentFolders': recentFolders,
      };

  @override
  String toString() => jsonEncode(toDebugJson());
}
