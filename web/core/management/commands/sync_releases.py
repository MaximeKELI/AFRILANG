import re
from datetime import date
from pathlib import Path

from django.conf import settings
from django.core.management.base import BaseCommand

from core.models import Release

SECTION_RE = re.compile(r'^##\s+(.+)$', re.MULTILINE)


def _parse_date(text: str) -> date | None:
    m = re.search(r'(\d{4}-\d{2}-\d{2})', text)
    if m:
        y, mo, d = map(int, m.group(1).split('-'))
        return date(y, mo, d)
    return None


class Command(BaseCommand):
    help = 'Importe CHANGELOG.md dans la table Release'

    def handle(self, *args, **options):
        path = Path(settings.AFRILANG_ROOT) / 'CHANGELOG.md'
        if not path.is_file():
            self.stderr.write(f'CHANGELOG introuvable: {path}')
            return

        text = path.read_text(encoding='utf-8')
        matches = list(SECTION_RE.finditer(text))
        if not matches:
            self.stderr.write('Aucune section ## trouvée.')
            return

        seen = set()
        for i, match in enumerate(matches):
            version = match.group(1).strip()
            start = match.end()
            end = matches[i + 1].start() if i + 1 < len(matches) else len(text)
            body = text[start:end].strip()
            if version.lower() == 'unreleased':
                version_key = 'Unreleased'
            else:
                version_key = version

            Release.objects.update_or_create(
                version=version_key,
                defaults={
                    'title': version_key,
                    'body': body,
                    'released_at': _parse_date(version),
                    'sort_order': len(matches) - i,
                },
            )
            seen.add(version_key)

        removed, _ = Release.objects.exclude(version__in=seen).delete()
        self.stdout.write(self.style.SUCCESS(
            f'{len(seen)} release(s) synchronisée(s), {removed} supprimée(s).'
        ))
