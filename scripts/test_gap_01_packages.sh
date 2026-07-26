#!/usr/bin/env bash
# Gap 1 — package ecosystem (métier quality + tests).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
bash "$ROOT/scripts/check_metier_quality.sh"
bash "$ROOT/scripts/test_metier_packages.sh"
echo "[gap1] ok"
