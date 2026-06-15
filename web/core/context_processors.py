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
        'SITE_URL': getattr(settings, 'SITE_URL', 'http://127.0.0.1:8000'),
    }


def i18n_ui(request):
    from django.utils import translation

    from .content.docs_nav import get_docs_nav
    from .content.site_ui import get_ui
    from .i18n_helpers import current_lang

    lang = current_lang()
    return {
        'ui': get_ui(lang),
        'current_lang': lang,
        'languages': settings.LANGUAGES,
        'LANGUAGE_CODE': translation.get_language(),
        'docs_nav': get_docs_nav(lang),
    }
