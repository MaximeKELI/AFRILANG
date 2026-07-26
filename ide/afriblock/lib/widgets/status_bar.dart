import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';
import 'package:provider/provider.dart';

import '../state/workbench_controller.dart';
import '../theme/afriblock_theme.dart';

class StatusBar extends StatelessWidget {
  const StatusBar({super.key});

  @override
  Widget build(BuildContext context) {
    final wb = context.watch<WorkbenchController>();
    final tab = wb.activeTab;
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
                child: CircularProgressIndicator(
                  strokeWidth: 1.5,
                  color: Colors.white,
                ),
              ),
            ),
          Expanded(
            child: Text(
              wb.statusMessage ?? '',
              overflow: TextOverflow.ellipsis,
              style: GoogleFonts.plusJakartaSans(
                fontSize: 11.5,
                color: Colors.white,
              ),
            ),
          ),
          if (wb.problems.isNotEmpty)
            Padding(
              padding: const EdgeInsets.only(right: 12),
              child: InkWell(
                onTap: () => wb.setBottomTab(BottomTab.problems),
                child: Text(
                  '${wb.problems.length} problems',
                  style: GoogleFonts.plusJakartaSans(
                    fontSize: 11.5,
                    color: Colors.white70,
                  ),
                ),
              ),
            ),
          Text(
            tab == null
                ? 'AFRIBLOCK'
                : (tab.name.endsWith('.afr') ? 'AFRILANG' : 'Plain Text'),
            style: GoogleFonts.plusJakartaSans(
              fontSize: 11.5,
              color: Colors.white70,
            ),
          ),
          const SizedBox(width: 12),
          Text(
            'UTF-8',
            style: GoogleFonts.plusJakartaSans(
              fontSize: 11.5,
              color: Colors.white70,
            ),
          ),
        ],
      ),
    );
  }
}
