# Performance & compiler backend (gap #4) — max

> Honest: Mid-IR + host `g++`/`clang++`. **No LLVM backend.** Numbers vary by machine.

## Pipeline

```
AST → Mid-IR CFG (fold + per-block const-prop + dead blocks)
    → AST fold (identity / strength-reduce / local const-prop / DCE / flatten)
    → C++ codegen → g++/clang/em++
```

See [`COMPILER.md`](COMPILER.md).

### Mid-end capabilities (2026-07 max)

| Pass | What it does |
|------|----------------|
| Literal fold | `2+2`, comparisons, string `+` |
| Identity / annihilator | `x+0`, `x*1`, `0*x`, `/1`, `0-x→-x`, bool short-circuit |
| Strength reduce | `x*2/4/8` (both sides), `x-x→0` |
| Boolean | `not not`, `-(-x)`, `x==true`, `x&&x` / `x\|\|x` |
| Local const-prop | `create n=10; create a=n+1` → `a=11` (linear blocks) |
| CFG / flatten | constant branch; `if(true)` inlined; `while(false)` dropped |
| DCE | pure expr-stmts (littéraux / identifiants seuls) |

**Codegen:** `repeat`/`for` integer → `int64_t`; unroll `repeat` ≤8; flatten nested text `+`; skip redundant `toString` on text; `const T&` params for unmutated text/list/map; `@inline` → `always_inline` + `noexcept`.

**Not** SSA / full variable const-prop across loops / alias analysis.

## Host optimization flags

| Variable | Effect |
|----------|--------|
| *(default)* | `-O3` ; catalogue **complex** → `-O1` |
| `AFRILANG_OPT_LEVEL=0\|1\|2\|3\|s\|fast` | Override `-O*` |
| `AFRILANG_LTO=1` | `-flto` (natif) |
| `AFRILANG_MARCH=native` | `-march=…` (natif) |
| `AFRILANG_GC_SECTIONS=0` | Désactive `-ffunction-sections` / `-Wl,--gc-sections` (défaut: on) |
| `AFRILANG_EXTRA_CXXFLAGS=…` | Flags additionnels |

Le fingerprint de cache inclut `optStamp` (invalidation si ces env changent).

## Decorators

- `@inline` → `[[gnu::always_inline]] inline` + `noexcept` (fonctions libres)
- `@deprecated` → `[[deprecated]]`

## Runtime

- `str::concat` / `join` pré-réservent
- `toString(const string&)` → `const string&` (pas de copie)
- `mapText` / `filterText` / `flatMapText` prennent `const string&`
- `optionalRequire(const optional&)` → `const T&`

## Benchmarks

```bash
afrilang benchmark                 # suite exemples
afrilang benchmark --micro         # hello + micros gap4
afrilang benchmark --json --micro
bash scripts/test_gap_04_perf.sh
```

Samples: [`benchmarks/micro_sample.json`](benchmarks/micro_sample.json) (committed),
`benchmarks/micro_latest.json` (régénéré par le test gap4).

## Tests

- Conformance: `constant_fold`, `mid_ir_fold`, `strength_reduce`
- Gap: `tests/gaps/perf/{loop_smoke,fold_identity,const_prop,inline_decorator,loop_hot,unroll_small}.afr`
- Unit: `testConstantFoldPass`, `testIdentityFoldPass`, `testConstPropPass`, `testStrengthReduceMul`

## Non-goals

LLVM IR, JIT, full loop CFG lowering, claims “as fast as Rust”.
