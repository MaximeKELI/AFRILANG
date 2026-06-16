# Bibliothèques simples AFRILANG

**651 modules** importables via `import "std/nom"` puis `use nom`.

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
- `xpForScore(score number) → number`
- `speedMsForLevel(level number) → number`

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

## std/gamekit001

`import "std/gamekit001"` · `use gamekit001`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit002

`import "std/gamekit002"` · `use gamekit002`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit003

`import "std/gamekit003"` · `use gamekit003`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit004

`import "std/gamekit004"` · `use gamekit004`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit005

`import "std/gamekit005"` · `use gamekit005`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit006

`import "std/gamekit006"` · `use gamekit006`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit007

`import "std/gamekit007"` · `use gamekit007`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit008

`import "std/gamekit008"` · `use gamekit008`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit009

`import "std/gamekit009"` · `use gamekit009`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit010

`import "std/gamekit010"` · `use gamekit010`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit011

`import "std/gamekit011"` · `use gamekit011`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit012

`import "std/gamekit012"` · `use gamekit012`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit013

`import "std/gamekit013"` · `use gamekit013`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit014

`import "std/gamekit014"` · `use gamekit014`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit015

`import "std/gamekit015"` · `use gamekit015`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit016

`import "std/gamekit016"` · `use gamekit016`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit017

`import "std/gamekit017"` · `use gamekit017`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit018

`import "std/gamekit018"` · `use gamekit018`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit019

`import "std/gamekit019"` · `use gamekit019`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit020

`import "std/gamekit020"` · `use gamekit020`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit021

`import "std/gamekit021"` · `use gamekit021`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit022

`import "std/gamekit022"` · `use gamekit022`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit023

`import "std/gamekit023"` · `use gamekit023`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit024

`import "std/gamekit024"` · `use gamekit024`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit025

`import "std/gamekit025"` · `use gamekit025`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit026

`import "std/gamekit026"` · `use gamekit026`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit027

`import "std/gamekit027"` · `use gamekit027`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit028

`import "std/gamekit028"` · `use gamekit028`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit029

`import "std/gamekit029"` · `use gamekit029`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit030

`import "std/gamekit030"` · `use gamekit030`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit031

`import "std/gamekit031"` · `use gamekit031`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit032

`import "std/gamekit032"` · `use gamekit032`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit033

`import "std/gamekit033"` · `use gamekit033`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit034

`import "std/gamekit034"` · `use gamekit034`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit035

`import "std/gamekit035"` · `use gamekit035`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit036

`import "std/gamekit036"` · `use gamekit036`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit037

`import "std/gamekit037"` · `use gamekit037`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit038

`import "std/gamekit038"` · `use gamekit038`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit039

`import "std/gamekit039"` · `use gamekit039`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit040

`import "std/gamekit040"` · `use gamekit040`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit041

`import "std/gamekit041"` · `use gamekit041`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit042

`import "std/gamekit042"` · `use gamekit042`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit043

`import "std/gamekit043"` · `use gamekit043`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit044

`import "std/gamekit044"` · `use gamekit044`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit045

`import "std/gamekit045"` · `use gamekit045`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit046

`import "std/gamekit046"` · `use gamekit046`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit047

`import "std/gamekit047"` · `use gamekit047`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit048

`import "std/gamekit048"` · `use gamekit048`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit049

`import "std/gamekit049"` · `use gamekit049`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit050

`import "std/gamekit050"` · `use gamekit050`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit051

`import "std/gamekit051"` · `use gamekit051`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit052

`import "std/gamekit052"` · `use gamekit052`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit053

`import "std/gamekit053"` · `use gamekit053`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit054

`import "std/gamekit054"` · `use gamekit054`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit055

`import "std/gamekit055"` · `use gamekit055`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit056

`import "std/gamekit056"` · `use gamekit056`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit057

`import "std/gamekit057"` · `use gamekit057`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit058

`import "std/gamekit058"` · `use gamekit058`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit059

`import "std/gamekit059"` · `use gamekit059`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit060

`import "std/gamekit060"` · `use gamekit060`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit061

`import "std/gamekit061"` · `use gamekit061`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit062

`import "std/gamekit062"` · `use gamekit062`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit063

`import "std/gamekit063"` · `use gamekit063`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit064

`import "std/gamekit064"` · `use gamekit064`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit065

`import "std/gamekit065"` · `use gamekit065`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit066

`import "std/gamekit066"` · `use gamekit066`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit067

`import "std/gamekit067"` · `use gamekit067`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit068

`import "std/gamekit068"` · `use gamekit068`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit069

`import "std/gamekit069"` · `use gamekit069`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit070

`import "std/gamekit070"` · `use gamekit070`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit071

`import "std/gamekit071"` · `use gamekit071`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit072

`import "std/gamekit072"` · `use gamekit072`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit073

`import "std/gamekit073"` · `use gamekit073`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit074

`import "std/gamekit074"` · `use gamekit074`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit075

`import "std/gamekit075"` · `use gamekit075`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit076

`import "std/gamekit076"` · `use gamekit076`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit077

`import "std/gamekit077"` · `use gamekit077`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit078

`import "std/gamekit078"` · `use gamekit078`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit079

`import "std/gamekit079"` · `use gamekit079`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit080

`import "std/gamekit080"` · `use gamekit080`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit081

`import "std/gamekit081"` · `use gamekit081`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit082

`import "std/gamekit082"` · `use gamekit082`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit083

`import "std/gamekit083"` · `use gamekit083`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit084

`import "std/gamekit084"` · `use gamekit084`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit085

`import "std/gamekit085"` · `use gamekit085`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit086

`import "std/gamekit086"` · `use gamekit086`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit087

`import "std/gamekit087"` · `use gamekit087`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit088

`import "std/gamekit088"` · `use gamekit088`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit089

`import "std/gamekit089"` · `use gamekit089`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit090

`import "std/gamekit090"` · `use gamekit090`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit091

`import "std/gamekit091"` · `use gamekit091`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit092

`import "std/gamekit092"` · `use gamekit092`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit093

`import "std/gamekit093"` · `use gamekit093`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit094

`import "std/gamekit094"` · `use gamekit094`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit095

`import "std/gamekit095"` · `use gamekit095`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit096

`import "std/gamekit096"` · `use gamekit096`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit097

`import "std/gamekit097"` · `use gamekit097`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit098

`import "std/gamekit098"` · `use gamekit098`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit099

`import "std/gamekit099"` · `use gamekit099`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit100

`import "std/gamekit100"` · `use gamekit100`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit101

`import "std/gamekit101"` · `use gamekit101`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit102

`import "std/gamekit102"` · `use gamekit102`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit103

`import "std/gamekit103"` · `use gamekit103`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit104

`import "std/gamekit104"` · `use gamekit104`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit105

`import "std/gamekit105"` · `use gamekit105`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit106

`import "std/gamekit106"` · `use gamekit106`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit107

`import "std/gamekit107"` · `use gamekit107`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit108

`import "std/gamekit108"` · `use gamekit108`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit109

`import "std/gamekit109"` · `use gamekit109`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit110

`import "std/gamekit110"` · `use gamekit110`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit111

`import "std/gamekit111"` · `use gamekit111`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit112

`import "std/gamekit112"` · `use gamekit112`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit113

`import "std/gamekit113"` · `use gamekit113`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit114

`import "std/gamekit114"` · `use gamekit114`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit115

`import "std/gamekit115"` · `use gamekit115`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit116

`import "std/gamekit116"` · `use gamekit116`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit117

`import "std/gamekit117"` · `use gamekit117`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit118

`import "std/gamekit118"` · `use gamekit118`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit119

`import "std/gamekit119"` · `use gamekit119`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit120

`import "std/gamekit120"` · `use gamekit120`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit121

`import "std/gamekit121"` · `use gamekit121`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit122

`import "std/gamekit122"` · `use gamekit122`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit123

`import "std/gamekit123"` · `use gamekit123`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit124

`import "std/gamekit124"` · `use gamekit124`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit125

`import "std/gamekit125"` · `use gamekit125`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit126

`import "std/gamekit126"` · `use gamekit126`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit127

`import "std/gamekit127"` · `use gamekit127`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit128

`import "std/gamekit128"` · `use gamekit128`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit129

`import "std/gamekit129"` · `use gamekit129`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit130

`import "std/gamekit130"` · `use gamekit130`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit131

`import "std/gamekit131"` · `use gamekit131`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit132

`import "std/gamekit132"` · `use gamekit132`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit133

`import "std/gamekit133"` · `use gamekit133`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit134

`import "std/gamekit134"` · `use gamekit134`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit135

`import "std/gamekit135"` · `use gamekit135`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit136

`import "std/gamekit136"` · `use gamekit136`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit137

`import "std/gamekit137"` · `use gamekit137`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit138

`import "std/gamekit138"` · `use gamekit138`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit139

`import "std/gamekit139"` · `use gamekit139`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit140

`import "std/gamekit140"` · `use gamekit140`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit141

`import "std/gamekit141"` · `use gamekit141`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit142

`import "std/gamekit142"` · `use gamekit142`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit143

`import "std/gamekit143"` · `use gamekit143`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit144

`import "std/gamekit144"` · `use gamekit144`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit145

`import "std/gamekit145"` · `use gamekit145`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit146

`import "std/gamekit146"` · `use gamekit146`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit147

`import "std/gamekit147"` · `use gamekit147`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit148

`import "std/gamekit148"` · `use gamekit148`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit149

`import "std/gamekit149"` · `use gamekit149`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit150

`import "std/gamekit150"` · `use gamekit150`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit151

`import "std/gamekit151"` · `use gamekit151`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit152

`import "std/gamekit152"` · `use gamekit152`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit153

`import "std/gamekit153"` · `use gamekit153`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit154

`import "std/gamekit154"` · `use gamekit154`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit155

`import "std/gamekit155"` · `use gamekit155`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit156

`import "std/gamekit156"` · `use gamekit156`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit157

`import "std/gamekit157"` · `use gamekit157`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit158

`import "std/gamekit158"` · `use gamekit158`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit159

`import "std/gamekit159"` · `use gamekit159`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit160

`import "std/gamekit160"` · `use gamekit160`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit161

`import "std/gamekit161"` · `use gamekit161`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit162

`import "std/gamekit162"` · `use gamekit162`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit163

`import "std/gamekit163"` · `use gamekit163`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit164

`import "std/gamekit164"` · `use gamekit164`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit165

`import "std/gamekit165"` · `use gamekit165`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit166

`import "std/gamekit166"` · `use gamekit166`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit167

`import "std/gamekit167"` · `use gamekit167`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit168

`import "std/gamekit168"` · `use gamekit168`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit169

`import "std/gamekit169"` · `use gamekit169`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit170

`import "std/gamekit170"` · `use gamekit170`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit171

`import "std/gamekit171"` · `use gamekit171`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit172

`import "std/gamekit172"` · `use gamekit172`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit173

`import "std/gamekit173"` · `use gamekit173`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit174

`import "std/gamekit174"` · `use gamekit174`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit175

`import "std/gamekit175"` · `use gamekit175`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit176

`import "std/gamekit176"` · `use gamekit176`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit177

`import "std/gamekit177"` · `use gamekit177`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit178

`import "std/gamekit178"` · `use gamekit178`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit179

`import "std/gamekit179"` · `use gamekit179`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit180

`import "std/gamekit180"` · `use gamekit180`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit181

`import "std/gamekit181"` · `use gamekit181`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit182

`import "std/gamekit182"` · `use gamekit182`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit183

`import "std/gamekit183"` · `use gamekit183`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit184

`import "std/gamekit184"` · `use gamekit184`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit185

`import "std/gamekit185"` · `use gamekit185`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit186

`import "std/gamekit186"` · `use gamekit186`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit187

`import "std/gamekit187"` · `use gamekit187`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit188

`import "std/gamekit188"` · `use gamekit188`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit189

`import "std/gamekit189"` · `use gamekit189`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit190

`import "std/gamekit190"` · `use gamekit190`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit191

`import "std/gamekit191"` · `use gamekit191`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit192

`import "std/gamekit192"` · `use gamekit192`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit193

`import "std/gamekit193"` · `use gamekit193`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit194

`import "std/gamekit194"` · `use gamekit194`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit195

`import "std/gamekit195"` · `use gamekit195`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit196

`import "std/gamekit196"` · `use gamekit196`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit197

`import "std/gamekit197"` · `use gamekit197`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit198

`import "std/gamekit198"` · `use gamekit198`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit199

`import "std/gamekit199"` · `use gamekit199`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit200

`import "std/gamekit200"` · `use gamekit200`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit201

`import "std/gamekit201"` · `use gamekit201`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit202

`import "std/gamekit202"` · `use gamekit202`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit203

`import "std/gamekit203"` · `use gamekit203`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit204

`import "std/gamekit204"` · `use gamekit204`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit205

`import "std/gamekit205"` · `use gamekit205`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit206

`import "std/gamekit206"` · `use gamekit206`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit207

`import "std/gamekit207"` · `use gamekit207`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit208

`import "std/gamekit208"` · `use gamekit208`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit209

`import "std/gamekit209"` · `use gamekit209`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit210

`import "std/gamekit210"` · `use gamekit210`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit211

`import "std/gamekit211"` · `use gamekit211`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit212

`import "std/gamekit212"` · `use gamekit212`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit213

`import "std/gamekit213"` · `use gamekit213`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit214

`import "std/gamekit214"` · `use gamekit214`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit215

`import "std/gamekit215"` · `use gamekit215`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit216

`import "std/gamekit216"` · `use gamekit216`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit217

`import "std/gamekit217"` · `use gamekit217`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit218

`import "std/gamekit218"` · `use gamekit218`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit219

`import "std/gamekit219"` · `use gamekit219`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit220

`import "std/gamekit220"` · `use gamekit220`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit221

`import "std/gamekit221"` · `use gamekit221`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit222

`import "std/gamekit222"` · `use gamekit222`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit223

`import "std/gamekit223"` · `use gamekit223`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit224

`import "std/gamekit224"` · `use gamekit224`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit225

`import "std/gamekit225"` · `use gamekit225`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit226

`import "std/gamekit226"` · `use gamekit226`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit227

`import "std/gamekit227"` · `use gamekit227`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit228

`import "std/gamekit228"` · `use gamekit228`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit229

`import "std/gamekit229"` · `use gamekit229`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit230

`import "std/gamekit230"` · `use gamekit230`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit231

`import "std/gamekit231"` · `use gamekit231`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit232

`import "std/gamekit232"` · `use gamekit232`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit233

`import "std/gamekit233"` · `use gamekit233`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit234

`import "std/gamekit234"` · `use gamekit234`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit235

`import "std/gamekit235"` · `use gamekit235`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit236

`import "std/gamekit236"` · `use gamekit236`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit237

`import "std/gamekit237"` · `use gamekit237`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit238

`import "std/gamekit238"` · `use gamekit238`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit239

`import "std/gamekit239"` · `use gamekit239`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit240

`import "std/gamekit240"` · `use gamekit240`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit241

`import "std/gamekit241"` · `use gamekit241`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit242

`import "std/gamekit242"` · `use gamekit242`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit243

`import "std/gamekit243"` · `use gamekit243`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit244

`import "std/gamekit244"` · `use gamekit244`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit245

`import "std/gamekit245"` · `use gamekit245`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit246

`import "std/gamekit246"` · `use gamekit246`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit247

`import "std/gamekit247"` · `use gamekit247`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit248

`import "std/gamekit248"` · `use gamekit248`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit249

`import "std/gamekit249"` · `use gamekit249`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit250

`import "std/gamekit250"` · `use gamekit250`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit251

`import "std/gamekit251"` · `use gamekit251`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit252

`import "std/gamekit252"` · `use gamekit252`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit253

`import "std/gamekit253"` · `use gamekit253`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit254

`import "std/gamekit254"` · `use gamekit254`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit255

`import "std/gamekit255"` · `use gamekit255`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit256

`import "std/gamekit256"` · `use gamekit256`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit257

`import "std/gamekit257"` · `use gamekit257`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit258

`import "std/gamekit258"` · `use gamekit258`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit259

`import "std/gamekit259"` · `use gamekit259`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit260

`import "std/gamekit260"` · `use gamekit260`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit261

`import "std/gamekit261"` · `use gamekit261`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit262

`import "std/gamekit262"` · `use gamekit262`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit263

`import "std/gamekit263"` · `use gamekit263`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit264

`import "std/gamekit264"` · `use gamekit264`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit265

`import "std/gamekit265"` · `use gamekit265`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit266

`import "std/gamekit266"` · `use gamekit266`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit267

`import "std/gamekit267"` · `use gamekit267`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit268

`import "std/gamekit268"` · `use gamekit268`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit269

`import "std/gamekit269"` · `use gamekit269`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit270

`import "std/gamekit270"` · `use gamekit270`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit271

`import "std/gamekit271"` · `use gamekit271`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit272

`import "std/gamekit272"` · `use gamekit272`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit273

`import "std/gamekit273"` · `use gamekit273`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit274

`import "std/gamekit274"` · `use gamekit274`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit275

`import "std/gamekit275"` · `use gamekit275`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit276

`import "std/gamekit276"` · `use gamekit276`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit277

`import "std/gamekit277"` · `use gamekit277`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit278

`import "std/gamekit278"` · `use gamekit278`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit279

`import "std/gamekit279"` · `use gamekit279`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit280

`import "std/gamekit280"` · `use gamekit280`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit281

`import "std/gamekit281"` · `use gamekit281`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit282

`import "std/gamekit282"` · `use gamekit282`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit283

`import "std/gamekit283"` · `use gamekit283`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit284

`import "std/gamekit284"` · `use gamekit284`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit285

`import "std/gamekit285"` · `use gamekit285`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit286

`import "std/gamekit286"` · `use gamekit286`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit287

`import "std/gamekit287"` · `use gamekit287`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit288

`import "std/gamekit288"` · `use gamekit288`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit289

`import "std/gamekit289"` · `use gamekit289`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit290

`import "std/gamekit290"` · `use gamekit290`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit291

`import "std/gamekit291"` · `use gamekit291`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit292

`import "std/gamekit292"` · `use gamekit292`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit293

`import "std/gamekit293"` · `use gamekit293`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit294

`import "std/gamekit294"` · `use gamekit294`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit295

`import "std/gamekit295"` · `use gamekit295`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit296

`import "std/gamekit296"` · `use gamekit296`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit297

`import "std/gamekit297"` · `use gamekit297`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit298

`import "std/gamekit298"` · `use gamekit298`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit299

`import "std/gamekit299"` · `use gamekit299`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit300

`import "std/gamekit300"` · `use gamekit300`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit301

`import "std/gamekit301"` · `use gamekit301`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit302

`import "std/gamekit302"` · `use gamekit302`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit303

`import "std/gamekit303"` · `use gamekit303`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit304

`import "std/gamekit304"` · `use gamekit304`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit305

`import "std/gamekit305"` · `use gamekit305`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit306

`import "std/gamekit306"` · `use gamekit306`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit307

`import "std/gamekit307"` · `use gamekit307`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit308

`import "std/gamekit308"` · `use gamekit308`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit309

`import "std/gamekit309"` · `use gamekit309`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit310

`import "std/gamekit310"` · `use gamekit310`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit311

`import "std/gamekit311"` · `use gamekit311`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit312

`import "std/gamekit312"` · `use gamekit312`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit313

`import "std/gamekit313"` · `use gamekit313`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit314

`import "std/gamekit314"` · `use gamekit314`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit315

`import "std/gamekit315"` · `use gamekit315`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit316

`import "std/gamekit316"` · `use gamekit316`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit317

`import "std/gamekit317"` · `use gamekit317`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit318

`import "std/gamekit318"` · `use gamekit318`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit319

`import "std/gamekit319"` · `use gamekit319`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit320

`import "std/gamekit320"` · `use gamekit320`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit321

`import "std/gamekit321"` · `use gamekit321`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit322

`import "std/gamekit322"` · `use gamekit322`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit323

`import "std/gamekit323"` · `use gamekit323`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit324

`import "std/gamekit324"` · `use gamekit324`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit325

`import "std/gamekit325"` · `use gamekit325`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit326

`import "std/gamekit326"` · `use gamekit326`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit327

`import "std/gamekit327"` · `use gamekit327`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit328

`import "std/gamekit328"` · `use gamekit328`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit329

`import "std/gamekit329"` · `use gamekit329`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit330

`import "std/gamekit330"` · `use gamekit330`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit331

`import "std/gamekit331"` · `use gamekit331`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit332

`import "std/gamekit332"` · `use gamekit332`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit333

`import "std/gamekit333"` · `use gamekit333`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit334

`import "std/gamekit334"` · `use gamekit334`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit335

`import "std/gamekit335"` · `use gamekit335`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit336

`import "std/gamekit336"` · `use gamekit336`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit337

`import "std/gamekit337"` · `use gamekit337`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit338

`import "std/gamekit338"` · `use gamekit338`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit339

`import "std/gamekit339"` · `use gamekit339`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit340

`import "std/gamekit340"` · `use gamekit340`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit341

`import "std/gamekit341"` · `use gamekit341`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit342

`import "std/gamekit342"` · `use gamekit342`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit343

`import "std/gamekit343"` · `use gamekit343`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit344

`import "std/gamekit344"` · `use gamekit344`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit345

`import "std/gamekit345"` · `use gamekit345`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit346

`import "std/gamekit346"` · `use gamekit346`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit347

`import "std/gamekit347"` · `use gamekit347`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit348

`import "std/gamekit348"` · `use gamekit348`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit349

`import "std/gamekit349"` · `use gamekit349`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit350

`import "std/gamekit350"` · `use gamekit350`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit351

`import "std/gamekit351"` · `use gamekit351`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit352

`import "std/gamekit352"` · `use gamekit352`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit353

`import "std/gamekit353"` · `use gamekit353`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit354

`import "std/gamekit354"` · `use gamekit354`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit355

`import "std/gamekit355"` · `use gamekit355`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit356

`import "std/gamekit356"` · `use gamekit356`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit357

`import "std/gamekit357"` · `use gamekit357`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit358

`import "std/gamekit358"` · `use gamekit358`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit359

`import "std/gamekit359"` · `use gamekit359`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit360

`import "std/gamekit360"` · `use gamekit360`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit361

`import "std/gamekit361"` · `use gamekit361`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit362

`import "std/gamekit362"` · `use gamekit362`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit363

`import "std/gamekit363"` · `use gamekit363`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit364

`import "std/gamekit364"` · `use gamekit364`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit365

`import "std/gamekit365"` · `use gamekit365`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit366

`import "std/gamekit366"` · `use gamekit366`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit367

`import "std/gamekit367"` · `use gamekit367`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit368

`import "std/gamekit368"` · `use gamekit368`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit369

`import "std/gamekit369"` · `use gamekit369`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit370

`import "std/gamekit370"` · `use gamekit370`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit371

`import "std/gamekit371"` · `use gamekit371`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit372

`import "std/gamekit372"` · `use gamekit372`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit373

`import "std/gamekit373"` · `use gamekit373`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit374

`import "std/gamekit374"` · `use gamekit374`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit375

`import "std/gamekit375"` · `use gamekit375`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit376

`import "std/gamekit376"` · `use gamekit376`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit377

`import "std/gamekit377"` · `use gamekit377`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit378

`import "std/gamekit378"` · `use gamekit378`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit379

`import "std/gamekit379"` · `use gamekit379`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit380

`import "std/gamekit380"` · `use gamekit380`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit381

`import "std/gamekit381"` · `use gamekit381`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit382

`import "std/gamekit382"` · `use gamekit382`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit383

`import "std/gamekit383"` · `use gamekit383`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit384

`import "std/gamekit384"` · `use gamekit384`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit385

`import "std/gamekit385"` · `use gamekit385`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit386

`import "std/gamekit386"` · `use gamekit386`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit387

`import "std/gamekit387"` · `use gamekit387`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit388

`import "std/gamekit388"` · `use gamekit388`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit389

`import "std/gamekit389"` · `use gamekit389`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit390

`import "std/gamekit390"` · `use gamekit390`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit391

`import "std/gamekit391"` · `use gamekit391`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit392

`import "std/gamekit392"` · `use gamekit392`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit393

`import "std/gamekit393"` · `use gamekit393`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit394

`import "std/gamekit394"` · `use gamekit394`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit395

`import "std/gamekit395"` · `use gamekit395`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit396

`import "std/gamekit396"` · `use gamekit396`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit397

`import "std/gamekit397"` · `use gamekit397`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit398

`import "std/gamekit398"` · `use gamekit398`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit399

`import "std/gamekit399"` · `use gamekit399`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit400

`import "std/gamekit400"` · `use gamekit400`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit401

`import "std/gamekit401"` · `use gamekit401`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit402

`import "std/gamekit402"` · `use gamekit402`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit403

`import "std/gamekit403"` · `use gamekit403`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit404

`import "std/gamekit404"` · `use gamekit404`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit405

`import "std/gamekit405"` · `use gamekit405`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit406

`import "std/gamekit406"` · `use gamekit406`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit407

`import "std/gamekit407"` · `use gamekit407`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit408

`import "std/gamekit408"` · `use gamekit408`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit409

`import "std/gamekit409"` · `use gamekit409`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit410

`import "std/gamekit410"` · `use gamekit410`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit411

`import "std/gamekit411"` · `use gamekit411`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit412

`import "std/gamekit412"` · `use gamekit412`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit413

`import "std/gamekit413"` · `use gamekit413`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit414

`import "std/gamekit414"` · `use gamekit414`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit415

`import "std/gamekit415"` · `use gamekit415`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit416

`import "std/gamekit416"` · `use gamekit416`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit417

`import "std/gamekit417"` · `use gamekit417`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit418

`import "std/gamekit418"` · `use gamekit418`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit419

`import "std/gamekit419"` · `use gamekit419`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit420

`import "std/gamekit420"` · `use gamekit420`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit421

`import "std/gamekit421"` · `use gamekit421`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit422

`import "std/gamekit422"` · `use gamekit422`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit423

`import "std/gamekit423"` · `use gamekit423`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit424

`import "std/gamekit424"` · `use gamekit424`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit425

`import "std/gamekit425"` · `use gamekit425`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit426

`import "std/gamekit426"` · `use gamekit426`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit427

`import "std/gamekit427"` · `use gamekit427`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit428

`import "std/gamekit428"` · `use gamekit428`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit429

`import "std/gamekit429"` · `use gamekit429`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit430

`import "std/gamekit430"` · `use gamekit430`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit431

`import "std/gamekit431"` · `use gamekit431`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit432

`import "std/gamekit432"` · `use gamekit432`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit433

`import "std/gamekit433"` · `use gamekit433`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit434

`import "std/gamekit434"` · `use gamekit434`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit435

`import "std/gamekit435"` · `use gamekit435`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit436

`import "std/gamekit436"` · `use gamekit436`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit437

`import "std/gamekit437"` · `use gamekit437`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit438

`import "std/gamekit438"` · `use gamekit438`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit439

`import "std/gamekit439"` · `use gamekit439`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit440

`import "std/gamekit440"` · `use gamekit440`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit441

`import "std/gamekit441"` · `use gamekit441`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit442

`import "std/gamekit442"` · `use gamekit442`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit443

`import "std/gamekit443"` · `use gamekit443`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit444

`import "std/gamekit444"` · `use gamekit444`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit445

`import "std/gamekit445"` · `use gamekit445`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit446

`import "std/gamekit446"` · `use gamekit446`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit447

`import "std/gamekit447"` · `use gamekit447`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit448

`import "std/gamekit448"` · `use gamekit448`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit449

`import "std/gamekit449"` · `use gamekit449`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit450

`import "std/gamekit450"` · `use gamekit450`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit451

`import "std/gamekit451"` · `use gamekit451`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit452

`import "std/gamekit452"` · `use gamekit452`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit453

`import "std/gamekit453"` · `use gamekit453`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit454

`import "std/gamekit454"` · `use gamekit454`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit455

`import "std/gamekit455"` · `use gamekit455`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit456

`import "std/gamekit456"` · `use gamekit456`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit457

`import "std/gamekit457"` · `use gamekit457`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit458

`import "std/gamekit458"` · `use gamekit458`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit459

`import "std/gamekit459"` · `use gamekit459`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit460

`import "std/gamekit460"` · `use gamekit460`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit461

`import "std/gamekit461"` · `use gamekit461`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit462

`import "std/gamekit462"` · `use gamekit462`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit463

`import "std/gamekit463"` · `use gamekit463`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit464

`import "std/gamekit464"` · `use gamekit464`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit465

`import "std/gamekit465"` · `use gamekit465`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit466

`import "std/gamekit466"` · `use gamekit466`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit467

`import "std/gamekit467"` · `use gamekit467`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit468

`import "std/gamekit468"` · `use gamekit468`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit469

`import "std/gamekit469"` · `use gamekit469`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit470

`import "std/gamekit470"` · `use gamekit470`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit471

`import "std/gamekit471"` · `use gamekit471`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit472

`import "std/gamekit472"` · `use gamekit472`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit473

`import "std/gamekit473"` · `use gamekit473`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit474

`import "std/gamekit474"` · `use gamekit474`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit475

`import "std/gamekit475"` · `use gamekit475`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit476

`import "std/gamekit476"` · `use gamekit476`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit477

`import "std/gamekit477"` · `use gamekit477`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit478

`import "std/gamekit478"` · `use gamekit478`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit479

`import "std/gamekit479"` · `use gamekit479`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit480

`import "std/gamekit480"` · `use gamekit480`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit481

`import "std/gamekit481"` · `use gamekit481`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit482

`import "std/gamekit482"` · `use gamekit482`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit483

`import "std/gamekit483"` · `use gamekit483`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit484

`import "std/gamekit484"` · `use gamekit484`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit485

`import "std/gamekit485"` · `use gamekit485`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit486

`import "std/gamekit486"` · `use gamekit486`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit487

`import "std/gamekit487"` · `use gamekit487`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit488

`import "std/gamekit488"` · `use gamekit488`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit489

`import "std/gamekit489"` · `use gamekit489`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit490

`import "std/gamekit490"` · `use gamekit490`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit491

`import "std/gamekit491"` · `use gamekit491`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit492

`import "std/gamekit492"` · `use gamekit492`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit493

`import "std/gamekit493"` · `use gamekit493`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit494

`import "std/gamekit494"` · `use gamekit494`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit495

`import "std/gamekit495"` · `use gamekit495`

- `easeIn(t number) → number`
- `easeOut(t number) → number`

## std/gamekit496

`import "std/gamekit496"` · `use gamekit496`

- `falloff(dist number, radius number) → number`
- `shake(time number, amp number) → number`

## std/gamekit497

`import "std/gamekit497"` · `use gamekit497`

- `easeIn(t number) → number`
- `falloff(dist number, radius number) → number`

## std/gamekit498

`import "std/gamekit498"` · `use gamekit498`

- `easeOut(t number) → number`
- `spring(x number, v number, target number, dt number) → number`

## std/gamekit499

`import "std/gamekit499"` · `use gamekit499`

- `spring(x number, v number, target number, dt number) → number`
- `shake(time number, amp number) → number`

## std/gamekit500

`import "std/gamekit500"` · `use gamekit500`

- `easeIn(t number) → number`
- `easeOut(t number) → number`
