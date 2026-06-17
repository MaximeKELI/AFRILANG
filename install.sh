#!/usr/bin/env bash
# AFRILANG — install pre-built binaries from GitHub Releases.
#   curl -fsSL https://raw.githubusercontent.com/MaximeKELI/AFRILANG/main/install.sh | bash
#   curl -fsSL ... | bash -s -- --version v1.0.0
#   curl -fsSL ... | bash -s -- --prefix ~/.local/afrilang
set -euo pipefail

GITHUB_REPO="${AFRILANG_GITHUB_REPO:-MaximeKELI/AFRILANG}"
VERSION="${AFRILANG_VERSION:-latest}"
INSTALL_ROOT="${AFRILANG_INSTALL_DIR:-$HOME/.local/afrilang}"
BIN_DIR="${AFRILANG_BIN_DIR:-$HOME/.local/bin}"
FROM_SOURCE=0

usage() {
  cat <<'EOF'
AFRILANG installer

Usage: install.sh [options]

Options:
  --version TAG     Release tag (default: latest), e.g. v1.0.0
  --prefix DIR      Install root (default: ~/.local/afrilang)
  --bin-dir DIR     Symlink target (default: ~/.local/bin)
  --from-source     Clone repo and build with cmake (fallback)
  -h, --help        Show help

Environment:
  AFRILANG_GITHUB_REPO   GitHub owner/repo
  AFRILANG_VERSION       Same as --version
  AFRILANG_INSTALL_DIR   Same as --prefix
  AFRILANG_BIN_DIR       Same as --bin-dir
EOF
}

while [[ $# -gt 0 ]]; do
  case "$1" in
    --version) VERSION="${2#v}"; shift 2 ;;
    --prefix) INSTALL_ROOT="$2"; shift 2 ;;
    --bin-dir) BIN_DIR="$2"; shift 2 ;;
    --from-source) FROM_SOURCE=1; shift ;;
    -h|--help) usage; exit 0 ;;
    *) echo "Unknown option: $1" >&2; usage; exit 1 ;;
  esac
done

detect_platform() {
  local os arch
  os="$(uname -s)"
  arch="$(uname -m)"
  case "$os" in
    Linux)
      case "$arch" in
        x86_64|amd64) echo "linux-x86_64" ;;
        aarch64|arm64) echo "linux-arm64" ;;
        *) echo "unsupported-linux-$arch" ;;
      esac
      ;;
    Darwin)
      case "$arch" in
        arm64) echo "macos-arm64" ;;
        x86_64) echo "macos-x86_64" ;;
        *) echo "unsupported-macos-$arch" ;;
      esac
      ;;
    MINGW*|MSYS*|CYGWIN*)
      echo "windows-x86_64"
      ;;
    *)
      echo "unsupported-$os-$arch"
      ;;
  esac
}

fetch_latest_version() {
  curl -fsSL "https://api.github.com/repos/${GITHUB_REPO}/releases/latest" \
    | sed -n 's/.*"tag_name"[[:space:]]*:[[:space:]]*"\([^"]*\)".*/\1/p' \
    | head -1 \
    | sed 's/^v//'
}

install_from_source() {
  local dest="$INSTALL_ROOT"
  local repo="https://github.com/${GITHUB_REPO}.git"
  local jobs="${AFRILANG_JOBS:-$(nproc 2>/dev/null || echo 4)}"
  echo "→ Building from source into $dest"
  rm -rf "$dest"
  git clone --depth 1 "$repo" "$dest"
  cmake -S "$dest" -B "$dest/build" -DCMAKE_BUILD_TYPE=Release
  cmake --build "$dest/build" -j"$jobs"
  mkdir -p "$dest/bin"
  cp "$dest/build/afrilang" "$dest/bin/"
  echo "${VERSION:-dev}" > "$dest/VERSION"
}

install_binary() {
  local platform="$1"
  local ver="$2"
  local tag="v${ver}"
  local base="afrilang-${ver}-${platform}"
  local url archive tmp

  mkdir -p "$INSTALL_ROOT" "$BIN_DIR"

  if [[ "$platform" == windows-* ]]; then
    archive="${base}.zip"
    url="https://github.com/${GITHUB_REPO}/releases/download/${tag}/${archive}"
    tmp="$(mktemp -d)"
    echo "→ Downloading $url"
    curl -fsSL "$url" -o "$tmp/$archive"
    unzip -q "$tmp/$archive" -d "$tmp"
    rm -rf "$INSTALL_ROOT"
    mv "$tmp/$base" "$INSTALL_ROOT"
    rm -rf "$tmp"
  else
    archive="${base}.tar.gz"
    url="https://github.com/${GITHUB_REPO}/releases/download/${tag}/${archive}"
    tmp="$(mktemp -d)"
    echo "→ Downloading $url"
    curl -fsSL "$url" -o "$tmp/$archive"
    tar -xzf "$tmp/$archive" -C "$tmp"
    rm -rf "$INSTALL_ROOT"
    mv "$tmp/$base" "$INSTALL_ROOT"
    rm -rf "$tmp"
  fi
}

link_binary() {
  local exe="$INSTALL_ROOT/bin/afrilang"
  [[ -f "$exe" ]] || exe="$INSTALL_ROOT/bin/afrilang.exe"
  if [[ ! -f "$exe" ]]; then
    echo "Error: afrilang binary not found under $INSTALL_ROOT/bin" >&2
    exit 1
  fi
  mkdir -p "$BIN_DIR"
  ln -sf "$exe" "$BIN_DIR/afrilang"
}

write_env_hint() {
  local ver
  ver="$(cat "$INSTALL_ROOT/VERSION" 2>/dev/null || echo "$VERSION")"
  cat <<EOF

✓ AFRILANG ${ver} installed at $INSTALL_ROOT
  Binary: $BIN_DIR/afrilang

Add to your shell profile (~/.bashrc or ~/.zshrc):

  export PATH="$BIN_DIR:\$PATH"
  export AFRILANG_HOME="$INSTALL_ROOT"

Then run:  afrilang version
            afrilang run $INSTALL_ROOT/examples/hello.afr

EOF
}

main() {
  if [[ "$FROM_SOURCE" -eq 1 ]]; then
    install_from_source
    link_binary
    write_env_hint
    return
  fi

  local platform
  platform="$(detect_platform)"
  if [[ "$platform" == unsupported-* ]]; then
    echo "Unsupported platform: $platform" >&2
    echo "Try: curl ... | bash -s -- --from-source" >&2
    exit 1
  fi

  if [[ "$VERSION" == "latest" ]]; then
    VERSION="$(fetch_latest_version)"
    if [[ -z "$VERSION" ]]; then
      echo "No GitHub release found; building from source..." >&2
      install_from_source
      link_binary
      write_env_hint
      return
    fi
  fi

  VERSION="${VERSION#v}"

  if ! install_binary "$platform" "$VERSION"; then
    echo "Release download failed; building from source..." >&2
    install_from_source
  fi

  link_binary
  write_env_hint
}

main
