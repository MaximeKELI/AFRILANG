#!/usr/bin/env bash
# Gap 6 — concurrency smoke (thread stdlib when native; sync always).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
[[ -x "$AFR" ]] || { echo "missing $AFR" >&2; exit 1; }

"$AFR" "$ROOT/tests/gaps/concurrency/sync_smoke.afr" --run
if [[ -f "$ROOT/tests/stdlib/thread.afr" ]]; then
  "$AFR" "$ROOT/tests/stdlib/thread.afr" --run
fi
echo "[gap6] ok"
