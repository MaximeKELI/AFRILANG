"""Documentation navigation — bilingual FR/EN."""

NAV_META = [
    ('overview', 'docs_overview'),
    ('getting-started', 'docs_getting_started'),
    ('syntax', 'docs_syntax'),
    ('types', 'docs_types'),
    ('functional', 'docs_functional'),
    ('oop', 'docs_oop'),
    ('pattern-matching', 'docs_pattern'),
    ('modules', 'docs_modules'),
    ('exceptions', 'docs_exceptions'),
    ('async', 'docs_async'),
    ('gui', 'docs_gui'),
    ('advanced', 'docs_advanced'),
    ('stdlib', 'docs_stdlib'),
    ('package-manager', 'docs_pkg'),
    ('tooling', 'docs_tooling'),
    ('spec', 'docs_spec'),
]

NAV_LABELS = {
    'overview': {'fr': 'Vue d\'ensemble', 'en': 'Overview'},
    'getting-started': {'fr': 'Premiers pas', 'en': 'Getting started'},
    'syntax': {'fr': 'Syntaxe de base', 'en': 'Basic syntax'},
    'types': {'fr': 'Types', 'en': 'Types'},
    'functional': {'fr': 'Lambdas & collections', 'en': 'Lambdas & collections'},
    'oop': {'fr': 'POO', 'en': 'OOP'},
    'pattern-matching': {'fr': 'Pattern matching', 'en': 'Pattern matching'},
    'modules': {'fr': 'Modules', 'en': 'Modules'},
    'exceptions': {'fr': 'Exceptions', 'en': 'Exceptions'},
    'async': {'fr': 'Async / await', 'en': 'Async / await'},
    'gui': {'fr': 'Interfaces graphiques', 'en': 'Graphical UI'},
    'advanced': {'fr': 'FFI & tests', 'en': 'FFI & tests'},
    'stdlib': {'fr': 'Bibliothèque standard', 'en': 'Standard library'},
    'package-manager': {'fr': 'Paquets', 'en': 'Packages'},
    'tooling': {'fr': 'Outils', 'en': 'Tooling'},
    'spec': {'fr': 'Référence', 'en': 'Reference'},
}

NAV_DESC = {
    'overview': {
        'fr': 'Introduction et parcours d\'apprentissage',
        'en': 'Introduction and learning path',
    },
    'getting-started': {
        'fr': 'Installation, premier programme, CLI',
        'en': 'Installation, first program, CLI',
    },
    'syntax': {
        'fr': 'Variables, fonctions, maps, boucles, alias FR/EN',
        'en': 'Variables, functions, maps, loops, FR/EN aliases',
    },
    'types': {
        'fr': 'Types, optionnels, Result, génériques',
        'en': 'Types, optionals, Result, generics',
    },
    'functional': {
        'fr': 'Lambdas, map/filter/reduce, paramètres par défaut',
        'en': 'Lambdas, map/filter/reduce, default params',
    },
    'oop': {
        'fr': 'Classes, héritage, records, opérateurs',
        'en': 'Classes, inheritance, records, operators',
    },
    'pattern-matching': {
        'fr': 'Enums, unions, match expression',
        'en': 'Enums, unions, match expressions',
    },
    'modules': {
        'fr': 'export/private, import, use',
        'en': 'export/private, import, use',
    },
    'exceptions': {
        'fr': 'try / catch / raise',
        'en': 'try / catch / raise',
    },
    'async': {
        'fr': 'Coroutines, await, std/async, I/O async',
        'en': 'Coroutines, await, std/async, async I/O',
    },
    'gui': {
        'fr': 'SDL2, fenêtres, boutons, std/ui',
        'en': 'SDL2, windows, buttons, std/ui',
    },
    'advanced': {
        'fr': 'FFI, tests intégrés',
        'en': 'FFI, built-in tests',
    },
    'stdlib': {
        'fr': '7900+ modules, SIG, data science, IA, SQLite',
        'en': '7900+ modules, GIS, data science, AI, SQLite',
    },
    'package-manager': {
        'fr': 'afrilang.toml, pkg, semver',
        'en': 'afrilang.toml, pkg, semver',
    },
    'tooling': {
        'fr': 'CLI, LSP, REPL, lint, debug, IDE',
        'en': 'CLI, LSP, REPL, lint, debug, IDE',
    },
    'spec': {
        'fr': 'Spécification 1.0, UTF-8, error codes',
        'en': 'Spec 1.0, UTF-8, error codes',
    },
}


def get_docs_nav(lang):
    code = (lang or 'fr')[:2]
    nav = []
    for slug, url_name in NAV_META:
        nav.append({
            'slug': slug,
            'url_name': url_name,
            'title': NAV_LABELS[slug].get(code, NAV_LABELS[slug]['fr']),
            'description': NAV_DESC[slug].get(code, NAV_DESC[slug]['fr']),
        })
    return nav


def docs_context(active_url_name, lang=None):
    return {
        'docs_nav': get_docs_nav(lang),
        'docs_active': active_url_name,
    }


def build_doc_nav_order():
    return [(url_name, slug) for slug, url_name in NAV_META]
