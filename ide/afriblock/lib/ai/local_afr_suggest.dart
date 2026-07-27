import '../editor/snippets.dart';
import 'ai_completion_parse.dart';

/// Petite IA locale AFRILANG : règles + contexte (pas de réseau / pas de LLM).
///
/// Fournit des suggestions inline et des réponses chat heuristiques
/// (expliquer le fichier, lister symboles, proposer des squelettes).
class LocalAfrSuggest {
  static const modelId = 'afrilang-local';

  static const keywords = <String>[
    'create',
    'set',
    'say',
    'dire',
    'function',
    'fonction',
    'returns',
    'retourne',
    'end',
    'fin',
    'if',
    'si',
    'then',
    'alors',
    'else',
    'sinon',
    'while',
    'for',
    'pour',
    'in',
    'dans',
    'class',
    'classe',
    'import',
    'use',
    'match',
    'case',
    'async',
    'await',
    'return',
    'true',
    'false',
    'null',
    'text',
    'number',
    'bool',
    'list',
    'map',
    'void',
  ];

  static const _types = ['text', 'number', 'bool', 'list', 'map', 'void'];

  /// Returns text to insert *after* [caret], or null.
  static String? suggest(String content, int caret) {
    final c = caret.clamp(0, content.length);
    final midWordBlocked = !shouldTriggerInlineSuggest(content, c) &&
        c < content.length;
    if (midWordBlocked) {
      // Still allow completing a partial identifier at EOF / before space.
      final ch = content[c];
      if (ch != '\n' && ch != ' ' && ch != '\t') return null;
    }

    final before = content.substring(0, c);
    final word = _currentWord(before);
    final line = _currentLine(before);
    final indent = _lineIndent(line);
    final lineTrim = line.trimLeft();
    final ids = harvestIdentifiers(content);

    // 1) Contextual continuations (line-aware, even mid-token after create/set)
    final ctx = _contextSuggest(
      before: before,
      lineTrim: lineTrim,
      indent: indent,
      ids: ids,
      word: word,
    );
    if (ctx != null) return ctx;

    // 2) Mid-word / prefix: snippets then keywords then identifiers
    if (word.isNotEmpty) {
      final snip = _snippetCompletion(word);
      if (snip != null) return snip;
      final kw = _keywordCompletion(word);
      if (kw != null) return kw;
      final idHit = _identifierCompletion(word, ids);
      if (idHit != null) return idHit;
    }

    // 3) Fresh line starter
    if (word.isEmpty && (before.endsWith('\n') || before.isEmpty)) {
      if (ids.isEmpty) return 'say "Hello AFRILANG"\n';
      return 'say ${ids.first}\n';
    }

    return null;
  }

  /// Heuristic chat reply (offline “explain / suggest”).
  static String chatReply(String userMessage, {String? fileContext}) {
    final q = userMessage.toLowerCase();
    final code = _extractCode(fileContext);

    if (q.contains('expliq') || q.contains('explain') || q.contains('analys')) {
      if (q.contains('error') ||
          q.contains('erreur') ||
          q.contains('diagnostic') ||
          q.contains('problem')) {
        return explainError(userMessage, fileContext: code);
      }
      return explainFile(code);
    }
    if (q.contains('fix') ||
        q.contains('corrige') ||
        q.contains('patch') ||
        q.contains('répare') ||
        q.contains('repare')) {
      final fix = suggestFix(userMessage, code);
      if (fix != null) return fix;
    }
    if (q.contains('fonction') || q.contains('function') || q.contains('squelette')) {
      return 'Voici un squelette AFRILANG :\n\n'
          '```afrilang\n'
          'function main()\n'
          '    say "ok"\n'
          'end\n'
          '```\n';
    }
    if (q.contains('boucle') || q.contains('loop') || q.contains('for')) {
      return 'Boucle typique :\n\n'
          '```afrilang\n'
          'for item in items\n'
          '    say item\n'
          'end\n'
          '```\n';
    }
    if (q.contains('si ') ||
        q.contains('if ') ||
        q.contains('condition') ||
        q.trim() == 'si' ||
        q.trim() == 'if') {
      return 'Condition :\n\n'
          '```afrilang\n'
          'if ready then\n'
          '    say "go"\n'
          'else\n'
          '    say "wait"\n'
          'end\n'
          '```\n';
    }

    final ids = harvestIdentifiers(code);
    final fns = harvestFunctions(code);
    final buf = StringBuffer()
      ..writeln('*(moteur local afrilang-local — pas de LLM distant)*')
      ..writeln();
    if (fns.isNotEmpty) {
      buf.writeln('Fonctions détectées : ${fns.join(', ')}');
    }
    if (ids.isNotEmpty) {
      buf.writeln('Identifiants : ${ids.take(12).join(', ')}');
    }
    if (fns.isEmpty && ids.isEmpty) {
      buf.writeln(
        'Je peux expliquer un fichier, proposer un squelette `function`, '
        'une boucle `for`, ou une condition `if`. '
        'Ouvre un `.afr` et clique « Expliquer le fichier ».',
      );
    } else {
      buf.writeln(
        'Demande « explique », « fonction », « boucle » ou « condition » '
        'pour une proposition concrète.',
      );
    }
    return buf.toString();
  }

  static String _extractCode(String? fileContext) {
    if (fileContext == null || fileContext.isEmpty) return '';
    var src = fileContext.trim();
    if (src.contains('--- Current file ---')) {
      src = src.split('--- Current file ---').last.trim();
    }
    if (src.startsWith('File:')) {
      final nl = src.indexOf('\n');
      if (nl >= 0) src = src.substring(nl + 1).trim();
    }
    return src;
  }

  static String explainFile(String code) {
    final lines = code.split('\n');
    final fns = harvestFunctions(code);
    final ids = harvestIdentifiers(code);
    final says = RegExp(r'\b(?:say|dire)\b')
        .allMatches(code)
        .length;
    final creates = RegExp(r'\bcreate\b').allMatches(code).length;
    final buf = StringBuffer()
      ..writeln('## Analyse locale')
      ..writeln('- Lignes : ${lines.where((l) => l.trim().isNotEmpty).length}')
      ..writeln('- `create` : $creates')
      ..writeln('- `say`/`dire` : $says')
      ..writeln('- Fonctions : ${fns.isEmpty ? "(aucune)" : fns.join(", ")}')
      ..writeln(
        '- Variables / ids : ${ids.isEmpty ? "(aucun)" : ids.take(20).join(", ")}',
      )
      ..writeln()
      ..writeln(
        'Suggestion : vérifier que chaque `function`/`if`/`for`/`class` '
        'a un `end` (ou `fin`) correspondant.',
      );

    final open = _unclosedBlocks(code);
    if (open.isNotEmpty) {
      buf
        ..writeln()
        ..writeln('Blocs potentiellement ouverts : ${open.join(" → ")}');
    }
    return buf.toString();
  }

  /// Explain a compiler/LSP diagnostic (offline heuristics).
  static String explainError(String userMessage, {String? fileContext}) {
    final msg = userMessage.toLowerCase();
    final code = fileContext ?? '';
    final buf = StringBuffer()
      ..writeln('## Explication (moteur local)')
      ..writeln();

    if (msg.contains('expected') && (msg.contains('do') || msg.contains('then'))) {
      buf.writeln(
        'Le parseur attend souvent `do` ou `then` après une condition '
        '(`if` / `while` / `for`). Exemple :',
      );
      buf.writeln();
      buf.writeln('```afrilang\nif x greater than 0 then\n    say x\nend\n```');
    } else if (msg.contains('end') || msg.contains('fin') || msg.contains('unclosed')) {
      buf.writeln(
        'Un bloc (`function`, `if`, `for`, `class`, `match`) semble sans `end`/`fin`. '
        'Compte les ouvertures et fermetures.',
      );
    } else if (msg.contains('undefined') || msg.contains('not found') || msg.contains('inconnu')) {
      buf.writeln(
        'Symbole inconnu : vérifie l’orthographe, un `create` manquant, '
        'ou un `import` / `use` oublié.',
      );
    } else if (msg.contains('type') || msg.contains('mismatch')) {
      buf.writeln(
        'Incompatibilité de type probable. AFRILANG distingue notamment '
        '`text`, `number`, `bool`, `list`, `map`.',
      );
    } else if (msg.contains('syntax') || msg.contains('parse') || msg.contains('unexpected')) {
      buf.writeln(
        'Erreur de syntaxe. Points fréquents : guillemets non fermés, '
        '`:` manquant sur un type, ou mot-clé FR/EN mélangé incorrectement.',
      );
    } else {
      buf.writeln(
        'Diagnostic reçu. Relis la ligne indiquée, puis la précédente '
        '(souvent l’erreur est un `end` / `do` manquant plus haut).',
      );
    }

    final open = _unclosedBlocks(code);
    if (open.isNotEmpty) {
      buf
        ..writeln()
        ..writeln('Blocs ouverts détectés dans le fichier : **${open.join(" → ")}**');
    }
    buf
      ..writeln()
      ..writeln('_Pour un correctif automatique, utilise « Fix with AI » sur le problème._');
    return buf.toString();
  }

  /// Propose a fenced AFRILANG fix when heuristics can rewrite the file.
  static String? suggestFix(String diagnostic, String fileContent, {int? line}) {
    if (fileContent.trim().isEmpty) return null;
    final msg = diagnostic.toLowerCase();
    var lines = fileContent.split('\n');
    final idx = (line ?? 1) - 1;
    var changed = false;

    // Missing then/do after if/while/for on the reported line.
    if (idx >= 0 &&
        idx < lines.length &&
        (msg.contains('do') || msg.contains('then') || msg.contains('expected'))) {
      final raw = lines[idx];
      final trim = raw.trimRight();
      final lower = trim.toLowerCase();
      if ((lower.startsWith('if ') ||
              lower.startsWith('si ') ||
              lower.startsWith('while ') ||
              lower.startsWith('tant ') ||
              lower.startsWith('for ') ||
              lower.startsWith('pour ')) &&
          !lower.contains(' then') &&
          !lower.endsWith(' then') &&
          !lower.contains(' do') &&
          !lower.endsWith(' do') &&
          !lower.endsWith(' alors')) {
        final indent = raw.substring(0, raw.length - raw.trimLeft().length);
        if (lower.startsWith('si ') || lower.startsWith('tant ') || lower.startsWith('pour ')) {
          lines[idx] = '$indent${trim.trimLeft()} alors';
        } else {
          lines[idx] = '$indent${trim.trimLeft()} then';
        }
        changed = true;
      }
    }

    // Unclosed blocks → append end
    final open = _unclosedBlocks(fileContent);
    if (!changed && open.isNotEmpty && (msg.contains('end') || msg.contains('fin') || msg.contains('eof') || msg.contains('unexpected'))) {
      lines = [...lines, 'end'];
      changed = true;
    }

    // Bare say without quotes for a single token that's not an ident already
    if (!changed && idx >= 0 && idx < lines.length && msg.contains('syntax')) {
      final m = RegExp(r'^(\s*say\s+)([^"\n]+)$', caseSensitive: false)
          .firstMatch(lines[idx]);
      if (m != null) {
        final rest = m.group(2)!.trim();
        if (rest.isNotEmpty && !rest.contains('"') && !RegExp(r'^[A-Za-z_]').hasMatch(rest)) {
          lines[idx] = '${m.group(1)}"$rest"';
          changed = true;
        }
      }
    }

    if (!changed) {
      // Generic tip with no rewrite
      return 'Je n’ai pas de patch automatique sûr pour cette erreur.\n\n'
          '${explainError(diagnostic, fileContext: fileContent)}\n';
    }

    final fixed = lines.join('\n');
    return 'Proposition de correctif (remplace le fichier) :\n\n'
        '```afrilang\n'
        '$fixed\n'
        '```\n';
  }

  static Set<String> harvestIdentifiers(String content) {
    final out = <String>{};
    final re = RegExp(
      r'\b(?:create|set)\s+([A-Za-z_][A-Za-z0-9_]*)',
      caseSensitive: false,
    );
    for (final m in re.allMatches(content)) {
      out.add(m.group(1)!);
    }
    for (final f in harvestFunctions(content)) {
      out.add(f);
    }
    return out;
  }

  static List<String> harvestFunctions(String content) {
    final out = <String>[];
    final re = RegExp(
      r'\b(?:function|fonction)\s+([A-Za-z_][A-Za-z0-9_]*)',
      caseSensitive: false,
    );
    for (final m in re.allMatches(content)) {
      out.add(m.group(1)!);
    }
    return out;
  }

  // --- internals ---

  static String? _snippetCompletion(String word) {
    for (final snip in kAfrilangSnippets) {
      if (snip.prefix.isEmpty) continue;
      if (snip.prefix.startsWith(word) && snip.prefix != word) {
        final body = expandSnippet(snip.body);
        return body.substring(word.length.clamp(0, body.length));
      }
      if (snip.prefix == word) {
        final body = expandSnippet(snip.body);
        if (body.startsWith(word)) return body.substring(word.length);
        return body;
      }
    }
    return null;
  }

  static String? _keywordCompletion(String word) {
    final matches = keywords
        .where((k) => k.startsWith(word.toLowerCase()) && k != word.toLowerCase())
        .toList()
      ..sort((a, b) => a.length.compareTo(b.length));
    if (matches.isEmpty) return null;
    return matches.first.substring(word.length);
  }

  static String? _identifierCompletion(String word, Set<String> ids) {
    final hits = ids
        .where((id) =>
            id.toLowerCase().startsWith(word.toLowerCase()) &&
            id.toLowerCase() != word.toLowerCase())
        .toList()
      ..sort((a, b) => a.length.compareTo(b.length));
    if (hits.isEmpty) return null;
    return hits.first.substring(word.length);
  }

  static String? _contextSuggest({
    required String before,
    required String lineTrim,
    required String indent,
    required Set<String> ids,
    required String word,
  }) {
    // create <name> …
    final createName = RegExp(r'^create\s+([A-Za-z_][A-Za-z0-9_]*)\s*$',
            caseSensitive: false)
        .firstMatch(lineTrim);
    if (createName != null) {
      return ' as text = ""';
    }
    if (RegExp(r'^create\s*$', caseSensitive: false).hasMatch(lineTrim)) {
      return ' name as text = ""';
    }
    final createAs = RegExp(r'^create\s+\w+\s+as\s*$', caseSensitive: false)
        .firstMatch(lineTrim);
    if (createAs != null) {
      return ' text = ""';
    }
    final createType = RegExp(
      r'^create\s+\w+\s+as\s+(\w*)$',
      caseSensitive: false,
    ).firstMatch(lineTrim);
    if (createType != null) {
      final partial = createType.group(1)!.toLowerCase();
      for (final t in _types) {
        if (t.startsWith(partial) && t != partial) {
          final suffix = t.substring(partial.length);
          final lit = switch (t) {
            'number' => '0',
            'bool' => 'false',
            'list' => '[]',
            'map' => '{}',
            'void' => 'null',
            _ => '""',
          };
          return '$suffix = $lit';
        }
      }
    }

    // set … (exact keyword alone → expand; "set name" → assign)
    if (RegExp(r'^set\s*$', caseSensitive: false).hasMatch(lineTrim) ||
        (lineTrim.toLowerCase() == 'set' && word.toLowerCase() == 'set')) {
      if (ids.isNotEmpty) return ' ${ids.first} = ';
      return ' name = ';
    }
    final setName = RegExp(r'^set\s+([A-Za-z_][A-Za-z0-9_]*)\s*$',
            caseSensitive: false)
        .firstMatch(lineTrim);
    if (setName != null) return ' = ';

    // Remaining contexts need trailing space / empty word (avoid fighting snippets)
    if (word.isNotEmpty &&
        !RegExp(r'^(create|set)\b', caseSensitive: false).hasMatch(lineTrim)) {
      return null;
    }

    // say / dire
    if (RegExp(r'^(say|dire)\s*$', caseSensitive: false).hasMatch(lineTrim)) {
      if (ids.isNotEmpty) return ' ${ids.first}';
      return ' ""';
    }

    // if / si without then
    if (RegExp(r'^(if|si)\s*$', caseSensitive: false).hasMatch(lineTrim)) {
      final fr = lineTrim.toLowerCase().startsWith('si');
      return fr
          ? ' pret alors\n${indent}    say ""\nsinon\n${indent}    say ""\n${indent}fin\n'
          : ' ready then\n${indent}    say ""\nelse\n${indent}    say ""\n${indent}end\n';
    }

    // function / fonction name
    if (RegExp(r'^(function|fonction)\s*$', caseSensitive: false)
        .hasMatch(lineTrim)) {
      final fr = lineTrim.toLowerCase().startsWith('fonc');
      return fr
          ? ' main()\n${indent}    say ""\n${indent}fin\n'
          : ' main()\n${indent}    say ""\n${indent}end\n';
    }

    // for / pour
    if (RegExp(r'^(for|pour)\s*$', caseSensitive: false).hasMatch(lineTrim)) {
      final fr = lineTrim.toLowerCase().startsWith('pour');
      return fr
          ? ' item dans items\n${indent}    say item\n${indent}fin\n'
          : ' item in items\n${indent}    say item\n${indent}end\n';
    }

    // class
    if (RegExp(r'^(class|classe)\s*$', caseSensitive: false).hasMatch(lineTrim)) {
      final fr = lineTrim.toLowerCase().startsWith('classe');
      return fr
          ? ' Nom\n${indent}    create x as number = 0\n${indent}fin\n'
          : ' Name\n${indent}    create x as number = 0\n${indent}end\n';
    }

    // match
    if (RegExp(r'^match\s*$', caseSensitive: false).hasMatch(lineTrim)) {
      return ' value\n${indent}    case x:\n${indent}        say x\n${indent}end\n';
    }

    // Close unclosed block on empty new line with indent
    if (word.isEmpty && before.endsWith('\n')) {
      final open = _unclosedBlocks(before);
      if (open.isNotEmpty) {
        final closer = open.last == 'fr' ? 'fin' : 'end';
        if (indent.isEmpty || indent.length <= 4) {
          return '$closer\n';
        }
      }
    }

    // After `=` on create/set — suggest literal
    if (word.isEmpty &&
        RegExp(r'(create|set).*=\s*$', caseSensitive: false).hasMatch(lineTrim)) {
      if (lineTrim.toLowerCase().contains(' as number')) return '0';
      if (lineTrim.toLowerCase().contains(' as bool')) return 'false';
      if (lineTrim.toLowerCase().contains(' as list')) return '[]';
      if (lineTrim.toLowerCase().contains(' as map')) return '{}';
      return '""';
    }

    return null;
  }

  /// Stack of open block kinds: 'en' (end) or 'fr' (fin).
  static List<String> _unclosedBlocks(String content) {
    final stack = <String>[];
    final token = RegExp(
      r'\b(function|fonction|if|si|while|for|pour|class|classe|match|else|sinon|end|fin)\b',
      caseSensitive: false,
    );
    for (final m in token.allMatches(content)) {
      final t = m.group(1)!.toLowerCase();
      if (t == 'end') {
        if (stack.isNotEmpty && stack.last == 'en') stack.removeLast();
      } else if (t == 'fin') {
        if (stack.isNotEmpty && stack.last == 'fr') stack.removeLast();
      } else if (t == 'else' || t == 'sinon') {
        // same block
      } else if (t == 'fonction' || t == 'si' || t == 'pour' || t == 'classe') {
        stack.add('fr');
      } else {
        stack.add('en');
      }
    }
    return stack;
  }

  static String _currentWord(String before) {
    if (before.isEmpty) return '';
    final m = RegExp(r'[A-Za-z_][A-Za-z0-9_]*$').firstMatch(before);
    return m?.group(0) ?? '';
  }

  static String _currentLine(String before) {
    final i = before.lastIndexOf('\n');
    return i < 0 ? before : before.substring(i + 1);
  }

  static String _lineIndent(String line) {
    final m = RegExp(r'^[ \t]*').firstMatch(line);
    return m?.group(0) ?? '';
  }
}
