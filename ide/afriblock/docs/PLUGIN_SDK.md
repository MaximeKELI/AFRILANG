# AFRIBLOCK Plugin SDK (internal)

In-process Dart plugins extend the workbench. There is **no** third-party
native (`.so`) loading until the API is frozen.

## Contract

```dart
abstract class AfriblockPlugin {
  String get id;
  String get name;
  String get description;
  Future<void> onActivate(PluginContext ctx);
  Future<void> onDeactivate();
}

class PluginContext {
  final CommandBus commands;
  final WorkbenchController workbench;
}
```

See [`lib/plugins/plugin_host.dart`](../lib/plugins/plugin_host.dart).

## Contributions (current)

| Hook | How |
|------|-----|
| Commands | `ctx.commands.register(IdeCommandDef(...))` |
| Views | Built-in sidebars; plugins listed under Extensions |
| Build targets | `ProjectService` / `kDefaultTargets` (extend carefully) |

## Built-in plugins

- `afrilang.language` — language + build surface
- `afrilang.git` — SCM
- `afrilang.terminal` — PTY

## Rules

1. Plugins must not block the UI isolate for long work — use async/`compute`.
2. Do not shell out to untrusted paths without user confirmation.
3. Prefer orchestrating `afrilang` over reimplementing language logic.
4. Document honesty: mark experimental APIs.

## Roadmap

- `contributeMenus` / `contributeViews` typed registries
- Problem matcher packs
- Freeze API → optional isolate-based sandbox for community plugins
