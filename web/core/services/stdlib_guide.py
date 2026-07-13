"""Guides HTML multi-sections (équivalent 5+ pages imprimées)."""
from __future__ import annotations

from core.content.stdlib_catalog import category_by_id, infer_tier
from core.services.stdlib_meta import _example_for_function


def build_guide_sections(
    mod,
    source: str,
    functions: list[dict],
    lang: str,
    overview: str = '',
    example: str = '',
    wasm_note: str = '',
) -> list[dict]:
    code = (lang or 'fr')[:2]
    is_en = code == 'en'
    cat = category_by_id(mod.category, lang) or {'label': mod.category, 'description': ''}
    tier = mod.tier or infer_tier(mod.name)
    intro = overview or (mod.description_en if is_en else mod.description_fr) or mod.summary

    if is_en:
        sections = [
            {
                'title': '1. Overview',
                'body': intro,
                'kind': 'text',
            },
            {
                'title': '2. Installation & import',
                'body': (
                    f'Add the module to your program:\n\n'
                    f'import "{mod.import_path}"\n'
                    f'use {mod.name.split("/")[-1]}\n\n'
                    f'Tier: {tier} · Category: {cat["label"]}\n'
                    f'{cat.get("description", "")}\n\n'
                    f'Platform: {wasm_note or "See WASM docs."}'
                ),
                'kind': 'code',
            },
            {
                'title': '3. API reference',
                'body': _api_section(functions, is_en),
                'kind': 'api',
                'functions': functions,
            },
            {
                'title': '4. Usage examples',
                'body': example or _examples_section(mod.import_path, functions, is_en),
                'kind': 'code',
            },
            {
                'title': '5. Best practices',
                'body': _best_practices(mod, is_en),
                'kind': 'text',
            },
            {
                'title': '6. Appendix — signatures',
                'body': (source or '')[:4000] + ('\n…' if source and len(source) > 4000 else ''),
                'kind': 'code',
            },
        ]
    else:
        sections = [
            {
                'title': '1. Vue d\'ensemble',
                'body': intro,
                'kind': 'text',
            },
            {
                'title': '2. Installation & import',
                'body': (
                    f'Ajoutez le module à votre programme :\n\n'
                    f'import "{mod.import_path}"\n'
                    f'use {mod.name.split("/")[-1]}\n\n'
                    f'Niveau : {tier} · Catégorie : {cat["label"]}\n'
                    f'{cat.get("description", "")}\n\n'
                    f'Plateforme : {wasm_note or "Voir la doc WASM."}'
                ),
                'kind': 'code',
            },
            {
                'title': '3. Référence API',
                'body': _api_section(functions, is_en),
                'kind': 'api',
                'functions': functions,
            },
            {
                'title': '4. Exemples d\'utilisation',
                'body': example or _examples_section(mod.import_path, functions, is_en),
                'kind': 'code',
            },
            {
                'title': '5. Bonnes pratiques',
                'body': _best_practices(mod, is_en),
                'kind': 'text',
            },
            {
                'title': '6. Annexe — signatures',
                'body': (source or '')[:4000] + ('\n…' if source and len(source) > 4000 else ''),
                'kind': 'code',
            },
        ]
    return sections


def _api_section(functions: list[dict], is_en: bool) -> str:
    if not functions:
        return 'No exported functions.' if is_en else 'Aucune fonction exportée.'
    lines = []
    for f in functions:
        params = ', '.join(f['params']) if f['params'] else ''
        ret = f['returns']
        desc = f.get('description') or ''
        line = f"• {f['name']}({params}) → {ret}"
        if desc:
            line += f' — {desc}'
        lines.append(line)
    return '\n'.join(lines)


def _examples_section(import_path: str, functions: list[dict], is_en: bool) -> str:
    if not functions:
        return 'No examples available.' if is_en else 'Pas d\'exemples disponibles.'
    lines = [
        f'import "{import_path}"',
        f'use {import_path.rsplit("/", 1)[-1]}',
        '',
    ]
    for f in functions[:6]:
        lines.append(_example_for_function(f, import_path))
        lines.append('')
    return '\n'.join(lines)


def _best_practices(mod, is_en: bool) -> str:
    if is_en:
        return (
            f'• Prefer `import "{mod.import_path}"` at the top of your file.\n'
            '• Prefer core modules (runtime-backed) over generated catalogs.\n'
            '• Run `afrilang check` and `afrilang test` before shipping.\n'
            '• Check WASM compatibility if you target the browser.\n'
            '• Report issues on GitHub if an export is missing or undocumented.'
        )
    return (
        f'• Préférez `import "{mod.import_path}"` en tête de fichier.\n'
        '• Préférez les modules core (runtime réel) aux catalogues générés.\n'
        '• Lancez `afrilang check` et `afrilang test` avant de livrer.\n'
        '• Vérifiez la compatibilité WASM si vous ciblez le navigateur.\n'
        '• Signalez les problèmes sur GitHub si une export manque.'
    )


def guide_html(mod, source: str, functions: list[dict], lang: str) -> str:
    sections = build_guide_sections(mod, source, functions, lang)
    parts = [
        f'<h1>AFRILANG — {mod.import_path}</h1>',
        f'<p><em>{"Guide PDF" if lang == "fr" else "PDF guide"} · {mod.function_count} fn</em></p>',
    ]
    for sec in sections:
        parts.append(f'<h2>{sec["title"]}</h2>')
        parts.append(f'<pre style="white-space:pre-wrap;font-family:monospace">{_esc(sec["body"])}</pre>')
    return '\n'.join(parts)


def _esc(s: str) -> str:
    return (
        s.replace('&', '&amp;')
        .replace('<', '&lt;')
        .replace('>', '&gt;')
    )
