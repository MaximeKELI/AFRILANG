import 'dart:async';
import 'dart:io';

import 'ai_completion_parse.dart';
import 'local_afr_suggest.dart';
import 'openai_compatible_client.dart';

class AiAssistConfig {
  const AiAssistConfig({
    this.enabled = true,
    this.inlineSuggest = true,
    this.baseUrl = 'http://127.0.0.1:11434/v1',
    this.apiKey = '',
    this.model = LocalAfrSuggest.modelId,
  });

  final bool enabled;
  final bool inlineSuggest;
  final String baseUrl;
  final String apiKey;
  final String model;

  bool get hasRemote {
    if (!enabled) return false;
    final m = model.trim().toLowerCase();
    if (m.isEmpty || m == 'local' || m == LocalAfrSuggest.modelId) {
      return false;
    }
    return baseUrl.trim().isNotEmpty;
  }
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

  /// Inline completion after [caret]. Local engine first; remote optional.
  Future<String?> propose({
    required String path,
    required String content,
    required int caret,
  }) async {
    if (!config.enabled || !config.inlineSuggest) return null;

    final local = LocalAfrSuggest.suggest(content, caret);
    final remote = _remote();
    if (remote == null) return local;

    try {
      busy = true;
      lastError = null;
      final before = content.substring(0, caret.clamp(0, content.length));
      final after = content.substring(caret.clamp(0, content.length));
      final reply = await remote
          .chat([
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
          ], maxTokens: 120)
          .timeout(const Duration(seconds: 4));
      final cont = continuationOnly(before, reply);
      if (cont.isEmpty) return local;
      if (cont.length > 280) return cont.substring(0, 280);
      return cont;
    } catch (e) {
      lastError = e.toString();
      return local;
    } finally {
      busy = false;
    }
  }

  Future<String> chat(
    String userMessage, {
    String? fileContext,
    String? projectContext,
  }) async {
    if (!config.enabled) {
      throw StateError('AI disabled — enable it in Settings');
    }
    final remote = _remote();
    final contextBlob = [
      if (projectContext != null && projectContext.isNotEmpty) projectContext,
      if (fileContext != null && fileContext.isNotEmpty) fileContext,
    ].join('\n\n');

    if (remote == null) {
      busy = true;
      lastError = null;
      try {
        if (chatLog.isEmpty) {
          chatLog.add(AiChatMessage(
            role: 'system',
            content: 'Local AFRILANG assist (${LocalAfrSuggest.modelId}).',
          ));
        }
        final buf = StringBuffer(userMessage);
        if (contextBlob.isNotEmpty) {
          buf.writeln('\n\n--- Context ---\n$contextBlob');
        }
        chatLog.add(AiChatMessage(role: 'user', content: buf.toString()));
        final reply = LocalAfrSuggest.chatReply(
          userMessage,
          fileContext: contextBlob.isEmpty ? fileContext : contextBlob,
        );
        chatLog.add(AiChatMessage(role: 'assistant', content: reply));
        return reply;
      } finally {
        busy = false;
      }
    }
    busy = true;
    lastError = null;
    try {
      if (chatLog.isEmpty) {
        chatLog.add(AiChatMessage(
          role: 'system',
          content:
              'You are AFRIBLOCK AI for AFRILANG. Be concise. Prefer AFRILANG code. '
              'When proposing code, use fenced ```afrilang blocks. '
              'For fixes, return the FULL corrected file in one ```afrilang block when possible. '
              'You may receive afrilang.toml, open editors, and diagnostics as context.',
        ));
      }
      final buf = StringBuffer(userMessage);
      if (contextBlob.isNotEmpty) {
        buf.writeln('\n\n--- Context ---\n$contextBlob');
      }
      chatLog.add(AiChatMessage(role: 'user', content: buf.toString()));
      final reply = await remote.chat(List.of(chatLog), maxTokens: 1200);
      chatLog.add(AiChatMessage(role: 'assistant', content: reply));
      return reply;
    } catch (e) {
      lastError = e.toString();
      final reply = LocalAfrSuggest.chatReply(
        userMessage,
        fileContext: contextBlob.isEmpty ? fileContext : contextBlob,
      );
      chatLog.add(AiChatMessage(
        role: 'assistant',
        content: '$reply\n\n_(distant indisponible : $e)_',
      ));
      return reply;
    } finally {
      busy = false;
    }
  }

  void clearChat() => chatLog.clear();

  /// Extract first fenced code block from assistant reply (for Insert / Replace).
  static String? extractCodeBlock(String reply) {
    final m = RegExp(
      r'```(?:afrilang|afr)?\s*\n([\s\S]*?)\n```',
      caseSensitive: false,
    ).firstMatch(reply);
    if (m != null) return m.group(1);
    final any = RegExp(r'```\w*\s*\n([\s\S]*?)\n```').firstMatch(reply);
    return any?.group(1);
  }

  /// True when the block looks like a whole-file replacement.
  static bool looksLikeFullFile(String code, String? current) {
    final c = code.trim();
    if (c.isEmpty) return false;
    if (current == null || current.trim().isEmpty) return c.contains('\n');
    // Heuristic: similar size or contains multiple top-level constructs.
    if (c.length >= (current.length * 0.5) && c.contains('\n')) return true;
    final opens = RegExp(r'\b(function|fonction|class|classe|create)\b', caseSensitive: false)
        .allMatches(c)
        .length;
    return opens >= 1 && c.split('\n').length >= 3;
  }
}
