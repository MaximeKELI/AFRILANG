# Bibliothèques simples AFRILANG

**2151 modules** importables via `import "std/nom"` puis `use nom`.

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

## std/game2dkit001

`import "std/game2dkit001"` · `use game2dkit001`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit002

`import "std/game2dkit002"` · `use game2dkit002`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit003

`import "std/game2dkit003"` · `use game2dkit003`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit004

`import "std/game2dkit004"` · `use game2dkit004`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit005

`import "std/game2dkit005"` · `use game2dkit005`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit006

`import "std/game2dkit006"` · `use game2dkit006`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit007

`import "std/game2dkit007"` · `use game2dkit007`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit008

`import "std/game2dkit008"` · `use game2dkit008`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit009

`import "std/game2dkit009"` · `use game2dkit009`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit010

`import "std/game2dkit010"` · `use game2dkit010`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit011

`import "std/game2dkit011"` · `use game2dkit011`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit012

`import "std/game2dkit012"` · `use game2dkit012`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit013

`import "std/game2dkit013"` · `use game2dkit013`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit014

`import "std/game2dkit014"` · `use game2dkit014`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit015

`import "std/game2dkit015"` · `use game2dkit015`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit016

`import "std/game2dkit016"` · `use game2dkit016`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit017

`import "std/game2dkit017"` · `use game2dkit017`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit018

`import "std/game2dkit018"` · `use game2dkit018`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit019

`import "std/game2dkit019"` · `use game2dkit019`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit020

`import "std/game2dkit020"` · `use game2dkit020`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit021

`import "std/game2dkit021"` · `use game2dkit021`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit022

`import "std/game2dkit022"` · `use game2dkit022`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit023

`import "std/game2dkit023"` · `use game2dkit023`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit024

`import "std/game2dkit024"` · `use game2dkit024`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit025

`import "std/game2dkit025"` · `use game2dkit025`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit026

`import "std/game2dkit026"` · `use game2dkit026`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit027

`import "std/game2dkit027"` · `use game2dkit027`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit028

`import "std/game2dkit028"` · `use game2dkit028`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit029

`import "std/game2dkit029"` · `use game2dkit029`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit030

`import "std/game2dkit030"` · `use game2dkit030`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit031

`import "std/game2dkit031"` · `use game2dkit031`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit032

`import "std/game2dkit032"` · `use game2dkit032`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit033

`import "std/game2dkit033"` · `use game2dkit033`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit034

`import "std/game2dkit034"` · `use game2dkit034`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit035

`import "std/game2dkit035"` · `use game2dkit035`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit036

`import "std/game2dkit036"` · `use game2dkit036`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit037

`import "std/game2dkit037"` · `use game2dkit037`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit038

`import "std/game2dkit038"` · `use game2dkit038`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit039

`import "std/game2dkit039"` · `use game2dkit039`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit040

`import "std/game2dkit040"` · `use game2dkit040`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit041

`import "std/game2dkit041"` · `use game2dkit041`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit042

`import "std/game2dkit042"` · `use game2dkit042`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit043

`import "std/game2dkit043"` · `use game2dkit043`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit044

`import "std/game2dkit044"` · `use game2dkit044`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit045

`import "std/game2dkit045"` · `use game2dkit045`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit046

`import "std/game2dkit046"` · `use game2dkit046`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit047

`import "std/game2dkit047"` · `use game2dkit047`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit048

`import "std/game2dkit048"` · `use game2dkit048`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit049

`import "std/game2dkit049"` · `use game2dkit049`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit050

`import "std/game2dkit050"` · `use game2dkit050`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit051

`import "std/game2dkit051"` · `use game2dkit051`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit052

`import "std/game2dkit052"` · `use game2dkit052`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit053

`import "std/game2dkit053"` · `use game2dkit053`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit054

`import "std/game2dkit054"` · `use game2dkit054`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit055

`import "std/game2dkit055"` · `use game2dkit055`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit056

`import "std/game2dkit056"` · `use game2dkit056`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit057

`import "std/game2dkit057"` · `use game2dkit057`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit058

`import "std/game2dkit058"` · `use game2dkit058`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit059

`import "std/game2dkit059"` · `use game2dkit059`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit060

`import "std/game2dkit060"` · `use game2dkit060`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit061

`import "std/game2dkit061"` · `use game2dkit061`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit062

`import "std/game2dkit062"` · `use game2dkit062`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit063

`import "std/game2dkit063"` · `use game2dkit063`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit064

`import "std/game2dkit064"` · `use game2dkit064`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit065

`import "std/game2dkit065"` · `use game2dkit065`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit066

`import "std/game2dkit066"` · `use game2dkit066`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit067

`import "std/game2dkit067"` · `use game2dkit067`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit068

`import "std/game2dkit068"` · `use game2dkit068`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit069

`import "std/game2dkit069"` · `use game2dkit069`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit070

`import "std/game2dkit070"` · `use game2dkit070`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit071

`import "std/game2dkit071"` · `use game2dkit071`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit072

`import "std/game2dkit072"` · `use game2dkit072`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit073

`import "std/game2dkit073"` · `use game2dkit073`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit074

`import "std/game2dkit074"` · `use game2dkit074`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit075

`import "std/game2dkit075"` · `use game2dkit075`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit076

`import "std/game2dkit076"` · `use game2dkit076`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit077

`import "std/game2dkit077"` · `use game2dkit077`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit078

`import "std/game2dkit078"` · `use game2dkit078`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit079

`import "std/game2dkit079"` · `use game2dkit079`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit080

`import "std/game2dkit080"` · `use game2dkit080`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit081

`import "std/game2dkit081"` · `use game2dkit081`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit082

`import "std/game2dkit082"` · `use game2dkit082`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit083

`import "std/game2dkit083"` · `use game2dkit083`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit084

`import "std/game2dkit084"` · `use game2dkit084`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit085

`import "std/game2dkit085"` · `use game2dkit085`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit086

`import "std/game2dkit086"` · `use game2dkit086`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit087

`import "std/game2dkit087"` · `use game2dkit087`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit088

`import "std/game2dkit088"` · `use game2dkit088`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit089

`import "std/game2dkit089"` · `use game2dkit089`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit090

`import "std/game2dkit090"` · `use game2dkit090`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit091

`import "std/game2dkit091"` · `use game2dkit091`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit092

`import "std/game2dkit092"` · `use game2dkit092`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit093

`import "std/game2dkit093"` · `use game2dkit093`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit094

`import "std/game2dkit094"` · `use game2dkit094`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit095

`import "std/game2dkit095"` · `use game2dkit095`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit096

`import "std/game2dkit096"` · `use game2dkit096`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit097

`import "std/game2dkit097"` · `use game2dkit097`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit098

`import "std/game2dkit098"` · `use game2dkit098`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit099

`import "std/game2dkit099"` · `use game2dkit099`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit100

`import "std/game2dkit100"` · `use game2dkit100`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit101

`import "std/game2dkit101"` · `use game2dkit101`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit102

`import "std/game2dkit102"` · `use game2dkit102`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit103

`import "std/game2dkit103"` · `use game2dkit103`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit104

`import "std/game2dkit104"` · `use game2dkit104`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit105

`import "std/game2dkit105"` · `use game2dkit105`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit106

`import "std/game2dkit106"` · `use game2dkit106`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit107

`import "std/game2dkit107"` · `use game2dkit107`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit108

`import "std/game2dkit108"` · `use game2dkit108`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit109

`import "std/game2dkit109"` · `use game2dkit109`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit110

`import "std/game2dkit110"` · `use game2dkit110`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit111

`import "std/game2dkit111"` · `use game2dkit111`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit112

`import "std/game2dkit112"` · `use game2dkit112`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit113

`import "std/game2dkit113"` · `use game2dkit113`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit114

`import "std/game2dkit114"` · `use game2dkit114`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit115

`import "std/game2dkit115"` · `use game2dkit115`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit116

`import "std/game2dkit116"` · `use game2dkit116`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit117

`import "std/game2dkit117"` · `use game2dkit117`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit118

`import "std/game2dkit118"` · `use game2dkit118`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit119

`import "std/game2dkit119"` · `use game2dkit119`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit120

`import "std/game2dkit120"` · `use game2dkit120`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit121

`import "std/game2dkit121"` · `use game2dkit121`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit122

`import "std/game2dkit122"` · `use game2dkit122`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit123

`import "std/game2dkit123"` · `use game2dkit123`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit124

`import "std/game2dkit124"` · `use game2dkit124`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit125

`import "std/game2dkit125"` · `use game2dkit125`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit126

`import "std/game2dkit126"` · `use game2dkit126`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit127

`import "std/game2dkit127"` · `use game2dkit127`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit128

`import "std/game2dkit128"` · `use game2dkit128`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit129

`import "std/game2dkit129"` · `use game2dkit129`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit130

`import "std/game2dkit130"` · `use game2dkit130`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit131

`import "std/game2dkit131"` · `use game2dkit131`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit132

`import "std/game2dkit132"` · `use game2dkit132`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit133

`import "std/game2dkit133"` · `use game2dkit133`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit134

`import "std/game2dkit134"` · `use game2dkit134`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit135

`import "std/game2dkit135"` · `use game2dkit135`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit136

`import "std/game2dkit136"` · `use game2dkit136`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit137

`import "std/game2dkit137"` · `use game2dkit137`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit138

`import "std/game2dkit138"` · `use game2dkit138`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit139

`import "std/game2dkit139"` · `use game2dkit139`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit140

`import "std/game2dkit140"` · `use game2dkit140`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit141

`import "std/game2dkit141"` · `use game2dkit141`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit142

`import "std/game2dkit142"` · `use game2dkit142`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit143

`import "std/game2dkit143"` · `use game2dkit143`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit144

`import "std/game2dkit144"` · `use game2dkit144`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit145

`import "std/game2dkit145"` · `use game2dkit145`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit146

`import "std/game2dkit146"` · `use game2dkit146`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit147

`import "std/game2dkit147"` · `use game2dkit147`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit148

`import "std/game2dkit148"` · `use game2dkit148`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit149

`import "std/game2dkit149"` · `use game2dkit149`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit150

`import "std/game2dkit150"` · `use game2dkit150`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit151

`import "std/game2dkit151"` · `use game2dkit151`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit152

`import "std/game2dkit152"` · `use game2dkit152`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit153

`import "std/game2dkit153"` · `use game2dkit153`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit154

`import "std/game2dkit154"` · `use game2dkit154`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit155

`import "std/game2dkit155"` · `use game2dkit155`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit156

`import "std/game2dkit156"` · `use game2dkit156`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit157

`import "std/game2dkit157"` · `use game2dkit157`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit158

`import "std/game2dkit158"` · `use game2dkit158`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit159

`import "std/game2dkit159"` · `use game2dkit159`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit160

`import "std/game2dkit160"` · `use game2dkit160`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit161

`import "std/game2dkit161"` · `use game2dkit161`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit162

`import "std/game2dkit162"` · `use game2dkit162`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit163

`import "std/game2dkit163"` · `use game2dkit163`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit164

`import "std/game2dkit164"` · `use game2dkit164`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit165

`import "std/game2dkit165"` · `use game2dkit165`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit166

`import "std/game2dkit166"` · `use game2dkit166`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit167

`import "std/game2dkit167"` · `use game2dkit167`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit168

`import "std/game2dkit168"` · `use game2dkit168`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit169

`import "std/game2dkit169"` · `use game2dkit169`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit170

`import "std/game2dkit170"` · `use game2dkit170`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit171

`import "std/game2dkit171"` · `use game2dkit171`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit172

`import "std/game2dkit172"` · `use game2dkit172`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit173

`import "std/game2dkit173"` · `use game2dkit173`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit174

`import "std/game2dkit174"` · `use game2dkit174`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit175

`import "std/game2dkit175"` · `use game2dkit175`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit176

`import "std/game2dkit176"` · `use game2dkit176`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit177

`import "std/game2dkit177"` · `use game2dkit177`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit178

`import "std/game2dkit178"` · `use game2dkit178`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit179

`import "std/game2dkit179"` · `use game2dkit179`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit180

`import "std/game2dkit180"` · `use game2dkit180`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit181

`import "std/game2dkit181"` · `use game2dkit181`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit182

`import "std/game2dkit182"` · `use game2dkit182`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit183

`import "std/game2dkit183"` · `use game2dkit183`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit184

`import "std/game2dkit184"` · `use game2dkit184`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit185

`import "std/game2dkit185"` · `use game2dkit185`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit186

`import "std/game2dkit186"` · `use game2dkit186`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit187

`import "std/game2dkit187"` · `use game2dkit187`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit188

`import "std/game2dkit188"` · `use game2dkit188`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit189

`import "std/game2dkit189"` · `use game2dkit189`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit190

`import "std/game2dkit190"` · `use game2dkit190`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit191

`import "std/game2dkit191"` · `use game2dkit191`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit192

`import "std/game2dkit192"` · `use game2dkit192`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit193

`import "std/game2dkit193"` · `use game2dkit193`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit194

`import "std/game2dkit194"` · `use game2dkit194`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit195

`import "std/game2dkit195"` · `use game2dkit195`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit196

`import "std/game2dkit196"` · `use game2dkit196`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit197

`import "std/game2dkit197"` · `use game2dkit197`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit198

`import "std/game2dkit198"` · `use game2dkit198`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit199

`import "std/game2dkit199"` · `use game2dkit199`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit200

`import "std/game2dkit200"` · `use game2dkit200`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit201

`import "std/game2dkit201"` · `use game2dkit201`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit202

`import "std/game2dkit202"` · `use game2dkit202`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit203

`import "std/game2dkit203"` · `use game2dkit203`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit204

`import "std/game2dkit204"` · `use game2dkit204`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit205

`import "std/game2dkit205"` · `use game2dkit205`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit206

`import "std/game2dkit206"` · `use game2dkit206`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit207

`import "std/game2dkit207"` · `use game2dkit207`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit208

`import "std/game2dkit208"` · `use game2dkit208`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit209

`import "std/game2dkit209"` · `use game2dkit209`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit210

`import "std/game2dkit210"` · `use game2dkit210`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit211

`import "std/game2dkit211"` · `use game2dkit211`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit212

`import "std/game2dkit212"` · `use game2dkit212`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit213

`import "std/game2dkit213"` · `use game2dkit213`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit214

`import "std/game2dkit214"` · `use game2dkit214`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit215

`import "std/game2dkit215"` · `use game2dkit215`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit216

`import "std/game2dkit216"` · `use game2dkit216`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit217

`import "std/game2dkit217"` · `use game2dkit217`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit218

`import "std/game2dkit218"` · `use game2dkit218`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit219

`import "std/game2dkit219"` · `use game2dkit219`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit220

`import "std/game2dkit220"` · `use game2dkit220`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit221

`import "std/game2dkit221"` · `use game2dkit221`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit222

`import "std/game2dkit222"` · `use game2dkit222`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit223

`import "std/game2dkit223"` · `use game2dkit223`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit224

`import "std/game2dkit224"` · `use game2dkit224`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit225

`import "std/game2dkit225"` · `use game2dkit225`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit226

`import "std/game2dkit226"` · `use game2dkit226`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit227

`import "std/game2dkit227"` · `use game2dkit227`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit228

`import "std/game2dkit228"` · `use game2dkit228`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit229

`import "std/game2dkit229"` · `use game2dkit229`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit230

`import "std/game2dkit230"` · `use game2dkit230`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit231

`import "std/game2dkit231"` · `use game2dkit231`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit232

`import "std/game2dkit232"` · `use game2dkit232`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit233

`import "std/game2dkit233"` · `use game2dkit233`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit234

`import "std/game2dkit234"` · `use game2dkit234`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit235

`import "std/game2dkit235"` · `use game2dkit235`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit236

`import "std/game2dkit236"` · `use game2dkit236`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit237

`import "std/game2dkit237"` · `use game2dkit237`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit238

`import "std/game2dkit238"` · `use game2dkit238`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit239

`import "std/game2dkit239"` · `use game2dkit239`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit240

`import "std/game2dkit240"` · `use game2dkit240`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit241

`import "std/game2dkit241"` · `use game2dkit241`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit242

`import "std/game2dkit242"` · `use game2dkit242`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit243

`import "std/game2dkit243"` · `use game2dkit243`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit244

`import "std/game2dkit244"` · `use game2dkit244`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit245

`import "std/game2dkit245"` · `use game2dkit245`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit246

`import "std/game2dkit246"` · `use game2dkit246`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit247

`import "std/game2dkit247"` · `use game2dkit247`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit248

`import "std/game2dkit248"` · `use game2dkit248`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit249

`import "std/game2dkit249"` · `use game2dkit249`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit250

`import "std/game2dkit250"` · `use game2dkit250`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit251

`import "std/game2dkit251"` · `use game2dkit251`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit252

`import "std/game2dkit252"` · `use game2dkit252`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit253

`import "std/game2dkit253"` · `use game2dkit253`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit254

`import "std/game2dkit254"` · `use game2dkit254`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit255

`import "std/game2dkit255"` · `use game2dkit255`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit256

`import "std/game2dkit256"` · `use game2dkit256`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit257

`import "std/game2dkit257"` · `use game2dkit257`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit258

`import "std/game2dkit258"` · `use game2dkit258`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit259

`import "std/game2dkit259"` · `use game2dkit259`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit260

`import "std/game2dkit260"` · `use game2dkit260`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit261

`import "std/game2dkit261"` · `use game2dkit261`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit262

`import "std/game2dkit262"` · `use game2dkit262`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit263

`import "std/game2dkit263"` · `use game2dkit263`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit264

`import "std/game2dkit264"` · `use game2dkit264`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit265

`import "std/game2dkit265"` · `use game2dkit265`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit266

`import "std/game2dkit266"` · `use game2dkit266`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit267

`import "std/game2dkit267"` · `use game2dkit267`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit268

`import "std/game2dkit268"` · `use game2dkit268`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit269

`import "std/game2dkit269"` · `use game2dkit269`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit270

`import "std/game2dkit270"` · `use game2dkit270`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit271

`import "std/game2dkit271"` · `use game2dkit271`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit272

`import "std/game2dkit272"` · `use game2dkit272`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit273

`import "std/game2dkit273"` · `use game2dkit273`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit274

`import "std/game2dkit274"` · `use game2dkit274`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit275

`import "std/game2dkit275"` · `use game2dkit275`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit276

`import "std/game2dkit276"` · `use game2dkit276`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit277

`import "std/game2dkit277"` · `use game2dkit277`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit278

`import "std/game2dkit278"` · `use game2dkit278`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit279

`import "std/game2dkit279"` · `use game2dkit279`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit280

`import "std/game2dkit280"` · `use game2dkit280`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit281

`import "std/game2dkit281"` · `use game2dkit281`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit282

`import "std/game2dkit282"` · `use game2dkit282`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit283

`import "std/game2dkit283"` · `use game2dkit283`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit284

`import "std/game2dkit284"` · `use game2dkit284`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit285

`import "std/game2dkit285"` · `use game2dkit285`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit286

`import "std/game2dkit286"` · `use game2dkit286`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit287

`import "std/game2dkit287"` · `use game2dkit287`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit288

`import "std/game2dkit288"` · `use game2dkit288`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit289

`import "std/game2dkit289"` · `use game2dkit289`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit290

`import "std/game2dkit290"` · `use game2dkit290`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit291

`import "std/game2dkit291"` · `use game2dkit291`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit292

`import "std/game2dkit292"` · `use game2dkit292`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit293

`import "std/game2dkit293"` · `use game2dkit293`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit294

`import "std/game2dkit294"` · `use game2dkit294`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit295

`import "std/game2dkit295"` · `use game2dkit295`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit296

`import "std/game2dkit296"` · `use game2dkit296`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit297

`import "std/game2dkit297"` · `use game2dkit297`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit298

`import "std/game2dkit298"` · `use game2dkit298`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit299

`import "std/game2dkit299"` · `use game2dkit299`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit300

`import "std/game2dkit300"` · `use game2dkit300`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit301

`import "std/game2dkit301"` · `use game2dkit301`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit302

`import "std/game2dkit302"` · `use game2dkit302`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit303

`import "std/game2dkit303"` · `use game2dkit303`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit304

`import "std/game2dkit304"` · `use game2dkit304`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit305

`import "std/game2dkit305"` · `use game2dkit305`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit306

`import "std/game2dkit306"` · `use game2dkit306`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit307

`import "std/game2dkit307"` · `use game2dkit307`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit308

`import "std/game2dkit308"` · `use game2dkit308`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit309

`import "std/game2dkit309"` · `use game2dkit309`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit310

`import "std/game2dkit310"` · `use game2dkit310`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit311

`import "std/game2dkit311"` · `use game2dkit311`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit312

`import "std/game2dkit312"` · `use game2dkit312`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit313

`import "std/game2dkit313"` · `use game2dkit313`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit314

`import "std/game2dkit314"` · `use game2dkit314`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit315

`import "std/game2dkit315"` · `use game2dkit315`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit316

`import "std/game2dkit316"` · `use game2dkit316`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit317

`import "std/game2dkit317"` · `use game2dkit317`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit318

`import "std/game2dkit318"` · `use game2dkit318`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit319

`import "std/game2dkit319"` · `use game2dkit319`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit320

`import "std/game2dkit320"` · `use game2dkit320`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit321

`import "std/game2dkit321"` · `use game2dkit321`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit322

`import "std/game2dkit322"` · `use game2dkit322`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit323

`import "std/game2dkit323"` · `use game2dkit323`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit324

`import "std/game2dkit324"` · `use game2dkit324`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit325

`import "std/game2dkit325"` · `use game2dkit325`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit326

`import "std/game2dkit326"` · `use game2dkit326`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit327

`import "std/game2dkit327"` · `use game2dkit327`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit328

`import "std/game2dkit328"` · `use game2dkit328`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit329

`import "std/game2dkit329"` · `use game2dkit329`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit330

`import "std/game2dkit330"` · `use game2dkit330`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit331

`import "std/game2dkit331"` · `use game2dkit331`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit332

`import "std/game2dkit332"` · `use game2dkit332`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit333

`import "std/game2dkit333"` · `use game2dkit333`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit334

`import "std/game2dkit334"` · `use game2dkit334`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit335

`import "std/game2dkit335"` · `use game2dkit335`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit336

`import "std/game2dkit336"` · `use game2dkit336`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit337

`import "std/game2dkit337"` · `use game2dkit337`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit338

`import "std/game2dkit338"` · `use game2dkit338`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit339

`import "std/game2dkit339"` · `use game2dkit339`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit340

`import "std/game2dkit340"` · `use game2dkit340`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit341

`import "std/game2dkit341"` · `use game2dkit341`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit342

`import "std/game2dkit342"` · `use game2dkit342`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit343

`import "std/game2dkit343"` · `use game2dkit343`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit344

`import "std/game2dkit344"` · `use game2dkit344`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit345

`import "std/game2dkit345"` · `use game2dkit345`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit346

`import "std/game2dkit346"` · `use game2dkit346`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit347

`import "std/game2dkit347"` · `use game2dkit347`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit348

`import "std/game2dkit348"` · `use game2dkit348`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit349

`import "std/game2dkit349"` · `use game2dkit349`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit350

`import "std/game2dkit350"` · `use game2dkit350`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit351

`import "std/game2dkit351"` · `use game2dkit351`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit352

`import "std/game2dkit352"` · `use game2dkit352`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit353

`import "std/game2dkit353"` · `use game2dkit353`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit354

`import "std/game2dkit354"` · `use game2dkit354`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit355

`import "std/game2dkit355"` · `use game2dkit355`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit356

`import "std/game2dkit356"` · `use game2dkit356`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit357

`import "std/game2dkit357"` · `use game2dkit357`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit358

`import "std/game2dkit358"` · `use game2dkit358`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit359

`import "std/game2dkit359"` · `use game2dkit359`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit360

`import "std/game2dkit360"` · `use game2dkit360`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit361

`import "std/game2dkit361"` · `use game2dkit361`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit362

`import "std/game2dkit362"` · `use game2dkit362`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit363

`import "std/game2dkit363"` · `use game2dkit363`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit364

`import "std/game2dkit364"` · `use game2dkit364`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit365

`import "std/game2dkit365"` · `use game2dkit365`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit366

`import "std/game2dkit366"` · `use game2dkit366`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit367

`import "std/game2dkit367"` · `use game2dkit367`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit368

`import "std/game2dkit368"` · `use game2dkit368`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit369

`import "std/game2dkit369"` · `use game2dkit369`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit370

`import "std/game2dkit370"` · `use game2dkit370`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit371

`import "std/game2dkit371"` · `use game2dkit371`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit372

`import "std/game2dkit372"` · `use game2dkit372`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit373

`import "std/game2dkit373"` · `use game2dkit373`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit374

`import "std/game2dkit374"` · `use game2dkit374`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit375

`import "std/game2dkit375"` · `use game2dkit375`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit376

`import "std/game2dkit376"` · `use game2dkit376`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit377

`import "std/game2dkit377"` · `use game2dkit377`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit378

`import "std/game2dkit378"` · `use game2dkit378`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit379

`import "std/game2dkit379"` · `use game2dkit379`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit380

`import "std/game2dkit380"` · `use game2dkit380`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit381

`import "std/game2dkit381"` · `use game2dkit381`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit382

`import "std/game2dkit382"` · `use game2dkit382`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit383

`import "std/game2dkit383"` · `use game2dkit383`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit384

`import "std/game2dkit384"` · `use game2dkit384`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit385

`import "std/game2dkit385"` · `use game2dkit385`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit386

`import "std/game2dkit386"` · `use game2dkit386`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit387

`import "std/game2dkit387"` · `use game2dkit387`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit388

`import "std/game2dkit388"` · `use game2dkit388`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit389

`import "std/game2dkit389"` · `use game2dkit389`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit390

`import "std/game2dkit390"` · `use game2dkit390`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit391

`import "std/game2dkit391"` · `use game2dkit391`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit392

`import "std/game2dkit392"` · `use game2dkit392`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit393

`import "std/game2dkit393"` · `use game2dkit393`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit394

`import "std/game2dkit394"` · `use game2dkit394`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit395

`import "std/game2dkit395"` · `use game2dkit395`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit396

`import "std/game2dkit396"` · `use game2dkit396`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit397

`import "std/game2dkit397"` · `use game2dkit397`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit398

`import "std/game2dkit398"` · `use game2dkit398`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit399

`import "std/game2dkit399"` · `use game2dkit399`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit400

`import "std/game2dkit400"` · `use game2dkit400`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit401

`import "std/game2dkit401"` · `use game2dkit401`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit402

`import "std/game2dkit402"` · `use game2dkit402`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit403

`import "std/game2dkit403"` · `use game2dkit403`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit404

`import "std/game2dkit404"` · `use game2dkit404`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit405

`import "std/game2dkit405"` · `use game2dkit405`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit406

`import "std/game2dkit406"` · `use game2dkit406`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit407

`import "std/game2dkit407"` · `use game2dkit407`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit408

`import "std/game2dkit408"` · `use game2dkit408`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit409

`import "std/game2dkit409"` · `use game2dkit409`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit410

`import "std/game2dkit410"` · `use game2dkit410`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit411

`import "std/game2dkit411"` · `use game2dkit411`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit412

`import "std/game2dkit412"` · `use game2dkit412`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit413

`import "std/game2dkit413"` · `use game2dkit413`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit414

`import "std/game2dkit414"` · `use game2dkit414`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit415

`import "std/game2dkit415"` · `use game2dkit415`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit416

`import "std/game2dkit416"` · `use game2dkit416`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit417

`import "std/game2dkit417"` · `use game2dkit417`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit418

`import "std/game2dkit418"` · `use game2dkit418`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit419

`import "std/game2dkit419"` · `use game2dkit419`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit420

`import "std/game2dkit420"` · `use game2dkit420`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit421

`import "std/game2dkit421"` · `use game2dkit421`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit422

`import "std/game2dkit422"` · `use game2dkit422`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit423

`import "std/game2dkit423"` · `use game2dkit423`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit424

`import "std/game2dkit424"` · `use game2dkit424`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit425

`import "std/game2dkit425"` · `use game2dkit425`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit426

`import "std/game2dkit426"` · `use game2dkit426`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit427

`import "std/game2dkit427"` · `use game2dkit427`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit428

`import "std/game2dkit428"` · `use game2dkit428`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit429

`import "std/game2dkit429"` · `use game2dkit429`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit430

`import "std/game2dkit430"` · `use game2dkit430`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit431

`import "std/game2dkit431"` · `use game2dkit431`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit432

`import "std/game2dkit432"` · `use game2dkit432`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit433

`import "std/game2dkit433"` · `use game2dkit433`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit434

`import "std/game2dkit434"` · `use game2dkit434`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit435

`import "std/game2dkit435"` · `use game2dkit435`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit436

`import "std/game2dkit436"` · `use game2dkit436`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit437

`import "std/game2dkit437"` · `use game2dkit437`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit438

`import "std/game2dkit438"` · `use game2dkit438`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit439

`import "std/game2dkit439"` · `use game2dkit439`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit440

`import "std/game2dkit440"` · `use game2dkit440`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit441

`import "std/game2dkit441"` · `use game2dkit441`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit442

`import "std/game2dkit442"` · `use game2dkit442`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit443

`import "std/game2dkit443"` · `use game2dkit443`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit444

`import "std/game2dkit444"` · `use game2dkit444`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit445

`import "std/game2dkit445"` · `use game2dkit445`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit446

`import "std/game2dkit446"` · `use game2dkit446`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit447

`import "std/game2dkit447"` · `use game2dkit447`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit448

`import "std/game2dkit448"` · `use game2dkit448`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit449

`import "std/game2dkit449"` · `use game2dkit449`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit450

`import "std/game2dkit450"` · `use game2dkit450`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit451

`import "std/game2dkit451"` · `use game2dkit451`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit452

`import "std/game2dkit452"` · `use game2dkit452`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit453

`import "std/game2dkit453"` · `use game2dkit453`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit454

`import "std/game2dkit454"` · `use game2dkit454`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit455

`import "std/game2dkit455"` · `use game2dkit455`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit456

`import "std/game2dkit456"` · `use game2dkit456`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit457

`import "std/game2dkit457"` · `use game2dkit457`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit458

`import "std/game2dkit458"` · `use game2dkit458`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit459

`import "std/game2dkit459"` · `use game2dkit459`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit460

`import "std/game2dkit460"` · `use game2dkit460`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit461

`import "std/game2dkit461"` · `use game2dkit461`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit462

`import "std/game2dkit462"` · `use game2dkit462`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit463

`import "std/game2dkit463"` · `use game2dkit463`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit464

`import "std/game2dkit464"` · `use game2dkit464`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit465

`import "std/game2dkit465"` · `use game2dkit465`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit466

`import "std/game2dkit466"` · `use game2dkit466`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit467

`import "std/game2dkit467"` · `use game2dkit467`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit468

`import "std/game2dkit468"` · `use game2dkit468`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit469

`import "std/game2dkit469"` · `use game2dkit469`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit470

`import "std/game2dkit470"` · `use game2dkit470`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit471

`import "std/game2dkit471"` · `use game2dkit471`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit472

`import "std/game2dkit472"` · `use game2dkit472`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit473

`import "std/game2dkit473"` · `use game2dkit473`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit474

`import "std/game2dkit474"` · `use game2dkit474`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit475

`import "std/game2dkit475"` · `use game2dkit475`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit476

`import "std/game2dkit476"` · `use game2dkit476`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit477

`import "std/game2dkit477"` · `use game2dkit477`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit478

`import "std/game2dkit478"` · `use game2dkit478`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit479

`import "std/game2dkit479"` · `use game2dkit479`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit480

`import "std/game2dkit480"` · `use game2dkit480`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit481

`import "std/game2dkit481"` · `use game2dkit481`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit482

`import "std/game2dkit482"` · `use game2dkit482`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit483

`import "std/game2dkit483"` · `use game2dkit483`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit484

`import "std/game2dkit484"` · `use game2dkit484`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit485

`import "std/game2dkit485"` · `use game2dkit485`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit486

`import "std/game2dkit486"` · `use game2dkit486`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit487

`import "std/game2dkit487"` · `use game2dkit487`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit488

`import "std/game2dkit488"` · `use game2dkit488`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit489

`import "std/game2dkit489"` · `use game2dkit489`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit490

`import "std/game2dkit490"` · `use game2dkit490`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit491

`import "std/game2dkit491"` · `use game2dkit491`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit492

`import "std/game2dkit492"` · `use game2dkit492`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit493

`import "std/game2dkit493"` · `use game2dkit493`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit494

`import "std/game2dkit494"` · `use game2dkit494`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit495

`import "std/game2dkit495"` · `use game2dkit495`

- `dist2(x0 number, y0 number, x1 number, y1 number) → number`
- `wrap(v number, size number) → number`

## std/game2dkit496

`import "std/game2dkit496"` · `use game2dkit496`

- `shake(time number, amp number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game2dkit497

`import "std/game2dkit497"` · `use game2dkit497`

- `snapGrid(v number) → number`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit498

`import "std/game2dkit498"` · `use game2dkit498`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `pointInRect(px number, py number, rx number, ry number, rw number, rh number) → bool`

## std/game2dkit499

`import "std/game2dkit499"` · `use game2dkit499`

- `aabbHit(ax number, ay number, aw number, ah number, bx number, by number, bw number, bh number) → bool`
- `dist2(x0 number, y0 number, x1 number, y1 number) → number`

## std/game2dkit500

`import "std/game2dkit500"` · `use game2dkit500`

- `approach(cur number, target number, maxDelta number) → number`
- `follow(cam number, target number, dt number) → number`

## std/game3dkit001

`import "std/game3dkit001"` · `use game3dkit001`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit002

`import "std/game3dkit002"` · `use game3dkit002`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit003

`import "std/game3dkit003"` · `use game3dkit003`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit004

`import "std/game3dkit004"` · `use game3dkit004`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit005

`import "std/game3dkit005"` · `use game3dkit005`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit006

`import "std/game3dkit006"` · `use game3dkit006`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit007

`import "std/game3dkit007"` · `use game3dkit007`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit008

`import "std/game3dkit008"` · `use game3dkit008`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit009

`import "std/game3dkit009"` · `use game3dkit009`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit010

`import "std/game3dkit010"` · `use game3dkit010`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit011

`import "std/game3dkit011"` · `use game3dkit011`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit012

`import "std/game3dkit012"` · `use game3dkit012`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit013

`import "std/game3dkit013"` · `use game3dkit013`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit014

`import "std/game3dkit014"` · `use game3dkit014`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit015

`import "std/game3dkit015"` · `use game3dkit015`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit016

`import "std/game3dkit016"` · `use game3dkit016`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit017

`import "std/game3dkit017"` · `use game3dkit017`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit018

`import "std/game3dkit018"` · `use game3dkit018`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit019

`import "std/game3dkit019"` · `use game3dkit019`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit020

`import "std/game3dkit020"` · `use game3dkit020`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit021

`import "std/game3dkit021"` · `use game3dkit021`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit022

`import "std/game3dkit022"` · `use game3dkit022`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit023

`import "std/game3dkit023"` · `use game3dkit023`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit024

`import "std/game3dkit024"` · `use game3dkit024`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit025

`import "std/game3dkit025"` · `use game3dkit025`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit026

`import "std/game3dkit026"` · `use game3dkit026`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit027

`import "std/game3dkit027"` · `use game3dkit027`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit028

`import "std/game3dkit028"` · `use game3dkit028`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit029

`import "std/game3dkit029"` · `use game3dkit029`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit030

`import "std/game3dkit030"` · `use game3dkit030`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit031

`import "std/game3dkit031"` · `use game3dkit031`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit032

`import "std/game3dkit032"` · `use game3dkit032`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit033

`import "std/game3dkit033"` · `use game3dkit033`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit034

`import "std/game3dkit034"` · `use game3dkit034`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit035

`import "std/game3dkit035"` · `use game3dkit035`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit036

`import "std/game3dkit036"` · `use game3dkit036`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit037

`import "std/game3dkit037"` · `use game3dkit037`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit038

`import "std/game3dkit038"` · `use game3dkit038`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit039

`import "std/game3dkit039"` · `use game3dkit039`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit040

`import "std/game3dkit040"` · `use game3dkit040`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit041

`import "std/game3dkit041"` · `use game3dkit041`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit042

`import "std/game3dkit042"` · `use game3dkit042`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit043

`import "std/game3dkit043"` · `use game3dkit043`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit044

`import "std/game3dkit044"` · `use game3dkit044`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit045

`import "std/game3dkit045"` · `use game3dkit045`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit046

`import "std/game3dkit046"` · `use game3dkit046`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit047

`import "std/game3dkit047"` · `use game3dkit047`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit048

`import "std/game3dkit048"` · `use game3dkit048`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit049

`import "std/game3dkit049"` · `use game3dkit049`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit050

`import "std/game3dkit050"` · `use game3dkit050`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit051

`import "std/game3dkit051"` · `use game3dkit051`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit052

`import "std/game3dkit052"` · `use game3dkit052`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit053

`import "std/game3dkit053"` · `use game3dkit053`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit054

`import "std/game3dkit054"` · `use game3dkit054`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit055

`import "std/game3dkit055"` · `use game3dkit055`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit056

`import "std/game3dkit056"` · `use game3dkit056`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit057

`import "std/game3dkit057"` · `use game3dkit057`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit058

`import "std/game3dkit058"` · `use game3dkit058`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit059

`import "std/game3dkit059"` · `use game3dkit059`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit060

`import "std/game3dkit060"` · `use game3dkit060`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit061

`import "std/game3dkit061"` · `use game3dkit061`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit062

`import "std/game3dkit062"` · `use game3dkit062`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit063

`import "std/game3dkit063"` · `use game3dkit063`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit064

`import "std/game3dkit064"` · `use game3dkit064`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit065

`import "std/game3dkit065"` · `use game3dkit065`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit066

`import "std/game3dkit066"` · `use game3dkit066`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit067

`import "std/game3dkit067"` · `use game3dkit067`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit068

`import "std/game3dkit068"` · `use game3dkit068`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit069

`import "std/game3dkit069"` · `use game3dkit069`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit070

`import "std/game3dkit070"` · `use game3dkit070`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit071

`import "std/game3dkit071"` · `use game3dkit071`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit072

`import "std/game3dkit072"` · `use game3dkit072`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit073

`import "std/game3dkit073"` · `use game3dkit073`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit074

`import "std/game3dkit074"` · `use game3dkit074`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit075

`import "std/game3dkit075"` · `use game3dkit075`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit076

`import "std/game3dkit076"` · `use game3dkit076`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit077

`import "std/game3dkit077"` · `use game3dkit077`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit078

`import "std/game3dkit078"` · `use game3dkit078`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit079

`import "std/game3dkit079"` · `use game3dkit079`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit080

`import "std/game3dkit080"` · `use game3dkit080`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit081

`import "std/game3dkit081"` · `use game3dkit081`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit082

`import "std/game3dkit082"` · `use game3dkit082`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit083

`import "std/game3dkit083"` · `use game3dkit083`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit084

`import "std/game3dkit084"` · `use game3dkit084`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit085

`import "std/game3dkit085"` · `use game3dkit085`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit086

`import "std/game3dkit086"` · `use game3dkit086`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit087

`import "std/game3dkit087"` · `use game3dkit087`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit088

`import "std/game3dkit088"` · `use game3dkit088`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit089

`import "std/game3dkit089"` · `use game3dkit089`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit090

`import "std/game3dkit090"` · `use game3dkit090`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit091

`import "std/game3dkit091"` · `use game3dkit091`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit092

`import "std/game3dkit092"` · `use game3dkit092`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit093

`import "std/game3dkit093"` · `use game3dkit093`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit094

`import "std/game3dkit094"` · `use game3dkit094`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit095

`import "std/game3dkit095"` · `use game3dkit095`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit096

`import "std/game3dkit096"` · `use game3dkit096`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit097

`import "std/game3dkit097"` · `use game3dkit097`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit098

`import "std/game3dkit098"` · `use game3dkit098`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit099

`import "std/game3dkit099"` · `use game3dkit099`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit100

`import "std/game3dkit100"` · `use game3dkit100`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit101

`import "std/game3dkit101"` · `use game3dkit101`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit102

`import "std/game3dkit102"` · `use game3dkit102`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit103

`import "std/game3dkit103"` · `use game3dkit103`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit104

`import "std/game3dkit104"` · `use game3dkit104`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit105

`import "std/game3dkit105"` · `use game3dkit105`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit106

`import "std/game3dkit106"` · `use game3dkit106`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit107

`import "std/game3dkit107"` · `use game3dkit107`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit108

`import "std/game3dkit108"` · `use game3dkit108`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit109

`import "std/game3dkit109"` · `use game3dkit109`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit110

`import "std/game3dkit110"` · `use game3dkit110`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit111

`import "std/game3dkit111"` · `use game3dkit111`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit112

`import "std/game3dkit112"` · `use game3dkit112`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit113

`import "std/game3dkit113"` · `use game3dkit113`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit114

`import "std/game3dkit114"` · `use game3dkit114`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit115

`import "std/game3dkit115"` · `use game3dkit115`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit116

`import "std/game3dkit116"` · `use game3dkit116`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit117

`import "std/game3dkit117"` · `use game3dkit117`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit118

`import "std/game3dkit118"` · `use game3dkit118`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit119

`import "std/game3dkit119"` · `use game3dkit119`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit120

`import "std/game3dkit120"` · `use game3dkit120`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit121

`import "std/game3dkit121"` · `use game3dkit121`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit122

`import "std/game3dkit122"` · `use game3dkit122`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit123

`import "std/game3dkit123"` · `use game3dkit123`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit124

`import "std/game3dkit124"` · `use game3dkit124`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit125

`import "std/game3dkit125"` · `use game3dkit125`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit126

`import "std/game3dkit126"` · `use game3dkit126`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit127

`import "std/game3dkit127"` · `use game3dkit127`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit128

`import "std/game3dkit128"` · `use game3dkit128`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit129

`import "std/game3dkit129"` · `use game3dkit129`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit130

`import "std/game3dkit130"` · `use game3dkit130`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit131

`import "std/game3dkit131"` · `use game3dkit131`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit132

`import "std/game3dkit132"` · `use game3dkit132`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit133

`import "std/game3dkit133"` · `use game3dkit133`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit134

`import "std/game3dkit134"` · `use game3dkit134`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit135

`import "std/game3dkit135"` · `use game3dkit135`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit136

`import "std/game3dkit136"` · `use game3dkit136`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit137

`import "std/game3dkit137"` · `use game3dkit137`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit138

`import "std/game3dkit138"` · `use game3dkit138`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit139

`import "std/game3dkit139"` · `use game3dkit139`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit140

`import "std/game3dkit140"` · `use game3dkit140`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit141

`import "std/game3dkit141"` · `use game3dkit141`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit142

`import "std/game3dkit142"` · `use game3dkit142`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit143

`import "std/game3dkit143"` · `use game3dkit143`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit144

`import "std/game3dkit144"` · `use game3dkit144`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit145

`import "std/game3dkit145"` · `use game3dkit145`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit146

`import "std/game3dkit146"` · `use game3dkit146`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit147

`import "std/game3dkit147"` · `use game3dkit147`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit148

`import "std/game3dkit148"` · `use game3dkit148`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit149

`import "std/game3dkit149"` · `use game3dkit149`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit150

`import "std/game3dkit150"` · `use game3dkit150`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit151

`import "std/game3dkit151"` · `use game3dkit151`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit152

`import "std/game3dkit152"` · `use game3dkit152`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit153

`import "std/game3dkit153"` · `use game3dkit153`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit154

`import "std/game3dkit154"` · `use game3dkit154`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit155

`import "std/game3dkit155"` · `use game3dkit155`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit156

`import "std/game3dkit156"` · `use game3dkit156`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit157

`import "std/game3dkit157"` · `use game3dkit157`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit158

`import "std/game3dkit158"` · `use game3dkit158`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit159

`import "std/game3dkit159"` · `use game3dkit159`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit160

`import "std/game3dkit160"` · `use game3dkit160`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit161

`import "std/game3dkit161"` · `use game3dkit161`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit162

`import "std/game3dkit162"` · `use game3dkit162`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit163

`import "std/game3dkit163"` · `use game3dkit163`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit164

`import "std/game3dkit164"` · `use game3dkit164`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit165

`import "std/game3dkit165"` · `use game3dkit165`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit166

`import "std/game3dkit166"` · `use game3dkit166`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit167

`import "std/game3dkit167"` · `use game3dkit167`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit168

`import "std/game3dkit168"` · `use game3dkit168`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit169

`import "std/game3dkit169"` · `use game3dkit169`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit170

`import "std/game3dkit170"` · `use game3dkit170`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit171

`import "std/game3dkit171"` · `use game3dkit171`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit172

`import "std/game3dkit172"` · `use game3dkit172`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit173

`import "std/game3dkit173"` · `use game3dkit173`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit174

`import "std/game3dkit174"` · `use game3dkit174`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit175

`import "std/game3dkit175"` · `use game3dkit175`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit176

`import "std/game3dkit176"` · `use game3dkit176`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit177

`import "std/game3dkit177"` · `use game3dkit177`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit178

`import "std/game3dkit178"` · `use game3dkit178`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit179

`import "std/game3dkit179"` · `use game3dkit179`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit180

`import "std/game3dkit180"` · `use game3dkit180`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit181

`import "std/game3dkit181"` · `use game3dkit181`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit182

`import "std/game3dkit182"` · `use game3dkit182`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit183

`import "std/game3dkit183"` · `use game3dkit183`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit184

`import "std/game3dkit184"` · `use game3dkit184`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit185

`import "std/game3dkit185"` · `use game3dkit185`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit186

`import "std/game3dkit186"` · `use game3dkit186`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit187

`import "std/game3dkit187"` · `use game3dkit187`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit188

`import "std/game3dkit188"` · `use game3dkit188`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit189

`import "std/game3dkit189"` · `use game3dkit189`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit190

`import "std/game3dkit190"` · `use game3dkit190`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit191

`import "std/game3dkit191"` · `use game3dkit191`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit192

`import "std/game3dkit192"` · `use game3dkit192`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit193

`import "std/game3dkit193"` · `use game3dkit193`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit194

`import "std/game3dkit194"` · `use game3dkit194`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit195

`import "std/game3dkit195"` · `use game3dkit195`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit196

`import "std/game3dkit196"` · `use game3dkit196`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit197

`import "std/game3dkit197"` · `use game3dkit197`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit198

`import "std/game3dkit198"` · `use game3dkit198`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit199

`import "std/game3dkit199"` · `use game3dkit199`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit200

`import "std/game3dkit200"` · `use game3dkit200`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit201

`import "std/game3dkit201"` · `use game3dkit201`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit202

`import "std/game3dkit202"` · `use game3dkit202`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit203

`import "std/game3dkit203"` · `use game3dkit203`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit204

`import "std/game3dkit204"` · `use game3dkit204`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit205

`import "std/game3dkit205"` · `use game3dkit205`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit206

`import "std/game3dkit206"` · `use game3dkit206`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit207

`import "std/game3dkit207"` · `use game3dkit207`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit208

`import "std/game3dkit208"` · `use game3dkit208`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit209

`import "std/game3dkit209"` · `use game3dkit209`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit210

`import "std/game3dkit210"` · `use game3dkit210`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit211

`import "std/game3dkit211"` · `use game3dkit211`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit212

`import "std/game3dkit212"` · `use game3dkit212`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit213

`import "std/game3dkit213"` · `use game3dkit213`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit214

`import "std/game3dkit214"` · `use game3dkit214`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit215

`import "std/game3dkit215"` · `use game3dkit215`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit216

`import "std/game3dkit216"` · `use game3dkit216`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit217

`import "std/game3dkit217"` · `use game3dkit217`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit218

`import "std/game3dkit218"` · `use game3dkit218`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit219

`import "std/game3dkit219"` · `use game3dkit219`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit220

`import "std/game3dkit220"` · `use game3dkit220`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit221

`import "std/game3dkit221"` · `use game3dkit221`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit222

`import "std/game3dkit222"` · `use game3dkit222`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit223

`import "std/game3dkit223"` · `use game3dkit223`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit224

`import "std/game3dkit224"` · `use game3dkit224`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit225

`import "std/game3dkit225"` · `use game3dkit225`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit226

`import "std/game3dkit226"` · `use game3dkit226`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit227

`import "std/game3dkit227"` · `use game3dkit227`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit228

`import "std/game3dkit228"` · `use game3dkit228`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit229

`import "std/game3dkit229"` · `use game3dkit229`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit230

`import "std/game3dkit230"` · `use game3dkit230`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit231

`import "std/game3dkit231"` · `use game3dkit231`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit232

`import "std/game3dkit232"` · `use game3dkit232`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit233

`import "std/game3dkit233"` · `use game3dkit233`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit234

`import "std/game3dkit234"` · `use game3dkit234`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit235

`import "std/game3dkit235"` · `use game3dkit235`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit236

`import "std/game3dkit236"` · `use game3dkit236`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit237

`import "std/game3dkit237"` · `use game3dkit237`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit238

`import "std/game3dkit238"` · `use game3dkit238`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit239

`import "std/game3dkit239"` · `use game3dkit239`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit240

`import "std/game3dkit240"` · `use game3dkit240`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit241

`import "std/game3dkit241"` · `use game3dkit241`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit242

`import "std/game3dkit242"` · `use game3dkit242`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit243

`import "std/game3dkit243"` · `use game3dkit243`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit244

`import "std/game3dkit244"` · `use game3dkit244`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit245

`import "std/game3dkit245"` · `use game3dkit245`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit246

`import "std/game3dkit246"` · `use game3dkit246`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit247

`import "std/game3dkit247"` · `use game3dkit247`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit248

`import "std/game3dkit248"` · `use game3dkit248`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit249

`import "std/game3dkit249"` · `use game3dkit249`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit250

`import "std/game3dkit250"` · `use game3dkit250`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit251

`import "std/game3dkit251"` · `use game3dkit251`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit252

`import "std/game3dkit252"` · `use game3dkit252`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit253

`import "std/game3dkit253"` · `use game3dkit253`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit254

`import "std/game3dkit254"` · `use game3dkit254`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit255

`import "std/game3dkit255"` · `use game3dkit255`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit256

`import "std/game3dkit256"` · `use game3dkit256`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit257

`import "std/game3dkit257"` · `use game3dkit257`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit258

`import "std/game3dkit258"` · `use game3dkit258`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit259

`import "std/game3dkit259"` · `use game3dkit259`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit260

`import "std/game3dkit260"` · `use game3dkit260`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit261

`import "std/game3dkit261"` · `use game3dkit261`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit262

`import "std/game3dkit262"` · `use game3dkit262`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit263

`import "std/game3dkit263"` · `use game3dkit263`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit264

`import "std/game3dkit264"` · `use game3dkit264`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit265

`import "std/game3dkit265"` · `use game3dkit265`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit266

`import "std/game3dkit266"` · `use game3dkit266`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit267

`import "std/game3dkit267"` · `use game3dkit267`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit268

`import "std/game3dkit268"` · `use game3dkit268`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit269

`import "std/game3dkit269"` · `use game3dkit269`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit270

`import "std/game3dkit270"` · `use game3dkit270`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit271

`import "std/game3dkit271"` · `use game3dkit271`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit272

`import "std/game3dkit272"` · `use game3dkit272`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit273

`import "std/game3dkit273"` · `use game3dkit273`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit274

`import "std/game3dkit274"` · `use game3dkit274`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit275

`import "std/game3dkit275"` · `use game3dkit275`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit276

`import "std/game3dkit276"` · `use game3dkit276`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit277

`import "std/game3dkit277"` · `use game3dkit277`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit278

`import "std/game3dkit278"` · `use game3dkit278`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit279

`import "std/game3dkit279"` · `use game3dkit279`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit280

`import "std/game3dkit280"` · `use game3dkit280`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit281

`import "std/game3dkit281"` · `use game3dkit281`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit282

`import "std/game3dkit282"` · `use game3dkit282`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit283

`import "std/game3dkit283"` · `use game3dkit283`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit284

`import "std/game3dkit284"` · `use game3dkit284`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit285

`import "std/game3dkit285"` · `use game3dkit285`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit286

`import "std/game3dkit286"` · `use game3dkit286`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit287

`import "std/game3dkit287"` · `use game3dkit287`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit288

`import "std/game3dkit288"` · `use game3dkit288`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit289

`import "std/game3dkit289"` · `use game3dkit289`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit290

`import "std/game3dkit290"` · `use game3dkit290`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit291

`import "std/game3dkit291"` · `use game3dkit291`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit292

`import "std/game3dkit292"` · `use game3dkit292`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit293

`import "std/game3dkit293"` · `use game3dkit293`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit294

`import "std/game3dkit294"` · `use game3dkit294`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit295

`import "std/game3dkit295"` · `use game3dkit295`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit296

`import "std/game3dkit296"` · `use game3dkit296`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit297

`import "std/game3dkit297"` · `use game3dkit297`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit298

`import "std/game3dkit298"` · `use game3dkit298`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit299

`import "std/game3dkit299"` · `use game3dkit299`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit300

`import "std/game3dkit300"` · `use game3dkit300`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit301

`import "std/game3dkit301"` · `use game3dkit301`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit302

`import "std/game3dkit302"` · `use game3dkit302`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit303

`import "std/game3dkit303"` · `use game3dkit303`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit304

`import "std/game3dkit304"` · `use game3dkit304`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit305

`import "std/game3dkit305"` · `use game3dkit305`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit306

`import "std/game3dkit306"` · `use game3dkit306`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit307

`import "std/game3dkit307"` · `use game3dkit307`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit308

`import "std/game3dkit308"` · `use game3dkit308`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit309

`import "std/game3dkit309"` · `use game3dkit309`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit310

`import "std/game3dkit310"` · `use game3dkit310`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit311

`import "std/game3dkit311"` · `use game3dkit311`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit312

`import "std/game3dkit312"` · `use game3dkit312`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit313

`import "std/game3dkit313"` · `use game3dkit313`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit314

`import "std/game3dkit314"` · `use game3dkit314`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit315

`import "std/game3dkit315"` · `use game3dkit315`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit316

`import "std/game3dkit316"` · `use game3dkit316`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit317

`import "std/game3dkit317"` · `use game3dkit317`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit318

`import "std/game3dkit318"` · `use game3dkit318`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit319

`import "std/game3dkit319"` · `use game3dkit319`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit320

`import "std/game3dkit320"` · `use game3dkit320`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit321

`import "std/game3dkit321"` · `use game3dkit321`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit322

`import "std/game3dkit322"` · `use game3dkit322`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit323

`import "std/game3dkit323"` · `use game3dkit323`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit324

`import "std/game3dkit324"` · `use game3dkit324`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit325

`import "std/game3dkit325"` · `use game3dkit325`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit326

`import "std/game3dkit326"` · `use game3dkit326`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit327

`import "std/game3dkit327"` · `use game3dkit327`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit328

`import "std/game3dkit328"` · `use game3dkit328`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit329

`import "std/game3dkit329"` · `use game3dkit329`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit330

`import "std/game3dkit330"` · `use game3dkit330`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit331

`import "std/game3dkit331"` · `use game3dkit331`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit332

`import "std/game3dkit332"` · `use game3dkit332`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit333

`import "std/game3dkit333"` · `use game3dkit333`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit334

`import "std/game3dkit334"` · `use game3dkit334`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit335

`import "std/game3dkit335"` · `use game3dkit335`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit336

`import "std/game3dkit336"` · `use game3dkit336`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit337

`import "std/game3dkit337"` · `use game3dkit337`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit338

`import "std/game3dkit338"` · `use game3dkit338`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit339

`import "std/game3dkit339"` · `use game3dkit339`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit340

`import "std/game3dkit340"` · `use game3dkit340`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit341

`import "std/game3dkit341"` · `use game3dkit341`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit342

`import "std/game3dkit342"` · `use game3dkit342`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit343

`import "std/game3dkit343"` · `use game3dkit343`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit344

`import "std/game3dkit344"` · `use game3dkit344`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit345

`import "std/game3dkit345"` · `use game3dkit345`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit346

`import "std/game3dkit346"` · `use game3dkit346`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit347

`import "std/game3dkit347"` · `use game3dkit347`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit348

`import "std/game3dkit348"` · `use game3dkit348`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit349

`import "std/game3dkit349"` · `use game3dkit349`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit350

`import "std/game3dkit350"` · `use game3dkit350`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit351

`import "std/game3dkit351"` · `use game3dkit351`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit352

`import "std/game3dkit352"` · `use game3dkit352`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit353

`import "std/game3dkit353"` · `use game3dkit353`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit354

`import "std/game3dkit354"` · `use game3dkit354`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit355

`import "std/game3dkit355"` · `use game3dkit355`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit356

`import "std/game3dkit356"` · `use game3dkit356`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit357

`import "std/game3dkit357"` · `use game3dkit357`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit358

`import "std/game3dkit358"` · `use game3dkit358`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit359

`import "std/game3dkit359"` · `use game3dkit359`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit360

`import "std/game3dkit360"` · `use game3dkit360`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit361

`import "std/game3dkit361"` · `use game3dkit361`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit362

`import "std/game3dkit362"` · `use game3dkit362`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit363

`import "std/game3dkit363"` · `use game3dkit363`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit364

`import "std/game3dkit364"` · `use game3dkit364`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit365

`import "std/game3dkit365"` · `use game3dkit365`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit366

`import "std/game3dkit366"` · `use game3dkit366`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit367

`import "std/game3dkit367"` · `use game3dkit367`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit368

`import "std/game3dkit368"` · `use game3dkit368`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit369

`import "std/game3dkit369"` · `use game3dkit369`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit370

`import "std/game3dkit370"` · `use game3dkit370`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit371

`import "std/game3dkit371"` · `use game3dkit371`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit372

`import "std/game3dkit372"` · `use game3dkit372`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit373

`import "std/game3dkit373"` · `use game3dkit373`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit374

`import "std/game3dkit374"` · `use game3dkit374`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit375

`import "std/game3dkit375"` · `use game3dkit375`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit376

`import "std/game3dkit376"` · `use game3dkit376`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit377

`import "std/game3dkit377"` · `use game3dkit377`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit378

`import "std/game3dkit378"` · `use game3dkit378`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit379

`import "std/game3dkit379"` · `use game3dkit379`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit380

`import "std/game3dkit380"` · `use game3dkit380`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit381

`import "std/game3dkit381"` · `use game3dkit381`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit382

`import "std/game3dkit382"` · `use game3dkit382`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit383

`import "std/game3dkit383"` · `use game3dkit383`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit384

`import "std/game3dkit384"` · `use game3dkit384`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit385

`import "std/game3dkit385"` · `use game3dkit385`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit386

`import "std/game3dkit386"` · `use game3dkit386`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit387

`import "std/game3dkit387"` · `use game3dkit387`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit388

`import "std/game3dkit388"` · `use game3dkit388`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit389

`import "std/game3dkit389"` · `use game3dkit389`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit390

`import "std/game3dkit390"` · `use game3dkit390`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit391

`import "std/game3dkit391"` · `use game3dkit391`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit392

`import "std/game3dkit392"` · `use game3dkit392`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit393

`import "std/game3dkit393"` · `use game3dkit393`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit394

`import "std/game3dkit394"` · `use game3dkit394`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit395

`import "std/game3dkit395"` · `use game3dkit395`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit396

`import "std/game3dkit396"` · `use game3dkit396`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit397

`import "std/game3dkit397"` · `use game3dkit397`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit398

`import "std/game3dkit398"` · `use game3dkit398`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit399

`import "std/game3dkit399"` · `use game3dkit399`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit400

`import "std/game3dkit400"` · `use game3dkit400`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit401

`import "std/game3dkit401"` · `use game3dkit401`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit402

`import "std/game3dkit402"` · `use game3dkit402`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit403

`import "std/game3dkit403"` · `use game3dkit403`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit404

`import "std/game3dkit404"` · `use game3dkit404`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit405

`import "std/game3dkit405"` · `use game3dkit405`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit406

`import "std/game3dkit406"` · `use game3dkit406`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit407

`import "std/game3dkit407"` · `use game3dkit407`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit408

`import "std/game3dkit408"` · `use game3dkit408`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit409

`import "std/game3dkit409"` · `use game3dkit409`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit410

`import "std/game3dkit410"` · `use game3dkit410`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit411

`import "std/game3dkit411"` · `use game3dkit411`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit412

`import "std/game3dkit412"` · `use game3dkit412`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit413

`import "std/game3dkit413"` · `use game3dkit413`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit414

`import "std/game3dkit414"` · `use game3dkit414`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit415

`import "std/game3dkit415"` · `use game3dkit415`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit416

`import "std/game3dkit416"` · `use game3dkit416`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit417

`import "std/game3dkit417"` · `use game3dkit417`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit418

`import "std/game3dkit418"` · `use game3dkit418`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit419

`import "std/game3dkit419"` · `use game3dkit419`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit420

`import "std/game3dkit420"` · `use game3dkit420`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit421

`import "std/game3dkit421"` · `use game3dkit421`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit422

`import "std/game3dkit422"` · `use game3dkit422`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit423

`import "std/game3dkit423"` · `use game3dkit423`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit424

`import "std/game3dkit424"` · `use game3dkit424`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit425

`import "std/game3dkit425"` · `use game3dkit425`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit426

`import "std/game3dkit426"` · `use game3dkit426`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit427

`import "std/game3dkit427"` · `use game3dkit427`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit428

`import "std/game3dkit428"` · `use game3dkit428`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit429

`import "std/game3dkit429"` · `use game3dkit429`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit430

`import "std/game3dkit430"` · `use game3dkit430`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit431

`import "std/game3dkit431"` · `use game3dkit431`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit432

`import "std/game3dkit432"` · `use game3dkit432`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit433

`import "std/game3dkit433"` · `use game3dkit433`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit434

`import "std/game3dkit434"` · `use game3dkit434`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit435

`import "std/game3dkit435"` · `use game3dkit435`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit436

`import "std/game3dkit436"` · `use game3dkit436`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit437

`import "std/game3dkit437"` · `use game3dkit437`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit438

`import "std/game3dkit438"` · `use game3dkit438`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit439

`import "std/game3dkit439"` · `use game3dkit439`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit440

`import "std/game3dkit440"` · `use game3dkit440`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit441

`import "std/game3dkit441"` · `use game3dkit441`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit442

`import "std/game3dkit442"` · `use game3dkit442`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit443

`import "std/game3dkit443"` · `use game3dkit443`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit444

`import "std/game3dkit444"` · `use game3dkit444`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit445

`import "std/game3dkit445"` · `use game3dkit445`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit446

`import "std/game3dkit446"` · `use game3dkit446`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit447

`import "std/game3dkit447"` · `use game3dkit447`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit448

`import "std/game3dkit448"` · `use game3dkit448`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit449

`import "std/game3dkit449"` · `use game3dkit449`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit450

`import "std/game3dkit450"` · `use game3dkit450`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit451

`import "std/game3dkit451"` · `use game3dkit451`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit452

`import "std/game3dkit452"` · `use game3dkit452`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit453

`import "std/game3dkit453"` · `use game3dkit453`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit454

`import "std/game3dkit454"` · `use game3dkit454`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit455

`import "std/game3dkit455"` · `use game3dkit455`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit456

`import "std/game3dkit456"` · `use game3dkit456`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit457

`import "std/game3dkit457"` · `use game3dkit457`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit458

`import "std/game3dkit458"` · `use game3dkit458`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit459

`import "std/game3dkit459"` · `use game3dkit459`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit460

`import "std/game3dkit460"` · `use game3dkit460`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit461

`import "std/game3dkit461"` · `use game3dkit461`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit462

`import "std/game3dkit462"` · `use game3dkit462`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit463

`import "std/game3dkit463"` · `use game3dkit463`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit464

`import "std/game3dkit464"` · `use game3dkit464`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit465

`import "std/game3dkit465"` · `use game3dkit465`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit466

`import "std/game3dkit466"` · `use game3dkit466`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit467

`import "std/game3dkit467"` · `use game3dkit467`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit468

`import "std/game3dkit468"` · `use game3dkit468`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit469

`import "std/game3dkit469"` · `use game3dkit469`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit470

`import "std/game3dkit470"` · `use game3dkit470`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit471

`import "std/game3dkit471"` · `use game3dkit471`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit472

`import "std/game3dkit472"` · `use game3dkit472`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit473

`import "std/game3dkit473"` · `use game3dkit473`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit474

`import "std/game3dkit474"` · `use game3dkit474`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit475

`import "std/game3dkit475"` · `use game3dkit475`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit476

`import "std/game3dkit476"` · `use game3dkit476`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit477

`import "std/game3dkit477"` · `use game3dkit477`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit478

`import "std/game3dkit478"` · `use game3dkit478`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit479

`import "std/game3dkit479"` · `use game3dkit479`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit480

`import "std/game3dkit480"` · `use game3dkit480`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit481

`import "std/game3dkit481"` · `use game3dkit481`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit482

`import "std/game3dkit482"` · `use game3dkit482`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit483

`import "std/game3dkit483"` · `use game3dkit483`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit484

`import "std/game3dkit484"` · `use game3dkit484`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit485

`import "std/game3dkit485"` · `use game3dkit485`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit486

`import "std/game3dkit486"` · `use game3dkit486`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit487

`import "std/game3dkit487"` · `use game3dkit487`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit488

`import "std/game3dkit488"` · `use game3dkit488`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit489

`import "std/game3dkit489"` · `use game3dkit489`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit490

`import "std/game3dkit490"` · `use game3dkit490`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit491

`import "std/game3dkit491"` · `use game3dkit491`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit492

`import "std/game3dkit492"` · `use game3dkit492`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit493

`import "std/game3dkit493"` · `use game3dkit493`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit494

`import "std/game3dkit494"` · `use game3dkit494`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/game3dkit495

`import "std/game3dkit495"` · `use game3dkit495`

- `yawFromDir(dx number, dz number) → number`
- `pitchFromDir(dx number, dy number, dz number) → number`

## std/game3dkit496

`import "std/game3dkit496"` · `use game3dkit496`

- `rayPlaneHitT(ox number, oy number, oz number, dx number, dy number, dz number, py number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit497

`import "std/game3dkit497"` · `use game3dkit497`

- `smooth(cur number, target number, dt number) → number`
- `lerp3x(ax number, bx number, t number) → number`

## std/game3dkit498

`import "std/game3dkit498"` · `use game3dkit498`

- `dot3(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossX(ax number, ay number, az number, bx number, by number, bz number) → number`
- `crossY(ax number, ay number, az number, bx number, by number, bz number) → number`

## std/game3dkit499

`import "std/game3dkit499"` · `use game3dkit499`

- `len3(x number, y number, z number) → number`
- `normalize3x(x number, y number, z number) → number`
- `normalize3y(x number, y number, z number) → number`

## std/game3dkit500

`import "std/game3dkit500"` · `use game3dkit500`

- `normalize3z(x number, y number, z number) → number`
- `dist3(x0 number, y0 number, z0 number, x1 number, y1 number, z1 number) → number`

## std/giskit001

`import "std/giskit001"` · `use giskit001`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit002

`import "std/giskit002"` · `use giskit002`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit003

`import "std/giskit003"` · `use giskit003`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit004

`import "std/giskit004"` · `use giskit004`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit005

`import "std/giskit005"` · `use giskit005`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit006

`import "std/giskit006"` · `use giskit006`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit007

`import "std/giskit007"` · `use giskit007`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit008

`import "std/giskit008"` · `use giskit008`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit009

`import "std/giskit009"` · `use giskit009`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit010

`import "std/giskit010"` · `use giskit010`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit011

`import "std/giskit011"` · `use giskit011`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit012

`import "std/giskit012"` · `use giskit012`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit013

`import "std/giskit013"` · `use giskit013`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit014

`import "std/giskit014"` · `use giskit014`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit015

`import "std/giskit015"` · `use giskit015`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit016

`import "std/giskit016"` · `use giskit016`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit017

`import "std/giskit017"` · `use giskit017`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit018

`import "std/giskit018"` · `use giskit018`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit019

`import "std/giskit019"` · `use giskit019`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit020

`import "std/giskit020"` · `use giskit020`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit021

`import "std/giskit021"` · `use giskit021`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit022

`import "std/giskit022"` · `use giskit022`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit023

`import "std/giskit023"` · `use giskit023`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit024

`import "std/giskit024"` · `use giskit024`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit025

`import "std/giskit025"` · `use giskit025`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit026

`import "std/giskit026"` · `use giskit026`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit027

`import "std/giskit027"` · `use giskit027`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit028

`import "std/giskit028"` · `use giskit028`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit029

`import "std/giskit029"` · `use giskit029`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit030

`import "std/giskit030"` · `use giskit030`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit031

`import "std/giskit031"` · `use giskit031`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit032

`import "std/giskit032"` · `use giskit032`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit033

`import "std/giskit033"` · `use giskit033`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit034

`import "std/giskit034"` · `use giskit034`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit035

`import "std/giskit035"` · `use giskit035`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit036

`import "std/giskit036"` · `use giskit036`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit037

`import "std/giskit037"` · `use giskit037`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit038

`import "std/giskit038"` · `use giskit038`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit039

`import "std/giskit039"` · `use giskit039`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit040

`import "std/giskit040"` · `use giskit040`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit041

`import "std/giskit041"` · `use giskit041`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit042

`import "std/giskit042"` · `use giskit042`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit043

`import "std/giskit043"` · `use giskit043`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit044

`import "std/giskit044"` · `use giskit044`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit045

`import "std/giskit045"` · `use giskit045`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit046

`import "std/giskit046"` · `use giskit046`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit047

`import "std/giskit047"` · `use giskit047`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit048

`import "std/giskit048"` · `use giskit048`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit049

`import "std/giskit049"` · `use giskit049`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit050

`import "std/giskit050"` · `use giskit050`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit051

`import "std/giskit051"` · `use giskit051`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit052

`import "std/giskit052"` · `use giskit052`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit053

`import "std/giskit053"` · `use giskit053`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit054

`import "std/giskit054"` · `use giskit054`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit055

`import "std/giskit055"` · `use giskit055`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit056

`import "std/giskit056"` · `use giskit056`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit057

`import "std/giskit057"` · `use giskit057`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit058

`import "std/giskit058"` · `use giskit058`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit059

`import "std/giskit059"` · `use giskit059`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit060

`import "std/giskit060"` · `use giskit060`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit061

`import "std/giskit061"` · `use giskit061`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit062

`import "std/giskit062"` · `use giskit062`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit063

`import "std/giskit063"` · `use giskit063`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit064

`import "std/giskit064"` · `use giskit064`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit065

`import "std/giskit065"` · `use giskit065`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit066

`import "std/giskit066"` · `use giskit066`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit067

`import "std/giskit067"` · `use giskit067`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit068

`import "std/giskit068"` · `use giskit068`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit069

`import "std/giskit069"` · `use giskit069`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit070

`import "std/giskit070"` · `use giskit070`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit071

`import "std/giskit071"` · `use giskit071`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit072

`import "std/giskit072"` · `use giskit072`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit073

`import "std/giskit073"` · `use giskit073`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit074

`import "std/giskit074"` · `use giskit074`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit075

`import "std/giskit075"` · `use giskit075`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit076

`import "std/giskit076"` · `use giskit076`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit077

`import "std/giskit077"` · `use giskit077`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit078

`import "std/giskit078"` · `use giskit078`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit079

`import "std/giskit079"` · `use giskit079`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit080

`import "std/giskit080"` · `use giskit080`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit081

`import "std/giskit081"` · `use giskit081`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit082

`import "std/giskit082"` · `use giskit082`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit083

`import "std/giskit083"` · `use giskit083`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit084

`import "std/giskit084"` · `use giskit084`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit085

`import "std/giskit085"` · `use giskit085`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit086

`import "std/giskit086"` · `use giskit086`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit087

`import "std/giskit087"` · `use giskit087`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit088

`import "std/giskit088"` · `use giskit088`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit089

`import "std/giskit089"` · `use giskit089`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit090

`import "std/giskit090"` · `use giskit090`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit091

`import "std/giskit091"` · `use giskit091`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit092

`import "std/giskit092"` · `use giskit092`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit093

`import "std/giskit093"` · `use giskit093`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit094

`import "std/giskit094"` · `use giskit094`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit095

`import "std/giskit095"` · `use giskit095`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit096

`import "std/giskit096"` · `use giskit096`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit097

`import "std/giskit097"` · `use giskit097`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit098

`import "std/giskit098"` · `use giskit098`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit099

`import "std/giskit099"` · `use giskit099`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit100

`import "std/giskit100"` · `use giskit100`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit101

`import "std/giskit101"` · `use giskit101`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit102

`import "std/giskit102"` · `use giskit102`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit103

`import "std/giskit103"` · `use giskit103`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit104

`import "std/giskit104"` · `use giskit104`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit105

`import "std/giskit105"` · `use giskit105`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit106

`import "std/giskit106"` · `use giskit106`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit107

`import "std/giskit107"` · `use giskit107`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit108

`import "std/giskit108"` · `use giskit108`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit109

`import "std/giskit109"` · `use giskit109`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit110

`import "std/giskit110"` · `use giskit110`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit111

`import "std/giskit111"` · `use giskit111`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit112

`import "std/giskit112"` · `use giskit112`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit113

`import "std/giskit113"` · `use giskit113`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit114

`import "std/giskit114"` · `use giskit114`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit115

`import "std/giskit115"` · `use giskit115`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit116

`import "std/giskit116"` · `use giskit116`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit117

`import "std/giskit117"` · `use giskit117`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit118

`import "std/giskit118"` · `use giskit118`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit119

`import "std/giskit119"` · `use giskit119`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit120

`import "std/giskit120"` · `use giskit120`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit121

`import "std/giskit121"` · `use giskit121`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit122

`import "std/giskit122"` · `use giskit122`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit123

`import "std/giskit123"` · `use giskit123`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit124

`import "std/giskit124"` · `use giskit124`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit125

`import "std/giskit125"` · `use giskit125`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit126

`import "std/giskit126"` · `use giskit126`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit127

`import "std/giskit127"` · `use giskit127`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit128

`import "std/giskit128"` · `use giskit128`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit129

`import "std/giskit129"` · `use giskit129`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit130

`import "std/giskit130"` · `use giskit130`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit131

`import "std/giskit131"` · `use giskit131`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit132

`import "std/giskit132"` · `use giskit132`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit133

`import "std/giskit133"` · `use giskit133`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit134

`import "std/giskit134"` · `use giskit134`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit135

`import "std/giskit135"` · `use giskit135`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit136

`import "std/giskit136"` · `use giskit136`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit137

`import "std/giskit137"` · `use giskit137`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit138

`import "std/giskit138"` · `use giskit138`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit139

`import "std/giskit139"` · `use giskit139`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit140

`import "std/giskit140"` · `use giskit140`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit141

`import "std/giskit141"` · `use giskit141`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit142

`import "std/giskit142"` · `use giskit142`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit143

`import "std/giskit143"` · `use giskit143`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit144

`import "std/giskit144"` · `use giskit144`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit145

`import "std/giskit145"` · `use giskit145`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit146

`import "std/giskit146"` · `use giskit146`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit147

`import "std/giskit147"` · `use giskit147`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit148

`import "std/giskit148"` · `use giskit148`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit149

`import "std/giskit149"` · `use giskit149`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit150

`import "std/giskit150"` · `use giskit150`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit151

`import "std/giskit151"` · `use giskit151`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit152

`import "std/giskit152"` · `use giskit152`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit153

`import "std/giskit153"` · `use giskit153`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit154

`import "std/giskit154"` · `use giskit154`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit155

`import "std/giskit155"` · `use giskit155`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit156

`import "std/giskit156"` · `use giskit156`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit157

`import "std/giskit157"` · `use giskit157`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit158

`import "std/giskit158"` · `use giskit158`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit159

`import "std/giskit159"` · `use giskit159`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit160

`import "std/giskit160"` · `use giskit160`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit161

`import "std/giskit161"` · `use giskit161`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit162

`import "std/giskit162"` · `use giskit162`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit163

`import "std/giskit163"` · `use giskit163`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit164

`import "std/giskit164"` · `use giskit164`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit165

`import "std/giskit165"` · `use giskit165`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit166

`import "std/giskit166"` · `use giskit166`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit167

`import "std/giskit167"` · `use giskit167`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit168

`import "std/giskit168"` · `use giskit168`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit169

`import "std/giskit169"` · `use giskit169`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit170

`import "std/giskit170"` · `use giskit170`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit171

`import "std/giskit171"` · `use giskit171`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit172

`import "std/giskit172"` · `use giskit172`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit173

`import "std/giskit173"` · `use giskit173`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit174

`import "std/giskit174"` · `use giskit174`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit175

`import "std/giskit175"` · `use giskit175`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit176

`import "std/giskit176"` · `use giskit176`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit177

`import "std/giskit177"` · `use giskit177`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit178

`import "std/giskit178"` · `use giskit178`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit179

`import "std/giskit179"` · `use giskit179`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit180

`import "std/giskit180"` · `use giskit180`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit181

`import "std/giskit181"` · `use giskit181`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit182

`import "std/giskit182"` · `use giskit182`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit183

`import "std/giskit183"` · `use giskit183`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit184

`import "std/giskit184"` · `use giskit184`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit185

`import "std/giskit185"` · `use giskit185`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit186

`import "std/giskit186"` · `use giskit186`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit187

`import "std/giskit187"` · `use giskit187`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit188

`import "std/giskit188"` · `use giskit188`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit189

`import "std/giskit189"` · `use giskit189`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit190

`import "std/giskit190"` · `use giskit190`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit191

`import "std/giskit191"` · `use giskit191`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit192

`import "std/giskit192"` · `use giskit192`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit193

`import "std/giskit193"` · `use giskit193`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit194

`import "std/giskit194"` · `use giskit194`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit195

`import "std/giskit195"` · `use giskit195`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit196

`import "std/giskit196"` · `use giskit196`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit197

`import "std/giskit197"` · `use giskit197`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit198

`import "std/giskit198"` · `use giskit198`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit199

`import "std/giskit199"` · `use giskit199`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit200

`import "std/giskit200"` · `use giskit200`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit201

`import "std/giskit201"` · `use giskit201`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit202

`import "std/giskit202"` · `use giskit202`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit203

`import "std/giskit203"` · `use giskit203`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit204

`import "std/giskit204"` · `use giskit204`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit205

`import "std/giskit205"` · `use giskit205`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit206

`import "std/giskit206"` · `use giskit206`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit207

`import "std/giskit207"` · `use giskit207`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit208

`import "std/giskit208"` · `use giskit208`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit209

`import "std/giskit209"` · `use giskit209`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit210

`import "std/giskit210"` · `use giskit210`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit211

`import "std/giskit211"` · `use giskit211`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit212

`import "std/giskit212"` · `use giskit212`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit213

`import "std/giskit213"` · `use giskit213`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit214

`import "std/giskit214"` · `use giskit214`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit215

`import "std/giskit215"` · `use giskit215`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit216

`import "std/giskit216"` · `use giskit216`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit217

`import "std/giskit217"` · `use giskit217`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit218

`import "std/giskit218"` · `use giskit218`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit219

`import "std/giskit219"` · `use giskit219`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit220

`import "std/giskit220"` · `use giskit220`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit221

`import "std/giskit221"` · `use giskit221`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit222

`import "std/giskit222"` · `use giskit222`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit223

`import "std/giskit223"` · `use giskit223`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit224

`import "std/giskit224"` · `use giskit224`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit225

`import "std/giskit225"` · `use giskit225`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit226

`import "std/giskit226"` · `use giskit226`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit227

`import "std/giskit227"` · `use giskit227`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit228

`import "std/giskit228"` · `use giskit228`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit229

`import "std/giskit229"` · `use giskit229`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit230

`import "std/giskit230"` · `use giskit230`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit231

`import "std/giskit231"` · `use giskit231`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit232

`import "std/giskit232"` · `use giskit232`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit233

`import "std/giskit233"` · `use giskit233`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit234

`import "std/giskit234"` · `use giskit234`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit235

`import "std/giskit235"` · `use giskit235`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit236

`import "std/giskit236"` · `use giskit236`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit237

`import "std/giskit237"` · `use giskit237`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit238

`import "std/giskit238"` · `use giskit238`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit239

`import "std/giskit239"` · `use giskit239`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit240

`import "std/giskit240"` · `use giskit240`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit241

`import "std/giskit241"` · `use giskit241`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit242

`import "std/giskit242"` · `use giskit242`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit243

`import "std/giskit243"` · `use giskit243`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit244

`import "std/giskit244"` · `use giskit244`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit245

`import "std/giskit245"` · `use giskit245`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit246

`import "std/giskit246"` · `use giskit246`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit247

`import "std/giskit247"` · `use giskit247`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit248

`import "std/giskit248"` · `use giskit248`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit249

`import "std/giskit249"` · `use giskit249`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit250

`import "std/giskit250"` · `use giskit250`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit251

`import "std/giskit251"` · `use giskit251`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit252

`import "std/giskit252"` · `use giskit252`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit253

`import "std/giskit253"` · `use giskit253`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit254

`import "std/giskit254"` · `use giskit254`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit255

`import "std/giskit255"` · `use giskit255`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit256

`import "std/giskit256"` · `use giskit256`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit257

`import "std/giskit257"` · `use giskit257`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit258

`import "std/giskit258"` · `use giskit258`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit259

`import "std/giskit259"` · `use giskit259`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit260

`import "std/giskit260"` · `use giskit260`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit261

`import "std/giskit261"` · `use giskit261`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit262

`import "std/giskit262"` · `use giskit262`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit263

`import "std/giskit263"` · `use giskit263`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit264

`import "std/giskit264"` · `use giskit264`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit265

`import "std/giskit265"` · `use giskit265`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit266

`import "std/giskit266"` · `use giskit266`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit267

`import "std/giskit267"` · `use giskit267`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit268

`import "std/giskit268"` · `use giskit268`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit269

`import "std/giskit269"` · `use giskit269`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit270

`import "std/giskit270"` · `use giskit270`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit271

`import "std/giskit271"` · `use giskit271`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit272

`import "std/giskit272"` · `use giskit272`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit273

`import "std/giskit273"` · `use giskit273`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit274

`import "std/giskit274"` · `use giskit274`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit275

`import "std/giskit275"` · `use giskit275`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit276

`import "std/giskit276"` · `use giskit276`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit277

`import "std/giskit277"` · `use giskit277`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit278

`import "std/giskit278"` · `use giskit278`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit279

`import "std/giskit279"` · `use giskit279`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit280

`import "std/giskit280"` · `use giskit280`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit281

`import "std/giskit281"` · `use giskit281`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit282

`import "std/giskit282"` · `use giskit282`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit283

`import "std/giskit283"` · `use giskit283`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit284

`import "std/giskit284"` · `use giskit284`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit285

`import "std/giskit285"` · `use giskit285`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit286

`import "std/giskit286"` · `use giskit286`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit287

`import "std/giskit287"` · `use giskit287`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit288

`import "std/giskit288"` · `use giskit288`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit289

`import "std/giskit289"` · `use giskit289`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit290

`import "std/giskit290"` · `use giskit290`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit291

`import "std/giskit291"` · `use giskit291`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit292

`import "std/giskit292"` · `use giskit292`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit293

`import "std/giskit293"` · `use giskit293`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit294

`import "std/giskit294"` · `use giskit294`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit295

`import "std/giskit295"` · `use giskit295`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit296

`import "std/giskit296"` · `use giskit296`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit297

`import "std/giskit297"` · `use giskit297`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit298

`import "std/giskit298"` · `use giskit298`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit299

`import "std/giskit299"` · `use giskit299`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit300

`import "std/giskit300"` · `use giskit300`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit301

`import "std/giskit301"` · `use giskit301`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit302

`import "std/giskit302"` · `use giskit302`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit303

`import "std/giskit303"` · `use giskit303`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit304

`import "std/giskit304"` · `use giskit304`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit305

`import "std/giskit305"` · `use giskit305`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit306

`import "std/giskit306"` · `use giskit306`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit307

`import "std/giskit307"` · `use giskit307`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit308

`import "std/giskit308"` · `use giskit308`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit309

`import "std/giskit309"` · `use giskit309`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit310

`import "std/giskit310"` · `use giskit310`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit311

`import "std/giskit311"` · `use giskit311`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit312

`import "std/giskit312"` · `use giskit312`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit313

`import "std/giskit313"` · `use giskit313`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit314

`import "std/giskit314"` · `use giskit314`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit315

`import "std/giskit315"` · `use giskit315`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit316

`import "std/giskit316"` · `use giskit316`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit317

`import "std/giskit317"` · `use giskit317`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit318

`import "std/giskit318"` · `use giskit318`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit319

`import "std/giskit319"` · `use giskit319`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit320

`import "std/giskit320"` · `use giskit320`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit321

`import "std/giskit321"` · `use giskit321`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit322

`import "std/giskit322"` · `use giskit322`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit323

`import "std/giskit323"` · `use giskit323`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit324

`import "std/giskit324"` · `use giskit324`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit325

`import "std/giskit325"` · `use giskit325`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit326

`import "std/giskit326"` · `use giskit326`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit327

`import "std/giskit327"` · `use giskit327`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit328

`import "std/giskit328"` · `use giskit328`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit329

`import "std/giskit329"` · `use giskit329`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit330

`import "std/giskit330"` · `use giskit330`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit331

`import "std/giskit331"` · `use giskit331`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit332

`import "std/giskit332"` · `use giskit332`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit333

`import "std/giskit333"` · `use giskit333`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit334

`import "std/giskit334"` · `use giskit334`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit335

`import "std/giskit335"` · `use giskit335`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit336

`import "std/giskit336"` · `use giskit336`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit337

`import "std/giskit337"` · `use giskit337`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit338

`import "std/giskit338"` · `use giskit338`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit339

`import "std/giskit339"` · `use giskit339`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit340

`import "std/giskit340"` · `use giskit340`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit341

`import "std/giskit341"` · `use giskit341`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit342

`import "std/giskit342"` · `use giskit342`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit343

`import "std/giskit343"` · `use giskit343`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit344

`import "std/giskit344"` · `use giskit344`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit345

`import "std/giskit345"` · `use giskit345`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit346

`import "std/giskit346"` · `use giskit346`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit347

`import "std/giskit347"` · `use giskit347`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit348

`import "std/giskit348"` · `use giskit348`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit349

`import "std/giskit349"` · `use giskit349`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit350

`import "std/giskit350"` · `use giskit350`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit351

`import "std/giskit351"` · `use giskit351`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit352

`import "std/giskit352"` · `use giskit352`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit353

`import "std/giskit353"` · `use giskit353`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit354

`import "std/giskit354"` · `use giskit354`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit355

`import "std/giskit355"` · `use giskit355`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit356

`import "std/giskit356"` · `use giskit356`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit357

`import "std/giskit357"` · `use giskit357`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit358

`import "std/giskit358"` · `use giskit358`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit359

`import "std/giskit359"` · `use giskit359`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit360

`import "std/giskit360"` · `use giskit360`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit361

`import "std/giskit361"` · `use giskit361`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit362

`import "std/giskit362"` · `use giskit362`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit363

`import "std/giskit363"` · `use giskit363`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit364

`import "std/giskit364"` · `use giskit364`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit365

`import "std/giskit365"` · `use giskit365`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit366

`import "std/giskit366"` · `use giskit366`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit367

`import "std/giskit367"` · `use giskit367`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit368

`import "std/giskit368"` · `use giskit368`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit369

`import "std/giskit369"` · `use giskit369`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit370

`import "std/giskit370"` · `use giskit370`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit371

`import "std/giskit371"` · `use giskit371`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit372

`import "std/giskit372"` · `use giskit372`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit373

`import "std/giskit373"` · `use giskit373`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit374

`import "std/giskit374"` · `use giskit374`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit375

`import "std/giskit375"` · `use giskit375`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit376

`import "std/giskit376"` · `use giskit376`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit377

`import "std/giskit377"` · `use giskit377`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit378

`import "std/giskit378"` · `use giskit378`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit379

`import "std/giskit379"` · `use giskit379`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit380

`import "std/giskit380"` · `use giskit380`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit381

`import "std/giskit381"` · `use giskit381`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit382

`import "std/giskit382"` · `use giskit382`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit383

`import "std/giskit383"` · `use giskit383`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit384

`import "std/giskit384"` · `use giskit384`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit385

`import "std/giskit385"` · `use giskit385`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit386

`import "std/giskit386"` · `use giskit386`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit387

`import "std/giskit387"` · `use giskit387`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit388

`import "std/giskit388"` · `use giskit388`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit389

`import "std/giskit389"` · `use giskit389`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit390

`import "std/giskit390"` · `use giskit390`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit391

`import "std/giskit391"` · `use giskit391`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit392

`import "std/giskit392"` · `use giskit392`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit393

`import "std/giskit393"` · `use giskit393`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit394

`import "std/giskit394"` · `use giskit394`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit395

`import "std/giskit395"` · `use giskit395`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit396

`import "std/giskit396"` · `use giskit396`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit397

`import "std/giskit397"` · `use giskit397`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit398

`import "std/giskit398"` · `use giskit398`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit399

`import "std/giskit399"` · `use giskit399`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit400

`import "std/giskit400"` · `use giskit400`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit401

`import "std/giskit401"` · `use giskit401`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit402

`import "std/giskit402"` · `use giskit402`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit403

`import "std/giskit403"` · `use giskit403`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit404

`import "std/giskit404"` · `use giskit404`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit405

`import "std/giskit405"` · `use giskit405`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit406

`import "std/giskit406"` · `use giskit406`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit407

`import "std/giskit407"` · `use giskit407`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit408

`import "std/giskit408"` · `use giskit408`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit409

`import "std/giskit409"` · `use giskit409`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit410

`import "std/giskit410"` · `use giskit410`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit411

`import "std/giskit411"` · `use giskit411`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit412

`import "std/giskit412"` · `use giskit412`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit413

`import "std/giskit413"` · `use giskit413`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit414

`import "std/giskit414"` · `use giskit414`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit415

`import "std/giskit415"` · `use giskit415`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit416

`import "std/giskit416"` · `use giskit416`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit417

`import "std/giskit417"` · `use giskit417`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit418

`import "std/giskit418"` · `use giskit418`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit419

`import "std/giskit419"` · `use giskit419`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit420

`import "std/giskit420"` · `use giskit420`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit421

`import "std/giskit421"` · `use giskit421`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit422

`import "std/giskit422"` · `use giskit422`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit423

`import "std/giskit423"` · `use giskit423`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit424

`import "std/giskit424"` · `use giskit424`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit425

`import "std/giskit425"` · `use giskit425`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit426

`import "std/giskit426"` · `use giskit426`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit427

`import "std/giskit427"` · `use giskit427`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit428

`import "std/giskit428"` · `use giskit428`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit429

`import "std/giskit429"` · `use giskit429`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit430

`import "std/giskit430"` · `use giskit430`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit431

`import "std/giskit431"` · `use giskit431`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit432

`import "std/giskit432"` · `use giskit432`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit433

`import "std/giskit433"` · `use giskit433`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit434

`import "std/giskit434"` · `use giskit434`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit435

`import "std/giskit435"` · `use giskit435`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit436

`import "std/giskit436"` · `use giskit436`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit437

`import "std/giskit437"` · `use giskit437`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit438

`import "std/giskit438"` · `use giskit438`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit439

`import "std/giskit439"` · `use giskit439`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit440

`import "std/giskit440"` · `use giskit440`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit441

`import "std/giskit441"` · `use giskit441`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit442

`import "std/giskit442"` · `use giskit442`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit443

`import "std/giskit443"` · `use giskit443`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit444

`import "std/giskit444"` · `use giskit444`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit445

`import "std/giskit445"` · `use giskit445`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit446

`import "std/giskit446"` · `use giskit446`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit447

`import "std/giskit447"` · `use giskit447`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit448

`import "std/giskit448"` · `use giskit448`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit449

`import "std/giskit449"` · `use giskit449`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit450

`import "std/giskit450"` · `use giskit450`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit451

`import "std/giskit451"` · `use giskit451`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit452

`import "std/giskit452"` · `use giskit452`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit453

`import "std/giskit453"` · `use giskit453`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit454

`import "std/giskit454"` · `use giskit454`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit455

`import "std/giskit455"` · `use giskit455`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit456

`import "std/giskit456"` · `use giskit456`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit457

`import "std/giskit457"` · `use giskit457`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit458

`import "std/giskit458"` · `use giskit458`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit459

`import "std/giskit459"` · `use giskit459`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit460

`import "std/giskit460"` · `use giskit460`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit461

`import "std/giskit461"` · `use giskit461`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit462

`import "std/giskit462"` · `use giskit462`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit463

`import "std/giskit463"` · `use giskit463`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit464

`import "std/giskit464"` · `use giskit464`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit465

`import "std/giskit465"` · `use giskit465`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit466

`import "std/giskit466"` · `use giskit466`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit467

`import "std/giskit467"` · `use giskit467`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit468

`import "std/giskit468"` · `use giskit468`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit469

`import "std/giskit469"` · `use giskit469`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit470

`import "std/giskit470"` · `use giskit470`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit471

`import "std/giskit471"` · `use giskit471`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit472

`import "std/giskit472"` · `use giskit472`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit473

`import "std/giskit473"` · `use giskit473`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit474

`import "std/giskit474"` · `use giskit474`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit475

`import "std/giskit475"` · `use giskit475`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit476

`import "std/giskit476"` · `use giskit476`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit477

`import "std/giskit477"` · `use giskit477`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit478

`import "std/giskit478"` · `use giskit478`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit479

`import "std/giskit479"` · `use giskit479`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit480

`import "std/giskit480"` · `use giskit480`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit481

`import "std/giskit481"` · `use giskit481`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit482

`import "std/giskit482"` · `use giskit482`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit483

`import "std/giskit483"` · `use giskit483`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit484

`import "std/giskit484"` · `use giskit484`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`

## std/giskit485

`import "std/giskit485"` · `use giskit485`

- `mToKm(m number) → number`
- `kmToM(km number) → number`

## std/giskit486

`import "std/giskit486"` · `use giskit486`

- `normalizeLon(lon number) → number`
- `clampLat(lat number) → number`

## std/giskit487

`import "std/giskit487"` · `use giskit487`

- `pixelIndex(row number, col number, width number) → number`
- `geoToPixelX(x number, originX number, resX number) → number`

## std/giskit488

`import "std/giskit488"` · `use giskit488`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit489

`import "std/giskit489"` · `use giskit489`

- `ndvi(nir number, red number) → number`
- `brightness(r number, g number, b number) → number`

## std/giskit490

`import "std/giskit490"` · `use giskit490`

- `gsdFromAltitude(altM number, focalMm number, pixelUm number) → number`
- `groundWidth(pixels number, gsd number) → number`

## std/giskit491

`import "std/giskit491"` · `use giskit491`

- `tileRow(lat number, z number) → number`
- `tileCol(lon number, z number) → number`

## std/giskit492

`import "std/giskit492"` · `use giskit492`

- `utmZone(lon number) → number`
- `isNorthernHemisphere(lat number) → bool`

## std/giskit493

`import "std/giskit493"` · `use giskit493`

- `planarDist(x1 number, y1 number, x2 number, y2 number) → number`
- `planarDist2(x1 number, y1 number, x2 number, y2 number) → number`

## std/giskit494

`import "std/giskit494"` · `use giskit494`

- `percentSlope(rise number, run number) → number`
- `degreeSlope(rise number, run number) → number`

## std/giskit495

`import "std/giskit495"` · `use giskit495`

- `tileOriginX(tileCol number, tileSize number) → number`
- `tileOriginY(tileRow number, tileSize number) → number`

## std/giskit496

`import "std/giskit496"` · `use giskit496`

- `haversineKm(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `haversineM(lat1 number, lon1 number, lat2 number, lon2 number) → number`

## std/giskit497

`import "std/giskit497"` · `use giskit497`

- `bearingDeg(lat1 number, lon1 number, lat2 number, lon2 number) → number`
- `azimuthDiff(a number, b number) → number`

## std/giskit498

`import "std/giskit498"` · `use giskit498`

- `bboxWidth(minX number, minY number, maxX number, maxY number) → number`
- `bboxArea(minX number, minY number, maxX number, maxY number) → number`

## std/giskit499

`import "std/giskit499"` · `use giskit499`

- `bboxCenterX(minX number, minY number, maxX number, maxY number) → number`
- `bboxCenterY(minX number, minY number, maxX number, maxY number) → number`

## std/giskit500

`import "std/giskit500"` · `use giskit500`

- `pointInBbox(x number, y number, minX number, minY number, maxX number, maxY number) → bool`
- `degToRad(deg number) → number`
