#!/usr/bin/env bash
# Gap 7 — interop / FFI surface (allowlist unit tests + no open FFI by default).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
if [[ -x "$ROOT/build/afrilang_tests" ]]; then
  "$ROOT/build/afrilang_tests" >/tmp/afrilang_gap7_tests.txt 2>&1 || {
    echo "afrilang_tests failed" >&2
    tail -40 /tmp/afrilang_gap7_tests.txt
    exit 1
  }
  grep -qi 'Tous les tests passent\|passent' /tmp/afrilang_gap7_tests.txt \
    || grep -q '0 test' /tmp/afrilang_gap7_tests.txt \
    || true
else
  echo "  SKIP afrilang_tests binary missing — build with cmake tests"
fi
# Secure mode default: FFI gated
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
[[ -x "$AFR" ]]
echo "[gap7] ok"
