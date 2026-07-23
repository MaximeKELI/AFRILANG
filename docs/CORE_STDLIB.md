# Core stdlib AFRILANG

La masse de fichiers sous `stdlib/` (catalogues générés) sert surtout à la complétion / signatures IDE.  
**Seuls les modules ci-dessous sont considérés « core »** : backend C++ réel dans `runtime/`, compatibilité 1.x, documentation prioritaire.

Voir aussi `STDLIB_API.md` (API prioritaire Vague 3), `STDLIB_GEN.md`, et `isLegacyStdlibModule` dans `src/utils/stdlib_registry.cpp`.  
Suite de tests : `afrilang test --specs`.

## Modules core (stabilisés)

| Module | Import typique | Domaine | Specs |
|--------|----------------|---------|-------|
| io | `std/io` | Entrées / sorties | `tests/stdlib/io.afr` |
| json | `std/json` | JSON | `tests/stdlib/json.afr` |
| fs | `std/fs` | Fichiers | `tests/stdlib/fs.afr` |
| http | `std/http` | HTTP sync | `tests/stdlib/http.afr` (offline reject) |
| str | `std/str` | Chaînes | `tests/stdlib/str.afr` |
| log / logging | `std/log` | Journalisation | `tests/stdlib/log.afr` |
| math | `std/math` | Math | `tests/stdlib/math.afr` |
| stats | `std/stats` | Statistiques descriptives | `tests/stdlib/stats.afr` |
| proba | `std/proba` | Probabilités / distributions | `tests/stdlib/proba.afr` |
| time / chrono | `std/time` | Temps | `tests/stdlib/time.afr` |
| re | `std/re` | Regex | `tests/stdlib/re.afr` |
| collections | `std/collections` | Structures | `tests/stdlib/collections.afr` |
| args | `std/args` | CLI args | `tests/stdlib/args.afr` |
| path | `std/path` | Chemins | `tests/stdlib/path.afr` |
| async | `std/async` | Coroutines | (couvert via demos / suite async) |
| ui | `std/ui` | Fenêtres (natif) | (SDL — hors smoke headless) |
| game2d / game3d | `std/game2d` | Jeux | (SDL — hors smoke headless) |
| env | `std/env` | Environnement | `tests/stdlib/env.afr` |
| random | `std/random` | Aléatoire | `tests/stdlib/random.afr` |
| crypto | `std/crypto` | Hash, HMAC, AES-GCM, CSPRNG | `tests/stdlib/crypto.afr` |
| process | `std/process` | Spawn, pipes, exit (posix_spawn) | `tests/stdlib/process.afr` |
| net | `std/net` | TCP + HTTP minimal (+ TLS OpenSSL) | `tests/stdlib/net.afr` |
| csv | `std/csv` | CSV | `tests/stdlib/csv.afr` |
| yaml / html | `std/yaml` … | Formats | `tests/stdlib/yaml.afr` (+ html via API) |
| uuid / base64 / hex / url | … | Utilitaires | `tests/stdlib/{uuid,base64,hex,url}.afr` |
| unicode | `std/unicode` | UTF-8 | `tests/stdlib/unicode.afr` |

Suite : `./build/afrilang test --specs .` (inclut `tests/stdlib/`).

- `stdlib/*.afr`, `stdlib/m/`, `stdlib/c/` — stubs de signatures, **pas** une garantie de profondeur API
- Un module utilisateur / paquet qui **porte le même nom** qu’une entrée de catalogue n’est **pas** traité comme stdlib (origine `isStdlibInjected`)
- Packs « ultra » (GIS, data, …) — utiles en démo ; stabilité au cas par cas

## Politique

1. Bugs et docs prioritaires sur le **core**.
2. Un module généré n’entre dans le core qu’avec runtime réel + tests + entrée ici.
3. Les catalogues générés peuvent évoluer sans promesse semver stricte.
