import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';

Future<void> showAfriblockSettings(BuildContext context) async {
  final wb = context.read<WorkbenchController>();
  final pathCtrl = TextEditingController(text: wb.settings.afrilangPath ?? '');
  var formatOnSave = wb.settings.formatOnSave;
  var lspTrace = wb.settings.lspTrace;
  final resolved = await wb.settings.resolveAfrilangBinary();

  if (!context.mounted) return;
  await showDialog<void>(
    context: context,
    builder: (ctx) {
      return StatefulBuilder(
        builder: (ctx, setLocal) {
          return AlertDialog(
            backgroundColor: AfriblockColors.panelElevated,
            title: const Text('AFRIBLOCK Settings'),
            content: SizedBox(
              width: 480,
              child: Column(
                mainAxisSize: MainAxisSize.min,
                crossAxisAlignment: CrossAxisAlignment.stretch,
                children: [
                  Text('Toolchain', style: GoogleFonts.plusJakartaSans(fontWeight: FontWeight.w700)),
                  const SizedBox(height: 8),
                  TextField(
                    controller: pathCtrl,
                    decoration: const InputDecoration(
                      labelText: 'afrilang path (optional)',
                      hintText: '/path/to/afrilang',
                      border: OutlineInputBorder(),
                    ),
                    style: afriblockMono(fontSize: 12),
                  ),
                  const SizedBox(height: 8),
                  Text(
                    'Resolved: ${resolved ?? "(not found)"}',
                    style: afriblockMono(fontSize: 11, color: AfriblockColors.textMuted),
                  ),
                  if (wb.toolchainVersion != null)
                    Text(
                      wb.toolchainVersion!,
                      style: afriblockMono(fontSize: 11, color: AfriblockColors.success),
                    ),
                  const SizedBox(height: 16),
                  SwitchListTile(
                    contentPadding: EdgeInsets.zero,
                    title: const Text('Format on Save (afrilang fmt -w)'),
                    value: formatOnSave,
                    onChanged: (v) => setLocal(() => formatOnSave = v),
                  ),
                  SwitchListTile(
                    contentPadding: EdgeInsets.zero,
                    title: const Text('LSP trace in Output'),
                    value: lspTrace,
                    onChanged: (v) => setLocal(() => lspTrace = v),
                  ),
                ],
              ),
            ),
            actions: [
              TextButton(onPressed: () => Navigator.pop(ctx), child: const Text('Cancel')),
              FilledButton(
                onPressed: () async {
                  await wb.settings.setAfrilangPath(pathCtrl.text.trim());
                  wb.settings.formatOnSave = formatOnSave;
                  wb.settings.lspTrace = lspTrace;
                  await wb.settings.saveFlags();
                  await wb.refreshToolchain();
                  if (ctx.mounted) Navigator.pop(ctx);
                },
                child: const Text('Save'),
              ),
            ],
          );
        },
      );
    },
  );
}
