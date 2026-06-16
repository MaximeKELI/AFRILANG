(function () {
  const cfg = window.AFR_PLAYGROUND || {};
  const EXAMPLES = cfg.examples || {};

  const editor = document.getElementById('editor');
  const output = document.getElementById('output');
  const status = document.getElementById('status');
  const select = document.getElementById('examples');

  function csrfToken() {
    return document.cookie.match(/csrftoken=([^;]+)/)?.[1] || '';
  }

  function loadExample(slug) {
    if (!editor) return;
    const keys = Object.keys(EXAMPLES);
    editor.value = EXAMPLES[slug] || EXAMPLES[keys[0]] || 'say "Hello"';
    if (select && slug && EXAMPLES[slug]) select.value = slug;
    updateShareUrl();
  }

  function updateShareUrl() {
    const params = new URLSearchParams(window.location.search);
    if (select?.value) params.set('example', select.value);
    const url = `${window.location.pathname}?${params.toString()}`;
    history.replaceState(null, '', url);
  }

  async function postJson(url, body) {
    const res = await fetch(url, {
      method: 'POST',
      headers: { 'Content-Type': 'application/json', 'X-CSRFToken': csrfToken() },
      body: JSON.stringify(body),
    });
    return res.json();
  }

  async function runCode(url, label) {
    if (!output || !status) return;
    status.textContent = label;
    output.style.color = '';
    try {
      const data = await postJson(url, { source: editor.value });
      output.textContent = data.output || '(no output)';
      status.textContent = data.ok ? '✓ OK' : '✗ ' + (data.exitCode ?? '?');
      if (!data.ok) output.style.color = '#f87171';
    } catch (e) {
      output.textContent = String(e);
      status.textContent = 'Error';
      output.style.color = '#f87171';
    }
  }

  async function checkCode() {
    if (!output || !status) return;
    status.textContent = 'Check…';
    output.style.color = '';
    try {
      const data = await postJson(cfg.urls.check, { source: editor.value });
      output.textContent = data.output || '(no output)';
      status.textContent = data.ok ? '✓ Check OK' : '✗ Errors';
      if (!data.ok) output.style.color = '#f87171';
    } catch (e) {
      output.textContent = String(e);
      status.textContent = 'Error';
    }
  }

  async function formatCode() {
    try {
      const data = await postJson(cfg.urls.fmt, { source: editor.value });
      if (data.ok && data.source) editor.value = data.source;
    } catch (_) { /* ignore */ }
  }

  function shareLink() {
    const params = new URLSearchParams();
    if (select?.value) params.set('example', select.value);
    const url = `${window.location.origin}${window.location.pathname}?${params.toString()}`;
    navigator.clipboard?.writeText(url).then(() => {
      if (status) status.textContent = 'Link copied';
    }).catch(() => {
      prompt('Share URL:', url);
    });
  }

  function copyOutput() {
    const text = output?.textContent || '';
    navigator.clipboard?.writeText(text).then(() => {
      if (status) status.textContent = 'Copied';
    });
  }

  select?.addEventListener('change', (e) => loadExample(e.target.value));

  document.getElementById('run')?.addEventListener('click', () => runCode(cfg.urls.run, '…'));
  document.getElementById('runWasm')?.addEventListener('click', () => runCode(cfg.urls.wasm, 'WASM…'));
  document.getElementById('fmt')?.addEventListener('click', formatCode);
  document.getElementById('check')?.addEventListener('click', checkCode);
  document.getElementById('share')?.addEventListener('click', shareLink);
  document.getElementById('copyOutput')?.addEventListener('click', copyOutput);

  editor?.addEventListener('keydown', (e) => {
    if ((e.ctrlKey || e.metaKey) && e.key === 'Enter') {
      e.preventDefault();
      runCode(cfg.urls.run, '…');
    }
  });

  const initial = cfg.initialSlug || new URLSearchParams(window.location.search).get('example');
  if (initial && EXAMPLES[initial]) {
    loadExample(initial);
  } else if (select?.value) {
    loadExample(select.value);
  }
})();
