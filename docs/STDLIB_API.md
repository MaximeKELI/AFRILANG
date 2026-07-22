# Core stdlib API (Vague 3)

Documentation prioritaire des backends réels (`runtime/*.hpp`).  
Les catalogues générés (`stdlib/m/`, `stdlib/c/`, stubs massifs) restent expérimentaux.

Voir aussi `CORE_STDLIB.md` et `afrilang test --specs`.

**Note licence** : les modules ci-dessous alignent leur *surface API* sur Python (`math`, `statistics`, `random`), Nim (`std/math`, `std/stats`, `std/random`) et Crystal (`Random`). L’implémentation est **propre** (wrappers C++ / formules classiques) — **aucun code source** de ces projets n’est copié.

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

## `std/math` (~116 fonctions)

Surface type **Python `math` + Nim `std/math`** :

- Entiers / reste : `floor`, `ceil`, `trunc`, `round`, `roundPlaces`, `fmod`, `remainder`, `floorDiv`, `floorMod`, `euclDiv`, `euclMod`, `fma`
- Puissances / logs : `pow`, `sqrt`, `cbrt`, `isqrt`, `exp`, `exp2`, `expm1`, `log`/`ln`, `log1p`, `log2`, `log10`, `logBase`
- Trig + hyperbolique + réciproques (Nim) : `sin`…`atanh`, `sec`/`csc`/`cot`, `arcsec`…
- Théorie des nombres : `gcd`, `lcm`, `factorial`/`fac`, `comb`/`binom`, `perm`, `isPowerOfTwo`, `nextPowerOfTwo`
- Spéciales : `erf`, `erfc`, `gamma`, `lgamma`
- IEEE : `isFinite`, `isInf`, `isNan`, `isClose`, `almostEqual`, `classify`, `ulp`, `nextafter`, `frexp*`, `ldexp`, `modf*`
- Listes : `fsum`, `sum`, `prod`, `sumprod`, `dist`, `cumsummed`, `cumproded`
- Constantes : `pi`, `e`, `tau`, `inf`, `nan`

Tests : `tests/stdlib/math.afr`

## `std/stats` (~60 fonctions)

Surface type **Python `statistics` + Nim `std/stats`** :

- Tendance : `mean`/`fmean`, `geometricMean`, `harmonicMean`, `rms`, `median`/`medianLow`/`medianHigh`/`medianGrouped`, `mode`/`multimode`
- Dispersion : `variance`/`varianceS`, `stddev`/`standardDeviationS`, `pvariance`/`pstdev`/`standardDeviation`, `seMean`, `cv`, `mad`, `iqr`, `trimmedMean`
- Forme : `skewness`/`skewnessS`, `kurtosis`/`kurtosisS`
- Bivarié / régression : `covariance`, `correlation`/`pearsonr`, `linRegSlope`/`Intercept`/`Predict`
- Transforms : `cumSum`, `normalize`, `ranks`, `movingAvg`, outliers Tukey, `quantiles`, `histogram`

Tests : `tests/stdlib/stats.afr`

## `std/proba` (~64 fonctions)

Surface type **Python `random` + distributions usuelles (R / SciPy-lite)** :

- Combinatoire, PDF/CDF : normale, uniforme, expo, binomiale, Poisson, géométrique, log-normale, gamma, chi², Student-t, Weibull, Beta, Pareto
- Sampling Python-like : `rand`, `randint`, `randrange`, `gauss`/`normalvariate`, `betavariate`, `gammavariate`, `weibullvariate`, `paretovariate`, `vonmisesvariate`, `expovariate`, `lognormvariate`, `sampleTriangular`
- Listes : `sampleChoice`, `sampleShuffle`, `sampleN`, `sampleWeighted`, `sampleWithoutReplacement`, `sampleCdf`
- `seed` / `randomize`

Tests : `tests/stdlib/proba.afr`

## `std/random`

RNG de base (Crystal / Nim style) : `seed`, `randomize`, `randomInt`, `randomFloat`, `rand`, `randint`, `gauss`, `uniform`, `choice`, `shuffle`, `sample`.

## `std/crypto`

OpenSSL : `sha256` / `sha512` / `sha1` / `sha3_256`, `sha256File`, `hmacSha256`, `randomBytes` / `randomHex`, `hexEncode` / `hexDecode`, `aesGcmEncrypt` / `aesGcmDecrypt` (hex packed nonce||tag||ciphertext).

Tests : `tests/stdlib/crypto.afr`

## `std/process`

Spawn sans shell (style Go `os/exec` / Python `subprocess`) : `run`, `runCmd`, `captureStdout`, `captureCombined`, `getPid`, `exitWith`.  
`runShell` uniquement si `AFRILANG_INSECURE=1` (sinon retourne `-2`).

Tests : `tests/stdlib/process.afr`

## `std/net`

TCP : `tcpConnect`, `tcpListen`, `tcpAccept`, `tcpRead`, `tcpWrite`, `tcpClose`.  
HTTP : `httpServe` (bloquant), `httpServeOnce`, `httpServeTlsOnce` (cert/key PEM, OpenSSL).

Tests : `tests/stdlib/net.afr` (listen/connect ; pas de serveur bloquant en CI).

## `std/json`

| Fonction | Rôle |
|----------|------|
| `makeObject(key, value)` | Objet simple |
| `parse(text)` / `stringify(doc)` | Sérialisation |
| `getString` / `getNumber` | Lecture |

Tests : `tests/stdlib/json.afr`

## WASM

Compatibles wasm32 (voir `WASM_COMPAT.md`) : `str`, `math`, `stats`, `proba`, `random`, `json`, `collections`, `path`, `log`, `async` (subset).  
Natif seulement : `fs`/`io` fichiers, `http`, `crypto`, `process`, `net`, `ui`, `game*`.

Démo : `examples/tier8_stdlib.afr` · `examples/math_stats_proba_demo.afr`

## Hors portée (volontairement)

- **SciPy.stats**, **Distributions.jl**, packs CRAN entiers : écosystèmes énormes, pas des stdlibs.
- Objets mutables type Nim `RunningStat` (pas de type opaque dédié en AFRILANG 1.x) — équivalents batch fournis.
- Nombres complexes / rationnels (modules séparés possibles plus tard).
