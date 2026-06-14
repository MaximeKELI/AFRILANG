# Bibliothèques simples AFRILANG

**151 modules** importables via `import "std/nom"` puis `use nom`.

## std/absnum

`import "std/absnum"` · `use absnum`

- `absNumber(n number) → number`
- `absDiff(a number, b number) → number`

## std/sqrtlib

`import "std/sqrtlib"` · `use sqrtlib`

- `sqrtNumber(n number) → number`
- `square(n number) → number`

## std/cbrtlib

`import "std/cbrtlib"` · `use cbrtlib`

- `cbrtNumber(n number) → number`
- `cube(n number) → number`

## std/min2

`import "std/min2"` · `use min2`

- `min2(a number, b number) → number`
- `min3(a number, b number, c number) → number`

## std/max2

`import "std/max2"` · `use max2`

- `max2(a number, b number) → number`
- `max3(a number, b number, c number) → number`

## std/clamp

`import "std/clamp"` · `use clamp`

- `clamp(n number, lo number, hi number) → number`
- `clamp01(n number) → number`

## std/lerp

`import "std/lerp"` · `use lerp`

- `lerp(a number, b number, t number) → number`
- `inverseLerp(a number, b number, v number) → number`

## std/sign

`import "std/sign"` · `use sign`

- `sign(n number) → number`
- `isPositive(n number) → bool`

## std/parity

`import "std/parity"` · `use parity`

- `isEven(n number) → bool`
- `isOdd(n number) → bool`

## std/trig

`import "std/trig"` · `use trig`

- `sinDeg(deg number) → number`
- `cosDeg(deg number) → number`

## std/trig2

`import "std/trig2"` · `use trig2`

- `tanDeg(deg number) → number`
- `cotDeg(deg number) → number`

## std/arc

`import "std/arc"` · `use arc`

- `asinSafe(n number) → number`
- `acosSafe(n number) → number`

## std/hyper

`import "std/hyper"` · `use hyper`

- `sinhN(n number) → number`
- `coshN(n number) → number`

## std/deg

`import "std/deg"` · `use deg`

- `degToRad(d number) → number`
- `radToDeg(r number) → number`

## std/roundlib

`import "std/roundlib"` · `use roundlib`

- `roundN(n number) → number`
- `truncN(n number) → number`

## std/modlib

`import "std/modlib"` · `use modlib`

- `mod(a number, b number) → number`
- `wrap(n number, lo number, hi number) → number`

## std/gcdlib

`import "std/gcdlib"` · `use gcdlib`

- `gcd(a number, b number) → number`
- `lcm(a number, b number) → number`

## std/fact

`import "std/fact"` · `use fact`

- `factorial(n number) → number`
- `doubleFact(n number) → number`

## std/fib

`import "std/fib"` · `use fib`

- `fib(n number) → number`
- `fibB(n number) → number`

## std/prime

`import "std/prime"` · `use prime`

- `isPrime(n number) → bool`
- `nextPrime(n number) → number`

## std/mean

`import "std/mean"` · `use mean`

- `mean2(a number, b number) → number`
- `mean3(a number, b number, c number) → number`

## std/percent

`import "std/percent"` · `use percent`

- `percent(part number, whole number) → number`
- `percentChange(oldVal number, newVal number) → number`

## std/ratio

`import "std/ratio"` · `use ratio`

- `ratio(a number, b number) → number`
- `proportion(a number, b number, total number) → number`

## std/dice

`import "std/dice"` · `use dice`

- `roll(sides number) → number`
- `roll2d6(ignored number) → number`

## std/coin

`import "std/coin"` · `use coin`

- `flip(ignored number) → bool`
- `flipN(n number) → number`

## std/upper

`import "std/upper"` · `use upper`

- `toUpper(s text) → text`
- `toLower(s text) → text`

## std/capitalize

`import "std/capitalize"` · `use capitalize`

- `capitalize(s text) → text`
- `titleWord(s text) → text`

## std/prefix

`import "std/prefix"` · `use prefix`

- `startsWith(s text, prefix text) → bool`
- `endsWith(s text, suffix text) → bool`

## std/repeat

`import "std/repeat"` · `use repeat`

- `repeatText(s text, n number) → text`
- `repeatChar(c text, n number) → text`

## std/pad

`import "std/pad"` · `use pad`

- `padLeft(s text, n number, ch text) → text`
- `padRight(s text, n number, ch text) → text`

## std/reverse

`import "std/reverse"` · `use reverse`

- `reverseText(s text) → text`
- `reverseWords(s text) → text`

## std/textlen

`import "std/textlen"` · `use textlen`

- `length(s text) → number`
- `isEmpty(s text) → bool`

## std/concat

`import "std/concat"` · `use concat`

- `concat2(a text, b text) → text`
- `concat3(a text, b text, c text) → text`

## std/compare

`import "std/compare"` · `use compare`

- `equals(a text, b text) → bool`
- `equalsIgnoreCase(a text, b text) → bool`

## std/celsius

`import "std/celsius"` · `use celsius`

- `cToF(c number) → number`
- `fToC(f number) → number`

## std/kelvin

`import "std/kelvin"` · `use kelvin`

- `cToK(c number) → number`
- `kToC(k number) → number`

## std/distance

`import "std/distance"` · `use distance`

- `kmToMiles(km number) → number`
- `milesToKm(mi number) → number`

## std/weight

`import "std/weight"` · `use weight`

- `kgToLb(kg number) → number`
- `lbToKg(lb number) → number`

## std/bytes

`import "std/bytes"` · `use bytes`

- `bytesToKb(b number) → number`
- `kbToMb(kb number) → number`

## std/timeconv

`import "std/timeconv"` · `use timeconv`

- `secToMin(s number) → number`
- `minToHour(m number) → number`

## std/msconv

`import "std/msconv"` · `use msconv`

- `msToSec(ms number) → number`
- `secToMs(s number) → number`

## std/angle

`import "std/angle"` · `use angle`

- `normalizeAngle(d number) → number`
- `angleDiff(a number, b number) → number`

## std/hex

`import "std/hex"` · `use hex`

- `toHex(n number) → text`
- `fromHex(s text) → number`

## std/binary

`import "std/binary"` · `use binary`

- `toBinary(n number) → text`
- `fromBinary(s text) → number`

## std/octal

`import "std/octal"` · `use octal`

- `toOctal(n number) → text`
- `fromOctal(s text) → number`

## std/rot13

`import "std/rot13"` · `use rot13`

- `rot13(s text) → text`
- `rot47(s text) → text`

## std/hash

`import "std/hash"` · `use hash`

- `hashText(s text) → number`
- `hashNumber(n number) → number`

## std/checksum

`import "std/checksum"` · `use checksum`

- `xorChecksum(s text) → number`
- `sumBytes(s text) → number`

## std/slug

`import "std/slug"` · `use slug`

- `slugify(s text) → text`
- `deslugify(s text) → text`

## std/email

`import "std/email"` · `use email`

- `isEmail(s text) → bool`
- `domainOf(s text) → text`

## std/phone

`import "std/phone"` · `use phone`

- `isPhone(s text) → bool`
- `digitsOnly(s text) → text`

## std/ipv4

`import "std/ipv4"` · `use ipv4`

- `isIpv4(s text) → bool`
- `countDots(s text) → number`

## std/html

`import "std/html"` · `use html`

- `escapeHtml(s text) → text`
- `unescapeHtml(s text) → text`

## std/point

`import "std/point"` · `use point`

- `distance2d(x1 number, y1 number, x2 number, y2 number) → number`
- `midpointX(x1 number, x2 number) → number`

## std/rect

`import "std/rect"` · `use rect`

- `area(w number, h number) → number`
- `perimeter(w number, h number) → number`

## std/circle

`import "std/circle"` · `use circle`

- `area(r number) → number`
- `circumference(r number) → number`

## std/triangle

`import "std/triangle"` · `use triangle`

- `areaBaseHeight(b number, h number) → number`
- `heron(a number, b number, c number) → number`

## std/vector2

`import "std/vector2"` · `use vector2`

- `dot2(x1 number, y1 number, x2 number, y2 number) → number`
- `length2(x number, y number) → number`

## std/collision

`import "std/collision"` · `use collision`

- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`
- `rectsOverlap(x1 number, y1 number, w1 number, h1 number, x2 number, y2 number, w2 number, h2 number) → bool`

## std/color

`import "std/color"` · `use color`

- `rgb(r number, g number, b number) → number`
- `redOf(packed number) → number`

## std/easing

`import "std/easing"` · `use easing`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/noise

`import "std/noise"` · `use noise`

- `noise1D(x number) → number`
- `noise2D(x number, y number) → number`

## std/semver

`import "std/semver"` · `use semver`

- `parseMajor(s text) → number`
- `bumpMajor(s text) → text`

## std/validate

`import "std/validate"` · `use validate`

- `isAlpha(s text) → bool`
- `isDigit(s text) → bool`

## std/parse

`import "std/parse"` · `use parse`

- `parseInt(s text) → number`
- `parseFloat(s text) → number`

## std/format

`import "std/format"` · `use format`

- `formatNumber(n number, decimals number) → text`
- `formatPercent(n number) → text`

## std/currency

`import "std/currency"` · `use currency`

- `formatEuro(n number) → text`
- `formatDollar(n number) → text`

## std/stopwatch

`import "std/stopwatch"` · `use stopwatch`

- `nowMs(ignored number) → number`
- `elapsedMs(start number) → number`

## std/bits

`import "std/bits"` · `use bits`

- `bitAnd(a number, b number) → number`
- `bitOr(a number, b number) → number`

## std/shift

`import "std/shift"` · `use shift`

- `shl(n number, b number) → number`
- `shr(n number, b number) → number`

## std/flags

`import "std/flags"` · `use flags`

- `hasFlag(n number, f number) → bool`
- `setFlag(n number, f number) → number`

## std/order

`import "std/order"` · `use order`

- `cmpNumber(a number, b number) → number`
- `cmpText(a text, b text) → number`

## std/range

`import "std/range"` · `use range`

- `inRange(n number, lo number, hi number) → bool`
- `rangeSize(lo number, hi number) → number`

## std/seq

`import "std/seq"` · `use seq`

- `arithmetic(a number, d number, n number) → number`
- `geometric(a number, r number, n number) → number`

## std/loglib

`import "std/loglib"` · `use loglib`

- `log10(n number) → number`
- `log2(n number) → number`

## std/powlib

`import "std/powlib"` · `use powlib`

- `pow2(n number) → number`
- `pow10(n number) → number`

## std/hypot

`import "std/hypot"` · `use hypot`

- `hypot2(a number, b number) → number`
- `hypot3(a number, b number, c number) → number`

## std/stats2

`import "std/stats2"` · `use stats2`

- `sum2(a number, b number) → number`
- `product2(a number, b number) → number`

## std/stats3

`import "std/stats3"` · `use stats3`

- `sum3(a number, b number, c number) → number`
- `product3(a number, b number, c number) → number`

## std/diff

`import "std/diff"` · `use diff`

- `delta(a number, b number) → number`
- `absDelta(a number, b number) → number`

## std/avg

`import "std/avg"` · `use avg`

- `avg4(a number, b number, c number, d number) → number`
- `avg5(a number, b number, c number, d number, e number) → number`

## std/margin

`import "std/margin"` · `use margin`

- `margin(cost number, price number) → number`
- `markup(cost number, price number) → number`

## std/tax

`import "std/tax"` · `use tax`

- `addTax(amount number, rate number) → number`
- `taxAmount(amount number, rate number) → number`

## std/discount

`import "std/discount"` · `use discount`

- `applyDiscount(price number, rate number) → number`
- `discountAmount(price number, rate number) → number`

## std/interest

`import "std/interest"` · `use interest`

- `simpleInterest(principal number, rate number, years number) → number`
- `compoundOnce(principal number, rate number) → number`

## std/loan

`import "std/loan"` · `use loan`

- `monthlyPayment(principal number, rate number, months number) → number`
- `totalPaid(payment number, months number) → number`

## std/speed

`import "std/speed"` · `use speed`

- `kmhToMs(kmh number) → number`
- `msToKmh(ms number) → number`

## std/volume

`import "std/volume"` · `use volume`

- `litersToMl(l number) → number`
- `mlToLiters(ml number) → number`

## std/area_conv

`import "std/area_conv"` · `use area_conv`

- `m2ToCm2(m2 number) → number`
- `cm2ToM2(cm2 number) → number`

## std/pressure

`import "std/pressure"` · `use pressure`

- `barToPsi(bar number) → number`
- `psiToBar(psi number) → number`

## std/energy

`import "std/energy"` · `use energy`

- `joulesToCal(j number) → number`
- `calToJoules(cal number) → number`

## std/bmi

`import "std/bmi"` · `use bmi`

- `bmi(kg number, m number) → number`
- `bmiCategory(bmi number) → text`

## std/geo

`import "std/geo"` · `use geo`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `midLat(a number, b number) → number`

## std/compass

`import "std/compass"` · `use compass`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `cardinal(deg number) → text`

## std/uuid

`import "std/uuid"` · `use uuid`

- `randomHex(n number) → text`
- `simpleId(ignored number) → text`

## std/counter

`import "std/counter"` · `use counter`

- `nextId(ignored number) → number`
- `resetId(ignored number) → number`

## std/env

`import "std/env"` · `use env`

- `getEnv(key text) → text`
- `hasEnv(key text) → bool`

## std/platform

`import "std/platform"` · `use platform`

- `osName(ignored number) → text`
- `archName(ignored number) → text`

## std/pathutil

`import "std/pathutil"` · `use pathutil`

- `normalizeSlashes(s text) → text`
- `hasTrailingSlash(s text) → bool`

## std/url

`import "std/url"` · `use url`

- `urlEncodeSpace(s text) → text`
- `urlDecodeSpace(s text) → text`

## std/csv

`import "std/csv"` · `use csv`

- `splitCsv2(line text) → text`
- `splitCsvRest(line text) → text`

## std/jsonlite

`import "std/jsonlite"` · `use jsonlite`

- `quote(s text) → text`
- `pair(key text, value text) → text`

## std/xml

`import "std/xml"` · `use xml`

- `tag(name text, content text) → text`
- `escapeXml(s text) → text`

## std/markdown

`import "std/markdown"` · `use markdown`

- `bold(s text) → text`
- `italic(s text) → text`

## std/password

`import "std/password"` · `use password`

- `strengthScore(s text) → number`
- `isStrong(s text) → bool`

## std/base64

`import "std/base64"` · `use base64`

- `encode64(s text) → text`
- `decode64(s text) → text`

## std/mime

`import "std/mime"` · `use mime`

- `isTextPlain(mime text) → bool`
- `isJson(mime text) → bool`

## std/httpcode

`import "std/httpcode"` · `use httpcode`

- `isSuccess(code number) → bool`
- `isRedirect(code number) → bool`

## std/game

`import "std/game"` · `use game`

- `scoreBonus(score number, level number) → number`
- `levelFromXp(xp number) → number`

## std/music

`import "std/music"` · `use music`

- `midiNote(octave number, note number) → number`
- `freqA4(ignored number) → number`

## std/color2

`import "std/color2"` · `use color2`

- `lerpColor(a number, b number, t number) → number`
- `invertRgb(packed number) → number`

## std/matrix2

`import "std/matrix2"` · `use matrix2`

- `det2(a number, b number, c number, d number) → number`
- `trace2(a number, d number) → number`

## std/physics

`import "std/physics"` · `use physics`

- `force(m number, a number) → number`
- `kineticEnergy(m number, v number) → number`

## std/chemistry

`import "std/chemistry"` · `use chemistry`

- `moles(mass number, molarMass number) → number`
- `mass(moles number, molarMass number) → number`

## std/units

`import "std/units"` · `use units`

- `inchToCm(inch number) → number`
- `cmToInch(cm number) → number`

## std/paper

`import "std/paper"` · `use paper`

- `a4WidthCm(ignored number) → number`
- `a4HeightCm(ignored number) → number`

## std/roman

`import "std/roman"` · `use roman`

- `toRoman(n number) → text`
- `fromRoman(s text) → number`

## std/spell

`import "std/spell"` · `use spell`

- `spellDigit(n number) → text`
- `spellBool(b bool) → text`

## std/listutil

`import "std/listutil"` · `use listutil`

- `firstIndex(ignored number) → number`
- `lastIndex(count number) → number`

## std/queue

`import "std/queue"` · `use queue`

- `wrapIndex(i number, size number) → number`
- `nextIndex(i number, size number) → number`

## std/stackutil

`import "std/stackutil"` · `use stackutil`

- `peekOffset(size number, offset number) → number`
- `isEmptyStack(size number) → bool`

## std/graph

`import "std/graph"` · `use graph`

- `edgeKey(a number, b number) → number`
- `selfLoop(a number, b number) → bool`

## std/search

`import "std/search"` · `use search`

- `binarySteps(n number) → number`
- `linearWorst(n number) → number`

## std/sortkey

`import "std/sortkey"` · `use sortkey`

- `ascKey(n number) → number`
- `descKey(n number) → number`

## std/textwrap

`import "std/textwrap"` · `use textwrap`

- `truncate(s text, n number) → text`
- `ellipsize(s text, n number) → text`

## std/whitespace

`import "std/whitespace"` · `use whitespace`

- `collapseSpaces(s text) → text`
- `isWhitespace(s text) → bool`

## std/charutil

`import "std/charutil"` · `use charutil`

- `charCode(s text) → number`
- `fromCharCode(n number) → text`

## std/version

`import "std/version"` · `use version`

- `compareMajor(a text, b text) → number`
- `sameMajor(a text, b text) → bool`

## std/config

`import "std/config"` · `use config`

- `parseBool(s text) → bool`
- `boolToText(b bool) → text`

## std/retry

`import "std/retry"` · `use retry`

- `backoffMs(attempt number) → number`
- `shouldRetry(attempt number, max number) → bool`

## std/ratelimit

`import "std/ratelimit"` · `use ratelimit`

- `allowBurst(count number, limit number) → bool`
- `tokensLeft(count number, limit number) → number`

## std/cache

`import "std/cache"` · `use cache`

- `ttlExpired(ageMs number, ttlMs number) → bool`
- `freshness(ageMs number, ttlMs number) → number`

## std/id

`import "std/id"` · `use id`

- `hashId(s text) → text`
- `shortHash(s text) → text`

## std/locale

`import "std/locale"` · `use locale`

- `decimalComma(s text) → text`
- `decimalDot(s text) → text`

## std/calendar

`import "std/calendar"` · `use calendar`

- `daysInYear(ignored number) → number`
- `isLeap(year number) → bool`

## std/weekday

`import "std/weekday"` · `use weekday`

- `weekIndex(day number) → number`
- `isWeekendIndex(day number) → bool`

## std/timezone

`import "std/timezone"` · `use timezone`

- `utcOffsetHours(ignored number) → number`
- `localHour(utcHour number) → number`

## std/network

`import "std/network"` · `use network`

- `isPortValid(port number) → bool`
- `isLocalhost(host text) → bool`

## std/dns

`import "std/dns"` · `use dns`

- `isValidHostname(s text) → bool`
- `hasSubdomain(s text) → bool`

## std/socket

`import "std/socket"` · `use socket`

- `portPairKey(a number, b number) → number`
- `isEphemeralPort(port number) → bool`

## std/process

`import "std/process"` · `use process`

- `exitOk(code number) → bool`
- `exitFailed(code number) → bool`

## std/shell

`import "std/shell"` · `use shell`

- `quoteShell(s text) → text`
- `escapeShell(s text) → text`

## std/memory

`import "std/memory"` · `use memory`

- `kbFromBytes(b number) → number`
- `mbFromBytes(b number) → number`

## std/cpu

`import "std/cpu"` · `use cpu`

- `clampUsage(pct number) → number`
- `isHighLoad(pct number) → bool`

## std/disk

`import "std/disk"` · `use disk`

- `usagePercent(used number, total number) → number`
- `freeSpace(used number, total number) → number`

## std/security

`import "std/security"` · `use security`

- `maskSecret(s text) → text`
- `isMasked(s text) → bool`

## std/audit

`import "std/audit"` · `use audit`

- `auditLine(action text, user text) → text`
- `timestampPrefix(msg text) → text`

## std/tmpl

`import "std/tmpl"` · `use tmpl`

- `fill(pattern text, value text) → text`
- `fill2(pattern text, a text, b text) → text`

## std/i18n

`import "std/i18n"` · `use i18n`

- `greetFr(name text) → text`
- `greetEn(name text) → text`

## std/education

`import "std/education"` · `use education`

- `gradeLetter(score number) → text`
- `passed(score number, min number) → bool`

## std/quiz

`import "std/quiz"` · `use quiz`

- `scorePercent(correct number, total number) → number`
- `isPerfect(correct number, total number) → bool`
