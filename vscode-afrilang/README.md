# AFRILANG — extension VS Code / Cursor

Coloration syntaxique, diagnostics LSP, complétion, formatage et exécution de fichiers `.afr`.

## Prérequis

- [AFRILANG](https://github.com/afrilang/afrilang) compilé et accessible dans le `PATH` (`afrilang --help`)
- Node.js 18+ (pour installer les dépendances de l'extension)

## Installation locale

```bash
# 1. Compiler le compilateur
cd /chemin/vers/AFRILANG/build && cmake .. && make

# 2. Installer l'extension
cd ../vscode-afrilang
npm install
code --install-extension .    # ou dans Cursor: cursor --install-extension .
```

Rechargez la fenêtre (*Developer: Reload Window*).

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
- **Icône** — carte d'Afrique pour `.afr` (thème d'icônes *AFRILANG* optionnel)

## Commandes

- `AFRILANG: Exécuter le fichier`
- `AFRILANG: Vérifier le fichier`
- `AFRILANG: Redémarrer le serveur LSP`
