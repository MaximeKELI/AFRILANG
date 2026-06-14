#include "afrilang/medium_catalog.hpp"

namespace afrilang {
namespace {

const StdlibParamSpec kMParams_0[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_0[] = {
    {"wordCount", "number", 1, &kMParams_0[0]},
    {"charCount", "number", 1, &kMParams_0[1]},
    {"lineCount", "number", 1, &kMParams_0[2]},
    {"avgWordLen", "number", 1, &kMParams_0[3]},
    {"digitCount", "number", 1, &kMParams_0[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_1[] = {
    {"s", "text"},
    {"ch", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_1[] = {
    {"countChar", "number", 2, &kMParams_1[0]},
    {"mostCommonChar", "text", 1, &kMParams_1[2]},
    {"uniqueChars", "number", 1, &kMParams_1[3]},
    {"alphaRatio", "number", 1, &kMParams_1[4]},
    {"spaceRatio", "number", 1, &kMParams_1[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_2[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_2[] = {
    {"splitSentences", "list text", 1, &kMParams_2[0]},
    {"sentenceCount", "number", 1, &kMParams_2[1]},
    {"firstSentence", "text", 1, &kMParams_2[2]},
    {"lastSentence", "text", 1, &kMParams_2[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_3[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_3[] = {
    {"tokenize", "list text", 1, &kMParams_3[0]},
    {"tokenCount", "number", 1, &kMParams_3[1]},
    {"longestToken", "text", 1, &kMParams_3[2]},
    {"shortestToken", "text", 1, &kMParams_3[3]},
    {"avgTokenLen", "number", 1, &kMParams_3[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_4[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_4[] = {
    {"bigrams", "list text", 1, &kMParams_4[0]},
    {"trigrams", "list text", 1, &kMParams_4[1]},
    {"charBigrams", "list text", 1, &kMParams_4[2]},
    {"ngramCount", "number", 2, &kMParams_4[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_5[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"w", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_5[] = {
    {"isPalindrome", "bool", 1, &kMParams_5[0]},
    {"longestPalindromeLen", "number", 1, &kMParams_5[1]},
    {"reverseAlphaNum", "text", 1, &kMParams_5[2]},
    {"isPalindromeWord", "bool", 1, &kMParams_5[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_6[] = {
    {"s", "text"},
    {"a", "text"},
    {"b", "text"},
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_6[] = {
    {"normalizeWord", "text", 1, &kMParams_6[0]},
    {"areAnagrams", "bool", 2, &kMParams_6[1]},
    {"anagramKey", "text", 1, &kMParams_6[3]},
    {"sortLetters", "text", 1, &kMParams_6[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_7[] = {
    {"s", "text"},
    {"width", "number"},
    {"s", "text"},
    {"width", "number"},
    {"s", "text"},
    {"maxWords", "number"},
    {"s", "text"},
    {"width", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_7[] = {
    {"wrapLines", "list text", 2, &kMParams_7[0]},
    {"wrapCount", "number", 2, &kMParams_7[2]},
    {"truncateWords", "text", 2, &kMParams_7[4]},
    {"padCenter", "text", 2, &kMParams_7[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_8[] = {
    {"s", "text"},
    {"sub", "text"},
    {"s", "text"},
    {"sub", "text"},
    {"s", "text"},
    {"sub", "text"},
    {"s", "text"},
    {"from", "text"},
    {"to", "text"},
    {"s", "text"},
    {"sub", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_8[] = {
    {"findAll", "list number", 2, &kMParams_8[0]},
    {"countOccurrences", "number", 2, &kMParams_8[2]},
    {"containsIgnoreCase", "bool", 2, &kMParams_8[4]},
    {"replaceAll", "text", 3, &kMParams_8[6]},
    {"indexOf", "number", 2, &kMParams_8[9]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_9[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_9[] = {
    {"stripAccents", "text", 1, &kMParams_9[0]},
    {"toAsciiFold", "text", 1, &kMParams_9[1]},
    {"removeNonPrintable", "text", 1, &kMParams_9[2]},
    {"collapseSpaces", "text", 1, &kMParams_9[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_10[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_10[] = {
    {"titleCase", "text", 1, &kMParams_10[0]},
    {"swapCase", "text", 1, &kMParams_10[1]},
    {"camelToSnake", "text", 1, &kMParams_10[2]},
    {"snakeToCamel", "text", 1, &kMParams_10[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_11[] = {
    {"a", "text"},
    {"b", "text"},
    {"a", "text"},
    {"b", "text"},
    {"a", "text"},
    {"b", "text"},
    {"a", "text"},
    {"b", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_11[] = {
    {"commonPrefixLen", "number", 2, &kMParams_11[0]},
    {"commonSuffixLen", "number", 2, &kMParams_11[2]},
    {"levenshtein", "number", 2, &kMParams_11[4]},
    {"similarityRatio", "number", 2, &kMParams_11[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_12[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_12[] = {
    {"matchDigits", "bool", 1, &kMParams_12[0]},
    {"matchAlpha", "bool", 1, &kMParams_12[1]},
    {"matchAlnum", "bool", 1, &kMParams_12[2]},
    {"extractDigits", "text", 1, &kMParams_12[3]},
    {"extractAlpha", "text", 1, &kMParams_12[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_13[] = {
    {"s", "text"},
    {"word", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_13[] = {
    {"wordFrequency", "number", 2, &kMParams_13[0]},
    {"mostFrequentWord", "text", 1, &kMParams_13[2]},
    {"uniqueWords", "number", 1, &kMParams_13[3]},
    {"lexicalDensity", "number", 1, &kMParams_13[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_14[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_14[] = {
    {"sum", "number", 1, &kMParams_14[0]},
    {"mean", "number", 1, &kMParams_14[1]},
    {"minVal", "number", 1, &kMParams_14[2]},
    {"maxVal", "number", 1, &kMParams_14[3]},
    {"range", "number", 1, &kMParams_14[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_15[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_15[] = {
    {"median", "number", 1, &kMParams_15[0]},
    {"q1", "number", 1, &kMParams_15[1]},
    {"q3", "number", 1, &kMParams_15[2]},
    {"iqr", "number", 1, &kMParams_15[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_16[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_16[] = {
    {"variance", "number", 1, &kMParams_16[0]},
    {"stddev", "number", 1, &kMParams_16[1]},
    {"popVariance", "number", 1, &kMParams_16[2]},
    {"popStddev", "number", 1, &kMParams_16[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_17[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_17[] = {
    {"mode", "number", 1, &kMParams_17[0]},
    {"modeCount", "number", 1, &kMParams_17[1]},
    {"uniqueCount", "number", 1, &kMParams_17[2]},
    {"duplicateCount", "number", 1, &kMParams_17[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_18[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_18[] = {
    {"cumSum", "list number", 1, &kMParams_18[0]},
    {"cumProd", "list number", 1, &kMParams_18[1]},
    {"diffs", "list number", 1, &kMParams_18[2]},
    {"pctChange", "list number", 1, &kMParams_18[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_19[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_19[] = {
    {"normalize", "list number", 1, &kMParams_19[0]},
    {"zScores", "list number", 1, &kMParams_19[1]},
    {"scaleTo100", "list number", 1, &kMParams_19[2]},
    {"demean", "list number", 1, &kMParams_19[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_20[] = {
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_20[] = {
    {"covariance", "number", 2, &kMParams_20[0]},
    {"correlation", "number", 2, &kMParams_20[2]},
    {"dotProduct", "number", 2, &kMParams_20[4]},
    {"euclidean", "number", 2, &kMParams_20[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_21[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"pct", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_21[] = {
    {"outlierIndices", "list number", 1, &kMParams_21[0]},
    {"outlierCount", "number", 1, &kMParams_21[1]},
    {"withoutOutliers", "list number", 1, &kMParams_21[2]},
    {"winsorize", "list number", 2, &kMParams_21[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_22[] = {
    {"v", "list number"},
    {"q", "number"},
    {"v", "list number"},
    {"p", "number"},
    {"v", "list number"},
    {"d", "number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_22[] = {
    {"quantile", "number", 2, &kMParams_22[0]},
    {"percentile", "number", 2, &kMParams_22[2]},
    {"decile", "number", 2, &kMParams_22[4]},
    {"rankOf", "list number", 1, &kMParams_22[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_23[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"bins", "number"},
    {"v", "list number"},
    {"bins", "number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_23[] = {
    {"valueCounts", "list number", 1, &kMParams_23[0]},
    {"histogram", "list number", 2, &kMParams_23[1]},
    {"binEdges", "list number", 2, &kMParams_23[3]},
    {"skewness", "number", 1, &kMParams_23[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_24[] = {
    {"v", "list number"},
    {"window", "number"},
    {"v", "list number"},
    {"window", "number"},
    {"v", "list number"},
    {"window", "number"},
    {"v", "list number"},
    {"window", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_24[] = {
    {"movingAvg", "list number", 2, &kMParams_24[0]},
    {"movingMax", "list number", 2, &kMParams_24[2]},
    {"movingMin", "list number", 2, &kMParams_24[4]},
    {"movingSum", "list number", 2, &kMParams_24[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_25[] = {
    {"v", "list number"},
    {"newMin", "number"},
    {"newMax", "number"},
    {"v", "list number"},
    {"lo", "number"},
    {"hi", "number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_25[] = {
    {"rescale", "list number", 3, &kMParams_25[0]},
    {"clip", "list number", 3, &kMParams_25[3]},
    {"absValues", "list number", 1, &kMParams_25[6]},
    {"negateAll", "list number", 1, &kMParams_25[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_26[] = {
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list text"},
    {"v", "list text"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_26[] = {
    {"sortAsc", "list number", 1, &kMParams_26[0]},
    {"sortDesc", "list number", 1, &kMParams_26[1]},
    {"sortTextAsc", "list text", 1, &kMParams_26[2]},
    {"sortTextDesc", "list text", 1, &kMParams_26[3]},
    {"isSorted", "bool", 1, &kMParams_26[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_27[] = {
    {"v", "list number"},
    {"target", "number"},
    {"v", "list number"},
    {"target", "number"},
    {"v", "list number"},
    {"target", "number"},
    {"v", "list number"},
    {"target", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_27[] = {
    {"linearSearch", "number", 2, &kMParams_27[0]},
    {"contains", "bool", 2, &kMParams_27[2]},
    {"countValue", "number", 2, &kMParams_27[4]},
    {"lastIndexOf", "number", 2, &kMParams_27[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_28[] = {
    {"v", "list number"},
    {"target", "number"},
    {"v", "list number"},
    {"target", "number"},
    {"v", "list number"},
    {"target", "number"},
    {"v", "list number"},
    {"val", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_28[] = {
    {"binarySearch", "number", 2, &kMParams_28[0]},
    {"lowerBound", "number", 2, &kMParams_28[2]},
    {"upperBound", "number", 2, &kMParams_28[4]},
    {"insertSorted", "list number", 2, &kMParams_28[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_29[] = {
    {"v", "list number"},
    {"v", "list text"},
    {"v", "list number"},
    {"v", "list number"},
    {"val", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_29[] = {
    {"unique", "list number", 1, &kMParams_29[0]},
    {"uniqueText", "list text", 1, &kMParams_29[1]},
    {"duplicates", "list number", 1, &kMParams_29[2]},
    {"frequency", "number", 2, &kMParams_29[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_30[] = {
    {"v", "list number"},
    {"pivot", "number"},
    {"v", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {"threshold", "number"},
    {"v", "list number"},
    {"threshold", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_30[] = {
    {"partitionAt", "list number", 2, &kMParams_30[0]},
    {"splitHalf", "list number", 1, &kMParams_30[2]},
    {"secondHalf", "list number", 1, &kMParams_30[3]},
    {"filterGt", "list number", 2, &kMParams_30[4]},
    {"filterLt", "list number", 2, &kMParams_30[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_31[] = {
    {"v", "list number"},
    {"k", "number"},
    {"v", "list number"},
    {"k", "number"},
    {"v", "list number"},
    {"k", "number"},
    {"v", "list number"},
    {"k", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_31[] = {
    {"topK", "list number", 2, &kMParams_31[0]},
    {"bottomK", "list number", 2, &kMParams_31[2]},
    {"kthLargest", "number", 2, &kMParams_31[4]},
    {"kthSmallest", "number", 2, &kMParams_31[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_32[] = {
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_32[] = {
    {"mergeSorted", "list number", 2, &kMParams_32[0]},
    {"mergeAll", "list number", 2, &kMParams_32[2]},
    {"intersect", "list number", 2, &kMParams_32[4]},
    {"unionAll", "list number", 2, &kMParams_32[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_33[] = {
    {"v", "list number"},
    {"n", "number"},
    {"v", "list number"},
    {"n", "number"},
    {"v", "list number"},
    {"v", "list number"},
    {"seed", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_33[] = {
    {"rotateLeft", "list number", 2, &kMParams_33[0]},
    {"rotateRight", "list number", 2, &kMParams_33[2]},
    {"reverseList", "list number", 1, &kMParams_33[4]},
    {"shuffleSeed", "list number", 2, &kMParams_33[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_34[] = {
    {"v", "list number"},
    {"size", "number"},
    {"v", "list number"},
    {"n", "number"},
    {"v", "list number"},
    {"n", "number"},
    {"v", "list number"},
    {"start", "number"},
    {"end", "number"},
    {"v", "list number"},
    {"index", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_34[] = {
    {"chunkCount", "number", 2, &kMParams_34[0]},
    {"take", "list number", 2, &kMParams_34[2]},
    {"drop", "list number", 2, &kMParams_34[4]},
    {"slice", "list number", 3, &kMParams_34[6]},
    {"chunkAt", "list number", 3, &kMParams_34[9]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_35[] = {
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_35[] = {
    {"zipAdd", "list number", 2, &kMParams_35[0]},
    {"zipMul", "list number", 2, &kMParams_35[2]},
    {"zipSub", "list number", 2, &kMParams_35[4]},
    {"zipMax", "list number", 2, &kMParams_35[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_36[] = {
    {"s", "text"},
    {"s", "text"},
    {"delim", "text"},
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_36[] = {
    {"splitLines", "list text", 1, &kMParams_36[0]},
    {"splitBy", "list text", 2, &kMParams_36[1]},
    {"splitWords", "list text", 1, &kMParams_36[3]},
    {"splitChars", "list text", 1, &kMParams_36[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_37[] = {
    {"parts", "list text"},
    {"parts", "list text"},
    {"delim", "text"},
    {"parts", "list text"},
    {"parts", "list text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_37[] = {
    {"joinLines", "text", 1, &kMParams_37[0]},
    {"joinWith", "text", 2, &kMParams_37[1]},
    {"joinComma", "text", 1, &kMParams_37[3]},
    {"joinSpace", "text", 1, &kMParams_37[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_38[] = {
    {"v", "list text"},
    {"v", "list text"},
    {"minLen", "number"},
    {"v", "list text"},
    {"sub", "text"},
    {"v", "list text"},
    {"prefix", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_38[] = {
    {"filterEmpty", "list text", 1, &kMParams_38[0]},
    {"filterLonger", "list text", 2, &kMParams_38[1]},
    {"filterContains", "list text", 2, &kMParams_38[3]},
    {"filterStarts", "list text", 2, &kMParams_38[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_39[] = {
    {"v", "list text"},
    {"v", "list text"},
    {"v", "list text"},
    {"v", "list text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_39[] = {
    {"mapUpper", "list text", 1, &kMParams_39[0]},
    {"mapLower", "list text", 1, &kMParams_39[1]},
    {"mapTrim", "list text", 1, &kMParams_39[2]},
    {"mapLength", "list number", 1, &kMParams_39[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_40[] = {
    {"v", "list text"},
    {"len", "number"},
    {"v", "list text"},
    {"prefix", "text"},
    {"v", "list text"},
    {"v", "list text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_40[] = {
    {"groupByLen", "list text", 2, &kMParams_40[0]},
    {"groupByPrefix", "list text", 2, &kMParams_40[2]},
    {"longestString", "text", 1, &kMParams_40[4]},
    {"shortestString", "text", 1, &kMParams_40[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_41[] = {
    {"v", "list text"},
    {"v", "list text"},
    {"v", "list text"},
    {"index", "number"},
    {"v", "list text"},
    {"seed", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_41[] = {
    {"pickFirst", "text", 1, &kMParams_41[0]},
    {"pickLast", "text", 1, &kMParams_41[1]},
    {"pickAt", "text", 2, &kMParams_41[2]},
    {"pickRandom", "text", 2, &kMParams_41[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_42[] = {
    {"d1", "text"},
    {"d2", "text"},
    {"date", "text"},
    {"days", "number"},
    {"year", "number"},
    {"year", "number"},
    {"month", "number"},
    {"date", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_42[] = {
    {"daysBetween", "number", 2, &kMParams_42[0]},
    {"addDays", "text", 2, &kMParams_42[2]},
    {"isLeapYear", "bool", 1, &kMParams_42[4]},
    {"daysInMonth", "number", 2, &kMParams_42[5]},
    {"weekday", "number", 1, &kMParams_42[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_43[] = {
    {"year", "number"},
    {"month", "number"},
    {"day", "number"},
    {"date", "text"},
    {"date", "text"},
    {"date", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_43[] = {
    {"formatIso", "text", 3, &kMParams_43[0]},
    {"parseYear", "number", 1, &kMParams_43[3]},
    {"parseMonth", "number", 1, &kMParams_43[4]},
    {"parseDay", "number", 1, &kMParams_43[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_44[] = {
    {"h", "number"},
    {"m", "number"},
    {"d", "number"},
    {"s", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_44[] = {
    {"hoursToMinutes", "number", 1, &kMParams_44[0]},
    {"minutesToSeconds", "number", 1, &kMParams_44[1]},
    {"daysToHours", "number", 1, &kMParams_44[2]},
    {"secondsToHours", "number", 1, &kMParams_44[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_45[] = {
    {"date", "text"},
    {"days", "number"},
    {"date", "text"},
    {"date", "text"},
    {"offset", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_45[] = {
    {"epochDays", "number", 1, &kMParams_45[0]},
    {"fromEpochDays", "text", 1, &kMParams_45[1]},
    {"isValidDate", "bool", 1, &kMParams_45[2]},
    {"todayOffset", "number", 2, &kMParams_45[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_46[] = {
    {"month", "number"},
    {"date", "text"},
    {"month", "number"},
    {"date", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_46[] = {
    {"quarterOf", "number", 1, &kMParams_46[0]},
    {"weekOfYear", "number", 1, &kMParams_46[1]},
    {"monthName", "text", 1, &kMParams_46[2]},
    {"dayName", "text", 1, &kMParams_46[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_47[] = {
    {"birth", "text"},
    {"today", "text"},
    {"birth", "text"},
    {"today", "text"},
    {"birth", "text"},
    {"today", "text"},
    {"birth", "text"},
    {"today", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_47[] = {
    {"ageYears", "number", 2, &kMParams_47[0]},
    {"ageMonths", "number", 2, &kMParams_47[2]},
    {"ageDays", "number", 2, &kMParams_47[4]},
    {"isBirthday", "bool", 2, &kMParams_47[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_48[] = {
    {"offset", "number"},
    {"localTime", "text"},
    {"offsetHours", "number"},
    {"utcTime", "text"},
    {"offsetHours", "number"},
    {"hours", "number"},
    {"minutes", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_48[] = {
    {"utcOffsetHours", "number", 1, &kMParams_48[0]},
    {"toUtc", "text", 2, &kMParams_48[1]},
    {"fromUtc", "text", 2, &kMParams_48[3]},
    {"formatTime", "text", 2, &kMParams_48[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_49[] = {
    {"d1", "text"},
    {"d2", "text"},
    {"d1", "text"},
    {"d2", "text"},
    {"date", "text"},
    {"months", "number"},
    {"date", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_49[] = {
    {"monthsBetween", "number", 2, &kMParams_49[0]},
    {"yearsBetween", "number", 2, &kMParams_49[2]},
    {"addMonths", "text", 2, &kMParams_49[4]},
    {"endOfMonth", "text", 1, &kMParams_49[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_50[] = {
    {"start", "text"},
    {"end", "text"},
    {"date", "text"},
    {"date", "text"},
    {"start", "text"},
    {"end", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_50[] = {
    {"elapsedDays", "number", 2, &kMParams_50[0]},
    {"isWeekend", "bool", 1, &kMParams_50[2]},
    {"nextWeekday", "text", 1, &kMParams_50[3]},
    {"businessDays", "number", 2, &kMParams_50[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_51[] = {
    {"month", "number"},
    {"month", "number"},
    {"month", "number"},
    {"month", "number"},
    {"lat", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_51[] = {
    {"seasonOf", "text", 1, &kMParams_51[0]},
    {"isSummer", "bool", 1, &kMParams_51[1]},
    {"isWinter", "bool", 1, &kMParams_51[2]},
    {"daylightHours", "number", 2, &kMParams_51[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_52[] = {
    {"url", "text"},
    {"url", "text"},
    {"url", "text"},
    {"url", "text"},
    {"url", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_52[] = {
    {"getScheme", "text", 1, &kMParams_52[0]},
    {"getHost", "text", 1, &kMParams_52[1]},
    {"getPath", "text", 1, &kMParams_52[2]},
    {"getQuery", "text", 1, &kMParams_52[3]},
    {"hasQuery", "bool", 1, &kMParams_52[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_53[] = {
    {"scheme", "text"},
    {"host", "text"},
    {"path", "text"},
    {"base", "text"},
    {"query", "text"},
    {"key", "text"},
    {"value", "text"},
    {"params", "list text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_53[] = {
    {"buildUrl", "text", 3, &kMParams_53[0]},
    {"buildWithQuery", "text", 2, &kMParams_53[3]},
    {"encodeParam", "text", 2, &kMParams_53[5]},
    {"joinParams", "text", 1, &kMParams_53[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_54[] = {
    {"query", "text"},
    {"query", "text"},
    {"key", "text"},
    {"query", "text"},
    {"query", "text"},
    {"key", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_54[] = {
    {"parseQuery", "list text", 1, &kMParams_54[0]},
    {"getParam", "text", 2, &kMParams_54[1]},
    {"paramCount", "number", 1, &kMParams_54[3]},
    {"hasParam", "bool", 2, &kMParams_54[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_55[] = {
    {"json", "text"},
    {"key", "text"},
    {"json", "text"},
    {"key", "text"},
    {"json", "text"},
    {"json", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_55[] = {
    {"parseString", "text", 2, &kMParams_55[0]},
    {"parseNumber", "number", 2, &kMParams_55[2]},
    {"isValidJson", "bool", 1, &kMParams_55[4]},
    {"keyCount", "number", 1, &kMParams_55[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_56[] = {
    {"pairs", "list text"},
    {"items", "list text"},
    {"key", "text"},
    {"value", "text"},
    {"key", "text"},
    {"value", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_56[] = {
    {"buildObject", "text", 1, &kMParams_56[0]},
    {"buildArray", "text", 1, &kMParams_56[1]},
    {"quoteKey", "text", 2, &kMParams_56[2]},
    {"quoteNum", "text", 2, &kMParams_56[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_57[] = {
    {"line", "text"},
    {"line", "text"},
    {"index", "number"},
    {"line", "text"},
    {"csv", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_57[] = {
    {"parseRow", "list text", 1, &kMParams_57[0]},
    {"getField", "text", 2, &kMParams_57[1]},
    {"fieldCount", "number", 1, &kMParams_57[3]},
    {"parseAll", "list text", 1, &kMParams_57[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_58[] = {
    {"fields", "list text"},
    {"field", "text"},
    {"rows", "list text"},
    {"field", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_58[] = {
    {"buildRow", "text", 1, &kMParams_58[0]},
    {"escapeField", "text", 1, &kMParams_58[1]},
    {"buildCsv", "text", 1, &kMParams_58[2]},
    {"quoteField", "text", 1, &kMParams_58[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_59[] = {
    {"path", "text"},
    {"path", "text"},
    {"path", "text"},
    {"path", "text"},
    {"a", "text"},
    {"b", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_59[] = {
    {"basename", "text", 1, &kMParams_59[0]},
    {"dirname", "text", 1, &kMParams_59[1]},
    {"extension", "text", 1, &kMParams_59[2]},
    {"stem", "text", 1, &kMParams_59[3]},
    {"joinPath", "text", 2, &kMParams_59[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_60[] = {
    {"mime", "text"},
    {"mime", "text"},
    {"mime", "text"},
    {"mime", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_60[] = {
    {"mainType", "text", 1, &kMParams_60[0]},
    {"subType", "text", 1, &kMParams_60[1]},
    {"isText", "bool", 1, &kMParams_60[2]},
    {"isImage", "bool", 1, &kMParams_60[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_61[] = {
    {"code", "number"},
    {"code", "number"},
    {"code", "number"},
    {"code", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_61[] = {
    {"statusClass", "number", 1, &kMParams_61[0]},
    {"isClientError", "bool", 1, &kMParams_61[1]},
    {"isServerError", "bool", 1, &kMParams_61[2]},
    {"statusText", "text", 1, &kMParams_61[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_62[] = {
    {"email", "text"},
    {"email", "text"},
    {"email", "text"},
    {"email", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_62[] = {
    {"localPart", "text", 1, &kMParams_62[0]},
    {"domainPart", "text", 1, &kMParams_62[1]},
    {"isValidEmail", "bool", 1, &kMParams_62[2]},
    {"normalizeEmail", "text", 1, &kMParams_62[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_63[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_63[] = {
    {"encodeBasic", "text", 1, &kMParams_63[0]},
    {"decodeBasic", "text", 1, &kMParams_63[1]},
    {"isBase64", "bool", 1, &kMParams_63[2]},
    {"paddedLength", "number", 1, &kMParams_63[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_64[] = {
    {"a", "number"},
    {"b", "number"},
    {"c", "number"},
    {"d", "number"},
    {"m", "list number"},
    {"m", "list number"},
    {"m", "list number"},
    {"s", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_64[] = {
    {"create2x2", "list number", 4, &kMParams_64[0]},
    {"det2x2", "number", 1, &kMParams_64[4]},
    {"trace2x2", "number", 1, &kMParams_64[5]},
    {"scale2x2", "list number", 2, &kMParams_64[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_65[] = {
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"m", "list number"},
    {"m", "list number"},
    {"s", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_65[] = {
    {"add", "list number", 2, &kMParams_65[0]},
    {"sub", "list number", 2, &kMParams_65[2]},
    {"neg", "list number", 1, &kMParams_65[4]},
    {"addScalar", "list number", 2, &kMParams_65[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_66[] = {
    {"a", "list number"},
    {"b", "list number"},
    {"m", "list number"},
    {"s", "number"},
    {"a", "list number"},
    {"b", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_66[] = {
    {"mul2x2", "list number", 2, &kMParams_66[0]},
    {"mulScalar", "list number", 2, &kMParams_66[2]},
    {"dot2", "number", 2, &kMParams_66[4]},
    {"norm2", "number", 1, &kMParams_66[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_67[] = {
    {"m", "list number"},
    {"m", "list number"},
    {"m", "list number"},
    {"n", "number"},
    {"ignored", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_67[] = {
    {"transpose2x2", "list number", 1, &kMParams_67[0]},
    {"transpose3x3", "list number", 1, &kMParams_67[1]},
    {"isSquare", "bool", 2, &kMParams_67[2]},
    {"identity2", "list number", 1, &kMParams_67[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_68[] = {
    {"m", "list number"},
    {"m", "list number"},
    {"m", "list number"},
    {"m", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_68[] = {
    {"det3x3", "list number", 1, &kMParams_68[0]},
    {"det2x2", "number", 1, &kMParams_68[1]},
    {"isSingular", "bool", 1, &kMParams_68[2]},
    {"cofactor2", "list number", 1, &kMParams_68[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_69[] = {
    {"m", "list number"},
    {"m", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"m", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_69[] = {
    {"inv2x2", "list number", 1, &kMParams_69[0]},
    {"adj2x2", "list number", 1, &kMParams_69[1]},
    {"solve2x2", "list number", 2, &kMParams_69[2]},
    {"condition2x2", "number", 1, &kMParams_69[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_70[] = {
    {"a", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"b", "list number"},
    {"v", "list number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_70[] = {
    {"cross3", "list number", 2, &kMParams_70[0]},
    {"dot3", "number", 2, &kMParams_70[2]},
    {"length3", "number", 1, &kMParams_70[4]},
    {"normalize3", "list number", 1, &kMParams_70[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_71[] = {
    {"angle", "number"},
    {"m", "list number"},
    {"v", "list number"},
    {"x", "number"},
    {"y", "number"},
    {"angle", "number"},
    {"deg", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_71[] = {
    {"rotate2d", "list number", 1, &kMParams_71[0]},
    {"apply2d", "list number", 2, &kMParams_71[1]},
    {"rotatePoint", "list number", 3, &kMParams_71[3]},
    {"degreesToRad", "number", 1, &kMParams_71[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_72[] = {
    {"m", "list number"},
    {"cols", "number"},
    {"m", "list number"},
    {"rows", "number"},
    {"cols", "number"},
    {"m", "list number"},
    {"m", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_72[] = {
    {"rowSum", "list number", 2, &kMParams_72[0]},
    {"colSum", "list number", 3, &kMParams_72[2]},
    {"frobeniusNorm", "number", 1, &kMParams_72[5]},
    {"maxAbs", "number", 1, &kMParams_72[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_73[] = {
    {"a1", "number"},
    {"b1", "number"},
    {"c1", "number"},
    {"a2", "number"},
    {"b2", "number"},
    {"c2", "number"},
    {"m", "list number"},
    {"b", "list number"},
    {"a", "list number"},
    {"x", "list number"},
    {"b", "list number"},
    {"m", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_73[] = {
    {"solveLinear2", "list number", 6, &kMParams_73[0]},
    {"solve3eq", "list number", 2, &kMParams_73[6]},
    {"residual", "number", 3, &kMParams_73[8]},
    {"isConsistent", "bool", 1, &kMParams_73[11]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_74[] = {
    {"pv", "number"},
    {"rate", "number"},
    {"periods", "number"},
    {"fv", "number"},
    {"rate", "number"},
    {"periods", "number"},
    {"payment", "number"},
    {"rate", "number"},
    {"periods", "number"},
    {"pv", "number"},
    {"rate", "number"},
    {"periods", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_74[] = {
    {"futureValue", "number", 3, &kMParams_74[0]},
    {"presentValue", "number", 3, &kMParams_74[3]},
    {"annuity", "number", 3, &kMParams_74[6]},
    {"payment", "number", 3, &kMParams_74[9]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_75[] = {
    {"balance", "number"},
    {"rate", "number"},
    {"payment", "number"},
    {"interest", "number"},
    {"balance", "number"},
    {"payment", "number"},
    {"interest", "number"},
    {"balance", "number"},
    {"rate", "number"},
    {"payment", "number"},
    {"months", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_75[] = {
    {"monthlyInterest", "number", 2, &kMParams_75[0]},
    {"principalPart", "number", 2, &kMParams_75[2]},
    {"remainingBalance", "number", 3, &kMParams_75[4]},
    {"amortSchedule", "list number", 4, &kMParams_75[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_76[] = {
    {"rate", "number"},
    {"cashflows", "list number"},
    {"rate", "number"},
    {"initial", "number"},
    {"returns", "list number"},
    {"npvVal", "number"},
    {"investment", "number"},
    {"cf", "number"},
    {"rate", "number"},
    {"period", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_76[] = {
    {"npv", "number", 2, &kMParams_76[0]},
    {"npvSimple", "number", 3, &kMParams_76[2]},
    {"profitability", "number", 2, &kMParams_76[5]},
    {"discountedCashflow", "number", 3, &kMParams_76[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_77[] = {
    {"cashflows", "list number"},
    {"cashflows", "list number"},
    {"financeRate", "number"},
    {"reinvestRate", "number"},
    {"cashflows", "list number"},
    {"gain", "number"},
    {"cost", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_77[] = {
    {"irrApprox", "number", 1, &kMParams_77[0]},
    {"mirr", "number", 3, &kMParams_77[1]},
    {"paybackPeriod", "number", 1, &kMParams_77[4]},
    {"roiPercent", "number", 2, &kMParams_77[5]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_78[] = {
    {"fixedCost", "number"},
    {"price", "number"},
    {"varCost", "number"},
    {"fixedCost", "number"},
    {"margin", "number"},
    {"price", "number"},
    {"varCost", "number"},
    {"currentSales", "number"},
    {"breakEven", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_78[] = {
    {"breakEvenUnits", "number", 3, &kMParams_78[0]},
    {"breakEvenRevenue", "number", 2, &kMParams_78[3]},
    {"contributionMargin", "number", 2, &kMParams_78[5]},
    {"marginOfSafety", "number", 2, &kMParams_78[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_79[] = {
    {"principal", "number"},
    {"rate", "number"},
    {"years", "number"},
    {"principal", "number"},
    {"rate", "number"},
    {"months", "number"},
    {"nominal", "number"},
    {"periods", "number"},
    {"rate", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_79[] = {
    {"compoundAnnual", "number", 3, &kMParams_79[0]},
    {"compoundMonthly", "number", 3, &kMParams_79[3]},
    {"effectiveRate", "number", 2, &kMParams_79[6]},
    {"doublingTime", "number", 1, &kMParams_79[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_80[] = {
    {"amount", "number"},
    {"rate", "number"},
    {"years", "number"},
    {"amount", "number"},
    {"rate", "number"},
    {"years", "number"},
    {"nominal", "number"},
    {"inflation", "number"},
    {"amount", "number"},
    {"inflation", "number"},
    {"years", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_80[] = {
    {"inflate", "number", 3, &kMParams_80[0]},
    {"deflate", "number", 3, &kMParams_80[3]},
    {"realReturn", "number", 2, &kMParams_80[6]},
    {"purchasingPower", "number", 3, &kMParams_80[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_81[] = {
    {"amount", "number"},
    {"rate", "number"},
    {"fromUsd", "number"},
    {"toUsd", "number"},
    {"bid", "number"},
    {"ask", "number"},
    {"bid", "number"},
    {"ask", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_81[] = {
    {"convert", "number", 2, &kMParams_81[0]},
    {"crossRate", "number", 2, &kMParams_81[2]},
    {"spread", "number", 2, &kMParams_81[4]},
    {"midRate", "number", 2, &kMParams_81[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_82[] = {
    {"returns", "list number"},
    {"weights", "list number"},
    {"shares", "list number"},
    {"prices", "list number"},
    {"values", "list number"},
    {"target", "list number"},
    {"weights", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_82[] = {
    {"weightedReturn", "number", 2, &kMParams_82[0]},
    {"portfolioValue", "number", 2, &kMParams_82[2]},
    {"rebalance", "list number", 2, &kMParams_82[4]},
    {"diversification", "number", 1, &kMParams_82[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_83[] = {
    {"income", "number"},
    {"rate", "number"},
    {"gross", "number"},
    {"rate", "number"},
    {"price", "number"},
    {"rate", "number"},
    {"price", "number"},
    {"rate", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_83[] = {
    {"incomeTax", "number", 2, &kMParams_83[0]},
    {"netIncome", "number", 2, &kMParams_83[2]},
    {"vatAmount", "number", 2, &kMParams_83[4]},
    {"priceWithVat", "number", 2, &kMParams_83[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_84[] = {
    {"cost", "number"},
    {"salvage", "number"},
    {"years", "number"},
    {"bookValue", "number"},
    {"rate", "number"},
    {"cost", "number"},
    {"salvage", "number"},
    {"years", "number"},
    {"year", "number"},
    {"annual", "number"},
    {"yearsElapsed", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_84[] = {
    {"straightLine", "number", 3, &kMParams_84[0]},
    {"decliningBalance", "number", 2, &kMParams_84[3]},
    {"sumOfYears", "number", 4, &kMParams_84[5]},
    {"accumDepreciation", "number", 2, &kMParams_84[9]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_85[] = {
    {"face", "number"},
    {"coupon", "number"},
    {"rate", "number"},
    {"years", "number"},
    {"price", "number"},
    {"face", "number"},
    {"coupon", "number"},
    {"years", "number"},
    {"coupon", "number"},
    {"price", "number"},
    {"years", "number"},
    {"coupon", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_85[] = {
    {"bondPrice", "number", 4, &kMParams_85[0]},
    {"yieldToMaturity", "number", 4, &kMParams_85[4]},
    {"currentYield", "number", 2, &kMParams_85[8]},
    {"duration", "number", 2, &kMParams_85[10]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_86[] = {
    {"base", "number"},
    {"height", "number"},
    {"w", "number"},
    {"h", "number"},
    {"w", "number"},
    {"h", "number"},
    {"w", "number"},
    {"h", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_86[] = {
    {"areaTriangle", "number", 2, &kMParams_86[0]},
    {"perimeterRect", "number", 2, &kMParams_86[2]},
    {"areaRect", "number", 2, &kMParams_86[4]},
    {"diagonal", "number", 2, &kMParams_86[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_87[] = {
    {"x", "list number"},
    {"y", "list number"},
    {"x", "list number"},
    {"y", "list number"},
    {"slope", "number"},
    {"intercept", "number"},
    {"x", "number"},
    {"x", "list number"},
    {"y", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_87[] = {
    {"linearSlope", "number", 2, &kMParams_87[0]},
    {"linearIntercept", "number", 2, &kMParams_87[2]},
    {"predict", "number", 3, &kMParams_87[4]},
    {"rSquared", "number", 2, &kMParams_87[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_88[] = {
    {"a", "number"},
    {"b", "number"},
    {"t", "number"},
    {"a", "list number"},
    {"b", "list number"},
    {"t", "number"},
    {"a", "number"},
    {"b", "number"},
    {"v", "number"},
    {"v", "number"},
    {"inLo", "number"},
    {"inHi", "number"},
    {"outLo", "number"},
    {"outHi", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_88[] = {
    {"lerp", "number", 3, &kMParams_88[0]},
    {"lerpList", "list number", 3, &kMParams_88[3]},
    {"inverseLerp", "number", 3, &kMParams_88[6]},
    {"remap", "number", 5, &kMParams_88[9]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_89[] = {
    {"p0", "number"},
    {"p1", "number"},
    {"p2", "number"},
    {"t", "number"},
    {"p0", "number"},
    {"p1", "number"},
    {"p2", "number"},
    {"p3", "number"},
    {"t", "number"},
    {"p0", "number"},
    {"p1", "number"},
    {"p2", "number"},
    {"t", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"x2", "number"},
    {"y2", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_89[] = {
    {"quadBezier", "number", 4, &kMParams_89[0]},
    {"cubicBezier", "number", 5, &kMParams_89[4]},
    {"bezierTangent", "number", 4, &kMParams_89[9]},
    {"bezierPoint2d", "list number", 7, &kMParams_89[13]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_90[] = {
    {"x1", "number"},
    {"y1", "number"},
    {"x2", "number"},
    {"y2", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"x2", "number"},
    {"y2", "number"},
    {"a", "list number"},
    {"b", "list number"},
    {"a", "text"},
    {"b", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_90[] = {
    {"manhattan2d", "number", 4, &kMParams_90[0]},
    {"chebyshev2d", "number", 4, &kMParams_90[4]},
    {"cosineSimilarity", "number", 2, &kMParams_90[8]},
    {"hammingDist", "number", 2, &kMParams_90[10]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_91[] = {
    {"value", "number"},
    {"minVal", "number"},
    {"maxVal", "number"},
    {"bins", "number"},
    {"counts", "list number"},
    {"counts", "list number"},
    {"counts", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_91[] = {
    {"binIndex", "number", 4, &kMParams_91[0]},
    {"normalizeHist", "list number", 1, &kMParams_91[4]},
    {"cumulativeHist", "list number", 1, &kMParams_91[5]},
    {"peakBin", "number", 1, &kMParams_91[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_92[] = {
    {"v", "list number"},
    {"value", "number"},
    {"v", "list number"},
    {"p", "number"},
    {"v", "list number"},
    {"pct", "number"},
    {"v", "list number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_92[] = {
    {"percentileRank", "number", 2, &kMParams_92[0]},
    {"percentileValue", "number", 2, &kMParams_92[2]},
    {"trimMean", "number", 2, &kMParams_92[4]},
    {"geometricMean", "number", 1, &kMParams_92[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_93[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_93[] = {
    {"crcSimple", "number", 1, &kMParams_93[0]},
    {"adler32lite", "number", 1, &kMParams_93[1]},
    {"fnvHash", "number", 1, &kMParams_93[2]},
    {"sumChecksum", "number", 1, &kMParams_93[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_94[] = {
    {"s", "text"},
    {"s", "text"},
    {"s", "text"},
    {"a", "number"},
    {"b", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_94[] = {
    {"djb2", "number", 1, &kMParams_94[0]},
    {"sdbm", "number", 1, &kMParams_94[1]},
    {"javaHash", "number", 1, &kMParams_94[2]},
    {"hashCombine", "number", 2, &kMParams_94[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_95[] = {
    {"s", "text"},
    {"n", "number"},
    {"s", "text"},
    {"n", "number"},
    {"s", "text"},
    {"n", "number"},
    {"s", "text"},
    {"key", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_95[] = {
    {"rotEncode", "text", 2, &kMParams_95[0]},
    {"rotDecode", "text", 2, &kMParams_95[2]},
    {"caesarShift", "text", 2, &kMParams_95[4]},
    {"xorCipher", "text", 2, &kMParams_95[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_96[] = {
    {"n", "number"},
    {"seed", "number"},
    {"hex32", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_96[] = {
    {"randomHex", "text", 1, &kMParams_96[0]},
    {"simpleUuid", "text", 1, &kMParams_96[1]},
    {"formatUuid", "text", 1, &kMParams_96[2]},
    {"isUuidFormat", "bool", 1, &kMParams_96[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_97[] = {
    {"seed", "number"},
    {"lo", "number"},
    {"hi", "number"},
    {"count", "number"},
    {"lo", "number"},
    {"hi", "number"},
    {"v", "list number"},
    {"seed", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_97[] = {
    {"seedRandom", "number", 1, &kMParams_97[0]},
    {"randomRange", "number", 2, &kMParams_97[1]},
    {"randomList", "list number", 3, &kMParams_97[3]},
    {"shuffleList", "list number", 2, &kMParams_97[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_98[] = {
    {"s", "text"},
    {"s", "text"},
    {"original", "number"},
    {"compressed", "number"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_98[] = {
    {"shannonEntropy", "number", 1, &kMParams_98[0]},
    {"uniqueRatio", "number", 1, &kMParams_98[1]},
    {"compressionRatio", "number", 2, &kMParams_98[2]},
    {"bitEntropy", "number", 1, &kMParams_98[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_99[] = {
    {"c", "number"},
    {"f", "number"},
    {"m", "number"},
    {"ft", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_99[] = {
    {"celsiusToFahrenheit", "number", 1, &kMParams_99[0]},
    {"fahrenheitToCelsius", "number", 1, &kMParams_99[1]},
    {"metersToFeet", "number", 1, &kMParams_99[2]},
    {"feetToMeters", "number", 1, &kMParams_99[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_100[] = {
    {"mass", "number"},
    {"velocity", "number"},
    {"mass", "number"},
    {"height", "number"},
    {"mass", "number"},
    {"velocity", "number"},
    {"mass", "number"},
    {"accel", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_100[] = {
    {"kineticEnergy", "number", 2, &kMParams_100[0]},
    {"potentialEnergy", "number", 2, &kMParams_100[2]},
    {"momentum", "number", 2, &kMParams_100[4]},
    {"force", "number", 2, &kMParams_100[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kMParams_101[] = {
    {"score", "number"},
    {"multiplier", "number"},
    {"level", "number"},
    {"xp", "number"},
    {"attack", "number"},
    {"defense", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kMFuncs_101[] = {
    {"scoreMultiplier", "number", 2, &kMParams_101[0]},
    {"xpForLevel", "number", 1, &kMParams_101[2]},
    {"levelFromXp", "number", 1, &kMParams_101[3]},
    {"damageCalc", "number", 2, &kMParams_101[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibModuleSpec kMediumModules[] = {
    {"textstats", "textstats", kMFuncs_0, 5, "med/medium_libs.hpp", false},
    {"charfreq", "charfreq", kMFuncs_1, 5, "med/medium_libs.hpp", false},
    {"sentsplit", "sentsplit", kMFuncs_2, 4, "med/medium_libs.hpp", false},
    {"wordtok", "wordtok", kMFuncs_3, 5, "med/medium_libs.hpp", false},
    {"ngrams", "ngrams", kMFuncs_4, 4, "med/medium_libs.hpp", false},
    {"palindrom2", "palindrom2", kMFuncs_5, 4, "med/medium_libs.hpp", false},
    {"anagram2", "anagram2", kMFuncs_6, 4, "med/medium_libs.hpp", false},
    {"textwrap2", "textwrap2", kMFuncs_7, 4, "med/medium_libs.hpp", false},
    {"textsearch", "textsearch", kMFuncs_8, 5, "med/medium_libs.hpp", false},
    {"accentstrip", "accentstrip", kMFuncs_9, 4, "med/medium_libs.hpp", false},
    {"casemap2", "casemap2", kMFuncs_10, 4, "med/medium_libs.hpp", false},
    {"textdiff2", "textdiff2", kMFuncs_11, 4, "med/medium_libs.hpp", false},
    {"regexlite", "regexlite", kMFuncs_12, 5, "med/medium_libs.hpp", false},
    {"motfreq", "motfreq", kMFuncs_13, 4, "med/medium_libs.hpp", false},
    {"numstats", "numstats", kMFuncs_14, 5, "med/medium_libs.hpp", false},
    {"listmedian", "listmedian", kMFuncs_15, 4, "med/medium_libs.hpp", false},
    {"listvar", "listvar", kMFuncs_16, 4, "med/medium_libs.hpp", false},
    {"listmode", "listmode", kMFuncs_17, 4, "med/medium_libs.hpp", false},
    {"listcum", "listcum", kMFuncs_18, 4, "med/medium_libs.hpp", false},
    {"listnorm", "listnorm", kMFuncs_19, 4, "med/medium_libs.hpp", false},
    {"listcorr", "listcorr", kMFuncs_20, 4, "med/medium_libs.hpp", false},
    {"listoutlier", "listoutlier", kMFuncs_21, 4, "med/medium_libs.hpp", false},
    {"listquantile", "listquantile", kMFuncs_22, 4, "med/medium_libs.hpp", false},
    {"listfreq", "listfreq", kMFuncs_23, 4, "med/medium_libs.hpp", false},
    {"listmoving", "listmoving", kMFuncs_24, 4, "med/medium_libs.hpp", false},
    {"listscale", "listscale", kMFuncs_25, 4, "med/medium_libs.hpp", false},
    {"listsort", "listsort", kMFuncs_26, 5, "med/medium_libs.hpp", false},
    {"listsearch", "listsearch", kMFuncs_27, 4, "med/medium_libs.hpp", false},
    {"listbinary", "listbinary", kMFuncs_28, 4, "med/medium_libs.hpp", false},
    {"listunique2", "listunique2", kMFuncs_29, 4, "med/medium_libs.hpp", false},
    {"listpartition", "listpartition", kMFuncs_30, 5, "med/medium_libs.hpp", false},
    {"listtopk", "listtopk", kMFuncs_31, 4, "med/medium_libs.hpp", false},
    {"listmerge2", "listmerge2", kMFuncs_32, 4, "med/medium_libs.hpp", false},
    {"listrotate2", "listrotate2", kMFuncs_33, 4, "med/medium_libs.hpp", false},
    {"listchunk", "listchunk", kMFuncs_34, 5, "med/medium_libs.hpp", false},
    {"listzip2", "listzip2", kMFuncs_35, 4, "med/medium_libs.hpp", false},
    {"textsplit2", "textsplit2", kMFuncs_36, 4, "med/medium_libs.hpp", false},
    {"textjoin2", "textjoin2", kMFuncs_37, 4, "med/medium_libs.hpp", false},
    {"listfilter2", "listfilter2", kMFuncs_38, 4, "med/medium_libs.hpp", false},
    {"listmap2", "listmap2", kMFuncs_39, 4, "med/medium_libs.hpp", false},
    {"listgroup2", "listgroup2", kMFuncs_40, 4, "med/medium_libs.hpp", false},
    {"listpick2", "listpick2", kMFuncs_41, 4, "med/medium_libs.hpp", false},
    {"datecalc", "datecalc", kMFuncs_42, 5, "med/medium_libs.hpp", false},
    {"datefmt2", "datefmt2", kMFuncs_43, 4, "med/medium_libs.hpp", false},
    {"duration2", "duration2", kMFuncs_44, 4, "med/medium_libs.hpp", false},
    {"timestamp2", "timestamp2", kMFuncs_45, 4, "med/medium_libs.hpp", false},
    {"calendar2", "calendar2", kMFuncs_46, 4, "med/medium_libs.hpp", false},
    {"agecalc", "agecalc", kMFuncs_47, 4, "med/medium_libs.hpp", false},
    {"timezone2", "timezone2", kMFuncs_48, 4, "med/medium_libs.hpp", false},
    {"period2", "period2", kMFuncs_49, 4, "med/medium_libs.hpp", false},
    {"chrono2", "chrono2", kMFuncs_50, 4, "med/medium_libs.hpp", false},
    {"season2", "season2", kMFuncs_51, 4, "med/medium_libs.hpp", false},
    {"uriparse", "uriparse", kMFuncs_52, 5, "med/medium_libs.hpp", false},
    {"urlbuild", "urlbuild", kMFuncs_53, 4, "med/medium_libs.hpp", false},
    {"queryparse", "queryparse", kMFuncs_54, 4, "med/medium_libs.hpp", false},
    {"jsonparse2", "jsonparse2", kMFuncs_55, 4, "med/medium_libs.hpp", false},
    {"jsonbuild2", "jsonbuild2", kMFuncs_56, 4, "med/medium_libs.hpp", false},
    {"csvparse2", "csvparse2", kMFuncs_57, 4, "med/medium_libs.hpp", false},
    {"csvbuild2", "csvbuild2", kMFuncs_58, 4, "med/medium_libs.hpp", false},
    {"pathparse2", "pathparse2", kMFuncs_59, 5, "med/medium_libs.hpp", false},
    {"mimeparse2", "mimeparse2", kMFuncs_60, 4, "med/medium_libs.hpp", false},
    {"httpparse2", "httpparse2", kMFuncs_61, 4, "med/medium_libs.hpp", false},
    {"emailparse2", "emailparse2", kMFuncs_62, 4, "med/medium_libs.hpp", false},
    {"base64med", "base64med", kMFuncs_63, 4, "med/medium_libs.hpp", false},
    {"matrix2", "matrix2", kMFuncs_64, 4, "med/medium_libs.hpp", false},
    {"matadd", "matadd", kMFuncs_65, 4, "med/medium_libs.hpp", false},
    {"matmul2", "matmul2", kMFuncs_66, 4, "med/medium_libs.hpp", false},
    {"mattranspose", "mattranspose", kMFuncs_67, 4, "med/medium_libs.hpp", false},
    {"matdet2", "matdet2", kMFuncs_68, 4, "med/medium_libs.hpp", false},
    {"matinv2", "matinv2", kMFuncs_69, 4, "med/medium_libs.hpp", false},
    {"vector3", "vector3", kMFuncs_70, 4, "med/medium_libs.hpp", false},
    {"matrotate", "matrotate", kMFuncs_71, 4, "med/medium_libs.hpp", false},
    {"matstats", "matstats", kMFuncs_72, 4, "med/medium_libs.hpp", false},
    {"linsolve2", "linsolve2", kMFuncs_73, 4, "med/medium_libs.hpp", false},
    {"finance2", "finance2", kMFuncs_74, 4, "med/medium_libs.hpp", false},
    {"amortize2", "amortize2", kMFuncs_75, 4, "med/medium_libs.hpp", false},
    {"npv2", "npv2", kMFuncs_76, 4, "med/medium_libs.hpp", false},
    {"irr2", "irr2", kMFuncs_77, 4, "med/medium_libs.hpp", false},
    {"breakEven2", "breakEven2", kMFuncs_78, 4, "med/medium_libs.hpp", false},
    {"compound2", "compound2", kMFuncs_79, 4, "med/medium_libs.hpp", false},
    {"inflation2", "inflation2", kMFuncs_80, 4, "med/medium_libs.hpp", false},
    {"currency2", "currency2", kMFuncs_81, 4, "med/medium_libs.hpp", false},
    {"portfolio2", "portfolio2", kMFuncs_82, 4, "med/medium_libs.hpp", false},
    {"taxcalc2", "taxcalc2", kMFuncs_83, 4, "med/medium_libs.hpp", false},
    {"depreciation2", "depreciation2", kMFuncs_84, 4, "med/medium_libs.hpp", false},
    {"bondcalc2", "bondcalc2", kMFuncs_85, 4, "med/medium_libs.hpp", false},
    {"polygon2", "polygon2", kMFuncs_86, 4, "med/medium_libs.hpp", false},
    {"statsreg2", "statsreg2", kMFuncs_87, 4, "med/medium_libs.hpp", false},
    {"interpolate2", "interpolate2", kMFuncs_88, 4, "med/medium_libs.hpp", false},
    {"bezier2", "bezier2", kMFuncs_89, 4, "med/medium_libs.hpp", false},
    {"distance3", "distance3", kMFuncs_90, 4, "med/medium_libs.hpp", false},
    {"histogram2", "histogram2", kMFuncs_91, 4, "med/medium_libs.hpp", false},
    {"percentile2", "percentile2", kMFuncs_92, 4, "med/medium_libs.hpp", false},
    {"checksum2", "checksum2", kMFuncs_93, 4, "med/medium_libs.hpp", false},
    {"hash2", "hash2", kMFuncs_94, 4, "med/medium_libs.hpp", false},
    {"rotN", "rotN", kMFuncs_95, 4, "med/medium_libs.hpp", false},
    {"uuid2", "uuid2", kMFuncs_96, 4, "med/medium_libs.hpp", false},
    {"random2", "random2", kMFuncs_97, 4, "med/medium_libs.hpp", false},
    {"entropy2", "entropy2", kMFuncs_98, 4, "med/medium_libs.hpp", false},
    {"units2", "units2", kMFuncs_99, 4, "med/medium_libs.hpp", false},
    {"physics2", "physics2", kMFuncs_100, 4, "med/medium_libs.hpp", false},
    {"gamestats2", "gamestats2", kMFuncs_101, 4, "med/medium_libs.hpp", false},
    {nullptr, nullptr, nullptr, 0, nullptr, false}
};

const std::size_t kMediumModuleCount = 102;

} // namespace

const StdlibModuleSpec* mediumCatalogFindModule(const std::string& name) {
    for (std::size_t i = 0; i < kMediumModuleCount; ++i) {
        if (name == kMediumModules[i].importName || name == kMediumModules[i].moduleName)
            return &kMediumModules[i];
    }
    return nullptr;
}

bool mediumCatalogIsMediumModule(const std::string& name) {
    return mediumCatalogFindModule(name) != nullptr;
}

} // namespace afrilang