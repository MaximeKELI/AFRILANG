import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';

/// Desktop workbench palette — AFRILANG identity, slate dark (not purple/cream).
class AfriblockColors {
  static const primary = Color(0xFF3B82F6);
  static const primaryDeep = Color(0xFF1D4ED8);
  static const accent = Color(0xFFD97706);
  static const bg = Color(0xFF0B1220);
  static const surface = Color(0xFF111827);
  static const panel = Color(0xFF0F172A);
  static const panelElevated = Color(0xFF1E293B);
  static const border = Color(0xFF334155);
  static const text = Color(0xFFE2E8F0);
  static const textMuted = Color(0xFF94A3B8);
  static const activityBar = Color(0xFF020617);
  static const tabInactive = Color(0xFF0F172A);
  static const tabActive = Color(0xFF1E293B);
  static const error = Color(0xFFF87171);
  static const warning = Color(0xFFFBBF24);
  static const success = Color(0xFF4ADE80);
}

ThemeData buildAfriblockTheme() {
  final base = GoogleFonts.plusJakartaSansTextTheme(ThemeData.dark().textTheme);
  return ThemeData(
    useMaterial3: true,
    brightness: Brightness.dark,
    scaffoldBackgroundColor: AfriblockColors.bg,
    colorScheme: const ColorScheme.dark(
      primary: AfriblockColors.primary,
      secondary: AfriblockColors.accent,
      surface: AfriblockColors.surface,
      error: AfriblockColors.error,
      onPrimary: Colors.white,
      onSecondary: Colors.black,
      onSurface: AfriblockColors.text,
      onError: Colors.black,
    ),
    textTheme: base.apply(
      bodyColor: AfriblockColors.text,
      displayColor: Colors.white,
    ),
    dividerColor: AfriblockColors.border,
    tooltipTheme: TooltipThemeData(
      waitDuration: const Duration(milliseconds: 400),
      decoration: BoxDecoration(
        color: AfriblockColors.panelElevated,
        borderRadius: BorderRadius.circular(6),
        border: Border.all(color: AfriblockColors.border),
      ),
      textStyle: GoogleFonts.plusJakartaSans(
        color: AfriblockColors.text,
        fontSize: 12,
      ),
    ),
  );
}

TextStyle afriblockMono({
  double fontSize = 13.5,
  Color color = AfriblockColors.text,
  FontWeight weight = FontWeight.w400,
  double height = 1.55,
}) {
  return GoogleFonts.jetBrainsMono(
    fontSize: fontSize,
    color: color,
    fontWeight: weight,
    height: height,
  );
}
