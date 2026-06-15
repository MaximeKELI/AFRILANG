from django.conf import settings


def site_settings(request):
    return {
        'AFRILANG_BIN': settings.AFRILANG_BIN,
        'SITE_STATS': {
            'version': '1.0',
            'compiler_version': '1.0.0',
            'examples': 60,
            'blessed_packages': 10,
            'stdlib_modules': 463,
            'cli_commands': 15,
        },
    }
