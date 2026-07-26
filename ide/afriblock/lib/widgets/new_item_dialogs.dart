import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

import '../editor/path_name_rules.dart';
import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';

Future<void> promptCreateFile(BuildContext context, {String? parentDir}) async {
  final wb = context.read<WorkbenchController>();
  if (wb.workspaceRoot == null) {
    ScaffoldMessenger.of(context).showSnackBar(
      const SnackBar(content: Text('Open a folder first')),
    );
    return;
  }
  final parent = parentDir ?? wb.createTargetDirectory();
  final name = await _promptName(
    context,
    title: 'New File',
    hint: 'main.afr',
    subtitle: 'in ${wb.relativePath(parent)}',
    isFolder: false,
  );
  if (name == null || !context.mounted) return;
  try {
    await wb.createFileInWorkspace(name, parentDir: parent);
  } catch (e) {
    if (context.mounted) {
      ScaffoldMessenger.of(context).showSnackBar(SnackBar(content: Text('$e')));
    }
  }
}

Future<void> promptCreateFolder(BuildContext context, {String? parentDir}) async {
  final wb = context.read<WorkbenchController>();
  if (wb.workspaceRoot == null) {
    ScaffoldMessenger.of(context).showSnackBar(
      const SnackBar(content: Text('Open a folder first')),
    );
    return;
  }
  final parent = parentDir ?? wb.createTargetDirectory();
  final name = await _promptName(
    context,
    title: 'New Folder',
    hint: 'src',
    subtitle: 'in ${wb.relativePath(parent)}',
    isFolder: true,
  );
  if (name == null || !context.mounted) return;
  try {
    await wb.createFolderInWorkspace(name, parentDir: parent);
  } catch (e) {
    if (context.mounted) {
      ScaffoldMessenger.of(context).showSnackBar(SnackBar(content: Text('$e')));
    }
  }
}

Future<String?> _promptName(
  BuildContext context, {
  required String title,
  required String hint,
  required String subtitle,
  required bool isFolder,
}) async {
  final ctrl = TextEditingController();
  String? error;

  final result = await showDialog<String>(
    context: context,
    builder: (ctx) {
      return StatefulBuilder(
        builder: (ctx, setLocal) {
          return AlertDialog(
            backgroundColor: AfriblockColors.panelElevated,
            title: Text(title),
            content: SizedBox(
              width: 360,
              child: Column(
                mainAxisSize: MainAxisSize.min,
                crossAxisAlignment: CrossAxisAlignment.stretch,
                children: [
                  Text(
                    subtitle,
                    style: afriblockMono(fontSize: 11, color: AfriblockColors.textMuted),
                  ),
                  const SizedBox(height: 12),
                  TextField(
                    controller: ctrl,
                    autofocus: true,
                    decoration: InputDecoration(
                      hintText: hint,
                      errorText: error,
                      border: const OutlineInputBorder(),
                    ),
                    onSubmitted: (_) {
                      final err = PathNameRules.validateSegment(ctrl.text, isFolder: isFolder);
                      if (err != null) {
                        setLocal(() => error = err);
                        return;
                      }
                      Navigator.pop(ctx, ctrl.text.trim());
                    },
                  ),
                ],
              ),
            ),
            actions: [
              TextButton(onPressed: () => Navigator.pop(ctx), child: const Text('Cancel')),
              FilledButton(
                onPressed: () {
                  final err = PathNameRules.validateSegment(ctrl.text, isFolder: isFolder);
                  if (err != null) {
                    setLocal(() => error = err);
                    return;
                  }
                  Navigator.pop(ctx, ctrl.text.trim());
                },
                style: FilledButton.styleFrom(backgroundColor: AfriblockColors.primaryDeep),
                child: const Text('Create'),
              ),
            ],
          );
        },
      );
    },
  );
  ctrl.dispose();
  return result;
}

/// Compact toolbar for Explorer header actions.
class ExplorerCreateBar extends StatelessWidget {
  const ExplorerCreateBar({super.key});

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.fromLTRB(8, 0, 8, 4),
      child: Row(
        children: [
          Text(
            'Workspace',
            style: GoogleFonts.plusJakartaSans(
              fontSize: 11,
              color: AfriblockColors.textMuted,
              fontWeight: FontWeight.w600,
            ),
          ),
          const Spacer(),
          IconButton(
            tooltip: 'New File',
            iconSize: 18,
            visualDensity: VisualDensity.compact,
            onPressed: () => promptCreateFile(context),
            icon: const Icon(Icons.note_add_outlined),
          ),
          IconButton(
            tooltip: 'New Folder',
            iconSize: 18,
            visualDensity: VisualDensity.compact,
            onPressed: () => promptCreateFolder(context),
            icon: const Icon(Icons.create_new_folder_outlined),
          ),
          IconButton(
            tooltip: 'Refresh',
            iconSize: 18,
            visualDensity: VisualDensity.compact,
            onPressed: () => context.read<WorkbenchController>().refreshExplorer(),
            icon: const Icon(Icons.refresh),
          ),
        ],
      ),
    );
  }
}
