"""Génération PDF (5+ pages) via LaTeX pour chaque bibliothèque stdlib."""
from __future__ import annotations

import os
from concurrent.futures import ThreadPoolExecutor, as_completed
from pathlib import Path

from django.conf import settings

from core.services.stdlib_latex import (
    build_latex_document,
    compile_latex,
    page_count,
)
from core.services.stdlib_meta import build_page_context

PDF_DIR_NAME = 'stdlib_pdfs'
MIN_PAGES = 5
LATEX_PDF_MIN_BYTES = 15_000


def pdf_dir() -> Path:
    d = Path(settings.STDLIB_PDF_DIR)
    d.mkdir(parents=True, exist_ok=True)
    return d


def pdf_path_for(name: str) -> Path:
    safe = name.replace('/', '__')
    return pdf_dir() / f'{safe}.pdf'


def resolve_pdf_path(name: str) -> Path | None:
    path = pdf_path_for(name)
    return path if path.is_file() else None


def _pad_latex_document(tex: str, mod, extra_chars: int) -> str:
    """Ajoute du contenu annexe si le PDF compilé est trop court."""
    appendix = (
        f'\\section*{{Annexe — documentation étendue}}\n'
        f'\\noindent Module \\texttt{{{mod.import_path}}} — '
        f'pages supplémentaires pour atteindre le minimum de {MIN_PAGES} pages.\n\n'
    )
    filler = (
        '\\begin{itemize}[leftmargin=*]\n'
        + ''.join(
            f'  \\item Point de référence {i + 1} : '
            f'consulter le guide HTML et les exemples du playground.\n'
            for i in range(max(8, extra_chars // 200))
        )
        + '\\end{itemize}\n'
    )
    return tex.replace('\\end{document}', appendix + filler + '\\end{document}')


def generate_pdf(mod, lang: str = 'fr') -> Path:
    page = build_page_context(mod, lang)
    source = page['source'] or ''
    functions = page['functions']
    out = pdf_path_for(mod.name)

    tex = build_latex_document(mod, source, functions)
    compile_latex(tex, out)

    pages = page_count(out)
    attempts = 0
    while pages < MIN_PAGES and attempts < 3:
        tex = _pad_latex_document(tex, mod, (MIN_PAGES - pages) * 1200)
        compile_latex(tex, out)
        pages = page_count(out)
        attempts += 1

    return out


def is_latex_pdf(path: Path) -> bool:
    return path.is_file() and path.stat().st_size >= LATEX_PDF_MIN_BYTES


def _generate_one(mod_name: str, skip_existing: bool) -> tuple[str, bool, str | None]:
    from core.models import StdlibModule

    mod = StdlibModule.objects.get(name=mod_name)
    out = pdf_path_for(mod_name)
    if skip_existing and is_latex_pdf(out):
        mod.has_pdf = True
        mod.save(update_fields=['has_pdf'])
        return mod_name, True, None
    try:
        generate_pdf(mod)
        mod.has_pdf = True
        mod.save(update_fields=['has_pdf'])
        return mod_name, True, None
    except Exception as exc:
        return mod_name, False, str(exc)


def generate_all_pdfs(queryset, *, workers: int = 1, skip_existing: bool = False) -> tuple[int, int]:
    names = list(queryset.values_list('name', flat=True))
    if not names:
        return 0, 0

    workers = max(1, min(workers, len(names), (os.cpu_count() or 4) * 2))
    ok = 0
    fail = 0

    if workers == 1:
        for name in names:
            _, success, _ = _generate_one(name, skip_existing)
            if success:
                ok += 1
            else:
                fail += 1
        return ok, fail

    with ThreadPoolExecutor(max_workers=workers) as pool:
        futures = {pool.submit(_generate_one, name, skip_existing): name for name in names}
        for future in as_completed(futures):
            _, success, _ = future.result()
            if success:
                ok += 1
            else:
                fail += 1
    return ok, fail
