"""Recherche plein texte dans la documentation bilingue."""
from __future__ import annotations

import re

from .docs_nav import NAV_META
from .docs_pages import PAGES


def _block_text(block: dict) -> str:
    t = block.get('type')
    if t in ('h2', 'h3', 'code'):
        return str(block.get('text', ''))
    if t == 'p':
        return re.sub(r'<[^>]+>', ' ', str(block.get('html', '')))
    if t == 'ul':
        return ' '.join(str(x) for x in block.get('items', []))
    if t == 'callout':
        return re.sub(r'<[^>]+>', ' ', str(block.get('html', '')))
    if t == 'table':
        parts = block.get('headers', [])
        for row in block.get('rows', []):
            parts.extend(str(c) for c in row)
        return ' '.join(parts)
    return ''


def search_docs(query: str, lang: str) -> list[dict]:
    q = (query or '').strip().lower()
    if len(q) < 2:
        return []

    code = (lang or 'fr')[:2]
    slug_to_url = {slug: url_name for slug, url_name in NAV_META}
    results = []

    for slug, page in PAGES.items():
        data = page.get(code) or page.get('fr', {})
        title = data.get('title', '')
        lead = data.get('lead', '')
        parts = [title, lead]
        for block in data.get('blocks', []):
            parts.append(_block_text(block))
        haystack = ' '.join(parts).lower()
        if q not in haystack:
            continue
        idx = haystack.find(q)
        snippet = re.sub(r'\s+', ' ', haystack[max(0, idx - 30):idx + len(q) + 50]).strip()
        results.append({
            'url_name': slug_to_url.get(slug, 'docs_overview'),
            'title': title,
            'snippet': snippet,
        })
    return results
