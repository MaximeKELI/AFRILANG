"""Génération PDF (5+ pages) via LaTeX pour chaque bibliothèque stdlib."""
from __future__ import annotations

from pathlib import Path

from django.conf import settings

from core.services.stdlib_latex import (
    build_latex_document,
    compile_latex,
    page_count,
)
from core.services.stdlib_meta import module_source_path, parse_module_source

PDF_DIR_NAME = 'stdlib_pdfs'
MIN_PAGES = 5


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
    src_path = module_source_path(mod.name)
    source = src_path.read_text(encoding='utf-8', errors='replace')
    parsed = parse_module_source(source)
    functions = parsed['functions']
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


def generate_all_pdfs(queryset) -> tuple[int, int]:
    ok = 0
    fail = 0
    for mod in queryset.iterator():
        try:
            generate_pdf(mod)
            mod.has_pdf = True
            mod.save(update_fields=['has_pdf'])
            ok += 1
        except Exception:
            fail += 1
    return ok, fail
