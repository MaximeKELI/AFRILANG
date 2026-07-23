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
| Object identity | Instances via `new` → `unique_ptr`; no raw `delete` in user code |
| Secure compile | Stack protector, FORTIFY, PIE (when host supports) |

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

## Residual risk

Any AFRILANG program that relies on undefined C++ behavior introduced outside the
checked surfaces above remains unsafe. Treat this document as a **mitigation map**,
not a certification.
