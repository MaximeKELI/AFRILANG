# AFRILANG Memory Model 1.0 (product)

> Informative + partially normative companion to `docs/NORMATIVE.md`.  
> **Not** a Rust/Ada-class memory-safety proof. AFRILANG 1.0 transpiles to C++.

## Goals

Reduce **language-surface** undefined behavior for everyday programs:

| Surface | Guarantee |
|---------|-----------|
| List / map index | Bounds / key checked → catchable error (§3 NORMATIVE) |
| Optional unwrap | Empty optional → catchable `optional value is nothing` |
| Result `.value` | Error Result → catchable error (message preserved) |
| Object identity | Instances via `new` → `unique_ptr`; method receivers null-checked (`null object`) |
| Secure compile | Stack protector, FORTIFY, PIE (when host supports) |
| Mid-end | Constant fold + dead-branch / unreachable cleanup before codegen |

## Non-goals (honest)

- No borrow checker, no GC, no proven absence of use-after-free in arbitrary C++.
- FFI (`extern`) and host UB remain the caller’s responsibility.
- Catalog / generated stub modules are experimental and outside this model.

## Ownership rules (language)

1. Values of primitive / text / list / map / optional / Result use C++ value semantics.
2. Class instances are heap-allocated and owned by `std::unique_ptr` in generated code.
3. The language surface **MUST NOT** expose raw C pointers to user programs.
4. Moving / destroying objects follows C++ `unique_ptr` rules after codegen.

## Sanitizers

- CI smoke: `scripts/check_asan_bounds.sh` (AddressSanitizer on conformance bounds).
- Optional local: `AFRILANG_SANITIZE=1` adds `-fsanitize=address,undefined` to host flags
  (requires `AFRILANG_INSECURE=1` at run time because ASan needs large virtual address space).

## FFI trust boundary

`extern` is the intentional **unsafe** escape hatch:

- Opt-in under secure mode (`AFRILANG_ALLOW_FFI=1`)
- Compile-time library allowlist
- `pointer` / `const char*` are raw host types — no AFRILANG bounds/optional guarantees

This mirrors the role of `unsafe` in other languages: **label and quarantine**, not eliminate.
