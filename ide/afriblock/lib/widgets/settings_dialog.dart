import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';

Future<void> showAfriblockSettings(BuildContext context) async {
  final wb = context.read<WorkbenchController>();
  final pathCtrl = TextEditingController(text: wb.settings.afrilangPath ?? '');
  final aiBaseCtrl = TextEditingController(text: wb.settings.aiBaseUrl);
  final aiKeyCtrl = TextEditingController(text: wb.settings.aiApiKey);
  final aiModelCtrl = TextEditingController(text: wb.settings.aiModel);
  var formatOnSave = wb.settings.formatOnSave;
  var lspTrace = wb.settings.lspTrace;
  var aiEnabled = wb.settings.aiEnabled;
  var aiInline = wb.settings.aiInlineSuggest;
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
              child: SingleChildScrollView(
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
                    const SizedBox(height: 16),
                    Text('AI Assist', style: GoogleFonts.plusJakartaSans(fontWeight: FontWeight.w700)),
                    const SizedBox(height: 8),
                    SwitchListTile(
                      contentPadding: EdgeInsets.zero,
                      title: const Text('Enable AI'),
                      subtitle: const Text('OpenAI-compatible API + local fallback'),
                      value: aiEnabled,
                      onChanged: (v) => setLocal(() => aiEnabled = v),
                    ),
                    SwitchListTile(
                      contentPadding: EdgeInsets.zero,
                      title: const Text('Inline suggestions (ghost text)'),
                      value: aiInline,
                      onChanged: (v) => setLocal(() => aiInline = v),
                    ),
                    TextField(
                      controller: aiBaseCtrl,
                      decoration: const InputDecoration(
                        labelText: 'Base URL',
                        hintText: 'http://127.0.0.1:11434/v1',
                        border: OutlineInputBorder(),
                      ),
                      style: afriblockMono(fontSize: 12),
                    ),
                    const SizedBox(height: 8),
                    TextField(
                      controller: aiModelCtrl,
                      decoration: const InputDecoration(
                        labelText: 'Model',
                        hintText: 'afrilang-local  |  llama3.2',
                        helperText:
                            'afrilang-local = IA interne offline ; sinon API OpenAI-compatible',
                        border: OutlineInputBorder(),
                      ),
                      style: afriblockMono(fontSize: 12),
                    ),
                    const SizedBox(height: 8),
                    TextField(
                      controller: aiKeyCtrl,
                      obscureText: true,
                      decoration: const InputDecoration(
                        labelText: 'API key (optional)',
                        hintText: 'or AFRIBLOCK_AI_API_KEY env',
                        border: OutlineInputBorder(),
                      ),
                      style: afriblockMono(fontSize: 12),
                    ),
                  ],
                ),
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
                  wb.settings.aiEnabled = aiEnabled;
                  wb.settings.aiInlineSuggest = aiInline;
                  wb.settings.aiBaseUrl = aiBaseCtrl.text.trim().isEmpty
                      ? 'http://127.0.0.1:11434/v1'
                      : aiBaseCtrl.text.trim();
                  wb.settings.aiApiKey = aiKeyCtrl.text;
                  wb.settings.aiModel =
                      aiModelCtrl.text.trim().isEmpty
                          ? 'afrilang-local'
                          : aiModelCtrl.text.trim();
                  await wb.settings.saveAiSettings();
                  wb.syncAiConfig();
                  await wb.refreshToolchain();
                  wb.refresh();
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
