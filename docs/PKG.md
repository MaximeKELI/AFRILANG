# Guide des paquets AFRILANG

Équivalent pratique de **Nimble** / **Shards** pour AFRILANG.

## Fichiers projet

| Fichier | Rôle |
|---------|------|
| `afrilang.toml` | Métadonnées + `[dependencies]` |
| `afrilang.lock` | Versions exactes installées (source de vérité pour `install`) |
| `vendor/` | Copies locales des paquets |
| `manifest.toml` | Métadonnées d’un **paquet** (bibliothèque) |

## Créer un projet ou un paquet

```bash
afrilang init mon_app              # application
afrilang init mon_lib --lib        # alias de pkg init
afrilang pkg init mon_lib          # paquet bibliothèque
```

## Dépendances

### Registre local

```toml
[dependencies]
math = "0.1.0"
strings = "^0.1.0"
```

```bash
afrilang pkg add math
afrilang pkg install
afrilang pkg update
```

### Semver

| Range | Signification |
|-------|----------------|
| `1.2.3` | `actual >= 1.2.3` (compat historique) |
| `^1.2.3` | `>= 1.2.3` et `< 2.0.0` |
| `~1.2.3` | `>= 1.2.3` et `< 1.3.0` |

### Git

```toml
[dependencies]
mylib = { git = "https://github.com/org/mylib.git", tag = "v0.1.0" }
```

```bash
afrilang pkg add mylib --git https://github.com/org/mylib.git --tag v0.1.0
```

### Path (développement local)

```toml
[dependencies]
mylib = { path = "../mylib" }
```

```bash
afrilang pkg add mylib --path ../mylib
```

## Install vs update

- `pkg install` — si `afrilang.lock` existe, installe **exactement** le lock ; sinon résout depuis le toml et écrit le lock.
- `pkg update` — ignore les pins du lock, re-résout depuis les ranges du toml, réécrit le lock.

## Publier (local)

```bash
afrilang pkg publish ./mon_lib
afrilang pkg list
```

Le publish distant authentifié est prévu en Vague 2 (voir `ROADMAP.md`).

## Imports

```afrilang
import pkg/math/math
```
