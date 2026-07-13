"""Génération de descriptions et parsing des modules stdlib."""
from __future__ import annotations

import re
from pathlib import Path

from django.conf import settings

from core.content.stdlib_catalog import infer_category, infer_tier
from core.content.stdlib_core_api import (
    CORE_MODULE_NAMES,
    enrich_functions_with_roles,
    get_core_functions,
    get_prose,
    is_core_module_name,
    related_links,
    wasm_note,
)
from core.services.stdlib_docs import get_module_doc

FUNCTION_RE = re.compile(
    r'^\s*(?:export\s+)?function\s+(\w+)\s*\(([^)]*)\)(?:\s+returns\s+(.+?))?\s*$',
    re.MULTILINE,
)
MODULE_RE = re.compile(r'^module\s+(\w+)', re.MULTILINE)


def parse_module_source(text: str) -> dict:
    functions = []
    for m in FUNCTION_RE.finditer(text):
        params = [p.strip() for p in m.group(2).split(',') if p.strip()]
        ret = (m.group(3) or 'void').strip()
        functions.append({
            'name': m.group(1),
            'params': params,
            'returns': ret,
        })
    mod_match = MODULE_RE.search(text)
    return {
        'module_name': mod_match.group(1) if mod_match else '',
        'functions': functions,
    }


def _example_for_function(func: dict, import_path: str) -> str:
    name = func['name']
    if func['returns'] and func['returns'] != 'void':
        return f'create result = {name}(/* args */)\nsay result'
    return f'{name}(/* args */)'


def resolve_functions(name: str, source_text: str | None = None) -> list[dict]:
    """Priorité : registry C++ (core) si plus complet → source .afr → MD."""
    source_fns: list[dict] = []
    if source_text:
        source_fns = parse_module_source(source_text)['functions']
    core_fns = get_core_functions(name)
    # Le registre est la source de vérité pour le core (stubs .afr souvent incomplets)
    if core_fns and (not source_fns or len(core_fns) >= len(source_fns)):
        return core_fns
    if source_fns:
        return source_fns
    doc = get_module_doc(name)
    if not doc:
        return []
    out = []
    for sig in doc['functions']:
        m = re.match(r'^(\w+)\s*\(([^)]*)\)(?:\s*→\s*(.+))?$', sig.strip())
        if not m:
            if re.match(r'^\w+$', sig.strip()):
                out.append({'name': sig.strip(), 'params': [], 'returns': '…'})
            continue
        params = [p.strip() for p in m.group(2).split(',') if p.strip()]
        out.append({
            'name': m.group(1),
            'params': params,
            'returns': (m.group(3) or '…').strip(),
        })
    return out


def build_descriptions(
    name: str,
    import_path: str,
    functions: list[dict],
    md_body: str | None,
) -> tuple[str, str]:
    prose = get_prose(name)
    if prose:
        fr = (
            f'{prose["summary_fr"]}\n\n{prose["body_fr"]}\n\n'
            f'Import : `import "{import_path}"` puis `use {name.split("/")[-1]}`.'
        )
        en = (
            f'{prose["summary_en"]}\n\n{prose["body_en"]}\n\n'
            f'Import: `import "{import_path}"` then `use {name.split("/")[-1]}`.'
        )
        return fr, en

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
            'Consultez le guide pour la référence complète et des exemples.'
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
            'See the guide for full reference and examples.'
        )

    return fr, en


def enrich_module(name: str, source_text: str = '') -> dict:
    functions = resolve_functions(name, source_text or None)
    import_path = f'std/{name}'
    doc = get_module_doc(name)
    md_body = doc['body'] if doc else None
    desc_fr, desc_en = build_descriptions(name, import_path, functions, md_body)
    prose = get_prose(name)

    summary = ''
    if prose:
        summary = prose['summary_fr'][:512]
    elif functions:
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
        'tier': 'core' if is_core_module_name(name) else infer_tier(name),
        'function_count': len(functions),
        'functions': functions,
        'is_core': is_core_module_name(name),
    }


def module_source_path(name: str) -> Path:
    return Path(settings.AFRILANG_ROOT) / 'stdlib' / f'{name}.afr'


def read_module_source(name: str) -> str | None:
    path = module_source_path(name)
    if path.is_file():
        return path.read_text(encoding='utf-8', errors='replace')
    return None


def synthetic_source(name: str, functions: list[dict]) -> str:
    """Source affichable quand le .afr est absent (core injecté)."""
    base = name.split('/')[-1]
    lines = [f'module {base}', '']
    for fn in functions:
        params = ', '.join(fn['params'])
        ret = fn.get('returns') or 'void'
        if ret and ret != 'void':
            lines.append(f'function {fn["name"]}({params}) returns {ret}')
        else:
            lines.append(f'function {fn["name"]}({params})')
        lines.append('end')
        lines.append('')
    lines.append('end')
    return '\n'.join(lines)


def build_page_context(mod, lang: str = 'fr') -> dict:
    """Données riches pour la page détail / guide."""
    source = read_module_source(mod.name)
    functions = resolve_functions(mod.name, source)
    functions = enrich_functions_with_roles(mod.name, functions, lang)
    doc = get_module_doc(mod.name)
    prose = get_prose(mod.name)
    is_en = (lang or 'fr')[:2] == 'en'
    example = ''
    if prose and prose.get('example'):
        example = prose['example']
    elif functions:
        use_name = mod.name.split('/')[-1]
        example = (
            f'import "{mod.import_path}"\n'
            f'use {use_name}\n\n'
            + '\n'.join(_example_for_function(f, mod.import_path) for f in functions[:4])
        )

    display_source = source
    source_label = f'{mod.name}.afr'
    source_note = None
    if not display_source:
        display_source = synthetic_source(mod.name, functions)
        source_label = 'registry (injecté)'
        source_note = (
            'Signatures provenant du registre compilateur (pas de stub .afr sur disque).'
            if not is_en else
            'Signatures from the compiler registry (no on-disk .afr stub).'
        )
    elif len(functions) == 0:
        # stub vide — compléter via registry pour l’UI
        functions = enrich_functions_with_roles(mod.name, get_core_functions(mod.name), lang)

    overview = ''
    if prose:
        overview = prose['body_en' if is_en else 'body_fr']
    elif is_en:
        overview = mod.description_en or mod.description_fr
    else:
        overview = mod.description_fr or mod.description_en

    return {
        'functions': functions,
        'doc': doc,
        'prose': prose,
        'example': example,
        'source': display_source,
        'source_label': source_label,
        'source_note': source_note,
        'has_real_source': source is not None,
        'overview': overview,
        'domain': (prose or {}).get('domain_en' if is_en else 'domain_fr', ''),
        'wasm_note': wasm_note(mod.name, lang),
        'links': related_links(mod.name),
        'is_core': bool(getattr(mod, 'is_core', False) or is_core_module_name(mod.name)),
        'use_name': mod.name.split('/')[-1],
    }
