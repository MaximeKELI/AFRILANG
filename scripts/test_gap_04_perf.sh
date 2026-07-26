#!/usr/bin/env bash
# Gap 4 — perf / compiler backend smoke.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
[[ -x "$AFR" ]] || { echo "missing $AFR" >&2; exit 1; }
export ROOT AFR

[[ -f "$ROOT/docs/PERF.md" ]]

"$AFR" "$ROOT/tests/gaps/perf/loop_smoke.afr" --run
"$AFR" "$ROOT/tests/gaps/perf/fold_identity.afr" --run
"$AFR" "$ROOT/tests/gaps/perf/inline_decorator.afr" --run

for f in constant_fold mid_ir_fold strength_reduce; do
  "$AFR" run "$ROOT/tests/conformance/${f}.afr"
done

# Opt-level override must still compile
AFRILANG_OPT_LEVEL=1 "$AFR" run "$ROOT/examples/hello.afr" >/dev/null

# Micro benchmark JSON
"$AFR" benchmark --json --micro >/tmp/afrilang_gap4_micro.json
python3 - <<'PY'
import json
d=json.load(open("/tmp/afrilang_gap4_micro.json"))
assert "results" in d and len(d["results"]) >= 1
r=d["results"][0]
assert "compile_ms" in r and "exec_ms" in r
print(f"  micro {r.get('file', r.get('name', '?'))}: compile={r['compile_ms']}ms exec={r['exec_ms']}ms")
PY

if [[ -x "$ROOT/build/afrilang_tests" ]]; then
  "$ROOT/build/afrilang_tests" >/dev/null
fi
echo "[gap4] ok"
