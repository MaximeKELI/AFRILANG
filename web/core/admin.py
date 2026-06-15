from django.contrib import admin

from .models import Capability, CodeExample, Package, PlaygroundRun


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
    prepopulated_fields = {'slug': ('title',)}


@admin.register(PlaygroundRun)
class PlaygroundRunAdmin(admin.ModelAdmin):
    list_display = ('created_at', 'target', 'ok', 'exit_code', 'duration_ms')
    list_filter = ('target', 'ok')
    readonly_fields = ('created_at',)
