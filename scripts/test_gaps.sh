#!/usr/bin/env bash
# Run industrial gap test suites (1–10). Usage:
#   bash scripts/test_gaps.sh           # all
#   bash scripts/test_gaps.sh 3 4 5     # selected
#   AFRILANG_GAPS_QUICK=1 …             # skip gap1 métier full (slow)
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

ALL=(1 2 3 4 5 6 7 8 9 10)
if [[ $# -gt 0 ]]; then
  ALL=("$@")
fi

pass=0
fail=0
failed=()

run_one() {
  local n="$1"
  local script
  case "$n" in
    1) script=scripts/test_gap_01_packages.sh
       if [[ "${AFRILANG_GAPS_QUICK:-0}" == "1" ]]; then
         echo "=== gap $n (SKIP quick) ==="
         return 0
       fi
       ;;
    2) script=scripts/test_gap_02_stdlib.sh ;;
    3) script=scripts/test_gap_03_platform.sh ;;
    4) script=scripts/test_gap_04_perf.sh ;;
    5) script=scripts/test_gap_05_safety.sh ;;
    6) script=scripts/test_gap_06_concurrency.sh ;;
    7) script=scripts/test_gap_07_interop.sh ;;
    8) script=scripts/test_gap_08_tooling.sh ;;
    9) script=scripts/test_gap_09_dist.sh ;;
    10) script=scripts/test_gap_10_trust.sh ;;
    *) echo "unknown gap: $n" >&2; return 1 ;;
  esac
  echo "=== gap $n ==="
  if bash "$script"; then
    pass=$((pass + 1))
  else
    fail=$((fail + 1))
    failed+=("$n")
  fi
}

for g in "${ALL[@]}"; do
  run_one "$g" || true
done

echo
echo "=== gaps summary ==="
echo "pass=$pass fail=$fail"
if [[ "$fail" -gt 0 ]]; then
  echo "failed gaps: ${failed[*]}"
  exit 1
fi
echo "all selected gap suites OK"
