import re
from pathlib import Path

from django.conf import settings
from django.core.management.base import BaseCommand
from django.utils.text import slugify

from core.models import CodeExample

# Exemples mis en avant (playground / accueil). Pas de GUI desktop (snake, gui_demo) :
# ils restent dans la galerie mais ne doivent pas apparaître comme « ça marche ici ».
FEATURED = {
    'hello', 'conditions', 'oop', 'generics', 'async_demo', 'traits_demo',
    'match_expr_demo', 'stdlib_demo', 'list_ops', 'natural_list_ops',
}


def _title_from_slug(slug: str) -> str:
    return slug.replace('_', ' ').replace('-', ' ').title()


def _description_from_source(source: str) -> str:
    lines = []
    for line in source.splitlines():
        stripped = line.strip()
        if stripped.startswith('#'):
            lines.append(stripped.lstrip('#').strip())
        elif stripped:
            break
    return ' '.join(lines)[:500]


class Command(BaseCommand):
    help = 'Importe les exemples .afr du dépôt dans la base'

    def handle(self, *args, **options):
        root = Path(settings.AFRILANG_ROOT) / 'examples'
        if not root.is_dir():
            self.stderr.write(f'Répertoire examples introuvable: {root}')
            return

        seen = set()
        count = 0
        for i, path in enumerate(sorted(root.glob('*.afr'))):
            slug = slugify(path.stem) or path.stem
            source = path.read_text(encoding='utf-8', errors='replace')
            CodeExample.objects.update_or_create(
                slug=slug,
                defaults={
                    'title': _title_from_slug(path.stem),
                    'description': _description_from_source(source),
                    'source': source,
                    'featured': path.stem in FEATURED or slug in FEATURED,
                    'sort_order': i,
                },
            )
            seen.add(slug)
            count += 1

        removed, _ = CodeExample.objects.exclude(slug__in=seen).delete()
        self.stdout.write(self.style.SUCCESS(
            f'{count} exemple(s) synchronisé(s), {removed} supprimé(s).'
        ))
