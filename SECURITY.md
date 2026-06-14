# Security Policy

## Supported Versions

| Version | Supported |
|---------|-----------|
| 1.0.x   | Yes       |
| < 1.0   | No        |

## Reporting a Vulnerability

Please report security issues privately to the repository maintainer.
Do **not** open public issues for exploitable vulnerabilities.

Include: affected component, reproduction steps, impact assessment, suggested fix if any.

## Secure-by-Default

AFRILANG runs in **secure mode** unless `AFRILANG_INSECURE=1` is set.

In secure mode:

- No shell invocation (`std::system` removed; `execve` / `posix_spawn` only)
- Resource limits on untrusted execution (memory, CPU, file size, open FDs)
- Source size and program complexity limits
- Import depth and file count limits with path confinement
- FFI library allowlist at compile time
- Playground server disabled unless explicitly enabled
- Playground binds to `127.0.0.1` unless explicitly made public
- Temporary files isolated under a private sandbox directory
- Generated binaries compiled with stack protector, FORTIFY, and PIE when supported

## Environment Variables

| Variable | Default | Effect |
|----------|---------|--------|
| `AFRILANG_INSECURE=1` | off | Disables secure mode entirely |
| `AFRILANG_ALLOW_FFI=1` | off | Allows FFI when insecure mode is off (allowlist still applies) |
| `AFRILANG_ALLOW_SERVE=1` | off | Enables `afrilang serve` playground |
| `AFRILANG_SERVE_PUBLIC=1` | off | Binds playground to `0.0.0.0` instead of localhost |

## Known Risk Surfaces

### Playground (`afrilang serve`)

The web playground compiles and executes user-supplied code locally.
**Do not expose `afrilang serve` to untrusted networks without additional isolation.**

Mitigations in place:

- Disabled by default (`AFRILANG_ALLOW_SERVE=1` required)
- Localhost bind by default (`127.0.0.1`)
- Rate limiting (30 requests/minute per client IP)
- Request body size cap (64 KiB)
- Source validation (UTF-8, no null bytes, size limits)
- Sandboxed execution with timeout, memory, and CPU limits
- Output size cap with truncation flag
- Static files confined under `site/` root (path traversal blocked)
- Security headers: `X-Content-Type-Options`, `X-Frame-Options`, CSP

### REPL (`afrilang repl`)

Each REPL evaluation compiles and runs in a sandbox with the same resource limits as the playground.
Session files are stored in a private temporary directory, cleaned up on exit.

### CLI execution (`afrilang run --run`)

Post-compile execution uses sandboxed `execve` with resource limits instead of shell invocation.

### Foreign Function Interface (`extern from "lib"`)

FFI links against an allowlist of system libraries. Unknown library names are rejected at compile time.

### Package manager

Packages are copied from the local registry without cryptographic signatures.
Symlinks pointing outside the package tree are rejected.
Only install packages from trusted sources.

### Imports

Relative imports are resolved under the project root or AFRILANG home.
Path traversal (`..`) in import paths is rejected.

## Security Best Practices for Users

- Keep secure mode enabled (default)
- Run playground and REPL locally only
- Do not set `AFRILANG_SERVE_PUBLIC=1` unless you understand the risk
- Review `extern` declarations before compiling untrusted code
- Keep the compiler and system toolchain updated
