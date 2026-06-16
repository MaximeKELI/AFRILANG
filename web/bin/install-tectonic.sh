#!/usr/bin/env bash
# Installe Tectonic (moteur LaTeX) dans web/bin/tectonic
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
BIN="$ROOT/bin"
mkdir -p "$BIN"
cd "$BIN"
if [[ -x tectonic ]]; then
  echo "tectonic déjà présent: $BIN/tectonic"
  "$BIN/tectonic" --version
  exit 0
fi
curl -fsSL https://drop-sh.fullyjustified.net | sh -s -- -y
mv -f tectonic "$BIN/tectonic" 2>/dev/null || mv -f ./tectonic "$BIN/tectonic"
chmod +x "$BIN/tectonic"
echo "Installé: $BIN/tectonic"
"$BIN/tectonic" --version
