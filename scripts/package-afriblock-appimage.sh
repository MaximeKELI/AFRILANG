#!/usr/bin/env bash
# Build a basic AFRIBLOCK AppImage from the Linux Flutter bundle.
# Requires: appimagetool (https://github.com/AppImage/appimagetool) on PATH,
# and a prior `bash scripts/package-afriblock.sh` linux package (or builds it).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT="${1:-$ROOT/dist/afriblock}"
BUNDLE="$OUT/afriblock-linux"
APPDIR="$OUT/AFRIBLOCK.AppDir"

if [[ ! -d "$BUNDLE" ]]; then
  echo "Linux bundle missing — packaging first…"
  bash "$ROOT/scripts/package-afriblock.sh" "$OUT" linux
fi

rm -rf "$APPDIR"
mkdir -p "$APPDIR/usr/bin" "$APPDIR/usr/share/applications" "$APPDIR/usr/share/icons/hicolor/256x256/apps"
cp -a "$BUNDLE/." "$APPDIR/usr/bin/"

# Prefer the flutter binary name inside the bundle.
BIN=""
for cand in afriblock afrilang_ide; do
  if [[ -x "$APPDIR/usr/bin/$cand" ]]; then
    BIN="$cand"
    break
  fi
done
if [[ -z "$BIN" ]]; then
  BIN="$(find "$APPDIR/usr/bin" -maxdepth 1 -type f -executable | head -n1 | xargs -r basename)"
fi
if [[ -z "$BIN" ]]; then
  echo "No executable found in $BUNDLE" >&2
  exit 1
fi

cat > "$APPDIR/AppRun" <<EOF
#!/usr/bin/env bash
HERE="\$(dirname "\$(readlink -f "\$0")")"
export AFRIBLOCK_AFRILANG="\${AFRIBLOCK_AFRILANG:-}"
exec "\$HERE/usr/bin/$BIN" "\$@"
EOF
chmod +x "$APPDIR/AppRun"

cat > "$APPDIR/afriblock.desktop" <<EOF
[Desktop Entry]
Type=Application
Name=AFRIBLOCK
Comment=AFRILANG IDE
Exec=$BIN
Icon=afriblock
Categories=Development;IDE;
Terminal=false
EOF
cp "$APPDIR/afriblock.desktop" "$APPDIR/usr/share/applications/"

# Placeholder icon (AppImage tools accept missing icon with a warning).
if [[ -f "$ROOT/ide/afriblock/assets/icon.png" ]]; then
  cp "$ROOT/ide/afriblock/assets/icon.png" "$APPDIR/afriblock.png"
  cp "$ROOT/ide/afriblock/assets/icon.png" "$APPDIR/usr/share/icons/hicolor/256x256/apps/afriblock.png"
else
  # Minimal 1x1 PNG so appimagetool does not hard-fail on some setups.
  printf '\x89PNG\r\n\x1a\n\x00\x00\x00\rIHDR\x00\x00\x00\x01\x00\x00\x00\x01\x08\x02\x00\x00\x00\x90wS\xde\x00\x00\x00\x0cIDATx\x9cc\xf8\x0f\x00\x00\x01\x01\x00\x05\x18\xd8N\x00\x00\x00\x00IEND\xaeB`\x82' \
    > "$APPDIR/afriblock.png"
fi

if ! command -v appimagetool >/dev/null 2>&1; then
  echo "AppDir ready at $APPDIR"
  echo "Install appimagetool, then:"
  echo "  appimagetool \"$APPDIR\" \"$OUT/AFRIBLOCK-x86_64.AppImage\""
  exit 0
fi

ARCH=x86_64 appimagetool "$APPDIR" "$OUT/AFRIBLOCK-x86_64.AppImage"
echo "AppImage → $OUT/AFRIBLOCK-x86_64.AppImage"
