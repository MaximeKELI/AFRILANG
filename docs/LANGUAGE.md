# AFRILANG Language Specification (draft 0.2)

## Types

| Type | Syntax | C++ |
|------|--------|-----|
| number | `number` | `double` |
| text | `text` | `std::string` |
| bool | `bool` | `bool` |
| list | `list of T` | `std::vector<T>` (classes: `vector<unique_ptr<T>>`) |
| map | `map K to V` | `std::unordered_map<K,V>` |
| optional | `T?` | `std::optional<T>` |
| result | `T or error` | `AfrResult_T` |

## Programmation orientée objet (POO)

Classes, héritage, encapsulation et interfaces :

```afr
class Animal
    function speak()
        say "..."
    end
end

class Dog extends Animal
    public field name text

    function init(aName text)
        set this.name = aName
    end

    function speak()
        say name + " says Woof!"
    end
end

create rex = new Dog("Rex")
rex.speak()
```

Fonctionnalités POO :
- **Classes** — `class Nom ... end` avec méthodes `function ... end`
- **Instanciation** — `new Classe` ou `new Classe(arg1, arg2)` (constructeur `init`)
- **Champs** — `public field` / `private field` / `protected field`, accès via `this.champ` ou `obj.champ`
- **Héritage** — `class Enfant extends Parent` avec redéfinition (`override` en C++)
- **super** — `super(arg)` dans `init`, `super.methode()` pour appeler le parent
- **static** — `static field` / `static function`, appel via `Classe.methode()`
- **abstract** — `abstract class` et `abstract function` (pas d'instanciation)
- **final** — `final class` (non extensible), `final function` (non redéfinissable)
- **property** — `property text name end` (getter/setter auto)
- **destroy** — bloc `destroy ... end` → destructeur virtuel
- **Polymorphisme** — `create pet Animal = new Dog("Rex")`, listes `list of Animal`
- **Classes génériques** — `class Box<T> ... end`, `new Box<number>(42)`
- **Interfaces** — `interface I ... end` et `class C implements I, J`
- **Records** — structs légers (`record Point ... end`)

Exemples : `examples/oop.afr`, `examples/inheritance.afr`, `examples/poo_demo.afr`, `examples/oop_full.afr`, `examples/polymorphic_list.afr`, `examples/generic_class.afr`, `examples/poo_advanced.afr`, `examples/phase11_demo.afr`

## Maps

```afr
create m = map of "a" to 1, "b" to 2
create m map text to number = map of "x" to 10
create empty = empty map text to number
say m at "a"
set m at "c" = 3
for each key, value in m do
    say key
    say value
end
```

## Exceptions

```afr
try
    raise "something failed"
catch error e
    say e
end
```

## Enums et pattern matching

```afr
enum Status
    case Ok
    case Error with message text
end

create e = Status.Error with "failed"

match e
    case Error with msg then
        say msg
    end
    default
        say "other"
    end
end
```

Liaison de payload : `case Error with msg then` lie `msg` au champ `message`.

## String interpolation

```afr
create name = "World"
say "Hello {name}!"
```

## Modules

Import with `import "std/io"` and `use io`.

```afr
module Math
    export function add(a number, b number) returns number
        return a + b
    end

    private function helper(x number) returns number
        return x * 2
    end
end

use Math
say add(3, 4)
say Math.add(5, 6)    -- accès qualifié sans ambiguïté
```

- **`export function`** — API publique du module (documentation explicite)
- **`private function` / `private class`** — invisible via `use` (accessible dans le module)
- **`Module.fn(...)`** — appel qualifié sans `use`

Available stdlib modules: io, json, fs, http, str, log, math, time, re, collections, args, path, async, ui, plus **151 simple** (`std/nom`), **102 medium** (`std/m/nom`), **210 complex** (`std/c/nom`) — see `docs/STDLIB_*.md`.

## Syntaxe bilingue (français / anglais)

Les mots-clés anglais acceptent des **alias français** (ex. `dire` = `say`, `si`/`alors`/`sinon`, `fin` = `end`, `creer` = `create`, `fonction` = `function`, `classe` = `class`, `utiliser` = `use`, `importer` = `import`, `tantque` = `while`, `cas`/`defaut`/`avec` pour `match`, types `nombre`/`texte`/`booleen`, etc.).

Exemple : `examples/language_demo.afr`

## Generics

```afr
function identity<T>(x T) returns T
    return x
end

say identity(42)              -- inférence
say identity<number>(42)      -- paramètre de type explicite
```

## Default parameters

```afr
function greet(name text, prefix text = "Hello") returns text
    return join(list of prefix, " ", name)
end

say greet("World")
say greet("Africa", "Bonjour")
```

## Numeric for loops

```afr
for i from 1 to 10 do
    say i
end

for n from 0 to 10 step 2 do
    say n
end
```

## Constants

```afr
create const MAX = 100
create const NAME text = "AFRILANG"
```

## Lambdas (fonctions anonymes)

```afr
create doubleIt = function(x number) returns number
    return x * 2
end

say doubleIt(21)

function apply(fn function number to number, value number) returns number
    return fn(value)
end

say apply(doubleIt, 10)
```

Type fonction : `function number to number`, `function number, text to text`, etc.

## map / filter / reduce (listes + lambdas)

Syntaxe naturelle (sans import) :

```afr
create doubled = map each x in nums do
    return x * 2
end

create big = filter each x in nums where x is greater than 3

create total = reduce nums from 0 with each acc, x do
    return acc + x
end

create flat = flatMap each n in nums do
    return list of n, n * 10
end
```

`reduce` fonctionne aussi sur `list text` (valeur initiale text).

Syntaxe explicite via `std/collections` :

```afr
import "std/collections"
use collections

create doubled = mapNumbers(nums, function(x number) returns number
    return x * 2
end)

create big = filterNumbers(nums, function(x number) returns bool
    if x is greater than 3 then
        return yes
    else
        return no
    end
end)

create total = reduceNumbers(nums, function(acc number, x number) returns number
    return acc + x
end, 0)
```

## Async / await

Les fonctions `async` retournent implicitement un `task T` (coroutines C++20).  
Support complet : `returns T or error`, `await` dans les tests, I/O async.

```afr
import "std/async"
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

test "async in test block"
    create r = await wait(1)
    assert r.value is equal to "ready"
end

await main()
```

| Fonctionnalité | Détail |
|----------------|--------|
| `async function` | Retourne `task T` ou `task (T or error)` |
| `await` | Global, fonctions async, blocs `test` |
| `std/async` | `sleep(ms)` — scheduler avec file de timers |
| `std/http` | `httpGetAsync`, `httpPostAsync` — thread pool |
| `std/io` | `readFileAsync` — lecture fichier non bloquante |
| Compilation | C++20 coroutines (`-std=c++20 -fcoroutines -pthread`) |

## Interfaces graphiques

Syntaxe naturelle pour créer des fenêtres SDL2 (backend `runtime/ui.hpp`).

```afr
open window titled "Demo" with width 640, height 480

while window is open do
    clear background color 28, 28, 36
    draw text "Bonjour!" at 80, 80 size 32
    if button "Quitter" at 220, 350 width 200 height 50 is clicked then
        close window
    end
    show frame
end
```

| Instruction / expression | Description |
|--------------------------|-------------|
| `open window titled ... with width ..., height ...` | Ouvre une fenêtre |
| `while window is open do` | Boucle principale (appelle `beginFrame` automatiquement) |
| `clear background color r, g, b` | Efface l'écran (RGB 0–255) |
| `draw text "..." at x, y size n` | Affiche du texte |
| `button "..." at x, y width w height h is clicked` | Bouton cliquable (booléen) |
| `show frame` | Présente l'image à l'écran |
| `close window` | Ferme la fenêtre |

Module stdlib équivalent : `import "std/ui"` puis `use ui` (`openWindow`, `drawButton`, etc.).

Compilation : `-lSDL2 -lSDL2_ttf` (SDL2 + SDL2_ttf requis).

## Modules

Import with `import "std/io"` and `use io`.

Available stdlib modules: io, json, fs, http, str, log, math, time, re, collections, args, path, async, ui, plus **151 simple** (`std/nom`), **102 medium** (`std/m/nom`), **210 complex** (`std/c/nom`) — see `docs/STDLIB_*.md`.

### std/args

```afr
import "std/args"
use args

say count()
say at(0)
```

### std/path

```afr
import "std/path"
use path

say join("home", "user")
say basename("/tmp/file.txt")
```

## REPL

```bash
afrilang repl
```

Commandes : `:help`, `:reset`, `:show`, `:run`, `:load fichier.afr`, `:type expr`, `:history`, `:paste` / `:end`, `:quit`
