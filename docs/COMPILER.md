# Architecture du compilateur AFRILANG

## Pipeline

```
.afr → Lexer → Parser → AST → SemanticAnalyzer → (passes AST optionnelles)
                                              → CodeGenerator → C++17/20
                                                              ↓
                                                         g++ / clang++ / em++
                                                              ↓
                                                         exécutable (+ sandbox)
```

Il n’existe **pas** d’IR AFRILANG (SSA / CFG / pass manager) aujourd’hui.
Les optimisations de performance viennent du **compilateur hôte** (`-O2` par défaut,
`-O0` si un module catalogue complexe est lié).

Point d’extension : `include/afrilang/passes.hpp` (`runOptionalPasses`) — vide pour
l’instant, volontairement, pour accueillir de futures passes AST sans prétendre à
un backend LLVM.

## Sûreté d’indexation

Depuis la vague ISO-majeurs :

- lecture liste hors bornes → `std::out_of_range("list index out of bounds")`
- lecture map clé absente → `std::out_of_range("map key not found")`
- écriture liste hors bornes → même message liste
- slices → vérification `start/end/size` (`list slice out of bounds`)

La sûreté mémoire globale reste celle du C++ généré (pas de borrow checker).
Smoke CI optionnel : `scripts/check_asan_bounds.sh` (`AFRILANG_EXTRA_CXXFLAGS`).

## Conformité

- Specs feature : `tests/specs/`, `tests/stdlib/`
- Conformité bornes / contraintes : `tests/conformance/`
- Ce n’est **pas** une suite de conformité ISO officielle de langage.

## Catalogue vs core

Voir `docs/CORE_STDLIB.md`. Les ~7971 entrées catalogue sont des **signatures
expérimentales IDE**, pas l’API core 1.x.
