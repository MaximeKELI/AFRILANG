# Tooling & IDE surface (gap #8)

> Honest product doc. AFRILANG ships **CLI tooling + a hand-rolled LSP subset**,
> not rust-analyzer / clangd parity.

## CLI

| Command | Role |
|---------|------|
| `afrilang check file.afr` | Compile + semantic diagnostics (exit 0/1) |
| `afrilang fmt file.afr` | Pretty-print AST to stdout (`-w` to write) |
| `afrilang lsp` | Language server over stdio (JSON-RPC) |
| `afrilang lint` | Extra lint pass (when enabled) |
| `afrilang version` | Version banner |

## LSP subset (what exists)

Advertised / handled today (`src/lsp/server.cpp`):

- `initialize` / `shutdown` / `exit`
- `textDocument/didOpen|didChange|didClose` → `publishDiagnostics`
- completion, hover, definition, references, rename (text/outline based)
- document / workspace symbols
- formatting, codeAction (basic)

**Limits (honest):** custom JSON string matching (not a full LSP library);
rename/refs are text-oriented; not an incremental semantic index.

## Editor extension

`vscode-afrilang/` — LanguageClient launching `afrilang lsp`.

## AFRIBLOCK (desktop IDE)

`ide/afriblock/` — Flutter desktop workbench (Linux / Windows / macOS) for
editing `.afr` and driving `afrilang` build/run/check. Architecture target:
[`AFRIBLOCK_ARCHITECTURE.md`](AFRIBLOCK_ARCHITECTURE.md).

## Tests

```bash
bash scripts/test_gap_08_tooling.sh
bash scripts/check_tooling_smoke.sh
python3 scripts/test_lsp_diag.py          # clean examples → empty diags (CI)
```

Fixtures: `tests/gaps/tooling/`.

## Non-goals

- Claiming “LSP 1.0 complete” or IDE parity with mature languages
- Rewriting the VS Code extension as the gap deliverable
- Full DAP redesign

## Related

- [`GAPS.md`](GAPS.md) row 8
- [`LANGUAGE.md`](LANGUAGE.md) — syntax tour
- `vscode-afrilang/README.md`
- `ide/afriblock/README.md`
- [`AFRIBLOCK_ARCHITECTURE.md`](AFRIBLOCK_ARCHITECTURE.md)

