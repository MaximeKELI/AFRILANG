from django import template
from django.urls import translate_url

register = template.Library()


@register.simple_tag(takes_context=True)
def switch_lang_url(context, lang_code):
    """Return same page URL in target language (i18n URL prefix)."""
    request = context.get('request')
    if not request:
        return '/'
    return translate_url(request.get_full_path(), lang_code)


@register.simple_tag(takes_context=True)
def hreflang_url(context, lang_code, url_name=None):
    """Absolute hreflang URL for SEO."""
    request = context.get('request')
    if not request:
        return ''
    from django.urls import reverse

    name = url_name or getattr(context.get('request').resolver_match, 'url_name', None) or 'home'
    match = context['request'].resolver_match
    try:
        if match and match.url_name == name:
            path = translate_url(request.path, lang_code)
            if request.GET:
                path += '?' + request.GET.urlencode()
        else:
            from django.utils import translation

            with translation.override(lang_code):
                path = reverse(name)
    except Exception:
        from django.utils import translation

        with translation.override(lang_code):
            path = reverse('home')
    return request.build_absolute_uri(path)
