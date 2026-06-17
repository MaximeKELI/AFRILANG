#!/usr/bin/env bash
# Redirect to the official installer (binary release or source fallback).
set -euo pipefail
exec bash -c "$(curl -fsSL "${AFRILANG_INSTALL_URL:-https://raw.githubusercontent.com/MaximeKELI/AFRILANG/main/install.sh}")" _ "$@"
