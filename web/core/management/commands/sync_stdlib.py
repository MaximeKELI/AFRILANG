import re
from pathlib import Path

from django.conf import settings
from django.core.management.base import BaseCommand

from core.content.stdlib_core_api import CORE_MODULE_NAMES, parse_registry_functions
from core.models import StdlibModule
from core.services.stdlib_docs import clear_doc_cache
from core.services.stdlib_meta import enrich_module, read_module_source

FUNCTION_RE = re.compile(r'^\s*(?:export\s+)?function\s+(\w+)', re.MULTILINE)


class Command(BaseCommand):
    help = 'Synchronise stdlib avec descriptions FR/EN, catégories et catalogue core'

    def handle(self, *args, **options):
        root = Path(settings.AFRILANG_ROOT) / 'stdlib'
        if not root.is_dir():
            self.stderr.write(f'Répertoire stdlib introuvable: {root}')
            return

        # Précharge le registre C++
        parse_registry_functions.cache_clear()
        clear_doc_cache()
        parse_registry_functions()

        seen = set()
        count = 0

        # 1) Fichiers stdlib/*.afr
        for path in sorted(root.rglob('*.afr')):
            rel = path.relative_to(root).with_suffix('')
            name = str(rel).replace('\\', '/')
            text = path.read_text(encoding='utf-8', errors='replace')
            meta = enrich_module(name, text)
            base = name.split('/')[-1]
            is_core = base in CORE_MODULE_NAMES and not name.startswith(('m/', 'c/'))

            StdlibModule.objects.update_or_create(
                name=name,
                defaults={
                    'import_path': meta['import_path'],
                    'summary': meta['summary'],
                    'description_fr': meta['description_fr'],
                    'description_en': meta['description_en'],
                    'category': meta['category'] if not is_core else 'core',
                    'tier': 'core' if is_core else meta['tier'],
                    'function_count': meta['function_count'],
                    'is_core': is_core,
                    'experimental': not is_core,
                },
            )
            seen.add(name)
            count += 1

        # 2) Modules core absents du disque (injectés via registry)
        core_added = 0
        for name in sorted(CORE_MODULE_NAMES):
            if name in seen:
                # rafraîchir métadonnées core même si le .afr est un stub vide
                text = read_module_source(name) or ''
                meta = enrich_module(name, text)
                StdlibModule.objects.filter(name=name).update(
                    import_path=meta['import_path'],
                    summary=meta['summary'],
                    description_fr=meta['description_fr'],
                    description_en=meta['description_en'],
                    category='core',
                    tier='core',
                    function_count=meta['function_count'],
                    is_core=True,
                    experimental=False,
                )
                continue
            meta = enrich_module(name, '')
            StdlibModule.objects.update_or_create(
                name=name,
                defaults={
                    'import_path': meta['import_path'],
                    'summary': meta['summary'],
                    'description_fr': meta['description_fr'],
                    'description_en': meta['description_en'],
                    'category': 'core',
                    'tier': 'core',
                    'function_count': meta['function_count'],
                    'is_core': True,
                    'experimental': False,
                },
            )
            seen.add(name)
            core_added += 1
            count += 1

        # Ne pas supprimer les modules core même s'ils n'ont plus de fichier
        removed, _ = StdlibModule.objects.exclude(name__in=seen).exclude(
            name__in=CORE_MODULE_NAMES,
        ).delete()

        clear_doc_cache()
        parse_registry_functions.cache_clear()
        self.stdout.write(self.style.SUCCESS(
            f'{count} module(s) synchronisé(s) '
            f'({core_added} core sans .afr), {removed} supprimé(s).'
        ))
