(function () {
  'use strict';

  var el = document.getElementById('benchmark-data');
  if (!el || typeof Chart === 'undefined') return;

  var data;
  try {
    data = JSON.parse(el.textContent);
  } catch (_) {
    return;
  }

  var results = data.results || [];
  if (!results.length) return;

  var labels = results.map(function (r) { return r.slug || r.file; });
  var compileData = results.map(function (r) { return r.compile_ms; });
  var execData = results.map(function (r) { return r.exec_ms; });
  var totalData = results.map(function (r) { return r.total_ms; });

  var isDark = document.documentElement.getAttribute('data-afr-theme') === 'dark';
  var gridColor = isDark ? 'rgba(148, 163, 184, 0.15)' : 'rgba(15, 23, 42, 0.08)';
  var textColor = isDark ? '#94a3b8' : '#475569';
  var primary = isDark ? '#60a5fa' : '#1d4ed8';
  var accent = isDark ? '#fbbf24' : '#d97706';

  var baseOpts = {
    responsive: true,
    maintainAspectRatio: false,
    plugins: {
      legend: { labels: { color: textColor, boxWidth: 12 } },
    },
    scales: {
      x: {
        ticks: { color: textColor, maxRotation: 45 },
        grid: { color: gridColor },
      },
      y: {
        ticks: { color: textColor, callback: function (v) { return v + ' ms'; } },
        grid: { color: gridColor },
        beginAtZero: true,
      },
    },
  };

  var ctx1 = document.getElementById('chart-compile-exec');
  if (ctx1) {
    new Chart(ctx1, {
      type: 'bar',
      data: {
        labels: labels,
        datasets: [
          { label: 'Compile', data: compileData, backgroundColor: primary, borderRadius: 4 },
          { label: 'Exec', data: execData, backgroundColor: accent, borderRadius: 4 },
        ],
      },
      options: Object.assign({}, baseOpts, {
        plugins: Object.assign({}, baseOpts.plugins, {
          tooltip: {
            callbacks: {
              label: function (ctx) { return ctx.dataset.label + ': ' + ctx.parsed.y + ' ms'; },
            },
          },
        }),
      }),
    });
  }

  var ctx2 = document.getElementById('chart-total');
  if (ctx2) {
    new Chart(ctx2, {
      type: 'doughnut',
      data: {
        labels: labels,
        datasets: [{
          data: totalData,
          backgroundColor: [
            '#1d4ed8', '#6366f1', '#8b5cf6', '#a855f7',
            '#d97706', '#059669', '#0d9488',
          ],
          borderWidth: 0,
        }],
      },
      options: {
        responsive: true,
        maintainAspectRatio: false,
        plugins: {
          legend: {
            position: 'bottom',
            labels: { color: textColor, boxWidth: 10, font: { size: 11 } },
          },
          tooltip: {
            callbacks: {
              label: function (ctx) { return ctx.label + ': ' + ctx.parsed + ' ms'; },
            },
          },
        },
      },
    });
  }
})();
