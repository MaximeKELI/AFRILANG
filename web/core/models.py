from django.db import models


class Package(models.Model):
    name = models.SlugField(max_length=64, unique=True)
    version = models.CharField(max_length=32, default='0.1.0')
    description = models.TextField(blank=True)
    sha256 = models.CharField(max_length=64, blank=True)
    blessed = models.BooleanField(default=False, db_index=True)
    updated_at = models.DateTimeField(auto_now=True)

    class Meta:
        ordering = ['-blessed', 'name']

    def __str__(self):
        prefix = '★ ' if self.blessed else ''
        return f'{prefix}{self.name} v{self.version}'


class Capability(models.Model):
    CATEGORY_CHOICES = [
        ('lang', 'Langage'),
        ('compiler', 'Compilateur'),
        ('cli', 'CLI'),
        ('stdlib', 'Stdlib'),
        ('pkg', 'Paquets'),
        ('wasm', 'WASM & Web'),
        ('lsp', 'LSP & IDE'),
        ('debug', 'Debug'),
        ('async', 'Async & UI'),
        ('ci', 'Qualité & CI'),
    ]

    category = models.CharField(max_length=32, choices=CATEGORY_CHOICES, db_index=True)
    title = models.CharField(max_length=128)
    sort_order = models.PositiveSmallIntegerField(default=0)
    items = models.JSONField(default=list, help_text='Liste de points (strings)')

    class Meta:
        ordering = ['sort_order', 'title']
        verbose_name_plural = 'Capabilities'

    def __str__(self):
        return self.title


class CodeExample(models.Model):
    slug = models.SlugField(max_length=64, unique=True)
    title = models.CharField(max_length=128)
    description = models.TextField(blank=True)
    source = models.TextField()
    sort_order = models.PositiveSmallIntegerField(default=0)
    featured = models.BooleanField(default=False)

    class Meta:
        ordering = ['sort_order', 'title']

    def __str__(self):
        return self.title


class StdlibModule(models.Model):
    TIER_CHOICES = [
        ('simple', 'Simple'),
        ('medium', 'Medium'),
        ('complex', 'Complex'),
    ]

    name = models.CharField(max_length=256, unique=True)
    import_path = models.CharField(max_length=256)
    summary = models.CharField(max_length=512, blank=True)
    description_fr = models.TextField(blank=True)
    description_en = models.TextField(blank=True)
    category = models.CharField(max_length=32, default='utilities', db_index=True)
    tier = models.CharField(max_length=16, choices=TIER_CHOICES, default='simple', db_index=True)
    function_count = models.PositiveSmallIntegerField(default=0)
    has_pdf = models.BooleanField(default=False)
    updated_at = models.DateTimeField(auto_now=True)

    class Meta:
        ordering = ['category', 'name']
        verbose_name = 'Stdlib module'

    def __str__(self):
        return self.import_path

    def description(self, lang: str = 'fr') -> str:
        if (lang or 'fr')[:2] == 'en' and self.description_en:
            return self.description_en
        return self.description_fr or self.description_en or self.summary


class Release(models.Model):
    version = models.CharField(max_length=64, unique=True)
    title = models.CharField(max_length=256, blank=True)
    body = models.TextField()
    released_at = models.DateField(null=True, blank=True)
    sort_order = models.PositiveSmallIntegerField(default=0)

    class Meta:
        ordering = ['-sort_order', '-released_at']

    def __str__(self):
        return self.version


class SiteMetric(models.Model):
    key = models.CharField(max_length=64, unique=True)
    value = models.JSONField(default=dict)

    class Meta:
        verbose_name = 'Site metric'

    def __str__(self):
        return self.key


class PlaygroundRun(models.Model):
    """Historique des exécutions playground (PostgreSQL)."""
    source_hash = models.CharField(max_length=64, db_index=True)
    target = models.CharField(max_length=32, default='native')
    ok = models.BooleanField(default=False)
    exit_code = models.IntegerField(default=1)
    output_preview = models.TextField(blank=True)
    duration_ms = models.PositiveIntegerField(default=0)
    created_at = models.DateTimeField(auto_now_add=True, db_index=True)

    class Meta:
        ordering = ['-created_at']

    def __str__(self):
        return f'{self.target} @ {self.created_at:%Y-%m-%d %H:%M}'
