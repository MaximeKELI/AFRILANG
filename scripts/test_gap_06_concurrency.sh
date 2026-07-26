#!/usr/bin/env bash
# Gap 6 — concurrency (async coroutines + native thread/mutex/channel).
# See docs/CONCURRENCY.md — not Go/Rust-level; honest surface tests only.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
[[ -x "$AFR" ]] || { echo "missing $AFR" >&2; exit 1; }

[[ -f "$ROOT/docs/CONCURRENCY.md" ]]

# Async surface (coroutines + sleep)
for f in async_sleep_smoke async_result sync_smoke; do
  "$AFR" "$ROOT/tests/gaps/concurrency/${f}.afr" --run
done

# Specs mirror (stable suite entry)
if [[ -f "$ROOT/tests/specs/async.afr" ]]; then
  "$AFR" "$ROOT/tests/specs/async.afr" --run
fi

# Native thread stdlib (skipped conceptually on wasm; gap harness is native)
if [[ -f "$ROOT/tests/gaps/concurrency/thread_spawn_join.afr" ]]; then
  "$AFR" "$ROOT/tests/gaps/concurrency/thread_spawn_join.afr" --run
fi
if [[ -f "$ROOT/tests/stdlib/thread.afr" ]]; then
  "$AFR" "$ROOT/tests/stdlib/thread.afr" --run
fi

echo "[gap6] ok"
