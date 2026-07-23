# Génération de la bibliothèque standard

La stdlib AFRILANG (~7971 modules) est générée à partir de scripts Python et de catalogues C++.

## Tiers

| Tier | Import | Script | Catalogue |
|------|--------|--------|-----------|
| Simple | `import "std/nom"` | `scripts/gen_simple_stdlib.py` | `src/utils/stdlib_catalog.cpp` (compilé) |
| Medium | `import "std/m/nom"` | `scripts/gen_medium_stdlib.py` | `src/utils/medium_catalog.cpp` (compilé) |
| Complex | `import "std/c/nom"` | `scripts/gen_complex_stdlib.py` | `share/afrilang/catalog/complex.json` (chargé paresseusement) |

> Le tier **complex** (~5710 modules) n'est **plus compilé** dans le binaire : il est
> externalisé en JSON et chargé à la demande par `src/utils/catalog_loader.cpp` (gain
> de taille binaire et de temps de rebuild). Un garde-fou de version (`kComplexCatalogVersion`
> dans `include/afrilang/complex_catalog.hpp` ↔ `CATALOG_JSON_VERSION` dans
> `scripts/gen_catalog_lib.py`) détecte tout décalage binaire/catalogue.
>
> Résolution du chemin : `AFRILANG_CATALOG` → `AFRILANG_HOME/share/...` → arbre source
> (build) → préfixe d'install → relatif à l'exécutable.

## Packs numérotés (500 modules)

- **giskit** — SIG simple (`gen_simple_stdlib.py`)
- **game2dkit**, **game3dkit**, **gamekit** — kits jeu
- **gisultra**, **rasterultra**, **segultra**, **dataultra**, **datasci**, **vizultra**, **iaultra**, **dbultra**, **gameultra**, **game3dultra** — `gen_complex_stdlib.py`

## Workflow après modification

```bash
# Régénérer un tier (exemple : simple)
python3 scripts/gen_simple_stdlib.py

# Recompiler le compilateur
cd build && cmake .. && make -j$(nproc)

# Synchroniser le site Django
cd web && .venv/bin/python manage.py sync_site
```

## Architecture

1. **Stub `.afr`** dans `stdlib/` — signature des fonctions (IDE, docs).
2. **Runtime C++** — `runtime/simple_libs.hpp`, `runtime/medium_libs.hpp`, `runtime/complex_libs.hpp` + headers dédiés (`runtime/hex.hpp`, `runtime/game2d.hpp`, …).
3. **Injection** — `src/utils/stdlib_registry.cpp` résout `import "std/…"` et injecte les modules dans l'AST.

Les modules **legacy** (`io`, `json`, `hex`, `html`, `email`, `game2d`, …) ont un header dédié dans `runtime/` et ne doivent pas être dupliqués dans `simple_libs.hpp`.

## Tests

`afrilang test` compile les exemples de référence + un échantillon par famille ultra (segultra, dataultra, giskit, …).
