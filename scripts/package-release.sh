#!/usr/bin/env bash
# Package AFRILANG binary + runtime/stdlib for GitHub Releases.
set -euo pipefail

ROOT="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
VERSION="${1:-}"
PLATFORM="${2:-}"
BUILD_DIR="${BUILD_DIR:-$ROOT/build}"
DIST_DIR="${DIST_DIR:-$ROOT/dist}"

detect_host_platform() {
  local os arch
  os="$(uname -s 2>/dev/null || echo unknown)"
  arch="$(uname -m 2>/dev/null || echo unknown)"
  case "$os" in
    Linux)
      case "$arch" in
        x86_64|amd64) echo "linux-x86_64" ;;
        aarch64|arm64) echo "linux-arm64" ;;
        *) echo "linux-${arch}" ;;
      esac
      ;;
    Darwin)
      case "$arch" in
        arm64|aarch64) echo "macos-arm64" ;;
        x86_64) echo "macos-x86_64" ;;
        *) echo "macos-${arch}" ;;
      esac
      ;;
    MINGW*|MSYS*|CYGWIN*)
      echo "windows-x86_64"
      ;;
    *)
      echo "unknown"
      ;;
  esac
}

if [[ -z "$VERSION" ]]; then
  echo "Usage: $0 <version> [platform]   e.g. 1.0.0 linux-x86_64" >&2
  echo "  platform defaults to host ($(detect_host_platform))" >&2
  exit 1
fi
if [[ -z "$PLATFORM" ]]; then
  PLATFORM="$(detect_host_platform)"
  if [[ "$PLATFORM" == "unknown" ]]; then
    echo "Cannot auto-detect platform; pass explicitly." >&2
    exit 1
  fi
  echo "Auto-detected platform: $PLATFORM"
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
  ARCHIVE_FILE="${ARCHIVE_BASE}.zip"
else
  tar -C "$DIST_DIR" -czf "$DIST_DIR/${ARCHIVE_BASE}.tar.gz" "$(basename "$STAGING")"
  echo "Created $DIST_DIR/${ARCHIVE_BASE}.tar.gz"
  ARCHIVE_FILE="${ARCHIVE_BASE}.tar.gz"
fi

# Local integrity file for the archive (CI/gap9 verify; not a signature).
(
  cd "$DIST_DIR"
  if command -v sha256sum >/dev/null 2>&1; then
    sha256sum "$ARCHIVE_FILE" > "${ARCHIVE_FILE}.sha256"
  elif command -v shasum >/dev/null 2>&1; then
    shasum -a 256 "$ARCHIVE_FILE" > "${ARCHIVE_FILE}.sha256"
  fi
  if [[ -f "${ARCHIVE_FILE}.sha256" ]]; then
    echo "Created $DIST_DIR/${ARCHIVE_FILE}.sha256"
  fi
)
