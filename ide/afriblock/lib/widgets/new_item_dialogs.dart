// Dialog helpers use a global NavigatorKey; context-after-await is intentional.
// ignore_for_file: use_build_context_synchronously

import 'dart:io';

import 'package:file_picker/file_picker.dart';
import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:path/path.dart' as p;
import 'package:path_provider/path_provider.dart';
import 'package:provider/provider.dart';

import '../editor/path_name_rules.dart';
import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';

/// Root navigator — dialogs stay reliable after popup menus close.
final afriblockNavigatorKey = GlobalKey<NavigatorState>();
final afriblockScaffoldMessengerKey = GlobalKey<ScaffoldMessengerState>();

BuildContext? get _navContext => afriblockNavigatorKey.currentContext;

void _toast(String message) {
  final messenger = afriblockScaffoldMessengerKey.currentState;
  messenger?.showSnackBar(SnackBar(content: Text(message)));
}

Future<String> defaultProjectsRoot() async {
  try {
    final docs = await getApplicationDocumentsDirectory();
    final dir = Directory(p.join(docs.path, 'AFRIBLOCK_Projects'));
    if (!await dir.exists()) await dir.create(recursive: true);
    return dir.path;
  } catch (_) {
    final home = Platform.environment['HOME'] ??
        Platform.environment['USERPROFILE'] ??
        Directory.systemTemp.path;
    final dir = Directory(p.join(home, 'AFRIBLOCK_Projects'));
    if (!await dir.exists()) await dir.create(recursive: true);
    return dir.path;
  }
}

/// Creates a full AFRILANG project on disk and opens it in the IDE.
Future<void> promptNewProject([BuildContext? context]) async {
  final ctx = _navContext ?? context;
  if (ctx == null) return;
  final wb = Provider.of<WorkbenchController>(ctx, listen: false);
  final projectsRoot = await defaultProjectsRoot();
  final nameCtrl = TextEditingController(text: 'mon_projet');
  final parentCtrl = TextEditingController(text: projectsRoot);
  String? error;

  final dialogCtx = _navContext ?? ctx;
  final ok = await showDialog<bool>(
    context: dialogCtx,
    builder: (ctx) {
      return StatefulBuilder(
        builder: (ctx, setLocal) {
          return AlertDialog(
            backgroundColor: AfriblockColors.panelElevated,
            title: const Text('Nouveau projet AFRILANG'),
            content: SizedBox(
              width: 440,
              child: Column(
                mainAxisSize: MainAxisSize.min,
                crossAxisAlignment: CrossAxisAlignment.stretch,
                children: [
                  Text(
                    'Crée un dossier, afrilang.toml et src/main.afr — sans passer par le gestionnaire.',
                    style: GoogleFonts.plusJakartaSans(
                      fontSize: 13,
                      color: AfriblockColors.textMuted,
                    ),
                  ),
                  const SizedBox(height: 14),
                  TextField(
                    controller: nameCtrl,
                    autofocus: true,
                    decoration: InputDecoration(
                      labelText: 'Nom du projet',
                      errorText: error,
                      border: const OutlineInputBorder(),
                    ),
                  ),
                  const SizedBox(height: 12),
                  TextField(
                    controller: parentCtrl,
                    decoration: const InputDecoration(
                      labelText: 'Dossier parent (chemin)',
                      border: OutlineInputBorder(),
                    ),
                  ),
                  const SizedBox(height: 8),
                  Align(
                    alignment: Alignment.centerLeft,
                    child: TextButton.icon(
                      onPressed: () async {
                        final picked = await FilePicker.platform.getDirectoryPath(
                          dialogTitle: 'Choisir le dossier parent',
                        );
                        if (picked != null) {
                          setLocal(() => parentCtrl.text = picked);
                        }
                      },
                      icon: const Icon(Icons.folder_open, size: 18),
                      label: const Text('Parcourir… (optionnel)'),
                    ),
                  ),
                ],
              ),
            ),
            actions: [
              TextButton(onPressed: () => Navigator.pop(ctx, false), child: const Text('Annuler')),
              FilledButton(
                style: FilledButton.styleFrom(backgroundColor: AfriblockColors.primaryDeep),
                onPressed: () {
                  final err = PathNameRules.validateSegment(nameCtrl.text, isFolder: true);
                  if (err != null) {
                    setLocal(() => error = err);
                    return;
                  }
                  if (parentCtrl.text.trim().isEmpty) {
                    setLocal(() => error = 'Dossier parent requis');
                    return;
                  }
                  Navigator.pop(ctx, true);
                },
                child: const Text('Créer'),
              ),
            ],
          );
        },
      );
    },
  );

  if (ok != true) {
    nameCtrl.dispose();
    parentCtrl.dispose();
    return;
  }

  try {
    final root = await wb.createNewProject(
      name: nameCtrl.text.trim(),
      parentDir: parentCtrl.text.trim(),
    );
    _toast('Projet créé : $root');
  } catch (e) {
    _toast('Échec création projet : $e');
  } finally {
    nameCtrl.dispose();
    parentCtrl.dispose();
  }
}

Future<void> promptCreateFile(BuildContext context, {String? parentDir}) async {
  final wb = context.read<WorkbenchController>();
  final ctx = _navContext ?? context;

  if (wb.workspaceRoot == null) {
    final choice = await showDialog<String>(
      context: ctx,
      builder: (dCtx) => AlertDialog(
        backgroundColor: AfriblockColors.panelElevated,
        title: const Text('Aucun projet ouvert'),
        content: const Text(
          'Créez un projet maintenant, ou un fichier temporaire (à enregistrer ensuite).',
        ),
        actions: [
          TextButton(onPressed: () => Navigator.pop(dCtx), child: const Text('Annuler')),
          TextButton(
            onPressed: () => Navigator.pop(dCtx, 'untitled'),
            child: const Text('Fichier temporaire'),
          ),
          FilledButton(
            onPressed: () => Navigator.pop(dCtx, 'project'),
            child: const Text('Nouveau projet'),
          ),
        ],
      ),
    );
    if (choice == 'project') {
      await promptNewProject();
      if (wb.workspaceRoot == null) return;
    } else if (choice == 'untitled') {
      wb.openUntitledBuffer();
      return;
    } else {
      return;
    }
  }

  final parent = parentDir ?? wb.createTargetDirectory();
  final nav = _navContext;
  if (nav == null) return;
  final name = await _promptName(
    nav,
    title: 'Nouveau fichier',
    hint: 'main.afr',
    subtitle: 'dans ${wb.relativePath(parent)}',
    isFolder: false,
  );
  if (name == null) return;
  try {
    await wb.createFileInWorkspace(name, parentDir: parent);
    _toast('Fichier créé');
  } catch (e) {
    _toast('$e');
  }
}

Future<void> promptCreateFolder(BuildContext context, {String? parentDir}) async {
  final wb = context.read<WorkbenchController>();
  final ctx = _navContext ?? context;

  if (wb.workspaceRoot == null) {
    final go = await showDialog<bool>(
      context: ctx,
      builder: (dCtx) => AlertDialog(
        backgroundColor: AfriblockColors.panelElevated,
        title: const Text('Aucun projet ouvert'),
        content: const Text('Il faut d’abord créer ou ouvrir un projet pour y ajouter un dossier.'),
        actions: [
          TextButton(onPressed: () => Navigator.pop(dCtx, false), child: const Text('Annuler')),
          FilledButton(
            onPressed: () => Navigator.pop(dCtx, true),
            child: const Text('Nouveau projet'),
          ),
        ],
      ),
    );
    if (go == true) {
      await promptNewProject();
      if (wb.workspaceRoot == null) return;
    } else {
      return;
    }
  }

  final parent = parentDir ?? wb.createTargetDirectory();
  final nav = _navContext;
  if (nav == null) return;
  final name = await _promptName(
    nav,
    title: 'Nouveau dossier',
    hint: 'src',
    subtitle: 'dans ${wb.relativePath(parent)}',
    isFolder: true,
  );
  if (name == null) return;
  try {
    await wb.createFolderInWorkspace(name, parentDir: parent);
    _toast('Dossier créé');
  } catch (e) {
    _toast('$e');
  }
}

/// Open folder by picker OR by typing an absolute path (Linux-friendly).
Future<void> promptOpenFolder(BuildContext context) async {
  final wb = context.read<WorkbenchController>();
  final ctx = _navContext ?? context;
  final pathCtrl = TextEditingController();

  final action = await showDialog<String>(
    context: ctx,
    builder: (dCtx) => AlertDialog(
      backgroundColor: AfriblockColors.panelElevated,
      title: const Text('Ouvrir un dossier'),
      content: SizedBox(
        width: 420,
        child: Column(
          mainAxisSize: MainAxisSize.min,
          children: [
            const Text('Choisissez via le sélecteur système, ou collez un chemin absolu.'),
            const SizedBox(height: 12),
            TextField(
              controller: pathCtrl,
              decoration: const InputDecoration(
                labelText: 'Chemin',
                hintText: '/home/…/mon_projet',
                border: OutlineInputBorder(),
              ),
            ),
          ],
        ),
      ),
      actions: [
        TextButton(onPressed: () => Navigator.pop(dCtx), child: const Text('Annuler')),
        TextButton(
          onPressed: () => Navigator.pop(dCtx, 'browse'),
          child: const Text('Parcourir…'),
        ),
        FilledButton(
          onPressed: () => Navigator.pop(dCtx, 'path'),
          child: const Text('Ouvrir'),
        ),
      ],
    ),
  );

  try {
    if (action == 'browse') {
      await wb.openFolder();
    } else if (action == 'path') {
      final path = pathCtrl.text.trim();
      if (path.isEmpty) {
        _toast('Chemin vide');
      } else {
        await wb.openFolder(path);
      }
    }
  } finally {
    pathCtrl.dispose();
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
              TextButton(onPressed: () => Navigator.pop(ctx), child: const Text('Annuler')),
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
                child: const Text('Créer'),
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

/// Always-visible create actions (title / build toolbar).
class CreateActionsRow extends StatelessWidget {
  const CreateActionsRow({super.key, this.compact = false});

  final bool compact;

  @override
  Widget build(BuildContext context) {
    Widget btn({
      required IconData icon,
      required String tip,
      required VoidCallback onPressed,
      Color? color,
    }) {
      return IconButton(
        tooltip: tip,
        iconSize: compact ? 18 : 20,
        visualDensity: VisualDensity.compact,
        color: color,
        onPressed: onPressed,
        icon: Icon(icon),
      );
    }

    return Row(
      mainAxisSize: MainAxisSize.min,
      children: [
        btn(
          icon: Icons.create_new_folder,
          tip: 'Nouveau projet',
          color: AfriblockColors.accent,
          onPressed: () => promptNewProject(context),
        ),
        btn(
          icon: Icons.note_add_outlined,
          tip: 'Nouveau fichier',
          onPressed: () => promptCreateFile(context),
        ),
        btn(
          icon: Icons.folder_outlined,
          tip: 'Nouveau dossier',
          onPressed: () => promptCreateFolder(context),
        ),
        btn(
          icon: Icons.folder_open,
          tip: 'Ouvrir un dossier',
          onPressed: () => promptOpenFolder(context),
        ),
      ],
    );
  }
}

class ExplorerCreateBar extends StatelessWidget {
  const ExplorerCreateBar({super.key});

  @override
  Widget build(BuildContext context) {
    return Padding(
      padding: const EdgeInsets.fromLTRB(8, 4, 4, 4),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          Text(
            'CRÉER',
            style: GoogleFonts.plusJakartaSans(
              fontSize: 10,
              letterSpacing: 1,
              color: AfriblockColors.textMuted,
              fontWeight: FontWeight.w700,
            ),
          ),
          const SizedBox(height: 4),
          Wrap(
            spacing: 4,
            runSpacing: 4,
            children: [
              _ChipBtn(
                icon: Icons.rocket_launch_outlined,
                label: 'Projet',
                onTap: () => promptNewProject(context),
              ),
              _ChipBtn(
                icon: Icons.note_add_outlined,
                label: 'Fichier',
                onTap: () => promptCreateFile(context),
              ),
              _ChipBtn(
                icon: Icons.create_new_folder_outlined,
                label: 'Dossier',
                onTap: () => promptCreateFolder(context),
              ),
              _ChipBtn(
                icon: Icons.refresh,
                label: 'Refresh',
                onTap: () => context.read<WorkbenchController>().refreshExplorer(),
              ),
            ],
          ),
        ],
      ),
    );
  }
}

class _ChipBtn extends StatelessWidget {
  const _ChipBtn({required this.icon, required this.label, required this.onTap});
  final IconData icon;
  final String label;
  final VoidCallback onTap;

  @override
  Widget build(BuildContext context) {
    return Material(
      color: AfriblockColors.panelElevated,
      borderRadius: BorderRadius.circular(6),
      child: InkWell(
        onTap: onTap,
        borderRadius: BorderRadius.circular(6),
        child: Padding(
          padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 6),
          child: Row(
            mainAxisSize: MainAxisSize.min,
            children: [
              Icon(icon, size: 14, color: AfriblockColors.primary),
              const SizedBox(width: 4),
              Text(label, style: GoogleFonts.plusJakartaSans(fontSize: 12)),
            ],
          ),
        ),
      ),
    );
  }
}
