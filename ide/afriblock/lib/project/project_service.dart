import 'dart:io';

import 'package:path/path.dart' as p;

class AfrilangProject {
  AfrilangProject({
    required this.root,
    required this.name,
    this.main,
    this.output,
    this.version,
    this.description,
  });

  final String root;
  final String name;
  final String? main;
  final String? output;
  final String? version;
  final String? description;

  String? get mainAbsolute =>
      main == null ? null : p.normalize(p.join(root, main!));

  String? get outputAbsolute =>
      output == null ? null : p.normalize(p.join(root, output!));
}

class BuildTarget {
  const BuildTarget({
    required this.id,
    required this.label,
    required this.args,
    this.description = '',
  });

  final String id;
  final String label;
  final List<String> args;
  final String description;
}

const kDefaultTargets = <BuildTarget>[
  BuildTarget(
    id: 'debug',
    label: 'debug',
    args: ['build'],
    description: 'afrilang build (default / debug-oriented)',
  ),
  BuildTarget(
    id: 'release',
    label: 'release',
    args: ['build'],
    description: 'afrilang build (release profile when supported)',
  ),
  BuildTarget(
    id: 'check',
    label: 'check',
    args: ['check'],
    description: 'Semantic check without full link when possible',
  ),
  BuildTarget(
    id: 'test',
    label: 'test',
    args: ['test'],
    description: 'afrilang test',
  ),
  BuildTarget(
    id: 'wasm32',
    label: 'wasm32',
    args: ['build-wasm-web'],
    description: 'Browser WASM pack (needs main .afr + -o)',
  ),
];

class ProjectService {
  AfrilangProject? project;

  /// Parse `afrilang.toml` text (also used by unit tests).
  AfrilangProject parseTomlText(String root, String text) => _parseToml(root, text);

  Future<AfrilangProject?> detect(String workspaceRoot) async {
    final toml = File(p.join(workspaceRoot, 'afrilang.toml'));
    if (!await toml.exists()) {
      project = null;
      return null;
    }
    final text = await toml.readAsString();
    project = _parseToml(workspaceRoot, text);
    return project;
  }

  AfrilangProject _parseToml(String root, String text) {
    String? pick(String key) {
      final re = RegExp('^\\s*$key\\s*=\\s*"([^"]*)"', multiLine: true);
      return re.firstMatch(text)?.group(1);
    }

    return AfrilangProject(
      root: root,
      name: pick('name') ?? p.basename(root),
      main: pick('main'),
      output: pick('output'),
      version: pick('version'),
      description: pick('description'),
    );
  }

  List<BuildTarget> targetsFor(AfrilangProject? proj) {
    if (proj == null) return kDefaultTargets;
    final list = List<BuildTarget>.from(kDefaultTargets);
    // Specialize wasm target with main + output dir when known.
    if (proj.main != null) {
      final outDir = p.join(proj.root, 'build', 'wasm');
      final idx = list.indexWhere((t) => t.id == 'wasm32');
      if (idx >= 0) {
        list[idx] = BuildTarget(
          id: 'wasm32',
          label: 'wasm32',
          args: ['build-wasm-web', proj.mainAbsolute!, '-o', outDir],
          description: 'WASM web pack for ${proj.main}',
        );
      }
    }
    if (proj.mainAbsolute != null) {
      list.insert(
        0,
        BuildTarget(
          id: 'check-main',
          label: 'check-main',
          args: ['check', proj.mainAbsolute!],
          description: 'Check project main',
        ),
      );
    }
    return list;
  }
}
