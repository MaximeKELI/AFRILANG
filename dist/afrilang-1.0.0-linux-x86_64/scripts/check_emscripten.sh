#!/usr/bin/env bash
set -euo pipefail

if command -v em++ >/dev/null 2>&1; then
  echo "Emscripten OK: $(em++ --version | head -1)"
  exit 0
fi

echo "Emscripten (em++) introuvable."
echo "Installation: https://emscripten.org/docs/getting_started/downloads.html"
echo "  git clone https://github.com/emscripten-core/emsdk.git"
echo "  cd emsdk && ./emsdk install latest && ./emsdk activate latest"
echo "  source ./emsdk_env.sh"
exit 1
