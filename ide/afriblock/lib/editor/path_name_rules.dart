import 'package:path/path.dart' as p;

/// Validates relative names for New File / New Folder (unit-tested).
class PathNameRules {
  static final _illegal = RegExp(r'[<>:"|?*\x00-\x1F]');

  /// Returns null if valid, otherwise an error message.
  static String? validateSegment(String raw, {required bool isFolder}) {
    final name = raw.trim();
    if (name.isEmpty) return 'Name cannot be empty';
    if (name == '.' || name == '..') return 'Invalid name';
    if (name.contains('/') || name.contains('\\')) {
      return 'Use a single name (no path separators)';
    }
    if (_illegal.hasMatch(name)) return 'Name contains illegal characters';
    if (!isFolder && name.endsWith('.')) return 'File name cannot end with a dot';
    return null;
  }

  static String joinUnder(String parentDir, String name) =>
      p.normalize(p.join(parentDir, name.trim()));

  /// Ensure .afr for empty extension when creating AFRILANG sources.
  static String ensureAfrExtension(String name, {bool forceAfr = false}) {
    final n = name.trim();
    if (!forceAfr) return n;
    if (p.extension(n).isEmpty) return '$n.afr';
    return n;
  }
}
