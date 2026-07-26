import 'package:flutter/material.dart';

import '../theme/afriblock_theme.dart';

/// Tokenizes AFRILANG source for syntax highlighting (mirrors mobile highlighter).
class AfrilangHighlighter {
  static const keywords = {
    'create', 'set', 'say', 'dire', 'function', 'fonction', 'returns', 'retourne',
    'end', 'fin', 'if', 'si', 'then', 'alors', 'else', 'sinon', 'while', 'tant',
    'for', 'pour', 'in', 'dans', 'class', 'classe', 'extends', 'étend', 'new',
    'nouveau', 'return', 'import', 'use', 'match', 'case',
    'async', 'await', 'true', 'false', 'null', 'and', 'or', 'not', 'is',
    'greater', 'than', 'equal', 'to', 'less', 'public', 'private',
    'field', 'this', 'super', 'export', 'module',
  };

  static const types = {
    'text', 'number', 'bool', 'list', 'map', 'void', 'any', 'int', 'float',
  };

  static TextSpan highlightSpan(String src, {double fontSize = 13.5}) {
    return TextSpan(children: _spans(src, fontSize: fontSize));
  }

  static List<InlineSpan> _spans(String src, {required double fontSize}) {
    final out = <InlineSpan>[];
    final re = RegExp(
      r'("(?:\\.|[^"\\])*")|(//[^\n]*)|(\b[A-Za-z_][A-Za-z0-9_]*\b)|(\d+\.?\d*)|(\S)|(\s+)',
      multiLine: true,
    );
    for (final m in re.allMatches(src)) {
      final s = m.group(0)!;
      if (m.group(1) != null) {
        out.add(TextSpan(
          text: s,
          style: afriblockMono(fontSize: fontSize, color: const Color(0xFF86EFAC)),
        ));
      } else if (m.group(2) != null) {
        out.add(TextSpan(
          text: s,
          style: afriblockMono(fontSize: fontSize, color: const Color(0xFF64748B)),
        ));
      } else if (m.group(3) != null) {
        final w = s.toLowerCase();
        Color c = AfriblockColors.text;
        var weight = FontWeight.w400;
        if (keywords.contains(w)) {
          c = const Color(0xFF93C5FD);
          weight = FontWeight.w600;
        } else if (types.contains(w)) {
          c = const Color(0xFFFCD34D);
        }
        out.add(TextSpan(
          text: s,
          style: afriblockMono(fontSize: fontSize, color: c, weight: weight),
        ));
      } else if (m.group(4) != null) {
        out.add(TextSpan(
          text: s,
          style: afriblockMono(fontSize: fontSize, color: const Color(0xFFFDBA74)),
        ));
      } else {
        out.add(TextSpan(
          text: s,
          style: afriblockMono(fontSize: fontSize),
        ));
      }
    }
    return out;
  }
}

class CodeEditor extends StatefulWidget {
  const CodeEditor({
    super.key,
    required this.path,
    required this.initialContent,
    required this.onChanged,
    this.onToggleBreakpoint,
    this.breakpoints = const {},
  });

  final String path;
  final String initialContent;
  final ValueChanged<String> onChanged;
  final ValueChanged<int>? onToggleBreakpoint;
  final Set<int> breakpoints;

  @override
  State<CodeEditor> createState() => _CodeEditorState();
}

class _CodeEditorState extends State<CodeEditor> {
  late final TextEditingController _controller;
  late final ScrollController _textScroll;
  late final ScrollController _gutterScroll;
  final FocusNode _focus = FocusNode();
  bool _syncing = false;

  static const _fontSize = 13.5;
  static const _lineHeight = 1.55;

  @override
  void initState() {
    super.initState();
    _controller = TextEditingController(text: widget.initialContent);
    _textScroll = ScrollController();
    _gutterScroll = ScrollController();
    _controller.addListener(() => setState(() {}));
    _textScroll.addListener(_onTextScroll);
  }

  void _onTextScroll() {
    if (_syncing || !_gutterScroll.hasClients) return;
    _syncing = true;
    if ((_gutterScroll.offset - _textScroll.offset).abs() > 0.5) {
      _gutterScroll.jumpTo(
        _textScroll.offset.clamp(
          0.0,
          _gutterScroll.position.maxScrollExtent,
        ),
      );
    }
    _syncing = false;
  }

  @override
  void didUpdateWidget(covariant CodeEditor oldWidget) {
    super.didUpdateWidget(oldWidget);
    if (oldWidget.path != widget.path) {
      _controller.text = widget.initialContent;
    } else if (widget.initialContent != oldWidget.initialContent &&
        widget.initialContent != _controller.text) {
      final sel = _controller.selection;
      _controller.value = TextEditingValue(
        text: widget.initialContent,
        selection: TextSelection(
          baseOffset: sel.baseOffset.clamp(0, widget.initialContent.length),
          extentOffset: sel.extentOffset.clamp(0, widget.initialContent.length),
        ),
      );
    }
  }

  @override
  void dispose() {
    _textScroll.removeListener(_onTextScroll);
    _controller.dispose();
    _textScroll.dispose();
    _gutterScroll.dispose();
    _focus.dispose();
    super.dispose();
  }

  int get _lineCount {
    final t = _controller.text;
    if (t.isEmpty) return 1;
    return '\n'.allMatches(t).length + 1;
  }

  @override
  Widget build(BuildContext context) {
    final isAfr = widget.path.toLowerCase().endsWith('.afr');
    final style = afriblockMono(
      fontSize: _fontSize,
      height: _lineHeight,
      color: isAfr ? Colors.transparent : AfriblockColors.text,
    );
    final lineCount = _lineCount;
    final gutterWidth = 28.0 + (lineCount.toString().length * 9.0);
    final lineBox = _fontSize * _lineHeight;

    return ColoredBox(
      color: AfriblockColors.bg,
      child: Row(
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          SizedBox(
            width: gutterWidth,
            child: ListView.builder(
              controller: _gutterScroll,
              physics: const ClampingScrollPhysics(),
              padding: const EdgeInsets.symmetric(vertical: 8),
              itemCount: lineCount,
              itemExtent: lineBox,
              itemBuilder: (context, i) {
                final line = i + 1;
                final hasBp = widget.breakpoints.contains(line);
                return InkWell(
                  onTap: widget.onToggleBreakpoint == null
                      ? null
                      : () => widget.onToggleBreakpoint!(line),
                  child: Row(
                    children: [
                      SizedBox(
                        width: 12,
                        child: hasBp
                            ? const Icon(Icons.circle, size: 8, color: AfriblockColors.error)
                            : null,
                      ),
                      Expanded(
                        child: Align(
                          alignment: Alignment.centerRight,
                          child: Padding(
                            padding: const EdgeInsets.only(right: 8),
                            child: Text(
                              '$line',
                              style: afriblockMono(
                                fontSize: _fontSize - 1,
                                color: AfriblockColors.textMuted,
                                height: _lineHeight,
                              ),
                            ),
                          ),
                        ),
                      ),
                    ],
                  ),
                );
              },
            ),
          ),
          Container(width: 1, color: AfriblockColors.border.withValues(alpha: 0.45)),
          Expanded(
            child: SingleChildScrollView(
              controller: _textScroll,
              padding: const EdgeInsets.fromLTRB(12, 8, 12, 8),
              child: Stack(
                children: [
                  if (isAfr)
                    Text.rich(
                      AfrilangHighlighter.highlightSpan(
                        _controller.text.isEmpty ? ' ' : _controller.text,
                        fontSize: _fontSize,
                      ),
                      style: afriblockMono(
                        fontSize: _fontSize,
                        height: _lineHeight,
                      ),
                    ),
                  TextField(
                    controller: _controller,
                    focusNode: _focus,
                    maxLines: null,
                    keyboardType: TextInputType.multiline,
                    cursorColor: AfriblockColors.primary,
                    style: style,
                    strutStyle: const StrutStyle(
                      fontSize: _fontSize,
                      height: _lineHeight,
                      forceStrutHeight: true,
                    ),
                    decoration: const InputDecoration(
                      border: InputBorder.none,
                      isCollapsed: true,
                      contentPadding: EdgeInsets.zero,
                    ),
                    onChanged: widget.onChanged,
                  ),
                ],
              ),
            ),
          ),
        ],
      ),
    );
  }
}
