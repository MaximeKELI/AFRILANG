import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

import 'state/workbench_controller.dart';
import 'theme/afriblock_theme.dart';
import 'workbench/workbench_shell.dart';

class AfriblockApp extends StatelessWidget {
  const AfriblockApp({super.key});

  @override
  Widget build(BuildContext context) {
    return ChangeNotifierProvider(
      create: (_) => WorkbenchController()..init(),
      child: MaterialApp(
        title: 'AFRIBLOCK',
        debugShowCheckedModeBanner: false,
        theme: buildAfriblockTheme(),
        home: const Scaffold(
          body: WorkbenchShell(),
        ),
      ),
    );
  }
}
