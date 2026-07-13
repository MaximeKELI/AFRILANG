import 'package:flutter/material.dart';
import 'package:flutter_animate/flutter_animate.dart';
import 'package:google_fonts/google_fonts.dart';

import '../theme/afrilang_theme.dart';

class AnimatedCounter extends StatelessWidget {
  const AnimatedCounter({
    super.key,
    required this.value,
    this.suffix = '',
    this.prefix = '',
    this.duration = const Duration(milliseconds: 1200),
  });

  final num value;
  final String suffix;
  final String prefix;
  final Duration duration;

  @override
  Widget build(BuildContext context) {
    final target = value.toDouble();
    return TweenAnimationBuilder<double>(
      tween: Tween(begin: 0, end: target),
      duration: duration,
      curve: Curves.easeOutCubic,
      builder: (context, v, _) {
        final display = value is int ? v.round().toString() : v.toStringAsFixed(0);
        return Text(
          '$prefix$display$suffix',
          style: GoogleFonts.plusJakartaSans(
            fontSize: 22,
            fontWeight: FontWeight.w800,
            color: AfrColors.primary,
          ),
        );
      },
    );
  }
}

class LetterReveal extends StatelessWidget {
  const LetterReveal({
    super.key,
    required this.text,
    this.style,
    this.staggerMs = 28,
  });

  final String text;
  final TextStyle? style;
  final int staggerMs;

  @override
  Widget build(BuildContext context) {
    final base = style ?? Theme.of(context).textTheme.headlineMedium?.copyWith(fontWeight: FontWeight.w800);
    return Wrap(
      children: [
        for (var i = 0; i < text.length; i++)
          Text(text[i], style: base)
              .animate(delay: (staggerMs * i).ms)
              .fadeIn(duration: 280.ms, curve: Curves.easeOut)
              .slideY(begin: 0.35, end: 0, duration: 320.ms, curve: Curves.easeOutCubic),
      ],
    );
  }
}

class SkeletonBox extends StatelessWidget {
  const SkeletonBox({super.key, this.height = 16, this.width, this.radius = 8});
  final double height;
  final double? width;
  final double radius;

  @override
  Widget build(BuildContext context) {
    return Container(
      height: height,
      width: width ?? double.infinity,
      decoration: BoxDecoration(
        color: Theme.of(context).brightness == Brightness.dark
            ? const Color(0xFF1E293B)
            : const Color(0xFFE2E8F0),
        borderRadius: BorderRadius.circular(radius),
      ),
    )
        .animate(onPlay: (c) => c.repeat())
        .shimmer(duration: 1200.ms, color: Colors.white24);
  }
}

class HomeSkeleton extends StatelessWidget {
  const HomeSkeleton({super.key});

  @override
  Widget build(BuildContext context) {
    return ListView(
      padding: const EdgeInsets.all(20),
      children: const [
        SkeletonBox(height: 28, width: 160),
        SizedBox(height: 16),
        SkeletonBox(height: 18),
        SizedBox(height: 8),
        SkeletonBox(height: 18, width: 220),
        SizedBox(height: 24),
        SkeletonBox(height: 200, radius: 14),
        SizedBox(height: 24),
        Row(
          children: [
            Expanded(child: SkeletonBox(height: 72, radius: 14)),
            SizedBox(width: 10),
            Expanded(child: SkeletonBox(height: 72, radius: 14)),
          ],
        ),
      ],
    );
  }
}

class PulsingDot extends StatelessWidget {
  const PulsingDot({super.key, this.color = AfrColors.primary});
  final Color color;

  @override
  Widget build(BuildContext context) {
    return Container(
      width: 8,
      height: 8,
      decoration: BoxDecoration(color: color, shape: BoxShape.circle),
    )
        .animate(onPlay: (c) => c.repeat(reverse: true))
        .scale(begin: const Offset(0.7, 0.7), end: const Offset(1.2, 1.2), duration: 900.ms)
        .fade(begin: 0.5, end: 1);
  }
}

class SoftPress extends StatefulWidget {
  const SoftPress({super.key, required this.child, this.onTap});
  final Widget child;
  final VoidCallback? onTap;

  @override
  State<SoftPress> createState() => _SoftPressState();
}

class _SoftPressState extends State<SoftPress> {
  bool _down = false;

  @override
  Widget build(BuildContext context) {
    return GestureDetector(
      onTap: widget.onTap,
      onTapDown: (_) => setState(() => _down = true),
      onTapUp: (_) => setState(() => _down = false),
      onTapCancel: () => setState(() => _down = false),
      child: AnimatedScale(
        scale: _down ? 0.97 : 1,
        duration: const Duration(milliseconds: 120),
        curve: Curves.easeOut,
        child: widget.child,
      ),
    );
  }
}
