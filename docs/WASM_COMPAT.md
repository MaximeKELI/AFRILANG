# Compatibilité WASM (wasm32)

AFRILANG peut cibler **wasm32** via Emscripten (`afrilang run fichier.afr --target wasm32`).

## Fonctionne en WASM

| Domaine | Modules / features |
|---------|-------------------|
| Langage de base | variables, fonctions, boucles, `if`, listes, maps |
| POO | classes, héritage, interfaces |
| Stdlib core | `json`, `str`, `math`, `collections`, `args`, `path`, `log` |
| Async | `std/async` — `sleep`, coroutines (Emscripten) |
| Démo CI | `examples/tier8_demo.afr` |

## Natif uniquement (pas WASM)

| Domaine | Raison |
|---------|--------|
| `std/ui`, SDL2 | pas de fenêtre native en navigateur |
| `std/game2d`, `std/game3d` | OpenGL / SDL |
| `std/http` (sync) | sockets système |
| `std/fs`, `std/io` fichiers | accès disque limité en WASM |
| `std/thread` | threads POSIX |
| `std/gamenet` UDP | sockets réseau |
| Packs ultra lourds | compilation/link très longue ; tester en natif |

## Recommandation

- **Playground / CI WASM** : petits programmes sans SDL/OpenGL.
- **Jeux, SIG, data science** : cible `native` ou `linux-arm64`.
- Voir `examples/tier8_demo.afr` pour le smoke test WASM minimal.
