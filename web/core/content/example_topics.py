"""Catégories d'exemples pour la galerie."""

EXAMPLE_TOPICS = [
    {
        'id': 'games',
        'label_fr': 'Jeux',
        'label_en': 'Games',
        'slugs': ['snake'],
    },
    {
        'id': 'basics',
        'label_fr': 'Bases',
        'label_en': 'Basics',
        'slugs': [
            'hello', 'conditions', 'while', 'natural', 'functions', 'defaults',
            'fields', 'educational', 'language-demo',
        ],
    },
    {
        'id': 'collections',
        'label_fr': 'Collections',
        'label_en': 'Collections',
        'slugs': [
            'lists', 'list-ops', 'natural-list-ops', 'maps', 'polymorphic-list',
        ],
    },
    {
        'id': 'types',
        'label_fr': 'Types & génériques',
        'label_en': 'Types & generics',
        'slugs': ['generics', 'generic-class', 'result', 'records'],
    },
    {
        'id': 'oop',
        'label_fr': 'POO',
        'label_en': 'OOP',
        'slugs': [
            'oop', 'oop-full', 'inheritance', 'poo-demo', 'poo-advanced',
            'interfaces', 'operators-demo',
        ],
    },
    {
        'id': 'pattern',
        'label_fr': 'Pattern matching',
        'label_en': 'Pattern matching',
        'slugs': ['traits-demo', 'unions-demo', 'match-expr-demo'],
    },
    {
        'id': 'modules',
        'label_fr': 'Modules & paquets',
        'label_en': 'Modules & packages',
        'slugs': ['modules', 'pkg-demo', 'args-path-demo'],
    },
    {
        'id': 'async',
        'label_fr': 'Async',
        'label_en': 'Async',
        'slugs': ['async-demo', 'async-full'],
    },
    {
        'id': 'gui',
        'label_fr': 'Interface graphique',
        'label_en': 'GUI',
        'slugs': ['gui-demo'],
    },
    {
        'id': 'stdlib',
        'label_fr': 'Bibliothèque standard',
        'label_en': 'Standard library',
        'slugs': [
            'stdlib-demo', 'simple-libs-demo', 'medium-libs-demo',
            'complex-libs-demo', 'fs-demo',
        ],
    },
    {
        'id': 'advanced',
        'label_fr': 'Avancé & FFI',
        'label_en': 'Advanced & FFI',
        'slugs': ['ffi', 'exceptions', 'lambdas', 'advanced', 'full-demo'],
    },
    {
        'id': 'demos',
        'label_fr': 'Démos phase / tier',
        'label_en': 'Phase / tier demos',
        'slugs': [
            'tier1-demo', 'tier2-demo', 'tier3-demo', 'tier4-demo', 'tier5-demo',
            'tier6-demo', 'tier7-demo', 'tier8-demo', 'tier9-demo', 'tier10-demo',
            'phase9-demo', 'phase10-demo', 'phase11-demo',
        ],
    },
]


def grouped_examples(examples_qs, lang: str):
    """Retourne [(topic, [examples])] pour le template."""
    by_slug = {ex.slug: ex for ex in examples_qs}
    code = (lang or 'fr')[:2]
    groups = []
    seen = set()
    for topic in EXAMPLE_TOPICS:
        label = topic['label_en'] if code == 'en' else topic['label_fr']
        items = []
        for slug in topic['slugs']:
            ex = by_slug.get(slug)
            if ex:
                items.append(ex)
                seen.add(slug)
        if items:
            groups.append({'id': topic['id'], 'label': label, 'examples': items})
    other = [ex for ex in examples_qs if ex.slug not in seen]
    if other:
        label = 'Other' if code == 'en' else 'Autres'
        groups.append({'id': 'other', 'label': label, 'examples': list(other)})
    return groups
