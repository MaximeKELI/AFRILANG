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

Inspiré de Python `math` et Nim `std/math`.

| Fonction | Rôle |
|----------|------|
| `abs` / `floor` / `ceil` / `round` / `trunc` | Entiers autour |
| `pow` / `sqrt` / `cbrt` / `exp` / `expm1` / `log` / `log1p` / `log10` / `log2` | Puissances & logs |
| `sin`…`tanh` / `hypot` | Trigonométrie |
| `min` / `max` / `clamp` / `sign` / `lerp` | Comparaisons / interpolation |
| `gcd` / `lcm` / `fmod` / `remainder` / `copysign` | Arithmétique |
| `erf` / `erfc` / `gamma` / `lgamma` | Fonctions spéciales |
| `isFinite` / `isInf` / `isNan` / `isClose` | Tests IEEE |
| `deg2rad` / `rad2deg` | Angles |
| `pi` / `e` / `tau` / `inf` / `nan` | Constantes |
| `random()` | `[0, 1)` |

Tests : `tests/stdlib/math.afr`

## `std/stats`

Inspiré de Nim `std/stats` et Python `statistics`.

| Fonction | Rôle |
|----------|------|
| `count` / `sum` / `fsum` / `product` | Agrégats |
| `mean` / `geometricMean` / `harmonicMean` / `rms` / `median` / `mode` | Tendance centrale |
| `minVal` / `maxVal` / `range` | Extrema |
| `variance` / `stddev` / `popVariance` / `popStddev` / `seMean` / `cv` | Dispersion |
| `q1` / `q3` / `iqr` / `midhinge` / `mad` / `trimmedMean` / `percentile` / `quantile` | Quantiles / robustesse |
| `skewness` / `kurtosis` | Forme |
| `covariance` / `correlation` | Bivarié |
| `linRegSlope` / `linRegIntercept` / `linRegPredict` | Régression linéaire OLS |
| `cumSum` / `cumProd` / `diffs` / `zScores` / `normalize` / `ranks` / `movingAvg` | Transformations |
| `outlierIndices` / `outlierCount` / `withoutOutliers` / `histogram` | Outliers & hist |

Tests : `tests/stdlib/stats.afr`

## `std/proba`

Inspiré de Python/`scipy`, R et Crystal `Random`.

| Fonction | Rôle |
|----------|------|
| `factorial` / `comb` / `perm` | Combinatoire |
| `normal*` / `uniform*` / `exponential*` | Continues de base |
| `binomial*` / `poisson*` / `geometric*` | Discrètes |
| `logNormal*` / `gamma*` / `chiSquare*` / `studentT*` | Continues avancées |
| `seed` / `sampleUniform` / `sampleInt` / `sampleNormal` / … | RNG |
| `sampleChoice` / `sampleShuffle` / `sampleN` | Tirages sur listes |

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
