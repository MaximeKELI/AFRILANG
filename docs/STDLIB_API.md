# Core stdlib API (Vague 3)

Documentation prioritaire des backends réels (`runtime/*.hpp`).  
Les catalogues générés (`stdlib/m/`, `stdlib/c/`, stubs massifs) restent expérimentaux.
Ils ne sont **inclus au link** (`simple_libs.hpp` / `medium_libs.hpp` / `complex_libs.hpp`)
que si un module catalogue est réellement importé via `std/...` (pas pour le core legacy,
pas pour un paquet utilisateur homonyme).

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
| `startsWith` / `endsWith` | Préfixe / suffixe |
| `toUpper` / `toLower` | Casse ASCII |
| `byteLen(text)` | Longueur octets |
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

## `std/re`

Regex : backend **std::regex** (ECMAScript, WASM) par défaut ; avec
`-DAFRILANG_HAS_PCRE2` (activé par CMake si `libpcre2` est trouvé), le moteur
**PCRE2** est utilisé pour `matches` / `matchFlags` / `search` (lookbehind inclus).
`engineName()` / `hasPcre2()` exposent le backend actif.

Surface façon Nim `re` / Crystal `Regex` :

| Fonction | Rôle |
|----------|------|
| `matches(text, pattern)` | Correspondance ancrée (texte entier) |
| `matchFlags(text, pattern, flags)` | Idem avec drapeaux `i` / `m` |
| `search(text, pattern)` | Cherche une sous-chaîne |
| `find(text, pattern)` | Premier match (ou `""`) |
| `findAll(text, pattern)` | Liste de tous les matches |
| `captures(text, pattern)` | Groupes capturants du 1er match |
| `captureNamed(text, pattern, name)` | Groupe nommé `(?<name>...)` du 1er match |
| `namedGroupIndex(pattern, name)` | Index 1-based du groupe nommé (0 si absent) |
| `count(text, pattern)` | Nombre de matches |
| `split(text, pattern)` | Découpe sur le motif |
| `replace` / `replaceFirst` | Remplacement global / premier |

Le lookahead `(?=)` / `(?!)` est supporté sur les deux backends ; le **lookbehind**
`(?<=)` / `(?<!)` nécessite PCRE2 (`hasPcre2()`). Les groupes nommés sont émulés
côté `std::regex` (toujours via le chemin `captureNamed`).

Tests : `tests/stdlib/re.afr`

## `std/crypto`

OpenSSL : `sha256` / `sha512` / `sha1` / `sha3_256`, `sha256File`, `hmacSha256`, `randomBytes` / `randomHex`, `hexEncode` / `hexDecode`, `aesGcmEncrypt` / `aesGcmDecrypt` (hex packed nonce||tag||ciphertext).

Signatures **Ed25519** (clés/signatures en hex) : `ed25519GenPrivate`, `ed25519PublicFromPrivate`, `ed25519Sign(privHex, message)`, `ed25519Verify(pubHex, message, sigHex)`.

Tests : `tests/stdlib/crypto.afr`

## `std/process`

Spawn sans shell (style Go `os/exec` / Python `subprocess`) : `run`, `runCmd`, `captureStdout`, `captureCombined`, `getPid`, `exitWith`.  
`runShell` uniquement si `AFRILANG_INSECURE=1` (sinon retourne `-2`).

Tests : `tests/stdlib/process.afr`

## `std/net`

TCP : `tcpConnect`, `tcpListen`, `tcpAccept`, `tcpRead`, `tcpWrite`, `tcpClose`.  
HTTP : `httpServe` (bloquant), `httpServeOnce`, parse (`httpRequestMethod` /
`httpRequestPath` / `httpRequestBody`), `httpServeTlsOnce` (cert/key PEM, OpenSSL).
Routage : module `web` — `createRouter` / `addRoute` / `dispatch` /
`httpServeOnceRouted` / `httpServeRouted(port, router, maxRequests)` /
`httpRoundTripRouted` / `httpRoundTripRoutedN` (tests).

Tests : `tests/stdlib/net.afr`, `tests/stdlib/web.afr`.

## `std/json`

Parseur conforme (échappements `\uXXXX` + surrogates, `\b`/`\f`/`\r`, notation scientifique) :

| Fonction | Rôle |
|----------|------|
| `makeObject(key, value)` | Objet simple |
| `parse(text)` / `stringify(doc)` | Sérialisation |
| `stringifyPretty(doc, indent)` | Sérialisation indentée |
| `getString` / `getNumber` / `getInt` / `getBool` | Lecture typée |
| `has(doc, key)` | Présence d'une clé |
| `arrayLength(doc)` / `arrayGet(doc, i)` | Accès tableau |
| `getPath(doc, "a.b.c")` | Navigation par chemin pointé |

Tests : `tests/stdlib/json.afr`

## `std/yaml`

Sous-ensemble YAML **bloc** (zéro-dép) : mappings et séquences imbriqués, scalaires (bool/number/string/null). La valeur renvoyée est un `json` (utiliser les accesseurs `std/json`). `parse(text)` → `json`, `stringify(doc)` → YAML indenté.

Non supporté : flow style `{}`/`[]` (hors vides), ancres/alias, scalaires bloc `|`/`>`, documents multiples.

Tests : `tests/stdlib/yaml.afr`

## `std/datetime`

Horodatage UTC + fuseaux IANA (native) :

| Fonction | Rôle |
|----------|------|
| `nowSeconds` / `nowMs` | Instant courant |
| `parseIso(text)` | ISO-8601 (`Z` ou `+HH:MM`) vers epoch secondes |
| `formatIso(seconds)` / `formatIsoOffset(seconds, offsetMinutes)` | Formatage |
| `year/month/day/hour/minute/second(seconds)` | Décomposition |
| `weekday(seconds)` | Jour de semaine (0 = dimanche) |
| `addSeconds` / `addDays` | Arithmétique |
| `diffSeconds(a, b)` | Écart absolu |
| `zoneOffsetStandard(name)` | Offset d'hiver (table ~45 zones) |
| `zoneOffsetAt(name, seconds)` | Offset **DST-aware** (zoneinfo POSIX native) |
| `zoneOffset(name)` | Offset à « maintenant » (DST-aware native) |
| `formatInZone(seconds, zoneName)` | Formatage DST-aware |

Sur native Linux/macOS, `zoneOffsetAt` / `formatInZone` lisent `/usr/share/zoneinfo`
(DST inclus). Sur WASM : table standard uniquement. Zone inconnue :
`zoneOffset*` → `-100000`, `formatInZone` → `""`.

Tests : `tests/stdlib/datetime.afr`

## `std/thread`

Threads utilitaires + primitives de synchronisation (natif, `-pthread`) :

| Fonction | Rôle |
|----------|------|
| `spawnSleep(ms)` / `join(id)` / `sleepMs(ms)` | Threads de temporisation |
| `hardwareConcurrency()` | Cœurs disponibles |
| `mutexNew()` / `mutexLock(id)` / `mutexUnlock(id)` | Exclusion mutuelle |
| `chanNewText()` / `chanNewNumber()` | Canaux FIFO typés |
| `chanSendText/Number(id, v)` | Envoi (tamponné) |
| `chanRecvText/Number(id)` | Réception (bloquante) |
| `chanClose(id)` | Fermeture |

Tests : `tests/stdlib/thread.afr`

## `std/fs`

| Fonction | Rôle |
|----------|------|
| `listDir` / `makeDir` / `removeFile` / `fileSize` | Contenu / taille |
| `exists` / `isFile` / `isDir` | Prédicats |
| `readText` / `writeText` | Lecture / écriture texte |
| `copyFile` / `renameFile` | Copie / renommage |

Tests : `tests/stdlib/fs.afr`

## `std/path`

| Fonction | Rôle |
|----------|------|
| `join` / `basename` / `dirname` / `extension` | Composition |
| `isAbsolute` / `normalize` / `absolute` | Forme |

Tests : `tests/stdlib/path.afr`

## `std/env`

| Fonction | Rôle |
|----------|------|
| `get(name)` / `has(name)` / `set(name, value)` | Variables d'environnement |

Tests : `tests/stdlib/env.afr`

## `std/unicode`

Utilitaires UTF-8 orientés points de code (zéro-dép, WASM-compatible). Le module `str` reste orienté **octets**.

| Fonction | Rôle |
|----------|------|
| `byteLength(s)` | Longueur en octets |
| `codepointCount(s)` | Nombre de points de code |
| `graphemeCount(s)` | Graphèmes (simplifié : base + marques combinantes + ZWJ) |
| `codepointAt(s, i)` | Point de code à l'index (−1 hors limites) |
| `charAt(s, i)` | Caractère à l'index (codepoints) |
| `slice(s, start, end)` | Sous-chaîne par points de code |
| `reverse(s)` | Inversion par points de code |
| `isValidUtf8(s)` | Validité UTF-8 |
| `codepoints(s)` | Liste des points de code |
| `isSpace(cp)` / `isAsciiLetter(cp)` / `isAsciiDigit(cp)` | Prédicats |

Hors périmètre (zéro-dép) : normalisation NFC/NFD et catégories Unicode complètes (grosses tables de données). `graphemeCount` ne couvre pas toutes les règles UAX #29 (ex. indicateurs régionaux).

Tests : `tests/stdlib/unicode.afr`

## WASM

Compatibles wasm32 (voir `WASM_COMPAT.md`) : `str`, `math`, `stats`, `proba`, `random`, `json`, `collections`, `path`, `log`, `async` (subset), `re`, `datetime`, `yaml`, `unicode`.  
Natif seulement : `fs`/`io` fichiers, `http`, `crypto`, `process`, `net`, `ui`, `game*`.

Démo : `examples/tier8_stdlib.afr` · `examples/math_stats_proba_demo.afr`

## Hors portée (volontairement)

- **SciPy.stats**, **Distributions.jl**, packs CRAN entiers : écosystèmes énormes, pas des stdlibs.
- Objets mutables type Nim `RunningStat` (pas de type opaque dédié en AFRILANG 1.x) — équivalents batch fournis.
- Nombres complexes / rationnels (modules séparés possibles plus tard).
