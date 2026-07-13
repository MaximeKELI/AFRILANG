import 'package:flutter/material.dart';
import 'package:provider/provider.dart';

import 'screens/shell_screen.dart';
import 'state/app_state.dart';
import 'theme/afrilang_theme.dart';

void main() {
  WidgetsFlutterBinding.ensureInitialized();
  runApp(const AfrilangApp());
}

class AfrilangApp extends StatelessWidget {
  const AfrilangApp({super.key});

  @override
  Widget build(BuildContext context) {
    return ChangeNotifierProvider(
      create: (_) => AppState()..init(),
      child: Consumer<AppState>(
        builder: (context, app, _) {
          return MaterialApp(
            title: 'AFRILANG',
            debugShowCheckedModeBanner: false,
            theme: buildAfrTheme(),
            darkTheme: buildAfrTheme(brightness: Brightness.dark),
            themeMode: app.darkMode ? ThemeMode.dark : ThemeMode.light,
            home: const ShellScreen(),
          );
        },
      ),
    );
  }
}
