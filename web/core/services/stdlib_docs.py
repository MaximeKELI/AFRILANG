"""Parse la documentation stdlib depuis docs/STDLIB_*.md."""
from __future__ import annotations

import re
from functools import lru_cache
from pathlib import Path

from django.conf import settings

SECTION_RE = re.compile(r'^## std/(\S+)\s*$', re.MULTILINE)
FUNC_RE = re.compile(r'^-\s+`([^`]+)`', re.MULTILINE)


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
    return sections


def module_doc_path(name: str) -> str:
    """Map DB module name (io, m/uuid2, c/foo) to STDLIB md path key."""
    if '/' in name:
        return name
    return name


def get_module_doc(name: str) -> dict | None:
    sections = _load_all_sections()
    body = sections.get(name)
    if not body:
        return None
    functions = FUNC_RE.findall(body)
    import_line = ''
    m = re.search(r'`import "([^"]+)"`', body)
    if m:
        import_line = m.group(1)
    return {
        'body': body,
        'functions': functions,
        'import_path': import_line or f'std/{name}',
    }
