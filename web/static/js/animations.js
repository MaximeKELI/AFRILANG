(function () {
  'use strict';

  var reduced = window.matchMedia('(prefers-reduced-motion: reduce)').matches;

  function lerp(a, b, t) {
    return a + (b - a) * t;
  }

  function revealClassFor(el) {
    if (el.matches('.code-panel, .afr-card, .compare-card')) return 'afr-reveal-scale';
    if (el.matches('.afr-feature-card')) return 'afr-reveal-scale';
    if (el.matches('.afr-feature-plain, .afr-pkg-row')) return 'afr-reveal-slide';
    if (el.matches('.section-label, .docs-callout')) return 'afr-reveal-blur';
    if (el.matches('h2, h3, .afr-page-header')) return 'afr-reveal-clip';
    return 'afr-reveal';
  }

  function initScrollReveal() {
    if (reduced) return;
    var selectors = [
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

    var revealKinds = [
      'afr-reveal',
      'afr-reveal-scale',
      'afr-reveal-blur',
      'afr-reveal-slide',
      'afr-reveal-clip',
    ];
    var seen = new Set();
    var nodes = [];

    document.querySelectorAll(selectors).forEach(function (el) {
      if (seen.has(el)) return;
      seen.add(el);
      var hasKind = revealKinds.some(function (k) { return el.classList.contains(k); });
      if (!hasKind) el.classList.add(revealClassFor(el));
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
    }, { rootMargin: '0px 0px -56px 0px', threshold: 0.12 });

    var groupIndex = new WeakMap();
    nodes.forEach(function (el) {
      var parent = el.closest('.row, .afr-stat-row, .afr-section .container, .docs-content') || document.body;
      var idx = groupIndex.get(parent) || 0;
      groupIndex.set(parent, idx + 1);
      el.style.setProperty('--afr-delay', Math.min(idx, 9) * 70 + 'ms');
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
      var duration = 1400;
      var startTime = null;

      function tick(ts) {
        if (!startTime) startTime = ts;
        var p = Math.min((ts - startTime) / duration, 1);
        // smootherstep — plus fondant qu’un ease cubic simple
        var eased = p * p * p * (p * (p * 6 - 15) + 10);
        el.textContent = prefix + Math.round(target * eased) + suffix;
        if (p < 1) requestAnimationFrame(tick);
      }

      var io = new IntersectionObserver(function (entries) {
        if (!entries[0].isIntersecting) return;
        requestAnimationFrame(tick);
        io.disconnect();
      }, { threshold: 0.4 });
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
        nav.classList.toggle('afr-navbar-scrolled', window.scrollY > 8);
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
    var current = 0;
    var target = 0;
    var raf = 0;

    function loop() {
      current = lerp(current, target, 0.12);
      if (Math.abs(current - target) < 0.0005) current = target;
      bar.style.transform = 'scaleX(' + current + ')';
      if (current !== target) raf = requestAnimationFrame(loop);
      else raf = 0;
    }

    function update() {
      var doc = document.documentElement;
      var max = doc.scrollHeight - doc.clientHeight;
      target = max > 0 ? Math.min(Math.max(window.scrollY / max, 0), 1) : 0;
      if (!raf) raf = requestAnimationFrame(loop);
    }

    window.addEventListener('scroll', update, { passive: true });
    update();
  }

  function initHeroCodeGlow() {
    if (reduced) return;
    document.querySelectorAll('.afr-hero .code-panel').forEach(function (panel) {
      panel.classList.add('afr-code-float');

      var rect = null;
      var curX = 0;
      var curY = 0;
      var tgtX = 0;
      var tgtY = 0;
      var hovering = false;
      var raf = 0;

      function frame() {
        curX = lerp(curX, tgtX, 0.1);
        curY = lerp(curY, tgtY, 0.1);
        if (!hovering && Math.abs(curX) < 0.02 && Math.abs(curY) < 0.02) {
          curX = curY = 0;
          panel.classList.remove('afr-code-tilt');
          panel.style.transform = '';
          panel.style.boxShadow = '';
          raf = 0;
          return;
        }
        panel.classList.add('afr-code-tilt');
        panel.style.transform =
          'perspective(1100px) rotateY(' + (curX * 7) + 'deg) rotateX(' + (-curY * 5.5) +
          'deg) translate3d(0, -3px, 0)';
        panel.style.boxShadow =
          Math.round(-curX * 22) + 'px ' + Math.round(14 + curY * 12) +
          'px 42px rgba(15, 23, 42, 0.2)';
        raf = requestAnimationFrame(frame);
      }

      panel.addEventListener('mousemove', function (e) {
        rect = rect || panel.getBoundingClientRect();
        tgtX = (e.clientX - rect.left) / rect.width - 0.5;
        tgtY = (e.clientY - rect.top) / rect.height - 0.5;
        hovering = true;
        if (!raf) raf = requestAnimationFrame(frame);
      });
      panel.addEventListener('mouseleave', function () {
        rect = null;
        hovering = false;
        tgtX = 0;
        tgtY = 0;
        if (!raf) raf = requestAnimationFrame(frame);
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
        var size = Math.max(rect.width, rect.height) * 1.25;
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
      var curX = 0;
      var curY = 0;
      var tgtX = 0;
      var tgtY = 0;
      var hovering = false;
      var raf = 0;

      function frame() {
        curX = lerp(curX, tgtX, 0.14);
        curY = lerp(curY, tgtY, 0.14);
        if (!hovering && Math.abs(curX) < 0.15 && Math.abs(curY) < 0.15) {
          curX = curY = 0;
          btn.style.transform = '';
          raf = 0;
          return;
        }
        btn.style.transform = 'translate3d(' + curX + 'px, ' + (curY - 2) + 'px, 0)';
        raf = requestAnimationFrame(frame);
      }

      btn.addEventListener('mousemove', function (e) {
        var rect = btn.getBoundingClientRect();
        tgtX = (e.clientX - rect.left - rect.width / 2) * 0.22;
        tgtY = (e.clientY - rect.top - rect.height / 2) * 0.28;
        hovering = true;
        if (!raf) raf = requestAnimationFrame(frame);
      });
      btn.addEventListener('mouseleave', function () {
        hovering = false;
        tgtX = 0;
        tgtY = 0;
        if (!raf) raf = requestAnimationFrame(frame);
      });
    });
  }

  function initHeroParallax() {
    if (reduced || window.matchMedia('(pointer: coarse)').matches) return;
    var hero = document.querySelector('.afr-hero');
    if (!hero) return;
    var curX = 0;
    var curY = 0;
    var tgtX = 0;
    var tgtY = 0;
    var raf = 0;

    function frame() {
      curX = lerp(curX, tgtX, 0.06);
      curY = lerp(curY, tgtY, 0.06);
      hero.style.setProperty('--afr-parx', curX.toFixed(3));
      hero.style.setProperty('--afr-pary', curY.toFixed(3));
      if (Math.abs(curX - tgtX) > 0.001 || Math.abs(curY - tgtY) > 0.001) {
        raf = requestAnimationFrame(frame);
      } else {
        raf = 0;
      }
    }

    hero.addEventListener('mousemove', function (e) {
      var rect = hero.getBoundingClientRect();
      tgtX = ((e.clientX - rect.left) / rect.width - 0.5) * 12;
      tgtY = ((e.clientY - rect.top) / rect.height - 0.5) * 8;
      if (!raf) raf = requestAnimationFrame(frame);
    });
    hero.addEventListener('mouseleave', function () {
      tgtX = 0;
      tgtY = 0;
      if (!raf) raf = requestAnimationFrame(frame);
    });
  }

  function boot() {
    // laisse un frame pour appliquer le fondu d’entrée
    requestAnimationFrame(function () {
      document.body.classList.add('afr-loaded');
    });
    initScrollReveal();
    initStatCounters();
    initNavbarScroll();
    initScrollProgress();
    initHeroCodeGlow();
    initButtonRipple();
    initMagneticButtons();
    initHeroParallax();
  }

  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', boot);
  } else {
    boot();
  }
})();
