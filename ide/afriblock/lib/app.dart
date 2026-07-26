import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

import 'state/workbench_controller.dart';
import 'theme/afriblock_theme.dart';
import 'widgets/new_item_dialogs.dart';
import 'workbench/workbench_shell.dart';

class AfriblockApp extends StatelessWidget {
  const AfriblockApp({super.key});

  @override
  Widget build(BuildContext context) {
    return ChangeNotifierProvider(
      create: (_) => WorkbenchController()..init(),
      child: Consumer<WorkbenchController>(
        builder: (context, wb, _) {
          return MaterialApp(
            title: 'AFRIBLOCK',
            debugShowCheckedModeBanner: false,
            navigatorKey: afriblockNavigatorKey,
            scaffoldMessengerKey: afriblockScaffoldMessengerKey,
            theme: buildAfriblockTheme(wb.themeMode),
            home: const Scaffold(body: WorkbenchShell()),
          );
        },
      ),
    );
  }
}
