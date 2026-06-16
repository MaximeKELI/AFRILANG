"""Security headers (OWASP recommendations)."""


def _is_embed_path(path: str) -> bool:
    return '/playground/embed' in path


class SecurityHeadersMiddleware:
    def __init__(self, get_response):
        self.get_response = get_response

    def __call__(self, request):
        response = self.get_response(request)
        response.headers.setdefault('X-Content-Type-Options', 'nosniff')
        if _is_embed_path(request.path):
            response.headers.pop('X-Frame-Options', None)
            response.headers['Content-Security-Policy'] = 'frame-ancestors *'
        else:
            response.headers.setdefault('X-Frame-Options', 'DENY')
        response.headers.setdefault('Referrer-Policy', 'strict-origin-when-cross-origin')
        response.headers.setdefault(
            'Permissions-Policy',
            'geolocation=(), microphone=(), camera=()',
        )
        if request.is_secure():
            response.headers.setdefault(
                'Strict-Transport-Security',
                'max-age=31536000; includeSubDomains',
            )
        return response
