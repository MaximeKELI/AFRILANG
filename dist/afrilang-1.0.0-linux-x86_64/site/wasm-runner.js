/**
 * Charge et exécute un module WASM Emscripten compilé par /api/build/wasm.
 */
async function runWasmInBrowser(sessionId, outputEl, statusEl) {
  const base = `/api/wasm/${sessionId}`;
  const wasmUrl = `${base}/module.wasm`;

  return new Promise((resolve, reject) => {
    const script = document.createElement('script');
    script.src = `${base}/module.js`;
    script.async = true;
    script.onerror = () => reject(new Error('Impossible de charger module.js'));

    script.onload = async () => {
      try {
        if (typeof createAfrilangModule !== 'function') {
          throw new Error('createAfrilangModule introuvable');
        }
        let text = '';
        const module = await createAfrilangModule({
          locateFile: (path) => (path.endsWith('.wasm') ? wasmUrl : path),
          print: (line) => { text += line + '\n'; outputEl.textContent = text; },
          printErr: (line) => { text += line + '\n'; outputEl.textContent = text; }
        });
        module._main();
        resolve(text);
      } catch (err) {
        reject(err);
      } finally {
        script.remove();
      }
    };

    document.head.appendChild(script);
  });
}

window.runWasmInBrowser = runWasmInBrowser;
