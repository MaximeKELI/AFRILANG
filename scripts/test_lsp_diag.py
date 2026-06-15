#!/usr/bin/env python3
"""Test LSP diagnostics and document symbols."""
import json
import re
import subprocess
import sys
import time
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
AFRILANG = ROOT / "build" / "afrilang"
EXAMPLES = ROOT / "examples"

DIAG_SAMPLES = [
    "hello.afr",
    "oop.afr",
    "generics.afr",
    "full_demo.afr",
    "modules.afr",
    "stdlib_demo.afr",
    "tier7_demo.afr",
    "tier9_demo.afr",
    "tier10_demo.afr",
]


def lsp_exchange(path: Path, extra_request=None, wait_for=b"publishDiagnostics") -> str:
    src = path.read_text()
    uri = f"file://{path.resolve()}"
    proc = subprocess.Popen(
        [str(AFRILANG), "lsp"],
        stdin=subprocess.PIPE,
        stdout=subprocess.PIPE,
        stderr=subprocess.DEVNULL,
    )

    def send(obj):
        data = json.dumps(obj)
        msg = f"Content-Length: {len(data)}\r\n\r\n{data}"
        proc.stdin.write(msg.encode())
        proc.stdin.flush()

    send({"jsonrpc": "2.0", "id": 1, "method": "initialize", "params": {"capabilities": {}}})
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
    if extra_request:
        send(extra_request)
    proc.stdin.close()

    out = b""
    deadline = time.time() + 2.0
    while time.time() < deadline:
        if proc.poll() is not None:
            out += proc.stdout.read()
            break
        chunk = proc.stdout.read1(4096) if hasattr(proc.stdout, "read1") else proc.stdout.read(4096)
        if chunk:
            out += chunk
            if wait_for in out:
                break
        else:
            time.sleep(0.01)

    if proc.poll() is None:
        proc.kill()
        try:
            out += proc.communicate(timeout=1)[0]
        except subprocess.TimeoutExpired:
            proc.kill()

    return out.decode(errors="replace")


def lsp_diag_for(path: Path) -> list[str]:
    text = lsp_exchange(path)
    if '"diagnostics":[]' in text.replace(" ", "") or '"diagnostics": []' in text:
        return []
    return re.findall(r'"message":"((?:\\.|[^"\\])*)"', text)


def lsp_symbols_for(path: Path) -> list[str]:
    uri = f"file://{path.resolve()}"
    text = lsp_exchange(
        path,
        extra_request={
            "jsonrpc": "2.0",
            "id": 2,
            "method": "textDocument/documentSymbol",
            "params": {"textDocument": {"uri": uri}},
        },
        wait_for=b'"id":2',
    )
    return re.findall(r'"name":"((?:\\.|[^"\\])*)"', text)


def main():
    if not AFRILANG.exists():
        print(f"SKIP: {AFRILANG} introuvable")
        return 0

    full = "--full" in sys.argv
    paths = sorted(EXAMPLES.glob("*.afr")) if full else [EXAMPLES / n for n in DIAG_SAMPLES]

    failures = []
    for path in paths:
        if not path.exists():
            continue
        msgs = lsp_diag_for(path)
        if msgs:
            failures.append((path.name, msgs))
            print(f"FAIL {path.name}: {msgs[0][:80]}")
        else:
            print(f"OK   {path.name}")

    tier10 = EXAMPLES / "tier10_demo.afr"
    if tier10.exists():
        symbols = lsp_symbols_for(tier10)
        if "double" not in symbols:
            failures.append(("tier10_demo.afr", ["documentSymbol 'double' manquant"]))
            print("FAIL tier10_demo.afr: symbole 'double' absent")
        else:
            print("OK   tier10_demo.afr (symbols)")

    if failures:
        print(f"\n{len(failures)} échec(s) LSP")
        return 1
    print("\nTous les tests LSP OK")
    return 0


if __name__ == "__main__":
    sys.exit(main())
