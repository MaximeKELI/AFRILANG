# Conformance suite manifest (AFRILANG 1.0 product)

See `docs/NORMATIVE.md`. This is **not** an ISO certification suite.

## Positive (must run / pass)

| File | Normative clauses | Kind |
|------|-------------------|------|
| `bounds.afr` | §3 Indexing / slices (incl. negative index) | runtime |
| `optional_access.afr` | §4 Optionals | runtime |
| `result_access.afr` | §5 Result | runtime |
| `generics_constraints.afr` | §6 Generics constraints | runtime |
| `exceptions_catch.afr` | §7 Exceptions | runtime |

## Negative (must reject)

| File | Clause | Expectation |
|------|--------|-------------|
| `negative/bad_constraint.afr` | §6 | semantic reject |
| `negative/bad_index_type.afr` | §3 | semantic reject |
| `negative/incomplete_optional_match.afr` | §4 / match | semantic reject |
| `negative/bad_macro_arity.afr` | macros MVP | semantic reject |
| `negative/bad_macro_recursion.afr` | macros MVP | semantic reject |

Harness: `scripts/check_conformance_negative.sh`

Run:

```bash
./build/afrilang test --conformance
bash scripts/check_conformance_negative.sh
```
