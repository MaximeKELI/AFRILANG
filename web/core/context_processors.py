from django.conf import settings


def site_settings(request):
    return {
        'AFRILANG_BIN': settings.AFRILANG_BIN,
        'SITE_STATS': {
            'examples': 60,
            'blessed_packages': 10,
            'stdlib_modules': 14,
        },
    }
