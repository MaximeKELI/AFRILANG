# AFRILANG Normative Specification (product) 1.0

> **Status:** product-normative document for AFRILANG 1.0.  
> **Not** an ISO/IEC language standard. There is no ISO project number for AFRILANG.  
> Conformance means: implementations that claim AFRILANG 1.0 **MUST** satisfy the
> requirements below and pass `afrilang test --conformance`.

Normative keywords: **MUST**, **MUST NOT**, **SHOULD**, **MAY** (RFC 2119 sense).

Companion documents:
- Informative language tour: `docs/LANGUAGE.md`
- Compiler pipeline / honesty: `docs/COMPILER.md`
- Memory model: `docs/MEMORY_MODEL.md`

---

## 1. Abstract machine

1. An AFRILANG program is translated to C++17/20 then linked with a host toolchain.
2. Observable behavior is defined by this document for language-surface constructs.
3. Behavior of host C++ undefined behavior outside the language surface is **out of scope**
   of this product norm (see `MEMORY_MODEL.md`).

---

## 2. Types (core)

| Type | MUST map to |
|------|-------------|
| `number` | IEEE-754 binary64 (`double`) host representation |
| `int` / `entier` | signed 64-bit two’s complement (`std::int64_t`) |
| `text` | UTF-8 byte string (`std::string`); indexing is by byte index if exposed |
| `bool` | boolean |
| `list of T` | ordered sequence; length and index in `[0, length)` |
| `map K to V` | unordered associative map |
| `T?` | optional; either a value of `T` or `nothing` |
| `T or error` | Result; either a value of `T` or an error message (`text`) |

---

## 3. Indexing and slices (Reliability / Safety)

1. Reading `list at i` when `i < 0` or `i >= length` **MUST** throw a catchable error
   whose message **MUST** be exactly `list index out of bounds`.
   (Negative indices **MUST NOT** wrap via unsigned conversion.)
2. Writing `set list at i = …` out of range **MUST** throw the same message.
3. Reading `map at k` when `k` is absent **MUST** throw a catchable error whose message
   **MUST** be exactly `map key not found`.
4. Writing `set map at k = …` **MUST** insert or replace (no throw solely for absence).
5. List slices with negative bounds, `start > end`, or `end > length` **MUST** throw
   `list slice out of bounds`.
6. Codegen **MUST NOT** emit unchecked `operator[]` for language-level list/map indexing.
Conformance: `tests/conformance/bounds.afr`.

---

## 4. Optionals

1. `nothing` **MUST** be representable for every `T?`.
2. `x is defined` **MUST** be true iff `x` is not `nothing`.
3. `x or else y` **MUST** evaluate to the inner value of `x` if defined, otherwise `y`.
4. Reading the inner value of an optional that is `nothing` (implicit unwrap of a defined
   binding required by the type system, or equivalent) **MUST** throw a catchable error
   whose message **MUST** be exactly `optional value is nothing`.
5. Programs **SHOULD** use `is defined`, `or else`, `?.`, or `match` instead of relying on
   throw-on-unwrap.

Conformance: `tests/conformance/optional_access.afr`.

---

## 5. Result (`T or error`)

1. `r is error` **MUST** distinguish error vs success.
2. On success, `r.value` **MUST** yield the inner value.
3. On error, reading `r.value` **MUST** throw a catchable error (message is the Result
   error text when non-empty, otherwise `result is error`).
4. `r or else y` / `or return` / `or raise` **MUST** follow `LANGUAGE.md` semantics.

Conformance: `tests/conformance/result_access.afr`.

---

## 6. Generics constraints

1. `where T is τ1|τ2|…` **MUST** reject instantiations outside the listed type set.
2. `where T implements I` **MUST** reject types that do not implement interface `I`.

Conformance: `tests/conformance/generics_constraints.afr` (+ unit negative tests).

---

## 7. Exceptions

1. `try` / `catch error e` **MUST** catch language-thrown runtime errors listed in §§3–5
   and user `raise` / `or raise` messages as text in `e`.

---

## 8. Conformance suite

1. The directory `tests/conformance/` (positive `.afr`, excluding `negative/`) **MUST** be
   executable via:
   - `afrilang test --conformance`
   - and included in `afrilang test --specs`
2. Negative cases under `tests/conformance/negative/` **MUST** be rejected by
   `afrilang check` (see `scripts/check_conformance_negative.sh`).
3. A claim of “AFRILANG 1.0 conformance (product)” **MUST NOT** be published unless the
   positive suite and negative harness pass on the claimed platform.
4. Passing the suite **MUST NOT** be described as “ISO certified” or “ISO conformant”.

Manifest: `tests/conformance/MANIFEST.md`.

---

## 9. FFI trust boundary (unsafe)

1. `extern from "lib"` **MUST** be treated as leaving the language safety contract.
2. In secure mode, FFI **MUST** require an explicit allow (`AFRILANG_ALLOW_FFI=1`) or
   insecure mode; unknown library names **MUST** be rejected.
3. Types `pointer` / `text`→`const char*` **MUST NOT** be claimed memory-safe by this
   product norm.
4. Implementations **SHOULD** document FFI as an auditable unsafe boundary (see
   `MEMORY_MODEL.md`).
