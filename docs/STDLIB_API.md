# Core stdlib API (Vague 3)

Documentation prioritaire des backends réels (`runtime/*.hpp`).  
Les catalogues générés (`stdlib/m/`, `stdlib/c/`, stubs massifs) restent expérimentaux.

Voir aussi `CORE_STDLIB.md` et `afrilang test --specs`.

## `std/str`

| Fonction | Rôle |
|----------|------|
| `trim(text)` | Enlève espaces / tabs / newlines |
| `contains(text, needle)` | Sous-chaîne |
| `replace(text, from, to)` | Remplacement global |
| `split(text, sep)` | Découpe en liste |
| `join(parts, sep)` | Jointure |
| `toString(...)` | Conversion |

Tests : `tests/stdlib/str.afr`

## `std/math`

| Fonction | Rôle |
|----------|------|
| `abs(n)` | Valeur absolue |
| `floor(n)` / `ceil(n)` / `round(n)` / `trunc(n)` | Entiers autour |
| `pow(base, exp)` / `sqrt` / `cbrt` / `exp` / `log` / `log10` / `log2` | Puissances & logs |
| `sin` / `cos` / `tan` / `asin` / `acos` / `atan` / `atan2` / `sinh` / `cosh` / `tanh` / `hypot` | Trigonométrie |
| `min` / `max` / `clamp` / `sign` | Comparaisons scalaires |
| `deg2rad` / `rad2deg` | Angles |
| `pi()` / `e()` / `tau()` | Constantes |
| `random()` | `[0, 1)` |

Tests : `tests/stdlib/math.afr`

## `std/stats`

| Fonction | Rôle |
|----------|------|
| `count` / `sum` / `mean` / `median` / `mode` | Tendance centrale |
| `minVal` / `maxVal` / `range` | Extrema (listes ; scalaires : `math.min` / `math.max`) |
| `variance` / `stddev` / `popVariance` / `popStddev` | Dispersion |
| `q1` / `q3` / `iqr` / `percentile` / `quantile` | Quantiles |
| `skewness` / `kurtosis` | Forme |
| `covariance` / `correlation` | Bivarié |
| `cumSum` / `zScores` / `histogram(v, bins)` | Transformations |

Tests : `tests/stdlib/stats.afr`

## `std/proba`

| Fonction | Rôle |
|----------|------|
| `factorial` / `comb` / `perm` | Combinatoire |
| `normalPdf` / `normalCdf` / `normalInv` | Normale |
| `uniformPdf` / `uniformCdf` | Uniforme |
| `exponentialPdf` / `exponentialCdf` | Exponentielle |
| `binomialPdf` / `binomialCdf` | Binomiale |
| `poissonPdf` / `poissonCdf` | Poisson |
| `seed` / `sampleUniform` / `sampleNormal` / `sampleBernoulli` / `sampleBinomial` / `samplePoisson` / `sampleExponential` | RNG |

Tests : `tests/stdlib/proba.afr`

## `std/json`

| Fonction | Rôle |
|----------|------|
| `makeObject(key, value)` | Objet simple |
| `parse(text)` / `stringify(doc)` | Sérialisation |
| `getString` / `getNumber` | Lecture |

Tests : `tests/stdlib/json.afr`

## WASM

Compatibles wasm32 (voir `WASM_COMPAT.md`) : `str`, `math`, `stats`, `proba`, `json`, `collections`, `path`, `log`, `async` (subset).  
Natif seulement : `fs`/`io` fichiers, `http`, `ui`, `game*`.

Démo : `examples/tier8_stdlib.afr`
