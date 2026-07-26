#!/usr/bin/env bash
# Gap 4 — perf / compiler backend smoke (no LLVM claim; Mid-IR + g++ path).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
[[ -x "$AFR" ]] || { echo "missing $AFR" >&2; exit 1; }
export ROOT AFR

"$AFR" "$ROOT/tests/gaps/perf/loop_smoke.afr" --run
ms="$(python3 - <<'PY'
import time, subprocess, os
root = os.environ["ROOT"]
afr = os.environ["AFR"]
t0 = time.time()
subprocess.run([afr, "run", f"{root}/examples/hello.afr"], check=True,
               stdout=subprocess.DEVNULL, stderr=subprocess.DEVNULL)
print(int((time.time() - t0) * 1000))
PY
)"
echo "  hello wall_clock_ms=${ms}"
if [[ -x "$ROOT/build/afrilang_tests" ]]; then
  "$ROOT/build/afrilang_tests" >/dev/null
fi
echo "[gap4] ok"
