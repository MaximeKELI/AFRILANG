"""Documentation navigation — bilingual FR/EN."""

NAV_META = [
    ('overview', 'docs_overview'),
    ('getting-started', 'docs_getting_started'),
    ('syntax', 'docs_syntax'),
    ('types', 'docs_types'),
    ('oop', 'docs_oop'),
    ('advanced', 'docs_advanced'),
    ('stdlib', 'docs_stdlib'),
    ('tooling', 'docs_tooling'),
]

NAV_LABELS = {
    'overview': {'fr': 'Vue d\'ensemble', 'en': 'Overview'},
    'getting-started': {'fr': 'Premiers pas', 'en': 'Getting started'},
    'syntax': {'fr': 'Syntaxe de base', 'en': 'Basic syntax'},
    'types': {'fr': 'Types', 'en': 'Types'},
    'oop': {'fr': 'POO', 'en': 'OOP'},
    'advanced': {'fr': 'Fonctionnalités avancées', 'en': 'Advanced features'},
    'stdlib': {'fr': 'Bibliothèque standard', 'en': 'Standard library'},
    'tooling': {'fr': 'Outils', 'en': 'Tooling'},
}

NAV_DESC = {
    'overview': {
        'fr': 'Introduction au langage AFRILANG 1.0',
        'en': 'Introduction to the AFRILANG 1.0 language',
    },
    'getting-started': {
        'fr': 'Installation, premier programme, CLI',
        'en': 'Installation, first program, CLI',
    },
    'syntax': {
        'fr': 'Variables, conditions, boucles, fonctions',
        'en': 'Variables, conditionals, loops, functions',
    },
    'types': {
        'fr': 'Système de types, optionnels, Result',
        'en': 'Type system, optionals, Result',
    },
    'oop': {
        'fr': 'Classes, héritage, interfaces, records',
        'en': 'Classes, inheritance, interfaces, records',
    },
    'advanced': {
        'fr': 'Génériques, enums, match, async, FFI',
        'en': 'Generics, enums, match, async, FFI',
    },
    'stdlib': {
        'fr': 'Modules std/, collections, I/O, HTTP',
        'en': 'std/ modules, collections, I/O, HTTP',
    },
    'tooling': {
        'fr': 'LSP, REPL, paquets, debug, extension IDE',
        'en': 'LSP, REPL, packages, debug, IDE extension',
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
