#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
OUT_DIR="$ROOT/site/compiler"
mkdir -p "$OUT_DIR"

if ! command -v em++ >/dev/null 2>&1; then
  echo "em++ introuvable — installez Emscripten (emsdk) pour le compilateur WASM client." >&2
  exit 1
fi

SOURCES=(
  "$ROOT/src/lexer/lexer.cpp"
  "$ROOT/src/parser/parser.cpp"
  "$ROOT/src/semantic/analyzer.cpp"
  "$ROOT/src/utils/compiler.cpp"
  "$ROOT/src/utils/diagnostics.cpp"
  "$ROOT/src/utils/utf8.cpp"
  "$ROOT/src/utils/i18n.cpp"
  "$ROOT/src/utils/js_codegen.cpp"
  "$ROOT/src/wasm_api/compiler_api.cpp"
)

em++ -std=c++17 -O2 \
  -I"$ROOT/include" \
  "${SOURCES[@]}" \
  -s EXPORTED_FUNCTIONS='["_afrilang_compile_js","_afrilang_free","_malloc","_free"]' \
  -s EXPORTED_RUNTIME_METHODS='["UTF8ToString","allocateUTF8"]' \
  -s MODULARIZE=1 \
  -s EXPORT_NAME=createAfrilangCompiler \
  -s ALLOW_MEMORY_GROWTH=1 \
  -s FILESYSTEM=0 \
  -o "$OUT_DIR/afrilang-compiler.js"

echo "Compilateur WASM client : $OUT_DIR/afrilang-compiler.js"
