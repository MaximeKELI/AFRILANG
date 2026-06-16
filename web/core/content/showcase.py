"""Showcase — projets AFRILANG FR/EN (liens GitHub)."""

CATEGORIES = [
    {'id': 'official', 'fr': 'Officiel', 'en': 'Official'},
    {'id': 'tools', 'fr': 'Outils & IDE', 'en': 'Tools & IDE'},
    {'id': 'web', 'fr': 'Web & playground', 'en': 'Web & playground'},
    {'id': 'packages', 'fr': 'Paquets', 'en': 'Packages'},
    {'id': 'demos', 'fr': 'Démos & exemples', 'en': 'Demos & examples'},
]

PROJECTS = [
    {
        'slug': 'afrilang',
        'category': 'official',
        'github': 'https://github.com/MaximeKELI/AFRILANG',
        'featured': True,
        'tags': ['compiler', 'stdlib', 'MIT'],
        'fr': {
            'title': 'AFRILANG',
            'summary': 'Compilateur, stdlib (7900+ modules), LSP, CLI et suite de tests.',
            'highlights': ['Transpilation C++17', '60+ exemples CI', 'Cross-compile WASM'],
        },
        'en': {
            'title': 'AFRILANG',
            'summary': 'Compiler, stdlib (7900+ modules), LSP, CLI and test suite.',
            'highlights': ['C++17 transpilation', '60+ CI examples', 'WASM cross-compile'],
        },
    },
    {
        'slug': 'vscode-extension',
        'category': 'tools',
        'github': 'https://github.com/MaximeKELI/AFRILANG/tree/main/vscode-afrilang',
        'featured': True,
        'tags': ['LSP', 'VS Code', 'Cursor'],
        'fr': {
            'title': 'Extension VS Code / Cursor',
            'summary': 'Coloration syntaxique, LSP 1.1, snippets et icônes AFRILANG.',
            'highlights': ['Diagnostics live', 'Format on save', 'Thème icônes'],
        },
        'en': {
            'title': 'VS Code / Cursor extension',
            'summary': 'Syntax highlighting, LSP 1.1, snippets and AFRILANG icon theme.',
            'highlights': ['Live diagnostics', 'Format on save', 'Icon theme'],
        },
    },
    {
        'slug': 'web-site',
        'category': 'web',
        'github': 'https://github.com/MaximeKELI/AFRILANG/tree/main/web',
        'featured': True,
        'tags': ['Django', 'playground', 'docs'],
        'fr': {
            'title': 'Site officiel Django',
            'summary': 'Documentation, playground, tutoriel, benchmarks et registre de paquets.',
            'highlights': ['Playground CodeMirror', '16 pages doc', 'i18n FR/EN'],
        },
        'en': {
            'title': 'Official Django site',
            'summary': 'Documentation, playground, tutorial, benchmarks and package registry.',
            'highlights': ['CodeMirror playground', '16 doc pages', 'FR/EN i18n'],
        },
    },
    {
        'slug': 'static-site',
        'category': 'web',
        'github': 'https://github.com/MaximeKELI/AFRILANG/tree/main/site',
        'featured': False,
        'tags': ['C++', 'serve', 'WASM'],
        'fr': {
            'title': 'Playground statique (afrilang serve)',
            'summary': 'Serveur HTTP léger intégré au compilateur — playground local.',
            'highlights': ['API /api/run', 'Compile JS client', 'WASM browser'],
        },
        'en': {
            'title': 'Static playground (afrilang serve)',
            'summary': 'Lightweight HTTP server built into the compiler — local playground.',
            'highlights': ['/api/run API', 'Client JS compile', 'Browser WASM'],
        },
    },
    {
        'slug': 'packages-registry',
        'category': 'packages',
        'github': 'https://github.com/MaximeKELI/AFRILANG/tree/main/packages',
        'featured': False,
        'tags': ['pkg', 'registry'],
        'fr': {
            'title': 'Registre de paquets',
            'summary': 'Paquets certifiés (math, json, http…) avec manifest.toml et SHA256.',
            'highlights': ['afrilang pkg add', 'Blessed packages', 'Index JSON'],
        },
        'en': {
            'title': 'Package registry',
            'summary': 'Certified packages (math, json, http…) with manifest.toml and SHA256.',
            'highlights': ['afrilang pkg add', 'Blessed packages', 'JSON index'],
        },
    },
    {
        'slug': 'examples',
        'category': 'demos',
        'github': 'https://github.com/MaximeKELI/AFRILANG/tree/main/examples',
        'featured': True,
        'tags': ['examples', 'CI'],
        'playground_slug': 'hello',
        'fr': {
            'title': 'Exemples officiels',
            'summary': '60+ programmes .afr couvrant POO, async, GUI, pattern matching…',
            'highlights': ['hello → tier10', 'Tests CI', 'Playground en 1 clic'],
        },
        'en': {
            'title': 'Official examples',
            'summary': '60+ .afr programs covering OOP, async, GUI, pattern matching…',
            'highlights': ['hello → tier10', 'CI tests', 'One-click playground'],
        },
    },
    {
        'slug': 'gui-demo',
        'category': 'demos',
        'github': 'https://github.com/MaximeKELI/AFRILANG/blob/main/examples/gui_demo.afr',
        'featured': False,
        'tags': ['GUI', 'SDL2'],
        'playground_slug': 'gui-demo',
        'fr': {
            'title': 'Démo GUI (SDL2)',
            'summary': 'Interface graphique native via stdlib/ui et SDL2.',
            'highlights': ['Fenêtres', 'Boutons', 'Cross-platform'],
        },
        'en': {
            'title': 'GUI demo (SDL2)',
            'summary': 'Native GUI via stdlib/ui and SDL2.',
            'highlights': ['Windows', 'Buttons', 'Cross-platform'],
        },
    },
    {
        'slug': 'async-demo',
        'category': 'demos',
        'github': 'https://github.com/MaximeKELI/AFRILANG/blob/main/examples/async_demo.afr',
        'featured': False,
        'tags': ['async', 'await'],
        'playground_slug': 'async-demo',
        'fr': {
            'title': 'Async / await',
            'summary': 'Concurrence moderne avec async, await et tasks.',
            'highlights': ['Coroutines', 'Runtime intégré', 'Exemples async_full'],
        },
        'en': {
            'title': 'Async / await',
            'summary': 'Modern concurrency with async, await and tasks.',
            'highlights': ['Coroutines', 'Built-in runtime', 'async_full examples'],
        },
    },
    {
        'slug': 'stdlib',
        'category': 'official',
        'github': 'https://github.com/MaximeKELI/AFRILANG/tree/main/stdlib',
        'featured': False,
        'tags': ['stdlib', '7900 modules'],
        'fr': {
            'title': 'Bibliothèque standard',
            'summary': 'I/O, JSON, HTTP, crypto, NLP, finance, graphes et bien plus.',
            'highlights': ['import "std/…"', 'Modules documentés', 'Sync web'],
        },
        'en': {
            'title': 'Standard library',
            'summary': 'I/O, JSON, HTTP, crypto, NLP, finance, graphs and more.',
            'highlights': ['import "std/…"', 'Documented modules', 'Web sync'],
        },
    },
]


def get_categories(lang: str) -> list[dict]:
    code = (lang or 'fr')[:2]
    return [
        {'id': c['id'], 'label': c.get(code) or c['fr']}
        for c in CATEGORIES
    ]


def get_projects(lang: str) -> list[dict]:
    code = (lang or 'fr')[:2]
    out = []
    for p in PROJECTS:
        loc = p.get(code) or p['fr']
        out.append({
            'slug': p['slug'],
            'category': p['category'],
            'github': p['github'],
            'featured': p.get('featured', False),
            'tags': p.get('tags', []),
            'playground_slug': p.get('playground_slug', ''),
            'title': loc['title'],
            'summary': loc['summary'],
            'highlights': loc['highlights'],
        })
    return out


def grouped_projects(lang: str) -> list[dict]:
    cats = {c['id']: c['label'] for c in get_categories(lang)}
    groups = []
    for cat_id, label in cats.items():
        items = [p for p in get_projects(lang) if p['category'] == cat_id]
        if items:
            groups.append({'id': cat_id, 'label': label, 'projects': items})
    return groups
