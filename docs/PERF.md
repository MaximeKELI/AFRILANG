# Performance & compiler backend (gap #4) — extreme

> Honest: Mid-IR + host `g++`/`clang++`. **No LLVM backend.** Numbers vary by machine.

## Pipeline

```
AST → Mid-IR CFG (fold + per-block const-prop + dead blocks)
    → AST fold (identity / strength-reduce / local const-prop / DCE)
    → C++ codegen → g++/clang/em++
```

See [`COMPILER.md`](COMPILER.md).

### Mid-end capabilities (2026-07 extreme)

| Pass | What it does |
|------|----------------|
| Literal fold | `2+2`, comparisons, string `+` |
| Identity / annihilator | `x+0`, `x*1`, `0*x`, `/1`, bool short-circuit |
| Strength reduce | `x*2` → `x+x`, `x-x` → `0` |
| Local const-prop | `create n=10; create a=n+1` → `a=11` (linear blocks) |
| DCE | pure expr-stmts (littéraux / identifiants seuls) |
| CFG | constant branch → jump; unreachable blocks cleared |

**Not** SSA / full variable const-prop across loops / alias analysis.

## Host optimization flags

| Variable | Effect |
|----------|--------|
| *(default)* | `-O2` ; catalogue **complex** → `-O1` |
| `AFRILANG_OPT_LEVEL=0\|1\|2\|3\|s\|fast` | Override `-O*` |
| `AFRILANG_LTO=1` | `-flto` (natif) |
| `AFRILANG_EXTRA_CXXFLAGS=…` | Flags additionnels |

Le fingerprint de cache inclut `optStamp` (invalidation si ces env changent).

## Decorators

- `@inline` → `[[gnu::always_inline]] inline` (GCC/Clang) / `inline` sinon
- `@deprecated` → `[[deprecated]]`

## Benchmarks

```bash
afrilang benchmark                 # suite exemples
afrilang benchmark --micro         # hello + micros gap4 (fold/loop/const-prop)
afrilang benchmark --json --micro
bash scripts/test_gap_04_perf.sh
```

Samples: [`benchmarks/micro_sample.json`](benchmarks/micro_sample.json) (committed),
`benchmarks/micro_latest.json` (régénéré par le test gap4).

## Tests

- Conformance: `constant_fold`, `mid_ir_fold`, `strength_reduce`
- Gap: `tests/gaps/perf/{loop_smoke,fold_identity,const_prop,inline_decorator,loop_hot}.afr`
- Unit: `testConstantFoldPass`, `testIdentityFoldPass`, `testConstPropPass`

## Non-goals

LLVM IR, JIT, full loop CFG lowering, claims “as fast as Rust”.
