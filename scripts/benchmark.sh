#!/usr/bin/env bash
set -euo pipefail

ROOT="$(cd "$(dirname "$0")/.." && pwd)"
AFRILANG="${AFRILANG:-$ROOT/build/afrilang}"
EXAMPLES="$ROOT/examples"

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

printf "=== Benchmark AFRILANG ===\n\n"
printf "%-24s %10s %10s %10s\n" "fichier" "compile" "exec" "total"
printf "%-24s %10s %10s %10s\n" "------------------------" "----------" "----------" "----------"

failures=0
for file in "${FILES[@]}"; do
  path="$EXAMPLES/$file"
  if [[ ! -f "$path" ]]; then
    echo "SKIP $file (introuvable)" >&2
    continue
  fi
  base="${file%.afr}"
  (
    cd "$(dirname "$path")"
    t0=$(now_ms)
    "$AFRILANG" run "$(basename "$path")" --emit >/dev/null 2>&1
    t1=$(now_ms)
    if [[ -x "./$base" ]]; then
      "./$base" >/dev/null 2>&1 || true
    fi
    t2=$(now_ms)
    compile_ms=$((t1 - t0))
    exec_ms=$((t2 - t1))
    total_ms=$((t2 - t0))
    printf "%-24s %9dms %9dms %9dms\n" "$file" "$compile_ms" "$exec_ms" "$total_ms"
  ) || {
    echo "FAIL $file" >&2
    failures=$((failures + 1))
  }
done

echo
if [[ $failures -gt 0 ]]; then
  echo "$failures benchmark(s) en échec" >&2
  exit 1
fi
echo "Benchmark terminé."
