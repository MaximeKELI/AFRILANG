class EditorTab {
  EditorTab({
    required this.path,
    required this.content,
    this.dirty = false,
  }) : savedContent = content;

  final String path;
  String content;
  bool dirty;
  String savedContent;

  /// Bumped only when content is changed *outside* the text field
  /// (format-on-save, discard, AI insert, reload). CodeEditor syncs on this.
  int contentRevision = 0;

  String get name {
    final i = path.replaceAll('\\', '/').lastIndexOf('/');
    return i < 0 ? path : path.substring(i + 1);
  }

  void markSaved() {
    savedContent = content;
    dirty = false;
  }

  /// Edit coming from the text field (source of truth while typing).
  void applyEdit(String next) {
    content = next;
    dirty = content != savedContent;
  }

  /// Edit applied programmatically — editor widgets must pull this in.
  void applyExternalEdit(String next) {
    content = next;
    dirty = content != savedContent;
    contentRevision++;
  }
}
