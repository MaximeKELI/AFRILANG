/**
 * Compatibility shim — AfrilangUI is provided by afrilang-rt.js.
 * Keep this file so existing templates that only load afrilang-ui.js still work
 * if afrilang-rt.js was loaded first; otherwise load rt when possible.
 */
(function (g) {
  'use strict';
  if (g.AfrilangPlayground && typeof g.AfrilangPlayground.createRuntime === 'function') {
    g.AfrilangUI = g.AfrilangPlayground.createRuntime({ game3d: false });
  }
  /* Prefer loading afrilang-rt.js before this file. */
})(window);
