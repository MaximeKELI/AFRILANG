(function () {
  const cfg = window.AFR_PLAYGROUND || {};
  const EXAMPLES = cfg.examples || {};
  const ws = window.AfrWorkspace;
  const isEn = (cfg.lang || 'fr') === 'en';

  const textarea = document.getElementById('editor');
  const output = document.getElementById('output');
  const status = document.getElementById('status');
  const select = document.getElementById('examples');
  const treeEl = document.getElementById('workspaceTree');
  const fileBadge = document.getElementById('wsFileBadge');
  const activeHint = document.getElementById('workspaceActiveHint');

  let cm = null;
  let suppressSave = false;
  let bootstrapped = false;

  function isDark() {
    return document.documentElement.getAttribute('data-afr-theme') === 'dark';
  }

  function initCodeMirror() {
    if (!textarea || typeof CodeMirror === 'undefined') return null;
    const embed = cfg.embedMode;
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
        Tab: (editor) => {
          if (editor.somethingSelected()) editor.indentSelection('add');
          else editor.replaceSelection('    ', 'end');
        },
      },
    });
    cm.setSize('100%', embed ? '220px' : '380px');
    cm.on('change', () => {
      if (suppressSave || !bootstrapped || !ws) return;
      ws.setActiveSource(getSource());
    });
    window.AFR_CM = {
      setTheme: (theme) => cm.setOption('theme', theme),
    };
    return cm;
  }

  function getSource() {
    return cm ? cm.getValue() : (textarea?.value || '');
  }

  function setSource(code, { persist = true } = {}) {
    suppressSave = true;
    if (cm) cm.setValue(code);
    else if (textarea) textarea.value = code;
    suppressSave = false;
    if (persist && bootstrapped && ws) ws.setActiveSource(code);
  }

  function csrfToken() {
    return document.cookie.match(/csrftoken=([^;]+)/)?.[1] || '';
  }

  function syncEditorToWorkspace() {
    if (!ws || !bootstrapped) return;
    ws.setActiveSource(getSource());
  }

  function projectPayload() {
    syncEditorToWorkspace();
    if (ws && !cfg.embedMode) {
      return ws.buildRunPayload();
    }
    return { source: getSource() };
  }

  function loadExample(slug, { intoEditorOnly = false } = {}) {
    const keys = Object.keys(EXAMPLES);
    const code = EXAMPLES[slug] || EXAMPLES[keys[0]] || 'say "Hello"';
    if (select && slug && EXAMPLES[slug]) select.value = slug;
    if (intoEditorOnly || cfg.embedMode || !ws) {
      setSource(code, { persist: !cfg.embedMode });
    } else {
      setSource(code, { persist: true });
    }
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
      const data = await postJson(url, projectPayload());
      output.textContent = data.output || '(no output)';
      status.textContent = data.ok ? '✓ OK' : '✗ ' + (data.exitCode ?? '?');
      status.classList.remove('running');
      if (!data.ok) output.style.color = '#f87171';
    } catch (e) {
      output.textContent = String(e.message || e);
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
      const data = await postJson(cfg.urls.check, projectPayload());
      output.textContent = data.output || '(no output)';
      status.textContent = data.ok ? '✓ Check OK' : '✗ Errors';
      if (!data.ok) output.style.color = '#f87171';
    } catch (e) {
      output.textContent = String(e.message || e);
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
      const data = await postJson(cfg.urls.buildWasm, projectPayload());
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
      output.textContent = String(e.message || e);
      status.textContent = 'Error';
      status.classList.remove('running');
      output.style.color = '#f87171';
    }
  }

  function renderTree() {
    if (!treeEl || !ws) return;
    const root = ws.treeNodes();
    treeEl.innerHTML = '';

    function renderNode(node, pathPrefix, depth) {
      const folderNames = Object.keys(node.children).sort();
      folderNames.forEach((name) => {
        const child = node.children[name];
        const full = pathPrefix ? `${pathPrefix}/${name}` : name;
        const row = document.createElement('div');
        row.className = 'ws-row ws-folder';
        row.style.paddingLeft = `${8 + depth * 12}px`;
        row.innerHTML = `<span class="ws-ico"></span><span class="ws-label">${escapeHtml(name)}</span>`;
        row.title = full;
        const actions = document.createElement('span');
        actions.className = 'ws-actions';
        actions.appendChild(actionBtn(isEn ? 'Del' : 'Suppr', () => {
          if (confirm(isEn ? `Delete folder ${full}?` : `Supprimer le dossier ${full} ?`)) {
            ws.deletePath(full);
          }
        }));
        row.appendChild(actions);
        treeEl.appendChild(row);
        renderNode(child, full, depth + 1);
      });

      (node.files || []).forEach((f) => {
        const row = document.createElement('button');
        row.type = 'button';
        row.className = 'ws-row ws-file' + (f.path === ws.activePath ? ' active' : '');
        row.style.paddingLeft = `${8 + depth * 12}px`;
        row.innerHTML = `<span class="ws-ico"></span><span class="ws-label">${escapeHtml(f.name)}</span>`;
        row.title = f.path;
        row.addEventListener('click', (e) => {
          if (e.target.closest('.ws-actions')) return;
          syncEditorToWorkspace();
          const code = ws.openFile(f.path);
          setSource(code, { persist: false });
          updateChrome();
          cm?.focus();
        });
        const actions = document.createElement('span');
        actions.className = 'ws-actions';
        actions.appendChild(actionBtn(isEn ? 'Del' : 'Suppr', (ev) => {
          ev.stopPropagation();
          if (confirm(isEn ? `Delete ${f.path}?` : `Supprimer ${f.path} ?`)) {
            syncEditorToWorkspace();
            ws.deletePath(f.path);
            setSource(ws.getActiveSource(), { persist: false });
            updateChrome();
          }
        }));
        row.appendChild(actions);
        treeEl.appendChild(row);
      });
    }

    renderNode(root, '', 0);
    updateChrome();
  }

  function actionBtn(label, onClick) {
    const b = document.createElement('button');
    b.type = 'button';
    b.className = 'btn btn-link btn-sm ws-action-btn';
    b.textContent = label;
    b.addEventListener('click', onClick);
    return b;
  }

  function escapeHtml(s) {
    return String(s)
      .replace(/&/g, '&amp;')
      .replace(/</g, '&lt;')
      .replace(/>/g, '&gt;')
      .replace(/"/g, '&quot;');
  }

  function updateChrome() {
    if (fileBadge) fileBadge.textContent = ws?.activePath || '';
    if (activeHint) {
      activeHint.textContent = ws?.activePath
        ? (isEn
          ? `Active entry: ${ws.activePath} (Run uses the whole project)`
          : `Fichier d’entrée : ${ws.activePath} (Run envoie tout le projet)`)
        : '';
    }
  }

  function promptPath(message, fallback) {
    const v = prompt(message, fallback || '');
    return v && v.trim() ? v.trim() : null;
  }

  initCodeMirror();

  async function bootWorkspace() {
    if (cfg.embedMode || !ws) {
      bootstrapped = true;
      return;
    }
    await ws.load();
    ws.onChange(() => renderTree());
    renderTree();
    setSource(ws.getActiveSource(), { persist: false });
    bootstrapped = true;
    updateChrome();
  }

  document.getElementById('wsNewFile')?.addEventListener('click', () => {
    const base = ws?.activePath ? ws.activePath.replace(/[^/]+$/, '') : 'Mes projets/';
    const path = promptPath(
      isEn ? 'New file path (.afr)' : 'Chemin du nouveau fichier (.afr)',
      `${base}main.afr`,
    );
    if (!path) return;
    try {
      syncEditorToWorkspace();
      ws.createFile(path);
      setSource(ws.getActiveSource(), { persist: false });
      updateChrome();
      cm?.focus();
    } catch (e) {
      alert(e.message || e);
    }
  });

  document.getElementById('wsNewFolder')?.addEventListener('click', () => {
    const path = promptPath(
      isEn ? 'New folder path' : 'Chemin du nouveau dossier',
      'Mes projets/mon_jeu',
    );
    if (!path) return;
    try {
      ws.createFolder(path);
    } catch (e) {
      alert(e.message || e);
    }
  });

  document.getElementById('wsCopyExample')?.addEventListener('click', () => {
    const slug = select?.value || 'example';
    const code = EXAMPLES[slug] || getSource();
    try {
      syncEditorToWorkspace();
      const path = ws.copyExampleIntoProject(slug, code, `${slug}.afr`);
      setSource(ws.getActiveSource(), { persist: false });
      updateChrome();
      if (status) status.textContent = isEn ? `Copied → ${path}` : `Copié → ${path}`;
      cm?.focus();
    } catch (e) {
      alert(e.message || e);
    }
  });

  select?.addEventListener('change', (e) => loadExample(e.target.value));
  document.getElementById('run')?.addEventListener('click', () => runCode(cfg.urls.run, '…'));
  document.getElementById('runBrowser')?.addEventListener('click', runBrowser);
  document.getElementById('runWasm')?.addEventListener('click', runWasmBrowser);
  document.getElementById('fmt')?.addEventListener('click', formatCode);
  document.getElementById('check')?.addEventListener('click', checkCode);
  document.getElementById('share')?.addEventListener('click', shareLink);
  document.getElementById('copyOutput')?.addEventListener('click', copyOutput);

  bootWorkspace().then(() => {
    const tutorialCode = sessionStorage.getItem('afr_tutorial_code');
    if (tutorialCode) {
      sessionStorage.removeItem('afr_tutorial_code');
      if (ws && !cfg.embedMode) {
        try {
          ws.copyExampleIntoProject('tutorial', tutorialCode, 'tutorial.afr');
          setSource(ws.getActiveSource(), { persist: false });
        } catch (_) {
          setSource(tutorialCode);
        }
      } else {
        setSource(tutorialCode);
      }
      cm?.focus();
      return;
    }
    if (cfg.initialCode) {
      setSource(cfg.initialCode);
      cm?.focus();
      return;
    }
    const params = new URLSearchParams(window.location.search);
    const codeParam = params.get('code');
    if (codeParam) {
      try {
        setSource(decodeURIComponent(codeParam));
      } catch (_) {
        setSource(codeParam);
      }
      cm?.focus();
      return;
    }
    const initial = cfg.initialSlug || params.get('example');
    if (initial && EXAMPLES[initial] && select) {
      select.value = initial;
      // Keep workspace file; only switch example select for share URL.
      updateShareUrl();
    }
  });
})();
