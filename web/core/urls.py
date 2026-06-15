from django.urls import path

from . import views

urlpatterns = [
    path('', views.home, name='home'),
    path('language/', views.language, name='language'),
    path('explore/', views.explore, name='explore'),
    path('docs/', views.docs_overview, name='docs'),
    path('docs/overview/', views.docs_overview, name='docs_overview'),
    path('docs/getting-started/', views.docs_getting_started, name='docs_getting_started'),
    path('docs/syntax/', views.docs_syntax, name='docs_syntax'),
    path('docs/types/', views.docs_types, name='docs_types'),
    path('docs/oop/', views.docs_oop, name='docs_oop'),
    path('docs/advanced/', views.docs_advanced, name='docs_advanced'),
    path('docs/stdlib/', views.docs_stdlib, name='docs_stdlib'),
    path('docs/tooling/', views.docs_tooling, name='docs_tooling'),
    path('packages/', views.packages_list, name='packages'),
    path('playground/', views.playground, name='playground'),
    path('api/packages/', views.api_packages, name='api_packages'),
    path('api/run/', views.api_run, name='api_run'),
    path('api/run/wasm/', views.api_run, {'target_override': 'wasm32'}, name='api_run_wasm'),
    path('api/fmt/', views.api_fmt, name='api_fmt'),
    path('api/examples/<slug:slug>/', views.api_example, name='api_example'),
]
