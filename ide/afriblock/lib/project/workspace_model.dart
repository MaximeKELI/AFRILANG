import 'dart:convert';
import 'dart:io';

import 'package:path/path.dart' as p;

/// Multi-root workspace persisted under `.afriblock/workspace.json`.
class WorkspaceFolder {
  WorkspaceFolder({required this.path, String? name})
      : name = name ?? p.basename(path);

  final String path;
  final String name;

  Map<String, dynamic> toJson() => {'path': path, 'name': name};

  factory WorkspaceFolder.fromJson(Map<String, dynamic> json) => WorkspaceFolder(
        path: json['path']?.toString() ?? '',
        name: json['name']?.toString(),
      );
}

class WorkspaceModel {
  WorkspaceModel({List<WorkspaceFolder>? folders, this.activeIndex = 0})
      : folders = folders ?? [];

  final List<WorkspaceFolder> folders;
  int activeIndex;

  bool get isEmpty => folders.isEmpty;
  bool get isMultiRoot => folders.length > 1;

  WorkspaceFolder? get active =>
      folders.isEmpty ? null : folders[activeIndex.clamp(0, folders.length - 1)];

  String? get primaryPath => active?.path;

  void setActive(int index) {
    if (folders.isEmpty) return;
    activeIndex = index.clamp(0, folders.length - 1);
  }

  void replaceAll(List<String> paths) {
    folders
      ..clear()
      ..addAll(paths.where((p) => p.isNotEmpty).map((e) => WorkspaceFolder(path: e)));
    activeIndex = 0;
  }

  void addFolder(String path) {
    final norm = p.normalize(path);
    if (folders.any((f) => p.equals(f.path, norm))) return;
    folders.add(WorkspaceFolder(path: norm));
    activeIndex = folders.length - 1;
  }

  void removeFolder(String path) {
    folders.removeWhere((f) => p.equals(f.path, path));
    if (activeIndex >= folders.length) {
      activeIndex = folders.isEmpty ? 0 : folders.length - 1;
    }
  }

  Map<String, dynamic> toJson() => {
        'version': 1,
        'folders': folders.map((f) => f.toJson()).toList(),
        'activeIndex': activeIndex,
      };

  factory WorkspaceModel.fromJson(Map<String, dynamic> json) {
    final list = (json['folders'] as List?) ?? const [];
    final folders = <WorkspaceFolder>[];
    for (final e in list) {
      if (e is Map) {
        final f = WorkspaceFolder.fromJson(Map<String, dynamic>.from(e));
        if (f.path.isNotEmpty) folders.add(f);
      }
    }
    return WorkspaceModel(
      folders: folders,
      activeIndex: (json['activeIndex'] as num?)?.toInt() ?? 0,
    );
  }

  static Future<WorkspaceModel?> loadBeside(String folderPath) async {
    final file = File(p.join(folderPath, '.afriblock', 'workspace.json'));
    if (!await file.exists()) return null;
    try {
      final json = jsonDecode(await file.readAsString());
      if (json is Map) return WorkspaceModel.fromJson(Map<String, dynamic>.from(json));
    } catch (_) {}
    return null;
  }

  /// Save next to the first folder (or [anchor] if provided).
  Future<void> save({String? anchor}) async {
    final root = anchor ?? primaryPath;
    if (root == null) return;
    final dir = Directory(p.join(root, '.afriblock'));
    if (!await dir.exists()) await dir.create(recursive: true);
    final file = File(p.join(dir.path, 'workspace.json'));
    await file.writeAsString(const JsonEncoder.withIndent('  ').convert(toJson()));
  }

  /// Resolve a relative path against the nearest workspace folder.
  String resolvePath(String path) {
    if (p.isAbsolute(path)) return path;
    final base = primaryPath;
    if (base == null) return path;
    return p.normalize(p.join(base, path));
  }
}
