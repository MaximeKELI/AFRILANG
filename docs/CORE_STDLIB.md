# Core stdlib AFRILANG

La masse de fichiers sous `stdlib/` (catalogues générés : simple / medium / complex) sert
surtout à la **complétion IDE**. Ce n’est **pas** l’équivalent d’une stdlib Python.

**Seuls les modules « core »** (ci-dessous) ont un backend C++ dédié dans `runtime/`,
des tests sous `tests/stdlib/`, et une promesse de stabilité 1.x.

Voir aussi `STDLIB_API.md`, `STDLIB_GEN.md`, et `isLegacyStdlibModule` dans
`src/utils/stdlib_registry.cpp`.

## Core vs kits vs ultras

| Couche | Exemple | Réalité |
|--------|---------|---------|
| **Core** | `std/http`, `std/orm`, `std/json` | Runtime dédié, tests, docs prioritaires |
| **Kits** (`giskit*`, `gamekit*`, …) | `std/giskit042` | Vrais snippets C++ minces — **pas** un framework GIS/jeu |
| **Ultras** (`dbultra*`, `gisultra*`, …) | `std/c/dbultra001` | Clones répétés autour du même noyau — **pas** 500 bases différentes |

Les `.afr` à corps vide = signatures ; le codegen injecte le C++ réel au compile-time.

## Modules core (stabilisés)

| Module | Import | Domaine | Specs |
|--------|--------|---------|-------|
| io | `std/io` | Entrées / sorties | `tests/stdlib/io.afr` |
| json | `std/json` | JSON (+ fichiers) | `tests/stdlib/json.afr` |
| fs | `std/fs` | Fichiers | `tests/stdlib/fs.afr` |
| http | `std/http` | HTTP client (GET/POST/PUT/PATCH/DELETE, status, timeout) | `tests/stdlib/http.afr` |
| csv | `std/csv` | CSV (+ fichiers) | `tests/stdlib/csv.afr` |
| sql | `std/sql` | SQLite query/exec | (via demos + orm) |
| orm | `std/orm` | SQLite ORM-lite | `tests/stdlib/orm.afr` |
| web | `std/web` | Router HTTP démo | `tests/stdlib/web.afr` |
| thread | `std/thread` | Threads / mutex / channels | `tests/stdlib/thread.afr` |
| async | `std/async` | `sleep` (+ Task interne) | demos async |
| str | `std/str` | Chaînes | `tests/stdlib/str.afr` |
| logging | `std/log` | Journalisation | `tests/stdlib/log.afr` |
| math | `std/math` | Math | `tests/stdlib/math.afr` |
| stats | `std/stats` | Stats | `tests/stdlib/stats.afr` |
| proba | `std/proba` | Probabilités | `tests/stdlib/proba.afr` |
| chrono / datetime | `std/chrono`, `std/datetime` | Temps | `tests/stdlib/time.afr` |
| re | `std/re` | Regex | `tests/stdlib/re.afr` |
| collections | `std/collections` | Structures | `tests/stdlib/collections.afr` |
| args / path / env | … | CLI / chemins / env | specs dédiées |
| crypto / process / net | … | Hash, spawn, TCP | specs dédiées |
| yaml / html / uuid / base64 / hex / url / unicode / email / cli / tempfile / random / bigint | … | Utilitaires | specs dédiées |
| ui / game2d / game3d / gamestate / gamenet | … | GUI / jeux (SDL) | hors smoke headless |

Suite : `./build/afrilang test --specs .` (inclut `tests/stdlib/`).

**Sandbox (`afrilang --run`)** : sous Landlock (mode sécurisé), écriture autorisée
sur `/tmp`, le cwd du processus, et `XDG_RUNTIME_DIR` le cas échéant. Réécrire un
fichier existant nécessite `TRUNCATE` (déjà accordé). Hors de ces racines → échec
d’ouverture.

## Batteries — vague 2026-07

Approfondissement **core** (pas de nouveaux kits) :

- **http** : `httpPut` / `httpPatch` / `httpDelete` / `httpMethod`, `httpExchange` + `httpStatusOf` / `httpBodyOf`, `httpGetStatus`, `httpGetTimeout` (timeout socket 30s par défaut)
- **orm** : `createTable` / `dropTable` / `tableExists` / `listTables` / `findWhere` / `updateRows` (+ garde identifiants SQL)
- **csv** : `readText` / `writeText` / `readRows` / `headerRow` / `rowCount`
- **json** : `parseFile` / `writeFile` / `writePretty`

## Politique

1. Bugs et docs prioritaires sur le **core**.
2. Un module généré n’entre dans le core qu’avec runtime réel + tests + entrée ici.
3. Les catalogues générés peuvent évoluer sans promesse semver stricte.
4. IA / ML catalogue : [`STDLIB_AI.md`](STDLIB_AI.md) — **pas** core.
