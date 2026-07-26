class AfrilangSnippet {
  const AfrilangSnippet({
    required this.id,
    required this.label,
    required this.body,
    this.prefix = '',
  });

  final String id;
  final String label;
  final String body;
  final String prefix;
}

const kAfrilangSnippets = <AfrilangSnippet>[
  AfrilangSnippet(
    id: 'fn',
    label: 'function',
    prefix: 'fn',
    body: 'function \${1:name}()\n    \${0}\nend\n',
  ),
  AfrilangSnippet(
    id: 'fonc',
    label: 'fonction',
    prefix: 'fonc',
    body: 'fonction \${1:nom}()\n    \${0}\nfin\n',
  ),
  AfrilangSnippet(
    id: 'if',
    label: 'if / then / else',
    prefix: 'if',
    body: 'if \${1:cond} then\n    \${2}\nelse\n    \${0}\nend\n',
  ),
  AfrilangSnippet(
    id: 'si',
    label: 'si / alors / sinon',
    prefix: 'si',
    body: 'si \${1:cond} alors\n    \${2}\nsinon\n    \${0}\nfin\n',
  ),
  AfrilangSnippet(
    id: 'for',
    label: 'for / in',
    prefix: 'for',
    body: 'for \${1:item} in \${2:list}\n    \${0}\nend\n',
  ),
  AfrilangSnippet(
    id: 'class',
    label: 'class',
    prefix: 'class',
    body: 'class \${1:Name}\n    \${0}\nend\n',
  ),
  AfrilangSnippet(
    id: 'match',
    label: 'match / case',
    prefix: 'match',
    body: 'match \${1:value}\n    case \${2:pat}:\n        \${0}\nend\n',
  ),
  AfrilangSnippet(
    id: 'say',
    label: 'say',
    prefix: 'say',
    body: 'say "\${0}"\n',
  ),
];

/// Expands `${n:default}` / `$n` placeholders to defaults (simple IDE expand).
String expandSnippet(String body) {
  var out = body;
  out = out.replaceAllMapped(
    RegExp(r'\$\{(\d+):([^}]*)\}'),
    (m) => m.group(2) ?? '',
  );
  out = out.replaceAllMapped(RegExp(r'\$\{(\d+)\}'), (_) => '');
  out = out.replaceAllMapped(RegExp(r'\$(\d+)'), (_) => '');
  return out;
}

List<AfrilangSnippet> filterSnippets(String query) {
  final q = query.trim().toLowerCase();
  if (q.isEmpty) return kAfrilangSnippets;
  return kAfrilangSnippets
      .where((s) =>
          s.id.contains(q) ||
          s.label.toLowerCase().contains(q) ||
          s.prefix.toLowerCase().contains(q))
      .toList();
}
