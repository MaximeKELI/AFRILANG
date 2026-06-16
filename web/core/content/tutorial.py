"""Tutoriel interactif AFRILANG — 7 leçons FR/EN."""

LESSONS = [
    {
        'step': 1,
        'duration_min': 10,
        'playground_slug': 'hello',
        'doc_url': 'docs_syntax',
        'fr': {
            'title': 'Bonjour AFRILANG',
            'summary': 'Affichage, boucles simples et premier programme.',
            'objectives': [
                'Utiliser <code>say</code> pour afficher du texte',
                'Comprendre la structure d\'un programme .afr',
                'Écrire une boucle <code>repeat N times</code>',
            ],
            'content': [
                'AFRILANG se lit comme une phrase. Pas de point-virgule, pas d\'accolades — '
                'chaque bloc se termine par <code>end</code>.',
                'Commencez par le classique « Hello World », puis une petite boucle.',
            ],
            'challenge': 'Modifiez le programme pour afficher votre prénom 5 fois.',
        },
        'en': {
            'title': 'Hello AFRILANG',
            'summary': 'Output, simple loops and your first program.',
            'objectives': [
                'Use <code>say</code> to print text',
                'Understand the structure of a .afr program',
                'Write a <code>repeat N times</code> loop',
            ],
            'content': [
                'AFRILANG reads like a sentence. No semicolons, no braces — '
                'each block ends with <code>end</code>.',
                'Start with the classic Hello World, then a small loop.',
            ],
            'challenge': 'Change the program to print your name 5 times.',
        },
        'code': '''say "Bonjour depuis AFRILANG!"

repeat 3 times
    say "Hello"
end''',
    },
    {
        'step': 2,
        'duration_min': 15,
        'playground_slug': 'conditions',
        'doc_url': 'docs_syntax',
        'fr': {
            'title': 'Variables & conditions',
            'summary': 'Créer des variables et prendre des décisions.',
            'objectives': [
                'Déclarer avec <code>create</code> et modifier avec <code>set</code>',
                'Écrire <code>if … then … else … end</code> en langage naturel',
                'Comparer avec <code>is greater than</code>, <code>is equal to</code>',
            ],
            'content': [
                'Les conditions AFRILANG ressemblent à de l\'anglais parlé : '
                '<code>if age is greater than 18 then</code>.',
                'Les variables peuvent être inférées ou typées explicitement.',
            ],
            'challenge': 'Ajoutez une branche pour afficher « Mineur » si age &lt; 18.',
        },
        'en': {
            'title': 'Variables & conditionals',
            'summary': 'Create variables and make decisions.',
            'objectives': [
                'Declare with <code>create</code> and update with <code>set</code>',
                'Write <code>if … then … else … end</code> in natural language',
                'Compare with <code>is greater than</code>, <code>is equal to</code>',
            ],
            'content': [
                'AFRILANG conditions read like spoken English: '
                '<code>if age is greater than 18 then</code>.',
                'Variables can be inferred or explicitly typed.',
            ],
            'challenge': 'Add a branch to print "Minor" when age &lt; 18.',
        },
        'code': '''create age = 25

if age is greater than 18 then
    say "Adulte"
else
    say "Mineur"
end

create score = 100
if score is equal to 100 then
    say "Score parfait!"
end''',
    },
    {
        'step': 3,
        'duration_min': 20,
        'playground_slug': 'functions',
        'doc_url': 'docs_syntax',
        'fr': {
            'title': 'Fonctions & boucles',
            'summary': 'Réutiliser du code avec des fonctions.',
            'objectives': [
                'Déclarer <code>function … returns … end</code>',
                'Utiliser <code>while … do</code> et <code>for each … in</code>',
                'Retourner une valeur avec <code>return</code>',
            ],
            'content': [
                'Les fonctions encapsulent la logique. Le type de retour est optionnel '
                'mais recommandé pour la clarté.',
            ],
            'challenge': 'Écrivez une fonction <code>double(n)</code> qui retourne n × 2.',
        },
        'en': {
            'title': 'Functions & loops',
            'summary': 'Reuse code with functions.',
            'objectives': [
                'Declare <code>function … returns … end</code>',
                'Use <code>while … do</code> and <code>for each … in</code>',
                'Return a value with <code>return</code>',
            ],
            'content': [
                'Functions encapsulate logic. Return types are optional '
                'but recommended for clarity.',
            ],
            'challenge': 'Write a <code>double(n)</code> function that returns n × 2.',
        },
        'code': '''function greet(name text) returns text
    return "Hello, " + name
end

say greet("AFRILANG")

create nums = list of 1, 2, 3
for each n in nums do
    say n
end

create i = 0
while i is less than 3 do
    say "tick"
    set i = i + 1
end''',
    },
    {
        'step': 4,
        'duration_min': 20,
        'playground_slug': 'natural-list-ops',
        'doc_url': 'docs_functional',
        'fr': {
            'title': 'Listes & collections',
            'summary': 'map, filter, reduce en syntaxe naturelle.',
            'objectives': [
                'Créer <code>list of 1, 2, 3</code>',
                'Transformer avec <code>map each … do</code>',
                'Filtrer avec <code>filter each … where</code>',
            ],
            'content': [
                'Les listes sont au cœur d\'AFRILANG. Les opérations fonctionnelles '
                'se lisent comme des phrases — pas besoin d\'import pour les bases.',
            ],
            'challenge': 'Calculez la somme des nombres &gt; 3 avec <code>reduce</code>.',
        },
        'en': {
            'title': 'Lists & collections',
            'summary': 'map, filter, reduce in natural syntax.',
            'objectives': [
                'Create <code>list of 1, 2, 3</code>',
                'Transform with <code>map each … do</code>',
                'Filter with <code>filter each … where</code>',
            ],
            'content': [
                'Lists are central to AFRILANG. Functional operations '
                'read like sentences — no import needed for basics.',
            ],
            'challenge': 'Sum numbers &gt; 3 using <code>reduce</code>.',
        },
        'code': '''create nums = list of 1, 2, 3, 4, 5

create doubled = map each x in nums do
    return x * 2
end

create big = filter each x in nums where x is greater than 3

create total = reduce nums from 0 with each acc, x do
    return acc + x
end

say total''',
    },
    {
        'step': 5,
        'duration_min': 25,
        'playground_slug': 'oop',
        'doc_url': 'docs_oop',
        'fr': {
            'title': 'Programmation orientée objet',
            'summary': 'Classes, constructeurs et méthodes.',
            'objectives': [
                'Définir une <code>class … end</code>',
                'Instancier avec <code>new</code>',
                'Utiliser <code>init</code> comme constructeur',
            ],
            'content': [
                'La POO AFRILANG est explicite et lisible. Les champs peuvent être '
                '<code>public</code> ou <code>private</code>.',
            ],
            'challenge': 'Ajoutez une méthode <code>bark()</code> à la classe Dog.',
        },
        'en': {
            'title': 'Object-oriented programming',
            'summary': 'Classes, constructors and methods.',
            'objectives': [
                'Define a <code>class … end</code>',
                'Instantiate with <code>new</code>',
                'Use <code>init</code> as constructor',
            ],
            'content': [
                'AFRILANG OOP is explicit and readable. Fields can be '
                '<code>public</code> or <code>private</code>.',
            ],
            'challenge': 'Add a <code>bark()</code> method to the Dog class.',
        },
        'code': '''class Dog
    public field name text

    function init(n text)
        set this.name = n
    end

    function speak()
        say name + " says Woof!"
    end
end

create rex = new Dog("Rex")
rex.speak()''',
    },
    {
        'step': 6,
        'duration_min': 25,
        'playground_slug': 'unions-demo',
        'doc_url': 'docs_pattern',
        'fr': {
            'title': 'Pattern matching',
            'summary': 'Enums, unions et match exhaustif.',
            'objectives': [
                'Créer un <code>enum</code> ou <code>union</code> avec payload',
                'Matcher avec <code>case … with … then</code>',
                'Utiliser le match en expression',
            ],
            'content': [
                'Le pattern matching remplace les longues chaînes if/else. '
                'Le compilateur vérifie l\'exhaustivité des cas.',
            ],
            'challenge': 'Ajoutez un cas <code>Triangle</code> à l\'union Shape.',
        },
        'en': {
            'title': 'Pattern matching',
            'summary': 'Enums, unions and exhaustive match.',
            'objectives': [
                'Create an <code>enum</code> or <code>union</code> with payload',
                'Match with <code>case … with … then</code>',
                'Use match as expression',
            ],
            'content': [
                'Pattern matching replaces long if/else chains. '
                'The compiler checks case exhaustiveness.',
            ],
            'challenge': 'Add a <code>Triangle</code> case to the Shape union.',
        },
        'code': '''union Shape
    case Circle with radius number
    case Rect with w number, h number
end

create circle = Shape.Circle with 5

match circle
    case Circle with r then
        say "radius {r}"
    end
    case Rect with w, h then
        say "{w}x{h}"
    end
end''',
    },
    {
        'step': 7,
        'duration_min': 30,
        'playground_slug': 'async-demo',
        'doc_url': 'docs_getting_started',
        'fr': {
            'title': 'Projet final & prochaines étapes',
            'summary': 'Installer le compilateur et aller plus loin.',
            'objectives': [
                'Compiler et exécuter localement avec <code>afrilang run</code>',
                'Découvrir async, stdlib et les paquets',
                'Configurer l\'extension VS Code / Cursor',
            ],
            'content': [
                'Félicitations — vous maîtrisez les bases ! Installez le compilateur, '
                'explorez la stdlib (7900+ modules) et rejoignez la communauté.',
            ],
            'challenge': 'Créez un projet avec <code>afrilang init mon_app</code> et partagez-le sur GitHub.',
        },
        'en': {
            'title': 'Final project & next steps',
            'summary': 'Install the compiler and go further.',
            'objectives': [
                'Compile and run locally with <code>afrilang run</code>',
                'Explore async, stdlib and packages',
                'Set up the VS Code / Cursor extension',
            ],
            'content': [
                'Congratulations — you know the basics! Install the compiler, '
                'explore the stdlib (7900+ modules) and join the community.',
            ],
            'challenge': 'Create a project with <code>afrilang init my_app</code> and share it on GitHub.',
        },
        'code': '''say "Bravo — tutoriel terminé!"

say "Prochaines étapes:"
say "  1. afrilang run file.afr"
say "  2. Explorer /stdlib/"
say "  3. Lire /docs/async/"''',
    },
]


def get_lessons(lang: str) -> list[dict]:
    code = (lang or 'fr')[:2]
    out = []
    for lesson in LESSONS:
        loc = lesson.get(code) or lesson['fr']
        out.append({
            'step': lesson['step'],
            'duration_min': lesson['duration_min'],
            'playground_slug': lesson.get('playground_slug', ''),
            'doc_url': lesson.get('doc_url', 'docs_overview'),
            'title': loc['title'],
            'summary': loc['summary'],
            'objectives': loc['objectives'],
            'content': loc['content'],
            'challenge': loc['challenge'],
            'code': lesson['code'],
        })
    return out


def get_lesson(step: int, lang: str) -> dict | None:
    for lesson in get_lessons(lang):
        if lesson['step'] == step:
            return lesson
    return None


def total_steps() -> int:
    return len(LESSONS)
