"""Recherche plein texte dans la documentation bilingue."""
from __future__ import annotations

from .docs_nav import get_docs_nav
from .docs_pages import PAGES


def search_docs(query: str, lang: str) -> list[dict]:
    q = (query or '').strip().lower()
    if len(q) < 2:
        return []

    results = []
    nav = {item['url_name']: item for item in get_docs_nav(lang)}

    for url_name, langs in PAGES.items():
        page = langs.get(lang) or langs.get('fr', {})
        title = page.get('title', '')
        blocks = page.get('blocks', [])
        haystack_parts = [title]
        for block in blocks:
            if block.get('type') in ('p', 'h2', 'h3', 'li'):
                haystack_parts.append(str(block.get('text', '')))
            elif block.get('type') == 'ul':
                haystack_parts.extend(str(x) for x in block.get('items', []))
            elif block.get('type') == 'callout':
                haystack_parts.append(str(block.get('text', '')))
        haystack = ' '.join(haystack_parts).lower()
        if q in haystack:
            nav_item = nav.get(url_name, {})
            idx = haystack.find(q)
            snippet = haystack[max(0, idx - 40):idx + len(q) + 60].strip()
            results.append({
                'url_name': url_name,
                'title': title,
                'snippet': snippet,
            })
    return results
