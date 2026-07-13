# Roadmap AFRILANG

Objectif : rapprocher AFRILANG d’un produit langage de type **Nim / Crystal** (haut niveau → natif + écosystème paquets), sans prétendre cloner 15 ans d’adoption d’un coup.

## Vague 1 — Parité écosystème (en cours / livrée)

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

## Vague 2 — Registre distant

- [ ] Téléchargement de paquets (archives) depuis un registre, pas seulement l’index JSON
- [ ] `pkg publish` distant authentifié
- [ ] Résolution transitive multi-niveaux + conflits
- [ ] Site searchable type shards.info / packages.nim-lang.org

## Vague 3 — Profondeur & cibles

- [ ] Qualité du **core stdlib** (voir `CORE_STDLIB.md`) : APIs documentées + tests
- [ ] Réduire la dépendance aux stubs générés pour l’expérience utilisateur
- [ ] WASM / JS : élargir le sous-ensemble (voir `WASM_COMPAT.md`)
- [ ] Batterie de tests compilateur élargie (style Testament / Crystal specs)

## Hors roadmap (non codable ici)

Communauté, libs tierces, adoption — progressent avec Vague 2 + usage réel.
