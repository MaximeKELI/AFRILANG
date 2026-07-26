# Concurrency model (gap #6)

> Honest product doc. AFRILANG is **not** Go/Rust/Java concurrency.
> Transpiles to C++20 coroutines + optional OS threads (`std/thread`, native only).

## Surfaces

| Surface | What it is | Limits |
|---------|------------|--------|
| `async` / `await` | C++20 coroutines (`Task<T>`), `std/async.sleep` | Single-process scheduler; busy-wait drain in `async::run` |
| Async I/O wrappers | `httpGetAsync`, `readFileAsync` via **thread-pool offload** of blocking calls | Not OS async I/O (`io_uring`, etc.) |
| `std/thread` | `spawnSleep` / `join` / `sleepMs`, mutex ids, typed channels | **Native only** (rejected on wasm); no user-lambda spawn yet |
| `spawn` keyword | Lexed | **Not implemented** as a language construct |

## Guarantees (language / stdlib)

1. `await` is only valid in `async function`, top-level/async main wrap, or `test` blocks.
2. `await sleep(ms)` resumes after ≈`ms` via the runtime timer scheduler.
3. Mutex / channel ids are process-local; channels are FIFO and thread-safe.
4. `chanClose` unblocks receivers; empty closed recv → `0` / `""`.
5. Adding a named class instance to a list still **moves** ownership (see `MEMORY_MODEL.md`) — concurrency does not change that.

## Non-goals

- Actor systems, work-stealing rewrite, Go `select`, structured concurrency frameworks
- Data-race / Send-Sync checker
- True non-blocking network stack
- Claiming NORMATIVE conformance for concurrency (fixtures live under gap6 + specs/stdlib)

## Tests

```bash
bash scripts/test_gap_06_concurrency.sh
```

Fixtures: `tests/gaps/concurrency/` · also `tests/specs/async.afr`, `tests/stdlib/thread.afr`.

## Related

- [`LANGUAGE.md`](LANGUAGE.md) — syntax tour (async section)
- [`STDLIB_API.md`](STDLIB_API.md) — `std/thread`, `std/async`
- [`WASM_COMPAT.md`](WASM_COMPAT.md) — `thread` rejected on wasm
- [`GAPS.md`](GAPS.md) — roadmap row 6
