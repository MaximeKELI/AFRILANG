"""Documentation complète AFRILANG — pages et extensions (FR/EN)."""

from .docs_pages import _page, callout, code, h2, h3, p, table, ul


def register_full_documentation(pages):
    """Enregistre toutes les pages langage et enrichit les pages existantes."""
    _register_new_pages(pages)
    _extend_existing_pages(pages)


def _register_new_pages(pages):
    pages['pattern-matching'] = _page(
        'pattern-matching',
        'Pattern matching', 'Pattern matching',
        'Enums, unions taguées, match statement et expression, exhaustivité.',
        'Enums, tagged unions, match statements and expressions, exhaustiveness.',
        [
            h2('Enums avec payload'),
            code('''enum Status
    case Ok
    case Error with message text
end

create e = Status.Error with "failed"

match e
    case Error with msg then
        say msg
    end
    default
        say "ok"
    end
end'''),
            h2('Unions taguées'),
            code('''union Shape
    case Circle with radius number
    case Rect with w number, h number
end

create circle = Shape.Circle with 5

match circle
    case Circle with r then say "radius {r}"
    end
    case Rect with w, h then say "{w}x{h}"
    end
end'''),
            h2('Match en expression'),
            code('''create area = match rect
    case Circle with r then 3.14 * r * r
    end
    case Rect with w, h then w * h
    end
end'''),
            h2('Exhaustivité'),
            p('Tous les cas d\'un enum/union doivent être couverts, ou un '
              '<code>default</code> doit être présent. Le compilateur vérifie '
              'l\'exhaustivité.'),
            callout('<strong>Exemples :</strong> <code>unions_demo.afr</code>, '
                    '<code>match_expr_demo.afr</code>, <code>traits_demo.afr</code>'),
        ],
        [
            h2('Enums with payload'),
            code('''enum Status
    case Ok
    case Error with message text
end

create e = Status.Error with "failed"

match e
    case Error with msg then
        say msg
    end
    default
        say "ok"
    end
end'''),
            h2('Tagged unions'),
            code('''union Shape
    case Circle with radius number
    case Rect with w number, h number
end

create circle = Shape.Circle with 5

match circle
    case Circle with r then say "radius {r}"
    end
    case Rect with w, h then say "{w}x{h}"
    end
end'''),
            h2('Match as expression'),
            code('''create area = match rect
    case Circle with r then 3.14 * r * r
    end
    case Rect with w, h then w * h
    end
end'''),
            h2('Exhaustiveness'),
            p('All enum/union cases must be covered, or a <code>default</code> '
              'branch is required. The compiler checks exhaustiveness.'),
            callout('<strong>Examples:</strong> <code>unions_demo.afr</code>, '
                    '<code>match_expr_demo.afr</code>, <code>traits_demo.afr</code>'),
        ],
    )

    pages['modules'] = _page(
        'modules',
        'Modules et imports', 'Modules & imports',
        'Modules export/private, import, use et appels qualifiés.',
        'export/private modules, import, use and qualified calls.',
        [
            h2('Déclaration de module'),
            code('''module Math
    export function add(a number, b number) returns number
        return a + b
    end

    private function helper(x number) returns number
        return x * 2
    end
end

use Math
say add(3, 4)
say Math.add(5, 6)'''),
            h2('Import stdlib / paquets'),
            code('''import "std/io"
import "std/json"
use io
use json

import "pkg/math/math.afr"
use Math'''),
            h2('Règles'),
            ul([
                '<code>export function</code> — API publique du module',
                '<code>private function</code> / <code>private class</code> — interne au module',
                '<code>Module.fn(...)</code> — appel qualifié sans ambiguïté',
                'Enums autorisés dans les modules',
            ]),
            callout('Exemple : <code>modules.afr</code>, <code>traits_demo.afr</code>'),
        ],
        [
            h2('Module declaration'),
            code('''module Math
    export function add(a number, b number) returns number
        return a + b
    end

    private function helper(x number) returns number
        return x * 2
    end
end

use Math
say add(3, 4)
say Math.add(5, 6)'''),
            h2('Import stdlib / packages'),
            code('''import "std/io"
import "std/json"
use io
use json

import "pkg/math/math.afr"
use Math'''),
            h2('Rules'),
            ul([
                '<code>export function</code> — public module API',
                '<code>private function</code> / <code>private class</code> — module-internal',
                '<code>Module.fn(...)</code> — qualified call',
                'Enums allowed inside modules',
            ]),
            callout('Example: <code>modules.afr</code>, <code>traits_demo.afr</code>'),
        ],
    )

    pages['functional'] = _page(
        'functional',
        'Lambdas et collections', 'Lambdas & collections',
        'Fonctions anonymes, map/filter/reduce/flatMap, paramètres par défaut.',
        'Anonymous functions, map/filter/reduce/flatMap, default parameters.',
        [
            h2('Lambdas'),
            code('''create doubleIt = function(x number) returns number
    return x * 2
end

function apply(fn function number to number, value number) returns number
    return fn(value)
end

say apply(doubleIt, 10)'''),
            h2('Opérations naturelles sur listes'),
            code('''create doubled = map each x in nums do
    return x * 2
end

create big = filter each x in nums where x is greater than 3

create total = reduce nums from 0 with each acc, x do
    return acc + x
end

create flat = flatMap each n in nums do
    return list of n, n * 10
end'''),
            h2('Paramètres par défaut'),
            code('''function greet(name text, prefix text = "Hello") returns text
    return prefix + " " + name
end

say greet("World")
say greet("Africa", "Bonjour")'''),
            h2('std/collections'),
            code('''import "std/collections"
use collections

create doubled = mapNumbers(nums, function(x number) returns number
    return x * 2
end)'''),
            callout('Exemples : <code>lambdas.afr</code>, <code>natural_list_ops.afr</code>, '
                    '<code>defaults.afr</code>'),
        ],
        [
            h2('Lambdas'),
            code('''create doubleIt = function(x number) returns number
    return x * 2
end

function apply(fn function number to number, value number) returns number
    return fn(value)
end

say apply(doubleIt, 10)'''),
            h2('Natural list operations'),
            code('''create doubled = map each x in nums do
    return x * 2
end

create big = filter each x in nums where x is greater than 3

create total = reduce nums from 0 with each acc, x do
    return acc + x
end

create flat = flatMap each n in nums do
    return list of n, n * 10
end'''),
            h2('Default parameters'),
            code('''function greet(name text, prefix text = "Hello") returns text
    return prefix + " " + name
end

say greet("World")
say greet("Africa", "Bonjour")'''),
            h2('std/collections'),
            code('''import "std/collections"
use collections

create doubled = mapNumbers(nums, function(x number) returns number
    return x * 2
end)'''),
            callout('Examples: <code>lambdas.afr</code>, <code>natural_list_ops.afr</code>, '
                    '<code>defaults.afr</code>'),
        ],
    )

    pages['exceptions'] = _page(
        'exceptions',
        'Exceptions', 'Exceptions',
        'try / catch / raise pour la gestion d\'erreurs runtime.',
        'try / catch / raise for runtime error handling.',
        [
            h2('Syntaxe'),
            code('''try
    raise "something failed"
catch error e
    say e
end'''),
            h2('Result vs exceptions'),
            p('<code>returns T or error</code> + <code>match</code> pour les erreurs typées. '
              '<code>try/catch/raise</code> pour les erreurs runtime.'),
            callout('Exemple : <code>exceptions.afr</code>'),
        ],
        [
            h2('Syntax'),
            code('''try
    raise "something failed"
catch error e
    say e
end'''),
            h2('Result vs exceptions'),
            p('<code>returns T or error</code> + <code>match</code> for typed errors. '
              '<code>try/catch/raise</code> for runtime errors.'),
            callout('Example: <code>exceptions.afr</code>'),
        ],
    )

    pages['async'] = _page(
        'async',
        'Async / await', 'Async / await',
        'Coroutines C++20, Result async, await dans les tests, std/async, std/http, std/io.',
        'C++20 coroutines, async Result, await in tests, std/async, std/http, std/io.',
        [
            h2('Fonctions async'),
            code('''import "std/async"
use async

async function wait(ms number) returns text or error
    if ms is less than 0 then
        return error "invalid delay"
    end
    await sleep(ms)
    return "ready"
end

async function main()
    create r = await wait(10)
    if r is error then
        say r.message
    else
        say r.value
    end
end

await main()'''),
            h2('Await dans les tests'),
            code('''test "async works"
    create r = await wait(1)
    assert r.value is equal to "ready"
end'''),
            h2('Modules async I/O'),
            table(['Module', 'Fonctions'], [
                ['<code>std/async</code>', '<code>sleep(ms)</code> — scheduler'],
                ['<code>std/http</code>', '<code>httpGetAsync</code>, <code>httpPostAsync</code>'],
                ['<code>std/io</code>', '<code>readFileAsync</code>'],
            ]),
            p('Compilation async : g++ C++20, <code>-fcoroutines -pthread</code>.'),
            callout('Exemples : <code>async_demo.afr</code>, <code>async_full.afr</code>'),
        ],
        [
            h2('Async functions'),
            code('''import "std/async"
use async

async function wait(ms number) returns text or error
    if ms is less than 0 then
        return error "invalid delay"
    end
    await sleep(ms)
    return "ready"
end

async function main()
    create r = await wait(10)
    if r is error then
        say r.message
    else
        say r.value
    end
end

await main()'''),
            h2('Await in tests'),
            code('''test "async works"
    create r = await wait(1)
    assert r.value is equal to "ready"
end'''),
            h2('Async I/O modules'),
            table(['Module', 'Functions'], [
                ['<code>std/async</code>', '<code>sleep(ms)</code> — scheduler'],
                ['<code>std/http</code>', '<code>httpGetAsync</code>, <code>httpPostAsync</code>'],
                ['<code>std/io</code>', '<code>readFileAsync</code>'],
            ]),
            p('Async build: g++ C++20, <code>-fcoroutines -pthread</code>.'),
            callout('Examples: <code>async_demo.afr</code>, <code>async_full.afr</code>'),
        ],
    )

    pages['gui'] = _page(
        'gui',
        'Interfaces graphiques', 'Graphical UI',
        'Syntaxe naturelle SDL2 et module std/ui.',
        'Natural SDL2 syntax and std/ui module.',
        [
            h2('Syntaxe naturelle (SDL2)'),
            code('''open window titled "Demo" with width 640, height 480

while window is open do
    clear background color 28, 28, 36
    draw text "Bonjour!" at 80, 80 size 32
    if button "Quitter" at 220, 350 width 200 height 50 is clicked then
        close window
    end
    show frame
end'''),
            h2('Module std/ui'),
            code('''import "std/ui"
use ui

openWindow("Demo", 640, 480)
drawText("Hello", 80, 80, 32)
drawButton("Quit", 220, 350, 200, 50)
showFrame()'''),
            p('Prérequis : SDL2 + SDL2_ttf (<code>-lSDL2 -lSDL2_ttf</code>).'),
            callout('Exemple : <code>gui_demo.afr</code>'),
        ],
        [
            h2('Natural syntax (SDL2)'),
            code('''open window titled "Demo" with width 640, height 480

while window is open do
    clear background color 28, 28, 36
    draw text "Hello!" at 80, 80 size 32
    if button "Quit" at 220, 350 width 200 height 50 is clicked then
        close window
    end
    show frame
end'''),
            h2('std/ui module'),
            code('''import "std/ui"
use ui

openWindow("Demo", 640, 480)
drawText("Hello", 80, 80, 32)
drawButton("Quit", 220, 350, 200, 50)
showFrame()'''),
            p('Requires SDL2 + SDL2_ttf (<code>-lSDL2 -lSDL2_ttf</code>).'),
            callout('Example: <code>gui_demo.afr</code>'),
        ],
    )

    pages['package-manager'] = _page(
        'package-manager',
        'Gestionnaire de paquets', 'Package manager',
        'afrilang.toml, semver, lockfile et commandes pkg.',
        'afrilang.toml, semver, lockfile and pkg commands.',
        [
            h2('afrilang.toml'),
            code('''[project]
name = "mon_app"
version = "0.1.0"

[dependencies]
math = "0.1.0"'''),
            h2('Commandes pkg'),
            table(['Commande', 'Description'], [
                ['<code>afrilang pkg add math</code>', 'Ajouter une dépendance'],
                ['<code>afrilang pkg install</code>', 'Installer depuis le lockfile'],
                ['<code>afrilang pkg list [--blessed]</code>', 'Lister les paquets'],
                ['<code>afrilang pkg search query</code>', 'Rechercher'],
                ['<code>afrilang pkg publish dir</code>', 'Publier localement'],
            ]),
            p('Paquets certifiés (★) avec vérification SHA256 — voir la '
              '<a href="/packages/">page Paquets</a>.'),
            callout('Exemple : <code>pkg_demo.afr</code>'),
        ],
        [
            h2('afrilang.toml'),
            code('''[project]
name = "my_app"
version = "0.1.0"

[dependencies]
math = "0.1.0"'''),
            h2('pkg commands'),
            table(['Command', 'Description'], [
                ['<code>afrilang pkg add math</code>', 'Add dependency'],
                ['<code>afrilang pkg install</code>', 'Install from lockfile'],
                ['<code>afrilang pkg list [--blessed]</code>', 'List packages'],
                ['<code>afrilang pkg search query</code>', 'Search'],
                ['<code>afrilang pkg publish dir</code>', 'Publish locally'],
            ]),
            p('Certified packages (★) with SHA256 — see the '
              '<a href="/packages/">Packages page</a>.'),
            callout('Example: <code>pkg_demo.afr</code>'),
        ],
    )

    pages['spec'] = _page(
        'spec',
        'Référence du langage', 'Language reference',
        'Spécification 1.0, identifiants UTF-8, codes d\'erreur, compatibilité.',
        'Spec 1.0, UTF-8 identifiers, error codes, compatibility.',
        [
            h2('Spécification complète'),
            p('Le document de référence est <code>docs/LANGUAGE.md</code> dans le dépôt GitHub. '
              'Il couvre l\'EBNF, la sémantique, la stdlib et la politique de compatibilité 1.x.'),
            h2('Identifiants UTF-8'),
            p('Les identifiants acceptent les caractères Unicode (accents, lettres africaines).'),
            h2('Codes d\'erreur stables'),
            p('Format : <code>Erreur [E0001] ligne X</code> — codes documentés pour l\'IDE et CI.'),
            h2('Compatibilité 1.x'),
            ul([
                'Semver pour les paquets (<code>afrilang.toml</code>)',
                'LSP 1.1 — diagnostics, hover, definition, complétion FR/EN',
                'Syntaxe bilingue FR/EN stable',
            ]),
            h2('Licence'),
            p('MIT — voir <code>LICENSE</code>, <code>CONTRIBUTING.md</code>, <code>SECURITY.md</code>.'),
        ],
        [
            h2('Full specification'),
            p('Reference document: <code>docs/LANGUAGE.md</code> on GitHub. '
              'Covers EBNF, semantics, stdlib and 1.x compatibility policy.'),
            h2('UTF-8 identifiers'),
            p('Identifiers accept Unicode characters (accents, African letters).'),
            h2('Stable error codes'),
            p('Format: <code>Erreur [E0001] line X</code> — documented codes for IDE and CI.'),
            h2('1.x compatibility'),
            ul([
                'Semver for packages (<code>afrilang.toml</code>)',
                'LSP 1.1 — diagnostics, hover, definition, FR/EN completion',
                'Stable bilingual FR/EN syntax',
            ]),
            h2('License'),
            p('MIT — see <code>LICENSE</code>, <code>CONTRIBUTING.md</code>, <code>SECURITY.md</code>.'),
        ],
    )


def _extend_existing_pages(pages):
    _extend_syntax(pages)
    _extend_types(pages)
    _extend_oop(pages)
    _extend_advanced(pages)
    _extend_stdlib(pages)
    _extend_tooling(pages)
    _extend_overview(pages)


def _extend_syntax(pages):
    fr = pages['syntax']['fr']['blocks']
    en = pages['syntax']['en']['blocks']
    extra_fr = [
        h2('Fonctions'),
        code('''function add(a number, b number) returns number
    return a + b
end

say add(2, 3)'''),
        h2('Maps'),
        code('''create m = map of "a" to 1, "b" to 2
say m at "a"
set m at "c" = 3
for each key, value in m do
    say key
    say value
end'''),
        h2('Boucle numérique for'),
        code('''for i from 1 to 10 do
    say i
end

for n from 0 to 10 step 2 do
    say n
end'''),
        h2('Interpolation'),
        code('create name = "World"\nsay "Hello {name}!"'),
        h2('Alias français (étendu)'),
        table(['Anglais', 'Français'], [
            ['<code>say</code>', '<code>dire</code>'],
            ['<code>ask</code>', '<code>demander</code>'],
            ['<code>create</code>', '<code>creer</code>'],
            ['<code>set</code>', '<code>definir</code>'],
            ['<code>if/then/else/end</code>', '<code>si/alors/sinon/fin</code>'],
            ['<code>while/do</code>', '<code>tantque/faire</code>'],
            ['<code>repeat/times</code>', '<code>repeter/fois</code>'],
            ['<code>function</code>', '<code>fonction</code>'],
            ['<code>class</code>', '<code>classe</code>'],
            ['<code>match/case/default</code>', '<code>correspondance/cas/defaut</code>'],
            ['<code>number/text/bool</code>', '<code>nombre/texte/booleen</code>'],
        ]),
    ]
    extra_en = [
        h2('Functions'),
        code('''function add(a number, b number) returns number
    return a + b
end

say add(2, 3)'''),
        h2('Maps'),
        code('''create m = map of "a" to 1, "b" to 2
say m at "a"
set m at "c" = 3
for each key, value in m do
    say key
    say value
end'''),
        h2('Numeric for loop'),
        code('''for i from 1 to 10 do
    say i
end

for n from 0 to 10 step 2 do
    say n
end'''),
        h2('Interpolation'),
        code('create name = "World"\nsay "Hello {name}!"'),
        h2('French aliases (extended)'),
        table(['English', 'French'], [
            ['<code>say</code>', '<code>dire</code>'],
            ['<code>ask</code>', '<code>demander</code>'],
            ['<code>create</code>', '<code>creer</code>'],
            ['<code>set</code>', '<code>definir</code>'],
            ['<code>if/then/else/end</code>', '<code>si/alors/sinon/fin</code>'],
            ['<code>while/do</code>', '<code>tantque/faire</code>'],
            ['<code>repeat/times</code>', '<code>repeter/fois</code>'],
            ['<code>function</code>', '<code>fonction</code>'],
            ['<code>class</code>', '<code>classe</code>'],
            ['<code>match/case/default</code>', '<code>correspondance/cas/defaut</code>'],
            ['<code>number/text/bool</code>', '<code>nombre/texte/booleen</code>'],
        ]),
    ]
    fr.extend(extra_fr)
    en.extend(extra_en)


def _extend_types(pages):
    fr = pages['types']['fr']['blocks']
    en = pages['types']['en']['blocks']
    fr.extend([
        h2('Génériques explicites'),
        code('say identity<number>(42)\nsay identity<text>("hi")'),
        h2('Matcher Result'),
        code('''match parse("42")
    case error with msg then say msg
    end
    default say "ok"
    end
end'''),
        h2('Listes polymorphes'),
        code('create pets list of Speakable = list of new Dog("Rex")'),
    ])
    en.extend([
        h2('Explicit type parameters'),
        code('say identity<number>(42)\nsay identity<text>("hi")'),
        h2('Matching Result'),
        code('''match parse("42")
    case error with msg then say msg
    end
    default say "ok"
    end
end'''),
        h2('Polymorphic lists'),
        code('create pets list of Speakable = list of new Dog("Rex")'),
    ])


def _extend_oop(pages):
    fr = pages['oop']['fr']['blocks']
    en = pages['oop']['en']['blocks']
    fr.extend([
        h2('Records'),
        code('''record Point
    field x number
    field y number
end'''),
        h2('POO avancée'),
        ul([
            '<code>static field</code> / <code>static function</code>',
            '<code>abstract class</code> / <code>abstract function</code>',
            '<code>final class</code> / <code>final function</code>',
            '<code>property</code> — getter/setter auto',
            '<code>destroy</code> — destructeur',
            '<code>protected field</code>',
        ]),
        h2('Polymorphisme'),
        code('create pet Speakable = new Dog()\ncreate pets list of Speakable = list of new Dog()'),
        h2('Surcharge d\'opérateurs'),
        code('''operator + (other Vector) returns Vector
    return new Vector(x + other.x, y + other.y)
end'''),
        p('Opérateurs : <code>+</code> <code>-</code> <code>*</code> <code>/</code> '
          '<code>==</code> <code>!=</code> <code>&lt;</code> <code>&gt;</code>'),
        callout('Exemples : <code>poo_advanced.afr</code>, <code>operators_demo.afr</code>, '
                '<code>traits_demo.afr</code>'),
    ])
    en.extend([
        h2('Records'),
        code('''record Point
    field x number
    field y number
end'''),
        h2('Advanced OOP'),
        ul([
            '<code>static field</code> / <code>static function</code>',
            '<code>abstract class</code> / <code>abstract function</code>',
            '<code>final class</code> / <code>final function</code>',
            '<code>property</code> — auto getter/setter',
            '<code>destroy</code> — destructor',
            '<code>protected field</code>',
        ]),
        h2('Polymorphism'),
        code('create pet Speakable = new Dog()\ncreate pets list of Speakable = list of new Dog()'),
        h2('Operator overloading'),
        code('''operator + (other Vector) returns Vector
    return new Vector(x + other.x, y + other.y)
end'''),
        p('Operators: <code>+</code> <code>-</code> <code>*</code> <code>/</code> '
          '<code>==</code> <code>!=</code> <code>&lt;</code> <code>&gt;</code>'),
        callout('Examples: <code>poo_advanced.afr</code>, <code>operators_demo.afr</code>, '
                '<code>traits_demo.afr</code>'),
    ])


def _extend_advanced(pages):
    fr = pages['advanced']['fr']['blocks']
    en = pages['advanced']['en']['blocks']
    fr.extend([
        h2('Exceptions'),
        code('''try
    raise "failed"
catch error e
    say e
end'''),
        h2('FFI — bibliothèques autorisées'),
        p('Libs : <code>m</code>, <code>pthread</code>, <code>dl</code>, <code>curl</code>, '
          '<code>c</code>. Types : number, text, bool, pointer.'),
        callout('Voir aussi : Pattern matching, Async, GUI, Modules.'),
    ])
    en.extend([
        h2('Exceptions'),
        code('''try
    raise "failed"
catch error e
    say e
end'''),
        h2('FFI — allowed libraries'),
        p('Libs: <code>m</code>, <code>pthread</code>, <code>dl</code>, <code>curl</code>, '
          '<code>c</code>. Types: number, text, bool, pointer.'),
        callout('See also: Pattern matching, Async, GUI, Modules.'),
    ])


def _extend_stdlib(pages):
    fr = pages['stdlib']['fr']['blocks']
    en = pages['stdlib']['en']['blocks']
    fr.extend([
        h2('Modules core (API)'),
        table(['Module', 'Fonctions clés'], [
            ['<code>std/io</code>', 'readFile, writeFile, readLine, readFileAsync'],
            ['<code>std/json</code>', 'parse, stringify'],
            ['<code>std/fs</code>', 'exists, listDir, copy, remove'],
            ['<code>std/http</code>', 'httpGet, httpPost, httpGetAsync'],
            ['<code>std/collections</code>', 'mapNumbers, filterNumbers, reduceNumbers'],
            ['<code>std/args</code>', 'count, at, all'],
            ['<code>std/path</code>', 'join, basename, dirname, extension'],
            ['<code>std/str</code>', 'split, trim, contains, replace'],
            ['<code>std/math</code>', 'sqrt, pow, floor, ceil'],
            ['<code>std/time</code>', 'now, format, sleep'],
            ['<code>std/re</code>', 'match, replace'],
            ['<code>std/log</code>', 'info, warn, error'],
            ['<code>std/async</code>', 'sleep(ms)'],
            ['<code>std/ui</code>', 'openWindow, drawText, drawButton, showFrame'],
        ]),
        h2('Domaines (210 modules complexes)'),
        ul(['Graphes, ML, crypto, finance, NLP, simulation, réseaux…']),
        p('Navigateur complet : <a href="/stdlib/">463+ modules</a> avec source et signatures.'),
        callout('Référence : <code>docs/STDLIB_SIMPLE.md</code>, <code>STDLIB_MEDIUM.md</code>, '
                '<code>STDLIB_COMPLEX.md</code>'),
    ])
    en.extend([
        h2('Core modules (API)'),
        table(['Module', 'Key functions'], [
            ['<code>std/io</code>', 'readFile, writeFile, readLine, readFileAsync'],
            ['<code>std/json</code>', 'parse, stringify'],
            ['<code>std/fs</code>', 'exists, listDir, copy, remove'],
            ['<code>std/http</code>', 'httpGet, httpPost, httpGetAsync'],
            ['<code>std/collections</code>', 'mapNumbers, filterNumbers, reduceNumbers'],
            ['<code>std/args</code>', 'count, at, all'],
            ['<code>std/path</code>', 'join, basename, dirname, extension'],
            ['<code>std/str</code>', 'split, trim, contains, replace'],
            ['<code>std/math</code>', 'sqrt, pow, floor, ceil'],
            ['<code>std/time</code>', 'now, format, sleep'],
            ['<code>std/re</code>', 'match, replace'],
            ['<code>std/log</code>', 'info, warn, error'],
            ['<code>std/async</code>', 'sleep(ms)'],
            ['<code>std/ui</code>', 'openWindow, drawText, drawButton, showFrame'],
        ]),
        h2('Domains (210 complex modules)'),
        ul(['Graphs, ML, crypto, finance, NLP, simulation, networking…']),
        p('Full browser: <a href="/stdlib/">463+ modules</a> with source and signatures.'),
        callout('Reference: <code>docs/STDLIB_SIMPLE.md</code>, <code>STDLIB_MEDIUM.md</code>, '
                '<code>STDLIB_COMPLEX.md</code>'),
    ])


def _extend_tooling(pages):
    fr = pages['tooling']['fr']['blocks']
    en = pages['tooling']['en']['blocks']
    fr.extend([
        h2('CLI complète'),
        table(['Commande', 'Rôle'], [
            ['<code>afrilang run</code>', 'Compiler + exécuter'],
            ['<code>afrilang build</code>', 'Build projet'],
            ['<code>afrilang check</code>', 'Vérifier sans compiler'],
            ['<code>afrilang test [--coverage]</code>', 'Tests intégrés'],
            ['<code>afrilang fmt</code>', 'Formater'],
            ['<code>afrilang lint</code>', 'Analyse statique (warnings)'],
            ['<code>afrilang doc</code>', 'Générer doc Markdown'],
            ['<code>afrilang repl</code>', 'REPL interactif v2'],
            ['<code>afrilang debug</code>', 'Debug GDB/DAP'],
            ['<code>afrilang serve</code>', 'Playground local'],
            ['<code>afrilang init</code>', 'Nouveau projet'],
            ['<code>afrilang benchmark</code>', 'Benchmarks'],
            ['<code>afrilang pkg …</code>', 'Gestionnaire de paquets'],
        ]),
        h2('REPL v2'),
        table(['Commande', 'Action'], [
            ['<code>:load file.afr</code>', 'Charger un fichier'],
            ['<code>:type expr</code>', 'Afficher le type'],
            ['<code>:run</code>', 'Exécuter le buffer'],
            ['<code>:history</code>', 'Historique'],
            ['<code>:paste</code>', 'Mode collage multiligne'],
            ['<code>:reset</code>', 'Réinitialiser'],
            ['<code>:quit</code>', 'Quitter'],
        ]),
        h2('Extension IDE'),
        p('VS Code / Cursor v1.4+ — LSP, coloration, snippets. Open VSX et marketplace.'),
    ])
    en.extend([
        h2('Full CLI'),
        table(['Command', 'Role'], [
            ['<code>afrilang run</code>', 'Compile + run'],
            ['<code>afrilang build</code>', 'Build project'],
            ['<code>afrilang check</code>', 'Check without compile'],
            ['<code>afrilang test [--coverage]</code>', 'Built-in tests'],
            ['<code>afrilang fmt</code>', 'Format'],
            ['<code>afrilang lint</code>', 'Static analysis (warnings)'],
            ['<code>afrilang doc</code>', 'Generate Markdown docs'],
            ['<code>afrilang repl</code>', 'Interactive REPL v2'],
            ['<code>afrilang debug</code>', 'GDB/DAP debug'],
            ['<code>afrilang serve</code>', 'Local playground'],
            ['<code>afrilang init</code>', 'New project'],
            ['<code>afrilang benchmark</code>', 'Benchmarks'],
            ['<code>afrilang pkg …</code>', 'Package manager'],
        ]),
        h2('REPL v2'),
        table(['Command', 'Action'], [
            ['<code>:load file.afr</code>', 'Load a file'],
            ['<code>:type expr</code>', 'Show type'],
            ['<code>:run</code>', 'Run buffer'],
            ['<code>:history</code>', 'History'],
            ['<code>:paste</code>', 'Multiline paste mode'],
            ['<code>:reset</code>', 'Reset'],
            ['<code>:quit</code>', 'Quit'],
        ]),
        h2('IDE extension'),
        p('VS Code / Cursor v1.4+ — LSP, highlighting, snippets. Open VSX and marketplace.'),
    ])


def _extend_overview():
    fr = pages['overview']['fr']['blocks']
    en = pages['overview']['en']['blocks']
    fr.extend([
        h2('Parcours d\'apprentissage'),
        table(['Sujet', 'Documentation', 'Exemple playground'], [
            ['Syntaxe de base', 'Premiers pas → Syntaxe', '<code>?example=hello</code>'],
            ['Conditions / boucles', 'Syntaxe', '<code>?example=conditions</code>'],
            ['POO / traits', 'POO → Pattern matching', '<code>?example=traits-demo</code>'],
            ['Listes / lambdas', 'Lambdas et collections', '<code>?example=natural-list-ops</code>'],
            ['Async', 'Async / await', '<code>?example=async-full</code>'],
            ['GUI SDL2', 'Interfaces graphiques', '<code>?example=gui-demo</code>'],
            ['Stdlib', 'Bibliothèque standard + /stdlib/', '<code>?example=stdlib-demo</code>'],
        ]),
        h2('Index des 59 exemples'),
        p('Galerie complète avec recherche : <a href="/examples/">/examples/</a>. '
              'Chaque exemple s\'ouvre dans le <a href="/playground/">playground</a>.'),
    ])
    en.extend([
        h2('Learning path'),
        table(['Topic', 'Documentation', 'Playground example'], [
            ['Basic syntax', 'Getting started → Syntax', '<code>?example=hello</code>'],
            ['Conditionals / loops', 'Syntax', '<code>?example=conditions</code>'],
            ['OOP / traits', 'OOP → Pattern matching', '<code>?example=traits-demo</code>'],
            ['Lists / lambdas', 'Lambdas & collections', '<code>?example=natural-list-ops</code>'],
            ['Async', 'Async / await', '<code>?example=async-full</code>'],
            ['SDL2 GUI', 'Graphical UI', '<code>?example=gui-demo</code>'],
            ['Stdlib', 'Standard library + /stdlib/', '<code>?example=stdlib-demo</code>'],
        ]),
        h2('All 59 examples'),
        p('Full gallery with search: <a href="/examples/">/examples/</a>. '
              'Each example opens in the <a href="/playground/">playground</a>.'),
    ])
