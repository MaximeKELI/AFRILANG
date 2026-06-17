(function (global) {
  'use strict';

  let wasmModule = null;
  let wasmReady = false;
  let wasmLoadAttempted = false;

  function loadWasmCompiler() {
    if (wasmReady) return Promise.resolve(wasmModule);
    if (wasmLoadAttempted) return Promise.resolve(null);
    wasmLoadAttempted = true;

    return new Promise((resolve) => {
      const script = document.createElement('script');
      script.src = '/compiler/afrilang-compiler.js';
      script.async = true;
      script.onload = async () => {
        try {
          const factory = global.createAfrilangCompiler;
          if (typeof factory !== 'function') {
            resolve(null);
            return;
          }
          wasmModule = await factory();
          wasmReady = true;
          resolve(wasmModule);
        } catch {
          resolve(null);
        }
      };
      script.onerror = () => resolve(null);
      document.head.appendChild(script);
    });
  }

  async function compileSource(source) {
    const mod = await loadWasmCompiler();
    if (mod && typeof mod._afrilang_compile_js === 'function') {
      const ptr = mod._afrilang_compile_js(mod.allocateUTF8(source));
      const raw = mod.UTF8ToString(ptr);
      mod._afrilang_free(ptr);
      if (raw.startsWith('ERROR:')) {
        throw new Error(raw.slice(6));
      }
      return raw;
    }

    const res = await fetch('/api/compile/js', {
      method: 'POST',
      headers: { 'Content-Type': 'application/json' },
      body: JSON.stringify({ source })
    });
    const data = await res.json();
    if (!data.ok) {
      throw new Error(data.output || 'Compilation failed');
    }
    return data.js;
  }

  function runJavaScript(js) {
    const lines = [];
    const fakeConsole = {
      log(...args) {
        lines.push(args.map((v) => String(v)).join(' '));
      }
    };
    const runner = new Function('console', '"use strict";\n' + js);
    runner(fakeConsole);
    return lines.join('\n');
  }

  async function runInstant(source) {
    const js = await compileSource(source);
    const output = runJavaScript(js);
    return { ok: true, output, clientSide: wasmReady };
  }

  global.AfrilangCompilerClient = { compileSource, runInstant, loadWasmCompiler };
})(window);
