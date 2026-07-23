#!/usr/bin/env bash
# Sign all blessed packages. Requires AFRILANG_PKG_SIGN_KEY (64-byte hex private key).
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
mapfile -t PKGS < <(python3 - <<'PY'
import json
from pathlib import Path
names = json.loads(Path("packages/blessed.json").read_text())
if isinstance(names, dict):
    names = names.get("packages", [])
for n in sorted(names):
    print(n)
PY
)
for p in "${PKGS[@]}"; do
  echo "signing $p ..."
  "$AFR" pkg sign "$p" "$AFRILANG_PKG_SIGN_KEY"
done
"$AFR" pkg reindex
# Refresh bundled remote index from local registry metadata
python3 - <<'PY'
import json
from pathlib import Path
root = Path(".")
idx = json.loads((root / "packages" / "index.json").read_text())
pkgs = idx.get("packages", idx if isinstance(idx, list) else [])
out = []
for p in pkgs:
    if not isinstance(p, dict) or not p.get("name"):
        continue
    entry = {
        "name": p["name"],
        "version": p.get("version", "0.1.0"),
        "description": p.get("description", ""),
        "method": "local",
        "sha256": p.get("sha256", ""),
        "blessed": bool(p.get("blessed", False)),
    }
    for k in ("license", "tags", "web", "sig"):
        if p.get(k):
            entry[k] = p[k]
    out.append(entry)
out.sort(key=lambda e: (not e.get("blessed"), e["name"]))
payload = {"registry": "afrilang-local-bundle", "version": 1, "packages": out}
(root / "packages" / "remote-index.bundled.json").write_text(
    json.dumps(payload, indent=2) + "\n"
)
print(f"updated remote-index.bundled.json ({len(out)} packages)")
PY
echo "done. verify with: afrilang pkg verify <name>"
