#!/usr/bin/env bash
# Smoke-run AI / datasci / complex examples + matching unit tests.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
if [[ ! -x "$AFR" ]]; then
  AFR="$(command -v afrilang)"
fi

examples=(
  datasci_demo.afr
  iaultra_demo.afr
  complex_libs_demo.afr
  ai_toolkit_demo.afr
  ml_cosine_demo.afr
  ml_distance_demo.afr
  ml_kmeans_demo.afr
  ml_linear_demo.afr
  ml_naivebayes_demo.afr
  ml_perceptron_demo.afr
  ml_softmax_demo.afr
  nlp_demo.afr
  nlp_jaccard_demo.afr
  nlp_tfidf_demo.afr
  nlp_token_bow_demo.afr
  llmx_chat.afr
)

echo "=== examples (run) via $AFR ==="
fail=0
for f in "${examples[@]}"; do
  echo -n "  examples/$f ... "
  if (cd "$ROOT/examples" && "$AFR" run "$f") >/tmp/afrilang_ex_out.txt 2>&1; then
    echo OK
  else
    echo FAIL
    tail -20 /tmp/afrilang_ex_out.txt || true
    fail=1
  fi
done

echo "=== unit tests tests/examples ==="
for f in "$ROOT"/tests/examples/*.afr; do
  rel="${f#"$ROOT"/}"
  echo -n "  $rel ... "
  if "$AFR" run "$f" >/tmp/afrilang_ex_test.txt 2>&1; then
    echo OK
  else
    echo FAIL
    tail -30 /tmp/afrilang_ex_test.txt || true
    fail=1
  fi
done

exit "$fail"
