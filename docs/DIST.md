# Distribution & releases (gap #9)

> Honest product doc. AFRILANG ships **install scripts + GitHub Releases + Docker**,
> not a managed cloud platform.

## Install

```bash
curl -fsSL https://raw.githubusercontent.com/MaximeKELI/AFRILANG/main/install.sh | bash
# or
bash install.sh --version v1.0.0 --prefix ~/.local/afrilang
bash install.sh --from-source   # cmake fallback
```

Platforms detected by `install.sh` / `scripts/package-release.sh`:

| Tag | Host |
|-----|------|
| `linux-x86_64` | Linux amd64 |
| `linux-arm64` | Linux aarch64 |
| `macos-arm64` | Apple Silicon |
| `macos-x86_64` | Intel Mac |
| `windows-x86_64` | Windows (MSYS2 / release zip) |

Archive layout: `afrilang-<ver>-<platform>/bin/afrilang` (+ `runtime/`, `stdlib/`, …).
Each archive gets a sibling `.sha256` file from `package-release.sh`.

## Release packaging

```bash
cmake --build build -j
bash scripts/package-release.sh 1.0.0 linux-x86_64
# → dist/afrilang-1.0.0-linux-x86_64.tar.gz (+ .sha256)
```

CI: `.github/workflows/release.yml` builds the platform matrix and uploads assets.

## Docker

`Dockerfile` + CI `docker-build` job — local/dev image, not a hosted SaaS.

## “Cloud”

`packages/deployx/` = Procfile/health helpers only. **Not** AWS/GCP/K8s product.

## Tests

```bash
bash scripts/test_gap_09_dist.sh
```

## Non-goals

- Managed multi-region cloud, Homebrew/Snap/winget as the gap deliverable
- Cosign/sigstore mandatory signing (`.sha256` is local integrity only)
- Live network download in gap9 CI (offline dry-run only)

## Related

- [`PLATFORM.md`](PLATFORM.md) · [`GAPS.md`](GAPS.md) · [`TRUST.md`](TRUST.md)

## Apps métier (monobinaire)

Le compilateur se distribue via Releases ; **vos** programmes `.afr` se déploient
comme un exécutable host (`afrilang build`). Exemple terrain A+B :
[`examples/apps/field_ops/DEPLOY.md`](../examples/apps/field_ops/DEPLOY.md).

