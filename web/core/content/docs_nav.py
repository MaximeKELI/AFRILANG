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
    ('testing', 'docs_testing'),
    ('tooling', 'docs_tooling'),
    ('wasm', 'docs_wasm'),
    ('spec', 'docs_spec'),
    ('contributing', 'docs_contributing'),
]

NAV_LABELS = {
    'overview': {'fr': "Vue d'ensemble", 'en': 'Overview'},
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
    'advanced': {'fr': 'FFI', 'en': 'FFI'},
    'stdlib': {'fr': 'Bibliothèque standard', 'en': 'Standard library'},
    'package-manager': {'fr': 'Paquets', 'en': 'Packages'},
    'testing': {'fr': 'Tests', 'en': 'Testing'},
    'tooling': {'fr': 'Outils', 'en': 'Tooling'},
    'wasm': {'fr': 'WASM & JS', 'en': 'WASM & JS'},
    'spec': {'fr': 'Référence', 'en': 'Reference'},
    'contributing': {'fr': 'Contribuer', 'en': 'Contributing'},
}

NAV_DESC = {
    'overview': {
        'fr': "Parcours d'apprentissage numéroté",
        'en': 'Numbered learning path',
    },
    'getting-started': {
        'fr': 'Installation pas à pas, PATH, premier programme',
        'en': 'Step-by-step install, PATH, first program',
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
        'fr': 'export/private, import, use, chemins std/pkg',
        'en': 'export/private, import, use, std/pkg paths',
    },
    'exceptions': {
        'fr': 'try/catch/raise et Result',
        'en': 'try/catch/raise and Result',
    },
    'async': {
        'fr': 'Coroutines, await, std/async, limites WASM',
        'en': 'Coroutines, await, std/async, WASM limits',
    },
    'gui': {
        'fr': 'SDL2, fenêtres, boutons, std/ui',
        'en': 'SDL2, windows, buttons, std/ui',
    },
    'advanced': {
        'fr': 'Interop C / extern',
        'en': 'C interop / extern',
    },
    'stdlib': {
        'fr': 'Core vs généré, API prioritaire',
        'en': 'Core vs generated, priority API',
    },
    'package-manager': {
        'fr': 'toml, lock, semver, git/path, publish',
        'en': 'toml, lock, semver, git/path, publish',
    },
    'testing': {
        'fr': 'assert, tests/, --specs, pkg test',
        'en': 'assert, tests/, --specs, pkg test',
    },
    'tooling': {
        'fr': 'CLI, LSP, REPL, IDE, cibles',
        'en': 'CLI, LSP, REPL, IDE, targets',
    },
    'wasm': {
        'fr': 'wasm32, playground JS, matrice de compat',
        'en': 'wasm32, JS playground, compat matrix',
    },
    'spec': {
        'fr': 'Spécification 1.0 condensée',
        'en': 'Condensed 1.0 specification',
    },
    'contributing': {
        'fr': 'Build, tests, PR, conventions',
        'en': 'Build, tests, PR, conventions',
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
