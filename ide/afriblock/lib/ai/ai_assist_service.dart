import 'dart:async';
import 'dart:io';

import 'ai_completion_parse.dart';
import 'local_afr_suggest.dart';
import 'openai_compatible_client.dart';

class AiAssistConfig {
  const AiAssistConfig({
    this.enabled = false,
    this.inlineSuggest = true,
    this.baseUrl = 'http://127.0.0.1:11434/v1',
    this.apiKey = '',
    this.model = 'llama3.2',
  });

  final bool enabled;
  final bool inlineSuggest;
  final String baseUrl;
  final String apiKey;
  final String model;

  bool get hasRemote =>
      enabled && baseUrl.trim().isNotEmpty && model.trim().isNotEmpty;
}

/// Orchestrates local + remote AFRILANG coding assistance.
class AiAssistService {
  AiAssistConfig config = const AiAssistConfig();
  String? lastError;
  bool busy = false;

  final chatLog = <AiChatMessage>[];

  OpenAiCompatibleClient? _client;

  void updateConfig(AiAssistConfig c) {
    config = c;
    _client?.close();
    _client = null;
    lastError = null;
  }

  OpenAiCompatibleClient? _remote() {
    if (!config.hasRemote) return null;
    final key = config.apiKey.isNotEmpty
        ? config.apiKey
        : (Platform.environment['AFRIBLOCK_AI_API_KEY'] ?? '');
    return _client ??= OpenAiCompatibleClient(
      baseUrl: config.baseUrl.trim(),
      apiKey: key,
      model: config.model.trim(),
    );
  }

  /// Inline completion after [caret]. Prefers remote; falls back to local.
  Future<String?> propose({
    required String path,
    required String content,
    required int caret,
  }) async {
    if (!config.enabled || !config.inlineSuggest) return null;
    if (!path.toLowerCase().endsWith('.afr')) {
      return LocalAfrSuggest.suggest(content, caret);
    }

    final local = LocalAfrSuggest.suggest(content, caret);
    final remote = _remote();
    if (remote == null) return local;

    try {
      busy = true;
      lastError = null;
      final before = content.substring(0, caret.clamp(0, content.length));
      final after = content.substring(caret.clamp(0, content.length));
      final reply = await remote.chat([
        AiChatMessage(
          role: 'system',
          content:
              'You are an AFRILANG coding assistant inside AFRIBLOCK IDE. '
              'Propose ONLY the code continuation that should be inserted at the cursor. '
              'No markdown fences, no explanations, no repeating text already before the cursor. '
              'AFRILANG keywords: create set say function end if then else while for in class import use match case.',
        ),
        AiChatMessage(
          role: 'user',
          content:
              'File: $path\n'
              'CODE BEFORE CURSOR:\n$before\n'
              'CODE AFTER CURSOR:\n$after\n'
              'Write only the continuation.',
        ),
      ], maxTokens: 120);
      final cont = continuationOnly(before, reply);
      if (cont.isEmpty) return local;
      // Cap ghost length for UX.
      if (cont.length > 280) return cont.substring(0, 280);
      return cont;
    } catch (e) {
      lastError = e.toString();
      return local;
    } finally {
      busy = false;
    }
  }

  Future<String> chat(String userMessage, {String? fileContext}) async {
    if (!config.enabled) {
      throw StateError('AI disabled — enable it in Settings');
    }
    final remote = _remote();
    if (remote == null) {
      throw StateError('Configure AI base URL and model in Settings');
    }
    busy = true;
    lastError = null;
    try {
      if (chatLog.isEmpty) {
        chatLog.add(AiChatMessage(
          role: 'system',
          content:
              'You are AFRIBLOCK AI for AFRILANG. Be concise. Prefer AFRILANG code. '
              'When proposing code, use fenced ```afrilang blocks.',
        ));
      }
      final buf = StringBuffer(userMessage);
      if (fileContext != null && fileContext.isNotEmpty) {
        buf.writeln('\n\n--- Current file ---\n$fileContext');
      }
      chatLog.add(AiChatMessage(role: 'user', content: buf.toString()));
      final reply = await remote.chat(List.of(chatLog), maxTokens: 900);
      chatLog.add(AiChatMessage(role: 'assistant', content: reply));
      return reply;
    } catch (e) {
      lastError = e.toString();
      rethrow;
    } finally {
      busy = false;
    }
  }

  void clearChat() => chatLog.clear();

  /// Extract first fenced code block from assistant reply (for Insert).
  static String? extractCodeBlock(String reply) {
    final m = RegExp(
      r'```(?:afrilang|afr)?\s*\n([\s\S]*?)\n```',
      caseSensitive: false,
    ).firstMatch(reply);
    if (m != null) return m.group(1);
    final any = RegExp(r'```\w*\s*\n([\s\S]*?)\n```').firstMatch(reply);
    return any?.group(1);
  }
}
