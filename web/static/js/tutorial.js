(function () {
  'use strict';

  var KEY = 'afr_tutorial_done';
  var cfg = window.AFR_TUTORIAL || { totalSteps: 7, currentStep: 0 };

  function loadDone() {
    try {
      return JSON.parse(localStorage.getItem(KEY) || '[]');
    } catch (_) {
      return [];
    }
  }

  function saveDone(arr) {
    localStorage.setItem(KEY, JSON.stringify(arr));
  }

  function markStep(step) {
    var done = loadDone();
    if (!done.includes(step)) {
      done.push(step);
      done.sort(function (a, b) { return a - b; });
      saveDone(done);
    }
    updateUI();
  }

  function updateUI() {
    var done = loadDone();
    var total = cfg.totalSteps || 7;
    var pct = Math.round((done.length / total) * 100);

    document.querySelectorAll('[data-step-check]').forEach(function (el) {
      var step = parseInt(el.getAttribute('data-step-check'), 10);
      el.classList.toggle('visible', done.includes(step));
    });

    document.querySelectorAll('.tutorial-overview-card').forEach(function (card) {
      var step = parseInt(card.getAttribute('data-step'), 10);
      card.classList.toggle('done', done.includes(step));
    });

    var bar = document.getElementById('tutorial-progress-bar');
    if (bar) bar.style.width = pct + '%';

    var text = document.getElementById('tutorial-progress-text');
    if (text) {
      text.textContent = done.length + ' / ' + total +
        (document.documentElement.lang === 'en' ? ' completed' : ' terminées');
    }
  }

  function tryPlayground(code, slug) {
    if (code) sessionStorage.setItem('afr_tutorial_code', code);
    var url = '/playground/';
    if (slug) url += '?example=' + encodeURIComponent(slug);
    window.location.href = url;
  }

  document.getElementById('mark-complete')?.addEventListener('click', function () {
    markStep(parseInt(this.getAttribute('data-step'), 10));
    this.textContent = document.documentElement.lang === 'en' ? '✓ Done' : '✓ Terminé';
    this.disabled = true;
  });

  document.getElementById('try-playground')?.addEventListener('click', function () {
    tryPlayground(this.getAttribute('data-code'), this.getAttribute('data-slug'));
  });

  document.getElementById('copy-lesson-code')?.addEventListener('click', function () {
    var pre = document.getElementById('lesson-code');
    if (!pre) return;
    navigator.clipboard?.writeText(pre.textContent || '').then(function () {
      var btn = document.getElementById('copy-lesson-code');
      if (btn) btn.textContent = document.documentElement.lang === 'en' ? 'Copied!' : 'Copié !';
    });
  });

  if (cfg.currentStep) markStep(cfg.currentStep);

  updateUI();
})();
