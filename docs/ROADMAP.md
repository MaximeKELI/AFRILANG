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

## Vague 5 — Non-conformités ISO majeures (livrée)

- [x] Indexation liste/map bornée (exceptions message stables)
- [x] Contraintes génériques MVP (`where T is …` / `implements`)
- [x] Suite `tests/conformance/` + inclusion dans `--specs`
- [x] Honesty docs (core vs catalogues) + `check_docs_honesty.sh`
- [x] `docs/COMPILER.md` (pas d’IR ; passes AST extension point)
- [x] Smoke ASan bornes (`scripts/check_asan_bounds.sh` + CI)

## Vague 6 — Non-conformités ISO critiques (mitigation produit)

> Impossible de devenir une norme ISO officielle ou Rust. Mitigation maximale honnête.

- [x] Spec normative produit `docs/NORMATIVE.md` + `docs/MEMORY_MODEL.md`
- [x] Suite conformité élargie + `afrilang test --conformance`
- [x] Unwrap optionnel / Result `.value` → erreurs catchables stables
- [x] `AFRILANG_SANITIZE` + CI conformance
- [x] Indices signés + pas de `operator[]` non vérifié ; harness négatif ; FFI trust boundary
- [x] Re-score audit canvas (critiques atténuées, pas « certifié ISO »)

## Vague 7 — Non-conformités ISO mineures / modérées (mitigation honnête)

> Pas de parité Win/macOS, pas d’IR, pas d’élargissement FFI agressif.

- [x] Macros MVP documentées (EBNF) + négatifs arité/récursion ; JS après expansion
- [x] Catalog stubs : header expérimental dans le générateur + honesty CI élargi
- [x] Playground JS : listes + `for each` + smoke `compile-js | node`
- [x] WASM core smoke (`examples/wasm_core_smoke.afr`) + `PLATFORM.md`
- [x] FFI allowlist unique (`ffi_allowlist.hpp`) + link flags host-aware
- [x] Re-score audit canvas (écarts modérés atténués)

## Vague 8 — Vers ≥18/20 international (mid-end + profondeur)

- [x] Mid-end AST réel : constant fold, dead branches, unreachable cleanup (`src/passes/passes.cpp`)
- [x] Null-check receivers `unique_ptr` (`null object`)
- [x] Playground JS maps + `at` + for-each entries
- [x] Conformité : `constant_fold.afr`, `null_receiver.afr`
- [x] Re-score audit canvas cible ≥18

## Vague 9 — Plafond crédible ~19.0–19.5 (pas 20/20)

- [x] Mid-IR CFG léger (`include/afrilang/ir/`, `src/passes/mid_ir.cpp`) + docs COMPILER
- [x] Linux `NO_NEW_PRIVS` + seccomp-bpf deny-list + `check_sandbox_seccomp.sh`
- [x] Conformité ×3 : 18 positifs + 9 négatifs (MANIFEST ↔ NORMATIVE)
- [x] ASan+UBSan full conformance (`check_asan_conformance.sh`)
- [x] CI secondaire macOS/Windows smoke + pack WASM conformité
- [x] Re-score canvas ~19.2 — **20/20 international non revendiqué**

## Vague 10 — Plafond crédible ~19.5–19.7 (jamais 20)

- [x] Landlock FS Linux (binaires utilisateur ; host `g++` exempt)
- [x] Mid-IR identity / annihilator folds + `strength_reduce.afr`
- [x] Tooling smoke IC (`check_tooling_smoke.sh`)
- [x] Conformité 21+10 ; WASM pack +2
- [x] Re-score canvas ~19.6 — **jamais 20/20**

> **Correction 2026-07-23 (audit adverse) :** le claim Vague 10 (~19.6) n’est **pas**
> défendable vs C++/Rust/Go. Score officiel international recalibré à **~16.6/20**
> (voir canvas `audit-iso-rigoureux`). Les livrables Vague 8–10 restent valides comme
> mitigations produit ; seuls les points auto-attribués sont corrigés.

