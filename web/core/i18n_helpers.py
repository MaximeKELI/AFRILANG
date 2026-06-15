from django.utils import translation


def current_lang():
    return (translation.get_language() or 'fr')[:2]


def pick(fr_text, en_text, lang=None):
    code = (lang or current_lang())[:2]
    return en_text if code == 'en' else fr_text
