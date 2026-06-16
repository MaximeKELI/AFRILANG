#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFRILANG="${AFRILANG:-$ROOT/build/afrilang}"
EXAMPLES="$ROOT/examples"
JSON_MODE=0

if [[ "${1:-}" == "--json" ]]; then
  JSON_MODE=1
  shift
fi

if [[ ! -x "$AFRILANG" ]]; then
  echo "Exécutable introuvable: $AFRILANG" >&2
  exit 1
fi

FILES=(
  hello.afr
  oop.afr
  generics.afr
  full_demo.afr
  stdlib_demo.afr
  tier9_demo.afr
  tier10_demo.afr
)

now_ms() {
  python3 -c 'import time; print(int(time.time() * 1000))'
}

compiler_version() {
  "$AFRILANG" --version 2>&1 | python3 -c "
import re, sys
t = sys.stdin.read()
m = re.search(r'v(\d+(?:\.\d+)*)', t)
print(m.group(1) if m else '1.0.0')
" 2>/dev/null || echo "1.0.0"
}

log() {
  if [[ "$JSON_MODE" -eq 0 ]]; then
    echo "$@"
  else
    echo "$@" >&2
  fi
}

log "=== Benchmark AFRILANG ==="
log ""
log "$(printf '%-24s %10s %10s %10s' 'fichier' 'compile' 'exec' 'total')"
log "$(printf '%-24s %10s %10s %10s' '------------------------' '----------' '----------' '----------')"

failures=0
RESULTS_TMP=$(mktemp)
echo "[]" > "$RESULTS_TMP"

for file in "${FILES[@]}"; do
  path="$EXAMPLES/$file"
  if [[ ! -f "$path" ]]; then
    log "SKIP $file (introuvable)"
    continue
  fi
  base="${file%.afr}"
  workdir="$(dirname "$path")"
  if ! (
    cd "$workdir"
    t0=$(now_ms)
    "$AFRILANG" run "$(basename "$path")" --emit >/dev/null 2>&1
    t1=$(now_ms)
    exec_ms=0
    if [[ -x "./$base" ]]; then
      t_exec0=$(now_ms)
      "./$base" >/dev/null 2>&1 || true
      t_exec1=$(now_ms)
      exec_ms=$((t_exec1 - t_exec0))
    fi
    t2=$(now_ms)
    compile_ms=$((t1 - t0))
    total_ms=$((t2 - t0))
    log "$(printf '%-24s %9dms %9dms %9dms' "$file" "$compile_ms" "$exec_ms" "$total_ms")"
    if [[ "$JSON_MODE" -eq 1 ]]; then
      python3 -c "
import json, sys
path = sys.argv[1]
row = {'file': '$file', 'slug': '$base', 'compile_ms': $compile_ms, 'exec_ms': $exec_ms, 'total_ms': $total_ms}
data = json.load(open(path))
data.append(row)
json.dump(data, open(path, 'w'))
" "$RESULTS_TMP"
    fi
  ); then
    log "FAIL $file"
    failures=$((failures + 1))
  fi
done

COMP_TMP=$(mktemp)
echo "[]" > "$COMP_TMP"
hello_bin="$EXAMPLES/hello"
if [[ -x "$hello_bin" ]]; then
  t0=$(now_ms)
  "$hello_bin" >/dev/null 2>&1 || true
  t1=$(now_ms)
  afr_exec=$((t1 - t0))
  py_ms=0
  if command -v python3 >/dev/null 2>&1; then
    t0=$(now_ms)
    python3 -c '
print("Bonjour depuis AFRILANG!")
print("Le compilateur fonctionne.")
for _ in range(3):
    print("Hello")
' >/dev/null 2>&1
    t1=$(now_ms)
    py_ms=$((t1 - t0))
  fi
  if [[ "$JSON_MODE" -eq 1 ]]; then
    python3 -c "
import json
row = {'name': 'hello', 'label': 'hello.afr', 'afrilang_exec_ms': $afr_exec, 'python_ms': $py_ms}
json.dump([row], open('$COMP_TMP', 'w'))
"
  fi
  if [[ "$JSON_MODE" -eq 0 && "$py_ms" -gt 0 ]]; then
    log ""
    log "--- Comparaison hello (exec seule) ---"
    log "AFRILANG binaire : ${afr_exec}ms"
    log "Python 3        : ${py_ms}ms"
  fi
fi

log ""
if [[ $failures -gt 0 ]]; then
  log "$failures benchmark(s) en échec"
  rm -f "$RESULTS_TMP" "$COMP_TMP"
  exit 1
fi
log "Benchmark terminé."

if [[ "$JSON_MODE" -eq 1 ]]; then
  VER=$(compiler_version | tr -d '\n\r')
  export BENCH_VER="$VER"
  export BENCH_RESULTS="$RESULTS_TMP"
  export BENCH_COMP="$COMP_TMP"
  python3 << 'PY'
import json, datetime, platform, os
print(json.dumps({
    'generated_at': datetime.datetime.utcnow().replace(microsecond=0).isoformat() + 'Z',
    'compiler_version': os.environ.get('BENCH_VER', '1.0.0'),
    'platform': platform.system().lower() + '-' + platform.machine().lower(),
    'results': json.load(open(os.environ['BENCH_RESULTS'])),
    'comparisons': json.load(open(os.environ['BENCH_COMP'])),
    'is_sample': False,
}, indent=2))
PY
fi

rm -f "$RESULTS_TMP" "$COMP_TMP"
