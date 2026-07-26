#!/usr/bin/env bash
# Gap 10 — norme / confiance (docs product + honesty + consistency).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
[[ -f "$ROOT/docs/TRUST.md" ]]

# Required docs list
REQ="$ROOT/tests/gaps/trust/required_docs.txt"
[[ -f "$REQ" ]]
while IFS= read -r f || [[ -n "$f" ]]; do
  [[ -z "$f" || "$f" =~ ^# ]] && continue
  [[ -f "$ROOT/docs/$f" ]] || { echo "missing docs/$f" >&2; exit 1; }
done < "$REQ"
echo "  required docs ok"

[[ -f "$ROOT/SECURITY.md" ]] || [[ -f "$ROOT/docs/SECURITY.md" ]] || {
  echo "missing SECURITY.md" >&2
  exit 1
}

# Honesty gates (catalog vs core, banned ISO claims)
bash "$ROOT/scripts/check_docs_honesty.sh"

# NORMATIVE must deny ISO certification wording
grep -qiE 'Not.*ISO|pas.*ISO|no ISO project' "$ROOT/docs/NORMATIVE.md" \
  || { echo "NORMATIVE.md must explicitly deny ISO status" >&2; exit 1; }
echo "  normative iso-denial ok"

# PLATFORM platforms ⊆ release.yml (same expected set as gap9)
EXPECTED="$ROOT/tests/gaps/dist/platforms.expected"
while read -r plat; do
  [[ -n "$plat" ]] || continue
  grep -qi "$plat" "$ROOT/docs/PLATFORM.md" \
    || { echo "PLATFORM.md missing $plat" >&2; exit 1; }
  grep -q "platform: $plat" "$ROOT/.github/workflows/release.yml" \
    || { echo "release.yml missing platform: $plat" >&2; exit 1; }
done < "$EXPECTED"
echo "  platform↔release ok"

# Conformance MANIFEST files exist
MANIFEST="$ROOT/tests/conformance/MANIFEST.md"
[[ -f "$MANIFEST" ]]
missing=0
while read -r rel; do
  [[ -z "$rel" ]] && continue
  if [[ ! -f "$ROOT/tests/conformance/$rel" ]]; then
    echo "MANIFEST missing file: tests/conformance/$rel" >&2
    missing=1
  fi
done < <(grep -oE '`[a-zA-Z0-9_./-]+\.afr`' "$MANIFEST" | tr -d '`' | sort -u)
[[ "$missing" -eq 0 ]] || exit 1
echo "  conformance manifest ok"

echo "[gap10] ok"
