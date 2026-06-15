# Publier l'extension AFRILANG

## Prérequis (une seule fois)

### 1. Créer l'éditeur « afrilang »

**VS Code Marketplace**

1. https://marketplace.visualstudio.com/manage/createpublisher
2. Publisher ID : `afrilang`
3. Créer un Personal Access Token Azure DevOps :
   - https://dev.azure.com → User settings → Personal access tokens
   - Scope : **Marketplace** → **Manage**
4. Exporter le token :
   ```bash
   export VSCE_PAT="votre_token_azure"
   ```

**Open VSX** (VSCodium)

1. https://open-vsx.org/ → Sign in (GitHub)
2. Créer le namespace `afrilang` (Settings → Namespaces)
3. Générer un access token
4. Exporter :
   ```bash
   export OVSX_PAT="votre_token_openvsx"
   ```

### 2. Publier

```bash
cd vscode-afrilang
chmod +x publish.sh
npm install
./publish.sh
```

Le script produit `afrilang-<version>.vsix` (ex. `afrilang-1.4.0.vsix`) avec :
- serveur LSP intégré via `afrilang.serverPath`
- adaptateur DAP (`debugAdapter.js`) + breakpoints `.afr`
- templates `launch.json` / `tasks.json`

## CI GitHub (optionnel)

Ajoutez ces secrets au dépôt GitHub (`Settings → Secrets`) :

| Secret | Description |
|--------|-------------|
| `VSCE_PAT` | Token Azure DevOps (Marketplace) |
| `OVSX_PAT` | Token Open VSX |

Puis créez un tag `vscode-v1.4.0` ou lancez le workflow **Publish Extension** manuellement.

## Après publication

Les utilisateurs installent depuis l'éditeur :

```
Extensions → rechercher « AFRILANG » → Install
```

Ou en ligne de commande :

```bash
code --install-extension afrilang.afrilang
codium --install-extension afrilang.afrilang
```

**Cursor** utilise le marketplace VS Code — l'extension apparaît aussi dans Cursor.

## Note

L'extension nécessite le compilateur `afrilang` (LSP, exécution). Les utilisateurs doivent [compiler AFRILANG](https://github.com/MaximeKELI/AFRILANG) ou configurer `afrilang.serverPath`.
