#!/usr/bin/env bash
# Installe l'extension AFRILANG dans Cursor (méthode fiable par lien symbolique).
set -euo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
VERSION="$(node -p "require('$ROOT/package.json').version")"
EXT_ID="afrilang.afrilang-${VERSION}"
CURSOR_EXT="${HOME}/.cursor/extensions/${EXT_ID}"

echo "→ Installation AFRILANG v${VERSION} pour Cursor..."
cd "$ROOT"
npm install --silent

mkdir -p "${HOME}/.cursor/extensions"
ln -sfn "$ROOT" "$CURSOR_EXT"

echo "✓ Extension liée : $CURSOR_EXT"
echo ""
echo "Prochaines étapes dans Cursor :"
echo "  1. Developer: Reload Window"
echo "  2. (optionnel) File Icon Theme → AFRILANG"
echo "     ou dans settings.json : \"workbench.iconTheme\": \"afrilang-icons\""
