(function () {
  'use strict';

  var KEY = 'afr_cookie_consent';
  var THEME_KEY = 'afr_theme';

  function initCookies() {
    var banner = document.getElementById('cookie-banner');
    if (!banner) return;
    if (localStorage.getItem(KEY)) return;
    banner.classList.remove('d-none');
    document.getElementById('cookie-accept')?.addEventListener('click', function () {
      localStorage.setItem(KEY, 'accepted');
      banner.classList.add('d-none');
    });
    document.getElementById('cookie-decline')?.addEventListener('click', function () {
      localStorage.setItem(KEY, 'declined');
      banner.classList.add('d-none');
    });
  }

  function initLangForms() {
    document.querySelectorAll('[data-lang-switch]').forEach(function (btn) {
      btn.addEventListener('click', function (e) {
        e.preventDefault();
        var form = document.getElementById('lang-form-' + btn.dataset.langSwitch);
        if (form) form.submit();
      });
    });
  }

  function isDark() {
    return document.documentElement.getAttribute('data-afr-theme') === 'dark';
  }

  function applyTheme(dark) {
    var root = document.documentElement;
    root.setAttribute('data-afr-theme', dark ? 'dark' : 'light');
    root.setAttribute('data-bs-theme', dark ? 'dark' : 'light');
    localStorage.setItem(THEME_KEY, dark ? 'dark' : 'light');
    var meta = document.getElementById('meta-theme-color');
    if (meta) meta.setAttribute('content', dark ? '#0f172a' : '#1d4ed8');
    var btn = document.getElementById('theme-toggle');
    if (btn) {
      btn.querySelector('.theme-icon-light')?.classList.toggle('d-none', dark);
      btn.querySelector('.theme-icon-dark')?.classList.toggle('d-none', !dark);
      btn.setAttribute('aria-label', dark ? 'Light mode' : 'Dark mode');
    }
    if (window.AFR_CM && window.AFR_CM.setTheme) {
      window.AFR_CM.setTheme(dark ? 'dracula' : 'default');
    }
  }

  function initTheme() {
    var btn = document.getElementById('theme-toggle');
    if (!btn) return;
    applyTheme(isDark());
    btn.addEventListener('click', function () {
      applyTheme(!isDark());
    });
  }

  function boot() {
    initCookies();
    initLangForms();
    initTheme();
  }

  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', boot);
  } else {
    boot();
  }
})();
