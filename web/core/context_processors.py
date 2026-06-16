from django.conf import settings


def _default_stats():
    return {
        'version': '1.0',
        'compiler_version': '1.0.0',
        'examples': 60,
        'blessed_packages': 10,
        'stdlib_modules': 7971,
        'cli_commands': 15,
    }


def site_settings(request):
    stats = _default_stats()
    try:
        from .models import SiteMetric
        row = SiteMetric.objects.filter(key='site_stats').first()
        if row and isinstance(row.value, dict):
            stats.update(row.value)
    except Exception:
        pass

    return {
        'AFRILANG_BIN': settings.AFRILANG_BIN,
        'SITE_STATS': stats,
        'SITE_URL': getattr(settings, 'SITE_URL', 'http://127.0.0.1:8000'),
        'PLAYGROUND_RATE_LIMIT': getattr(settings, 'PLAYGROUND_RATE_LIMIT', 30),
        'PLAYGROUND_RATE_WINDOW': getattr(settings, 'PLAYGROUND_RATE_WINDOW', 3600),
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
