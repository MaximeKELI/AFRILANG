import 'dart:io';

/// Environment helpers for spawning toolchain processes from AFRIBLOCK.
///
/// Flutter's snap packages prepend `/snap/flutter/.../usr/bin` to `PATH`. That
/// directory ships an ancient GNU `as` (binutils 2.34) which rejects
/// `--gdwarf-5` when the host `g++` drives assembly — breaking `afrilang run`.
class ProcessEnv {
  ProcessEnv._();

  /// Entries that must not precede the host system assembler/linker.
  static bool isPollutedToolchainEntry(String entry) {
    if (entry.isEmpty) return true;
    final n = entry.replaceAll('\\', '/').toLowerCase();
    if (n.contains('/snap/flutter/')) return true;
    if (n.contains('/snap/dart-sdk/')) return true;
    if (n.contains('/snap/flutter-sdk/')) return true;
    return false;
  }

  /// Returns a PATH safe for invoking host `g++` / `as` / `ld`.
  static String sanitizePath(String path, {String separator = ':'}) {
    final sep = Platform.isWindows ? ';' : separator;
    final parts = path.split(Platform.isWindows ? ';' : sep);
    final filtered = <String>[];
    for (final raw in parts) {
      final p = raw.trim();
      if (p.isEmpty) continue;
      if (isPollutedToolchainEntry(p)) continue;
      if (!filtered.contains(p)) filtered.add(p);
    }

    if (Platform.isWindows) {
      return filtered.join(';');
    }

    const prefer = <String>['/usr/bin', '/bin', '/usr/local/bin'];
    final out = <String>[];
    for (final p in prefer) {
      if (!out.contains(p)) out.add(p);
    }
    for (final p in filtered) {
      if (!out.contains(p)) out.add(p);
    }
    return out.join(':');
  }

  /// Full environment map for `Process.start` / `Process.run` of afrilang.
  static Map<String, String> forHostToolchain([Map<String, String>? base]) {
    final env = Map<String, String>.from(base ?? Platform.environment);
    final rawPath = env['PATH'] ?? '';
    env['PATH'] = sanitizePath(rawPath);
    // Drop snap-tainted compiler search paths if present.
    for (final key in const [
      'COMPILER_PATH',
      'LIBRARY_PATH',
      'C_INCLUDE_PATH',
      'CPLUS_INCLUDE_PATH',
      'CPATH',
    ]) {
      final v = env[key];
      if (v == null || v.isEmpty) continue;
      if (v.toLowerCase().contains('/snap/flutter/')) {
        env.remove(key);
      }
    }
    return env;
  }
}
