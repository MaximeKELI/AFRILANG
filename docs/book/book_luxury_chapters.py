#!/usr/bin/env python3
"""Chapitres luxueux — narration a la premiere personne."""

from __future__ import annotations

import re
from pathlib import Path

AUTHOR = "Maxime Dzidula KELI"
TEL = "98 60 00 18"
WHATSAPP = "+33 754830039"
EMAIL = "MaximeKELI25@gmail.com"


def build_all(pdf, ROOT: Path) -> None:
    part_vision(pdf)
    part_install(pdf, ROOT)
    part_cli(pdf)
    part_language(pdf, ROOT)
    part_ask(pdf, ROOT)
    part_advanced(pdf)
    part_pedagogy(pdf)
    part_stdlib(pdf, ROOT)
    part_pkg(pdf, ROOT)
    part_tools(pdf, ROOT)
    part_web(pdf, ROOT)
    part_examples(pdf, ROOT)
    part_internals(pdf)
    part_closing(pdf, ROOT)
    appendix_glossary(pdf)
    appendix_toc(pdf)
    colophon(pdf)


def part_vision(pdf) -> None:
    pdf.part_opener(
        "I",
        "Naissance d'AFRILANG",
        "Pourquoi j'ai voulu un langage lisible comme une procedure,\net solide comme un outil de terrain.",
    )
    pdf.h1("Ce que je voulais resoudre")
    pdf.body(
        """
Dans mon travail de geoinformaticien, je vois trop souvent un fosse entre l'intention
humaine et le code. Une procedure QHSE peut etre limpide sur le papier, puis se perdre
dans une syntaxe opaque. A l'inverse, un script puissant peut etre illegible pour celui
qui devra le maintenir dans six mois, sous pression, sur un site.

J'ai donc pose une exigence simple : AFRILANG doit se lire presque comme de l'anglais
naturel, tout en produisant un executable natif via C++17/C++20. Je ne cherche pas un
jouet pedagogique. Je cherche un instrument de precision, capable d'accompagner aussi
bien un calcul geomatique qu'un petit outil de suivi QHSE.
"""
    )
    pdf.definition(
        "AFRILANG",
        "Langage de programmation oriente objet a syntaxe naturelle que j'ai concu pour "
        "exprimer des intentions clairement, puis les compiler en programmes natifs "
        "performants par transpilation vers C++.",
    )
    pdf.definition(
        "Transpilation",
        "Traduction automatique d'un programme source (ici .afr) vers un autre langage "
        "source (ici C++), avant compilation native. Ce n'est pas de l'interpretation "
        "ligne a ligne : le resultat final est un binaire.",
    )
    pdf.h2("Le pipeline que je defends")
    pdf.body(
        """
Chaque fichier .afr traverse une chaine que je voulais explicite et auditable — une
habitude que je dois aussi a la culture QHSE : on doit pouvoir expliquer chaque etape.
"""
    )
    pdf.code(
        "fichier.afr\n"
        "  → resolution des imports\n"
        "  → analyse lexicale (tokens)\n"
        "  → analyse syntaxique (AST)\n"
        "  → analyse semantique (types, portee)\n"
        "  → generation C++\n"
        "  → compilation g++ / em++\n"
        "  → executable natif ou artefact WASM",
        caption="Chaine de compilation AFRILANG",
    )
    pdf.h2("Principes que je refuse de trahir")
    pdf.bullet(
        [
            "Lisibilite d'abord : say, ask into, is greater than, repeat N times",
            "Bilingualisme pragmatique : anglais pivot, alias francais pour l'accessibilite",
            "Types honnetes : number, text, bool, list, map, optionnels, Result",
            "Performance reelle : C++ sous le capot, pas une couche cosmétique",
            "Ecosysteme complet : paquets, LSP, playground, stdlib, outils",
            "Erreurs utiles : messages stables, suggestions, localisation",
        ]
    )
    pdf.callout(
        "Lien avec mon metier",
        "La geoinformatique m'impose la rigueur des donnees ; le QHSE m'impose la clarte "
        "des procedures. AFRILANG est ma reponse technique a ces deux disciplines.",
    )


def part_install(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "II",
        "Installation et premiers pas",
        "Je vous accompagne jusqu'au premier programme qui repond vraiment.",
    )
    pdf.h1("Installer AFRILANG proprement")
    pdf.body(
        """
Avant toute chose, je distingue deux situations. Si vous voulez simplement ecrire et
executer, l'installateur officiel suffit. Si vous contribuez au compilateur ou si vous
deboquez le codegen, compilez depuis les sources. Dans les deux cas, je recommande de
fixer AFRILANG_HOME et le PATH une fois pour toutes dans votre shell.
"""
    )
    pdf.definition(
        "AFRILANG_HOME",
        "Repertoire racine de votre installation AFRILANG. Le compilateur s'en sert pour "
        "retrouver runtime, stdlib et ressources associees.",
    )
    pdf.h2("Voie rapide")
    pdf.code(
        "curl -fsSL https://raw.githubusercontent.com/MaximeKELI/AFRILANG/main/install.sh | bash\n"
        'export PATH="$HOME/.local/bin:$PATH"\n'
        'export AFRILANG_HOME="$HOME/.local/afrilang"\n'
        "afrilang version",
        caption="Installation et verification",
    )
    pdf.body(
        """
Je n'aime pas les installations "magiques" non verifiees. Apres l'installateur, je lance
toujours afrilang version. Si la commande repond avec le chemin home, je sais que mon
atelier est pret.
"""
    )
    pdf.h2("Compilation depuis les sources")
    pdf.code("mkdir build && cd build\ncmake ..\nmake -j$(nproc)", caption="Build local")
    pdf.h2("Le rituel du premier say")
    pdf.body(
        """
Mon premier programme n'est jamais un framework. C'est une phrase. Je veux entendre la
voix du langage avant d'empiler les abstractions. say affiche une ligne. repeat repete
un bloc. end ferme clairement la structure — j'insiste sur cette fermeture explicite :
elle evite les ambiguites que j'ai trop vues dans des procedures mal delimitees.
"""
    )
    pdf.code(
        'say "Bonjour depuis AFRILANG!"\n\nrepeat 3 times\n    say "Hello"\nend',
        caption="examples/hello.afr (esprit)",
    )
    pdf.code("afrilang run examples/hello.afr")
    pdf.h2("Un premier vrai dialogue : le PAHT")
    pdf.body(
        """
Le calcul du PAHT (Prix d'Achat Hors Taxes) est volontairement concret. En QHSE comme
en gestion de projet, on manipule des montants, des taux, des libelles. Je montre ici
comment demander une saisie, convertir un nombre, et produire un resultat comprehensible.
"""
    )
    pdf.definition(
        "PAHT",
        "Prix d'Achat Hors Taxes. Lorsque le prix saisi est TTC et que t est le taux de "
        "TVA en pourcentage, PAHT = TTC / (1 + t/100).",
    )
    paht = ROOT / "examples" / "paht.afr"
    if paht.exists():
        pdf.code(paht.read_text(encoding="utf-8"), caption="examples/paht.afr")
    pdf.code("afrilang run examples/paht.afr")


def part_cli(pdf) -> None:
    pdf.part_opener(
        "III",
        "La ligne de commande",
        "Mon atelier quotidien : une seule commande, plusieurs gestes precis.",
    )
    pdf.h1("Pourquoi une CLI unifiee")
    pdf.body(
        """
Je refuse de multiplier les outils disparates. afrilang est mon point d'entree unique :
compiler, executer, verifier, formater, tester, gerer les paquets, servir un playground,
parler a l'editeur via LSP. Cette unite reduit la charge cognitive — encore une lecon
QHSE : moins d'interfaces, moins d'erreurs operateur.
"""
    )
    pdf.definition(
        "CLI",
        "Command Line Interface : interface texte permettant de piloter le compilateur "
        "et son ecosysteme depuis un terminal.",
    )
    rows = [
        ("version", "Je verifie l'installation et le home."),
        ("build", "Je construis un projet declare dans afrilang.toml."),
        ("run", "Je compile puis j'execute un fichier .afr."),
        ("check", "J'analyse sans produire l'executable final."),
        ("test", "Je lance les blocs test et assertions."),
        ("init", "Je cree une ossature de projet ou de bibliotheque."),
        ("lsp", "Je connecte l'intelligence a l'editeur."),
        ("fmt", "Je normalise le style du code."),
        ("repl", "J'explore des idees en interactif."),
        ("pkg …", "J'ajoute, installe, mets a jour, publie des paquets."),
        ("serve", "Je demarre un playground local."),
        ("debug / lint / explain / doc", "Je diagnistique, explique, documente."),
        ("compile-js / build-wasm-web", "Je vise le web lorsque c'est pertinent."),
        ("benchmark", "Je mesure compile et execution."),
    ]
    for cmd, why in rows:
        pdf.set_font("Mono", "", 8.5)
        pdf.set_text_color(184, 148, 74)
        pdf.set_x(pdf.l_margin)
        pdf.multi_cell(pdf.epw, 4.5, f"afrilang {cmd}")
        pdf.set_font("Serif", "", 10)
        pdf.set_text_color(45, 42, 38)
        pdf.set_x(pdf.l_margin)
        pdf.multi_cell(pdf.epw, 5.2, why)
        pdf.ln(1.2)
    pdf.h2("Le projet comme contrat")
    pdf.body(
        """
afrilang.toml n'est pas un detail administratif. C'est le contrat du projet : nom,
version, point d'entree, dependances. Je le traite comme une fiche d'identite — stable,
lisible, versionnee.
"""
    )
    pdf.code(
        '[package]\nname = "mon_app"\nversion = "0.1.0"\nmain = "src/main.afr"\n\n'
        '[dependencies]\nmath = "^0.1.0"',
        caption="Exemple afrilang.toml",
    )


def part_language(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "IV",
        "Le langage en profondeur",
        "Definitions, intentions et mecanismes — pas seulement des exemples a copier.",
    )
    pdf.h1("Comment je lis une specification")
    pdf.body(
        """
Une specification sans pedagogie devient un mur. Une pedagogie sans specification devient
du flou. Dans cette partie, je commence par poser les definitions, puis je vous livre la
specification officielle enrichie de mon commentaire.
"""
    )
    pdf.definition("Token", "Plus petite unite lexicale reconnue (mot-cle, identifiant, litteral, symbole).")
    pdf.definition("AST", "Arbre syntaxique abstrait : representation structuree du programme apres parsing.")
    pdf.definition(
        "Analyse semantique",
        "Verification des sens : types, portee des variables, existence des symboles, "
        "compatibilite des operations.",
    )
    pdf.h2("Types : ce que je promets a la machine")
    pdf.body(
        """
number est mon type numerique general (double cote C++). text porte les chaines.
bool exprime le vrai/faux, avec aussi yes/no pour coller au langage naturel.
list of T modelise une sequence homogene. map K to V associe des cles a des valeurs.
T? signifie "valeur optionnelle". T or error formalise le succes ou l'echec explicite.
"""
    )
    pdf.definition(
        "Type",
        "Contrat sur la nature des valeurs qu'une expression peut produire. Un type bien "
        "choisi documente l'intention et permet au compilateur de refuser les absurdites.",
    )
    pdf.h2("Specification officielle commentee")
    pdf.body(
        "Je reproduis ci-dessous la specification du langage. Lisez-la comme un manuel "
        "de precision : chaque construction a une raison d'etre."
    )
    pdf.md_file(ROOT / "docs" / "LANGUAGE.md", mono_size=6.8)
    readme = (ROOT / "README.md").read_text(encoding="utf-8", errors="replace")
    m = re.search(r"## Syntaxe du langage[\s\S]*?(?=\n## [^#]|\Z)", readme)
    if m:
        pdf.h2("Complement de syntaxe naturelle")
        pdf.body(
            "J'ajoute ici le panorama de syntaxe naturelle, utile pour les premiers jours "
            "et pour les formateurs qui introduisent AFRILANG en atelier."
        )
        pdf.ingest_markdown(m.group(0), mono_size=6.8)


def part_ask(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "V",
        "Dialoguer avec le programme",
        "L'entree utilisateur digne d'une procedure claire.",
    )
    pdf.h1("Pourquoi ask compte autant")
    pdf.body(
        """
Un programme silencieux qui n'ecoute personne reste un monologue. Dans mes contextes
QHSE et geomatiques, je dois souvent demander un parametre : un seuil, un taux, un nom
d'operateur, une coordonnee. ask est ma primitive de dialogue.
"""
    )
    pdf.definition(
        "ask … into …",
        "Instruction qui affiche une invite, lit une ligne depuis l'entree standard, et "
        "range le resultat dans une variable. Sans as, le type est text. Avec as number, "
        "la saisie est convertie en nombre.",
    )
    pdf.h2("La syntaxe que je recommande desormais")
    pdf.body(
        """
J'ai assoupli ask pour coller a mon objectif de simplicite anglaise. Vous n'avez plus a
predeclarer create x = "". Vous n'avez plus a importer parseFloat pour un cas simple.
Vous ecrivez l'intention, le compilateur declare et convertit.
"""
    )
    pdf.code(
        'ask "Operator name:" into operatorName\n'
        'ask "Threshold:" into threshold as number\n'
        'say "Hello " + operatorName\n'
        'say "Next step uses " + threshold',
        caption="Dialogue minimal",
    )
    pdf.h2("Cas metier : PAHT")
    pdf.body(
        """
Je reviens au PAHT parce qu'il enseigne trois gestes a la fois : saisir du texte, saisir
des nombres, composer un message de synthese. C'est exactement le niveau de clarte que
j'attends d'un outil de terrain.
"""
    )
    paht = ROOT / "examples" / "paht.afr"
    if paht.exists():
        pdf.code(paht.read_text(encoding="utf-8"), caption="examples/paht.afr")
    pdf.callout(
        "Bonne pratique",
        "Precisez toujours l'unite dans l'invite (%, EUR, TTC, metres). Une invite floue "
        "produit des donnees floues — inacceptable en QHSE comme en geomatique.",
    )


def part_advanced(pdf) -> None:
    pdf.part_opener(
        "VI",
        "Objets, modules, async et monde exterieur",
        "Quand le programme grandit sans perdre sa lisibilite.",
    )
    pdf.h1("Modularite")
    pdf.definition(
        "Module",
        "Unite de regroupement de fonctions et classes, exposee via use / import, afin "
        "de separer les responsabilites sans sacrifier la lisibilite.",
    )
    pdf.body(
        """
J'organise le code comme j'organise une procedure : une responsabilite par module, des
exports explicites, des dependances assumees. import "std/…" tire la bibliotheque
standard. import d'un fichier local compose votre architecture.
"""
    )
    pdf.code('import "std/json"\nuse json')
    pdf.h2("POO : modeliser le domaine")
    pdf.body(
        """
Les classes me servent a modeliser des entites du monde reel : un site, un capteur, un
dossier de non-conformite, une emprise geographique. fields, init, this, extends,
interfaces : tout est la pour coller au domaine, pas pour faire du style.
"""
    )
    pdf.h2("Async")
    pdf.definition(
        "async / await",
        "Mecanisme permettant d'exprimer des operations non bloquantes. Une async "
        "function retourne un task T ; await suspend l'execution jusqu'au resultat.",
    )
    pdf.h2("FFI")
    pdf.body(
        "Lorsque la bibliotheque standard ne suffit pas, j'ouvre une porte controlee vers "
        "le C via extern from. Je limite volontairement les bibliotheques autorisees : "
        "la securite n'est pas une option."
    )
    pdf.code('extern from "m" function cos(x number) returns number')
    pdf.h2("Tests")
    pdf.body(
        "Un test n'est pas une ceremonie. C'est une preuve minimale que je peux relancer. "
        "Les blocs test et assert vivent dans le langage, pas dans un outil etranger."
    )
    pdf.code('test "addition"\n    assert 1 + 1 is equal to 2\nend')


def part_pedagogy(pdf) -> None:
    pdf.part_opener(
        "VII",
        "Pedagogie",
        "Dix lecons pour entrer, puis le chemin vers la maitrise.",
    )
    pdf.h1("Parcours debutant")
    pdf.body(
        """
Si vous formez une equipe, gardez cette progression. Chaque lecon ajoute une capacite
sans noyer l'apprenant. J'explique d'abord l'intention, puis je montre le geste.
"""
    )
    lessons = [
        (
            "Lecon 1 — Faire entendre une voix",
            "say ecrit une ligne sur la sortie standard. C'est le premier feedback. Sans "
            "feedback, aucun apprentissage n'est possible.",
            'say "Hello AFRILANG"\n',
        ),
        (
            "Lecon 2 — Nommer pour gouverner",
            "create declare. set modifie. Nommer une valeur, c'est deja documenter.",
            'create site = "Depot Nord"\ncreate score = 92\nsay site\n',
        ),
        (
            "Lecon 3 — Decider",
            "if … then … else … end formalise une branche. Les comparaisons naturelles "
            "(is greater than) reduisent la charge cognitive.",
            'if score is greater than 80 then\n    say "Conforme"\nelse\n    say "A revoir"\nend\n',
        ),
        (
            "Lecon 4 — Repeter sans se repeter",
            "repeat fixe un nombre d'iterations. while exprime une condition durable.",
            'repeat 3 times\n    say "Controle"\nend\n',
        ),
        (
            "Lecon 5 — Collections",
            "Une list of T est une sequence homogene. Elle devient std::vector cote C++.",
            "create mesures = list of 1.2, 1.3, 1.1\nfor each m in mesures do\n    say m\nend\n",
        ),
        (
            "Lecon 6 — Fonctions",
            "Une function encapsule une responsabilite. returns annonce le contrat.",
            "function double(x number) returns number\n    return x * 2\nend\n",
        ),
        (
            "Lecon 7 — Dialoguer",
            "ask transforme l'utilisateur en partenaire du calcul.",
            'ask "Seuil:" into seuil as number\nsay "Seuil retenu : " + seuil\n',
        ),
        (
            "Lecon 8 — Objets",
            "Une class modelise une entite durable du domaine.",
            'class Capteur\n    public field nom text\n    function init(n text)\n        set this.nom = n\n    end\nend\n',
        ),
        (
            "Lecon 9 — Standard library",
            "Reutilisez avant de reinventer. Le core est stabilise pour la production.",
            'import "std/math"\nuse math\nsay sqrt(16)\n',
        ),
        (
            "Lecon 10 — Projet",
            "init, run, test : le cycle de vie minimal d'une equipe serieuse.",
            "afrilang init atelier_qhs\ncd atelier_qhs\nafrilang run src/main.afr\n",
        ),
    ]
    for title, prose, code in lessons:
        pdf.h3(title)
        pdf.body(prose)
        pdf.code(code)
    pdf.h2("Vers l'intermediaire et l'avance")
    pdf.body(
        """
Ensuite viennent Result, match, generiques, cibles cross (linux-arm64, wasm32), et la
mesure (--profile). Je vous invite a ne bruler aucune etape : la maitrise est une
accumulation de clartes, pas une accumulation de raccourcis.
"""
    )


def part_stdlib(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "VIII",
        "Bibliotheque standard",
        "La carte d'un vaste territoire, avec boussole et legendes.",
    )
    pdf.h1("Comment je structure la stdlib")
    pdf.body(
        """
Je refuse un monolithe indigeste. La bibliotheque standard est stratifiee. Le core est
le socle de production. Simple, medium et complex etendent l'espace d'exploration —
y compris pour mes besoins de geoinformatique (analyse spatiale, raster, segmentation,
visualisation, jeux de donnees).
"""
    )
    pdf.definition(
        "Stdlib (bibliotheque standard)",
        "Ensemble de modules fournis avec le langage pour accomplir des taches courantes "
        "sans reecrire l'infrastructure.",
    )
    pdf.bullet(
        [
            "Core : runtime C++ reel (io, json, fs, http, str, math, …)",
            "Simple : import \"std/nom\" — milliers de briques utiles",
            "Medium : import \"std/m/nom\"",
            "Complex : import \"std/c/nom\" — dont packs geomatiques et data",
        ]
    )
    pdf.callout(
        "Regard geoinformaticien",
        "Dans les couches avancees, vous trouverez des familles utiles a mon metier : "
        "giskit/gisultra, rasterultra, segultra, dataultra, vizultra. Je les documente "
        "ici comme reference de travail.",
    )
    pdf.h2("Core")
    pdf.md_file(ROOT / "docs" / "CORE_STDLIB.md")
    pdf.h2("API core")
    pdf.md_file(ROOT / "docs" / "STDLIB_API.md")
    pdf.h2("Reference SIMPLE")
    pdf.body(
        "Je fournis ci-dessous la reference simple complete. Servez-vous-en comme d'un "
        "catalogue raisonne, pas comme d'une obligation de tout memoriser."
    )
    pdf.md_file(ROOT / "docs" / "STDLIB_SIMPLE.md", mono_size=6.4)
    pdf.h2("Reference MEDIUM")
    pdf.md_file(ROOT / "docs" / "STDLIB_MEDIUM.md", mono_size=6.4)
    pdf.h2("Reference COMPLEX")
    pdf.body(
        "La couche complex est vaste. Je l'inclus comme atlas : vous y naviguerez selon "
        "vos campagnes (SIG, raster, data science, visualisation)."
    )
    pdf.md_file(ROOT / "docs" / "STDLIB_COMPLEX.md", mono_size=6)
    pdf.h2("Generation des catalogues")
    pdf.md_file(ROOT / "docs" / "STDLIB_GEN.md")


def part_pkg(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "IX",
        "Paquets",
        "Reutiliser sans perdre le controle.",
    )
    pdf.h1("Ma philosophie des dependances")
    pdf.body(
        """
Une dependance est un engagement. En QHSE, j'exige la tracabilite ; en ingenierie
logicielle aussi. Le gestionnaire de paquets d'AFRILANG formalise cet engagement via
afrilang.toml, le lockfile, et des regles semver explicites.
"""
    )
    pdf.definition(
        "Semver",
        "Versionnage semantique (majeure.mineure.correctif). Les operateurs ^ et ~ "
        "encadrent les mises a jour acceptables sans surprise brutale.",
    )
    pdf.md_file(ROOT / "docs" / "PKG.md")


def part_tools(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "X",
        "Outils du quotidien",
        "Editeur, formatage, diagnostic, cible web.",
    )
    pdf.h1("LSP et editeur")
    pdf.body(
        """
Je travaille mieux lorsque l'editeur me parle. afrilang lsp fournit diagnostics, hover,
definition et completion bilingue. L'extension Visual Studio Code / Cursor s'y branche.
"""
    )
    pdf.definition(
        "LSP",
        "Language Server Protocol : protocole standard reliant un editeur a un serveur "
        "d'intelligence linguistique independant.",
    )
    vs = ROOT / "vscode-afrilang" / "README.md"
    if vs.exists():
        pdf.h2("Extension editeur")
        pdf.md_file(vs, max_lines=220)
    pdf.h2("WASM")
    pdf.body(
        "Certaines cibles vivent dans le navigateur. Je documente honnetement ce qui "
        "fonctionne en WASM et ce qui reste natif (UI lourde, filesystem, etc.)."
    )
    pdf.md_file(ROOT / "docs" / "WASM_COMPAT.md")
    pdf.h2("Qualite")
    pdf.bullet(
        [
            "fmt — style stable, relectures plus rapides",
            "lint — signaux faibles avant l'incident",
            "debug — GDB lorsque le binaire doit parler",
            "explain — pedagogie integree pour la formation",
        ]
    )


def part_web(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "XI",
        "Surfaces numeriques",
        "Playground, site, mobile : la meme exigence de clarte.",
    )
    pdf.h1("Playground local")
    pdf.body(
        "Parfois je demontre AFRILANG sans installer quoi que ce soit sur la machine "
        "d'un interlocuteur. afrilang serve ouvre ce theatre local."
    )
    pdf.code("afrilang serve\n# http://127.0.0.1:8080")
    web = ROOT / "web" / "README.md"
    if web.exists():
        pdf.h2("Site dynamiques")
        pdf.body(
            "Le site officiel s'appuie sur une stack robuste pour documenter, explorer "
            "les paquets, et offrir un playground connecte."
        )
        pdf.md_file(web)
    mob = ROOT / "mobile" / "README.md"
    if mob.exists():
        pdf.h2("Mobile")
        pdf.md_file(mob, max_lines=180)


def part_examples(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "XII",
        "Exemples commentes",
        "Une bibliotheque vivante de gestes reels.",
    )
    pdf.h1("Comment j'utilise les exemples")
    pdf.body(
        """
Un exemple n'est pas un trophée. C'est un scenario. Je recommande de le lire a voix
haute, de predire la sortie, puis de l'executer. Ensuite seulement, modifiez-le.
"""
    )
    pdf.code("afrilang run examples/NOM.afr")
    examples = sorted((ROOT / "examples").glob("*.afr"))
    pdf.h2(f"Catalogue — {len(examples)} programmes")
    for i, ex in enumerate(examples, 1):
        pdf.h3(f"{i}. {ex.name}")
        pdf.body(
            f"Fichier {ex.name}. Observez d'abord la structure (declarations, controle, "
            f"sorties). Puis executez et confrontez votre prediction au resultat."
        )
        try:
            src = ex.read_text(encoding="utf-8", errors="replace")
        except OSError:
            continue
        lines = src.splitlines()
        if len(lines) > 220:
            src = "\n".join(lines[:220]) + f"\n... [{len(lines)-220} lignes supplementaires]"
        pdf.code(src, size=6.3, caption=str(ex.relative_to(ROOT)))


def part_internals(pdf) -> None:
    pdf.part_opener(
        "XIII",
        "Sous le capot",
        "Pour ceux qui doivent comprendre afin de mieux gouverner.",
    )
    pdf.h1("Architecture du compilateur")
    pdf.body(
        """
Je resume ici l'architecture pour les lecteurs avances et pour les auditeurs techniques
qui m'interrogent sur la fiabilite de la chaine. Comprendre le pipeline, c'est pouvoir
diagnostiquer.
"""
    )
    pdf.bullet(
        [
            "Lexer — decoupe le texte en tokens",
            "Parser — construit l'AST",
            "SemanticAnalyzer — types, portee, drapeaux (usesAsk, usesUi, usesAsync)",
            "CodeGenerator — C++ puis g++/em++",
            "Sandbox — execution bornee ; console interactive pour ask",
            "Cache — evite le travail inutile lorsque rien n'a change",
        ]
    )
    pdf.h2("Correspondances essentielles")
    pdf.code(
        "list → std::vector\ntext → std::string\nnumber → double\n"
        "ask as number → getline + std::stod\nsay / + → toString / concat"
    )


def part_closing(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "XIV",
        "Route et contacts",
        "Ce que je compte continuer, et comment me joindre.",
    )
    pdf.h1("Feuille de route")
    pdf.body(
        "Voici l'etat de la feuille de route telle que je la partage avec mon ecosysteme. "
        "Elle decrit ce qui est livre et ce qui reste structurellement ouvert."
    )
    pdf.md_file(ROOT / "docs" / "ROADMAP.md")
    pdf.h2("Contribution")
    pdf.body(
        """
Si vous contribuez, apportez des tests, de la documentation, et le respect du style
existant. Une contribution claire vaut mieux qu'une contribution brillante mais opaque.
"""
    )
    lic = ROOT / "LICENSE"
    pdf.h2("Licence")
    if lic.exists():
        pdf.code(lic.read_text(encoding="utf-8", errors="replace")[:4000])
    pdf.h2("Me contacter")
    pdf.bullet(
        [
            f"Nom : {AUTHOR}",
            "Geoinformaticien & Professionnel QHSE",
            f"Telephone : {TEL}",
            f"WhatsApp : {WHATSAPP}",
            f"Email : {EMAIL}",
        ]
    )


def appendix_glossary(pdf) -> None:
    pdf.h1("Annexe A — Glossaire raisonne")
    pdf.body(
        "Je regroupe ici les termes que je veux voir partages sans ambiguite dans une "
        "equipe mixte (technique, QHSE, geomatique)."
    )
    entries = [
        ("AST", "Representation arborescente du programme apres analyse syntaxique."),
        ("CLI", "Interface en ligne de commande du compilateur AFRILANG."),
        ("Codegen", "Generation de code C++ a partir de l'AST annote."),
        ("FFI", "Passerelle controlee vers des bibliotheques C."),
        ("Geoinformatique", "Discipline croisant informatique et sciences de l'information geographique."),
        ("LSP", "Protocole d'intelligence editeur."),
        ("PAHT", "Prix d'Achat Hors Taxes."),
        ("QHSE", "Qualite, Hygiene, Securite, Environnement."),
        ("REPL", "Boucle interactive d'evaluation."),
        ("Result", "Type T or error pour un echec explicite."),
        ("Sandbox", "Execution isolee avec limites."),
        ("Semver", "Versionnage semantique des paquets."),
        ("Stdlib", "Bibliotheque standard du langage."),
        ("Transpilation", "Traduction source-a-source avant compilation native."),
        ("WASM", "WebAssembly, cible d'execution portable."),
    ]
    for term, defn in entries:
        pdf.definition(term, defn)


def appendix_toc(pdf) -> None:
    pdf.h1("Annexe B — Index des chapitres")
    pdf.set_font("Serif", "", 8.5)
    for level, title, page in pdf.toc_entries:
        indent = "   " * max(0, level - 1)
        t = title if len(title) < 82 else title[:79] + "…"
        t = "".join(ch if ord(ch) >= 32 else " " for ch in t)
        dots = "." * max(2, 70 - len(indent) - len(t) - len(str(page)))
        pdf.set_x(pdf.l_margin)
        pdf.set_text_color(45, 42, 38)
        pdf.multi_cell(pdf.epw, 4.1, f"{indent}{t} {dots} {page}")


def colophon(pdf) -> None:
    pdf.h1("Colophon")
    pdf.body(
        f"""
J'ai compose ce manuel pour transmettre AFRILANG avec la meme exigence que je mets dans
mes missions de geoinformatique et de QHSE : clarte, tracabilite, elegance utile.

{AUTHOR}
Tel. {TEL}
WhatsApp {WHATSAPP}
{EMAIL}
"""
    )
    pdf.ornament()
