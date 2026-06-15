"""Navigation et métadonnées de la documentation AFRILANG."""

DOCS_NAV = [
    {
        'slug': 'overview',
        'title': 'Vue d\'ensemble',
        'url_name': 'docs_overview',
        'description': 'Introduction au langage AFRILANG 1.0',
    },
    {
        'slug': 'getting-started',
        'title': 'Premiers pas',
        'url_name': 'docs_getting_started',
        'description': 'Installation, premier programme, CLI',
    },
    {
        'slug': 'syntax',
        'title': 'Syntaxe de base',
        'url_name': 'docs_syntax',
        'description': 'Variables, conditions, boucles, fonctions',
    },
    {
        'slug': 'types',
        'title': 'Types',
        'url_name': 'docs_types',
        'description': 'Système de types, optionnels, Result',
    },
    {
        'slug': 'oop',
        'title': 'POO',
        'url_name': 'docs_oop',
        'description': 'Classes, héritage, interfaces, records',
    },
    {
        'slug': 'advanced',
        'title': 'Fonctionnalités avancées',
        'url_name': 'docs_advanced',
        'description': 'Génériques, enums, match, async, FFI',
    },
    {
        'slug': 'stdlib',
        'title': 'Bibliothèque standard',
        'url_name': 'docs_stdlib',
        'description': 'Modules std/, collections, I/O, HTTP',
    },
    {
        'slug': 'tooling',
        'title': 'Outils',
        'url_name': 'docs_tooling',
        'description': 'LSP, REPL, paquets, debug, extension IDE',
    },
]


def docs_context(active_url_name):
    return {
        'docs_nav': DOCS_NAV,
        'docs_active': active_url_name,
    }
