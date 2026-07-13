"""Parse la documentation stdlib depuis docs/STDLIB_*.md et STDLIB_API.md."""
from __future__ import annotations

import re
from functools import lru_cache
from pathlib import Path

from django.conf import settings

SECTION_RE = re.compile(r'^## std/(\S+)\s*$', re.MULTILINE)
API_SECTION_RE = re.compile(r'^##\s+`std/([^`]+)`\s*$', re.MULTILINE)
FUNC_RE = re.compile(r'^-\s+`([^`]+)`', re.MULTILINE)
TABLE_FN_RE = re.compile(r'^\|\s*`([^`(]+)\([^`]*\)`\s*\|', re.MULTILINE)


@lru_cache(maxsize=1)
def _load_all_sections() -> dict[str, str]:
    root = Path(settings.AFRILANG_ROOT) / 'docs'
    sections: dict[str, str] = {}
    for name in ('STDLIB_SIMPLE.md', 'STDLIB_MEDIUM.md', 'STDLIB_COMPLEX.md'):
        path = root / name
        if not path.is_file():
            continue
        text = path.read_text(encoding='utf-8', errors='replace')
        matches = list(SECTION_RE.finditer(text))
        for i, match in enumerate(matches):
            mod_path = match.group(1)
            start = match.end()
            end = matches[i + 1].start() if i + 1 < len(matches) else len(text)
            sections[mod_path] = text[start:end].strip()

    # Priorité Vague 3 : STDLIB_API.md écrase / complète
    api_path = root / 'STDLIB_API.md'
    if api_path.is_file():
        text = api_path.read_text(encoding='utf-8', errors='replace')
        matches = list(API_SECTION_RE.finditer(text))
        for i, match in enumerate(matches):
            mod_path = match.group(1)
            start = match.end()
            end = matches[i + 1].start() if i + 1 < len(matches) else len(text)
            # stop before next ## that isn't std
            body = text[start:end].strip()
            # trim trailing global sections like ## WASM if captured wrongly
            cut = re.search(r'^##\s+(?!`)', body, re.MULTILINE)
            if cut:
                body = body[:cut.start()].strip()
            sections[mod_path] = body
    return sections


def module_doc_path(name: str) -> str:
    """Map DB module name (io, m/uuid2, c/foo) to STDLIB md path key."""
    if '/' in name:
        return name
    return name


def get_module_doc(name: str) -> dict | None:
    sections = _load_all_sections()
    body = sections.get(name)
    if not body and '/' not in name:
        # try without prefix variants
        body = sections.get(name)
    if not body:
        return None
    functions = FUNC_RE.findall(body)
    if not functions:
        functions = TABLE_FN_RE.findall(body)
    import_line = ''
    m = re.search(r'`import "([^"]+)"`', body)
    if m:
        import_line = m.group(1)
    return {
        'body': body,
        'functions': functions,
        'import_path': import_line or f'std/{name}',
        'source': 'STDLIB_API' if name in ('str', 'math', 'json') else 'STDLIB_CATALOG',
    }


def clear_doc_cache() -> None:
    _load_all_sections.cache_clear()
