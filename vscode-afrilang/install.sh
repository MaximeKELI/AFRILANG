#!/usr/bin/env bash
# Installe l'extension AFRILANG dans VS Code, Cursor et VSCodium (copie réelle).
set -euo pipefail

ROOT="$(cd "$(dirname "$0")" && pwd)"
REPO="$(cd "$ROOT/.." && pwd)"
VERSION="$(node -p "require('$ROOT/package.json').version")"
EXT_ID="afrilang.afrilang-${VERSION}"
BUILD_BIN="${REPO}/build/afrilang"

install_editor() {
  local label="$1"
  local ext_dir="$2"
  local dest="${ext_dir}/${EXT_ID}"

  if [[ ! -d "$ext_dir" ]]; then
    echo "  ⊘ $label — $ext_dir absent (éditeur non installé ?)"
    return 0
  fi

  for old in "${ext_dir}"/afrilang.afrilang-*; do
    if [[ -e "$old" || -L "$old" ]]; then
      echo "  Suppression ancienne version ($label): $(basename "$old")"
      rm -rf "$old"
    fi
  done

  mkdir -p "$dest"
  if command -v rsync >/dev/null 2>&1; then
    rsync -a --delete \
      --exclude node_modules \
      --exclude '*.vsix' \
      --exclude .git \
      --exclude hello \
      --exclude '*.generated.cpp' \
      "$ROOT/" "$dest/"
  else
    cp -a "$ROOT"/. "$dest/"
    rm -rf "$dest/node_modules" "$dest"/*.vsix 2>/dev/null || true
  fi

  (cd "$dest" && npm install --omit=dev --silent)

  # Enregistrement minimal dans extensions.json (Cursor / VS Code)
  local catalog="${ext_dir}/extensions.json"
  if [[ -f "$catalog" ]] || [[ -d "$ext_dir" ]]; then
    node -e "
const fs = require('fs');
const path = ${JSON.stringify(catalog)};
const id = 'afrilang.afrilang';
const version = ${JSON.stringify(VERSION)};
const rel = ${JSON.stringify(EXT_ID)};
const abs = ${JSON.stringify('${dest}')};
let data = [];
try { data = JSON.parse(fs.readFileSync(path, 'utf8')); } catch (_) {}
if (!Array.isArray(data)) data = [];
const entry = {
  identifier: { id },
  version,
  location: { \$mid: 1, fsPath: abs, external: 'file://' + abs, path: abs, scheme: 'file' },
  relativeLocation: rel,
  metadata: {
    isApplicationScoped: false,
    isMachineScoped: false,
    isBuiltin: false,
    installedTimestamp: Date.now(),
    pinned: true,
    source: 'vsix'
  }
};
const out = data.filter(e => e?.identifier?.id !== id);
out.push(entry);
fs.writeFileSync(path, JSON.stringify(out));
"
  fi

  echo "  ✓ $label → ${dest}"
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
for settings_dir in "${VSCODE_DIR}" "${REPO}/.cursor"; do
  mkdir -p "$settings_dir"
  cat > "$settings_dir/settings.json" << EOF
{
  "afrilang.serverPath": "${BUILD_BIN}",
  "workbench.iconTheme": "afrilang-icons",
  "files.associations": { "*.afr": "afrilang" },
  "[afrilang]": { "editor.tabSize": 4 }
}
EOF
  echo "✓ Settings : $settings_dir/settings.json"
done

echo ""
echo "Dans chaque éditeur (VS Code / Cursor / VSCodium) :"
echo "  1. Ouvrir le dossier $REPO"
echo "  2. Developer: Reload Window"
echo "  3. Barre d'état (bas à droite) = AFRILANG (pas Plain Text)"
echo "  4. Thème d'icônes = AFRILANG (File Icon Theme)"
echo "  5. Output → AFRILANG — vérifier le chemin du serveur"
echo ""
echo "Note Cursor Glass / Agents Window :"
echo "  La coloration TextMate y est souvent absente (limite Cursor)."
echo "  Ouvrez le fichier dans l'éditeur classique (IDE) pour couleurs + logo."
