import 'dart:convert';

import 'package:http/http.dart' as http;

import '../config/api_config.dart';

class ApiException implements Exception {
  ApiException(this.message, {this.statusCode});
  final String message;
  final int? statusCode;

  @override
  String toString() => message;
}

/// Client HTTP vers `/api/mobile/*` et APIs playground.
class AfrApiClient {
  AfrApiClient({String? baseUrl, http.Client? client})
      : baseUrl = (baseUrl ?? ApiConfig.baseUrl).replaceAll(RegExp(r'/$'), ''),
        _client = client ?? http.Client();

  final String baseUrl;
  final http.Client _client;

  Map<String, String> get _headers => {
        'Accept': 'application/json',
        'X-Afrilang-Client': 'flutter-mobile',
      };

  Map<String, String> get _postHeaders => {
        ..._headers,
        'Content-Type': 'application/json',
      };

  Uri _u(String path, [Map<String, String>? query]) {
    final p = path.startsWith('/') ? path : '/$path';
    final cleaned = <String, String>{};
    if (query != null) {
      for (final e in query.entries) {
        if (e.value.isNotEmpty) cleaned[e.key] = e.value;
      }
    }
    return Uri.parse('$baseUrl$p').replace(queryParameters: cleaned.isEmpty ? null : cleaned);
  }

  Future<Map<String, dynamic>> getJson(String path, {Map<String, String>? query}) async {
    final res = await _client.get(_u(path, query), headers: _headers);
    return _decode(res);
  }

  Future<Map<String, dynamic>> postJson(String path, Map<String, dynamic> body) async {
    final res = await _client.post(
      _u(path),
      headers: _postHeaders,
      body: jsonEncode(body),
    );
    return _decode(res);
  }

  Map<String, dynamic> _decode(http.Response res) {
    Map<String, dynamic> data;
    try {
      final raw = jsonDecode(utf8.decode(res.bodyBytes));
      data = raw is Map<String, dynamic> ? raw : {'data': raw};
    } catch (_) {
      throw ApiException('Réponse invalide (${res.statusCode})', statusCode: res.statusCode);
    }
    if (res.statusCode >= 400) {
      throw ApiException(
        data['output']?.toString() ?? data['error']?.toString() ?? 'Erreur ${res.statusCode}',
        statusCode: res.statusCode,
      );
    }
    return data;
  }

  Future<Map<String, dynamic>> bootstrap(String lang) =>
      getJson('/api/mobile/bootstrap/', query: {'lang': lang});

  Future<Map<String, dynamic>> home(String lang) =>
      getJson('/api/mobile/home/', query: {'lang': lang});

  Future<Map<String, dynamic>> docsIndex(String lang) =>
      getJson('/api/mobile/docs/', query: {'lang': lang});

  Future<Map<String, dynamic>> docsPage(String slug, String lang) =>
      getJson('/api/mobile/docs/$slug/', query: {'lang': lang});

  Future<Map<String, dynamic>> packages({String q = '', String lang = 'fr'}) =>
      getJson('/api/mobile/packages/', query: {'q': q, 'lang': lang});

  Future<Map<String, dynamic>> packageDetail(String name) =>
      getJson('/api/mobile/packages/$name/');

  Future<Map<String, dynamic>> examples({String q = '', String lang = 'fr'}) =>
      getJson('/api/mobile/examples/', query: {'q': q, 'lang': lang});

  Future<Map<String, dynamic>> example(String slug) =>
      getJson('/api/examples/$slug/');

  Future<Map<String, dynamic>> stdlib({
    String lang = 'fr',
    String q = '',
    bool coreOnly = true,
    bool experimental = false,
  }) =>
      getJson('/api/mobile/stdlib/', query: {
        'lang': lang,
        'q': q,
        'core': coreOnly ? '1' : '0',
        if (experimental) 'experimental': '1',
      });

  Future<Map<String, dynamic>> stdlibDetail(String name, String lang) =>
      getJson('/api/mobile/stdlib/$name/', query: {'lang': lang});

  Future<Map<String, dynamic>> tutorial(String lang) =>
      getJson('/api/mobile/tutorial/', query: {'lang': lang});

  Future<Map<String, dynamic>> tutorialStep(int step, String lang) =>
      getJson('/api/mobile/tutorial/$step/', query: {'lang': lang});

  Future<Map<String, dynamic>> releases() => getJson('/api/mobile/releases/');

  Future<Map<String, dynamic>> run(String source, {String target = 'native'}) =>
      postJson('/api/mobile/run/', {'source': source, 'target': target});

  Future<Map<String, dynamic>> fmt(String source) =>
      postJson('/api/mobile/fmt/', {'source': source});

  Future<Map<String, dynamic>> check(String source) =>
      postJson('/api/mobile/check/', {'source': source});
}
