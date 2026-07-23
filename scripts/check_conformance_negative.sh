#!/usr/bin/env bash
# Negative conformance: each .afr under tests/conformance/negative/ MUST fail check/compile.
# Product suite — not ISO certification. See docs/NORMATIVE.md.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
DIR="$ROOT/tests/conformance/negative"
if [[ ! -x "$AFR" ]]; then
  echo "missing afrilang binary: $AFR" >&2
  exit 1
fi
if [[ ! -d "$DIR" ]]; then
  echo "missing $DIR" >&2
  exit 1
fi
failed=0
passed=0
shopt -s nullglob
for f in "$DIR"/*.afr; do
  name="$(basename "$f")"
  if "$AFR" check "$f" >/dev/null 2>&1; then
    echo "FAIL (expected reject): $name"
    failed=$((failed + 1))
  else
    echo "OK (rejected): $name"
    passed=$((passed + 1))
  fi
done
echo "$passed rejected as required, $failed unexpected pass(es)."
[[ "$failed" -eq 0 && "$passed" -gt 0 ]]
