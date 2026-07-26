#!/usr/bin/env bash
# Fail if docs treat catalog volume as the core stdlib, or claim ISO certification.
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

# Banned certification / ISO claims (allow negation lines).
BANNED="$ROOT/tests/gaps/trust/banned_phrases.txt"
if [[ -f "$BANNED" ]]; then
  while IFS= read -r phrase || [[ -n "$phrase" ]]; do
    [[ -z "$phrase" || "$phrase" =~ ^# ]] && continue
    hits="$(grep -RniF --include='*.md' -e "$phrase" \
      "$ROOT/README.md" "$ROOT/CHANGELOG.md" "$ROOT/SECURITY.md" "$ROOT/docs" 2>/dev/null || true)"
    if [[ -n "$hits" ]]; then
      bad="$(echo "$hits" | grep -viE \
        'not an iso|pas une|must not|n.est pas|no iso|not.*iso|pas un projet iso|there is no iso|pas .certifié|pas «|pas \"|atténu' || true)"
      if [[ -n "$bad" ]]; then
        echo "docs honesty: banned phrase '$phrase' found:" >&2
        echo "$bad" >&2
        exit 1
      fi
    fi
  done < "$BANNED"
fi

# Large catalog counts in CHANGELOG must stay labeled (simple/moyen/catalog/experimental).
if [[ -f "$ROOT/CHANGELOG.md" ]]; then
  if grep -E '\*\*[0-9]{3,}[[:space:]]+biblioth' "$ROOT/CHANGELOG.md" \
    | grep -viE 'simple|moyenne|moyen|complexe|catalog|experimental|génér' >/dev/null; then
    echo "docs honesty: CHANGELOG large library counts must be labeled catalog/experimental." >&2
    exit 1
  fi
fi

echo "docs honesty ok"
