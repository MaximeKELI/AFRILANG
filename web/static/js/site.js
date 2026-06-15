(function () {
  'use strict';

  var KEY = 'afr_cookie_consent';

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

  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', function () {
      initCookies();
      initLangForms();
    });
  } else {
    initCookies();
    initLangForms();
  }
})();
