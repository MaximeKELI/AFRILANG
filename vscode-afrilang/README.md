# AFRILANG — extension VS Code / Cursor / VSCodium

Coloration syntaxique, diagnostics, complétion LSP, formatage et exécution de fichiers `.afr`.

## Installation (utilisateurs)

Depuis l'éditeur : **Extensions** → rechercher **AFRILANG** → **Install**

```bash
code --install-extension afrilang.afrilang      # VS Code
codium --install-extension afrilang.afrilang    # VSCodium
# Cursor : même marketplace que VS Code
```

### Compilateur requis

L'extension appelle `afrilang` pour le LSP et l'exécution. [Compilez AFRILANG](https://github.com/MaximeKELI/AFRILANG) puis configurez :

```json
{
  "afrilang.serverPath": "/chemin/vers/AFRILANG/build/afrilang"
}
```

## Installation locale (développeurs)

```bash
cd vscode-afrilang
./install.sh
```

Puis **Developer: Reload Window**.

## Publication (mainteneurs)

Voir [PUBLISHING.md](./PUBLISHING.md).

```bash
cd vscode-afrilang
npm install
./publish.sh          # crée afrilang-1.4.0.vsix (+ publish si VSCE_PAT/OVSX_PAT)
```

Tag Git optionnel : `git tag vscode-v1.4.0 && git push origin vscode-v1.4.0` déclenche le workflow CI.

### Open VSX (VSCodium / Cursor)

Après publication, l'extension est disponible sur [Open VSX](https://open-vsx.org/extension/afrilang/afrilang) :

```bash
codium --install-extension afrilang.afrilang
```

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
- **Débugger** — *AFRILANG: Débugger le fichier* (adaptateur DAP + GDB, types Afrilang dans Variables)
- **Config debug** — *AFRILANG: Initialiser la config debug* → `launch.json` pour F5
- **Icône** — carte d'Afrique pour les fichiers `.afr`

### Icône + coloration des fichiers `.afr`

Le workspace active le thème d'icônes **AFRILANG** (`afrilang-icons`) : les `.afr`
affichent la carte d'Afrique. La grammaire TextMate colore mots-clés, types, chaînes, etc.

**Important — Cursor Agents Window (Glass)**  
La coloration et les icônes d'extensions **ne s'appliquent pas** dans la vue Agents
([bug Cursor connu](https://forum.cursor.com/t/cursor-3-0-agents-window-syntax-highlighting-is-broken/156630)).
Ce n'est pas un défaut de l'extension AFRILANG.

Pour voir couleurs + logo :

1. `Ctrl+Shift+P` → **Cursor: Open or Focus Editor Window**  
   (`cursor.openOrFocusEditorWindow`) — quitte Glass / Agents
2. Ouvrir `examples/hello.afr` dans cet éditeur classique
3. Barre d'état (bas à droite) = **AFRILANG**
4. *File Icon Theme* = **AFRILANG**

Réinstallation si besoin :

```bash
cd vscode-afrilang && ./install.sh
# ou :
cursor --install-extension ./afrilang-1.4.0.vsix
```

Puis **Developer: Reload Window**.

## Commandes

- `AFRILANG: Exécuter le fichier`
- `AFRILANG: Vérifier le fichier`
- `AFRILANG: Redémarrer le serveur LSP`
