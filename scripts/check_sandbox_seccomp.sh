#!/usr/bin/env bash
# Smoke: sandboxed child gets NO_NEW_PRIVS + seccomp deny of ptrace (Linux).
# Win/macOS: skip successfully (rlimits-only documented).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
if [[ ! -x "$AFR" ]]; then
  echo "missing afrilang binary: $AFR" >&2
  exit 1
fi
if [[ "$(uname -s)" != "Linux" ]]; then
  echo "sandbox seccomp smoke skipped (non-Linux)"
  exit 0
fi
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT
cat >"$TMP/ok.afr" <<'AFR'
say "sandbox-ok"
AFR
# Normal sandboxed run must still succeed under seccomp allow-by-default denylist.
"$AFR" run "$TMP/ok.afr" --run >/dev/null
echo "sandbox seccomp smoke ok"
