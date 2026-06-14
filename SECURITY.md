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

## Known Risk Surfaces

### Playground (`afrilang serve`)

The web playground compiles and executes user-supplied code locally.
**Do not expose `afrilang serve` to untrusted networks without additional isolation.**

Mitigations in place:
- Execution timeout (default 5 seconds)
- No shell invocation (`execve` direct)
- Static files confined under `site/` root (path traversal blocked)

### Foreign Function Interface (`extern from "lib"`)

FFI links against an allowlist of system libraries. Unknown library names are rejected at compile time.

### Package manager

Packages are copied from the local registry without cryptographic signatures.
Only install packages from trusted sources.

## Security Best Practices for Users

- Run playground and REPL locally only
- Review `extern` declarations before compiling untrusted code
- Keep the compiler and system toolchain updated
