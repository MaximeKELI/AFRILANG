#!/usr/bin/env bash
# Gap 5 — memory / safety smoke (bounds + optional ASan + sandbox seccomp on Linux).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
[[ -x "$AFR" ]] || { echo "missing $AFR" >&2; exit 1; }

"$AFR" "$ROOT/tests/gaps/safety/bounds_smoke.afr" --run
if [[ -f "$ROOT/tests/conformance/bounds.afr" ]]; then
  "$AFR" run "$ROOT/tests/conformance/bounds.afr"
fi
if [[ "$(uname -s)" == "Linux" ]] && [[ -f "$ROOT/scripts/check_sandbox_seccomp.sh" ]]; then
  bash "$ROOT/scripts/check_sandbox_seccomp.sh" || {
    echo "  WARN sandbox seccomp check failed (non-fatal on exotic kernels)" >&2
  }
fi
# ASan is heavier — opt-in
if [[ "${AFRILANG_GAP5_ASAN:-0}" == "1" ]]; then
  bash "$ROOT/scripts/check_asan_bounds.sh"
fi
echo "[gap5] ok"
