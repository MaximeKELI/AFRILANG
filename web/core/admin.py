from django.contrib import admin

from .models import Capability, CodeExample, Package, PlaygroundRun, Release, SiteMetric, StdlibModule


@admin.register(Package)
class PackageAdmin(admin.ModelAdmin):
    list_display = ('name', 'version', 'blessed', 'updated_at')
    list_filter = ('blessed',)
    search_fields = ('name', 'description')


@admin.register(Capability)
class CapabilityAdmin(admin.ModelAdmin):
    list_display = ('title', 'category', 'sort_order')
    list_filter = ('category',)


@admin.register(CodeExample)
class CodeExampleAdmin(admin.ModelAdmin):
    list_display = ('slug', 'title', 'featured', 'sort_order')
    search_fields = ('slug', 'title', 'description')
    prepopulated_fields = {'slug': ('title',)}


@admin.register(StdlibModule)
class StdlibModuleAdmin(admin.ModelAdmin):
    list_display = ('name', 'import_path', 'function_count', 'updated_at')
    search_fields = ('name', 'summary', 'import_path')


@admin.register(Release)
class ReleaseAdmin(admin.ModelAdmin):
    list_display = ('version', 'released_at', 'sort_order')
    search_fields = ('version', 'body')


@admin.register(SiteMetric)
class SiteMetricAdmin(admin.ModelAdmin):
    list_display = ('key',)


@admin.register(PlaygroundRun)
class PlaygroundRunAdmin(admin.ModelAdmin):
    list_display = ('created_at', 'target', 'ok', 'exit_code', 'duration_ms')
    list_filter = ('target', 'ok')
    readonly_fields = ('created_at',)
