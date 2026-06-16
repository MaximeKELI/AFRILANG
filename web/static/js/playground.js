(function () {
  const cfg = window.AFR_PLAYGROUND || {};
  const EXAMPLES = cfg.examples || {};

  const textarea = document.getElementById('editor');
  const output = document.getElementById('output');
  const status = document.getElementById('status');
  const select = document.getElementById('examples');

  let cm = null;

  function isDark() {
    return document.documentElement.getAttribute('data-afr-theme') === 'dark';
  }

  function initCodeMirror() {
    if (!textarea || typeof CodeMirror === 'undefined') return null;
    cm = CodeMirror.fromTextArea(textarea, {
      mode: 'afrilang',
      theme: isDark() ? 'dracula' : 'default',
      lineNumbers: true,
      lineWrapping: true,
      indentUnit: 4,
      tabSize: 4,
      indentWithTabs: false,
      extraKeys: {
        'Ctrl-Enter': () => runCode(cfg.urls.run, '…'),
        'Cmd-Enter': () => runCode(cfg.urls.run, '…'),
        Tab: (cm) => {
          if (cm.somethingSelected()) cm.indentSelection('add');
          else cm.replaceSelection('    ', 'end');
        },
      },
    });
    cm.setSize('100%', '380px');
    window.AFR_CM = {
      setTheme: (theme) => cm.setOption('theme', theme),
    };
    return cm;
  }

  function getSource() {
    return cm ? cm.getValue() : (textarea?.value || '');
  }

  function setSource(code) {
    if (cm) cm.setValue(code);
    else if (textarea) textarea.value = code;
  }

  function csrfToken() {
    return document.cookie.match(/csrftoken=([^;]+)/)?.[1] || '';
  }

  function loadExample(slug) {
    const keys = Object.keys(EXAMPLES);
    setSource(EXAMPLES[slug] || EXAMPLES[keys[0]] || 'say "Hello"');
    if (select && slug && EXAMPLES[slug]) select.value = slug;
    updateShareUrl();
    cm?.focus();
  }

  function updateShareUrl() {
    const params = new URLSearchParams(window.location.search);
    if (select?.value) params.set('example', select.value);
    history.replaceState(null, '', `${window.location.pathname}?${params.toString()}`);
  }

  async function postJson(url, body) {
    const res = await fetch(url, {
      method: 'POST',
      headers: { 'Content-Type': 'application/json', 'X-CSRFToken': csrfToken() },
      body: JSON.stringify(body),
    });
    const data = await res.json();
    if (res.status === 429) {
      data.ok = false;
      data.output = data.output || 'Rate limit exceeded';
    }
    return data;
  }

  async function runCode(url, label) {
    if (!output || !status) return;
    status.textContent = label;
    status.classList.add('running');
    output.style.color = '';
    try {
      const data = await postJson(url, { source: getSource() });
      output.textContent = data.output || '(no output)';
      status.textContent = data.ok ? '✓ OK' : '✗ ' + (data.exitCode ?? '?');
      status.classList.remove('running');
      if (!data.ok) output.style.color = '#f87171';
    } catch (e) {
      output.textContent = String(e);
      status.textContent = 'Error';
      status.classList.remove('running');
      output.style.color = '#f87171';
    }
  }

  async function checkCode() {
    if (!output || !status) return;
    status.textContent = 'Check…';
    output.style.color = '';
    try {
      const data = await postJson(cfg.urls.check, { source: getSource() });
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
      const data = await postJson(cfg.urls.fmt, { source: getSource() });
      if (data.ok && data.source) setSource(data.source);
    } catch (_) { /* ignore */ }
  }

  function shareLink() {
    const params = new URLSearchParams();
    if (select?.value) params.set('example', select.value);
    const url = `${window.location.origin}${window.location.pathname}?${params.toString()}`;
    navigator.clipboard?.writeText(url).then(() => {
      if (status) status.textContent = 'Link copied';
    }).catch(() => prompt('Share URL:', url));
  }

  function copyOutput() {
    navigator.clipboard?.writeText(output?.textContent || '').then(() => {
      if (status) status.textContent = 'Copied';
    });
  }

  async function runBrowser() {
    if (!output || !status || !window.AfrilangCompilerClient) return;
    status.textContent = 'Browser…';
    status.classList.add('running');
    output.style.color = '';
    try {
      const result = await window.AfrilangCompilerClient.runInstant(getSource());
      output.textContent = result.output || '(no output)';
      status.textContent = result.clientSide ? '✓ Browser (WASM)' : '✓ Browser (JS)';
      status.classList.remove('running');
    } catch (e) {
      output.textContent = String(e.message || e);
      status.textContent = 'Error';
      status.classList.remove('running');
      output.style.color = '#f87171';
    }
  }

  async function runWasmBrowser() {
    if (!output || !status || !window.runWasmInBrowser) return;
    status.textContent = 'WASM build…';
    status.classList.add('running');
    output.style.color = '';
    output.textContent = '';
    try {
      const data = await postJson(cfg.urls.buildWasm, { source: getSource() });
      if (!data.ok || !data.id) {
        output.textContent = data.output || 'WASM build failed';
        status.textContent = '✗ WASM';
        status.classList.remove('running');
        output.style.color = '#f87171';
        return;
      }
      status.textContent = 'WASM run…';
      await window.runWasmInBrowser(data.id, output, status, cfg);
      status.classList.remove('running');
    } catch (e) {
      output.textContent = String(e);
      status.textContent = 'Error';
      status.classList.remove('running');
      output.style.color = '#f87171';
    }
  }

  initCodeMirror();

  select?.addEventListener('change', (e) => loadExample(e.target.value));
  document.getElementById('run')?.addEventListener('click', () => runCode(cfg.urls.run, '…'));
  document.getElementById('runBrowser')?.addEventListener('click', runBrowser);
  document.getElementById('runWasm')?.addEventListener('click', runWasmBrowser);
  document.getElementById('fmt')?.addEventListener('click', formatCode);
  document.getElementById('check')?.addEventListener('click', checkCode);
  document.getElementById('share')?.addEventListener('click', shareLink);
  document.getElementById('copyOutput')?.addEventListener('click', copyOutput);

  const tutorialCode = sessionStorage.getItem('afr_tutorial_code');
  if (tutorialCode) {
    sessionStorage.removeItem('afr_tutorial_code');
    setSource(tutorialCode);
    cm?.focus();
  } else {
    const initial = cfg.initialSlug || new URLSearchParams(window.location.search).get('example');
    if (initial && EXAMPLES[initial]) loadExample(initial);
    else if (select?.value) loadExample(select.value);
  }
})();
