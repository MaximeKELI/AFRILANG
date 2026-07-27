# Deploy field_ops — monobinaire & cibles

> Preuve **A+B** côté ops : un exécutable utilisateur à copier, pas une stack
> Python/Node à installer. Honnêteté : dépendances dynamiques (SQLite, libstdc++).

## Modèle

```
src/*.afr  →  afrilang build  →  build/field_ops  →  machine terrain / serveur
```

| Claim | Réalité |
|-------|---------|
| Un binaire applicatif | Oui — `build/field_ops` |
| Zéro runtime AFRILANG | Oui — pas d’interpréteur à embarquer |
| 100 % statique | **Non** — lie `libsqlite3`, `libstdc++`, `libc` (voir `ldd`) |
| Cross Windows/macOS via `--target` | **Non** — voir [`docs/PLATFORM.md`](../../docs/PLATFORM.md) |

## Build natif (Linux host)

```bash
cd examples/apps/field_ops
afrilang pkg install
afrilang build
./build/field_ops
```

Sortie : `build/field_ops` (ELF host). Vérifier les libs :

```bash
file build/field_ops
ldd build/field_ops
# libsqlite3.so.0 doit être résolue sur la cible
```

### Prérequis cible

- glibc compatible (même famille Linux que le host de build, en pratique)
- `libsqlite3` installé (`apt install libsqlite3-0` / équivalent)
- Répertoire writable pour la DB (défaut relatif `build/field_ops.db` — passez un chemin absolu en prod si vous adaptez le code)

## Cross `linux-arm64`

Quand la toolchain est présente (`aarch64-linux-gnu-g++`) :

```bash
afrilang build --target linux-arm64
file build/field_ops   # doit indiquer ARM aarch64
```

Sur la cible ARM64 : même contrainte SQLite (`libsqlite3` aarch64).

Sans toolchain : le build échoue clairement — installer
`g++-aarch64-linux-gnu` (Debian/Ubuntu) ou équivalent.

Alias : `--target linux-x64` ≡ `native` (pas un cross distinct).

## Cibles non adaptées à field_ops

| Cible | Pourquoi |
|-------|----------|
| `wasm32` | `storex` / SQLite / FS hors sous-ensemble WASM — voir [`WASM_COMPAT.md`](../../docs/WASM_COMPAT.md) |
| `--target windows` / `macos` | Non fournis (cross-OS) |

Pour Windows/macOS : compiler **en host** sur cette OS (`afrilang build` natif), pas depuis Linux.

## Déploiement minimal

1. Build sur CI Linux (x86_64 ou arm64 selon flotte).
2. Copier `build/field_ops` vers la machine.
3. Installer `libsqlite3` si absent.
4. Lancer : `./field_ops` (ou unit/systemd/cron selon le métier).
5. Persistance : fichier SQLite local — pas de cloud requis (vertical B).

### Conteneur (optionnel)

Esquisse (Debian slim + sqlite) — pas un produit cloud AFRILANG :

```dockerfile
FROM debian:bookworm-slim
RUN apt-get update && apt-get install -y --no-install-recommends libsqlite3-0 \
    && rm -rf /var/lib/apt/lists/*
COPY field_ops /app/field_ops
WORKDIR /app
CMD ["/app/field_ops"]
```

Helpers texte Procfile/Dockerfile : paquet `deployx` — pas AWS/K8s managé
([`docs/DIST.md`](../../docs/DIST.md)).

## Smoke deploy

```bash
bash scripts/check_field_ops_deploy.sh
```

Vérifie : build natif, ELF, présence de `libsqlite3` dans `ldd`, exécution → `field_ops OK`.

## Liens

- App : [`README.md`](README.md)
- Plateformes CLI : [`docs/PLATFORM.md`](../../docs/PLATFORM.md)
- Distribution compilateur : [`docs/DIST.md`](../../docs/DIST.md)
- Positionnement A+B : [README racine — Problème résolu](../../README.md#problème-résolu)
