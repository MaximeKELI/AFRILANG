"""API JSON pour l’app Flutter mobile — même backend que le site web."""
from __future__ import annotations

from django.http import JsonResponse
from django.shortcuts import get_object_or_404
from django.views.decorators.http import require_GET

from core.content.docs_nav import NAV_ITEMS, docs_context
from core.content.docs_pages import PAGES, get_doc_page
from core.content.site_ui import UI
from core.content.stdlib_catalog import get_categories
from core.content.tutorial import get_lesson, get_lessons, total_steps
from core.models import CodeExample, Package, Release, StdlibModule
from core.services.stdlib_meta import build_page_context


def _lang(request) -> str:
    lang = request.GET.get('lang') or request.LANGUAGE_CODE or 'fr'
    return 'en' if lang.startswith('en') else 'fr'


def _serialize_block(block: dict) -> dict:
    t = block.get('type')
    out = {'type': t}
    if t in ('h2', 'h3'):
        out['text'] = block.get('text', '')
    elif t == 'p':
        out['html'] = str(block.get('html', ''))
    elif t == 'code':
        out['text'] = block.get('text', '')
        out['header'] = block.get('header')
    elif t == 'ul':
        out['items'] = [str(i) for i in block.get('items', [])]
    elif t == 'callout':
        out['html'] = str(block.get('html', ''))
        out['variant'] = block.get('variant', 'info')
    elif t == 'table':
        out['headers'] = block.get('headers', [])
        out['rows'] = block.get('rows', [])
    elif t == 'nav_footer':
        out.update({
            'prev_url': block.get('prev_url'),
            'prev_label': block.get('prev_label'),
            'next_url': block.get('next_url'),
            'next_label': block.get('next_label'),
        })
    else:
        out['raw'] = {k: str(v) for k, v in block.items() if k != 'type'}
    return out


@require_GET
def api_mobile_bootstrap(request):
    """Config + strings UI + stats pour démarrer l’app."""
    lang = _lang(request)
    ui = UI.get(lang, UI['fr'])
    from django.conf import settings

    # Stats légères (miroir context processor)
    stats = {
        'version': getattr(settings, 'AFRILANG_LANG_VERSION', '1.0'),
        'compiler_version': getattr(settings, 'AFRILANG_COMPILER_VERSION', '1.0.0'),
        'examples': CodeExample.objects.count(),
        'stdlib_modules': StdlibModule.objects.count(),
        'blessed_packages': Package.objects.filter(blessed=True).count(),
        'core_modules': StdlibModule.objects.filter(is_core=True).count(),
    }
    docs_nav = [
        {'slug': slug, 'title': labels.get(lang, labels.get('fr', slug))}
        for slug, labels in [
            (item[0], __import__('core.content.docs_nav', fromlist=['NAV_LABELS']).NAV_LABELS.get(item[0], {'fr': item[0], 'en': item[0]}))
            for item in NAV_ITEMS
        ]
    ]
    return JsonResponse({
        'lang': lang,
        'ui': {
            'home': ui.get('home', {}),
            'nav_docs': ui.get('nav_docs'),
            'nav_packages': ui.get('nav_packages'),
            'nav_examples': ui.get('nav_examples'),
            'nav_playground': ui.get('nav_playground'),
            'nav_download': ui.get('nav_download'),
            'nav_stdlib': ui.get('nav_stdlib'),
            'nav_more': ui.get('nav_more'),
            'nav_start': ui.get('nav_start'),
            'meta_default': ui.get('meta_default'),
            'stdlib_page': ui.get('stdlib_page', {}),
            'libraries_page': ui.get('libraries_page', {}),
        },
        'stats': stats,
        'docs_nav': docs_nav,
        'theme': {
            'primary': '#1d4ed8',
            'primaryDark': '#1e3a8a',
            'accent': '#d97706',
            'bg': '#ffffff',
            'bgSubtle': '#f8fafc',
            'text': '#0f172a',
            'textSecondary': '#475569',
            'border': '#e2e8f0',
            'codeBg': '#0f172a',
        },
    })


@require_GET
def api_mobile_home(request):
    lang = _lang(request)
    ui = UI.get(lang, UI['fr'])
    packages = [
        {
            'name': p.name,
            'version': p.version,
            'description': p.description,
            'blessed': p.blessed,
            'tags': p.tag_list,
        }
        for p in Package.objects.filter(blessed=True).order_by('name')[:8]
    ]
    return JsonResponse({
        'lang': lang,
        'home': ui.get('home', {}),
        'packages': packages,
        'hero_code': (
            'create name text = "AFRILANG"\n'
            'say "Hello, {name}!"\n\n'
            'function greet(who text) returns text\n'
            '    return "Hello, " + who\n'
            'end\n\n'
            'create score number = 95\n'
            'if score is greater than or equal to 90 then\n'
            '    say greet(name) + " — Excellent!"\n'
            'else\n'
            '    say "Keep learning"\n'
            'end'
        ),
    })


@require_GET
def api_mobile_docs_index(request):
    lang = _lang(request)
    from core.content.docs_nav import NAV_LABELS

    items = []
    for slug, url_name in NAV_ITEMS:
        labels = NAV_LABELS.get(slug, {'fr': slug, 'en': slug})
        page = get_doc_page(slug, lang)
        items.append({
            'slug': slug,
            'title': labels.get(lang, labels.get('fr', slug)),
            'lead': page.get('lead', ''),
        })
    return JsonResponse({'lang': lang, 'pages': items})


@require_GET
def api_mobile_docs_page(request, slug):
    lang = _lang(request)
    if slug not in PAGES:
        return JsonResponse({'error': 'not_found'}, status=404)
    page = get_doc_page(slug, lang)
    ctx = docs_context(f'docs_{slug.replace("-", "_")}' if False else f'docs_{slug}', lang)
    # docs_context expects url_name like docs_getting_started — best-effort nav
    blocks = [_serialize_block(b) for b in page.get('blocks', [])]
    return JsonResponse({
        'lang': lang,
        'slug': slug,
        'title': page.get('title', slug),
        'lead': page.get('lead', ''),
        'blocks': blocks,
    })


@require_GET
def api_mobile_packages(request):
    q = request.GET.get('q', '').strip()
    qs = Package.objects.all()
    if q:
        qs = qs.filter(name__icontains=q) | qs.filter(description__icontains=q)
    data = [
        {
            'name': p.name,
            'version': p.version,
            'description': p.description,
            'blessed': p.blessed,
            'tags': p.tag_list,
            'readme': p.readme[:2000] if p.readme else '',
            'repo_url': p.repo_url,
        }
        for p in qs[:200]
    ]
    return JsonResponse({'packages': data, 'query': q})


@require_GET
def api_mobile_package_detail(request, name):
    pkg = get_object_or_404(Package, name=name)
    return JsonResponse({
        'name': pkg.name,
        'version': pkg.version,
        'description': pkg.description,
        'blessed': pkg.blessed,
        'tags': pkg.tag_list,
        'readme': pkg.readme,
        'repo_url': pkg.repo_url,
        'license': pkg.license,
        'install': f'afrilang pkg add {pkg.name}',
    })


@require_GET
def api_mobile_examples(request):
    lang = _lang(request)
    q = request.GET.get('q', '').strip()
    qs = CodeExample.objects.all()
    if q:
        qs = qs.filter(slug__icontains=q) | qs.filter(title__icontains=q)
    data = []
    for ex in qs[:120]:
        title = ex.title
        if lang == 'en' and getattr(ex, 'title_en', None):
            title = ex.title_en or title
        data.append({
            'slug': ex.slug,
            'title': title,
            'topic': getattr(ex, 'topic', '') or '',
            'source_preview': (ex.source or '')[:280],
        })
    return JsonResponse({'examples': data})


@require_GET
def api_mobile_stdlib(request):
    lang = _lang(request)
    q = request.GET.get('q', '').strip()
    core_only = request.GET.get('core', '1') not in ('0', 'false', 'no')
    experimental = request.GET.get('experimental', '') in ('1', 'true', 'yes')
    qs = StdlibModule.objects.all().order_by('name')
    if experimental:
        pass
    elif core_only:
        qs = qs.filter(is_core=True)
    if q:
        qs = qs.filter(name__icontains=q) | qs.filter(summary__icontains=q)
    modules = [
        {
            'name': m.name,
            'import_path': m.import_path,
            'summary': m.summary,
            'description': m.description_en if lang == 'en' else m.description_fr,
            'tier': m.tier,
            'category': m.category,
            'function_count': m.function_count,
            'is_core': m.is_core,
            'experimental': m.experimental,
        }
        for m in qs[:500]
    ]
    return JsonResponse({
        'lang': lang,
        'modules': modules,
        'categories': get_categories(lang),
        'total': len(modules),
        'core_only': core_only and not experimental,
    })


@require_GET
def api_mobile_stdlib_detail(request, name):
    lang = _lang(request)
    mod = get_object_or_404(StdlibModule, name=name)
    page = build_page_context(mod, lang)
    return JsonResponse({
        'lang': lang,
        'name': mod.name,
        'import_path': mod.import_path,
        'use_name': page['use_name'],
        'tier': mod.tier,
        'category': mod.category,
        'is_core': page['is_core'],
        'description': mod.description_en if lang == 'en' else mod.description_fr,
        'overview': page['overview'],
        'domain': page['domain'],
        'wasm_note': page['wasm_note'],
        'functions': page['functions'],
        'example': page['example'],
        'source': page['source'],
        'source_label': page['source_label'],
        'source_note': page['source_note'],
        'doc_body': (page['doc'] or {}).get('body') if page['doc'] else None,
        'links': page['links'],
    })


@require_GET
def api_mobile_tutorial(request):
    lang = _lang(request)
    lessons = get_lessons(lang)
    return JsonResponse({
        'lang': lang,
        'total_steps': total_steps(),
        'lessons': [
            {
                'step': i + 1,
                'title': lesson.get('title', f'Step {i+1}'),
                'summary': lesson.get('summary', ''),
            }
            for i, lesson in enumerate(lessons)
        ],
    })


@require_GET
def api_mobile_tutorial_step(request, step: int):
    lang = _lang(request)
    lesson = get_lesson(step, lang)
    if not lesson:
        return JsonResponse({'error': 'not_found'}, status=404)
    return JsonResponse({
        'lang': lang,
        'step': step,
        'total_steps': total_steps(),
        'lesson': lesson,
    })


@require_GET
def api_mobile_releases(request):
    data = [
        {
            'version': r.version,
            'date': r.released_at.isoformat() if getattr(r, 'released_at', None) else '',
            'title': r.title,
            'body': r.body[:4000],
        }
        for r in Release.objects.all().order_by('-released_at')[:40]
    ]
    return JsonResponse({'releases': data})
