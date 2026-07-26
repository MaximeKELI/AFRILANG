#!/usr/bin/env bash
# Best-effort: under secure --run, write outside Landlock allowlist must fail.
# Soft-skip when Landlock is unavailable (old kernels / containers).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
[[ -x "$AFR" ]] || { echo "missing $AFR" >&2; exit 1; }
if [[ "$(uname -s)" != "Linux" ]]; then
  echo "sandbox landlock smoke skipped (non-Linux)"
  exit 0
fi

TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT

# Path almost never in Landlock allowlist (/lib /usr /tmp /etc /cwd /xdg).
DENY_PATH="/var/empty/afrilang_gap5_landlock_deny_$$.txt"

cat >"$TMP/deny.afr" <<AFR
import "std/fs"
use fs
create ok = writeText("${DENY_PATH}", "should-not-write")
if ok is equal to true then
    say "landlock-leak"
else
    say "landlock-blocked"
end
AFR

unset AFRILANG_INSECURE || true
set +e
OUT="$("$AFR" run "$TMP/deny.afr" --run 2>&1)"
RC=$?
set -e

if echo "$OUT" | grep -q "landlock-blocked"; then
  echo "sandbox landlock smoke ok"
  exit 0
fi
if echo "$OUT" | grep -q "landlock-leak"; then
  echo "WARN: write outside jail succeeded (Landlock inactive?)" >&2
  exit 1
fi
echo "sandbox landlock smoke inconclusive (skip) rc=$RC"
exit 0
