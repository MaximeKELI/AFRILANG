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
            '<strong>7900+ modules stdlib</strong> — I/O, SIG, data science, IA, SQLite, jeux, ML',
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
            '<strong>7900+ stdlib modules</strong> — I/O, GIS, data science, AI, SQLite, games, ML',
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
    'Classes, constructeurs, héritage, interfaces, records — avec le pourquoi de chaque concept.',
    'Classes, constructors, inheritance, interfaces, records — with the why behind each concept.',
    [
        callout(
            '<strong>En une phrase</strong> — Une classe regroupe des données (champs) et '
            'des comportements (méthodes). On crée des instances avec <code>new</code>.'
        ),
        h2('1. Classes et constructeur'),
        p(
            'Déclarez une <code>class</code>, des <code>field</code> '
            '(souvent <code>public</code> ou <code>private</code>), et des méthodes '
            '<code>function</code>. Le constructeur s’appelle <code>init</code> : '
            'il s’exécute quand vous faites <code>new Classe(…)</code>. '
            'À l’intérieur, <code>this</code> désigne l’instance courante.'
        ),
        p(
            'Dans l’exemple ci-dessous : chaque <code>Dog</code> a un <code>name</code>. '
            'À la création, <code>init</code> range le nom. '
            '<code>speak</code> utilise ce nom pour afficher un message. '
            'Puis on crée <code>rex</code> et on appelle <code>rex.speak()</code>.'
        ),
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
        p(
            '<strong>Lecture</strong> — <code>public field name text</code> déclare un champ '
            'accessible depuis l’extérieur. <code>set this.name = n</code> assigne le '
            'paramètre du constructeur. Sans <code>end</code>, le parseur ne sait pas '
            'où s’arrête la classe ou la méthode.'
        ),
        h2('2. Héritage'),
        p(
            '<code>extends</code> crée une spécialisation : la classe fille réutilise '
            'ou redéfinit le comportement du parent. '
            '<code>super</code> appelle explicitement la version parente '
            '(utile pour enrichir un message ou une description).'
        ),
        code('''class Vehicle
    function describe() returns text
        return "Vehicle "
    end
end

class Car extends Vehicle
    public field model text

    function describe() returns text
        return super.describe() + model
    end
end'''),
        p(
            '<strong>Lecture</strong> — <code>Car</code> hérite de <code>Vehicle</code>. '
            'En redéfinissant <code>describe</code>, on compose le texte parent via '
            '<code>super.describe()</code> puis on ajoute <code>model</code>. '
            'Le type de retour <code>returns text</code> doit rester compatible.'
        ),
        h2('3. Interfaces'),
        p(
            'Une <code>interface</code> décrit un contrat (« qui sait parler ») '
            'sans fournir le corps des méthodes. '
            'Une classe <code>implements</code> l’interface et doit fournir '
            'chaque méthode. Cela permet de traiter différents objets '
            'de façon uniforme tant qu’ils respectent le contrat.'
        ),
        code('''interface Speakable
    function speak()
end

class Robot implements Speakable
    function speak()
        say "Beep"
    end
end

create pet Speakable = new Robot()
pet.speak()'''),
        p(
            '<strong>Lecture</strong> — <code>Speakable</code> n’a pas d’implémentation. '
            '<code>Robot</code> doit définir <code>speak</code>. '
            'La variable <code>pet</code> est typée par l’interface : on peut y mettre '
            'n’importe quel objet qui implémente <code>Speakable</code>.'
        ),
        h2('4. Classes génériques et records'),
        p(
            'Comme pour les fonctions, une classe peut être paramétrée '
            '(<code>Box&lt;T&gt;</code>). '
            'Les <strong>records</strong> conviennent quand vous n’avez besoin '
            'que de champs groupés, sans hiérarchie complexe.'
        ),
        code('''class Box<T>
    public field value T

    function init(v T)
        set this.value = v
    end
end

create b = new Box<number>(42)
say b.value

record Point
    field x number
    field y number
end

create p = Point with x 3, y 4
say p.x'''),
        p(
            '<strong>Lecture</strong> — <code>Box&lt;number&gt;</code> fixe T = number. '
            '<code>Point with x 3, y 4</code> construit un record en nommant les champs. '
            'Pas besoin de <code>new</code> pour un record.'
        ),
        h2('5. Mots-clés POO utiles'),
        ul([
            '<code>static field</code> / <code>static function</code> — partagés par la classe',
            '<code>abstract class</code> / <code>abstract function</code> — non instanciable / à redéfinir',
            '<code>final class</code> / <code>final function</code> — non extensible / non redéfinissable',
            '<code>property</code> — getter/setter auto',
            '<code>destroy … end</code> — destructeur',
            '<code>protected field</code> — visible dans la hiérarchie',
        ]),
        h2('6. Surcharge d’opérateurs'),
        p(
            'Dans une classe, déclarez <code>operator +</code>, <code>-</code>, '
            '<code>*</code>, <code>/</code>, <code>==</code>, <code>!=</code>, '
            '<code>&lt;</code>, <code>&gt;</code> pour définir le comportement '
            'des opérateurs sur vos types.'
        ),
        code('''class Vector
    public field x number
    public field y number

    function init(ax number, ay number)
        set this.x = ax
        set this.y = ay
    end

    operator + (other Vector) returns Vector
        return new Vector(x + other.x, y + other.y)
    end
end

create a = new Vector(1, 2)
create b = new Vector(3, 4)
create c = a + b
say c.x'''),
        p(
            '<strong>Lecture</strong> — <code>a + b</code> appelle '
            '<code>operator +</code> sur <code>a</code> avec <code>b</code> '
            'comme <code>other</code>. Le résultat est un nouveau <code>Vector</code>.'
        ),
        callout(
            '<strong>Pratique :</strong> '
            '<a href="/playground/?example=oop">oop</a>, '
            '<a href="/playground/?example=inheritance">inheritance</a>, '
            '<a href="/playground/?example=operators-demo">operators-demo</a>. '
            'Suite : <a href="/docs/pattern-matching/">Pattern matching →</a>'
        ),
    ],
    [
        callout(
            '<strong>In one sentence</strong> — A class groups data (fields) and '
            'behavior (methods). Create instances with <code>new</code>.'
        ),
        h2('1. Classes and constructor'),
        p(
            'Declare a <code>class</code>, <code>field</code>s '
            '(often <code>public</code> or <code>private</code>), and '
            '<code>function</code> methods. The constructor is <code>init</code>: '
            'it runs on <code>new Class(…)</code>. Inside, <code>this</code> is the instance.'
        ),
        p(
            'Below: each <code>Dog</code> has a <code>name</code>. '
            '<code>init</code> stores it; <code>speak</code> prints a message. '
            'Then we create <code>rex</code> and call <code>rex.speak()</code>.'
        ),
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
        p(
            '<strong>Reading</strong> — <code>public field name text</code> declares '
            'an externally visible field. <code>set this.name = n</code> assigns the '
            'constructor argument. Every block ends with <code>end</code>.'
        ),
        h2('2. Inheritance'),
        p(
            '<code>extends</code> specializes a parent. '
            '<code>super</code> calls the parent implementation explicitly.'
        ),
        code('''class Vehicle
    function describe() returns text
        return "Vehicle "
    end
end

class Car extends Vehicle
    public field model text

    function describe() returns text
        return super.describe() + model
    end
end'''),
        p(
            '<strong>Reading</strong> — <code>Car</code> inherits <code>Vehicle</code>. '
            'Overriding <code>describe</code> composes the parent text via '
            '<code>super.describe()</code> then appends <code>model</code>.'
        ),
        h2('3. Interfaces'),
        p(
            'An <code>interface</code> is a contract without method bodies. '
            'A class <code>implements</code> it and must provide each method.'
        ),
        code('''interface Speakable
    function speak()
end

class Robot implements Speakable
    function speak()
        say "Beep"
    end
end

create pet Speakable = new Robot()
pet.speak()'''),
        p(
            '<strong>Reading</strong> — <code>pet</code> is typed as the interface, '
            'so any <code>Speakable</code> implementor can be assigned.'
        ),
        h2('4. Generic classes and records'),
        p(
            'Classes can take type parameters (<code>Box&lt;T&gt;</code>). '
            'Records fit when you only need grouped fields.'
        ),
        code('''class Box<T>
    public field value T

    function init(v T)
        set this.value = v
    end
end

create b = new Box<number>(42)
say b.value

record Point
    field x number
    field y number
end

create p = Point with x 3, y 4
say p.x'''),
        p(
            '<strong>Reading</strong> — <code>Box&lt;number&gt;</code> fixes T. '
            '<code>Point with x 3, y 4</code> builds a record without <code>new</code>.'
        ),
        h2('5. Useful OOP keywords'),
        ul([
            '<code>static field</code> / <code>static function</code> — shared by the class',
            '<code>abstract class</code> / <code>abstract function</code> — not instantiable / must override',
            '<code>final class</code> / <code>final function</code> — not extensible / not overridable',
            '<code>property</code> — auto getter/setter',
            '<code>destroy … end</code> — destructor',
            '<code>protected field</code> — visible in the hierarchy',
        ]),
        h2('6. Operator overloading'),
        p(
            'Declare <code>operator +</code>, <code>-</code>, <code>*</code>, '
            '<code>/</code>, <code>==</code>, <code>!=</code>, <code>&lt;</code>, '
            '<code>&gt;</code> inside a class.'
        ),
        code('''class Vector
    public field x number
    public field y number

    function init(ax number, ay number)
        set this.x = ax
        set this.y = ay
    end

    operator + (other Vector) returns Vector
        return new Vector(x + other.x, y + other.y)
    end
end

create a = new Vector(1, 2)
create b = new Vector(3, 4)
create c = a + b
say c.x'''),
        p(
            '<strong>Reading</strong> — <code>a + b</code> calls '
            '<code>operator +</code> on <code>a</code> with <code>b</code> as '
            '<code>other</code>.'
        ),
        callout(
            '<strong>Practice:</strong> '
            '<a href="/playground/?example=oop">oop</a>, '
            '<a href="/playground/?example=inheritance">inheritance</a>, '
            '<a href="/playground/?example=operators-demo">operators-demo</a>. '
            'Next: <a href="/docs/pattern-matching/">Pattern matching →</a>'
        ),
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
    '7900+ modules : I/O, JSON, HTTP, SIG, data science, IA, SQLite, jeux, graphes, ML.',
    '7900+ modules: I/O, JSON, HTTP, GIS, data science, AI, SQLite, games, graphs, ML.',
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
            '<strong>2151 simple</strong> — <code>import "std/name"</code> (dont giskit001–500 SIG)',
            '<strong>102 medium</strong> — <code>import "std/m/name"</code>',
            '<strong>5710 complex</strong> — gisultra, rasterultra, segultra, dataultra, datasci, vizultra, iaultra, dbultra, jeux…',
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
            '<strong>2151 simple</strong> — <code>import "std/name"</code> (incl. giskit001–500 GIS)',
            '<strong>102 medium</strong> — <code>import "std/m/name"</code>',
            '<strong>5710 complex</strong> — gisultra, rasterultra, segultra, dataultra, datasci, vizultra, iaultra, dbultra, games…',
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
from .docs_methodical import register_methodical_documentation

register_full_documentation(PAGES)
register_methodical_documentation(PAGES)
DOC_NAV_ORDER = _build_nav_order()
