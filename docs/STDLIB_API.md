# Core stdlib API (Vague 3)

Documentation prioritaire des backends réels (`runtime/*.hpp`).  
Les catalogues générés (`stdlib/m/`, `stdlib/c/`, stubs massifs) restent expérimentaux.

Voir aussi `CORE_STDLIB.md` et `afrilang test --specs`.

## `std/str`

| Fonction | Rôle |
|----------|------|
| `trim(text)` | Enlève espaces / tabs / newlines |
| `contains(text, needle)` | Sous-chaîne |
| `replace(text, from, to)` | Remplacement global |
| `split(text, sep)` | Découpe en liste |
| `join(parts, sep)` | Jointure |
| `toString(...)` | Conversion |

Tests : `tests/stdlib/str.afr`

## `std/math`

| Fonction | Rôle |
|----------|------|
| `abs(n)` | Valeur absolue |
| `floor(n)` / `ceil(n)` | Entiers autour |
| `pow(base, exp)` | Puissance |
| `random()` | `[0, 1)` |

Tests : `tests/stdlib/math.afr`

## `std/json`

| Fonction | Rôle |
|----------|------|
| `makeObject(key, value)` | Objet simple |
| `parse(text)` / `stringify(doc)` | Sérialisation |
| `getString` / `getNumber` | Lecture |

Tests : `tests/stdlib/json.afr`

## WASM

Compatibles wasm32 (voir `WASM_COMPAT.md`) : `str`, `math`, `json`, `collections`, `path`, `log`, `async` (subset).  
Natif seulement : `fs`/`io` fichiers, `http`, `ui`, `game*`.

Démo : `examples/tier8_stdlib.afr`
