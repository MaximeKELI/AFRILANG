#!/usr/bin/env bash
# Smoke deploy field_ops : monobinaire natif + deps dynamiques honnêtes.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
APP="$ROOT/examples/apps/field_ops"
AFR="${AFRILANG_BIN:-$ROOT/build/afrilang}"

if [[ ! -x "$AFR" ]]; then
  AFR="$(command -v afrilang || true)"
fi
if [[ -z "${AFR}" || ! -x "$AFR" ]]; then
  echo "afrilang binary introuvable" >&2
  exit 1
fi

cd "$APP"
"$AFR" pkg install >/dev/null
rm -f build/field_ops
"$AFR" build

BIN="$APP/build/field_ops"
[[ -x "$BIN" ]] || { echo "missing $BIN" >&2; exit 1; }

echo "=== file ==="
file "$BIN"

echo "=== ldd (extrait) ==="
if command -v ldd >/dev/null; then
  ldd "$BIN" | tee /tmp/field_ops_ldd.txt
  grep -q 'libsqlite3' /tmp/field_ops_ldd.txt \
    || { echo "attendu: dépendance libsqlite3 (storex)" >&2; exit 1; }
else
  echo "(ldd indisponible — skip)"
fi

echo "=== run ==="
"$BIN" | tee /tmp/field_ops_deploy_run.txt
grep -q 'field_ops OK' /tmp/field_ops_deploy_run.txt

# Optional arm64 cross when toolchain exists
if command -v aarch64-linux-gnu-g++ >/dev/null 2>&1; then
  echo "=== cross linux-arm64 ==="
  "$AFR" build --target linux-arm64
  file "$BIN" | tee /tmp/field_ops_arm.txt
  grep -qiE 'ARM|aarch64' /tmp/field_ops_arm.txt \
    || { echo "cross arm64: architecture inattendue" >&2; exit 1; }
  echo "cross linux-arm64 OK"
else
  echo "=== cross linux-arm64 === (skip — pas de aarch64-linux-gnu-g++)"
fi

echo "field_ops deploy smoke OK"
echo "Doc: examples/apps/field_ops/DEPLOY.md"
