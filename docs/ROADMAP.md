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

## Vague 3 — Profondeur & cibles

- [ ] Qualité du **core stdlib** (voir `CORE_STDLIB.md`) : APIs documentées + tests
- [ ] Réduire la dépendance aux stubs générés pour l’expérience utilisateur
- [ ] WASM / JS : élargir le sous-ensemble (voir `WASM_COMPAT.md`)
- [ ] Batterie de tests compilateur élargie (style Testament / Crystal specs)
- [ ] Site searchable type shards.info (deps graph, versions, README)

## Hors roadmap (non codable ici)

Communauté, libs tierces, adoption — progressent avec le registre distant + usage réel.
