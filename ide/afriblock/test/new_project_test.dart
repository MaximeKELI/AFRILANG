import 'dart:io';

import 'package:flutter_test/flutter_test.dart';
import 'package:path/path.dart' as p;
import 'package:afriblock/services/file_service.dart';
import 'package:afriblock/state/workbench_controller.dart';

void main() {
  TestWidgetsFlutterBinding.ensureInitialized();

  test('createNewProject writes toml and main then opens', () async {
    final tmp = await Directory.systemTemp.createTemp('afriblock_proj_');
    addTearDown(() async {
      if (await tmp.exists()) await tmp.delete(recursive: true);
    });

    final wb = WorkbenchController(fileService: FileService());
    // Skip SharedPreferences-heavy init; exercise filesystem create path.
    final root = await wb.createNewProject(name: 'demo_app', parentDir: tmp.path);
    expect(await File(p.join(root, 'afrilang.toml')).exists(), isTrue);
    expect(await File(p.join(root, 'src', 'main.afr')).exists(), isTrue);
    expect(wb.workspaceRoot, root);
    expect(wb.projects.project?.name, 'demo_app');
  });
}
