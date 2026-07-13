"""API JSON pour l’app Flutter mobile — même backend que le site web."""
from __future__ import annotations

import json

from django.http import JsonResponse
from django.shortcuts import get_object_or_404
from django.views.decorators.csrf import csrf_exempt
from django.views.decorators.http import require_GET, require_http_methods

from core.content.docs_nav import NAV_DESC, NAV_LABELS, NAV_META, get_docs_nav
from core.content.docs_pages import PAGES, get_doc_page
from core.content.site_ui import UI
from core.content.stdlib_catalog import get_categories
from core.content.tutorial import get_lesson, get_lessons, total_steps
from core.models import CodeExample, Package, Release, StdlibModule
from core.services.afrilang import AfrilangError, check_source, format_source, run_source, source_hash
from core.services.stdlib_meta import build_page_context
from core.models import PlaygroundRun


def _lang(request) -> str:
    lang = request.GET.get('lang') or getattr(request, 'LANGUAGE_CODE', None) or 'fr'
    return 'en' if str(lang).startswith('en') else 'fr'


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


def _cors(response: JsonResponse) -> JsonResponse:
    response['Access-Control-Allow-Origin'] = '*'
    response['Access-Control-Allow-Methods'] = 'GET, POST, OPTIONS'
    response['Access-Control-Allow-Headers'] = 'Content-Type, Accept, X-Afrilang-Client'
    return response


def _json(data, status=200):
    return _cors(JsonResponse(data, status=status, json_dumps_params={'ensure_ascii': False}))


@require_GET
def api_mobile_bootstrap(request):
    """Config + strings UI + stats pour démarrer l’app."""
    lang = _lang(request)
    ui = UI.get(lang, UI['fr'])
    from django.conf import settings

    stats = {
        'version': getattr(settings, 'AFRILANG_LANG_VERSION', '1.0'),
        'compiler_version': getattr(settings, 'AFRILANG_COMPILER_VERSION', '1.0.0'),
        'examples': CodeExample.objects.count(),
        'stdlib_modules': StdlibModule.objects.count(),
        'blessed_packages': Package.objects.filter(blessed=True).count(),
        'core_modules': StdlibModule.objects.filter(is_core=True).count(),
    }
    docs_nav = []
    for slug, _url_name in NAV_META:
        labels = NAV_LABELS.get(slug, {'fr': slug, 'en': slug})
        desc = NAV_DESC.get(slug, {'fr': '', 'en': ''})
        docs_nav.append({
            'slug': slug,
            'title': labels.get(lang, labels.get('fr', slug)),
            'description': desc.get(lang, desc.get('fr', '')),
        })
    return _json({
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
            'nav_tutorial': ui.get('nav_tutorial'),
            'nav_language': ui.get('nav_language'),
            'nav_community': ui.get('nav_community'),
            'meta_default': ui.get('meta_default'),
            'stdlib_page': ui.get('stdlib_page', {}),
            'libraries_page': ui.get('libraries_page', {}),
            'footer_tagline': ui.get('footer_tagline'),
            'footer_desc': ui.get('footer_desc'),
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
    return _json({
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
    items = []
    for item in get_docs_nav(lang):
        page = get_doc_page(item['slug'], lang)
        items.append({
            'slug': item['slug'],
            'title': item['title'],
            'description': item.get('description', ''),
            'lead': page.get('lead', ''),
        })
    return _json({'lang': lang, 'pages': items})


@require_GET
def api_mobile_docs_page(request, slug):
    lang = _lang(request)
    if slug not in PAGES:
        return _json({'error': 'not_found'}, status=404)
    page = get_doc_page(slug, lang)
    blocks = [_serialize_block(b) for b in page.get('blocks', [])]
    return _json({
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
        from django.db.models import Q
        qs = qs.filter(Q(name__icontains=q) | Q(description__icontains=q))
    data = [
        {
            'name': p.name,
            'version': p.version,
            'description': p.description,
            'blessed': p.blessed,
            'tags': p.tag_list,
            'readme': (p.readme or '')[:2000],
            'repo_url': p.repo_url,
        }
        for p in qs[:200]
    ]
    return _json({'packages': data, 'query': q})


@require_GET
def api_mobile_package_detail(request, name):
    pkg = get_object_or_404(Package, name=name)
    return _json({
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
        from django.db.models import Q
        qs = qs.filter(Q(slug__icontains=q) | Q(title__icontains=q) | Q(description__icontains=q))
    data = [
        {
            'slug': ex.slug,
            'title': ex.title,
            'description': ex.description,
            'featured': ex.featured,
            'source_preview': (ex.source or '')[:280],
        }
        for ex in qs[:120]
    ]
    return _json({'lang': lang, 'examples': data})


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
        from django.db.models import Q
        qs = qs.filter(Q(name__icontains=q) | Q(summary__icontains=q))
    modules = [
        {
            'name': m.name,
            'import_path': m.import_path,
            'summary': m.summary,
            'description': m.description(lang),
            'tier': m.tier,
            'category': m.category,
            'function_count': m.function_count,
            'is_core': m.is_core,
            'experimental': m.experimental,
        }
        for m in qs[:500]
    ]
    return _json({
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
    doc = page.get('doc') or {}
    return _json({
        'lang': lang,
        'name': mod.name,
        'import_path': mod.import_path,
        'use_name': page['use_name'],
        'tier': mod.tier,
        'category': mod.category,
        'is_core': page['is_core'],
        'description': mod.description(lang),
        'overview': page['overview'],
        'domain': page['domain'],
        'wasm_note': page['wasm_note'],
        'functions': page['functions'],
        'example': page['example'],
        'source': page['source'],
        'source_label': page['source_label'],
        'source_note': page['source_note'],
        'doc_body': doc.get('body') if doc else None,
        'links': page['links'],
    })


@require_GET
def api_mobile_tutorial(request):
    lang = _lang(request)
    lessons = get_lessons(lang)
    return _json({
        'lang': lang,
        'total_steps': total_steps(),
        'lessons': [
            {
                'step': lesson['step'],
                'title': lesson['title'],
                'summary': lesson['summary'],
                'duration_min': lesson.get('duration_min', 5),
            }
            for lesson in lessons
        ],
    })


@require_GET
def api_mobile_tutorial_step(request, step: int):
    lang = _lang(request)
    lesson = get_lesson(step, lang)
    if not lesson:
        return _json({'error': 'not_found'}, status=404)
    return _json({
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
            'date': r.released_at.isoformat() if r.released_at else '',
            'title': r.title,
            'body': (r.body or '')[:4000],
        }
        for r in Release.objects.all().order_by('-sort_order', '-released_at')[:40]
    ]
    return _json({'releases': data})


@csrf_exempt
@require_http_methods(['POST', 'OPTIONS'])
def api_mobile_run(request):
    """Playground run — CSRF exempt pour clients mobiles (rate-limité)."""
    if request.method == 'OPTIONS':
        return _cors(JsonResponse({}))
    try:
        body = json.loads(request.body.decode('utf-8'))
    except json.JSONDecodeError:
        return _json({'ok': False, 'output': 'Invalid JSON', 'exitCode': 1}, status=400)

    source = body.get('source', '')
    target = body.get('target', 'native')
    if not source.strip():
        return _json({'ok': False, 'output': 'Empty source', 'exitCode': 1}, status=400)

    try:
        result = run_source(source, target=target)
    except AfrilangError as e:
        return _json({'ok': False, 'output': str(e), 'exitCode': 1}, status=503)

    PlaygroundRun.objects.create(
        source_hash=source_hash(source),
        target=target,
        ok=result['ok'],
        exit_code=result['exitCode'],
        output_preview=result['output'][:2000],
        duration_ms=result.get('duration_ms', 0),
    )
    return _json({
        'ok': result['ok'],
        'output': result['output'],
        'exitCode': result['exitCode'],
    })


@csrf_exempt
@require_http_methods(['POST', 'OPTIONS'])
def api_mobile_fmt(request):
    if request.method == 'OPTIONS':
        return _cors(JsonResponse({}))
    try:
        body = json.loads(request.body.decode('utf-8'))
    except json.JSONDecodeError:
        return _json({'ok': False, 'output': 'Invalid JSON'}, status=400)
    try:
        result = format_source(body.get('source', ''))
    except AfrilangError as e:
        return _json({'ok': False, 'output': str(e)}, status=503)
    return _json(result)


@csrf_exempt
@require_http_methods(['POST', 'OPTIONS'])
def api_mobile_check(request):
    if request.method == 'OPTIONS':
        return _cors(JsonResponse({}))
    try:
        body = json.loads(request.body.decode('utf-8'))
    except json.JSONDecodeError:
        return _json({'ok': False, 'output': 'Invalid JSON'}, status=400)
    source = body.get('source', '')
    if not source.strip():
        return _json({'ok': False, 'output': 'Empty source', 'errors': 1}, status=400)
    try:
        result = check_source(source)
    except AfrilangError as e:
        return _json({'ok': False, 'output': str(e), 'errors': 1}, status=503)
    return _json(result)
