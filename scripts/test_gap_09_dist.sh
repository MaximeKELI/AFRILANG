#!/usr/bin/env bash
# Gap 9 — distribution / packaging (offline dry-run + platform contracts).
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
[[ -f "$ROOT/docs/DIST.md" ]]
[[ -f "$ROOT/install.sh" ]]
[[ -f "$ROOT/scripts/package-release.sh" ]]
[[ -f "$ROOT/.github/workflows/release.yml" ]]
grep -q 'detect_platform' "$ROOT/install.sh"

# Platform tags: expected ⊆ install.sh + package-release + release.yml
EXPECTED="$ROOT/tests/gaps/dist/platforms.expected"
[[ -f "$EXPECTED" ]]
while read -r plat; do
  [[ -n "$plat" ]] || continue
  grep -q "$plat" "$ROOT/install.sh" \
    || { echo "install.sh missing platform $plat" >&2; exit 1; }
  grep -qE "linux-x86_64|macos-arm64|windows-x86_64|linux-arm64|macos-x86_64" \
    "$ROOT/scripts/package-release.sh"
  grep -q "platform: $plat" "$ROOT/.github/workflows/release.yml" \
    || { echo "release.yml missing platform: $plat" >&2; exit 1; }
done < "$EXPECTED"
echo "  platform tags ok"

# package-release without version → Usage
set +e
out="$(bash "$ROOT/scripts/package-release.sh" 2>&1)"
code=$?
set -e
[[ "$code" -ne 0 ]]
echo "$out" | grep -qi 'Usage'
echo "  package-release usage ok"

# install.sh --help
bash "$ROOT/install.sh" --help | grep -qi 'Usage\|prefix\|version'
echo "  install help ok"

# Offline package dry-run with fake binary
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT
mkdir -p "$TMP/build"
printf '#!/bin/sh\necho fake-afrilang\n' >"$TMP/build/afrilang"
chmod +x "$TMP/build/afrilang"
export BUILD_DIR="$TMP/build"
export DIST_DIR="$TMP/dist"
bash "$ROOT/scripts/package-release.sh" 0.0.0-test linux-x86_64 >/dev/null
ARCHIVE="$DIST_DIR/afrilang-0.0.0-test-linux-x86_64.tar.gz"
[[ -f "$ARCHIVE" ]]
[[ -f "${ARCHIVE}.sha256" ]]
tar -tzf "$ARCHIVE" | grep -q 'bin/afrilang'
tar -xzf "$ARCHIVE" -C "$TMP"
STAGED="$DIST_DIR/afrilang-0.0.0-test-linux-x86_64"
# After tar extract to TMP, staging dir name is inside archive
EXTRACTED="$(find "$TMP" -type d -name 'afrilang-0.0.0-test-linux-x86_64' | head -1)"
[[ -n "$EXTRACTED" ]]
[[ -f "$EXTRACTED/VERSION" ]]
[[ -x "$EXTRACTED/bin/afrilang" ]] || [[ -f "$EXTRACTED/bin/afrilang" ]]
grep -qx '0.0.0-test' "$EXTRACTED/VERSION"
# Verify sha256
(
  cd "$DIST_DIR"
  if command -v sha256sum >/dev/null 2>&1; then
    sha256sum -c "afrilang-0.0.0-test-linux-x86_64.tar.gz.sha256" >/dev/null
  elif command -v shasum >/dev/null 2>&1; then
    shasum -a 256 -c "afrilang-0.0.0-test-linux-x86_64.tar.gz.sha256" >/dev/null
  fi
)
echo "  package dry-run + sha256 ok"

echo "[gap9] ok"
