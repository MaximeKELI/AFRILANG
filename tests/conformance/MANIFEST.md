# Conformance suite manifest (AFRILANG 1.0 product)

See `docs/NORMATIVE.md`. This is **not** an ISO certification suite.

## Positive (must run / pass)

| File | Normative clauses | Kind |
|------|-------------------|------|
| `bounds.afr` | §3 Indexing / slices (incl. negative index) | runtime |
| `slices.afr` | §3 List slices | runtime |
| `optional_access.afr` | §4 Optionals | runtime |
| `result_access.afr` | §5 Result | runtime |
| `generics_constraints.afr` | §6 Generics constraints | runtime |
| `exceptions_catch.afr` | §7 Exceptions | runtime |
| `finally.afr` | §7 finally | runtime |
| `constant_fold.afr` | Mid-end constant fold / dead branch | runtime |
| `mid_ir_fold.afr` | Mid-IR CFG fold | runtime |
| `null_receiver.afr` | Null-safe method receivers | runtime |
| `records.afr` | Records | runtime |
| `enums_match.afr` | Enums + match | runtime |
| `loops_basic.afr` | for-range / for-each | runtime |
| `functions_basic.afr` | Functions | runtime |
| `text_bool.afr` | Text + bool | runtime |
| `collections_basic.afr` | List / map basics | runtime |
| `class_basic.afr` | Classes | runtime |
| `assert_raise.afr` | assert / raise | runtime |
| `while_repeat.afr` | while / repeat | runtime |
| `macros_smoke.afr` | macros MVP | runtime |
| `strength_reduce.afr` | Mid-IR identity folds | runtime |

## Negative (must reject)

| File | Clause | Expectation |
|------|--------|-------------|
| `negative/bad_constraint.afr` | §6 | semantic reject |
| `negative/bad_constraint_text.afr` | §6 | semantic reject |
| `negative/bad_index_type.afr` | §3 | semantic reject |
| `negative/bad_index_text.afr` | §3 | semantic reject |
| `negative/incomplete_optional_match.afr` | §4 / match | semantic reject |
| `negative/bad_macro_arity.afr` | macros MVP | semantic reject |
| `negative/bad_macro_recursion.afr` | macros MVP | semantic reject |
| `negative/bad_ffi_lib.afr` | §9 FFI | semantic reject |
| `negative/bad_arity.afr` | calls | semantic reject |
| `negative/bad_type_assign.afr` | types | semantic reject |

Harness: `scripts/check_conformance_negative.sh`

Run:

```bash
./build/afrilang test --conformance
bash scripts/check_conformance_negative.sh
bash scripts/check_asan_conformance.sh
```
