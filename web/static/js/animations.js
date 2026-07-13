(function () {
  'use strict';

  var reduced = window.matchMedia('(prefers-reduced-motion: reduce)').matches;

  function initScrollReveal() {
    if (reduced) return;
    var selectors = [
      '.afr-hero .col-lg-6',
      '.afr-section .afr-feature-plain',
      '.afr-section .afr-feature-card',
      '.afr-section .afr-stat-row',
      '.afr-section .code-panel',
      '.afr-page-header',
      '.afr-card',
      '.compare-card',
      '.docs-content > h2',
      '.docs-content > h3',
      '.docs-content > .code-panel',
      '.docs-content > .docs-callout',
      '.docs-content > .docs-table',
      '.afr-reveal',
    ].join(', ');

    var seen = new Set();
    var nodes = [];
    document.querySelectorAll(selectors).forEach(function (el) {
      if (seen.has(el)) return;
      seen.add(el);
      el.classList.add('afr-reveal');
      nodes.push(el);
    });

    if (!nodes.length || !('IntersectionObserver' in window)) {
      nodes.forEach(function (el) { el.classList.add('afr-reveal-visible'); });
      return;
    }

    var io = new IntersectionObserver(function (entries) {
      entries.forEach(function (entry) {
        if (!entry.isIntersecting) return;
        entry.target.classList.add('afr-reveal-visible');
        io.unobserve(entry.target);
      });
    }, { rootMargin: '0px 0px -40px 0px', threshold: 0.08 });

    nodes.forEach(function (el, i) {
      el.style.setProperty('--afr-delay', Math.min(i % 8, 7) * 70 + 'ms');
      io.observe(el);
    });
  }

  function initStatCounters() {
    if (reduced) return;
    document.querySelectorAll('.afr-stat-card .stat-value[data-count]').forEach(function (el) {
      var target = parseInt(el.getAttribute('data-count'), 10);
      if (isNaN(target)) return;
      var suffix = el.getAttribute('data-suffix') || '';
      var prefix = el.getAttribute('data-prefix') || '';
      var start = 0;
      var duration = 1200;
      var startTime = null;

      function tick(ts) {
        if (!startTime) startTime = ts;
        var p = Math.min((ts - startTime) / duration, 1);
        var eased = 1 - Math.pow(1 - p, 3);
        el.textContent = prefix + Math.round(start + (target - start) * eased) + suffix;
        if (p < 1) requestAnimationFrame(tick);
      }

      var io = new IntersectionObserver(function (entries) {
        if (!entries[0].isIntersecting) return;
        requestAnimationFrame(tick);
        io.disconnect();
      }, { threshold: 0.5 });
      io.observe(el);
    });
  }

  function initNavbarScroll() {
    var nav = document.querySelector('.afr-navbar');
    if (!nav) return;
    function onScroll() {
      nav.classList.toggle('afr-navbar-scrolled', window.scrollY > 12);
    }
    onScroll();
    window.addEventListener('scroll', onScroll, { passive: true });
  }

  function initHeroCodeGlow() {
    if (reduced) return;
    document.querySelectorAll('.afr-hero .code-panel').forEach(function (panel) {
      panel.classList.add('afr-code-float');
    });
  }

  function initButtonRipple() {
    if (reduced) return;
    document.querySelectorAll('.btn-afr-primary, .btn-afr-outline').forEach(function (btn) {
      btn.addEventListener('click', function (e) {
        var rect = btn.getBoundingClientRect();
        var ripple = document.createElement('span');
        ripple.className = 'afr-ripple';
        var size = Math.max(rect.width, rect.height);
        ripple.style.width = ripple.style.height = size + 'px';
        ripple.style.left = (e.clientX - rect.left - size / 2) + 'px';
        ripple.style.top = (e.clientY - rect.top - size / 2) + 'px';
        btn.appendChild(ripple);
        ripple.addEventListener('animationend', function () { ripple.remove(); });
      });
    });
  }

  function boot() {
    document.body.classList.add('afr-loaded');
    initScrollReveal();
    initStatCounters();
    initNavbarScroll();
    initHeroCodeGlow();
    initButtonRipple();
  }

  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', boot);
  } else {
    boot();
  }
})();
