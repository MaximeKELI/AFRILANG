# AFRILANG platform support (product)

> Honest matrix — not OS parity with Go/Rust.

## Primary

| Host / target | Status |
|---------------|--------|
| Linux x86_64 `native` | **Primary** — full stdlib, CI, sandbox |
| `linux-arm64` cross (`aarch64-linux-gnu-g++`) | Supported when toolchain present |
| `wasm32` (Emscripten) | Supported subset — see [`WASM_COMPAT.md`](WASM_COMPAT.md) |

## Secondary

| Host | Status |
|------|--------|
| Windows / macOS **host binaries** | Secondary — release artifacts may ship; run as host `native` |
| `--target windows` / `--target macos` | **Not provided** — do not claim cross OS targets |

Secondary hosts inherit host C++ linking conventions. Some FFI libs (`dl`, Linux `pthread`) are POSIX/Linux-shaped; see [`SECURITY.md`](../SECURITY.md) and NORMATIVE §9.

## CLI targets (`--target`)

Allowed values today: `native`, `linux-arm64`, `wasm32`.

## Recommendation

- Develop and CI on **Linux native**.
- Secondary host smokes (macOS / Windows) run `version` + a conformance subset — not stdlib/FFI parity.
- Use WASM for sandboxed demos (no SDL/net/fs).
- Treat Win/macOS as “binary may run”, not “stdlib/FFI parity”.
- Linux sandbox: rlimits + seccomp deny-list + Landlock FS (best-effort); other hosts: rlimits only.
