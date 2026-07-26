import 'dart:io';

/// Environment helpers for spawning toolchain processes from AFRIBLOCK.
///
/// Flutter's snap packages inject host-incompatible toolchain paths:
/// - `/snap/flutter/.../usr/bin` ships ancient GNU `as` (no `--gdwarf-5`)
/// - `/snap/flutter/.../usr/lib` on `LD_LIBRARY_PATH` / `LIBRARY_PATH` makes
///   host `g++`/`ld` resolve against snap's old glibc → undefined
///   `fstat@GLIBC_2.33`, `pthread_*@GLIBC_2.34`, etc.
class ProcessEnv {
  ProcessEnv._();

  /// Entries that must not precede the host system assembler/linker/libc.
  static bool isPollutedToolchainEntry(String entry) {
    if (entry.isEmpty) return true;
    final n = entry.replaceAll('\\', '/').toLowerCase();
    if (n.contains('/snap/flutter/')) return true;
    if (n.contains('/snap/dart-sdk/')) return true;
    if (n.contains('/snap/flutter-sdk/')) return true;
    return false;
  }

  /// Filter colon/semicolon-separated path lists, dropping snap Flutter dirs.
  static String sanitizePathList(String path, {required String separator}) {
    final parts = path.split(separator);
    final filtered = <String>[];
    for (final raw in parts) {
      final p = raw.trim();
      if (p.isEmpty) continue;
      if (isPollutedToolchainEntry(p)) continue;
      if (!filtered.contains(p)) filtered.add(p);
    }
    return filtered.join(separator);
  }

  /// Returns a PATH safe for invoking host `g++` / `as` / `ld`.
  static String sanitizePath(String path, {String separator = ':'}) {
    final sep = Platform.isWindows ? ';' : separator;
    final filtered = sanitizePathList(path, separator: Platform.isWindows ? ';' : sep);

    if (Platform.isWindows) {
      return filtered;
    }

    const prefer = <String>['/usr/bin', '/bin', '/usr/local/bin'];
    final out = <String>[];
    for (final p in prefer) {
      if (!out.contains(p)) out.add(p);
    }
    for (final p in filtered.split(':')) {
      if (p.isEmpty) continue;
      if (!out.contains(p)) out.add(p);
    }
    return out.join(':');
  }

  static const _pathLikeKeys = <String>[
    'LD_LIBRARY_PATH',
    'LIBRARY_PATH',
    'COMPILER_PATH',
    'C_INCLUDE_PATH',
    'CPLUS_INCLUDE_PATH',
    'CPATH',
    'PKG_CONFIG_PATH',
    'CMAKE_PREFIX_PATH',
  ];

  /// Full environment map for `Process.start` / `Process.run` of afrilang.
  static Map<String, String> forHostToolchain([Map<String, String>? base]) {
    final env = Map<String, String>.from(base ?? Platform.environment);
    final pathSep = Platform.isWindows ? ';' : ':';
    final rawPath = env['PATH'] ?? '';
    env['PATH'] = sanitizePath(rawPath);

    for (final key in _pathLikeKeys) {
      final v = env[key];
      if (v == null || v.isEmpty) continue;
      final cleaned = sanitizePathList(v, separator: pathSep);
      if (cleaned.isEmpty) {
        env.remove(key);
      } else {
        env[key] = cleaned;
      }
    }
    return env;
  }
}
