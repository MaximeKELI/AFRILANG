#!/usr/bin/env bash
# Compile + run bounds conformance under AddressSanitizer.
# Requires a Debug/Release afrilang binary already built.
#
# Note: ASan needs a large virtual address space for its shadow map, so this
# smoke sets AFRILANG_INSECURE=1 to skip rlimits that would break the sanitizer.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
if [[ ! -x "$AFR" ]]; then
  echo "missing afrilang binary: $AFR" >&2
  exit 1
fi
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT
export AFRILANG_INSECURE=1
export AFRILANG_EXTRA_CXXFLAGS="-fsanitize=address -fno-omit-frame-pointer -O1"
# Soften any inherited address-space cap that breaks ASan shadow mapping.
ulimit -v unlimited 2>/dev/null || true
ulimit -d unlimited 2>/dev/null || true
cd "$TMP"
"$AFR" run "$ROOT/tests/conformance/bounds.afr"
echo "asan bounds ok"
