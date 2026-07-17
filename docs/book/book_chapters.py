#!/usr/bin/env python3
"""Chapitres du livre AFRILANG."""
from __future__ import annotations
import re
from pathlib import Path

AUTHOR = "Maxime Dzidula KELI"
TEL = "98 60 00 18"
WHATSAPP = "+33 754830039"
EMAIL = "MaximeKELI25@gmail.com"
GITHUB = "https://github.com/MaximeKELI/AFRILANG"

def build_all_chapters(pdf, ROOT: Path) -> None:
    part_vision(pdf)
    part_install(pdf, ROOT)
    part_cli(pdf)
    part_language(pdf, ROOT)
    part_ask(pdf, ROOT)
    part_advanced_lang(pdf)
    expand_pedagogy(pdf)
    part_stdlib(pdf, ROOT)
    part_pkg(pdf, ROOT)
    part_tools(pdf, ROOT)
    part_web(pdf, ROOT)
    part_examples(pdf, ROOT)
    part_internals(pdf)
    part_roadmap(pdf, ROOT)
    part_appendix_glossary(pdf)
    part_appendix_toc(pdf)
    colophon(pdf)

def part_vision(pdf) -> None:
    pdf.h1("Partie I — Vision, philosophie et architecture")
    pdf.h2("Qu'est-ce qu'AFRILANG ?")
    pdf.body("""
AFRILANG est un langage de programmation orienté objet à syntaxe naturelle. Il est conçu
pour être lisible comme de l'anglais simple, tout en compilant vers du C++17/C++20 puis
en produisant un exécutable natif via g++.

Le projet vise une expérience proche des écosystèmes modernes (inspiration Nim / Crystal) :
langage haut niveau, compilateur, bibliothèque standard riche, gestionnaire de paquets,
serveur LSP, playground web, et cibles natives ainsi que WASM.
""")
    pdf.h2("Pipeline de compilation")
    pdf.code("fichier.afr\n   → Compiler (imports)\n   → Lexer\n   → Parser (AST)\n   → Sémantique\n   → CodeGen C++\n   → g++ / em++\n   → exécutable")
    pdf.h2("Principes de conception")
    pdf.bullet([
        "Syntaxe naturelle : say, ask … into, if … is greater than, repeat N times",
        "Bilingue : anglais + alias français (dire, creer, si, alors, fin…)",
        "Typage clair : number, text, bool, list, map, T?, T or error",
        "Performance : génération C++ et exécution native",
        "Écosystème : pkg, LSP, playground, stdlib multi-niveaux",
        "Erreurs utiles : codes stables, suggestions, locales en/fr",
    ])
    pdf.h2("Organisation du dépôt")
    pdf.body("""
include/afrilang/, src/, runtime/, stdlib/, examples/, packages/, web/ (Django),
site/, vscode-afrilang/, mobile/, docs/, scripts/.
""")

def part_install(pdf, ROOT: Path) -> None:
    pdf.h1("Partie II — Installation et premiers pas")
    pdf.h2("Installation rapide")
    pdf.code("curl -fsSL https://raw.githubusercontent.com/MaximeKELI/AFRILANG/main/install.sh | bash")
    pdf.h2("Shell")
    pdf.code('export PATH="$HOME/.local/bin:$PATH"\nexport AFRILANG_HOME="$HOME/.local/afrilang"\nafrilang version')
    pdf.h2("Build source")
    pdf.code("mkdir build && cd build\ncmake ..\nmake -j$(nproc)")
    pdf.h2("Hello")
    pdf.code('say "Bonjour depuis AFRILANG!"\nrepeat 3 times\n    say "Hello"\nend')
    pdf.code("afrilang run examples/hello.afr")
    pdf.h2("Programme PAHT")
    paht = ROOT / "examples" / "paht.afr"
    if paht.exists():
        pdf.code(paht.read_text(encoding="utf-8"))
    pdf.code("afrilang run examples/paht.afr")

def part_cli(pdf) -> None:
    pdf.h1("Partie III — Guide d'utilisation de la CLI")
    commands = [
        ("afrilang version", "Version + AFRILANG_HOME"),
        ("afrilang build", "Compile le projet"),
        ("afrilang run f.afr", "Compile et exécute"),
        ("afrilang check f.afr", "Analyse sans link"),
        ("afrilang test", "Suite de tests"),
        ("afrilang init nom", "Nouveau projet"),
        ("afrilang init nom --lib", "Nouvelle bibliothèque"),
        ("afrilang lsp", "Language Server"),
        ("afrilang fmt f.afr [-w]", "Formateur"),
        ("afrilang repl", "REPL"),
        ("afrilang pkg add/install/update/list/search/publish", "Paquets"),
        ("afrilang serve", "Playground local :8080"),
        ("afrilang debug/lint/explain/doc", "Outils qualité"),
        ("afrilang compile-js / build-wasm-web", "Cibles web"),
        ("afrilang benchmark", "Mesures"),
    ]
    for cmd, desc in commands:
        pdf.set_font("Mono", "", 8)
        pdf.multi_cell(0, 4.5, cmd)
        pdf.set_font("DejaVu", "", 9)
        pdf.multi_cell(0, 5, f"    → {desc}")
        pdf.ln(1)
    pdf.h2("Projet")
    pdf.code('[package]\nname = "mon_app"\nversion = "0.1.0"\nmain = "src/main.afr"\n\n[dependencies]\nmath = "^0.1.0"')

def part_language(pdf, ROOT: Path) -> None:
    pdf.h1("Partie IV — Spécification complète du langage")
    pdf.md_file(ROOT / "docs" / "LANGUAGE.md", mono_size=7)
    readme = (ROOT / "README.md").read_text(encoding="utf-8", errors="replace")
    m = re.search(r"## Syntaxe du langage[\s\S]*?(?=\n## [^#]|\Z)", readme)
    if m:
        pdf.h2("Complément README — syntaxe")
        pdf.ingest_markdown(m.group(0), mono_size=7)

def part_ask(pdf, ROOT: Path) -> None:
    pdf.h1("Partie V — Entrée utilisateur (ask)")
    pdf.code('ask "Name:" into name\nask "Age:" into age as number\nsay "Hi " + name + " " + age')
    pdf.bullet([
        "Auto-déclaration de variable",
        "as number / as text",
        "say et + convertissent les nombres",
        "Mode console interactive (sans timeout sandbox)",
    ])
    paht = ROOT / "examples" / "paht.afr"
    if paht.exists():
        pdf.h2("Exemple PAHT")
        pdf.code(paht.read_text(encoding="utf-8"))

def part_advanced_lang(pdf) -> None:
    pdf.h1("Partie VI — POO, modules, async, FFI, tests")
    pdf.code('import "std/json"\nuse json')
    pdf.code('extern from "m" function cos(x number) returns number')
    pdf.code('test "addition"\n    assert 1 + 1 is equal to 2\nend')
    pdf.body("GUI/jeux : std/ui, std/game2d, std/game3d, examples/snake.afr, gui_demo.afr.")

def expand_pedagogy(pdf) -> None:
    pdf.h1("Partie VII — Guides pédagogiques")
    lessons = [
        ("Leçon 1 — Afficher", 'say "Hello"\n', "say écrit sur stdout."),
        ("Leçon 2 — Variables", 'create x = 1\nset x = 2\n', "create et set."),
        ("Leçon 3 — Conditions", 'if x is greater than 0 then\n    say "ok"\nend\n', "Comparaisons naturelles."),
        ("Leçon 4 — Boucles", "repeat 3 times\n    say \"x\"\nend\n", "repeat / while / for each."),
        ("Leçon 5 — Listes", "create n = list of 1, 2\nadd 3 to n\n", "list → vector."),
        ("Leçon 6 — Fonctions", "function add(a number, b number) returns number\n    return a + b\nend\n", "Réutilisation."),
        ("Leçon 7 — ask", 'ask "n:" into n as number\n', "Saisie typée."),
        ("Leçon 8 — Classes", 'class A\n    function hi()\n        say "hi"\n    end\nend\n', "POO."),
        ("Leçon 9 — std", 'import "std/math"\nuse math\nsay sqrt(9)\n', "Core stdlib."),
        ("Leçon 10 — Projet", "afrilang init app\nafrilang run src/main.afr\n", "Cycle de vie."),
    ]
    for title, code, exp in lessons:
        pdf.h3(title)
        pdf.body(exp)
        pdf.code(code)
    pdf.h2("Intermédiaire / avancé")
    pdf.code("function id<T>(v T) returns T\n    return v\nend")
    pdf.code("afrilang run app.afr --target wasm32")

def part_stdlib(pdf, ROOT: Path) -> None:
    pdf.h1("Partie VIII — Bibliothèque standard")
    pdf.bullet([
        "Core stabilisé (runtime C++)",
        "Simple ~2150 modules (std/nom)",
        "Medium ~100 modules (std/m/nom)",
        "Complex ~5700 modules (std/c/nom)",
        "~7971 modules documentés",
    ])
    pdf.h2("Core")
    pdf.md_file(ROOT / "docs" / "CORE_STDLIB.md")
    pdf.h2("API core")
    pdf.md_file(ROOT / "docs" / "STDLIB_API.md")
    pdf.h2("SIMPLE — référence complète")
    pdf.md_file(ROOT / "docs" / "STDLIB_SIMPLE.md", mono_size=6.5)
    pdf.h2("MEDIUM")
    pdf.md_file(ROOT / "docs" / "STDLIB_MEDIUM.md", mono_size=6.5)
    pdf.h2("COMPLEX — catalogue")
    pdf.md_file(ROOT / "docs" / "STDLIB_COMPLEX.md", mono_size=6)
    pdf.h2("Génération")
    pdf.md_file(ROOT / "docs" / "STDLIB_GEN.md")

def part_pkg(pdf, ROOT: Path) -> None:
    pdf.h1("Partie IX — Gestionnaire de paquets")
    pdf.md_file(ROOT / "docs" / "PKG.md")

def part_tools(pdf, ROOT: Path) -> None:
    pdf.h1("Partie X — Outils (LSP, VS Code, WASM)")
    pdf.body("afrilang lsp — diagnostics, hover, définition, complétion EN/FR.")
    vs = ROOT / "vscode-afrilang" / "README.md"
    if vs.exists():
        pdf.h2("Extension VS Code")
        pdf.md_file(vs, max_lines=250)
    pdf.h2("WASM")
    pdf.md_file(ROOT / "docs" / "WASM_COMPAT.md")
    pdf.bullet(["fmt", "lint", "debug (GDB)", "explain"])

def part_web(pdf, ROOT: Path) -> None:
    pdf.h1("Partie XI — Site web, playground, mobile")
    pdf.code("afrilang serve  # http://127.0.0.1:8080")
    web = ROOT / "web" / "README.md"
    if web.exists():
        pdf.md_file(web)
    mob = ROOT / "mobile" / "README.md"
    if mob.exists():
        pdf.h2("Mobile")
        pdf.md_file(mob, max_lines=200)

def part_examples(pdf, ROOT: Path) -> None:
    pdf.h1("Partie XII — Catalogue d'exemples")
    pdf.code("afrilang run examples/NOM.afr")
    examples = sorted((ROOT / "examples").glob("*.afr"))
    pdf.h2(f"{len(examples)} fichiers")
    for i, ex in enumerate(examples, 1):
        pdf.h3(f"{i}. {ex.name}")
        try:
            src = ex.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        lines = src.splitlines()
        if len(lines) > 250:
            src = "\n".join(lines[:250]) + f"\n... [{len(lines)-250} lignes]"
        pdf.code(src, size=6.5)

def part_internals(pdf) -> None:
    pdf.h1("Partie XIII — Architecture interne")
    pdf.bullet([
        "Lexer → tokens",
        "Parser → AST",
        "SemanticAnalyzer → types / usesAsk",
        "CodeGenerator → C++ / g++",
        "Sandbox + cache",
    ])
    pdf.code("list→vector  text→string  number→double\nask as number → getline + stod\nsay/+ → str::toString/concat")

def part_roadmap(pdf, ROOT: Path) -> None:
    pdf.h1("Partie XIV — Roadmap, contribution, licence")
    pdf.md_file(ROOT / "docs" / "ROADMAP.md")
    pdf.h2("Contribution")
    pdf.body(f"PR bienvenues sur {GITHUB}. Tests dans tests/test_compiler.cpp.")
    lic = ROOT / "LICENSE"
    pdf.h2("Licence")
    if lic.exists():
        pdf.code(lic.read_text(encoding="utf-8", errors="replace")[:4000])
    pdf.h2("Contact")
    pdf.bullet([f"Auteur : {AUTHOR}", f"Tél. : {TEL}", f"WhatsApp : {WHATSAPP}", f"Email : {EMAIL}", f"GitHub : {GITHUB}"])

def part_appendix_glossary(pdf) -> None:
    pdf.h1("Annexe A — Glossaire")
    for term, defn in [
        ("AST", "Arbre syntaxique abstrait."),
        ("CLI", "Interface ligne de commande."),
        ("Codegen", "Génération C++."),
        ("FFI", "Appels bibliothèques C."),
        ("LSP", "Language Server Protocol."),
        ("PAHT", "Prix d'Achat Hors Taxes."),
        ("REPL", "Boucle interactive."),
        ("Result", "Type T or error."),
        ("Sandbox", "Exécution isolée."),
        ("Stdlib", "Bibliothèque standard."),
        ("WASM", "WebAssembly."),
    ]:
        pdf.set_font("DejaVu", "B", 10)
        pdf.multi_cell(0, 5, term)
        pdf.set_font("DejaVu", "", 9.5)
        pdf.multi_cell(0, 5, defn)
        pdf.ln(1)

def part_appendix_toc(pdf) -> None:
    pdf.h1("Annexe B — Index des chapitres (avec pages)")
    pdf.set_font("DejaVu", "", 8.5)
    for level, title, page in pdf.toc_entries:
        indent = "   " * (level - 1)
        t = title if len(title) < 85 else title[:82] + "…"
        t = "".join(ch if ord(ch) >= 32 else " " for ch in t)
        dots = "." * max(2, 72 - len(indent) - len(t) - len(str(page)))
        pdf.multi_cell(0, 4.2, f"{indent}{t} {dots} {page}")

def colophon(pdf) -> None:
    pdf.h1("Colophon et contacts")
    pdf.body(f"Ouvrage généré depuis {GITHUB}.")
    pdf.bullet([AUTHOR, f"Tél. : {TEL}", f"WhatsApp : {WHATSAPP}", f"Email : {EMAIL}", f"GitHub : {GITHUB}"])
