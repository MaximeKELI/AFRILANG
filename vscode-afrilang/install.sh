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
    CATALOG="$catalog" EXT_VERSION="$VERSION" EXT_REL="$EXT_ID" EXT_ABS="$dest" node <<'NODE'
const fs = require('fs');
const path = process.env.CATALOG;
const id = 'afrilang.afrilang';
const version = process.env.EXT_VERSION;
const rel = process.env.EXT_REL;
const abs = process.env.EXT_ABS;
let data = [];
try { data = JSON.parse(fs.readFileSync(path, 'utf8')); } catch (_) {}
if (!Array.isArray(data)) data = [];
const entry = {
  identifier: { id },
  version,
  location: { $mid: 1, fsPath: abs, external: 'file://' + abs, path: abs, scheme: 'file' },
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
const out = data.filter(e => e && e.identifier && e.identifier.id !== id);
out.push(entry);
fs.writeFileSync(path, JSON.stringify(out));
NODE
  fi

  echo "  ✓ $label → ${dest}"
}

echo "→ Installation AFRILANG v${VERSION}..."
cd "$ROOT"
npm install --silent

# Préférer l'install officielle via CLI (enregistre correctement l'extension)
VSIX="${ROOT}/afrilang-${VERSION}.vsix"
if command -v zip >/dev/null 2>&1; then
  TMP="$(mktemp -d)"
  mkdir -p "${TMP}/extension"
  if command -v rsync >/dev/null 2>&1; then
    rsync -a --exclude node_modules --exclude '*.vsix' --exclude .git "$ROOT/" "${TMP}/extension/"
  else
    cp -a "$ROOT"/. "${TMP}/extension/"
    rm -rf "${TMP}/extension/node_modules" "${TMP}/extension"/*.vsix 2>/dev/null || true
  fi
  cp -a "$ROOT/node_modules" "${TMP}/extension/" 2>/dev/null || true
  cat > "${TMP}/[Content_Types].xml" <<'EOF'
<?xml version="1.0" encoding="utf-8"?>
<Types xmlns="http://schemas.openxmlformats.org/package/2006/content-types">
  <Default Extension=".json" ContentType="application/json"/>
  <Default Extension=".vsixmanifest" ContentType="text/xml"/>
  <Default Extension=".js" ContentType="application/javascript"/>
  <Default Extension=".png" ContentType="image/png"/>
  <Default Extension=".svg" ContentType="image/svg+xml"/>
  <Default Extension=".md" ContentType="text/markdown"/>
</Types>
EOF
  cat > "${TMP}/extension.vsixmanifest" <<EOF
<?xml version="1.0" encoding="utf-8"?>
<PackageManifest Version="2.0.0" xmlns="http://schemas.microsoft.com/developer/vsx-schema/2011">
  <Metadata>
    <Identity Id="afrilang" Version="${VERSION}" Publisher="afrilang" Language="en-US"/>
    <DisplayName>AFRILANG</DisplayName>
    <Description xml:space="preserve">Langage AFRILANG</Description>
    <Categories>Programming Languages</Categories>
  </Metadata>
  <Installation>
    <InstallationTarget Id="Microsoft.VisualStudio.Code"/>
  </Installation>
  <Dependencies/>
  <Assets>
    <Asset Type="Microsoft.VisualStudio.Code.Manifest" Path="extension/package.json" Addressable="true"/>
  </Assets>
</PackageManifest>
EOF
  rm -f "$VSIX"
  (cd "$TMP" && zip -qr "$VSIX" .)
  rm -rf "$TMP"
  echo "✓ VSIX : $VSIX"
fi

install_via_cli() {
  local bin="$1"
  local label="$2"
  if ! command -v "$bin" >/dev/null 2>&1; then
    echo "  ⊘ $label — CLI '$bin' absente"
    return 0
  fi
  if [[ -f "$VSIX" ]]; then
    if "$bin" --no-sandbox --install-extension "$VSIX" >/dev/null 2>&1 \
      || "$bin" --install-extension "$VSIX" >/dev/null 2>&1; then
      echo "  ✓ $label via CLI ($bin --install-extension)"
      return 0
    fi
  fi
  return 1
}

CLI_OK=0
install_via_cli cursor  "Cursor"   && CLI_OK=1 || true
install_via_cli code    "VS Code"  && CLI_OK=1 || true
install_via_cli codium  "VSCodium" && CLI_OK=1 || true

# Repli : copie manuelle si CLI indisponible
if [[ "$CLI_OK" -eq 0 ]]; then
  echo "⚠ CLI indisponible — installation par copie dans extensions/"
  install_editor "Cursor"    "${HOME}/.cursor/extensions"
  install_editor "VS Code"   "${HOME}/.vscode/extensions"
  install_editor "VSCodium"  "${HOME}/.vscode-oss/extensions"
fi

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
echo "  1. Developer: Reload Window"
echo "  2. Cursor : Ctrl+Shift+P → « Open or Focus Editor Window » (pas Agents/Glass)"
echo "  3. Ouvrir un fichier .afr — barre d'état = AFRILANG"
echo "  4. File Icon Theme = AFRILANG"
echo ""
echo "Note : dans Agents Window (Glass), Cursor n'applique PAS les grammaires"
echo "       d'extensions (bug connu). Couleurs + logo = éditeur classique uniquement."
