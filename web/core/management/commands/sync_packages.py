import json
from pathlib import Path

from django.conf import settings
from django.core.management.base import BaseCommand

from core.models import Package


def _load_json(path: Path):
    if not path.is_file():
        return None
    return json.loads(path.read_text(encoding='utf-8'))


def _readme_for(root: Path, name: str) -> str:
    for candidate in (
        root / 'packages' / name / 'README.md',
        root / 'packages' / name / 'readme.md',
    ):
        if candidate.is_file():
            return candidate.read_text(encoding='utf-8', errors='replace')[:20000]
    return ''


class Command(BaseCommand):
    help = 'Synchronise les paquets depuis index.json + remote-index.json (+ README)'

    def handle(self, *args, **options):
        root = Path(settings.AFRILANG_ROOT)
        local = _load_json(root / 'packages' / 'index.json') or _load_json(
            root / 'site' / 'packages.json'
        )
        remote = _load_json(root / 'packages' / 'remote-index.json') or _load_json(
            root / 'packages' / 'remote-index.example.json'
        )

        by_name = {}
        for source in (local, remote):
            if not source:
                continue
            for entry in source.get('packages', []):
                name = entry.get('name')
                if not name:
                    continue
                prev = by_name.get(name, {})
                merged = {**prev, **entry}
                by_name[name] = merged

        if not by_name:
            self.stderr.write('Aucun index de paquets trouvé.')
            return

        count = 0
        for name, entry in by_name.items():
            tags = entry.get('tags') or []
            if isinstance(tags, str):
                tags = [tags]
            Package.objects.update_or_create(
                name=name,
                defaults={
                    'version': entry.get('version', '0.1.0') or '0.1.0',
                    'description': entry.get('description', ''),
                    'sha256': entry.get('sha256', ''),
                    'blessed': bool(entry.get('blessed', False)),
                    'repo_url': entry.get('url') or entry.get('web') or '',
                    'method': entry.get('method', 'local') or 'local',
                    'license': entry.get('license', ''),
                    'tags': list(tags),
                    'readme': _readme_for(root, name),
                },
            )
            count += 1
        self.stdout.write(self.style.SUCCESS(f'{count} paquet(s) synchronisé(s).'))
