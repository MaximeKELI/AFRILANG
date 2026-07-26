#!/usr/bin/env bash
# Gap 3 — platform parity smoke (native + optional wasm + target honesty).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
[[ -x "$AFR" ]] || { echo "missing $AFR" >&2; exit 1; }

pass=0
fail=0
ok() { echo "  OK  $1"; pass=$((pass + 1)); }
bad() { echo "  FAIL $1"; fail=$((fail + 1)); }

echo "[gap3] platform"
"$AFR" version | grep -qi afrilang && ok "version" || bad "version"

if "$AFR" run "$ROOT/examples/hello.afr" >/tmp/afrilang_gap3_hello.txt 2>&1; then
  ok "hello native"
else
  bad "hello native"; tail -15 /tmp/afrilang_gap3_hello.txt || true
fi

if "$AFR" run "$ROOT/examples/hello.afr" --target windows >/tmp/afrilang_gap3_win.txt 2>&1; then
  bad "windows target should fail"
else
  if grep -Eqi 'windows|Cibles|PLATFORM' /tmp/afrilang_gap3_win.txt; then
    ok "reject --target windows"
  else
    bad "reject --target windows (message)"
    cat /tmp/afrilang_gap3_win.txt || true
  fi
fi

if "$AFR" run "$ROOT/examples/hello.afr" --target linux-x64 >/tmp/afrilang_gap3_x64.txt 2>&1; then
  ok "linux-x64 alias"
else
  bad "linux-x64 alias"; tail -15 /tmp/afrilang_gap3_x64.txt || true
fi

if "$AFR" "$ROOT/tests/gaps/platform/wasm_reject_http.afr" --target wasm32 --emit \
    >/tmp/afrilang_gap3_wasm_rej.txt 2>&1; then
  bad "wasm should reject http"
else
  if grep -Eqi 'wasm32|WASM_COMPAT|natif|supporté|unsupported' /tmp/afrilang_gap3_wasm_rej.txt; then
    ok "wasm reject http"
  else
    bad "wasm reject http (message)"
    cat /tmp/afrilang_gap3_wasm_rej.txt || true
  fi
fi

if command -v em++ >/dev/null 2>&1 && command -v node >/dev/null 2>&1; then
  if "$AFR" run "$ROOT/tests/gaps/platform/wasm_ok_str.afr" --target wasm32 \
      >/tmp/afrilang_gap3_wasm_ok.txt 2>&1; then
    ok "wasm ok str"
  else
    bad "wasm ok str"; tail -20 /tmp/afrilang_gap3_wasm_ok.txt || true
  fi
  for m in proba datetime yaml unicode; do
    f="$ROOT/tests/stdlib/${m}.afr"
    [[ -f "$f" ]] || continue
    if "$AFR" run "$f" --target wasm32 >/tmp/afrilang_gap3_wasm_${m}.txt 2>&1; then
      ok "wasm stdlib $m"
    else
      bad "wasm stdlib $m"; tail -15 "/tmp/afrilang_gap3_wasm_${m}.txt" || true
    fi
  done
else
  echo "  SKIP wasm run (no em++/node)"
fi

echo "[gap3] pass=$pass fail=$fail"
[[ "$fail" -eq 0 ]]
