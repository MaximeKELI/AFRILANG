#!/usr/bin/env python3
"""Génère le livre PDF ultra-détaillé AFRILANG — Maxime Dzidula KELI."""

from __future__ import annotations

import re
import sys
from pathlib import Path

from fpdf import FPDF
from fpdf.enums import XPos, YPos

ROOT = Path(__file__).resolve().parents[2]
OUT = Path(__file__).resolve().parent / "AFRILANG_Livre_Complet.pdf"

FONT_REG = "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"
FONT_BOLD = "/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf"
FONT_MONO = "/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf"

AUTHOR = "Maxime Dzidula KELI"
TEL = "98 60 00 18"
WHATSAPP = "+33 754830039"
EMAIL = "MaximeKELI25@gmail.com"
GITHUB = "https://github.com/MaximeKELI/AFRILANG"


class AfrilangBook(FPDF):
    def __init__(self) -> None:
        super().__init__(orientation="P", unit="mm", format="A4")
        self.set_auto_page_break(auto=True, margin=18)
        self.add_font("DejaVu", "", FONT_REG)
        self.add_font("DejaVu", "B", FONT_BOLD)
        self.add_font("Mono", "", FONT_MONO)
        self.chapter_title = ""
        self.show_header = False
        self.toc_entries: list[tuple[int, str, int]] = []

    def header(self) -> None:
        if not self.show_header:
            return
        self.set_font("DejaVu", "", 8)
        self.set_text_color(90, 90, 90)
        self.cell(0, 6, f"AFRILANG — Manuel complet  |  {self.chapter_title}", align="L")
        self.ln(2)
        self.set_draw_color(180, 180, 180)
        self.line(10, self.get_y(), 200, self.get_y())
        self.ln(4)
        self.set_text_color(0, 0, 0)

    def footer(self) -> None:
        if not self.show_header:
            return
        self.set_y(-14)
        self.set_font("DejaVu", "", 8)
        self.set_text_color(100, 100, 100)
        self.cell(0, 8, f"{AUTHOR}  —  Page {self.page_no()}", align="C")
        self.set_text_color(0, 0, 0)

    def start_body(self) -> None:
        self.show_header = True

    def add_toc_entry(self, level: int, title: str) -> None:
        self.toc_entries.append((level, title, self.page_no()))

    def h1(self, title: str) -> None:
        self.add_page()
        self.chapter_title = title[:80]
        self.add_toc_entry(1, title)
        self.set_font("DejaVu", "B", 18)
        self.multi_cell(0, 10, title)
        self.ln(3)
        self.set_draw_color(20, 100, 60)
        self.set_line_width(0.6)
        y = self.get_y()
        self.line(10, y, 200, y)
        self.ln(6)

    def h2(self, title: str) -> None:
        self.add_toc_entry(2, title)
        if self.get_y() > 250:
            self.add_page()
        self.set_font("DejaVu", "B", 13)
        self.ln(2)
        self.multi_cell(0, 7, title)
        self.ln(2)

    def h3(self, title: str) -> None:
        self.add_toc_entry(3, title)
        if self.get_y() > 255:
            self.add_page()
        self.set_font("DejaVu", "B", 11)
        self.ln(1)
        self.multi_cell(0, 6, title)
        self.ln(1)

    def body(self, text: str, size: float = 10) -> None:
        self.set_font("DejaVu", "", size)
        for para in text.strip().split("\n\n"):
            para = para.strip()
            if not para:
                continue
            self.multi_cell(0, 5, para)
            self.ln(2)

    def bullet(self, items: list[str], size: float = 10) -> None:
        self.set_font("DejaVu", "", size)
        for item in items:
            self.multi_cell(0, 5, f"•  {item}")
        self.ln(2)

    def code(self, text: str, size: float = 7.5) -> None:
        if self.get_y() > 250:
            self.add_page()
        self.set_fill_color(245, 245, 245)
        self.set_font("Mono", "", size)
        w = self.epw
        x0 = self.l_margin
        line_h = size * 0.45
        for line in text.replace("\t", "    ").splitlines() or [""]:
            while len(line) > 108:
                chunk, line = line[:108], line[108:]
                if self.get_y() + line_h > self.page_break_trigger:
                    self.add_page()
                self.set_x(x0)
                self.cell(w, line_h, chunk, fill=True, new_x=XPos.LMARGIN, new_y=YPos.NEXT)
            if self.get_y() + line_h > self.page_break_trigger:
                self.add_page()
            self.set_x(x0)
            self.cell(w, line_h, line, fill=True, new_x=XPos.LMARGIN, new_y=YPos.NEXT)
        self.ln(3)

    def md_file(self, path: Path, max_lines: int | None = None, mono_size: float = 7) -> None:
        if not path.exists():
            self.body(f"[Fichier manquant : {path}]")
            return
        text = path.read_text(encoding="utf-8", errors="replace")
        lines = text.splitlines()
        total = len(lines)
        if max_lines is not None and total > max_lines:
            lines = lines[:max_lines]
            lines.append("")
            lines.append(f"... [extrait {max_lines}/{total} lignes — voir {path.name}]")
        self.ingest_markdown("\n".join(lines), mono_size=mono_size)

    def ingest_markdown(self, text: str, mono_size: float = 7) -> None:
        lines = text.splitlines()
        i = 0
        in_code = False
        code_buf: list[str] = []
        while i < len(lines):
            line = lines[i]
            if line.strip().startswith("```"):
                if in_code:
                    self.code("\n".join(code_buf), size=mono_size)
                    code_buf = []
                    in_code = False
                else:
                    in_code = True
                i += 1
                continue
            if in_code:
                code_buf.append(line)
                i += 1
                continue
            if line.startswith("# "):
                self.h2(line[2:].strip())
            elif line.startswith("## "):
                self.h2(line[3:].strip())
            elif line.startswith("### ") or line.startswith("#### "):
                self.h3(line.lstrip("#").strip())
            elif re.match(r"^[-*] ", line):
                items = []
                while i < len(lines) and re.match(r"^[-*] ", lines[i]):
                    items.append(re.sub(r"^[-*] ", "", lines[i]))
                    i += 1
                self.bullet(items, size=9)
                continue
            elif line.startswith("|") and i + 1 < len(lines) and "---" in lines[i + 1]:
                table_lines = [line]
                i += 1
                while i < len(lines) and lines[i].startswith("|"):
                    table_lines.append(lines[i])
                    i += 1
                self.code("\n".join(table_lines), size=mono_size)
                continue
            elif line.strip() == "":
                self.ln(1)
            else:
                para = [line]
                i += 1
                while (
                    i < len(lines)
                    and lines[i].strip()
                    and not lines[i].startswith("#")
                    and not lines[i].startswith("```")
                    and not re.match(r"^[-*] ", lines[i])
                    and not lines[i].startswith("|")
                ):
                    para.append(lines[i])
                    i += 1
                cleaned = " ".join(p.strip() for p in para)
                cleaned = re.sub(r"`([^`]+)`", r"\1", cleaned)
                cleaned = re.sub(r"\*\*([^*]+)\*\*", r"\1", cleaned)
                cleaned = re.sub(r"\*([^*]+)\*", r"\1", cleaned)
                cleaned = re.sub(r"\[([^\]]+)\]\([^)]+\)", r"\1", cleaned)
                self.set_font("DejaVu", "", 9.5)
                self.multi_cell(0, 5, cleaned)
                self.ln(1.5)
                continue
            i += 1
        if in_code and code_buf:
            self.code("\n".join(code_buf), size=mono_size)


def cover(pdf: AfrilangBook) -> None:
    pdf.add_page()
    pdf.set_margins(15, 15, 15)
    pdf.set_x(15)
    pdf.ln(35)
    pdf.set_font("DejaVu", "B", 28)
    pdf.cell(0, 14, "AFRILANG", align="C", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
    pdf.ln(6)
    pdf.set_font("DejaVu", "B", 14)
    for line in (
        "Le langage a syntaxe naturelle",
        "qui transpile vers C++17/C++20",
    ):
        pdf.cell(0, 8, line, align="C", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
    pdf.ln(10)
    pdf.set_font("DejaVu", "", 12)
    for line in (
        "Manuel officiel ultra-detaille",
        "Guide d'utilisation - Specification du langage",
        "Bibliotheque standard - Paquets - Outils - Architecture",
        "Playground web - Extension VS Code - WASM",
    ):
        pdf.cell(0, 7, line, align="C", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
    pdf.ln(16)
    pdf.set_draw_color(20, 100, 60)
    pdf.set_line_width(0.8)
    pdf.line(60, pdf.get_y(), 150, pdf.get_y())
    pdf.ln(12)
    pdf.set_font("DejaVu", "B", 12)
    pdf.cell(0, 7, f"Auteur : {AUTHOR}", align="C", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
    pdf.set_font("DejaVu", "", 11)
    for line in (
        f"Telephone : {TEL}",
        f"WhatsApp : {WHATSAPP}",
        f"Email : {EMAIL}",
        f"GitHub : {GITHUB}",
        "Licence : MIT",
    ):
        pdf.cell(0, 6, line, align="C", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
    pdf.ln(16)
    pdf.set_font("DejaVu", "", 10)
    pdf.cell(
        0,
        5,
        "Edition 1.0 - Documentation complete de l'ecosysteme AFRILANG",
        align="C",
        new_x=XPos.LMARGIN,
        new_y=YPos.NEXT,
    )


def author_page(pdf: AfrilangBook) -> None:
    pdf.add_page()
    pdf.set_font("DejaVu", "B", 16)
    pdf.multi_cell(0, 9, "À propos de l'auteur")
    pdf.ln(4)
    pdf.body(
        f"""
{AUTHOR} est le créateur et mainteneur principal du langage AFRILANG et de son écosystème
(compilateur, bibliothèque standard, gestionnaire de paquets, serveur Language Server,
playground web Django, extension Visual Studio Code / Cursor, et application mobile Flutter).

AFRILANG poursuit un objectif clair : offrir une syntaxe naturelle, accessible en anglais
(avec alias français), tout en produisant des exécutables natifs performants via une
transpilation vers C++17/C++20.

Ce manuel regroupe la spécification du langage, les guides d'installation et d'utilisation,
la référence de la bibliothèque standard, la documentation des outils, ainsi que des
exemples commentés issus du dépôt officiel.
"""
    )
    pdf.h3("Coordonnées")
    pdf.bullet(
        [
            f"Nom : {AUTHOR}",
            f"Téléphone : {TEL}",
            f"WhatsApp : {WHATSAPP}",
            f"Email : {EMAIL}",
            f"Dépôt : {GITHUB}",
        ]
    )


def write_toc(pdf: AfrilangBook) -> None:
    pdf.add_page()
    pdf.chapter_title = "Table des matières"
    pdf.set_font("DejaVu", "B", 18)
    pdf.multi_cell(0, 10, "Table des matières")
    pdf.ln(4)
    pdf.set_font("DejaVu", "", 10)
    pdf.multi_cell(
        0,
        5,
        "L'index détaillé avec numéros de pages se trouve en fin d'ouvrage. "
        "Plan général :",
    )
    pdf.ln(3)
    pdf.bullet(
        [
            "Partie I — Vision, philosophie et architecture",
            "Partie II — Installation et premiers pas",
            "Partie III — Guide d'utilisation de la CLI",
            "Partie IV — Spécification complète du langage",
            "Partie V — Entrée utilisateur (ask) et programmes interactifs",
            "Partie VI — POO, modules, async, FFI et tests",
            "Partie VII — Guides pédagogiques (débutant → avancé)",
            "Partie VIII — Bibliothèque standard (core, simple, medium, complex)",
            "Partie IX — Gestionnaire de paquets",
            "Partie X — Outils : LSP, VS Code, WASM",
            "Partie XI — Site web Django, playground et mobile",
            "Partie XII — Tutoriels et catalogue d'exemples",
            "Partie XIII — Architecture interne du compilateur",
            "Partie XIV — Roadmap, contribution et licence",
            "Annexes — Glossaire, index des chapitres, contacts",
        ]
    )


def main() -> int:
    # Import chapter builders from companion module
    from book_chapters import build_all_chapters

    print("Génération du livre AFRILANG…", flush=True)
    pdf = AfrilangBook()
    pdf.set_title("AFRILANG — Manuel officiel ultra-détaillé")
    pdf.set_author(AUTHOR)
    pdf.set_creator("AFRILANG Book Generator")
    pdf.set_subject("Guide complet du langage AFRILANG")

    cover(pdf)
    author_page(pdf)
    write_toc(pdf)
    pdf.start_body()
    build_all_chapters(pdf, ROOT)

    OUT.parent.mkdir(parents=True, exist_ok=True)
    print(f"Écriture PDF ({pdf.page_no()} pages)…", flush=True)
    pdf.output(str(OUT))
    size_mb = OUT.stat().st_size / (1024 * 1024)
    print(f"OK → {OUT} ({pdf.page_no()} pages, {size_mb:.1f} Mo)", flush=True)
    return 0


if __name__ == "__main__":
    sys.exit(main())
