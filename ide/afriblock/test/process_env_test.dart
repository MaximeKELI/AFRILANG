import 'package:flutter_test/flutter_test.dart';
import 'package:afriblock/services/process_env.dart';

void main() {
  test('sanitizePath strips Flutter snap toolchain dirs', () {
    const polluted =
        '/snap/flutter/current/usr/bin:/home/u/.local/bin:/usr/bin:/bin';
    final clean = ProcessEnv.sanitizePath(polluted);
    expect(clean.contains('/snap/flutter/'), isFalse);
    expect(clean.startsWith('/usr/bin'), isTrue);
    expect(clean.contains('/home/u/.local/bin'), isTrue);
    expect(clean.contains('/bin'), isTrue);
  });

  test('isPollutedToolchainEntry detects snap flutter', () {
    expect(
      ProcessEnv.isPollutedToolchainEntry('/snap/flutter/current/usr/bin'),
      isTrue,
    );
    expect(ProcessEnv.isPollutedToolchainEntry('/usr/bin'), isFalse);
  });

  test('forHostToolchain drops snap COMPILER_PATH', () {
    final env = ProcessEnv.forHostToolchain({
      'PATH': '/snap/flutter/current/usr/bin:/usr/bin',
      'COMPILER_PATH': '/snap/flutter/current/usr/lib/gcc',
      'HOME': '/home/u',
    });
    expect(env['PATH']!.contains('/snap/flutter/'), isFalse);
    expect(env.containsKey('COMPILER_PATH'), isFalse);
    expect(env['HOME'], '/home/u');
  });
}
