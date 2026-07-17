#!/usr/bin/env python3
"""Livre AFRILANG — edition luxe, premiere personne (Maxime Dzidula KELI)."""

from __future__ import annotations

import re
import sys
from pathlib import Path

from fpdf import FPDF
from fpdf.enums import XPos, YPos

ROOT = Path(__file__).resolve().parents[2]
OUT = Path(__file__).resolve().parent / "AFRILANG_Livre_Complet.pdf"

SERIF = "/usr/share/fonts/truetype/dejavu/DejaVuSerif.ttf"
SERIF_B = "/usr/share/fonts/truetype/dejavu/DejaVuSerif-Bold.ttf"
SANS = "/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf"
SANS_B = "/usr/share/fonts/truetype/dejavu/DejaVuSans-Bold.ttf"
MONO = "/usr/share/fonts/truetype/dejavu/DejaVuSansMono.ttf"

AUTHOR = "Maxime Dzidula KELI"
TEL = "98 60 00 18"
WHATSAPP = "+33 754830039"
EMAIL = "MaximeKELI25@gmail.com"

# Palette luxe
INK = (11, 29, 42)          # bleu encre
IVORY = (247, 243, 235)     # ivoire
GOLD = (184, 148, 74)       # or mat
GOLD_SOFT = (212, 186, 120)
CHARCOAL = (45, 42, 38)
MUTED = (110, 100, 88)
RULE = (196, 180, 150)


class AfrilangBook(FPDF):
    def __init__(self) -> None:
        super().__init__(orientation="P", unit="mm", format="A4")
        self.set_auto_page_break(auto=True, margin=22)
        self.set_margins(18, 22, 18)
        self.add_font("Serif", "", SERIF)
        self.add_font("Serif", "B", SERIF_B)
        self.add_font("Sans", "", SANS)
        self.add_font("Sans", "B", SANS_B)
        self.add_font("Mono", "", MONO)
        self.chapter_title = ""
        self.part_label = ""
        self.show_chrome = False
        self.toc_entries: list[tuple[int, str, int]] = []
        self._cream = True

    def _paint_page(self) -> None:
        if self._cream:
            self.set_fill_color(*IVORY)
            self.rect(0, 0, 210, 297, "F")
        # fine gold side accent
        if self.show_chrome:
            self.set_fill_color(*GOLD)
            self.rect(0, 0, 2.2, 297, "F")

    def header(self) -> None:
        self._paint_page()
        if not self.show_chrome:
            return
        self.set_y(10)
        self.set_font("Sans", "", 7.5)
        self.set_text_color(*MUTED)
        left = "AFRILANG  ·  Manuel de reference"
        right = (self.chapter_title or "")[:55]
        self.set_x(self.l_margin)
        self.cell(self.epw * 0.55, 5, left, align="L")
        self.cell(self.epw * 0.45, 5, right, align="R", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
        self.set_draw_color(*GOLD)
        self.set_line_width(0.35)
        y = self.get_y() + 1
        self.line(self.l_margin, y, self.l_margin + self.epw, y)
        self.set_draw_color(*RULE)
        self.set_line_width(0.15)
        self.line(self.l_margin, y + 1.1, self.l_margin + self.epw, y + 1.1)
        self.ln(6)
        self.set_text_color(*CHARCOAL)

    def footer(self) -> None:
        if not self.show_chrome:
            return
        self.set_y(-16)
        self.set_draw_color(*GOLD)
        self.set_line_width(0.25)
        self.line(self.l_margin, self.get_y(), self.l_margin + self.epw, self.get_y())
        self.ln(2)
        self.set_font("Sans", "", 8)
        self.set_text_color(*MUTED)
        self.set_x(self.l_margin)
        self.cell(self.epw / 3, 6, AUTHOR, align="L")
        self.cell(self.epw / 3, 6, f"—  {self.page_no()}  —", align="C")
        self.cell(self.epw / 3, 6, "Edition luxe", align="R")
        self.set_text_color(*CHARCOAL)

    def start_body(self) -> None:
        self.show_chrome = True

    def add_toc_entry(self, level: int, title: str) -> None:
        self.toc_entries.append((level, title, self.page_no()))

    def ornament(self) -> None:
        self.ln(2)
        self.set_draw_color(*GOLD)
        self.set_line_width(0.4)
        cx = self.l_margin + self.epw / 2
        self.line(cx - 28, self.get_y(), cx - 6, self.get_y())
        self.line(cx + 6, self.get_y(), cx + 28, self.get_y())
        self.set_fill_color(*GOLD)
        self.ellipse(cx - 1.6, self.get_y() - 1.6, 3.2, 3.2, "F")
        self.ln(6)

    def part_opener(self, roman: str, title: str, subtitle: str) -> None:
        self.show_chrome = False
        self._cream = False
        self.add_page()
        self.set_fill_color(*INK)
        self.rect(0, 0, 210, 297, "F")
        # gold frame
        self.set_draw_color(*GOLD)
        self.set_line_width(0.8)
        self.rect(12, 12, 186, 273)
        self.set_line_width(0.25)
        self.rect(15, 15, 180, 267)
        self.set_y(88)
        self.set_text_color(*GOLD_SOFT)
        self.set_font("Sans", "", 11)
        self.cell(0, 8, f"PARTIE  {roman}", align="C", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
        self.ln(8)
        self.set_text_color(*IVORY)
        self.set_font("Serif", "B", 26)
        self.set_x(28)
        self.multi_cell(154, 12, title, align="C")
        self.ln(10)
        self.set_draw_color(*GOLD)
        self.set_line_width(0.4)
        self.line(70, self.get_y(), 140, self.get_y())
        self.ln(10)
        self.set_font("Serif", "", 12)
        self.set_text_color(*GOLD_SOFT)
        self.set_x(35)
        self.multi_cell(140, 7, subtitle, align="C")
        self.set_text_color(*CHARCOAL)
        self._cream = True
        self.show_chrome = True
        self.part_label = title
        self.add_toc_entry(1, f"Partie {roman} — {title}")

    def h1(self, title: str) -> None:
        self.add_page()
        self.set_x(self.l_margin)
        self.chapter_title = title[:70]
        self.add_toc_entry(1, title)
        self.set_font("Sans", "", 9)
        self.set_text_color(*GOLD)
        self.cell(0, 5, "CHAPITRE", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
        self.set_text_color(*INK)
        self.set_font("Serif", "B", 20)
        self.multi_cell(self.epw, 10, title)
        self.ornament()
        self.set_text_color(*CHARCOAL)

    def h2(self, title: str) -> None:
        self.add_toc_entry(2, title)
        if self.get_y() > 248:
            self.add_page()
        self.ln(3)
        self.set_x(self.l_margin)
        self.set_font("Serif", "B", 13)
        self.set_text_color(*INK)
        self.multi_cell(self.epw, 7, title)
        self.set_draw_color(*GOLD)
        self.set_line_width(0.3)
        self.line(self.l_margin, self.get_y(), self.l_margin + 36, self.get_y())
        self.ln(4)
        self.set_text_color(*CHARCOAL)

    def h3(self, title: str) -> None:
        self.add_toc_entry(3, title)
        if self.get_y() > 252:
            self.add_page()
        self.ln(2)
        self.set_x(self.l_margin)
        self.set_font("Serif", "B", 11)
        self.set_text_color(*INK)
        self.multi_cell(self.epw, 6, title)
        self.ln(2)
        self.set_text_color(*CHARCOAL)

    def body(self, text: str, size: float = 10.5) -> None:
        self.set_font("Serif", "", size)
        self.set_text_color(*CHARCOAL)
        for para in text.strip().split("\n\n"):
            para = " ".join(para.split())
            if not para:
                continue
            self.set_x(self.l_margin)
            self.multi_cell(self.epw, 5.6, para)
            self.ln(2.5)

    def bullet(self, items: list[str], size: float = 10) -> None:
        self.set_font("Serif", "", size)
        for item in items:
            self.set_x(self.l_margin)
            self.set_text_color(*GOLD)
            self.cell(5, 5.4, "◆")
            self.set_text_color(*CHARCOAL)
            self.multi_cell(self.epw - 5, 5.4, item)
            self.ln(0.8)
        self.ln(2)

    def definition(self, term: str, meaning: str) -> None:
        if self.get_y() > 240:
            self.add_page()
        x = self.l_margin
        y0 = self.get_y()
        self.set_fill_color(252, 249, 242)
        # estimate box later by drawing after text — simple left bar + fill strip
        self.set_draw_color(*GOLD)
        self.set_line_width(1.2)
        self.set_x(x)
        self.set_font("Sans", "B", 9)
        self.set_text_color(*GOLD)
        self.cell(self.epw, 5, "DÉFINITION", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
        self.set_font("Serif", "B", 11)
        self.set_text_color(*INK)
        self.set_x(x + 3)
        self.multi_cell(self.epw - 3, 6, term)
        self.set_font("Serif", "", 10)
        self.set_text_color(*CHARCOAL)
        self.set_x(x + 3)
        self.multi_cell(self.epw - 3, 5.3, meaning)
        y1 = self.get_y()
        self.set_draw_color(*GOLD)
        self.set_line_width(1.4)
        self.line(x, y0, x, y1)
        self.ln(4)

    def callout(self, title: str, text: str) -> None:
        if self.get_y() > 235:
            self.add_page()
        self.set_fill_color(236, 242, 245)
        self.set_x(self.l_margin)
        y0 = self.get_y()
        self.set_font("Sans", "B", 9)
        self.set_text_color(*INK)
        self.cell(self.epw, 5, title.upper(), new_x=XPos.LMARGIN, new_y=YPos.NEXT)
        self.set_font("Serif", "", 10)
        self.set_text_color(*CHARCOAL)
        self.set_x(self.l_margin + 2)
        self.multi_cell(self.epw - 2, 5.2, " ".join(text.split()))
        self.ln(3)

    def code(self, text: str, size: float = 7.2, caption: str = "") -> None:
        if self.get_y() > 245:
            self.add_page()
        if caption:
            self.set_font("Sans", "", 8)
            self.set_text_color(*MUTED)
            self.set_x(self.l_margin)
            self.cell(self.epw, 4, caption, new_x=XPos.LMARGIN, new_y=YPos.NEXT)
        self.set_fill_color(18, 32, 44)
        self.set_text_color(232, 220, 190)
        self.set_font("Mono", "", size)
        w = self.epw
        x0 = self.l_margin
        line_h = size * 0.48

        def clean(s: str) -> str:
            return "".join(ch if (ord(ch) >= 32 or ch in "\t") else " " for ch in s)

        for line in text.replace("\t", "    ").splitlines() or [""]:
            line = clean(line)
            while len(line) > 100:
                chunk, line = line[:100], line[100:]
                if self.get_y() + line_h > self.page_break_trigger:
                    self.add_page()
                self.set_x(x0)
                self.cell(w, line_h + 0.6, "  " + chunk, fill=True, new_x=XPos.LMARGIN, new_y=YPos.NEXT)
            if self.get_y() + line_h > self.page_break_trigger:
                self.add_page()
            self.set_x(x0)
            self.cell(w, line_h + 0.6, "  " + line, fill=True, new_x=XPos.LMARGIN, new_y=YPos.NEXT)
        self.set_text_color(*CHARCOAL)
        self.ln(4)

    def md_file(self, path: Path, max_lines: int | None = None, mono_size: float = 6.8) -> None:
        if not path.exists():
            self.body(f"[Document manquant : {path.name}]")
            return
        text = path.read_text(encoding="utf-8", errors="replace")
        lines = text.splitlines()
        total = len(lines)
        if max_lines is not None and total > max_lines:
            lines = lines[:max_lines] + ["", f"... [suite du document — {total} lignes au total]"]
        self.ingest_markdown("\n".join(lines), mono_size=mono_size)

    def ingest_markdown(self, text: str, mono_size: float = 6.8) -> None:
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
                self.bullet(items, size=9.5)
                continue
            elif line.startswith("|") and i + 1 < len(lines) and "---" in lines[i + 1]:
                table_lines = [line]
                i += 1
                while i < len(lines) and lines[i].startswith("|"):
                    table_lines.append(lines[i])
                    i += 1
                self.code("\n".join(table_lines), size=mono_size)
                continue
            elif not line.strip():
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
                self.set_font("Serif", "", 10)
                self.set_text_color(*CHARCOAL)
                self.set_x(self.l_margin)
                self.multi_cell(self.epw, 5.4, cleaned)
                self.ln(1.8)
                continue
            i += 1
        if in_code and code_buf:
            self.code("\n".join(code_buf), size=mono_size)


def cover(pdf: AfrilangBook) -> None:
    pdf.show_chrome = False
    pdf._cream = False
    pdf.add_page()
    pdf.set_fill_color(*INK)
    pdf.rect(0, 0, 210, 297, "F")
    pdf.set_draw_color(*GOLD)
    pdf.set_line_width(1.0)
    pdf.rect(10, 10, 190, 277)
    pdf.set_line_width(0.3)
    pdf.rect(14, 14, 182, 269)

    pdf.set_y(42)
    pdf.set_font("Sans", "", 10)
    pdf.set_text_color(*GOLD_SOFT)
    pdf.cell(0, 6, "MANUEL DE RÉFÉRENCE  ·  ÉDITION LUXE", align="C", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
    pdf.ln(18)
    pdf.set_font("Serif", "B", 42)
    pdf.set_text_color(*IVORY)
    pdf.cell(0, 18, "AFRILANG", align="C", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
    pdf.ln(6)
    pdf.set_draw_color(*GOLD)
    pdf.set_line_width(0.5)
    pdf.line(75, pdf.get_y(), 135, pdf.get_y())
    pdf.ln(10)
    pdf.set_font("Serif", "", 14)
    pdf.set_text_color(*GOLD_SOFT)
    pdf.set_x(30)
    pdf.multi_cell(
        150,
        8,
        "Le langage a syntaxe naturelle\nqui transpile vers C++17 / C++20",
        align="C",
    )
    pdf.ln(16)
    pdf.set_font("Serif", "", 11)
    pdf.set_text_color(*IVORY)
    pdf.set_x(35)
    pdf.multi_cell(
        140,
        6.5,
        "Guide complet d'utilisation, specification du langage,\n"
        "bibliotheque standard, outils, architecture et pratique",
        align="C",
    )
    pdf.set_y(210)
    pdf.set_font("Serif", "B", 13)
    pdf.set_text_color(*GOLD)
    pdf.cell(0, 7, AUTHOR, align="C", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
    pdf.set_font("Sans", "", 10)
    pdf.set_text_color(*GOLD_SOFT)
    pdf.cell(0, 6, "Geoinformaticien  ·  Professionnel QHSE", align="C", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
    pdf.ln(4)
    pdf.set_font("Sans", "", 9)
    for line in (f"Tel. {TEL}", f"WhatsApp {WHATSAPP}", EMAIL):
        pdf.cell(0, 5, line, align="C", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
    pdf.set_y(270)
    pdf.set_font("Sans", "", 8)
    pdf.cell(0, 5, "Edition 1.0", align="C", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
    pdf._cream = True


def half_title(pdf: AfrilangBook) -> None:
    pdf.show_chrome = False
    pdf.add_page()
    pdf.set_y(120)
    pdf.set_font("Serif", "B", 22)
    pdf.set_text_color(*INK)
    pdf.cell(0, 10, "AFRILANG", align="C", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
    pdf.ln(4)
    pdf.ornament()
    pdf.set_font("Serif", "", 11)
    pdf.set_text_color(*MUTED)
    pdf.cell(0, 6, "Manuel de reference — Edition luxe", align="C", new_x=XPos.LMARGIN, new_y=YPos.NEXT)


def author_page(pdf: AfrilangBook) -> None:
    pdf.show_chrome = False
    pdf.add_page()
    pdf.set_font("Sans", "", 9)
    pdf.set_text_color(*GOLD)
    pdf.cell(0, 5, "L'AUTEUR", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
    pdf.set_font("Serif", "B", 20)
    pdf.set_text_color(*INK)
    pdf.multi_cell(pdf.epw, 10, "Qui je suis")
    pdf.ornament()
    pdf.body(
        f"""
Je m'appelle {AUTHOR}. Je suis geoinformaticien et professionnel QHSE. Ces deux
identites ne sont pas pour moi des etiquettes separees : elles nourrissent la maniere
dont j'ai concu AFRILANG.

En geoinformatique, je travaille chaque jour avec des donnees spatiales, des pipelines
de traitement, des contraintes de precision et des outils qui doivent rester
comprehensibles pour des equipes mixtes — techniciens, ingenieurs, decideurs. En QHSE,
j'exige la clarte des procedures, la tracabilite, et des formulations qui ne laissent
aucune ambiguite lorsqu'il s'agit de securite, de qualite ou d'environnement.

AFRILANG nait de cette double exigence : une syntaxe naturelle, lisible comme de
l'anglais simple, et une execution native performante via C++. Je veux qu'un collegue
puisse lire un programme presque comme une procedure, tout en obtenant un binaire
serieux pour le terrain, le laboratoire ou le bureau d'etudes.
"""
    )
    pdf.h3("Mes coordonnees")
    pdf.bullet(
        [
            f"Nom : {AUTHOR}",
            "Profil : Geoinformaticien & Professionnel QHSE",
            f"Telephone : {TEL}",
            f"WhatsApp : {WHATSAPP}",
            f"Email : {EMAIL}",
        ]
    )
    pdf.callout(
        "Intention de cet ouvrage",
        "Je n'ai pas ecrit ce livre comme une simple liste de commandes. Je l'ai concu "
        "comme un compagnon : definitions, raisons, exemples, et references. Vous devez "
        "pouvoir comprendre le pourquoi avant le comment.",
    )


def front_toc(pdf: AfrilangBook) -> None:
    pdf.show_chrome = False
    pdf.add_page()
    pdf.set_font("Sans", "", 9)
    pdf.set_text_color(*GOLD)
    pdf.cell(0, 5, "SOMMAIRE", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
    pdf.set_font("Serif", "B", 20)
    pdf.set_text_color(*INK)
    pdf.cell(0, 10, "Plan de l'ouvrage", new_x=XPos.LMARGIN, new_y=YPos.NEXT)
    pdf.ornament()
    pdf.body(
        "L'index detaille avec les numeros de pages figure en fin d'ouvrage. "
        "Voici d'abord la carte du territoire que nous allons parcourir ensemble."
    )
    pdf.bullet(
        [
            "I — Naissance d'AFRILANG : vision et architecture",
            "II — Installation et premiers pas",
            "III — La ligne de commande, mon atelier quotidien",
            "IV — Le langage explique en profondeur",
            "V — Dialoguer avec le programme : ask et l'interactif",
            "VI — Objets, modules, asynchronisme et monde exterieur",
            "VII — Pedagogie : du premier say a la maitrise",
            "VIII — Bibliotheque standard : carte et references",
            "IX — Paquets et reutilisation",
            "X — Outils : editeur, formatage, WASM",
            "XI — Surface web, playground et mobile",
            "XII — Exemples commentes",
            "XIII — Sous le capot du compilateur",
            "XIV — Route, contribution et contacts",
            "Annexes — Glossaire et index",
        ]
    )


from book_luxury_chapters import build_all  # noqa: E402


def main() -> int:
    print("Generation du livre luxe AFRILANG…", flush=True)
    pdf = AfrilangBook()
    pdf.set_title("AFRILANG — Manuel de reference (Edition luxe)")
    pdf.set_author(AUTHOR)
    pdf.set_creator(AUTHOR)
    pdf.set_subject("Manuel AFRILANG par Maxime Dzidula KELI, geoinformaticien et QHSE")

    cover(pdf)
    half_title(pdf)
    author_page(pdf)
    front_toc(pdf)
    pdf.start_body()
    build_all(pdf, ROOT)

    OUT.parent.mkdir(parents=True, exist_ok=True)
    print(f"Ecriture ({pdf.page_no()} pages)…", flush=True)
    pdf.output(str(OUT))
    mb = OUT.stat().st_size / (1024 * 1024)
    print(f"OK → {OUT} ({pdf.page_no()} pages, {mb:.1f} Mo)", flush=True)
    return 0


if __name__ == "__main__":
    sys.exit(main())
