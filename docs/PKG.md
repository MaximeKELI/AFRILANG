# Guide des paquets AFRILANG

Équivalent pratique de **Nimble** / **Shards** pour AFRILANG.

## Méthode en 6 étapes

1. **Créer** — `afrilang init` / `pkg init`  
2. **Déclarer** — `[dependencies]` dans `afrilang.toml` (version, git, path)  
3. **Synchroniser** — `pkg sync` (index distant)  
4. **Installer** — `pkg install` (respecte `afrilang.lock` s’il existe)  
5. **Tester** — `pkg test` / `afrilang test`  
6. **Publier** — `pkg publish` (+ `--remote` si registre)

Guide web détaillé (bilingue) : `/docs/package-manager/`.

## Fichiers projet

| Fichier | Rôle |
|---------|------|
| `afrilang.toml` | Métadonnées + `[dependencies]` |
| `afrilang.lock` | Versions exactes installées (source de vérité pour `install`) |
| `vendor/` | Copies locales des paquets |
| `manifest.toml` | Métadonnées d’un **paquet** (bibliothèque) |
| `packages/index.json` | Index local |
| `packages/remote-index.json` | Index distant (`pkg sync`) |

## Créer un projet ou un paquet

```bash
afrilang init mon_app              # application
afrilang init mon_lib --lib        # alias de pkg init
afrilang pkg init mon_lib          # paquet bibliothèque
cd mon_lib && afrilang pkg test    # self-vendor + tests/
afrilang doc .                     # docs/api/
```

## Dépendances

### Registre (local ou distant)

```toml
[dependencies]
math = "0.1.0"
strings = "^0.1.0"
```

```bash
afrilang pkg sync                  # télécharge remote-index.json
afrilang pkg add math              # local packages/ ou clone via url/method
afrilang pkg install
afrilang pkg update
```

Si le paquet n’est pas dans `packages/<name>` mais apparaît dans l’index avec
`"method":"git"` + `"url"`, AFRILANG clone comme **Nimble** (cache sous
`packages/.cache/`).

Voir le modèle : [`packages/remote-index.example.json`](../packages/remote-index.example.json).

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

## Transitivité & conflits

`install` / `update` résolvent les deps des `manifest.toml` **récursivement**.
Si deux contraintes sur le même nom sont incompatibles → erreur de conflit.

## Install vs update

- `pkg install` — si `afrilang.lock` existe, installe **exactement** le lock ; sinon résout depuis le toml et écrit le lock.
- `pkg update` — ignore les pins du lock, re-résout depuis les ranges du toml, réécrit le lock.

## Publier

### Local

```bash
afrilang pkg publish ./mon_lib
afrilang pkg list
```

### Distant (style Nimble)

```bash
export AFRILANG_PACKAGE_GIT_URL=https://github.com/vous/mon_lib
export AFRILANG_REGISTRY_TOKEN=...          # optionnel
export AFRILANG_REGISTRY_PUBLISH_URL=...    # optionnel
afrilang pkg publish ./mon_lib --remote
```

Écrit `registry-entry.json`, affiche la recette d’ajout au registre, et POST
si un token est défini.

Variables utiles :

| Variable | Rôle |
|----------|------|
| `AFRILANG_REGISTRY_URL` | URL de l’index JSON (`pkg sync`) |
| `AFRILANG_REGISTRY_PUBLISH_URL` | Endpoint POST publish |
| `AFRILANG_REGISTRY_TOKEN` | Bearer token |
| `AFRILANG_PACKAGE_GIT_URL` | URL git du paquet pour la recette |

## Imports

```afrilang
import pkg/math/math
```

## Paquets blessed (extraits)

Outre les utilitaires historiques (`math`, `fmt`, `numcheck`, …), le registre local
inclut notamment : `resultx`, `optionx`, `iterx`, `logx` (helpers Result/optionnel,
plages, log textuel). Lister : `afrilang pkg list --blessed`.
