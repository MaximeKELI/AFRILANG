"""Catégories et métadonnées des bibliothèques stdlib AFRILANG."""

CATEGORIES = [
    {'id': 'core', 'fr': 'Core & I/O', 'en': 'Core & I/O',
     'fr_desc': 'Entrées/sorties, fichiers, JSON, HTTP, collections, chemins.',
     'en_desc': 'I/O, files, JSON, HTTP, collections, paths.'},
    {'id': 'math', 'fr': 'Mathématiques', 'en': 'Mathematics',
     'fr_desc': 'Arithmétique, trigonométrie, statistiques, conversions.',
     'en_desc': 'Arithmetic, trigonometry, statistics, conversions.'},
    {'id': 'text', 'fr': 'Texte & chaînes', 'en': 'Text & strings',
     'fr_desc': 'Manipulation de texte, regex, formatage, parsing.',
     'en_desc': 'Text manipulation, regex, formatting, parsing.'},
    {'id': 'time', 'fr': 'Temps & dates', 'en': 'Time & dates',
     'fr_desc': 'Horloge, calendrier, délais, formatage temporel.',
     'en_desc': 'Clock, calendar, delays, time formatting.'},
    {'id': 'data', 'fr': 'Données & formats', 'en': 'Data & formats',
     'fr_desc': 'CSV, encodages, sérialisation, structures.',
     'en_desc': 'CSV, encodings, serialization, structures.'},
    {'id': 'crypto', 'fr': 'Crypto & sécurité', 'en': 'Crypto & security',
     'fr_desc': 'Hachage, checksum, audit, sécurité.',
     'en_desc': 'Hashing, checksum, audit, security.'},
    {'id': 'network', 'fr': 'Réseau', 'en': 'Networking',
     'fr_desc': 'HTTP, sockets, protocoles, DNS.',
     'en_desc': 'HTTP, sockets, protocols, DNS.'},
    {'id': 'finance', 'fr': 'Finance', 'en': 'Finance',
     'fr_desc': 'Monnaie, intérêts, budgets, marchés.',
     'en_desc': 'Currency, interest, budgets, markets.'},
    {'id': 'science', 'fr': 'Sciences', 'en': 'Science',
     'fr_desc': 'Physique, chimie, unités, conversions.',
     'en_desc': 'Physics, chemistry, units, conversions.'},
    {'id': 'ml', 'fr': 'ML & analyse', 'en': 'ML & analytics',
     'fr_desc': 'Machine learning, stats, prédictions.',
     'en_desc': 'Machine learning, stats, predictions.'},
    {'id': 'graphics', 'fr': 'Graphiques & UI', 'en': 'Graphics & UI',
     'fr_desc': 'Couleurs, SDL, fenêtres, dessin.',
     'en_desc': 'Colors, SDL, windows, drawing.'},
    {'id': 'games', 'fr': 'Jeux & simulation', 'en': 'Games & simulation',
     'fr_desc': 'Dés, collisions, physique ludique.',
     'en_desc': 'Dice, collisions, game physics.'},
    {'id': 'system', 'fr': 'Système', 'en': 'System',
     'fr_desc': 'CPU, disque, processus, environnement.',
     'en_desc': 'CPU, disk, processes, environment.'},
    {'id': 'medium', 'fr': 'Modules medium (m/)', 'en': 'Medium modules (m/)',
     'fr_desc': 'Bibliothèques intermédiaires — import std/m/…',
     'en_desc': 'Intermediate libraries — import std/m/…'},
    {'id': 'complex', 'fr': 'Modules complex (c/)', 'en': 'Complex modules (c/)',
     'fr_desc': 'Domaines avancés — graphes, NLP, réseaux complexes.',
     'en_desc': 'Advanced domains — graphs, NLP, complex networks.'},
    {'id': 'utilities', 'fr': 'Utilitaires', 'en': 'Utilities',
     'fr_desc': 'Helpers simples et fonctions ponctuelles.',
     'en_desc': 'Simple helpers and single-purpose functions.'},
]

CORE_MODULES = frozenset({
    'io', 'json', 'http', 'fs', 'path', 'str', 'collections', 'args', 'log',
    'async', 'ui', 'config', 're', 'math', 'time', 'binary', 'bytes',
})

MATH_KEYWORDS = frozenset({
    'absnum', 'sqrtlib', 'cbrtlib', 'min2', 'max2', 'clamp', 'lerp', 'sign',
    'parity', 'trig', 'trig2', 'avg', 'median', 'stats', 'percent', 'round',
    'floor', 'ceil', 'gcd', 'lcm', 'prime', 'fib', 'factorial', 'pow', 'log10',
    'exp', 'sin', 'cos', 'tan', 'matrix', 'vector', 'angle', 'arc', 'circle',
})

TEXT_KEYWORDS = frozenset({
    'str', 'string', 'text', 'char', 'concat', 'split', 'trim', 'capitalize',
    'upper', 'lower', 'replace', 'regex', 're', 'parse', 'format', 'template',
})

TIME_KEYWORDS = frozenset({
    'time', 'date', 'calendar', 'clock', 'timer', 'sleep', 'delay', 'duration',
    'week', 'month', 'year', 'hour', 'minute', 'second',
})

DATA_KEYWORDS = frozenset({
    'csv', 'json', 'xml', 'yaml', 'encode', 'decode', 'base64', 'binary',
    'serialize', 'parse', 'utf', 'ascii', 'hex',
})

CRYPTO_KEYWORDS = frozenset({
    'hash', 'crypto', 'checksum', 'sha', 'md5', 'hmac', 'audit', 'secure',
    'password', 'salt', 'token',
})

NETWORK_KEYWORDS = frozenset({
    'http', 'url', 'socket', 'tcp', 'udp', 'dns', 'ip', 'net', 'web', 'api',
    'rest', 'fetch',
})

FINANCE_KEYWORDS = frozenset({
    'finance', 'currency', 'money', 'coin', 'budget', 'tax', 'interest',
    'loan', 'stock', 'market', 'price', 'discount', 'invoice',
})

SCIENCE_KEYWORDS = frozenset({
    'chemistry', 'physics', 'mol', 'atom', 'unit', 'celsius', 'fahrenheit',
    'kelvin', 'gravity', 'energy', 'force', 'mass', 'volume', 'density',
})

ML_KEYWORDS = frozenset({
    'ml', 'learn', 'train', 'model', 'predict', 'cluster', 'neural', 'regress',
    'classify', 'dataset', 'feature',
})

GRAPHICS_KEYWORDS = frozenset({
    'ui', 'color', 'draw', 'sdl', 'window', 'pixel', 'image', 'canvas', 'font',
    'graphics', 'render',
})

GAMES_KEYWORDS = frozenset({
    'game', 'dice', 'collision', 'sprite', 'player', 'score', 'level', 'board',
})

SYSTEM_KEYWORDS = frozenset({
    'cpu', 'disk', 'memory', 'process', 'env', 'os', 'file', 'fs', 'path',
    'cache', 'thread',
})


def infer_tier(name: str) -> str:
    if name.startswith('c/'):
        return 'complex'
    if name.startswith('m/'):
        return 'medium'
    return 'simple'


def infer_category(name: str) -> str:
    tier = infer_tier(name)
    if tier == 'complex':
        return 'complex'
    if tier == 'medium':
        return 'medium'

    base = name.split('/')[0].lower()
    low = name.lower()

    if base in CORE_MODULES or name in CORE_MODULES:
        return 'core'
    for kw in MATH_KEYWORDS:
        if kw in low:
            return 'math'
    for kw in TEXT_KEYWORDS:
        if kw in low:
            return 'text'
    for kw in TIME_KEYWORDS:
        if kw in low:
            return 'time'
    for kw in DATA_KEYWORDS:
        if kw in low:
            return 'data'
    for kw in CRYPTO_KEYWORDS:
        if kw in low:
            return 'crypto'
    for kw in NETWORK_KEYWORDS:
        if kw in low:
            return 'network'
    for kw in FINANCE_KEYWORDS:
        if kw in low:
            return 'finance'
    for kw in SCIENCE_KEYWORDS:
        if kw in low:
            return 'science'
    for kw in ML_KEYWORDS:
        if kw in low:
            return 'ml'
    for kw in GRAPHICS_KEYWORDS:
        if kw in low:
            return 'graphics'
    for kw in GAMES_KEYWORDS:
        if kw in low:
            return 'games'
    for kw in SYSTEM_KEYWORDS:
        if kw in low:
            return 'system'
    return 'utilities'


def get_categories(lang: str) -> list[dict]:
    code = (lang or 'fr')[:2]
    return [
        {
            'id': c['id'],
            'label': c.get(code) or c['fr'],
            'description': c.get(f'{code}_desc') or c['fr_desc'],
        }
        for c in CATEGORIES
    ]


def category_by_id(cat_id: str, lang: str) -> dict | None:
    for c in get_categories(lang):
        if c['id'] == cat_id:
            return c
    return None
