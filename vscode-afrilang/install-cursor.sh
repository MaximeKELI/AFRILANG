#!/usr/bin/env bash
# Installe l'extension AFRILANG dans Cursor (méthode fiable par lien symbolique).
set -euo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
VERSION="$(node -p "require('$ROOT/package.json').version")"
EXT_ID="afrilang.afrilang-${VERSION}"
CURSOR_EXT="${HOME}/.cursor/extensions/${EXT_ID}"
BUILD_BIN="${ROOT}/../build/afrilang"

echo "→ Installation AFRILANG v${VERSION} pour Cursor..."
cd "$ROOT"
npm install --silent

# Supprimer les anciennes versions
for old in "${HOME}/.cursor/extensions/afrilang.afrilang-"*; do
  if [[ -e "$old" && "$old" != "$CURSOR_EXT" ]]; then
    echo "  Suppression ancienne version: $(basename "$old")"
    rm -f "$old"
  fi
done

mkdir -p "${HOME}/.cursor/extensions"
ln -sfn "$ROOT" "$CURSOR_EXT"

echo "✓ Extension liée : $CURSOR_EXT"

if [[ -x "$BUILD_BIN" ]]; then
  echo "✓ Compilateur trouvé : $BUILD_BIN"
else
  echo "⚠ Compilateur absent — lancez : cd build && cmake .. && make"
fi

# Config workspace si le dossier AFRILANG est ouvert
VSCODE_DIR="${ROOT}/../.vscode"
mkdir -p "$VSCODE_DIR"
cat > "$VSCODE_DIR/settings.json" << EOF
{
  "afrilang.serverPath": "${BUILD_BIN}",
  "workbench.iconTheme": "afrilang-icons",
  "[afrilang]": { "editor.tabSize": 4 }
}
EOF
echo "✓ Settings workspace : $VSCODE_DIR/settings.json"

echo ""
echo "Dans Cursor :"
echo "  1. Developer: Reload Window"
echo "  2. Output → AFRILANG → doit afficher le chemin du serveur"
echo "  3. AFRILANG: Redémarrer le serveur LSP"
