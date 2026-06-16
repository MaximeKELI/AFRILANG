"""Génération PDF (5+ pages) pour chaque bibliothèque stdlib."""
from __future__ import annotations

from pathlib import Path

from django.conf import settings

from core.services.stdlib_guide import build_guide_sections
from core.services.stdlib_meta import module_source_path, parse_module_source

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


def _sanitize(text: str) -> str:
    return text.encode('latin-1', 'replace').decode('latin-1')


def _write_block(pdf, text: str, *, h: float = 5, family: str = 'Helvetica', style: str = '', size: int = 11) -> None:
    pdf.set_x(pdf.l_margin)
    pdf.set_font(family, style, size)
    w = pdf.epw
    for raw in (text or '').splitlines() or ['']:
        line = _sanitize(raw[:120])
        if not line.strip():
            pdf.ln(h * 0.4)
            continue
        pdf.set_x(pdf.l_margin)
        pdf.multi_cell(w, h, line)


def generate_pdf(mod, lang: str = 'fr') -> Path:
    src_path = module_source_path(mod.name)
    source = src_path.read_text(encoding='utf-8', errors='replace')
    parsed = parse_module_source(source)
    functions = parsed['functions']
    out = pdf_path_for(mod.name)

    try:
        from fpdf import FPDF
    except ImportError as e:
        raise RuntimeError('Installez fpdf2: pip install fpdf2') from e

    pdf = FPDF()
    pdf.set_auto_page_break(auto=True, margin=15)
    pdf.add_page()

    # Page de garde
    _write_block(pdf, 'AFRILANG Stdlib', h=10, style='B', size=20)
    pdf.ln(4)
    _write_block(pdf, mod.import_path, h=8, style='B', size=16)
    pdf.ln(4)
    desc = mod.description_fr[:800] if mod.description_fr else mod.summary
    _write_block(pdf, desc, h=6, size=11)
    pdf.ln(4)
    _write_block(
        pdf,
        f'Category: {mod.category} | Tier: {mod.tier} | Functions: {mod.function_count}',
        h=5,
        size=10,
    )
    pdf.add_page()

    for lang_code in ('fr', 'en'):
        sections = build_guide_sections(mod, source, functions, lang_code)
        label = 'FRANCAIS' if lang_code == 'fr' else 'ENGLISH'
        _write_block(pdf, label, h=8, style='B', size=14)
        pdf.ln(4)
        for sec in sections:
            _write_block(pdf, sec['title'], h=7, style='B', size=12)
            pdf.ln(2)
            _write_block(pdf, sec['body'], h=4, family='Courier', size=9)
            pdf.ln(4)
        if lang_code == 'fr':
            pdf.add_page()

    while pdf.page_no() < 5:
        pdf.add_page()
        _write_block(
            pdf,
            f'AFRILANG — {mod.import_path} — appendix page {pdf.page_no()}',
            h=5,
            size=10,
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
