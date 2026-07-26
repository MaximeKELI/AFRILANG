#!/usr/bin/env bash
# Gap 2 — stdlib batteries (core HTTP/ORM/JSON/CSV + honesty docs).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
[[ -x "$AFR" ]] || { echo "missing $AFR" >&2; exit 1; }
for t in http orm json csv io; do
  echo "  run tests/stdlib/${t}.afr"
  "$AFR" "$ROOT/tests/stdlib/${t}.afr" --run
done
bash "$ROOT/scripts/check_docs_honesty.sh"
echo "[gap2] ok"
