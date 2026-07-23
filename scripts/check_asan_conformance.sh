#!/usr/bin/env bash
# Compile + run all positive conformance files under ASan+UBSan.
# Not a borrow-checker proof — see docs/MEMORY_MODEL.md.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
DIR="$ROOT/tests/conformance"
if [[ ! -x "$AFR" ]]; then
  echo "missing afrilang binary: $AFR" >&2
  exit 1
fi
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT
export AFRILANG_INSECURE=1
export AFRILANG_EXTRA_CXXFLAGS="-fsanitize=address,undefined -fno-omit-frame-pointer -O1"
export ASAN_OPTIONS="${ASAN_OPTIONS:-detect_leaks=0:abort_on_error=1}"
export UBSAN_OPTIONS="${UBSAN_OPTIONS:-halt_on_error=1}"
ulimit -v unlimited 2>/dev/null || true
ulimit -d unlimited 2>/dev/null || true
cd "$TMP"
shopt -s nullglob
n=0
for f in "$DIR"/*.afr; do
  name="$(basename "$f" .afr)"
  echo "asan+ubsan: $name"
  "$AFR" run "$f" --run
  n=$((n + 1))
done
[[ "$n" -gt 0 ]]
echo "asan conformance ok ($n files)"
