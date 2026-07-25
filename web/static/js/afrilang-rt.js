/**
 * AFRILANG playground browser runtime (ui + game2d + game3d + helpers).
 * Exposes window.AfrilangPlayground.createRuntime({ game3d }) → flat __rt API.
 * Also sets window.AfrilangUI = createRuntime({ game3d: false }) for compat.
 */
(function (global) {
  'use strict';

  var DEG2RAD = Math.PI / 180;
  var TWO_PI = Math.PI * 2;

  /* ---------- key normalization (SDL-style ↔ browser) ---------- */
  var SDL_TO_BROWSER = {
    left: 'ArrowLeft',
    right: 'ArrowRight',
    up: 'ArrowUp',
    down: 'ArrowDown',
    escape: 'Escape',
    esc: 'Escape',
    enter: 'Enter',
    return: 'Enter',
    space: ' ',
    f1: 'F1',
    f2: 'F2',
    f3: 'F3',
    f4: 'F4',
    f5: 'F5',
    f6: 'F6',
    f7: 'F7',
    f8: 'F8',
    f9: 'F9',
    f10: 'F10',
    f11: 'F11',
    f12: 'F12',
  };

  var BROWSER_ALIASES = {
    arrowleft: ['left', 'arrowleft'],
    arrowright: ['right', 'arrowright'],
    arrowup: ['up', 'arrowup'],
    arrowdown: ['down', 'arrowdown'],
    escape: ['escape', 'esc'],
    enter: ['enter', 'return'],
    ' ': ['space', ' '],
    spacebar: ['space', ' '],
  };

  function canonicalKey(name) {
    var s = String(name == null ? '' : name);
    if (s.length === 1) return s.toLowerCase();
    var lower = s.toLowerCase();
    if (SDL_TO_BROWSER[lower]) {
      var b = SDL_TO_BROWSER[lower];
      return b.length === 1 ? b.toLowerCase() : b.toLowerCase();
    }
    return lower;
  }

  function keyAliases(browserKey) {
    var k = browserKey.length === 1 ? browserKey.toLowerCase() : browserKey;
    if (k.length === 1) return [k];
    var lower = k.toLowerCase();
    if (BROWSER_ALIASES[lower]) return BROWSER_ALIASES[lower];
    if (lower.length === 1) return [lower];
    return [lower];
  }

  function assetUrl(path) {
    var p = String(path == null ? '' : path);
    if (/^https?:\/\//i.test(p)) return p;
    if (p.indexOf('./') === 0) p = p.slice(2);
    while (p.charAt(0) === '/') p = p.slice(1);
    var base =
      (global.AFR_PLAYGROUND && global.AFR_PLAYGROUND.assetBase) || '/api/assets/';
    if (base.charAt(base.length - 1) !== '/') base += '/';
    return base + p;
  }

  /* ---------- mat4 helpers (column-major, WebGL) ---------- */
  function mat4Identity() {
    return new Float32Array([1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1]);
  }

  function mat4Multiply(a, b) {
    var o = new Float32Array(16);
    for (var c = 0; c < 4; c++) {
      for (var r = 0; r < 4; r++) {
        o[c * 4 + r] =
          a[0 * 4 + r] * b[c * 4 + 0] +
          a[1 * 4 + r] * b[c * 4 + 1] +
          a[2 * 4 + r] * b[c * 4 + 2] +
          a[3 * 4 + r] * b[c * 4 + 3];
      }
    }
    return o;
  }

  function mat4Translate(m, x, y, z) {
    var t = mat4Identity();
    t[12] = x;
    t[13] = y;
    t[14] = z;
    return mat4Multiply(m, t);
  }

  function mat4RotateY(m, deg) {
    var r = deg * DEG2RAD;
    var c = Math.cos(r);
    var s = Math.sin(r);
    var rot = new Float32Array([c, 0, s, 0, 0, 1, 0, 0, -s, 0, c, 0, 0, 0, 0, 1]);
    return mat4Multiply(m, rot);
  }

  function mat4Perspective(fovyDeg, aspect, near, far) {
    var f = 1 / Math.tan((fovyDeg * DEG2RAD) / 2);
    var nf = 1 / (near - far);
    var o = new Float32Array(16);
    o[0] = f / aspect;
    o[5] = f;
    o[10] = (far + near) * nf;
    o[11] = -1;
    o[14] = 2 * far * near * nf;
    return o;
  }

  function mat4LookAt(eyeX, eyeY, eyeZ, cx, cy, cz, ux, uy, uz) {
    var zx = eyeX - cx;
    var zy = eyeY - cy;
    var zz = eyeZ - cz;
    var zl = Math.sqrt(zx * zx + zy * zy + zz * zz) || 1;
    zx /= zl;
    zy /= zl;
    zz /= zl;
    var xx = uy * zz - uz * zy;
    var xy = uz * zx - ux * zz;
    var xz = ux * zy - uy * zx;
    var xl = Math.sqrt(xx * xx + xy * xy + xz * xz) || 1;
    xx /= xl;
    xy /= xl;
    xz /= xl;
    var yx = zy * xz - zz * xy;
    var yy = zz * xx - zx * xz;
    var yz = zx * xy - zy * xx;
    var o = new Float32Array(16);
    o[0] = xx;
    o[1] = yx;
    o[2] = zx;
    o[3] = 0;
    o[4] = xy;
    o[5] = yy;
    o[6] = zy;
    o[7] = 0;
    o[8] = xz;
    o[9] = yz;
    o[10] = zz;
    o[11] = 0;
    o[12] = -(xx * eyeX + xy * eyeY + xz * eyeZ);
    o[13] = -(yx * eyeX + yy * eyeY + yz * eyeZ);
    o[14] = -(zx * eyeX + zy * eyeY + zz * eyeZ);
    o[15] = 1;
    return o;
  }

  function createRuntime(opts) {
    opts = opts || {};
    var game3d = !!opts.game3d;

    var canvas = null;
    var ctx2d = null;
    var gl = null;
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
    var frameDeltaMs = 16;
    var fpsAccumMs = 0;
    var fpsFrameCount = 0;
    var fpsValue = 60;

    /* game2d state */
    var grid = {
      cols: 0,
      rows: 0,
      viewCols: 0,
      viewRows: 0,
      cellSize: 28,
      padX: 32,
      padY: 88,
    };
    var timers = Object.create(null);
    var sprites = Object.create(null);
    var sheets = Object.create(null);
    var sounds = Object.create(null);
    var musicTracks = Object.create(null);
    var musicEl = null;
    var triggers = Object.create(null);
    var highScoreVal = 0;
    var animTime = 0;
    var pendingDx = 1;
    var pendingDy = 0;
    var cam2dX = 0;
    var cam2dY = 0;

    /* gamestate */
    var stateCurrent = 'menu';
    var statePrevious = '';
    var stateTime = 0;
    var stateChanged = false;

    /* RNG */
    var randSeed = 1;

    /* game3d state */
    var cam3d = { x: 0, y: 0, z: 10, yaw: 0, pitch: 0 };
    var sceneRotY = 0;
    var projMat = mat4Identity();
    var viewMat = mat4Identity();
    var modelMat = mat4Identity();
    var glProg = null;
    var glLoc = null;
    var glBuf = null;
    var glCreatedCanvas = false;

    function rgbCss(r, g, b) {
      return 'rgb(' + (r | 0) + ',' + (g | 0) + ',' + (b | 0) + ')';
    }

    function ensureCanvasEl() {
      if (canvas && canvas.isConnected) return canvas;
      canvas =
        document.getElementById('wasm-canvas') ||
        document.getElementById('afr-ui-canvas');
      if (!canvas) {
        canvas = document.createElement('canvas');
        canvas.id = 'afr-ui-canvas';
        canvas.style.cssText =
          'display:block;width:100%;max-width:100%;background:#0b1020;height:420px;outline:none;border-radius:8px;';
        canvas.tabIndex = 0;
        var out = document.getElementById('output');
        if (out && out.parentNode) out.parentNode.insertBefore(canvas, out);
        else document.body.appendChild(canvas);
        glCreatedCanvas = true;
      }
      canvas.tabIndex = 0;
      bindInput(canvas);
      return canvas;
    }

    function replaceCanvasForGl() {
      var old = ensureCanvasEl();
      var neu = document.createElement('canvas');
      neu.id = old.id || 'wasm-canvas';
      neu.className = old.className;
      neu.style.cssText = old.style.cssText;
      neu.tabIndex = 0;
      if (old.parentNode) old.parentNode.replaceChild(neu, old);
      canvas = neu;
      ctx2d = null;
      gl = null;
      bindInput(canvas);
      return canvas;
    }

    function bindInput(el) {
      if (el._afrRtBound) return;
      el._afrRtBound = true;
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
        mouseClicked = true;
        try {
          el.focus();
        } catch (err) {}
      });
      el.addEventListener('mouseup', function () {
        mouseDown = false;
      });
      el.addEventListener('mouseleave', function () {
        mouseDown = false;
      });
      el.addEventListener('keydown', function (e) {
        var aliases = keyAliases(e.key);
        var first = false;
        for (var i = 0; i < aliases.length; i++) {
          if (!keysDown[aliases[i]]) first = true;
          keysDown[aliases[i]] = true;
          if (first) keysPressed[aliases[i]] = true;
        }
        e.preventDefault();
      });
      el.addEventListener('keyup', function (e) {
        var aliases = keyAliases(e.key);
        for (var i = 0; i < aliases.length; i++) keysDown[aliases[i]] = false;
      });
      window.addEventListener('blur', function () {
        keysDown = Object.create(null);
        mouseDown = false;
      });
    }

    function showHost(show) {
      ensureCanvasEl();
      canvas.style.display = show ? 'block' : 'none';
      if (show) {
        canvas.width = width;
        canvas.height = height;
        try {
          canvas.focus();
        } catch (err) {}
      }
      var host = document.getElementById('afr-ui-host');
      if (host) host.style.display = show ? 'block' : 'none';
      var titleEl = document.getElementById('afr-ui-title');
      if (titleEl) titleEl.textContent = title || 'AFRILANG GUI';
    }

    function updateTiming(now) {
      if (lastFrameTs) frameDeltaMs = Math.min(100, now - lastFrameTs);
      lastFrameTs = now;
      fpsAccumMs += frameDeltaMs;
      fpsFrameCount++;
      if (fpsAccumMs >= 500) {
        fpsValue = (fpsFrameCount * 1000) / fpsAccumMs;
        fpsAccumMs = 0;
        fpsFrameCount = 0;
      }
    }

    function clearEdgeInput() {
      mousePressed = false;
      mouseClicked = false;
      keysPressed = Object.create(null);
    }

    function isKeyDown(key) {
      return !!keysDown[canonicalKey(key)];
    }

    function wasKeyPressed(key) {
      return !!keysPressed[canonicalKey(key)];
    }

    /* ===== Canvas2D UI ===== */
    function ensure2d() {
      ensureCanvasEl();
      if (!ctx2d) ctx2d = canvas.getContext('2d');
      return ctx2d;
    }

    function ui_openWindow(t, w, h) {
      title = String(t == null ? 'AFRILANG' : t);
      width = Math.max(64, Number(w) || 640);
      height = Math.max(64, Number(h) || 480);
      open = true;
      lastFrameTs = 0;
      showHost(true);
      ensure2d();
      ctx2d.fillStyle = '#0b1020';
      ctx2d.fillRect(0, 0, width, height);
    }

    function ui_closeWindow() {
      open = false;
      showHost(false);
    }

    function ui_beginFrame() {
      updateTiming(performance.now());
    }

    function ui_showFrame() {
      ensure2d();
      return new Promise(function (resolve) {
        requestAnimationFrame(function () {
          clearEdgeInput();
          resolve();
        });
      });
    }

    function ui_clearBackground(r, g, b) {
      ensure2d();
      ctx2d.fillStyle = rgbCss(r, g, b);
      ctx2d.fillRect(0, 0, width, height);
    }

    function ui_fillRect(x, y, w, h, r, g, b) {
      ensure2d();
      ctx2d.fillStyle = rgbCss(r, g, b);
      ctx2d.fillRect(x, y, w, h);
    }

    function ui_drawRect(x, y, w, h, r, g, b) {
      ensure2d();
      ctx2d.strokeStyle = rgbCss(r, g, b);
      ctx2d.strokeRect(x, y, w, h);
    }

    function ui_drawTextColor(text, x, y, size, r, g, b) {
      ensure2d();
      var s = Math.max(8, Number(size) || 16);
      ctx2d.fillStyle = rgbCss(r, g, b);
      ctx2d.font = 'bold ' + s + 'px system-ui,Segoe UI,sans-serif';
      ctx2d.textBaseline = 'top';
      ctx2d.textAlign = 'start';
      var lines = String(text).split('\n');
      for (var i = 0; i < lines.length; i++) {
        ctx2d.fillText(lines[i], x, y + i * (s + 2));
      }
    }

    function ui_drawText(text, x, y, size) {
      ui_drawTextColor(text, x, y, size, 240, 240, 245);
    }

    function ui_drawButton(label, x, y, w, h) {
      ensure2d();
      var hovered =
        mouseX >= x && mouseX <= x + w && mouseY >= y && mouseY <= y + h;
      var pressed = hovered && mouseDown;
      ctx2d.fillStyle = pressed ? '#1d4ed8' : hovered ? '#2563eb' : '#334155';
      ctx2d.fillRect(x, y, w, h);
      ctx2d.strokeStyle = '#93c5fd';
      ctx2d.strokeRect(x, y, w, h);
      ctx2d.fillStyle = '#f8fafc';
      var fontSize = Math.max(12, Math.min(22, h * 0.4));
      ctx2d.font = 'bold ' + fontSize + 'px system-ui,Segoe UI,sans-serif';
      ctx2d.textAlign = 'center';
      ctx2d.textBaseline = 'middle';
      ctx2d.fillText(String(label), x + w / 2, y + h / 2);
      ctx2d.textAlign = 'start';
      ctx2d.textBaseline = 'alphabetic';
      return hovered && mouseClicked;
    }

    /* ===== game2d ===== */
    function visibleCols() {
      return grid.viewCols > 0 ? grid.viewCols : grid.cols;
    }
    function visibleRows() {
      return grid.viewRows > 0 ? grid.viewRows : grid.rows;
    }
    function cellInnerSize() {
      return grid.cellSize - 2;
    }

    function configureGrid(cols, rows, cellSize, padX, padY) {
      grid.cols = cols | 0;
      grid.rows = rows | 0;
      grid.cellSize = cellSize | 0;
      grid.padX = padX | 0;
      grid.padY = padY | 0;
    }

    function configureViewport(viewCols, viewRows) {
      grid.viewCols = viewCols | 0;
      grid.viewRows = viewRows | 0;
    }

    function gridWindowWidth() {
      return grid.padX * 2 + visibleCols() * grid.cellSize;
    }

    function gridWindowHeight() {
      return grid.padY + visibleRows() * grid.cellSize + 40;
    }

    function cellWorldX(col) {
      return grid.padX + (col | 0) * grid.cellSize;
    }

    function cellWorldY(row) {
      return grid.padY + (row | 0) * grid.cellSize;
    }

    function cellPx(col) {
      return cellWorldX(col) - cam2dX;
    }

    function cellPy(row) {
      return cellWorldY(row) - cam2dY;
    }

    function isBorderCell(col, row) {
      var c = col | 0;
      var r = row | 0;
      return c <= 0 || r <= 0 || c >= grid.cols - 1 || r >= grid.rows - 1;
    }

    function fillCell(col, row, r, g, b) {
      var inset = 1;
      var size = cellInnerSize();
      ui_fillRect(cellPx(col) + inset, cellPy(row) + inset, size, size, r, g, b);
    }

    function drawCell(col, row, r, g, b) {
      ui_drawRect(cellPx(col), cellPy(row), grid.cellSize, grid.cellSize, r, g, b);
    }

    function fillBoard(r, g, b) {
      ui_fillRect(
        cellPx(0),
        cellPy(0),
        grid.cols * grid.cellSize,
        grid.rows * grid.cellSize,
        r,
        g,
        b
      );
    }

    function drawWalls(r, g, b) {
      for (var y = 0; y < grid.rows; y++) {
        for (var x = 0; x < grid.cols; x++) {
          if (isBorderCell(x, y)) fillCell(x, y, r, g, b);
        }
      }
    }

    function drawGridLines(r, g, b) {
      var x0 = cellPx(0);
      var y0 = cellPy(0);
      var w = grid.cols * grid.cellSize;
      var h = grid.rows * grid.cellSize;
      for (var i = 0; i <= grid.cols; i++) {
        ui_drawRect(x0 + i * grid.cellSize, y0, 1, h, r, g, b);
      }
      for (var j = 0; j <= grid.rows; j++) {
        ui_drawRect(x0, y0 + j * grid.cellSize, w, 1, r, g, b);
      }
    }

    function fillCircleSolid(x, y, radius, r, g, b) {
      ensure2d();
      var sx = x - cam2dX;
      var sy = y - cam2dY;
      var rad = Math.max(1, radius | 0);
      ctx2d.beginPath();
      ctx2d.arc(sx, sy, rad, 0, TWO_PI);
      ctx2d.fillStyle = rgbCss(r, g, b);
      ctx2d.fill();
    }

    function everyMs(name, delta, interval) {
      if (interval <= 0) return true;
      animTime += delta;
      if (timers[name] == null) timers[name] = 0;
      timers[name] += delta;
      if (timers[name] >= interval) {
        timers[name] -= interval;
        return true;
      }
      return false;
    }

    function resetTimer(name) {
      timers[name] = 0;
    }

    function animTimeMs() {
      return animTime;
    }

    function pulse01(periodMs) {
      if (periodMs <= 0) return 1;
      var t = animTime / periodMs;
      return 0.5 + 0.5 * Math.sin(t * TWO_PI);
    }

    function updateDirection(curDx, curDy) {
      var ndx = curDx;
      var ndy = curDy;
      var left = isKeyDown('Left') || isKeyDown('A');
      var right = isKeyDown('Right') || isKeyDown('D');
      var up = isKeyDown('Up') || isKeyDown('W');
      var down = isKeyDown('Down') || isKeyDown('S');
      if (left && curDx !== 1) {
        ndx = -1;
        ndy = 0;
      } else if (right && curDx !== -1) {
        ndx = 1;
        ndy = 0;
      } else if (up && curDy !== 1) {
        ndx = 0;
        ndy = -1;
      } else if (down && curDy !== -1) {
        ndx = 0;
        ndy = 1;
      }
      pendingDx = ndx;
      pendingDy = ndy;
    }

    function inputDirX() {
      return pendingDx;
    }
    function inputDirY() {
      return pendingDy;
    }
    function syncDirection(dx, dy) {
      pendingDx = dx;
      pendingDy = dy;
    }

    function gridHas(xs, ys, count, gx, gy) {
      var n = count | 0;
      var ax = xs || [];
      var ay = ys || [];
      for (var i = 0; i < n && i < ax.length && i < ay.length; i++) {
        if (ax[i] === gx && ay[i] === gy) return true;
      }
      return false;
    }

    function clampByte(v) {
      return v < 0 ? 0 : v > 255 ? 255 : v | 0;
    }

    function rgb(r, g, b) {
      return clampByte(r) * 65536 + clampByte(g) * 256 + clampByte(b);
    }

    function redOf(packed) {
      return ((packed | 0) / 65536) % 256 | 0;
    }
    function greenOf(packed) {
      return ((packed | 0) / 256) % 256 | 0;
    }
    function blueOf(packed) {
      return (packed | 0) % 256;
    }

    function fillCellRgb(col, row, packed) {
      fillCell(col, row, redOf(packed), greenOf(packed), blueOf(packed));
    }

    function drawCenteredText(text, y, size, r, g, b) {
      var s = String(text);
      var approxW = s.length * size * 0.55;
      var x = (width - approxW) / 2;
      ui_drawTextColor(s, x, y, size, r, g, b);
    }

    function drawHud(text, x, y, size, r, g, b) {
      ui_drawTextColor(text, x, y, size, r, g, b);
    }

    function drawFps(x, y) {
      drawHud('FPS ' + Math.round(fpsValue), x, y, 16, 120, 255, 120);
    }

    function highScore() {
      return highScoreVal;
    }
    function updateHighScore(score) {
      if (score > highScoreVal) highScoreVal = score;
    }

    function moveIntervalForScore(score, baseMs, minMs) {
      var interval = baseMs - score * 3;
      return interval < minMs ? minMs : interval;
    }

    function setCamera2d(x, y) {
      cam2dX = x;
      cam2dY = y;
    }

    function cameraX() {
      return cam2dX;
    }
    function cameraY() {
      return cam2dY;
    }

    function followCamera(targetX, targetY, smooth) {
      var viewW = width;
      var viewH = height;
      var targetCamX = targetX - viewW / 2;
      var targetCamY = targetY - viewH / 2;
      var t = smooth <= 0 ? 1 : Math.min(1, smooth);
      cam2dX += (targetCamX - cam2dX) * t;
      cam2dY += (targetCamY - cam2dY) * t;
      var maxCamX = Math.max(0, grid.padX * 2 + grid.cols * grid.cellSize - viewW);
      var maxCamY = Math.max(0, grid.padY + grid.rows * grid.cellSize + 40 - viewH);
      if (cam2dX < 0) cam2dX = 0;
      if (cam2dY < 0) cam2dY = 0;
      if (cam2dX > maxCamX) cam2dX = maxCamX;
      if (cam2dY > maxCamY) cam2dY = maxCamY;
    }

    function loadSprite(name, path) {
      var img = new Image();
      img.crossOrigin = 'anonymous';
      var info = { img: img, ready: false, width: 0, height: 0 };
      sprites[name] = info;
      img.onload = function () {
        info.ready = true;
        info.width = img.naturalWidth || img.width;
        info.height = img.naturalHeight || img.height;
      };
      img.onerror = function () {
        info.ready = false;
      };
      img.src = assetUrl(path);
      return true;
    }

    function hasSprite(name) {
      var s = sprites[name];
      return !!(s && s.ready && s.img);
    }

    function spriteWidth(name) {
      var s = sprites[name];
      return s ? s.width : 0;
    }
    function spriteHeight(name) {
      var s = sprites[name];
      return s ? s.height : 0;
    }

    function drawSprite(name, worldX, worldY) {
      var s = sprites[name];
      if (!s || !s.ready) return;
      ensure2d();
      ctx2d.drawImage(s.img, worldX - cam2dX, worldY - cam2dY);
    }

    function drawSpriteScaled(name, worldX, worldY, w, h) {
      var s = sprites[name];
      if (!s || !s.ready) return;
      ensure2d();
      ctx2d.drawImage(s.img, worldX - cam2dX, worldY - cam2dY, w, h);
    }

    function drawSpriteCell(name, col, row) {
      var size = grid.cellSize;
      drawSpriteScaled(name, cellWorldX(col), cellWorldY(row), size, size);
    }

    function loadSpriteSheet(name, path, frameW, frameH) {
      var img = new Image();
      img.crossOrigin = 'anonymous';
      var fw = Math.max(1, frameW | 0);
      var fh = Math.max(1, frameH | 0);
      var sheet = {
        img: img,
        ready: false,
        width: 0,
        height: 0,
        frameW: fw,
        frameH: fh,
        cols: 1,
        rows: 1,
      };
      sheets[name] = sheet;
      img.onload = function () {
        sheet.ready = true;
        sheet.width = img.naturalWidth || img.width;
        sheet.height = img.naturalHeight || img.height;
        sheet.cols = Math.max(1, (sheet.width / fw) | 0);
        sheet.rows = Math.max(1, (sheet.height / fh) | 0);
      };
      img.src = assetUrl(path);
      return true;
    }

    function hasSpriteSheet(name) {
      var s = sheets[name];
      return !!(s && s.ready);
    }
    function sheetCols(name) {
      var s = sheets[name];
      return s ? s.cols : 0;
    }
    function sheetRows(name) {
      var s = sheets[name];
      return s ? s.rows : 0;
    }

    function drawSpriteFrame(name, frameIdx, worldX, worldY, w, h) {
      var sh = sheets[name];
      if (!sh || !sh.ready) return;
      var frames = Math.max(1, sh.cols * sh.rows);
      var idx = frameIdx | 0;
      if (idx < 0) idx = 0;
      idx = idx % frames;
      var col = sh.cols > 0 ? idx % sh.cols : 0;
      var row = sh.cols > 0 ? (idx / sh.cols) | 0 : 0;
      ensure2d();
      ctx2d.drawImage(
        sh.img,
        col * sh.frameW,
        row * sh.frameH,
        sh.frameW,
        sh.frameH,
        worldX - cam2dX,
        worldY - cam2dY,
        w,
        h
      );
    }

    function drawSpriteFrameCell(name, frameIdx, col, row) {
      var size = grid.cellSize;
      drawSpriteFrame(name, frameIdx, cellWorldX(col), cellWorldY(row), size, size);
    }

    function loadSound(name, path) {
      try {
        var a = new Audio(assetUrl(path));
        a.preload = 'auto';
        sounds[name] = a;
        return true;
      } catch (e) {
        return false;
      }
    }

    function playSound(name) {
      var a = sounds[name];
      if (!a) return false;
      try {
        var c = a.cloneNode();
        c.volume = a.volume;
        var p = c.play();
        if (p && p.catch) p.catch(function () {});
        return true;
      } catch (e) {
        return false;
      }
    }

    function playSoundVolume(name, volume) {
      var a = sounds[name];
      if (!a) return false;
      a.volume = Math.max(0, Math.min(1, Number(volume) / 128));
      return playSound(name);
    }

    function loadMusic(name, path) {
      try {
        var a = new Audio(assetUrl(path));
        a.preload = 'auto';
        a.loop = true;
        musicTracks[name] = a;
        return true;
      } catch (e) {
        return false;
      }
    }

    function playMusic(name, loops) {
      var a = musicTracks[name];
      if (!a) return false;
      if (musicEl && musicEl !== a) {
        try {
          musicEl.pause();
        } catch (e) {}
      }
      musicEl = a;
      a.loop = !(loops === 0 || loops === 1);
      try {
        a.currentTime = 0;
        var p = a.play();
        if (p && p.catch) p.catch(function () {});
        return true;
      } catch (e) {
        return false;
      }
    }

    function stopMusic() {
      if (!musicEl) return;
      try {
        musicEl.pause();
        musicEl.currentTime = 0;
      } catch (e) {}
    }

    function setMusicVolume(volume0to128) {
      var vol = Math.max(0, Math.min(128, Number(volume0to128))) / 128;
      if (musicEl) musicEl.volume = vol;
      for (var k in musicTracks) {
        if (musicTracks[k]) musicTracks[k].volume = vol;
      }
    }

    function defineTrigger(name, x, y, w, h) {
      triggers[name] = { x: x, y: y, w: w, h: h, active: true };
    }

    function setTriggerActive(name, active) {
      if (triggers[name]) triggers[name].active = !!active;
    }

    function pointInTrigger(name, wx, wy) {
      var t = triggers[name];
      if (!t || !t.active) return false;
      return wx >= t.x && wx <= t.x + t.w && wy >= t.y && wy <= t.y + t.h;
    }

    function mouseWorldX() {
      return mouseX + cam2dX;
    }
    function mouseWorldY() {
      return mouseY + cam2dY;
    }

    function mouseInTrigger(name) {
      return pointInTrigger(name, mouseWorldX(), mouseWorldY());
    }

    function storagePathKey(path) {
      return 'afrilang:save:' + String(path);
    }

    function saveValue(path, key, value) {
      try {
        var data = {};
        try {
          data = JSON.parse(localStorage.getItem(storagePathKey(path)) || '{}');
        } catch (e) {
          data = {};
        }
        data[String(key)] = Number(value);
        localStorage.setItem(storagePathKey(path), JSON.stringify(data));
        return true;
      } catch (e) {
        return false;
      }
    }

    function loadValue(path, key, defaultValue) {
      try {
        var data = JSON.parse(localStorage.getItem(storagePathKey(path)) || '{}');
        if (Object.prototype.hasOwnProperty.call(data, String(key))) {
          return Number(data[String(key)]);
        }
      } catch (e) {}
      return Number(defaultValue);
    }

    function loadHighScore(path) {
      highScoreVal = loadValue(path, 'highscore', highScoreVal);
    }

    function saveHighScore(path) {
      return saveValue(path, 'highscore', highScoreVal);
    }

    function game2d_shutdown() {
      sprites = Object.create(null);
      sheets = Object.create(null);
      sounds = Object.create(null);
      stopMusic();
      musicTracks = Object.create(null);
      musicEl = null;
      triggers = Object.create(null);
      timers = Object.create(null);
      ui_closeWindow();
    }

    /* ===== WebGL1 game3d ===== */
    function compileShader(type, src) {
      var sh = gl.createShader(type);
      gl.shaderSource(sh, src);
      gl.compileShader(sh);
      if (!gl.getShaderParameter(sh, gl.COMPILE_STATUS)) {
        gl.deleteShader(sh);
        return null;
      }
      return sh;
    }

    function initGl() {
      ensureCanvasEl();
      canvas.width = width;
      canvas.height = height;
      gl =
        canvas.getContext('webgl', { antialias: true, depth: true }) ||
        canvas.getContext('experimental-webgl', { antialias: true, depth: true });
      if (!gl) {
        replaceCanvasForGl();
        canvas.width = width;
        canvas.height = height;
        gl =
          canvas.getContext('webgl', { antialias: true, depth: true }) ||
          canvas.getContext('experimental-webgl', { antialias: true, depth: true });
      }
      if (!gl) return false;

      var vs =
        'attribute vec3 aPos; attribute vec3 aColor; uniform mat4 uMVP;' +
        'varying vec3 vColor; void main(){ vColor=aColor; gl_Position=uMVP*vec4(aPos,1.0); }';
      var fs =
        'precision mediump float; varying vec3 vColor; void main(){ gl_FragColor=vec4(vColor,1.0); }';
      var vsh = compileShader(gl.VERTEX_SHADER, vs);
      var fsh = compileShader(gl.FRAGMENT_SHADER, fs);
      if (!vsh || !fsh) return false;
      glProg = gl.createProgram();
      gl.attachShader(glProg, vsh);
      gl.attachShader(glProg, fsh);
      gl.linkProgram(glProg);
      if (!gl.getProgramParameter(glProg, gl.LINK_STATUS)) return false;
      gl.useProgram(glProg);
      glLoc = {
        aPos: gl.getAttribLocation(glProg, 'aPos'),
        aColor: gl.getAttribLocation(glProg, 'aColor'),
        uMVP: gl.getUniformLocation(glProg, 'uMVP'),
      };
      glBuf = gl.createBuffer();
      gl.enable(gl.DEPTH_TEST);
      gl.enable(gl.CULL_FACE);
      gl.cullFace(gl.BACK);
      return true;
    }

    function mvpMatrix() {
      return mat4Multiply(projMat, mat4Multiply(viewMat, modelMat));
    }

    function drawArraysColored(mode, data) {
      if (!gl || !data || data.length < 6) return;
      gl.useProgram(glProg);
      gl.bindBuffer(gl.ARRAY_BUFFER, glBuf);
      gl.bufferData(gl.ARRAY_BUFFER, new Float32Array(data), gl.DYNAMIC_DRAW);
      var stride = 6 * 4;
      gl.enableVertexAttribArray(glLoc.aPos);
      gl.vertexAttribPointer(glLoc.aPos, 3, gl.FLOAT, false, stride, 0);
      gl.enableVertexAttribArray(glLoc.aColor);
      gl.vertexAttribPointer(glLoc.aColor, 3, gl.FLOAT, false, stride, 12);
      gl.uniformMatrix4fv(glLoc.uMVP, false, mvpMatrix());
      gl.drawArrays(mode, 0, data.length / 6);
    }

    function pushVert(out, x, y, z, r, g, b) {
      out.push(x, y, z, r / 255, g / 255, b / 255);
    }

    function g3_openWindow(t, w, h) {
      title = String(t == null ? 'AFRILANG 3D' : t);
      width = Math.max(64, Number(w) || 640);
      height = Math.max(64, Number(h) || 480);
      lastFrameTs = 0;
      showHost(true);
      if (!initGl()) {
        open = false;
        return;
      }
      open = true;
      modelMat = mat4Identity();
    }

    function g3_closeWindow() {
      open = false;
      if (gl) {
        var lose = gl.getExtension('WEBGL_lose_context');
        if (lose) lose.loseContext();
      }
      gl = null;
      glProg = null;
      showHost(false);
    }

    function g3_shutdown() {
      g3_closeWindow();
    }

    function g3_beginFrame() {
      updateTiming(performance.now());
      animTime += frameDeltaMs;
    }

    function g3_showFrame() {
      return new Promise(function (resolve) {
        requestAnimationFrame(function () {
          clearEdgeInput();
          resolve();
        });
      });
    }

    function clearScreen(r, g, b) {
      if (!gl) return;
      gl.viewport(0, 0, width, height);
      gl.clearColor((r | 0) / 255, (g | 0) / 255, (b | 0) / 255, 1);
      gl.clear(gl.COLOR_BUFFER_BIT | gl.DEPTH_BUFFER_BIT);
      modelMat = mat4Identity();
    }

    function setCamera3d(x, y, z, yaw, pitch) {
      cam3d.x = x;
      cam3d.y = y;
      cam3d.z = z;
      cam3d.yaw = yaw;
      cam3d.pitch = pitch;
    }

    function applyCamera() {
      var aspect = height > 0 ? width / height : 1;
      projMat = mat4Perspective(60, aspect, 0.1, 500);
      var yawRad = cam3d.yaw * DEG2RAD;
      var pitchRad = cam3d.pitch * DEG2RAD;
      var lookX = cam3d.x + Math.sin(yawRad) * Math.cos(pitchRad);
      var lookY = cam3d.y + Math.sin(pitchRad);
      var lookZ = cam3d.z - Math.cos(yawRad) * Math.cos(pitchRad);
      viewMat = mat4LookAt(cam3d.x, cam3d.y, cam3d.z, lookX, lookY, lookZ, 0, 1, 0);
      modelMat = mat4Identity();
    }

    function updateFlyCamera(moveSpeed, turnSpeed) {
      var yawRad = cam3d.yaw * DEG2RAD;
      var forwardX = Math.sin(yawRad);
      var forwardZ = -Math.cos(yawRad);
      var rightX = Math.cos(yawRad);
      var rightZ = Math.sin(yawRad);
      if (isKeyDown('W')) {
        cam3d.x += forwardX * moveSpeed;
        cam3d.z += forwardZ * moveSpeed;
      }
      if (isKeyDown('S')) {
        cam3d.x -= forwardX * moveSpeed;
        cam3d.z -= forwardZ * moveSpeed;
      }
      if (isKeyDown('A')) {
        cam3d.x -= rightX * moveSpeed;
        cam3d.z -= rightZ * moveSpeed;
      }
      if (isKeyDown('D')) {
        cam3d.x += rightX * moveSpeed;
        cam3d.z += rightZ * moveSpeed;
      }
      if (isKeyDown('E') || isKeyDown('Space')) cam3d.y += moveSpeed;
      if (isKeyDown('Q')) cam3d.y -= moveSpeed;
      if (isKeyDown('Left')) cam3d.yaw -= turnSpeed;
      if (isKeyDown('Right')) cam3d.yaw += turnSpeed;
      if (isKeyDown('Up')) cam3d.pitch += turnSpeed;
      if (isKeyDown('Down')) cam3d.pitch -= turnSpeed;
      if (cam3d.pitch > 89) cam3d.pitch = 89;
      if (cam3d.pitch < -89) cam3d.pitch = -89;
    }

    function setSceneRotation(angleY) {
      sceneRotY = angleY;
    }

    function applySceneRotation() {
      modelMat = mat4RotateY(mat4Identity(), sceneRotY);
    }

    function drawCube(x, y, z, size, r, g, b) {
      var s = size * 0.5;
      var data = [];
      function face(ax, ay, az, bx, by, bz, cx, cy, cz, dx, dy, dz, cr, cg, cb) {
        pushVert(data, x + ax, y + ay, z + az, cr, cg, cb);
        pushVert(data, x + bx, y + by, z + bz, cr, cg, cb);
        pushVert(data, x + cx, y + cy, z + cz, cr, cg, cb);
        pushVert(data, x + ax, y + ay, z + az, cr, cg, cb);
        pushVert(data, x + cx, y + cy, z + cz, cr, cg, cb);
        pushVert(data, x + dx, y + dy, z + dz, cr, cg, cb);
      }
      face(-s, s, -s, -s, s, s, s, s, s, s, s, -s, r, g, b);
      face(-s, -s, -s, s, -s, -s, s, -s, s, -s, -s, s, r * 0.6, g * 0.6, b * 0.6);
      face(-s, -s, s, s, -s, s, s, s, s, -s, s, s, r * 0.85, g * 0.85, b * 0.85);
      face(-s, -s, -s, -s, s, -s, s, s, -s, s, -s, -s, r * 0.7, g * 0.7, b * 0.7);
      face(-s, -s, -s, -s, -s, s, -s, s, s, -s, s, -s, r * 0.75, g * 0.75, b * 0.75);
      face(s, -s, -s, s, s, -s, s, s, s, s, -s, s, r, g, b);
      drawArraysColored(gl.TRIANGLES, data);
    }

    function drawBox(x, y, z, sx, sy, sz, r, g, b) {
      var hx = sx * 0.5;
      var hy = sy * 0.5;
      var hz = sz * 0.5;
      var data = [];
      function face(ax, ay, az, bx, by, bz, cx, cy, cz, dx, dy, dz) {
        pushVert(data, x + ax, y + ay, z + az, r, g, b);
        pushVert(data, x + bx, y + by, z + bz, r, g, b);
        pushVert(data, x + cx, y + cy, z + cz, r, g, b);
        pushVert(data, x + ax, y + ay, z + az, r, g, b);
        pushVert(data, x + cx, y + cy, z + cz, r, g, b);
        pushVert(data, x + dx, y + dy, z + dz, r, g, b);
      }
      face(-hx, -hy, hz, hx, -hy, hz, hx, hy, hz, -hx, hy, hz);
      face(hx, -hy, -hz, -hx, -hy, -hz, -hx, hy, -hz, hx, hy, -hz);
      face(-hx, hy, hz, hx, hy, hz, hx, hy, -hz, -hx, hy, -hz);
      face(-hx, -hy, -hz, hx, -hy, -hz, hx, -hy, hz, -hx, -hy, hz);
      face(-hx, -hy, -hz, -hx, -hy, hz, -hx, hy, hz, -hx, hy, -hz);
      face(hx, -hy, hz, hx, -hy, -hz, hx, hy, -hz, hx, hy, hz);
      drawArraysColored(gl.TRIANGLES, data);
    }

    function drawPlane(y, halfSize, r, g, b) {
      var hs = halfSize;
      var data = [];
      pushVert(data, -hs, y, -hs, r, g, b);
      pushVert(data, hs, y, -hs, r, g, b);
      pushVert(data, hs, y, hs, r, g, b);
      pushVert(data, -hs, y, -hs, r, g, b);
      pushVert(data, hs, y, hs, r, g, b);
      pushVert(data, -hs, y, hs, r, g, b);
      drawArraysColored(gl.TRIANGLES, data);
    }

    function drawGrid(y, halfSize, divisions) {
      var div = Math.max(1, divisions | 0);
      var hs = halfSize;
      var step = (2 * hs) / div;
      var data = [];
      for (var i = 0; i <= div; i++) {
        var p = -hs + step * i;
        var major = i % 5 === 0;
        var cr = major ? 0.45 * 255 : 0.28 * 255;
        var cg = major ? 0.5 * 255 : 0.32 * 255;
        var cb = major ? 0.58 * 255 : 0.38 * 255;
        pushVert(data, -hs, y, p, cr, cg, cb);
        pushVert(data, hs, y, p, cr, cg, cb);
        pushVert(data, p, y, -hs, cr, cg, cb);
        pushVert(data, p, y, hs, cr, cg, cb);
      }
      drawArraysColored(gl.LINES, data);
    }

    function drawAxis(size) {
      var s = size;
      var data = [];
      pushVert(data, 0, 0, 0, 255, 51, 51);
      pushVert(data, s, 0, 0, 255, 51, 51);
      pushVert(data, 0, 0, 0, 51, 255, 76);
      pushVert(data, 0, s, 0, 51, 255, 76);
      pushVert(data, 0, 0, 0, 76, 128, 255);
      pushVert(data, 0, 0, s, 76, 128, 255);
      drawArraysColored(gl.LINES, data);
    }

    function drawSphere(x, y, z, radius, r, g, b) {
      var stacks = 12;
      var slices = 16;
      var data = [];
      function sph(phi, th) {
        return [
          x + radius * Math.sin(phi) * Math.cos(th),
          y + radius * Math.cos(phi),
          z + radius * Math.sin(phi) * Math.sin(th),
        ];
      }
      for (var i = 0; i < stacks; i++) {
        var phi0 = (Math.PI * i) / stacks;
        var phi1 = (Math.PI * (i + 1)) / stacks;
        for (var j = 0; j < slices; j++) {
          var th0 = (TWO_PI * j) / slices;
          var th1 = (TWO_PI * (j + 1)) / slices;
          var a = sph(phi0, th0);
          var b2 = sph(phi0, th1);
          var c = sph(phi1, th0);
          var d = sph(phi1, th1);
          pushVert(data, a[0], a[1], a[2], r, g, b);
          pushVert(data, c[0], c[1], c[2], r, g, b);
          pushVert(data, b2[0], b2[1], b2[2], r, g, b);
          pushVert(data, b2[0], b2[1], b2[2], r, g, b);
          pushVert(data, c[0], c[1], c[2], r, g, b);
          pushVert(data, d[0], d[1], d[2], r, g, b);
        }
      }
      drawArraysColored(gl.TRIANGLES, data);
    }

    /* ===== gamestate + helpers ===== */
    function setState(name) {
      name = String(name);
      if (stateCurrent === name) return;
      statePrevious = stateCurrent;
      stateCurrent = name;
      stateTime = 0;
      stateChanged = true;
    }

    function getState() {
      return stateCurrent;
    }
    function isState(name) {
      return stateCurrent === String(name);
    }
    function stateTimeMs() {
      return stateTime;
    }
    function wasStateChanged() {
      var v = stateChanged;
      stateChanged = false;
      return v;
    }
    function tickState(delta) {
      stateTime += delta;
    }

    function scoreBonus(score, level) {
      return score + level * 100;
    }
    function levelFromXp(xp) {
      return Math.floor(xp / 1000) + 1;
    }
    function xpForScore(score) {
      return score * 250;
    }
    function speedMsForLevel(level) {
      var ms = 140 - (level - 1) * 8;
      return ms < 55 ? 55 : ms;
    }

    function nowMs() {
      return performance.now();
    }
    function elapsedMs(start) {
      return nowMs() - Number(start);
    }

    function nextRand() {
      randSeed = (Math.imul(randSeed, 1103515245) + 12345) & 0x7fffffff;
      return randSeed;
    }

    function seedRandom(seed) {
      randSeed = (Number(seed) >>> 0) || 1;
      return nextRand();
    }

    function randomRange(lo, hi) {
      lo = Math.floor(Number(lo));
      hi = Math.floor(Number(hi));
      if (hi < lo) {
        var t = lo;
        lo = hi;
        hi = t;
      }
      var span = hi - lo + 1;
      if (span <= 0) return lo;
      return lo + (nextRand() % span);
    }

    function randomList(count, lo, hi) {
      var n = count | 0;
      var out = [];
      for (var i = 0; i < n; i++) out.push(randomRange(lo, hi));
      return out;
    }

    function shuffleList(v, seed) {
      var r = (v || []).slice();
      seedRandom(seed);
      for (var i = r.length; i > 1; i--) {
        var j = nextRand() % i;
        var tmp = r[i - 1];
        r[i - 1] = r[j];
        r[j] = tmp;
      }
      return r;
    }

    /* ----- assemble flat API ----- */
    var rt = {
      assetUrl: assetUrl,

      /* UI always present (2d path unless overridden) */
      openWindow: ui_openWindow,
      closeWindow: ui_closeWindow,
      isOpen: function () {
        return open;
      },
      beginFrame: ui_beginFrame,
      clearBackground: ui_clearBackground,
      fillRect: ui_fillRect,
      drawRect: ui_drawRect,
      drawText: ui_drawText,
      drawTextColor: ui_drawTextColor,
      drawButton: ui_drawButton,
      isKeyDown: isKeyDown,
      wasKeyPressed: wasKeyPressed,
      deltaMs: function () {
        return frameDeltaMs;
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
        return fpsValue;
      },
      showFrame: ui_showFrame,

      /* game2d */
      configureGrid: configureGrid,
      configureViewport: configureViewport,
      gridWindowWidth: gridWindowWidth,
      gridWindowHeight: gridWindowHeight,
      cellWorldX: cellWorldX,
      cellWorldY: cellWorldY,
      cellPx: cellPx,
      cellPy: cellPy,
      isBorderCell: isBorderCell,
      fillCell: fillCell,
      drawCell: drawCell,
      fillBoard: fillBoard,
      drawWalls: drawWalls,
      drawGridLines: drawGridLines,
      fillCircleSolid: fillCircleSolid,
      everyMs: everyMs,
      resetTimer: resetTimer,
      animTimeMs: animTimeMs,
      pulse01: pulse01,
      updateDirection: updateDirection,
      inputDirX: inputDirX,
      inputDirY: inputDirY,
      syncDirection: syncDirection,
      gridHas: gridHas,
      rgb: rgb,
      redOf: redOf,
      greenOf: greenOf,
      blueOf: blueOf,
      fillCellRgb: fillCellRgb,
      drawCenteredText: drawCenteredText,
      drawHud: drawHud,
      highScore: highScore,
      updateHighScore: updateHighScore,
      moveIntervalForScore: moveIntervalForScore,
      setCamera: setCamera2d,
      cameraX: cameraX,
      cameraY: cameraY,
      followCamera: followCamera,
      loadSprite: loadSprite,
      hasSprite: hasSprite,
      spriteWidth: spriteWidth,
      spriteHeight: spriteHeight,
      drawSprite: drawSprite,
      drawSpriteScaled: drawSpriteScaled,
      drawSpriteCell: drawSpriteCell,
      loadSpriteSheet: loadSpriteSheet,
      hasSpriteSheet: hasSpriteSheet,
      sheetCols: sheetCols,
      sheetRows: sheetRows,
      drawSpriteFrame: drawSpriteFrame,
      drawSpriteFrameCell: drawSpriteFrameCell,
      loadSound: loadSound,
      playSound: playSound,
      playSoundVolume: playSoundVolume,
      loadMusic: loadMusic,
      playMusic: playMusic,
      stopMusic: stopMusic,
      setMusicVolume: setMusicVolume,
      defineTrigger: defineTrigger,
      setTriggerActive: setTriggerActive,
      pointInTrigger: pointInTrigger,
      mouseInTrigger: mouseInTrigger,
      mouseWorldX: mouseWorldX,
      mouseWorldY: mouseWorldY,
      saveValue: saveValue,
      loadValue: loadValue,
      loadHighScore: loadHighScore,
      saveHighScore: saveHighScore,
      drawFps: drawFps,
      shutdown: game2d_shutdown,

      /* game3d core (stubs unless game3d mode wires real impl) */
      clearScreen: function () {},
      applyCamera: function () {},
      updateFlyCamera: function () {},
      setSceneRotation: function () {},
      applySceneRotation: function () {},
      drawCube: function () {},
      drawPlane: function () {},
      drawGrid: function () {},
      drawAxis: function () {},
      drawSphere: function () {},
      drawBox: function () {},

      /* gamestate + helpers */
      setState: setState,
      getState: getState,
      isState: isState,
      stateTimeMs: stateTimeMs,
      wasStateChanged: wasStateChanged,
      tickState: tickState,
      scoreBonus: scoreBonus,
      levelFromXp: levelFromXp,
      xpForScore: xpForScore,
      speedMsForLevel: speedMsForLevel,
      nowMs: nowMs,
      elapsedMs: elapsedMs,
      seedRandom: seedRandom,
      randomRange: randomRange,
      randomList: randomList,
      shuffleList: shuffleList,
    };

    /* game3d advanced stubs — no-op / false / 0 so demos don't crash */
    var stubFalse = [
      'loadTexture3d',
      'hasTexture3d',
      'loadModel',
      'hasModel',
      'hasBody',
      'loadSkyboxFace',
      'hasSkybox',
      'loadShader',
      'hasShader',
      'loadGltf',
      'hasGltf',
      'loadGlb',
      'isEditMode',
      'pickGroundHit',
      'saveLevel',
      'loadLevel',
    ];
    var stubZero = [
      'bodyX',
      'bodyY',
      'bodyZ',
      'gltfAnimCount',
      'gltfAnimRotY',
      'levelCount',
      'levelX',
      'levelY',
      'levelZ',
      'levelScale',
      'levelRotY',
      'pickGroundX',
      'pickGroundY',
      'pickGroundZ',
      'pickBody',
      'pickGround',
    ];
    var stubEmpty = ['pickBodyName', 'levelType', 'levelAsset'];
    var stubNoop = [
      'drawPlaneTextured',
      'drawCubeTextured',
      'drawModel',
      'drawModelColored',
      'drawModelLit',
      'createBody',
      'setBodyVelocity',
      'setBodyPosition',
      'applyImpulse',
      'stepPhysics',
      'stepPhysicsEx',
      'removeBody',
      'createBoxBody',
      'setBodyFriction',
      'setBodyRestitution',
      'drawBody',
      'enableLighting',
      'setAmbientLight',
      'setSunLight',
      'applyLighting',
      'setFog',
      'applyFog',
      'setWind',
      'followBody',
      'emitBurst',
      'updateParticles',
      'drawParticles',
      'drawSkyGradient',
      'drawSkybox',
      'useShader',
      'stopShader',
      'setShaderFloat',
      'setShaderVec3',
      'drawModelShader',
      'drawGltf',
      'drawGltfLit',
      'playGltfAnim',
      'stopGltfAnim',
      'updateGltfAnims',
      'setEditMode',
      'clearLevel',
      'addLevelGltf',
      'addLevelModel',
      'drawLevel',
      'rotateScene',
    ];
    var i;
    for (i = 0; i < stubFalse.length; i++) {
      rt[stubFalse[i]] = function () {
        return false;
      };
    }
    for (i = 0; i < stubZero.length; i++) {
      rt[stubZero[i]] = function () {
        return 0;
      };
    }
    for (i = 0; i < stubEmpty.length; i++) {
      rt[stubEmpty[i]] = function () {
        return '';
      };
    }
    for (i = 0; i < stubNoop.length; i++) {
      rt[stubNoop[i]] = function () {};
    }

    if (game3d) {
      rt.openWindow = g3_openWindow;
      rt.closeWindow = g3_closeWindow;
      rt.shutdown = g3_shutdown;
      rt.beginFrame = g3_beginFrame;
      rt.showFrame = g3_showFrame;
      rt.setCamera = setCamera3d;
      rt.clearScreen = clearScreen;
      rt.applyCamera = applyCamera;
      rt.updateFlyCamera = updateFlyCamera;
      rt.setSceneRotation = setSceneRotation;
      rt.applySceneRotation = applySceneRotation;
      rt.drawCube = drawCube;
      rt.drawPlane = drawPlane;
      rt.drawGrid = drawGrid;
      rt.drawAxis = drawAxis;
      rt.drawSphere = drawSphere;
      rt.drawBox = drawBox;
    }

    return rt;
  }

  global.AfrilangPlayground = {
    createRuntime: createRuntime,
  };
  global.AfrilangUI = createRuntime({ game3d: false });
})(typeof window !== 'undefined' ? window : this);
