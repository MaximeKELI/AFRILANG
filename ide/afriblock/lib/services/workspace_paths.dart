import 'dart:io';

import 'package:path/path.dart' as p;

/// Detects xdg-desktop-portal document mounts (Flatpak / snap file pickers).
/// These paths under `/run/user/*/doc/` are ephemeral and often break builds.
bool isDocumentPortalPath(String path) {
  final n = path.replaceAll('\\', '/');
  return RegExp(r'^/run/user/\d+/doc/').hasMatch(n);
}

/// Resolves symlinks / portal binds to a stable path when possible.
Future<String> resolveWorkspacePath(String folder) async {
  final normalized = p.normalize(folder);
  try {
    final resolved = await Directory(normalized).resolveSymbolicLinks();
    return p.normalize(resolved);
  } catch (_) {
    return normalized;
  }
}

/// Suggests the real AFRILANG `examples/` tree next to the toolchain binary.
String? suggestAfrilangExamplesDir(String? afrilangBinary) {
  if (afrilangBinary == null || afrilangBinary.isEmpty) return null;
  final bin = p.normalize(afrilangBinary);
  // .../AFRILANG/build/afrilang → .../AFRILANG/examples
  final buildDir = p.dirname(bin);
  final root = p.dirname(buildDir);
  final examples = p.join(root, 'examples');
  if (Directory(examples).existsSync()) return examples;
  // .../AFRILANG/afrilang (installed) → try sibling examples
  final sibling = p.join(p.dirname(bin), 'examples');
  if (Directory(sibling).existsSync()) return sibling;
  return null;
}
