# Industrial gaps vs mature languages

Roadmap of depth gaps (not “missing a compiler”). Test each section with:

```bash
bash scripts/test_gaps.sh           # 1–10 (gap1 métier can be slow)
bash scripts/test_gaps.sh 3         # platform only
AFRILANG_GAPS_QUICK=1 bash scripts/test_gaps.sh
```

| # | Theme | Status focus | Test entry |
|---|--------|--------------|------------|
| 1 | Écosystème de paquets | Métier packages + `pkg` | `scripts/test_gap_01_packages.sh` |
| 2 | Stdlib batteries | Core HTTP/ORM/JSON/CSV | `scripts/test_gap_02_stdlib.sh` |
| 3 | Parité plateformes | Linux primary; Win/macOS host; wasm subset | `scripts/test_gap_03_platform.sh` |
| 4 | Perf & backend | Mid-IR + g++ (pas LLVM) — voir [`PERF.md`](PERF.md) | `scripts/test_gap_04_perf.sh` |

| 5 | Mémoire / sûreté | Bounds + sandbox Linux | `scripts/test_gap_05_safety.sh` |
| 6 | Concurrence | Threads / async surface | `scripts/test_gap_06_concurrency.sh` |
| 7 | Interop | FFI allowlist / C++ transpile | `scripts/test_gap_07_interop.sh` |
| 8 | Tooling IDE | fmt / check / LSP smoke | `scripts/test_gap_08_tooling.sh` |
| 9 | Distribution & cloud | install / release scripts | `scripts/test_gap_09_dist.sh` |
| 10 | Norme & confiance | Docs honesty + PLATFORM | `scripts/test_gap_10_trust.sh` |

See also [`PLATFORM.md`](PLATFORM.md), [`WASM_COMPAT.md`](WASM_COMPAT.md), [`CORE_STDLIB.md`](CORE_STDLIB.md).
