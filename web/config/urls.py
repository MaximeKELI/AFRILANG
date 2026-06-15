from django.contrib import admin
from django.contrib.sitemaps.views import sitemap
from django.urls import include, path
from django.views.i18n import set_language

from core.sitemaps import StaticViewSitemap

sitemaps = {
    'static': StaticViewSitemap,
}

urlpatterns = [
    path('admin/', admin.site.urls),
    path('i18n/setlang/', set_language, name='set_language'),
    path('sitemap.xml', sitemap, {'sitemaps': sitemaps}, name='django.contrib.sitemaps.views.sitemap'),
]

urlpatterns += [
    path('', include('core.urls')),
]

# English prefix: /en/...
from django.conf.urls.i18n import i18n_patterns

urlpatterns += i18n_patterns(
    path('', include('core.urls')),
    prefix_default_language=False,
)
