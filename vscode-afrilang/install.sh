#!/usr/bin/env bash
# Installe l'extension AFRILANG dans VS Code, Cursor et VSCodium (lien symbolique).
set -euo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$ROOT/.." && pwd)"
VERSION="$(node -p "require('$ROOT/package.json').version")"
EXT_ID="afrilang.afrilang-${VERSION}"
BUILD_BIN="${REPO}/build/afrilang"

install_editor() {
  local label="$1"
  local ext_dir="$2"

  if [[ ! -d "$ext_dir" ]]; then
    echo "  ⊘ $label — $ext_dir absent (éditeur non installé ?)"
    return 0
  fi

  for old in "${ext_dir}"/afrilang.afrilang-*; do
    if [[ -e "$old" && "$old" != "${ext_dir}/${EXT_ID}" ]]; then
      echo "  Suppression ancienne version ($label): $(basename "$old")"
      rm -f "$old"
    fi
  done

  ln -sfn "$ROOT" "${ext_dir}/${EXT_ID}"
  echo "  ✓ $label → ${ext_dir}/${EXT_ID}"
}

echo "→ Installation AFRILANG v${VERSION}..."
cd "$ROOT"
npm install --silent

install_editor "Cursor"    "${HOME}/.cursor/extensions"
install_editor "VS Code"   "${HOME}/.vscode/extensions"
install_editor "VSCodium"  "${HOME}/.vscode-oss/extensions"

if [[ -x "$BUILD_BIN" ]]; then
  echo "✓ Compilateur : $BUILD_BIN"
else
  echo "⚠ Compilateur absent — lancez : cd $REPO/build && cmake .. && make"
fi

VSCODE_DIR="${REPO}/.vscode"
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
echo "Dans chaque éditeur (VS Code / Cursor / VSCodium) :"
echo "  1. Ouvrir le dossier $REPO"
echo "  2. Developer: Reload Window"
echo "  3. Preferences → File Icon Theme → AFRILANG (optionnel)"
echo "  4. Output → AFRILANG — vérifier le chemin du serveur"
