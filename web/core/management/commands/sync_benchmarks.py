import json

from django.core.management.base import BaseCommand

from core.models import SiteMetric
from core.services.benchmarks import run_benchmarks


class Command(BaseCommand):
    help = 'Exécute scripts/benchmark.sh et enregistre les résultats (SiteMetric benchmarks)'

    def handle(self, *args, **options):
        data = run_benchmarks()
        SiteMetric.objects.update_or_create(key='benchmarks', defaults={'value': data})
        self.stdout.write(self.style.SUCCESS(json.dumps(data, indent=2)))
