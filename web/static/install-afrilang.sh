#!/usr/bin/env bash
# AFRILANG — installateur rapide (build from source)
set -euo pipefail

REPO="${AFRILANG_REPO:-https://github.com/MaximeKELI/AFRILANG.git}"
DEST="${AFRILANG_INSTALL_DIR:-$HOME/.local/afrilang}"
JOBS="${AFRILANG_JOBS:-$(nproc 2>/dev/null || echo 4)}"

echo "→ Cloning AFRILANG into $DEST"
git clone --depth 1 "$REPO" "$DEST"
mkdir -p "$DEST/build"
cd "$DEST/build"
cmake ..
cmake --build . -j"$JOBS"

BIN="$DEST/build/afrilang"
"$BIN" run "$DEST/examples/hello.afr" --run || true

echo ""
echo "✓ AFRILANG installed at $BIN"
echo "  Add to PATH:  export PATH=\"$DEST/build:\$PATH\""
echo "  Or symlink:   ln -sf \"$BIN\" ~/.local/bin/afrilang"
