import 'package:flutter_test/flutter_test.dart';
import 'package:afriblock/project/project_service.dart';

void main() {
  test('parseTomlText extracts fields', () {
    const sample = '''
name = "demo"
version = "0.2.0"
main = "src/main.afr"
output = "build/demo"
description = "hello"
''';
    final svc = ProjectService();
    final proj = svc.parseTomlText('/tmp/demo', sample);
    expect(proj.name, 'demo');
    expect(proj.version, '0.2.0');
    expect(proj.main, 'src/main.afr');
    expect(proj.output, 'build/demo');
    expect(proj.mainAbsolute, '/tmp/demo/src/main.afr');
  });

  test('targetsFor adds check-main when main exists', () {
    final proj =
        ProjectService().parseTomlText('/w', 'name = "x"\nmain = "a.afr"\n');
    final targets = ProjectService().targetsFor(proj);
    expect(targets.map((t) => t.id), contains('check-main'));
    expect(targets.map((t) => t.id), contains('wasm32'));
  });

  test('default targets always available', () {
    expect(
      kDefaultTargets.map((t) => t.id),
      containsAll(['debug', 'release', 'test']),
    );
  });

  group('resolveRunSource', () {
    test('prefers active .afr over project main', () {
      expect(
        resolveRunSource(
          activePath: '/proj/src/Hello-World.afr',
          projectMain: '/proj/src/main.afr',
        ),
        '/proj/src/Hello-World.afr',
      );
    });

    test('falls back to project main when active is not .afr', () {
      expect(
        resolveRunSource(
          activePath: '/proj/src/main.generated.cpp',
          projectMain: '/proj/src/main.afr',
        ),
        '/proj/src/main.afr',
      );
    });

    test('uses project main when no active tab', () {
      expect(
        resolveRunSource(activePath: null, projectMain: '/proj/src/main.afr'),
        '/proj/src/main.afr',
      );
    });

    test('returns null when nothing runnable', () {
      expect(
        resolveRunSource(activePath: '/proj/README.md', projectMain: null),
        isNull,
      );
    });

    test('is case-insensitive for .afr extension', () {
      expect(
        resolveRunSource(
          activePath: '/proj/Demo.AFR',
          projectMain: '/proj/main.afr',
        ),
        '/proj/Demo.AFR',
      );
    });
  });
}
