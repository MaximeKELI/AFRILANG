import json
from pathlib import Path

from django.conf import settings
from django.core.management.base import BaseCommand

from core.models import Package


class Command(BaseCommand):
    help = 'Synchronise les paquets depuis packages/index.json ou site/packages.json'

    def handle(self, *args, **options):
        root = Path(settings.AFRILANG_ROOT)
        candidates = [
            root / 'packages' / 'index.json',
            root / 'site' / 'packages.json',
        ]
        data = None
        for path in candidates:
            if path.is_file():
                data = json.loads(path.read_text(encoding='utf-8'))
                self.stdout.write(f'Lu: {path}')
                break

        if not data:
            self.stderr.write('Aucun index de paquets trouvé.')
            return

        count = 0
        for entry in data.get('packages', []):
            Package.objects.update_or_create(
                name=entry['name'],
                defaults={
                    'version': entry.get('version', '0.1.0'),
                    'description': entry.get('description', ''),
                    'sha256': entry.get('sha256', ''),
                    'blessed': entry.get('blessed', False),
                },
            )
            count += 1
        self.stdout.write(self.style.SUCCESS(f'{count} paquet(s) synchronisé(s).'))
