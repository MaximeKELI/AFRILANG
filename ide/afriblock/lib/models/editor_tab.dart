class EditorTab {
  EditorTab({
    required this.path,
    required this.content,
    this.dirty = false,
  });

  final String path;
  String content;
  bool dirty;
  String savedContent = '';

  String get name {
    final i = path.replaceAll('\\', '/').lastIndexOf('/');
    return i < 0 ? path : path.substring(i + 1);
  }

  void markSaved() {
    savedContent = content;
    dirty = false;
  }

  void applyEdit(String next) {
    content = next;
    dirty = content != savedContent;
  }
}
