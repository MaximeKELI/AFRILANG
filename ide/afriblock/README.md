# AFRIBLOCK

Desktop IDE for **AFRILANG**, built with Flutter.

Inspired by Code OSS workbench layout, Flutter-native editors (Lumide /
flutter_ide style), and the existing [`vscode-afrilang`](../../vscode-afrilang/)
CLI/LSP surface — without claiming VS Code parity.

## Features (phases A–F foundation)

- Workbench: activity bar, explorer, editor tabs/split, bottom panel, status bar, build toolbar
- Command palette (`Ctrl/Cmd+Shift+P`) + Quick Open (`Ctrl/Cmd+P`)
- Native `.afr` editor + breakpoints gutter + Outline
- `afrilang.toml` project detection + build targets (debug/release/test/wasm)
- Streamed **Build / Run / Check / Test / Debug** via local `afrilang`
- LSP client (stdio), format-on-save, Problems from build + LSP
- Git SCM, Find in Files, PTY terminal
- Themes (dark/light/HC), settings, plugin host
- Linux, Windows, and macOS desktop targets

## Still deepening

- Full GDB/MI DAP parity with vscode-afrilang
- Detachable tool windows, blame, multi-root workspace JSON polish
- Public plugin marketplace (explicit non-goal until API freeze)

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

World-class target architecture (AFRILANG-only):
[`docs/AFRIBLOCK_ARCHITECTURE.md`](../../docs/AFRIBLOCK_ARCHITECTURE.md).

Plugin SDK: [`docs/PLUGIN_SDK.md`](docs/PLUGIN_SDK.md).

Package desktop builds: `bash scripts/package-afriblock.sh`.

### Implemented phases (A–F foundation)

| Phase | In tree |
|-------|---------|
| A | `afrilang.toml` detect, streamed build, toolchain settings, Quick Open (`Ctrl+P`) |
| B | LSP client stdio, format-on-save, Outline |
| C | Build targets toolbar, Test Explorer |
| D | Debug sidebar, breakpoints gutter, `afrilang debug` launch |
| E | PTY terminal, Git SCM, Find in Files |
| F | Editor split, themes, plugin host + SDK doc, packaging script |

```
lib/
  workbench/ core/ project/ lsp/ debug/ git/ search/ terminal/ plugins/
  widgets/ services/ state/ theme/
```

Coexists with [`vscode-afrilang`](../../vscode-afrilang/) and
[`mobile/afrilang`](../../mobile/afrilang/) (web mirror) — different products.

## License

Same as the AFRILANG monorepo.
