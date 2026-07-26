#!/usr/bin/env bash
# Gap 8 — tooling IDE (check / fmt / LSP smoke) with fixture contracts.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
export ROOT AFR
[[ -x "$AFR" ]] || { echo "missing $AFR" >&2; exit 1; }
[[ -f "$ROOT/docs/TOOLING.md" ]]

TOOL="$ROOT/tests/gaps/tooling"
ERR="$(mktemp)"
trap 'rm -f "$ERR"' EXIT

# --- check ---
"$AFR" check "$TOOL/ok_smoke.afr" >/dev/null
set +e
"$AFR" check "$TOOL/bad_semantic.afr" >/dev/null 2>"$ERR"
RC=$?
set -e
[[ "$RC" -ne 0 ]] || { echo "expected check failure on bad_semantic.afr" >&2; exit 1; }
grep -qiE 'missing_variable_xyz|non déclarée|undeclared|E3002' "$ERR" \
  || { echo "check error message missing" >&2; cat "$ERR" >&2; exit 1; }
echo "  check ok/bad ok"

# --- fmt golden + idempotency ---
FMT_OUT="$("$AFR" fmt "$TOOL/fmt_messy.afr")"
diff -u "$TOOL/fmt_golden.afr" <(printf '%s\n' "$FMT_OUT") >/dev/null \
  || { echo "fmt golden mismatch" >&2; diff -u "$TOOL/fmt_golden.afr" <(printf '%s\n' "$FMT_OUT") >&2; exit 1; }
FMT2="$("$AFR" fmt "$TOOL/fmt_golden.afr")"
diff -u "$TOOL/fmt_golden.afr" <(printf '%s\n' "$FMT2") >/dev/null \
  || { echo "fmt not idempotent on golden" >&2; exit 1; }
echo "  fmt golden/idempotent ok"

# --- version ---
"$AFR" version | grep -qi afrilang

# --- LSP initialize must return capabilities ---
INIT=$(printf '%s' '{"jsonrpc":"2.0","id":1,"method":"initialize","params":{"capabilities":{},"processId":null,"rootUri":null}}')
HDR=$'Content-Length: '"${#INIT}"$'\r\n\r\n'
RESP=$(printf '%s%s' "$HDR" "$INIT" | timeout 5 "$AFR" lsp 2>/dev/null || true)
echo "$RESP" | grep -q 'capabilities' \
  || { echo "LSP initialize missing capabilities" >&2; echo "$RESP" >&2; exit 1; }
echo "  lsp initialize ok"

# --- LSP diagnostics + symbols (Python helper) ---
python3 "$ROOT/scripts/gap8_lsp_smoke.py"

# Soft base smoke still available for CI alias
bash "$ROOT/scripts/check_tooling_smoke.sh" >/dev/null

echo "[gap8] ok"
