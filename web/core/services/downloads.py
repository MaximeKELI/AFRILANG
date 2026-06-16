"""Détection et métadonnées des binaires AFRILANG téléchargeables."""
from __future__ import annotations

import hashlib
import platform
from pathlib import Path

from django.conf import settings
from django.core.cache import cache

CACHE_KEY = 'afr_binary_meta'


def _human_size(n: int) -> str:
    for unit in ('B', 'KB', 'MB', 'GB'):
        if n < 1024:
            return f'{n:.0f} {unit}' if unit == 'B' else f'{n:.1f} {unit}'
        n /= 1024
    return f'{n:.1f} TB'


def _file_sha256(path: Path) -> str:
    h = hashlib.sha256()
    with path.open('rb') as f:
        for chunk in iter(lambda: f.read(65536), b''):
            h.update(chunk)
    return h.hexdigest()


def _detect_platform_id() -> str:
    machine = platform.machine().lower()
    if machine in ('x86_64', 'amd64'):
        return 'linux-x64'
    if machine in ('aarch64', 'arm64'):
        return 'linux-arm64'
    return 'linux-x64'


def get_binary_assets(refresh: bool = False) -> list[dict]:
    if not refresh:
        cached = cache.get(CACHE_KEY)
        if cached is not None:
            return cached

    root = Path(settings.AFRILANG_ROOT)
    candidates = [
        ('linux-x64', root / 'build' / 'afrilang', Path(settings.AFRILANG_BIN)),
    ]
    assets = []
    seen = set()
    for platform_id, *paths in candidates:
        if platform_id in seen:
            continue
        bin_path = None
        for p in paths:
            p = Path(p).resolve()
            if p.is_file():
                bin_path = p
                break
        if not bin_path:
            continue
        stat = bin_path.stat()
        assets.append({
            'platform': platform_id,
            'label': 'Linux x64 (glibc)',
            'filename': 'afrilang',
            'size_bytes': stat.st_size,
            'size_human': _human_size(stat.st_size),
            'sha256': _file_sha256(bin_path),
            'path': str(bin_path),
        })
        seen.add(platform_id)

    cache.set(CACHE_KEY, assets, 300)
    return assets


def resolve_binary(platform_id: str) -> Path | None:
    for asset in get_binary_assets():
        if asset['platform'] == platform_id:
            path = Path(asset['path'])
            if path.is_file():
                return path
    return None


def get_download_context() -> dict:
    assets = get_binary_assets()
    return {
        'binaries': assets,
        'has_binary': bool(assets),
        'current_platform': _detect_platform_id(),
        'github_releases': 'https://github.com/MaximeKELI/AFRILANG/releases',
    }
