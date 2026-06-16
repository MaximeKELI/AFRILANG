"""Génération de descriptions et parsing des modules stdlib."""
from __future__ import annotations

import re
from pathlib import Path

from django.conf import settings

from core.content.stdlib_catalog import infer_category, infer_tier
from core.services.stdlib_docs import get_module_doc

FUNCTION_RE = re.compile(
    r'^\s*(?:export\s+)?function\s+(\w+)\s*\(([^)]*)\)(?:\s+returns\s+(\w+))?',
    re.MULTILINE,
)
MODULE_RE = re.compile(r'^module\s+(\w+)', re.MULTILINE)


def parse_module_source(text: str) -> dict:
    functions = []
    for m in FUNCTION_RE.finditer(text):
        params = [p.strip() for p in m.group(2).split(',') if p.strip()]
        functions.append({
            'name': m.group(1),
            'params': params,
            'returns': m.group(3) or 'void',
        })
    mod_match = MODULE_RE.search(text)
    return {
        'module_name': mod_match.group(1) if mod_match else '',
        'functions': functions,
    }


def _example_for_function(func: dict, import_path: str) -> str:
    mod_use = import_path.rsplit('/', 1)[-1].replace('-', '_')
    name = func['name']
    if func['returns'] and func['returns'] != 'void':
        return f'create result = {name}(/* args */)\nsay result'
    return f'{name}(/* args */)'


def build_descriptions(
    name: str,
    import_path: str,
    functions: list[dict],
    md_body: str | None,
) -> tuple[str, str]:
    fn_list = ', '.join(f['name'] for f in functions[:8])
    if len(functions) > 8:
        fn_list += f' (+{len(functions) - 8})'

    tier = infer_tier(name)
    category = infer_category(name)

    fr = (
        f'Bibliothèque AFRILANG `{import_path}` (niveau {tier}, catégorie {category}). '
        f'Elle expose {len(functions)} fonction(s)'
    )
    if fn_list:
        fr += f' : {fn_list}'
    fr += '.\n\n'
    if md_body:
        fr += md_body.strip()[:2000]
    else:
        fr += (
            f'Import : `import "{import_path}"` puis `use` le module.\n\n'
            'Utilisez ce module pour des opérations spécialisées dans son domaine. '
            'Consultez le guide PDF pour la référence complète, des exemples et les bonnes pratiques.'
        )

    en = (
        f'AFRILANG library `{import_path}` (tier {tier}, category {category}). '
        f'Exports {len(functions)} function(s)'
    )
    if fn_list:
        en += f': {fn_list}'
    en += '.\n\n'
    if md_body:
        en += md_body.strip()[:2000]
    else:
        en += (
            f'Import: `import "{import_path}"` then `use` the module.\n\n'
            'Use this module for specialized operations in its domain. '
            'See the PDF guide for full reference, examples and best practices.'
        )

    return fr, en


def enrich_module(name: str, source_text: str) -> dict:
    parsed = parse_module_source(source_text)
    functions = parsed['functions']
    import_path = f'std/{name}'
    doc = get_module_doc(name)
    md_body = doc['body'] if doc else None
    desc_fr, desc_en = build_descriptions(name, import_path, functions, md_body)

    summary = ''
    if functions:
        preview = ', '.join(f['name'] for f in functions[:4])
        if len(functions) > 4:
            preview += f' (+{len(functions) - 4})'
        summary = preview

    return {
        'import_path': import_path,
        'summary': summary[:512],
        'description_fr': desc_fr,
        'description_en': desc_en,
        'category': infer_category(name),
        'tier': infer_tier(name),
        'function_count': len(functions),
        'functions': functions,
    }


def module_source_path(name: str) -> Path:
    return Path(settings.AFRILANG_ROOT) / 'stdlib' / f'{name}.afr'
