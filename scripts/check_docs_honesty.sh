#!/usr/bin/env bash
# Fail if README leads with raw catalog counts as if they were the core stdlib.
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
echo "docs honesty ok"
