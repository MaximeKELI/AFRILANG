import 'package:flutter/material.dart';
import 'package:flutter/services.dart';

import '../editor/text_ops.dart';
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

  static TextSpan highlightSpan(
    String src, {
    double fontSize = 13.5,
    Set<int> errorLines = const {},
  }) {
    return TextSpan(children: _spans(src, fontSize: fontSize, errorLines: errorLines));
  }

  static List<InlineSpan> _spans(
    String src, {
    required double fontSize,
    Set<int> errorLines = const {},
  }) {
    final out = <InlineSpan>[];
    final re = RegExp(
      r'("(?:\\.|[^"\\])*")|(//[^\n]*)|(\b[A-Za-z_][A-Za-z0-9_]*\b)|(\d+\.?\d*)|(\S)|(\s+)',
      multiLine: true,
    );
    var line = 1;
    for (final m in re.allMatches(src)) {
      final s = m.group(0)!;
      final onError = errorLines.contains(line);
      Color base;
      var weight = FontWeight.w400;
      if (m.group(1) != null) {
        base = const Color(0xFF86EFAC);
      } else if (m.group(2) != null) {
        base = const Color(0xFF64748B);
      } else if (m.group(3) != null) {
        final w = s.toLowerCase();
        base = AfriblockColors.text;
        if (keywords.contains(w)) {
          base = const Color(0xFF93C5FD);
          weight = FontWeight.w600;
        } else if (types.contains(w)) {
          base = const Color(0xFFFCD34D);
        }
      } else if (m.group(4) != null) {
        base = const Color(0xFFFDBA74);
      } else {
        base = AfriblockColors.text;
      }
      if (onError && m.group(6) == null) {
        // Keep whitespace styling subtle; emphasize tokens on error lines.
        base = AfriblockColors.error;
        weight = FontWeight.w600;
      }
      out.add(TextSpan(
        text: s,
        style: afriblockMono(fontSize: fontSize, color: base, weight: weight),
      ));
      line += '\n'.allMatches(s).length;
    }
    return out;
  }
}

class _AcceptGhostIntent extends Intent {
  const _AcceptGhostIntent();
}

class _RejectGhostIntent extends Intent {
  const _RejectGhostIntent();
}

class _GoToDefinitionIntent extends Intent {
  const _GoToDefinitionIntent();
}

class CodeEditor extends StatefulWidget {
  const CodeEditor({
    super.key,
    required this.path,
    required this.initialContent,
    required this.onChanged,
    this.contentRevision = 0,
    this.onCaretChanged,
    this.ghostText,
    this.onAcceptGhost,
    this.onRejectGhost,
    this.onToggleBreakpoint,
    this.breakpoints = const {},
    this.goToLine,
    this.goToColumn,
    this.onGoToLineHandled,
    this.hoverInfo,
    this.onGoToDefinition,
    this.onDismissHover,
    this.errorLines = const {},
    this.warningLines = const {},
  });

  final String path;
  final String initialContent;
  /// When this changes, [initialContent] is pulled into the field (external edits).
  final int contentRevision;
  final ValueChanged<String> onChanged;
  final ValueChanged<int>? onCaretChanged;
  final String? ghostText;
  final VoidCallback? onAcceptGhost;
  final VoidCallback? onRejectGhost;
  final ValueChanged<int>? onToggleBreakpoint;
  final Set<int> breakpoints;
  final int? goToLine;
  final int? goToColumn;
  final VoidCallback? onGoToLineHandled;
  final String? hoverInfo;
  final VoidCallback? onGoToDefinition;
  final VoidCallback? onDismissHover;
  /// 1-based lines with error diagnostics (red gutter + highlight).
  final Set<int> errorLines;
  /// 1-based lines with warnings (amber gutter).
  final Set<int> warningLines;

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
    _controller.addListener(_onControllerTick);
    _textScroll.addListener(_onTextScroll);
    if (widget.goToLine != null) {
      WidgetsBinding.instance.addPostFrameCallback((_) {
        if (!mounted || widget.goToLine == null) return;
        _jumpToLine(widget.goToLine!, column: widget.goToColumn);
        widget.onGoToLineHandled?.call();
      });
    }
  }

  void _onControllerTick() {
    setState(() {});
    final sel = _controller.selection;
    if (sel.isValid) {
      widget.onCaretChanged?.call(sel.baseOffset.clamp(0, _controller.text.length));
    }
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
      _controller.value = TextEditingValue(
        text: widget.initialContent,
        selection: TextSelection.collapsed(
          offset: widget.initialContent.length,
        ),
      );
    } else if (widget.contentRevision != oldWidget.contentRevision &&
        widget.initialContent != _controller.text) {
      // Only pull external buffer updates (format / discard / AI insert).
      // Never clobber the field just because the parent rebuilt with a stale
      // [initialContent] string — that was wiping unsaved edits on Run.
      final sel = _controller.selection;
      _controller.value = TextEditingValue(
        text: widget.initialContent,
        selection: TextSelection(
          baseOffset: sel.baseOffset.clamp(0, widget.initialContent.length),
          extentOffset: sel.extentOffset.clamp(0, widget.initialContent.length),
        ),
      );
    }
    if (widget.goToLine != null &&
        (widget.goToLine != oldWidget.goToLine ||
            widget.goToColumn != oldWidget.goToColumn)) {
      WidgetsBinding.instance.addPostFrameCallback((_) {
        if (!mounted) return;
        _jumpToLine(widget.goToLine!, column: widget.goToColumn);
        widget.onGoToLineHandled?.call();
      });
    }
  }

  void _jumpToLine(int line, {int? column}) {
    final text = _controller.text;
    final offset = TextOps.offsetAtLine(text, line, column: column ?? 1);
    _controller.selection = TextSelection.collapsed(offset: offset);
    widget.onCaretChanged?.call(offset);
    final lineBox = _fontSize * _lineHeight;
    final target = ((line - 1) * lineBox).clamp(0.0, double.infinity);
    if (_textScroll.hasClients) {
      _textScroll.jumpTo(
        target.clamp(0.0, _textScroll.position.maxScrollExtent),
      );
    }
    _focus.requestFocus();
    setState(() {});
  }

  @override
  void dispose() {
    _controller.removeListener(_onControllerTick);
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

  int get _caret {
    final sel = _controller.selection;
    if (!sel.isValid) return _controller.text.length;
    return sel.baseOffset.clamp(0, _controller.text.length);
  }

  void _acceptGhost() {
    final ghost = widget.ghostText;
    if (ghost == null || ghost.isEmpty) return;
    final text = _controller.text;
    final caret = _caret;
    final next = text.substring(0, caret) + ghost + text.substring(caret);
    final newCaret = caret + ghost.length;
    _controller.value = TextEditingValue(
      text: next,
      selection: TextSelection.collapsed(offset: newCaret),
    );
    widget.onChanged(next);
    widget.onAcceptGhost?.call();
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
    final ghost = widget.ghostText;
    final hasGhost = ghost != null && ghost.isNotEmpty;
    final caret = _caret;
    final before = _controller.text.substring(0, caret);
    final hover = widget.hoverInfo;

    return ColoredBox(
      color: AfriblockColors.bg,
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          if (hover != null && hover.isNotEmpty)
            Material(
              color: AfriblockColors.panelElevated,
              child: Padding(
                padding: const EdgeInsets.symmetric(horizontal: 10, vertical: 6),
                child: Row(
                  children: [
                    const Icon(Icons.info_outline, size: 14, color: AfriblockColors.primary),
                    const SizedBox(width: 8),
                    Expanded(
                      child: Text(
                        hover.replaceAll(RegExp(r'\*\*'), ''),
                        maxLines: 3,
                        overflow: TextOverflow.ellipsis,
                        style: afriblockMono(fontSize: 11.5, color: AfriblockColors.text),
                      ),
                    ),
                    IconButton(
                      tooltip: 'Go to Definition (F12)',
                      iconSize: 16,
                      onPressed: widget.onGoToDefinition,
                      icon: const Icon(Icons.subdirectory_arrow_right),
                    ),
                    IconButton(
                      tooltip: 'Dismiss',
                      iconSize: 16,
                      onPressed: widget.onDismissHover,
                      icon: const Icon(Icons.close, size: 14),
                    ),
                  ],
                ),
              ),
            ),
          Expanded(
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
                      final isError = widget.errorLines.contains(line);
                      final isWarn = !isError && widget.warningLines.contains(line);
                      final numColor = isError
                          ? AfriblockColors.error
                          : isWarn
                              ? AfriblockColors.warning
                              : AfriblockColors.textMuted;
                      return InkWell(
                        onTap: widget.onToggleBreakpoint == null
                            ? null
                            : () => widget.onToggleBreakpoint!(line),
                        child: ColoredBox(
                          color: isError
                              ? AfriblockColors.error.withValues(alpha: 0.18)
                              : isWarn
                                  ? AfriblockColors.warning.withValues(alpha: 0.12)
                                  : Colors.transparent,
                          child: Row(
                            children: [
                              SizedBox(
                                width: 12,
                                child: hasBp
                                    ? const Icon(Icons.circle, size: 8, color: AfriblockColors.error)
                                    : (isError
                                        ? const Icon(Icons.circle, size: 6, color: AfriblockColors.error)
                                        : null),
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
                                        color: numColor,
                                        height: _lineHeight,
                                        weight: isError ? FontWeight.w700 : FontWeight.w400,
                                      ),
                                    ),
                                  ),
                                ),
                              ),
                            ],
                          ),
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
                    child: Shortcuts(
                      shortcuts: {
                        if (hasGhost)
                          const SingleActivator(LogicalKeyboardKey.tab):
                              const _AcceptGhostIntent(),
                        if (hasGhost)
                          const SingleActivator(LogicalKeyboardKey.escape):
                              const _RejectGhostIntent(),
                        const SingleActivator(LogicalKeyboardKey.f12):
                            const _GoToDefinitionIntent(),
                      },
                      child: Actions(
                        actions: {
                          _AcceptGhostIntent: CallbackAction<_AcceptGhostIntent>(
                            onInvoke: (_) {
                              _acceptGhost();
                              return null;
                            },
                          ),
                          _RejectGhostIntent: CallbackAction<_RejectGhostIntent>(
                            onInvoke: (_) {
                              widget.onRejectGhost?.call();
                              return null;
                            },
                          ),
                          _GoToDefinitionIntent: CallbackAction<_GoToDefinitionIntent>(
                            onInvoke: (_) {
                              widget.onGoToDefinition?.call();
                              return null;
                            },
                          ),
                        },
                        child: Listener(
                          onPointerDown: (e) {
                            final keys = HardwareKeyboard.instance;
                            if (keys.isControlPressed || keys.isMetaPressed) {
                              WidgetsBinding.instance.addPostFrameCallback((_) {
                                widget.onGoToDefinition?.call();
                              });
                            }
                          },
                          child: Stack(
                            children: [
                              // Error / warning line backgrounds
                              if (widget.errorLines.isNotEmpty ||
                                  widget.warningLines.isNotEmpty)
                                Positioned.fill(
                                  child: IgnorePointer(
                                    child: CustomPaint(
                                      painter: _DiagnosticLinePainter(
                                        errorLines: widget.errorLines,
                                        warningLines: widget.warningLines,
                                        lineHeight: lineBox,
                                        lineCount: lineCount,
                                      ),
                                    ),
                                  ),
                                ),
                              if (isAfr)
                                Text.rich(
                                  AfrilangHighlighter.highlightSpan(
                                    _controller.text.isEmpty ? ' ' : _controller.text,
                                    fontSize: _fontSize,
                                    errorLines: widget.errorLines,
                                  ),
                                  style: afriblockMono(
                                    fontSize: _fontSize,
                                    height: _lineHeight,
                                  ),
                                ),
                              if (hasGhost)
                                Text.rich(
                                  TextSpan(
                                    children: [
                                      TextSpan(
                                        text: before.isEmpty ? '' : before,
                                        style: afriblockMono(
                                          fontSize: _fontSize,
                                          height: _lineHeight,
                                          color: Colors.transparent,
                                        ),
                                      ),
                                      TextSpan(
                                        text: ghost,
                                        style: afriblockMono(
                                          fontSize: _fontSize,
                                          height: _lineHeight,
                                          color: AfriblockColors.textMuted
                                              .withValues(alpha: 0.55),
                                        ),
                                      ),
                                    ],
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
                    ),
                  ),
                ),
              ],
            ),
          ),
        ],
      ),
    );
  }
}

class _DiagnosticLinePainter extends CustomPainter {
  _DiagnosticLinePainter({
    required this.errorLines,
    required this.warningLines,
    required this.lineHeight,
    required this.lineCount,
  });

  final Set<int> errorLines;
  final Set<int> warningLines;
  final double lineHeight;
  final int lineCount;

  @override
  void paint(Canvas canvas, Size size) {
    final errorPaint = Paint()..color = AfriblockColors.error.withValues(alpha: 0.16);
    final warnPaint = Paint()..color = AfriblockColors.warning.withValues(alpha: 0.10);
    final underline = Paint()
      ..color = AfriblockColors.error
      ..strokeWidth = 1.5
      ..style = PaintingStyle.stroke;

    for (var line = 1; line <= lineCount; line++) {
      final top = (line - 1) * lineHeight;
      if (errorLines.contains(line)) {
        canvas.drawRect(Rect.fromLTWH(0, top, size.width, lineHeight), errorPaint);
        final y = top + lineHeight - 2;
        // Wavy underline
        final path = Path()..moveTo(0, y);
        var x = 0.0;
        var up = true;
        while (x < size.width) {
          path.lineTo(x + 3, y + (up ? -1.5 : 1.5));
          x += 3;
          up = !up;
        }
        canvas.drawPath(path, underline);
      } else if (warningLines.contains(line)) {
        canvas.drawRect(Rect.fromLTWH(0, top, size.width, lineHeight), warnPaint);
      }
    }
  }

  @override
  bool shouldRepaint(covariant _DiagnosticLinePainter oldDelegate) {
    return oldDelegate.errorLines != errorLines ||
        oldDelegate.warningLines != warningLines ||
        oldDelegate.lineHeight != lineHeight ||
        oldDelegate.lineCount != lineCount;
  }
}
