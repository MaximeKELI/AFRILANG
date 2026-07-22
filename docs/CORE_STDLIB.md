# Core stdlib AFRILANG

La masse de fichiers sous `stdlib/` (catalogues générés) sert surtout à la complétion / signatures IDE.  
**Seuls les modules ci-dessous sont considérés « core »** : backend C++ réel dans `runtime/`, compatibilité 1.x, documentation prioritaire.

Voir aussi `STDLIB_API.md` (API prioritaire Vague 3), `STDLIB_GEN.md`, et `isLegacyStdlibModule` dans `src/utils/stdlib_registry.cpp`.  
Suite de tests : `afrilang test --specs`.

## Modules core (stabilisés)

| Module | Import typique | Domaine |
|--------|----------------|---------|
| io | `std/io` | Entrées / sorties |
| json | `std/json` | JSON |
| fs | `std/fs` | Fichiers |
| http | `std/http` | HTTP sync |
| str | `std/str` | Chaînes |
| log / logging | `std/log` | Journalisation |
| math | `std/math` | Math |
| stats | `std/stats` | Statistiques descriptives |
| proba | `std/proba` | Probabilités / distributions |
| time / chrono | `std/time` | Temps |
| re | `std/re` | Regex |
| collections | `std/collections` | Structures |
| args | `std/args` | CLI args |
| path | `std/path` | Chemins |
| async | `std/async` | Coroutines |
| ui | `std/ui` | Fenêtres (natif) |
| game2d / game3d | `std/game2d` | Jeux |
| env | `std/env` | Environnement |
| random | `std/random` | Aléatoire |
| crypto | `std/crypto` | Hash, HMAC, AES-GCM, CSPRNG |
| process | `std/process` | Spawn, pipes, exit (posix_spawn) |
| net | `std/net` | TCP + HTTP minimal (+ TLS OpenSSL) |
| csv / yaml / html | `std/csv` … | Formats |
| uuid / base64 / hex / url | … | Utilitaires |

## Hors core (expérimental / généré)

- `stdlib/*.afr`, `stdlib/m/`, `stdlib/c/` — stubs de signatures, **pas** une garantie de profondeur API
- Packs « ultra » (GIS, data, …) — utiles en démo ; stabilité au cas par cas

## Politique

1. Bugs et docs prioritaires sur le **core**.
2. Un module généré n’entre dans le core qu’avec runtime réel + tests + entrée ici.
3. Les catalogues générés peuvent évoluer sans promesse semver stricte.
