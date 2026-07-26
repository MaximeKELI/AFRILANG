#!/usr/bin/env python3
"""Gap 8 — LSP publishDiagnostics (error) + documentSymbol smoke."""
from __future__ import annotations

import json
import os
import re
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(os.environ.get("ROOT", Path(__file__).resolve().parents[1])).resolve()
AFR = Path(os.environ.get("AFR", ROOT / "build" / "afrilang"))


def lsp_exchange(path: Path, extra=None, wait_for: bytes = b"publishDiagnostics") -> str:
    src = path.read_text()
    uri = f"file://{path.resolve()}"
    proc = subprocess.Popen(
        [str(AFR), "lsp"],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.DEVNULL,
    )

    def send(obj):
        data = json.dumps(obj, separators=(",", ":"))
        msg = f"Content-Length: {len(data)}\r\n\r\n{data}".encode()
        proc.stdin.write(msg)
        proc.stdin.flush()

    send({"jsonrpc": "2.0", "id": 1, "method": "initialize", "params": {"capabilities": {}}})
    send(
        {
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
        }
    )
    if extra:
        send(extra)
    proc.stdin.close()

    out = b""
    deadline = time.time() + 3.0
    while time.time() < deadline:
        if proc.poll() is not None:
            out += proc.stdout.read() or b""
            break
        chunk = (
            proc.stdout.read1(4096)
            if hasattr(proc.stdout, "read1")
            else proc.stdout.read(4096)
        )
        if chunk:
            out += chunk
            if wait_for in out:
                break
        else:
            time.sleep(0.01)

    if proc.poll() is None:
        proc.kill()
        out += proc.stdout.read() or b""
    return out.decode(errors="replace")


def main() -> int:
    if not AFR.exists():
        print(f"missing {AFR}", file=sys.stderr)
        return 1

    diag_path = ROOT / "tests/gaps/tooling/lsp_diag.afr"
    text = lsp_exchange(diag_path)
    compact = text.replace(" ", "")
    if "publishDiagnostics" not in text:
        print("LSP missing publishDiagnostics", text[:600], file=sys.stderr)
        return 1
    if '"diagnostics":[]' in compact or '"diagnostics": []' in text:
        print("LSP diagnostics empty for bad file", file=sys.stderr)
        return 1
    if "undeclared_for_lsp_diag" not in text and "E3002" not in text and "non" not in text:
        # Still OK if any non-empty diagnostic message exists
        if not re.search(r'"message"\s*:\s*"[^"]+"', text):
            print("LSP diagnostic message missing", text[:600], file=sys.stderr)
            return 1
    print("  lsp diag ok")

    sym_path = ROOT / "tests/gaps/tooling/lsp_symbols.afr"
    uri = f"file://{sym_path.resolve()}"
    text = lsp_exchange(
        sym_path,
        extra={
            "jsonrpc": "2.0",
            "id": 2,
            "method": "textDocument/documentSymbol",
            "params": {"textDocument": {"uri": uri}},
        },
        wait_for=b'"id":2',
    )
    names = re.findall(r'"name"\s*:\s*"([^"]+)"', text)
    if "double" not in names and "Point" not in names:
        print("documentSymbol missing double/Point:", names, file=sys.stderr)
        print(text[:800], file=sys.stderr)
        return 1
    print("  lsp symbols ok")
    return 0


if __name__ == "__main__":
    sys.exit(main())
