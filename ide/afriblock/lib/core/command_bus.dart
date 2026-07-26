import '../state/workbench_controller.dart';

typedef CommandHandler = Future<void> Function(WorkbenchController wb);

class IdeCommandDef {
  const IdeCommandDef({
    required this.id,
    required this.label,
    required this.run,
    this.shortcut,
    this.category = 'General',
  });

  final String id;
  final String label;
  final String? shortcut;
  final String category;
  final CommandHandler run;
}

class CommandBus {
  final _commands = <String, IdeCommandDef>{};

  void register(IdeCommandDef cmd) => _commands[cmd.id] = cmd;

  void registerAll(Iterable<IdeCommandDef> cmds) {
    for (final c in cmds) {
      register(c);
    }
  }

  IdeCommandDef? operator [](String id) => _commands[id];

  List<IdeCommandDef> get all => _commands.values.toList()
    ..sort((a, b) => a.label.compareTo(b.label));

  List<IdeCommandDef> filter(String query) {
    final q = query.trim().toLowerCase();
    if (q.isEmpty) return all;
    return all
        .where((c) =>
            c.label.toLowerCase().contains(q) ||
            c.id.toLowerCase().contains(q) ||
            c.category.toLowerCase().contains(q))
        .toList();
  }

  Future<void> execute(String id, WorkbenchController wb) async {
    final cmd = _commands[id];
    if (cmd == null) return;
    await cmd.run(wb);
  }
}
