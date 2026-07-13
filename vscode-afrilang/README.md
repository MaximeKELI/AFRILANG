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

### Icône des fichiers `.afr`

Les fichiers `.afr` affichent le logo AFRILANG dans l'explorateur (via l'icône de langage + thème Seti).

Si la coloration ou l'icône n'apparaissent pas :

1. **Réinstallez** l'extension :
   ```bash
   cd vscode-afrilang && ./install.sh
   ```
2. **Rechargez** la fenêtre : *Developer: Reload Window*
3. Vérifiez le mode langage en bas à droite : **AFRILANG** (pas « Plain Text »)
4. **Cursor Glass / Agents Window** : bug connu — les grammaires d'extensions
   (dont AFRILANG) ne s'appliquent souvent pas dans la vue Agents.
   Ouvrez le fichier dans l'**éditeur classique** (IDE) : couleurs + logo y fonctionnent.
5. **Optionnel** — thème d'icônes dédié :
   ```json
   { "workbench.iconTheme": "afrilang-icons" }
   ```

## Commandes

- `AFRILANG: Exécuter le fichier`
- `AFRILANG: Vérifier le fichier`
- `AFRILANG: Redémarrer le serveur LSP`
