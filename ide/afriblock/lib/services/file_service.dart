import 'dart:io';

import 'package:path/path.dart' as p;

import '../models/workspace_node.dart';

const _ignoredNames = {
  '.git',
  '.hg',
  '.svn',
  'build',
  '.dart_tool',
  'node_modules',
  '.idea',
  '.vscode',
  '__pycache__',
  '.afrilang',
};

class FileService {
  Future<String> readFile(String path) => File(path).readAsString();

  Future<void> writeFile(String path, String content) async {
    final file = File(path);
    await file.parent.create(recursive: true);
    await file.writeAsString(content);
  }

  Future<bool> exists(String path) async =>
      await File(path).exists() || await Directory(path).exists();

  Future<void> createDirectory(String path) async {
    final dir = Directory(path);
    if (await dir.exists()) {
      throw StateError('Folder already exists: $path');
    }
    await dir.create(recursive: true);
  }

  /// Creates a new file; fails if it already exists.
  Future<void> createFile(String path, {String content = ''}) async {
    final file = File(path);
    if (await file.exists()) {
      throw StateError('File already exists: $path');
    }
    await file.parent.create(recursive: true);
    await file.writeAsString(content);
  }

  Future<WorkspaceNode> loadTree(String rootPath, {int maxDepth = 6}) async {
    final root = Directory(rootPath);
    if (!await root.exists()) {
      throw StateError('Folder not found: $rootPath');
    }
    return _walk(root, depth: 0, maxDepth: maxDepth);
  }

  Future<WorkspaceNode> _walk(
    Directory dir, {
    required int depth,
    required int maxDepth,
  }) async {
    final children = <WorkspaceNode>[];
    if (depth < maxDepth) {
      final entities = await dir.list(followLinks: false).toList();
      entities.sort((a, b) {
        final aDir = a is Directory;
        final bDir = b is Directory;
        if (aDir != bDir) return aDir ? -1 : 1;
        return p.basename(a.path).toLowerCase().compareTo(p.basename(b.path).toLowerCase());
      });
      for (final e in entities) {
        final name = p.basename(e.path);
        if (name.startsWith('.') && name != '.afr') {
          if (_ignoredNames.contains(name)) continue;
          // hide most dotfiles; keep visible only if not ignored
          if (name != '.env.example') continue;
        }
        if (_ignoredNames.contains(name)) continue;
        if (e is Directory) {
          children.add(await _walk(e, depth: depth + 1, maxDepth: maxDepth));
        } else if (e is File) {
          children.add(WorkspaceNode(
            path: e.path,
            name: name,
            isDirectory: false,
          ));
        }
      }
    }
    return WorkspaceNode(
      path: dir.path,
      name: p.basename(dir.path),
      isDirectory: true,
      children: children,
      expanded: depth == 0,
    );
  }
}
