# Conformance suite manifest (AFRILANG 1.0 product)

See `docs/NORMATIVE.md`. This is **not** an ISO certification suite.

| File | Normative clauses | Kind |
|------|-------------------|------|
| `bounds.afr` | §3 Indexing / slices | runtime |
| `optional_access.afr` | §4 Optionals | runtime |
| `result_access.afr` | §5 Result | runtime |
| `generics_constraints.afr` | §6 Generics constraints | runtime |
| `exceptions_catch.afr` | §7 Exceptions | runtime |

Negative (compile-time) cases for §6 live in `tests/test_compiler.cpp`
(`testGenericConstraintRejectsText`).

Run:

```bash
./build/afrilang test --conformance
# or
./build/afrilang test --specs   # includes this directory
```
