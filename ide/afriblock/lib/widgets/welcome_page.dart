import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';

class WelcomePage extends StatelessWidget {
  const WelcomePage({super.key});

  @override
  Widget build(BuildContext context) {
    final wb = context.watch<WorkbenchController>();
    final recent = wb.settings.recentFolders;

    return Container(
      decoration: const BoxDecoration(
        gradient: LinearGradient(
          begin: Alignment.topLeft,
          end: Alignment.bottomRight,
          colors: [
            Color(0xFF0B1220),
            Color(0xFF111827),
            Color(0xFF0F172A),
          ],
        ),
      ),
      child: Center(
        child: ConstrainedBox(
          constraints: const BoxConstraints(maxWidth: 640),
          child: SingleChildScrollView(
            padding: const EdgeInsets.all(32),
            child: Column(
              mainAxisAlignment: MainAxisAlignment.center,
              crossAxisAlignment: CrossAxisAlignment.start,
              children: [
                Row(
                  children: [
                    Image.asset(
                      'assets/brand/app_icon_transparent.png',
                      width: 56,
                      height: 56,
                      errorBuilder: (_, _, _) => const Icon(
                        Icons.grid_view_rounded,
                        size: 48,
                        color: AfriblockColors.primary,
                      ),
                    ),
                    const SizedBox(width: 16),
                    Expanded(
                      child: Column(
                        crossAxisAlignment: CrossAxisAlignment.start,
                        children: [
                          Text(
                            'AFRIBLOCK',
                            style: GoogleFonts.plusJakartaSans(
                              fontSize: 36,
                              fontWeight: FontWeight.w800,
                              letterSpacing: -0.5,
                              color: Colors.white,
                            ),
                          ),
                          Text(
                            'Desktop IDE for AFRILANG',
                            style: GoogleFonts.plusJakartaSans(
                              fontSize: 15,
                              color: AfriblockColors.textMuted,
                            ),
                          ),
                        ],
                      ),
                    ),
                  ],
                ),
                const SizedBox(height: 28),
                Text(
                  'Open a folder to start editing `.afr` sources. Run and Check use the local `afrilang` binary.',
                  style: GoogleFonts.plusJakartaSans(
                    fontSize: 14.5,
                    height: 1.45,
                    color: AfriblockColors.text,
                  ),
                ),
                const SizedBox(height: 24),
                Wrap(
                  spacing: 12,
                  runSpacing: 12,
                  children: [
                    FilledButton.icon(
                      onPressed: () => wb.openFolder(),
                      icon: const Icon(Icons.folder_open),
                      label: const Text('Open Folder'),
                      style: FilledButton.styleFrom(
                        backgroundColor: AfriblockColors.primaryDeep,
                        foregroundColor: Colors.white,
                        padding: const EdgeInsets.symmetric(
                          horizontal: 20,
                          vertical: 14,
                        ),
                      ),
                    ),
                    OutlinedButton.icon(
                      onPressed: () => wb.showOverlay(OverlayMode.commandPalette),
                      icon: const Icon(Icons.terminal),
                      label: const Text('Command Palette'),
                      style: OutlinedButton.styleFrom(
                        foregroundColor: AfriblockColors.text,
                        side: const BorderSide(color: AfriblockColors.border),
                        padding: const EdgeInsets.symmetric(
                          horizontal: 20,
                          vertical: 14,
                        ),
                      ),
                    ),
                  ],
                ),
                if (recent.isNotEmpty) ...[
                  const SizedBox(height: 36),
                  Text(
                    'Recent',
                    style: GoogleFonts.plusJakartaSans(
                      fontSize: 12,
                      fontWeight: FontWeight.w700,
                      letterSpacing: 1,
                      color: AfriblockColors.textMuted,
                    ),
                  ),
                  const SizedBox(height: 10),
                  ...recent.take(5).map(
                    (path) => InkWell(
                      onTap: () => wb.openFolder(path),
                      child: Padding(
                        padding: const EdgeInsets.symmetric(vertical: 6),
                        child: Row(
                          children: [
                            const Icon(
                              Icons.history,
                              size: 16,
                              color: AfriblockColors.textMuted,
                            ),
                            const SizedBox(width: 10),
                            Expanded(
                              child: Text(
                                path,
                                overflow: TextOverflow.ellipsis,
                                style: afriblockMono(
                                  fontSize: 12.5,
                                  color: AfriblockColors.primary,
                                ),
                              ),
                            ),
                          ],
                        ),
                      ),
                    ),
                  ),
                ],
              ],
            ),
          ),
        ),
      ),
    );
  }
}
