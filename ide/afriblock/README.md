# AFRIBLOCK

Desktop IDE for **AFRILANG**, built with Flutter.

Inspired by Code OSS workbench layout, Flutter-native editors (Lumide /
flutter_ide style), and the existing [`vscode-afrilang`](../../vscode-afrilang/)
CLI/LSP surface — without claiming VS Code parity.

## v0.1 features

- Workbench: activity bar, explorer, editor tabs, bottom panel, status bar
- Command palette (`Ctrl/Cmd+Shift+P`)
- Native `.afr` editor with line numbers + keyword highlighting
- **Run** / **Check** via local `afrilang` binary → Output + Problems
- Linux, Windows, and macOS desktop targets

## Non-goals (phase 2)

- Full LSP client (`afrilang lsp`)
- Integrated PTY terminal
- Git UI / DAP debugger

## Prerequisites

- Flutter 3.22+ with desktop enabled (`flutter config --enable-linux-desktop`, etc.)
- Optional: built AFRILANG compiler at `../../build/afrilang`

## Run

```bash
cd ide/afriblock
flutter pub get
flutter run -d linux          # or windows / macos
```

### Locate `afrilang`

Resolution order:

1. Env `AFRIBLOCK_AFRILANG=/path/to/afrilang`
2. Saved preference (Settings / About shows resolved path)
3. Relative monorepo candidates (`../../build/afrilang`, …)
4. `PATH` (`which afrilang`)

```bash
export AFRIBLOCK_AFRILANG=/home/you/AFRILANG/build/afrilang
flutter run -d linux
```

### Shortcuts

| Shortcut | Action |
|----------|--------|
| `Ctrl/Cmd+Shift+P` | Command palette |
| `Ctrl/Cmd+S` | Save |
| `F5` | Run current file |
| `Ctrl/Cmd+Shift+B` | Check current file |
| `Ctrl/Cmd+J` | Toggle panel |
| `Ctrl/Cmd+W` | Close tab |
| `Esc` | Close palette |

## Architecture

```
lib/
  workbench/     # shell layout (Code OSS-inspired)
  widgets/       # explorer, editor, panel, palette
  services/      # FileService, AfrilangCli, SettingsStore
  state/         # WorkbenchController
  theme/         # AFRIBLOCK dark identity
```

Coexists with [`vscode-afrilang`](../../vscode-afrilang/) and
[`mobile/afrilang`](../../mobile/afrilang/) (web mirror) — different products.

## License

Same as the AFRILANG monorepo.
