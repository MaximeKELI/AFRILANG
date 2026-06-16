"""Génération PDF (5+ pages) pour chaque bibliothèque stdlib."""
from __future__ import annotations

from pathlib import Path

from django.conf import settings

from core.services.stdlib_guide import build_guide_sections, guide_html
from core.services.stdlib_meta import enrich_module, module_source_path, parse_module_source

PDF_DIR_NAME = 'stdlib_pdfs'


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


def generate_pdf(mod, lang: str = 'fr') -> Path:
    src_path = module_source_path(mod.name)
    source = src_path.read_text(encoding='utf-8', errors='replace')
    parsed = parse_module_source(source)
    functions = parsed['functions']
    out = pdf_path_for(mod.name)

    html_fr = guide_html(mod, source, functions, 'fr')
    html_en = guide_html(mod, source, functions, 'en')
    combined = f'{html_fr}<div style="page-break-before:always"></div>{html_en}'

    try:
        from fpdf import FPDF
    except ImportError as e:
        raise RuntimeError('Installez fpdf2: pip install fpdf2') from e

    pdf = FPDF()
    pdf.set_auto_page_break(auto=True, margin=15)
    pdf.add_page()
    pdf.set_font('Helvetica', size=11)

    # Page de garde
    pdf.set_font('Helvetica', 'B', 20)
    pdf.cell(text='AFRILANG Stdlib')
    pdf.ln(12)
    pdf.set_font('Helvetica', 'B', 16)
    pdf.multi_cell(0, 10, mod.import_path)
    pdf.ln(8)
    pdf.set_font('Helvetica', size=11)
    pdf.multi_cell(0, 6, mod.description_fr[:800] if mod.description_fr else mod.summary)
    pdf.ln(6)
    pdf.set_font('Helvetica', size=10)
    pdf.multi_cell(0, 5, f'Category: {mod.category} | Tier: {mod.tier} | Functions: {mod.function_count}')
    pdf.add_page()

    for lang_code in ('fr', 'en'):
        sections = build_guide_sections(mod, source, functions, lang_code)
        label = 'FRANCAIS' if lang_code == 'fr' else 'ENGLISH'
        pdf.set_font('Helvetica', 'B', 14)
        pdf.cell(text=label)
        pdf.ln(10)
        for sec in sections:
            pdf.set_font('Helvetica', 'B', 12)
            pdf.multi_cell(0, 7, sec['title'])
            pdf.ln(2)
            pdf.set_font('Courier', size=9)
            for line in sec['body'].splitlines():
                line = line[:110]
                try:
                    pdf.multi_cell(0, 4, line)
                except Exception:
                    pdf.multi_cell(0, 4, line.encode('latin-1', 'replace').decode('latin-1'))
            pdf.ln(6)
        if lang_code == 'fr':
            pdf.add_page()

    # Garantir au moins 5 pages
    while pdf.page_no() < 5:
        pdf.add_page()
        pdf.set_font('Helvetica', size=10)
        pdf.multi_cell(
            0, 5,
            f'AFRILANG — {mod.import_path} — appendix page {pdf.page_no()}',
        )

    pdf.output(str(out))
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
