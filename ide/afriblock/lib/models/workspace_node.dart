class WorkspaceNode {
  WorkspaceNode({
    required this.path,
    required this.name,
    required this.isDirectory,
    this.children = const [],
    this.expanded = false,
  });

  final String path;
  final String name;
  final bool isDirectory;
  List<WorkspaceNode> children;
  bool expanded;
}
