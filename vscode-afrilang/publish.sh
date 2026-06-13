#!/usr/bin/env bash
# Empaquette et publie l'extension sur VS Code Marketplace + Open VSX.
set -euo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
cd "$ROOT"

VERSION="$(node -p "require('./package.json').version")"
VSIX="afrilang-${VERSION}.vsix"

echo "→ AFRILANG extension v${VERSION}"
npm install --silent

echo "→ Empaquetage..."
npx --yes @vscode/vsce package --out "$VSIX"
echo "✓ $VSIX ($(du -h "$VSIX" | cut -f1))"

publish_vscode() {
  if [[ -z "${VSCE_PAT:-}" ]]; then
    echo "⊘ VS Code Marketplace — VSCE_PAT non défini (voir PUBLISHING.md)"
    return 0
  fi
  echo "→ Publication VS Code Marketplace..."
  npx --yes @vscode/vsce publish -i "$VSIX"
  echo "✓ https://marketplace.visualstudio.com/items?itemName=afrilang.afrilang"
}

publish_openvsx() {
  if [[ -z "${OVSX_PAT:-}" ]]; then
    echo "⊘ Open VSX — OVSX_PAT non défini (voir PUBLISHING.md)"
    return 0
  fi
  echo "→ Publication Open VSX (VSCodium)..."
  npx --yes ovsx publish "$VSIX" -p "$OVSX_PAT"
  echo "✓ https://open-vsx.org/extension/afrilang/afrilang"
}

publish_vscode
publish_openvsx

echo ""
echo "Installation pour les utilisateurs :"
echo "  code --install-extension afrilang.afrilang"
echo "  codium --install-extension afrilang.afrilang"
