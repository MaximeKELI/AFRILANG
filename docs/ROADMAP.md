# Roadmap AFRILANG

Objectif : rapprocher AFRILANG d’un produit langage de type **Nim / Crystal** (haut niveau → natif + écosystème paquets), sans prétendre cloner 15 ans d’adoption d’un coup.

## Vague 1 — Parité écosystème (livrée)

Inspiré de [Nimble](https://github.com/nim-lang/nimble) et [Shards](https://github.com/crystal-lang/shards) :

- [x] `pkg init` — scaffold paquet (`manifest.toml`, module, tests, README)
- [x] Deps **git** / **path** dans `afrilang.toml`
- [x] `afrilang.lock` comme source de vérité pour `pkg install`
- [x] `pkg update` — re-résolution + régénération du lock
- [x] Semver `^` / `~`
- [x] `afrilang init` enrichi (`.gitignore`, README, `tests` avec `assert`) + `--lib`
- [x] `afrilang test` découvre `tests/**/*.afr` ; `--examples` pour la suite demos
- [x] Docs : ce roadmap, `PKG.md`, `CORE_STDLIB.md`
- [x] `afrilang doc <dir>` → `docs/api/`

## Vague 2 — Registre distant (livrée)

Modèle [nim-lang/packages](https://github.com/nim-lang/packages) (`url` + `method: git`) :

- [x] Téléchargement de paquets depuis l’index distant si absent du registre local
- [x] `pkg sync` enrichit `list` / `search` / `lookup` via `remote-index.json`
- [x] `pkg publish --remote` — recette `registry-entry.json` + POST si `AFRILANG_REGISTRY_TOKEN`
- [x] Résolution transitive multi-niveaux + détection de conflits de versions
- [x] Index enrichi (`url`, `method`, `tags`, `license`, `web`)
- [x] `pkg test` — boucle auteur (self-vendor + tests/)

## Vague 3 — Profondeur & cibles (livrée)

- [x] Qualité du **core stdlib** : `docs/STDLIB_API.md` + `tests/stdlib/*.afr`
- [x] UX stubs : hover LSP core vs experimental ; site stdlib **core** par défaut (`?experimental=1`)
- [x] WASM / JS : sous-ensemble documenté (`WASM_COMPAT.md`) + `examples/tier8_stdlib.afr` ; playground JS avec fonctions/`for`
- [x] Batterie specs : `afrilang test --specs` (`tests/specs` + `tests/stdlib`)
- [x] Site packages : tags / repo / README / recherche (`sync_packages`, détail paquet)

## Hors roadmap (non codable ici)

Communauté, libs tierces, adoption — progressent avec le registre distant + usage réel.
