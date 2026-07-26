import 'package:flutter/material.dart';
import 'package:google_fonts/google_fonts.dart';

enum AfriThemeMode { dark, light, highContrast }

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

ThemeData buildAfriblockTheme(AfriThemeMode mode) {
  final brightness = mode == AfriThemeMode.light ? Brightness.light : Brightness.dark;
  final hc = mode == AfriThemeMode.highContrast;
  final bg = mode == AfriThemeMode.light
      ? const Color(0xFFF8FAFC)
      : (hc ? const Color(0xFF000000) : AfriblockColors.bg);
  final surface = mode == AfriThemeMode.light
      ? Colors.white
      : (hc ? const Color(0xFF0A0A0A) : AfriblockColors.surface);
  final onSurface = mode == AfriThemeMode.light
      ? const Color(0xFF0F172A)
      : AfriblockColors.text;

  final base = GoogleFonts.plusJakartaSansTextTheme(
    brightness == Brightness.dark ? ThemeData.dark().textTheme : ThemeData.light().textTheme,
  );

  return ThemeData(
    useMaterial3: true,
    brightness: brightness,
    scaffoldBackgroundColor: bg,
    colorScheme: ColorScheme(
      brightness: brightness,
      primary: AfriblockColors.primary,
      onPrimary: Colors.white,
      secondary: AfriblockColors.accent,
      onSecondary: Colors.black,
      error: AfriblockColors.error,
      onError: Colors.black,
      surface: surface,
      onSurface: onSurface,
    ),
    textTheme: base.apply(bodyColor: onSurface, displayColor: onSurface),
    dividerColor: hc ? Colors.white70 : AfriblockColors.border,
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
