import '../core/command_bus.dart';
import '../state/workbench_controller.dart';

abstract class AfriblockPlugin {
  String get id;
  String get name;
  String get description;

  Future<void> onActivate(PluginContext ctx);
  Future<void> onDeactivate() async {}
}

class PluginContext {
  PluginContext({
    required this.commands,
    required this.workbench,
  });

  final CommandBus commands;
  final WorkbenchController workbench;
}

class PluginHost {
  final plugins = <AfriblockPlugin>[];
  bool started = false;

  void register(AfriblockPlugin plugin) => plugins.add(plugin);

  Future<void> activateAll(PluginContext ctx) async {
    for (final p in plugins) {
      await p.onActivate(ctx);
    }
    started = true;
  }

  Future<void> deactivateAll() async {
    for (final p in plugins) {
      await p.onDeactivate();
    }
    started = false;
  }
}

class BuiltinAfrilangPlugin extends AfriblockPlugin {
  @override
  String get id => 'afrilang.language';

  @override
  String get name => 'AFRILANG Language';

  @override
  String get description => 'Highlighting, build, LSP, debug for .afr';

  @override
  Future<void> onActivate(PluginContext ctx) async {
    // Commands are registered by WorkbenchController.registerBuiltinCommands.
  }
}

class BuiltinGitPlugin extends AfriblockPlugin {
  @override
  String get id => 'afrilang.git';
  @override
  String get name => 'Git';
  @override
  String get description => 'Source control via git porcelain';
  @override
  Future<void> onActivate(PluginContext ctx) async {}
}

class BuiltinTerminalPlugin extends AfriblockPlugin {
  @override
  String get id => 'afrilang.terminal';
  @override
  String get name => 'Terminal';
  @override
  String get description => 'Integrated PTY terminal';
  @override
  Future<void> onActivate(PluginContext ctx) async {}
}
