"""Guides HTML multi-sections (équivalent 5+ pages imprimées)."""
from __future__ import annotations

from core.content.stdlib_catalog import category_by_id, infer_tier
from core.services.stdlib_meta import _example_for_function


def build_guide_sections(mod, source: str, functions: list[dict], lang: str) -> list[dict]:
    code = (lang or 'fr')[:2]
    is_en = code == 'en'
    cat = category_by_id(mod.category, lang) or {'label': mod.category, 'description': ''}
    tier = mod.tier or infer_tier(mod.name)

    if is_en:
        sections = [
            {
                'title': '1. Overview',
                'body': mod.description_en or mod.description_fr or mod.summary,
            },
            {
                'title': '2. Installation & import',
                'body': (
                    f'Add the module to your program:\n\n'
                    f'import "{mod.import_path}"\n'
                    f'use {mod.name.split("/")[-1]}\n\n'
                    f'Tier: {tier} · Category: {cat["label"]}\n'
                    f'{cat.get("description", "")}'
                ),
            },
            {
                'title': '3. API reference',
                'body': _api_section(functions, is_en),
            },
            {
                'title': '4. Usage examples',
                'body': _examples_section(mod.import_path, functions, is_en),
            },
            {
                'title': '5. Best practices',
                'body': _best_practices(mod, is_en),
            },
            {
                'title': '6. Appendix — source',
                'body': source[:4000] + ('\n…' if len(source) > 4000 else ''),
            },
        ]
    else:
        sections = [
            {
                'title': '1. Vue d\'ensemble',
                'body': mod.description_fr or mod.description_en or mod.summary,
            },
            {
                'title': '2. Installation & import',
                'body': (
                    f'Ajoutez le module à votre programme :\n\n'
                    f'import "{mod.import_path}"\n'
                    f'use {mod.name.split("/")[-1]}\n\n'
                    f'Niveau : {tier} · Catégorie : {cat["label"]}\n'
                    f'{cat.get("description", "")}'
                ),
            },
            {
                'title': '3. Référence API',
                'body': _api_section(functions, is_en),
            },
            {
                'title': '4. Exemples d\'utilisation',
                'body': _examples_section(mod.import_path, functions, is_en),
            },
            {
                'title': '5. Bonnes pratiques',
                'body': _best_practices(mod, is_en),
            },
            {
                'title': '6. Annexe — source',
                'body': source[:4000] + ('\n…' if len(source) > 4000 else ''),
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
        lines.append(f"• {f['name']}({params}) → {ret}")
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
            '• Run `afrilang check` before shipping.\n'
            '• Combine with related stdlib modules from the same category.\n'
            '• See /stdlib/ for the live source and playground demos.\n'
            '• Report issues on GitHub if an export is missing or undocumented.'
        )
    return (
        f'• Préférez `import "{mod.import_path}"` en tête de fichier.\n'
        '• Lancez `afrilang check` avant de livrer.\n'
        '• Combinez avec les modules stdlib de la même catégorie.\n'
        '• Voir /stdlib/ pour le source live et les démos playground.\n'
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
