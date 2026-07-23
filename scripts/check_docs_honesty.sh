#!/usr/bin/env bash
# Fail if docs treat catalog volume as the core stdlib.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
README="$ROOT/README.md"
if grep -E '^\*\*[0-9]+ modules\*\*' "$README" >/dev/null; then
  echo "README honesty: do not lead with raw 'N modules' catalog counts." >&2
  echo "Lead with core runtime modules; demote catalogs as experimental." >&2
  exit 1
fi
if ! grep -qi 'Core' "$README"; then
  echo "README honesty: expected a Core stdlib mention." >&2
  exit 1
fi
# Reject “N modules = core” style claims in stdlib docs.
for f in "$ROOT/docs/STDLIB_API.md" "$ROOT/docs/STDLIB_GEN.md" "$ROOT/docs/CORE_STDLIB.md"; do
  [[ -f "$f" ]] || continue
  if grep -Eiq '[0-9]{3,}[[:space:]]+modules[[:space:]]+(core|runtime)' "$f"; then
    echo "docs honesty: $f must not equate large module counts with core runtime." >&2
    exit 1
  fi
done
# Generator must stamp experimental headers on future regenerations.
if ! grep -q 'experimental catalog' "$ROOT/scripts/gen_catalog_lib.py"; then
  echo "docs honesty: gen_catalog_lib.py must stamp experimental catalog headers." >&2
  exit 1
fi
echo "docs honesty ok"
