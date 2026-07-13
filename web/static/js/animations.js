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
      '.afr-section .stat-item',
      '.afr-section .code-panel',
      '.afr-section .section-label',
      '.afr-section h2',
      '.afr-section .afr-pkg-row',
      '.afr-section .btn',
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
      if (!el.classList.contains('afr-reveal') && !el.classList.contains('afr-reveal-scale')) {
        el.classList.add(
          el.matches('.afr-feature-card, .code-panel, .afr-card, .compare-card')
            ? 'afr-reveal-scale'
            : 'afr-reveal'
        );
      }
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
    }, { rootMargin: '0px 0px -48px 0px', threshold: 0.1 });

    var groupIndex = new WeakMap();
    nodes.forEach(function (el) {
      var parent = el.closest('.row, .afr-stat-row, .afr-section .container, .docs-content') || document.body;
      var idx = groupIndex.get(parent) || 0;
      groupIndex.set(parent, idx + 1);
      el.style.setProperty('--afr-delay', Math.min(idx, 8) * 55 + 'ms');
      io.observe(el);
    });
  }

  function initStatCounters() {
    if (reduced) return;
    document.querySelectorAll('.afr-stat-card .stat-value[data-count], .afr-stat-row .stat-value[data-count]').forEach(function (el) {
      var target = parseInt(el.getAttribute('data-count'), 10);
      if (isNaN(target)) return;
      var suffix = el.getAttribute('data-suffix') || '';
      var prefix = el.getAttribute('data-prefix') || '';
      var start = 0;
      var duration = 1100;
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
      }, { threshold: 0.45 });
      io.observe(el);
    });
  }

  function initNavbarScroll() {
    var nav = document.querySelector('.afr-navbar');
    if (!nav) return;
    var ticking = false;
    function onScroll() {
      if (ticking) return;
      ticking = true;
      requestAnimationFrame(function () {
        nav.classList.toggle('afr-navbar-scrolled', window.scrollY > 10);
        ticking = false;
      });
    }
    onScroll();
    window.addEventListener('scroll', onScroll, { passive: true });
  }

  function initScrollProgress() {
    if (reduced) return;
    var bar = document.createElement('div');
    bar.className = 'afr-scroll-progress';
    bar.setAttribute('aria-hidden', 'true');
    document.body.appendChild(bar);
    var ticking = false;
    function update() {
      var doc = document.documentElement;
      var max = doc.scrollHeight - doc.clientHeight;
      var p = max > 0 ? window.scrollY / max : 0;
      bar.style.transform = 'scaleX(' + Math.min(Math.max(p, 0), 1) + ')';
      ticking = false;
    }
    window.addEventListener('scroll', function () {
      if (ticking) return;
      ticking = true;
      requestAnimationFrame(update);
    }, { passive: true });
    update();
  }

  function initHeroCodeGlow() {
    if (reduced) return;
    document.querySelectorAll('.afr-hero .code-panel').forEach(function (panel) {
      panel.classList.add('afr-code-float');

      var rect = null;
      panel.addEventListener('mousemove', function (e) {
        rect = rect || panel.getBoundingClientRect();
        var x = (e.clientX - rect.left) / rect.width - 0.5;
        var y = (e.clientY - rect.top) / rect.height - 0.5;
        panel.classList.add('afr-code-tilt');
        panel.style.transform =
          'perspective(900px) rotateY(' + (x * 6) + 'deg) rotateX(' + (-y * 5) + 'deg) translateY(-2px)';
        panel.style.boxShadow =
          Math.round(-x * 18) + 'px ' + Math.round(12 + y * 10) + 'px 36px rgba(15, 23, 42, 0.18)';
      });
      panel.addEventListener('mouseleave', function () {
        rect = null;
        panel.classList.remove('afr-code-tilt');
        panel.style.transform = '';
        panel.style.boxShadow = '';
      });
      window.addEventListener('resize', function () { rect = null; }, { passive: true });
    });
  }

  function initButtonRipple() {
    if (reduced) return;
    document.querySelectorAll('.btn-afr-primary, .btn-afr-outline').forEach(function (btn) {
      btn.addEventListener('click', function (e) {
        var rect = btn.getBoundingClientRect();
        var ripple = document.createElement('span');
        ripple.className = 'afr-ripple';
        var size = Math.max(rect.width, rect.height) * 1.15;
        ripple.style.width = ripple.style.height = size + 'px';
        ripple.style.left = (e.clientX - rect.left - size / 2) + 'px';
        ripple.style.top = (e.clientY - rect.top - size / 2) + 'px';
        btn.appendChild(ripple);
        ripple.addEventListener('animationend', function () { ripple.remove(); });
      });
    });
  }

  function initMagneticButtons() {
    if (reduced || window.matchMedia('(pointer: coarse)').matches) return;
    document.querySelectorAll('.afr-hero .btn-afr-primary, .afr-hero .btn-afr-outline').forEach(function (btn) {
      btn.addEventListener('mousemove', function (e) {
        var rect = btn.getBoundingClientRect();
        var x = e.clientX - rect.left - rect.width / 2;
        var y = e.clientY - rect.top - rect.height / 2;
        btn.style.transform = 'translate(' + (x * 0.12) + 'px, ' + (y * 0.18 - 2) + 'px)';
      });
      btn.addEventListener('mouseleave', function () {
        btn.style.transform = '';
      });
    });
  }

  function boot() {
    document.body.classList.add('afr-loaded');
    initScrollReveal();
    initStatCounters();
    initNavbarScroll();
    initScrollProgress();
    initHeroCodeGlow();
    initButtonRipple();
    initMagneticButtons();
  }

  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', boot);
  } else {
    boot();
  }
})();
