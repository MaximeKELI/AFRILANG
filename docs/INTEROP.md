# Interop / FFI (gap #7)

> Honest product doc. AFRILANG interop is **C declarations + host link flags**,
> not a full C++ ABI / COM / JNI bridge.

## Surfaces

| Surface | What it is | Limits |
|---------|------------|--------|
| `extern from "lib"` | Declares a C function; codegen emits `extern "C"` | No structs, no templates, no member functions |
| Library allowlist | `m`/`libm`, `c`/`libc`, `pthread`, `dl`, `math`, `curl` | Unknown names → semantic error |
| Secure gate | `AFRILANG_ALLOW_FFI=1` **or** `AFRILANG_INSECURE=1` | Default secure mode blocks **all** `extern` |
| Transpile | Whole program → C++17/20 then `g++`/`clang++` | Host toolchain required |

## Example

```bash
AFRILANG_ALLOW_FFI=1 afrilang run examples/ffi.afr
```

```afr
extern from "m" function sqrt(x number) returns number

test "sqrt"
    assert sqrt(16) is equal to 4
end
```

## Trust boundary

Matches [`MEMORY_MODEL.md`](MEMORY_MODEL.md) / [`NORMATIVE.md`](NORMATIVE.md) §9:

- Leaving the language safety contract (bounds/optional/Result do not apply inside the C call)
- `pointer` / `const char*` are raw host types

## Tests

```bash
bash scripts/test_gap_07_interop.sh
```

## Non-goals

- Arbitrary `.so` paths / `dlopen` of user libraries
- C++ name mangling / class layout interop
- WASM FFI (see [`WASM_COMPAT.md`](WASM_COMPAT.md))
- Growing the allowlist aggressively

## Related

- [`LANGUAGE.md`](LANGUAGE.md) — FFI syntax tour
- [`GAPS.md`](GAPS.md) — roadmap row 7
- [`SECURITY.md`](SECURITY.md)
