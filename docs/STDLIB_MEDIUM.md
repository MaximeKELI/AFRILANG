# Bibliothèques moyennes AFRILANG

**102 modules** — `std/m/{nom}`

## std/m/textstats

`import "std/m/textstats"` · `use textstats`

- `wordCount(s text) → number`
- `charCount(s text) → number`
- `lineCount(s text) → number`
- `avgWordLen(s text) → number`
- `digitCount(s text) → number`

## std/m/charfreq

`import "std/m/charfreq"` · `use charfreq`

- `countChar(s text, ch text) → number`
- `mostCommonChar(s text) → text`
- `uniqueChars(s text) → number`
- `alphaRatio(s text) → number`
- `spaceRatio(s text) → number`

## std/m/sentsplit

`import "std/m/sentsplit"` · `use sentsplit`

- `splitSentences(s text) → list text`
- `sentenceCount(s text) → number`
- `firstSentence(s text) → text`
- `lastSentence(s text) → text`

## std/m/wordtok

`import "std/m/wordtok"` · `use wordtok`

- `tokenize(s text) → list text`
- `tokenCount(s text) → number`
- `longestToken(s text) → text`
- `shortestToken(s text) → text`
- `avgTokenLen(s text) → number`

## std/m/ngrams

`import "std/m/ngrams"` · `use ngrams`

- `bigrams(s text) → list text`
- `trigrams(s text) → list text`
- `charBigrams(s text) → list text`
- `ngramCount(s text, n number) → number`

## std/m/palindrom2

`import "std/m/palindrom2"` · `use palindrom2`

- `isPalindrome(s text) → bool`
- `longestPalindromeLen(s text) → number`
- `reverseAlphaNum(s text) → text`
- `isPalindromeWord(w text) → bool`

## std/m/anagram2

`import "std/m/anagram2"` · `use anagram2`

- `normalizeWord(s text) → text`
- `areAnagrams(a text, b text) → bool`
- `anagramKey(s text) → text`
- `sortLetters(s text) → text`

## std/m/textwrap2

`import "std/m/textwrap2"` · `use textwrap2`

- `wrapLines(s text, width number) → list text`
- `wrapCount(s text, width number) → number`
- `truncateWords(s text, maxWords number) → text`
- `padCenter(s text, width number) → text`

## std/m/textsearch

`import "std/m/textsearch"` · `use textsearch`

- `findAll(s text, sub text) → list number`
- `countOccurrences(s text, sub text) → number`
- `containsIgnoreCase(s text, sub text) → bool`
- `replaceAll(s text, from text, to text) → text`
- `indexOf(s text, sub text) → number`

## std/m/accentstrip

`import "std/m/accentstrip"` · `use accentstrip`

- `stripAccents(s text) → text`
- `toAsciiFold(s text) → text`
- `removeNonPrintable(s text) → text`
- `collapseSpaces(s text) → text`

## std/m/casemap2

`import "std/m/casemap2"` · `use casemap2`

- `titleCase(s text) → text`
- `swapCase(s text) → text`
- `camelToSnake(s text) → text`
- `snakeToCamel(s text) → text`

## std/m/textdiff2

`import "std/m/textdiff2"` · `use textdiff2`

- `commonPrefixLen(a text, b text) → number`
- `commonSuffixLen(a text, b text) → number`
- `levenshtein(a text, b text) → number`
- `similarityRatio(a text, b text) → number`

## std/m/regexlite

`import "std/m/regexlite"` · `use regexlite`

- `matchDigits(s text) → bool`
- `matchAlpha(s text) → bool`
- `matchAlnum(s text) → bool`
- `extractDigits(s text) → text`
- `extractAlpha(s text) → text`

## std/m/motfreq

`import "std/m/motfreq"` · `use motfreq`

- `wordFrequency(s text, word text) → number`
- `mostFrequentWord(s text) → text`
- `uniqueWords(s text) → number`
- `lexicalDensity(s text) → number`

## std/m/numstats

`import "std/m/numstats"` · `use numstats`

- `sum(v list number) → number`
- `mean(v list number) → number`
- `minVal(v list number) → number`
- `maxVal(v list number) → number`
- `range(v list number) → number`

## std/m/listmedian

`import "std/m/listmedian"` · `use listmedian`

- `median(v list number) → number`
- `q1(v list number) → number`
- `q3(v list number) → number`
- `iqr(v list number) → number`

## std/m/listvar

`import "std/m/listvar"` · `use listvar`

- `variance(v list number) → number`
- `stddev(v list number) → number`
- `popVariance(v list number) → number`
- `popStddev(v list number) → number`

## std/m/listmode

`import "std/m/listmode"` · `use listmode`

- `mode(v list number) → number`
- `modeCount(v list number) → number`
- `uniqueCount(v list number) → number`
- `duplicateCount(v list number) → number`

## std/m/listcum

`import "std/m/listcum"` · `use listcum`

- `cumSum(v list number) → list number`
- `cumProd(v list number) → list number`
- `diffs(v list number) → list number`
- `pctChange(v list number) → list number`

## std/m/listnorm

`import "std/m/listnorm"` · `use listnorm`

- `normalize(v list number) → list number`
- `zScores(v list number) → list number`
- `scaleTo100(v list number) → list number`
- `demean(v list number) → list number`

## std/m/listcorr

`import "std/m/listcorr"` · `use listcorr`

- `covariance(a list number, b list number) → number`
- `correlation(a list number, b list number) → number`
- `dotProduct(a list number, b list number) → number`
- `euclidean(a list number, b list number) → number`

## std/m/listoutlier

`import "std/m/listoutlier"` · `use listoutlier`

- `outlierIndices(v list number) → list number`
- `outlierCount(v list number) → number`
- `withoutOutliers(v list number) → list number`
- `winsorize(v list number, pct number) → list number`

## std/m/listquantile

`import "std/m/listquantile"` · `use listquantile`

- `quantile(v list number, q number) → number`
- `percentile(v list number, p number) → number`
- `decile(v list number, d number) → number`
- `rankOf(v list number) → list number`

## std/m/listfreq

`import "std/m/listfreq"` · `use listfreq`

- `valueCounts(v list number) → list number`
- `histogram(v list number, bins number) → list number`
- `binEdges(v list number, bins number) → list number`
- `skewness(v list number) → number`

## std/m/listmoving

`import "std/m/listmoving"` · `use listmoving`

- `movingAvg(v list number, window number) → list number`
- `movingMax(v list number, window number) → list number`
- `movingMin(v list number, window number) → list number`
- `movingSum(v list number, window number) → list number`

## std/m/listscale

`import "std/m/listscale"` · `use listscale`

- `rescale(v list number, newMin number, newMax number) → list number`
- `clip(v list number, lo number, hi number) → list number`
- `absValues(v list number) → list number`
- `negateAll(v list number) → list number`

## std/m/listsort

`import "std/m/listsort"` · `use listsort`

- `sortAsc(v list number) → list number`
- `sortDesc(v list number) → list number`
- `sortTextAsc(v list text) → list text`
- `sortTextDesc(v list text) → list text`
- `isSorted(v list number) → bool`

## std/m/listsearch

`import "std/m/listsearch"` · `use listsearch`

- `linearSearch(v list number, target number) → number`
- `contains(v list number, target number) → bool`
- `countValue(v list number, target number) → number`
- `lastIndexOf(v list number, target number) → number`

## std/m/listbinary

`import "std/m/listbinary"` · `use listbinary`

- `binarySearch(v list number, target number) → number`
- `lowerBound(v list number, target number) → number`
- `upperBound(v list number, target number) → number`
- `insertSorted(v list number, val number) → list number`

## std/m/listunique2

`import "std/m/listunique2"` · `use listunique2`

- `unique(v list number) → list number`
- `uniqueText(v list text) → list text`
- `duplicates(v list number) → list number`
- `frequency(v list number, val number) → number`

## std/m/listpartition

`import "std/m/listpartition"` · `use listpartition`

- `partitionAt(v list number, pivot number) → list number`
- `splitHalf(v list number) → list number`
- `secondHalf(v list number) → list number`
- `filterGt(v list number, threshold number) → list number`
- `filterLt(v list number, threshold number) → list number`

## std/m/listtopk

`import "std/m/listtopk"` · `use listtopk`

- `topK(v list number, k number) → list number`
- `bottomK(v list number, k number) → list number`
- `kthLargest(v list number, k number) → number`
- `kthSmallest(v list number, k number) → number`

## std/m/listmerge2

`import "std/m/listmerge2"` · `use listmerge2`

- `mergeSorted(a list number, b list number) → list number`
- `mergeAll(a list number, b list number) → list number`
- `intersect(a list number, b list number) → list number`
- `unionAll(a list number, b list number) → list number`

## std/m/listrotate2

`import "std/m/listrotate2"` · `use listrotate2`

- `rotateLeft(v list number, n number) → list number`
- `rotateRight(v list number, n number) → list number`
- `reverseList(v list number) → list number`
- `shuffleSeed(v list number, seed number) → list number`

## std/m/listchunk

`import "std/m/listchunk"` · `use listchunk`

- `chunkCount(v list number, size number) → number`
- `take(v list number, n number) → list number`
- `drop(v list number, n number) → list number`
- `slice(v list number, start number, end number) → list number`
- `chunkAt(v list number, index number, size number) → list number`

## std/m/listzip2

`import "std/m/listzip2"` · `use listzip2`

- `zipAdd(a list number, b list number) → list number`
- `zipMul(a list number, b list number) → list number`
- `zipSub(a list number, b list number) → list number`
- `zipMax(a list number, b list number) → list number`

## std/m/textsplit2

`import "std/m/textsplit2"` · `use textsplit2`

- `splitLines(s text) → list text`
- `splitBy(s text, delim text) → list text`
- `splitWords(s text) → list text`
- `splitChars(s text) → list text`

## std/m/textjoin2

`import "std/m/textjoin2"` · `use textjoin2`

- `joinLines(parts list text) → text`
- `joinWith(parts list text, delim text) → text`
- `joinComma(parts list text) → text`
- `joinSpace(parts list text) → text`

## std/m/listfilter2

`import "std/m/listfilter2"` · `use listfilter2`

- `filterEmpty(v list text) → list text`
- `filterLonger(v list text, minLen number) → list text`
- `filterContains(v list text, sub text) → list text`
- `filterStarts(v list text, prefix text) → list text`

## std/m/listmap2

`import "std/m/listmap2"` · `use listmap2`

- `mapUpper(v list text) → list text`
- `mapLower(v list text) → list text`
- `mapTrim(v list text) → list text`
- `mapLength(v list text) → list number`

## std/m/listgroup2

`import "std/m/listgroup2"` · `use listgroup2`

- `groupByLen(v list text, len number) → list text`
- `groupByPrefix(v list text, prefix text) → list text`
- `longestString(v list text) → text`
- `shortestString(v list text) → text`

## std/m/listpick2

`import "std/m/listpick2"` · `use listpick2`

- `pickFirst(v list text) → text`
- `pickLast(v list text) → text`
- `pickAt(v list text, index number) → text`
- `pickRandom(v list text, seed number) → text`

## std/m/datecalc

`import "std/m/datecalc"` · `use datecalc`

- `daysBetween(d1 text, d2 text) → number`
- `addDays(date text, days number) → text`
- `isLeapYear(year number) → bool`
- `daysInMonth(year number, month number) → number`
- `weekday(date text) → number`

## std/m/datefmt2

`import "std/m/datefmt2"` · `use datefmt2`

- `formatIso(year number, month number, day number) → text`
- `parseYear(date text) → number`
- `parseMonth(date text) → number`
- `parseDay(date text) → number`

## std/m/duration2

`import "std/m/duration2"` · `use duration2`

- `hoursToMinutes(h number) → number`
- `minutesToSeconds(m number) → number`
- `daysToHours(d number) → number`
- `secondsToHours(s number) → number`

## std/m/timestamp2

`import "std/m/timestamp2"` · `use timestamp2`

- `epochDays(date text) → number`
- `fromEpochDays(days number) → text`
- `isValidDate(date text) → bool`
- `todayOffset(date text, offset number) → number`

## std/m/calendar2

`import "std/m/calendar2"` · `use calendar2`

- `quarterOf(month number) → number`
- `weekOfYear(date text) → number`
- `monthName(month number) → text`
- `dayName(date text) → text`

## std/m/agecalc

`import "std/m/agecalc"` · `use agecalc`

- `ageYears(birth text, today text) → number`
- `ageMonths(birth text, today text) → number`
- `ageDays(birth text, today text) → number`
- `isBirthday(birth text, today text) → bool`

## std/m/timezone2

`import "std/m/timezone2"` · `use timezone2`

- `utcOffsetHours(offset number) → number`
- `toUtc(localTime text, offsetHours number) → text`
- `fromUtc(utcTime text, offsetHours number) → text`
- `formatTime(hours number, minutes number) → text`

## std/m/period2

`import "std/m/period2"` · `use period2`

- `monthsBetween(d1 text, d2 text) → number`
- `yearsBetween(d1 text, d2 text) → number`
- `addMonths(date text, months number) → text`
- `endOfMonth(date text) → text`

## std/m/chrono2

`import "std/m/chrono2"` · `use chrono2`

- `elapsedDays(start text, end text) → number`
- `isWeekend(date text) → bool`
- `nextWeekday(date text) → text`
- `businessDays(start text, end text) → number`

## std/m/season2

`import "std/m/season2"` · `use season2`

- `seasonOf(month number) → text`
- `isSummer(month number) → bool`
- `isWinter(month number) → bool`
- `daylightHours(month number, lat number) → number`

## std/m/uriparse

`import "std/m/uriparse"` · `use uriparse`

- `getScheme(url text) → text`
- `getHost(url text) → text`
- `getPath(url text) → text`
- `getQuery(url text) → text`
- `hasQuery(url text) → bool`

## std/m/urlbuild

`import "std/m/urlbuild"` · `use urlbuild`

- `buildUrl(scheme text, host text, path text) → text`
- `buildWithQuery(base text, query text) → text`
- `encodeParam(key text, value text) → text`
- `joinParams(params list text) → text`

## std/m/queryparse

`import "std/m/queryparse"` · `use queryparse`

- `parseQuery(query text) → list text`
- `getParam(query text, key text) → text`
- `paramCount(query text) → number`
- `hasParam(query text, key text) → bool`

## std/m/jsonparse2

`import "std/m/jsonparse2"` · `use jsonparse2`

- `parseString(json text, key text) → text`
- `parseNumber(json text, key text) → number`
- `isValidJson(json text) → bool`
- `keyCount(json text) → number`

## std/m/jsonbuild2

`import "std/m/jsonbuild2"` · `use jsonbuild2`

- `buildObject(pairs list text) → text`
- `buildArray(items list text) → text`
- `quoteKey(key text, value text) → text`
- `quoteNum(key text, value number) → text`

## std/m/csvparse2

`import "std/m/csvparse2"` · `use csvparse2`

- `parseRow(line text) → list text`
- `getField(line text, index number) → text`
- `fieldCount(line text) → number`
- `parseAll(csv text) → list text`

## std/m/csvbuild2

`import "std/m/csvbuild2"` · `use csvbuild2`

- `buildRow(fields list text) → text`
- `escapeField(field text) → text`
- `buildCsv(rows list text) → text`
- `quoteField(field text) → text`

## std/m/pathparse2

`import "std/m/pathparse2"` · `use pathparse2`

- `basename(path text) → text`
- `dirname(path text) → text`
- `extension(path text) → text`
- `stem(path text) → text`
- `joinPath(a text, b text) → text`

## std/m/mimeparse2

`import "std/m/mimeparse2"` · `use mimeparse2`

- `mainType(mime text) → text`
- `subType(mime text) → text`
- `isText(mime text) → bool`
- `isImage(mime text) → bool`

## std/m/httpparse2

`import "std/m/httpparse2"` · `use httpparse2`

- `statusClass(code number) → number`
- `isClientError(code number) → bool`
- `isServerError(code number) → bool`
- `statusText(code number) → text`

## std/m/emailparse2

`import "std/m/emailparse2"` · `use emailparse2`

- `localPart(email text) → text`
- `domainPart(email text) → text`
- `isValidEmail(email text) → bool`
- `normalizeEmail(email text) → text`

## std/m/base64med

`import "std/m/base64med"` · `use base64med`

- `encodeBasic(s text) → text`
- `decodeBasic(s text) → text`
- `isBase64(s text) → bool`
- `paddedLength(s text) → number`

## std/m/matrix2

`import "std/m/matrix2"` · `use matrix2`

- `create2x2(a number, b number, c number, d number) → list number`
- `det2x2(m list number) → number`
- `trace2x2(m list number) → number`
- `scale2x2(m list number, s number) → list number`

## std/m/matadd

`import "std/m/matadd"` · `use matadd`

- `add(a list number, b list number) → list number`
- `sub(a list number, b list number) → list number`
- `neg(m list number) → list number`
- `addScalar(m list number, s number) → list number`

## std/m/matmul2

`import "std/m/matmul2"` · `use matmul2`

- `mul2x2(a list number, b list number) → list number`
- `mulScalar(m list number, s number) → list number`
- `dot2(a list number, b list number) → number`
- `norm2(v list number) → number`

## std/m/mattranspose

`import "std/m/mattranspose"` · `use mattranspose`

- `transpose2x2(m list number) → list number`
- `transpose3x3(m list number) → list number`
- `isSquare(m list number, n number) → bool`
- `identity2(ignored number) → list number`

## std/m/matdet2

`import "std/m/matdet2"` · `use matdet2`

- `det3x3(m list number) → number`
- `det2x2(m list number) → number`
- `isSingular(m list number) → bool`
- `cofactor2(m list number) → list number`

## std/m/matinv2

`import "std/m/matinv2"` · `use matinv2`

- `inv2x2(m list number) → list number`
- `adj2x2(m list number) → list number`
- `solve2x2(a list number, b list number) → list number`
- `condition2x2(m list number) → number`

## std/m/vector3

`import "std/m/vector3"` · `use vector3`

- `cross3(a list number, b list number) → list number`
- `dot3(a list number, b list number) → number`
- `length3(v list number) → number`
- `normalize3(v list number) → list number`

## std/m/matrotate

`import "std/m/matrotate"` · `use matrotate`

- `rotate2d(angle number) → list number`
- `apply2d(m list number, v list number) → list number`
- `rotatePoint(x number, y number, angle number) → list number`
- `degreesToRad(deg number) → number`

## std/m/matstats

`import "std/m/matstats"` · `use matstats`

- `rowSum(m list number, cols number) → list number`
- `colSum(m list number, rows number, cols number) → list number`
- `frobeniusNorm(m list number) → number`
- `maxAbs(m list number) → number`

## std/m/linsolve2

`import "std/m/linsolve2"` · `use linsolve2`

- `solveLinear2(a1 number, b1 number, c1 number, a2 number, b2 number, c2 number) → list number`
- `solve3eq(m list number, b list number) → list number`
- `residual(a list number, x list number, b list number) → number`
- `isConsistent(m list number) → bool`

## std/m/finance2

`import "std/m/finance2"` · `use finance2`

- `futureValue(pv number, rate number, periods number) → number`
- `presentValue(fv number, rate number, periods number) → number`
- `annuity(payment number, rate number, periods number) → number`
- `payment(pv number, rate number, periods number) → number`

## std/m/amortize2

`import "std/m/amortize2"` · `use amortize2`

- `monthlyInterest(balance number, rate number) → number`
- `principalPart(payment number, interest number) → number`
- `remainingBalance(balance number, payment number, interest number) → number`
- `amortSchedule(balance number, rate number, payment number, months number) → list number`

## std/m/npv2

`import "std/m/npv2"` · `use npv2`

- `npv(rate number, cashflows list number) → number`
- `npvSimple(rate number, initial number, returns list number) → number`
- `profitability(npvVal number, investment number) → number`
- `discountedCashflow(cf number, rate number, period number) → number`

## std/m/irr2

`import "std/m/irr2"` · `use irr2`

- `irrApprox(cashflows list number) → number`
- `mirr(cashflows list number, financeRate number, reinvestRate number) → number`
- `paybackPeriod(cashflows list number) → number`
- `roiPercent(gain number, cost number) → number`

## std/m/breakEven2

`import "std/m/breakEven2"` · `use breakEven2`

- `breakEvenUnits(fixedCost number, price number, varCost number) → number`
- `breakEvenRevenue(fixedCost number, margin number) → number`
- `contributionMargin(price number, varCost number) → number`
- `marginOfSafety(currentSales number, breakEven number) → number`

## std/m/compound2

`import "std/m/compound2"` · `use compound2`

- `compoundAnnual(principal number, rate number, years number) → number`
- `compoundMonthly(principal number, rate number, months number) → number`
- `effectiveRate(nominal number, periods number) → number`
- `doublingTime(rate number) → number`

## std/m/inflation2

`import "std/m/inflation2"` · `use inflation2`

- `inflate(amount number, rate number, years number) → number`
- `deflate(amount number, rate number, years number) → number`
- `realReturn(nominal number, inflation number) → number`
- `purchasingPower(amount number, inflation number, years number) → number`

## std/m/currency2

`import "std/m/currency2"` · `use currency2`

- `convert(amount number, rate number) → number`
- `crossRate(fromUsd number, toUsd number) → number`
- `spread(bid number, ask number) → number`
- `midRate(bid number, ask number) → number`

## std/m/portfolio2

`import "std/m/portfolio2"` · `use portfolio2`

- `weightedReturn(returns list number, weights list number) → number`
- `portfolioValue(shares list number, prices list number) → number`
- `rebalance(values list number, target list number) → list number`
- `diversification(weights list number) → number`

## std/m/taxcalc2

`import "std/m/taxcalc2"` · `use taxcalc2`

- `incomeTax(income number, rate number) → number`
- `netIncome(gross number, rate number) → number`
- `vatAmount(price number, rate number) → number`
- `priceWithVat(price number, rate number) → number`

## std/m/depreciation2

`import "std/m/depreciation2"` · `use depreciation2`

- `straightLine(cost number, salvage number, years number) → number`
- `decliningBalance(bookValue number, rate number) → number`
- `sumOfYears(cost number, salvage number, years number, year number) → number`
- `accumDepreciation(annual number, yearsElapsed number) → number`

## std/m/bondcalc2

`import "std/m/bondcalc2"` · `use bondcalc2`

- `bondPrice(face number, coupon number, rate number, years number) → number`
- `yieldToMaturity(price number, face number, coupon number, years number) → number`
- `currentYield(coupon number, price number) → number`
- `duration(years number, coupon number) → number`

## std/m/polygon2

`import "std/m/polygon2"` · `use polygon2`

- `areaTriangle(base number, height number) → number`
- `perimeterRect(w number, h number) → number`
- `areaRect(w number, h number) → number`
- `diagonal(w number, h number) → number`

## std/m/statsreg2

`import "std/m/statsreg2"` · `use statsreg2`

- `linearSlope(x list number, y list number) → number`
- `linearIntercept(x list number, y list number) → number`
- `predict(slope number, intercept number, x number) → number`
- `rSquared(x list number, y list number) → number`

## std/m/interpolate2

`import "std/m/interpolate2"` · `use interpolate2`

- `lerp(a number, b number, t number) → number`
- `lerpList(a list number, b list number, t number) → list number`
- `inverseLerp(a number, b number, v number) → number`
- `remap(v number, inLo number, inHi number, outLo number, outHi number) → number`

## std/m/bezier2

`import "std/m/bezier2"` · `use bezier2`

- `quadBezier(p0 number, p1 number, p2 number, t number) → number`
- `cubicBezier(p0 number, p1 number, p2 number, p3 number, t number) → number`
- `bezierTangent(p0 number, p1 number, p2 number, t number) → number`
- `bezierPoint2d(x0 number, y0 number, x1 number, y1 number, x2 number, y2 number, t number) → list number`

## std/m/distance3

`import "std/m/distance3"` · `use distance3`

- `manhattan2d(x1 number, y1 number, x2 number, y2 number) → number`
- `chebyshev2d(x1 number, y1 number, x2 number, y2 number) → number`
- `cosineSimilarity(a list number, b list number) → number`
- `hammingDist(a text, b text) → number`

## std/m/histogram2

`import "std/m/histogram2"` · `use histogram2`

- `binIndex(value number, minVal number, maxVal number, bins number) → number`
- `normalizeHist(counts list number) → list number`
- `cumulativeHist(counts list number) → list number`
- `peakBin(counts list number) → number`

## std/m/percentile2

`import "std/m/percentile2"` · `use percentile2`

- `percentileRank(v list number, value number) → number`
- `percentileValue(v list number, p number) → number`
- `trimMean(v list number, pct number) → number`
- `geometricMean(v list number) → number`

## std/m/checksum2

`import "std/m/checksum2"` · `use checksum2`

- `crcSimple(s text) → number`
- `adler32lite(s text) → number`
- `fnvHash(s text) → number`
- `sumChecksum(s text) → number`

## std/m/hash2

`import "std/m/hash2"` · `use hash2`

- `djb2(s text) → number`
- `sdbm(s text) → number`
- `javaHash(s text) → number`
- `hashCombine(a number, b number) → number`

## std/m/rotN

`import "std/m/rotN"` · `use rotN`

- `rotEncode(s text, n number) → text`
- `rotDecode(s text, n number) → text`
- `caesarShift(s text, n number) → text`
- `xorCipher(s text, key text) → text`

## std/m/uuid2

`import "std/m/uuid2"` · `use uuid2`

- `randomHex(n number) → text`
- `simpleUuid(seed number) → text`
- `formatUuid(hex32 text) → text`
- `isUuidFormat(s text) → bool`

## std/m/random2

`import "std/m/random2"` · `use random2`

- `seedRandom(seed number) → number`
- `randomRange(lo number, hi number) → number`
- `randomList(count number, lo number, hi number) → list number`
- `shuffleList(v list number, seed number) → list number`

## std/m/entropy2

`import "std/m/entropy2"` · `use entropy2`

- `shannonEntropy(s text) → number`
- `uniqueRatio(s text) → number`
- `compressionRatio(original number, compressed number) → number`
- `bitEntropy(s text) → number`

## std/m/units2

`import "std/m/units2"` · `use units2`

- `celsiusToFahrenheit(c number) → number`
- `fahrenheitToCelsius(f number) → number`
- `metersToFeet(m number) → number`
- `feetToMeters(ft number) → number`

## std/m/physics2

`import "std/m/physics2"` · `use physics2`

- `kineticEnergy(mass number, velocity number) → number`
- `potentialEnergy(mass number, height number) → number`
- `momentum(mass number, velocity number) → number`
- `force(mass number, accel number) → number`

## std/m/gamestats2

`import "std/m/gamestats2"` · `use gamestats2`

- `scoreMultiplier(score number, multiplier number) → number`
- `xpForLevel(level number) → number`
- `levelFromXp(xp number) → number`
- `damageCalc(attack number, defense number) → number`
