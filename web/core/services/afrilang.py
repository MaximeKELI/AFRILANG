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


def compile_to_js(source: str) -> dict:
    bin_path = _bin()
    cwd = _repo_root()

    with tempfile.TemporaryDirectory(prefix='afrilang_js_') as tmp:
        src_file = Path(tmp) / 'playground.afr'
        src_file.write_text(source, encoding='utf-8')
        try:
            proc = subprocess.run(
                [str(bin_path), 'compile-js', str(src_file)],
                cwd=cwd,
                capture_output=True,
                text=True,
                timeout=15,
            )
        except subprocess.TimeoutExpired:
            return {'ok': False, 'output': 'Compile timeout'}

        if proc.returncode != 0:
            return {'ok': False, 'output': (proc.stderr or proc.stdout or 'Compile error').strip()}

        return {'ok': True, 'js': proc.stdout}


def build_wasm_web(source: str) -> dict:
    """Compile source to browser-loadable WASM (requires Emscripten on server)."""
    import secrets
    import shutil

    bin_path = _bin()
    cwd = _repo_root()
    session_root = Path(settings.PLAYGROUND_WASM_DIR)
    session_root.mkdir(parents=True, exist_ok=True)
    session_id = secrets.token_hex(8)
    session_dir = session_root / session_id

    with tempfile.TemporaryDirectory(prefix='afr_build_') as tmp:
        tmp_path = Path(tmp)
        src_file = tmp_path / 'playground.afr'
        src_file.write_text(source, encoding='utf-8')
        out_dir = tmp_path / 'out'
        out_dir.mkdir()
        try:
            proc = subprocess.run(
                [str(bin_path), 'build-wasm-web', str(src_file), '-o', str(out_dir)],
                cwd=cwd,
                capture_output=True,
                text=True,
                timeout=settings.PLAYGROUND_TIMEOUT,
            )
        except subprocess.TimeoutExpired:
            return {'ok': False, 'output': 'WASM build timeout', 'exitCode': 124}

        if proc.returncode != 0:
            return {
                'ok': False,
                'output': (proc.stderr or proc.stdout or 'WASM build failed').strip(),
                'exitCode': proc.returncode,
            }

        js_file = out_dir / 'module.js'
        wasm_file = out_dir / 'module.wasm'
        if not js_file.is_file() or not wasm_file.is_file():
            return {'ok': False, 'output': 'WASM artifacts missing', 'exitCode': 1}

        session_dir.mkdir(parents=True)
        shutil.copy2(js_file, session_dir / 'module.js')
        shutil.copy2(wasm_file, session_dir / 'module.wasm')

    return {'ok': True, 'id': session_id}


def wasm_session_path(session_id: str, filename: str) -> Path | None:
    if not session_id or filename not in ('module.js', 'module.wasm'):
        return None
    if '..' in session_id or '/' in session_id or '\\' in session_id:
        return None
    base = Path(settings.PLAYGROUND_WASM_DIR).resolve()
    path = (base / session_id / filename).resolve()
    try:
        path.relative_to(base / session_id)
    except ValueError:
        return None
    return path if path.is_file() else None


def source_hash(source: str) -> str:
    return hashlib.sha256(source.encode('utf-8')).hexdigest()
