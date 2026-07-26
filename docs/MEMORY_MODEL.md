# AFRILANG Memory Model 1.0 (product)

> Informative + partially normative companion to `docs/NORMATIVE.md`.  
> **Not** a Rust/Ada-class memory-safety proof. AFRILANG 1.0 transpiles to C++.

## Goals

Reduce **language-surface** undefined behavior for everyday programs:

| Surface | Guarantee |
|---------|-----------|
| List / map index | Bounds / key checked → catchable error (§3 NORMATIVE) |
| List slice | Out-of-range / negative → `list slice out of bounds` |
| Optional unwrap | Empty optional → catchable `optional value is nothing` |
| Result `.value` | Error Result → catchable error (empty message → `result is error`) |
| Object identity | Instances via `new` → `unique_ptr`; method receivers null-checked (`null object`) |
| Ownership move | `add` of a named class instance into a list **moves**; later use → `null object` |
| Secure compile | Stack protector, FORTIFY, PIE (when host supports) |
| Mid-end | Mid-IR CFG (const-prop / simplify-cfg / DCE) + residual AST fold before codegen |

## Non-goals (honest)

- No borrow checker, no GC, no proven absence of use-after-free in arbitrary C++.
- FFI (`extern`) and host UB remain the caller’s responsibility.
- Catalog / generated stub modules are experimental and outside this model.
- Stdlib helpers such as `collections::sliceVec` may **clamp** silently; language `from…to` slices use the checked codegen path above.

## Ownership rules (language)

1. Values of primitive / text / list / map / optional / Result use C++ value semantics.
2. Class instances are heap-allocated and owned by `std::unique_ptr` in generated code.
3. The language surface **MUST NOT** expose raw C pointers to user programs.
4. Moving / destroying objects follows C++ `unique_ptr` rules after codegen.

## Sanitizers

- CI: `scripts/check_asan_conformance.sh` — AddressSanitizer **and** UndefinedBehaviorSanitizer
  on the full positive `--conformance` suite.
- Legacy smoke: `scripts/check_asan_bounds.sh` (bounds only).
- Gap 5 opt-in: `AFRILANG_GAP5_ASAN=1 bash scripts/test_gap_05_safety.sh`
- Optional local: `AFRILANG_SANITIZE=1` adds `-fsanitize=address,undefined` to host flags
  (requires `AFRILANG_INSECURE=1` at run time because ASan needs large virtual address space).
- These proofs are **not** a borrow checker or proven absence of UAF.

## Sandbox (Linux)

- Seccomp deny-list + Landlock FS jail on secure `--run` (best-effort; kernels vary).
- Smokes: `scripts/check_sandbox_seccomp.sh`, `scripts/check_sandbox_landlock.sh`
- Host toolchain compile is **never** Landlocked.

## Gap 5 test entry

```bash
bash scripts/test_gap_05_safety.sh
```

Covers: bounds / slices / optional / Result / null-after-move / null_receiver + Linux sandbox smokes.

## FFI trust boundary

`extern` is the intentional **unsafe** escape hatch:

- Opt-in under secure mode (`AFRILANG_ALLOW_FFI=1`)
- Compile-time library allowlist
- `pointer` / `const char*` are raw host types — no AFRILANG bounds/optional guarantees

This mirrors the role of `unsafe` in other languages: **label and quarantine**, not eliminate.
