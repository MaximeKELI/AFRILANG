import json
import re
import subprocess
from pathlib import Path

from django.conf import settings
from django.core.management.base import BaseCommand

from core.models import Package, SiteMetric


def _repo_version() -> str:
    bin_path = Path(settings.AFRILANG_BIN)
    if not bin_path.is_file():
        return '1.0.0'
    try:
        proc = subprocess.run(
            [str(bin_path), '--version'],
            capture_output=True,
            text=True,
            timeout=5,
        )
        out = (proc.stdout or proc.stderr or '').strip()
        if not out:
            return '1.0.0'
        m = re.search(r'v(\d+(?:\.\d+)*)', out)
        if m:
            return m.group(1)
        parts = out.split()
        for part in reversed(parts):
            if part and part[0].isdigit():
                return part
        return parts[-1]
    except (subprocess.TimeoutExpired, OSError):
        return '1.0.0'


class Command(BaseCommand):
    help = 'Met à jour les statistiques du site depuis le dépôt'

    def handle(self, *args, **options):
        root = Path(settings.AFRILANG_ROOT)
        examples = len(list((root / 'examples').glob('*.afr'))) if (root / 'examples').is_dir() else 0
        stdlib = len(list((root / 'stdlib').rglob('*.afr'))) if (root / 'stdlib').is_dir() else 0
        blessed = Package.objects.filter(blessed=True).count()

        compiler_version = _repo_version()

        stats = {
            'version': '1.0',
            'compiler_version': compiler_version,
            'examples': examples,
            'blessed_packages': blessed,
            'stdlib_modules': stdlib,
            'cli_commands': 15,
        }
        SiteMetric.objects.update_or_create(key='site_stats', defaults={'value': stats})
        self.stdout.write(self.style.SUCCESS(json.dumps(stats, indent=2)))
