from django.urls import path

from . import views

urlpatterns = [
    path('', views.home, name='home'),
    path('explore/', views.explore, name='explore'),
    path('docs/', views.docs, name='docs'),
    path('packages/', views.packages_list, name='packages'),
    path('playground/', views.playground, name='playground'),
    path('api/packages/', views.api_packages, name='api_packages'),
    path('api/run/', views.api_run, name='api_run'),
    path('api/run/wasm/', views.api_run, {'target_override': 'wasm32'}, name='api_run_wasm'),
    path('api/fmt/', views.api_fmt, name='api_fmt'),
    path('api/examples/<slug:slug>/', views.api_example, name='api_example'),
]
