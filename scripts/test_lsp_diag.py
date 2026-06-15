#!/usr/bin/env python3
"""Test LSP diagnostics for each .afr file."""
import json
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
AFRILANG = ROOT / "build" / "afrilang"


def lsp_diag_for(path: Path) -> list[str]:
    src = path.read_text()
    uri = f"file://{path.resolve()}"
    proc = subprocess.Popen(
        [str(AFRILANG), "lsp"],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.PIPE,
    )

    def send(obj):
        data = json.dumps(obj)
        msg = f"Content-Length: {len(data)}\r\n\r\n{data}"
        proc.stdin.write(msg.encode())
        proc.stdin.flush()

    send({"jsonrpc": "2.0", "id": 1, "method": "initialize", "params": {"capabilities": {}}})
    time.sleep(0.05)
    send({
        "jsonrpc": "2.0",
        "method": "textDocument/didOpen",
        "params": {
            "textDocument": {
                "uri": uri,
                "languageId": "afrilang",
                "version": 1,
                "text": src,
            }
        },
    })

    out = b""
    deadline = time.time() + 2.0
    while time.time() < deadline:
        chunk = proc.stdout.read(4096)
        if chunk:
            out += chunk
            if b"publishDiagnostics" in out:
                break
        else:
            time.sleep(0.02)

    proc.kill()
    text = out.decode(errors="replace")
    if '"diagnostics":[]' in text.replace(" ", "") or '"diagnostics": []' in text:
        return []
    import re
    return re.findall(r'"message":"((?:\\.|[^"\\])*)"', text)


def main():
    failures = []
    for path in sorted(EXAMPLES.glob("*.afr")):
        msgs = lsp_diag_for(path)
        if msgs:
            failures.append((path.name, msgs))
            print(f"FAIL {path.name}: {msgs[0][:80]}")
        else:
            print(f"OK   {path.name}")

    if failures:
        print(f"\n{len(failures)} fichier(s) avec fausses erreurs LSP")
        return 1
    print("\nTous les diagnostics LSP OK")
    return 0


if __name__ == "__main__":
    sys.exit(main())
