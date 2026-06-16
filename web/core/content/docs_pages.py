"""Bilingual documentation page content (FR/EN)."""

from django.utils.safestring import mark_safe

from .docs_nav import NAV_LABELS


def _page(slug, title_fr, title_en, lead_fr, lead_en, blocks_fr, blocks_en):
    return {
        'fr': {'slug': slug, 'title': title_fr, 'lead': lead_fr, 'blocks': blocks_fr},
        'en': {'slug': slug, 'title': title_en, 'lead': lead_en, 'blocks': blocks_en},
    }


def h2(text):
    return {'type': 'h2', 'text': text}


def h3(text):
    return {'type': 'h3', 'text': text}


def p(html):
    return {'type': 'p', 'html': mark_safe(html)}


def code(text, header=None):
    return {'type': 'code', 'text': text.strip(), 'header': header}


def ul(items):
    return {'type': 'ul', 'items': items}


def callout(html, variant='info'):
    return {'type': 'callout', 'html': mark_safe(html), 'variant': variant}


def table(headers, rows):
    return {'type': 'table', 'headers': headers, 'rows': rows}


def nav_footer(prev_url, prev_label, next_url, next_label):
    return {'type': 'nav_footer', 'prev_url': prev_url, 'prev_label': prev_label,
            'next_url': next_url, 'next_label': next_label}


PAGES = {}

PAGES['overview'] = _page(
    'overview',
    'Documentation AFRILANG', 'AFRILANG Documentation',
    'Bienvenue dans la documentation officielle d\'AFRILANG 1.0. Ce guide couvre '
    'l\'installation, la syntaxe, les types, la POO, les fonctionnalités avancées, '
    'la bibliothèque standard et les outils.',
    'Welcome to the official AFRILANG 1.0 documentation. This guide covers '
    'installation, syntax, types, OOP, advanced features, the standard library and tooling.',
    [
        callout('<strong>Nouveau ?</strong> Commencez par le guide Premiers pas, puis la syntaxe de base et le playground.'),
        h2('Qu\'est-ce qu\'AFRILANG ?'),
        p('AFRILANG est un langage orienté objet à <strong>syntaxe naturelle</strong>. '
          'Le compilateur génère du C++17 et produit des exécutables natifs via <code>g++</code>.'),
        h2('Caractéristiques principales'),
        ul([
            '<strong>Syntaxe naturelle</strong> — conditions et boucles en mots-clés FR/EN',
            '<strong>Transpilation C++</strong> — performance native',
            '<strong>POO complète</strong> — classes, héritage, interfaces, génériques',
            '<strong>Pattern matching</strong> — <code>match</code> exhaustif sur enums/unions',
            '<strong>Async/await</strong> — coroutines C++20',
            '<strong>463+ modules stdlib</strong> — I/O, graphes, ML, finance, crypto',
            '<strong>Toolchain</strong> — CLI, LSP, REPL, formatter, debug, IDE extension',
        ]),
        h2('Spécification'),
        p('Spécification complète : <code>docs/LANGUAGE.md</code> dans le dépôt GitHub. '
          '60+ exemples testés en CI dans <code>examples/</code>.'),
    ],
    [
        callout('<strong>New here?</strong> Start with Getting started, then Basic syntax and the playground.'),
        h2('What is AFRILANG?'),
        p('AFRILANG is an object-oriented language with <strong>natural-language syntax</strong>. '
          'The compiler generates C++17 and produces native executables via <code>g++</code>.'),
        h2('Key features'),
        ul([
            '<strong>Natural syntax</strong> — FR/EN keywords for control flow',
            '<strong>C++ transpilation</strong> — native performance',
            '<strong>Full OOP</strong> — classes, inheritance, interfaces, generics',
            '<strong>Pattern matching</strong> — exhaustive <code>match</code> on enums/unions',
            '<strong>Async/await</strong> — C++20 coroutines',
            '<strong>463+ stdlib modules</strong> — I/O, graphs, ML, finance, crypto',
            '<strong>Toolchain</strong> — CLI, LSP, REPL, formatter, debug, IDE extension',
        ]),
        h2('Specification'),
        p('Full spec: <code>docs/LANGUAGE.md</code> on GitHub. 60+ CI-tested examples in <code>examples/</code>.'),
    ],
)

PAGES['getting-started'] = _page(
    'getting-started',
    'Premiers pas', 'Getting started',
    'Installez le compilateur, exécutez votre premier programme et découvrez la CLI.',
    'Install the compiler, run your first program and learn the CLI.',
    [
        h2('Prérequis'),
        ul(['Linux (Ubuntu/Debian) — macOS/Windows via toolchain compatible',
            'CMake ≥ 3.16, g++ C++17 (C++20 pour async)', 'Git']),
        h2('Installation'),
        code('''git clone https://github.com/MaximeKELI/AFRILANG.git
cd AFRILANG/build && cmake .. && cmake --build .
./afrilang --version
./afrilang run ../examples/hello.afr''', 'Terminal'),
        h2('Premier programme'),
        code('''say "Hello, AFRILANG!"
repeat 3 times
    say "Hello"
end'''),
        h2('Créer un projet'),
        code('''afrilang init mon_app
cd mon_app
afrilang build
afrilang run src/main.afr'''),
        h2('Commandes essentielles'),
        table(['Commande', 'Description'], [
            ['<code>afrilang run file.afr</code>', 'Compiler et exécuter'],
            ['<code>afrilang build</code>', 'Compiler le projet'],
            ['<code>afrilang test</code>', 'Lancer les tests'],
            ['<code>afrilang fmt -w file.afr</code>', 'Formater'],
            ['<code>afrilang lsp</code>', 'Language Server'],
            ['<code>afrilang pkg add math</code>', 'Ajouter un paquet'],
        ]),
    ],
    [
        h2('Requirements'),
        ul(['Linux (Ubuntu/Debian) — macOS/Windows with compatible toolchain',
            'CMake ≥ 3.16, g++ C++17 (C++20 for async)', 'Git']),
        h2('Installation'),
        code('''git clone https://github.com/MaximeKELI/AFRILANG.git
cd AFRILANG/build && cmake .. && cmake --build .
./afrilang --version
./afrilang run ../examples/hello.afr''', 'Terminal'),
        h2('First program'),
        code('''say "Hello, AFRILANG!"
repeat 3 times
    say "Hello"
end'''),
        h2('Create a project'),
        code('''afrilang init my_app
cd my_app
afrilang build
afrilang run src/main.afr'''),
        h2('Essential commands'),
        table(['Command', 'Description'], [
            ['<code>afrilang run file.afr</code>', 'Compile and run'],
            ['<code>afrilang build</code>', 'Build project'],
            ['<code>afrilang test</code>', 'Run tests'],
            ['<code>afrilang fmt -w file.afr</code>', 'Format code'],
            ['<code>afrilang lsp</code>', 'Language Server'],
            ['<code>afrilang pkg add math</code>', 'Add package'],
        ]),
    ],
)

PAGES['syntax'] = _page(
    'syntax', 'Syntaxe de base', 'Basic syntax',
    'Variables, E/S, conditions, boucles, listes, maps et fonctions.',
    'Variables, I/O, conditionals, loops, lists, maps and functions.',
    [
        h2('Affichage et entrée'),
        code('say "Hello"\nask "Name?" into name\nsay "Hi, {name}!"'),
        h2('Variables'),
        code('create x = 42\ncreate name text = "AFRILANG"\ncreate const MAX = 100\nset x = x + 1'),
        h2('Conditions'),
        code('if age is greater than 18 then\n    say "Adult"\nelse\n    say "Minor"\nend'),
        h2('Boucles'),
        code('repeat 5 times\n    say "tick"\nend\n\nwhile count is less than 10 do\n    set count = count + 1\nend\n\nfor each item in nums do\n    say item\nend'),
        h2('Listes'),
        code('create nums = list of 1, 2, 3\nsay nums at 0\nadd 4 to nums\ncreate doubled = map each n in nums with n * 2'),
        h2('Alias français'),
        table(['Anglais', 'Français'], [
            ['<code>say</code>', '<code>dire</code>'],
            ['<code>create</code>', '<code>creer</code>'],
            ['<code>if … then</code>', '<code>si … alors</code>'],
            ['<code>end</code>', '<code>fin</code>'],
            ['<code>function</code>', '<code>fonction</code>'],
        ]),
    ],
    [
        h2('Output and input'),
        code('say "Hello"\nask "Name?" into name\nsay "Hi, {name}!"'),
        h2('Variables'),
        code('create x = 42\ncreate name text = "AFRILANG"\ncreate const MAX = 100\nset x = x + 1'),
        h2('Conditionals'),
        code('if age is greater than 18 then\n    say "Adult"\nelse\n    say "Minor"\nend'),
        h2('Loops'),
        code('repeat 5 times\n    say "tick"\nend\n\nwhile count is less than 10 do\n    set count = count + 1\nend\n\nfor each item in nums do\n    say item\nend'),
        h2('Lists'),
        code('create nums = list of 1, 2, 3\nsay nums at 0\nadd 4 to nums\ncreate doubled = map each n in nums with n * 2'),
        h2('French aliases'),
        table(['English', 'French'], [
            ['<code>say</code>', '<code>dire</code>'],
            ['<code>create</code>', '<code>creer</code>'],
            ['<code>if … then</code>', '<code>si … alors</code>'],
            ['<code>end</code>', '<code>fin</code>'],
            ['<code>function</code>', '<code>fonction</code>'],
        ]),
    ],
)

PAGES['types'] = _page(
    'types', 'Système de types', 'Type system',
    'Types statiques, collections, optionnels et Result.',
    'Static types, collections, optionals and Result.',
    [
        h2('Types primitifs'),
        table(['Type', 'C++'], [
            ['<code>number</code>', '<code>double</code>'],
            ['<code>text</code>', '<code>std::string</code>'],
            ['<code>bool</code>', '<code>bool</code>'],
            ['<code>list of T</code>', '<code>std::vector&lt;T&gt;</code>'],
            ['<code>map K to V</code>', '<code>std::unordered_map</code>'],
        ]),
        h2('Optionnels'),
        code('create name text? = nothing\nif name is defined then\n    say name\nend'),
        h2('Result'),
        code('function parse(s text) returns number or error\n    return error "invalid"\nend'),
        h2('Génériques'),
        code('function identity<T>(x T) returns T\n    return x\nend\nsay identity(42)'),
    ],
    [
        h2('Primitive types'),
        table(['Type', 'C++'], [
            ['<code>number</code>', '<code>double</code>'],
            ['<code>text</code>', '<code>std::string</code>'],
            ['<code>bool</code>', '<code>bool</code>'],
            ['<code>list of T</code>', '<code>std::vector&lt;T&gt;</code>'],
            ['<code>map K to V</code>', '<code>std::unordered_map</code>'],
        ]),
        h2('Optionals'),
        code('create name text? = nothing\nif name is defined then\n    say name\nend'),
        h2('Result'),
        code('function parse(s text) returns number or error\n    return error "invalid"\nend'),
        h2('Generics'),
        code('function identity<T>(x T) returns T\n    return x\nend\nsay identity(42)'),
    ],
)

PAGES['oop'] = _page(
    'oop', 'Programmation orientée objet', 'Object-oriented programming',
    'Classes, héritage, encapsulation, interfaces et records.',
    'Classes, inheritance, encapsulation, interfaces and records.',
    [
        h2('Classes'),
        code('''class Dog
    public field name text
    function init(n text)
        set this.name = n
    end
    function speak()
        say name + " says Woof!"
    end
end
create rex = new Dog("Rex")
rex.speak()'''),
        h2('Héritage'),
        code('class Car extends Vehicle\n    function describe() returns text\n        return super.describe() + model\n    end\nend'),
        h2('Interfaces'),
        code('interface Speakable\n    function speak()\nend\nclass Robot implements Speakable\n    function speak()\n        say "Beep"\n    end\nend'),
        h2('Classes génériques'),
        code('class Box<T>\n    public field value T\nend\ncreate b = new Box<number>(42)'),
    ],
    [
        h2('Classes'),
        code('''class Dog
    public field name text
    function init(n text)
        set this.name = n
    end
    function speak()
        say name + " says Woof!"
    end
end
create rex = new Dog("Rex")
rex.speak()'''),
        h2('Inheritance'),
        code('class Car extends Vehicle\n    function describe() returns text\n        return super.describe() + model\n    end\nend'),
        h2('Interfaces'),
        code('interface Speakable\n    function speak()\nend\nclass Robot implements Speakable\n    function speak()\n        say "Beep"\n    end\nend'),
        h2('Generic classes'),
        code('class Box<T>\n    public field value T\nend\ncreate b = new Box<number>(42)'),
    ],
)

PAGES['advanced'] = _page(
    'advanced', 'Fonctionnalités avancées', 'Advanced features',
    'Génériques, match, async, exceptions, FFI, tests et GUI SDL2.',
    'Generics, match, async, exceptions, FFI, tests and SDL2 GUI.',
    [
        h2('Pattern matching'),
        code('''enum Status
    case Ok
    case Error with message text
end
match e
    case Error with msg then say msg
    end
    default say "ok"
end'''),
        h2('Async / await'),
        code('async function fetch() returns task text\n    await sleep(100)\n    return "done"\nend'),
        h2('FFI'),
        code('extern from "m" function sin(x number) returns number'),
        h2('Tests intégrés'),
        code('test "add works"\n    assert add(2, 3) is equal to 5\nend'),
    ],
    [
        h2('Pattern matching'),
        code('''enum Status
    case Ok
    case Error with message text
end
match e
    case Error with msg then say msg
    end
    default say "ok"
end'''),
        h2('Async / await'),
        code('async function fetch() returns task text\n    await sleep(100)\n    return "done"\nend'),
        h2('FFI'),
        code('extern from "m" function sin(x number) returns number'),
        h2('Built-in tests'),
        code('test "add works"\n    assert add(2, 3) is equal to 5\nend'),
    ],
)

PAGES['stdlib'] = _page(
    'stdlib', 'Bibliothèque standard', 'Standard library',
    '463+ modules : I/O, JSON, HTTP, collections, graphes, ML, finance, crypto.',
    '463+ modules: I/O, JSON, HTTP, collections, graphs, ML, finance, crypto.',
    [
        h2('Modules essentiels'),
        table(['Module', 'Import'], [
            ['I/O', '<code>import "std/io"</code>'],
            ['JSON', '<code>import "std/json"</code>'],
            ['HTTP', '<code>import "std/http"</code>'],
            ['Collections', '<code>import "std/collections"</code>'],
        ]),
        h2('Catalogue tiered'),
        ul([
            '<strong>151 simple</strong> — <code>import "std/name"</code>',
            '<strong>102 medium</strong> — <code>import "std/m/name"</code>',
            '<strong>210 complex</strong> — graphes, ML, crypto, finance, NLP',
        ]),
        h2('Exemple JSON'),
        code('import "std/io"\nimport "std/json"\ncreate raw = readFile("config.json")\ncreate doc = parse(raw)'),
    ],
    [
        h2('Core modules'),
        table(['Module', 'Import'], [
            ['I/O', '<code>import "std/io"</code>'],
            ['JSON', '<code>import "std/json"</code>'],
            ['HTTP', '<code>import "std/http"</code>'],
            ['Collections', '<code>import "std/collections"</code>'],
        ]),
        h2('Tiered catalog'),
        ul([
            '<strong>151 simple</strong> — <code>import "std/name"</code>',
            '<strong>102 medium</strong> — <code>import "std/m/name"</code>',
            '<strong>210 complex</strong> — graphs, ML, crypto, finance, NLP',
        ]),
        h2('JSON example'),
        code('import "std/io"\nimport "std/json"\ncreate raw = readFile("config.json")\ncreate doc = parse(raw)'),
    ],
)

PAGES['tooling'] = _page(
    'tooling', 'Outils et écosystème', 'Tooling & ecosystem',
    'CLI, LSP, REPL, paquets, debug, cross-compilation et playground.',
    'CLI, LSP, REPL, packages, debug, cross-compilation and playground.',
    [
        h2('CLI'),
        table(['Commande', 'Rôle'], [
            ['<code>afrilang build</code>', 'Compiler'],
            ['<code>afrilang lsp</code>', 'Language Server'],
            ['<code>afrilang repl</code>', 'REPL interactif'],
            ['<code>afrilang benchmark</code>', 'Benchmarks'],
        ]),
        h2('LSP 1.1'),
        ul(['Diagnostics, hover, go-to-definition', 'Complétion FR/EN', 'Symboles, code actions']),
        h2('Cross-compilation'),
        code('afrilang build --target linux-x64\nafrilang build --target wasm32'),
        h2('Variables d\'environnement'),
        table(['Variable', 'Effet'], [
            ['<code>AFRILANG_LOCALE=fr|en</code>', 'Langue des erreurs'],
            ['<code>AFRILANG_ROOT</code>', 'Racine du projet'],
        ]),
    ],
    [
        h2('CLI'),
        table(['Command', 'Role'], [
            ['<code>afrilang build</code>', 'Compile'],
            ['<code>afrilang lsp</code>', 'Language Server'],
            ['<code>afrilang repl</code>', 'Interactive REPL'],
            ['<code>afrilang benchmark</code>', 'Benchmarks'],
        ]),
        h2('LSP 1.1'),
        ul(['Diagnostics, hover, go-to-definition', 'FR/EN completion', 'Symbols, code actions']),
        h2('Cross-compilation'),
        code('afrilang build --target linux-x64\nafrilang build --target wasm32'),
        h2('Environment variables'),
        table(['Variable', 'Effect'], [
            ['<code>AFRILANG_LOCALE=fr|en</code>', 'Error message locale'],
            ['<code>AFRILANG_ROOT</code>', 'Project root path'],
        ]),
    ],
)

DOC_NAV_ORDER = []  # filled after full docs registration


def _build_nav_order():
    from .docs_nav import build_doc_nav_order
    return build_doc_nav_order()


def get_doc_page(slug, lang):
    code = (lang or 'fr')[:2]
    page = PAGES.get(slug, PAGES['overview'])
    data = page.get(code, page['fr'])
    return data


def get_doc_page_by_url_name(url_name, lang):
    slug_map = {name: slug for name, slug in DOC_NAV_ORDER}
    slug = slug_map.get(url_name, 'overview')
    page = get_doc_page(slug, lang)
    idx = next(i for i, (n, _) in enumerate(DOC_NAV_ORDER) if n == url_name)
    prev_item = DOC_NAV_ORDER[idx - 1] if idx > 0 else None
    next_item = DOC_NAV_ORDER[idx + 1] if idx < len(DOC_NAV_ORDER) - 1 else None
    code = (lang or 'fr')[:2]

    def label(item):
        if not item:
            return None
        _, s = item
        return NAV_LABELS[s].get(code, NAV_LABELS[s]['fr'])

    page['prev'] = {'url_name': prev_item[0], 'label': label(prev_item)} if prev_item else None
    page['next'] = {'url_name': next_item[0], 'label': label(next_item)} if next_item else None
    return page


from .docs_full import register_full_documentation

register_full_documentation(PAGES)
DOC_NAV_ORDER = _build_nav_order()
