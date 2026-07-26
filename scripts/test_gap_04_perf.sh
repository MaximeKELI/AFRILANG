#!/usr/bin/env bash
# Gap 4 — extreme perf / Mid-IR / host opt smoke.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
[[ -x "$AFR" ]] || { echo "missing $AFR" >&2; exit 1; }
export ROOT AFR

[[ -f "$ROOT/docs/PERF.md" ]]
[[ -f "$ROOT/docs/benchmarks/micro_sample.json" ]]

for f in loop_smoke fold_identity const_prop inline_decorator loop_hot; do
  "$AFR" "$ROOT/tests/gaps/perf/${f}.afr" --run
done

for f in constant_fold mid_ir_fold strength_reduce; do
  "$AFR" run "$ROOT/tests/conformance/${f}.afr"
done

# Opt / LTO overrides must still compile
AFRILANG_OPT_LEVEL=1 "$AFR" run "$ROOT/examples/hello.afr" >/dev/null
AFRILANG_OPT_LEVEL=2 "$AFR" run "$ROOT/examples/hello.afr" >/dev/null

# @inline → always_inline in generated C++
"$AFR" "$ROOT/tests/gaps/perf/inline_decorator.afr" --emit >/dev/null
rg -q 'always_inline|inline double afr_addOne' "$ROOT/inline_decorator.generated.cpp" \
  || rg -q 'always_inline|inline double afr_addOne' inline_decorator.generated.cpp

# Micro benchmark JSON (extreme suite)
"$AFR" benchmark --json --micro 2>/dev/null >/tmp/afrilang_gap4_micro.json
python3 - <<'PY'
import json
d=json.load(open("/tmp/afrilang_gap4_micro.json"))
assert len(d["results"]) >= 3, d
for r in d["results"]:
    assert "compile_ms" in r and "exec_ms" in r
print(f"  micro files={len(d['results'])} sample={d['results'][0]}")
PY

# Persist latest micro snapshot (informational)
cp /tmp/afrilang_gap4_micro.json "$ROOT/docs/benchmarks/micro_latest.json" 2>/dev/null || true

if [[ -x "$ROOT/build/afrilang_tests" ]]; then
  "$ROOT/build/afrilang_tests" >/dev/null 2>&1
fi
echo "[gap4] ok"
