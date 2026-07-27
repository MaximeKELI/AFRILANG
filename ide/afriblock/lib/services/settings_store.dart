import 'dart:convert';
import 'dart:io';

import 'package:path/path.dart' as p;
import 'package:shared_preferences/shared_preferences.dart';

import '../theme/afriblock_theme.dart';

class SettingsStore {
  static const _keyAfrilang = 'afrilang_path';
  static const _keyRecent = 'recent_folders';
  static const _keyTheme = 'theme_mode';
  static const _keyFormat = 'format_on_save';
  static const _keyLspTrace = 'lsp_trace';
  static const _keyAiEnabled = 'ai_enabled';
  static const _keyAiInline = 'ai_inline';
  static const _keyAiBaseUrl = 'ai_base_url';
  static const _keyAiApiKey = 'ai_api_key';
  static const _keyAiModel = 'ai_model';

  String? afrilangPath;
  List<String> recentFolders = [];
  AfriThemeMode themeMode = AfriThemeMode.dark;
  bool formatOnSave = true;
  bool lspTrace = false;

  bool aiEnabled = true;
  bool aiInlineSuggest = true;
  String aiBaseUrl = 'http://127.0.0.1:11434/v1';
  String aiApiKey = '';
  String aiModel = 'afrilang-local';

  Future<void> load() async {
    final prefs = await SharedPreferences.getInstance();
    afrilangPath = prefs.getString(_keyAfrilang);
    recentFolders = prefs.getStringList(_keyRecent) ?? [];
    formatOnSave = prefs.getBool(_keyFormat) ?? true;
    lspTrace = prefs.getBool(_keyLspTrace) ?? false;
    aiEnabled = prefs.getBool(_keyAiEnabled) ?? true;
    aiInlineSuggest = prefs.getBool(_keyAiInline) ?? true;
    aiBaseUrl = prefs.getString(_keyAiBaseUrl) ?? 'http://127.0.0.1:11434/v1';
    aiApiKey = prefs.getString(_keyAiApiKey) ?? '';
    aiModel = prefs.getString(_keyAiModel) ?? 'afrilang-local';
    // Old default: llama3.2 without a reachable server → prefer offline engine.
    // Keep llama* when Base URL points at Ollama / LM Studio (local OpenAI API).
    final localServer = aiBaseUrl.contains('11434') || aiBaseUrl.contains('1234');
    if (aiApiKey.isEmpty &&
        !localServer &&
        (aiModel == 'llama3.2' || aiModel == 'llama3' || aiModel == 'llama3.1')) {
      aiModel = 'afrilang-local';
    }
    final t = prefs.getString(_keyTheme);
    themeMode = switch (t) {
      'light' => AfriThemeMode.light,
      'hc' => AfriThemeMode.highContrast,
      _ => AfriThemeMode.dark,
    };
  }

  Future<void> setAfrilangPath(String? path) async {
    afrilangPath = path;
    final prefs = await SharedPreferences.getInstance();
    if (path == null || path.isEmpty) {
      await prefs.remove(_keyAfrilang);
    } else {
      await prefs.setString(_keyAfrilang, path);
    }
  }

  Future<void> saveTheme() async {
    final prefs = await SharedPreferences.getInstance();
    final v = switch (themeMode) {
      AfriThemeMode.light => 'light',
      AfriThemeMode.highContrast => 'hc',
      AfriThemeMode.dark => 'dark',
    };
    await prefs.setString(_keyTheme, v);
  }

  Future<void> saveFlags() async {
    final prefs = await SharedPreferences.getInstance();
    await prefs.setBool(_keyFormat, formatOnSave);
    await prefs.setBool(_keyLspTrace, lspTrace);
  }

  Future<void> saveAiSettings() async {
    final prefs = await SharedPreferences.getInstance();
    await prefs.setBool(_keyAiEnabled, aiEnabled);
    await prefs.setBool(_keyAiInline, aiInlineSuggest);
    await prefs.setString(_keyAiBaseUrl, aiBaseUrl);
    await prefs.setString(_keyAiApiKey, aiApiKey);
    await prefs.setString(_keyAiModel, aiModel);
  }

  Future<void> pushRecent(String folder) async {
    recentFolders = [
      folder,
      ...recentFolders.where((e) => e != folder),
    ].take(8).toList();
    final prefs = await SharedPreferences.getInstance();
    await prefs.setStringList(_keyRecent, recentFolders);
  }

  Future<String?> resolveAfrilangBinary() async {
    final env = Platform.environment['AFRIBLOCK_AFRILANG'];
    if (env != null && env.isNotEmpty && await File(env).exists()) return env;

    if (afrilangPath != null &&
        afrilangPath!.isNotEmpty &&
        await File(afrilangPath!).exists()) {
      return afrilangPath;
    }

    final cwd = Directory.current.path;
    final candidates = <String>[
      p.normalize(p.join(cwd, '..', '..', 'build', 'afrilang')),
      p.normalize(p.join(cwd, 'build', 'afrilang')),
      p.normalize(p.join(cwd, '..', 'build', 'afrilang')),
    ];
    if (Platform.isWindows) {
      candidates.addAll(candidates.map((c) => '$c.exe').toList());
    }
    for (final c in candidates) {
      if (await File(c).exists()) return c;
    }

    try {
      final which = Platform.isWindows ? 'where' : 'which';
      final r = await Process.run(which, ['afrilang']);
      if (r.exitCode == 0) {
        final line = (r.stdout as String).trim().split('\n').first.trim();
        if (line.isNotEmpty && await File(line).exists()) return line;
      }
    } catch (_) {}
    return null;
  }

  Map<String, dynamic> toDebugJson() => {
        'afrilangPath': afrilangPath,
        'recentFolders': recentFolders,
        'themeMode': themeMode.name,
        'formatOnSave': formatOnSave,
        'aiEnabled': aiEnabled,
        'aiModel': aiModel,
      };

  @override
  String toString() => jsonEncode(toDebugJson());
}
