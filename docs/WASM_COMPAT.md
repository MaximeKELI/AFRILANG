# Compatibilité WASM (wasm32)

AFRILANG peut cibler **wasm32** via Emscripten (`afrilang run fichier.afr --target wasm32`).

## Fonctionne en WASM

| Domaine | Modules / features |
|---------|-------------------|
| Langage de base | variables, fonctions, boucles, `if`, listes, maps |
| POO | classes, héritage, interfaces |
| Stdlib core | `json`, `str`, `math`, `stats`, `proba`, `collections`, `args`, `path`, `log`, `re`, `datetime`, `yaml`, `unicode` |
| Async | `std/async` — `sleep`, coroutines (Emscripten) |
| Démos CI | `examples/tier8_demo.afr`, `examples/tier8_stdlib.afr` |

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

Sous-ensemble élargi (Vague 3) : `say`, assign/set, `if`/`while`/`repeat`/`for`, **fonctions** + appels + `return`.  
Toujours exclus : imports, classes, async, UI, tests.

## Recommandation

- **Playground / CI WASM** : petits programmes sans SDL/OpenGL ; stdlib `str`/`math`/`stats`/`proba`/`json` OK.
- **Jeux, SIG, data science** : cible `native` ou `linux-arm64`.
