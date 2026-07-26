#!/usr/bin/env bash
# Gap 10 — norme / confiance (docs product + honesty gates).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
for f in PLATFORM.md WASM_COMPAT.md CORE_STDLIB.md GAPS.md; do
  [[ -f "$ROOT/docs/$f" ]] || { echo "missing docs/$f" >&2; exit 1; }
done
[[ -f "$ROOT/SECURITY.md" ]] || [[ -f "$ROOT/docs/SECURITY.md" ]] || {
  echo "missing SECURITY.md" >&2
  exit 1
}
bash "$ROOT/scripts/check_docs_honesty.sh"
echo "[gap10] ok"
