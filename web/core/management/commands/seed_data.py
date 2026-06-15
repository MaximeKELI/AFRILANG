from django.core.management.base import BaseCommand

from core.models import Capability, CodeExample


EXAMPLES = [
    ('hello', 'Hello World', True, '''say "Hello from AFRILANG!"

repeat 3 times
    say "Hello"
end
'''),
    ('natural', 'Syntaxe naturelle', False, '''say "Natural English syntax"

if 42 is greater than 40 then
    say "Condition is true"
else
    say "False branch"
end
'''),
    ('oop', 'Classes', True, '''class Greeter
    function hello()
        say "Hello from a class!"
    end
end

create g = new Greeter
g.hello()
'''),
    ('generics', 'Génériques', False, '''function identity<T>(x T) returns T
    return x
end

say identity(42)
say identity("hello")
'''),
    ('wasm', 'WASM demo', True, '''say "Phase E WASM OK"

create i int = 0
while i is less than 3 do
    say "hello wasm"
    set i = i + 1
end
'''),
]

CAPABILITIES = [
    ('lang', 'Langage', 1, [
        'Syntaxe naturelle FR / EN',
        'POO, génériques, enums, match, async',
        'Lambdas, traits, records, unions',
    ]),
    ('compiler', 'Compilateur', 2, [
        'Transpilation C++17 + g++/clang++',
        'Cibles: native, linux-x64, linux-arm64, wasm32',
        'Cache, symboles debug, mode sécurisé',
    ]),
    ('cli', 'CLI', 3, [
        'run, build, check, test, fmt, lint, repl',
        'pkg, debug, benchmark, serve',
    ]),
    ('stdlib', 'Stdlib', 4, [
        'io, json, fs, http, crypto, yaml, csv',
        'math, datetime, collections, thread…',
    ]),
    ('pkg', 'Paquets blessed', 5, [
        '10 paquets officiels SHA256',
        'math, strings, fmt, validate, config…',
    ]),
    ('wasm', 'WASM & Web', 6, [
        'Emscripten, Run in browser',
        'Playground Django + API REST',
    ]),
    ('lsp', 'LSP & IDE', 7, [
        'Diagnostics, symboles, code actions',
        'Extension VS Code / Open VSX',
    ]),
    ('debug', 'Debug', 8, [
        'DAP GDB/MI, métadonnées Afrilang',
        'Pretty-print des variables typées',
    ]),
    ('async', 'Async & UI', 9, [
        'async/await, SDL2 UI, FFI extern',
    ]),
    ('ci', 'Qualité & CI', 10, [
        '60+ exemples, wasm-build CI, Docker',
    ]),
]


class Command(BaseCommand):
    help = 'Peuple PostgreSQL avec exemples et capacités par défaut'

    def handle(self, *args, **options):
        for i, (slug, title, featured, source) in enumerate(EXAMPLES):
            CodeExample.objects.update_or_create(
                slug=slug,
                defaults={
                    'title': title,
                    'source': source,
                    'featured': featured,
                    'sort_order': i,
                },
            )

        Capability.objects.all().delete()
        for cat, title, order, items in CAPABILITIES:
            Capability.objects.create(
                category=cat,
                title=title,
                sort_order=order,
                items=items,
            )

        self.stdout.write(self.style.SUCCESS('Données initiales créées.'))
