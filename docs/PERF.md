# Performance & compiler backend (gap #4)

> Honest: Mid-IR + host `g++`/`clang++`. **No LLVM backend.** Numbers vary by machine.

## Pipeline

```
AST → Mid-IR CFG (fold + dead blocks) → AST fold → C++ codegen → g++/clang/em++
```

See [`COMPILER.md`](COMPILER.md). Mid-IR does **literal** folds and identity/annihilator
(`x+0`, `x*1`, `0*x`, …), not full SSA const-prop.

## Host optimization flags

| Variable | Effect |
|----------|--------|
| *(default)* | `-O2` ; catalogue **complex** → `-O1` (mémoire compile) |
| `AFRILANG_OPT_LEVEL=0\|1\|2\|3\|s\|fast` | Override `-O*` |
| `AFRILANG_LTO=1` | Ajoute `-flto` (natif) |
| `AFRILANG_EXTRA_CXXFLAGS=…` | Flags additionnels (ASan, etc.) |

## Decorators

- `@inline` → mot-clé C++ `inline` sur la fonction émise
- `@deprecated` → `[[deprecated]]`

## Benchmarks

```bash
afrilang benchmark              # suite exemples
afrilang benchmark --micro      # hello seulement
afrilang benchmark --json --micro
bash scripts/test_gap_04_perf.sh
```

Sample micro numbers (informational, regenerate on your host):

```bash
./build/afrilang benchmark --json --micro > docs/benchmarks/micro_latest.json
```

Committed sample (not a CI gate): [`benchmarks/micro_sample.json`](benchmarks/micro_sample.json).

## Tests

- Conformance: `tests/conformance/{constant_fold,mid_ir_fold,strength_reduce}.afr`
- Gap: `tests/gaps/perf/{loop_smoke,fold_identity,inline_decorator}.afr`
- Unit: `testConstantFoldPass` / `testNormalizeCrossTarget` in `afrilang_tests`

## Non-goals (this gap)

LLVM IR, JIT, full loop CFG lowering, claims “as fast as Rust”.
