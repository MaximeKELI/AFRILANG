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
     'fr_desc': 'Dés, collisions, physique ludique, moteurs 2D/3D.',
     'en_desc': 'Dice, collisions, game physics, 2D/3D engines.'},
    {'id': 'gis', 'fr': 'SIG & télédétection', 'en': 'GIS & remote sensing',
     'fr_desc': 'Géomatique, NDVI, rasters, tuiles — giskit*, gisultra*.',
     'en_desc': 'Geomatics, NDVI, rasters, tiles — giskit*, gisultra*.'},
    {'id': 'raster', 'fr': 'Traitement raster', 'en': 'Raster processing',
     'fr_desc': 'Filtres, Sobel, NDVI, lissage — rasterultra* (500 modules).',
     'en_desc': 'Filters, Sobel, NDVI, smoothing — rasterultra* (500 modules).'},
    {'id': 'segmentation', 'fr': 'Segmentation & morphologie', 'en': 'Segmentation & morphology',
     'fr_desc': 'Composantes connexes, flood fill, érosion — segultra*.',
     'en_desc': 'Connected components, flood fill, erosion — segultra*.'},
    {'id': 'datascience', 'fr': 'Data science', 'en': 'Data science',
     'fr_desc': 'Stats, séries, régression — dataultra*, datasci*.',
     'en_desc': 'Stats, time series, regression — dataultra*, datasci*.'},
    {'id': 'visualization', 'fr': 'Visualisation (fichiers)', 'en': 'Visualization (files)',
     'fr_desc': 'Export SVG/CSV — vizultra* (graphiques, heatmaps).',
     'en_desc': 'SVG/CSV export — vizultra* (charts, heatmaps).'},
    {'id': 'ai', 'fr': 'Intelligence artificielle', 'en': 'Artificial intelligence',
     'fr_desc': 'Activations, softmax, métriques ML — iaultra*.',
     'en_desc': 'Activations, softmax, ML metrics — iaultra*.'},
    {'id': 'database', 'fr': 'Bases de données', 'en': 'Databases',
     'fr_desc': 'SQLite, requêtes, export CSV — dbultra*.',
     'en_desc': 'SQLite, queries, CSV export — dbultra*.'},
    {'id': 'system', 'fr': 'Système', 'en': 'System',
     'fr_desc': 'CPU, disque, processus, environnement.',
     'en_desc': 'CPU, disk, processes, environment.'},
    {'id': 'medium', 'fr': 'Modules medium (m/)', 'en': 'Medium modules (m/)',
     'fr_desc': 'Bibliothèques intermédiaires — import std/m/…',
     'en_desc': 'Intermediate libraries — import std/m/…'},
    {'id': 'complex', 'fr': 'Modules complex (c/)', 'en': 'Complex modules (c/)',
     'fr_desc': 'Graphes, NLP, crypto avancé, réseaux, jeux pro.',
     'en_desc': 'Graphs, NLP, advanced crypto, networks, pro games.'},
    {'id': 'utilities', 'fr': 'Utilitaires', 'en': 'Utilities',
     'fr_desc': 'Helpers simples et fonctions ponctuelles.',
     'en_desc': 'Simple helpers and single-purpose functions.'},
]

# Paquets ultra générés (500 modules chacun sauf indication)
ULTRA_PACKS = [
    {'prefix': 'giskit', 'tier': 'simple', 'count': 500, 'category': 'gis',
     'fr': 'SIG simple (giskit001–500)', 'en': 'Simple GIS (giskit001–500)'},
    {'prefix': 'gisultra', 'tier': 'complex', 'count': 500, 'category': 'gis',
     'fr': 'SIG avancé (gisultra001–500)', 'en': 'Advanced GIS (gisultra001–500)'},
    {'prefix': 'rasterultra', 'tier': 'complex', 'count': 500, 'category': 'raster',
     'fr': 'Raster (rasterultra001–500)', 'en': 'Raster (rasterultra001–500)'},
    {'prefix': 'segultra', 'tier': 'complex', 'count': 500, 'category': 'segmentation',
     'fr': 'Segmentation (segultra001–500)', 'en': 'Segmentation (segultra001–500)'},
    {'prefix': 'dataultra', 'tier': 'complex', 'count': 500, 'category': 'datascience',
     'fr': 'Analyse de données (dataultra001–500)', 'en': 'Data analysis (dataultra001–500)'},
    {'prefix': 'datasci', 'tier': 'complex', 'count': 500, 'category': 'datascience',
     'fr': 'Data science (datasci001–500)', 'en': 'Data science (datasci001–500)'},
    {'prefix': 'vizultra', 'tier': 'complex', 'count': 500, 'category': 'visualization',
     'fr': 'Visualisation fichiers (vizultra001–500)', 'en': 'File visualization (vizultra001–500)'},
    {'prefix': 'iaultra', 'tier': 'complex', 'count': 500, 'category': 'ai',
     'fr': 'IA / ML (iaultra001–500)', 'en': 'AI / ML (iaultra001–500)'},
    {'prefix': 'dbultra', 'tier': 'complex', 'count': 500, 'category': 'database',
     'fr': 'Bases de données (dbultra001–500)', 'en': 'Databases (dbultra001–500)'},
    {'prefix': 'gameultra', 'tier': 'complex', 'count': 500, 'category': 'games',
     'fr': 'Jeux 2D (gameultra001–500)', 'en': '2D games (gameultra001–500)'},
    {'prefix': 'game3dultra', 'tier': 'complex', 'count': 500, 'category': 'games',
     'fr': 'Jeux 3D (game3dultra001–500)', 'en': '3D games (game3dultra001–500)'},
]

COMPLEX_PREFIX_CATEGORIES = [
    ('gisultra', 'gis'),
    ('rasterultra', 'raster'),
    ('segultra', 'segmentation'),
    ('dataultra', 'datascience'),
    ('datasci', 'datascience'),
    ('vizultra', 'visualization'),
    ('iaultra', 'ai'),
    ('dbultra', 'database'),
    ('gameultra', 'games'),
    ('game3dultra', 'games'),
    ('game3dpro', 'games'),
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
    'game2d', 'game3d',
})

GIS_KEYWORDS = frozenset({
    'giskit', 'gis', 'ndvi', 'raster', 'geo', 'tile', 'bbox', 'haversine',
    'hillshade', 'remote',
})

SYSTEM_KEYWORDS = frozenset({
    'cpu', 'disk', 'memory', 'process', 'env', 'os', 'file', 'fs', 'path',
    'cache', 'thread',
})


def _module_basename(name: str) -> str:
    return name.split('/')[-1].lower()


def infer_tier(name: str) -> str:
    if name.startswith('c/'):
        return 'complex'
    if name.startswith('m/'):
        return 'medium'
    return 'simple'


def infer_category(name: str) -> str:
    tier = infer_tier(name)
    base = _module_basename(name)
    low = name.lower()

    if tier == 'complex':
        for prefix, cat in COMPLEX_PREFIX_CATEGORIES:
            if base.startswith(prefix):
                return cat
        return 'complex'
    if tier == 'medium':
        return 'medium'

    if base in CORE_MODULES or name in CORE_MODULES:
        return 'core'
    for prefix, _cat in COMPLEX_PREFIX_CATEGORIES:
        if base.startswith(prefix):
            return _cat
    for kw in GIS_KEYWORDS:
        if kw in low:
            return 'gis'
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


def get_ultra_packs(lang: str) -> list[dict]:
    code = (lang or 'fr')[:2]
    return [
        {
            'prefix': p['prefix'],
            'tier': p['tier'],
            'count': p['count'],
            'category': p['category'],
            'label': p.get(code) or p['fr'],
            'import_example': (
                f'import "std/c/{p["prefix"]}001"'
                if p['tier'] == 'complex'
                else f'import "std/{p["prefix"]}001"'
            ),
        }
        for p in ULTRA_PACKS
    ]
