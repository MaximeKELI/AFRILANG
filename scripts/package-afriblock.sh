#!/usr/bin/env bash
# Package AFRIBLOCK desktop release (Phase F helper).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/../.." && pwd)"
APP="$ROOT/ide/afriblock"
OUT="${1:-$ROOT/dist/afriblock}"
PLATFORM="${2:-linux}"

mkdir -p "$OUT"
cd "$APP"
flutter pub get
case "$PLATFORM" in
  linux)
    flutter build linux --release
    cp -a build/linux/*/release/bundle "$OUT/afriblock-linux"
    ;;
  windows)
    flutter build windows --release
    cp -a build/windows/x64/runner/Release "$OUT/afriblock-windows"
    ;;
  macos)
    flutter build macos --release
    cp -a build/macos/Build/Products/Release/afriblock.app "$OUT/"
    ;;
  *)
    echo "Usage: $0 [out_dir] [linux|windows|macos]" >&2
    exit 2
    ;;
esac
echo "Packaged → $OUT"
echo "Set AFRIBLOCK_AFRILANG to the afrilang binary on end-user machines."
