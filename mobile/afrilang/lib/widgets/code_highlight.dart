import 'package:flutter/material.dart';

import '../theme/afrilang_theme.dart';

/// Coloration légère des mots-clés AFRILANG (miroir web).
class AfrCodeHighlight extends StatelessWidget {
  const AfrCodeHighlight({
    super.key,
    required this.code,
    this.fontSize = 13,
    this.selectable = true,
  });

  final String code;
  final double fontSize;
  final bool selectable;

  static const _keywords = {
    'create', 'set', 'say', 'dire', 'function', 'fonction', 'returns', 'retourne',
    'end', 'fin', 'if', 'si', 'then', 'alors', 'else', 'sinon', 'while', 'tant',
    'for', 'pour', 'in', 'dans', 'class', 'classe', 'extends', 'étend', 'new',
    'nouveau', 'return', 'import', 'use', 'match', 'case',
    'async', 'await', 'true', 'false', 'null', 'and', 'or', 'not', 'is',
    'greater', 'than', 'equal', 'to', 'less', 'public', 'private',
    'field', 'this', 'super', 'export', 'module',
  };

  static const _types = {
    'text', 'number', 'bool', 'list', 'map', 'void', 'any', 'int', 'float',
  };

  @override
  Widget build(BuildContext context) {
    final spans = _tokenize(code);
    final style = afrMono(fontSize: fontSize);
    final text = Text.rich(TextSpan(style: style, children: spans));
    if (selectable) return SelectableText.rich(TextSpan(style: style, children: spans));
    return text;
  }

  List<InlineSpan> _tokenize(String src) {
    final out = <InlineSpan>[];
    final re = RegExp(
      r'("(?:\\.|[^"\\])*")|(//[^\n]*)|(\b[A-Za-z_][A-Za-z0-9_]*\b)|(\d+\.?\d*)|(\S)|(\s+)',
      multiLine: true,
    );
    for (final m in re.allMatches(src)) {
      final s = m.group(0)!;
      if (m.group(1) != null) {
        out.add(TextSpan(text: s, style: afrMono(fontSize: fontSize, color: const Color(0xFF86EFAC))));
      } else if (m.group(2) != null) {
        out.add(TextSpan(text: s, style: afrMono(fontSize: fontSize, color: const Color(0xFF64748B))));
      } else if (m.group(3) != null) {
        final w = s.toLowerCase();
        Color c = const Color(0xFFE2E8F0);
        if (_keywords.contains(w)) {
          c = const Color(0xFF93C5FD);
        } else if (_types.contains(w)) {
          c = const Color(0xFFFCD34D);
        }
        out.add(TextSpan(
          text: s,
          style: afrMono(
            fontSize: fontSize,
            color: c,
            weight: _keywords.contains(w) ? FontWeight.w600 : FontWeight.w400,
          ),
        ));
      } else if (m.group(4) != null) {
        out.add(TextSpan(text: s, style: afrMono(fontSize: fontSize, color: const Color(0xFFFDBA74))));
      } else {
        out.add(TextSpan(text: s));
      }
    }
    return out;
  }
}
