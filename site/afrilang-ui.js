/**
 * AFRILANG Canvas UI runtime for the web playground (std/ui subset).
 * Implements open window / draw text / buttons / show frame via HTMLCanvasElement.
 */
(function (global) {
  'use strict';

  var canvas = null;
  var ctx = null;
  var open = false;
  var width = 640;
  var height = 480;
  var title = '';
  var mouseX = 0;
  var mouseY = 0;
  var mouseDown = false;
  var mousePressed = false;
  var mouseClicked = false;
  var keysDown = Object.create(null);
  var keysPressed = Object.create(null);
  var lastFrameTs = 0;
  var delta = 16;
  var host = null;

  function ensureCanvas() {
    if (canvas && ctx) return canvas;
    canvas = document.getElementById('wasm-canvas') || document.getElementById('afr-ui-canvas');
    if (!canvas) {
      canvas = document.createElement('canvas');
      canvas.id = 'afr-ui-canvas';
      canvas.style.cssText = 'display:block;width:100%;max-width:100%;background:#0b1020;height:420px;outline:none;border-radius:8px;';
      canvas.tabIndex = 0;
      var out = document.getElementById('output');
      if (out && out.parentNode) out.parentNode.insertBefore(canvas, out);
      else document.body.appendChild(canvas);
    }
    ctx = canvas.getContext('2d');
    bindInput(canvas);
    return canvas;
  }

  function bindInput(el) {
    if (el._afrUiBound) return;
    el._afrUiBound = true;
    el.addEventListener('mousemove', function (e) {
      var rect = el.getBoundingClientRect();
      var sx = el.width / Math.max(1, rect.width);
      var sy = el.height / Math.max(1, rect.height);
      mouseX = (e.clientX - rect.left) * sx;
      mouseY = (e.clientY - rect.top) * sy;
    });
    el.addEventListener('mousedown', function () {
      mouseDown = true;
      mousePressed = true;
    });
    el.addEventListener('mouseup', function () {
      if (mouseDown) mouseClicked = true;
      mouseDown = false;
    });
    el.addEventListener('mouseleave', function () {
      mouseDown = false;
    });
    el.addEventListener('keydown', function (e) {
      var k = e.key.length === 1 ? e.key.toLowerCase() : e.key;
      if (!keysDown[k]) keysPressed[k] = true;
      keysDown[k] = true;
      e.preventDefault();
    });
    el.addEventListener('keyup', function (e) {
      var k = e.key.length === 1 ? e.key.toLowerCase() : e.key;
      keysDown[k] = false;
    });
  }

  function showHost(show) {
    ensureCanvas();
    canvas.style.display = show ? 'block' : 'none';
    if (show) {
      canvas.width = width;
      canvas.height = height;
      canvas.focus();
    }
    host = document.getElementById('afr-ui-host');
    if (host) host.style.display = show ? 'block' : 'none';
    var titleEl = document.getElementById('afr-ui-title');
    if (titleEl) titleEl.textContent = title || 'AFRILANG GUI';
  }

  var AfrilangUI = {
    openWindow: function (t, w, h) {
      title = String(t == null ? 'AFRILANG' : t);
      width = Math.max(64, Number(w) || 640);
      height = Math.max(64, Number(h) || 480);
      open = true;
      lastFrameTs = 0;
      showHost(true);
      ensureCanvas();
      ctx.fillStyle = '#0b1020';
      ctx.fillRect(0, 0, width, height);
    },

    closeWindow: function () {
      open = false;
      showHost(false);
    },

    isOpen: function () {
      return open;
    },

    beginFrame: function () {
      mousePressed = false;
      mouseClicked = false;
      keysPressed = Object.create(null);
    },

    clearBackground: function (r, g, b) {
      ensureCanvas();
      ctx.fillStyle = 'rgb(' + (r | 0) + ',' + (g | 0) + ',' + (b | 0) + ')';
      ctx.fillRect(0, 0, width, height);
    },

    fillRect: function (x, y, w, h, r, g, b) {
      ensureCanvas();
      ctx.fillStyle = 'rgb(' + (r | 0) + ',' + (g | 0) + ',' + (b | 0) + ')';
      ctx.fillRect(x, y, w, h);
    },

    drawRect: function (x, y, w, h, r, g, b) {
      ensureCanvas();
      ctx.strokeStyle = 'rgb(' + (r | 0) + ',' + (g | 0) + ',' + (b | 0) + ')';
      ctx.strokeRect(x, y, w, h);
    },

    drawText: function (text, x, y, size) {
      AfrilangUI.drawTextColor(text, x, y, size, 240, 240, 245);
    },

    drawTextColor: function (text, x, y, size, r, g, b) {
      ensureCanvas();
      var s = Math.max(8, Number(size) || 16);
      ctx.fillStyle = 'rgb(' + (r | 0) + ',' + (g | 0) + ',' + (b | 0) + ')';
      ctx.font = 'bold ' + s + 'px system-ui,Segoe UI,sans-serif';
      ctx.textBaseline = 'top';
      ctx.fillText(String(text), x, y);
    },

    drawButton: function (label, x, y, w, h) {
      ensureCanvas();
      var hovered =
        mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h;
      var pressed = hovered && mouseDown;
      ctx.fillStyle = pressed ? '#1d4ed8' : hovered ? '#2563eb' : '#334155';
      ctx.fillRect(x, y, w, h);
      ctx.strokeStyle = '#93c5fd';
      ctx.strokeRect(x, y, w, h);
      ctx.fillStyle = '#f8fafc';
      var fontSize = Math.max(12, Math.min(22, h * 0.4));
      ctx.font = 'bold ' + fontSize + 'px system-ui,Segoe UI,sans-serif';
      ctx.textAlign = 'center';
      ctx.textBaseline = 'middle';
      ctx.fillText(String(label), x + w / 2, y + h / 2);
      ctx.textAlign = 'start';
      ctx.textBaseline = 'alphabetic';
      return hovered && mouseClicked;
    },

    isKeyDown: function (key) {
      return !!keysDown[String(key).toLowerCase()];
    },

    wasKeyPressed: function (key) {
      return !!keysPressed[String(key).toLowerCase()];
    },

    deltaMs: function () {
      return delta;
    },

    windowWidth: function () {
      return width;
    },

    windowHeight: function () {
      return height;
    },

    mouseX: function () {
      return mouseX;
    },

    mouseY: function () {
      return mouseY;
    },

    isMouseDown: function () {
      return mouseDown;
    },

    wasMousePressed: function () {
      return mousePressed;
    },

    wasMouseClicked: function () {
      return mouseClicked;
    },

    fps: function () {
      return delta > 0 ? 1000 / delta : 60;
    },

    showFrame: function () {
      ensureCanvas();
      var now = performance.now();
      if (lastFrameTs) delta = Math.min(100, now - lastFrameTs);
      lastFrameTs = now;
      return new Promise(function (resolve) {
        requestAnimationFrame(function () {
          resolve();
        });
      });
    },
  };

  global.AfrilangUI = AfrilangUI;
})(window);
