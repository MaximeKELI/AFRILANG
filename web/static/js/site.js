(function () {
  'use strict';

  var COOKIE_KEY = 'afr_cookie_consent';
  var PRIVACY_KEY = 'afr_privacy_consent';
  var THEME_KEY = 'afr_theme';

  function privacyVersion() {
    var gate = document.getElementById('privacy-gate');
    return (gate && gate.getAttribute('data-privacy-version')) || '1';
  }

  function hasValidPrivacyConsent() {
    var raw = localStorage.getItem(PRIVACY_KEY);
    if (!raw) return false;
    try {
      var data = JSON.parse(raw);
      return data && data.accepted === true && String(data.version) === String(privacyVersion());
    } catch (e) {
      return raw === 'accepted:' + privacyVersion() || raw === 'accepted';
    }
  }

  function savePrivacyConsent() {
    var payload = {
      accepted: true,
      version: privacyVersion(),
      at: new Date().toISOString(),
    };
    localStorage.setItem(PRIVACY_KEY, JSON.stringify(payload));
    // Keep cookie banner preference aligned after privacy accept
    if (!localStorage.getItem(COOKIE_KEY)) {
      localStorage.setItem(COOKIE_KEY, 'accepted');
    }
  }

  function unlockSite() {
    document.documentElement.classList.remove('privacy-pending');
    document.body.classList.remove('privacy-locked');
    var gate = document.getElementById('privacy-gate');
    if (gate) gate.classList.add('d-none');
    var pageBar = document.getElementById('privacy-page-accept');
    if (pageBar) pageBar.classList.add('d-none');
  }

  function lockSite() {
    var allow = document.body.getAttribute('data-privacy-allow') === '1';
    document.body.classList.add('privacy-locked');
    var gate = document.getElementById('privacy-gate');
    if (!gate) return;
    if (allow) {
      // On the privacy page itself: keep content readable, hide blocking panel
      gate.classList.add('d-none');
      document.body.classList.add('privacy-page-mode');
      document.body.classList.remove('privacy-locked');
    } else {
      gate.classList.remove('d-none');
      // Focus checkbox for a11y
      setTimeout(function () {
        document.getElementById('privacy-gate-check')?.focus();
      }, 50);
    }
  }

  function initPrivacyGate() {
    var gate = document.getElementById('privacy-gate');
    var check = document.getElementById('privacy-gate-check');
    var acceptBtn = document.getElementById('privacy-gate-accept');
    var err = document.getElementById('privacy-gate-error');
    var pageAccept = document.getElementById('privacy-page-accept-btn');

    if (hasValidPrivacyConsent()) {
      unlockSite();
      return;
    }

    lockSite();

    function tryAccept() {
      if (check && !check.checked && acceptBtn) {
        // From gate: require checkbox
        if (err) err.classList.remove('d-none');
        check.focus();
        return;
      }
      if (err) err.classList.add('d-none');
      savePrivacyConsent();
      unlockSite();
    }

    if (check && acceptBtn) {
      check.addEventListener('change', function () {
        acceptBtn.disabled = !check.checked;
        if (check.checked && err) err.classList.add('d-none');
      });
      acceptBtn.addEventListener('click', function () {
        if (!check.checked) {
          if (err) err.classList.remove('d-none');
          return;
        }
        tryAccept();
      });
    }

    if (pageAccept) {
      pageAccept.addEventListener('click', function () {
        // Accepting from full policy page implies having read it
        if (check) check.checked = true;
        savePrivacyConsent();
        unlockSite();
        // Optional: go home after accept from privacy page
        if (document.body.getAttribute('data-privacy-allow') === '1') {
          window.location.href = '/';
        }
      });
    }
  }

  function initCookies() {
    // Only show optional cookie banner AFTER privacy consent
    if (!hasValidPrivacyConsent()) return;
    var banner = document.getElementById('cookie-banner');
    if (!banner) return;
    if (localStorage.getItem(COOKIE_KEY)) return;
    banner.classList.remove('d-none');
    document.getElementById('cookie-accept')?.addEventListener('click', function () {
      localStorage.setItem(COOKIE_KEY, 'accepted');
      banner.classList.add('d-none');
    });
    document.getElementById('cookie-decline')?.addEventListener('click', function () {
      localStorage.setItem(COOKIE_KEY, 'declined');
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
    initPrivacyGate();
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
