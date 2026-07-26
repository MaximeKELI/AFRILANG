#!/usr/bin/env bash
# Gap 7 — interop / FFI (allowlist + secure gate + C transpile smoke).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
[[ -x "$AFR" ]] || { echo "missing $AFR" >&2; exit 1; }
[[ -f "$ROOT/docs/INTEROP.md" ]]

# Positive: allowlisted libm under explicit FFI opt-in
export AFRILANG_ALLOW_FFI=1
"$AFR" "$ROOT/tests/gaps/interop/ffi_math_smoke.afr" --run

# Symbolic compare smoke (language surface used by interop demos too)
"$AFR" "$ROOT/tests/gaps/interop/compare_symbolic.afr" --run

# Specs mirror when present
if [[ -f "$ROOT/tests/specs/ffi.afr" ]]; then
  "$AFR" "$ROOT/tests/specs/ffi.afr" --run
fi

# Negative: unknown library must fail (with FFI enabled — allowlist still applies)
set +e
OUT="$("$AFR" "$ROOT/tests/gaps/interop/ffi_reject_unknown.afr" --run 2>&1)"
RC=$?
set -e
if [[ "$RC" -eq 0 ]]; then
  echo "expected FFI reject for unknown lib" >&2
  echo "$OUT" >&2
  exit 1
fi
echo "$OUT" | grep -qiE 'FFI|autorisée|allowlist|non autor' \
  || echo "$OUT" | grep -qi 'not_a_real_ffi_lib' \
  || { echo "reject message missing:" >&2; echo "$OUT" >&2; exit 1; }
echo "  ffi unknown-lib reject ok"

# Secure gate: without ALLOW_FFI, even libm must fail
unset AFRILANG_ALLOW_FFI
unset AFRILANG_INSECURE || true
set +e
OUT2="$("$AFR" "$ROOT/tests/gaps/interop/ffi_math_smoke.afr" --run 2>&1)"
RC2=$?
set -e
if [[ "$RC2" -eq 0 ]]; then
  echo "expected FFI blocked without AFRILANG_ALLOW_FFI" >&2
  echo "$OUT2" >&2
  exit 1
fi
echo "$OUT2" | grep -qiE 'FFI|ALLOW_FFI|sécurisé|secure' \
  || { echo "secure-gate message missing:" >&2; echo "$OUT2" >&2; exit 1; }
echo "  ffi secure-gate ok"

# Unit allowlist test
if [[ -x "$ROOT/build/afrilang_tests" ]]; then
  "$ROOT/build/afrilang_tests" >/tmp/afrilang_gap7_tests.txt 2>&1 || {
    echo "afrilang_tests failed" >&2
    tail -40 /tmp/afrilang_gap7_tests.txt
    exit 1
  }
fi

echo "[gap7] ok"
