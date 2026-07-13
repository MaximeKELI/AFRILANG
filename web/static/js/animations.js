(function () {
  'use strict';

  var reduced = window.matchMedia('(prefers-reduced-motion: reduce)').matches;

  function lerp(a, b, t) {
    return a + (b - a) * t;
  }

  function revealClassFor(el) {
    if (el.matches('.code-panel, .afr-card, .compare-card, .playground-card')) return 'afr-reveal-scale';
    if (el.matches('.afr-feature-card')) return 'afr-reveal-flip';
    if (el.matches('.afr-feature-plain, .afr-pkg-row')) return 'afr-reveal-slide';
    if (el.matches('.section-label, .docs-callout, .alert')) return 'afr-reveal-blur';
    if (el.matches('h2, h3, .afr-page-header')) return 'afr-reveal-clip';
    if (el.matches('.afr-stat-row, .stat-item')) return 'afr-reveal-zoom';
    if (el.matches('.docs-table, pre, .benchmark-bar-wrap')) return 'afr-reveal-scale';
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
      '.afr-section p.text-secondary-custom',
      '.afr-section .afr-pkg-row',
      '.afr-section .btn',
      '.afr-page-header',
      '.afr-card',
      '.compare-card',
      '.playground-card',
      '.playground-grid > *',
      '.docs-content > h2',
      '.docs-content > h3',
      '.docs-content > .code-panel',
      '.docs-content > .docs-callout',
      '.docs-content > .docs-table',
      '.docs-content > ul',
      '.docs-content > ol',
      '.docs-sidebar .nav-link',
      'article.afr-feature-card',
      '.showcase-card',
      '.tutorial-overview-card',
      '.afr-reveal',
    ].join(', ');

    var revealKinds = [
      'afr-reveal',
      'afr-reveal-scale',
      'afr-reveal-blur',
      'afr-reveal-slide',
      'afr-reveal-clip',
      'afr-reveal-flip',
      'afr-reveal-zoom',
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
    }, { rootMargin: '0px 0px -56px 0px', threshold: 0.1 });

    var groupIndex = new WeakMap();
    nodes.forEach(function (el) {
      var parent = el.closest('.row, .afr-stat-row, .afr-section .container, .docs-content, .playground-grid, .docs-sidebar') || document.body;
      var idx = groupIndex.get(parent) || 0;
      groupIndex.set(parent, idx + 1);
      el.style.setProperty('--afr-delay', Math.min(idx, 10) * 65 + 'ms');
      io.observe(el);
    });
  }

  function initInviewSections() {
    if (reduced || !('IntersectionObserver' in window)) {
      document.querySelectorAll('.afr-section, .afr-footer').forEach(function (el) {
        el.classList.add('is-inview');
      });
      return;
    }
    var io = new IntersectionObserver(function (entries) {
      entries.forEach(function (entry) {
        if (!entry.isIntersecting) return;
        entry.target.classList.add('is-inview');
        if (entry.target.classList.contains('afr-footer')) {
          entry.target.querySelectorAll('.col-lg-4, .col-6').forEach(function (col, i) {
            col.style.setProperty('--afr-delay', i * 90 + 'ms');
          });
        }
        io.unobserve(entry.target);
      });
    }, { threshold: 0.15 });
    document.querySelectorAll('.afr-section, .afr-footer').forEach(function (el) {
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

  function initBackToTop() {
    var btn = document.createElement('button');
    btn.type = 'button';
    btn.className = 'afr-back-top';
    btn.setAttribute('aria-label', 'Haut de page');
    btn.innerHTML = '↑';
    document.body.appendChild(btn);
    btn.addEventListener('click', function () {
      window.scrollTo({ top: 0, behavior: reduced ? 'auto' : 'smooth' });
    });
    var ticking = false;
    window.addEventListener('scroll', function () {
      if (ticking) return;
      ticking = true;
      requestAnimationFrame(function () {
        btn.classList.toggle('is-visible', window.scrollY > 480);
        ticking = false;
      });
    }, { passive: true });
  }

  function initHeroLetters() {
    if (reduced) return;
    var h1 = document.querySelector('.afr-hero h1');
    if (!h1 || h1.dataset.letters === '1') return;
    h1.dataset.letters = '1';
    var delay = 0;

    function wrapTextNode(node) {
      var text = node.textContent;
      if (!text || !text.trim()) return;
      var frag = document.createDocumentFragment();
      text.split(/(\s+)/).forEach(function (chunk) {
        if (!chunk) return;
        if (/^\s+$/.test(chunk)) {
          var sp = document.createElement('span');
          sp.className = 'afr-space';
          sp.innerHTML = '&nbsp;';
          frag.appendChild(sp);
          return;
        }
        var word = document.createElement('span');
        word.className = 'afr-word';
        chunk.split('').forEach(function (ch) {
          var letter = document.createElement('span');
          letter.className = 'afr-letter';
          letter.textContent = ch;
          letter.style.animationDelay = (0.38 + delay * 0.026) + 's';
          delay += 1;
          word.appendChild(letter);
        });
        frag.appendChild(word);
      });
      node.parentNode.replaceChild(frag, node);
    }

    function walk(el) {
      Array.prototype.slice.call(el.childNodes).forEach(function (child) {
        if (child.nodeType === 3) wrapTextNode(child);
        else if (child.nodeType === 1 && child.tagName !== 'BR') walk(child);
      });
    }

    walk(h1);
  }

  function initHeroParticles() {
    if (reduced) return;
    var hero = document.querySelector('.afr-hero');
    if (!hero || hero.querySelector('.afr-hero-particles')) return;
    var layer = document.createElement('div');
    layer.className = 'afr-hero-particles';
    layer.setAttribute('aria-hidden', 'true');
    for (var i = 0; i < 16; i++) {
      var p = document.createElement('span');
      p.className = 'afr-hero-particle';
      p.style.left = (8 + Math.random() * 84) + '%';
      p.style.top = (10 + Math.random() * 75) + '%';
      p.style.setProperty('--afr-orbit-dur', (10 + Math.random() * 16) + 's');
      p.style.setProperty('--afr-spark-dur', (2.4 + Math.random() * 3.2) + 's');
      p.style.animationDelay = (-Math.random() * 8) + 's';
      layer.appendChild(p);
    }
    hero.appendChild(layer);
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

  function initCardSpotlight() {
    if (reduced || window.matchMedia('(pointer: coarse)').matches) return;
    var cards = document.querySelectorAll(
      '.afr-feature-card, .afr-card, .compare-card, .showcase-card, .tutorial-overview-card'
    );
    cards.forEach(function (card) {
      card.classList.add('afr-spotlight');
      card.addEventListener('mousemove', function (e) {
        var rect = card.getBoundingClientRect();
        var x = ((e.clientX - rect.left) / rect.width) * 100;
        var y = ((e.clientY - rect.top) / rect.height) * 100;
        card.style.setProperty('--spot-x', x.toFixed(2) + '%');
        card.style.setProperty('--spot-y', y.toFixed(2) + '%');
      });
    });
  }

  function initMarquee() {
    if (reduced) return;
    var home = document.querySelector('.afr-hero');
    if (!home || document.querySelector('.afr-marquee')) return;
    var strip = document.createElement('div');
    strip.className = 'afr-marquee afr-section';
    strip.setAttribute('aria-hidden', 'true');
    strip.style.padding = '0.85rem 0';
    strip.style.borderBottom = '1px solid var(--afr-border)';
    var items = [
      'Syntaxe naturelle', 'C++17', 'WASM', 'LSP', 'REPL',
      'pkg', 'stdlib', 'FR / EN', 'Open Source', 'Native',
    ];
    var track = document.createElement('div');
    track.className = 'afr-marquee-track';
    var html = items.concat(items).map(function (t) {
      return '<span>' + t + ' ·</span>';
    }).join('');
    track.innerHTML = html;
    strip.appendChild(track);
    home.insertAdjacentElement('afterend', strip);
  }

  function boot() {
    requestAnimationFrame(function () {
      document.body.classList.add('afr-loaded');
    });
    initHeroLetters();
    initHeroParticles();
    initScrollReveal();
    initInviewSections();
    initStatCounters();
    initNavbarScroll();
    initScrollProgress();
    initBackToTop();
    initHeroCodeGlow();
    initButtonRipple();
    initMagneticButtons();
    initHeroParallax();
    initCardSpotlight();
    initMarquee();
  }

  if (document.readyState === 'loading') {
    document.addEventListener('DOMContentLoaded', boot);
  } else {
    boot();
  }
})();
