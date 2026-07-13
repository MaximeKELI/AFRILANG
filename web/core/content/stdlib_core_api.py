"""Catalogue stdlib core pour le site — API réelle + prose FR/EN.

Les stubs `stdlib/*.afr` sont souvent vides ou absents pour le core injecté
via `stdlib_registry.cpp`. Ce module fournit la matière des pages détail.
"""
from __future__ import annotations

import re
from functools import lru_cache
from pathlib import Path

from django.conf import settings

# Noms canoniques (miroir sync_stdlib / isLegacyStdlibModule)
CORE_MODULE_NAMES = frozenset({
    'io', 'json', 'fs', 'http', 'str', 'logging', 'log', 'math', 'chrono', 'time',
    're', 'collections', 'args', 'path', 'sql', 'web', 'orm', 'thread', 'bigint',
    'crypto', 'yaml', 'datetime', 'env', 'tempfile', 'base64', 'url', 'random',
    'hex', 'csv', 'html', 'cli', 'email', 'uuid', 'async', 'ui', 'game2d',
    'game3d', 'gamestate', 'gamenet',
})

# Alias -> module injecté dans le registry C++
_REGISTRY_ALIASES = {
    'log': 'logging',
    'time': 'chrono',
}

# Module registry inject name -> site module name(s)
_INJECT_TO_SITE = {
    'logging': ['logging', 'log'],
    'chrono': ['chrono', 'time'],
}

WASM_OK = frozenset({
    'str', 'math', 'json', 'collections', 'path', 'log', 'logging', 'async',
    'args', 'env', 'base64', 'hex', 'uuid', 'url', 'html', 'csv',
})
NATIVE_ONLY = frozenset({
    'fs', 'io', 'http', 'ui', 'game2d', 'game3d', 'gamestate', 'gamenet',
    'thread', 'sql', 'orm', 'web',
})

# Prose + exemples pour les modules prioritaires (Vague 3+)
_PROSE: dict[str, dict] = {
    'str': {
        'domain_fr': 'Chaînes de caractères',
        'domain_en': 'Text strings',
        'summary_fr': 'Manipulation de texte UTF-8 : trim, recherche, remplacement, découpe.',
        'summary_en': 'UTF-8 text helpers: trim, search, replace, split/join.',
        'body_fr': (
            'Le module `str` est le cœur texte de la stdlib core. '
            'Il s’appuie sur un runtime C++ réel (`runtime/str.hpp`) et est couvert '
            'par `tests/stdlib/str.afr`.'
        ),
        'body_en': (
            'The `str` module is the core text toolkit. '
            'It uses a real C++ backend (`runtime/str.hpp`) and is covered by '
            '`tests/stdlib/str.afr`.'
        ),
        'example': (
            'import "std/str"\n'
            'use str\n\n'
            'create t = trim("  hello  ")\n'
            'say t\n'
            'if contains("afrilang", "lang") then\n'
            '    say "ok"\n'
            'end\n'
            'create parts = split("a,b,c", ",")\n'
            'say join(parts, "-")'
        ),
        'roles': {
            'trim': {'fr': 'Enlève espaces / tabs / newlines', 'en': 'Strip whitespace'},
            'contains': {'fr': 'Teste une sous-chaîne', 'en': 'Substring test'},
            'replace': {'fr': 'Remplacement global', 'en': 'Global replace'},
            'split': {'fr': 'Découpe en liste', 'en': 'Split into list'},
            'join': {'fr': 'Jointure de liste', 'en': 'Join list'},
        },
    },
    'math': {
        'domain_fr': 'Mathématiques',
        'domain_en': 'Mathematics',
        'summary_fr': 'Fonctions numériques de base : abs, floor, ceil, pow, random.',
        'summary_en': 'Basic numeric helpers: abs, floor, ceil, pow, random.',
        'body_fr': (
            'Module numérique core (`runtime/math.hpp`). '
            '`random()` renvoie un flottant dans `[0, 1)`. '
            'Tests : `tests/stdlib/math.afr`.'
        ),
        'body_en': (
            'Core numeric module (`runtime/math.hpp`). '
            '`random()` returns a float in `[0, 1)`. '
            'Tests: `tests/stdlib/math.afr`.'
        ),
        'example': (
            'import "std/math"\n'
            'use math\n\n'
            'say abs(0 - 4)\n'
            'say floor(3.9)\n'
            'say ceil(3.1)\n'
            'say pow(2, 10)\n'
            'say random()'
        ),
        'roles': {
            'abs': {'fr': 'Valeur absolue', 'en': 'Absolute value'},
            'floor': {'fr': 'Entier inférieur', 'en': 'Floor'},
            'ceil': {'fr': 'Entier supérieur', 'en': 'Ceil'},
            'pow': {'fr': 'Puissance', 'en': 'Power'},
            'random': {'fr': 'Aléatoire [0, 1)', 'en': 'Random in [0, 1)'},
        },
    },
    'json': {
        'domain_fr': 'JSON',
        'domain_en': 'JSON',
        'summary_fr': 'Parse, stringify et accès typé aux documents JSON.',
        'summary_en': 'Parse, stringify and typed access to JSON documents.',
        'body_fr': (
            'Backend réel dans `runtime/`. Idéal pour configs et APIs. '
            'Compatible WASM. Tests : `tests/stdlib/json.afr`.'
        ),
        'body_en': (
            'Real runtime backend. Ideal for configs and APIs. '
            'WASM-compatible. Tests: `tests/stdlib/json.afr`.'
        ),
        'example': (
            'import "std/json"\n'
            'use json\n\n'
            'create doc = makeObject("name", "AFRILANG")\n'
            'say stringify(doc)\n'
            'create parsed = parse("{\\"n\\": 1}")\n'
            'say getNumber(parsed, "n")'
        ),
        'roles': {
            'parse': {'fr': 'Parse une chaîne JSON', 'en': 'Parse JSON text'},
            'stringify': {'fr': 'Sérialise en texte', 'en': 'Serialize to text'},
            'getString': {'fr': 'Lit une clé texte', 'en': 'Read string key'},
            'getNumber': {'fr': 'Lit une clé nombre', 'en': 'Read number key'},
            'getInt': {'fr': 'Lit une clé entier', 'en': 'Read int key'},
            'makeObject': {'fr': 'Crée un objet simple', 'en': 'Build a simple object'},
        },
    },
    'io': {
        'domain_fr': 'Entrées / sorties',
        'domain_en': 'Input / output',
        'summary_fr': 'Lecture / écriture de fichiers et ligne stdin.',
        'summary_en': 'File read/write and stdin line input.',
        'body_fr': (
            'I/O synchrone et `readFileAsync` pour l’async. '
            'Cible native pour les fichiers ; le playground web a des limites.'
        ),
        'body_en': (
            'Sync I/O plus `readFileAsync`. '
            'Native target for files; web playground is limited.'
        ),
        'example': (
            'import "std/io"\n'
            'use io\n\n'
            'if fileExists("notes.txt") then\n'
            '    say readFile("notes.txt")\n'
            'end\n'
            'writeFile("out.txt", "hello")'
        ),
        'roles': {
            'readFile': {'fr': 'Lit un fichier entier', 'en': 'Read whole file'},
            'writeFile': {'fr': 'Écrit un fichier', 'en': 'Write a file'},
            'fileExists': {'fr': 'Teste l’existence', 'en': 'Existence check'},
            'readLine': {'fr': 'Lit une ligne stdin', 'en': 'Read stdin line'},
            'readFileAsync': {'fr': 'Lecture async', 'en': 'Async read'},
        },
    },
    'fs': {
        'domain_fr': 'Système de fichiers',
        'domain_en': 'Filesystem',
        'summary_fr': 'Lister, créer des dossiers, taille et suppression.',
        'summary_en': 'List dirs, mkdir, size and delete.',
        'body_fr': 'Complète `io` pour la navigation du disque. Natif uniquement.',
        'body_en': 'Complements `io` for disk navigation. Native only.',
        'example': (
            'import "std/fs"\n'
            'use fs\n\n'
            'create files = listDir(".")\n'
            'say makeDir("tmp_out")'
        ),
        'roles': {},
    },
    'http': {
        'domain_fr': 'HTTP',
        'domain_en': 'HTTP',
        'summary_fr': 'Requêtes HTTP GET/POST synchrones et async.',
        'summary_en': 'Sync and async HTTP GET/POST.',
        'body_fr': 'Réseau bloquant / async. Natif (pas dans le playground JS).',
        'body_en': 'Blocking / async networking. Native (not in JS playground).',
        'example': (
            'import "std/http"\n'
            'use http\n\n'
            'create body = httpGet("https://example.com")\n'
            'say body'
        ),
        'roles': {},
    },
    'collections': {
        'domain_fr': 'Collections',
        'domain_en': 'Collections',
        'summary_fr': 'Tri, filtre, map, reduce sur listes number/text.',
        'summary_en': 'Sort, filter, map, reduce on number/text lists.',
        'body_fr': 'Helpers fonctionnels core. Compatible WASM. Tests stdlib.',
        'body_en': 'Core functional helpers. WASM-compatible. Stdlib tests.',
        'example': (
            'import "std/collections"\n'
            'use collections\n\n'
            'create nums = list of 3, 1, 2\n'
            'say sortNumbers(nums)\n'
            'say sumNumbers(nums)'
        ),
        'roles': {},
    },
    'async': {
        'domain_fr': 'Async / coroutines',
        'domain_en': 'Async / coroutines',
        'summary_fr': 'Temporisation non bloquante via `sleep`.',
        'summary_en': 'Non-blocking delay via `sleep`.',
        'body_fr': 'C++20 coroutines. Sous-ensemble WASM (Emscripten).',
        'body_en': 'C++20 coroutines. WASM subset (Emscripten).',
        'example': (
            'import "std/async"\n'
            'use async\n\n'
            'async function waitThenSay() returns number or error\n'
            '    await sleep(100)\n'
            '    return 1\n'
            'end'
        ),
        'roles': {
            'sleep': {'fr': 'Attendre N ms', 'en': 'Wait N ms'},
        },
    },
    'path': {
        'domain_fr': 'Chemins',
        'domain_en': 'Paths',
        'summary_fr': 'Joindre et analyser des chemins de fichiers.',
        'summary_en': 'Join and inspect filesystem paths.',
        'body_fr': 'Utilitaire portable. Compatible WASM pour la logique pure.',
        'body_en': 'Portable helpers. WASM-ok for pure path logic.',
        'example': (
            'import "std/path"\n'
            'use path\n\n'
            'say join("src", "main.afr")\n'
            'say basename("/tmp/a.afr")\n'
            'say extension("main.afr")'
        ),
        'roles': {},
    },
    'args': {
        'domain_fr': 'Arguments CLI',
        'domain_en': 'CLI arguments',
        'summary_fr': 'Accès aux arguments du programme.',
        'summary_en': 'Access program arguments.',
        'body_fr': 'Utile pour les outils en ligne de commande.',
        'body_en': 'Useful for command-line tools.',
        'example': (
            'import "std/args"\n'
            'use args\n\n'
            'say count()\n'
            'if count() is greater than 0 then\n'
            '    say at(0)\n'
            'end'
        ),
        'roles': {},
    },
    'ui': {
        'domain_fr': 'Interface graphique',
        'domain_en': 'Graphical UI',
        'summary_fr': 'Fenêtres SDL2, dessin 2D, clavier / souris.',
        'summary_en': 'SDL2 windows, 2D drawing, keyboard / mouse.',
        'body_fr': 'Natif uniquement (libsdl2-dev). Boucle d’événements classique.',
        'body_en': 'Native only (libsdl2-dev). Classic event loop.',
        'example': (
            'import "std/ui"\n'
            'use ui\n\n'
            'openWindow("Demo", 640, 480)\n'
            'while isOpen() do\n'
            '    beginFrame()\n'
            '    clearBackground(20, 24, 40)\n'
            '    showFrame()\n'
            'end\n'
            'closeWindow()'
        ),
        'roles': {},
    },
    'log': {
        'domain_fr': 'Journalisation',
        'domain_en': 'Logging',
        'summary_fr': 'Messages info / warn / error.',
        'summary_en': 'Info / warn / error messages.',
        'body_fr': 'Alias pratique de `logging`.',
        'body_en': 'Convenient alias of `logging`.',
        'example': (
            'import "std/log"\n'
            'use log\n\n'
            'info("démarrage")\n'
            'warn("attention")\n'
            'error("échec")'
        ),
        'roles': {},
    },
    'logging': {
        'domain_fr': 'Journalisation',
        'domain_en': 'Logging',
        'summary_fr': 'Messages info / warn / error.',
        'summary_en': 'Info / warn / error messages.',
        'body_fr': 'Backend log core.',
        'body_en': 'Core logging backend.',
        'example': (
            'import "std/logging"\n'
            'use logging\n\n'
            'info("hello")'
        ),
        'roles': {},
    },
    'env': {
        'domain_fr': 'Environnement',
        'domain_en': 'Environment',
        'summary_fr': 'Variables d’environnement du processus.',
        'summary_en': 'Process environment variables.',
        'body_fr': 'Lire et utiliser la config machine / CI.',
        'body_en': 'Read machine / CI configuration.',
        'example': 'import "std/env"\nuse env',
        'roles': {},
    },
}


def _normalize_name(name: str) -> str:
    return name.split('/')[-1]


@lru_cache(maxsize=1)
def parse_registry_functions() -> dict[str, list[dict]]:
    """Extrait les signatures depuis stdlib_registry.cpp (makeStubFunction)."""
    path = Path(settings.AFRILANG_ROOT) / 'src' / 'utils' / 'stdlib_registry.cpp'
    if not path.is_file():
        return {}
    text = path.read_text(encoding='utf-8', errors='replace')
    modules: dict[str, list[dict]] = {}
    block_re = re.compile(
        r'void StdlibRegistry::inject\w+Module\(ProgramNode& program\)\s*\{(.*?)'
        r'injectModule\(program,\s*"([^"]+)"',
        re.DOTALL,
    )
    # Params = {} ou {{"a","t"}, ...} (un niveau d’imbrication)
    fn_re = re.compile(
        r'makeStubFunction\(\s*"([^"]+)"\s*,\s*'
        r'(\{(?:[^{}]|\{[^{}]*\})*\})\s*,\s*"([^"]*)"',
        re.DOTALL,
    )
    param_re = re.compile(r'\{\s*"([^"]+)"\s*,\s*"([^"]+)"\s*\}')

    for block, mod_name in block_re.findall(text):
        fns = []
        for name, params_blob, ret in fn_re.findall(block):
            params = [f'{a} {t}' for a, t in param_re.findall(params_blob)]
            fns.append({
                'name': name,
                'params': params,
                'returns': ret or 'void',
            })
        modules[mod_name] = fns
        for alias in _INJECT_TO_SITE.get(mod_name, []):
            modules[alias] = fns
    return modules


def get_prose(name: str) -> dict | None:
    base = _normalize_name(name)
    if base in _PROSE:
        return _PROSE[base]
    # fallback léger pour tout core
    if base in CORE_MODULE_NAMES:
        return {
            'domain_fr': base,
            'domain_en': base,
            'summary_fr': f'Module stdlib core `{base}` (runtime AFRILANG).',
            'summary_en': f'Core stdlib module `{base}` (AFRILANG runtime).',
            'body_fr': (
                f'Import : `import "std/{base}"` puis `use {base}`. '
                'API injectée par le compilateur (voir `stdlib_registry.cpp`).'
            ),
            'body_en': (
                f'Import: `import "std/{base}"` then `use {base}`. '
                'API injected by the compiler (see `stdlib_registry.cpp`).'
            ),
            'example': f'import "std/{base}"\nuse {base}',
            'roles': {},
        }
    return None


def get_core_functions(name: str) -> list[dict]:
    base = _normalize_name(name)
    reg_key = _REGISTRY_ALIASES.get(base, base)
    registry = parse_registry_functions()
    return list(registry.get(reg_key) or registry.get(base) or [])


def enrich_functions_with_roles(name: str, functions: list[dict], lang: str = 'fr') -> list[dict]:
    prose = get_prose(name) or {}
    roles = prose.get('roles') or {}
    is_en = (lang or 'fr')[:2] == 'en'
    out = []
    for fn in functions:
        role = roles.get(fn['name'], {})
        desc = role.get('en' if is_en else 'fr') or role.get('fr') or role.get('en') or ''
        item = dict(fn)
        item['description'] = desc
        out.append(item)
    return out


def wasm_note(name: str, lang: str = 'fr') -> str:
    base = _normalize_name(name)
    is_en = (lang or 'fr')[:2] == 'en'
    if base in WASM_OK:
        return (
            'Compatible cible wasm32 (sous-ensemble documenté).'
            if not is_en else
            'Compatible with wasm32 target (documented subset).'
        )
    if base in NATIVE_ONLY:
        return (
            'Natif uniquement (pas de playground navigateur / wasm simple).'
            if not is_en else
            'Native only (no simple browser playground / wasm).'
        )
    return (
        'Vérifiez la page WASM pour la compatibilité exacte.'
        if not is_en else
        'Check the WASM page for exact compatibility.'
    )


def related_links(name: str) -> dict:
    base = _normalize_name(name)
    root = Path(settings.AFRILANG_ROOT)
    links = {
        'test_path': None,
        'runtime_hint': None,
        'docs_api': True,
    }
    test = root / 'tests' / 'stdlib' / f'{base}.afr'
    if test.is_file():
        links['test_path'] = f'tests/stdlib/{base}.afr'
    # runtime often matches name
    for candidate in (base, 'str' if base == 'str' else base):
        hp = root / 'runtime' / f'{candidate}.hpp'
        if hp.is_file():
            links['runtime_hint'] = f'runtime/{candidate}.hpp'
            break
    return links


def is_core_module_name(name: str) -> bool:
    return _normalize_name(name) in CORE_MODULE_NAMES
