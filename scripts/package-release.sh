#!/usr/bin/env bash
# Package AFRILANG binary + runtime/stdlib for GitHub Releases.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
VERSION="${1:-}"
PLATFORM="${2:-}"
BUILD_DIR="${BUILD_DIR:-$ROOT/build}"
DIST_DIR="${DIST_DIR:-$ROOT/dist}"

if [[ -z "$VERSION" || -z "$PLATFORM" ]]; then
  echo "Usage: $0 <version> <platform>   e.g. 1.0.0 linux-x86_64" >&2
  exit 1
fi

BIN="$BUILD_DIR/afrilang"
if [[ "$PLATFORM" == windows-* ]]; then
  BIN="$BUILD_DIR/afrilang.exe"
  if [[ ! -f "$BIN" && -f "$BUILD_DIR/Release/afrilang.exe" ]]; then
    BIN="$BUILD_DIR/Release/afrilang.exe"
  fi
fi

if [[ ! -f "$BIN" ]]; then
  echo "Binary not found: $BIN (build first)" >&2
  exit 1
fi

STAGING="$DIST_DIR/afrilang-${VERSION}-${PLATFORM}"
rm -rf "$STAGING"
mkdir -p "$STAGING/bin"

cp "$BIN" "$STAGING/bin/"
chmod +x "$STAGING/bin/"* 2>/dev/null || true

for dir in runtime stdlib examples packages site scripts; do
  if [[ -d "$ROOT/$dir" ]]; then
    cp -a "$ROOT/$dir" "$STAGING/"
  fi
done

cp "$ROOT/LICENSE" "$STAGING/" 2>/dev/null || true
cp "$ROOT/README.md" "$STAGING/" 2>/dev/null || true
echo "$VERSION" > "$STAGING/VERSION"

mkdir -p "$DIST_DIR"
ARCHIVE_BASE="afrilang-${VERSION}-${PLATFORM}"

if [[ "$PLATFORM" == windows-* ]]; then
  (cd "$DIST_DIR" && zip -rq "${ARCHIVE_BASE}.zip" "$(basename "$STAGING")")
  echo "Created $DIST_DIR/${ARCHIVE_BASE}.zip"
else
  tar -C "$DIST_DIR" -czf "$DIST_DIR/${ARCHIVE_BASE}.tar.gz" "$(basename "$STAGING")"
  echo "Created $DIST_DIR/${ARCHIVE_BASE}.tar.gz"
fi
