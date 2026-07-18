#!/usr/bin/env python3
"""Chapitres luxueux — narration à la première personne."""

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
        "Pourquoi j'ai voulu un langage lisible comme une procédure,\net solide comme un outil de terrain.",
    )
    pdf.h1("Pourquoi j'ai créé AFRILANG")
    pdf.body(
        """
J'ai créé AFRILANG d'abord pour une conviction profonde : l'Afrique doit avoir son propre
langage de programmation. Trop longtemps, nous avons appris, travaillé et innové avec des
outils venus d'ailleurs, pensés dans d'autres langues et d'autres contextes. Je voulais un
langage né chez nous, portant notre nom, notre ambition et notre fierté — un langage que
l'on puisse revendiquer comme une contribution africaine au monde du logiciel.
"""
    )
    pdf.body(
        """
Ma deuxième raison est tout aussi importante : je voulais un langage plus intuitif, le
plus proche possible du langage humain. Je rêve d'un outil où l'on écrit presque comme on
parle, où l'intention se lit à voix haute sans traduction mentale. Je souhaite que tout le
monde puisse se lancer dans la programmation — l'étudiant, l'artisan, l'agent de terrain,
la personne curieuse — et que plus personne n'ait peur de cette discipline. La peur du
code vient souvent de sa syntaxe hostile ; en la rendant naturelle, je veux ouvrir grand
la porte.
"""
    )
    pdf.callout(
        "Ma conviction fondatrice",
        "Un langage africain, intuitif et proche du langage humain, pour que la "
        "programmation cesse d'intimider et devienne accessible à toutes et à tous.",
    )
    pdf.h1("Ce que je voulais résoudre")
    pdf.body(
        """
Dans mon travail de géoinformaticien, je vois trop souvent un fossé entre l'intention
humaine et le code. Une procédure QHSE peut être limpide sur le papier, puis se perdre
dans une syntaxe opaque. À l'inverse, un script puissant peut être illisible pour celui
qui devra le maintenir dans six mois, sous pression, sur un site.

J'ai donc posé une exigence simple : AFRILANG doit se lire presque comme de l'anglais
naturel, tout en produisant un exécutable natif via C++17/C++20. Je ne cherche pas un
jouet pédagogique. Je cherche un instrument de précision, capable d'accompagner aussi
bien un calcul géomatique qu'un petit outil de suivi QHSE.
"""
    )
    pdf.definition(
        "AFRILANG",
        "Langage de programmation orienté objet à syntaxe naturelle que j'ai conçu pour "
        "exprimer des intentions clairement, puis les compiler en programmes natifs "
        "performants par transpilation vers C++.",
    )
    pdf.definition(
        "Transpilation",
        "Traduction automatique d'un programme source (ici .afr) vers un autre langage "
        "source (ici C++), avant compilation native. Ce n'est pas de l'interprétation "
        "ligne à ligne : le résultat final est un binaire.",
    )
    pdf.h2("Le pipeline que je défends")
    pdf.body(
        """
Chaque fichier .afr traverse une chaîne que je voulais explicite et auditable — une
habitude que je dois aussi à la culture QHSE : on doit pouvoir expliquer chaque étape.
"""
    )
    pdf.code(
        "fichier.afr\n"
        "  -> resolution des imports\n"
        "  -> analyse lexicale (tokens)\n"
        "  -> analyse syntaxique (AST)\n"
        "  -> analyse semantique (types, portee)\n"
        "  -> generation C++\n"
        "  -> compilation g++ / em++\n"
        "  -> executable natif ou artefact WASM",
        caption="Chaîne de compilation AFRILANG",
    )
    pdf.h2("Principes que je refuse de trahir")
    pdf.bullet(
        [
            "Lisibilité d'abord : say, ask into, is greater than, repeat N times",
            "Bilinguisme pragmatique : anglais pivot, alias français pour l'accessibilité",
            "Types honnêtes : number, text, bool, list, map, optionnels, Result",
            "Performance réelle : C++ sous le capot, pas une couche cosmétique",
            "Écosystème complet : paquets, LSP, playground, stdlib, outils",
            "Erreurs utiles : messages stables, suggestions, localisation",
        ]
    )
    pdf.callout(
        "Lien avec mon métier",
        "La géoinformatique m'impose la rigueur des données ; le QHSE m'impose la clarté "
        "des procédures. AFRILANG est ma réponse technique à ces deux disciplines.",
    )


def part_install(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "II",
        "Installation et premiers pas",
        "Je vous accompagne jusqu'au premier programme qui répond vraiment.",
    )
    pdf.h1("Installer AFRILANG proprement")
    pdf.body(
        """
Avant toute chose, je distingue deux situations. Si vous voulez simplement écrire et
exécuter, l'installateur officiel suffit. Si vous contribuez au compilateur ou si vous
déboguez le codegen, compilez depuis les sources. Dans les deux cas, je recommande de
fixer AFRILANG_HOME et le PATH une fois pour toutes dans votre shell.
"""
    )
    pdf.definition(
        "AFRILANG_HOME",
        "Répertoire racine de votre installation AFRILANG. Le compilateur s'en sert pour "
        "retrouver runtime, stdlib et ressources associées.",
    )
    pdf.h2("Voie rapide")
    pdf.body(
        """
Je fournis un installateur officiel. Une fois le binaire placé dans votre PATH, exportez
AFRILANG_HOME puis vérifiez. Si vous travaillez depuis les sources du projet, compilez
localement comme indiqué plus bas — c'est la méthode que je privilégie en atelier.
"""
    )
    pdf.code(
        'export PATH="$HOME/.local/bin:$PATH"\n'
        'export AFRILANG_HOME="$HOME/.local/afrilang"\n'
        "afrilang version",
        caption="Vérification de l'atelier",
    )
    pdf.body(
        """
Je n'aime pas les installations « magiques » non vérifiées. Après l'installateur, je lance
toujours afrilang version. Si la commande répond avec le chemin home, je sais que mon
atelier est prêt.
"""
    )
    pdf.h2("Compilation depuis les sources")
    pdf.code("mkdir build && cd build\ncmake ..\nmake -j$(nproc)", caption="Build local")
    pdf.h2("Le rituel du premier say")
    pdf.body(
        """
Mon premier programme n'est jamais un framework. C'est une phrase. Je veux entendre la
voix du langage avant d'empiler les abstractions. say affiche une ligne. repeat répète
un bloc. end ferme clairement la structure — j'insiste sur cette fermeture explicite :
elle évite les ambiguïtés que j'ai trop vues dans des procédures mal délimitées.
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
en gestion de projet, on manipule des montants, des taux, des libellés. Je montre ici
comment demander une saisie, convertir un nombre, et produire un résultat compréhensible.
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
        "Mon atelier quotidien : une seule commande, plusieurs gestes précis.",
    )
    pdf.h1("Pourquoi une CLI unifiée")
    pdf.body(
        """
Je refuse de multiplier les outils disparates. afrilang est mon point d'entrée unique :
compiler, exécuter, vérifier, formater, tester, gérer les paquets, servir un playground,
parler à l'éditeur via LSP. Cette unité réduit la charge cognitive — encore une leçon
QHSE : moins d'interfaces, moins d'erreurs opérateur.
"""
    )
    pdf.definition(
        "CLI",
        "Command Line Interface : interface texte permettant de piloter le compilateur "
        "et son écosystème depuis un terminal.",
    )
    rows = [
        ("version", "Je vérifie l'installation et le home."),
        ("build", "Je construis un projet déclaré dans afrilang.toml."),
        ("run", "Je compile puis j'exécute un fichier .afr."),
        ("check", "J'analyse sans produire l'exécutable final."),
        ("test", "Je lance les blocs test et assertions."),
        ("init", "Je crée une ossature de projet ou de bibliothèque."),
        ("lsp", "Je connecte l'intelligence à l'éditeur."),
        ("fmt", "Je normalise le style du code."),
        ("repl", "J'explore des idées en interactif."),
        ("pkg ...", "J'ajoute, installe, mets à jour, publie des paquets."),
        ("serve", "Je démarre un playground local."),
        ("debug / lint / explain / doc", "Je diagnostique, explique, documente."),
        ("compile-js / build-wasm-web", "Je vise le web lorsque c'est pertinent."),
        ("benchmark", "Je mesure compile et exécution."),
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
afrilang.toml n'est pas un détail administratif. C'est le contrat du projet : nom,
version, point d'entrée, dépendances. Je le traite comme une fiche d'identité — stable,
lisible, versionnée.
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
        "Définitions, intentions et mécanismes — pas seulement des exemples à copier.",
    )
    pdf.h1("Comment je lis une spécification")
    pdf.body(
        """
Une spécification sans pédagogie devient un mur. Une pédagogie sans spécification devient
du flou. Dans cette partie, je commence par poser les définitions, puis je vous livre la
spécification officielle enrichie de mon commentaire.
"""
    )
    pdf.definition("Token", "Plus petite unité lexicale reconnue (mot-clé, identifiant, littéral, symbole).")
    pdf.definition("AST", "Arbre syntaxique abstrait : représentation structurée du programme après parsing.")
    pdf.definition(
        "Analyse sémantique",
        "Vérification des sens : types, portée des variables, existence des symboles, "
        "compatibilité des opérations.",
    )
    pdf.h2("Types : ce que je promets à la machine")
    pdf.body(
        """
number est mon type numérique général (double côté C++). text porte les chaînes.
bool exprime le vrai/faux, avec aussi yes/no pour coller au langage naturel.
list of T modélise une séquence homogène. map K to V associe des clés à des valeurs.
T? signifie « valeur optionnelle ». T or error formalise le succès ou l'échec explicite.
"""
    )
    pdf.definition(
        "Type",
        "Contrat sur la nature des valeurs qu'une expression peut produire. Un type bien "
        "choisi documente l'intention et permet au compilateur de refuser les absurdités.",
    )
    pdf.h2("Spécification officielle commentée")
    pdf.body(
        "Je reproduis ci-dessous la spécification du langage. Lisez-la comme un manuel "
        "de précision : chaque construction a une raison d'être."
    )
    pdf.md_file(ROOT / "docs" / "LANGUAGE.md", mono_size=6.8)
    readme = (ROOT / "README.md").read_text(encoding="utf-8", errors="replace")
    m = re.search(r"## Syntaxe du langage[\s\S]*?(?=\n## [^#]|\Z)", readme)
    if m:
        pdf.h2("Complément de syntaxe naturelle")
        pdf.body(
            "J'ajoute ici le panorama de syntaxe naturelle, utile pour les premiers jours "
            "et pour les formateurs qui introduisent AFRILANG en atelier."
        )
        pdf.ingest_markdown(m.group(0), mono_size=6.8)


def part_ask(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "V",
        "Dialoguer avec le programme",
        "L'entrée utilisateur digne d'une procédure claire.",
    )
    pdf.h1("Pourquoi ask compte autant")
    pdf.body(
        """
Un programme silencieux qui n'écoute personne reste un monologue. Dans mes contextes
QHSE et géomatiques, je dois souvent demander un paramètre : un seuil, un taux, un nom
d'opérateur, une coordonnée. ask est ma primitive de dialogue.
"""
    )
    pdf.definition(
        "ask ... into ...",
        "Instruction qui affiche une invite, lit une ligne depuis l'entrée standard, et "
        "range le résultat dans une variable. Sans as, le type est text. Avec as number, "
        "la saisie est convertie en nombre.",
    )
    pdf.h2("La syntaxe que je recommande désormais")
    pdf.body(
        """
J'ai assoupli ask pour coller à mon objectif de simplicité anglaise. Vous n'avez plus à
prédéclarer create x = "". Vous n'avez plus à importer parseFloat pour un cas simple.
Vous écrivez l'intention, le compilateur déclare et convertit.
"""
    )
    pdf.code(
        'ask "Operator name:" into operatorName\n'
        'ask "Threshold:" into threshold as number\n'
        'say "Hello " + operatorName\n'
        'say "Next step uses " + threshold',
        caption="Dialogue minimal",
    )
    pdf.h2("Cas métier : PAHT")
    pdf.body(
        """
Je reviens au PAHT parce qu'il enseigne trois gestes à la fois : saisir du texte, saisir
des nombres, composer un message de synthèse. C'est exactement le niveau de clarté que
j'attends d'un outil de terrain.
"""
    )
    paht = ROOT / "examples" / "paht.afr"
    if paht.exists():
        pdf.code(paht.read_text(encoding="utf-8"), caption="examples/paht.afr")
    pdf.callout(
        "Bonne pratique",
        "Précisez toujours l'unité dans l'invite (%, EUR, TTC, mètres). Une invite floue "
        "produit des données floues — inacceptable en QHSE comme en géomatique.",
    )


def part_advanced(pdf) -> None:
    pdf.part_opener(
        "VI",
        "Objets, modules, async et monde extérieur",
        "Quand le programme grandit sans perdre sa lisibilité.",
    )
    pdf.h1("Modularité")
    pdf.definition(
        "Module",
        "Unité de regroupement de fonctions et classes, exposée via use / import, afin "
        "de séparer les responsabilités sans sacrifier la lisibilité.",
    )
    pdf.body(
        """
J'organise le code comme j'organise une procédure : une responsabilité par module, des
exports explicites, des dépendances assumées. import "std/..." tire la bibliothèque
standard. import d'un fichier local compose votre architecture.
"""
    )
    pdf.code('import "std/json"\nuse json')
    pdf.h2("POO : modéliser le domaine")
    pdf.body(
        """
Les classes me servent à modéliser des entités du monde réel : un site, un capteur, un
dossier de non-conformité, une emprise géographique. fields, init, this, extends,
interfaces : tout est là pour coller au domaine, pas pour faire du style.
"""
    )
    pdf.h2("Async")
    pdf.definition(
        "async / await",
        "Mécanisme permettant d'exprimer des opérations non bloquantes. Une async "
        "function retourne un task T ; await suspend l'exécution jusqu'au résultat.",
    )
    pdf.h2("FFI")
    pdf.body(
        "Lorsque la bibliothèque standard ne suffit pas, j'ouvre une porte contrôlée vers "
        "le C via extern from. Je limite volontairement les bibliothèques autorisées : "
        "la sécurité n'est pas une option."
    )
    pdf.code('extern from "m" function cos(x number) returns number')
    pdf.h2("Tests")
    pdf.body(
        "Un test n'est pas une cérémonie. C'est une preuve minimale que je peux relancer. "
        "Les blocs test et assert vivent dans le langage, pas dans un outil étranger."
    )
    pdf.code('test "addition"\n    assert 1 + 1 is equal to 2\nend')


def part_pedagogy(pdf) -> None:
    pdf.part_opener(
        "VII",
        "Pédagogie",
        "Dix leçons pour entrer, puis le chemin vers la maîtrise.",
    )
    pdf.h1("Parcours débutant")
    pdf.body(
        """
Si vous formez une équipe, gardez cette progression. Chaque leçon ajoute une capacité
sans noyer l'apprenant. J'explique d'abord l'intention, puis je montre le geste.
"""
    )
    lessons = [
        (
            "Leçon 1 — Faire entendre une voix",
            "say écrit une ligne sur la sortie standard. C'est le premier retour visible. "
            "Sans retour, aucun apprentissage n'est possible.",
            'say "Hello AFRILANG"\n',
        ),
        (
            "Leçon 2 — Nommer pour gouverner",
            "create déclare. set modifie. Nommer une valeur, c'est déjà documenter.",
            'create site = "Depot Nord"\ncreate score = 92\nsay site\n',
        ),
        (
            "Leçon 3 — Décider",
            "if ... then ... else ... end formalise une branche. Les comparaisons "
            "naturelles (is greater than) réduisent la charge cognitive.",
            'if score is greater than 80 then\n    say "Conforme"\nelse\n    say "A revoir"\nend\n',
        ),
        (
            "Leçon 4 — Répéter sans se répéter",
            "repeat fixe un nombre d'itérations. while exprime une condition durable.",
            'repeat 3 times\n    say "Controle"\nend\n',
        ),
        (
            "Leçon 5 — Collections",
            "Une list of T est une séquence homogène. Elle devient std::vector côté C++.",
            "create mesures = list of 1.2, 1.3, 1.1\nfor each m in mesures do\n    say m\nend\n",
        ),
        (
            "Leçon 6 — Fonctions",
            "Une function encapsule une responsabilité. returns annonce le contrat.",
            "function double(x number) returns number\n    return x * 2\nend\n",
        ),
        (
            "Leçon 7 — Dialoguer",
            "ask transforme l'utilisateur en partenaire du calcul.",
            'ask "Seuil:" into seuil as number\nsay "Seuil retenu : " + seuil\n',
        ),
        (
            "Leçon 8 — Objets",
            "Une class modélise une entité durable du domaine.",
            'class Capteur\n    public field nom text\n    function init(n text)\n        set this.nom = n\n    end\nend\n',
        ),
        (
            "Leçon 9 — Bibliothèque standard",
            "Réutilisez avant de réinventer. Le core est stabilisé pour la production.",
            'import "std/math"\nuse math\nsay sqrt(16)\n',
        ),
        (
            "Leçon 10 — Projet",
            "init, run, test : le cycle de vie minimal d'une équipe sérieuse.",
            "afrilang init atelier_qhs\ncd atelier_qhs\nafrilang run src/main.afr\n",
        ),
    ]
    for title, prose, code in lessons:
        pdf.h3(title)
        pdf.body(prose)
        pdf.code(code)
    pdf.h2("Vers l'intermédiaire et l'avancé")
    pdf.body(
        """
Ensuite viennent Result, match, génériques, cibles cross (linux-arm64, wasm32), et la
mesure (--profile). Je vous invite à ne brûler aucune étape : la maîtrise est une
accumulation de clartés, pas une accumulation de raccourcis.
"""
    )


def part_stdlib(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "VIII",
        "Bibliothèque standard",
        "La carte d'un vaste territoire, avec boussole et légendes.",
    )
    pdf.h1("Comment je structure la stdlib")
    pdf.body(
        """
Je refuse un monolithe indigeste. La bibliothèque standard est stratifiée. Le core est
le socle de production. Simple, medium et complex étendent l'espace d'exploration —
y compris pour mes besoins de géoinformatique (analyse spatiale, raster, segmentation,
visualisation, jeux de données).
"""
    )
    pdf.definition(
        "Stdlib (bibliothèque standard)",
        "Ensemble de modules fournis avec le langage pour accomplir des tâches courantes "
        "sans réécrire l'infrastructure.",
    )
    pdf.bullet(
        [
            "Core : runtime C++ réel (io, json, fs, http, str, math, ...)",
            "Simple : import \"std/nom\" — milliers de briques utiles",
            "Medium : import \"std/m/nom\"",
            "Complex : import \"std/c/nom\" — dont packs géomatiques et data",
        ]
    )
    pdf.callout(
        "Regard géoinformaticien",
        "Dans les couches avancées, vous trouverez des familles utiles à mon métier : "
        "giskit/gisultra, rasterultra, segultra, dataultra, vizultra. Je les documente "
        "ici comme référence de travail.",
    )
    pdf.h2("Core")
    pdf.md_file(ROOT / "docs" / "CORE_STDLIB.md")
    pdf.h2("API core")
    pdf.md_file(ROOT / "docs" / "STDLIB_API.md")
    pdf.h2("Référence SIMPLE")
    pdf.body(
        "Je fournis ci-dessous la référence simple complète. Servez-vous-en comme d'un "
        "catalogue raisonné, pas comme d'une obligation de tout mémoriser."
    )
    pdf.md_file(ROOT / "docs" / "STDLIB_SIMPLE.md", mono_size=6.4)
    pdf.h2("Référence MEDIUM")
    pdf.md_file(ROOT / "docs" / "STDLIB_MEDIUM.md", mono_size=6.4)
    pdf.h2("Référence COMPLEX")
    pdf.body(
        "La couche complex est vaste. Je l'inclus comme atlas : vous y naviguerez selon "
        "vos campagnes (SIG, raster, data science, visualisation)."
    )
    pdf.md_file(ROOT / "docs" / "STDLIB_COMPLEX.md", mono_size=6)
    pdf.h2("Génération des catalogues")
    pdf.md_file(ROOT / "docs" / "STDLIB_GEN.md")


def part_pkg(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "IX",
        "Paquets",
        "Réutiliser sans perdre le contrôle.",
    )
    pdf.h1("Ma philosophie des dépendances")
    pdf.body(
        """
Une dépendance est un engagement. En QHSE, j'exige la traçabilité ; en ingénierie
logicielle aussi. Le gestionnaire de paquets d'AFRILANG formalise cet engagement via
afrilang.toml, le lockfile, et des règles semver explicites.
"""
    )
    pdf.definition(
        "Semver",
        "Versionnage sémantique (majeure.mineure.correctif). Les opérateurs ^ et ~ "
        "encadrent les mises à jour acceptables sans surprise brutale.",
    )
    pdf.md_file(ROOT / "docs" / "PKG.md")


def part_tools(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "X",
        "Outils du quotidien",
        "Éditeur, formatage, diagnostic, cible web.",
    )
    pdf.h1("LSP et éditeur")
    pdf.body(
        """
Je travaille mieux lorsque l'éditeur me parle. afrilang lsp fournit diagnostics, hover,
définition et complétion bilingue. L'extension Visual Studio Code / Cursor s'y branche.
"""
    )
    pdf.definition(
        "LSP",
        "Language Server Protocol : protocole standard reliant un éditeur à un serveur "
        "d'intelligence linguistique indépendant.",
    )
    vs = ROOT / "vscode-afrilang" / "README.md"
    if vs.exists():
        pdf.h2("Extension éditeur")
        pdf.md_file(vs, max_lines=220)
    pdf.h2("WASM")
    pdf.body(
        "Certaines cibles vivent dans le navigateur. Je documente honnêtement ce qui "
        "fonctionne en WASM et ce qui reste natif (UI lourde, filesystem, etc.)."
    )
    pdf.md_file(ROOT / "docs" / "WASM_COMPAT.md")
    pdf.h2("Qualité")
    pdf.bullet(
        [
            "fmt — style stable, relectures plus rapides",
            "lint — signaux faibles avant l'incident",
            "debug — GDB lorsque le binaire doit parler",
            "explain — pédagogie intégrée pour la formation",
        ]
    )


def part_web(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "XI",
        "Surfaces numériques",
        "Playground, site, mobile : la même exigence de clarté.",
    )
    pdf.h1("Playground local")
    pdf.body(
        "Parfois je démontre AFRILANG sans installer quoi que ce soit sur la machine "
        "d'un interlocuteur. afrilang serve ouvre ce théâtre local."
    )
    pdf.code("afrilang serve\n# http://127.0.0.1:8080")
    web = ROOT / "web" / "README.md"
    if web.exists():
        pdf.h2("Site dynamique")
        pdf.body(
            "Le site officiel s'appuie sur une stack robuste pour documenter, explorer "
            "les paquets, et offrir un playground connecté."
        )
        pdf.md_file(web)
    mob = ROOT / "mobile" / "README.md"
    if mob.exists():
        pdf.h2("Mobile")
        pdf.md_file(mob, max_lines=180)


def part_examples(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "XII",
        "Exemples commentés",
        "Une bibliothèque vivante de gestes réels.",
    )
    pdf.h1("Comment j'utilise les exemples")
    pdf.body(
        """
Un exemple n'est pas un trophée. C'est un scénario. Je recommande de le lire à voix
haute, de prédire la sortie, puis de l'exécuter. Ensuite seulement, modifiez-le.
"""
    )
    pdf.code("afrilang run examples/NOM.afr")
    examples = sorted((ROOT / "examples").glob("*.afr"))
    pdf.h2(f"Catalogue — {len(examples)} programmes")
    for i, ex in enumerate(examples, 1):
        pdf.h3(f"{i}. {ex.name}")
        pdf.body(
            f"Fichier {ex.name}. Observez d'abord la structure (déclarations, contrôle, "
            f"sorties). Puis exécutez et confrontez votre prédiction au résultat."
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
Je résume ici l'architecture pour les lecteurs avancés et pour les auditeurs techniques
qui m'interrogent sur la fiabilité de la chaîne. Comprendre le pipeline, c'est pouvoir
diagnostiquer.
"""
    )
    pdf.bullet(
        [
            "Lexer — découpe le texte en tokens",
            "Parser — construit l'AST",
            "SemanticAnalyzer — types, portée, drapeaux (usesAsk, usesUi, usesAsync)",
            "CodeGenerator — C++ puis g++/em++",
            "Sandbox — exécution bornée ; console interactive pour ask",
            "Cache — évite le travail inutile lorsque rien n'a changé",
        ]
    )
    pdf.h2("Correspondances essentielles")
    pdf.code(
        "list -> std::vector\ntext -> std::string\nnumber -> double\n"
        "ask as number -> getline + std::stod\nsay / + -> toString / concat"
    )


def part_closing(pdf, ROOT: Path) -> None:
    pdf.part_opener(
        "XIV",
        "Route et contacts",
        "Ce que je compte continuer, et comment me joindre.",
    )
    pdf.h1("Feuille de route")
    pdf.body(
        "Voici l'état de la feuille de route telle que je la partage avec mon écosystème. "
        "Elle décrit ce qui est livré et ce qui reste structurellement ouvert."
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
            "Géoinformaticien & Professionnel QHSE",
            f"Téléphone : {TEL}",
            f"WhatsApp : {WHATSAPP}",
            f"Email : {EMAIL}",
        ]
    )


def appendix_glossary(pdf) -> None:
    pdf.h1("Annexe A — Glossaire raisonné")
    pdf.body(
        "Je regroupe ici les termes que je veux voir partagés sans ambiguïté dans une "
        "équipe mixte (technique, QHSE, géomatique)."
    )
    entries = [
        ("AST", "Représentation arborescente du programme après analyse syntaxique."),
        ("CLI", "Interface en ligne de commande du compilateur AFRILANG."),
        ("Codegen", "Génération de code C++ à partir de l'AST annoté."),
        ("FFI", "Passerelle contrôlée vers des bibliothèques C."),
        ("Géoinformatique", "Discipline croisant informatique et sciences de l'information géographique."),
        ("LSP", "Protocole d'intelligence éditeur."),
        ("PAHT", "Prix d'Achat Hors Taxes."),
        ("QHSE", "Qualité, Hygiène, Sécurité, Environnement."),
        ("REPL", "Boucle interactive d'évaluation."),
        ("Result", "Type T or error pour un échec explicite."),
        ("Sandbox", "Exécution isolée avec limites."),
        ("Semver", "Versionnage sémantique des paquets."),
        ("Stdlib", "Bibliothèque standard du langage."),
        ("Transpilation", "Traduction source-à-source avant compilation native."),
        ("WASM", "WebAssembly, cible d'exécution portable."),
    ]
    for term, defn in entries:
        pdf.definition(term, defn)


def appendix_toc(pdf) -> None:
    pdf.h1("Annexe B — Index des chapitres")
    pdf.set_font("Serif", "", 8.5)
    for level, title, page in pdf.toc_entries:
        indent = "   " * max(0, level - 1)
        t = title if len(title) < 82 else title[:79] + "..."
        t = "".join(ch if ord(ch) >= 32 else " " for ch in t)
        dots = "." * max(2, 70 - len(indent) - len(t) - len(str(page)))
        pdf.set_x(pdf.l_margin)
        pdf.set_text_color(45, 42, 38)
        pdf.multi_cell(pdf.epw, 4.1, f"{indent}{t} {dots} {page}")


def colophon(pdf) -> None:
    pdf.h1("Colophon")
    pdf.body(
        f"""
J'ai composé ce manuel pour transmettre AFRILANG avec la même exigence que je mets dans
mes missions de géoinformatique et de QHSE : clarté, traçabilité, élégance utile.

{AUTHOR}
Tél. {TEL}
WhatsApp {WHATSAPP}
{EMAIL}
"""
    )
    pdf.ornament()
