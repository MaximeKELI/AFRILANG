import 'package:flutter/material.dart';
import 'package:shared_preferences/shared_preferences.dart';

import '../services/api_client.dart';

class AppState extends ChangeNotifier {
  AppState({AfrApiClient? api}) : api = api ?? AfrApiClient();

  final AfrApiClient api;

  String lang = 'fr';
  bool darkMode = false;
  bool loading = true;
  String? error;
  Map<String, dynamic>? bootstrap;

  Map<String, dynamic> get ui =>
      (bootstrap?['ui'] as Map<String, dynamic>?) ?? const {};

  Map<String, dynamic> get stats =>
      (bootstrap?['stats'] as Map<String, dynamic>?) ?? const {};

  List<dynamic> get docsNav =>
      (bootstrap?['docs_nav'] as List<dynamic>?) ?? const [];

  Future<void> init() async {
    final prefs = await SharedPreferences.getInstance();
    lang = prefs.getString('lang') ?? 'fr';
    darkMode = prefs.getBool('darkMode') ?? false;
    await refreshBootstrap();
  }

  Future<void> refreshBootstrap() async {
    loading = true;
    error = null;
    notifyListeners();
    try {
      bootstrap = await api.bootstrap(lang);
      error = null;
    } catch (e) {
      error = e.toString();
    } finally {
      loading = false;
      notifyListeners();
    }
  }

  Future<void> setLang(String code) async {
    lang = code.startsWith('en') ? 'en' : 'fr';
    final prefs = await SharedPreferences.getInstance();
    await prefs.setString('lang', lang);
    await refreshBootstrap();
  }

  Future<void> toggleDark() async {
    darkMode = !darkMode;
    final prefs = await SharedPreferences.getInstance();
    await prefs.setBool('darkMode', darkMode);
    notifyListeners();
  }

  String t(String key, [String fallback = '']) {
    final v = ui[key];
    if (v is String && v.isNotEmpty) return v;
    return fallback;
  }

  String home(String key, [String fallback = '']) {
    final h = ui['home'];
    if (h is Map && h[key] is String) return h[key] as String;
    return fallback;
  }
}
