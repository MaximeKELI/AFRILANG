import re
from pathlib import Path

from django.conf import settings
from django.core.management.base import BaseCommand

from core.models import StdlibModule

FUNCTION_RE = re.compile(r'^\s*(?:export\s+)?function\s+(\w+)', re.MULTILINE)


class Command(BaseCommand):
    help = 'Synchronise les modules stdlib depuis le dépôt AFRILANG'

    def handle(self, *args, **options):
        root = Path(settings.AFRILANG_ROOT) / 'stdlib'
        if not root.is_dir():
            self.stderr.write(f'Répertoire stdlib introuvable: {root}')
            return

        seen = set()
        count = 0
        for path in sorted(root.glob('*.afr')):
            name = path.stem
            text = path.read_text(encoding='utf-8', errors='replace')
            functions = FUNCTION_RE.findall(text)
            summary = ''
            if functions:
                preview = ', '.join(functions[:4])
                if len(functions) > 4:
                    preview += f' (+{len(functions) - 4})'
                summary = preview

            StdlibModule.objects.update_or_create(
                name=name,
                defaults={
                    'import_path': f'std/{name}',
                    'summary': summary[:512],
                    'function_count': len(functions),
                },
            )
            seen.add(name)
            count += 1

        removed, _ = StdlibModule.objects.exclude(name__in=seen).delete()
        self.stdout.write(self.style.SUCCESS(
            f'{count} module(s) stdlib synchronisé(s), {removed} supprimé(s).'
        ))
