import 'dart:async';
import 'dart:convert';
import 'dart:io';

import 'ai_completion_parse.dart';

class AiChatMessage {
  AiChatMessage({required this.role, required this.content});
  final String role; // system | user | assistant
  final String content;

  Map<String, String> toJson() => {'role': role, 'content': content};
}

/// Minimal OpenAI-compatible Chat Completions client (`/chat/completions`).
class OpenAiCompatibleClient {
  OpenAiCompatibleClient({
    required this.baseUrl,
    required this.apiKey,
    required this.model,
    HttpClient? httpClient,
  }) : _http = httpClient ?? HttpClient();

  /// e.g. `https://api.openai.com/v1` or `http://127.0.0.1:11434/v1`
  final String baseUrl;
  final String apiKey;
  final String model;
  final HttpClient _http;

  void close() => _http.close(force: true);

  Future<String> chat(
    List<AiChatMessage> messages, {
    double temperature = 0.2,
    int maxTokens = 512,
    Duration timeout = const Duration(seconds: 45),
  }) async {
    final root = baseUrl.replaceAll(RegExp(r'/+$'), '');
    final uri = Uri.parse('$root/chat/completions');
    final req = await _http.postUrl(uri).timeout(timeout);
    req.headers.set(HttpHeaders.contentTypeHeader, 'application/json');
    req.headers.set(HttpHeaders.acceptHeader, 'application/json');
    if (apiKey.isNotEmpty) {
      req.headers.set(HttpHeaders.authorizationHeader, 'Bearer $apiKey');
    }
    final body = jsonEncode({
      'model': model,
      'temperature': temperature,
      'max_tokens': maxTokens,
      'messages': messages.map((m) => m.toJson()).toList(),
    });
    req.add(utf8.encode(body));
    final res = await req.close().timeout(timeout);
    final raw = await res.transform(utf8.decoder).join();
    if (res.statusCode < 200 || res.statusCode >= 300) {
      throw StateError('AI HTTP ${res.statusCode}: ${_short(raw)}');
    }
    final decoded = jsonDecode(raw);
    if (decoded is! Map<String, dynamic>) {
      throw StateError('AI: invalid JSON response');
    }
    final choices = decoded['choices'];
    if (choices is! List || choices.isEmpty) {
      throw StateError('AI: empty choices');
    }
    final first = choices.first;
    if (first is! Map) throw StateError('AI: bad choice');
    final msg = first['message'];
    if (msg is Map && msg['content'] is String) {
      return stripCompletionFences(msg['content'] as String);
    }
    final text = first['text'];
    if (text is String) return stripCompletionFences(text);
    throw StateError('AI: no content in response');
  }

  static String _short(String s) =>
      s.length > 180 ? '${s.substring(0, 180)}…' : s;
}
