"""CORS pour /api/mobile/ (clients Flutter web / desktop)."""
from __future__ import annotations


class MobileCorsMiddleware:
    """Répond aux preflight OPTIONS et ajoute les en-têtes CORS sur /api/."""

    def __init__(self, get_response):
        self.get_response = get_response

    def __call__(self, request):
        path = request.path or ''
        if not path.startswith('/api/'):
            return self.get_response(request)

        if request.method == 'OPTIONS':
            from django.http import HttpResponse
            response = HttpResponse(status=204)
            self._apply(response, request)
            return response

        response = self.get_response(request)
        self._apply(response, request)
        return response

    @staticmethod
    def _apply(response, request):
        origin = request.headers.get('Origin', '*') or '*'
        # En dev on accepte toute origine (Flutter web sur localhost:xxxxx)
        response['Access-Control-Allow-Origin'] = origin if origin != 'null' else '*'
        response['Access-Control-Allow-Methods'] = 'GET, POST, OPTIONS'
        response['Access-Control-Allow-Headers'] = (
            'Content-Type, Accept, X-Afrilang-Client, X-CSRFToken, Authorization'
        )
        response['Access-Control-Max-Age'] = '86400'
        # Varier sur Origin pour caches
        vary = response.get('Vary')
        if vary:
            if 'Origin' not in vary:
                response['Vary'] = f'{vary}, Origin'
        else:
            response['Vary'] = 'Origin'
        return response
