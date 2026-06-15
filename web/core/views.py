import json

from django.http import JsonResponse
from django.shortcuts import get_object_or_404, render
from django.views.decorators.http import require_GET, require_POST

from .models import Capability, CodeExample, Package, PlaygroundRun
from .services.afrilang import AfrilangError, format_source, run_source, source_hash


def home(request):
    packages = Package.objects.filter(blessed=True)[:10]
    examples = CodeExample.objects.filter(featured=True)[:5]
    if not examples.exists():
        examples = CodeExample.objects.all()[:5]
    return render(request, 'core/home.html', {
        'packages': packages,
        'examples': examples,
    })


def explore(request):
    caps = Capability.objects.all()
    by_category = {}
    for cap in caps:
        by_category.setdefault(cap.get_category_display(), []).append(cap)
    return render(request, 'core/explore.html', {'by_category': by_category})


def docs(request):
    return render(request, 'core/docs.html')


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
        return JsonResponse({'ok': False, 'output': 'JSON invalide', 'exitCode': 1}, status=400)

    source = body.get('source', '')
    target = target_override or body.get('target', 'native')
    if not source.strip():
        return JsonResponse({'ok': False, 'output': 'Source vide', 'exitCode': 1}, status=400)

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
        return JsonResponse({'ok': False, 'output': 'JSON invalide'}, status=400)

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
