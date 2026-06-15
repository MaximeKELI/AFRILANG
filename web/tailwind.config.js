/** @type {import('tailwindcss').Config} */
module.exports = {
  prefix: 'tw-',
  content: ['./templates/**/*.html', './core/templates/**/*.html'],
  corePlugins: {
    preflight: false,
  },
  theme: {
    extend: {
      colors: {
        afr: {
          bg: '#06080d',
          surface: '#121824',
          accent: '#5b8cff',
          gold: '#ffc857',
        },
      },
      fontFamily: {
        sans: ['Plus Jakarta Sans', 'system-ui', 'sans-serif'],
        mono: ['JetBrains Mono', 'ui-monospace', 'monospace'],
      },
    },
  },
  plugins: [],
};
