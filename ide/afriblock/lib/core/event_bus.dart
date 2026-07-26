/// Lightweight pub/sub for workbench modules.
class EventBus {
  final _handlers = <Type, List<void Function(Object)>>{};

  void on<T>(void Function(T event) handler) {
    _handlers.putIfAbsent(T, () => []).add((e) => handler(e as T));
  }

  void emit<T extends Object>(T event) {
    final list = _handlers[T];
    if (list == null) return;
    for (final h in List.of(list)) {
      h(event);
    }
  }

  void clear() => _handlers.clear();
}

class WorkspaceOpenedEvent {
  WorkspaceOpenedEvent(this.root);
  final String root;
}

class BuildFinishedEvent {
  BuildFinishedEvent({required this.exitCode, required this.targetId});
  final int exitCode;
  final String targetId;
}
