"""Translate ecosystem capability categories FR → EN."""

CATEGORY_EN = {
    'Langage': 'Language',
    'Compilateur': 'Compiler',
    'CLI': 'CLI',
    'Stdlib': 'Standard library',
    'Paquets blessed': 'Certified packages',
    'WASM & Web': 'WASM & Web',
    'LSP & IDE': 'LSP & IDE',
    'Debug': 'Debug',
    'Async & UI': 'Async & UI',
    'Qualité & CI': 'Quality & CI',
}

ITEMS_EN = {
    'Syntaxe naturelle FR / EN': 'Natural FR / EN syntax',
    'POO, génériques, enums, match, async': 'OOP, generics, enums, match, async',
    'Lambdas, traits, records, unions': 'Lambdas, traits, records, unions',
    'Transpilation C++17 + g++/clang++': 'C++17 transpilation + g++/clang++',
    'Cibles: native, linux-x64, linux-arm64, wasm32': 'Targets: native, linux-x64, linux-arm64, wasm32',
    'Cache, symboles debug, mode sécurisé': 'Cache, debug symbols, safe mode',
    'run, build, check, test, fmt, lint, repl': 'run, build, check, test, fmt, lint, repl',
    'pkg, debug, benchmark, serve': 'pkg, debug, benchmark, serve',
    'io, json, fs, http, crypto, yaml, csv': 'io, json, fs, http, crypto, yaml, csv',
    'math, datetime, collections, thread…': 'math, datetime, collections, thread…',
    '10 paquets officiels SHA256': '10 official SHA256 packages',
    'math, strings, fmt, validate, config…': 'math, strings, fmt, validate, config…',
    'Emscripten, Run in browser': 'Emscripten, run in browser',
    'Playground Django + API REST': 'Django playground + REST API',
    'Diagnostics, symboles, code actions': 'Diagnostics, symbols, code actions',
    'Extension VS Code / Open VSX': 'VS Code / Open VSX extension',
    'DAP GDB/MI, métadonnées Afrilang': 'DAP GDB/MI, Afrilang metadata',
    'Pretty-print des variables typées': 'Typed variable pretty-print',
    'async/await, SDL2 UI, FFI externe': 'async/await, SDL2 UI, external FFI',
    '60+ exemples, CI wasm-build, Docker': '60+ examples, wasm CI, Docker',
}


def translate_ecosystem(by_category, lang):
    code = (lang or 'fr')[:2]
    if code != 'en':
        return by_category
    out = {}
    for cat, caps in by_category.items():
        en_cat = CATEGORY_EN.get(cat, cat)
        translated_caps = []
        for cap in caps:
            items = [ITEMS_EN.get(i, i) for i in cap.items]
            translated_caps.append(type('Cap', (), {
                'title': cap.title,
                'items': items,
            })())
        out[en_cat] = translated_caps
    return out
