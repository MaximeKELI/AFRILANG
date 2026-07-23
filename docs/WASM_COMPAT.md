# Compatibilité WASM (wasm32)

AFRILANG peut cibler **wasm32** via Emscripten (`afrilang run fichier.afr --target wasm32`).
Plateformes host : voir [`PLATFORM.md`](PLATFORM.md).

## Fonctionne en WASM

| Domaine | Modules / features |
|---------|-------------------|
| Langage de base | variables, fonctions, boucles, `if`, listes, maps, macros (après expansion) |
| Robustesse | pattern matching complet, `or else`, `?.`, `or return`/`or raise`, plages `1..10`/`1..<10` (`runtime/range.hpp`), générateurs, protocole `hasNext`/`next` |
| POO | classes, héritage, interfaces |
| Stdlib core | `json`, `str`, `math`, `stats`, `proba`, `collections`, `args`, `path`, `log`, `re`, `datetime`, `yaml`, `unicode` |
| Async | `std/async` — `sleep`, coroutines (Emscripten) |
| Démos CI | `examples/tier8_demo.afr`, `examples/tier8_stdlib.afr`, `examples/wasm_core_smoke.afr` |
| Conformité WASM (subset) | conformance pack + `tests/stdlib/{str,json,collections,math,stats,path,re}.afr` |

## Natif uniquement (pas WASM)

| Domaine | Raison |
|---------|--------|
| `std/ui`, SDL2 | pas de fenêtre native en navigateur |
| `std/game2d`, `std/game3d` | OpenGL / SDL |
| `std/http` (sync) | sockets système |
| `std/net` | sockets TCP / HTTP / TLS |
| `std/process` | `posix_spawn` / pipes |
| `std/crypto` | OpenSSL natif |
| `std/fs`, `std/io` fichiers | accès disque limité en WASM |
| `std/thread` | threads POSIX |
| `std/gamenet` UDP | sockets réseau |
| Packs ultra lourds | compilation/link très longue ; tester en natif |

## Playground JS (`compile-js`)

Sous-ensemble (Vague 7–8) : `say`, assign/set, `if`/`while`/`repeat`/`for`, **fonctions**,
**list of** + `for each`, **map of** + `at` + `for each key, value`, **macros après expansion**.

Toujours exclus : imports, classes, async, UI, tests, FFI.

CI smoke : `scripts/check_js_playground.sh` (lists + maps).

## Recommandation

- **Playground / CI WASM** : petits programmes sans SDL/OpenGL ; stdlib `str`/`math`/`stats`/`proba`/`json` OK.
- **Jeux, SIG, data science** : cible `native` ou `linux-arm64`.
