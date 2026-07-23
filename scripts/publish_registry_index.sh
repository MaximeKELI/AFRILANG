#!/usr/bin/env bash
# Regenerate registry/index.json + packages/remote-index.bundled.json from packages/index.json.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"
python3 - <<'PY'
import json
from pathlib import Path
root = Path(".")
idx = json.loads((root / "packages" / "index.json").read_text())
pkgs = idx.get("packages", [])
out = []
for p in pkgs:
    if not isinstance(p, dict) or not p.get("name"):
        continue
    entry = {
        "name": p["name"],
        "version": p.get("version", "0.1.0"),
        "description": p.get("description", ""),
        "method": "git",
        "url": "https://github.com/MaximeKELI/AFRILANG.git",
        "path": f"packages/{p['name']}",
        "sha256": p.get("sha256", ""),
        "blessed": bool(p.get("blessed", False)),
    }
    for k in ("license", "tags", "web", "sig"):
        if p.get(k):
            entry[k] = p[k]
    out.append(entry)
out.sort(key=lambda e: (not e.get("blessed"), e["name"]))
payload = {
    "registry": "afrilang",
    "version": 1,
    "source": "https://github.com/MaximeKELI/AFRILANG",
    "packages": out,
}
(root / "registry").mkdir(exist_ok=True)
(root / "registry" / "index.json").write_text(json.dumps(payload, indent=2) + "\n")
bundled = []
for p in out:
    b = {k: v for k, v in p.items() if k not in ("url", "path")}
    b["method"] = "local"
    bundled.append(b)
(root / "packages" / "remote-index.bundled.json").write_text(
    json.dumps({"registry": "afrilang-local-bundle", "version": 1, "packages": bundled}, indent=2)
    + "\n"
)
print(f"registry/index.json: {len(out)} packages")
PY
