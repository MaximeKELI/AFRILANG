#!/usr/bin/env bash
# Gap 5 — memory / safety (bounds, optional, Result, null object, sandbox).
# Mirrors docs/MEMORY_MODEL.md language-surface guarantees (not a borrow checker).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
[[ -x "$AFR" ]] || { echo "missing $AFR" >&2; exit 1; }

[[ -f "$ROOT/docs/MEMORY_MODEL.md" ]]

# Gap fixtures
for f in bounds_smoke null_after_move result_empty optional_smoke; do
  "$AFR" "$ROOT/tests/gaps/safety/${f}.afr" --run
done

# Conformance surfaces named in MEMORY_MODEL
for f in bounds slices optional_access result_access null_receiver; do
  if [[ -f "$ROOT/tests/conformance/${f}.afr" ]]; then
    "$AFR" run "$ROOT/tests/conformance/${f}.afr"
  fi
done

# Linux sandbox: seccomp smoke (+ optional landlock deny write outside jail)
if [[ "$(uname -s)" == "Linux" ]]; then
  if [[ -f "$ROOT/scripts/check_sandbox_seccomp.sh" ]]; then
    bash "$ROOT/scripts/check_sandbox_seccomp.sh" || {
      echo "  WARN sandbox seccomp check failed (non-fatal on exotic kernels)" >&2
    }
  fi
  if [[ -f "$ROOT/scripts/check_sandbox_landlock.sh" ]]; then
    bash "$ROOT/scripts/check_sandbox_landlock.sh" || {
      echo "  WARN sandbox landlock check failed (non-fatal if Landlock unsupported)" >&2
    }
  fi
fi

# ASan: short bounds path when requested; full suite stays CI-owned
if [[ "${AFRILANG_GAP5_ASAN:-0}" == "1" ]]; then
  bash "$ROOT/scripts/check_asan_bounds.sh"
fi

echo "[gap5] ok"
