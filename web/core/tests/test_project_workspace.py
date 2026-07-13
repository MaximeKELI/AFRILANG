"""Tests for multi-file playground project staging."""
from __future__ import annotations

import tempfile
import unittest
from pathlib import Path

from django.conf import settings
from django.test import SimpleTestCase

from core.services.afrilang import (
    ProjectPayloadError,
    normalize_project_path,
    requires_desktop_display,
    resolve_run_payload,
    run_project,
    stage_project,
    validate_project_files,
)


class ProjectPathTests(SimpleTestCase):
    def test_normalize_ok(self):
        self.assertEqual(normalize_project_path('game/main.afr'), 'game/main.afr')
        self.assertEqual(normalize_project_path('\\game\\main.afr'), 'game/main.afr')

    def test_reject_traversal(self):
        with self.assertRaises(ProjectPayloadError):
            normalize_project_path('../etc/passwd.afr')
        with self.assertRaises(ProjectPayloadError):
            normalize_project_path('/tmp/x.afr')
        with self.assertRaises(ProjectPayloadError):
            normalize_project_path('foo/../../x.afr')

    def test_reject_non_afr(self):
        with self.assertRaises(ProjectPayloadError):
            normalize_project_path('main.py')

    def test_entry_must_exist(self):
        with self.assertRaises(ProjectPayloadError):
            validate_project_files('missing.afr', {'main.afr': 'say "hi"'})


class ProjectStagingTests(SimpleTestCase):
    def test_stage_writes_nested_files(self):
        files = {
            'game/main.afr': 'import "helpers.afr"\nsay add(1, 2)\n',
            'game/helpers.afr': (
                'function add(a number, b number) returns number\n'
                '    return a + b\n'
                'end\n'
            ),
        }
        # Import path is relative to entry dir for compiler — use same-dir names
        files = {
            'game/main.afr': 'import "helpers.afr"\nsay sum2(10, 32)\n',
            'game/helpers.afr': (
                'function sum2(a number, b number) returns number\n'
                '    return a + b\n'
                'end\n'
            ),
        }
        with tempfile.TemporaryDirectory() as tmp:
            entry = stage_project(Path(tmp), 'game/main.afr', files)
            self.assertTrue(entry.is_file())
            self.assertTrue((Path(tmp) / 'game' / 'helpers.afr').is_file())

    def test_resolve_payload_compat_source(self):
        entry, files = resolve_run_payload({'source': 'say "hi"'})
        self.assertEqual(entry, 'playground.afr')
        self.assertIn('playground.afr', files)

    def test_resolve_payload_files(self):
        entry, files = resolve_run_payload({
            'entry': 'main.afr',
            'files': {'main.afr': 'say 1', 'lib.afr': 'say 2'},
        })
        self.assertEqual(entry, 'main.afr')
        self.assertEqual(len(files), 2)


class ProjectRunTests(SimpleTestCase):
    def test_run_multifile_import(self):
        bin_path = Path(settings.AFRILANG_BIN)
        if not bin_path.is_file():
            self.skipTest('AFRILANG_BIN missing')

        files = {
            'main.afr': 'import "helpers.afr"\nsay sum2(10, 32)\n',
            'helpers.afr': (
                'function sum2(a number, b number) returns number\n'
                '    return a + b\n'
                'end\n'
            ),
        }
        result = run_project('main.afr', files)
        self.assertTrue(result['ok'], result['output'])
        self.assertIn('42', result['output'])


class DesktopGuiGateTests(SimpleTestCase):
    def test_detects_ui_import_and_open_window(self):
        self.assertTrue(requires_desktop_display('import "std/ui"\nuse ui\n'))
        self.assertTrue(requires_desktop_display('import "std/game2d"\n'))
        self.assertTrue(requires_desktop_display('import "std/game3d"\n'))
        self.assertTrue(requires_desktop_display('open window titled "Hi"\n'))
        self.assertTrue(requires_desktop_display('while window is open do\nend\n'))
        self.assertFalse(requires_desktop_display('say "hello"\nclass Dog\nend\n'))

    def test_run_project_refuses_gui(self):
        result = run_project(
            'gui.afr',
            {'gui.afr': 'import "std/ui"\nopen window titled "Demo"\n'},
        )
        self.assertFalse(result['ok'])
        self.assertEqual(result['exitCode'], 2)
        self.assertIn('fenêtre graphique', result['output'])
        self.assertIn('application mobile', result['output'])


if __name__ == '__main__':
    unittest.main()
