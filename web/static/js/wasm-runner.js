/**
 * Charge et exécute un module WASM Emscripten compilé par /api/build/wasm/.
 */
async function runWasmInBrowser(sessionId, outputEl, statusEl, cfg) {
  var canvasEl = document.getElementById('wasm-canvas');
  if (canvasEl) {
    canvasEl.style.display = 'block';
    // ensure focus for keyboard events
    setTimeout(() => canvasEl.focus(), 50);
  }
  var base = (cfg?.urls?.wasmBase || '/api/wasm/') + encodeURIComponent(sessionId) + '/';
  var wasmUrl = base + 'module.wasm';

  return new Promise(function (resolve, reject) {
    var script = document.createElement('script');
    script.src = base + 'module.js';
    script.async = true;
    script.onerror = function () {
      reject(new Error('Cannot load module.js'));
    };

    script.onload = async function () {
      try {
        if (typeof createAfrilangModule !== 'function') {
          throw new Error('createAfrilangModule not found');
        }
        var text = '';
        var module = await createAfrilangModule({
          canvas: canvasEl || undefined,
          locateFile: function (path) {
            return path.endsWith('.wasm') ? wasmUrl : path;
          },
          print: function (line) {
            text += line + '\n';
            if (outputEl) outputEl.textContent = text;
          },
          printErr: function (line) {
            text += line + '\n';
            if (outputEl) outputEl.textContent = text;
          },
        });
        module._main();
        if (statusEl) statusEl.textContent = '✓ WASM browser';
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
