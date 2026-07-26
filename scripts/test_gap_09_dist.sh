#!/usr/bin/env bash
# Gap 9 — distribution / packaging smoke (scripts present + platform tags).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
[[ -f "$ROOT/install.sh" ]]
[[ -f "$ROOT/scripts/package-release.sh" ]]
[[ -f "$ROOT/.github/workflows/release.yml" ]]
grep -q 'detect_platform' "$ROOT/install.sh"
grep -Eq 'linux-x86_64|macos-arm64|windows-x86_64' "$ROOT/scripts/package-release.sh" \
  || grep -Eq 'linux-x86_64|macos-arm64|windows-x86_64' "$ROOT/.github/workflows/release.yml"
# package-release without version must fail with Usage
set +e
out="$(bash "$ROOT/scripts/package-release.sh" 2>&1)"
code=$?
set -e
[[ "$code" -ne 0 ]]
echo "$out" | grep -qi 'Usage'
echo "[gap9] ok"
