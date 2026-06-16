from django.core.management import call_command
from django.core.management.base import BaseCommand


class Command(BaseCommand):
    help = 'Synchronise paquets, stdlib, exemples, releases et stats'

    def handle(self, *args, **options):
        for cmd in ('sync_packages', 'sync_stdlib', 'sync_examples', 'sync_releases', 'sync_stats'):
            self.stdout.write(f'→ {cmd}')
            call_command(cmd)
