# AFRILANG — extension VS Code / Cursor

Coloration syntaxique, diagnostics LSP, complétion, formatage et exécution de fichiers `.afr`.

## Prérequis

- [AFRILANG](https://github.com/afrilang/afrilang) compilé et accessible dans le `PATH` (`afrilang --help`)
- Node.js 18+ (pour installer les dépendances de l'extension)

## Installation locale

Un script installe l'extension dans **Cursor**, **VS Code** et **VSCodium** (lien symbolique, méthode fiable) :

```bash
cd /chemin/vers/AFRILANG/vscode-afrilang
./install.sh
```

Équivalent : `./install-cursor.sh`

Puis dans l'éditeur : **Developer: Reload Window**.

### Par éditeur (alternative)

| Éditeur | Dossier extension |
|---------|-------------------|
| Cursor | `~/.cursor/extensions/afrilang.afrilang-*` |
| VS Code | `~/.vscode/extensions/afrilang.afrilang-*` |
| VSCodium | `~/.vscode-oss/extensions/afrilang.afrilang-*` |

Installation manuelle :

```bash
cd vscode-afrilang && npm install
code --install-extension .      # VS Code
codium --install-extension .    # VSCodium
```

`cursor --install-extension .` peut échouer silencieusement — préférez `./install.sh`.

## Configuration

| Paramètre | Défaut | Description |
|-----------|--------|-------------|
| `afrilang.serverPath` | `afrilang` | Chemin vers l'exécutable (absolu si hors PATH) |
| `afrilang.trace.server` | `off` | Trace LSP dans le panneau « AFRILANG LSP » |

Exemple `settings.json` :

```json
{
  "afrilang.serverPath": "/home/user/AFRILANG/build/afrilang",
  "editor.formatOnSave": true,
  "[afrilang]": { "editor.tabSize": 4 }
}
```

## Fonctionnalités

- **Diagnostics** — erreurs de compilation en temps réel (soulignés rouges)
- **Complétion** — mots-clés FR/EN + Phase 6 (`enum`, `match`, `nothing`, …)
- **Formatage** — `Shift+Alt+F` ou format on save via LSP
- **Exécuter** — bouton ▶ dans l'éditeur ou commande *AFRILANG: Exécuter le fichier*
- **Vérifier** — *AFRILANG: Vérifier le fichier* (`afrilang check`)
- **Icône** — carte d'Afrique pour les fichiers `.afr`

### Icône des fichiers `.afr`

Les fichiers `.afr` affichent le logo AFRILANG dans l'explorateur (VS Code / Cursor récent).

Si l'icône n'apparaît pas :

1. **Réinstallez** l'extension après mise à jour :
   ```bash
   cd vscode-afrilang && cursor --install-extension . --force
   ```
2. **Rechargez** la fenêtre : *Developer: Reload Window*
3. **Optionnel** — activez le thème d'icônes AFRILANG dans `settings.json` :
   ```json
   {
     "workbench.iconTheme": "afrilang-icons"
   }
   ```
   Ou : *Preferences → File Icon Theme → AFRILANG*

## Commandes

- `AFRILANG: Exécuter le fichier`
- `AFRILANG: Vérifier le fichier`
- `AFRILANG: Redémarrer le serveur LSP`
