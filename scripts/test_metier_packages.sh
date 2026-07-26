#!/usr/bin/env bash
# Run unit + smoke tests for all métier packages listed in packages/metier.json.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

AFRILANG_BIN="${AFRILANG_BIN:-$ROOT/build/afrilang}"
if [[ ! -x "$AFRILANG_BIN" ]]; then
  echo "error: afrilang binary not found at $AFRILANG_BIN (build first)" >&2
  exit 2
fi

mapfile -t PKGS < <(python3 - <<'PY'
import json
from pathlib import Path
print("\n".join(json.loads(Path("packages/metier.json").read_text())))
PY
)

pass_n=0
fail_n=0
skip_n=0
failed=()

run_one() {
  local pkg="$1"
  local file="$2"
  local label="$3"
  if [[ ! -f "$file" ]]; then
    echo "  SKIP $label (missing)"
    skip_n=$((skip_n + 1))
    return 0
  fi
  local out
  if out=$("$AFRILANG_BIN" "$file" --run 2>&1); then
    if echo "$out" | grep -q "Fin (code: 0)"; then
      echo "  OK   $label"
      pass_n=$((pass_n + 1))
      return 0
    fi
  fi
  echo "  FAIL $label"
  echo "$out" | tail -20 | sed 's/^/       /'
  fail_n=$((fail_n + 1))
  failed+=("$pkg/$label")
  return 1
}

echo "=== AFRILANG métier package tests (${#PKGS[@]} packages) ==="
echo "binary: $AFRILANG_BIN"
echo

set +e
for pkg in "${PKGS[@]}"; do
  echo "[$pkg]"
  run_one "$pkg" "packages/$pkg/tests/smoke.afr" "smoke"
  run_one "$pkg" "packages/$pkg/tests/unit.afr" "unit"
  echo
done
set -e

echo "=== Summary ==="
echo "pass=$pass_n fail=$fail_n skip=$skip_n"
if (( fail_n > 0 )); then
  echo "failed:"
  for f in "${failed[@]}"; do
    echo " - $f"
  done
  exit 1
fi
echo "all métier tests OK"
