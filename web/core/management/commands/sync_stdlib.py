import re
from pathlib import Path

from django.conf import settings
from django.core.management.base import BaseCommand

from core.models import StdlibModule
from core.services.stdlib_meta import enrich_module
from core.services.stdlib_pdf import generate_all_pdfs, generate_pdf

FUNCTION_RE = re.compile(r'^\s*(?:export\s+)?function\s+(\w+)', re.MULTILINE)

# Mirrors StdlibRegistry::isLegacyStdlibModule (+ aliases)
CORE_MODULES = {
    'io', 'json', 'fs', 'http', 'str', 'logging', 'log', 'math', 'chrono', 'time',
    're', 'collections', 'args', 'path', 'sql', 'web', 'orm', 'thread', 'bigint',
    'crypto', 'yaml', 'datetime', 'env', 'tempfile', 'base64', 'url', 'random',
    'hex', 'csv', 'html', 'cli', 'email', 'uuid', 'async', 'ui', 'game2d',
    'game3d', 'gamestate', 'gamenet',
}


def _module_base(name: str) -> str:
    # stdlib/m/foo -> foo, stdlib paths use name without std/
    base = name.split('/')[-1]
    return base


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
            base = _module_base(name)
            is_core = base in CORE_MODULES and not name.startswith(('m/', 'c/'))

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
                    'is_core': is_core,
                    'experimental': not is_core,
                },
            )
            seen.add(name)
            count += 1

        removed, _ = StdlibModule.objects.exclude(name__in=seen).delete()
        from core.services.stdlib_docs import _load_all_sections
        _load_all_sections.cache_clear()
        self.stdout.write(self.style.SUCCESS(
            f'{count} module(s) synchronisé(s), {removed} supprimé(s).'
        ))
