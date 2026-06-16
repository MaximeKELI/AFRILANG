"""Exécution du compilateur AFRILANG depuis Django."""
from __future__ import annotations

import hashlib
import os
import subprocess
import tempfile
import time
from pathlib import Path

from django.conf import settings


class AfrilangError(Exception):
    pass


def _bin() -> Path:
    path = Path(settings.AFRILANG_BIN)
    if not path.is_file():
        raise AfrilangError(
            f'Compilateur introuvable: {path}. '
            'Compilez AFRILANG ou définissez AFRILANG_BIN.'
        )
    return path.resolve()


def _repo_root() -> Path:
    return Path(settings.AFRILANG_ROOT).resolve()


def run_source(source: str, target: str = 'native') -> dict:
    bin_path = _bin()
    timeout = settings.PLAYGROUND_TIMEOUT
    start = time.monotonic()

    with tempfile.TemporaryDirectory(prefix='afrilang_web_') as tmp:
        tmp_path = Path(tmp)
        src_file = tmp_path / 'playground.afr'
        src_file.write_text(source, encoding='utf-8')
        cwd = _repo_root()

        cmd = [str(bin_path), 'run', str(src_file), '--target', target, '--run']

        env = os.environ.copy()
        env['AFRILANG_HOME'] = str(cwd)

        try:
            proc = subprocess.run(
                cmd,
                cwd=cwd,
                capture_output=True,
                text=True,
                timeout=timeout,
                env=env,
            )
        except subprocess.TimeoutExpired:
            return {
                'ok': False,
                'output': f'[timeout après {timeout}s]',
                'exitCode': 124,
                'duration_ms': int((time.monotonic() - start) * 1000),
            }

        output = (proc.stdout or '') + (proc.stderr or '')
        return {
            'ok': proc.returncode == 0,
            'output': output.strip() or '(no output)',
            'exitCode': proc.returncode,
            'duration_ms': int((time.monotonic() - start) * 1000),
        }


def format_source(source: str) -> dict:
    bin_path = _bin()
    cwd = _repo_root()

    with tempfile.TemporaryDirectory(prefix='afrilang_fmt_') as tmp:
        src_file = Path(tmp) / 'fmt.afr'
        src_file.write_text(source, encoding='utf-8')
        try:
            proc = subprocess.run(
                [str(bin_path), 'fmt', str(src_file)],
                cwd=cwd,
                capture_output=True,
                text=True,
                timeout=15,
            )
        except subprocess.TimeoutExpired:
            return {'ok': False, 'output': 'Format timeout'}

        if proc.returncode != 0:
            return {'ok': False, 'output': (proc.stderr or proc.stdout or 'Format error').strip()}

        formatted = src_file.read_text(encoding='utf-8')
        return {'ok': True, 'source': formatted}


def check_source(source: str) -> dict:
    bin_path = _bin()
    cwd = _repo_root()

    with tempfile.TemporaryDirectory(prefix='afrilang_check_') as tmp:
        src_file = Path(tmp) / 'check.afr'
        src_file.write_text(source, encoding='utf-8')
        try:
            proc = subprocess.run(
                [str(bin_path), 'check', str(src_file)],
                cwd=cwd,
                capture_output=True,
                text=True,
                timeout=15,
            )
        except subprocess.TimeoutExpired:
            return {'ok': False, 'output': 'Check timeout', 'errors': 1}

        output = (proc.stdout or '') + (proc.stderr or '')
        return {
            'ok': proc.returncode == 0,
            'output': output.strip() or '(no output)',
            'errors': 0 if proc.returncode == 0 else 1,
        }


def source_hash(source: str) -> str:
    return hashlib.sha256(source.encode('utf-8')).hexdigest()
