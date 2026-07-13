import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';

/// Couleurs & typo alignées sur `web/static/css/app.css`.
class AfrColors {
  static const primary = Color(0xFF1D4ED8);
  static const primaryDark = Color(0xFF1E3A8A);
  static const accent = Color(0xFFD97706);
  static const bg = Color(0xFFFFFFFF);
  static const bgSubtle = Color(0xFFF8FAFC);
  static const text = Color(0xFF0F172A);
  static const textSecondary = Color(0xFF475569);
  static const border = Color(0xFFE2E8F0);
  static const codeBg = Color(0xFF0F172A);
  static const codePanelHeader = Color(0xFF1E293B);
}

ThemeData buildAfrTheme({Brightness brightness = Brightness.light}) {
  final isDark = brightness == Brightness.dark;
  final base = GoogleFonts.plusJakartaSansTextTheme(
    isDark ? ThemeData.dark().textTheme : ThemeData.light().textTheme,
  );
  final colorScheme = ColorScheme.fromSeed(
    seedColor: AfrColors.primary,
    brightness: brightness,
    primary: isDark ? const Color(0xFF60A5FA) : AfrColors.primary,
    surface: isDark ? const Color(0xFF0F172A) : AfrColors.bg,
  );

  return ThemeData(
    useMaterial3: true,
    colorScheme: colorScheme,
    scaffoldBackgroundColor: isDark ? const Color(0xFF0B1220) : AfrColors.bg,
    textTheme: base.apply(
      bodyColor: isDark ? const Color(0xFFE2E8F0) : AfrColors.text,
      displayColor: isDark ? const Color(0xFFF8FAFC) : AfrColors.text,
    ),
    appBarTheme: AppBarTheme(
      centerTitle: false,
      elevation: 0,
      scrolledUnderElevation: 0.5,
      backgroundColor: isDark ? const Color(0xFF0F172A) : Colors.white,
      foregroundColor: isDark ? Colors.white : AfrColors.text,
      titleTextStyle: GoogleFonts.plusJakartaSans(
        fontWeight: FontWeight.w700,
        fontSize: 18,
        color: isDark ? Colors.white : AfrColors.text,
      ),
    ),
    bottomNavigationBarTheme: BottomNavigationBarThemeData(
      selectedItemColor: AfrColors.primary,
      unselectedItemColor: AfrColors.textSecondary,
      type: BottomNavigationBarType.fixed,
      backgroundColor: isDark ? const Color(0xFF0F172A) : Colors.white,
      elevation: 8,
    ),
    elevatedButtonTheme: ElevatedButtonThemeData(
      style: ElevatedButton.styleFrom(
        backgroundColor: AfrColors.primary,
        foregroundColor: Colors.white,
        elevation: 0,
        padding: const EdgeInsets.symmetric(horizontal: 22, vertical: 14),
        shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(10)),
        textStyle: GoogleFonts.plusJakartaSans(fontWeight: FontWeight.w600),
      ),
    ),
    outlinedButtonTheme: OutlinedButtonThemeData(
      style: OutlinedButton.styleFrom(
        foregroundColor: AfrColors.primary,
        side: const BorderSide(color: AfrColors.primary, width: 1.5),
        padding: const EdgeInsets.symmetric(horizontal: 22, vertical: 14),
        shape: RoundedRectangleBorder(borderRadius: BorderRadius.circular(10)),
        textStyle: GoogleFonts.plusJakartaSans(fontWeight: FontWeight.w600),
      ),
    ),
    cardTheme: CardThemeData(
      elevation: 0,
      color: isDark ? const Color(0xFF1E293B) : Colors.white,
      shape: RoundedRectangleBorder(
        borderRadius: BorderRadius.circular(14),
        side: BorderSide(color: isDark ? const Color(0xFF334155) : AfrColors.border),
      ),
    ),
    inputDecorationTheme: InputDecorationTheme(
      filled: true,
      fillColor: isDark ? const Color(0xFF1E293B) : AfrColors.bgSubtle,
      border: OutlineInputBorder(
        borderRadius: BorderRadius.circular(12),
        borderSide: const BorderSide(color: AfrColors.border),
      ),
      enabledBorder: OutlineInputBorder(
        borderRadius: BorderRadius.circular(12),
        borderSide: const BorderSide(color: AfrColors.border),
      ),
      focusedBorder: OutlineInputBorder(
        borderRadius: BorderRadius.circular(12),
        borderSide: const BorderSide(color: AfrColors.primary, width: 2),
      ),
    ),
    dividerColor: AfrColors.border,
  );
}

TextStyle afrMono({
  double fontSize = 13,
  Color color = const Color(0xFFE2E8F0),
  FontWeight weight = FontWeight.w400,
}) {
  return GoogleFonts.jetBrainsMono(
    fontSize: fontSize,
    color: color,
    fontWeight: weight,
    height: 1.55,
  );
}
