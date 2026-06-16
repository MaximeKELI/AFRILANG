"""Rate limiting for playground API endpoints (by IP)."""
from __future__ import annotations

import hashlib

from django.conf import settings
from django.core.cache import cache
from django.http import JsonResponse

LIMITED_PREFIXES = (
    '/api/run/',
    '/api/fmt/',
    '/api/check/',
)


class PlaygroundRateLimitMiddleware:
    def __init__(self, get_response):
        self.get_response = get_response
        self.limit = getattr(settings, 'PLAYGROUND_RATE_LIMIT', 30)
        self.window = getattr(settings, 'PLAYGROUND_RATE_WINDOW', 3600)

    def __call__(self, request):
        if request.method == 'POST' and self._is_limited_path(request.path):
            key = self._cache_key(request)
            count = cache.get(key, 0)
            if count >= self.limit:
                return JsonResponse({
                    'ok': False,
                    'output': (
                        f'Rate limit exceeded ({self.limit} requests per '
                        f'{self.window // 60} min). Try again later.'
                    ),
                    'exitCode': 429,
                }, status=429)
            cache.set(key, count + 1, self.window)
        return self.get_response(request)

    @staticmethod
    def _is_limited_path(path: str) -> bool:
        return any(path.startswith(p) for p in LIMITED_PREFIXES)

    @staticmethod
    def _cache_key(request) -> str:
        forwarded = request.META.get('HTTP_X_FORWARDED_FOR', '')
        ip = forwarded.split(',')[0].strip() if forwarded else request.META.get('REMOTE_ADDR', 'unknown')
        path_hash = hashlib.sha256(request.path.encode()).hexdigest()[:8]
        return f'afr_rl:{ip}:{path_hash}'
