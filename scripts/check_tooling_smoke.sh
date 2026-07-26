#!/usr/bin/env bash
# Tooling smoke (Interaction capability): version, check, fmt, LSP initialize.
# Prefer scripts/test_gap_08_tooling.sh for full fixture contracts.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
if [[ ! -x "$AFR" ]]; then
  echo "missing afrilang: $AFR" >&2
  exit 1
fi
"$AFR" version | grep -qi afrilang
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT
cat >"$TMP/t.afr" <<'AFR'
say "tooling"
AFR
"$AFR" check "$TMP/t.afr" >/dev/null
"$AFR" fmt "$TMP/t.afr" >/dev/null
# Minimal LSP initialize — must advertise capabilities
INIT=$(printf '%s' '{"jsonrpc":"2.0","id":1,"method":"initialize","params":{"capabilities":{},"processId":null,"rootUri":null}}')
HDR=$'Content-Length: '"${#INIT}"$'\r\n\r\n'
RESP=$(printf '%s%s' "$HDR" "$INIT" | timeout 5 "$AFR" lsp 2>/dev/null || true)
echo "$RESP" | grep -q 'capabilities' || {
  echo "lsp smoke: initialize missing capabilities" >&2
  echo "$RESP" >&2
  exit 1
}
echo "tooling smoke ok"
