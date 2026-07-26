import 'dart:io';

import 'package:flutter_test/flutter_test.dart';
import 'package:afriblock/services/process_env.dart';
import 'package:path/path.dart' as p;

void main() {
  group('isPollutedToolchainEntry', () {
    test('flags snap flutter / dart / flutter-sdk paths', () {
      expect(
        ProcessEnv.isPollutedToolchainEntry('/snap/flutter/current/usr/bin'),
        isTrue,
      );
      expect(
        ProcessEnv.isPollutedToolchainEntry(
          '/snap/flutter/4921/usr/lib/x86_64-linux-gnu',
        ),
        isTrue,
      );
      expect(
        ProcessEnv.isPollutedToolchainEntry('/snap/dart-sdk/bin'),
        isTrue,
      );
      expect(
        ProcessEnv.isPollutedToolchainEntry('/snap/flutter-sdk/bin'),
        isTrue,
      );
    });

    test('allows host and user paths', () {
      expect(ProcessEnv.isPollutedToolchainEntry('/usr/bin'), isFalse);
      expect(ProcessEnv.isPollutedToolchainEntry('/bin'), isFalse);
      expect(ProcessEnv.isPollutedToolchainEntry('/usr/local/bin'), isFalse);
      expect(
        ProcessEnv.isPollutedToolchainEntry('/home/u/.local/bin'),
        isFalse,
      );
      expect(ProcessEnv.isPollutedToolchainEntry('/opt/extra/lib'), isFalse);
      expect(ProcessEnv.isPollutedToolchainEntry('/snap/bin'), isFalse);
    });

    test('rejects empty entries', () {
      expect(ProcessEnv.isPollutedToolchainEntry(''), isTrue);
    });
  });

  group('sanitizePathList', () {
    test('drops snap entries and keeps others', () {
      final cleaned = ProcessEnv.sanitizePathList(
        '/snap/flutter/current/usr/lib:/opt/a:/snap/dart-sdk/lib:/opt/b',
        separator: ':',
      );
      expect(cleaned, '/opt/a:/opt/b');
    });

    test('dedupes and skips empties', () {
      final cleaned = ProcessEnv.sanitizePathList(
        ':/opt/a::/opt/a:/opt/b:',
        separator: ':',
      );
      expect(cleaned, '/opt/a:/opt/b');
    });

    test('returns empty when only snap remains', () {
      final cleaned = ProcessEnv.sanitizePathList(
        '/snap/flutter/current/usr/lib/x86_64-linux-gnu',
        separator: ':',
      );
      expect(cleaned, isEmpty);
    });
  });

  group('sanitizePath', () {
    test('strips Flutter snap toolchain dirs and prefers /usr/bin', () {
      const polluted =
          '/snap/flutter/current/usr/bin:/home/u/.local/bin:/usr/bin:/bin';
      final clean = ProcessEnv.sanitizePath(polluted);
      expect(clean.contains('/snap/flutter/'), isFalse);
      expect(clean.startsWith('/usr/bin'), isTrue);
      expect(clean.contains('/home/u/.local/bin'), isTrue);
      expect(clean.split(':').contains('/bin'), isTrue);
    });

    test('still prefers host bins when PATH is empty', () {
      final clean = ProcessEnv.sanitizePath('');
      expect(clean.startsWith('/usr/bin'), isTrue);
      expect(clean.contains('/bin'), isTrue);
    });
  });

  group('forHostToolchain', () {
    test('strips snap from PATH and LD_LIBRARY_PATH / LIBRARY_PATH', () {
      final env = ProcessEnv.forHostToolchain({
        'PATH': '/snap/flutter/current/usr/bin:/usr/bin',
        'LD_LIBRARY_PATH':
            '/snap/flutter/current/usr/lib/x86_64-linux-gnu:/opt/extra/lib',
        'LIBRARY_PATH': '/snap/flutter/current/usr/lib/x86_64-linux-gnu',
        'COMPILER_PATH': '/snap/flutter/current/usr/lib/gcc',
        'C_INCLUDE_PATH': '/snap/flutter/current/usr/include:/usr/include',
        'PKG_CONFIG_PATH': '/snap/flutter/current/usr/lib/pkgconfig',
        'CMAKE_PREFIX_PATH': '/snap/flutter/current/usr:/opt/cmake',
        'HOME': '/home/u',
        'DISPLAY': ':0',
      });
      expect(env['PATH']!.contains('/snap/flutter/'), isFalse);
      expect(env['PATH']!.startsWith('/usr/bin'), isTrue);
      expect(env['LD_LIBRARY_PATH'], '/opt/extra/lib');
      expect(env.containsKey('LIBRARY_PATH'), isFalse);
      expect(env.containsKey('COMPILER_PATH'), isFalse);
      expect(env['C_INCLUDE_PATH'], '/usr/include');
      expect(env.containsKey('PKG_CONFIG_PATH'), isFalse);
      expect(env['CMAKE_PREFIX_PATH'], '/opt/cmake');
      expect(env['HOME'], '/home/u');
      expect(env['DISPLAY'], ':0');
    });

    test('does not mutate the input map', () {
      final input = <String, String>{
        'PATH': '/snap/flutter/current/usr/bin:/usr/bin',
        'LD_LIBRARY_PATH': '/snap/flutter/current/usr/lib',
      };
      final copy = Map<String, String>.from(input);
      ProcessEnv.forHostToolchain(input);
      expect(input, copy);
    });

    test('clears snap-only LD_LIBRARY_PATH that breaks host g++/ld', () {
      // Mirrors the GLIBC_2.33 / libctf failure seen under Flutter snap.
      final env = ProcessEnv.forHostToolchain({
        'PATH': '/usr/bin:/bin',
        'LD_LIBRARY_PATH': '/snap/flutter/current/usr/lib/x86_64-linux-gnu',
        'LIBRARY_PATH': '/snap/flutter/current/usr/lib/x86_64-linux-gnu',
      });
      expect(env.containsKey('LD_LIBRARY_PATH'), isFalse);
      expect(env.containsKey('LIBRARY_PATH'), isFalse);
    });
  });

  group('integration with afrilang binary', () {
    late String? afrilangBin;

    setUpAll(() {
      afrilangBin = Platform.environment['AFRIBLOCK_AFRILANG'];
      if (afrilangBin == null || afrilangBin!.isEmpty) {
        final candidate = p.normalize(
          p.join(Directory.current.path, '../../build/afrilang'),
        );
        if (File(candidate).existsSync()) {
          afrilangBin = candidate;
        }
      }
    });

    test(
      'spawn with polluted LD_LIBRARY_PATH fails without sanitizer',
      () async {
        if (afrilangBin == null) {
          // ignore: avoid_print
          print('skip: afrilang binary not found');
          return;
        }
        final snapLib = '/snap/flutter/current/usr/lib/x86_64-linux-gnu';
        if (!Directory(snapLib).existsSync()) {
          // ignore: avoid_print
          print('skip: flutter snap libs not present');
          return;
        }
        final polluted = Map<String, String>.from(Platform.environment);
        polluted['PATH'] = '/usr/bin:/bin';
        polluted['LD_LIBRARY_PATH'] = snapLib;
        polluted['LIBRARY_PATH'] = snapLib;
        final r = await Process.run(
          afrilangBin!,
          ['version'],
          environment: polluted,
          runInShell: false,
        );
        // Dynamic linker should fail against snap libstdc++ / glibc.
        expect(
          r.exitCode != 0 ||
              '${r.stdout}${r.stderr}'.contains('GLIBCXX') ||
              '${r.stdout}${r.stderr}'.contains('version'),
          isTrue,
          reason: 'polluted env should break afrilang load or report glibc issue',
        );
      },
    );

    test(
      'spawn with forHostToolchain succeeds despite polluted parent map',
      () async {
        if (afrilangBin == null) {
          // ignore: avoid_print
          print('skip: afrilang binary not found');
          return;
        }
        final snapLib = '/snap/flutter/current/usr/lib/x86_64-linux-gnu';
        final polluted = Map<String, String>.from(Platform.environment);
        polluted['PATH'] =
            '/snap/flutter/current/usr/bin:${polluted['PATH'] ?? '/usr/bin'}';
        if (Directory(snapLib).existsSync()) {
          polluted['LD_LIBRARY_PATH'] =
              '$snapLib:${polluted['LD_LIBRARY_PATH'] ?? ''}';
          polluted['LIBRARY_PATH'] = snapLib;
        }
        final clean = ProcessEnv.forHostToolchain(polluted);
        expect(clean['PATH']!.contains('/snap/flutter/'), isFalse);
        if (Directory(snapLib).existsSync()) {
          expect(
            (clean['LD_LIBRARY_PATH'] ?? '').contains('/snap/flutter/'),
            isFalse,
          );
        }
        final r = await Process.run(
          afrilangBin!,
          ['version'],
          environment: clean,
          runInShell: false,
        );
        expect(r.exitCode, 0, reason: '${r.stdout}\n${r.stderr}');
        expect(
          ('${r.stdout}${r.stderr}').toLowerCase(),
          contains('afrilang'),
        );
      },
    );

    test(
      'afrilang run Hello sample under sanitized snap-like env',
      () async {
        if (afrilangBin == null) {
          // ignore: avoid_print
          print('skip: afrilang binary not found');
          return;
        }
        final home = Platform.environment['HOME'] ?? '';
        final mainAfr = p.join(
          home,
          'Documents/AFRIBLOCK_Projects/Hello_AFRILANG/src/main.afr',
        );
        if (!File(mainAfr).existsSync()) {
          // ignore: avoid_print
          print('skip: Hello_AFRILANG sample not found at $mainAfr');
          return;
        }
        final polluted = <String, String>{
          'PATH':
              '/snap/flutter/current/usr/bin:/usr/bin:/bin:/usr/local/bin',
          'HOME': home,
          'TMPDIR': Platform.environment['TMPDIR'] ?? '/tmp',
          'LANG': Platform.environment['LANG'] ?? 'C.UTF-8',
        };
        if (Directory('/snap/flutter/current/usr/lib/x86_64-linux-gnu')
            .existsSync()) {
          polluted['LD_LIBRARY_PATH'] =
              '/snap/flutter/current/usr/lib/x86_64-linux-gnu';
          polluted['LIBRARY_PATH'] =
              '/snap/flutter/current/usr/lib/x86_64-linux-gnu';
        }
        final r = await Process.run(
          afrilangBin!,
          ['run', mainAfr],
          environment: ProcessEnv.forHostToolchain(polluted),
          workingDirectory: p.dirname(mainAfr),
          runInShell: false,
        );
        expect(r.exitCode, 0, reason: '${r.stdout}\n${r.stderr}');
        expect('${r.stdout}${r.stderr}', contains('Hello'));
      },
    );
  });
}
