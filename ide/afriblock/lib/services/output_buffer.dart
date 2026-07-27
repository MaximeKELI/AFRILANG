/// Bounded console/output log — drops oldest content when over [maxChars].
class OutputBuffer {
  OutputBuffer({this.maxChars = 250000});

  final int maxChars;
  final StringBuffer _buf = StringBuffer();

  int get length => _buf.length;

  void write(Object? object) {
    _buf.write(object);
    _trim();
  }

  void writeln([Object? object = '']) {
    _buf.writeln(object);
    _trim();
  }

  void clear() => _buf.clear();

  @override
  String toString() => _buf.toString();

  void _trim() {
    if (_buf.length <= maxChars) return;
    final s = _buf.toString();
    final keep = maxChars - 28;
    final start = s.length - keep;
    _buf
      ..clear()
      ..write('…[output truncated]\n')
      ..write(start > 0 ? s.substring(start) : s);
  }
}
