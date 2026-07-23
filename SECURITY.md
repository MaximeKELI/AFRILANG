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
- On **Linux**: `PR_SET_NO_NEW_PRIVS` + seccomp-bpf deny-list (`ptrace`, `mount`,
  `reboot`, module load, `bpf`, …) **and** best-effort Landlock FS restrict for
  sandboxed `exec` (REPL / serve / `run --run`). Not a VM; Windows/macOS keep
  rlimits only — see `docs/PLATFORM.md`.
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
| `AFRILANG_SANITIZE=1` | off | Adds `-fsanitize=address,undefined` to host compile (use with `AFRILANG_INSECURE=1` when running) |
| `AFRILANG_EXTRA_CXXFLAGS` | empty | Extra host compiler flags (space-separated) |
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
- Linux seccomp deny-list + Landlock FS on sandboxed children
  (`scripts/check_sandbox_seccomp.sh`)
- Output size cap with truncation flag
- Static files confined under `site/` root (path traversal blocked)
- Security headers: `X-Content-Type-Options`, `X-Frame-Options`, CSP

### REPL (`afrilang repl`)

Each REPL evaluation compiles and runs in a sandbox with the same resource limits as the playground.
Session files are stored in a private temporary directory, cleaned up on exit.

### CLI execution (`afrilang run --run`)

Post-compile execution uses sandboxed `execve` with resource limits instead of shell invocation.

### Foreign Function Interface (`extern from "lib"`)

FFI links against a **shared compile-time allowlist** (`include/afrilang/ffi_allowlist.hpp`:
`m`/`c`/`pthread`/`dl`/`curl` and aliases). Unknown library names are rejected at
compile time. Secure mode still requires `AFRILANG_ALLOW_FFI=1` (or insecure mode).

Link flags are **host-aware** (e.g. no `-ldl` on Windows/Apple). See `docs/PLATFORM.md`.

### Package manager

Packages are verified by SHA-256 checksum (recorded in `packages/index.json`) at
install time. Symlinks pointing outside the package tree are rejected.

**Detached Ed25519 signatures (provenance).** Maintainers can sign a package's
directory hash:

```
# Generate a keypair once (keep the private key secret):
afrilang run - <<'AFR'
import "std/crypto"
use crypto
create priv = ed25519GenPrivate()
say priv
say ed25519PublicFromPrivate(priv)
AFR

# Sign a package (writes packages/signatures.json and reindexes):
afrilang pkg sign <name> <privateKeyHex>

# Or sign the representative blessed subset:
#   export AFRILANG_PKG_SIGN_KEY=<privateKeyHex>
#   bash scripts/sign_blessed_subset.sh

# Trust the public key by adding it to packages/trusted_keys.json:
#   ["<publicKeyHex>", ...]

# Verify checksum + signature:
afrilang pkg verify <name>
```

At install time, if a `sig` field is present in the index **and** at least one
trusted key is configured in `packages/trusted_keys.json`, the signature over the
package's SHA-256 must validate against a trusted key or the install is refused.

**Blessed packages** (`packages/blessed.json`) additionally **require** a verifiable
Ed25519 signature whenever trusted keys are configured — unsigned blessed packages
are refused at install. Sign all of them with:

```
export AFRILANG_PKG_SIGN_KEY=<privateKeyHex>
bash scripts/sign_blessed_all.sh
```

Non-blessed packages without a signature still install with checksum verification
only (when no `sig` is recorded).

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
