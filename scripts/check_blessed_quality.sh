#!/usr/bin/env bash
# Quality gate for core-blessed packages: README + smoke test + min LOC.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"
python3 - <<'PY'
import json
from pathlib import Path
root = Path(".")
core = json.loads((root / "packages" / "core-blessed.json").read_text())
errors = []
for name in core:
    pkg = root / "packages" / name
    if not (pkg / "manifest.toml").exists():
        errors.append(f"{name}: missing manifest.toml")
        continue
    if not (pkg / "README.md").exists():
        errors.append(f"{name}: missing README.md")
    smoke = pkg / "tests" / "smoke.afr"
    if not smoke.exists():
        errors.append(f"{name}: missing tests/smoke.afr")
    afr_files = list(pkg.glob("*.afr"))
    loc = 0
    for f in afr_files:
        loc += sum(1 for line in f.read_text(encoding="utf-8", errors="ignore").splitlines() if line.strip())
    if loc < 8:
        errors.append(f"{name}: only {loc} non-empty LOC (min 8)")
if errors:
    print("core-blessed quality gate FAILED:")
    for e in errors:
        print(" -", e)
    raise SystemExit(1)
print(f"core-blessed quality ok: {len(core)} packages")
PY
