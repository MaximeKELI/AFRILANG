from django.contrib.sitemaps import Sitemap
from django.urls import reverse

from core.content.docs_nav import NAV_META


class StaticViewSitemap(Sitemap):
    changefreq = 'weekly'
    priority = 0.8
    i18n = True

    def items(self):
        views = [
            'home', 'language', 'explore', 'packages', 'playground', 'tutorial',
            'download', 'community', 'api_reference', 'examples',
            'stdlib', 'releases', 'docs_search',
        ]
        docs = [url_name for _, url_name in NAV_META]
        return views + docs

    def location(self, item):
        return reverse(item)
