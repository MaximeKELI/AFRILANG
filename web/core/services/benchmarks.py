"""Benchmarks AFRILANG — exécution et lecture des métriques."""
from __future__ import annotations

import json
import os
import subprocess
from pathlib import Path

from django.conf import settings

from .afrilang import AfrilangError, _bin, _repo_root

DEFAULT_BENCHMARKS = {
    'generated_at': None,
    'compiler_version': '1.0.0',
    'platform': 'linux-x64',
    'results': [
        {'file': 'hello.afr', 'slug': 'hello', 'compile_ms': 850, 'exec_ms': 12, 'total_ms': 862},
        {'file': 'oop.afr', 'slug': 'oop', 'compile_ms': 1200, 'exec_ms': 8, 'total_ms': 1208},
        {'file': 'generics.afr', 'slug': 'generics', 'compile_ms': 1400, 'exec_ms': 10, 'total_ms': 1410},
        {'file': 'full_demo.afr', 'slug': 'full_demo', 'compile_ms': 2200, 'exec_ms': 25, 'total_ms': 2225},
        {'file': 'stdlib_demo.afr', 'slug': 'stdlib_demo', 'compile_ms': 3500, 'exec_ms': 40, 'total_ms': 3540},
        {'file': 'tier9_demo.afr', 'slug': 'tier9_demo', 'compile_ms': 900, 'exec_ms': 15, 'total_ms': 915},
        {'file': 'tier10_demo.afr', 'slug': 'tier10_demo', 'compile_ms': 950, 'exec_ms': 14, 'total_ms': 964},
    ],
    'comparisons': [
        {'name': 'hello', 'label': 'hello.afr', 'afrilang_exec_ms': 12, 'python_ms': 45},
    ],
    'is_sample': True,
}


def run_benchmarks() -> dict:
    root = _repo_root()
    script = root / 'scripts' / 'benchmark.sh'
    if not script.is_file():
        raise AfrilangError(f'Script benchmark introuvable: {script}')

    bin_path = _bin()
    env = {'AFRILANG': str(bin_path), **os.environ}
    try:
        proc = subprocess.run(
            ['bash', str(script), '--json'],
            cwd=root,
            capture_output=True,
            text=True,
            timeout=300,
            env=env,
        )
    except subprocess.TimeoutExpired:
        raise AfrilangError('Benchmark timeout (5 min)')

    if proc.returncode != 0:
        err = (proc.stderr or proc.stdout or 'Benchmark failed').strip()
        raise AfrilangError(err[:2000])

    stdout = (proc.stdout or '').strip()
    if not stdout:
        raise AfrilangError('Benchmark produced no JSON output')

    try:
        data = json.loads(stdout)
    except json.JSONDecodeError as e:
        raise AfrilangError(f'JSON benchmark invalide: {e}') from e

    data['is_sample'] = False
    return data


def load_benchmarks() -> dict:
    try:
        from core.models import SiteMetric

        row = SiteMetric.objects.filter(key='benchmarks').first()
        if row and isinstance(row.value, dict) and row.value.get('results'):
            return row.value
    except Exception:
        pass
    return dict(DEFAULT_BENCHMARKS)


def benchmark_summary(data: dict) -> dict:
    results = data.get('results') or []
    if not results:
        return {'count': 0, 'avg_compile_ms': 0, 'avg_exec_ms': 0, 'avg_total_ms': 0}

    n = len(results)
    return {
        'count': n,
        'avg_compile_ms': round(sum(r.get('compile_ms', 0) for r in results) / n),
        'avg_exec_ms': round(sum(r.get('exec_ms', 0) for r in results) / n),
        'avg_total_ms': round(sum(r.get('total_ms', 0) for r in results) / n),
        'max_total_ms': max(r.get('total_ms', 0) for r in results),
        'min_total_ms': min(r.get('total_ms', 0) for r in results),
    }
