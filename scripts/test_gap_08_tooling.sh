#!/usr/bin/env bash
# Gap 8 — tooling IDE / debug smoke.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
bash "$ROOT/scripts/check_tooling_smoke.sh"
echo "[gap8] ok"
