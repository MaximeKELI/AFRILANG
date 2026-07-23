#!/usr/bin/env bash
# Smoke: compile-js playground subset | node
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
FIX="$ROOT/tests/js/playground_lists.afr"
if [[ ! -x "$AFR" ]]; then
  echo "missing afrilang: $AFR" >&2
  exit 1
fi
command -v node >/dev/null || { echo "node required" >&2; exit 1; }
out="$("$AFR" compile-js "$FIX")"
echo "$out" | node
echo "js playground smoke ok"
