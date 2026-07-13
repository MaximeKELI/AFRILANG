import 'package:flutter/material.dart';
import 'package:flutter/services.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:google_fonts/google_fonts.dart';

import '../theme/afrilang_theme.dart';
import 'code_highlight.dart';
import 'motion.dart';

class AfrBrandMark extends StatelessWidget {
  const AfrBrandMark({super.key, this.size = 22});
  final double size;

  @override
  Widget build(BuildContext context) {
    return Text(
      'AFRILANG',
      style: GoogleFonts.plusJakartaSans(
        fontSize: size,
        fontWeight: FontWeight.w800,
        letterSpacing: -0.5,
        color: Theme.of(context).colorScheme.primary,
      ),
    );
  }
}

class SectionLabel extends StatelessWidget {
  const SectionLabel(this.text, {super.key});
  final String text;

  @override
  Widget build(BuildContext context) {
    return Text(
      text.toUpperCase(),
      style: GoogleFonts.plusJakartaSans(
        fontSize: 12,
        fontWeight: FontWeight.w700,
        letterSpacing: 1.2,
        color: AfrColors.primary,
      ),
    );
  }
}

class FadeSlideIn extends StatelessWidget {
  const FadeSlideIn({
    super.key,
    required this.child,
    this.delay = Duration.zero,
    this.offsetY = 18,
  });

  final Widget child;
  final Duration delay;
  final double offsetY;

  @override
  Widget build(BuildContext context) {
    return child
        .animate(delay: delay)
        .fadeIn(duration: 480.ms, curve: Curves.easeOutCubic)
        .slideY(begin: offsetY / 80, end: 0, duration: 520.ms, curve: Curves.easeOutCubic);
  }
}

class CodePanel extends StatelessWidget {
  const CodePanel({
    super.key,
    required this.code,
    this.filename = 'main.afr',
    this.maxHeight,
  });

  final String code;
  final String filename;
  final double? maxHeight;

  @override
  Widget build(BuildContext context) {
    final body = Container(
      width: double.infinity,
      decoration: BoxDecoration(
        color: AfrColors.codeBg,
        borderRadius: BorderRadius.circular(14),
        boxShadow: [
          BoxShadow(
            color: AfrColors.primary.withValues(alpha: 0.12),
            blurRadius: 24,
            offset: const Offset(0, 10),
          ),
        ],
      ),
      child: Column(
        crossAxisAlignment: CrossAxisAlignment.stretch,
        children: [
          Container(
            padding: const EdgeInsets.symmetric(horizontal: 14, vertical: 10),
            decoration: const BoxDecoration(
              color: AfrColors.codePanelHeader,
              borderRadius: BorderRadius.vertical(top: Radius.circular(14)),
            ),
            child: Row(
              children: [
                _dot(const Color(0xFFFF5F56)),
                const SizedBox(width: 6),
                _dot(const Color(0xFFFFBD2E)),
                const SizedBox(width: 6),
                _dot(const Color(0xFF27C93F)),
                const SizedBox(width: 12),
                Expanded(
                  child: Text(
                    filename,
                    style: afrMono(fontSize: 12, color: const Color(0xFF94A3B8)),
                  ),
                ),
                IconButton(
                  tooltip: 'Copier',
                  iconSize: 18,
                  visualDensity: VisualDensity.compact,
                  onPressed: () {
                    Clipboard.setData(ClipboardData(text: code));
                    ScaffoldMessenger.of(context).showSnackBar(
                      const SnackBar(content: Text('Code copié'), duration: Duration(seconds: 1)),
                    );
                  },
                  icon: const Icon(Icons.copy_rounded, color: Color(0xFF94A3B8)),
                ),
              ],
            ),
          ),
          Padding(
            padding: const EdgeInsets.fromLTRB(14, 12, 14, 16),
            child: AfrCodeHighlight(code: code),
          ),
        ],
      ),
    )
        .animate()
        .fadeIn(duration: 400.ms)
        .slideY(begin: 0.04, end: 0, curve: Curves.easeOutCubic);

    if (maxHeight == null) return body;
    return ConstrainedBox(
      constraints: BoxConstraints(maxHeight: maxHeight!),
      child: SingleChildScrollView(child: body),
    );
  }

  Widget _dot(Color c) => Container(
        width: 10,
        height: 10,
        decoration: BoxDecoration(color: c, shape: BoxShape.circle),
      )
          .animate(onPlay: (ctrl) => ctrl.repeat(reverse: true))
          .scale(begin: const Offset(0.9, 0.9), end: const Offset(1.05, 1.05), duration: 1800.ms);
}


class AfrPrimaryButton extends StatelessWidget {
  const AfrPrimaryButton({
    super.key,
    required this.label,
    required this.onPressed,
    this.icon,
  });

  final String label;
  final VoidCallback? onPressed;
  final IconData? icon;

  @override
  Widget build(BuildContext context) {
    return ElevatedButton.icon(
      onPressed: onPressed,
      icon: Icon(icon ?? Icons.arrow_forward_rounded, size: 18),
      label: Text(label),
    ).animate(onPlay: (c) => c.repeat(reverse: true)).shimmer(
          delay: 2.seconds,
          duration: 1600.ms,
          color: Colors.white24,
        );
  }
}

class StatRow extends StatelessWidget {
  const StatRow({super.key, required this.items});

  /// (numeric value for animation, display suffix, label) — or use display string via suffix-only.
  final List<({num? count, String display, String label})> items;

  @override
  Widget build(BuildContext context) {
    return Wrap(
      spacing: 12,
      runSpacing: 12,
      children: [
        for (var i = 0; i < items.length; i++)
          FadeSlideIn(
            delay: (80 * i).ms,
            child: SoftPress(
              child: Container(
                width: 150,
                padding: const EdgeInsets.all(16),
                decoration: BoxDecoration(
                  color: Theme.of(context).cardColor,
                  borderRadius: BorderRadius.circular(14),
                  border: Border.all(color: AfrColors.border.withValues(alpha: 0.8)),
                ),
                child: Column(
                  crossAxisAlignment: CrossAxisAlignment.start,
                  children: [
                    if (items[i].count != null)
                      AnimatedCounter(value: items[i].count!, suffix: items[i].display)
                    else
                      Text(
                        items[i].display,
                        style: GoogleFonts.plusJakartaSans(
                          fontSize: 22,
                          fontWeight: FontWeight.w800,
                          color: AfrColors.primary,
                        ),
                      ),
                    const SizedBox(height: 4),
                    Text(
                      items[i].label,
                      style: TextStyle(
                        fontSize: 12,
                        color: Theme.of(context).colorScheme.onSurface.withValues(alpha: 0.65),
                      ),
                    ),
                  ],
                ),
              ),
            ),
          ),
      ],
    );
  }
}

class PkgRow extends StatelessWidget {
  const PkgRow({
    super.key,
    required this.name,
    required this.version,
    required this.description,
    this.blessed = false,
    this.onTap,
  });

  final String name;
  final String version;
  final String description;
  final bool blessed;
  final VoidCallback? onTap;

  @override
  Widget build(BuildContext context) {
    return SoftPress(
      onTap: onTap,
      child: Container(
        width: double.infinity,
        margin: const EdgeInsets.only(bottom: 10),
        padding: const EdgeInsets.all(14),
        decoration: BoxDecoration(
          border: Border(
            bottom: BorderSide(color: AfrColors.border.withValues(alpha: 0.9)),
          ),
        ),
        child: Column(
          crossAxisAlignment: CrossAxisAlignment.start,
          children: [
            Row(
              children: [
                if (blessed)
                  const Padding(
                    padding: EdgeInsets.only(right: 6),
                    child: Text('★', style: TextStyle(color: AfrColors.accent, fontSize: 16)),
                  ),
                Text(name, style: const TextStyle(fontWeight: FontWeight.w800)),
                const SizedBox(width: 8),
                Container(
                  padding: const EdgeInsets.symmetric(horizontal: 8, vertical: 2),
                  decoration: BoxDecoration(
                    border: Border.all(color: AfrColors.border),
                    borderRadius: BorderRadius.circular(6),
                  ),
                  child: Text('v$version', style: const TextStyle(fontSize: 12)),
                ),
              ],
            ),
            if (description.isNotEmpty) ...[
              const SizedBox(height: 6),
              Text(
                description,
                maxLines: 2,
                overflow: TextOverflow.ellipsis,
                style: TextStyle(
                  fontSize: 13,
                  color: Theme.of(context).colorScheme.onSurface.withValues(alpha: 0.65),
                ),
              ),
            ],
            const SizedBox(height: 6),
            Text(
              'afrilang pkg add $name',
              style: afrMono(fontSize: 12, color: AfrColors.primary),
            ),
          ],
        ),
      ),
    );
  }
}


class HeroMeshBackground extends StatelessWidget {
  const HeroMeshBackground({super.key, required this.child});
  final Widget child;

  @override
  Widget build(BuildContext context) {
    return Stack(
      children: [
        Positioned.fill(
          child: DecoratedBox(
            decoration: BoxDecoration(
              gradient: LinearGradient(
                begin: Alignment.topLeft,
                end: Alignment.bottomRight,
                colors: [
                  AfrColors.primary.withValues(alpha: 0.08),
                  AfrColors.bgSubtle,
                  AfrColors.accent.withValues(alpha: 0.06),
                ],
              ),
            ),
          ),
        ),
        Positioned(
          top: -40,
          right: -30,
          child: Container(
            width: 180,
            height: 180,
            decoration: BoxDecoration(
              shape: BoxShape.circle,
              color: AfrColors.primary.withValues(alpha: 0.12),
            ),
          )
              .animate(onPlay: (c) => c.repeat(reverse: true))
              .scale(begin: const Offset(0.92, 0.92), end: const Offset(1.05, 1.05), duration: 4.seconds)
              .blur(begin: const Offset(0, 0), end: const Offset(2, 2), duration: 4.seconds),
        ),
        child,
      ],
    );
  }
}

class EmptyError extends StatelessWidget {
  const EmptyError({super.key, required this.message, this.onRetry});
  final String message;
  final VoidCallback? onRetry;

  @override
  Widget build(BuildContext context) {
    return Center(
      child: Padding(
        padding: const EdgeInsets.all(24),
        child: Column(
          mainAxisSize: MainAxisSize.min,
          children: [
            const Icon(Icons.cloud_off_rounded, size: 48, color: AfrColors.textSecondary),
            const SizedBox(height: 12),
            Text(message, textAlign: TextAlign.center),
            if (onRetry != null) ...[
              const SizedBox(height: 16),
              OutlinedButton(onPressed: onRetry, child: const Text('Réessayer')),
            ],
          ],
        ),
      ),
    );
  }
}
