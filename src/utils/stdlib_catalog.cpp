#include "afrilang/stdlib_catalog.hpp"

namespace afrilang {
namespace {

const StdlibParamSpec kParams_0[] = {
    {"n", "number"},
    {"a", "number"},
    {"b", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_0[] = {
    {"absNumber", "number", 1, &kParams_0[0]},
    {"absDiff", "number", 2, &kParams_0[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1[] = {
    {"n", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1[] = {
    {"sqrtNumber", "number", 1, &kParams_1[0]},
    {"square", "number", 1, &kParams_1[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_2[] = {
    {"n", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_2[] = {
    {"cbrtNumber", "number", 1, &kParams_2[0]},
    {"cube", "number", 1, &kParams_2[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_3[] = {
    {"a", "number"},
    {"b", "number"},
    {"a", "number"},
    {"b", "number"},
    {"c", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_3[] = {
    {"min2", "number", 2, &kParams_3[0]},
    {"min3", "number", 3, &kParams_3[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_4[] = {
    {"a", "number"},
    {"b", "number"},
    {"a", "number"},
    {"b", "number"},
    {"c", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_4[] = {
    {"max2", "number", 2, &kParams_4[0]},
    {"max3", "number", 3, &kParams_4[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_5[] = {
    {"n", "number"},
    {"lo", "number"},
    {"hi", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_5[] = {
    {"clamp", "number", 3, &kParams_5[0]},
    {"clamp01", "number", 1, &kParams_5[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_6[] = {
    {"a", "number"},
    {"b", "number"},
    {"t", "number"},
    {"a", "number"},
    {"b", "number"},
    {"v", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_6[] = {
    {"lerp", "number", 3, &kParams_6[0]},
    {"inverseLerp", "number", 3, &kParams_6[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_7[] = {
    {"n", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_7[] = {
    {"sign", "number", 1, &kParams_7[0]},
    {"isPositive", "bool", 1, &kParams_7[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_8[] = {
    {"n", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_8[] = {
    {"isEven", "bool", 1, &kParams_8[0]},
    {"isOdd", "bool", 1, &kParams_8[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_9[] = {
    {"deg", "number"},
    {"deg", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_9[] = {
    {"sinDeg", "number", 1, &kParams_9[0]},
    {"cosDeg", "number", 1, &kParams_9[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_10[] = {
    {"deg", "number"},
    {"deg", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_10[] = {
    {"tanDeg", "number", 1, &kParams_10[0]},
    {"cotDeg", "number", 1, &kParams_10[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_11[] = {
    {"n", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_11[] = {
    {"asinSafe", "number", 1, &kParams_11[0]},
    {"acosSafe", "number", 1, &kParams_11[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_12[] = {
    {"n", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_12[] = {
    {"sinhN", "number", 1, &kParams_12[0]},
    {"coshN", "number", 1, &kParams_12[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_13[] = {
    {"d", "number"},
    {"r", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_13[] = {
    {"degToRad", "number", 1, &kParams_13[0]},
    {"radToDeg", "number", 1, &kParams_13[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_14[] = {
    {"n", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_14[] = {
    {"roundN", "number", 1, &kParams_14[0]},
    {"truncN", "number", 1, &kParams_14[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_15[] = {
    {"a", "number"},
    {"b", "number"},
    {"n", "number"},
    {"lo", "number"},
    {"hi", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_15[] = {
    {"mod", "number", 2, &kParams_15[0]},
    {"wrap", "number", 3, &kParams_15[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_16[] = {
    {"a", "number"},
    {"b", "number"},
    {"a", "number"},
    {"b", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_16[] = {
    {"gcd", "number", 2, &kParams_16[0]},
    {"lcm", "number", 2, &kParams_16[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_17[] = {
    {"n", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_17[] = {
    {"factorial", "number", 1, &kParams_17[0]},
    {"doubleFact", "number", 1, &kParams_17[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_18[] = {
    {"n", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_18[] = {
    {"fib", "number", 1, &kParams_18[0]},
    {"fibB", "number", 1, &kParams_18[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_19[] = {
    {"n", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_19[] = {
    {"isPrime", "bool", 1, &kParams_19[0]},
    {"nextPrime", "number", 1, &kParams_19[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_20[] = {
    {"a", "number"},
    {"b", "number"},
    {"a", "number"},
    {"b", "number"},
    {"c", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_20[] = {
    {"mean2", "number", 2, &kParams_20[0]},
    {"mean3", "number", 3, &kParams_20[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_21[] = {
    {"part", "number"},
    {"whole", "number"},
    {"oldVal", "number"},
    {"newVal", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_21[] = {
    {"percent", "number", 2, &kParams_21[0]},
    {"percentChange", "number", 2, &kParams_21[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_22[] = {
    {"a", "number"},
    {"b", "number"},
    {"a", "number"},
    {"b", "number"},
    {"total", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_22[] = {
    {"ratio", "number", 2, &kParams_22[0]},
    {"proportion", "number", 3, &kParams_22[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_23[] = {
    {"sides", "number"},
    {"ignored", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_23[] = {
    {"roll", "number", 1, &kParams_23[0]},
    {"roll2d6", "number", 1, &kParams_23[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_24[] = {
    {"ignored", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_24[] = {
    {"flip", "bool", 1, &kParams_24[0]},
    {"flipN", "number", 1, &kParams_24[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_25[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_25[] = {
    {"toUpper", "text", 1, &kParams_25[0]},
    {"toLower", "text", 1, &kParams_25[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_26[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_26[] = {
    {"capitalize", "text", 1, &kParams_26[0]},
    {"titleWord", "text", 1, &kParams_26[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_27[] = {
    {"s", "text"},
    {"prefix", "text"},
    {"s", "text"},
    {"suffix", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_27[] = {
    {"startsWith", "bool", 2, &kParams_27[0]},
    {"endsWith", "bool", 2, &kParams_27[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_28[] = {
    {"s", "text"},
    {"n", "number"},
    {"c", "text"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_28[] = {
    {"repeatText", "text", 2, &kParams_28[0]},
    {"repeatChar", "text", 2, &kParams_28[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_29[] = {
    {"s", "text"},
    {"n", "number"},
    {"ch", "text"},
    {"s", "text"},
    {"n", "number"},
    {"ch", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_29[] = {
    {"padLeft", "text", 3, &kParams_29[0]},
    {"padRight", "text", 3, &kParams_29[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_30[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_30[] = {
    {"reverseText", "text", 1, &kParams_30[0]},
    {"reverseWords", "text", 1, &kParams_30[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_31[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_31[] = {
    {"length", "number", 1, &kParams_31[0]},
    {"isEmpty", "bool", 1, &kParams_31[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_32[] = {
    {"a", "text"},
    {"b", "text"},
    {"a", "text"},
    {"b", "text"},
    {"c", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_32[] = {
    {"concat2", "text", 2, &kParams_32[0]},
    {"concat3", "text", 3, &kParams_32[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_33[] = {
    {"a", "text"},
    {"b", "text"},
    {"a", "text"},
    {"b", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_33[] = {
    {"equals", "bool", 2, &kParams_33[0]},
    {"equalsIgnoreCase", "bool", 2, &kParams_33[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_34[] = {
    {"c", "number"},
    {"f", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_34[] = {
    {"cToF", "number", 1, &kParams_34[0]},
    {"fToC", "number", 1, &kParams_34[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_35[] = {
    {"c", "number"},
    {"k", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_35[] = {
    {"cToK", "number", 1, &kParams_35[0]},
    {"kToC", "number", 1, &kParams_35[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_36[] = {
    {"km", "number"},
    {"mi", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_36[] = {
    {"kmToMiles", "number", 1, &kParams_36[0]},
    {"milesToKm", "number", 1, &kParams_36[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_37[] = {
    {"kg", "number"},
    {"lb", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_37[] = {
    {"kgToLb", "number", 1, &kParams_37[0]},
    {"lbToKg", "number", 1, &kParams_37[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_38[] = {
    {"b", "number"},
    {"kb", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_38[] = {
    {"bytesToKb", "number", 1, &kParams_38[0]},
    {"kbToMb", "number", 1, &kParams_38[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_39[] = {
    {"s", "number"},
    {"m", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_39[] = {
    {"secToMin", "number", 1, &kParams_39[0]},
    {"minToHour", "number", 1, &kParams_39[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_40[] = {
    {"ms", "number"},
    {"s", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_40[] = {
    {"msToSec", "number", 1, &kParams_40[0]},
    {"secToMs", "number", 1, &kParams_40[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_41[] = {
    {"d", "number"},
    {"a", "number"},
    {"b", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_41[] = {
    {"normalizeAngle", "number", 1, &kParams_41[0]},
    {"angleDiff", "number", 2, &kParams_41[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_42[] = {
    {"n", "number"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_42[] = {
    {"toHex", "text", 1, &kParams_42[0]},
    {"fromHex", "number", 1, &kParams_42[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_43[] = {
    {"n", "number"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_43[] = {
    {"toBinary", "text", 1, &kParams_43[0]},
    {"fromBinary", "number", 1, &kParams_43[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_44[] = {
    {"n", "number"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_44[] = {
    {"toOctal", "text", 1, &kParams_44[0]},
    {"fromOctal", "number", 1, &kParams_44[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_45[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_45[] = {
    {"rot13", "text", 1, &kParams_45[0]},
    {"rot47", "text", 1, &kParams_45[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_46[] = {
    {"s", "text"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_46[] = {
    {"hashText", "number", 1, &kParams_46[0]},
    {"hashNumber", "number", 1, &kParams_46[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_47[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_47[] = {
    {"xorChecksum", "number", 1, &kParams_47[0]},
    {"sumBytes", "number", 1, &kParams_47[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_48[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_48[] = {
    {"slugify", "text", 1, &kParams_48[0]},
    {"deslugify", "text", 1, &kParams_48[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_49[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_49[] = {
    {"isEmail", "bool", 1, &kParams_49[0]},
    {"domainOf", "text", 1, &kParams_49[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_50[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_50[] = {
    {"isPhone", "bool", 1, &kParams_50[0]},
    {"digitsOnly", "text", 1, &kParams_50[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_51[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_51[] = {
    {"isIpv4", "bool", 1, &kParams_51[0]},
    {"countDots", "number", 1, &kParams_51[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_52[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_52[] = {
    {"escapeHtml", "text", 1, &kParams_52[0]},
    {"unescapeHtml", "text", 1, &kParams_52[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_53[] = {
    {"x1", "number"},
    {"y1", "number"},
    {"x2", "number"},
    {"y2", "number"},
    {"x1", "number"},
    {"x2", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_53[] = {
    {"distance2d", "number", 4, &kParams_53[0]},
    {"midpointX", "number", 2, &kParams_53[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_54[] = {
    {"w", "number"},
    {"h", "number"},
    {"w", "number"},
    {"h", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_54[] = {
    {"area", "number", 2, &kParams_54[0]},
    {"perimeter", "number", 2, &kParams_54[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_55[] = {
    {"r", "number"},
    {"r", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_55[] = {
    {"area", "number", 1, &kParams_55[0]},
    {"circumference", "number", 1, &kParams_55[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_56[] = {
    {"b", "number"},
    {"h", "number"},
    {"a", "number"},
    {"b", "number"},
    {"c", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_56[] = {
    {"areaBaseHeight", "number", 2, &kParams_56[0]},
    {"heron", "number", 3, &kParams_56[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_57[] = {
    {"x1", "number"},
    {"y1", "number"},
    {"x2", "number"},
    {"y2", "number"},
    {"x", "number"},
    {"y", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_57[] = {
    {"dot2", "number", 4, &kParams_57[0]},
    {"length2", "number", 2, &kParams_57[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_58[] = {
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"w1", "number"},
    {"h1", "number"},
    {"x2", "number"},
    {"y2", "number"},
    {"w2", "number"},
    {"h2", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_58[] = {
    {"pointInRect", "bool", 6, &kParams_58[0]},
    {"rectsOverlap", "bool", 8, &kParams_58[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_59[] = {
    {"r", "number"},
    {"g", "number"},
    {"b", "number"},
    {"packed", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_59[] = {
    {"rgb", "number", 3, &kParams_59[0]},
    {"redOf", "number", 1, &kParams_59[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_60[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_60[] = {
    {"easeIn", "number", 1, &kParams_60[0]},
    {"easeOut", "number", 1, &kParams_60[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_61[] = {
    {"x", "number"},
    {"x", "number"},
    {"y", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_61[] = {
    {"noise1D", "number", 1, &kParams_61[0]},
    {"noise2D", "number", 2, &kParams_61[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_62[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_62[] = {
    {"parseMajor", "number", 1, &kParams_62[0]},
    {"bumpMajor", "text", 1, &kParams_62[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_63[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_63[] = {
    {"isAlpha", "bool", 1, &kParams_63[0]},
    {"isDigit", "bool", 1, &kParams_63[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_64[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_64[] = {
    {"parseInt", "number", 1, &kParams_64[0]},
    {"parseFloat", "number", 1, &kParams_64[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_65[] = {
    {"n", "number"},
    {"decimals", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_65[] = {
    {"formatNumber", "text", 2, &kParams_65[0]},
    {"formatPercent", "text", 1, &kParams_65[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_66[] = {
    {"n", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_66[] = {
    {"formatEuro", "text", 1, &kParams_66[0]},
    {"formatDollar", "text", 1, &kParams_66[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_67[] = {
    {"ignored", "number"},
    {"start", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_67[] = {
    {"nowMs", "number", 1, &kParams_67[0]},
    {"elapsedMs", "number", 1, &kParams_67[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_68[] = {
    {"a", "number"},
    {"b", "number"},
    {"a", "number"},
    {"b", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_68[] = {
    {"bitAnd", "number", 2, &kParams_68[0]},
    {"bitOr", "number", 2, &kParams_68[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_69[] = {
    {"n", "number"},
    {"b", "number"},
    {"n", "number"},
    {"b", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_69[] = {
    {"shl", "number", 2, &kParams_69[0]},
    {"shr", "number", 2, &kParams_69[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_70[] = {
    {"n", "number"},
    {"f", "number"},
    {"n", "number"},
    {"f", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_70[] = {
    {"hasFlag", "bool", 2, &kParams_70[0]},
    {"setFlag", "number", 2, &kParams_70[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_71[] = {
    {"a", "number"},
    {"b", "number"},
    {"a", "text"},
    {"b", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_71[] = {
    {"cmpNumber", "number", 2, &kParams_71[0]},
    {"cmpText", "number", 2, &kParams_71[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_72[] = {
    {"n", "number"},
    {"lo", "number"},
    {"hi", "number"},
    {"lo", "number"},
    {"hi", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_72[] = {
    {"inRange", "bool", 3, &kParams_72[0]},
    {"rangeSize", "number", 2, &kParams_72[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_73[] = {
    {"a", "number"},
    {"d", "number"},
    {"n", "number"},
    {"a", "number"},
    {"r", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_73[] = {
    {"arithmetic", "number", 3, &kParams_73[0]},
    {"geometric", "number", 3, &kParams_73[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_74[] = {
    {"n", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_74[] = {
    {"log10", "number", 1, &kParams_74[0]},
    {"log2", "number", 1, &kParams_74[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_75[] = {
    {"n", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_75[] = {
    {"pow2", "number", 1, &kParams_75[0]},
    {"pow10", "number", 1, &kParams_75[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_76[] = {
    {"a", "number"},
    {"b", "number"},
    {"a", "number"},
    {"b", "number"},
    {"c", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_76[] = {
    {"hypot2", "number", 2, &kParams_76[0]},
    {"hypot3", "number", 3, &kParams_76[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_77[] = {
    {"a", "number"},
    {"b", "number"},
    {"a", "number"},
    {"b", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_77[] = {
    {"sum2", "number", 2, &kParams_77[0]},
    {"product2", "number", 2, &kParams_77[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_78[] = {
    {"a", "number"},
    {"b", "number"},
    {"c", "number"},
    {"a", "number"},
    {"b", "number"},
    {"c", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_78[] = {
    {"sum3", "number", 3, &kParams_78[0]},
    {"product3", "number", 3, &kParams_78[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_79[] = {
    {"a", "number"},
    {"b", "number"},
    {"a", "number"},
    {"b", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_79[] = {
    {"delta", "number", 2, &kParams_79[0]},
    {"absDelta", "number", 2, &kParams_79[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_80[] = {
    {"a", "number"},
    {"b", "number"},
    {"c", "number"},
    {"d", "number"},
    {"a", "number"},
    {"b", "number"},
    {"c", "number"},
    {"d", "number"},
    {"e", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_80[] = {
    {"avg4", "number", 4, &kParams_80[0]},
    {"avg5", "number", 5, &kParams_80[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_81[] = {
    {"cost", "number"},
    {"price", "number"},
    {"cost", "number"},
    {"price", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_81[] = {
    {"margin", "number", 2, &kParams_81[0]},
    {"markup", "number", 2, &kParams_81[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_82[] = {
    {"amount", "number"},
    {"rate", "number"},
    {"amount", "number"},
    {"rate", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_82[] = {
    {"addTax", "number", 2, &kParams_82[0]},
    {"taxAmount", "number", 2, &kParams_82[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_83[] = {
    {"price", "number"},
    {"rate", "number"},
    {"price", "number"},
    {"rate", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_83[] = {
    {"applyDiscount", "number", 2, &kParams_83[0]},
    {"discountAmount", "number", 2, &kParams_83[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_84[] = {
    {"principal", "number"},
    {"rate", "number"},
    {"years", "number"},
    {"principal", "number"},
    {"rate", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_84[] = {
    {"simpleInterest", "number", 3, &kParams_84[0]},
    {"compoundOnce", "number", 2, &kParams_84[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_85[] = {
    {"principal", "number"},
    {"rate", "number"},
    {"months", "number"},
    {"payment", "number"},
    {"months", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_85[] = {
    {"monthlyPayment", "number", 3, &kParams_85[0]},
    {"totalPaid", "number", 2, &kParams_85[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_86[] = {
    {"kmh", "number"},
    {"ms", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_86[] = {
    {"kmhToMs", "number", 1, &kParams_86[0]},
    {"msToKmh", "number", 1, &kParams_86[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_87[] = {
    {"l", "number"},
    {"ml", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_87[] = {
    {"litersToMl", "number", 1, &kParams_87[0]},
    {"mlToLiters", "number", 1, &kParams_87[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_88[] = {
    {"m2", "number"},
    {"cm2", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_88[] = {
    {"m2ToCm2", "number", 1, &kParams_88[0]},
    {"cm2ToM2", "number", 1, &kParams_88[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_89[] = {
    {"bar", "number"},
    {"psi", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_89[] = {
    {"barToPsi", "number", 1, &kParams_89[0]},
    {"psiToBar", "number", 1, &kParams_89[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_90[] = {
    {"j", "number"},
    {"cal", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_90[] = {
    {"joulesToCal", "number", 1, &kParams_90[0]},
    {"calToJoules", "number", 1, &kParams_90[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_91[] = {
    {"kg", "number"},
    {"m", "number"},
    {"bmi", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_91[] = {
    {"bmi", "number", 2, &kParams_91[0]},
    {"bmiCategory", "text", 1, &kParams_91[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_92[] = {
    {"lat1", "number"},
    {"lon1", "number"},
    {"lat2", "number"},
    {"lon2", "number"},
    {"a", "number"},
    {"b", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_92[] = {
    {"haversineKm", "number", 4, &kParams_92[0]},
    {"midLat", "number", 2, &kParams_92[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_93[] = {
    {"lat1", "number"},
    {"lon1", "number"},
    {"lat2", "number"},
    {"lon2", "number"},
    {"deg", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_93[] = {
    {"bearingDeg", "number", 4, &kParams_93[0]},
    {"cardinal", "text", 1, &kParams_93[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_94[] = {
    {"n", "number"},
    {"ignored", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_94[] = {
    {"randomHex", "text", 1, &kParams_94[0]},
    {"simpleId", "text", 1, &kParams_94[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_95[] = {
    {"ignored", "number"},
    {"ignored", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_95[] = {
    {"nextId", "number", 1, &kParams_95[0]},
    {"resetId", "number", 1, &kParams_95[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_96[] = {
    {"key", "text"},
    {"key", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_96[] = {
    {"getEnv", "text", 1, &kParams_96[0]},
    {"hasEnv", "bool", 1, &kParams_96[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_97[] = {
    {"ignored", "number"},
    {"ignored", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_97[] = {
    {"osName", "text", 1, &kParams_97[0]},
    {"archName", "text", 1, &kParams_97[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_98[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_98[] = {
    {"normalizeSlashes", "text", 1, &kParams_98[0]},
    {"hasTrailingSlash", "bool", 1, &kParams_98[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_99[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_99[] = {
    {"urlEncodeSpace", "text", 1, &kParams_99[0]},
    {"urlDecodeSpace", "text", 1, &kParams_99[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_100[] = {
    {"line", "text"},
    {"line", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_100[] = {
    {"splitCsv2", "text", 1, &kParams_100[0]},
    {"splitCsvRest", "text", 1, &kParams_100[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_101[] = {
    {"s", "text"},
    {"key", "text"},
    {"value", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_101[] = {
    {"quote", "text", 1, &kParams_101[0]},
    {"pair", "text", 2, &kParams_101[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_102[] = {
    {"name", "text"},
    {"content", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_102[] = {
    {"tag", "text", 2, &kParams_102[0]},
    {"escapeXml", "text", 1, &kParams_102[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_103[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_103[] = {
    {"bold", "text", 1, &kParams_103[0]},
    {"italic", "text", 1, &kParams_103[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_104[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_104[] = {
    {"strengthScore", "number", 1, &kParams_104[0]},
    {"isStrong", "bool", 1, &kParams_104[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_105[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_105[] = {
    {"encode64", "text", 1, &kParams_105[0]},
    {"decode64", "text", 1, &kParams_105[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_106[] = {
    {"mime", "text"},
    {"mime", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_106[] = {
    {"isTextPlain", "bool", 1, &kParams_106[0]},
    {"isJson", "bool", 1, &kParams_106[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_107[] = {
    {"code", "number"},
    {"code", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_107[] = {
    {"isSuccess", "bool", 1, &kParams_107[0]},
    {"isRedirect", "bool", 1, &kParams_107[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_108[] = {
    {"score", "number"},
    {"level", "number"},
    {"xp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_108[] = {
    {"scoreBonus", "number", 2, &kParams_108[0]},
    {"levelFromXp", "number", 1, &kParams_108[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_109[] = {
    {"octave", "number"},
    {"note", "number"},
    {"ignored", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_109[] = {
    {"midiNote", "number", 2, &kParams_109[0]},
    {"freqA4", "number", 1, &kParams_109[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_110[] = {
    {"a", "number"},
    {"b", "number"},
    {"t", "number"},
    {"packed", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_110[] = {
    {"lerpColor", "number", 3, &kParams_110[0]},
    {"invertRgb", "number", 1, &kParams_110[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_111[] = {
    {"a", "number"},
    {"b", "number"},
    {"c", "number"},
    {"d", "number"},
    {"a", "number"},
    {"d", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_111[] = {
    {"det2", "number", 4, &kParams_111[0]},
    {"trace2", "number", 2, &kParams_111[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_112[] = {
    {"m", "number"},
    {"a", "number"},
    {"m", "number"},
    {"v", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_112[] = {
    {"force", "number", 2, &kParams_112[0]},
    {"kineticEnergy", "number", 2, &kParams_112[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_113[] = {
    {"mass", "number"},
    {"molarMass", "number"},
    {"moles", "number"},
    {"molarMass", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_113[] = {
    {"moles", "number", 2, &kParams_113[0]},
    {"mass", "number", 2, &kParams_113[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_114[] = {
    {"inch", "number"},
    {"cm", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_114[] = {
    {"inchToCm", "number", 1, &kParams_114[0]},
    {"cmToInch", "number", 1, &kParams_114[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_115[] = {
    {"ignored", "number"},
    {"ignored", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_115[] = {
    {"a4WidthCm", "number", 1, &kParams_115[0]},
    {"a4HeightCm", "number", 1, &kParams_115[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_116[] = {
    {"n", "number"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_116[] = {
    {"toRoman", "text", 1, &kParams_116[0]},
    {"fromRoman", "number", 1, &kParams_116[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_117[] = {
    {"n", "number"},
    {"b", "bool"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_117[] = {
    {"spellDigit", "text", 1, &kParams_117[0]},
    {"spellBool", "text", 1, &kParams_117[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_118[] = {
    {"ignored", "number"},
    {"count", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_118[] = {
    {"firstIndex", "number", 1, &kParams_118[0]},
    {"lastIndex", "number", 1, &kParams_118[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_119[] = {
    {"i", "number"},
    {"size", "number"},
    {"i", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_119[] = {
    {"wrapIndex", "number", 2, &kParams_119[0]},
    {"nextIndex", "number", 2, &kParams_119[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_120[] = {
    {"size", "number"},
    {"offset", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_120[] = {
    {"peekOffset", "number", 2, &kParams_120[0]},
    {"isEmptyStack", "bool", 1, &kParams_120[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_121[] = {
    {"a", "number"},
    {"b", "number"},
    {"a", "number"},
    {"b", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_121[] = {
    {"edgeKey", "number", 2, &kParams_121[0]},
    {"selfLoop", "bool", 2, &kParams_121[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_122[] = {
    {"n", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_122[] = {
    {"binarySteps", "number", 1, &kParams_122[0]},
    {"linearWorst", "number", 1, &kParams_122[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_123[] = {
    {"n", "number"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_123[] = {
    {"ascKey", "number", 1, &kParams_123[0]},
    {"descKey", "number", 1, &kParams_123[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_124[] = {
    {"s", "text"},
    {"n", "number"},
    {"s", "text"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_124[] = {
    {"truncate", "text", 2, &kParams_124[0]},
    {"ellipsize", "text", 2, &kParams_124[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_125[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_125[] = {
    {"collapseSpaces", "text", 1, &kParams_125[0]},
    {"isWhitespace", "bool", 1, &kParams_125[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_126[] = {
    {"s", "text"},
    {"n", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_126[] = {
    {"charCode", "number", 1, &kParams_126[0]},
    {"fromCharCode", "text", 1, &kParams_126[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_127[] = {
    {"a", "text"},
    {"b", "text"},
    {"a", "text"},
    {"b", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_127[] = {
    {"compareMajor", "number", 2, &kParams_127[0]},
    {"sameMajor", "bool", 2, &kParams_127[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_128[] = {
    {"s", "text"},
    {"b", "bool"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_128[] = {
    {"parseBool", "bool", 1, &kParams_128[0]},
    {"boolToText", "text", 1, &kParams_128[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_129[] = {
    {"attempt", "number"},
    {"attempt", "number"},
    {"max", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_129[] = {
    {"backoffMs", "number", 1, &kParams_129[0]},
    {"shouldRetry", "bool", 2, &kParams_129[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_130[] = {
    {"count", "number"},
    {"limit", "number"},
    {"count", "number"},
    {"limit", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_130[] = {
    {"allowBurst", "bool", 2, &kParams_130[0]},
    {"tokensLeft", "number", 2, &kParams_130[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_131[] = {
    {"ageMs", "number"},
    {"ttlMs", "number"},
    {"ageMs", "number"},
    {"ttlMs", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_131[] = {
    {"ttlExpired", "bool", 2, &kParams_131[0]},
    {"freshness", "number", 2, &kParams_131[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_132[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_132[] = {
    {"hashId", "text", 1, &kParams_132[0]},
    {"shortHash", "text", 1, &kParams_132[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_133[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_133[] = {
    {"decimalComma", "text", 1, &kParams_133[0]},
    {"decimalDot", "text", 1, &kParams_133[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_134[] = {
    {"ignored", "number"},
    {"year", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_134[] = {
    {"daysInYear", "number", 1, &kParams_134[0]},
    {"isLeap", "bool", 1, &kParams_134[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_135[] = {
    {"day", "number"},
    {"day", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_135[] = {
    {"weekIndex", "number", 1, &kParams_135[0]},
    {"isWeekendIndex", "bool", 1, &kParams_135[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_136[] = {
    {"ignored", "number"},
    {"utcHour", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_136[] = {
    {"utcOffsetHours", "number", 1, &kParams_136[0]},
    {"localHour", "number", 1, &kParams_136[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_137[] = {
    {"port", "number"},
    {"host", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_137[] = {
    {"isPortValid", "bool", 1, &kParams_137[0]},
    {"isLocalhost", "bool", 1, &kParams_137[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_138[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_138[] = {
    {"isValidHostname", "bool", 1, &kParams_138[0]},
    {"hasSubdomain", "bool", 1, &kParams_138[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_139[] = {
    {"a", "number"},
    {"b", "number"},
    {"port", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_139[] = {
    {"portPairKey", "number", 2, &kParams_139[0]},
    {"isEphemeralPort", "bool", 1, &kParams_139[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_140[] = {
    {"code", "number"},
    {"code", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_140[] = {
    {"exitOk", "bool", 1, &kParams_140[0]},
    {"exitFailed", "bool", 1, &kParams_140[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_141[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_141[] = {
    {"quoteShell", "text", 1, &kParams_141[0]},
    {"escapeShell", "text", 1, &kParams_141[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_142[] = {
    {"b", "number"},
    {"b", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_142[] = {
    {"kbFromBytes", "number", 1, &kParams_142[0]},
    {"mbFromBytes", "number", 1, &kParams_142[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_143[] = {
    {"pct", "number"},
    {"pct", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_143[] = {
    {"clampUsage", "number", 1, &kParams_143[0]},
    {"isHighLoad", "bool", 1, &kParams_143[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_144[] = {
    {"used", "number"},
    {"total", "number"},
    {"used", "number"},
    {"total", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_144[] = {
    {"usagePercent", "number", 2, &kParams_144[0]},
    {"freeSpace", "number", 2, &kParams_144[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_145[] = {
    {"s", "text"},
    {"s", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_145[] = {
    {"maskSecret", "text", 1, &kParams_145[0]},
    {"isMasked", "bool", 1, &kParams_145[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_146[] = {
    {"action", "text"},
    {"user", "text"},
    {"msg", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_146[] = {
    {"auditLine", "text", 2, &kParams_146[0]},
    {"timestampPrefix", "text", 1, &kParams_146[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_147[] = {
    {"pattern", "text"},
    {"value", "text"},
    {"pattern", "text"},
    {"a", "text"},
    {"b", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_147[] = {
    {"fill", "text", 2, &kParams_147[0]},
    {"fill2", "text", 3, &kParams_147[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_148[] = {
    {"name", "text"},
    {"name", "text"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_148[] = {
    {"greetFr", "text", 1, &kParams_148[0]},
    {"greetEn", "text", 1, &kParams_148[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_149[] = {
    {"score", "number"},
    {"score", "number"},
    {"min", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_149[] = {
    {"gradeLetter", "text", 1, &kParams_149[0]},
    {"passed", "bool", 2, &kParams_149[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_150[] = {
    {"correct", "number"},
    {"total", "number"},
    {"correct", "number"},
    {"total", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_150[] = {
    {"scorePercent", "number", 2, &kParams_150[0]},
    {"isPerfect", "bool", 2, &kParams_150[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_151[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_151[] = {
    {"falloff", "number", 2, &kParams_151[0]},
    {"shake", "number", 2, &kParams_151[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_152[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_152[] = {
    {"easeIn", "number", 1, &kParams_152[0]},
    {"falloff", "number", 2, &kParams_152[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_153[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_153[] = {
    {"easeOut", "number", 1, &kParams_153[0]},
    {"spring", "number", 4, &kParams_153[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_154[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_154[] = {
    {"spring", "number", 4, &kParams_154[0]},
    {"shake", "number", 2, &kParams_154[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_155[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_155[] = {
    {"easeIn", "number", 1, &kParams_155[0]},
    {"easeOut", "number", 1, &kParams_155[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_156[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_156[] = {
    {"falloff", "number", 2, &kParams_156[0]},
    {"shake", "number", 2, &kParams_156[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_157[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_157[] = {
    {"easeIn", "number", 1, &kParams_157[0]},
    {"falloff", "number", 2, &kParams_157[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_158[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_158[] = {
    {"easeOut", "number", 1, &kParams_158[0]},
    {"spring", "number", 4, &kParams_158[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_159[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_159[] = {
    {"spring", "number", 4, &kParams_159[0]},
    {"shake", "number", 2, &kParams_159[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_160[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_160[] = {
    {"easeIn", "number", 1, &kParams_160[0]},
    {"easeOut", "number", 1, &kParams_160[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_161[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_161[] = {
    {"falloff", "number", 2, &kParams_161[0]},
    {"shake", "number", 2, &kParams_161[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_162[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_162[] = {
    {"easeIn", "number", 1, &kParams_162[0]},
    {"falloff", "number", 2, &kParams_162[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_163[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_163[] = {
    {"easeOut", "number", 1, &kParams_163[0]},
    {"spring", "number", 4, &kParams_163[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_164[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_164[] = {
    {"spring", "number", 4, &kParams_164[0]},
    {"shake", "number", 2, &kParams_164[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_165[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_165[] = {
    {"easeIn", "number", 1, &kParams_165[0]},
    {"easeOut", "number", 1, &kParams_165[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_166[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_166[] = {
    {"falloff", "number", 2, &kParams_166[0]},
    {"shake", "number", 2, &kParams_166[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_167[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_167[] = {
    {"easeIn", "number", 1, &kParams_167[0]},
    {"falloff", "number", 2, &kParams_167[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_168[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_168[] = {
    {"easeOut", "number", 1, &kParams_168[0]},
    {"spring", "number", 4, &kParams_168[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_169[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_169[] = {
    {"spring", "number", 4, &kParams_169[0]},
    {"shake", "number", 2, &kParams_169[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_170[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_170[] = {
    {"easeIn", "number", 1, &kParams_170[0]},
    {"easeOut", "number", 1, &kParams_170[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_171[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_171[] = {
    {"falloff", "number", 2, &kParams_171[0]},
    {"shake", "number", 2, &kParams_171[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_172[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_172[] = {
    {"easeIn", "number", 1, &kParams_172[0]},
    {"falloff", "number", 2, &kParams_172[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_173[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_173[] = {
    {"easeOut", "number", 1, &kParams_173[0]},
    {"spring", "number", 4, &kParams_173[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_174[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_174[] = {
    {"spring", "number", 4, &kParams_174[0]},
    {"shake", "number", 2, &kParams_174[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_175[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_175[] = {
    {"easeIn", "number", 1, &kParams_175[0]},
    {"easeOut", "number", 1, &kParams_175[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_176[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_176[] = {
    {"falloff", "number", 2, &kParams_176[0]},
    {"shake", "number", 2, &kParams_176[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_177[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_177[] = {
    {"easeIn", "number", 1, &kParams_177[0]},
    {"falloff", "number", 2, &kParams_177[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_178[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_178[] = {
    {"easeOut", "number", 1, &kParams_178[0]},
    {"spring", "number", 4, &kParams_178[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_179[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_179[] = {
    {"spring", "number", 4, &kParams_179[0]},
    {"shake", "number", 2, &kParams_179[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_180[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_180[] = {
    {"easeIn", "number", 1, &kParams_180[0]},
    {"easeOut", "number", 1, &kParams_180[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_181[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_181[] = {
    {"falloff", "number", 2, &kParams_181[0]},
    {"shake", "number", 2, &kParams_181[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_182[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_182[] = {
    {"easeIn", "number", 1, &kParams_182[0]},
    {"falloff", "number", 2, &kParams_182[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_183[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_183[] = {
    {"easeOut", "number", 1, &kParams_183[0]},
    {"spring", "number", 4, &kParams_183[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_184[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_184[] = {
    {"spring", "number", 4, &kParams_184[0]},
    {"shake", "number", 2, &kParams_184[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_185[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_185[] = {
    {"easeIn", "number", 1, &kParams_185[0]},
    {"easeOut", "number", 1, &kParams_185[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_186[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_186[] = {
    {"falloff", "number", 2, &kParams_186[0]},
    {"shake", "number", 2, &kParams_186[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_187[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_187[] = {
    {"easeIn", "number", 1, &kParams_187[0]},
    {"falloff", "number", 2, &kParams_187[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_188[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_188[] = {
    {"easeOut", "number", 1, &kParams_188[0]},
    {"spring", "number", 4, &kParams_188[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_189[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_189[] = {
    {"spring", "number", 4, &kParams_189[0]},
    {"shake", "number", 2, &kParams_189[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_190[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_190[] = {
    {"easeIn", "number", 1, &kParams_190[0]},
    {"easeOut", "number", 1, &kParams_190[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_191[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_191[] = {
    {"falloff", "number", 2, &kParams_191[0]},
    {"shake", "number", 2, &kParams_191[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_192[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_192[] = {
    {"easeIn", "number", 1, &kParams_192[0]},
    {"falloff", "number", 2, &kParams_192[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_193[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_193[] = {
    {"easeOut", "number", 1, &kParams_193[0]},
    {"spring", "number", 4, &kParams_193[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_194[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_194[] = {
    {"spring", "number", 4, &kParams_194[0]},
    {"shake", "number", 2, &kParams_194[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_195[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_195[] = {
    {"easeIn", "number", 1, &kParams_195[0]},
    {"easeOut", "number", 1, &kParams_195[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_196[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_196[] = {
    {"falloff", "number", 2, &kParams_196[0]},
    {"shake", "number", 2, &kParams_196[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_197[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_197[] = {
    {"easeIn", "number", 1, &kParams_197[0]},
    {"falloff", "number", 2, &kParams_197[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_198[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_198[] = {
    {"easeOut", "number", 1, &kParams_198[0]},
    {"spring", "number", 4, &kParams_198[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_199[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_199[] = {
    {"spring", "number", 4, &kParams_199[0]},
    {"shake", "number", 2, &kParams_199[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_200[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_200[] = {
    {"easeIn", "number", 1, &kParams_200[0]},
    {"easeOut", "number", 1, &kParams_200[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_201[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_201[] = {
    {"falloff", "number", 2, &kParams_201[0]},
    {"shake", "number", 2, &kParams_201[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_202[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_202[] = {
    {"easeIn", "number", 1, &kParams_202[0]},
    {"falloff", "number", 2, &kParams_202[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_203[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_203[] = {
    {"easeOut", "number", 1, &kParams_203[0]},
    {"spring", "number", 4, &kParams_203[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_204[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_204[] = {
    {"spring", "number", 4, &kParams_204[0]},
    {"shake", "number", 2, &kParams_204[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_205[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_205[] = {
    {"easeIn", "number", 1, &kParams_205[0]},
    {"easeOut", "number", 1, &kParams_205[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_206[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_206[] = {
    {"falloff", "number", 2, &kParams_206[0]},
    {"shake", "number", 2, &kParams_206[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_207[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_207[] = {
    {"easeIn", "number", 1, &kParams_207[0]},
    {"falloff", "number", 2, &kParams_207[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_208[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_208[] = {
    {"easeOut", "number", 1, &kParams_208[0]},
    {"spring", "number", 4, &kParams_208[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_209[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_209[] = {
    {"spring", "number", 4, &kParams_209[0]},
    {"shake", "number", 2, &kParams_209[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_210[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_210[] = {
    {"easeIn", "number", 1, &kParams_210[0]},
    {"easeOut", "number", 1, &kParams_210[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_211[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_211[] = {
    {"falloff", "number", 2, &kParams_211[0]},
    {"shake", "number", 2, &kParams_211[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_212[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_212[] = {
    {"easeIn", "number", 1, &kParams_212[0]},
    {"falloff", "number", 2, &kParams_212[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_213[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_213[] = {
    {"easeOut", "number", 1, &kParams_213[0]},
    {"spring", "number", 4, &kParams_213[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_214[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_214[] = {
    {"spring", "number", 4, &kParams_214[0]},
    {"shake", "number", 2, &kParams_214[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_215[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_215[] = {
    {"easeIn", "number", 1, &kParams_215[0]},
    {"easeOut", "number", 1, &kParams_215[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_216[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_216[] = {
    {"falloff", "number", 2, &kParams_216[0]},
    {"shake", "number", 2, &kParams_216[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_217[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_217[] = {
    {"easeIn", "number", 1, &kParams_217[0]},
    {"falloff", "number", 2, &kParams_217[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_218[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_218[] = {
    {"easeOut", "number", 1, &kParams_218[0]},
    {"spring", "number", 4, &kParams_218[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_219[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_219[] = {
    {"spring", "number", 4, &kParams_219[0]},
    {"shake", "number", 2, &kParams_219[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_220[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_220[] = {
    {"easeIn", "number", 1, &kParams_220[0]},
    {"easeOut", "number", 1, &kParams_220[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_221[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_221[] = {
    {"falloff", "number", 2, &kParams_221[0]},
    {"shake", "number", 2, &kParams_221[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_222[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_222[] = {
    {"easeIn", "number", 1, &kParams_222[0]},
    {"falloff", "number", 2, &kParams_222[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_223[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_223[] = {
    {"easeOut", "number", 1, &kParams_223[0]},
    {"spring", "number", 4, &kParams_223[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_224[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_224[] = {
    {"spring", "number", 4, &kParams_224[0]},
    {"shake", "number", 2, &kParams_224[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_225[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_225[] = {
    {"easeIn", "number", 1, &kParams_225[0]},
    {"easeOut", "number", 1, &kParams_225[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_226[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_226[] = {
    {"falloff", "number", 2, &kParams_226[0]},
    {"shake", "number", 2, &kParams_226[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_227[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_227[] = {
    {"easeIn", "number", 1, &kParams_227[0]},
    {"falloff", "number", 2, &kParams_227[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_228[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_228[] = {
    {"easeOut", "number", 1, &kParams_228[0]},
    {"spring", "number", 4, &kParams_228[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_229[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_229[] = {
    {"spring", "number", 4, &kParams_229[0]},
    {"shake", "number", 2, &kParams_229[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_230[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_230[] = {
    {"easeIn", "number", 1, &kParams_230[0]},
    {"easeOut", "number", 1, &kParams_230[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_231[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_231[] = {
    {"falloff", "number", 2, &kParams_231[0]},
    {"shake", "number", 2, &kParams_231[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_232[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_232[] = {
    {"easeIn", "number", 1, &kParams_232[0]},
    {"falloff", "number", 2, &kParams_232[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_233[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_233[] = {
    {"easeOut", "number", 1, &kParams_233[0]},
    {"spring", "number", 4, &kParams_233[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_234[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_234[] = {
    {"spring", "number", 4, &kParams_234[0]},
    {"shake", "number", 2, &kParams_234[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_235[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_235[] = {
    {"easeIn", "number", 1, &kParams_235[0]},
    {"easeOut", "number", 1, &kParams_235[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_236[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_236[] = {
    {"falloff", "number", 2, &kParams_236[0]},
    {"shake", "number", 2, &kParams_236[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_237[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_237[] = {
    {"easeIn", "number", 1, &kParams_237[0]},
    {"falloff", "number", 2, &kParams_237[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_238[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_238[] = {
    {"easeOut", "number", 1, &kParams_238[0]},
    {"spring", "number", 4, &kParams_238[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_239[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_239[] = {
    {"spring", "number", 4, &kParams_239[0]},
    {"shake", "number", 2, &kParams_239[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_240[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_240[] = {
    {"easeIn", "number", 1, &kParams_240[0]},
    {"easeOut", "number", 1, &kParams_240[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_241[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_241[] = {
    {"falloff", "number", 2, &kParams_241[0]},
    {"shake", "number", 2, &kParams_241[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_242[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_242[] = {
    {"easeIn", "number", 1, &kParams_242[0]},
    {"falloff", "number", 2, &kParams_242[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_243[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_243[] = {
    {"easeOut", "number", 1, &kParams_243[0]},
    {"spring", "number", 4, &kParams_243[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_244[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_244[] = {
    {"spring", "number", 4, &kParams_244[0]},
    {"shake", "number", 2, &kParams_244[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_245[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_245[] = {
    {"easeIn", "number", 1, &kParams_245[0]},
    {"easeOut", "number", 1, &kParams_245[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_246[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_246[] = {
    {"falloff", "number", 2, &kParams_246[0]},
    {"shake", "number", 2, &kParams_246[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_247[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_247[] = {
    {"easeIn", "number", 1, &kParams_247[0]},
    {"falloff", "number", 2, &kParams_247[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_248[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_248[] = {
    {"easeOut", "number", 1, &kParams_248[0]},
    {"spring", "number", 4, &kParams_248[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_249[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_249[] = {
    {"spring", "number", 4, &kParams_249[0]},
    {"shake", "number", 2, &kParams_249[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_250[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_250[] = {
    {"easeIn", "number", 1, &kParams_250[0]},
    {"easeOut", "number", 1, &kParams_250[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_251[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_251[] = {
    {"falloff", "number", 2, &kParams_251[0]},
    {"shake", "number", 2, &kParams_251[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_252[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_252[] = {
    {"easeIn", "number", 1, &kParams_252[0]},
    {"falloff", "number", 2, &kParams_252[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_253[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_253[] = {
    {"easeOut", "number", 1, &kParams_253[0]},
    {"spring", "number", 4, &kParams_253[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_254[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_254[] = {
    {"spring", "number", 4, &kParams_254[0]},
    {"shake", "number", 2, &kParams_254[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_255[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_255[] = {
    {"easeIn", "number", 1, &kParams_255[0]},
    {"easeOut", "number", 1, &kParams_255[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_256[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_256[] = {
    {"falloff", "number", 2, &kParams_256[0]},
    {"shake", "number", 2, &kParams_256[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_257[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_257[] = {
    {"easeIn", "number", 1, &kParams_257[0]},
    {"falloff", "number", 2, &kParams_257[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_258[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_258[] = {
    {"easeOut", "number", 1, &kParams_258[0]},
    {"spring", "number", 4, &kParams_258[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_259[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_259[] = {
    {"spring", "number", 4, &kParams_259[0]},
    {"shake", "number", 2, &kParams_259[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_260[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_260[] = {
    {"easeIn", "number", 1, &kParams_260[0]},
    {"easeOut", "number", 1, &kParams_260[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_261[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_261[] = {
    {"falloff", "number", 2, &kParams_261[0]},
    {"shake", "number", 2, &kParams_261[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_262[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_262[] = {
    {"easeIn", "number", 1, &kParams_262[0]},
    {"falloff", "number", 2, &kParams_262[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_263[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_263[] = {
    {"easeOut", "number", 1, &kParams_263[0]},
    {"spring", "number", 4, &kParams_263[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_264[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_264[] = {
    {"spring", "number", 4, &kParams_264[0]},
    {"shake", "number", 2, &kParams_264[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_265[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_265[] = {
    {"easeIn", "number", 1, &kParams_265[0]},
    {"easeOut", "number", 1, &kParams_265[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_266[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_266[] = {
    {"falloff", "number", 2, &kParams_266[0]},
    {"shake", "number", 2, &kParams_266[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_267[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_267[] = {
    {"easeIn", "number", 1, &kParams_267[0]},
    {"falloff", "number", 2, &kParams_267[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_268[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_268[] = {
    {"easeOut", "number", 1, &kParams_268[0]},
    {"spring", "number", 4, &kParams_268[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_269[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_269[] = {
    {"spring", "number", 4, &kParams_269[0]},
    {"shake", "number", 2, &kParams_269[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_270[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_270[] = {
    {"easeIn", "number", 1, &kParams_270[0]},
    {"easeOut", "number", 1, &kParams_270[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_271[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_271[] = {
    {"falloff", "number", 2, &kParams_271[0]},
    {"shake", "number", 2, &kParams_271[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_272[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_272[] = {
    {"easeIn", "number", 1, &kParams_272[0]},
    {"falloff", "number", 2, &kParams_272[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_273[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_273[] = {
    {"easeOut", "number", 1, &kParams_273[0]},
    {"spring", "number", 4, &kParams_273[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_274[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_274[] = {
    {"spring", "number", 4, &kParams_274[0]},
    {"shake", "number", 2, &kParams_274[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_275[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_275[] = {
    {"easeIn", "number", 1, &kParams_275[0]},
    {"easeOut", "number", 1, &kParams_275[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_276[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_276[] = {
    {"falloff", "number", 2, &kParams_276[0]},
    {"shake", "number", 2, &kParams_276[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_277[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_277[] = {
    {"easeIn", "number", 1, &kParams_277[0]},
    {"falloff", "number", 2, &kParams_277[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_278[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_278[] = {
    {"easeOut", "number", 1, &kParams_278[0]},
    {"spring", "number", 4, &kParams_278[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_279[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_279[] = {
    {"spring", "number", 4, &kParams_279[0]},
    {"shake", "number", 2, &kParams_279[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_280[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_280[] = {
    {"easeIn", "number", 1, &kParams_280[0]},
    {"easeOut", "number", 1, &kParams_280[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_281[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_281[] = {
    {"falloff", "number", 2, &kParams_281[0]},
    {"shake", "number", 2, &kParams_281[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_282[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_282[] = {
    {"easeIn", "number", 1, &kParams_282[0]},
    {"falloff", "number", 2, &kParams_282[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_283[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_283[] = {
    {"easeOut", "number", 1, &kParams_283[0]},
    {"spring", "number", 4, &kParams_283[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_284[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_284[] = {
    {"spring", "number", 4, &kParams_284[0]},
    {"shake", "number", 2, &kParams_284[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_285[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_285[] = {
    {"easeIn", "number", 1, &kParams_285[0]},
    {"easeOut", "number", 1, &kParams_285[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_286[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_286[] = {
    {"falloff", "number", 2, &kParams_286[0]},
    {"shake", "number", 2, &kParams_286[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_287[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_287[] = {
    {"easeIn", "number", 1, &kParams_287[0]},
    {"falloff", "number", 2, &kParams_287[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_288[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_288[] = {
    {"easeOut", "number", 1, &kParams_288[0]},
    {"spring", "number", 4, &kParams_288[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_289[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_289[] = {
    {"spring", "number", 4, &kParams_289[0]},
    {"shake", "number", 2, &kParams_289[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_290[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_290[] = {
    {"easeIn", "number", 1, &kParams_290[0]},
    {"easeOut", "number", 1, &kParams_290[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_291[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_291[] = {
    {"falloff", "number", 2, &kParams_291[0]},
    {"shake", "number", 2, &kParams_291[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_292[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_292[] = {
    {"easeIn", "number", 1, &kParams_292[0]},
    {"falloff", "number", 2, &kParams_292[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_293[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_293[] = {
    {"easeOut", "number", 1, &kParams_293[0]},
    {"spring", "number", 4, &kParams_293[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_294[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_294[] = {
    {"spring", "number", 4, &kParams_294[0]},
    {"shake", "number", 2, &kParams_294[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_295[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_295[] = {
    {"easeIn", "number", 1, &kParams_295[0]},
    {"easeOut", "number", 1, &kParams_295[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_296[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_296[] = {
    {"falloff", "number", 2, &kParams_296[0]},
    {"shake", "number", 2, &kParams_296[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_297[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_297[] = {
    {"easeIn", "number", 1, &kParams_297[0]},
    {"falloff", "number", 2, &kParams_297[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_298[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_298[] = {
    {"easeOut", "number", 1, &kParams_298[0]},
    {"spring", "number", 4, &kParams_298[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_299[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_299[] = {
    {"spring", "number", 4, &kParams_299[0]},
    {"shake", "number", 2, &kParams_299[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_300[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_300[] = {
    {"easeIn", "number", 1, &kParams_300[0]},
    {"easeOut", "number", 1, &kParams_300[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_301[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_301[] = {
    {"falloff", "number", 2, &kParams_301[0]},
    {"shake", "number", 2, &kParams_301[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_302[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_302[] = {
    {"easeIn", "number", 1, &kParams_302[0]},
    {"falloff", "number", 2, &kParams_302[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_303[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_303[] = {
    {"easeOut", "number", 1, &kParams_303[0]},
    {"spring", "number", 4, &kParams_303[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_304[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_304[] = {
    {"spring", "number", 4, &kParams_304[0]},
    {"shake", "number", 2, &kParams_304[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_305[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_305[] = {
    {"easeIn", "number", 1, &kParams_305[0]},
    {"easeOut", "number", 1, &kParams_305[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_306[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_306[] = {
    {"falloff", "number", 2, &kParams_306[0]},
    {"shake", "number", 2, &kParams_306[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_307[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_307[] = {
    {"easeIn", "number", 1, &kParams_307[0]},
    {"falloff", "number", 2, &kParams_307[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_308[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_308[] = {
    {"easeOut", "number", 1, &kParams_308[0]},
    {"spring", "number", 4, &kParams_308[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_309[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_309[] = {
    {"spring", "number", 4, &kParams_309[0]},
    {"shake", "number", 2, &kParams_309[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_310[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_310[] = {
    {"easeIn", "number", 1, &kParams_310[0]},
    {"easeOut", "number", 1, &kParams_310[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_311[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_311[] = {
    {"falloff", "number", 2, &kParams_311[0]},
    {"shake", "number", 2, &kParams_311[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_312[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_312[] = {
    {"easeIn", "number", 1, &kParams_312[0]},
    {"falloff", "number", 2, &kParams_312[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_313[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_313[] = {
    {"easeOut", "number", 1, &kParams_313[0]},
    {"spring", "number", 4, &kParams_313[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_314[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_314[] = {
    {"spring", "number", 4, &kParams_314[0]},
    {"shake", "number", 2, &kParams_314[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_315[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_315[] = {
    {"easeIn", "number", 1, &kParams_315[0]},
    {"easeOut", "number", 1, &kParams_315[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_316[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_316[] = {
    {"falloff", "number", 2, &kParams_316[0]},
    {"shake", "number", 2, &kParams_316[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_317[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_317[] = {
    {"easeIn", "number", 1, &kParams_317[0]},
    {"falloff", "number", 2, &kParams_317[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_318[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_318[] = {
    {"easeOut", "number", 1, &kParams_318[0]},
    {"spring", "number", 4, &kParams_318[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_319[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_319[] = {
    {"spring", "number", 4, &kParams_319[0]},
    {"shake", "number", 2, &kParams_319[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_320[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_320[] = {
    {"easeIn", "number", 1, &kParams_320[0]},
    {"easeOut", "number", 1, &kParams_320[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_321[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_321[] = {
    {"falloff", "number", 2, &kParams_321[0]},
    {"shake", "number", 2, &kParams_321[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_322[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_322[] = {
    {"easeIn", "number", 1, &kParams_322[0]},
    {"falloff", "number", 2, &kParams_322[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_323[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_323[] = {
    {"easeOut", "number", 1, &kParams_323[0]},
    {"spring", "number", 4, &kParams_323[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_324[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_324[] = {
    {"spring", "number", 4, &kParams_324[0]},
    {"shake", "number", 2, &kParams_324[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_325[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_325[] = {
    {"easeIn", "number", 1, &kParams_325[0]},
    {"easeOut", "number", 1, &kParams_325[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_326[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_326[] = {
    {"falloff", "number", 2, &kParams_326[0]},
    {"shake", "number", 2, &kParams_326[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_327[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_327[] = {
    {"easeIn", "number", 1, &kParams_327[0]},
    {"falloff", "number", 2, &kParams_327[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_328[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_328[] = {
    {"easeOut", "number", 1, &kParams_328[0]},
    {"spring", "number", 4, &kParams_328[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_329[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_329[] = {
    {"spring", "number", 4, &kParams_329[0]},
    {"shake", "number", 2, &kParams_329[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_330[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_330[] = {
    {"easeIn", "number", 1, &kParams_330[0]},
    {"easeOut", "number", 1, &kParams_330[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_331[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_331[] = {
    {"falloff", "number", 2, &kParams_331[0]},
    {"shake", "number", 2, &kParams_331[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_332[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_332[] = {
    {"easeIn", "number", 1, &kParams_332[0]},
    {"falloff", "number", 2, &kParams_332[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_333[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_333[] = {
    {"easeOut", "number", 1, &kParams_333[0]},
    {"spring", "number", 4, &kParams_333[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_334[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_334[] = {
    {"spring", "number", 4, &kParams_334[0]},
    {"shake", "number", 2, &kParams_334[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_335[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_335[] = {
    {"easeIn", "number", 1, &kParams_335[0]},
    {"easeOut", "number", 1, &kParams_335[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_336[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_336[] = {
    {"falloff", "number", 2, &kParams_336[0]},
    {"shake", "number", 2, &kParams_336[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_337[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_337[] = {
    {"easeIn", "number", 1, &kParams_337[0]},
    {"falloff", "number", 2, &kParams_337[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_338[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_338[] = {
    {"easeOut", "number", 1, &kParams_338[0]},
    {"spring", "number", 4, &kParams_338[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_339[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_339[] = {
    {"spring", "number", 4, &kParams_339[0]},
    {"shake", "number", 2, &kParams_339[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_340[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_340[] = {
    {"easeIn", "number", 1, &kParams_340[0]},
    {"easeOut", "number", 1, &kParams_340[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_341[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_341[] = {
    {"falloff", "number", 2, &kParams_341[0]},
    {"shake", "number", 2, &kParams_341[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_342[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_342[] = {
    {"easeIn", "number", 1, &kParams_342[0]},
    {"falloff", "number", 2, &kParams_342[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_343[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_343[] = {
    {"easeOut", "number", 1, &kParams_343[0]},
    {"spring", "number", 4, &kParams_343[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_344[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_344[] = {
    {"spring", "number", 4, &kParams_344[0]},
    {"shake", "number", 2, &kParams_344[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_345[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_345[] = {
    {"easeIn", "number", 1, &kParams_345[0]},
    {"easeOut", "number", 1, &kParams_345[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_346[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_346[] = {
    {"falloff", "number", 2, &kParams_346[0]},
    {"shake", "number", 2, &kParams_346[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_347[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_347[] = {
    {"easeIn", "number", 1, &kParams_347[0]},
    {"falloff", "number", 2, &kParams_347[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_348[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_348[] = {
    {"easeOut", "number", 1, &kParams_348[0]},
    {"spring", "number", 4, &kParams_348[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_349[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_349[] = {
    {"spring", "number", 4, &kParams_349[0]},
    {"shake", "number", 2, &kParams_349[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_350[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_350[] = {
    {"easeIn", "number", 1, &kParams_350[0]},
    {"easeOut", "number", 1, &kParams_350[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_351[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_351[] = {
    {"falloff", "number", 2, &kParams_351[0]},
    {"shake", "number", 2, &kParams_351[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_352[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_352[] = {
    {"easeIn", "number", 1, &kParams_352[0]},
    {"falloff", "number", 2, &kParams_352[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_353[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_353[] = {
    {"easeOut", "number", 1, &kParams_353[0]},
    {"spring", "number", 4, &kParams_353[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_354[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_354[] = {
    {"spring", "number", 4, &kParams_354[0]},
    {"shake", "number", 2, &kParams_354[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_355[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_355[] = {
    {"easeIn", "number", 1, &kParams_355[0]},
    {"easeOut", "number", 1, &kParams_355[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_356[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_356[] = {
    {"falloff", "number", 2, &kParams_356[0]},
    {"shake", "number", 2, &kParams_356[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_357[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_357[] = {
    {"easeIn", "number", 1, &kParams_357[0]},
    {"falloff", "number", 2, &kParams_357[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_358[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_358[] = {
    {"easeOut", "number", 1, &kParams_358[0]},
    {"spring", "number", 4, &kParams_358[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_359[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_359[] = {
    {"spring", "number", 4, &kParams_359[0]},
    {"shake", "number", 2, &kParams_359[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_360[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_360[] = {
    {"easeIn", "number", 1, &kParams_360[0]},
    {"easeOut", "number", 1, &kParams_360[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_361[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_361[] = {
    {"falloff", "number", 2, &kParams_361[0]},
    {"shake", "number", 2, &kParams_361[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_362[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_362[] = {
    {"easeIn", "number", 1, &kParams_362[0]},
    {"falloff", "number", 2, &kParams_362[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_363[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_363[] = {
    {"easeOut", "number", 1, &kParams_363[0]},
    {"spring", "number", 4, &kParams_363[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_364[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_364[] = {
    {"spring", "number", 4, &kParams_364[0]},
    {"shake", "number", 2, &kParams_364[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_365[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_365[] = {
    {"easeIn", "number", 1, &kParams_365[0]},
    {"easeOut", "number", 1, &kParams_365[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_366[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_366[] = {
    {"falloff", "number", 2, &kParams_366[0]},
    {"shake", "number", 2, &kParams_366[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_367[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_367[] = {
    {"easeIn", "number", 1, &kParams_367[0]},
    {"falloff", "number", 2, &kParams_367[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_368[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_368[] = {
    {"easeOut", "number", 1, &kParams_368[0]},
    {"spring", "number", 4, &kParams_368[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_369[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_369[] = {
    {"spring", "number", 4, &kParams_369[0]},
    {"shake", "number", 2, &kParams_369[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_370[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_370[] = {
    {"easeIn", "number", 1, &kParams_370[0]},
    {"easeOut", "number", 1, &kParams_370[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_371[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_371[] = {
    {"falloff", "number", 2, &kParams_371[0]},
    {"shake", "number", 2, &kParams_371[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_372[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_372[] = {
    {"easeIn", "number", 1, &kParams_372[0]},
    {"falloff", "number", 2, &kParams_372[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_373[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_373[] = {
    {"easeOut", "number", 1, &kParams_373[0]},
    {"spring", "number", 4, &kParams_373[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_374[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_374[] = {
    {"spring", "number", 4, &kParams_374[0]},
    {"shake", "number", 2, &kParams_374[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_375[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_375[] = {
    {"easeIn", "number", 1, &kParams_375[0]},
    {"easeOut", "number", 1, &kParams_375[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_376[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_376[] = {
    {"falloff", "number", 2, &kParams_376[0]},
    {"shake", "number", 2, &kParams_376[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_377[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_377[] = {
    {"easeIn", "number", 1, &kParams_377[0]},
    {"falloff", "number", 2, &kParams_377[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_378[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_378[] = {
    {"easeOut", "number", 1, &kParams_378[0]},
    {"spring", "number", 4, &kParams_378[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_379[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_379[] = {
    {"spring", "number", 4, &kParams_379[0]},
    {"shake", "number", 2, &kParams_379[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_380[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_380[] = {
    {"easeIn", "number", 1, &kParams_380[0]},
    {"easeOut", "number", 1, &kParams_380[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_381[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_381[] = {
    {"falloff", "number", 2, &kParams_381[0]},
    {"shake", "number", 2, &kParams_381[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_382[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_382[] = {
    {"easeIn", "number", 1, &kParams_382[0]},
    {"falloff", "number", 2, &kParams_382[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_383[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_383[] = {
    {"easeOut", "number", 1, &kParams_383[0]},
    {"spring", "number", 4, &kParams_383[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_384[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_384[] = {
    {"spring", "number", 4, &kParams_384[0]},
    {"shake", "number", 2, &kParams_384[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_385[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_385[] = {
    {"easeIn", "number", 1, &kParams_385[0]},
    {"easeOut", "number", 1, &kParams_385[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_386[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_386[] = {
    {"falloff", "number", 2, &kParams_386[0]},
    {"shake", "number", 2, &kParams_386[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_387[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_387[] = {
    {"easeIn", "number", 1, &kParams_387[0]},
    {"falloff", "number", 2, &kParams_387[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_388[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_388[] = {
    {"easeOut", "number", 1, &kParams_388[0]},
    {"spring", "number", 4, &kParams_388[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_389[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_389[] = {
    {"spring", "number", 4, &kParams_389[0]},
    {"shake", "number", 2, &kParams_389[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_390[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_390[] = {
    {"easeIn", "number", 1, &kParams_390[0]},
    {"easeOut", "number", 1, &kParams_390[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_391[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_391[] = {
    {"falloff", "number", 2, &kParams_391[0]},
    {"shake", "number", 2, &kParams_391[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_392[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_392[] = {
    {"easeIn", "number", 1, &kParams_392[0]},
    {"falloff", "number", 2, &kParams_392[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_393[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_393[] = {
    {"easeOut", "number", 1, &kParams_393[0]},
    {"spring", "number", 4, &kParams_393[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_394[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_394[] = {
    {"spring", "number", 4, &kParams_394[0]},
    {"shake", "number", 2, &kParams_394[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_395[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_395[] = {
    {"easeIn", "number", 1, &kParams_395[0]},
    {"easeOut", "number", 1, &kParams_395[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_396[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_396[] = {
    {"falloff", "number", 2, &kParams_396[0]},
    {"shake", "number", 2, &kParams_396[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_397[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_397[] = {
    {"easeIn", "number", 1, &kParams_397[0]},
    {"falloff", "number", 2, &kParams_397[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_398[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_398[] = {
    {"easeOut", "number", 1, &kParams_398[0]},
    {"spring", "number", 4, &kParams_398[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_399[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_399[] = {
    {"spring", "number", 4, &kParams_399[0]},
    {"shake", "number", 2, &kParams_399[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_400[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_400[] = {
    {"easeIn", "number", 1, &kParams_400[0]},
    {"easeOut", "number", 1, &kParams_400[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_401[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_401[] = {
    {"falloff", "number", 2, &kParams_401[0]},
    {"shake", "number", 2, &kParams_401[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_402[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_402[] = {
    {"easeIn", "number", 1, &kParams_402[0]},
    {"falloff", "number", 2, &kParams_402[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_403[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_403[] = {
    {"easeOut", "number", 1, &kParams_403[0]},
    {"spring", "number", 4, &kParams_403[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_404[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_404[] = {
    {"spring", "number", 4, &kParams_404[0]},
    {"shake", "number", 2, &kParams_404[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_405[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_405[] = {
    {"easeIn", "number", 1, &kParams_405[0]},
    {"easeOut", "number", 1, &kParams_405[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_406[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_406[] = {
    {"falloff", "number", 2, &kParams_406[0]},
    {"shake", "number", 2, &kParams_406[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_407[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_407[] = {
    {"easeIn", "number", 1, &kParams_407[0]},
    {"falloff", "number", 2, &kParams_407[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_408[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_408[] = {
    {"easeOut", "number", 1, &kParams_408[0]},
    {"spring", "number", 4, &kParams_408[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_409[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_409[] = {
    {"spring", "number", 4, &kParams_409[0]},
    {"shake", "number", 2, &kParams_409[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_410[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_410[] = {
    {"easeIn", "number", 1, &kParams_410[0]},
    {"easeOut", "number", 1, &kParams_410[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_411[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_411[] = {
    {"falloff", "number", 2, &kParams_411[0]},
    {"shake", "number", 2, &kParams_411[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_412[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_412[] = {
    {"easeIn", "number", 1, &kParams_412[0]},
    {"falloff", "number", 2, &kParams_412[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_413[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_413[] = {
    {"easeOut", "number", 1, &kParams_413[0]},
    {"spring", "number", 4, &kParams_413[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_414[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_414[] = {
    {"spring", "number", 4, &kParams_414[0]},
    {"shake", "number", 2, &kParams_414[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_415[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_415[] = {
    {"easeIn", "number", 1, &kParams_415[0]},
    {"easeOut", "number", 1, &kParams_415[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_416[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_416[] = {
    {"falloff", "number", 2, &kParams_416[0]},
    {"shake", "number", 2, &kParams_416[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_417[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_417[] = {
    {"easeIn", "number", 1, &kParams_417[0]},
    {"falloff", "number", 2, &kParams_417[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_418[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_418[] = {
    {"easeOut", "number", 1, &kParams_418[0]},
    {"spring", "number", 4, &kParams_418[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_419[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_419[] = {
    {"spring", "number", 4, &kParams_419[0]},
    {"shake", "number", 2, &kParams_419[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_420[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_420[] = {
    {"easeIn", "number", 1, &kParams_420[0]},
    {"easeOut", "number", 1, &kParams_420[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_421[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_421[] = {
    {"falloff", "number", 2, &kParams_421[0]},
    {"shake", "number", 2, &kParams_421[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_422[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_422[] = {
    {"easeIn", "number", 1, &kParams_422[0]},
    {"falloff", "number", 2, &kParams_422[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_423[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_423[] = {
    {"easeOut", "number", 1, &kParams_423[0]},
    {"spring", "number", 4, &kParams_423[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_424[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_424[] = {
    {"spring", "number", 4, &kParams_424[0]},
    {"shake", "number", 2, &kParams_424[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_425[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_425[] = {
    {"easeIn", "number", 1, &kParams_425[0]},
    {"easeOut", "number", 1, &kParams_425[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_426[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_426[] = {
    {"falloff", "number", 2, &kParams_426[0]},
    {"shake", "number", 2, &kParams_426[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_427[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_427[] = {
    {"easeIn", "number", 1, &kParams_427[0]},
    {"falloff", "number", 2, &kParams_427[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_428[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_428[] = {
    {"easeOut", "number", 1, &kParams_428[0]},
    {"spring", "number", 4, &kParams_428[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_429[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_429[] = {
    {"spring", "number", 4, &kParams_429[0]},
    {"shake", "number", 2, &kParams_429[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_430[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_430[] = {
    {"easeIn", "number", 1, &kParams_430[0]},
    {"easeOut", "number", 1, &kParams_430[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_431[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_431[] = {
    {"falloff", "number", 2, &kParams_431[0]},
    {"shake", "number", 2, &kParams_431[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_432[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_432[] = {
    {"easeIn", "number", 1, &kParams_432[0]},
    {"falloff", "number", 2, &kParams_432[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_433[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_433[] = {
    {"easeOut", "number", 1, &kParams_433[0]},
    {"spring", "number", 4, &kParams_433[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_434[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_434[] = {
    {"spring", "number", 4, &kParams_434[0]},
    {"shake", "number", 2, &kParams_434[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_435[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_435[] = {
    {"easeIn", "number", 1, &kParams_435[0]},
    {"easeOut", "number", 1, &kParams_435[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_436[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_436[] = {
    {"falloff", "number", 2, &kParams_436[0]},
    {"shake", "number", 2, &kParams_436[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_437[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_437[] = {
    {"easeIn", "number", 1, &kParams_437[0]},
    {"falloff", "number", 2, &kParams_437[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_438[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_438[] = {
    {"easeOut", "number", 1, &kParams_438[0]},
    {"spring", "number", 4, &kParams_438[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_439[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_439[] = {
    {"spring", "number", 4, &kParams_439[0]},
    {"shake", "number", 2, &kParams_439[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_440[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_440[] = {
    {"easeIn", "number", 1, &kParams_440[0]},
    {"easeOut", "number", 1, &kParams_440[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_441[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_441[] = {
    {"falloff", "number", 2, &kParams_441[0]},
    {"shake", "number", 2, &kParams_441[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_442[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_442[] = {
    {"easeIn", "number", 1, &kParams_442[0]},
    {"falloff", "number", 2, &kParams_442[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_443[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_443[] = {
    {"easeOut", "number", 1, &kParams_443[0]},
    {"spring", "number", 4, &kParams_443[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_444[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_444[] = {
    {"spring", "number", 4, &kParams_444[0]},
    {"shake", "number", 2, &kParams_444[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_445[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_445[] = {
    {"easeIn", "number", 1, &kParams_445[0]},
    {"easeOut", "number", 1, &kParams_445[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_446[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_446[] = {
    {"falloff", "number", 2, &kParams_446[0]},
    {"shake", "number", 2, &kParams_446[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_447[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_447[] = {
    {"easeIn", "number", 1, &kParams_447[0]},
    {"falloff", "number", 2, &kParams_447[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_448[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_448[] = {
    {"easeOut", "number", 1, &kParams_448[0]},
    {"spring", "number", 4, &kParams_448[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_449[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_449[] = {
    {"spring", "number", 4, &kParams_449[0]},
    {"shake", "number", 2, &kParams_449[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_450[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_450[] = {
    {"easeIn", "number", 1, &kParams_450[0]},
    {"easeOut", "number", 1, &kParams_450[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_451[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_451[] = {
    {"falloff", "number", 2, &kParams_451[0]},
    {"shake", "number", 2, &kParams_451[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_452[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_452[] = {
    {"easeIn", "number", 1, &kParams_452[0]},
    {"falloff", "number", 2, &kParams_452[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_453[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_453[] = {
    {"easeOut", "number", 1, &kParams_453[0]},
    {"spring", "number", 4, &kParams_453[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_454[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_454[] = {
    {"spring", "number", 4, &kParams_454[0]},
    {"shake", "number", 2, &kParams_454[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_455[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_455[] = {
    {"easeIn", "number", 1, &kParams_455[0]},
    {"easeOut", "number", 1, &kParams_455[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_456[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_456[] = {
    {"falloff", "number", 2, &kParams_456[0]},
    {"shake", "number", 2, &kParams_456[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_457[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_457[] = {
    {"easeIn", "number", 1, &kParams_457[0]},
    {"falloff", "number", 2, &kParams_457[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_458[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_458[] = {
    {"easeOut", "number", 1, &kParams_458[0]},
    {"spring", "number", 4, &kParams_458[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_459[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_459[] = {
    {"spring", "number", 4, &kParams_459[0]},
    {"shake", "number", 2, &kParams_459[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_460[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_460[] = {
    {"easeIn", "number", 1, &kParams_460[0]},
    {"easeOut", "number", 1, &kParams_460[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_461[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_461[] = {
    {"falloff", "number", 2, &kParams_461[0]},
    {"shake", "number", 2, &kParams_461[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_462[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_462[] = {
    {"easeIn", "number", 1, &kParams_462[0]},
    {"falloff", "number", 2, &kParams_462[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_463[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_463[] = {
    {"easeOut", "number", 1, &kParams_463[0]},
    {"spring", "number", 4, &kParams_463[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_464[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_464[] = {
    {"spring", "number", 4, &kParams_464[0]},
    {"shake", "number", 2, &kParams_464[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_465[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_465[] = {
    {"easeIn", "number", 1, &kParams_465[0]},
    {"easeOut", "number", 1, &kParams_465[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_466[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_466[] = {
    {"falloff", "number", 2, &kParams_466[0]},
    {"shake", "number", 2, &kParams_466[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_467[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_467[] = {
    {"easeIn", "number", 1, &kParams_467[0]},
    {"falloff", "number", 2, &kParams_467[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_468[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_468[] = {
    {"easeOut", "number", 1, &kParams_468[0]},
    {"spring", "number", 4, &kParams_468[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_469[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_469[] = {
    {"spring", "number", 4, &kParams_469[0]},
    {"shake", "number", 2, &kParams_469[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_470[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_470[] = {
    {"easeIn", "number", 1, &kParams_470[0]},
    {"easeOut", "number", 1, &kParams_470[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_471[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_471[] = {
    {"falloff", "number", 2, &kParams_471[0]},
    {"shake", "number", 2, &kParams_471[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_472[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_472[] = {
    {"easeIn", "number", 1, &kParams_472[0]},
    {"falloff", "number", 2, &kParams_472[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_473[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_473[] = {
    {"easeOut", "number", 1, &kParams_473[0]},
    {"spring", "number", 4, &kParams_473[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_474[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_474[] = {
    {"spring", "number", 4, &kParams_474[0]},
    {"shake", "number", 2, &kParams_474[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_475[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_475[] = {
    {"easeIn", "number", 1, &kParams_475[0]},
    {"easeOut", "number", 1, &kParams_475[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_476[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_476[] = {
    {"falloff", "number", 2, &kParams_476[0]},
    {"shake", "number", 2, &kParams_476[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_477[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_477[] = {
    {"easeIn", "number", 1, &kParams_477[0]},
    {"falloff", "number", 2, &kParams_477[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_478[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_478[] = {
    {"easeOut", "number", 1, &kParams_478[0]},
    {"spring", "number", 4, &kParams_478[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_479[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_479[] = {
    {"spring", "number", 4, &kParams_479[0]},
    {"shake", "number", 2, &kParams_479[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_480[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_480[] = {
    {"easeIn", "number", 1, &kParams_480[0]},
    {"easeOut", "number", 1, &kParams_480[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_481[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_481[] = {
    {"falloff", "number", 2, &kParams_481[0]},
    {"shake", "number", 2, &kParams_481[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_482[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_482[] = {
    {"easeIn", "number", 1, &kParams_482[0]},
    {"falloff", "number", 2, &kParams_482[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_483[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_483[] = {
    {"easeOut", "number", 1, &kParams_483[0]},
    {"spring", "number", 4, &kParams_483[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_484[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_484[] = {
    {"spring", "number", 4, &kParams_484[0]},
    {"shake", "number", 2, &kParams_484[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_485[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_485[] = {
    {"easeIn", "number", 1, &kParams_485[0]},
    {"easeOut", "number", 1, &kParams_485[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_486[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_486[] = {
    {"falloff", "number", 2, &kParams_486[0]},
    {"shake", "number", 2, &kParams_486[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_487[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_487[] = {
    {"easeIn", "number", 1, &kParams_487[0]},
    {"falloff", "number", 2, &kParams_487[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_488[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_488[] = {
    {"easeOut", "number", 1, &kParams_488[0]},
    {"spring", "number", 4, &kParams_488[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_489[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_489[] = {
    {"spring", "number", 4, &kParams_489[0]},
    {"shake", "number", 2, &kParams_489[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_490[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_490[] = {
    {"easeIn", "number", 1, &kParams_490[0]},
    {"easeOut", "number", 1, &kParams_490[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_491[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_491[] = {
    {"falloff", "number", 2, &kParams_491[0]},
    {"shake", "number", 2, &kParams_491[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_492[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_492[] = {
    {"easeIn", "number", 1, &kParams_492[0]},
    {"falloff", "number", 2, &kParams_492[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_493[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_493[] = {
    {"easeOut", "number", 1, &kParams_493[0]},
    {"spring", "number", 4, &kParams_493[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_494[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_494[] = {
    {"spring", "number", 4, &kParams_494[0]},
    {"shake", "number", 2, &kParams_494[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_495[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_495[] = {
    {"easeIn", "number", 1, &kParams_495[0]},
    {"easeOut", "number", 1, &kParams_495[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_496[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_496[] = {
    {"falloff", "number", 2, &kParams_496[0]},
    {"shake", "number", 2, &kParams_496[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_497[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_497[] = {
    {"easeIn", "number", 1, &kParams_497[0]},
    {"falloff", "number", 2, &kParams_497[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_498[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_498[] = {
    {"easeOut", "number", 1, &kParams_498[0]},
    {"spring", "number", 4, &kParams_498[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_499[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_499[] = {
    {"spring", "number", 4, &kParams_499[0]},
    {"shake", "number", 2, &kParams_499[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_500[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_500[] = {
    {"easeIn", "number", 1, &kParams_500[0]},
    {"easeOut", "number", 1, &kParams_500[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_501[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_501[] = {
    {"falloff", "number", 2, &kParams_501[0]},
    {"shake", "number", 2, &kParams_501[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_502[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_502[] = {
    {"easeIn", "number", 1, &kParams_502[0]},
    {"falloff", "number", 2, &kParams_502[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_503[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_503[] = {
    {"easeOut", "number", 1, &kParams_503[0]},
    {"spring", "number", 4, &kParams_503[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_504[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_504[] = {
    {"spring", "number", 4, &kParams_504[0]},
    {"shake", "number", 2, &kParams_504[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_505[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_505[] = {
    {"easeIn", "number", 1, &kParams_505[0]},
    {"easeOut", "number", 1, &kParams_505[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_506[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_506[] = {
    {"falloff", "number", 2, &kParams_506[0]},
    {"shake", "number", 2, &kParams_506[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_507[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_507[] = {
    {"easeIn", "number", 1, &kParams_507[0]},
    {"falloff", "number", 2, &kParams_507[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_508[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_508[] = {
    {"easeOut", "number", 1, &kParams_508[0]},
    {"spring", "number", 4, &kParams_508[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_509[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_509[] = {
    {"spring", "number", 4, &kParams_509[0]},
    {"shake", "number", 2, &kParams_509[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_510[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_510[] = {
    {"easeIn", "number", 1, &kParams_510[0]},
    {"easeOut", "number", 1, &kParams_510[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_511[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_511[] = {
    {"falloff", "number", 2, &kParams_511[0]},
    {"shake", "number", 2, &kParams_511[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_512[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_512[] = {
    {"easeIn", "number", 1, &kParams_512[0]},
    {"falloff", "number", 2, &kParams_512[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_513[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_513[] = {
    {"easeOut", "number", 1, &kParams_513[0]},
    {"spring", "number", 4, &kParams_513[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_514[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_514[] = {
    {"spring", "number", 4, &kParams_514[0]},
    {"shake", "number", 2, &kParams_514[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_515[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_515[] = {
    {"easeIn", "number", 1, &kParams_515[0]},
    {"easeOut", "number", 1, &kParams_515[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_516[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_516[] = {
    {"falloff", "number", 2, &kParams_516[0]},
    {"shake", "number", 2, &kParams_516[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_517[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_517[] = {
    {"easeIn", "number", 1, &kParams_517[0]},
    {"falloff", "number", 2, &kParams_517[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_518[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_518[] = {
    {"easeOut", "number", 1, &kParams_518[0]},
    {"spring", "number", 4, &kParams_518[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_519[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_519[] = {
    {"spring", "number", 4, &kParams_519[0]},
    {"shake", "number", 2, &kParams_519[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_520[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_520[] = {
    {"easeIn", "number", 1, &kParams_520[0]},
    {"easeOut", "number", 1, &kParams_520[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_521[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_521[] = {
    {"falloff", "number", 2, &kParams_521[0]},
    {"shake", "number", 2, &kParams_521[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_522[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_522[] = {
    {"easeIn", "number", 1, &kParams_522[0]},
    {"falloff", "number", 2, &kParams_522[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_523[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_523[] = {
    {"easeOut", "number", 1, &kParams_523[0]},
    {"spring", "number", 4, &kParams_523[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_524[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_524[] = {
    {"spring", "number", 4, &kParams_524[0]},
    {"shake", "number", 2, &kParams_524[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_525[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_525[] = {
    {"easeIn", "number", 1, &kParams_525[0]},
    {"easeOut", "number", 1, &kParams_525[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_526[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_526[] = {
    {"falloff", "number", 2, &kParams_526[0]},
    {"shake", "number", 2, &kParams_526[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_527[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_527[] = {
    {"easeIn", "number", 1, &kParams_527[0]},
    {"falloff", "number", 2, &kParams_527[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_528[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_528[] = {
    {"easeOut", "number", 1, &kParams_528[0]},
    {"spring", "number", 4, &kParams_528[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_529[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_529[] = {
    {"spring", "number", 4, &kParams_529[0]},
    {"shake", "number", 2, &kParams_529[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_530[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_530[] = {
    {"easeIn", "number", 1, &kParams_530[0]},
    {"easeOut", "number", 1, &kParams_530[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_531[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_531[] = {
    {"falloff", "number", 2, &kParams_531[0]},
    {"shake", "number", 2, &kParams_531[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_532[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_532[] = {
    {"easeIn", "number", 1, &kParams_532[0]},
    {"falloff", "number", 2, &kParams_532[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_533[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_533[] = {
    {"easeOut", "number", 1, &kParams_533[0]},
    {"spring", "number", 4, &kParams_533[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_534[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_534[] = {
    {"spring", "number", 4, &kParams_534[0]},
    {"shake", "number", 2, &kParams_534[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_535[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_535[] = {
    {"easeIn", "number", 1, &kParams_535[0]},
    {"easeOut", "number", 1, &kParams_535[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_536[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_536[] = {
    {"falloff", "number", 2, &kParams_536[0]},
    {"shake", "number", 2, &kParams_536[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_537[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_537[] = {
    {"easeIn", "number", 1, &kParams_537[0]},
    {"falloff", "number", 2, &kParams_537[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_538[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_538[] = {
    {"easeOut", "number", 1, &kParams_538[0]},
    {"spring", "number", 4, &kParams_538[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_539[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_539[] = {
    {"spring", "number", 4, &kParams_539[0]},
    {"shake", "number", 2, &kParams_539[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_540[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_540[] = {
    {"easeIn", "number", 1, &kParams_540[0]},
    {"easeOut", "number", 1, &kParams_540[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_541[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_541[] = {
    {"falloff", "number", 2, &kParams_541[0]},
    {"shake", "number", 2, &kParams_541[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_542[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_542[] = {
    {"easeIn", "number", 1, &kParams_542[0]},
    {"falloff", "number", 2, &kParams_542[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_543[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_543[] = {
    {"easeOut", "number", 1, &kParams_543[0]},
    {"spring", "number", 4, &kParams_543[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_544[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_544[] = {
    {"spring", "number", 4, &kParams_544[0]},
    {"shake", "number", 2, &kParams_544[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_545[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_545[] = {
    {"easeIn", "number", 1, &kParams_545[0]},
    {"easeOut", "number", 1, &kParams_545[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_546[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_546[] = {
    {"falloff", "number", 2, &kParams_546[0]},
    {"shake", "number", 2, &kParams_546[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_547[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_547[] = {
    {"easeIn", "number", 1, &kParams_547[0]},
    {"falloff", "number", 2, &kParams_547[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_548[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_548[] = {
    {"easeOut", "number", 1, &kParams_548[0]},
    {"spring", "number", 4, &kParams_548[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_549[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_549[] = {
    {"spring", "number", 4, &kParams_549[0]},
    {"shake", "number", 2, &kParams_549[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_550[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_550[] = {
    {"easeIn", "number", 1, &kParams_550[0]},
    {"easeOut", "number", 1, &kParams_550[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_551[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_551[] = {
    {"falloff", "number", 2, &kParams_551[0]},
    {"shake", "number", 2, &kParams_551[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_552[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_552[] = {
    {"easeIn", "number", 1, &kParams_552[0]},
    {"falloff", "number", 2, &kParams_552[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_553[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_553[] = {
    {"easeOut", "number", 1, &kParams_553[0]},
    {"spring", "number", 4, &kParams_553[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_554[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_554[] = {
    {"spring", "number", 4, &kParams_554[0]},
    {"shake", "number", 2, &kParams_554[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_555[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_555[] = {
    {"easeIn", "number", 1, &kParams_555[0]},
    {"easeOut", "number", 1, &kParams_555[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_556[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_556[] = {
    {"falloff", "number", 2, &kParams_556[0]},
    {"shake", "number", 2, &kParams_556[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_557[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_557[] = {
    {"easeIn", "number", 1, &kParams_557[0]},
    {"falloff", "number", 2, &kParams_557[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_558[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_558[] = {
    {"easeOut", "number", 1, &kParams_558[0]},
    {"spring", "number", 4, &kParams_558[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_559[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_559[] = {
    {"spring", "number", 4, &kParams_559[0]},
    {"shake", "number", 2, &kParams_559[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_560[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_560[] = {
    {"easeIn", "number", 1, &kParams_560[0]},
    {"easeOut", "number", 1, &kParams_560[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_561[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_561[] = {
    {"falloff", "number", 2, &kParams_561[0]},
    {"shake", "number", 2, &kParams_561[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_562[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_562[] = {
    {"easeIn", "number", 1, &kParams_562[0]},
    {"falloff", "number", 2, &kParams_562[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_563[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_563[] = {
    {"easeOut", "number", 1, &kParams_563[0]},
    {"spring", "number", 4, &kParams_563[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_564[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_564[] = {
    {"spring", "number", 4, &kParams_564[0]},
    {"shake", "number", 2, &kParams_564[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_565[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_565[] = {
    {"easeIn", "number", 1, &kParams_565[0]},
    {"easeOut", "number", 1, &kParams_565[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_566[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_566[] = {
    {"falloff", "number", 2, &kParams_566[0]},
    {"shake", "number", 2, &kParams_566[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_567[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_567[] = {
    {"easeIn", "number", 1, &kParams_567[0]},
    {"falloff", "number", 2, &kParams_567[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_568[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_568[] = {
    {"easeOut", "number", 1, &kParams_568[0]},
    {"spring", "number", 4, &kParams_568[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_569[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_569[] = {
    {"spring", "number", 4, &kParams_569[0]},
    {"shake", "number", 2, &kParams_569[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_570[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_570[] = {
    {"easeIn", "number", 1, &kParams_570[0]},
    {"easeOut", "number", 1, &kParams_570[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_571[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_571[] = {
    {"falloff", "number", 2, &kParams_571[0]},
    {"shake", "number", 2, &kParams_571[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_572[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_572[] = {
    {"easeIn", "number", 1, &kParams_572[0]},
    {"falloff", "number", 2, &kParams_572[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_573[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_573[] = {
    {"easeOut", "number", 1, &kParams_573[0]},
    {"spring", "number", 4, &kParams_573[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_574[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_574[] = {
    {"spring", "number", 4, &kParams_574[0]},
    {"shake", "number", 2, &kParams_574[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_575[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_575[] = {
    {"easeIn", "number", 1, &kParams_575[0]},
    {"easeOut", "number", 1, &kParams_575[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_576[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_576[] = {
    {"falloff", "number", 2, &kParams_576[0]},
    {"shake", "number", 2, &kParams_576[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_577[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_577[] = {
    {"easeIn", "number", 1, &kParams_577[0]},
    {"falloff", "number", 2, &kParams_577[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_578[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_578[] = {
    {"easeOut", "number", 1, &kParams_578[0]},
    {"spring", "number", 4, &kParams_578[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_579[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_579[] = {
    {"spring", "number", 4, &kParams_579[0]},
    {"shake", "number", 2, &kParams_579[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_580[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_580[] = {
    {"easeIn", "number", 1, &kParams_580[0]},
    {"easeOut", "number", 1, &kParams_580[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_581[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_581[] = {
    {"falloff", "number", 2, &kParams_581[0]},
    {"shake", "number", 2, &kParams_581[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_582[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_582[] = {
    {"easeIn", "number", 1, &kParams_582[0]},
    {"falloff", "number", 2, &kParams_582[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_583[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_583[] = {
    {"easeOut", "number", 1, &kParams_583[0]},
    {"spring", "number", 4, &kParams_583[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_584[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_584[] = {
    {"spring", "number", 4, &kParams_584[0]},
    {"shake", "number", 2, &kParams_584[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_585[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_585[] = {
    {"easeIn", "number", 1, &kParams_585[0]},
    {"easeOut", "number", 1, &kParams_585[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_586[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_586[] = {
    {"falloff", "number", 2, &kParams_586[0]},
    {"shake", "number", 2, &kParams_586[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_587[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_587[] = {
    {"easeIn", "number", 1, &kParams_587[0]},
    {"falloff", "number", 2, &kParams_587[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_588[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_588[] = {
    {"easeOut", "number", 1, &kParams_588[0]},
    {"spring", "number", 4, &kParams_588[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_589[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_589[] = {
    {"spring", "number", 4, &kParams_589[0]},
    {"shake", "number", 2, &kParams_589[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_590[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_590[] = {
    {"easeIn", "number", 1, &kParams_590[0]},
    {"easeOut", "number", 1, &kParams_590[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_591[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_591[] = {
    {"falloff", "number", 2, &kParams_591[0]},
    {"shake", "number", 2, &kParams_591[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_592[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_592[] = {
    {"easeIn", "number", 1, &kParams_592[0]},
    {"falloff", "number", 2, &kParams_592[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_593[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_593[] = {
    {"easeOut", "number", 1, &kParams_593[0]},
    {"spring", "number", 4, &kParams_593[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_594[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_594[] = {
    {"spring", "number", 4, &kParams_594[0]},
    {"shake", "number", 2, &kParams_594[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_595[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_595[] = {
    {"easeIn", "number", 1, &kParams_595[0]},
    {"easeOut", "number", 1, &kParams_595[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_596[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_596[] = {
    {"falloff", "number", 2, &kParams_596[0]},
    {"shake", "number", 2, &kParams_596[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_597[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_597[] = {
    {"easeIn", "number", 1, &kParams_597[0]},
    {"falloff", "number", 2, &kParams_597[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_598[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_598[] = {
    {"easeOut", "number", 1, &kParams_598[0]},
    {"spring", "number", 4, &kParams_598[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_599[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_599[] = {
    {"spring", "number", 4, &kParams_599[0]},
    {"shake", "number", 2, &kParams_599[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_600[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_600[] = {
    {"easeIn", "number", 1, &kParams_600[0]},
    {"easeOut", "number", 1, &kParams_600[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_601[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_601[] = {
    {"falloff", "number", 2, &kParams_601[0]},
    {"shake", "number", 2, &kParams_601[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_602[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_602[] = {
    {"easeIn", "number", 1, &kParams_602[0]},
    {"falloff", "number", 2, &kParams_602[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_603[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_603[] = {
    {"easeOut", "number", 1, &kParams_603[0]},
    {"spring", "number", 4, &kParams_603[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_604[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_604[] = {
    {"spring", "number", 4, &kParams_604[0]},
    {"shake", "number", 2, &kParams_604[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_605[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_605[] = {
    {"easeIn", "number", 1, &kParams_605[0]},
    {"easeOut", "number", 1, &kParams_605[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_606[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_606[] = {
    {"falloff", "number", 2, &kParams_606[0]},
    {"shake", "number", 2, &kParams_606[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_607[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_607[] = {
    {"easeIn", "number", 1, &kParams_607[0]},
    {"falloff", "number", 2, &kParams_607[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_608[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_608[] = {
    {"easeOut", "number", 1, &kParams_608[0]},
    {"spring", "number", 4, &kParams_608[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_609[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_609[] = {
    {"spring", "number", 4, &kParams_609[0]},
    {"shake", "number", 2, &kParams_609[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_610[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_610[] = {
    {"easeIn", "number", 1, &kParams_610[0]},
    {"easeOut", "number", 1, &kParams_610[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_611[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_611[] = {
    {"falloff", "number", 2, &kParams_611[0]},
    {"shake", "number", 2, &kParams_611[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_612[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_612[] = {
    {"easeIn", "number", 1, &kParams_612[0]},
    {"falloff", "number", 2, &kParams_612[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_613[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_613[] = {
    {"easeOut", "number", 1, &kParams_613[0]},
    {"spring", "number", 4, &kParams_613[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_614[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_614[] = {
    {"spring", "number", 4, &kParams_614[0]},
    {"shake", "number", 2, &kParams_614[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_615[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_615[] = {
    {"easeIn", "number", 1, &kParams_615[0]},
    {"easeOut", "number", 1, &kParams_615[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_616[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_616[] = {
    {"falloff", "number", 2, &kParams_616[0]},
    {"shake", "number", 2, &kParams_616[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_617[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_617[] = {
    {"easeIn", "number", 1, &kParams_617[0]},
    {"falloff", "number", 2, &kParams_617[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_618[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_618[] = {
    {"easeOut", "number", 1, &kParams_618[0]},
    {"spring", "number", 4, &kParams_618[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_619[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_619[] = {
    {"spring", "number", 4, &kParams_619[0]},
    {"shake", "number", 2, &kParams_619[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_620[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_620[] = {
    {"easeIn", "number", 1, &kParams_620[0]},
    {"easeOut", "number", 1, &kParams_620[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_621[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_621[] = {
    {"falloff", "number", 2, &kParams_621[0]},
    {"shake", "number", 2, &kParams_621[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_622[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_622[] = {
    {"easeIn", "number", 1, &kParams_622[0]},
    {"falloff", "number", 2, &kParams_622[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_623[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_623[] = {
    {"easeOut", "number", 1, &kParams_623[0]},
    {"spring", "number", 4, &kParams_623[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_624[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_624[] = {
    {"spring", "number", 4, &kParams_624[0]},
    {"shake", "number", 2, &kParams_624[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_625[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_625[] = {
    {"easeIn", "number", 1, &kParams_625[0]},
    {"easeOut", "number", 1, &kParams_625[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_626[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_626[] = {
    {"falloff", "number", 2, &kParams_626[0]},
    {"shake", "number", 2, &kParams_626[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_627[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_627[] = {
    {"easeIn", "number", 1, &kParams_627[0]},
    {"falloff", "number", 2, &kParams_627[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_628[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_628[] = {
    {"easeOut", "number", 1, &kParams_628[0]},
    {"spring", "number", 4, &kParams_628[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_629[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_629[] = {
    {"spring", "number", 4, &kParams_629[0]},
    {"shake", "number", 2, &kParams_629[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_630[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_630[] = {
    {"easeIn", "number", 1, &kParams_630[0]},
    {"easeOut", "number", 1, &kParams_630[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_631[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_631[] = {
    {"falloff", "number", 2, &kParams_631[0]},
    {"shake", "number", 2, &kParams_631[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_632[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_632[] = {
    {"easeIn", "number", 1, &kParams_632[0]},
    {"falloff", "number", 2, &kParams_632[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_633[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_633[] = {
    {"easeOut", "number", 1, &kParams_633[0]},
    {"spring", "number", 4, &kParams_633[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_634[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_634[] = {
    {"spring", "number", 4, &kParams_634[0]},
    {"shake", "number", 2, &kParams_634[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_635[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_635[] = {
    {"easeIn", "number", 1, &kParams_635[0]},
    {"easeOut", "number", 1, &kParams_635[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_636[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_636[] = {
    {"falloff", "number", 2, &kParams_636[0]},
    {"shake", "number", 2, &kParams_636[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_637[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_637[] = {
    {"easeIn", "number", 1, &kParams_637[0]},
    {"falloff", "number", 2, &kParams_637[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_638[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_638[] = {
    {"easeOut", "number", 1, &kParams_638[0]},
    {"spring", "number", 4, &kParams_638[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_639[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_639[] = {
    {"spring", "number", 4, &kParams_639[0]},
    {"shake", "number", 2, &kParams_639[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_640[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_640[] = {
    {"easeIn", "number", 1, &kParams_640[0]},
    {"easeOut", "number", 1, &kParams_640[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_641[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_641[] = {
    {"falloff", "number", 2, &kParams_641[0]},
    {"shake", "number", 2, &kParams_641[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_642[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_642[] = {
    {"easeIn", "number", 1, &kParams_642[0]},
    {"falloff", "number", 2, &kParams_642[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_643[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_643[] = {
    {"easeOut", "number", 1, &kParams_643[0]},
    {"spring", "number", 4, &kParams_643[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_644[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_644[] = {
    {"spring", "number", 4, &kParams_644[0]},
    {"shake", "number", 2, &kParams_644[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_645[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_645[] = {
    {"easeIn", "number", 1, &kParams_645[0]},
    {"easeOut", "number", 1, &kParams_645[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_646[] = {
    {"dist", "number"},
    {"radius", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_646[] = {
    {"falloff", "number", 2, &kParams_646[0]},
    {"shake", "number", 2, &kParams_646[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_647[] = {
    {"t", "number"},
    {"dist", "number"},
    {"radius", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_647[] = {
    {"easeIn", "number", 1, &kParams_647[0]},
    {"falloff", "number", 2, &kParams_647[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_648[] = {
    {"t", "number"},
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_648[] = {
    {"easeOut", "number", 1, &kParams_648[0]},
    {"spring", "number", 4, &kParams_648[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_649[] = {
    {"x", "number"},
    {"v", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"time", "number"},
    {"amp", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_649[] = {
    {"spring", "number", 4, &kParams_649[0]},
    {"shake", "number", 2, &kParams_649[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_650[] = {
    {"t", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_650[] = {
    {"easeIn", "number", 1, &kParams_650[0]},
    {"easeOut", "number", 1, &kParams_650[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibModuleSpec kSimpleModules[] = {
    {"absnum", "absnum", kFuncs_0, 2, "simple/absnum.hpp", false},
    {"sqrtlib", "sqrtlib", kFuncs_1, 2, "simple/sqrtlib.hpp", false},
    {"cbrtlib", "cbrtlib", kFuncs_2, 2, "simple/cbrtlib.hpp", false},
    {"min2", "min2", kFuncs_3, 2, "simple/min2.hpp", false},
    {"max2", "max2", kFuncs_4, 2, "simple/max2.hpp", false},
    {"clamp", "clamp", kFuncs_5, 2, "simple/clamp.hpp", false},
    {"lerp", "lerp", kFuncs_6, 2, "simple/lerp.hpp", false},
    {"sign", "sign", kFuncs_7, 2, "simple/sign.hpp", false},
    {"parity", "parity", kFuncs_8, 2, "simple/parity.hpp", false},
    {"trig", "trig", kFuncs_9, 2, "simple/trig.hpp", false},
    {"trig2", "trig2", kFuncs_10, 2, "simple/trig2.hpp", false},
    {"arc", "arc", kFuncs_11, 2, "simple/arc.hpp", false},
    {"hyper", "hyper", kFuncs_12, 2, "simple/hyper.hpp", false},
    {"deg", "deg", kFuncs_13, 2, "simple/deg.hpp", false},
    {"roundlib", "roundlib", kFuncs_14, 2, "simple/roundlib.hpp", false},
    {"modlib", "modlib", kFuncs_15, 2, "simple/modlib.hpp", false},
    {"gcdlib", "gcdlib", kFuncs_16, 2, "simple/gcdlib.hpp", false},
    {"fact", "fact", kFuncs_17, 2, "simple/fact.hpp", false},
    {"fib", "fib", kFuncs_18, 2, "simple/fib.hpp", false},
    {"prime", "prime", kFuncs_19, 2, "simple/prime.hpp", false},
    {"mean", "mean", kFuncs_20, 2, "simple/mean.hpp", false},
    {"percent", "percent", kFuncs_21, 2, "simple/percent.hpp", false},
    {"ratio", "ratio", kFuncs_22, 2, "simple/ratio.hpp", false},
    {"dice", "dice", kFuncs_23, 2, "simple/dice.hpp", false},
    {"coin", "coin", kFuncs_24, 2, "simple/coin.hpp", false},
    {"upper", "upper", kFuncs_25, 2, "simple/upper.hpp", false},
    {"capitalize", "capitalize", kFuncs_26, 2, "simple/capitalize.hpp", false},
    {"prefix", "prefix", kFuncs_27, 2, "simple/prefix.hpp", false},
    {"repeat", "repeat", kFuncs_28, 2, "simple/repeat.hpp", false},
    {"pad", "pad", kFuncs_29, 2, "simple/pad.hpp", false},
    {"reverse", "reverse", kFuncs_30, 2, "simple/reverse.hpp", false},
    {"textlen", "textlen", kFuncs_31, 2, "simple/textlen.hpp", false},
    {"concat", "concat", kFuncs_32, 2, "simple/concat.hpp", false},
    {"compare", "compare", kFuncs_33, 2, "simple/compare.hpp", false},
    {"celsius", "celsius", kFuncs_34, 2, "simple/celsius.hpp", false},
    {"kelvin", "kelvin", kFuncs_35, 2, "simple/kelvin.hpp", false},
    {"distance", "distance", kFuncs_36, 2, "simple/distance.hpp", false},
    {"weight", "weight", kFuncs_37, 2, "simple/weight.hpp", false},
    {"bytes", "bytes", kFuncs_38, 2, "simple/bytes.hpp", false},
    {"timeconv", "timeconv", kFuncs_39, 2, "simple/timeconv.hpp", false},
    {"msconv", "msconv", kFuncs_40, 2, "simple/msconv.hpp", false},
    {"angle", "angle", kFuncs_41, 2, "simple/angle.hpp", false},
    {"hex", "hex", kFuncs_42, 2, "simple/hex.hpp", false},
    {"binary", "binary", kFuncs_43, 2, "simple/binary.hpp", false},
    {"octal", "octal", kFuncs_44, 2, "simple/octal.hpp", false},
    {"rot13", "rot13", kFuncs_45, 2, "simple/rot13.hpp", false},
    {"hash", "hash", kFuncs_46, 2, "simple/hash.hpp", false},
    {"checksum", "checksum", kFuncs_47, 2, "simple/checksum.hpp", false},
    {"slug", "slug", kFuncs_48, 2, "simple/slug.hpp", false},
    {"email", "email", kFuncs_49, 2, "simple/email.hpp", false},
    {"phone", "phone", kFuncs_50, 2, "simple/phone.hpp", false},
    {"ipv4", "ipv4", kFuncs_51, 2, "simple/ipv4.hpp", false},
    {"html", "html", kFuncs_52, 2, "simple/html.hpp", false},
    {"point", "point", kFuncs_53, 2, "simple/point.hpp", false},
    {"rect", "rect", kFuncs_54, 2, "simple/rect.hpp", false},
    {"circle", "circle", kFuncs_55, 2, "simple/circle.hpp", false},
    {"triangle", "triangle", kFuncs_56, 2, "simple/triangle.hpp", false},
    {"vector2", "vector2", kFuncs_57, 2, "simple/vector2.hpp", false},
    {"collision", "collision", kFuncs_58, 2, "simple/collision.hpp", false},
    {"color", "color", kFuncs_59, 2, "simple/color.hpp", false},
    {"easing", "easing", kFuncs_60, 2, "simple/easing.hpp", false},
    {"noise", "noise", kFuncs_61, 2, "simple/noise.hpp", false},
    {"semver", "semver", kFuncs_62, 2, "simple/semver.hpp", false},
    {"validate", "validate", kFuncs_63, 2, "simple/validate.hpp", false},
    {"parse", "parse", kFuncs_64, 2, "simple/parse.hpp", false},
    {"format", "format", kFuncs_65, 2, "simple/format.hpp", false},
    {"currency", "currency", kFuncs_66, 2, "simple/currency.hpp", false},
    {"stopwatch", "stopwatch", kFuncs_67, 2, "simple/stopwatch.hpp", false},
    {"bits", "bits", kFuncs_68, 2, "simple/bits.hpp", false},
    {"shift", "shift", kFuncs_69, 2, "simple/shift.hpp", false},
    {"flags", "flags", kFuncs_70, 2, "simple/flags.hpp", false},
    {"order", "order", kFuncs_71, 2, "simple/order.hpp", false},
    {"range", "range", kFuncs_72, 2, "simple/range.hpp", false},
    {"seq", "seq", kFuncs_73, 2, "simple/seq.hpp", false},
    {"loglib", "loglib", kFuncs_74, 2, "simple/loglib.hpp", false},
    {"powlib", "powlib", kFuncs_75, 2, "simple/powlib.hpp", false},
    {"hypot", "hypot", kFuncs_76, 2, "simple/hypot.hpp", false},
    {"stats2", "stats2", kFuncs_77, 2, "simple/stats2.hpp", false},
    {"stats3", "stats3", kFuncs_78, 2, "simple/stats3.hpp", false},
    {"diff", "diff", kFuncs_79, 2, "simple/diff.hpp", false},
    {"avg", "avg", kFuncs_80, 2, "simple/avg.hpp", false},
    {"margin", "margin", kFuncs_81, 2, "simple/margin.hpp", false},
    {"tax", "tax", kFuncs_82, 2, "simple/tax.hpp", false},
    {"discount", "discount", kFuncs_83, 2, "simple/discount.hpp", false},
    {"interest", "interest", kFuncs_84, 2, "simple/interest.hpp", false},
    {"loan", "loan", kFuncs_85, 2, "simple/loan.hpp", false},
    {"speed", "speed", kFuncs_86, 2, "simple/speed.hpp", false},
    {"volume", "volume", kFuncs_87, 2, "simple/volume.hpp", false},
    {"area_conv", "area_conv", kFuncs_88, 2, "simple/area_conv.hpp", false},
    {"pressure", "pressure", kFuncs_89, 2, "simple/pressure.hpp", false},
    {"energy", "energy", kFuncs_90, 2, "simple/energy.hpp", false},
    {"bmi", "bmi", kFuncs_91, 2, "simple/bmi.hpp", false},
    {"geo", "geo", kFuncs_92, 2, "simple/geo.hpp", false},
    {"compass", "compass", kFuncs_93, 2, "simple/compass.hpp", false},
    {"uuid", "uuid", kFuncs_94, 2, "simple/uuid.hpp", false},
    {"counter", "counter", kFuncs_95, 2, "simple/counter.hpp", false},
    {"env", "env", kFuncs_96, 2, "simple/env.hpp", false},
    {"platform", "platform", kFuncs_97, 2, "simple/platform.hpp", false},
    {"pathutil", "pathutil", kFuncs_98, 2, "simple/pathutil.hpp", false},
    {"url", "url", kFuncs_99, 2, "simple/url.hpp", false},
    {"csv", "csv", kFuncs_100, 2, "simple/csv.hpp", false},
    {"jsonlite", "jsonlite", kFuncs_101, 2, "simple/jsonlite.hpp", false},
    {"xml", "xml", kFuncs_102, 2, "simple/xml.hpp", false},
    {"markdown", "markdown", kFuncs_103, 2, "simple/markdown.hpp", false},
    {"password", "password", kFuncs_104, 2, "simple/password.hpp", false},
    {"base64", "base64", kFuncs_105, 2, "simple/base64.hpp", false},
    {"mime", "mime", kFuncs_106, 2, "simple/mime.hpp", false},
    {"httpcode", "httpcode", kFuncs_107, 2, "simple/httpcode.hpp", false},
    {"game", "game", kFuncs_108, 2, "simple/game.hpp", false},
    {"music", "music", kFuncs_109, 2, "simple/music.hpp", false},
    {"color2", "color2", kFuncs_110, 2, "simple/color2.hpp", false},
    {"matrix2", "matrix2", kFuncs_111, 2, "simple/matrix2.hpp", false},
    {"physics", "physics", kFuncs_112, 2, "simple/physics.hpp", false},
    {"chemistry", "chemistry", kFuncs_113, 2, "simple/chemistry.hpp", false},
    {"units", "units", kFuncs_114, 2, "simple/units.hpp", false},
    {"paper", "paper", kFuncs_115, 2, "simple/paper.hpp", false},
    {"roman", "roman", kFuncs_116, 2, "simple/roman.hpp", false},
    {"spell", "spell", kFuncs_117, 2, "simple/spell.hpp", false},
    {"listutil", "listutil", kFuncs_118, 2, "simple/listutil.hpp", false},
    {"queue", "queue", kFuncs_119, 2, "simple/queue.hpp", false},
    {"stackutil", "stackutil", kFuncs_120, 2, "simple/stackutil.hpp", false},
    {"graph", "graph", kFuncs_121, 2, "simple/graph.hpp", false},
    {"search", "search", kFuncs_122, 2, "simple/search.hpp", false},
    {"sortkey", "sortkey", kFuncs_123, 2, "simple/sortkey.hpp", false},
    {"textwrap", "textwrap", kFuncs_124, 2, "simple/textwrap.hpp", false},
    {"whitespace", "whitespace", kFuncs_125, 2, "simple/whitespace.hpp", false},
    {"charutil", "charutil", kFuncs_126, 2, "simple/charutil.hpp", false},
    {"version", "version", kFuncs_127, 2, "simple/version.hpp", false},
    {"config", "config", kFuncs_128, 2, "simple/config.hpp", false},
    {"retry", "retry", kFuncs_129, 2, "simple/retry.hpp", false},
    {"ratelimit", "ratelimit", kFuncs_130, 2, "simple/ratelimit.hpp", false},
    {"cache", "cache", kFuncs_131, 2, "simple/cache.hpp", false},
    {"id", "id", kFuncs_132, 2, "simple/id.hpp", false},
    {"locale", "locale", kFuncs_133, 2, "simple/locale.hpp", false},
    {"calendar", "calendar", kFuncs_134, 2, "simple/calendar.hpp", false},
    {"weekday", "weekday", kFuncs_135, 2, "simple/weekday.hpp", false},
    {"timezone", "timezone", kFuncs_136, 2, "simple/timezone.hpp", false},
    {"network", "network", kFuncs_137, 2, "simple/network.hpp", false},
    {"dns", "dns", kFuncs_138, 2, "simple/dns.hpp", false},
    {"socket", "socket", kFuncs_139, 2, "simple/socket.hpp", false},
    {"process", "process", kFuncs_140, 2, "simple/process.hpp", false},
    {"shell", "shell", kFuncs_141, 2, "simple/shell.hpp", false},
    {"memory", "memory", kFuncs_142, 2, "simple/memory.hpp", false},
    {"cpu", "cpu", kFuncs_143, 2, "simple/cpu.hpp", false},
    {"disk", "disk", kFuncs_144, 2, "simple/disk.hpp", false},
    {"security", "security", kFuncs_145, 2, "simple/security.hpp", false},
    {"audit", "audit", kFuncs_146, 2, "simple/audit.hpp", false},
    {"tmpl", "tmpl", kFuncs_147, 2, "simple/tmpl.hpp", false},
    {"i18n", "i18n", kFuncs_148, 2, "simple/i18n.hpp", false},
    {"education", "education", kFuncs_149, 2, "simple/education.hpp", false},
    {"quiz", "quiz", kFuncs_150, 2, "simple/quiz.hpp", false},
    {"gamekit001", "gamekit001", kFuncs_151, 2, "simple/gamekit001.hpp", false},
    {"gamekit002", "gamekit002", kFuncs_152, 2, "simple/gamekit002.hpp", false},
    {"gamekit003", "gamekit003", kFuncs_153, 2, "simple/gamekit003.hpp", false},
    {"gamekit004", "gamekit004", kFuncs_154, 2, "simple/gamekit004.hpp", false},
    {"gamekit005", "gamekit005", kFuncs_155, 2, "simple/gamekit005.hpp", false},
    {"gamekit006", "gamekit006", kFuncs_156, 2, "simple/gamekit006.hpp", false},
    {"gamekit007", "gamekit007", kFuncs_157, 2, "simple/gamekit007.hpp", false},
    {"gamekit008", "gamekit008", kFuncs_158, 2, "simple/gamekit008.hpp", false},
    {"gamekit009", "gamekit009", kFuncs_159, 2, "simple/gamekit009.hpp", false},
    {"gamekit010", "gamekit010", kFuncs_160, 2, "simple/gamekit010.hpp", false},
    {"gamekit011", "gamekit011", kFuncs_161, 2, "simple/gamekit011.hpp", false},
    {"gamekit012", "gamekit012", kFuncs_162, 2, "simple/gamekit012.hpp", false},
    {"gamekit013", "gamekit013", kFuncs_163, 2, "simple/gamekit013.hpp", false},
    {"gamekit014", "gamekit014", kFuncs_164, 2, "simple/gamekit014.hpp", false},
    {"gamekit015", "gamekit015", kFuncs_165, 2, "simple/gamekit015.hpp", false},
    {"gamekit016", "gamekit016", kFuncs_166, 2, "simple/gamekit016.hpp", false},
    {"gamekit017", "gamekit017", kFuncs_167, 2, "simple/gamekit017.hpp", false},
    {"gamekit018", "gamekit018", kFuncs_168, 2, "simple/gamekit018.hpp", false},
    {"gamekit019", "gamekit019", kFuncs_169, 2, "simple/gamekit019.hpp", false},
    {"gamekit020", "gamekit020", kFuncs_170, 2, "simple/gamekit020.hpp", false},
    {"gamekit021", "gamekit021", kFuncs_171, 2, "simple/gamekit021.hpp", false},
    {"gamekit022", "gamekit022", kFuncs_172, 2, "simple/gamekit022.hpp", false},
    {"gamekit023", "gamekit023", kFuncs_173, 2, "simple/gamekit023.hpp", false},
    {"gamekit024", "gamekit024", kFuncs_174, 2, "simple/gamekit024.hpp", false},
    {"gamekit025", "gamekit025", kFuncs_175, 2, "simple/gamekit025.hpp", false},
    {"gamekit026", "gamekit026", kFuncs_176, 2, "simple/gamekit026.hpp", false},
    {"gamekit027", "gamekit027", kFuncs_177, 2, "simple/gamekit027.hpp", false},
    {"gamekit028", "gamekit028", kFuncs_178, 2, "simple/gamekit028.hpp", false},
    {"gamekit029", "gamekit029", kFuncs_179, 2, "simple/gamekit029.hpp", false},
    {"gamekit030", "gamekit030", kFuncs_180, 2, "simple/gamekit030.hpp", false},
    {"gamekit031", "gamekit031", kFuncs_181, 2, "simple/gamekit031.hpp", false},
    {"gamekit032", "gamekit032", kFuncs_182, 2, "simple/gamekit032.hpp", false},
    {"gamekit033", "gamekit033", kFuncs_183, 2, "simple/gamekit033.hpp", false},
    {"gamekit034", "gamekit034", kFuncs_184, 2, "simple/gamekit034.hpp", false},
    {"gamekit035", "gamekit035", kFuncs_185, 2, "simple/gamekit035.hpp", false},
    {"gamekit036", "gamekit036", kFuncs_186, 2, "simple/gamekit036.hpp", false},
    {"gamekit037", "gamekit037", kFuncs_187, 2, "simple/gamekit037.hpp", false},
    {"gamekit038", "gamekit038", kFuncs_188, 2, "simple/gamekit038.hpp", false},
    {"gamekit039", "gamekit039", kFuncs_189, 2, "simple/gamekit039.hpp", false},
    {"gamekit040", "gamekit040", kFuncs_190, 2, "simple/gamekit040.hpp", false},
    {"gamekit041", "gamekit041", kFuncs_191, 2, "simple/gamekit041.hpp", false},
    {"gamekit042", "gamekit042", kFuncs_192, 2, "simple/gamekit042.hpp", false},
    {"gamekit043", "gamekit043", kFuncs_193, 2, "simple/gamekit043.hpp", false},
    {"gamekit044", "gamekit044", kFuncs_194, 2, "simple/gamekit044.hpp", false},
    {"gamekit045", "gamekit045", kFuncs_195, 2, "simple/gamekit045.hpp", false},
    {"gamekit046", "gamekit046", kFuncs_196, 2, "simple/gamekit046.hpp", false},
    {"gamekit047", "gamekit047", kFuncs_197, 2, "simple/gamekit047.hpp", false},
    {"gamekit048", "gamekit048", kFuncs_198, 2, "simple/gamekit048.hpp", false},
    {"gamekit049", "gamekit049", kFuncs_199, 2, "simple/gamekit049.hpp", false},
    {"gamekit050", "gamekit050", kFuncs_200, 2, "simple/gamekit050.hpp", false},
    {"gamekit051", "gamekit051", kFuncs_201, 2, "simple/gamekit051.hpp", false},
    {"gamekit052", "gamekit052", kFuncs_202, 2, "simple/gamekit052.hpp", false},
    {"gamekit053", "gamekit053", kFuncs_203, 2, "simple/gamekit053.hpp", false},
    {"gamekit054", "gamekit054", kFuncs_204, 2, "simple/gamekit054.hpp", false},
    {"gamekit055", "gamekit055", kFuncs_205, 2, "simple/gamekit055.hpp", false},
    {"gamekit056", "gamekit056", kFuncs_206, 2, "simple/gamekit056.hpp", false},
    {"gamekit057", "gamekit057", kFuncs_207, 2, "simple/gamekit057.hpp", false},
    {"gamekit058", "gamekit058", kFuncs_208, 2, "simple/gamekit058.hpp", false},
    {"gamekit059", "gamekit059", kFuncs_209, 2, "simple/gamekit059.hpp", false},
    {"gamekit060", "gamekit060", kFuncs_210, 2, "simple/gamekit060.hpp", false},
    {"gamekit061", "gamekit061", kFuncs_211, 2, "simple/gamekit061.hpp", false},
    {"gamekit062", "gamekit062", kFuncs_212, 2, "simple/gamekit062.hpp", false},
    {"gamekit063", "gamekit063", kFuncs_213, 2, "simple/gamekit063.hpp", false},
    {"gamekit064", "gamekit064", kFuncs_214, 2, "simple/gamekit064.hpp", false},
    {"gamekit065", "gamekit065", kFuncs_215, 2, "simple/gamekit065.hpp", false},
    {"gamekit066", "gamekit066", kFuncs_216, 2, "simple/gamekit066.hpp", false},
    {"gamekit067", "gamekit067", kFuncs_217, 2, "simple/gamekit067.hpp", false},
    {"gamekit068", "gamekit068", kFuncs_218, 2, "simple/gamekit068.hpp", false},
    {"gamekit069", "gamekit069", kFuncs_219, 2, "simple/gamekit069.hpp", false},
    {"gamekit070", "gamekit070", kFuncs_220, 2, "simple/gamekit070.hpp", false},
    {"gamekit071", "gamekit071", kFuncs_221, 2, "simple/gamekit071.hpp", false},
    {"gamekit072", "gamekit072", kFuncs_222, 2, "simple/gamekit072.hpp", false},
    {"gamekit073", "gamekit073", kFuncs_223, 2, "simple/gamekit073.hpp", false},
    {"gamekit074", "gamekit074", kFuncs_224, 2, "simple/gamekit074.hpp", false},
    {"gamekit075", "gamekit075", kFuncs_225, 2, "simple/gamekit075.hpp", false},
    {"gamekit076", "gamekit076", kFuncs_226, 2, "simple/gamekit076.hpp", false},
    {"gamekit077", "gamekit077", kFuncs_227, 2, "simple/gamekit077.hpp", false},
    {"gamekit078", "gamekit078", kFuncs_228, 2, "simple/gamekit078.hpp", false},
    {"gamekit079", "gamekit079", kFuncs_229, 2, "simple/gamekit079.hpp", false},
    {"gamekit080", "gamekit080", kFuncs_230, 2, "simple/gamekit080.hpp", false},
    {"gamekit081", "gamekit081", kFuncs_231, 2, "simple/gamekit081.hpp", false},
    {"gamekit082", "gamekit082", kFuncs_232, 2, "simple/gamekit082.hpp", false},
    {"gamekit083", "gamekit083", kFuncs_233, 2, "simple/gamekit083.hpp", false},
    {"gamekit084", "gamekit084", kFuncs_234, 2, "simple/gamekit084.hpp", false},
    {"gamekit085", "gamekit085", kFuncs_235, 2, "simple/gamekit085.hpp", false},
    {"gamekit086", "gamekit086", kFuncs_236, 2, "simple/gamekit086.hpp", false},
    {"gamekit087", "gamekit087", kFuncs_237, 2, "simple/gamekit087.hpp", false},
    {"gamekit088", "gamekit088", kFuncs_238, 2, "simple/gamekit088.hpp", false},
    {"gamekit089", "gamekit089", kFuncs_239, 2, "simple/gamekit089.hpp", false},
    {"gamekit090", "gamekit090", kFuncs_240, 2, "simple/gamekit090.hpp", false},
    {"gamekit091", "gamekit091", kFuncs_241, 2, "simple/gamekit091.hpp", false},
    {"gamekit092", "gamekit092", kFuncs_242, 2, "simple/gamekit092.hpp", false},
    {"gamekit093", "gamekit093", kFuncs_243, 2, "simple/gamekit093.hpp", false},
    {"gamekit094", "gamekit094", kFuncs_244, 2, "simple/gamekit094.hpp", false},
    {"gamekit095", "gamekit095", kFuncs_245, 2, "simple/gamekit095.hpp", false},
    {"gamekit096", "gamekit096", kFuncs_246, 2, "simple/gamekit096.hpp", false},
    {"gamekit097", "gamekit097", kFuncs_247, 2, "simple/gamekit097.hpp", false},
    {"gamekit098", "gamekit098", kFuncs_248, 2, "simple/gamekit098.hpp", false},
    {"gamekit099", "gamekit099", kFuncs_249, 2, "simple/gamekit099.hpp", false},
    {"gamekit100", "gamekit100", kFuncs_250, 2, "simple/gamekit100.hpp", false},
    {"gamekit101", "gamekit101", kFuncs_251, 2, "simple/gamekit101.hpp", false},
    {"gamekit102", "gamekit102", kFuncs_252, 2, "simple/gamekit102.hpp", false},
    {"gamekit103", "gamekit103", kFuncs_253, 2, "simple/gamekit103.hpp", false},
    {"gamekit104", "gamekit104", kFuncs_254, 2, "simple/gamekit104.hpp", false},
    {"gamekit105", "gamekit105", kFuncs_255, 2, "simple/gamekit105.hpp", false},
    {"gamekit106", "gamekit106", kFuncs_256, 2, "simple/gamekit106.hpp", false},
    {"gamekit107", "gamekit107", kFuncs_257, 2, "simple/gamekit107.hpp", false},
    {"gamekit108", "gamekit108", kFuncs_258, 2, "simple/gamekit108.hpp", false},
    {"gamekit109", "gamekit109", kFuncs_259, 2, "simple/gamekit109.hpp", false},
    {"gamekit110", "gamekit110", kFuncs_260, 2, "simple/gamekit110.hpp", false},
    {"gamekit111", "gamekit111", kFuncs_261, 2, "simple/gamekit111.hpp", false},
    {"gamekit112", "gamekit112", kFuncs_262, 2, "simple/gamekit112.hpp", false},
    {"gamekit113", "gamekit113", kFuncs_263, 2, "simple/gamekit113.hpp", false},
    {"gamekit114", "gamekit114", kFuncs_264, 2, "simple/gamekit114.hpp", false},
    {"gamekit115", "gamekit115", kFuncs_265, 2, "simple/gamekit115.hpp", false},
    {"gamekit116", "gamekit116", kFuncs_266, 2, "simple/gamekit116.hpp", false},
    {"gamekit117", "gamekit117", kFuncs_267, 2, "simple/gamekit117.hpp", false},
    {"gamekit118", "gamekit118", kFuncs_268, 2, "simple/gamekit118.hpp", false},
    {"gamekit119", "gamekit119", kFuncs_269, 2, "simple/gamekit119.hpp", false},
    {"gamekit120", "gamekit120", kFuncs_270, 2, "simple/gamekit120.hpp", false},
    {"gamekit121", "gamekit121", kFuncs_271, 2, "simple/gamekit121.hpp", false},
    {"gamekit122", "gamekit122", kFuncs_272, 2, "simple/gamekit122.hpp", false},
    {"gamekit123", "gamekit123", kFuncs_273, 2, "simple/gamekit123.hpp", false},
    {"gamekit124", "gamekit124", kFuncs_274, 2, "simple/gamekit124.hpp", false},
    {"gamekit125", "gamekit125", kFuncs_275, 2, "simple/gamekit125.hpp", false},
    {"gamekit126", "gamekit126", kFuncs_276, 2, "simple/gamekit126.hpp", false},
    {"gamekit127", "gamekit127", kFuncs_277, 2, "simple/gamekit127.hpp", false},
    {"gamekit128", "gamekit128", kFuncs_278, 2, "simple/gamekit128.hpp", false},
    {"gamekit129", "gamekit129", kFuncs_279, 2, "simple/gamekit129.hpp", false},
    {"gamekit130", "gamekit130", kFuncs_280, 2, "simple/gamekit130.hpp", false},
    {"gamekit131", "gamekit131", kFuncs_281, 2, "simple/gamekit131.hpp", false},
    {"gamekit132", "gamekit132", kFuncs_282, 2, "simple/gamekit132.hpp", false},
    {"gamekit133", "gamekit133", kFuncs_283, 2, "simple/gamekit133.hpp", false},
    {"gamekit134", "gamekit134", kFuncs_284, 2, "simple/gamekit134.hpp", false},
    {"gamekit135", "gamekit135", kFuncs_285, 2, "simple/gamekit135.hpp", false},
    {"gamekit136", "gamekit136", kFuncs_286, 2, "simple/gamekit136.hpp", false},
    {"gamekit137", "gamekit137", kFuncs_287, 2, "simple/gamekit137.hpp", false},
    {"gamekit138", "gamekit138", kFuncs_288, 2, "simple/gamekit138.hpp", false},
    {"gamekit139", "gamekit139", kFuncs_289, 2, "simple/gamekit139.hpp", false},
    {"gamekit140", "gamekit140", kFuncs_290, 2, "simple/gamekit140.hpp", false},
    {"gamekit141", "gamekit141", kFuncs_291, 2, "simple/gamekit141.hpp", false},
    {"gamekit142", "gamekit142", kFuncs_292, 2, "simple/gamekit142.hpp", false},
    {"gamekit143", "gamekit143", kFuncs_293, 2, "simple/gamekit143.hpp", false},
    {"gamekit144", "gamekit144", kFuncs_294, 2, "simple/gamekit144.hpp", false},
    {"gamekit145", "gamekit145", kFuncs_295, 2, "simple/gamekit145.hpp", false},
    {"gamekit146", "gamekit146", kFuncs_296, 2, "simple/gamekit146.hpp", false},
    {"gamekit147", "gamekit147", kFuncs_297, 2, "simple/gamekit147.hpp", false},
    {"gamekit148", "gamekit148", kFuncs_298, 2, "simple/gamekit148.hpp", false},
    {"gamekit149", "gamekit149", kFuncs_299, 2, "simple/gamekit149.hpp", false},
    {"gamekit150", "gamekit150", kFuncs_300, 2, "simple/gamekit150.hpp", false},
    {"gamekit151", "gamekit151", kFuncs_301, 2, "simple/gamekit151.hpp", false},
    {"gamekit152", "gamekit152", kFuncs_302, 2, "simple/gamekit152.hpp", false},
    {"gamekit153", "gamekit153", kFuncs_303, 2, "simple/gamekit153.hpp", false},
    {"gamekit154", "gamekit154", kFuncs_304, 2, "simple/gamekit154.hpp", false},
    {"gamekit155", "gamekit155", kFuncs_305, 2, "simple/gamekit155.hpp", false},
    {"gamekit156", "gamekit156", kFuncs_306, 2, "simple/gamekit156.hpp", false},
    {"gamekit157", "gamekit157", kFuncs_307, 2, "simple/gamekit157.hpp", false},
    {"gamekit158", "gamekit158", kFuncs_308, 2, "simple/gamekit158.hpp", false},
    {"gamekit159", "gamekit159", kFuncs_309, 2, "simple/gamekit159.hpp", false},
    {"gamekit160", "gamekit160", kFuncs_310, 2, "simple/gamekit160.hpp", false},
    {"gamekit161", "gamekit161", kFuncs_311, 2, "simple/gamekit161.hpp", false},
    {"gamekit162", "gamekit162", kFuncs_312, 2, "simple/gamekit162.hpp", false},
    {"gamekit163", "gamekit163", kFuncs_313, 2, "simple/gamekit163.hpp", false},
    {"gamekit164", "gamekit164", kFuncs_314, 2, "simple/gamekit164.hpp", false},
    {"gamekit165", "gamekit165", kFuncs_315, 2, "simple/gamekit165.hpp", false},
    {"gamekit166", "gamekit166", kFuncs_316, 2, "simple/gamekit166.hpp", false},
    {"gamekit167", "gamekit167", kFuncs_317, 2, "simple/gamekit167.hpp", false},
    {"gamekit168", "gamekit168", kFuncs_318, 2, "simple/gamekit168.hpp", false},
    {"gamekit169", "gamekit169", kFuncs_319, 2, "simple/gamekit169.hpp", false},
    {"gamekit170", "gamekit170", kFuncs_320, 2, "simple/gamekit170.hpp", false},
    {"gamekit171", "gamekit171", kFuncs_321, 2, "simple/gamekit171.hpp", false},
    {"gamekit172", "gamekit172", kFuncs_322, 2, "simple/gamekit172.hpp", false},
    {"gamekit173", "gamekit173", kFuncs_323, 2, "simple/gamekit173.hpp", false},
    {"gamekit174", "gamekit174", kFuncs_324, 2, "simple/gamekit174.hpp", false},
    {"gamekit175", "gamekit175", kFuncs_325, 2, "simple/gamekit175.hpp", false},
    {"gamekit176", "gamekit176", kFuncs_326, 2, "simple/gamekit176.hpp", false},
    {"gamekit177", "gamekit177", kFuncs_327, 2, "simple/gamekit177.hpp", false},
    {"gamekit178", "gamekit178", kFuncs_328, 2, "simple/gamekit178.hpp", false},
    {"gamekit179", "gamekit179", kFuncs_329, 2, "simple/gamekit179.hpp", false},
    {"gamekit180", "gamekit180", kFuncs_330, 2, "simple/gamekit180.hpp", false},
    {"gamekit181", "gamekit181", kFuncs_331, 2, "simple/gamekit181.hpp", false},
    {"gamekit182", "gamekit182", kFuncs_332, 2, "simple/gamekit182.hpp", false},
    {"gamekit183", "gamekit183", kFuncs_333, 2, "simple/gamekit183.hpp", false},
    {"gamekit184", "gamekit184", kFuncs_334, 2, "simple/gamekit184.hpp", false},
    {"gamekit185", "gamekit185", kFuncs_335, 2, "simple/gamekit185.hpp", false},
    {"gamekit186", "gamekit186", kFuncs_336, 2, "simple/gamekit186.hpp", false},
    {"gamekit187", "gamekit187", kFuncs_337, 2, "simple/gamekit187.hpp", false},
    {"gamekit188", "gamekit188", kFuncs_338, 2, "simple/gamekit188.hpp", false},
    {"gamekit189", "gamekit189", kFuncs_339, 2, "simple/gamekit189.hpp", false},
    {"gamekit190", "gamekit190", kFuncs_340, 2, "simple/gamekit190.hpp", false},
    {"gamekit191", "gamekit191", kFuncs_341, 2, "simple/gamekit191.hpp", false},
    {"gamekit192", "gamekit192", kFuncs_342, 2, "simple/gamekit192.hpp", false},
    {"gamekit193", "gamekit193", kFuncs_343, 2, "simple/gamekit193.hpp", false},
    {"gamekit194", "gamekit194", kFuncs_344, 2, "simple/gamekit194.hpp", false},
    {"gamekit195", "gamekit195", kFuncs_345, 2, "simple/gamekit195.hpp", false},
    {"gamekit196", "gamekit196", kFuncs_346, 2, "simple/gamekit196.hpp", false},
    {"gamekit197", "gamekit197", kFuncs_347, 2, "simple/gamekit197.hpp", false},
    {"gamekit198", "gamekit198", kFuncs_348, 2, "simple/gamekit198.hpp", false},
    {"gamekit199", "gamekit199", kFuncs_349, 2, "simple/gamekit199.hpp", false},
    {"gamekit200", "gamekit200", kFuncs_350, 2, "simple/gamekit200.hpp", false},
    {"gamekit201", "gamekit201", kFuncs_351, 2, "simple/gamekit201.hpp", false},
    {"gamekit202", "gamekit202", kFuncs_352, 2, "simple/gamekit202.hpp", false},
    {"gamekit203", "gamekit203", kFuncs_353, 2, "simple/gamekit203.hpp", false},
    {"gamekit204", "gamekit204", kFuncs_354, 2, "simple/gamekit204.hpp", false},
    {"gamekit205", "gamekit205", kFuncs_355, 2, "simple/gamekit205.hpp", false},
    {"gamekit206", "gamekit206", kFuncs_356, 2, "simple/gamekit206.hpp", false},
    {"gamekit207", "gamekit207", kFuncs_357, 2, "simple/gamekit207.hpp", false},
    {"gamekit208", "gamekit208", kFuncs_358, 2, "simple/gamekit208.hpp", false},
    {"gamekit209", "gamekit209", kFuncs_359, 2, "simple/gamekit209.hpp", false},
    {"gamekit210", "gamekit210", kFuncs_360, 2, "simple/gamekit210.hpp", false},
    {"gamekit211", "gamekit211", kFuncs_361, 2, "simple/gamekit211.hpp", false},
    {"gamekit212", "gamekit212", kFuncs_362, 2, "simple/gamekit212.hpp", false},
    {"gamekit213", "gamekit213", kFuncs_363, 2, "simple/gamekit213.hpp", false},
    {"gamekit214", "gamekit214", kFuncs_364, 2, "simple/gamekit214.hpp", false},
    {"gamekit215", "gamekit215", kFuncs_365, 2, "simple/gamekit215.hpp", false},
    {"gamekit216", "gamekit216", kFuncs_366, 2, "simple/gamekit216.hpp", false},
    {"gamekit217", "gamekit217", kFuncs_367, 2, "simple/gamekit217.hpp", false},
    {"gamekit218", "gamekit218", kFuncs_368, 2, "simple/gamekit218.hpp", false},
    {"gamekit219", "gamekit219", kFuncs_369, 2, "simple/gamekit219.hpp", false},
    {"gamekit220", "gamekit220", kFuncs_370, 2, "simple/gamekit220.hpp", false},
    {"gamekit221", "gamekit221", kFuncs_371, 2, "simple/gamekit221.hpp", false},
    {"gamekit222", "gamekit222", kFuncs_372, 2, "simple/gamekit222.hpp", false},
    {"gamekit223", "gamekit223", kFuncs_373, 2, "simple/gamekit223.hpp", false},
    {"gamekit224", "gamekit224", kFuncs_374, 2, "simple/gamekit224.hpp", false},
    {"gamekit225", "gamekit225", kFuncs_375, 2, "simple/gamekit225.hpp", false},
    {"gamekit226", "gamekit226", kFuncs_376, 2, "simple/gamekit226.hpp", false},
    {"gamekit227", "gamekit227", kFuncs_377, 2, "simple/gamekit227.hpp", false},
    {"gamekit228", "gamekit228", kFuncs_378, 2, "simple/gamekit228.hpp", false},
    {"gamekit229", "gamekit229", kFuncs_379, 2, "simple/gamekit229.hpp", false},
    {"gamekit230", "gamekit230", kFuncs_380, 2, "simple/gamekit230.hpp", false},
    {"gamekit231", "gamekit231", kFuncs_381, 2, "simple/gamekit231.hpp", false},
    {"gamekit232", "gamekit232", kFuncs_382, 2, "simple/gamekit232.hpp", false},
    {"gamekit233", "gamekit233", kFuncs_383, 2, "simple/gamekit233.hpp", false},
    {"gamekit234", "gamekit234", kFuncs_384, 2, "simple/gamekit234.hpp", false},
    {"gamekit235", "gamekit235", kFuncs_385, 2, "simple/gamekit235.hpp", false},
    {"gamekit236", "gamekit236", kFuncs_386, 2, "simple/gamekit236.hpp", false},
    {"gamekit237", "gamekit237", kFuncs_387, 2, "simple/gamekit237.hpp", false},
    {"gamekit238", "gamekit238", kFuncs_388, 2, "simple/gamekit238.hpp", false},
    {"gamekit239", "gamekit239", kFuncs_389, 2, "simple/gamekit239.hpp", false},
    {"gamekit240", "gamekit240", kFuncs_390, 2, "simple/gamekit240.hpp", false},
    {"gamekit241", "gamekit241", kFuncs_391, 2, "simple/gamekit241.hpp", false},
    {"gamekit242", "gamekit242", kFuncs_392, 2, "simple/gamekit242.hpp", false},
    {"gamekit243", "gamekit243", kFuncs_393, 2, "simple/gamekit243.hpp", false},
    {"gamekit244", "gamekit244", kFuncs_394, 2, "simple/gamekit244.hpp", false},
    {"gamekit245", "gamekit245", kFuncs_395, 2, "simple/gamekit245.hpp", false},
    {"gamekit246", "gamekit246", kFuncs_396, 2, "simple/gamekit246.hpp", false},
    {"gamekit247", "gamekit247", kFuncs_397, 2, "simple/gamekit247.hpp", false},
    {"gamekit248", "gamekit248", kFuncs_398, 2, "simple/gamekit248.hpp", false},
    {"gamekit249", "gamekit249", kFuncs_399, 2, "simple/gamekit249.hpp", false},
    {"gamekit250", "gamekit250", kFuncs_400, 2, "simple/gamekit250.hpp", false},
    {"gamekit251", "gamekit251", kFuncs_401, 2, "simple/gamekit251.hpp", false},
    {"gamekit252", "gamekit252", kFuncs_402, 2, "simple/gamekit252.hpp", false},
    {"gamekit253", "gamekit253", kFuncs_403, 2, "simple/gamekit253.hpp", false},
    {"gamekit254", "gamekit254", kFuncs_404, 2, "simple/gamekit254.hpp", false},
    {"gamekit255", "gamekit255", kFuncs_405, 2, "simple/gamekit255.hpp", false},
    {"gamekit256", "gamekit256", kFuncs_406, 2, "simple/gamekit256.hpp", false},
    {"gamekit257", "gamekit257", kFuncs_407, 2, "simple/gamekit257.hpp", false},
    {"gamekit258", "gamekit258", kFuncs_408, 2, "simple/gamekit258.hpp", false},
    {"gamekit259", "gamekit259", kFuncs_409, 2, "simple/gamekit259.hpp", false},
    {"gamekit260", "gamekit260", kFuncs_410, 2, "simple/gamekit260.hpp", false},
    {"gamekit261", "gamekit261", kFuncs_411, 2, "simple/gamekit261.hpp", false},
    {"gamekit262", "gamekit262", kFuncs_412, 2, "simple/gamekit262.hpp", false},
    {"gamekit263", "gamekit263", kFuncs_413, 2, "simple/gamekit263.hpp", false},
    {"gamekit264", "gamekit264", kFuncs_414, 2, "simple/gamekit264.hpp", false},
    {"gamekit265", "gamekit265", kFuncs_415, 2, "simple/gamekit265.hpp", false},
    {"gamekit266", "gamekit266", kFuncs_416, 2, "simple/gamekit266.hpp", false},
    {"gamekit267", "gamekit267", kFuncs_417, 2, "simple/gamekit267.hpp", false},
    {"gamekit268", "gamekit268", kFuncs_418, 2, "simple/gamekit268.hpp", false},
    {"gamekit269", "gamekit269", kFuncs_419, 2, "simple/gamekit269.hpp", false},
    {"gamekit270", "gamekit270", kFuncs_420, 2, "simple/gamekit270.hpp", false},
    {"gamekit271", "gamekit271", kFuncs_421, 2, "simple/gamekit271.hpp", false},
    {"gamekit272", "gamekit272", kFuncs_422, 2, "simple/gamekit272.hpp", false},
    {"gamekit273", "gamekit273", kFuncs_423, 2, "simple/gamekit273.hpp", false},
    {"gamekit274", "gamekit274", kFuncs_424, 2, "simple/gamekit274.hpp", false},
    {"gamekit275", "gamekit275", kFuncs_425, 2, "simple/gamekit275.hpp", false},
    {"gamekit276", "gamekit276", kFuncs_426, 2, "simple/gamekit276.hpp", false},
    {"gamekit277", "gamekit277", kFuncs_427, 2, "simple/gamekit277.hpp", false},
    {"gamekit278", "gamekit278", kFuncs_428, 2, "simple/gamekit278.hpp", false},
    {"gamekit279", "gamekit279", kFuncs_429, 2, "simple/gamekit279.hpp", false},
    {"gamekit280", "gamekit280", kFuncs_430, 2, "simple/gamekit280.hpp", false},
    {"gamekit281", "gamekit281", kFuncs_431, 2, "simple/gamekit281.hpp", false},
    {"gamekit282", "gamekit282", kFuncs_432, 2, "simple/gamekit282.hpp", false},
    {"gamekit283", "gamekit283", kFuncs_433, 2, "simple/gamekit283.hpp", false},
    {"gamekit284", "gamekit284", kFuncs_434, 2, "simple/gamekit284.hpp", false},
    {"gamekit285", "gamekit285", kFuncs_435, 2, "simple/gamekit285.hpp", false},
    {"gamekit286", "gamekit286", kFuncs_436, 2, "simple/gamekit286.hpp", false},
    {"gamekit287", "gamekit287", kFuncs_437, 2, "simple/gamekit287.hpp", false},
    {"gamekit288", "gamekit288", kFuncs_438, 2, "simple/gamekit288.hpp", false},
    {"gamekit289", "gamekit289", kFuncs_439, 2, "simple/gamekit289.hpp", false},
    {"gamekit290", "gamekit290", kFuncs_440, 2, "simple/gamekit290.hpp", false},
    {"gamekit291", "gamekit291", kFuncs_441, 2, "simple/gamekit291.hpp", false},
    {"gamekit292", "gamekit292", kFuncs_442, 2, "simple/gamekit292.hpp", false},
    {"gamekit293", "gamekit293", kFuncs_443, 2, "simple/gamekit293.hpp", false},
    {"gamekit294", "gamekit294", kFuncs_444, 2, "simple/gamekit294.hpp", false},
    {"gamekit295", "gamekit295", kFuncs_445, 2, "simple/gamekit295.hpp", false},
    {"gamekit296", "gamekit296", kFuncs_446, 2, "simple/gamekit296.hpp", false},
    {"gamekit297", "gamekit297", kFuncs_447, 2, "simple/gamekit297.hpp", false},
    {"gamekit298", "gamekit298", kFuncs_448, 2, "simple/gamekit298.hpp", false},
    {"gamekit299", "gamekit299", kFuncs_449, 2, "simple/gamekit299.hpp", false},
    {"gamekit300", "gamekit300", kFuncs_450, 2, "simple/gamekit300.hpp", false},
    {"gamekit301", "gamekit301", kFuncs_451, 2, "simple/gamekit301.hpp", false},
    {"gamekit302", "gamekit302", kFuncs_452, 2, "simple/gamekit302.hpp", false},
    {"gamekit303", "gamekit303", kFuncs_453, 2, "simple/gamekit303.hpp", false},
    {"gamekit304", "gamekit304", kFuncs_454, 2, "simple/gamekit304.hpp", false},
    {"gamekit305", "gamekit305", kFuncs_455, 2, "simple/gamekit305.hpp", false},
    {"gamekit306", "gamekit306", kFuncs_456, 2, "simple/gamekit306.hpp", false},
    {"gamekit307", "gamekit307", kFuncs_457, 2, "simple/gamekit307.hpp", false},
    {"gamekit308", "gamekit308", kFuncs_458, 2, "simple/gamekit308.hpp", false},
    {"gamekit309", "gamekit309", kFuncs_459, 2, "simple/gamekit309.hpp", false},
    {"gamekit310", "gamekit310", kFuncs_460, 2, "simple/gamekit310.hpp", false},
    {"gamekit311", "gamekit311", kFuncs_461, 2, "simple/gamekit311.hpp", false},
    {"gamekit312", "gamekit312", kFuncs_462, 2, "simple/gamekit312.hpp", false},
    {"gamekit313", "gamekit313", kFuncs_463, 2, "simple/gamekit313.hpp", false},
    {"gamekit314", "gamekit314", kFuncs_464, 2, "simple/gamekit314.hpp", false},
    {"gamekit315", "gamekit315", kFuncs_465, 2, "simple/gamekit315.hpp", false},
    {"gamekit316", "gamekit316", kFuncs_466, 2, "simple/gamekit316.hpp", false},
    {"gamekit317", "gamekit317", kFuncs_467, 2, "simple/gamekit317.hpp", false},
    {"gamekit318", "gamekit318", kFuncs_468, 2, "simple/gamekit318.hpp", false},
    {"gamekit319", "gamekit319", kFuncs_469, 2, "simple/gamekit319.hpp", false},
    {"gamekit320", "gamekit320", kFuncs_470, 2, "simple/gamekit320.hpp", false},
    {"gamekit321", "gamekit321", kFuncs_471, 2, "simple/gamekit321.hpp", false},
    {"gamekit322", "gamekit322", kFuncs_472, 2, "simple/gamekit322.hpp", false},
    {"gamekit323", "gamekit323", kFuncs_473, 2, "simple/gamekit323.hpp", false},
    {"gamekit324", "gamekit324", kFuncs_474, 2, "simple/gamekit324.hpp", false},
    {"gamekit325", "gamekit325", kFuncs_475, 2, "simple/gamekit325.hpp", false},
    {"gamekit326", "gamekit326", kFuncs_476, 2, "simple/gamekit326.hpp", false},
    {"gamekit327", "gamekit327", kFuncs_477, 2, "simple/gamekit327.hpp", false},
    {"gamekit328", "gamekit328", kFuncs_478, 2, "simple/gamekit328.hpp", false},
    {"gamekit329", "gamekit329", kFuncs_479, 2, "simple/gamekit329.hpp", false},
    {"gamekit330", "gamekit330", kFuncs_480, 2, "simple/gamekit330.hpp", false},
    {"gamekit331", "gamekit331", kFuncs_481, 2, "simple/gamekit331.hpp", false},
    {"gamekit332", "gamekit332", kFuncs_482, 2, "simple/gamekit332.hpp", false},
    {"gamekit333", "gamekit333", kFuncs_483, 2, "simple/gamekit333.hpp", false},
    {"gamekit334", "gamekit334", kFuncs_484, 2, "simple/gamekit334.hpp", false},
    {"gamekit335", "gamekit335", kFuncs_485, 2, "simple/gamekit335.hpp", false},
    {"gamekit336", "gamekit336", kFuncs_486, 2, "simple/gamekit336.hpp", false},
    {"gamekit337", "gamekit337", kFuncs_487, 2, "simple/gamekit337.hpp", false},
    {"gamekit338", "gamekit338", kFuncs_488, 2, "simple/gamekit338.hpp", false},
    {"gamekit339", "gamekit339", kFuncs_489, 2, "simple/gamekit339.hpp", false},
    {"gamekit340", "gamekit340", kFuncs_490, 2, "simple/gamekit340.hpp", false},
    {"gamekit341", "gamekit341", kFuncs_491, 2, "simple/gamekit341.hpp", false},
    {"gamekit342", "gamekit342", kFuncs_492, 2, "simple/gamekit342.hpp", false},
    {"gamekit343", "gamekit343", kFuncs_493, 2, "simple/gamekit343.hpp", false},
    {"gamekit344", "gamekit344", kFuncs_494, 2, "simple/gamekit344.hpp", false},
    {"gamekit345", "gamekit345", kFuncs_495, 2, "simple/gamekit345.hpp", false},
    {"gamekit346", "gamekit346", kFuncs_496, 2, "simple/gamekit346.hpp", false},
    {"gamekit347", "gamekit347", kFuncs_497, 2, "simple/gamekit347.hpp", false},
    {"gamekit348", "gamekit348", kFuncs_498, 2, "simple/gamekit348.hpp", false},
    {"gamekit349", "gamekit349", kFuncs_499, 2, "simple/gamekit349.hpp", false},
    {"gamekit350", "gamekit350", kFuncs_500, 2, "simple/gamekit350.hpp", false},
    {"gamekit351", "gamekit351", kFuncs_501, 2, "simple/gamekit351.hpp", false},
    {"gamekit352", "gamekit352", kFuncs_502, 2, "simple/gamekit352.hpp", false},
    {"gamekit353", "gamekit353", kFuncs_503, 2, "simple/gamekit353.hpp", false},
    {"gamekit354", "gamekit354", kFuncs_504, 2, "simple/gamekit354.hpp", false},
    {"gamekit355", "gamekit355", kFuncs_505, 2, "simple/gamekit355.hpp", false},
    {"gamekit356", "gamekit356", kFuncs_506, 2, "simple/gamekit356.hpp", false},
    {"gamekit357", "gamekit357", kFuncs_507, 2, "simple/gamekit357.hpp", false},
    {"gamekit358", "gamekit358", kFuncs_508, 2, "simple/gamekit358.hpp", false},
    {"gamekit359", "gamekit359", kFuncs_509, 2, "simple/gamekit359.hpp", false},
    {"gamekit360", "gamekit360", kFuncs_510, 2, "simple/gamekit360.hpp", false},
    {"gamekit361", "gamekit361", kFuncs_511, 2, "simple/gamekit361.hpp", false},
    {"gamekit362", "gamekit362", kFuncs_512, 2, "simple/gamekit362.hpp", false},
    {"gamekit363", "gamekit363", kFuncs_513, 2, "simple/gamekit363.hpp", false},
    {"gamekit364", "gamekit364", kFuncs_514, 2, "simple/gamekit364.hpp", false},
    {"gamekit365", "gamekit365", kFuncs_515, 2, "simple/gamekit365.hpp", false},
    {"gamekit366", "gamekit366", kFuncs_516, 2, "simple/gamekit366.hpp", false},
    {"gamekit367", "gamekit367", kFuncs_517, 2, "simple/gamekit367.hpp", false},
    {"gamekit368", "gamekit368", kFuncs_518, 2, "simple/gamekit368.hpp", false},
    {"gamekit369", "gamekit369", kFuncs_519, 2, "simple/gamekit369.hpp", false},
    {"gamekit370", "gamekit370", kFuncs_520, 2, "simple/gamekit370.hpp", false},
    {"gamekit371", "gamekit371", kFuncs_521, 2, "simple/gamekit371.hpp", false},
    {"gamekit372", "gamekit372", kFuncs_522, 2, "simple/gamekit372.hpp", false},
    {"gamekit373", "gamekit373", kFuncs_523, 2, "simple/gamekit373.hpp", false},
    {"gamekit374", "gamekit374", kFuncs_524, 2, "simple/gamekit374.hpp", false},
    {"gamekit375", "gamekit375", kFuncs_525, 2, "simple/gamekit375.hpp", false},
    {"gamekit376", "gamekit376", kFuncs_526, 2, "simple/gamekit376.hpp", false},
    {"gamekit377", "gamekit377", kFuncs_527, 2, "simple/gamekit377.hpp", false},
    {"gamekit378", "gamekit378", kFuncs_528, 2, "simple/gamekit378.hpp", false},
    {"gamekit379", "gamekit379", kFuncs_529, 2, "simple/gamekit379.hpp", false},
    {"gamekit380", "gamekit380", kFuncs_530, 2, "simple/gamekit380.hpp", false},
    {"gamekit381", "gamekit381", kFuncs_531, 2, "simple/gamekit381.hpp", false},
    {"gamekit382", "gamekit382", kFuncs_532, 2, "simple/gamekit382.hpp", false},
    {"gamekit383", "gamekit383", kFuncs_533, 2, "simple/gamekit383.hpp", false},
    {"gamekit384", "gamekit384", kFuncs_534, 2, "simple/gamekit384.hpp", false},
    {"gamekit385", "gamekit385", kFuncs_535, 2, "simple/gamekit385.hpp", false},
    {"gamekit386", "gamekit386", kFuncs_536, 2, "simple/gamekit386.hpp", false},
    {"gamekit387", "gamekit387", kFuncs_537, 2, "simple/gamekit387.hpp", false},
    {"gamekit388", "gamekit388", kFuncs_538, 2, "simple/gamekit388.hpp", false},
    {"gamekit389", "gamekit389", kFuncs_539, 2, "simple/gamekit389.hpp", false},
    {"gamekit390", "gamekit390", kFuncs_540, 2, "simple/gamekit390.hpp", false},
    {"gamekit391", "gamekit391", kFuncs_541, 2, "simple/gamekit391.hpp", false},
    {"gamekit392", "gamekit392", kFuncs_542, 2, "simple/gamekit392.hpp", false},
    {"gamekit393", "gamekit393", kFuncs_543, 2, "simple/gamekit393.hpp", false},
    {"gamekit394", "gamekit394", kFuncs_544, 2, "simple/gamekit394.hpp", false},
    {"gamekit395", "gamekit395", kFuncs_545, 2, "simple/gamekit395.hpp", false},
    {"gamekit396", "gamekit396", kFuncs_546, 2, "simple/gamekit396.hpp", false},
    {"gamekit397", "gamekit397", kFuncs_547, 2, "simple/gamekit397.hpp", false},
    {"gamekit398", "gamekit398", kFuncs_548, 2, "simple/gamekit398.hpp", false},
    {"gamekit399", "gamekit399", kFuncs_549, 2, "simple/gamekit399.hpp", false},
    {"gamekit400", "gamekit400", kFuncs_550, 2, "simple/gamekit400.hpp", false},
    {"gamekit401", "gamekit401", kFuncs_551, 2, "simple/gamekit401.hpp", false},
    {"gamekit402", "gamekit402", kFuncs_552, 2, "simple/gamekit402.hpp", false},
    {"gamekit403", "gamekit403", kFuncs_553, 2, "simple/gamekit403.hpp", false},
    {"gamekit404", "gamekit404", kFuncs_554, 2, "simple/gamekit404.hpp", false},
    {"gamekit405", "gamekit405", kFuncs_555, 2, "simple/gamekit405.hpp", false},
    {"gamekit406", "gamekit406", kFuncs_556, 2, "simple/gamekit406.hpp", false},
    {"gamekit407", "gamekit407", kFuncs_557, 2, "simple/gamekit407.hpp", false},
    {"gamekit408", "gamekit408", kFuncs_558, 2, "simple/gamekit408.hpp", false},
    {"gamekit409", "gamekit409", kFuncs_559, 2, "simple/gamekit409.hpp", false},
    {"gamekit410", "gamekit410", kFuncs_560, 2, "simple/gamekit410.hpp", false},
    {"gamekit411", "gamekit411", kFuncs_561, 2, "simple/gamekit411.hpp", false},
    {"gamekit412", "gamekit412", kFuncs_562, 2, "simple/gamekit412.hpp", false},
    {"gamekit413", "gamekit413", kFuncs_563, 2, "simple/gamekit413.hpp", false},
    {"gamekit414", "gamekit414", kFuncs_564, 2, "simple/gamekit414.hpp", false},
    {"gamekit415", "gamekit415", kFuncs_565, 2, "simple/gamekit415.hpp", false},
    {"gamekit416", "gamekit416", kFuncs_566, 2, "simple/gamekit416.hpp", false},
    {"gamekit417", "gamekit417", kFuncs_567, 2, "simple/gamekit417.hpp", false},
    {"gamekit418", "gamekit418", kFuncs_568, 2, "simple/gamekit418.hpp", false},
    {"gamekit419", "gamekit419", kFuncs_569, 2, "simple/gamekit419.hpp", false},
    {"gamekit420", "gamekit420", kFuncs_570, 2, "simple/gamekit420.hpp", false},
    {"gamekit421", "gamekit421", kFuncs_571, 2, "simple/gamekit421.hpp", false},
    {"gamekit422", "gamekit422", kFuncs_572, 2, "simple/gamekit422.hpp", false},
    {"gamekit423", "gamekit423", kFuncs_573, 2, "simple/gamekit423.hpp", false},
    {"gamekit424", "gamekit424", kFuncs_574, 2, "simple/gamekit424.hpp", false},
    {"gamekit425", "gamekit425", kFuncs_575, 2, "simple/gamekit425.hpp", false},
    {"gamekit426", "gamekit426", kFuncs_576, 2, "simple/gamekit426.hpp", false},
    {"gamekit427", "gamekit427", kFuncs_577, 2, "simple/gamekit427.hpp", false},
    {"gamekit428", "gamekit428", kFuncs_578, 2, "simple/gamekit428.hpp", false},
    {"gamekit429", "gamekit429", kFuncs_579, 2, "simple/gamekit429.hpp", false},
    {"gamekit430", "gamekit430", kFuncs_580, 2, "simple/gamekit430.hpp", false},
    {"gamekit431", "gamekit431", kFuncs_581, 2, "simple/gamekit431.hpp", false},
    {"gamekit432", "gamekit432", kFuncs_582, 2, "simple/gamekit432.hpp", false},
    {"gamekit433", "gamekit433", kFuncs_583, 2, "simple/gamekit433.hpp", false},
    {"gamekit434", "gamekit434", kFuncs_584, 2, "simple/gamekit434.hpp", false},
    {"gamekit435", "gamekit435", kFuncs_585, 2, "simple/gamekit435.hpp", false},
    {"gamekit436", "gamekit436", kFuncs_586, 2, "simple/gamekit436.hpp", false},
    {"gamekit437", "gamekit437", kFuncs_587, 2, "simple/gamekit437.hpp", false},
    {"gamekit438", "gamekit438", kFuncs_588, 2, "simple/gamekit438.hpp", false},
    {"gamekit439", "gamekit439", kFuncs_589, 2, "simple/gamekit439.hpp", false},
    {"gamekit440", "gamekit440", kFuncs_590, 2, "simple/gamekit440.hpp", false},
    {"gamekit441", "gamekit441", kFuncs_591, 2, "simple/gamekit441.hpp", false},
    {"gamekit442", "gamekit442", kFuncs_592, 2, "simple/gamekit442.hpp", false},
    {"gamekit443", "gamekit443", kFuncs_593, 2, "simple/gamekit443.hpp", false},
    {"gamekit444", "gamekit444", kFuncs_594, 2, "simple/gamekit444.hpp", false},
    {"gamekit445", "gamekit445", kFuncs_595, 2, "simple/gamekit445.hpp", false},
    {"gamekit446", "gamekit446", kFuncs_596, 2, "simple/gamekit446.hpp", false},
    {"gamekit447", "gamekit447", kFuncs_597, 2, "simple/gamekit447.hpp", false},
    {"gamekit448", "gamekit448", kFuncs_598, 2, "simple/gamekit448.hpp", false},
    {"gamekit449", "gamekit449", kFuncs_599, 2, "simple/gamekit449.hpp", false},
    {"gamekit450", "gamekit450", kFuncs_600, 2, "simple/gamekit450.hpp", false},
    {"gamekit451", "gamekit451", kFuncs_601, 2, "simple/gamekit451.hpp", false},
    {"gamekit452", "gamekit452", kFuncs_602, 2, "simple/gamekit452.hpp", false},
    {"gamekit453", "gamekit453", kFuncs_603, 2, "simple/gamekit453.hpp", false},
    {"gamekit454", "gamekit454", kFuncs_604, 2, "simple/gamekit454.hpp", false},
    {"gamekit455", "gamekit455", kFuncs_605, 2, "simple/gamekit455.hpp", false},
    {"gamekit456", "gamekit456", kFuncs_606, 2, "simple/gamekit456.hpp", false},
    {"gamekit457", "gamekit457", kFuncs_607, 2, "simple/gamekit457.hpp", false},
    {"gamekit458", "gamekit458", kFuncs_608, 2, "simple/gamekit458.hpp", false},
    {"gamekit459", "gamekit459", kFuncs_609, 2, "simple/gamekit459.hpp", false},
    {"gamekit460", "gamekit460", kFuncs_610, 2, "simple/gamekit460.hpp", false},
    {"gamekit461", "gamekit461", kFuncs_611, 2, "simple/gamekit461.hpp", false},
    {"gamekit462", "gamekit462", kFuncs_612, 2, "simple/gamekit462.hpp", false},
    {"gamekit463", "gamekit463", kFuncs_613, 2, "simple/gamekit463.hpp", false},
    {"gamekit464", "gamekit464", kFuncs_614, 2, "simple/gamekit464.hpp", false},
    {"gamekit465", "gamekit465", kFuncs_615, 2, "simple/gamekit465.hpp", false},
    {"gamekit466", "gamekit466", kFuncs_616, 2, "simple/gamekit466.hpp", false},
    {"gamekit467", "gamekit467", kFuncs_617, 2, "simple/gamekit467.hpp", false},
    {"gamekit468", "gamekit468", kFuncs_618, 2, "simple/gamekit468.hpp", false},
    {"gamekit469", "gamekit469", kFuncs_619, 2, "simple/gamekit469.hpp", false},
    {"gamekit470", "gamekit470", kFuncs_620, 2, "simple/gamekit470.hpp", false},
    {"gamekit471", "gamekit471", kFuncs_621, 2, "simple/gamekit471.hpp", false},
    {"gamekit472", "gamekit472", kFuncs_622, 2, "simple/gamekit472.hpp", false},
    {"gamekit473", "gamekit473", kFuncs_623, 2, "simple/gamekit473.hpp", false},
    {"gamekit474", "gamekit474", kFuncs_624, 2, "simple/gamekit474.hpp", false},
    {"gamekit475", "gamekit475", kFuncs_625, 2, "simple/gamekit475.hpp", false},
    {"gamekit476", "gamekit476", kFuncs_626, 2, "simple/gamekit476.hpp", false},
    {"gamekit477", "gamekit477", kFuncs_627, 2, "simple/gamekit477.hpp", false},
    {"gamekit478", "gamekit478", kFuncs_628, 2, "simple/gamekit478.hpp", false},
    {"gamekit479", "gamekit479", kFuncs_629, 2, "simple/gamekit479.hpp", false},
    {"gamekit480", "gamekit480", kFuncs_630, 2, "simple/gamekit480.hpp", false},
    {"gamekit481", "gamekit481", kFuncs_631, 2, "simple/gamekit481.hpp", false},
    {"gamekit482", "gamekit482", kFuncs_632, 2, "simple/gamekit482.hpp", false},
    {"gamekit483", "gamekit483", kFuncs_633, 2, "simple/gamekit483.hpp", false},
    {"gamekit484", "gamekit484", kFuncs_634, 2, "simple/gamekit484.hpp", false},
    {"gamekit485", "gamekit485", kFuncs_635, 2, "simple/gamekit485.hpp", false},
    {"gamekit486", "gamekit486", kFuncs_636, 2, "simple/gamekit486.hpp", false},
    {"gamekit487", "gamekit487", kFuncs_637, 2, "simple/gamekit487.hpp", false},
    {"gamekit488", "gamekit488", kFuncs_638, 2, "simple/gamekit488.hpp", false},
    {"gamekit489", "gamekit489", kFuncs_639, 2, "simple/gamekit489.hpp", false},
    {"gamekit490", "gamekit490", kFuncs_640, 2, "simple/gamekit490.hpp", false},
    {"gamekit491", "gamekit491", kFuncs_641, 2, "simple/gamekit491.hpp", false},
    {"gamekit492", "gamekit492", kFuncs_642, 2, "simple/gamekit492.hpp", false},
    {"gamekit493", "gamekit493", kFuncs_643, 2, "simple/gamekit493.hpp", false},
    {"gamekit494", "gamekit494", kFuncs_644, 2, "simple/gamekit494.hpp", false},
    {"gamekit495", "gamekit495", kFuncs_645, 2, "simple/gamekit495.hpp", false},
    {"gamekit496", "gamekit496", kFuncs_646, 2, "simple/gamekit496.hpp", false},
    {"gamekit497", "gamekit497", kFuncs_647, 2, "simple/gamekit497.hpp", false},
    {"gamekit498", "gamekit498", kFuncs_648, 2, "simple/gamekit498.hpp", false},
    {"gamekit499", "gamekit499", kFuncs_649, 2, "simple/gamekit499.hpp", false},
    {"gamekit500", "gamekit500", kFuncs_650, 2, "simple/gamekit500.hpp", false},
    {nullptr, nullptr, nullptr, 0, nullptr, false}
};

const std::size_t kSimpleModuleCount = 651;

} // namespace

const StdlibModuleSpec* stdlibCatalogModules() { return kSimpleModules; }
std::size_t stdlibCatalogModuleCount() { return kSimpleModuleCount; }

const StdlibModuleSpec* stdlibCatalogFindModule(const std::string& name) {
    for (std::size_t i = 0; i < kSimpleModuleCount; ++i) {
        if (name == kSimpleModules[i].importName || name == kSimpleModules[i].moduleName)
            return &kSimpleModules[i];
    }
    return nullptr;
}

bool stdlibCatalogIsSimpleModule(const std::string& name) {
    return stdlibCatalogFindModule(name) != nullptr;
}

} // namespace afrilang