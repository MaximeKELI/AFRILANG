(function (global) {
  'use strict';

  var wasmModule = null;
  var wasmReady = false;
  var wasmLoadAttempted = false;

  function cfg() {
    return global.AFR_PLAYGROUND || {};
  }

  function csrfToken() {
    return document.cookie.match(/csrftoken=([^;]+)/)?.[1] || '';
  }

  function loadWasmCompiler() {
    if (wasmReady) return Promise.resolve(wasmModule);
    if (wasmLoadAttempted) return Promise.resolve(null);
    wasmLoadAttempted = true;

    var compilerUrl = cfg().urls?.compilerJs || '/static/compiler/afrilang-compiler.js';

    return new Promise(function (resolve) {
      fetch(compilerUrl, { method: 'HEAD' }).then(function (res) {
        if (!res.ok) {
          resolve(null);
          return;
        }
        var script = document.createElement('script');
        script.src = compilerUrl;
        script.async = true;
        script.onload = async function () {
          try {
            var factory = global.createAfrilangCompiler;
            if (typeof factory !== 'function') {
              resolve(null);
              return;
            }
            wasmModule = await factory();
            wasmReady = true;
            resolve(wasmModule);
          } catch (_) {
            resolve(null);
          }
        };
        script.onerror = function () { resolve(null); };
        document.head.appendChild(script);
      }).catch(function () { resolve(null); });
    });
  }

  async function compileSource(source) {
    var mod = await loadWasmCompiler();
    if (mod && typeof mod._afrilang_compile_js === 'function') {
      var ptr = mod._afrilang_compile_js(mod.allocateUTF8(source));
      var raw = mod.UTF8ToString(ptr);
      mod._afrilang_free(ptr);
      if (raw.startsWith('ERROR:')) {
        throw new Error(raw.slice(6));
      }
      return raw;
    }

    var url = cfg().urls?.compileJs || '/api/compile/js/';
    var res = await fetch(url, {
      method: 'POST',
      headers: {
        'Content-Type': 'application/json',
        'X-CSRFToken': csrfToken(),
      },
      body: JSON.stringify({ source: source }),
    });
    var data = await res.json();
    if (res.status === 429) {
      throw new Error(data.output || 'Rate limit exceeded');
    }
    if (!data.ok) {
      throw new Error(data.output || 'Compilation failed');
    }
    return data.js;
  }

  function runJavaScript(js) {
    var lines = [];
    var fakeConsole = {
      log: function () {
        lines.push(Array.prototype.slice.call(arguments).map(String).join(' '));
      },
    };
    var runner = new Function('console', '"use strict";\n' + js);
    runner(fakeConsole);
    return lines.join('\n');
  }

  async function runInstant(source) {
    var js = await compileSource(source);
    var output = runJavaScript(js);
    return { ok: true, output: output, clientSide: wasmReady };
  }

  global.AfrilangCompilerClient = {
    compileSource: compileSource,
    runInstant: runInstant,
    loadWasmCompiler: loadWasmCompiler,
  };
})(window);
