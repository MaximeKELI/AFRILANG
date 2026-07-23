#!/usr/bin/env bash
# Sign a representative blessed subset. Requires AFRILANG_PKG_SIGN_KEY (64-byte hex private key).
# Public key must be listed in packages/trusted_keys.json.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFR="${ROOT}/build/afrilang"
if [[ ! -x "$AFR" ]]; then
  echo "missing $AFR — build first" >&2
  exit 1
fi
if [[ -z "${AFRILANG_PKG_SIGN_KEY:-}" ]]; then
  echo "Set AFRILANG_PKG_SIGN_KEY to the Ed25519 private key hex (see SECURITY.md)." >&2
  exit 1
fi
PKGS=(math strx flagx urlx queryx percentx listx jsonx semverx
      bannerx clampx checkx csvx textx pathx envx numcheck fmt cli)
for p in "${PKGS[@]}"; do
  echo "signing $p ..."
  "$AFR" pkg sign "$p" "$AFRILANG_PKG_SIGN_KEY"
done
"$AFR" pkg reindex
echo "done. verify with: afrilang pkg verify <name>"
