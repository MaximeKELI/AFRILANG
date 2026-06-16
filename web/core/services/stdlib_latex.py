"""Génération de documents LaTeX pour les guides stdlib."""
from __future__ import annotations

import os
import re
import shutil
import subprocess
import tempfile
from pathlib import Path

from django.conf import settings

from core.content.stdlib_catalog import category_by_id
from core.services.stdlib_guide import build_guide_sections

LATEX_PREAMBLE = r"""
\documentclass[11pt,a4paper]{article}
\usepackage{fontspec}
\usepackage[french,english]{babel}
\usepackage{geometry}
\usepackage{listings}
\usepackage{hyperref}
\usepackage{enumitem}
\usepackage{fancyhdr}
\usepackage{titlesec}
\usepackage{xcolor}

\geometry{margin=2.4cm}
\setmainfont{DejaVu Serif}
\setsansfont{DejaVu Sans}
\setmonofont{DejaVu Sans Mono}

\definecolor{afrblue}{HTML}{1a5fb4}
\definecolor{afrgray}{HTML}{f4f6f8}
\hypersetup{colorlinks=true, linkcolor=afrblue, urlcolor=afrblue}

\pagestyle{fancy}
\fancyhf{}
\fancyhead[L]{\small\textsf{AFRILANG Stdlib}}
\fancyhead[R]{\small\textsf{\leftmark}}
\fancyfoot[C]{\thepage}
\renewcommand{\headrulewidth}{0.4pt}

\titleformat{\section}{\Large\bfseries\color{afrblue}}{}{0em}{}
\titleformat{\subsection}{\large\bfseries}{}{0em}{}

\lstset{
  basicstyle=\ttfamily\footnotesize,
  breaklines=true,
  breakatwhitespace=false,
  frame=single,
  rulecolor=\color{afrblue},
  backgroundcolor=\color{afrgray},
  columns=fullflexible,
  keepspaces=true,
  showstringspaces=false,
  tabsize=2,
  escapeinside={(*@}{@*)},
}
"""


def _latex_escape(text: str) -> str:
    if not text:
        return ''
    replacements = (
        ('\\', r'\textbackslash{}'),
        ('&', r'\&'),
        ('%', r'\%'),
        ('$', r'\$'),
        ('#', r'\#'),
        ('_', r'\_'),
        ('{', r'\{'),
        ('}', r'\}'),
        ('~', r'\textasciitilde{}'),
        ('^', r'\textasciicircum{}'),
    )
    for old, new in replacements:
        text = text.replace(old, new)
    return text


def _latex_listing(code: str) -> str:
    body = (code or '').replace('\r\n', '\n').replace('\r', '\n')
    end_marker = '\\end{lstlisting}'
    if end_marker in body:
        body = body.replace(end_marker, '(*@\\end{lstlisting}@*)')
    escaped_lines = []
    for line in body.split('\n'):
        line = (
            line.replace('\\', '(*@\\textbackslash{}@*)')
            .replace('{', '(*@\\{@*)')
            .replace('}', '(*@\\}@*)')
            .replace('_', '(*@\\_@*)')
            .replace('#', '(*@\\#@*)')
            .replace('$', '(*@\\$@*)')
            .replace('%', '(*@\\%@*)')
            .replace('&', '(*@\\&@*)')
        )
        escaped_lines.append(line)
    body = '\n'.join(escaped_lines)
    return f'\\begin{{lstlisting}}\n{body}\n\\end{{lstlisting}}'


def _latex_paragraph(text: str) -> str:
    parts = []
    for para in re.split(r'\n\s*\n', text or ''):
        para = para.strip()
        if not para:
            continue
        if '\n' in para:
            parts.append(_latex_listing(para))
        else:
            parts.append(_latex_escape(para))
    return '\n\n'.join(parts) if parts else ''


def _lang_block(sections: list[dict], lang_label: str) -> str:
    chunks = [f'\\section*{{{_latex_escape(lang_label)}}}']
    for sec in sections:
        chunks.append(f'\\subsection*{{{_latex_escape(sec["title"])}}}')
        chunks.append(_latex_paragraph(sec['body']))
        chunks.append('')
    return '\n'.join(chunks)


def build_latex_document(mod, source: str, functions: list[dict]) -> str:
    cat_fr = category_by_id(mod.category, 'fr') or {'label': mod.category}
    cat_en = category_by_id(mod.category, 'en') or {'label': mod.category}
    desc_fr = mod.description_fr or mod.summary or ''
    desc_en = mod.description_en or mod.description_fr or mod.summary or ''
    sections_fr = build_guide_sections(mod, source, functions, 'fr')
    sections_en = build_guide_sections(mod, source, functions, 'en')
    import_path_tex = _latex_escape(mod.import_path)
    source_excerpt = source[:6000]
    if len(source) > 6000:
        source_excerpt += '\n…'
    source_block = _latex_listing(source_excerpt)

    body = f"""
\\begin{{document}}
\\begin{{titlepage}}
  \\centering
  \\vspace*{{2cm}}
  {{\\Huge\\bfseries\\color{{afrblue}} AFRILANG Stdlib\\par}}
  \\vspace{{1.2cm}}
  {{\\LARGE\\texttt{{{import_path_tex}}}\\par}}
  \\vspace{{1.5cm}}
  \\begin{{minipage}}{{0.85\\textwidth}}
    \\textbf{{Français.}} {_latex_escape(desc_fr[:600])}
    \\medskip
    \\textbf{{English.}} {_latex_escape(desc_en[:600])}
  \\end{{minipage}}
  \\vfill
  \\begin{{tabular}}{{rl}}
    Catégorie / Category & {_latex_escape(cat_fr['label'])} \\\\
    Niveau / Tier & {_latex_escape(mod.tier)} \\\\
    Fonctions / Functions & {mod.function_count} \\\\
  \\end{{tabular}}
  \\vspace{{1cm}}
  {{\\large \\today\\par}}
\\end{{titlepage}}

\\tableofcontents
\\clearpage

{_lang_block(sections_fr, 'Français')}
\\clearpage
{_lang_block(sections_en, 'English')}

\\appendix
\\section*{{Référence rapide / Quick reference}}
\\begin{{itemize}}[leftmargin=*]
  \\item Import : \\texttt{{import "{import_path_tex}"}}
  \\item Vérification : \\texttt{{afrilang check}}
  \\item Documentation : \\url{{https://afrilang.dev/stdlib/{import_path_tex}/}}
\\end{{itemize}}

\\section*{{Source (extrait)}}
{source_block}

\\end{{document}}
"""
    return LATEX_PREAMBLE + body


def find_latex_engine() -> tuple[str, str]:
    """Retourne (chemin, type) avec type dans tectonic, xelatex, pdflatex."""
    explicit = os.environ.get('TECTONIC_BIN') or os.environ.get('LATEX_ENGINE_BIN')
    if explicit and Path(explicit).is_file():
        name = Path(explicit).name
        kind = 'tectonic' if 'tectonic' in name else name
        return explicit, kind

    configured = getattr(settings, 'TECTONIC_BIN', '')
    if configured and Path(configured).is_file():
        return configured, 'tectonic'

    for candidate in (
        shutil.which('tectonic'),
        str(Path(settings.BASE_DIR) / 'tectonic'),
        str(Path(settings.BASE_DIR) / 'bin' / 'tectonic'),
        shutil.which('xelatex'),
        shutil.which('pdflatex'),
    ):
        if candidate and Path(candidate).is_file():
            kind = 'tectonic' if 'tectonic' in Path(candidate).name else Path(candidate).name
            return candidate, kind

    raise RuntimeError(
        'Moteur LaTeX introuvable. Installez Tectonic '
        '(curl -fsSL https://drop-sh.fullyjustified.net | sh) '
        'ou texlive-xetex (apt install texlive-xetex texlive-lang-french).'
    )


def compile_latex(tex_source: str, output_pdf: Path) -> Path:
    engine, kind = find_latex_engine()
    output_pdf.parent.mkdir(parents=True, exist_ok=True)

    with tempfile.TemporaryDirectory(prefix='afrilang-latex-') as tmp:
        work = Path(tmp)
        tex_path = work / 'guide.tex'
        tex_path.write_text(tex_source, encoding='utf-8')

        if kind == 'tectonic':
            cmd = [engine, '--synctex', str(tex_path)]
            result = subprocess.run(cmd, cwd=work, capture_output=True, text=True, timeout=180)
        else:
            cmd = [
                engine,
                '-interaction=nonstopmode',
                '-halt-on-error',
                '-output-directory',
                str(work),
                str(tex_path.name),
            ]
            result = subprocess.run(cmd, cwd=work, capture_output=True, text=True, timeout=180)
            if result.returncode == 0:
                subprocess.run(cmd, cwd=work, capture_output=True, text=True, timeout=180)

        pdf_path = work / 'guide.pdf'
        if not pdf_path.is_file():
            log = work / 'guide.log'
            detail = ''
            if log.is_file():
                detail = log.read_text(encoding='utf-8', errors='replace')[-2500:]
            stderr = (result.stderr or '')[-1500:]
            stdout = (result.stdout or '')[-1500:]
            raise RuntimeError(
                f'Compilation LaTeX échouée ({kind}).\n{stderr}\n{stdout}\n{detail}'
            )

        output_pdf.write_bytes(pdf_path.read_bytes())
    return output_pdf


def page_count(pdf_path: Path) -> int:
    try:
        result = subprocess.run(
            ['pdfinfo', str(pdf_path)],
            capture_output=True,
            text=True,
            timeout=10,
        )
        for line in result.stdout.splitlines():
            if line.startswith('Pages:'):
                return int(line.split(':', 1)[1].strip())
    except (FileNotFoundError, ValueError, subprocess.TimeoutExpired):
        pass
    return 0
