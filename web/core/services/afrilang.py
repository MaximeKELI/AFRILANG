"""Exécution du compilateur AFRILANG depuis Django."""
from __future__ import annotations

import hashlib
import os
import re
import secrets
import shutil
import subprocess
import tempfile
import time
from pathlib import Path

from django.conf import settings

_IMPORT_RE = re.compile(r'^\s*import\s+"([^"]+)"', re.MULTILINE)

MAX_PROJECT_FILES = 40
MAX_FILE_BYTES = 200 * 1024
MAX_PROJECT_BYTES = 1024 * 1024

# Exemples / programmes qui ouvrent une fenêtre ou une boucle d'événements :
# le playground web / l'app mobile sont headless — on refuse au lieu d'attendre le timeout.
_DESKTOP_MARKERS = (
    'import "std/ui"',
    'import "std/game2d"',
    'import "std/game3d"',
    'open window',
    'while window is open',
)

_DESKTOP_MESSAGE = (
    'Cet exemple nécessite une fenêtre graphique (SDL) et le compilateur '
    'AFRILANG en local — il ne peut pas tourner dans le playground web '
    'ni dans l’application mobile.\n\n'
    'Sur votre machine (Linux / macOS / Windows) :\n'
    '  afrilang run examples/<fichier>.afr\n\n'
    'Choisissez un autre exemple (hello, list_ops, oop, …) pour l’exécuter ici.'
)


class AfrilangError(Exception):
    pass


class ProjectPayloadError(ValueError):
    """Payload projet invalide (chemins, taille, etc.)."""


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


def requires_desktop_display(source: str) -> bool:
    """True si le programme ouvre une UI / boucle fenêtre (incompatible playground)."""
    return any(marker in source for marker in _DESKTOP_MARKERS)


def normalize_project_path(raw: str) -> str:
    """Normalise et valide un chemin relatif de projet (.afr)."""
    if not isinstance(raw, str) or not raw.strip():
        raise ProjectPayloadError('Chemin de fichier vide')
    raw_stripped = raw.strip()
    path = raw_stripped.replace('\\', '/')
    # Lecteur Windows (C:/...)
    if len(path) >= 2 and path[0].isalpha() and path[1] == ':':
        raise ProjectPayloadError(f'Chemin absolu interdit: {raw!r}')
    # Absolu Unix (commence par /) — pas les chemins Windows style \game\...
    if raw_stripped.startswith('/'):
        raise ProjectPayloadError(f'Chemin absolu interdit: {raw!r}')
    path = path.lstrip('/')
    if not path or path in ('.', '..'):
        raise ProjectPayloadError(f'Chemin invalide: {raw!r}')
    parts = [p for p in path.split('/') if p and p != '.']
    if any(p == '..' for p in parts):
        raise ProjectPayloadError(f'Traversée de répertoire interdite: {raw!r}')
    if any(p.startswith('.') for p in parts):
        raise ProjectPayloadError(f'Nom de segment interdit: {raw!r}')
    normalized = '/'.join(parts)
    if not normalized.lower().endswith('.afr'):
        raise ProjectPayloadError(f'Seuls les fichiers .afr sont autorisés: {raw!r}')
    return normalized


def validate_project_files(entry: str, files: dict) -> tuple[str, dict[str, str]]:
    """Valide entry + map path→source. Retourne (entry_norm, files_norm)."""
    if not isinstance(files, dict) or not files:
        raise ProjectPayloadError('Aucun fichier de projet')
    if len(files) > MAX_PROJECT_FILES:
        raise ProjectPayloadError(f'Trop de fichiers (max {MAX_PROJECT_FILES})')

    normalized: dict[str, str] = {}
    total = 0
    for raw_path, content in files.items():
        path = normalize_project_path(str(raw_path))
        if not isinstance(content, str):
            raise ProjectPayloadError(f'Contenu non texte: {path}')
        size = len(content.encode('utf-8'))
        if size > MAX_FILE_BYTES:
            raise ProjectPayloadError(
                f'Fichier trop volumineux (max {MAX_FILE_BYTES} octets): {path}'
            )
        total += size
        if total > MAX_PROJECT_BYTES:
            raise ProjectPayloadError(
                f'Projet trop volumineux (max {MAX_PROJECT_BYTES} octets)'
            )
        normalized[path] = content

    entry_norm = normalize_project_path(entry)
    if entry_norm not in normalized:
        raise ProjectPayloadError(f'Fichier d’entrée introuvable dans le projet: {entry_norm}')
    return entry_norm, normalized


def resolve_run_payload(body: dict) -> tuple[str, dict[str, str]]:
    """
    Accepte soit {entry, files} soit {source} (rétrocompat → playground.afr).
    """
    files = body.get('files')
    if isinstance(files, dict) and files:
        entry = body.get('entry') or next(iter(files.keys()))
        return validate_project_files(str(entry), files)

    source = body.get('source', '')
    if isinstance(source, str) and source.strip():
        return 'playground.afr', {'playground.afr': source}

    raise ProjectPayloadError('Empty source')


def _resolve_relative_import(import_path: str) -> Path | None:
    """Cherche un import relatif (.afr local) dans examples/ puis à la racine du dépôt."""
    if import_path.startswith('std/') or import_path.startswith('pkg/'):
        return None
    if '..' in import_path or import_path.startswith('/') or import_path.startswith('\\'):
        return None

    root = _repo_root()
    candidates = [
        root / 'examples' / import_path,
        root / 'examples' / Path(import_path).name,
        root / import_path,
    ]
    for cand in candidates:
        try:
            resolved = cand.resolve()
            resolved.relative_to(root)
        except (ValueError, OSError):
            continue
        if resolved.is_file():
            return resolved
    return None


def _stage_relative_imports(source: str, tmp_path: Path) -> None:
    """Copie les .afr importés depuis examples/ s'ils manquent dans tmp."""
    pending = list(_IMPORT_RE.findall(source))
    seen: set[str] = set()

    while pending:
        imp = pending.pop(0)
        if imp in seen:
            continue
        seen.add(imp)
        dest = tmp_path / imp
        if dest.exists():
            try:
                content = dest.read_text(encoding='utf-8', errors='replace')
            except OSError:
                continue
            for nested in _IMPORT_RE.findall(content):
                if nested not in seen:
                    pending.append(nested)
            continue

        src = _resolve_relative_import(imp)
        if src is None:
            continue
        if '/' in imp:
            dest.parent.mkdir(parents=True, exist_ok=True)
        shutil.copy2(src, dest)
        try:
            content = dest.read_text(encoding='utf-8', errors='replace')
        except OSError:
            continue
        for nested in _IMPORT_RE.findall(content):
            if nested not in seen:
                pending.append(nested)


def stage_project(tmp_path: Path, entry: str, files: dict[str, str]) -> Path:
    """Écrit tous les fichiers user dans tmp, complète les imports examples, retourne entry path."""
    entry_norm, files_norm = validate_project_files(entry, files)
    for path, content in files_norm.items():
        dest = tmp_path / path
        dest.parent.mkdir(parents=True, exist_ok=True)
        dest.write_text(content, encoding='utf-8')

    for content in files_norm.values():
        _stage_relative_imports(content, tmp_path)

    return tmp_path / entry_norm


def _write_staged_source(tmp_path: Path, filename: str, source: str) -> Path:
    return stage_project(tmp_path, filename, {filename: source})


def _combined_sources(files: dict[str, str]) -> str:
    return '\n'.join(files.values())


def run_project(entry: str, files: dict[str, str], target: str = 'native') -> dict:
    entry_norm, files_norm = validate_project_files(entry, files)
    if requires_desktop_display(_combined_sources(files_norm)):
        return {
            'ok': False,
            'output': _DESKTOP_MESSAGE,
            'exitCode': 2,
            'duration_ms': 0,
        }

    bin_path = _bin()
    timeout = settings.PLAYGROUND_TIMEOUT
    start = time.monotonic()

    with tempfile.TemporaryDirectory(prefix='afrilang_web_') as tmp:
        tmp_path = Path(tmp)
        src_file = stage_project(tmp_path, entry_norm, files_norm)
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


def run_source(source: str, target: str = 'native') -> dict:
    return run_project('playground.afr', {'playground.afr': source}, target=target)


def format_source(source: str) -> dict:
    bin_path = _bin()
    cwd = _repo_root()

    with tempfile.TemporaryDirectory(prefix='afrilang_fmt_') as tmp:
        src_file = _write_staged_source(Path(tmp), 'fmt.afr', source)
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


def check_project(entry: str, files: dict[str, str]) -> dict:
    entry_norm, files_norm = validate_project_files(entry, files)
    bin_path = _bin()
    cwd = _repo_root()

    with tempfile.TemporaryDirectory(prefix='afrilang_check_') as tmp:
        src_file = stage_project(Path(tmp), entry_norm, files_norm)
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


def check_source(source: str) -> dict:
    return check_project('check.afr', {'check.afr': source})


def compile_to_js(source: str) -> dict:
    if requires_desktop_display(source):
        return {'ok': False, 'output': _DESKTOP_MESSAGE}

    bin_path = _bin()
    cwd = _repo_root()

    with tempfile.TemporaryDirectory(prefix='afrilang_js_') as tmp:
        src_file = _write_staged_source(Path(tmp), 'playground.afr', source)
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


def compile_project_to_js(entry: str, files: dict[str, str]) -> dict:
    entry_norm, files_norm = validate_project_files(entry, files)
    if requires_desktop_display(_combined_sources(files_norm)):
        return {'ok': False, 'output': _DESKTOP_MESSAGE}

    bin_path = _bin()
    cwd = _repo_root()
    with tempfile.TemporaryDirectory(prefix='afrilang_js_') as tmp:
        src_file = stage_project(Path(tmp), entry_norm, files_norm)
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
    return build_wasm_project('playground.afr', {'playground.afr': source})


def build_wasm_project(entry: str, files: dict[str, str]) -> dict:
    entry_norm, files_norm = validate_project_files(entry, files)
    if requires_desktop_display(_combined_sources(files_norm)):
        return {'ok': False, 'output': _DESKTOP_MESSAGE, 'exitCode': 2}

    bin_path = _bin()
    cwd = _repo_root()
    session_root = Path(settings.PLAYGROUND_WASM_DIR)
    session_root.mkdir(parents=True, exist_ok=True)
    session_id = secrets.token_hex(8)
    session_dir = session_root / session_id

    with tempfile.TemporaryDirectory(prefix='afr_build_') as tmp:
        tmp_path = Path(tmp)
        src_file = stage_project(tmp_path, entry_norm, files_norm)
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


def project_hash(entry: str, files: dict[str, str]) -> str:
    entry_norm, files_norm = validate_project_files(entry, files)
    blob = entry_norm + '\n' + '\n'.join(
        f'{p}\n{files_norm[p]}' for p in sorted(files_norm)
    )
    return hashlib.sha256(blob.encode('utf-8')).hexdigest()
