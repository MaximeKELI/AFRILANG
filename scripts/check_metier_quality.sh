#!/usr/bin/env bash
# Quality gate for métier packages: manifest, README, smoke, unit, min LOC.
set -euo pipefail
ROOT="$(cd "$(dirname "$0")/.." && pwd)"
cd "$ROOT"
python3 - <<'PY'
import json
from pathlib import Path
root = Path(".")
metier = json.loads((root / "packages" / "metier.json").read_text())
errors = []
for name in metier:
    pkg = root / "packages" / name
    if not (pkg / "manifest.toml").exists():
        errors.append(f"{name}: missing manifest.toml")
        continue
    if not (pkg / "README.md").exists():
        errors.append(f"{name}: missing README.md")
    for need in ("tests/smoke.afr", "tests/unit.afr"):
        if not (pkg / need).exists():
            errors.append(f"{name}: missing {need}")
    afr_files = list(pkg.glob("*.afr"))
    loc = 0
    for f in afr_files:
        loc += sum(1 for line in f.read_text(encoding="utf-8", errors="ignore").splitlines() if line.strip())
    if loc < 12:
        errors.append(f"{name}: only {loc} non-empty LOC (min 12)")
    # tag check
    text = (pkg / "manifest.toml").read_text(encoding="utf-8", errors="ignore")
    if "metier" not in text:
        errors.append(f"{name}: manifest missing metier tag")
if errors:
    print("metier quality gate FAILED:")
    for e in errors:
        print(" -", e)
    raise SystemExit(1)
print(f"metier quality ok: {len(metier)} packages")
PY
