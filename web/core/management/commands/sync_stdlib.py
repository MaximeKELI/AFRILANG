import re
from pathlib import Path

from django.conf import settings
from django.core.management.base import BaseCommand

from core.models import StdlibModule
from core.services.stdlib_meta import enrich_module
from core.services.stdlib_pdf import generate_all_pdfs, generate_pdf

FUNCTION_RE = re.compile(r'^\s*(?:export\s+)?function\s+(\w+)', re.MULTILINE)


class Command(BaseCommand):
    help = 'Synchronise stdlib avec descriptions FR/EN et catégories'

    def handle(self, *args, **options):
        root = Path(settings.AFRILANG_ROOT) / 'stdlib'
        if not root.is_dir():
            self.stderr.write(f'Répertoire stdlib introuvable: {root}')
            return

        seen = set()
        count = 0
        for path in sorted(root.rglob('*.afr')):
            rel = path.relative_to(root).with_suffix('')
            name = str(rel).replace('\\', '/')
            text = path.read_text(encoding='utf-8', errors='replace')
            meta = enrich_module(name, text)

            StdlibModule.objects.update_or_create(
                name=name,
                defaults={
                    'import_path': meta['import_path'],
                    'summary': meta['summary'],
                    'description_fr': meta['description_fr'],
                    'description_en': meta['description_en'],
                    'category': meta['category'],
                    'tier': meta['tier'],
                    'function_count': meta['function_count'],
                },
            )
            seen.add(name)
            count += 1

        removed, _ = StdlibModule.objects.exclude(name__in=seen).delete()
        self.stdout.write(self.style.SUCCESS(
            f'{count} module(s) synchronisé(s), {removed} supprimé(s).'
        ))
