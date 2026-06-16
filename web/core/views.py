import json
from pathlib import Path

from django.conf import settings
from django.http import FileResponse, Http404, HttpResponse, JsonResponse
from django.shortcuts import get_object_or_404, render
from django.views.decorators.http import require_GET, require_POST

from .content.docs_nav import docs_context
from .content.docs_pages import get_doc_page_by_url_name
from .content.docs_search import search_docs
from .content.ecosystem_i18n import translate_ecosystem
from .content.example_topics import grouped_examples
from .content.tutorial import get_lesson, get_lessons, total_steps
from .models import Capability, CodeExample, Package, PlaygroundRun, Release, StdlibModule
from .services.afrilang import (
    AfrilangError,
    build_wasm_web,
    check_source,
    compile_to_js,
    format_source,
    run_source,
    source_hash,
    wasm_session_path,
)
from .services.downloads import get_download_context, resolve_binary
from .services.stdlib_docs import get_module_doc


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


def docs_functional(request):
    return _doc_view(request, 'docs_functional')


def docs_pattern(request):
    return _doc_view(request, 'docs_pattern')


def docs_modules(request):
    return _doc_view(request, 'docs_modules')


def docs_exceptions(request):
    return _doc_view(request, 'docs_exceptions')


def docs_async(request):
    return _doc_view(request, 'docs_async')


def docs_gui(request):
    return _doc_view(request, 'docs_gui')


def docs_pkg(request):
    return _doc_view(request, 'docs_pkg')


def docs_spec(request):
    return _doc_view(request, 'docs_spec')


def download(request):
    ctx = get_download_context()
    return render(request, 'core/download.html', ctx)


@require_GET
def download_binary(request, platform):
    path = resolve_binary(platform)
    if not path:
        raise Http404('Binary not available for this platform')
    response = FileResponse(path.open('rb'), as_attachment=True, filename='afrilang')
    response['X-Content-Type-Options'] = 'nosniff'
    return response


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


def package_detail(request, name):
    pkg = get_object_or_404(Package, name=name)
    source = ''
    pkg_path = Path(settings.AFRILANG_ROOT) / 'packages' / name / f'{name}.afr'
    if pkg_path.is_file():
        source = pkg_path.read_text(encoding='utf-8', errors='replace')
    return render(request, 'core/package_detail.html', {'pkg': pkg, 'source': source})


def examples_gallery(request):
    q = request.GET.get('q', '').strip()
    qs = CodeExample.objects.all()
    if q:
        qs = qs.filter(title__icontains=q) | qs.filter(description__icontains=q) | qs.filter(slug__icontains=q)
    groups = grouped_examples(qs, request.LANGUAGE_CODE) if not q else None
    return render(request, 'core/examples.html', {
        'examples': qs,
        'groups': groups,
        'query': q,
    })


def stdlib_browse(request):
    q = request.GET.get('q', '').strip()
    qs = StdlibModule.objects.all()
    if q:
        qs = qs.filter(name__icontains=q) | qs.filter(summary__icontains=q) | qs.filter(import_path__icontains=q)
    return render(request, 'core/stdlib.html', {'modules': qs, 'query': q})


def stdlib_detail(request, name):
    mod = get_object_or_404(StdlibModule, name=name)
    path = Path(settings.AFRILANG_ROOT) / 'stdlib' / f'{name}.afr'
    if not path.is_file():
        raise Http404('Module source not found')
    source = path.read_text(encoding='utf-8', errors='replace')
    doc = get_module_doc(name)
    return render(request, 'core/stdlib_detail.html', {
        'mod': mod, 'source': source, 'doc': doc,
    })


def _parse_release_body(body: str) -> list[dict]:
    items = []
    for line in body.splitlines():
        stripped = line.strip()
        if not stripped:
            continue
        if stripped.startswith('### '):
            items.append({'type': 'h3', 'text': stripped[4:]})
        elif stripped.startswith('- '):
            items.append({'type': 'li', 'text': stripped[2:]})
        else:
            items.append({'type': 'p', 'text': stripped})
    return items


def releases(request):
    items = []
    for rel in Release.objects.all():
        items.append({
            'version': rel.version,
            'released_at': rel.released_at,
            'blocks': _parse_release_body(rel.body),
        })
    return render(request, 'core/releases.html', {'releases': items})


def docs_search_view(request):
    q = request.GET.get('q', '').strip()
    results = search_docs(q, request.LANGUAGE_CODE) if q else []
    ctx = docs_context('docs_overview', request.LANGUAGE_CODE)
    ctx.update({'query': q, 'results': results})
    return render(request, 'core/docs_search.html', ctx)


def tutorial(request, step=None):
    lang = request.LANGUAGE_CODE
    lessons = get_lessons(lang)
    total = total_steps()
    ctx = {
        'lessons': lessons,
        'total_steps': total,
        'current_step': 0,
    }
    if step is not None:
        lesson = get_lesson(step, lang)
        if not lesson:
            raise Http404
        ctx.update({
            'lesson': lesson,
            'current_step': step,
            'prev_step': step - 1 if step > 1 else None,
            'next_step': step + 1 if step < total else None,
        })
    return render(request, 'core/tutorial.html', ctx)


def playground(request):
    examples = CodeExample.objects.all()
    examples_map = {ex.slug: ex.source for ex in examples}
    initial_slug = request.GET.get('example', '').strip()
    return render(request, 'core/playground.html', {
        'examples': examples,
        'examples_map': examples_map,
        'initial_slug': initial_slug,
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


@require_POST
def api_check(request):
    try:
        body = json.loads(request.body.decode('utf-8'))
    except json.JSONDecodeError:
        return JsonResponse({'ok': False, 'output': 'Invalid JSON'}, status=400)

    source = body.get('source', '')
    if not source.strip():
        return JsonResponse({'ok': False, 'output': 'Empty source', 'errors': 1}, status=400)

    try:
        result = check_source(source)
    except AfrilangError as e:
        return JsonResponse({'ok': False, 'output': str(e), 'errors': 1}, status=503)

    return JsonResponse(result)


@require_GET
def api_example(request, slug):
    ex = get_object_or_404(CodeExample, slug=slug)
    return JsonResponse({'slug': ex.slug, 'title': ex.title, 'source': ex.source})


@require_POST
def api_compile_js(request):
    try:
        body = json.loads(request.body.decode('utf-8'))
    except json.JSONDecodeError:
        return JsonResponse({'ok': False, 'output': 'Invalid JSON'}, status=400)

    source = body.get('source', '')
    if not source.strip():
        return JsonResponse({'ok': False, 'output': 'Empty source'}, status=400)

    try:
        result = compile_to_js(source)
    except AfrilangError as e:
        return JsonResponse({'ok': False, 'output': str(e)}, status=503)

    return JsonResponse(result)


@require_POST
def api_build_wasm(request):
    try:
        body = json.loads(request.body.decode('utf-8'))
    except json.JSONDecodeError:
        return JsonResponse({'ok': False, 'output': 'Invalid JSON'}, status=400)

    source = body.get('source', '')
    if not source.strip():
        return JsonResponse({'ok': False, 'output': 'Empty source'}, status=400)

    try:
        result = build_wasm_web(source)
    except AfrilangError as e:
        return JsonResponse({'ok': False, 'output': str(e)}, status=503)

    return JsonResponse(result)


@require_GET
def api_wasm_asset(request, session_id, filename):
    path = wasm_session_path(session_id, filename)
    if not path:
        raise Http404
    content_type = 'application/javascript' if filename.endswith('.js') else 'application/wasm'
    return FileResponse(open(path, 'rb'), content_type=content_type)
