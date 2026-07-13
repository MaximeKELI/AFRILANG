#!/usr/bin/env bash
# Installe AFRILANG en local dans Cursor (sans marketplace).
# Usage : ./install-cursor.sh
set -euo pipefail
ROOT="$(cd "$(dirname "$0")" && pwd)"
exec "$ROOT/install.sh"
