# AFRILANG platform support (product)

> Honest matrix — not OS parity with Go/Rust.

## Primary

| Host / target | Status |
|---------------|--------|
| Linux x86_64 `native` | **Primary** — full stdlib, CI, sandbox (rlimits + seccomp + Landlock) |
| `linux-arm64` cross (`aarch64-linux-gnu-g++`) | Supported when toolchain present |
| `wasm32` (Emscripten) | Supported **subset** — see [`WASM_COMPAT.md`](WASM_COMPAT.md) |

## Secondary (host binaries)

| Host | Status |
|------|--------|
| Windows / macOS **host** builds | Secondary — CI smoke + release artifacts (`native` on that OS) |
| `--target windows` / `--target macos` | **Not provided** — no cross-OS targets |

Secondary hosts inherit host C++ linking. Process spawn, SDL paths, and sandbox differ:

| Capability | Linux | macOS | Windows (MinGW) |
|------------|-------|-------|-----------------|
| `afrilang --run` | fork + Landlock/seccomp | fork + rlimits | `CreateProcess` (no Landlock) |
| `std/process` | posix_spawn | posix_spawn | stub (−1) |
| GUI / SDL | `/usr/include/SDL2` | Homebrew `/opt/homebrew` + `/usr/local` | host-dependent |
| Root detection | `/proc/self/exe` | `_NSGetExecutablePath` | `GetModuleFileNameW` |

## CLI targets (`--target`)

| Value | Meaning |
|-------|---------|
| `native` | Host `g++` / `clang++` |
| `linux-x64` | **Alias** of `native` (not a separate cross) |
| `linux-arm64` | Cross to `aarch64-linux-gnu-g++` |
| `wasm32` | Emscripten → Node (or web pack) |

## Release artifact tags (`install.sh` / `package-release.sh`)

| Tag | Meaning |
|-----|---------|
| `linux-x86_64` | Linux amd64 release tarball |
| `linux-arm64` | Linux aarch64 release tarball |
| `macos-arm64` | Apple Silicon release tarball |
| `macos-x86_64` | Intel Mac release tarball |
| `windows-x86_64` | Windows release zip |

These tags are what GitHub Releases and `install.sh` use — distinct from CLI `--target`
(`native` / `linux-x64` alias / `wasm32`).

## Recommendation

- Develop and CI on **Linux native**.
- Secondary host smokes (macOS / Windows MSYS2) run `version` + `hello` + conformance subset — not stdlib/FFI parity.
- Use WASM for sandboxed demos (no SDL/net/fs/threads); native-only imports are **rejected** at compile time.
- Mobile (`mobile/afrilang`) is a **Flutter client** of the web API — not a native AFRILANG runtime.
- Gap tests: `bash scripts/test_gaps.sh 3` — see [`GAPS.md`](GAPS.md).

See also [`SECURITY.md`](../SECURITY.md), [`WASM_COMPAT.md`](WASM_COMPAT.md), [`GAPS.md`](GAPS.md).
