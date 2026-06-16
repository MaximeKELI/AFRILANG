from django.core.management.base import BaseCommand

from core.models import StdlibModule
from core.services.stdlib_pdf import generate_all_pdfs, generate_pdf, pdf_dir


class Command(BaseCommand):
    help = 'Génère les PDF explicatifs (5+ pages, LaTeX/Tectonic) pour chaque bibliothèque stdlib'

    def add_arguments(self, parser):
        parser.add_argument('--name', help='Un seul module (ex: io, m/uuid2)')
        parser.add_argument('--category', help='Filtrer par catégorie')
        parser.add_argument('--limit', type=int, default=0, help='Limiter le nombre')
        parser.add_argument('--workers', type=int, default=6, help='Compilations parallèles')
        parser.add_argument(
            '--skip-existing',
            action='store_true',
            help='Ignorer les PDF LaTeX déjà générés (>15 Ko)',
        )

    def handle(self, *args, **options):
        qs = StdlibModule.objects.all()
        if options['name']:
            qs = qs.filter(name=options['name'])
        if options['category']:
            qs = qs.filter(category=options['category'])
        if options['limit']:
            qs = qs[: options['limit']]

        if options['name'] and qs.count() == 1:
            mod = qs.first()
            path = generate_pdf(mod)
            mod.has_pdf = True
            mod.save(update_fields=['has_pdf'])
            self.stdout.write(self.style.SUCCESS(f'PDF: {path}'))
            return

        self.stdout.write(
            f'Génération PDF → {pdf_dir()} '
            f'({qs.count()} modules, {options["workers"]} workers)…'
        )
        ok, fail = generate_all_pdfs(
            qs,
            workers=options['workers'],
            skip_existing=options['skip_existing'],
        )
        self.stdout.write(self.style.SUCCESS(f'{ok} PDF(s) généré(s), {fail} échec(s).'))
