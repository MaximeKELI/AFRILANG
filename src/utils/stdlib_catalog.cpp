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
    {"template", "template", kFuncs_147, 2, "simple/template.hpp", false},
    {"i18n", "i18n", kFuncs_148, 2, "simple/i18n.hpp", false},
    {"education", "education", kFuncs_149, 2, "simple/education.hpp", false},
    {"quiz", "quiz", kFuncs_150, 2, "simple/quiz.hpp", false},
    {nullptr, nullptr, nullptr, 0, nullptr, false}
};

const std::size_t kSimpleModuleCount = 151;

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