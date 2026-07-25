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

  function looksLikeGui(source) {
    return /open\s+window|while\s+window\s+is\s+open|show\s+frame|clear\s+background|draw\s+text|openWindow\s*\(|showFrame\s*\(|import\s+"std\/(ui|game2d|game3d)"/i.test(
      source || ''
    );
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

  async function compileSource(source, payload) {
    // Prefer server compile-js (full imports / stdlib). WASM client is a fallback.
    var url = cfg().urls?.compileJs || '/api/compile/js/';
    var body = payload && typeof payload === 'object' ? payload : { source: source };
    if (!body.source && source) body.source = source;
    try {
      var res = await fetch(url, {
        method: 'POST',
        headers: {
          'Content-Type': 'application/json',
          'X-CSRFToken': csrfToken(),
        },
        body: JSON.stringify(body),
      });
      var data = await res.json();
      if (res.status === 429) {
        throw new Error(data.output || 'Rate limit exceeded');
      }
      if (data.ok && data.js) {
        return data.js;
      }
      if (!data.ok && data.output) {
        // Fall through to WASM only if server has no binary / compile error that WASM might not fix
        var serverErr = data.output;
        var mod = await loadWasmCompiler();
        if (mod && typeof mod._afrilang_compile_js === 'function' && !/import\s+"/i.test(source || '')) {
          var ptr = mod._afrilang_compile_js(mod.allocateUTF8(source));
          var raw = mod.UTF8ToString(ptr);
          mod._afrilang_free(ptr);
          if (raw.startsWith('ERROR:')) {
            throw new Error(raw.slice(6) || serverErr);
          }
          return raw;
        }
        throw new Error(serverErr);
      }
    } catch (e) {
      if (e && e.message && !/Failed to fetch|NetworkError/i.test(e.message)) throw e;
    }

    var mod2 = await loadWasmCompiler();
    if (mod2 && typeof mod2._afrilang_compile_js === 'function') {
      var ptr2 = mod2._afrilang_compile_js(mod2.allocateUTF8(source));
      var raw2 = mod2.UTF8ToString(ptr2);
      mod2._afrilang_free(ptr2);
      if (raw2.startsWith('ERROR:')) {
        throw new Error(raw2.slice(6));
      }
      return raw2;
    }
    throw new Error('Compilation failed');
  }

  function runJavaScript(js) {
    var lines = [];
    var fakeConsole = {
      log: function () {
        lines.push(Array.prototype.slice.call(arguments).map(String).join(' '));
      },
    };
    var runner = new Function(
      'console',
      'AfrilangPlayground',
      'AfrilangUI',
      '"use strict";\n' + js
    );
    var result = runner(
      fakeConsole,
      global.AfrilangPlayground || null,
      global.AfrilangUI || null
    );
    if (result && typeof result.then === 'function') {
      return result.then(function () {
        return lines.join('\n');
      });
    }
    return Promise.resolve(lines.join('\n'));
  }

  async function runInstant(source, payload) {
    var js = await compileSource(source, payload);
    var output = await runJavaScript(js);
    var gui =
      looksLikeGui(source) ||
      /AfrilangPlayground|__rt\.openWindow|__ui\.openWindow/.test(js);
    return {
      ok: true,
      output: output || (gui ? '(GUI — canvas à droite ; Escape / Quitter pour fermer)' : ''),
      clientSide: wasmReady,
      gui: gui,
    };
  }

  global.AfrilangCompilerClient = {
    compileSource: compileSource,
    runInstant: runInstant,
    loadWasmCompiler: loadWasmCompiler,
    looksLikeGui: looksLikeGui,
  };
})(window);
