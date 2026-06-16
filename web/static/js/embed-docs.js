(function () {
  'use strict';

  var cfg = window.AFR_EMBED_DOCS || {};
  var base = cfg.baseUrl || '/playground/embed/';
  var exampleEl = document.getElementById('embed-example');
  var heightEl = document.getElementById('embed-height');
  var examplesEl = document.getElementById('embed-examples');
  var codeEl = document.getElementById('embed-code');
  var previewEl = document.getElementById('embed-preview');
  var copyBtn = document.getElementById('copy-embed-code');

  function buildUrl() {
    var params = new URLSearchParams();
    if (exampleEl && exampleEl.value) params.set('example', exampleEl.value);
    if (examplesEl && examplesEl.checked) params.set('examples', '1');
    var qs = params.toString();
    return base + (qs ? '?' + qs : '');
  }

  function buildIframeCode() {
    var url = buildUrl();
    var h = heightEl ? parseInt(heightEl.value, 10) || 480 : 480;
    return '<iframe src="' + url + '"\n' +
      '  width="100%" height="' + h + '"\n' +
      '  loading="lazy"\n' +
      '  title="AFRILANG Playground"\n' +
      '  style="border:1px solid #e2e8f0;border-radius:12px">\n' +
      '</iframe>';
  }

  function update() {
    var code = buildIframeCode();
    if (codeEl) codeEl.textContent = code;
    if (previewEl) previewEl.src = buildUrl();
  }

  exampleEl?.addEventListener('change', update);
  heightEl?.addEventListener('input', update);
  examplesEl?.addEventListener('change', update);

  copyBtn?.addEventListener('click', function () {
    var text = codeEl ? codeEl.textContent : '';
    var label = cfg.copyLabel || 'Copy';
    navigator.clipboard?.writeText(text).then(function () {
      copyBtn.textContent = cfg.copied || 'Copied!';
      setTimeout(function () { copyBtn.textContent = label; }, 1500);
    });
  });
  update();
})();
