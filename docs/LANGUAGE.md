# AFRILANG Language Specification 1.0

## Comment lire cette spécification

1. **Types** — primitives, collections, optionnels, Result  
2. **POO** — classes, héritage, interfaces, records  
3. **Contrôle** — conditions, boucles, match  
4. **Modules & paquets** — import / use (voir aussi `PKG.md`)  
5. **Async, FFI, tests** — sections dédiées plus bas  
6. **Guide web méthodique** — [documentation site](https://github.com/MaximeKELI/AFRILANG) `/docs/` (parcours numéroté)

Convention : chaque bloc se ferme par `end` (ou `fin`). Comparaisons en mots (`is equal to`, …).  
Optionnels : `T?`, `nothing`, `is defined` — pas `none` / `is some`.

---

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

**Union taguée** — alias de `enum` pour les types somme :

```afr
union Shape
    case Circle with radius number
    case Rect with width number, height number
end

create s = Shape.Circle with 5

match s
    case Circle with r then
        say r
    end
    case Rect with w, h then
        say w
    end
end
```

**Exhaustivité** : tous les cas doivent être couverts ou un `default` doit être présent.

### Match en expression

Retourne une valeur (utilisable dans `create`, `say`, `return`, etc.) :

```afr
create label = match s
    case Ok then "success"
    end
    case Error with msg then msg
    end
    default "unknown"
    end
end

say match Status.Ok then "ok" end default "?" end
```

Chaque bras : `case Nom then <expression> end` ou `default <expression> end`.

## Interfaces (traits)

```afr
interface Speakable
    function speak()
end

class Dog implements Speakable
    function speak()
        say "Woof!"
    end
end

create pet Speakable = new Dog()
create pets list of Speakable = list of new Dog()
pet.speak()
```

- Vérification des **signatures** à l'implémentation (paramètres, retour)
- Variables et listes **typées par interface**
- Polymorphisme via `std::unique_ptr<Interface>` + virtual

## Surcharge d'opérateurs

Dans une classe, déclarez des opérateurs binaires :

```afr
class Vector
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

create c = a + b
```

Opérateurs supportés : `+`, `-`, `*`, `/`, `==`, `!=`, `<`, `>`.

## String interpolation

```afr
create name = "World"
say "Hello {name}!"
```

Literal braces: `{{` and `}}`. JSON literals (`"{\"key\": 1}"`) are supported — a `{` followed by `"` is not treated as interpolation.

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

Available stdlib modules: io, json, fs, http, str, log, math, stats, proba, time, re, collections, args, path, async, ui, game2d, game3d, plus **2151 simple** (`std/nom`), **102 medium** (`std/m/nom`), **5710 complex** (`std/c/nom`) — see `docs/STDLIB_*.md`.

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

### Jeux 2D (module `std/ui`)

Primitives pour créer de vrais jeux (rectangles colorés, timing, clavier) :

| Fonction | Description |
|----------|-------------|
| `fillRect(x, y, w, h, r, g, b)` | Rectangle plein (RGB 0–255) |
| `drawRect(x, y, w, h, r, g, b)` | Contour de rectangle |
| `drawTextColor(text, x, y, size, r, g, b)` | Texte coloré |
| `deltaMs()` | Millisecondes depuis la dernière frame |
| `windowWidth()` / `windowHeight()` | Taille de la fenêtre |
| `isKeyDown(key)` / `wasKeyPressed(key)` | Clavier (WASD, flèches, Space, Escape) |
| `mouseX()` / `mouseY()` | Souris (position) |
| `isMouseDown()` / `wasMousePressed()` / `wasMouseClicked()` | Souris (bouton gauche) |
| `fps()` | Images par seconde (moyenne glissante) |

### Moteur 2D (`std/game2d`)

Bibliothèque de jeu haut niveau (grille, timers, entrées, collisions) — bâtie sur `std/ui` :

| Fonction | Description |
|----------|-------------|
| `configureGrid(cols, rows, cellSize, padX, padY)` | Configure une grille logique |
| `gridWindowWidth()` / `gridWindowHeight()` | Taille fenêtre pour la grille |
| `fillCell(col, row, r, g, b)` | Dessine une case |
| `fillBoard` / `drawWalls` / `drawGridLines` | Arrière-plan et murs |
| `fillCircleSolid(x, y, radius, r, g, b)` | Cercle plein (nourriture, effets) |
| `everyMs(name, delta, interval)` | Timer nommé (retourne `yes` quand l’intervalle est écoulé) |
| `updateDirection(curDx, curDy)` + `inputDirX()` / `inputDirY()` | Entrées clavier sans demi-tour |
| `gridHas(xs, ys, count, gx, gy)` | Collision sur grille |
| `pulse01(period)` | Animation sinusoïdale 0–1 |
| `drawCenteredText` / `drawHud` | Interface de jeu |
| `moveIntervalForScore(score, base, min)` | Vitesse progressive |

**Sprites PNG** : `loadSprite(name, path)`, `drawSprite`, `drawSpriteScaled`, `drawSpriteCell`, `hasSprite`

**Spritesheet** : `loadSpriteSheet(name, path, frameW, frameH)`, `drawSpriteFrame`, `drawSpriteFrameCell`, `sheetCols`, `sheetRows`

**Sons** : `loadSound(name, path)`, `playSound`, `playSoundVolume(name, 0-128)`

**Musique** : `loadMusic(name, path)`, `playMusic(name, loops)`, `stopMusic()`, `setMusicVolume(0-128)`

**Caméra** : `setCamera`, `followCamera(x, y, smooth)`, `configureViewport(cols, rows)` pour cartes plus grandes que l’écran

**Triggers** : `defineTrigger(name, x, y, w, h)`, `pointInTrigger(name, wx, wy)`, `mouseInTrigger(name)`

**Sauvegarde** : `saveValue(path, key, value)`, `loadValue(path, key, default)`, `loadHighScore(path)`, `saveHighScore(path)`

**Debug** : `drawFps(x, y)` affiche le FPS à l’écran

`import "std/game2d"` puis `use game2d`. Voir aussi `std/game` (score, niveau, XP) et `std/gamestate` (états menu/jeu/pause).

### États de jeu (`std/gamestate`)

Machine à états simple pour menus, pause et game over :

| Fonction | Description |
|----------|-------------|
| `setState(name)` | Change l’état courant |
| `getState()` / `isState(name)` | Lecture de l’état |
| `stateTimeMs()` | Temps passé dans l’état courant |
| `wasStateChanged()` | `yes` une frame après un changement |
| `tickState(deltaMs)` | À appeler chaque frame dans la boucle |

### Moteur 3D (`std/game3d`)

Jeux 3D avec OpenGL (SDL2 + GL) :

| Fonction | Description |
|----------|-------------|
| `openWindow` / `isOpen` / `beginFrame` / `showFrame` | Boucle 3D |
| `clearScreen(r, g, b)` | Efface l’écran et le tampon de profondeur |
| `setCamera(x, y, z, yaw, pitch)` + `applyCamera()` | Caméra perspective |
| `updateFlyCamera(moveSpeed, turnSpeed)` | Vol libre WASD + QE + flèches |
| `drawCube`, `drawSphere`, `drawPlane`, `drawGrid`, `drawAxis` | Primitives 3D |
| `setSceneRotation` / `applySceneRotation` | Rotation du monde |
| `pickBody(screenX, screenY)` | Picking simple (raycast) → index du corps touché, ou -1 |
| `pickBodyName(screenX, screenY)` | Nom du corps touché, ou texte vide |
| `mouseX()` / `mouseY()` / `isMouseDown()` | Souris en 3D |
| `drawSkyGradient(topR,G,B, botR,G,B)` | Ciel dégradé plein écran |

```bash
./build/afrilang examples/game3d_demo.afr -o game3d_demo --run
```

Contrôles : **WASD** déplacer, **QE** monter/descendre, **flèches** regarder, **Échap** quitter.

**Textures 3D** : `loadTexture3d`, `drawPlaneTextured`, `drawCubeTextured`

**Modèles OBJ** : `loadModel`, `drawModel`, `drawModelColored`

**Physique simple** : `createBody`, `setBodyVelocity`, `stepPhysics(delta, gravity)`, `bodyX/Y/Z`, `applyImpulse`

```bash
./build/afrilang examples/game3d_physics.afr -o game3d_physics --run
```

Espace = lancer une bille supplémentaire.

### 3D avancé (éclairage, brouillard, particules)

| Fonction | Description |
|----------|-------------|
| `enableLighting`, `setAmbientLight`, `setSunLight`, `applyLighting` | Éclairage directionnel |
| `setFog`, `applyFog` | Brouillard atmosphérique |
| `drawModelLit` | Modèle OBJ avec normales et lumière |
| `createBoxBody`, `drawBox`, `drawBody` | Physique et rendu de boîtes |
| `stepPhysicsEx` | Gravité + vent + frottement |
| `setWind`, `setBodyFriction`, `setBodyRestitution` | Paramètres physiques |
| `emitBurst`, `updateParticles`, `drawParticles` | Système de particules |
| `followBody` | Caméra qui suit un corps |

```bash
./build/afrilang examples/game3d_complex.afr -o game3d_complex --run
```

**C** bascule caméra libre / suivi du héros.

### 3D expert (skybox, GLSL, glTF, physique box-box)

| Fonction | Description |
|----------|-------------|
| `loadSkyboxFace(face, path)` | Face du ciel : `px`, `nx`, `py`, `ny`, `pz`, `nz` |
| `hasSkybox()` / `drawSkybox(halfSize)` | Cube ciel texturé centré sur la caméra |
| `loadShader(name, vert, frag)` | Programme GLSL 1.20 |
| `useShader` / `stopShader` | Active / désactive le shader |
| `setShaderFloat` / `setShaderVec3` | Uniformes shader |
| `drawModelShader(shader, model, x,y,z, scale, rotY)` | Modèle OBJ avec shader |
| `loadGltf(name, path)` | Chargeur glTF 2.0 minimal (`.gltf` + buffer embarqué ou `.bin`) |
| `drawGltf` / `drawGltfLit` | Rendu modèle glTF |
| `stepPhysicsEx` | Collisions sphère-sphère, box-box et sphère-box |

```bash
./build/afrilang examples/game3d_advanced.afr -o game3d_advanced --run
```

Clic souris : `pickBodyName` sur les corps physiques.

### glTF binaire, animations, éditeur, réseau

| Fonction | Description |
|----------|-------------|
| `loadGlb(name, path)` | Alias `.glb` (binaire) |
| `gltfAnimCount`, `playGltfAnim`, `updateGltfAnims`, `gltfAnimRotY` | Animations de rotation glTF |
| `setEditMode`, `addLevelGltf`, `addLevelModel`, `drawLevel` | Éditeur de niveau intégré |
| `saveLevel(path)`, `loadLevel(path)` | Format texte `type asset x y z scale rotY` |
| `pickGround(screenX, screenY)` + `pickGroundX/Z` | Clic sur le sol (y=0) |

Module **`std/gamenet`** (UDP) : `hostGame(port)`, `joinGame(host, port)`, `sendPose`, `pollNet`, `remoteX/Y/Z/RotY`

```bash
./build/afrilang examples/game3d_editor.afr -o editor --run   # E éditer, clic placer, S/L sauver/charger
./build/afrilang examples/game3d_net.afr -o net --run         # 2 instances : host + join
```

Exemple minimal :

```afr
import "std/ui"
use ui

openWindow("Jeu", 640, 480)
while isOpen() do
    beginFrame()
    clearBackground(18, 18, 24)
    fillRect(100, 100, 48, 48, 90, 200, 120)
    drawTextColor("Score: 0", 20, 20, 24, 240, 240, 245)
    showFrame()
end
```

Module stdlib équivalent : `import "std/ui"` puis `use ui` (`openWindow`, `drawButton`, etc.).

Compilation : `-lSDL2 -lSDL2_ttf` (SDL2 + SDL2_ttf requis).

## Modules

Import with `import "std/io"` and `use io`.

Available stdlib modules: io, json, fs, http, str, log, math, stats, proba, time, re, collections, args, path, async, ui, game2d, game3d, plus **2151 simple** (`std/nom`), **102 medium** (`std/m/nom`), **5710 complex** (`std/c/nom`) — see `docs/STDLIB_*.md`.

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

## Foreign Function Interface (FFI)

```afr
extern from "m" function sin(x number) returns number
```

Bibliothèques autorisées : `m`, `pthread`, `dl`, `curl`, `c`.

Types FFI : `number` → `double`, `text` → `const char*`, `bool`, `pointer`.

## Identifiants et encodage

- Fichiers source : **UTF-8** obligatoire
- Identifiants : ASCII `[A-Za-z_][A-Za-z0-9_]*` ou **Unicode** (lettres UTF-8)
- Mots réservés : voir section « Syntaxe bilingue »

## Gestion de paquets

```toml
[dependencies]
math = "0.1.0"
```

Commandes : `afrilang pkg add math`, `pkg install`, `pkg list`, `pkg publish`.

Le lockfile `afrilang.lock` fige les versions installées. Semver 2.0 appliqué à l'installation.

## Grammaire (EBNF, extrait)

```ebnf
program     = { declaration | statement } ;
declaration = class_decl | function_decl | enum_decl | module_decl | extern_decl ;
statement   = "say" expression
              | "create" identifier [ type ] "=" expression
              | "if" expression "then" block [ "else" block ] "end"
              | "match" expression match_arm { match_arm } "end" ;
expression  = literal | identifier | call | binary_op | "match" expression ... ;
```

## Politique de compatibilité

- **1.x** : compatibilité source ascendante pour les programmes valides 1.0
- Numéros d'erreur stables (`E3002`, etc.)
- Variable d'environnement `AFRILANG_LOCALE=en|fr` pour les messages
