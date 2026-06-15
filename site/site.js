(function () {
  'use strict';

  const NAV = [
    { href: '/', label: 'Accueil', id: 'home' },
    { href: '/explore.html', label: 'Explorer', id: 'explore' },
    { href: '/docs.html', label: 'Docs', id: 'docs' },
    { href: '/packages.html', label: 'Paquets', id: 'packages' },
    { href: '/playground.html', label: 'Playground', id: 'playground' }
  ];

  function mountShell(activeId) {
    const shell = document.querySelector('[data-afr-shell]');
    if (!shell) return;

    const navLinks = NAV.map((item) => {
      const cls = item.id === activeId ? 'nav-link active' : 'nav-link';
      return `<a class="${cls}" href="${item.href}">${item.label}</a>`;
    }).join('');

    shell.innerHTML = `
      <div class="mesh" aria-hidden="true"></div>
      <header class="topbar">
        <a class="brand" href="/">
          <img src="/icon.png" alt="" width="40" height="40" class="brand-icon">
          <span class="brand-text">
            <strong>AFRILANG</strong>
            <small>Langage naturel → C++ natif</small>
          </span>
        </a>
        <button class="nav-toggle" type="button" aria-label="Menu" aria-expanded="false">
          <span></span><span></span><span></span>
        </button>
        <nav class="nav" aria-label="Principal">${navLinks}</nav>
        <div class="topbar-actions">
          <a class="btn btn-ghost" href="https://github.com/MaximeKELI/AFRILANG" target="_blank" rel="noopener">GitHub</a>
          <a class="btn btn-primary" href="/playground.html">Essayer</a>
        </div>
      </header>
    `;

    const toggle = shell.querySelector('.nav-toggle');
    const nav = shell.querySelector('.nav');
    toggle?.addEventListener('click', () => {
      const open = nav.classList.toggle('open');
      toggle.setAttribute('aria-expanded', open ? 'true' : 'false');
    });

    document.querySelectorAll('.nav-link').forEach((link) => {
      link.addEventListener('click', () => nav.classList.remove('open'));
    });

    const topbar = shell.querySelector('.topbar');
    window.addEventListener('scroll', () => {
      topbar?.classList.toggle('scrolled', window.scrollY > 24);
    }, { passive: true });
  }

  function animateCounters() {
    document.querySelectorAll('[data-count]').forEach((el) => {
      const target = parseInt(el.dataset.count, 10);
      if (Number.isNaN(target)) return;
      const obs = new IntersectionObserver((entries) => {
        if (!entries[0].isIntersecting) return;
        obs.disconnect();
        let n = 0;
        const step = Math.max(1, Math.floor(target / 40));
        const tick = () => {
          n = Math.min(target, n + step);
          el.textContent = String(n) + (el.dataset.suffix || '');
          if (n < target) requestAnimationFrame(tick);
        };
        tick();
      }, { threshold: 0.4 });
      obs.observe(el);
    });
  }

  function initCodeTabs() {
    const root = document.querySelector('[data-code-tabs]');
    if (!root) return;
    const tabs = root.querySelectorAll('[data-tab]');
    const panes = root.querySelectorAll('[data-pane]');
    tabs.forEach((tab) => {
      tab.addEventListener('click', () => {
        const id = tab.dataset.tab;
        tabs.forEach((t) => t.classList.toggle('active', t === tab));
        panes.forEach((p) => p.classList.toggle('active', p.dataset.pane === id));
      });
    });
  }

  async function loadPackagePreview() {
    const grid = document.getElementById('pkg-preview');
    if (!grid) return;
    try {
      const res = await fetch('/packages.json');
      const data = await res.json();
      const pkgs = (data.packages || []).filter((p) => p.blessed);
      grid.innerHTML = pkgs.map((p) => `
        <article class="pkg-card">
          <div class="pkg-card-head">
            <span class="pkg-star">★</span>
            <h3>${p.name}</h3>
            <span class="tag">v${p.version || '0.1.0'}</span>
          </div>
          <p>${p.description || ''}</p>
          <code class="pkg-cmd">afrilang pkg add ${p.name}</code>
        </article>
      `).join('');
    } catch {
      grid.innerHTML = '<p class="muted">Lancez <code>afrilang pkg reindex</code> pour générer le registre.</p>';
    }
  }

  function mountFooter() {
    const foot = document.querySelector('[data-afr-footer]');
    if (!foot) return;
    foot.innerHTML = `
      <div class="footer-grid">
        <div>
          <strong>AFRILANG</strong>
          <p class="muted">Compilateur open source · syntaxe naturelle FR/EN · C++17 · WASM · LSP</p>
        </div>
        <div>
          <strong>Ressources</strong>
          <a href="/docs.html">Documentation</a>
          <a href="/explore.html">Explorer</a>
          <a href="/packages.html">Paquets blessed</a>
          <a href="/playground.html">Playground</a>
        </div>
        <div>
          <strong>Outils</strong>
          <a href="https://github.com/MaximeKELI/AFRILANG" target="_blank" rel="noopener">GitHub</a>
          <a href="https://open-vsx.org/extension/afrilang/afrilang" target="_blank" rel="noopener">Extension VS Code</a>
        </div>
      </div>
      <p class="footer-copy">MIT · Fait pour l'Afrique et le monde</p>
    `;
  }

  document.addEventListener('DOMContentLoaded', () => {
    const page = document.body.dataset.page || '';
    mountShell(page);
    mountFooter();
    animateCounters();
    initCodeTabs();
    loadPackagePreview();
  });

  window.AfrilangSite = { mountShell, loadPackagePreview };
})();
