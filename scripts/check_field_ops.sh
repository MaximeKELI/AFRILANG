#!/usr/bin/env bash
# Smoke vertical A+B : paquets moneyx/phonex/geox/storex + tests field_ops.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"

AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"
if [[ ! -x "$AFR" ]]; then
  AFR="$(command -v afrilang || true)"
fi
if [[ -z "${AFR}" || ! -x "$AFR" ]]; then
  echo "afrilang binary introuvable (build/afrilang ou PATH)" >&2
  exit 1
fi

echo "=== pkg test vertical B ==="
for pkg in moneyx phonex geox storex; do
  echo "--- $pkg ---"
  "$AFR" pkg test "$ROOT/packages/$pkg"
done

echo ""
echo "=== field_ops project tests (A+B) ==="
cd "$ROOT/examples/apps/field_ops"
"$AFR" pkg install
mkdir -p build
"$AFR" test

echo ""
echo "=== field_ops run smoke ==="
"$AFR" run src/main.afr >/tmp/field_ops_smoke.out
grep -q "field_ops OK" /tmp/field_ops_smoke.out
grep -q "REJECT:Hors zone" /tmp/field_ops_smoke.out
grep -q "REJECT:Plafond" /tmp/field_ops_smoke.out
echo "field_ops vertical OK"

echo ""
echo "=== deploy smoke (optionnel détaillé) ==="
echo "bash scripts/check_field_ops_deploy.sh"

