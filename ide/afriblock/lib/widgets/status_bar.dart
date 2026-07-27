import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

import '../editor/text_ops.dart';
import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';

class StatusBar extends StatelessWidget {
  const StatusBar({super.key});

  @override
  Widget build(BuildContext context) {
    final wb = context.watch<WorkbenchController>();
    final tab = wb.activeTab;
    String? blameLabel;
    if (wb.blameEnabled && tab != null && wb.blameLines.isNotEmpty) {
      final line = TextOps.lineColAt(tab.content, wb.editorCaret).line + 1;
      for (final b in wb.blameLines) {
        if (b.line == line) {
          final hash = b.hash.length > 7 ? b.hash.substring(0, 7) : b.hash;
          blameLabel = '${b.author} $hash';
          break;
        }
      }
    }
    return Container(
      height: 24,
      color: AfriblockColors.primaryDeep,
      padding: const EdgeInsets.symmetric(horizontal: 10),
      child: Row(
        children: [
          if (wb.busy)
            const Padding(
              padding: EdgeInsets.only(right: 8),
              child: SizedBox(
                width: 12,
                height: 12,
                child: CircularProgressIndicator(strokeWidth: 1.5, color: Colors.white),
              ),
            ),
          Expanded(
            child: Text(
              wb.statusMessage ?? '',
              overflow: TextOverflow.ellipsis,
              style: GoogleFonts.plusJakartaSans(fontSize: 11.5, color: Colors.white),
            ),
          ),
          if (blameLabel != null)
            Padding(
              padding: const EdgeInsets.only(right: 12),
              child: Text(
                blameLabel,
                style: GoogleFonts.plusJakartaSans(fontSize: 11.5, color: Colors.white70),
              ),
            ),
          if (wb.git.branch != null)
            Padding(
              padding: const EdgeInsets.only(right: 12),
              child: Text(' ${wb.git.branch}',
                  style: GoogleFonts.plusJakartaSans(fontSize: 11.5, color: Colors.white70)),
            ),
          if (wb.problems.isNotEmpty)
            Padding(
              padding: const EdgeInsets.only(right: 12),
              child: InkWell(
                onTap: () => wb.setBottomTab(BottomTab.problems),
                child: Text('${wb.problems.length} problems',
                    style: GoogleFonts.plusJakartaSans(fontSize: 11.5, color: Colors.white70)),
              ),
            ),
          Text(
            'target:${wb.activeTarget.label}',
            style: GoogleFonts.plusJakartaSans(fontSize: 11.5, color: Colors.white70),
          ),
          const SizedBox(width: 12),
          Text(
            wb.lspState,
            style: GoogleFonts.plusJakartaSans(fontSize: 11.5, color: Colors.white70),
          ),
          const SizedBox(width: 12),
          InkWell(
            onTap: () async {
              if (!wb.settings.aiEnabled ||
                  wb.settings.aiModel == 'llama3.2' ||
                  wb.settings.aiModel == 'llama3') {
                await wb.enableLocalAi();
                wb.toggleAiChat();
              } else {
                wb.toggleAiChat();
              }
            },
            child: Text(
              wb.aiStatusLabel,
              style: GoogleFonts.plusJakartaSans(
                fontSize: 11.5,
                color: wb.ai.lastError != null
                    ? const Color(0xFFFCA5A5)
                    : (wb.settings.aiEnabled ? Colors.white : Colors.white70),
              ),
            ),
          ),
          const SizedBox(width: 12),
          Text(
            tab == null
                ? 'AFRIBLOCK'
                : (tab.name.endsWith('.afr') ? 'AFRILANG' : 'Plain Text'),
            style: GoogleFonts.plusJakartaSans(fontSize: 11.5, color: Colors.white70),
          ),
        ],
      ),
    );
  }
}
