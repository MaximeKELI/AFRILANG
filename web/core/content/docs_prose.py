"""Enrichissement prose : explications littérales FR/EN avant/après le code."""

from .docs_pages import callout, code, h2, p, table, ul


def enrich_language_pages_with_prose(pages):
    """Ajoute des explications littérales aux pages langage déjà présentes."""
    _extend(pages, "syntax", _syntax_fr(), _syntax_en())
    _extend(pages, "types", _types_fr(), _types_en())
    _extend(pages, "oop", _oop_fr(), _oop_en())
    _extend(pages, "functional", _functional_fr(), _functional_en())
    _extend(pages, "pattern-matching", _pattern_fr(), _pattern_en())


def _extend(pages, slug, fr_blocks, en_blocks):
    pages[slug]["fr"]["blocks"] = fr_blocks + pages[slug]["fr"]["blocks"]
    pages[slug]["en"]["blocks"] = en_blocks + pages[slug]["en"]["blocks"]


def _syntax_fr():
    return [
        h2("À lire avant les exemples"),
        p(
            "La syntaxe AFRILANG est conçue pour se <strong>lire à voix haute</strong>. "
            "Au lieu d’écrire <code>if (x &gt; 18)</code>, on écrit "
            "<code>if x is greater than 18 then</code>. L’idée n’est pas d’être plus long "
            "pour le plaisir : c’est de rendre le programme compréhensible à un débutant, "
            "à un enseignant, ou à quelqu’un qui relit du code six mois plus tard."
        ),
        p(
            "Tout bloc (condition, boucle, fonction, classe, test) se termine par "
            "<code>end</code> (ou <code>fin</code> en français). C’est volontaire : "
            "on voit clairement où s’arrête chaque structure, sans compter les accolades."
        ),
        p(
            "Vous pouvez mélanger les mots-clés anglais et français dans un même dépôt, "
            "mais <strong>restez cohérent dans un fichier</strong> pour la lisibilité. "
            "Les messages d’erreur suivent <code>AFRILANG_LOCALE</code>."
        ),
        callout(
            "<strong>En pratique</strong> — Lisez d’abord le paragraphe, puis le code. "
            "Le code illustre ; le texte explique <em>pourquoi</em>."
        ),
    ]


def _syntax_en():
    return [
        h2("Read this before the examples"),
        p(
            "AFRILANG syntax is meant to be <strong>read aloud</strong>. "
            "Instead of <code>if (x &gt; 18)</code>, you write "
            "<code>if x is greater than 18 then</code>. The goal is not verbosity for its own sake: "
            "it is to keep programs understandable for beginners, teachers, and future you."
        ),
        p(
            "Every block (conditional, loop, function, class, test) ends with "
            "<code>end</code> (or <code>fin</code> in French). That makes structure obvious "
            "without counting braces."
        ),
        p(
            "You may mix English and French keywords in a repo, but "
            "<strong>stay consistent inside one file</strong>. Error messages follow "
            "<code>AFRILANG_LOCALE</code>."
        ),
        callout(
            "<strong>How to use this page</strong> — Read the paragraph first, then the code. "
            "Code illustrates; prose explains <em>why</em>."
        ),
    ]


def _types_fr():
    return [
        h2("Pourquoi des types explicites ?"),
        p(
            "AFRILANG est <strong>statiquement typé</strong> : le compilateur connaît le type "
            "de chaque valeur avant l’exécution. Cela permet de détecter beaucoup d’erreurs "
            "tôt (mauvais argument, liste hétérogène interdite, etc.) et de générer du C++ efficace."
        ),
        p(
            "<code>number</code> est un nombre flottant (comme un <code>double</code> C++). "
            "Pour la plupart des programmes, c’est le type numérique unique : pas besoin de "
            "choisir entre int/float au début. <code>text</code> est une chaîne Unicode UTF-8. "
            "<code>bool</code> vaut <code>true</code>/<code>false</code> (ou <code>vrai</code>/<code>faux</code>)."
        ),
        p(
            "Les <strong>optionnels</strong> (<code>text?</code>) modélisent « une valeur ou "
            "l’absence de valeur ». On initialise avec <code>nothing</code>, et on teste avec "
            "<code>is defined</code>. Ce n’est <em>pas</em> la même chose qu’une chaîne vide : "
            "vide = texte présent mais sans caractères ; <code>nothing</code> = pas de texte du tout."
        ),
        p(
            "Un <strong>Result</strong> (<code>number or error</code>) représente un calcul qui "
            "peut échouer de façon attendue (division par zéro, parse invalide). On ne plante "
            "pas le programme : on retourne une erreur que l’appelant doit examiner avec "
            "<code>is error</code>, puis lire <code>.value</code> ou <code>.message</code>."
        ),
    ]


def _types_en():
    return [
        h2("Why explicit types?"),
        p(
            "AFRILANG is <strong>statically typed</strong>: the compiler knows each value’s type "
            "before runtime. That catches many mistakes early and enables efficient C++ output."
        ),
        p(
            "<code>number</code> is a floating value (like C++ <code>double</code>). "
            "For most programs it is the single numeric type. <code>text</code> is a UTF-8 string. "
            "<code>bool</code> is <code>true</code>/<code>false</code>."
        ),
        p(
            "<strong>Optionals</strong> (<code>text?</code>) mean “a value or no value”. "
            "Initialize with <code>nothing</code>, test with <code>is defined</code>. "
            "That is <em>not</em> the same as an empty string: empty = present but blank; "
            "<code>nothing</code> = absent entirely."
        ),
        p(
            "A <strong>Result</strong> (<code>number or error</code>) models a computation that "
            "may fail in an expected way. The caller checks <code>is error</code>, then reads "
            "<code>.value</code> or <code>.message</code>."
        ),
    ]


def _oop_fr():
    return [
        h2("Idée générale de la POO en AFRILANG"),
        p(
            "La programmation orientée objet regroupe <strong>données</strong> (champs) et "
            "<strong>comportements</strong> (méthodes) dans des <code>class</code>. "
            "On crée des instances avec <code>new</code>. Le constructeur s’appelle "
            "<code>init</code> : c’est la fonction appelée au moment du <code>new</code>."
        ),
        p(
            "L’<strong>héritage</strong> (<code>extends</code>) permet de spécialiser une classe "
            "existante : un <code>Dog</code> est un <code>Animal</code>, il peut réutiliser "
            "<code>speak</code> ou le redéfinir. <code>super</code> appelle le parent."
        ),
        p(
            "Une <strong>interface</strong> décrit un contrat (« qui sait parler ») sans fournir "
            "l’implémentation. Une classe <code>implements</code> une ou plusieurs interfaces. "
            "Les <strong>records</strong> sont des structures légères quand vous n’avez besoin "
            "que de champs, sans hiérarchie complexe."
        ),
    ]


def _oop_en():
    return [
        h2("OOP in AFRILANG — the idea"),
        p(
            "Object-oriented programming groups <strong>data</strong> (fields) and "
            "<strong>behavior</strong> (methods) in a <code>class</code>. "
            "Create instances with <code>new</code>. The constructor is named "
            "<code>init</code>."
        ),
        p(
            "<strong>Inheritance</strong> (<code>extends</code>) specializes an existing class. "
            "<code>super</code> calls the parent."
        ),
        p(
            "An <strong>interface</strong> is a contract without implementation. "
            "A class <code>implements</code> one or more interfaces. "
            "<strong>Records</strong> are lightweight structs when you only need fields."
        ),
    ]


def _functional_fr():
    return [
        h2("Transformer des listes sans boucles manuelles"),
        p(
            "Souvent on veut « prendre chaque élément, le transformer, garder certains, "
            "agréger ». AFRILANG propose une syntaxe naturelle pour cela : "
            "<code>map each …</code>, <code>filter each … where …</code>, "
            "<code>reduce … with each …</code>."
        ),
        p(
            "<strong>map</strong> produit une nouvelle liste de même longueur : chaque élément "
            "est remplacé par le résultat d’une expression ou d’un petit bloc. "
            "<strong>filter</strong> garde seulement les éléments qui satisfont une condition. "
            "<strong>reduce</strong> accumule (somme, concaténation, etc.)."
        ),
        p(
            "Ces opérations ne modifient pas la liste d’origine : elles en créent une nouvelle. "
            "C’est plus sûr pour raisonner, surtout dans les tests."
        ),
    ]


def _functional_en():
    return [
        h2("Transforming lists without hand-written loops"),
        p(
            "Often you want to “take each item, transform it, keep some, aggregate”. "
            "AFRILANG offers natural syntax: "
            "<code>map each …</code>, <code>filter each … where …</code>, "
            "<code>reduce … with each …</code>."
        ),
        p(
            "<strong>map</strong> builds a new list of the same length. "
            "<strong>filter</strong> keeps matching items. "
            "<strong>reduce</strong> accumulates (sum, join, …)."
        ),
        p(
            "These operations do not mutate the original list; they create a new one."
        ),
    ]


def _pattern_fr():
    return [
        h2("Décider selon la forme d’une valeur"),
        p(
            "Le pattern matching répond à la question : « cette valeur est-elle de telle "
            "variante, et quels champs contient-elle ? ». C’est plus sûr qu’une cascade de "
            "<code>if</code> : le compilateur peut vérifier que tous les cas sont couverts "
            "(exhaustivité), ou exiger un <code>default</code>."
        ),
        p(
            "Un <strong>enum</strong> liste des cas nommés, éventuellement avec payload "
            "(<code>case Error with message text</code>). Une <strong>union</strong> taguée "
            "regroupe des formes différentes (cercle / rectangle). "
            "<code>match</code> peut être une instruction (effets de bord) ou une expression "
            "(calcule une valeur)."
        ),
    ]


def _pattern_en():
    return [
        h2("Branching on the shape of a value"),
        p(
            "Pattern matching answers: “is this value that variant, and which fields does it carry?”. "
            "Safer than long <code>if</code> chains: the compiler can require exhaustiveness "
            "or a <code>default</code>."
        ),
        p(
            "An <strong>enum</strong> lists named cases, optionally with payload. "
            "A tagged <strong>union</strong> groups different shapes. "
            "<code>match</code> can be a statement or an expression."
        ),
    ]
