import json

from django.http import HttpResponse, JsonResponse
from django.shortcuts import get_object_or_404, render
from django.views.decorators.http import require_GET, require_POST

from .content.docs_nav import docs_context
from .content.docs_pages import get_doc_page_by_url_name
from .content.ecosystem_i18n import translate_ecosystem
from .models import Capability, CodeExample, Package, PlaygroundRun
from .services.afrilang import AfrilangError, format_source, run_source, source_hash


def _doc_view(request, url_name):
    lang = request.LANGUAGE_CODE
    ctx = docs_context(url_name, lang)
    ctx['page'] = get_doc_page_by_url_name(url_name, lang)
    return render(request, 'docs/page.html', ctx)


def home(request):
    packages = Package.objects.filter(blessed=True)[:6]
    examples = CodeExample.objects.filter(featured=True)[:4]
    if not examples.exists():
        examples = CodeExample.objects.all()[:4]
    return render(request, 'core/home.html', {
        'packages': packages,
        'examples': examples,
    })


def language(request):
    return render(request, 'core/language.html')


def explore(request):
    caps = Capability.objects.all()
    by_category = {}
    for cap in caps:
        by_category.setdefault(cap.get_category_display(), []).append(cap)
    by_category = translate_ecosystem(by_category, request.LANGUAGE_CODE)
    return render(request, 'core/explore.html', {'by_category': by_category})


def docs_overview(request):
    return _doc_view(request, 'docs_overview')


def docs_getting_started(request):
    return _doc_view(request, 'docs_getting_started')


def docs_syntax(request):
    return _doc_view(request, 'docs_syntax')


def docs_types(request):
    return _doc_view(request, 'docs_types')


def docs_oop(request):
    return _doc_view(request, 'docs_oop')


def docs_advanced(request):
    return _doc_view(request, 'docs_advanced')


def docs_stdlib(request):
    return _doc_view(request, 'docs_stdlib')


def docs_tooling(request):
    return _doc_view(request, 'docs_tooling')


def download(request):
    return render(request, 'core/download.html')


def community(request):
    return render(request, 'core/community.html')


def api_reference(request):
    return render(request, 'core/api.html')


def packages_list(request):
    q = request.GET.get('q', '').strip()
    qs = Package.objects.all()
    if q:
        qs = qs.filter(name__icontains=q) | qs.filter(description__icontains=q)
    return render(request, 'core/packages.html', {'packages': qs, 'query': q})


def playground(request):
    examples = CodeExample.objects.all()
    examples_map = {ex.slug: ex.source for ex in examples}
    return render(request, 'core/playground.html', {
        'examples': examples,
        'examples_map': examples_map,
    })


def robots_txt(request):
    lines = [
        'User-agent: *',
        'Allow: /',
        'Disallow: /admin/',
        'Disallow: /api/',
        f'Sitemap: {request.build_absolute_uri("/sitemap.xml")}',
    ]
    return HttpResponse('\n'.join(lines), content_type='text/plain')


@require_GET
def api_packages(request):
    data = [
        {
            'name': p.name,
            'version': p.version,
            'description': p.description,
            'sha256': p.sha256,
            'blessed': p.blessed,
        }
        for p in Package.objects.all()
    ]
    return JsonResponse({'packages': data})


@require_POST
def api_run(request, target_override=None):
    try:
        body = json.loads(request.body.decode('utf-8'))
    except json.JSONDecodeError:
        return JsonResponse({'ok': False, 'output': 'Invalid JSON', 'exitCode': 1}, status=400)

    source = body.get('source', '')
    target = target_override or body.get('target', 'native')
    if not source.strip():
        return JsonResponse({'ok': False, 'output': 'Empty source', 'exitCode': 1}, status=400)

    try:
        result = run_source(source, target=target)
    except AfrilangError as e:
        return JsonResponse({'ok': False, 'output': str(e), 'exitCode': 1}, status=503)

    PlaygroundRun.objects.create(
        source_hash=source_hash(source),
        target=target,
        ok=result['ok'],
        exit_code=result['exitCode'],
        output_preview=result['output'][:2000],
        duration_ms=result.get('duration_ms', 0),
    )
    return JsonResponse({
        'ok': result['ok'],
        'output': result['output'],
        'exitCode': result['exitCode'],
    })


@require_POST
def api_fmt(request):
    try:
        body = json.loads(request.body.decode('utf-8'))
    except json.JSONDecodeError:
        return JsonResponse({'ok': False, 'output': 'Invalid JSON'}, status=400)

    source = body.get('source', '')
    try:
        result = format_source(source)
    except AfrilangError as e:
        return JsonResponse({'ok': False, 'output': str(e)}, status=503)

    return JsonResponse(result)


@require_GET
def api_example(request, slug):
    ex = get_object_or_404(CodeExample, slug=slug)
    return JsonResponse({'slug': ex.slug, 'title': ex.title, 'source': ex.source})
