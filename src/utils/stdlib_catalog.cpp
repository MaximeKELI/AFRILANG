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
    {"score", "number"},
    {"level", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_108[] = {
    {"scoreBonus", "number", 2, &kParams_108[0]},
    {"levelFromXp", "number", 1, &kParams_108[2]},
    {"xpForScore", "number", 1, &kParams_108[3]},
    {"speedMsForLevel", "number", 1, &kParams_108[4]},
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

const StdlibParamSpec kParams_651[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_651[] = {
    {"aabbHit", "bool", 8, &kParams_651[0]},
    {"dist2", "number", 4, &kParams_651[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_652[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_652[] = {
    {"approach", "number", 3, &kParams_652[0]},
    {"follow", "number", 3, &kParams_652[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_653[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_653[] = {
    {"dist2", "number", 4, &kParams_653[0]},
    {"wrap", "number", 2, &kParams_653[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_654[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_654[] = {
    {"shake", "number", 2, &kParams_654[0]},
    {"follow", "number", 3, &kParams_654[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_655[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_655[] = {
    {"snapGrid", "number", 1, &kParams_655[0]},
    {"pointInRect", "bool", 6, &kParams_655[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_656[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_656[] = {
    {"aabbHit", "bool", 8, &kParams_656[0]},
    {"pointInRect", "bool", 6, &kParams_656[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_657[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_657[] = {
    {"aabbHit", "bool", 8, &kParams_657[0]},
    {"dist2", "number", 4, &kParams_657[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_658[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_658[] = {
    {"approach", "number", 3, &kParams_658[0]},
    {"follow", "number", 3, &kParams_658[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_659[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_659[] = {
    {"dist2", "number", 4, &kParams_659[0]},
    {"wrap", "number", 2, &kParams_659[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_660[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_660[] = {
    {"shake", "number", 2, &kParams_660[0]},
    {"follow", "number", 3, &kParams_660[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_661[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_661[] = {
    {"snapGrid", "number", 1, &kParams_661[0]},
    {"pointInRect", "bool", 6, &kParams_661[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_662[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_662[] = {
    {"aabbHit", "bool", 8, &kParams_662[0]},
    {"pointInRect", "bool", 6, &kParams_662[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_663[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_663[] = {
    {"aabbHit", "bool", 8, &kParams_663[0]},
    {"dist2", "number", 4, &kParams_663[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_664[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_664[] = {
    {"approach", "number", 3, &kParams_664[0]},
    {"follow", "number", 3, &kParams_664[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_665[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_665[] = {
    {"dist2", "number", 4, &kParams_665[0]},
    {"wrap", "number", 2, &kParams_665[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_666[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_666[] = {
    {"shake", "number", 2, &kParams_666[0]},
    {"follow", "number", 3, &kParams_666[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_667[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_667[] = {
    {"snapGrid", "number", 1, &kParams_667[0]},
    {"pointInRect", "bool", 6, &kParams_667[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_668[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_668[] = {
    {"aabbHit", "bool", 8, &kParams_668[0]},
    {"pointInRect", "bool", 6, &kParams_668[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_669[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_669[] = {
    {"aabbHit", "bool", 8, &kParams_669[0]},
    {"dist2", "number", 4, &kParams_669[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_670[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_670[] = {
    {"approach", "number", 3, &kParams_670[0]},
    {"follow", "number", 3, &kParams_670[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_671[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_671[] = {
    {"dist2", "number", 4, &kParams_671[0]},
    {"wrap", "number", 2, &kParams_671[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_672[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_672[] = {
    {"shake", "number", 2, &kParams_672[0]},
    {"follow", "number", 3, &kParams_672[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_673[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_673[] = {
    {"snapGrid", "number", 1, &kParams_673[0]},
    {"pointInRect", "bool", 6, &kParams_673[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_674[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_674[] = {
    {"aabbHit", "bool", 8, &kParams_674[0]},
    {"pointInRect", "bool", 6, &kParams_674[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_675[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_675[] = {
    {"aabbHit", "bool", 8, &kParams_675[0]},
    {"dist2", "number", 4, &kParams_675[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_676[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_676[] = {
    {"approach", "number", 3, &kParams_676[0]},
    {"follow", "number", 3, &kParams_676[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_677[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_677[] = {
    {"dist2", "number", 4, &kParams_677[0]},
    {"wrap", "number", 2, &kParams_677[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_678[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_678[] = {
    {"shake", "number", 2, &kParams_678[0]},
    {"follow", "number", 3, &kParams_678[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_679[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_679[] = {
    {"snapGrid", "number", 1, &kParams_679[0]},
    {"pointInRect", "bool", 6, &kParams_679[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_680[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_680[] = {
    {"aabbHit", "bool", 8, &kParams_680[0]},
    {"pointInRect", "bool", 6, &kParams_680[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_681[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_681[] = {
    {"aabbHit", "bool", 8, &kParams_681[0]},
    {"dist2", "number", 4, &kParams_681[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_682[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_682[] = {
    {"approach", "number", 3, &kParams_682[0]},
    {"follow", "number", 3, &kParams_682[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_683[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_683[] = {
    {"dist2", "number", 4, &kParams_683[0]},
    {"wrap", "number", 2, &kParams_683[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_684[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_684[] = {
    {"shake", "number", 2, &kParams_684[0]},
    {"follow", "number", 3, &kParams_684[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_685[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_685[] = {
    {"snapGrid", "number", 1, &kParams_685[0]},
    {"pointInRect", "bool", 6, &kParams_685[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_686[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_686[] = {
    {"aabbHit", "bool", 8, &kParams_686[0]},
    {"pointInRect", "bool", 6, &kParams_686[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_687[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_687[] = {
    {"aabbHit", "bool", 8, &kParams_687[0]},
    {"dist2", "number", 4, &kParams_687[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_688[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_688[] = {
    {"approach", "number", 3, &kParams_688[0]},
    {"follow", "number", 3, &kParams_688[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_689[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_689[] = {
    {"dist2", "number", 4, &kParams_689[0]},
    {"wrap", "number", 2, &kParams_689[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_690[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_690[] = {
    {"shake", "number", 2, &kParams_690[0]},
    {"follow", "number", 3, &kParams_690[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_691[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_691[] = {
    {"snapGrid", "number", 1, &kParams_691[0]},
    {"pointInRect", "bool", 6, &kParams_691[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_692[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_692[] = {
    {"aabbHit", "bool", 8, &kParams_692[0]},
    {"pointInRect", "bool", 6, &kParams_692[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_693[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_693[] = {
    {"aabbHit", "bool", 8, &kParams_693[0]},
    {"dist2", "number", 4, &kParams_693[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_694[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_694[] = {
    {"approach", "number", 3, &kParams_694[0]},
    {"follow", "number", 3, &kParams_694[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_695[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_695[] = {
    {"dist2", "number", 4, &kParams_695[0]},
    {"wrap", "number", 2, &kParams_695[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_696[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_696[] = {
    {"shake", "number", 2, &kParams_696[0]},
    {"follow", "number", 3, &kParams_696[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_697[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_697[] = {
    {"snapGrid", "number", 1, &kParams_697[0]},
    {"pointInRect", "bool", 6, &kParams_697[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_698[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_698[] = {
    {"aabbHit", "bool", 8, &kParams_698[0]},
    {"pointInRect", "bool", 6, &kParams_698[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_699[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_699[] = {
    {"aabbHit", "bool", 8, &kParams_699[0]},
    {"dist2", "number", 4, &kParams_699[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_700[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_700[] = {
    {"approach", "number", 3, &kParams_700[0]},
    {"follow", "number", 3, &kParams_700[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_701[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_701[] = {
    {"dist2", "number", 4, &kParams_701[0]},
    {"wrap", "number", 2, &kParams_701[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_702[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_702[] = {
    {"shake", "number", 2, &kParams_702[0]},
    {"follow", "number", 3, &kParams_702[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_703[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_703[] = {
    {"snapGrid", "number", 1, &kParams_703[0]},
    {"pointInRect", "bool", 6, &kParams_703[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_704[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_704[] = {
    {"aabbHit", "bool", 8, &kParams_704[0]},
    {"pointInRect", "bool", 6, &kParams_704[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_705[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_705[] = {
    {"aabbHit", "bool", 8, &kParams_705[0]},
    {"dist2", "number", 4, &kParams_705[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_706[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_706[] = {
    {"approach", "number", 3, &kParams_706[0]},
    {"follow", "number", 3, &kParams_706[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_707[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_707[] = {
    {"dist2", "number", 4, &kParams_707[0]},
    {"wrap", "number", 2, &kParams_707[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_708[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_708[] = {
    {"shake", "number", 2, &kParams_708[0]},
    {"follow", "number", 3, &kParams_708[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_709[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_709[] = {
    {"snapGrid", "number", 1, &kParams_709[0]},
    {"pointInRect", "bool", 6, &kParams_709[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_710[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_710[] = {
    {"aabbHit", "bool", 8, &kParams_710[0]},
    {"pointInRect", "bool", 6, &kParams_710[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_711[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_711[] = {
    {"aabbHit", "bool", 8, &kParams_711[0]},
    {"dist2", "number", 4, &kParams_711[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_712[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_712[] = {
    {"approach", "number", 3, &kParams_712[0]},
    {"follow", "number", 3, &kParams_712[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_713[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_713[] = {
    {"dist2", "number", 4, &kParams_713[0]},
    {"wrap", "number", 2, &kParams_713[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_714[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_714[] = {
    {"shake", "number", 2, &kParams_714[0]},
    {"follow", "number", 3, &kParams_714[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_715[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_715[] = {
    {"snapGrid", "number", 1, &kParams_715[0]},
    {"pointInRect", "bool", 6, &kParams_715[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_716[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_716[] = {
    {"aabbHit", "bool", 8, &kParams_716[0]},
    {"pointInRect", "bool", 6, &kParams_716[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_717[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_717[] = {
    {"aabbHit", "bool", 8, &kParams_717[0]},
    {"dist2", "number", 4, &kParams_717[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_718[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_718[] = {
    {"approach", "number", 3, &kParams_718[0]},
    {"follow", "number", 3, &kParams_718[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_719[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_719[] = {
    {"dist2", "number", 4, &kParams_719[0]},
    {"wrap", "number", 2, &kParams_719[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_720[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_720[] = {
    {"shake", "number", 2, &kParams_720[0]},
    {"follow", "number", 3, &kParams_720[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_721[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_721[] = {
    {"snapGrid", "number", 1, &kParams_721[0]},
    {"pointInRect", "bool", 6, &kParams_721[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_722[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_722[] = {
    {"aabbHit", "bool", 8, &kParams_722[0]},
    {"pointInRect", "bool", 6, &kParams_722[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_723[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_723[] = {
    {"aabbHit", "bool", 8, &kParams_723[0]},
    {"dist2", "number", 4, &kParams_723[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_724[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_724[] = {
    {"approach", "number", 3, &kParams_724[0]},
    {"follow", "number", 3, &kParams_724[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_725[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_725[] = {
    {"dist2", "number", 4, &kParams_725[0]},
    {"wrap", "number", 2, &kParams_725[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_726[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_726[] = {
    {"shake", "number", 2, &kParams_726[0]},
    {"follow", "number", 3, &kParams_726[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_727[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_727[] = {
    {"snapGrid", "number", 1, &kParams_727[0]},
    {"pointInRect", "bool", 6, &kParams_727[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_728[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_728[] = {
    {"aabbHit", "bool", 8, &kParams_728[0]},
    {"pointInRect", "bool", 6, &kParams_728[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_729[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_729[] = {
    {"aabbHit", "bool", 8, &kParams_729[0]},
    {"dist2", "number", 4, &kParams_729[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_730[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_730[] = {
    {"approach", "number", 3, &kParams_730[0]},
    {"follow", "number", 3, &kParams_730[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_731[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_731[] = {
    {"dist2", "number", 4, &kParams_731[0]},
    {"wrap", "number", 2, &kParams_731[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_732[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_732[] = {
    {"shake", "number", 2, &kParams_732[0]},
    {"follow", "number", 3, &kParams_732[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_733[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_733[] = {
    {"snapGrid", "number", 1, &kParams_733[0]},
    {"pointInRect", "bool", 6, &kParams_733[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_734[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_734[] = {
    {"aabbHit", "bool", 8, &kParams_734[0]},
    {"pointInRect", "bool", 6, &kParams_734[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_735[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_735[] = {
    {"aabbHit", "bool", 8, &kParams_735[0]},
    {"dist2", "number", 4, &kParams_735[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_736[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_736[] = {
    {"approach", "number", 3, &kParams_736[0]},
    {"follow", "number", 3, &kParams_736[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_737[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_737[] = {
    {"dist2", "number", 4, &kParams_737[0]},
    {"wrap", "number", 2, &kParams_737[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_738[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_738[] = {
    {"shake", "number", 2, &kParams_738[0]},
    {"follow", "number", 3, &kParams_738[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_739[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_739[] = {
    {"snapGrid", "number", 1, &kParams_739[0]},
    {"pointInRect", "bool", 6, &kParams_739[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_740[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_740[] = {
    {"aabbHit", "bool", 8, &kParams_740[0]},
    {"pointInRect", "bool", 6, &kParams_740[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_741[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_741[] = {
    {"aabbHit", "bool", 8, &kParams_741[0]},
    {"dist2", "number", 4, &kParams_741[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_742[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_742[] = {
    {"approach", "number", 3, &kParams_742[0]},
    {"follow", "number", 3, &kParams_742[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_743[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_743[] = {
    {"dist2", "number", 4, &kParams_743[0]},
    {"wrap", "number", 2, &kParams_743[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_744[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_744[] = {
    {"shake", "number", 2, &kParams_744[0]},
    {"follow", "number", 3, &kParams_744[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_745[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_745[] = {
    {"snapGrid", "number", 1, &kParams_745[0]},
    {"pointInRect", "bool", 6, &kParams_745[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_746[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_746[] = {
    {"aabbHit", "bool", 8, &kParams_746[0]},
    {"pointInRect", "bool", 6, &kParams_746[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_747[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_747[] = {
    {"aabbHit", "bool", 8, &kParams_747[0]},
    {"dist2", "number", 4, &kParams_747[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_748[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_748[] = {
    {"approach", "number", 3, &kParams_748[0]},
    {"follow", "number", 3, &kParams_748[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_749[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_749[] = {
    {"dist2", "number", 4, &kParams_749[0]},
    {"wrap", "number", 2, &kParams_749[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_750[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_750[] = {
    {"shake", "number", 2, &kParams_750[0]},
    {"follow", "number", 3, &kParams_750[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_751[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_751[] = {
    {"snapGrid", "number", 1, &kParams_751[0]},
    {"pointInRect", "bool", 6, &kParams_751[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_752[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_752[] = {
    {"aabbHit", "bool", 8, &kParams_752[0]},
    {"pointInRect", "bool", 6, &kParams_752[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_753[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_753[] = {
    {"aabbHit", "bool", 8, &kParams_753[0]},
    {"dist2", "number", 4, &kParams_753[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_754[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_754[] = {
    {"approach", "number", 3, &kParams_754[0]},
    {"follow", "number", 3, &kParams_754[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_755[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_755[] = {
    {"dist2", "number", 4, &kParams_755[0]},
    {"wrap", "number", 2, &kParams_755[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_756[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_756[] = {
    {"shake", "number", 2, &kParams_756[0]},
    {"follow", "number", 3, &kParams_756[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_757[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_757[] = {
    {"snapGrid", "number", 1, &kParams_757[0]},
    {"pointInRect", "bool", 6, &kParams_757[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_758[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_758[] = {
    {"aabbHit", "bool", 8, &kParams_758[0]},
    {"pointInRect", "bool", 6, &kParams_758[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_759[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_759[] = {
    {"aabbHit", "bool", 8, &kParams_759[0]},
    {"dist2", "number", 4, &kParams_759[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_760[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_760[] = {
    {"approach", "number", 3, &kParams_760[0]},
    {"follow", "number", 3, &kParams_760[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_761[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_761[] = {
    {"dist2", "number", 4, &kParams_761[0]},
    {"wrap", "number", 2, &kParams_761[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_762[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_762[] = {
    {"shake", "number", 2, &kParams_762[0]},
    {"follow", "number", 3, &kParams_762[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_763[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_763[] = {
    {"snapGrid", "number", 1, &kParams_763[0]},
    {"pointInRect", "bool", 6, &kParams_763[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_764[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_764[] = {
    {"aabbHit", "bool", 8, &kParams_764[0]},
    {"pointInRect", "bool", 6, &kParams_764[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_765[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_765[] = {
    {"aabbHit", "bool", 8, &kParams_765[0]},
    {"dist2", "number", 4, &kParams_765[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_766[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_766[] = {
    {"approach", "number", 3, &kParams_766[0]},
    {"follow", "number", 3, &kParams_766[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_767[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_767[] = {
    {"dist2", "number", 4, &kParams_767[0]},
    {"wrap", "number", 2, &kParams_767[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_768[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_768[] = {
    {"shake", "number", 2, &kParams_768[0]},
    {"follow", "number", 3, &kParams_768[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_769[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_769[] = {
    {"snapGrid", "number", 1, &kParams_769[0]},
    {"pointInRect", "bool", 6, &kParams_769[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_770[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_770[] = {
    {"aabbHit", "bool", 8, &kParams_770[0]},
    {"pointInRect", "bool", 6, &kParams_770[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_771[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_771[] = {
    {"aabbHit", "bool", 8, &kParams_771[0]},
    {"dist2", "number", 4, &kParams_771[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_772[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_772[] = {
    {"approach", "number", 3, &kParams_772[0]},
    {"follow", "number", 3, &kParams_772[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_773[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_773[] = {
    {"dist2", "number", 4, &kParams_773[0]},
    {"wrap", "number", 2, &kParams_773[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_774[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_774[] = {
    {"shake", "number", 2, &kParams_774[0]},
    {"follow", "number", 3, &kParams_774[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_775[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_775[] = {
    {"snapGrid", "number", 1, &kParams_775[0]},
    {"pointInRect", "bool", 6, &kParams_775[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_776[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_776[] = {
    {"aabbHit", "bool", 8, &kParams_776[0]},
    {"pointInRect", "bool", 6, &kParams_776[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_777[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_777[] = {
    {"aabbHit", "bool", 8, &kParams_777[0]},
    {"dist2", "number", 4, &kParams_777[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_778[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_778[] = {
    {"approach", "number", 3, &kParams_778[0]},
    {"follow", "number", 3, &kParams_778[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_779[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_779[] = {
    {"dist2", "number", 4, &kParams_779[0]},
    {"wrap", "number", 2, &kParams_779[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_780[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_780[] = {
    {"shake", "number", 2, &kParams_780[0]},
    {"follow", "number", 3, &kParams_780[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_781[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_781[] = {
    {"snapGrid", "number", 1, &kParams_781[0]},
    {"pointInRect", "bool", 6, &kParams_781[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_782[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_782[] = {
    {"aabbHit", "bool", 8, &kParams_782[0]},
    {"pointInRect", "bool", 6, &kParams_782[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_783[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_783[] = {
    {"aabbHit", "bool", 8, &kParams_783[0]},
    {"dist2", "number", 4, &kParams_783[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_784[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_784[] = {
    {"approach", "number", 3, &kParams_784[0]},
    {"follow", "number", 3, &kParams_784[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_785[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_785[] = {
    {"dist2", "number", 4, &kParams_785[0]},
    {"wrap", "number", 2, &kParams_785[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_786[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_786[] = {
    {"shake", "number", 2, &kParams_786[0]},
    {"follow", "number", 3, &kParams_786[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_787[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_787[] = {
    {"snapGrid", "number", 1, &kParams_787[0]},
    {"pointInRect", "bool", 6, &kParams_787[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_788[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_788[] = {
    {"aabbHit", "bool", 8, &kParams_788[0]},
    {"pointInRect", "bool", 6, &kParams_788[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_789[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_789[] = {
    {"aabbHit", "bool", 8, &kParams_789[0]},
    {"dist2", "number", 4, &kParams_789[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_790[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_790[] = {
    {"approach", "number", 3, &kParams_790[0]},
    {"follow", "number", 3, &kParams_790[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_791[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_791[] = {
    {"dist2", "number", 4, &kParams_791[0]},
    {"wrap", "number", 2, &kParams_791[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_792[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_792[] = {
    {"shake", "number", 2, &kParams_792[0]},
    {"follow", "number", 3, &kParams_792[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_793[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_793[] = {
    {"snapGrid", "number", 1, &kParams_793[0]},
    {"pointInRect", "bool", 6, &kParams_793[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_794[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_794[] = {
    {"aabbHit", "bool", 8, &kParams_794[0]},
    {"pointInRect", "bool", 6, &kParams_794[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_795[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_795[] = {
    {"aabbHit", "bool", 8, &kParams_795[0]},
    {"dist2", "number", 4, &kParams_795[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_796[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_796[] = {
    {"approach", "number", 3, &kParams_796[0]},
    {"follow", "number", 3, &kParams_796[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_797[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_797[] = {
    {"dist2", "number", 4, &kParams_797[0]},
    {"wrap", "number", 2, &kParams_797[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_798[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_798[] = {
    {"shake", "number", 2, &kParams_798[0]},
    {"follow", "number", 3, &kParams_798[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_799[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_799[] = {
    {"snapGrid", "number", 1, &kParams_799[0]},
    {"pointInRect", "bool", 6, &kParams_799[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_800[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_800[] = {
    {"aabbHit", "bool", 8, &kParams_800[0]},
    {"pointInRect", "bool", 6, &kParams_800[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_801[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_801[] = {
    {"aabbHit", "bool", 8, &kParams_801[0]},
    {"dist2", "number", 4, &kParams_801[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_802[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_802[] = {
    {"approach", "number", 3, &kParams_802[0]},
    {"follow", "number", 3, &kParams_802[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_803[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_803[] = {
    {"dist2", "number", 4, &kParams_803[0]},
    {"wrap", "number", 2, &kParams_803[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_804[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_804[] = {
    {"shake", "number", 2, &kParams_804[0]},
    {"follow", "number", 3, &kParams_804[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_805[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_805[] = {
    {"snapGrid", "number", 1, &kParams_805[0]},
    {"pointInRect", "bool", 6, &kParams_805[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_806[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_806[] = {
    {"aabbHit", "bool", 8, &kParams_806[0]},
    {"pointInRect", "bool", 6, &kParams_806[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_807[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_807[] = {
    {"aabbHit", "bool", 8, &kParams_807[0]},
    {"dist2", "number", 4, &kParams_807[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_808[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_808[] = {
    {"approach", "number", 3, &kParams_808[0]},
    {"follow", "number", 3, &kParams_808[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_809[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_809[] = {
    {"dist2", "number", 4, &kParams_809[0]},
    {"wrap", "number", 2, &kParams_809[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_810[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_810[] = {
    {"shake", "number", 2, &kParams_810[0]},
    {"follow", "number", 3, &kParams_810[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_811[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_811[] = {
    {"snapGrid", "number", 1, &kParams_811[0]},
    {"pointInRect", "bool", 6, &kParams_811[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_812[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_812[] = {
    {"aabbHit", "bool", 8, &kParams_812[0]},
    {"pointInRect", "bool", 6, &kParams_812[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_813[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_813[] = {
    {"aabbHit", "bool", 8, &kParams_813[0]},
    {"dist2", "number", 4, &kParams_813[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_814[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_814[] = {
    {"approach", "number", 3, &kParams_814[0]},
    {"follow", "number", 3, &kParams_814[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_815[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_815[] = {
    {"dist2", "number", 4, &kParams_815[0]},
    {"wrap", "number", 2, &kParams_815[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_816[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_816[] = {
    {"shake", "number", 2, &kParams_816[0]},
    {"follow", "number", 3, &kParams_816[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_817[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_817[] = {
    {"snapGrid", "number", 1, &kParams_817[0]},
    {"pointInRect", "bool", 6, &kParams_817[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_818[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_818[] = {
    {"aabbHit", "bool", 8, &kParams_818[0]},
    {"pointInRect", "bool", 6, &kParams_818[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_819[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_819[] = {
    {"aabbHit", "bool", 8, &kParams_819[0]},
    {"dist2", "number", 4, &kParams_819[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_820[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_820[] = {
    {"approach", "number", 3, &kParams_820[0]},
    {"follow", "number", 3, &kParams_820[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_821[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_821[] = {
    {"dist2", "number", 4, &kParams_821[0]},
    {"wrap", "number", 2, &kParams_821[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_822[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_822[] = {
    {"shake", "number", 2, &kParams_822[0]},
    {"follow", "number", 3, &kParams_822[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_823[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_823[] = {
    {"snapGrid", "number", 1, &kParams_823[0]},
    {"pointInRect", "bool", 6, &kParams_823[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_824[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_824[] = {
    {"aabbHit", "bool", 8, &kParams_824[0]},
    {"pointInRect", "bool", 6, &kParams_824[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_825[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_825[] = {
    {"aabbHit", "bool", 8, &kParams_825[0]},
    {"dist2", "number", 4, &kParams_825[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_826[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_826[] = {
    {"approach", "number", 3, &kParams_826[0]},
    {"follow", "number", 3, &kParams_826[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_827[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_827[] = {
    {"dist2", "number", 4, &kParams_827[0]},
    {"wrap", "number", 2, &kParams_827[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_828[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_828[] = {
    {"shake", "number", 2, &kParams_828[0]},
    {"follow", "number", 3, &kParams_828[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_829[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_829[] = {
    {"snapGrid", "number", 1, &kParams_829[0]},
    {"pointInRect", "bool", 6, &kParams_829[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_830[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_830[] = {
    {"aabbHit", "bool", 8, &kParams_830[0]},
    {"pointInRect", "bool", 6, &kParams_830[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_831[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_831[] = {
    {"aabbHit", "bool", 8, &kParams_831[0]},
    {"dist2", "number", 4, &kParams_831[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_832[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_832[] = {
    {"approach", "number", 3, &kParams_832[0]},
    {"follow", "number", 3, &kParams_832[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_833[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_833[] = {
    {"dist2", "number", 4, &kParams_833[0]},
    {"wrap", "number", 2, &kParams_833[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_834[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_834[] = {
    {"shake", "number", 2, &kParams_834[0]},
    {"follow", "number", 3, &kParams_834[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_835[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_835[] = {
    {"snapGrid", "number", 1, &kParams_835[0]},
    {"pointInRect", "bool", 6, &kParams_835[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_836[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_836[] = {
    {"aabbHit", "bool", 8, &kParams_836[0]},
    {"pointInRect", "bool", 6, &kParams_836[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_837[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_837[] = {
    {"aabbHit", "bool", 8, &kParams_837[0]},
    {"dist2", "number", 4, &kParams_837[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_838[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_838[] = {
    {"approach", "number", 3, &kParams_838[0]},
    {"follow", "number", 3, &kParams_838[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_839[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_839[] = {
    {"dist2", "number", 4, &kParams_839[0]},
    {"wrap", "number", 2, &kParams_839[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_840[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_840[] = {
    {"shake", "number", 2, &kParams_840[0]},
    {"follow", "number", 3, &kParams_840[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_841[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_841[] = {
    {"snapGrid", "number", 1, &kParams_841[0]},
    {"pointInRect", "bool", 6, &kParams_841[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_842[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_842[] = {
    {"aabbHit", "bool", 8, &kParams_842[0]},
    {"pointInRect", "bool", 6, &kParams_842[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_843[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_843[] = {
    {"aabbHit", "bool", 8, &kParams_843[0]},
    {"dist2", "number", 4, &kParams_843[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_844[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_844[] = {
    {"approach", "number", 3, &kParams_844[0]},
    {"follow", "number", 3, &kParams_844[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_845[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_845[] = {
    {"dist2", "number", 4, &kParams_845[0]},
    {"wrap", "number", 2, &kParams_845[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_846[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_846[] = {
    {"shake", "number", 2, &kParams_846[0]},
    {"follow", "number", 3, &kParams_846[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_847[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_847[] = {
    {"snapGrid", "number", 1, &kParams_847[0]},
    {"pointInRect", "bool", 6, &kParams_847[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_848[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_848[] = {
    {"aabbHit", "bool", 8, &kParams_848[0]},
    {"pointInRect", "bool", 6, &kParams_848[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_849[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_849[] = {
    {"aabbHit", "bool", 8, &kParams_849[0]},
    {"dist2", "number", 4, &kParams_849[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_850[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_850[] = {
    {"approach", "number", 3, &kParams_850[0]},
    {"follow", "number", 3, &kParams_850[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_851[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_851[] = {
    {"dist2", "number", 4, &kParams_851[0]},
    {"wrap", "number", 2, &kParams_851[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_852[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_852[] = {
    {"shake", "number", 2, &kParams_852[0]},
    {"follow", "number", 3, &kParams_852[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_853[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_853[] = {
    {"snapGrid", "number", 1, &kParams_853[0]},
    {"pointInRect", "bool", 6, &kParams_853[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_854[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_854[] = {
    {"aabbHit", "bool", 8, &kParams_854[0]},
    {"pointInRect", "bool", 6, &kParams_854[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_855[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_855[] = {
    {"aabbHit", "bool", 8, &kParams_855[0]},
    {"dist2", "number", 4, &kParams_855[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_856[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_856[] = {
    {"approach", "number", 3, &kParams_856[0]},
    {"follow", "number", 3, &kParams_856[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_857[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_857[] = {
    {"dist2", "number", 4, &kParams_857[0]},
    {"wrap", "number", 2, &kParams_857[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_858[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_858[] = {
    {"shake", "number", 2, &kParams_858[0]},
    {"follow", "number", 3, &kParams_858[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_859[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_859[] = {
    {"snapGrid", "number", 1, &kParams_859[0]},
    {"pointInRect", "bool", 6, &kParams_859[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_860[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_860[] = {
    {"aabbHit", "bool", 8, &kParams_860[0]},
    {"pointInRect", "bool", 6, &kParams_860[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_861[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_861[] = {
    {"aabbHit", "bool", 8, &kParams_861[0]},
    {"dist2", "number", 4, &kParams_861[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_862[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_862[] = {
    {"approach", "number", 3, &kParams_862[0]},
    {"follow", "number", 3, &kParams_862[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_863[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_863[] = {
    {"dist2", "number", 4, &kParams_863[0]},
    {"wrap", "number", 2, &kParams_863[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_864[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_864[] = {
    {"shake", "number", 2, &kParams_864[0]},
    {"follow", "number", 3, &kParams_864[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_865[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_865[] = {
    {"snapGrid", "number", 1, &kParams_865[0]},
    {"pointInRect", "bool", 6, &kParams_865[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_866[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_866[] = {
    {"aabbHit", "bool", 8, &kParams_866[0]},
    {"pointInRect", "bool", 6, &kParams_866[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_867[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_867[] = {
    {"aabbHit", "bool", 8, &kParams_867[0]},
    {"dist2", "number", 4, &kParams_867[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_868[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_868[] = {
    {"approach", "number", 3, &kParams_868[0]},
    {"follow", "number", 3, &kParams_868[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_869[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_869[] = {
    {"dist2", "number", 4, &kParams_869[0]},
    {"wrap", "number", 2, &kParams_869[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_870[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_870[] = {
    {"shake", "number", 2, &kParams_870[0]},
    {"follow", "number", 3, &kParams_870[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_871[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_871[] = {
    {"snapGrid", "number", 1, &kParams_871[0]},
    {"pointInRect", "bool", 6, &kParams_871[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_872[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_872[] = {
    {"aabbHit", "bool", 8, &kParams_872[0]},
    {"pointInRect", "bool", 6, &kParams_872[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_873[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_873[] = {
    {"aabbHit", "bool", 8, &kParams_873[0]},
    {"dist2", "number", 4, &kParams_873[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_874[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_874[] = {
    {"approach", "number", 3, &kParams_874[0]},
    {"follow", "number", 3, &kParams_874[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_875[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_875[] = {
    {"dist2", "number", 4, &kParams_875[0]},
    {"wrap", "number", 2, &kParams_875[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_876[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_876[] = {
    {"shake", "number", 2, &kParams_876[0]},
    {"follow", "number", 3, &kParams_876[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_877[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_877[] = {
    {"snapGrid", "number", 1, &kParams_877[0]},
    {"pointInRect", "bool", 6, &kParams_877[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_878[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_878[] = {
    {"aabbHit", "bool", 8, &kParams_878[0]},
    {"pointInRect", "bool", 6, &kParams_878[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_879[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_879[] = {
    {"aabbHit", "bool", 8, &kParams_879[0]},
    {"dist2", "number", 4, &kParams_879[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_880[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_880[] = {
    {"approach", "number", 3, &kParams_880[0]},
    {"follow", "number", 3, &kParams_880[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_881[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_881[] = {
    {"dist2", "number", 4, &kParams_881[0]},
    {"wrap", "number", 2, &kParams_881[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_882[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_882[] = {
    {"shake", "number", 2, &kParams_882[0]},
    {"follow", "number", 3, &kParams_882[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_883[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_883[] = {
    {"snapGrid", "number", 1, &kParams_883[0]},
    {"pointInRect", "bool", 6, &kParams_883[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_884[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_884[] = {
    {"aabbHit", "bool", 8, &kParams_884[0]},
    {"pointInRect", "bool", 6, &kParams_884[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_885[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_885[] = {
    {"aabbHit", "bool", 8, &kParams_885[0]},
    {"dist2", "number", 4, &kParams_885[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_886[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_886[] = {
    {"approach", "number", 3, &kParams_886[0]},
    {"follow", "number", 3, &kParams_886[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_887[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_887[] = {
    {"dist2", "number", 4, &kParams_887[0]},
    {"wrap", "number", 2, &kParams_887[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_888[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_888[] = {
    {"shake", "number", 2, &kParams_888[0]},
    {"follow", "number", 3, &kParams_888[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_889[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_889[] = {
    {"snapGrid", "number", 1, &kParams_889[0]},
    {"pointInRect", "bool", 6, &kParams_889[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_890[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_890[] = {
    {"aabbHit", "bool", 8, &kParams_890[0]},
    {"pointInRect", "bool", 6, &kParams_890[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_891[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_891[] = {
    {"aabbHit", "bool", 8, &kParams_891[0]},
    {"dist2", "number", 4, &kParams_891[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_892[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_892[] = {
    {"approach", "number", 3, &kParams_892[0]},
    {"follow", "number", 3, &kParams_892[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_893[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_893[] = {
    {"dist2", "number", 4, &kParams_893[0]},
    {"wrap", "number", 2, &kParams_893[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_894[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_894[] = {
    {"shake", "number", 2, &kParams_894[0]},
    {"follow", "number", 3, &kParams_894[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_895[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_895[] = {
    {"snapGrid", "number", 1, &kParams_895[0]},
    {"pointInRect", "bool", 6, &kParams_895[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_896[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_896[] = {
    {"aabbHit", "bool", 8, &kParams_896[0]},
    {"pointInRect", "bool", 6, &kParams_896[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_897[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_897[] = {
    {"aabbHit", "bool", 8, &kParams_897[0]},
    {"dist2", "number", 4, &kParams_897[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_898[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_898[] = {
    {"approach", "number", 3, &kParams_898[0]},
    {"follow", "number", 3, &kParams_898[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_899[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_899[] = {
    {"dist2", "number", 4, &kParams_899[0]},
    {"wrap", "number", 2, &kParams_899[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_900[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_900[] = {
    {"shake", "number", 2, &kParams_900[0]},
    {"follow", "number", 3, &kParams_900[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_901[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_901[] = {
    {"snapGrid", "number", 1, &kParams_901[0]},
    {"pointInRect", "bool", 6, &kParams_901[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_902[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_902[] = {
    {"aabbHit", "bool", 8, &kParams_902[0]},
    {"pointInRect", "bool", 6, &kParams_902[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_903[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_903[] = {
    {"aabbHit", "bool", 8, &kParams_903[0]},
    {"dist2", "number", 4, &kParams_903[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_904[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_904[] = {
    {"approach", "number", 3, &kParams_904[0]},
    {"follow", "number", 3, &kParams_904[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_905[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_905[] = {
    {"dist2", "number", 4, &kParams_905[0]},
    {"wrap", "number", 2, &kParams_905[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_906[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_906[] = {
    {"shake", "number", 2, &kParams_906[0]},
    {"follow", "number", 3, &kParams_906[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_907[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_907[] = {
    {"snapGrid", "number", 1, &kParams_907[0]},
    {"pointInRect", "bool", 6, &kParams_907[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_908[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_908[] = {
    {"aabbHit", "bool", 8, &kParams_908[0]},
    {"pointInRect", "bool", 6, &kParams_908[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_909[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_909[] = {
    {"aabbHit", "bool", 8, &kParams_909[0]},
    {"dist2", "number", 4, &kParams_909[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_910[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_910[] = {
    {"approach", "number", 3, &kParams_910[0]},
    {"follow", "number", 3, &kParams_910[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_911[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_911[] = {
    {"dist2", "number", 4, &kParams_911[0]},
    {"wrap", "number", 2, &kParams_911[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_912[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_912[] = {
    {"shake", "number", 2, &kParams_912[0]},
    {"follow", "number", 3, &kParams_912[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_913[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_913[] = {
    {"snapGrid", "number", 1, &kParams_913[0]},
    {"pointInRect", "bool", 6, &kParams_913[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_914[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_914[] = {
    {"aabbHit", "bool", 8, &kParams_914[0]},
    {"pointInRect", "bool", 6, &kParams_914[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_915[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_915[] = {
    {"aabbHit", "bool", 8, &kParams_915[0]},
    {"dist2", "number", 4, &kParams_915[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_916[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_916[] = {
    {"approach", "number", 3, &kParams_916[0]},
    {"follow", "number", 3, &kParams_916[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_917[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_917[] = {
    {"dist2", "number", 4, &kParams_917[0]},
    {"wrap", "number", 2, &kParams_917[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_918[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_918[] = {
    {"shake", "number", 2, &kParams_918[0]},
    {"follow", "number", 3, &kParams_918[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_919[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_919[] = {
    {"snapGrid", "number", 1, &kParams_919[0]},
    {"pointInRect", "bool", 6, &kParams_919[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_920[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_920[] = {
    {"aabbHit", "bool", 8, &kParams_920[0]},
    {"pointInRect", "bool", 6, &kParams_920[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_921[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_921[] = {
    {"aabbHit", "bool", 8, &kParams_921[0]},
    {"dist2", "number", 4, &kParams_921[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_922[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_922[] = {
    {"approach", "number", 3, &kParams_922[0]},
    {"follow", "number", 3, &kParams_922[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_923[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_923[] = {
    {"dist2", "number", 4, &kParams_923[0]},
    {"wrap", "number", 2, &kParams_923[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_924[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_924[] = {
    {"shake", "number", 2, &kParams_924[0]},
    {"follow", "number", 3, &kParams_924[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_925[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_925[] = {
    {"snapGrid", "number", 1, &kParams_925[0]},
    {"pointInRect", "bool", 6, &kParams_925[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_926[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_926[] = {
    {"aabbHit", "bool", 8, &kParams_926[0]},
    {"pointInRect", "bool", 6, &kParams_926[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_927[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_927[] = {
    {"aabbHit", "bool", 8, &kParams_927[0]},
    {"dist2", "number", 4, &kParams_927[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_928[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_928[] = {
    {"approach", "number", 3, &kParams_928[0]},
    {"follow", "number", 3, &kParams_928[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_929[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_929[] = {
    {"dist2", "number", 4, &kParams_929[0]},
    {"wrap", "number", 2, &kParams_929[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_930[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_930[] = {
    {"shake", "number", 2, &kParams_930[0]},
    {"follow", "number", 3, &kParams_930[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_931[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_931[] = {
    {"snapGrid", "number", 1, &kParams_931[0]},
    {"pointInRect", "bool", 6, &kParams_931[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_932[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_932[] = {
    {"aabbHit", "bool", 8, &kParams_932[0]},
    {"pointInRect", "bool", 6, &kParams_932[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_933[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_933[] = {
    {"aabbHit", "bool", 8, &kParams_933[0]},
    {"dist2", "number", 4, &kParams_933[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_934[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_934[] = {
    {"approach", "number", 3, &kParams_934[0]},
    {"follow", "number", 3, &kParams_934[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_935[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_935[] = {
    {"dist2", "number", 4, &kParams_935[0]},
    {"wrap", "number", 2, &kParams_935[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_936[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_936[] = {
    {"shake", "number", 2, &kParams_936[0]},
    {"follow", "number", 3, &kParams_936[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_937[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_937[] = {
    {"snapGrid", "number", 1, &kParams_937[0]},
    {"pointInRect", "bool", 6, &kParams_937[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_938[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_938[] = {
    {"aabbHit", "bool", 8, &kParams_938[0]},
    {"pointInRect", "bool", 6, &kParams_938[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_939[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_939[] = {
    {"aabbHit", "bool", 8, &kParams_939[0]},
    {"dist2", "number", 4, &kParams_939[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_940[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_940[] = {
    {"approach", "number", 3, &kParams_940[0]},
    {"follow", "number", 3, &kParams_940[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_941[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_941[] = {
    {"dist2", "number", 4, &kParams_941[0]},
    {"wrap", "number", 2, &kParams_941[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_942[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_942[] = {
    {"shake", "number", 2, &kParams_942[0]},
    {"follow", "number", 3, &kParams_942[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_943[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_943[] = {
    {"snapGrid", "number", 1, &kParams_943[0]},
    {"pointInRect", "bool", 6, &kParams_943[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_944[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_944[] = {
    {"aabbHit", "bool", 8, &kParams_944[0]},
    {"pointInRect", "bool", 6, &kParams_944[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_945[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_945[] = {
    {"aabbHit", "bool", 8, &kParams_945[0]},
    {"dist2", "number", 4, &kParams_945[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_946[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_946[] = {
    {"approach", "number", 3, &kParams_946[0]},
    {"follow", "number", 3, &kParams_946[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_947[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_947[] = {
    {"dist2", "number", 4, &kParams_947[0]},
    {"wrap", "number", 2, &kParams_947[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_948[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_948[] = {
    {"shake", "number", 2, &kParams_948[0]},
    {"follow", "number", 3, &kParams_948[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_949[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_949[] = {
    {"snapGrid", "number", 1, &kParams_949[0]},
    {"pointInRect", "bool", 6, &kParams_949[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_950[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_950[] = {
    {"aabbHit", "bool", 8, &kParams_950[0]},
    {"pointInRect", "bool", 6, &kParams_950[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_951[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_951[] = {
    {"aabbHit", "bool", 8, &kParams_951[0]},
    {"dist2", "number", 4, &kParams_951[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_952[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_952[] = {
    {"approach", "number", 3, &kParams_952[0]},
    {"follow", "number", 3, &kParams_952[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_953[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_953[] = {
    {"dist2", "number", 4, &kParams_953[0]},
    {"wrap", "number", 2, &kParams_953[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_954[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_954[] = {
    {"shake", "number", 2, &kParams_954[0]},
    {"follow", "number", 3, &kParams_954[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_955[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_955[] = {
    {"snapGrid", "number", 1, &kParams_955[0]},
    {"pointInRect", "bool", 6, &kParams_955[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_956[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_956[] = {
    {"aabbHit", "bool", 8, &kParams_956[0]},
    {"pointInRect", "bool", 6, &kParams_956[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_957[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_957[] = {
    {"aabbHit", "bool", 8, &kParams_957[0]},
    {"dist2", "number", 4, &kParams_957[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_958[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_958[] = {
    {"approach", "number", 3, &kParams_958[0]},
    {"follow", "number", 3, &kParams_958[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_959[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_959[] = {
    {"dist2", "number", 4, &kParams_959[0]},
    {"wrap", "number", 2, &kParams_959[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_960[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_960[] = {
    {"shake", "number", 2, &kParams_960[0]},
    {"follow", "number", 3, &kParams_960[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_961[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_961[] = {
    {"snapGrid", "number", 1, &kParams_961[0]},
    {"pointInRect", "bool", 6, &kParams_961[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_962[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_962[] = {
    {"aabbHit", "bool", 8, &kParams_962[0]},
    {"pointInRect", "bool", 6, &kParams_962[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_963[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_963[] = {
    {"aabbHit", "bool", 8, &kParams_963[0]},
    {"dist2", "number", 4, &kParams_963[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_964[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_964[] = {
    {"approach", "number", 3, &kParams_964[0]},
    {"follow", "number", 3, &kParams_964[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_965[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_965[] = {
    {"dist2", "number", 4, &kParams_965[0]},
    {"wrap", "number", 2, &kParams_965[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_966[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_966[] = {
    {"shake", "number", 2, &kParams_966[0]},
    {"follow", "number", 3, &kParams_966[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_967[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_967[] = {
    {"snapGrid", "number", 1, &kParams_967[0]},
    {"pointInRect", "bool", 6, &kParams_967[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_968[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_968[] = {
    {"aabbHit", "bool", 8, &kParams_968[0]},
    {"pointInRect", "bool", 6, &kParams_968[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_969[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_969[] = {
    {"aabbHit", "bool", 8, &kParams_969[0]},
    {"dist2", "number", 4, &kParams_969[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_970[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_970[] = {
    {"approach", "number", 3, &kParams_970[0]},
    {"follow", "number", 3, &kParams_970[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_971[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_971[] = {
    {"dist2", "number", 4, &kParams_971[0]},
    {"wrap", "number", 2, &kParams_971[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_972[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_972[] = {
    {"shake", "number", 2, &kParams_972[0]},
    {"follow", "number", 3, &kParams_972[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_973[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_973[] = {
    {"snapGrid", "number", 1, &kParams_973[0]},
    {"pointInRect", "bool", 6, &kParams_973[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_974[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_974[] = {
    {"aabbHit", "bool", 8, &kParams_974[0]},
    {"pointInRect", "bool", 6, &kParams_974[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_975[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_975[] = {
    {"aabbHit", "bool", 8, &kParams_975[0]},
    {"dist2", "number", 4, &kParams_975[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_976[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_976[] = {
    {"approach", "number", 3, &kParams_976[0]},
    {"follow", "number", 3, &kParams_976[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_977[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_977[] = {
    {"dist2", "number", 4, &kParams_977[0]},
    {"wrap", "number", 2, &kParams_977[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_978[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_978[] = {
    {"shake", "number", 2, &kParams_978[0]},
    {"follow", "number", 3, &kParams_978[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_979[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_979[] = {
    {"snapGrid", "number", 1, &kParams_979[0]},
    {"pointInRect", "bool", 6, &kParams_979[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_980[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_980[] = {
    {"aabbHit", "bool", 8, &kParams_980[0]},
    {"pointInRect", "bool", 6, &kParams_980[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_981[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_981[] = {
    {"aabbHit", "bool", 8, &kParams_981[0]},
    {"dist2", "number", 4, &kParams_981[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_982[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_982[] = {
    {"approach", "number", 3, &kParams_982[0]},
    {"follow", "number", 3, &kParams_982[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_983[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_983[] = {
    {"dist2", "number", 4, &kParams_983[0]},
    {"wrap", "number", 2, &kParams_983[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_984[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_984[] = {
    {"shake", "number", 2, &kParams_984[0]},
    {"follow", "number", 3, &kParams_984[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_985[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_985[] = {
    {"snapGrid", "number", 1, &kParams_985[0]},
    {"pointInRect", "bool", 6, &kParams_985[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_986[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_986[] = {
    {"aabbHit", "bool", 8, &kParams_986[0]},
    {"pointInRect", "bool", 6, &kParams_986[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_987[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_987[] = {
    {"aabbHit", "bool", 8, &kParams_987[0]},
    {"dist2", "number", 4, &kParams_987[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_988[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_988[] = {
    {"approach", "number", 3, &kParams_988[0]},
    {"follow", "number", 3, &kParams_988[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_989[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_989[] = {
    {"dist2", "number", 4, &kParams_989[0]},
    {"wrap", "number", 2, &kParams_989[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_990[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_990[] = {
    {"shake", "number", 2, &kParams_990[0]},
    {"follow", "number", 3, &kParams_990[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_991[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_991[] = {
    {"snapGrid", "number", 1, &kParams_991[0]},
    {"pointInRect", "bool", 6, &kParams_991[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_992[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_992[] = {
    {"aabbHit", "bool", 8, &kParams_992[0]},
    {"pointInRect", "bool", 6, &kParams_992[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_993[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_993[] = {
    {"aabbHit", "bool", 8, &kParams_993[0]},
    {"dist2", "number", 4, &kParams_993[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_994[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_994[] = {
    {"approach", "number", 3, &kParams_994[0]},
    {"follow", "number", 3, &kParams_994[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_995[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_995[] = {
    {"dist2", "number", 4, &kParams_995[0]},
    {"wrap", "number", 2, &kParams_995[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_996[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_996[] = {
    {"shake", "number", 2, &kParams_996[0]},
    {"follow", "number", 3, &kParams_996[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_997[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_997[] = {
    {"snapGrid", "number", 1, &kParams_997[0]},
    {"pointInRect", "bool", 6, &kParams_997[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_998[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_998[] = {
    {"aabbHit", "bool", 8, &kParams_998[0]},
    {"pointInRect", "bool", 6, &kParams_998[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_999[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_999[] = {
    {"aabbHit", "bool", 8, &kParams_999[0]},
    {"dist2", "number", 4, &kParams_999[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1000[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1000[] = {
    {"approach", "number", 3, &kParams_1000[0]},
    {"follow", "number", 3, &kParams_1000[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1001[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1001[] = {
    {"dist2", "number", 4, &kParams_1001[0]},
    {"wrap", "number", 2, &kParams_1001[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1002[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1002[] = {
    {"shake", "number", 2, &kParams_1002[0]},
    {"follow", "number", 3, &kParams_1002[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1003[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1003[] = {
    {"snapGrid", "number", 1, &kParams_1003[0]},
    {"pointInRect", "bool", 6, &kParams_1003[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1004[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1004[] = {
    {"aabbHit", "bool", 8, &kParams_1004[0]},
    {"pointInRect", "bool", 6, &kParams_1004[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1005[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1005[] = {
    {"aabbHit", "bool", 8, &kParams_1005[0]},
    {"dist2", "number", 4, &kParams_1005[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1006[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1006[] = {
    {"approach", "number", 3, &kParams_1006[0]},
    {"follow", "number", 3, &kParams_1006[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1007[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1007[] = {
    {"dist2", "number", 4, &kParams_1007[0]},
    {"wrap", "number", 2, &kParams_1007[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1008[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1008[] = {
    {"shake", "number", 2, &kParams_1008[0]},
    {"follow", "number", 3, &kParams_1008[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1009[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1009[] = {
    {"snapGrid", "number", 1, &kParams_1009[0]},
    {"pointInRect", "bool", 6, &kParams_1009[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1010[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1010[] = {
    {"aabbHit", "bool", 8, &kParams_1010[0]},
    {"pointInRect", "bool", 6, &kParams_1010[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1011[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1011[] = {
    {"aabbHit", "bool", 8, &kParams_1011[0]},
    {"dist2", "number", 4, &kParams_1011[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1012[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1012[] = {
    {"approach", "number", 3, &kParams_1012[0]},
    {"follow", "number", 3, &kParams_1012[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1013[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1013[] = {
    {"dist2", "number", 4, &kParams_1013[0]},
    {"wrap", "number", 2, &kParams_1013[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1014[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1014[] = {
    {"shake", "number", 2, &kParams_1014[0]},
    {"follow", "number", 3, &kParams_1014[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1015[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1015[] = {
    {"snapGrid", "number", 1, &kParams_1015[0]},
    {"pointInRect", "bool", 6, &kParams_1015[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1016[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1016[] = {
    {"aabbHit", "bool", 8, &kParams_1016[0]},
    {"pointInRect", "bool", 6, &kParams_1016[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1017[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1017[] = {
    {"aabbHit", "bool", 8, &kParams_1017[0]},
    {"dist2", "number", 4, &kParams_1017[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1018[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1018[] = {
    {"approach", "number", 3, &kParams_1018[0]},
    {"follow", "number", 3, &kParams_1018[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1019[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1019[] = {
    {"dist2", "number", 4, &kParams_1019[0]},
    {"wrap", "number", 2, &kParams_1019[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1020[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1020[] = {
    {"shake", "number", 2, &kParams_1020[0]},
    {"follow", "number", 3, &kParams_1020[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1021[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1021[] = {
    {"snapGrid", "number", 1, &kParams_1021[0]},
    {"pointInRect", "bool", 6, &kParams_1021[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1022[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1022[] = {
    {"aabbHit", "bool", 8, &kParams_1022[0]},
    {"pointInRect", "bool", 6, &kParams_1022[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1023[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1023[] = {
    {"aabbHit", "bool", 8, &kParams_1023[0]},
    {"dist2", "number", 4, &kParams_1023[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1024[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1024[] = {
    {"approach", "number", 3, &kParams_1024[0]},
    {"follow", "number", 3, &kParams_1024[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1025[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1025[] = {
    {"dist2", "number", 4, &kParams_1025[0]},
    {"wrap", "number", 2, &kParams_1025[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1026[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1026[] = {
    {"shake", "number", 2, &kParams_1026[0]},
    {"follow", "number", 3, &kParams_1026[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1027[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1027[] = {
    {"snapGrid", "number", 1, &kParams_1027[0]},
    {"pointInRect", "bool", 6, &kParams_1027[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1028[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1028[] = {
    {"aabbHit", "bool", 8, &kParams_1028[0]},
    {"pointInRect", "bool", 6, &kParams_1028[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1029[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1029[] = {
    {"aabbHit", "bool", 8, &kParams_1029[0]},
    {"dist2", "number", 4, &kParams_1029[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1030[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1030[] = {
    {"approach", "number", 3, &kParams_1030[0]},
    {"follow", "number", 3, &kParams_1030[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1031[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1031[] = {
    {"dist2", "number", 4, &kParams_1031[0]},
    {"wrap", "number", 2, &kParams_1031[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1032[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1032[] = {
    {"shake", "number", 2, &kParams_1032[0]},
    {"follow", "number", 3, &kParams_1032[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1033[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1033[] = {
    {"snapGrid", "number", 1, &kParams_1033[0]},
    {"pointInRect", "bool", 6, &kParams_1033[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1034[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1034[] = {
    {"aabbHit", "bool", 8, &kParams_1034[0]},
    {"pointInRect", "bool", 6, &kParams_1034[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1035[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1035[] = {
    {"aabbHit", "bool", 8, &kParams_1035[0]},
    {"dist2", "number", 4, &kParams_1035[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1036[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1036[] = {
    {"approach", "number", 3, &kParams_1036[0]},
    {"follow", "number", 3, &kParams_1036[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1037[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1037[] = {
    {"dist2", "number", 4, &kParams_1037[0]},
    {"wrap", "number", 2, &kParams_1037[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1038[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1038[] = {
    {"shake", "number", 2, &kParams_1038[0]},
    {"follow", "number", 3, &kParams_1038[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1039[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1039[] = {
    {"snapGrid", "number", 1, &kParams_1039[0]},
    {"pointInRect", "bool", 6, &kParams_1039[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1040[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1040[] = {
    {"aabbHit", "bool", 8, &kParams_1040[0]},
    {"pointInRect", "bool", 6, &kParams_1040[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1041[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1041[] = {
    {"aabbHit", "bool", 8, &kParams_1041[0]},
    {"dist2", "number", 4, &kParams_1041[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1042[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1042[] = {
    {"approach", "number", 3, &kParams_1042[0]},
    {"follow", "number", 3, &kParams_1042[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1043[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1043[] = {
    {"dist2", "number", 4, &kParams_1043[0]},
    {"wrap", "number", 2, &kParams_1043[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1044[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1044[] = {
    {"shake", "number", 2, &kParams_1044[0]},
    {"follow", "number", 3, &kParams_1044[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1045[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1045[] = {
    {"snapGrid", "number", 1, &kParams_1045[0]},
    {"pointInRect", "bool", 6, &kParams_1045[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1046[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1046[] = {
    {"aabbHit", "bool", 8, &kParams_1046[0]},
    {"pointInRect", "bool", 6, &kParams_1046[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1047[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1047[] = {
    {"aabbHit", "bool", 8, &kParams_1047[0]},
    {"dist2", "number", 4, &kParams_1047[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1048[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1048[] = {
    {"approach", "number", 3, &kParams_1048[0]},
    {"follow", "number", 3, &kParams_1048[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1049[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1049[] = {
    {"dist2", "number", 4, &kParams_1049[0]},
    {"wrap", "number", 2, &kParams_1049[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1050[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1050[] = {
    {"shake", "number", 2, &kParams_1050[0]},
    {"follow", "number", 3, &kParams_1050[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1051[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1051[] = {
    {"snapGrid", "number", 1, &kParams_1051[0]},
    {"pointInRect", "bool", 6, &kParams_1051[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1052[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1052[] = {
    {"aabbHit", "bool", 8, &kParams_1052[0]},
    {"pointInRect", "bool", 6, &kParams_1052[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1053[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1053[] = {
    {"aabbHit", "bool", 8, &kParams_1053[0]},
    {"dist2", "number", 4, &kParams_1053[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1054[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1054[] = {
    {"approach", "number", 3, &kParams_1054[0]},
    {"follow", "number", 3, &kParams_1054[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1055[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1055[] = {
    {"dist2", "number", 4, &kParams_1055[0]},
    {"wrap", "number", 2, &kParams_1055[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1056[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1056[] = {
    {"shake", "number", 2, &kParams_1056[0]},
    {"follow", "number", 3, &kParams_1056[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1057[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1057[] = {
    {"snapGrid", "number", 1, &kParams_1057[0]},
    {"pointInRect", "bool", 6, &kParams_1057[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1058[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1058[] = {
    {"aabbHit", "bool", 8, &kParams_1058[0]},
    {"pointInRect", "bool", 6, &kParams_1058[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1059[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1059[] = {
    {"aabbHit", "bool", 8, &kParams_1059[0]},
    {"dist2", "number", 4, &kParams_1059[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1060[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1060[] = {
    {"approach", "number", 3, &kParams_1060[0]},
    {"follow", "number", 3, &kParams_1060[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1061[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1061[] = {
    {"dist2", "number", 4, &kParams_1061[0]},
    {"wrap", "number", 2, &kParams_1061[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1062[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1062[] = {
    {"shake", "number", 2, &kParams_1062[0]},
    {"follow", "number", 3, &kParams_1062[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1063[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1063[] = {
    {"snapGrid", "number", 1, &kParams_1063[0]},
    {"pointInRect", "bool", 6, &kParams_1063[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1064[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1064[] = {
    {"aabbHit", "bool", 8, &kParams_1064[0]},
    {"pointInRect", "bool", 6, &kParams_1064[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1065[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1065[] = {
    {"aabbHit", "bool", 8, &kParams_1065[0]},
    {"dist2", "number", 4, &kParams_1065[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1066[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1066[] = {
    {"approach", "number", 3, &kParams_1066[0]},
    {"follow", "number", 3, &kParams_1066[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1067[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1067[] = {
    {"dist2", "number", 4, &kParams_1067[0]},
    {"wrap", "number", 2, &kParams_1067[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1068[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1068[] = {
    {"shake", "number", 2, &kParams_1068[0]},
    {"follow", "number", 3, &kParams_1068[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1069[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1069[] = {
    {"snapGrid", "number", 1, &kParams_1069[0]},
    {"pointInRect", "bool", 6, &kParams_1069[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1070[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1070[] = {
    {"aabbHit", "bool", 8, &kParams_1070[0]},
    {"pointInRect", "bool", 6, &kParams_1070[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1071[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1071[] = {
    {"aabbHit", "bool", 8, &kParams_1071[0]},
    {"dist2", "number", 4, &kParams_1071[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1072[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1072[] = {
    {"approach", "number", 3, &kParams_1072[0]},
    {"follow", "number", 3, &kParams_1072[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1073[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1073[] = {
    {"dist2", "number", 4, &kParams_1073[0]},
    {"wrap", "number", 2, &kParams_1073[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1074[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1074[] = {
    {"shake", "number", 2, &kParams_1074[0]},
    {"follow", "number", 3, &kParams_1074[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1075[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1075[] = {
    {"snapGrid", "number", 1, &kParams_1075[0]},
    {"pointInRect", "bool", 6, &kParams_1075[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1076[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1076[] = {
    {"aabbHit", "bool", 8, &kParams_1076[0]},
    {"pointInRect", "bool", 6, &kParams_1076[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1077[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1077[] = {
    {"aabbHit", "bool", 8, &kParams_1077[0]},
    {"dist2", "number", 4, &kParams_1077[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1078[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1078[] = {
    {"approach", "number", 3, &kParams_1078[0]},
    {"follow", "number", 3, &kParams_1078[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1079[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1079[] = {
    {"dist2", "number", 4, &kParams_1079[0]},
    {"wrap", "number", 2, &kParams_1079[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1080[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1080[] = {
    {"shake", "number", 2, &kParams_1080[0]},
    {"follow", "number", 3, &kParams_1080[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1081[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1081[] = {
    {"snapGrid", "number", 1, &kParams_1081[0]},
    {"pointInRect", "bool", 6, &kParams_1081[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1082[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1082[] = {
    {"aabbHit", "bool", 8, &kParams_1082[0]},
    {"pointInRect", "bool", 6, &kParams_1082[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1083[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1083[] = {
    {"aabbHit", "bool", 8, &kParams_1083[0]},
    {"dist2", "number", 4, &kParams_1083[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1084[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1084[] = {
    {"approach", "number", 3, &kParams_1084[0]},
    {"follow", "number", 3, &kParams_1084[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1085[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1085[] = {
    {"dist2", "number", 4, &kParams_1085[0]},
    {"wrap", "number", 2, &kParams_1085[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1086[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1086[] = {
    {"shake", "number", 2, &kParams_1086[0]},
    {"follow", "number", 3, &kParams_1086[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1087[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1087[] = {
    {"snapGrid", "number", 1, &kParams_1087[0]},
    {"pointInRect", "bool", 6, &kParams_1087[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1088[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1088[] = {
    {"aabbHit", "bool", 8, &kParams_1088[0]},
    {"pointInRect", "bool", 6, &kParams_1088[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1089[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1089[] = {
    {"aabbHit", "bool", 8, &kParams_1089[0]},
    {"dist2", "number", 4, &kParams_1089[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1090[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1090[] = {
    {"approach", "number", 3, &kParams_1090[0]},
    {"follow", "number", 3, &kParams_1090[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1091[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1091[] = {
    {"dist2", "number", 4, &kParams_1091[0]},
    {"wrap", "number", 2, &kParams_1091[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1092[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1092[] = {
    {"shake", "number", 2, &kParams_1092[0]},
    {"follow", "number", 3, &kParams_1092[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1093[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1093[] = {
    {"snapGrid", "number", 1, &kParams_1093[0]},
    {"pointInRect", "bool", 6, &kParams_1093[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1094[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1094[] = {
    {"aabbHit", "bool", 8, &kParams_1094[0]},
    {"pointInRect", "bool", 6, &kParams_1094[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1095[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1095[] = {
    {"aabbHit", "bool", 8, &kParams_1095[0]},
    {"dist2", "number", 4, &kParams_1095[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1096[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1096[] = {
    {"approach", "number", 3, &kParams_1096[0]},
    {"follow", "number", 3, &kParams_1096[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1097[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1097[] = {
    {"dist2", "number", 4, &kParams_1097[0]},
    {"wrap", "number", 2, &kParams_1097[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1098[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1098[] = {
    {"shake", "number", 2, &kParams_1098[0]},
    {"follow", "number", 3, &kParams_1098[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1099[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1099[] = {
    {"snapGrid", "number", 1, &kParams_1099[0]},
    {"pointInRect", "bool", 6, &kParams_1099[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1100[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1100[] = {
    {"aabbHit", "bool", 8, &kParams_1100[0]},
    {"pointInRect", "bool", 6, &kParams_1100[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1101[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1101[] = {
    {"aabbHit", "bool", 8, &kParams_1101[0]},
    {"dist2", "number", 4, &kParams_1101[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1102[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1102[] = {
    {"approach", "number", 3, &kParams_1102[0]},
    {"follow", "number", 3, &kParams_1102[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1103[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1103[] = {
    {"dist2", "number", 4, &kParams_1103[0]},
    {"wrap", "number", 2, &kParams_1103[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1104[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1104[] = {
    {"shake", "number", 2, &kParams_1104[0]},
    {"follow", "number", 3, &kParams_1104[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1105[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1105[] = {
    {"snapGrid", "number", 1, &kParams_1105[0]},
    {"pointInRect", "bool", 6, &kParams_1105[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1106[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1106[] = {
    {"aabbHit", "bool", 8, &kParams_1106[0]},
    {"pointInRect", "bool", 6, &kParams_1106[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1107[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1107[] = {
    {"aabbHit", "bool", 8, &kParams_1107[0]},
    {"dist2", "number", 4, &kParams_1107[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1108[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1108[] = {
    {"approach", "number", 3, &kParams_1108[0]},
    {"follow", "number", 3, &kParams_1108[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1109[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1109[] = {
    {"dist2", "number", 4, &kParams_1109[0]},
    {"wrap", "number", 2, &kParams_1109[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1110[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1110[] = {
    {"shake", "number", 2, &kParams_1110[0]},
    {"follow", "number", 3, &kParams_1110[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1111[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1111[] = {
    {"snapGrid", "number", 1, &kParams_1111[0]},
    {"pointInRect", "bool", 6, &kParams_1111[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1112[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1112[] = {
    {"aabbHit", "bool", 8, &kParams_1112[0]},
    {"pointInRect", "bool", 6, &kParams_1112[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1113[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1113[] = {
    {"aabbHit", "bool", 8, &kParams_1113[0]},
    {"dist2", "number", 4, &kParams_1113[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1114[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1114[] = {
    {"approach", "number", 3, &kParams_1114[0]},
    {"follow", "number", 3, &kParams_1114[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1115[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1115[] = {
    {"dist2", "number", 4, &kParams_1115[0]},
    {"wrap", "number", 2, &kParams_1115[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1116[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1116[] = {
    {"shake", "number", 2, &kParams_1116[0]},
    {"follow", "number", 3, &kParams_1116[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1117[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1117[] = {
    {"snapGrid", "number", 1, &kParams_1117[0]},
    {"pointInRect", "bool", 6, &kParams_1117[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1118[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1118[] = {
    {"aabbHit", "bool", 8, &kParams_1118[0]},
    {"pointInRect", "bool", 6, &kParams_1118[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1119[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1119[] = {
    {"aabbHit", "bool", 8, &kParams_1119[0]},
    {"dist2", "number", 4, &kParams_1119[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1120[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1120[] = {
    {"approach", "number", 3, &kParams_1120[0]},
    {"follow", "number", 3, &kParams_1120[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1121[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1121[] = {
    {"dist2", "number", 4, &kParams_1121[0]},
    {"wrap", "number", 2, &kParams_1121[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1122[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1122[] = {
    {"shake", "number", 2, &kParams_1122[0]},
    {"follow", "number", 3, &kParams_1122[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1123[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1123[] = {
    {"snapGrid", "number", 1, &kParams_1123[0]},
    {"pointInRect", "bool", 6, &kParams_1123[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1124[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1124[] = {
    {"aabbHit", "bool", 8, &kParams_1124[0]},
    {"pointInRect", "bool", 6, &kParams_1124[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1125[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1125[] = {
    {"aabbHit", "bool", 8, &kParams_1125[0]},
    {"dist2", "number", 4, &kParams_1125[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1126[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1126[] = {
    {"approach", "number", 3, &kParams_1126[0]},
    {"follow", "number", 3, &kParams_1126[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1127[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1127[] = {
    {"dist2", "number", 4, &kParams_1127[0]},
    {"wrap", "number", 2, &kParams_1127[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1128[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1128[] = {
    {"shake", "number", 2, &kParams_1128[0]},
    {"follow", "number", 3, &kParams_1128[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1129[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1129[] = {
    {"snapGrid", "number", 1, &kParams_1129[0]},
    {"pointInRect", "bool", 6, &kParams_1129[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1130[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1130[] = {
    {"aabbHit", "bool", 8, &kParams_1130[0]},
    {"pointInRect", "bool", 6, &kParams_1130[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1131[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1131[] = {
    {"aabbHit", "bool", 8, &kParams_1131[0]},
    {"dist2", "number", 4, &kParams_1131[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1132[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1132[] = {
    {"approach", "number", 3, &kParams_1132[0]},
    {"follow", "number", 3, &kParams_1132[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1133[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1133[] = {
    {"dist2", "number", 4, &kParams_1133[0]},
    {"wrap", "number", 2, &kParams_1133[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1134[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1134[] = {
    {"shake", "number", 2, &kParams_1134[0]},
    {"follow", "number", 3, &kParams_1134[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1135[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1135[] = {
    {"snapGrid", "number", 1, &kParams_1135[0]},
    {"pointInRect", "bool", 6, &kParams_1135[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1136[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1136[] = {
    {"aabbHit", "bool", 8, &kParams_1136[0]},
    {"pointInRect", "bool", 6, &kParams_1136[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1137[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1137[] = {
    {"aabbHit", "bool", 8, &kParams_1137[0]},
    {"dist2", "number", 4, &kParams_1137[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1138[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1138[] = {
    {"approach", "number", 3, &kParams_1138[0]},
    {"follow", "number", 3, &kParams_1138[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1139[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1139[] = {
    {"dist2", "number", 4, &kParams_1139[0]},
    {"wrap", "number", 2, &kParams_1139[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1140[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1140[] = {
    {"shake", "number", 2, &kParams_1140[0]},
    {"follow", "number", 3, &kParams_1140[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1141[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1141[] = {
    {"snapGrid", "number", 1, &kParams_1141[0]},
    {"pointInRect", "bool", 6, &kParams_1141[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1142[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1142[] = {
    {"aabbHit", "bool", 8, &kParams_1142[0]},
    {"pointInRect", "bool", 6, &kParams_1142[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1143[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1143[] = {
    {"aabbHit", "bool", 8, &kParams_1143[0]},
    {"dist2", "number", 4, &kParams_1143[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1144[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1144[] = {
    {"approach", "number", 3, &kParams_1144[0]},
    {"follow", "number", 3, &kParams_1144[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1145[] = {
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"v", "number"},
    {"size", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1145[] = {
    {"dist2", "number", 4, &kParams_1145[0]},
    {"wrap", "number", 2, &kParams_1145[4]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1146[] = {
    {"time", "number"},
    {"amp", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1146[] = {
    {"shake", "number", 2, &kParams_1146[0]},
    {"follow", "number", 3, &kParams_1146[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1147[] = {
    {"v", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1147[] = {
    {"snapGrid", "number", 1, &kParams_1147[0]},
    {"pointInRect", "bool", 6, &kParams_1147[1]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1148[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"px", "number"},
    {"py", "number"},
    {"rx", "number"},
    {"ry", "number"},
    {"rw", "number"},
    {"rh", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1148[] = {
    {"aabbHit", "bool", 8, &kParams_1148[0]},
    {"pointInRect", "bool", 6, &kParams_1148[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1149[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"aw", "number"},
    {"ah", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bw", "number"},
    {"bh", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1149[] = {
    {"aabbHit", "bool", 8, &kParams_1149[0]},
    {"dist2", "number", 4, &kParams_1149[8]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1150[] = {
    {"cur", "number"},
    {"target", "number"},
    {"maxDelta", "number"},
    {"cam", "number"},
    {"target", "number"},
    {"dt", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1150[] = {
    {"approach", "number", 3, &kParams_1150[0]},
    {"follow", "number", 3, &kParams_1150[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1151[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1151[] = {
    {"len3", "number", 3, &kParams_1151[0]},
    {"normalize3x", "number", 3, &kParams_1151[3]},
    {"normalize3y", "number", 3, &kParams_1151[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1152[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1152[] = {
    {"normalize3z", "number", 3, &kParams_1152[0]},
    {"dist3", "number", 6, &kParams_1152[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1153[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1153[] = {
    {"yawFromDir", "number", 2, &kParams_1153[0]},
    {"pitchFromDir", "number", 3, &kParams_1153[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1154[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1154[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1154[0]},
    {"lerp3x", "number", 3, &kParams_1154[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1155[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1155[] = {
    {"smooth", "number", 3, &kParams_1155[0]},
    {"lerp3x", "number", 3, &kParams_1155[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1156[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1156[] = {
    {"dot3", "number", 6, &kParams_1156[0]},
    {"crossX", "number", 6, &kParams_1156[6]},
    {"crossY", "number", 6, &kParams_1156[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1157[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1157[] = {
    {"len3", "number", 3, &kParams_1157[0]},
    {"normalize3x", "number", 3, &kParams_1157[3]},
    {"normalize3y", "number", 3, &kParams_1157[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1158[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1158[] = {
    {"normalize3z", "number", 3, &kParams_1158[0]},
    {"dist3", "number", 6, &kParams_1158[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1159[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1159[] = {
    {"yawFromDir", "number", 2, &kParams_1159[0]},
    {"pitchFromDir", "number", 3, &kParams_1159[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1160[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1160[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1160[0]},
    {"lerp3x", "number", 3, &kParams_1160[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1161[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1161[] = {
    {"smooth", "number", 3, &kParams_1161[0]},
    {"lerp3x", "number", 3, &kParams_1161[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1162[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1162[] = {
    {"dot3", "number", 6, &kParams_1162[0]},
    {"crossX", "number", 6, &kParams_1162[6]},
    {"crossY", "number", 6, &kParams_1162[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1163[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1163[] = {
    {"len3", "number", 3, &kParams_1163[0]},
    {"normalize3x", "number", 3, &kParams_1163[3]},
    {"normalize3y", "number", 3, &kParams_1163[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1164[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1164[] = {
    {"normalize3z", "number", 3, &kParams_1164[0]},
    {"dist3", "number", 6, &kParams_1164[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1165[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1165[] = {
    {"yawFromDir", "number", 2, &kParams_1165[0]},
    {"pitchFromDir", "number", 3, &kParams_1165[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1166[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1166[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1166[0]},
    {"lerp3x", "number", 3, &kParams_1166[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1167[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1167[] = {
    {"smooth", "number", 3, &kParams_1167[0]},
    {"lerp3x", "number", 3, &kParams_1167[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1168[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1168[] = {
    {"dot3", "number", 6, &kParams_1168[0]},
    {"crossX", "number", 6, &kParams_1168[6]},
    {"crossY", "number", 6, &kParams_1168[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1169[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1169[] = {
    {"len3", "number", 3, &kParams_1169[0]},
    {"normalize3x", "number", 3, &kParams_1169[3]},
    {"normalize3y", "number", 3, &kParams_1169[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1170[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1170[] = {
    {"normalize3z", "number", 3, &kParams_1170[0]},
    {"dist3", "number", 6, &kParams_1170[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1171[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1171[] = {
    {"yawFromDir", "number", 2, &kParams_1171[0]},
    {"pitchFromDir", "number", 3, &kParams_1171[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1172[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1172[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1172[0]},
    {"lerp3x", "number", 3, &kParams_1172[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1173[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1173[] = {
    {"smooth", "number", 3, &kParams_1173[0]},
    {"lerp3x", "number", 3, &kParams_1173[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1174[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1174[] = {
    {"dot3", "number", 6, &kParams_1174[0]},
    {"crossX", "number", 6, &kParams_1174[6]},
    {"crossY", "number", 6, &kParams_1174[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1175[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1175[] = {
    {"len3", "number", 3, &kParams_1175[0]},
    {"normalize3x", "number", 3, &kParams_1175[3]},
    {"normalize3y", "number", 3, &kParams_1175[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1176[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1176[] = {
    {"normalize3z", "number", 3, &kParams_1176[0]},
    {"dist3", "number", 6, &kParams_1176[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1177[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1177[] = {
    {"yawFromDir", "number", 2, &kParams_1177[0]},
    {"pitchFromDir", "number", 3, &kParams_1177[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1178[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1178[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1178[0]},
    {"lerp3x", "number", 3, &kParams_1178[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1179[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1179[] = {
    {"smooth", "number", 3, &kParams_1179[0]},
    {"lerp3x", "number", 3, &kParams_1179[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1180[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1180[] = {
    {"dot3", "number", 6, &kParams_1180[0]},
    {"crossX", "number", 6, &kParams_1180[6]},
    {"crossY", "number", 6, &kParams_1180[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1181[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1181[] = {
    {"len3", "number", 3, &kParams_1181[0]},
    {"normalize3x", "number", 3, &kParams_1181[3]},
    {"normalize3y", "number", 3, &kParams_1181[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1182[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1182[] = {
    {"normalize3z", "number", 3, &kParams_1182[0]},
    {"dist3", "number", 6, &kParams_1182[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1183[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1183[] = {
    {"yawFromDir", "number", 2, &kParams_1183[0]},
    {"pitchFromDir", "number", 3, &kParams_1183[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1184[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1184[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1184[0]},
    {"lerp3x", "number", 3, &kParams_1184[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1185[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1185[] = {
    {"smooth", "number", 3, &kParams_1185[0]},
    {"lerp3x", "number", 3, &kParams_1185[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1186[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1186[] = {
    {"dot3", "number", 6, &kParams_1186[0]},
    {"crossX", "number", 6, &kParams_1186[6]},
    {"crossY", "number", 6, &kParams_1186[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1187[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1187[] = {
    {"len3", "number", 3, &kParams_1187[0]},
    {"normalize3x", "number", 3, &kParams_1187[3]},
    {"normalize3y", "number", 3, &kParams_1187[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1188[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1188[] = {
    {"normalize3z", "number", 3, &kParams_1188[0]},
    {"dist3", "number", 6, &kParams_1188[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1189[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1189[] = {
    {"yawFromDir", "number", 2, &kParams_1189[0]},
    {"pitchFromDir", "number", 3, &kParams_1189[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1190[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1190[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1190[0]},
    {"lerp3x", "number", 3, &kParams_1190[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1191[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1191[] = {
    {"smooth", "number", 3, &kParams_1191[0]},
    {"lerp3x", "number", 3, &kParams_1191[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1192[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1192[] = {
    {"dot3", "number", 6, &kParams_1192[0]},
    {"crossX", "number", 6, &kParams_1192[6]},
    {"crossY", "number", 6, &kParams_1192[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1193[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1193[] = {
    {"len3", "number", 3, &kParams_1193[0]},
    {"normalize3x", "number", 3, &kParams_1193[3]},
    {"normalize3y", "number", 3, &kParams_1193[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1194[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1194[] = {
    {"normalize3z", "number", 3, &kParams_1194[0]},
    {"dist3", "number", 6, &kParams_1194[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1195[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1195[] = {
    {"yawFromDir", "number", 2, &kParams_1195[0]},
    {"pitchFromDir", "number", 3, &kParams_1195[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1196[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1196[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1196[0]},
    {"lerp3x", "number", 3, &kParams_1196[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1197[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1197[] = {
    {"smooth", "number", 3, &kParams_1197[0]},
    {"lerp3x", "number", 3, &kParams_1197[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1198[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1198[] = {
    {"dot3", "number", 6, &kParams_1198[0]},
    {"crossX", "number", 6, &kParams_1198[6]},
    {"crossY", "number", 6, &kParams_1198[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1199[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1199[] = {
    {"len3", "number", 3, &kParams_1199[0]},
    {"normalize3x", "number", 3, &kParams_1199[3]},
    {"normalize3y", "number", 3, &kParams_1199[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1200[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1200[] = {
    {"normalize3z", "number", 3, &kParams_1200[0]},
    {"dist3", "number", 6, &kParams_1200[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1201[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1201[] = {
    {"yawFromDir", "number", 2, &kParams_1201[0]},
    {"pitchFromDir", "number", 3, &kParams_1201[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1202[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1202[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1202[0]},
    {"lerp3x", "number", 3, &kParams_1202[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1203[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1203[] = {
    {"smooth", "number", 3, &kParams_1203[0]},
    {"lerp3x", "number", 3, &kParams_1203[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1204[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1204[] = {
    {"dot3", "number", 6, &kParams_1204[0]},
    {"crossX", "number", 6, &kParams_1204[6]},
    {"crossY", "number", 6, &kParams_1204[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1205[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1205[] = {
    {"len3", "number", 3, &kParams_1205[0]},
    {"normalize3x", "number", 3, &kParams_1205[3]},
    {"normalize3y", "number", 3, &kParams_1205[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1206[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1206[] = {
    {"normalize3z", "number", 3, &kParams_1206[0]},
    {"dist3", "number", 6, &kParams_1206[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1207[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1207[] = {
    {"yawFromDir", "number", 2, &kParams_1207[0]},
    {"pitchFromDir", "number", 3, &kParams_1207[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1208[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1208[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1208[0]},
    {"lerp3x", "number", 3, &kParams_1208[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1209[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1209[] = {
    {"smooth", "number", 3, &kParams_1209[0]},
    {"lerp3x", "number", 3, &kParams_1209[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1210[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1210[] = {
    {"dot3", "number", 6, &kParams_1210[0]},
    {"crossX", "number", 6, &kParams_1210[6]},
    {"crossY", "number", 6, &kParams_1210[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1211[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1211[] = {
    {"len3", "number", 3, &kParams_1211[0]},
    {"normalize3x", "number", 3, &kParams_1211[3]},
    {"normalize3y", "number", 3, &kParams_1211[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1212[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1212[] = {
    {"normalize3z", "number", 3, &kParams_1212[0]},
    {"dist3", "number", 6, &kParams_1212[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1213[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1213[] = {
    {"yawFromDir", "number", 2, &kParams_1213[0]},
    {"pitchFromDir", "number", 3, &kParams_1213[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1214[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1214[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1214[0]},
    {"lerp3x", "number", 3, &kParams_1214[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1215[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1215[] = {
    {"smooth", "number", 3, &kParams_1215[0]},
    {"lerp3x", "number", 3, &kParams_1215[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1216[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1216[] = {
    {"dot3", "number", 6, &kParams_1216[0]},
    {"crossX", "number", 6, &kParams_1216[6]},
    {"crossY", "number", 6, &kParams_1216[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1217[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1217[] = {
    {"len3", "number", 3, &kParams_1217[0]},
    {"normalize3x", "number", 3, &kParams_1217[3]},
    {"normalize3y", "number", 3, &kParams_1217[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1218[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1218[] = {
    {"normalize3z", "number", 3, &kParams_1218[0]},
    {"dist3", "number", 6, &kParams_1218[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1219[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1219[] = {
    {"yawFromDir", "number", 2, &kParams_1219[0]},
    {"pitchFromDir", "number", 3, &kParams_1219[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1220[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1220[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1220[0]},
    {"lerp3x", "number", 3, &kParams_1220[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1221[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1221[] = {
    {"smooth", "number", 3, &kParams_1221[0]},
    {"lerp3x", "number", 3, &kParams_1221[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1222[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1222[] = {
    {"dot3", "number", 6, &kParams_1222[0]},
    {"crossX", "number", 6, &kParams_1222[6]},
    {"crossY", "number", 6, &kParams_1222[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1223[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1223[] = {
    {"len3", "number", 3, &kParams_1223[0]},
    {"normalize3x", "number", 3, &kParams_1223[3]},
    {"normalize3y", "number", 3, &kParams_1223[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1224[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1224[] = {
    {"normalize3z", "number", 3, &kParams_1224[0]},
    {"dist3", "number", 6, &kParams_1224[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1225[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1225[] = {
    {"yawFromDir", "number", 2, &kParams_1225[0]},
    {"pitchFromDir", "number", 3, &kParams_1225[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1226[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1226[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1226[0]},
    {"lerp3x", "number", 3, &kParams_1226[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1227[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1227[] = {
    {"smooth", "number", 3, &kParams_1227[0]},
    {"lerp3x", "number", 3, &kParams_1227[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1228[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1228[] = {
    {"dot3", "number", 6, &kParams_1228[0]},
    {"crossX", "number", 6, &kParams_1228[6]},
    {"crossY", "number", 6, &kParams_1228[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1229[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1229[] = {
    {"len3", "number", 3, &kParams_1229[0]},
    {"normalize3x", "number", 3, &kParams_1229[3]},
    {"normalize3y", "number", 3, &kParams_1229[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1230[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1230[] = {
    {"normalize3z", "number", 3, &kParams_1230[0]},
    {"dist3", "number", 6, &kParams_1230[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1231[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1231[] = {
    {"yawFromDir", "number", 2, &kParams_1231[0]},
    {"pitchFromDir", "number", 3, &kParams_1231[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1232[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1232[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1232[0]},
    {"lerp3x", "number", 3, &kParams_1232[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1233[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1233[] = {
    {"smooth", "number", 3, &kParams_1233[0]},
    {"lerp3x", "number", 3, &kParams_1233[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1234[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1234[] = {
    {"dot3", "number", 6, &kParams_1234[0]},
    {"crossX", "number", 6, &kParams_1234[6]},
    {"crossY", "number", 6, &kParams_1234[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1235[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1235[] = {
    {"len3", "number", 3, &kParams_1235[0]},
    {"normalize3x", "number", 3, &kParams_1235[3]},
    {"normalize3y", "number", 3, &kParams_1235[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1236[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1236[] = {
    {"normalize3z", "number", 3, &kParams_1236[0]},
    {"dist3", "number", 6, &kParams_1236[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1237[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1237[] = {
    {"yawFromDir", "number", 2, &kParams_1237[0]},
    {"pitchFromDir", "number", 3, &kParams_1237[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1238[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1238[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1238[0]},
    {"lerp3x", "number", 3, &kParams_1238[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1239[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1239[] = {
    {"smooth", "number", 3, &kParams_1239[0]},
    {"lerp3x", "number", 3, &kParams_1239[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1240[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1240[] = {
    {"dot3", "number", 6, &kParams_1240[0]},
    {"crossX", "number", 6, &kParams_1240[6]},
    {"crossY", "number", 6, &kParams_1240[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1241[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1241[] = {
    {"len3", "number", 3, &kParams_1241[0]},
    {"normalize3x", "number", 3, &kParams_1241[3]},
    {"normalize3y", "number", 3, &kParams_1241[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1242[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1242[] = {
    {"normalize3z", "number", 3, &kParams_1242[0]},
    {"dist3", "number", 6, &kParams_1242[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1243[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1243[] = {
    {"yawFromDir", "number", 2, &kParams_1243[0]},
    {"pitchFromDir", "number", 3, &kParams_1243[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1244[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1244[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1244[0]},
    {"lerp3x", "number", 3, &kParams_1244[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1245[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1245[] = {
    {"smooth", "number", 3, &kParams_1245[0]},
    {"lerp3x", "number", 3, &kParams_1245[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1246[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1246[] = {
    {"dot3", "number", 6, &kParams_1246[0]},
    {"crossX", "number", 6, &kParams_1246[6]},
    {"crossY", "number", 6, &kParams_1246[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1247[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1247[] = {
    {"len3", "number", 3, &kParams_1247[0]},
    {"normalize3x", "number", 3, &kParams_1247[3]},
    {"normalize3y", "number", 3, &kParams_1247[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1248[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1248[] = {
    {"normalize3z", "number", 3, &kParams_1248[0]},
    {"dist3", "number", 6, &kParams_1248[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1249[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1249[] = {
    {"yawFromDir", "number", 2, &kParams_1249[0]},
    {"pitchFromDir", "number", 3, &kParams_1249[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1250[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1250[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1250[0]},
    {"lerp3x", "number", 3, &kParams_1250[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1251[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1251[] = {
    {"smooth", "number", 3, &kParams_1251[0]},
    {"lerp3x", "number", 3, &kParams_1251[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1252[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1252[] = {
    {"dot3", "number", 6, &kParams_1252[0]},
    {"crossX", "number", 6, &kParams_1252[6]},
    {"crossY", "number", 6, &kParams_1252[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1253[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1253[] = {
    {"len3", "number", 3, &kParams_1253[0]},
    {"normalize3x", "number", 3, &kParams_1253[3]},
    {"normalize3y", "number", 3, &kParams_1253[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1254[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1254[] = {
    {"normalize3z", "number", 3, &kParams_1254[0]},
    {"dist3", "number", 6, &kParams_1254[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1255[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1255[] = {
    {"yawFromDir", "number", 2, &kParams_1255[0]},
    {"pitchFromDir", "number", 3, &kParams_1255[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1256[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1256[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1256[0]},
    {"lerp3x", "number", 3, &kParams_1256[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1257[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1257[] = {
    {"smooth", "number", 3, &kParams_1257[0]},
    {"lerp3x", "number", 3, &kParams_1257[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1258[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1258[] = {
    {"dot3", "number", 6, &kParams_1258[0]},
    {"crossX", "number", 6, &kParams_1258[6]},
    {"crossY", "number", 6, &kParams_1258[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1259[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1259[] = {
    {"len3", "number", 3, &kParams_1259[0]},
    {"normalize3x", "number", 3, &kParams_1259[3]},
    {"normalize3y", "number", 3, &kParams_1259[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1260[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1260[] = {
    {"normalize3z", "number", 3, &kParams_1260[0]},
    {"dist3", "number", 6, &kParams_1260[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1261[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1261[] = {
    {"yawFromDir", "number", 2, &kParams_1261[0]},
    {"pitchFromDir", "number", 3, &kParams_1261[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1262[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1262[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1262[0]},
    {"lerp3x", "number", 3, &kParams_1262[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1263[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1263[] = {
    {"smooth", "number", 3, &kParams_1263[0]},
    {"lerp3x", "number", 3, &kParams_1263[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1264[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1264[] = {
    {"dot3", "number", 6, &kParams_1264[0]},
    {"crossX", "number", 6, &kParams_1264[6]},
    {"crossY", "number", 6, &kParams_1264[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1265[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1265[] = {
    {"len3", "number", 3, &kParams_1265[0]},
    {"normalize3x", "number", 3, &kParams_1265[3]},
    {"normalize3y", "number", 3, &kParams_1265[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1266[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1266[] = {
    {"normalize3z", "number", 3, &kParams_1266[0]},
    {"dist3", "number", 6, &kParams_1266[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1267[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1267[] = {
    {"yawFromDir", "number", 2, &kParams_1267[0]},
    {"pitchFromDir", "number", 3, &kParams_1267[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1268[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1268[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1268[0]},
    {"lerp3x", "number", 3, &kParams_1268[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1269[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1269[] = {
    {"smooth", "number", 3, &kParams_1269[0]},
    {"lerp3x", "number", 3, &kParams_1269[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1270[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1270[] = {
    {"dot3", "number", 6, &kParams_1270[0]},
    {"crossX", "number", 6, &kParams_1270[6]},
    {"crossY", "number", 6, &kParams_1270[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1271[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1271[] = {
    {"len3", "number", 3, &kParams_1271[0]},
    {"normalize3x", "number", 3, &kParams_1271[3]},
    {"normalize3y", "number", 3, &kParams_1271[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1272[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1272[] = {
    {"normalize3z", "number", 3, &kParams_1272[0]},
    {"dist3", "number", 6, &kParams_1272[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1273[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1273[] = {
    {"yawFromDir", "number", 2, &kParams_1273[0]},
    {"pitchFromDir", "number", 3, &kParams_1273[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1274[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1274[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1274[0]},
    {"lerp3x", "number", 3, &kParams_1274[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1275[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1275[] = {
    {"smooth", "number", 3, &kParams_1275[0]},
    {"lerp3x", "number", 3, &kParams_1275[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1276[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1276[] = {
    {"dot3", "number", 6, &kParams_1276[0]},
    {"crossX", "number", 6, &kParams_1276[6]},
    {"crossY", "number", 6, &kParams_1276[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1277[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1277[] = {
    {"len3", "number", 3, &kParams_1277[0]},
    {"normalize3x", "number", 3, &kParams_1277[3]},
    {"normalize3y", "number", 3, &kParams_1277[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1278[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1278[] = {
    {"normalize3z", "number", 3, &kParams_1278[0]},
    {"dist3", "number", 6, &kParams_1278[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1279[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1279[] = {
    {"yawFromDir", "number", 2, &kParams_1279[0]},
    {"pitchFromDir", "number", 3, &kParams_1279[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1280[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1280[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1280[0]},
    {"lerp3x", "number", 3, &kParams_1280[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1281[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1281[] = {
    {"smooth", "number", 3, &kParams_1281[0]},
    {"lerp3x", "number", 3, &kParams_1281[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1282[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1282[] = {
    {"dot3", "number", 6, &kParams_1282[0]},
    {"crossX", "number", 6, &kParams_1282[6]},
    {"crossY", "number", 6, &kParams_1282[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1283[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1283[] = {
    {"len3", "number", 3, &kParams_1283[0]},
    {"normalize3x", "number", 3, &kParams_1283[3]},
    {"normalize3y", "number", 3, &kParams_1283[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1284[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1284[] = {
    {"normalize3z", "number", 3, &kParams_1284[0]},
    {"dist3", "number", 6, &kParams_1284[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1285[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1285[] = {
    {"yawFromDir", "number", 2, &kParams_1285[0]},
    {"pitchFromDir", "number", 3, &kParams_1285[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1286[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1286[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1286[0]},
    {"lerp3x", "number", 3, &kParams_1286[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1287[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1287[] = {
    {"smooth", "number", 3, &kParams_1287[0]},
    {"lerp3x", "number", 3, &kParams_1287[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1288[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1288[] = {
    {"dot3", "number", 6, &kParams_1288[0]},
    {"crossX", "number", 6, &kParams_1288[6]},
    {"crossY", "number", 6, &kParams_1288[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1289[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1289[] = {
    {"len3", "number", 3, &kParams_1289[0]},
    {"normalize3x", "number", 3, &kParams_1289[3]},
    {"normalize3y", "number", 3, &kParams_1289[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1290[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1290[] = {
    {"normalize3z", "number", 3, &kParams_1290[0]},
    {"dist3", "number", 6, &kParams_1290[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1291[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1291[] = {
    {"yawFromDir", "number", 2, &kParams_1291[0]},
    {"pitchFromDir", "number", 3, &kParams_1291[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1292[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1292[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1292[0]},
    {"lerp3x", "number", 3, &kParams_1292[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1293[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1293[] = {
    {"smooth", "number", 3, &kParams_1293[0]},
    {"lerp3x", "number", 3, &kParams_1293[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1294[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1294[] = {
    {"dot3", "number", 6, &kParams_1294[0]},
    {"crossX", "number", 6, &kParams_1294[6]},
    {"crossY", "number", 6, &kParams_1294[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1295[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1295[] = {
    {"len3", "number", 3, &kParams_1295[0]},
    {"normalize3x", "number", 3, &kParams_1295[3]},
    {"normalize3y", "number", 3, &kParams_1295[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1296[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1296[] = {
    {"normalize3z", "number", 3, &kParams_1296[0]},
    {"dist3", "number", 6, &kParams_1296[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1297[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1297[] = {
    {"yawFromDir", "number", 2, &kParams_1297[0]},
    {"pitchFromDir", "number", 3, &kParams_1297[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1298[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1298[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1298[0]},
    {"lerp3x", "number", 3, &kParams_1298[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1299[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1299[] = {
    {"smooth", "number", 3, &kParams_1299[0]},
    {"lerp3x", "number", 3, &kParams_1299[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1300[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1300[] = {
    {"dot3", "number", 6, &kParams_1300[0]},
    {"crossX", "number", 6, &kParams_1300[6]},
    {"crossY", "number", 6, &kParams_1300[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1301[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1301[] = {
    {"len3", "number", 3, &kParams_1301[0]},
    {"normalize3x", "number", 3, &kParams_1301[3]},
    {"normalize3y", "number", 3, &kParams_1301[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1302[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1302[] = {
    {"normalize3z", "number", 3, &kParams_1302[0]},
    {"dist3", "number", 6, &kParams_1302[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1303[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1303[] = {
    {"yawFromDir", "number", 2, &kParams_1303[0]},
    {"pitchFromDir", "number", 3, &kParams_1303[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1304[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1304[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1304[0]},
    {"lerp3x", "number", 3, &kParams_1304[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1305[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1305[] = {
    {"smooth", "number", 3, &kParams_1305[0]},
    {"lerp3x", "number", 3, &kParams_1305[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1306[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1306[] = {
    {"dot3", "number", 6, &kParams_1306[0]},
    {"crossX", "number", 6, &kParams_1306[6]},
    {"crossY", "number", 6, &kParams_1306[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1307[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1307[] = {
    {"len3", "number", 3, &kParams_1307[0]},
    {"normalize3x", "number", 3, &kParams_1307[3]},
    {"normalize3y", "number", 3, &kParams_1307[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1308[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1308[] = {
    {"normalize3z", "number", 3, &kParams_1308[0]},
    {"dist3", "number", 6, &kParams_1308[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1309[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1309[] = {
    {"yawFromDir", "number", 2, &kParams_1309[0]},
    {"pitchFromDir", "number", 3, &kParams_1309[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1310[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1310[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1310[0]},
    {"lerp3x", "number", 3, &kParams_1310[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1311[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1311[] = {
    {"smooth", "number", 3, &kParams_1311[0]},
    {"lerp3x", "number", 3, &kParams_1311[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1312[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1312[] = {
    {"dot3", "number", 6, &kParams_1312[0]},
    {"crossX", "number", 6, &kParams_1312[6]},
    {"crossY", "number", 6, &kParams_1312[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1313[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1313[] = {
    {"len3", "number", 3, &kParams_1313[0]},
    {"normalize3x", "number", 3, &kParams_1313[3]},
    {"normalize3y", "number", 3, &kParams_1313[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1314[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1314[] = {
    {"normalize3z", "number", 3, &kParams_1314[0]},
    {"dist3", "number", 6, &kParams_1314[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1315[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1315[] = {
    {"yawFromDir", "number", 2, &kParams_1315[0]},
    {"pitchFromDir", "number", 3, &kParams_1315[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1316[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1316[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1316[0]},
    {"lerp3x", "number", 3, &kParams_1316[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1317[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1317[] = {
    {"smooth", "number", 3, &kParams_1317[0]},
    {"lerp3x", "number", 3, &kParams_1317[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1318[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1318[] = {
    {"dot3", "number", 6, &kParams_1318[0]},
    {"crossX", "number", 6, &kParams_1318[6]},
    {"crossY", "number", 6, &kParams_1318[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1319[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1319[] = {
    {"len3", "number", 3, &kParams_1319[0]},
    {"normalize3x", "number", 3, &kParams_1319[3]},
    {"normalize3y", "number", 3, &kParams_1319[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1320[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1320[] = {
    {"normalize3z", "number", 3, &kParams_1320[0]},
    {"dist3", "number", 6, &kParams_1320[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1321[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1321[] = {
    {"yawFromDir", "number", 2, &kParams_1321[0]},
    {"pitchFromDir", "number", 3, &kParams_1321[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1322[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1322[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1322[0]},
    {"lerp3x", "number", 3, &kParams_1322[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1323[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1323[] = {
    {"smooth", "number", 3, &kParams_1323[0]},
    {"lerp3x", "number", 3, &kParams_1323[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1324[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1324[] = {
    {"dot3", "number", 6, &kParams_1324[0]},
    {"crossX", "number", 6, &kParams_1324[6]},
    {"crossY", "number", 6, &kParams_1324[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1325[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1325[] = {
    {"len3", "number", 3, &kParams_1325[0]},
    {"normalize3x", "number", 3, &kParams_1325[3]},
    {"normalize3y", "number", 3, &kParams_1325[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1326[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1326[] = {
    {"normalize3z", "number", 3, &kParams_1326[0]},
    {"dist3", "number", 6, &kParams_1326[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1327[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1327[] = {
    {"yawFromDir", "number", 2, &kParams_1327[0]},
    {"pitchFromDir", "number", 3, &kParams_1327[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1328[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1328[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1328[0]},
    {"lerp3x", "number", 3, &kParams_1328[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1329[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1329[] = {
    {"smooth", "number", 3, &kParams_1329[0]},
    {"lerp3x", "number", 3, &kParams_1329[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1330[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1330[] = {
    {"dot3", "number", 6, &kParams_1330[0]},
    {"crossX", "number", 6, &kParams_1330[6]},
    {"crossY", "number", 6, &kParams_1330[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1331[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1331[] = {
    {"len3", "number", 3, &kParams_1331[0]},
    {"normalize3x", "number", 3, &kParams_1331[3]},
    {"normalize3y", "number", 3, &kParams_1331[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1332[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1332[] = {
    {"normalize3z", "number", 3, &kParams_1332[0]},
    {"dist3", "number", 6, &kParams_1332[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1333[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1333[] = {
    {"yawFromDir", "number", 2, &kParams_1333[0]},
    {"pitchFromDir", "number", 3, &kParams_1333[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1334[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1334[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1334[0]},
    {"lerp3x", "number", 3, &kParams_1334[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1335[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1335[] = {
    {"smooth", "number", 3, &kParams_1335[0]},
    {"lerp3x", "number", 3, &kParams_1335[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1336[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1336[] = {
    {"dot3", "number", 6, &kParams_1336[0]},
    {"crossX", "number", 6, &kParams_1336[6]},
    {"crossY", "number", 6, &kParams_1336[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1337[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1337[] = {
    {"len3", "number", 3, &kParams_1337[0]},
    {"normalize3x", "number", 3, &kParams_1337[3]},
    {"normalize3y", "number", 3, &kParams_1337[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1338[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1338[] = {
    {"normalize3z", "number", 3, &kParams_1338[0]},
    {"dist3", "number", 6, &kParams_1338[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1339[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1339[] = {
    {"yawFromDir", "number", 2, &kParams_1339[0]},
    {"pitchFromDir", "number", 3, &kParams_1339[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1340[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1340[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1340[0]},
    {"lerp3x", "number", 3, &kParams_1340[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1341[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1341[] = {
    {"smooth", "number", 3, &kParams_1341[0]},
    {"lerp3x", "number", 3, &kParams_1341[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1342[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1342[] = {
    {"dot3", "number", 6, &kParams_1342[0]},
    {"crossX", "number", 6, &kParams_1342[6]},
    {"crossY", "number", 6, &kParams_1342[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1343[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1343[] = {
    {"len3", "number", 3, &kParams_1343[0]},
    {"normalize3x", "number", 3, &kParams_1343[3]},
    {"normalize3y", "number", 3, &kParams_1343[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1344[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1344[] = {
    {"normalize3z", "number", 3, &kParams_1344[0]},
    {"dist3", "number", 6, &kParams_1344[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1345[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1345[] = {
    {"yawFromDir", "number", 2, &kParams_1345[0]},
    {"pitchFromDir", "number", 3, &kParams_1345[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1346[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1346[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1346[0]},
    {"lerp3x", "number", 3, &kParams_1346[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1347[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1347[] = {
    {"smooth", "number", 3, &kParams_1347[0]},
    {"lerp3x", "number", 3, &kParams_1347[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1348[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1348[] = {
    {"dot3", "number", 6, &kParams_1348[0]},
    {"crossX", "number", 6, &kParams_1348[6]},
    {"crossY", "number", 6, &kParams_1348[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1349[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1349[] = {
    {"len3", "number", 3, &kParams_1349[0]},
    {"normalize3x", "number", 3, &kParams_1349[3]},
    {"normalize3y", "number", 3, &kParams_1349[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1350[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1350[] = {
    {"normalize3z", "number", 3, &kParams_1350[0]},
    {"dist3", "number", 6, &kParams_1350[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1351[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1351[] = {
    {"yawFromDir", "number", 2, &kParams_1351[0]},
    {"pitchFromDir", "number", 3, &kParams_1351[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1352[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1352[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1352[0]},
    {"lerp3x", "number", 3, &kParams_1352[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1353[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1353[] = {
    {"smooth", "number", 3, &kParams_1353[0]},
    {"lerp3x", "number", 3, &kParams_1353[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1354[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1354[] = {
    {"dot3", "number", 6, &kParams_1354[0]},
    {"crossX", "number", 6, &kParams_1354[6]},
    {"crossY", "number", 6, &kParams_1354[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1355[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1355[] = {
    {"len3", "number", 3, &kParams_1355[0]},
    {"normalize3x", "number", 3, &kParams_1355[3]},
    {"normalize3y", "number", 3, &kParams_1355[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1356[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1356[] = {
    {"normalize3z", "number", 3, &kParams_1356[0]},
    {"dist3", "number", 6, &kParams_1356[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1357[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1357[] = {
    {"yawFromDir", "number", 2, &kParams_1357[0]},
    {"pitchFromDir", "number", 3, &kParams_1357[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1358[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1358[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1358[0]},
    {"lerp3x", "number", 3, &kParams_1358[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1359[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1359[] = {
    {"smooth", "number", 3, &kParams_1359[0]},
    {"lerp3x", "number", 3, &kParams_1359[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1360[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1360[] = {
    {"dot3", "number", 6, &kParams_1360[0]},
    {"crossX", "number", 6, &kParams_1360[6]},
    {"crossY", "number", 6, &kParams_1360[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1361[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1361[] = {
    {"len3", "number", 3, &kParams_1361[0]},
    {"normalize3x", "number", 3, &kParams_1361[3]},
    {"normalize3y", "number", 3, &kParams_1361[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1362[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1362[] = {
    {"normalize3z", "number", 3, &kParams_1362[0]},
    {"dist3", "number", 6, &kParams_1362[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1363[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1363[] = {
    {"yawFromDir", "number", 2, &kParams_1363[0]},
    {"pitchFromDir", "number", 3, &kParams_1363[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1364[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1364[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1364[0]},
    {"lerp3x", "number", 3, &kParams_1364[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1365[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1365[] = {
    {"smooth", "number", 3, &kParams_1365[0]},
    {"lerp3x", "number", 3, &kParams_1365[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1366[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1366[] = {
    {"dot3", "number", 6, &kParams_1366[0]},
    {"crossX", "number", 6, &kParams_1366[6]},
    {"crossY", "number", 6, &kParams_1366[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1367[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1367[] = {
    {"len3", "number", 3, &kParams_1367[0]},
    {"normalize3x", "number", 3, &kParams_1367[3]},
    {"normalize3y", "number", 3, &kParams_1367[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1368[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1368[] = {
    {"normalize3z", "number", 3, &kParams_1368[0]},
    {"dist3", "number", 6, &kParams_1368[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1369[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1369[] = {
    {"yawFromDir", "number", 2, &kParams_1369[0]},
    {"pitchFromDir", "number", 3, &kParams_1369[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1370[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1370[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1370[0]},
    {"lerp3x", "number", 3, &kParams_1370[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1371[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1371[] = {
    {"smooth", "number", 3, &kParams_1371[0]},
    {"lerp3x", "number", 3, &kParams_1371[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1372[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1372[] = {
    {"dot3", "number", 6, &kParams_1372[0]},
    {"crossX", "number", 6, &kParams_1372[6]},
    {"crossY", "number", 6, &kParams_1372[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1373[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1373[] = {
    {"len3", "number", 3, &kParams_1373[0]},
    {"normalize3x", "number", 3, &kParams_1373[3]},
    {"normalize3y", "number", 3, &kParams_1373[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1374[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1374[] = {
    {"normalize3z", "number", 3, &kParams_1374[0]},
    {"dist3", "number", 6, &kParams_1374[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1375[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1375[] = {
    {"yawFromDir", "number", 2, &kParams_1375[0]},
    {"pitchFromDir", "number", 3, &kParams_1375[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1376[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1376[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1376[0]},
    {"lerp3x", "number", 3, &kParams_1376[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1377[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1377[] = {
    {"smooth", "number", 3, &kParams_1377[0]},
    {"lerp3x", "number", 3, &kParams_1377[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1378[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1378[] = {
    {"dot3", "number", 6, &kParams_1378[0]},
    {"crossX", "number", 6, &kParams_1378[6]},
    {"crossY", "number", 6, &kParams_1378[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1379[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1379[] = {
    {"len3", "number", 3, &kParams_1379[0]},
    {"normalize3x", "number", 3, &kParams_1379[3]},
    {"normalize3y", "number", 3, &kParams_1379[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1380[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1380[] = {
    {"normalize3z", "number", 3, &kParams_1380[0]},
    {"dist3", "number", 6, &kParams_1380[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1381[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1381[] = {
    {"yawFromDir", "number", 2, &kParams_1381[0]},
    {"pitchFromDir", "number", 3, &kParams_1381[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1382[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1382[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1382[0]},
    {"lerp3x", "number", 3, &kParams_1382[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1383[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1383[] = {
    {"smooth", "number", 3, &kParams_1383[0]},
    {"lerp3x", "number", 3, &kParams_1383[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1384[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1384[] = {
    {"dot3", "number", 6, &kParams_1384[0]},
    {"crossX", "number", 6, &kParams_1384[6]},
    {"crossY", "number", 6, &kParams_1384[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1385[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1385[] = {
    {"len3", "number", 3, &kParams_1385[0]},
    {"normalize3x", "number", 3, &kParams_1385[3]},
    {"normalize3y", "number", 3, &kParams_1385[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1386[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1386[] = {
    {"normalize3z", "number", 3, &kParams_1386[0]},
    {"dist3", "number", 6, &kParams_1386[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1387[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1387[] = {
    {"yawFromDir", "number", 2, &kParams_1387[0]},
    {"pitchFromDir", "number", 3, &kParams_1387[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1388[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1388[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1388[0]},
    {"lerp3x", "number", 3, &kParams_1388[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1389[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1389[] = {
    {"smooth", "number", 3, &kParams_1389[0]},
    {"lerp3x", "number", 3, &kParams_1389[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1390[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1390[] = {
    {"dot3", "number", 6, &kParams_1390[0]},
    {"crossX", "number", 6, &kParams_1390[6]},
    {"crossY", "number", 6, &kParams_1390[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1391[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1391[] = {
    {"len3", "number", 3, &kParams_1391[0]},
    {"normalize3x", "number", 3, &kParams_1391[3]},
    {"normalize3y", "number", 3, &kParams_1391[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1392[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1392[] = {
    {"normalize3z", "number", 3, &kParams_1392[0]},
    {"dist3", "number", 6, &kParams_1392[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1393[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1393[] = {
    {"yawFromDir", "number", 2, &kParams_1393[0]},
    {"pitchFromDir", "number", 3, &kParams_1393[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1394[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1394[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1394[0]},
    {"lerp3x", "number", 3, &kParams_1394[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1395[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1395[] = {
    {"smooth", "number", 3, &kParams_1395[0]},
    {"lerp3x", "number", 3, &kParams_1395[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1396[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1396[] = {
    {"dot3", "number", 6, &kParams_1396[0]},
    {"crossX", "number", 6, &kParams_1396[6]},
    {"crossY", "number", 6, &kParams_1396[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1397[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1397[] = {
    {"len3", "number", 3, &kParams_1397[0]},
    {"normalize3x", "number", 3, &kParams_1397[3]},
    {"normalize3y", "number", 3, &kParams_1397[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1398[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1398[] = {
    {"normalize3z", "number", 3, &kParams_1398[0]},
    {"dist3", "number", 6, &kParams_1398[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1399[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1399[] = {
    {"yawFromDir", "number", 2, &kParams_1399[0]},
    {"pitchFromDir", "number", 3, &kParams_1399[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1400[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1400[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1400[0]},
    {"lerp3x", "number", 3, &kParams_1400[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1401[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1401[] = {
    {"smooth", "number", 3, &kParams_1401[0]},
    {"lerp3x", "number", 3, &kParams_1401[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1402[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1402[] = {
    {"dot3", "number", 6, &kParams_1402[0]},
    {"crossX", "number", 6, &kParams_1402[6]},
    {"crossY", "number", 6, &kParams_1402[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1403[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1403[] = {
    {"len3", "number", 3, &kParams_1403[0]},
    {"normalize3x", "number", 3, &kParams_1403[3]},
    {"normalize3y", "number", 3, &kParams_1403[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1404[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1404[] = {
    {"normalize3z", "number", 3, &kParams_1404[0]},
    {"dist3", "number", 6, &kParams_1404[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1405[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1405[] = {
    {"yawFromDir", "number", 2, &kParams_1405[0]},
    {"pitchFromDir", "number", 3, &kParams_1405[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1406[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1406[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1406[0]},
    {"lerp3x", "number", 3, &kParams_1406[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1407[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1407[] = {
    {"smooth", "number", 3, &kParams_1407[0]},
    {"lerp3x", "number", 3, &kParams_1407[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1408[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1408[] = {
    {"dot3", "number", 6, &kParams_1408[0]},
    {"crossX", "number", 6, &kParams_1408[6]},
    {"crossY", "number", 6, &kParams_1408[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1409[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1409[] = {
    {"len3", "number", 3, &kParams_1409[0]},
    {"normalize3x", "number", 3, &kParams_1409[3]},
    {"normalize3y", "number", 3, &kParams_1409[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1410[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1410[] = {
    {"normalize3z", "number", 3, &kParams_1410[0]},
    {"dist3", "number", 6, &kParams_1410[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1411[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1411[] = {
    {"yawFromDir", "number", 2, &kParams_1411[0]},
    {"pitchFromDir", "number", 3, &kParams_1411[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1412[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1412[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1412[0]},
    {"lerp3x", "number", 3, &kParams_1412[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1413[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1413[] = {
    {"smooth", "number", 3, &kParams_1413[0]},
    {"lerp3x", "number", 3, &kParams_1413[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1414[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1414[] = {
    {"dot3", "number", 6, &kParams_1414[0]},
    {"crossX", "number", 6, &kParams_1414[6]},
    {"crossY", "number", 6, &kParams_1414[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1415[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1415[] = {
    {"len3", "number", 3, &kParams_1415[0]},
    {"normalize3x", "number", 3, &kParams_1415[3]},
    {"normalize3y", "number", 3, &kParams_1415[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1416[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1416[] = {
    {"normalize3z", "number", 3, &kParams_1416[0]},
    {"dist3", "number", 6, &kParams_1416[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1417[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1417[] = {
    {"yawFromDir", "number", 2, &kParams_1417[0]},
    {"pitchFromDir", "number", 3, &kParams_1417[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1418[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1418[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1418[0]},
    {"lerp3x", "number", 3, &kParams_1418[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1419[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1419[] = {
    {"smooth", "number", 3, &kParams_1419[0]},
    {"lerp3x", "number", 3, &kParams_1419[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1420[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1420[] = {
    {"dot3", "number", 6, &kParams_1420[0]},
    {"crossX", "number", 6, &kParams_1420[6]},
    {"crossY", "number", 6, &kParams_1420[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1421[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1421[] = {
    {"len3", "number", 3, &kParams_1421[0]},
    {"normalize3x", "number", 3, &kParams_1421[3]},
    {"normalize3y", "number", 3, &kParams_1421[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1422[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1422[] = {
    {"normalize3z", "number", 3, &kParams_1422[0]},
    {"dist3", "number", 6, &kParams_1422[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1423[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1423[] = {
    {"yawFromDir", "number", 2, &kParams_1423[0]},
    {"pitchFromDir", "number", 3, &kParams_1423[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1424[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1424[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1424[0]},
    {"lerp3x", "number", 3, &kParams_1424[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1425[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1425[] = {
    {"smooth", "number", 3, &kParams_1425[0]},
    {"lerp3x", "number", 3, &kParams_1425[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1426[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1426[] = {
    {"dot3", "number", 6, &kParams_1426[0]},
    {"crossX", "number", 6, &kParams_1426[6]},
    {"crossY", "number", 6, &kParams_1426[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1427[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1427[] = {
    {"len3", "number", 3, &kParams_1427[0]},
    {"normalize3x", "number", 3, &kParams_1427[3]},
    {"normalize3y", "number", 3, &kParams_1427[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1428[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1428[] = {
    {"normalize3z", "number", 3, &kParams_1428[0]},
    {"dist3", "number", 6, &kParams_1428[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1429[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1429[] = {
    {"yawFromDir", "number", 2, &kParams_1429[0]},
    {"pitchFromDir", "number", 3, &kParams_1429[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1430[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1430[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1430[0]},
    {"lerp3x", "number", 3, &kParams_1430[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1431[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1431[] = {
    {"smooth", "number", 3, &kParams_1431[0]},
    {"lerp3x", "number", 3, &kParams_1431[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1432[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1432[] = {
    {"dot3", "number", 6, &kParams_1432[0]},
    {"crossX", "number", 6, &kParams_1432[6]},
    {"crossY", "number", 6, &kParams_1432[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1433[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1433[] = {
    {"len3", "number", 3, &kParams_1433[0]},
    {"normalize3x", "number", 3, &kParams_1433[3]},
    {"normalize3y", "number", 3, &kParams_1433[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1434[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1434[] = {
    {"normalize3z", "number", 3, &kParams_1434[0]},
    {"dist3", "number", 6, &kParams_1434[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1435[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1435[] = {
    {"yawFromDir", "number", 2, &kParams_1435[0]},
    {"pitchFromDir", "number", 3, &kParams_1435[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1436[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1436[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1436[0]},
    {"lerp3x", "number", 3, &kParams_1436[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1437[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1437[] = {
    {"smooth", "number", 3, &kParams_1437[0]},
    {"lerp3x", "number", 3, &kParams_1437[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1438[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1438[] = {
    {"dot3", "number", 6, &kParams_1438[0]},
    {"crossX", "number", 6, &kParams_1438[6]},
    {"crossY", "number", 6, &kParams_1438[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1439[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1439[] = {
    {"len3", "number", 3, &kParams_1439[0]},
    {"normalize3x", "number", 3, &kParams_1439[3]},
    {"normalize3y", "number", 3, &kParams_1439[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1440[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1440[] = {
    {"normalize3z", "number", 3, &kParams_1440[0]},
    {"dist3", "number", 6, &kParams_1440[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1441[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1441[] = {
    {"yawFromDir", "number", 2, &kParams_1441[0]},
    {"pitchFromDir", "number", 3, &kParams_1441[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1442[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1442[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1442[0]},
    {"lerp3x", "number", 3, &kParams_1442[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1443[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1443[] = {
    {"smooth", "number", 3, &kParams_1443[0]},
    {"lerp3x", "number", 3, &kParams_1443[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1444[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1444[] = {
    {"dot3", "number", 6, &kParams_1444[0]},
    {"crossX", "number", 6, &kParams_1444[6]},
    {"crossY", "number", 6, &kParams_1444[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1445[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1445[] = {
    {"len3", "number", 3, &kParams_1445[0]},
    {"normalize3x", "number", 3, &kParams_1445[3]},
    {"normalize3y", "number", 3, &kParams_1445[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1446[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1446[] = {
    {"normalize3z", "number", 3, &kParams_1446[0]},
    {"dist3", "number", 6, &kParams_1446[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1447[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1447[] = {
    {"yawFromDir", "number", 2, &kParams_1447[0]},
    {"pitchFromDir", "number", 3, &kParams_1447[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1448[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1448[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1448[0]},
    {"lerp3x", "number", 3, &kParams_1448[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1449[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1449[] = {
    {"smooth", "number", 3, &kParams_1449[0]},
    {"lerp3x", "number", 3, &kParams_1449[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1450[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1450[] = {
    {"dot3", "number", 6, &kParams_1450[0]},
    {"crossX", "number", 6, &kParams_1450[6]},
    {"crossY", "number", 6, &kParams_1450[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1451[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1451[] = {
    {"len3", "number", 3, &kParams_1451[0]},
    {"normalize3x", "number", 3, &kParams_1451[3]},
    {"normalize3y", "number", 3, &kParams_1451[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1452[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1452[] = {
    {"normalize3z", "number", 3, &kParams_1452[0]},
    {"dist3", "number", 6, &kParams_1452[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1453[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1453[] = {
    {"yawFromDir", "number", 2, &kParams_1453[0]},
    {"pitchFromDir", "number", 3, &kParams_1453[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1454[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1454[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1454[0]},
    {"lerp3x", "number", 3, &kParams_1454[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1455[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1455[] = {
    {"smooth", "number", 3, &kParams_1455[0]},
    {"lerp3x", "number", 3, &kParams_1455[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1456[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1456[] = {
    {"dot3", "number", 6, &kParams_1456[0]},
    {"crossX", "number", 6, &kParams_1456[6]},
    {"crossY", "number", 6, &kParams_1456[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1457[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1457[] = {
    {"len3", "number", 3, &kParams_1457[0]},
    {"normalize3x", "number", 3, &kParams_1457[3]},
    {"normalize3y", "number", 3, &kParams_1457[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1458[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1458[] = {
    {"normalize3z", "number", 3, &kParams_1458[0]},
    {"dist3", "number", 6, &kParams_1458[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1459[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1459[] = {
    {"yawFromDir", "number", 2, &kParams_1459[0]},
    {"pitchFromDir", "number", 3, &kParams_1459[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1460[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1460[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1460[0]},
    {"lerp3x", "number", 3, &kParams_1460[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1461[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1461[] = {
    {"smooth", "number", 3, &kParams_1461[0]},
    {"lerp3x", "number", 3, &kParams_1461[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1462[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1462[] = {
    {"dot3", "number", 6, &kParams_1462[0]},
    {"crossX", "number", 6, &kParams_1462[6]},
    {"crossY", "number", 6, &kParams_1462[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1463[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1463[] = {
    {"len3", "number", 3, &kParams_1463[0]},
    {"normalize3x", "number", 3, &kParams_1463[3]},
    {"normalize3y", "number", 3, &kParams_1463[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1464[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1464[] = {
    {"normalize3z", "number", 3, &kParams_1464[0]},
    {"dist3", "number", 6, &kParams_1464[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1465[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1465[] = {
    {"yawFromDir", "number", 2, &kParams_1465[0]},
    {"pitchFromDir", "number", 3, &kParams_1465[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1466[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1466[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1466[0]},
    {"lerp3x", "number", 3, &kParams_1466[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1467[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1467[] = {
    {"smooth", "number", 3, &kParams_1467[0]},
    {"lerp3x", "number", 3, &kParams_1467[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1468[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1468[] = {
    {"dot3", "number", 6, &kParams_1468[0]},
    {"crossX", "number", 6, &kParams_1468[6]},
    {"crossY", "number", 6, &kParams_1468[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1469[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1469[] = {
    {"len3", "number", 3, &kParams_1469[0]},
    {"normalize3x", "number", 3, &kParams_1469[3]},
    {"normalize3y", "number", 3, &kParams_1469[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1470[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1470[] = {
    {"normalize3z", "number", 3, &kParams_1470[0]},
    {"dist3", "number", 6, &kParams_1470[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1471[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1471[] = {
    {"yawFromDir", "number", 2, &kParams_1471[0]},
    {"pitchFromDir", "number", 3, &kParams_1471[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1472[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1472[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1472[0]},
    {"lerp3x", "number", 3, &kParams_1472[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1473[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1473[] = {
    {"smooth", "number", 3, &kParams_1473[0]},
    {"lerp3x", "number", 3, &kParams_1473[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1474[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1474[] = {
    {"dot3", "number", 6, &kParams_1474[0]},
    {"crossX", "number", 6, &kParams_1474[6]},
    {"crossY", "number", 6, &kParams_1474[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1475[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1475[] = {
    {"len3", "number", 3, &kParams_1475[0]},
    {"normalize3x", "number", 3, &kParams_1475[3]},
    {"normalize3y", "number", 3, &kParams_1475[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1476[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1476[] = {
    {"normalize3z", "number", 3, &kParams_1476[0]},
    {"dist3", "number", 6, &kParams_1476[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1477[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1477[] = {
    {"yawFromDir", "number", 2, &kParams_1477[0]},
    {"pitchFromDir", "number", 3, &kParams_1477[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1478[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1478[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1478[0]},
    {"lerp3x", "number", 3, &kParams_1478[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1479[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1479[] = {
    {"smooth", "number", 3, &kParams_1479[0]},
    {"lerp3x", "number", 3, &kParams_1479[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1480[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1480[] = {
    {"dot3", "number", 6, &kParams_1480[0]},
    {"crossX", "number", 6, &kParams_1480[6]},
    {"crossY", "number", 6, &kParams_1480[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1481[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1481[] = {
    {"len3", "number", 3, &kParams_1481[0]},
    {"normalize3x", "number", 3, &kParams_1481[3]},
    {"normalize3y", "number", 3, &kParams_1481[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1482[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1482[] = {
    {"normalize3z", "number", 3, &kParams_1482[0]},
    {"dist3", "number", 6, &kParams_1482[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1483[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1483[] = {
    {"yawFromDir", "number", 2, &kParams_1483[0]},
    {"pitchFromDir", "number", 3, &kParams_1483[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1484[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1484[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1484[0]},
    {"lerp3x", "number", 3, &kParams_1484[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1485[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1485[] = {
    {"smooth", "number", 3, &kParams_1485[0]},
    {"lerp3x", "number", 3, &kParams_1485[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1486[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1486[] = {
    {"dot3", "number", 6, &kParams_1486[0]},
    {"crossX", "number", 6, &kParams_1486[6]},
    {"crossY", "number", 6, &kParams_1486[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1487[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1487[] = {
    {"len3", "number", 3, &kParams_1487[0]},
    {"normalize3x", "number", 3, &kParams_1487[3]},
    {"normalize3y", "number", 3, &kParams_1487[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1488[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1488[] = {
    {"normalize3z", "number", 3, &kParams_1488[0]},
    {"dist3", "number", 6, &kParams_1488[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1489[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1489[] = {
    {"yawFromDir", "number", 2, &kParams_1489[0]},
    {"pitchFromDir", "number", 3, &kParams_1489[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1490[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1490[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1490[0]},
    {"lerp3x", "number", 3, &kParams_1490[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1491[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1491[] = {
    {"smooth", "number", 3, &kParams_1491[0]},
    {"lerp3x", "number", 3, &kParams_1491[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1492[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1492[] = {
    {"dot3", "number", 6, &kParams_1492[0]},
    {"crossX", "number", 6, &kParams_1492[6]},
    {"crossY", "number", 6, &kParams_1492[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1493[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1493[] = {
    {"len3", "number", 3, &kParams_1493[0]},
    {"normalize3x", "number", 3, &kParams_1493[3]},
    {"normalize3y", "number", 3, &kParams_1493[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1494[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1494[] = {
    {"normalize3z", "number", 3, &kParams_1494[0]},
    {"dist3", "number", 6, &kParams_1494[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1495[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1495[] = {
    {"yawFromDir", "number", 2, &kParams_1495[0]},
    {"pitchFromDir", "number", 3, &kParams_1495[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1496[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1496[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1496[0]},
    {"lerp3x", "number", 3, &kParams_1496[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1497[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1497[] = {
    {"smooth", "number", 3, &kParams_1497[0]},
    {"lerp3x", "number", 3, &kParams_1497[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1498[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1498[] = {
    {"dot3", "number", 6, &kParams_1498[0]},
    {"crossX", "number", 6, &kParams_1498[6]},
    {"crossY", "number", 6, &kParams_1498[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1499[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1499[] = {
    {"len3", "number", 3, &kParams_1499[0]},
    {"normalize3x", "number", 3, &kParams_1499[3]},
    {"normalize3y", "number", 3, &kParams_1499[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1500[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1500[] = {
    {"normalize3z", "number", 3, &kParams_1500[0]},
    {"dist3", "number", 6, &kParams_1500[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1501[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1501[] = {
    {"yawFromDir", "number", 2, &kParams_1501[0]},
    {"pitchFromDir", "number", 3, &kParams_1501[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1502[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1502[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1502[0]},
    {"lerp3x", "number", 3, &kParams_1502[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1503[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1503[] = {
    {"smooth", "number", 3, &kParams_1503[0]},
    {"lerp3x", "number", 3, &kParams_1503[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1504[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1504[] = {
    {"dot3", "number", 6, &kParams_1504[0]},
    {"crossX", "number", 6, &kParams_1504[6]},
    {"crossY", "number", 6, &kParams_1504[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1505[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1505[] = {
    {"len3", "number", 3, &kParams_1505[0]},
    {"normalize3x", "number", 3, &kParams_1505[3]},
    {"normalize3y", "number", 3, &kParams_1505[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1506[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1506[] = {
    {"normalize3z", "number", 3, &kParams_1506[0]},
    {"dist3", "number", 6, &kParams_1506[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1507[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1507[] = {
    {"yawFromDir", "number", 2, &kParams_1507[0]},
    {"pitchFromDir", "number", 3, &kParams_1507[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1508[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1508[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1508[0]},
    {"lerp3x", "number", 3, &kParams_1508[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1509[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1509[] = {
    {"smooth", "number", 3, &kParams_1509[0]},
    {"lerp3x", "number", 3, &kParams_1509[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1510[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1510[] = {
    {"dot3", "number", 6, &kParams_1510[0]},
    {"crossX", "number", 6, &kParams_1510[6]},
    {"crossY", "number", 6, &kParams_1510[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1511[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1511[] = {
    {"len3", "number", 3, &kParams_1511[0]},
    {"normalize3x", "number", 3, &kParams_1511[3]},
    {"normalize3y", "number", 3, &kParams_1511[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1512[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1512[] = {
    {"normalize3z", "number", 3, &kParams_1512[0]},
    {"dist3", "number", 6, &kParams_1512[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1513[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1513[] = {
    {"yawFromDir", "number", 2, &kParams_1513[0]},
    {"pitchFromDir", "number", 3, &kParams_1513[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1514[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1514[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1514[0]},
    {"lerp3x", "number", 3, &kParams_1514[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1515[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1515[] = {
    {"smooth", "number", 3, &kParams_1515[0]},
    {"lerp3x", "number", 3, &kParams_1515[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1516[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1516[] = {
    {"dot3", "number", 6, &kParams_1516[0]},
    {"crossX", "number", 6, &kParams_1516[6]},
    {"crossY", "number", 6, &kParams_1516[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1517[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1517[] = {
    {"len3", "number", 3, &kParams_1517[0]},
    {"normalize3x", "number", 3, &kParams_1517[3]},
    {"normalize3y", "number", 3, &kParams_1517[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1518[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1518[] = {
    {"normalize3z", "number", 3, &kParams_1518[0]},
    {"dist3", "number", 6, &kParams_1518[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1519[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1519[] = {
    {"yawFromDir", "number", 2, &kParams_1519[0]},
    {"pitchFromDir", "number", 3, &kParams_1519[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1520[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1520[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1520[0]},
    {"lerp3x", "number", 3, &kParams_1520[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1521[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1521[] = {
    {"smooth", "number", 3, &kParams_1521[0]},
    {"lerp3x", "number", 3, &kParams_1521[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1522[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1522[] = {
    {"dot3", "number", 6, &kParams_1522[0]},
    {"crossX", "number", 6, &kParams_1522[6]},
    {"crossY", "number", 6, &kParams_1522[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1523[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1523[] = {
    {"len3", "number", 3, &kParams_1523[0]},
    {"normalize3x", "number", 3, &kParams_1523[3]},
    {"normalize3y", "number", 3, &kParams_1523[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1524[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1524[] = {
    {"normalize3z", "number", 3, &kParams_1524[0]},
    {"dist3", "number", 6, &kParams_1524[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1525[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1525[] = {
    {"yawFromDir", "number", 2, &kParams_1525[0]},
    {"pitchFromDir", "number", 3, &kParams_1525[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1526[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1526[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1526[0]},
    {"lerp3x", "number", 3, &kParams_1526[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1527[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1527[] = {
    {"smooth", "number", 3, &kParams_1527[0]},
    {"lerp3x", "number", 3, &kParams_1527[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1528[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1528[] = {
    {"dot3", "number", 6, &kParams_1528[0]},
    {"crossX", "number", 6, &kParams_1528[6]},
    {"crossY", "number", 6, &kParams_1528[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1529[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1529[] = {
    {"len3", "number", 3, &kParams_1529[0]},
    {"normalize3x", "number", 3, &kParams_1529[3]},
    {"normalize3y", "number", 3, &kParams_1529[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1530[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1530[] = {
    {"normalize3z", "number", 3, &kParams_1530[0]},
    {"dist3", "number", 6, &kParams_1530[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1531[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1531[] = {
    {"yawFromDir", "number", 2, &kParams_1531[0]},
    {"pitchFromDir", "number", 3, &kParams_1531[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1532[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1532[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1532[0]},
    {"lerp3x", "number", 3, &kParams_1532[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1533[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1533[] = {
    {"smooth", "number", 3, &kParams_1533[0]},
    {"lerp3x", "number", 3, &kParams_1533[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1534[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1534[] = {
    {"dot3", "number", 6, &kParams_1534[0]},
    {"crossX", "number", 6, &kParams_1534[6]},
    {"crossY", "number", 6, &kParams_1534[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1535[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1535[] = {
    {"len3", "number", 3, &kParams_1535[0]},
    {"normalize3x", "number", 3, &kParams_1535[3]},
    {"normalize3y", "number", 3, &kParams_1535[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1536[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1536[] = {
    {"normalize3z", "number", 3, &kParams_1536[0]},
    {"dist3", "number", 6, &kParams_1536[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1537[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1537[] = {
    {"yawFromDir", "number", 2, &kParams_1537[0]},
    {"pitchFromDir", "number", 3, &kParams_1537[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1538[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1538[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1538[0]},
    {"lerp3x", "number", 3, &kParams_1538[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1539[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1539[] = {
    {"smooth", "number", 3, &kParams_1539[0]},
    {"lerp3x", "number", 3, &kParams_1539[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1540[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1540[] = {
    {"dot3", "number", 6, &kParams_1540[0]},
    {"crossX", "number", 6, &kParams_1540[6]},
    {"crossY", "number", 6, &kParams_1540[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1541[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1541[] = {
    {"len3", "number", 3, &kParams_1541[0]},
    {"normalize3x", "number", 3, &kParams_1541[3]},
    {"normalize3y", "number", 3, &kParams_1541[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1542[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1542[] = {
    {"normalize3z", "number", 3, &kParams_1542[0]},
    {"dist3", "number", 6, &kParams_1542[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1543[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1543[] = {
    {"yawFromDir", "number", 2, &kParams_1543[0]},
    {"pitchFromDir", "number", 3, &kParams_1543[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1544[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1544[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1544[0]},
    {"lerp3x", "number", 3, &kParams_1544[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1545[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1545[] = {
    {"smooth", "number", 3, &kParams_1545[0]},
    {"lerp3x", "number", 3, &kParams_1545[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1546[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1546[] = {
    {"dot3", "number", 6, &kParams_1546[0]},
    {"crossX", "number", 6, &kParams_1546[6]},
    {"crossY", "number", 6, &kParams_1546[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1547[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1547[] = {
    {"len3", "number", 3, &kParams_1547[0]},
    {"normalize3x", "number", 3, &kParams_1547[3]},
    {"normalize3y", "number", 3, &kParams_1547[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1548[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1548[] = {
    {"normalize3z", "number", 3, &kParams_1548[0]},
    {"dist3", "number", 6, &kParams_1548[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1549[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1549[] = {
    {"yawFromDir", "number", 2, &kParams_1549[0]},
    {"pitchFromDir", "number", 3, &kParams_1549[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1550[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1550[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1550[0]},
    {"lerp3x", "number", 3, &kParams_1550[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1551[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1551[] = {
    {"smooth", "number", 3, &kParams_1551[0]},
    {"lerp3x", "number", 3, &kParams_1551[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1552[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1552[] = {
    {"dot3", "number", 6, &kParams_1552[0]},
    {"crossX", "number", 6, &kParams_1552[6]},
    {"crossY", "number", 6, &kParams_1552[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1553[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1553[] = {
    {"len3", "number", 3, &kParams_1553[0]},
    {"normalize3x", "number", 3, &kParams_1553[3]},
    {"normalize3y", "number", 3, &kParams_1553[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1554[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1554[] = {
    {"normalize3z", "number", 3, &kParams_1554[0]},
    {"dist3", "number", 6, &kParams_1554[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1555[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1555[] = {
    {"yawFromDir", "number", 2, &kParams_1555[0]},
    {"pitchFromDir", "number", 3, &kParams_1555[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1556[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1556[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1556[0]},
    {"lerp3x", "number", 3, &kParams_1556[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1557[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1557[] = {
    {"smooth", "number", 3, &kParams_1557[0]},
    {"lerp3x", "number", 3, &kParams_1557[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1558[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1558[] = {
    {"dot3", "number", 6, &kParams_1558[0]},
    {"crossX", "number", 6, &kParams_1558[6]},
    {"crossY", "number", 6, &kParams_1558[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1559[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1559[] = {
    {"len3", "number", 3, &kParams_1559[0]},
    {"normalize3x", "number", 3, &kParams_1559[3]},
    {"normalize3y", "number", 3, &kParams_1559[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1560[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1560[] = {
    {"normalize3z", "number", 3, &kParams_1560[0]},
    {"dist3", "number", 6, &kParams_1560[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1561[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1561[] = {
    {"yawFromDir", "number", 2, &kParams_1561[0]},
    {"pitchFromDir", "number", 3, &kParams_1561[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1562[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1562[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1562[0]},
    {"lerp3x", "number", 3, &kParams_1562[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1563[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1563[] = {
    {"smooth", "number", 3, &kParams_1563[0]},
    {"lerp3x", "number", 3, &kParams_1563[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1564[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1564[] = {
    {"dot3", "number", 6, &kParams_1564[0]},
    {"crossX", "number", 6, &kParams_1564[6]},
    {"crossY", "number", 6, &kParams_1564[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1565[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1565[] = {
    {"len3", "number", 3, &kParams_1565[0]},
    {"normalize3x", "number", 3, &kParams_1565[3]},
    {"normalize3y", "number", 3, &kParams_1565[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1566[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1566[] = {
    {"normalize3z", "number", 3, &kParams_1566[0]},
    {"dist3", "number", 6, &kParams_1566[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1567[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1567[] = {
    {"yawFromDir", "number", 2, &kParams_1567[0]},
    {"pitchFromDir", "number", 3, &kParams_1567[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1568[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1568[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1568[0]},
    {"lerp3x", "number", 3, &kParams_1568[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1569[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1569[] = {
    {"smooth", "number", 3, &kParams_1569[0]},
    {"lerp3x", "number", 3, &kParams_1569[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1570[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1570[] = {
    {"dot3", "number", 6, &kParams_1570[0]},
    {"crossX", "number", 6, &kParams_1570[6]},
    {"crossY", "number", 6, &kParams_1570[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1571[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1571[] = {
    {"len3", "number", 3, &kParams_1571[0]},
    {"normalize3x", "number", 3, &kParams_1571[3]},
    {"normalize3y", "number", 3, &kParams_1571[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1572[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1572[] = {
    {"normalize3z", "number", 3, &kParams_1572[0]},
    {"dist3", "number", 6, &kParams_1572[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1573[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1573[] = {
    {"yawFromDir", "number", 2, &kParams_1573[0]},
    {"pitchFromDir", "number", 3, &kParams_1573[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1574[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1574[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1574[0]},
    {"lerp3x", "number", 3, &kParams_1574[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1575[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1575[] = {
    {"smooth", "number", 3, &kParams_1575[0]},
    {"lerp3x", "number", 3, &kParams_1575[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1576[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1576[] = {
    {"dot3", "number", 6, &kParams_1576[0]},
    {"crossX", "number", 6, &kParams_1576[6]},
    {"crossY", "number", 6, &kParams_1576[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1577[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1577[] = {
    {"len3", "number", 3, &kParams_1577[0]},
    {"normalize3x", "number", 3, &kParams_1577[3]},
    {"normalize3y", "number", 3, &kParams_1577[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1578[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1578[] = {
    {"normalize3z", "number", 3, &kParams_1578[0]},
    {"dist3", "number", 6, &kParams_1578[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1579[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1579[] = {
    {"yawFromDir", "number", 2, &kParams_1579[0]},
    {"pitchFromDir", "number", 3, &kParams_1579[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1580[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1580[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1580[0]},
    {"lerp3x", "number", 3, &kParams_1580[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1581[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1581[] = {
    {"smooth", "number", 3, &kParams_1581[0]},
    {"lerp3x", "number", 3, &kParams_1581[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1582[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1582[] = {
    {"dot3", "number", 6, &kParams_1582[0]},
    {"crossX", "number", 6, &kParams_1582[6]},
    {"crossY", "number", 6, &kParams_1582[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1583[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1583[] = {
    {"len3", "number", 3, &kParams_1583[0]},
    {"normalize3x", "number", 3, &kParams_1583[3]},
    {"normalize3y", "number", 3, &kParams_1583[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1584[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1584[] = {
    {"normalize3z", "number", 3, &kParams_1584[0]},
    {"dist3", "number", 6, &kParams_1584[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1585[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1585[] = {
    {"yawFromDir", "number", 2, &kParams_1585[0]},
    {"pitchFromDir", "number", 3, &kParams_1585[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1586[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1586[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1586[0]},
    {"lerp3x", "number", 3, &kParams_1586[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1587[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1587[] = {
    {"smooth", "number", 3, &kParams_1587[0]},
    {"lerp3x", "number", 3, &kParams_1587[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1588[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1588[] = {
    {"dot3", "number", 6, &kParams_1588[0]},
    {"crossX", "number", 6, &kParams_1588[6]},
    {"crossY", "number", 6, &kParams_1588[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1589[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1589[] = {
    {"len3", "number", 3, &kParams_1589[0]},
    {"normalize3x", "number", 3, &kParams_1589[3]},
    {"normalize3y", "number", 3, &kParams_1589[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1590[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1590[] = {
    {"normalize3z", "number", 3, &kParams_1590[0]},
    {"dist3", "number", 6, &kParams_1590[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1591[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1591[] = {
    {"yawFromDir", "number", 2, &kParams_1591[0]},
    {"pitchFromDir", "number", 3, &kParams_1591[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1592[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1592[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1592[0]},
    {"lerp3x", "number", 3, &kParams_1592[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1593[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1593[] = {
    {"smooth", "number", 3, &kParams_1593[0]},
    {"lerp3x", "number", 3, &kParams_1593[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1594[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1594[] = {
    {"dot3", "number", 6, &kParams_1594[0]},
    {"crossX", "number", 6, &kParams_1594[6]},
    {"crossY", "number", 6, &kParams_1594[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1595[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1595[] = {
    {"len3", "number", 3, &kParams_1595[0]},
    {"normalize3x", "number", 3, &kParams_1595[3]},
    {"normalize3y", "number", 3, &kParams_1595[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1596[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1596[] = {
    {"normalize3z", "number", 3, &kParams_1596[0]},
    {"dist3", "number", 6, &kParams_1596[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1597[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1597[] = {
    {"yawFromDir", "number", 2, &kParams_1597[0]},
    {"pitchFromDir", "number", 3, &kParams_1597[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1598[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1598[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1598[0]},
    {"lerp3x", "number", 3, &kParams_1598[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1599[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1599[] = {
    {"smooth", "number", 3, &kParams_1599[0]},
    {"lerp3x", "number", 3, &kParams_1599[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1600[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1600[] = {
    {"dot3", "number", 6, &kParams_1600[0]},
    {"crossX", "number", 6, &kParams_1600[6]},
    {"crossY", "number", 6, &kParams_1600[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1601[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1601[] = {
    {"len3", "number", 3, &kParams_1601[0]},
    {"normalize3x", "number", 3, &kParams_1601[3]},
    {"normalize3y", "number", 3, &kParams_1601[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1602[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1602[] = {
    {"normalize3z", "number", 3, &kParams_1602[0]},
    {"dist3", "number", 6, &kParams_1602[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1603[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1603[] = {
    {"yawFromDir", "number", 2, &kParams_1603[0]},
    {"pitchFromDir", "number", 3, &kParams_1603[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1604[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1604[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1604[0]},
    {"lerp3x", "number", 3, &kParams_1604[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1605[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1605[] = {
    {"smooth", "number", 3, &kParams_1605[0]},
    {"lerp3x", "number", 3, &kParams_1605[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1606[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1606[] = {
    {"dot3", "number", 6, &kParams_1606[0]},
    {"crossX", "number", 6, &kParams_1606[6]},
    {"crossY", "number", 6, &kParams_1606[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1607[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1607[] = {
    {"len3", "number", 3, &kParams_1607[0]},
    {"normalize3x", "number", 3, &kParams_1607[3]},
    {"normalize3y", "number", 3, &kParams_1607[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1608[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1608[] = {
    {"normalize3z", "number", 3, &kParams_1608[0]},
    {"dist3", "number", 6, &kParams_1608[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1609[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1609[] = {
    {"yawFromDir", "number", 2, &kParams_1609[0]},
    {"pitchFromDir", "number", 3, &kParams_1609[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1610[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1610[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1610[0]},
    {"lerp3x", "number", 3, &kParams_1610[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1611[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1611[] = {
    {"smooth", "number", 3, &kParams_1611[0]},
    {"lerp3x", "number", 3, &kParams_1611[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1612[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1612[] = {
    {"dot3", "number", 6, &kParams_1612[0]},
    {"crossX", "number", 6, &kParams_1612[6]},
    {"crossY", "number", 6, &kParams_1612[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1613[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1613[] = {
    {"len3", "number", 3, &kParams_1613[0]},
    {"normalize3x", "number", 3, &kParams_1613[3]},
    {"normalize3y", "number", 3, &kParams_1613[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1614[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1614[] = {
    {"normalize3z", "number", 3, &kParams_1614[0]},
    {"dist3", "number", 6, &kParams_1614[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1615[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1615[] = {
    {"yawFromDir", "number", 2, &kParams_1615[0]},
    {"pitchFromDir", "number", 3, &kParams_1615[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1616[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1616[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1616[0]},
    {"lerp3x", "number", 3, &kParams_1616[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1617[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1617[] = {
    {"smooth", "number", 3, &kParams_1617[0]},
    {"lerp3x", "number", 3, &kParams_1617[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1618[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1618[] = {
    {"dot3", "number", 6, &kParams_1618[0]},
    {"crossX", "number", 6, &kParams_1618[6]},
    {"crossY", "number", 6, &kParams_1618[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1619[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1619[] = {
    {"len3", "number", 3, &kParams_1619[0]},
    {"normalize3x", "number", 3, &kParams_1619[3]},
    {"normalize3y", "number", 3, &kParams_1619[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1620[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1620[] = {
    {"normalize3z", "number", 3, &kParams_1620[0]},
    {"dist3", "number", 6, &kParams_1620[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1621[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1621[] = {
    {"yawFromDir", "number", 2, &kParams_1621[0]},
    {"pitchFromDir", "number", 3, &kParams_1621[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1622[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1622[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1622[0]},
    {"lerp3x", "number", 3, &kParams_1622[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1623[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1623[] = {
    {"smooth", "number", 3, &kParams_1623[0]},
    {"lerp3x", "number", 3, &kParams_1623[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1624[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1624[] = {
    {"dot3", "number", 6, &kParams_1624[0]},
    {"crossX", "number", 6, &kParams_1624[6]},
    {"crossY", "number", 6, &kParams_1624[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1625[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1625[] = {
    {"len3", "number", 3, &kParams_1625[0]},
    {"normalize3x", "number", 3, &kParams_1625[3]},
    {"normalize3y", "number", 3, &kParams_1625[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1626[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1626[] = {
    {"normalize3z", "number", 3, &kParams_1626[0]},
    {"dist3", "number", 6, &kParams_1626[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1627[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1627[] = {
    {"yawFromDir", "number", 2, &kParams_1627[0]},
    {"pitchFromDir", "number", 3, &kParams_1627[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1628[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1628[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1628[0]},
    {"lerp3x", "number", 3, &kParams_1628[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1629[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1629[] = {
    {"smooth", "number", 3, &kParams_1629[0]},
    {"lerp3x", "number", 3, &kParams_1629[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1630[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1630[] = {
    {"dot3", "number", 6, &kParams_1630[0]},
    {"crossX", "number", 6, &kParams_1630[6]},
    {"crossY", "number", 6, &kParams_1630[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1631[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1631[] = {
    {"len3", "number", 3, &kParams_1631[0]},
    {"normalize3x", "number", 3, &kParams_1631[3]},
    {"normalize3y", "number", 3, &kParams_1631[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1632[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1632[] = {
    {"normalize3z", "number", 3, &kParams_1632[0]},
    {"dist3", "number", 6, &kParams_1632[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1633[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1633[] = {
    {"yawFromDir", "number", 2, &kParams_1633[0]},
    {"pitchFromDir", "number", 3, &kParams_1633[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1634[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1634[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1634[0]},
    {"lerp3x", "number", 3, &kParams_1634[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1635[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1635[] = {
    {"smooth", "number", 3, &kParams_1635[0]},
    {"lerp3x", "number", 3, &kParams_1635[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1636[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1636[] = {
    {"dot3", "number", 6, &kParams_1636[0]},
    {"crossX", "number", 6, &kParams_1636[6]},
    {"crossY", "number", 6, &kParams_1636[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1637[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1637[] = {
    {"len3", "number", 3, &kParams_1637[0]},
    {"normalize3x", "number", 3, &kParams_1637[3]},
    {"normalize3y", "number", 3, &kParams_1637[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1638[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1638[] = {
    {"normalize3z", "number", 3, &kParams_1638[0]},
    {"dist3", "number", 6, &kParams_1638[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1639[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1639[] = {
    {"yawFromDir", "number", 2, &kParams_1639[0]},
    {"pitchFromDir", "number", 3, &kParams_1639[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1640[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1640[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1640[0]},
    {"lerp3x", "number", 3, &kParams_1640[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1641[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1641[] = {
    {"smooth", "number", 3, &kParams_1641[0]},
    {"lerp3x", "number", 3, &kParams_1641[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1642[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1642[] = {
    {"dot3", "number", 6, &kParams_1642[0]},
    {"crossX", "number", 6, &kParams_1642[6]},
    {"crossY", "number", 6, &kParams_1642[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1643[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1643[] = {
    {"len3", "number", 3, &kParams_1643[0]},
    {"normalize3x", "number", 3, &kParams_1643[3]},
    {"normalize3y", "number", 3, &kParams_1643[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1644[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1644[] = {
    {"normalize3z", "number", 3, &kParams_1644[0]},
    {"dist3", "number", 6, &kParams_1644[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1645[] = {
    {"dx", "number"},
    {"dz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1645[] = {
    {"yawFromDir", "number", 2, &kParams_1645[0]},
    {"pitchFromDir", "number", 3, &kParams_1645[2]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1646[] = {
    {"ox", "number"},
    {"oy", "number"},
    {"oz", "number"},
    {"dx", "number"},
    {"dy", "number"},
    {"dz", "number"},
    {"py", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1646[] = {
    {"rayPlaneHitT", "number", 7, &kParams_1646[0]},
    {"lerp3x", "number", 3, &kParams_1646[7]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1647[] = {
    {"cur", "number"},
    {"target", "number"},
    {"dt", "number"},
    {"ax", "number"},
    {"bx", "number"},
    {"t", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1647[] = {
    {"smooth", "number", 3, &kParams_1647[0]},
    {"lerp3x", "number", 3, &kParams_1647[3]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1648[] = {
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {"ax", "number"},
    {"ay", "number"},
    {"az", "number"},
    {"bx", "number"},
    {"by", "number"},
    {"bz", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1648[] = {
    {"dot3", "number", 6, &kParams_1648[0]},
    {"crossX", "number", 6, &kParams_1648[6]},
    {"crossY", "number", 6, &kParams_1648[12]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1649[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1649[] = {
    {"len3", "number", 3, &kParams_1649[0]},
    {"normalize3x", "number", 3, &kParams_1649[3]},
    {"normalize3y", "number", 3, &kParams_1649[6]},
    {nullptr, nullptr, 0, nullptr}
};

const StdlibParamSpec kParams_1650[] = {
    {"x", "number"},
    {"y", "number"},
    {"z", "number"},
    {"x0", "number"},
    {"y0", "number"},
    {"z0", "number"},
    {"x1", "number"},
    {"y1", "number"},
    {"z1", "number"},
    {nullptr, nullptr}
};

const StdlibFuncSpec kFuncs_1650[] = {
    {"normalize3z", "number", 3, &kParams_1650[0]},
    {"dist3", "number", 6, &kParams_1650[3]},
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
    {"game", "game", kFuncs_108, 4, "simple/game.hpp", false},
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
    {"game2dkit001", "game2dkit001", kFuncs_651, 2, "simple/game2dkit001.hpp", false},
    {"game2dkit002", "game2dkit002", kFuncs_652, 2, "simple/game2dkit002.hpp", false},
    {"game2dkit003", "game2dkit003", kFuncs_653, 2, "simple/game2dkit003.hpp", false},
    {"game2dkit004", "game2dkit004", kFuncs_654, 2, "simple/game2dkit004.hpp", false},
    {"game2dkit005", "game2dkit005", kFuncs_655, 2, "simple/game2dkit005.hpp", false},
    {"game2dkit006", "game2dkit006", kFuncs_656, 2, "simple/game2dkit006.hpp", false},
    {"game2dkit007", "game2dkit007", kFuncs_657, 2, "simple/game2dkit007.hpp", false},
    {"game2dkit008", "game2dkit008", kFuncs_658, 2, "simple/game2dkit008.hpp", false},
    {"game2dkit009", "game2dkit009", kFuncs_659, 2, "simple/game2dkit009.hpp", false},
    {"game2dkit010", "game2dkit010", kFuncs_660, 2, "simple/game2dkit010.hpp", false},
    {"game2dkit011", "game2dkit011", kFuncs_661, 2, "simple/game2dkit011.hpp", false},
    {"game2dkit012", "game2dkit012", kFuncs_662, 2, "simple/game2dkit012.hpp", false},
    {"game2dkit013", "game2dkit013", kFuncs_663, 2, "simple/game2dkit013.hpp", false},
    {"game2dkit014", "game2dkit014", kFuncs_664, 2, "simple/game2dkit014.hpp", false},
    {"game2dkit015", "game2dkit015", kFuncs_665, 2, "simple/game2dkit015.hpp", false},
    {"game2dkit016", "game2dkit016", kFuncs_666, 2, "simple/game2dkit016.hpp", false},
    {"game2dkit017", "game2dkit017", kFuncs_667, 2, "simple/game2dkit017.hpp", false},
    {"game2dkit018", "game2dkit018", kFuncs_668, 2, "simple/game2dkit018.hpp", false},
    {"game2dkit019", "game2dkit019", kFuncs_669, 2, "simple/game2dkit019.hpp", false},
    {"game2dkit020", "game2dkit020", kFuncs_670, 2, "simple/game2dkit020.hpp", false},
    {"game2dkit021", "game2dkit021", kFuncs_671, 2, "simple/game2dkit021.hpp", false},
    {"game2dkit022", "game2dkit022", kFuncs_672, 2, "simple/game2dkit022.hpp", false},
    {"game2dkit023", "game2dkit023", kFuncs_673, 2, "simple/game2dkit023.hpp", false},
    {"game2dkit024", "game2dkit024", kFuncs_674, 2, "simple/game2dkit024.hpp", false},
    {"game2dkit025", "game2dkit025", kFuncs_675, 2, "simple/game2dkit025.hpp", false},
    {"game2dkit026", "game2dkit026", kFuncs_676, 2, "simple/game2dkit026.hpp", false},
    {"game2dkit027", "game2dkit027", kFuncs_677, 2, "simple/game2dkit027.hpp", false},
    {"game2dkit028", "game2dkit028", kFuncs_678, 2, "simple/game2dkit028.hpp", false},
    {"game2dkit029", "game2dkit029", kFuncs_679, 2, "simple/game2dkit029.hpp", false},
    {"game2dkit030", "game2dkit030", kFuncs_680, 2, "simple/game2dkit030.hpp", false},
    {"game2dkit031", "game2dkit031", kFuncs_681, 2, "simple/game2dkit031.hpp", false},
    {"game2dkit032", "game2dkit032", kFuncs_682, 2, "simple/game2dkit032.hpp", false},
    {"game2dkit033", "game2dkit033", kFuncs_683, 2, "simple/game2dkit033.hpp", false},
    {"game2dkit034", "game2dkit034", kFuncs_684, 2, "simple/game2dkit034.hpp", false},
    {"game2dkit035", "game2dkit035", kFuncs_685, 2, "simple/game2dkit035.hpp", false},
    {"game2dkit036", "game2dkit036", kFuncs_686, 2, "simple/game2dkit036.hpp", false},
    {"game2dkit037", "game2dkit037", kFuncs_687, 2, "simple/game2dkit037.hpp", false},
    {"game2dkit038", "game2dkit038", kFuncs_688, 2, "simple/game2dkit038.hpp", false},
    {"game2dkit039", "game2dkit039", kFuncs_689, 2, "simple/game2dkit039.hpp", false},
    {"game2dkit040", "game2dkit040", kFuncs_690, 2, "simple/game2dkit040.hpp", false},
    {"game2dkit041", "game2dkit041", kFuncs_691, 2, "simple/game2dkit041.hpp", false},
    {"game2dkit042", "game2dkit042", kFuncs_692, 2, "simple/game2dkit042.hpp", false},
    {"game2dkit043", "game2dkit043", kFuncs_693, 2, "simple/game2dkit043.hpp", false},
    {"game2dkit044", "game2dkit044", kFuncs_694, 2, "simple/game2dkit044.hpp", false},
    {"game2dkit045", "game2dkit045", kFuncs_695, 2, "simple/game2dkit045.hpp", false},
    {"game2dkit046", "game2dkit046", kFuncs_696, 2, "simple/game2dkit046.hpp", false},
    {"game2dkit047", "game2dkit047", kFuncs_697, 2, "simple/game2dkit047.hpp", false},
    {"game2dkit048", "game2dkit048", kFuncs_698, 2, "simple/game2dkit048.hpp", false},
    {"game2dkit049", "game2dkit049", kFuncs_699, 2, "simple/game2dkit049.hpp", false},
    {"game2dkit050", "game2dkit050", kFuncs_700, 2, "simple/game2dkit050.hpp", false},
    {"game2dkit051", "game2dkit051", kFuncs_701, 2, "simple/game2dkit051.hpp", false},
    {"game2dkit052", "game2dkit052", kFuncs_702, 2, "simple/game2dkit052.hpp", false},
    {"game2dkit053", "game2dkit053", kFuncs_703, 2, "simple/game2dkit053.hpp", false},
    {"game2dkit054", "game2dkit054", kFuncs_704, 2, "simple/game2dkit054.hpp", false},
    {"game2dkit055", "game2dkit055", kFuncs_705, 2, "simple/game2dkit055.hpp", false},
    {"game2dkit056", "game2dkit056", kFuncs_706, 2, "simple/game2dkit056.hpp", false},
    {"game2dkit057", "game2dkit057", kFuncs_707, 2, "simple/game2dkit057.hpp", false},
    {"game2dkit058", "game2dkit058", kFuncs_708, 2, "simple/game2dkit058.hpp", false},
    {"game2dkit059", "game2dkit059", kFuncs_709, 2, "simple/game2dkit059.hpp", false},
    {"game2dkit060", "game2dkit060", kFuncs_710, 2, "simple/game2dkit060.hpp", false},
    {"game2dkit061", "game2dkit061", kFuncs_711, 2, "simple/game2dkit061.hpp", false},
    {"game2dkit062", "game2dkit062", kFuncs_712, 2, "simple/game2dkit062.hpp", false},
    {"game2dkit063", "game2dkit063", kFuncs_713, 2, "simple/game2dkit063.hpp", false},
    {"game2dkit064", "game2dkit064", kFuncs_714, 2, "simple/game2dkit064.hpp", false},
    {"game2dkit065", "game2dkit065", kFuncs_715, 2, "simple/game2dkit065.hpp", false},
    {"game2dkit066", "game2dkit066", kFuncs_716, 2, "simple/game2dkit066.hpp", false},
    {"game2dkit067", "game2dkit067", kFuncs_717, 2, "simple/game2dkit067.hpp", false},
    {"game2dkit068", "game2dkit068", kFuncs_718, 2, "simple/game2dkit068.hpp", false},
    {"game2dkit069", "game2dkit069", kFuncs_719, 2, "simple/game2dkit069.hpp", false},
    {"game2dkit070", "game2dkit070", kFuncs_720, 2, "simple/game2dkit070.hpp", false},
    {"game2dkit071", "game2dkit071", kFuncs_721, 2, "simple/game2dkit071.hpp", false},
    {"game2dkit072", "game2dkit072", kFuncs_722, 2, "simple/game2dkit072.hpp", false},
    {"game2dkit073", "game2dkit073", kFuncs_723, 2, "simple/game2dkit073.hpp", false},
    {"game2dkit074", "game2dkit074", kFuncs_724, 2, "simple/game2dkit074.hpp", false},
    {"game2dkit075", "game2dkit075", kFuncs_725, 2, "simple/game2dkit075.hpp", false},
    {"game2dkit076", "game2dkit076", kFuncs_726, 2, "simple/game2dkit076.hpp", false},
    {"game2dkit077", "game2dkit077", kFuncs_727, 2, "simple/game2dkit077.hpp", false},
    {"game2dkit078", "game2dkit078", kFuncs_728, 2, "simple/game2dkit078.hpp", false},
    {"game2dkit079", "game2dkit079", kFuncs_729, 2, "simple/game2dkit079.hpp", false},
    {"game2dkit080", "game2dkit080", kFuncs_730, 2, "simple/game2dkit080.hpp", false},
    {"game2dkit081", "game2dkit081", kFuncs_731, 2, "simple/game2dkit081.hpp", false},
    {"game2dkit082", "game2dkit082", kFuncs_732, 2, "simple/game2dkit082.hpp", false},
    {"game2dkit083", "game2dkit083", kFuncs_733, 2, "simple/game2dkit083.hpp", false},
    {"game2dkit084", "game2dkit084", kFuncs_734, 2, "simple/game2dkit084.hpp", false},
    {"game2dkit085", "game2dkit085", kFuncs_735, 2, "simple/game2dkit085.hpp", false},
    {"game2dkit086", "game2dkit086", kFuncs_736, 2, "simple/game2dkit086.hpp", false},
    {"game2dkit087", "game2dkit087", kFuncs_737, 2, "simple/game2dkit087.hpp", false},
    {"game2dkit088", "game2dkit088", kFuncs_738, 2, "simple/game2dkit088.hpp", false},
    {"game2dkit089", "game2dkit089", kFuncs_739, 2, "simple/game2dkit089.hpp", false},
    {"game2dkit090", "game2dkit090", kFuncs_740, 2, "simple/game2dkit090.hpp", false},
    {"game2dkit091", "game2dkit091", kFuncs_741, 2, "simple/game2dkit091.hpp", false},
    {"game2dkit092", "game2dkit092", kFuncs_742, 2, "simple/game2dkit092.hpp", false},
    {"game2dkit093", "game2dkit093", kFuncs_743, 2, "simple/game2dkit093.hpp", false},
    {"game2dkit094", "game2dkit094", kFuncs_744, 2, "simple/game2dkit094.hpp", false},
    {"game2dkit095", "game2dkit095", kFuncs_745, 2, "simple/game2dkit095.hpp", false},
    {"game2dkit096", "game2dkit096", kFuncs_746, 2, "simple/game2dkit096.hpp", false},
    {"game2dkit097", "game2dkit097", kFuncs_747, 2, "simple/game2dkit097.hpp", false},
    {"game2dkit098", "game2dkit098", kFuncs_748, 2, "simple/game2dkit098.hpp", false},
    {"game2dkit099", "game2dkit099", kFuncs_749, 2, "simple/game2dkit099.hpp", false},
    {"game2dkit100", "game2dkit100", kFuncs_750, 2, "simple/game2dkit100.hpp", false},
    {"game2dkit101", "game2dkit101", kFuncs_751, 2, "simple/game2dkit101.hpp", false},
    {"game2dkit102", "game2dkit102", kFuncs_752, 2, "simple/game2dkit102.hpp", false},
    {"game2dkit103", "game2dkit103", kFuncs_753, 2, "simple/game2dkit103.hpp", false},
    {"game2dkit104", "game2dkit104", kFuncs_754, 2, "simple/game2dkit104.hpp", false},
    {"game2dkit105", "game2dkit105", kFuncs_755, 2, "simple/game2dkit105.hpp", false},
    {"game2dkit106", "game2dkit106", kFuncs_756, 2, "simple/game2dkit106.hpp", false},
    {"game2dkit107", "game2dkit107", kFuncs_757, 2, "simple/game2dkit107.hpp", false},
    {"game2dkit108", "game2dkit108", kFuncs_758, 2, "simple/game2dkit108.hpp", false},
    {"game2dkit109", "game2dkit109", kFuncs_759, 2, "simple/game2dkit109.hpp", false},
    {"game2dkit110", "game2dkit110", kFuncs_760, 2, "simple/game2dkit110.hpp", false},
    {"game2dkit111", "game2dkit111", kFuncs_761, 2, "simple/game2dkit111.hpp", false},
    {"game2dkit112", "game2dkit112", kFuncs_762, 2, "simple/game2dkit112.hpp", false},
    {"game2dkit113", "game2dkit113", kFuncs_763, 2, "simple/game2dkit113.hpp", false},
    {"game2dkit114", "game2dkit114", kFuncs_764, 2, "simple/game2dkit114.hpp", false},
    {"game2dkit115", "game2dkit115", kFuncs_765, 2, "simple/game2dkit115.hpp", false},
    {"game2dkit116", "game2dkit116", kFuncs_766, 2, "simple/game2dkit116.hpp", false},
    {"game2dkit117", "game2dkit117", kFuncs_767, 2, "simple/game2dkit117.hpp", false},
    {"game2dkit118", "game2dkit118", kFuncs_768, 2, "simple/game2dkit118.hpp", false},
    {"game2dkit119", "game2dkit119", kFuncs_769, 2, "simple/game2dkit119.hpp", false},
    {"game2dkit120", "game2dkit120", kFuncs_770, 2, "simple/game2dkit120.hpp", false},
    {"game2dkit121", "game2dkit121", kFuncs_771, 2, "simple/game2dkit121.hpp", false},
    {"game2dkit122", "game2dkit122", kFuncs_772, 2, "simple/game2dkit122.hpp", false},
    {"game2dkit123", "game2dkit123", kFuncs_773, 2, "simple/game2dkit123.hpp", false},
    {"game2dkit124", "game2dkit124", kFuncs_774, 2, "simple/game2dkit124.hpp", false},
    {"game2dkit125", "game2dkit125", kFuncs_775, 2, "simple/game2dkit125.hpp", false},
    {"game2dkit126", "game2dkit126", kFuncs_776, 2, "simple/game2dkit126.hpp", false},
    {"game2dkit127", "game2dkit127", kFuncs_777, 2, "simple/game2dkit127.hpp", false},
    {"game2dkit128", "game2dkit128", kFuncs_778, 2, "simple/game2dkit128.hpp", false},
    {"game2dkit129", "game2dkit129", kFuncs_779, 2, "simple/game2dkit129.hpp", false},
    {"game2dkit130", "game2dkit130", kFuncs_780, 2, "simple/game2dkit130.hpp", false},
    {"game2dkit131", "game2dkit131", kFuncs_781, 2, "simple/game2dkit131.hpp", false},
    {"game2dkit132", "game2dkit132", kFuncs_782, 2, "simple/game2dkit132.hpp", false},
    {"game2dkit133", "game2dkit133", kFuncs_783, 2, "simple/game2dkit133.hpp", false},
    {"game2dkit134", "game2dkit134", kFuncs_784, 2, "simple/game2dkit134.hpp", false},
    {"game2dkit135", "game2dkit135", kFuncs_785, 2, "simple/game2dkit135.hpp", false},
    {"game2dkit136", "game2dkit136", kFuncs_786, 2, "simple/game2dkit136.hpp", false},
    {"game2dkit137", "game2dkit137", kFuncs_787, 2, "simple/game2dkit137.hpp", false},
    {"game2dkit138", "game2dkit138", kFuncs_788, 2, "simple/game2dkit138.hpp", false},
    {"game2dkit139", "game2dkit139", kFuncs_789, 2, "simple/game2dkit139.hpp", false},
    {"game2dkit140", "game2dkit140", kFuncs_790, 2, "simple/game2dkit140.hpp", false},
    {"game2dkit141", "game2dkit141", kFuncs_791, 2, "simple/game2dkit141.hpp", false},
    {"game2dkit142", "game2dkit142", kFuncs_792, 2, "simple/game2dkit142.hpp", false},
    {"game2dkit143", "game2dkit143", kFuncs_793, 2, "simple/game2dkit143.hpp", false},
    {"game2dkit144", "game2dkit144", kFuncs_794, 2, "simple/game2dkit144.hpp", false},
    {"game2dkit145", "game2dkit145", kFuncs_795, 2, "simple/game2dkit145.hpp", false},
    {"game2dkit146", "game2dkit146", kFuncs_796, 2, "simple/game2dkit146.hpp", false},
    {"game2dkit147", "game2dkit147", kFuncs_797, 2, "simple/game2dkit147.hpp", false},
    {"game2dkit148", "game2dkit148", kFuncs_798, 2, "simple/game2dkit148.hpp", false},
    {"game2dkit149", "game2dkit149", kFuncs_799, 2, "simple/game2dkit149.hpp", false},
    {"game2dkit150", "game2dkit150", kFuncs_800, 2, "simple/game2dkit150.hpp", false},
    {"game2dkit151", "game2dkit151", kFuncs_801, 2, "simple/game2dkit151.hpp", false},
    {"game2dkit152", "game2dkit152", kFuncs_802, 2, "simple/game2dkit152.hpp", false},
    {"game2dkit153", "game2dkit153", kFuncs_803, 2, "simple/game2dkit153.hpp", false},
    {"game2dkit154", "game2dkit154", kFuncs_804, 2, "simple/game2dkit154.hpp", false},
    {"game2dkit155", "game2dkit155", kFuncs_805, 2, "simple/game2dkit155.hpp", false},
    {"game2dkit156", "game2dkit156", kFuncs_806, 2, "simple/game2dkit156.hpp", false},
    {"game2dkit157", "game2dkit157", kFuncs_807, 2, "simple/game2dkit157.hpp", false},
    {"game2dkit158", "game2dkit158", kFuncs_808, 2, "simple/game2dkit158.hpp", false},
    {"game2dkit159", "game2dkit159", kFuncs_809, 2, "simple/game2dkit159.hpp", false},
    {"game2dkit160", "game2dkit160", kFuncs_810, 2, "simple/game2dkit160.hpp", false},
    {"game2dkit161", "game2dkit161", kFuncs_811, 2, "simple/game2dkit161.hpp", false},
    {"game2dkit162", "game2dkit162", kFuncs_812, 2, "simple/game2dkit162.hpp", false},
    {"game2dkit163", "game2dkit163", kFuncs_813, 2, "simple/game2dkit163.hpp", false},
    {"game2dkit164", "game2dkit164", kFuncs_814, 2, "simple/game2dkit164.hpp", false},
    {"game2dkit165", "game2dkit165", kFuncs_815, 2, "simple/game2dkit165.hpp", false},
    {"game2dkit166", "game2dkit166", kFuncs_816, 2, "simple/game2dkit166.hpp", false},
    {"game2dkit167", "game2dkit167", kFuncs_817, 2, "simple/game2dkit167.hpp", false},
    {"game2dkit168", "game2dkit168", kFuncs_818, 2, "simple/game2dkit168.hpp", false},
    {"game2dkit169", "game2dkit169", kFuncs_819, 2, "simple/game2dkit169.hpp", false},
    {"game2dkit170", "game2dkit170", kFuncs_820, 2, "simple/game2dkit170.hpp", false},
    {"game2dkit171", "game2dkit171", kFuncs_821, 2, "simple/game2dkit171.hpp", false},
    {"game2dkit172", "game2dkit172", kFuncs_822, 2, "simple/game2dkit172.hpp", false},
    {"game2dkit173", "game2dkit173", kFuncs_823, 2, "simple/game2dkit173.hpp", false},
    {"game2dkit174", "game2dkit174", kFuncs_824, 2, "simple/game2dkit174.hpp", false},
    {"game2dkit175", "game2dkit175", kFuncs_825, 2, "simple/game2dkit175.hpp", false},
    {"game2dkit176", "game2dkit176", kFuncs_826, 2, "simple/game2dkit176.hpp", false},
    {"game2dkit177", "game2dkit177", kFuncs_827, 2, "simple/game2dkit177.hpp", false},
    {"game2dkit178", "game2dkit178", kFuncs_828, 2, "simple/game2dkit178.hpp", false},
    {"game2dkit179", "game2dkit179", kFuncs_829, 2, "simple/game2dkit179.hpp", false},
    {"game2dkit180", "game2dkit180", kFuncs_830, 2, "simple/game2dkit180.hpp", false},
    {"game2dkit181", "game2dkit181", kFuncs_831, 2, "simple/game2dkit181.hpp", false},
    {"game2dkit182", "game2dkit182", kFuncs_832, 2, "simple/game2dkit182.hpp", false},
    {"game2dkit183", "game2dkit183", kFuncs_833, 2, "simple/game2dkit183.hpp", false},
    {"game2dkit184", "game2dkit184", kFuncs_834, 2, "simple/game2dkit184.hpp", false},
    {"game2dkit185", "game2dkit185", kFuncs_835, 2, "simple/game2dkit185.hpp", false},
    {"game2dkit186", "game2dkit186", kFuncs_836, 2, "simple/game2dkit186.hpp", false},
    {"game2dkit187", "game2dkit187", kFuncs_837, 2, "simple/game2dkit187.hpp", false},
    {"game2dkit188", "game2dkit188", kFuncs_838, 2, "simple/game2dkit188.hpp", false},
    {"game2dkit189", "game2dkit189", kFuncs_839, 2, "simple/game2dkit189.hpp", false},
    {"game2dkit190", "game2dkit190", kFuncs_840, 2, "simple/game2dkit190.hpp", false},
    {"game2dkit191", "game2dkit191", kFuncs_841, 2, "simple/game2dkit191.hpp", false},
    {"game2dkit192", "game2dkit192", kFuncs_842, 2, "simple/game2dkit192.hpp", false},
    {"game2dkit193", "game2dkit193", kFuncs_843, 2, "simple/game2dkit193.hpp", false},
    {"game2dkit194", "game2dkit194", kFuncs_844, 2, "simple/game2dkit194.hpp", false},
    {"game2dkit195", "game2dkit195", kFuncs_845, 2, "simple/game2dkit195.hpp", false},
    {"game2dkit196", "game2dkit196", kFuncs_846, 2, "simple/game2dkit196.hpp", false},
    {"game2dkit197", "game2dkit197", kFuncs_847, 2, "simple/game2dkit197.hpp", false},
    {"game2dkit198", "game2dkit198", kFuncs_848, 2, "simple/game2dkit198.hpp", false},
    {"game2dkit199", "game2dkit199", kFuncs_849, 2, "simple/game2dkit199.hpp", false},
    {"game2dkit200", "game2dkit200", kFuncs_850, 2, "simple/game2dkit200.hpp", false},
    {"game2dkit201", "game2dkit201", kFuncs_851, 2, "simple/game2dkit201.hpp", false},
    {"game2dkit202", "game2dkit202", kFuncs_852, 2, "simple/game2dkit202.hpp", false},
    {"game2dkit203", "game2dkit203", kFuncs_853, 2, "simple/game2dkit203.hpp", false},
    {"game2dkit204", "game2dkit204", kFuncs_854, 2, "simple/game2dkit204.hpp", false},
    {"game2dkit205", "game2dkit205", kFuncs_855, 2, "simple/game2dkit205.hpp", false},
    {"game2dkit206", "game2dkit206", kFuncs_856, 2, "simple/game2dkit206.hpp", false},
    {"game2dkit207", "game2dkit207", kFuncs_857, 2, "simple/game2dkit207.hpp", false},
    {"game2dkit208", "game2dkit208", kFuncs_858, 2, "simple/game2dkit208.hpp", false},
    {"game2dkit209", "game2dkit209", kFuncs_859, 2, "simple/game2dkit209.hpp", false},
    {"game2dkit210", "game2dkit210", kFuncs_860, 2, "simple/game2dkit210.hpp", false},
    {"game2dkit211", "game2dkit211", kFuncs_861, 2, "simple/game2dkit211.hpp", false},
    {"game2dkit212", "game2dkit212", kFuncs_862, 2, "simple/game2dkit212.hpp", false},
    {"game2dkit213", "game2dkit213", kFuncs_863, 2, "simple/game2dkit213.hpp", false},
    {"game2dkit214", "game2dkit214", kFuncs_864, 2, "simple/game2dkit214.hpp", false},
    {"game2dkit215", "game2dkit215", kFuncs_865, 2, "simple/game2dkit215.hpp", false},
    {"game2dkit216", "game2dkit216", kFuncs_866, 2, "simple/game2dkit216.hpp", false},
    {"game2dkit217", "game2dkit217", kFuncs_867, 2, "simple/game2dkit217.hpp", false},
    {"game2dkit218", "game2dkit218", kFuncs_868, 2, "simple/game2dkit218.hpp", false},
    {"game2dkit219", "game2dkit219", kFuncs_869, 2, "simple/game2dkit219.hpp", false},
    {"game2dkit220", "game2dkit220", kFuncs_870, 2, "simple/game2dkit220.hpp", false},
    {"game2dkit221", "game2dkit221", kFuncs_871, 2, "simple/game2dkit221.hpp", false},
    {"game2dkit222", "game2dkit222", kFuncs_872, 2, "simple/game2dkit222.hpp", false},
    {"game2dkit223", "game2dkit223", kFuncs_873, 2, "simple/game2dkit223.hpp", false},
    {"game2dkit224", "game2dkit224", kFuncs_874, 2, "simple/game2dkit224.hpp", false},
    {"game2dkit225", "game2dkit225", kFuncs_875, 2, "simple/game2dkit225.hpp", false},
    {"game2dkit226", "game2dkit226", kFuncs_876, 2, "simple/game2dkit226.hpp", false},
    {"game2dkit227", "game2dkit227", kFuncs_877, 2, "simple/game2dkit227.hpp", false},
    {"game2dkit228", "game2dkit228", kFuncs_878, 2, "simple/game2dkit228.hpp", false},
    {"game2dkit229", "game2dkit229", kFuncs_879, 2, "simple/game2dkit229.hpp", false},
    {"game2dkit230", "game2dkit230", kFuncs_880, 2, "simple/game2dkit230.hpp", false},
    {"game2dkit231", "game2dkit231", kFuncs_881, 2, "simple/game2dkit231.hpp", false},
    {"game2dkit232", "game2dkit232", kFuncs_882, 2, "simple/game2dkit232.hpp", false},
    {"game2dkit233", "game2dkit233", kFuncs_883, 2, "simple/game2dkit233.hpp", false},
    {"game2dkit234", "game2dkit234", kFuncs_884, 2, "simple/game2dkit234.hpp", false},
    {"game2dkit235", "game2dkit235", kFuncs_885, 2, "simple/game2dkit235.hpp", false},
    {"game2dkit236", "game2dkit236", kFuncs_886, 2, "simple/game2dkit236.hpp", false},
    {"game2dkit237", "game2dkit237", kFuncs_887, 2, "simple/game2dkit237.hpp", false},
    {"game2dkit238", "game2dkit238", kFuncs_888, 2, "simple/game2dkit238.hpp", false},
    {"game2dkit239", "game2dkit239", kFuncs_889, 2, "simple/game2dkit239.hpp", false},
    {"game2dkit240", "game2dkit240", kFuncs_890, 2, "simple/game2dkit240.hpp", false},
    {"game2dkit241", "game2dkit241", kFuncs_891, 2, "simple/game2dkit241.hpp", false},
    {"game2dkit242", "game2dkit242", kFuncs_892, 2, "simple/game2dkit242.hpp", false},
    {"game2dkit243", "game2dkit243", kFuncs_893, 2, "simple/game2dkit243.hpp", false},
    {"game2dkit244", "game2dkit244", kFuncs_894, 2, "simple/game2dkit244.hpp", false},
    {"game2dkit245", "game2dkit245", kFuncs_895, 2, "simple/game2dkit245.hpp", false},
    {"game2dkit246", "game2dkit246", kFuncs_896, 2, "simple/game2dkit246.hpp", false},
    {"game2dkit247", "game2dkit247", kFuncs_897, 2, "simple/game2dkit247.hpp", false},
    {"game2dkit248", "game2dkit248", kFuncs_898, 2, "simple/game2dkit248.hpp", false},
    {"game2dkit249", "game2dkit249", kFuncs_899, 2, "simple/game2dkit249.hpp", false},
    {"game2dkit250", "game2dkit250", kFuncs_900, 2, "simple/game2dkit250.hpp", false},
    {"game2dkit251", "game2dkit251", kFuncs_901, 2, "simple/game2dkit251.hpp", false},
    {"game2dkit252", "game2dkit252", kFuncs_902, 2, "simple/game2dkit252.hpp", false},
    {"game2dkit253", "game2dkit253", kFuncs_903, 2, "simple/game2dkit253.hpp", false},
    {"game2dkit254", "game2dkit254", kFuncs_904, 2, "simple/game2dkit254.hpp", false},
    {"game2dkit255", "game2dkit255", kFuncs_905, 2, "simple/game2dkit255.hpp", false},
    {"game2dkit256", "game2dkit256", kFuncs_906, 2, "simple/game2dkit256.hpp", false},
    {"game2dkit257", "game2dkit257", kFuncs_907, 2, "simple/game2dkit257.hpp", false},
    {"game2dkit258", "game2dkit258", kFuncs_908, 2, "simple/game2dkit258.hpp", false},
    {"game2dkit259", "game2dkit259", kFuncs_909, 2, "simple/game2dkit259.hpp", false},
    {"game2dkit260", "game2dkit260", kFuncs_910, 2, "simple/game2dkit260.hpp", false},
    {"game2dkit261", "game2dkit261", kFuncs_911, 2, "simple/game2dkit261.hpp", false},
    {"game2dkit262", "game2dkit262", kFuncs_912, 2, "simple/game2dkit262.hpp", false},
    {"game2dkit263", "game2dkit263", kFuncs_913, 2, "simple/game2dkit263.hpp", false},
    {"game2dkit264", "game2dkit264", kFuncs_914, 2, "simple/game2dkit264.hpp", false},
    {"game2dkit265", "game2dkit265", kFuncs_915, 2, "simple/game2dkit265.hpp", false},
    {"game2dkit266", "game2dkit266", kFuncs_916, 2, "simple/game2dkit266.hpp", false},
    {"game2dkit267", "game2dkit267", kFuncs_917, 2, "simple/game2dkit267.hpp", false},
    {"game2dkit268", "game2dkit268", kFuncs_918, 2, "simple/game2dkit268.hpp", false},
    {"game2dkit269", "game2dkit269", kFuncs_919, 2, "simple/game2dkit269.hpp", false},
    {"game2dkit270", "game2dkit270", kFuncs_920, 2, "simple/game2dkit270.hpp", false},
    {"game2dkit271", "game2dkit271", kFuncs_921, 2, "simple/game2dkit271.hpp", false},
    {"game2dkit272", "game2dkit272", kFuncs_922, 2, "simple/game2dkit272.hpp", false},
    {"game2dkit273", "game2dkit273", kFuncs_923, 2, "simple/game2dkit273.hpp", false},
    {"game2dkit274", "game2dkit274", kFuncs_924, 2, "simple/game2dkit274.hpp", false},
    {"game2dkit275", "game2dkit275", kFuncs_925, 2, "simple/game2dkit275.hpp", false},
    {"game2dkit276", "game2dkit276", kFuncs_926, 2, "simple/game2dkit276.hpp", false},
    {"game2dkit277", "game2dkit277", kFuncs_927, 2, "simple/game2dkit277.hpp", false},
    {"game2dkit278", "game2dkit278", kFuncs_928, 2, "simple/game2dkit278.hpp", false},
    {"game2dkit279", "game2dkit279", kFuncs_929, 2, "simple/game2dkit279.hpp", false},
    {"game2dkit280", "game2dkit280", kFuncs_930, 2, "simple/game2dkit280.hpp", false},
    {"game2dkit281", "game2dkit281", kFuncs_931, 2, "simple/game2dkit281.hpp", false},
    {"game2dkit282", "game2dkit282", kFuncs_932, 2, "simple/game2dkit282.hpp", false},
    {"game2dkit283", "game2dkit283", kFuncs_933, 2, "simple/game2dkit283.hpp", false},
    {"game2dkit284", "game2dkit284", kFuncs_934, 2, "simple/game2dkit284.hpp", false},
    {"game2dkit285", "game2dkit285", kFuncs_935, 2, "simple/game2dkit285.hpp", false},
    {"game2dkit286", "game2dkit286", kFuncs_936, 2, "simple/game2dkit286.hpp", false},
    {"game2dkit287", "game2dkit287", kFuncs_937, 2, "simple/game2dkit287.hpp", false},
    {"game2dkit288", "game2dkit288", kFuncs_938, 2, "simple/game2dkit288.hpp", false},
    {"game2dkit289", "game2dkit289", kFuncs_939, 2, "simple/game2dkit289.hpp", false},
    {"game2dkit290", "game2dkit290", kFuncs_940, 2, "simple/game2dkit290.hpp", false},
    {"game2dkit291", "game2dkit291", kFuncs_941, 2, "simple/game2dkit291.hpp", false},
    {"game2dkit292", "game2dkit292", kFuncs_942, 2, "simple/game2dkit292.hpp", false},
    {"game2dkit293", "game2dkit293", kFuncs_943, 2, "simple/game2dkit293.hpp", false},
    {"game2dkit294", "game2dkit294", kFuncs_944, 2, "simple/game2dkit294.hpp", false},
    {"game2dkit295", "game2dkit295", kFuncs_945, 2, "simple/game2dkit295.hpp", false},
    {"game2dkit296", "game2dkit296", kFuncs_946, 2, "simple/game2dkit296.hpp", false},
    {"game2dkit297", "game2dkit297", kFuncs_947, 2, "simple/game2dkit297.hpp", false},
    {"game2dkit298", "game2dkit298", kFuncs_948, 2, "simple/game2dkit298.hpp", false},
    {"game2dkit299", "game2dkit299", kFuncs_949, 2, "simple/game2dkit299.hpp", false},
    {"game2dkit300", "game2dkit300", kFuncs_950, 2, "simple/game2dkit300.hpp", false},
    {"game2dkit301", "game2dkit301", kFuncs_951, 2, "simple/game2dkit301.hpp", false},
    {"game2dkit302", "game2dkit302", kFuncs_952, 2, "simple/game2dkit302.hpp", false},
    {"game2dkit303", "game2dkit303", kFuncs_953, 2, "simple/game2dkit303.hpp", false},
    {"game2dkit304", "game2dkit304", kFuncs_954, 2, "simple/game2dkit304.hpp", false},
    {"game2dkit305", "game2dkit305", kFuncs_955, 2, "simple/game2dkit305.hpp", false},
    {"game2dkit306", "game2dkit306", kFuncs_956, 2, "simple/game2dkit306.hpp", false},
    {"game2dkit307", "game2dkit307", kFuncs_957, 2, "simple/game2dkit307.hpp", false},
    {"game2dkit308", "game2dkit308", kFuncs_958, 2, "simple/game2dkit308.hpp", false},
    {"game2dkit309", "game2dkit309", kFuncs_959, 2, "simple/game2dkit309.hpp", false},
    {"game2dkit310", "game2dkit310", kFuncs_960, 2, "simple/game2dkit310.hpp", false},
    {"game2dkit311", "game2dkit311", kFuncs_961, 2, "simple/game2dkit311.hpp", false},
    {"game2dkit312", "game2dkit312", kFuncs_962, 2, "simple/game2dkit312.hpp", false},
    {"game2dkit313", "game2dkit313", kFuncs_963, 2, "simple/game2dkit313.hpp", false},
    {"game2dkit314", "game2dkit314", kFuncs_964, 2, "simple/game2dkit314.hpp", false},
    {"game2dkit315", "game2dkit315", kFuncs_965, 2, "simple/game2dkit315.hpp", false},
    {"game2dkit316", "game2dkit316", kFuncs_966, 2, "simple/game2dkit316.hpp", false},
    {"game2dkit317", "game2dkit317", kFuncs_967, 2, "simple/game2dkit317.hpp", false},
    {"game2dkit318", "game2dkit318", kFuncs_968, 2, "simple/game2dkit318.hpp", false},
    {"game2dkit319", "game2dkit319", kFuncs_969, 2, "simple/game2dkit319.hpp", false},
    {"game2dkit320", "game2dkit320", kFuncs_970, 2, "simple/game2dkit320.hpp", false},
    {"game2dkit321", "game2dkit321", kFuncs_971, 2, "simple/game2dkit321.hpp", false},
    {"game2dkit322", "game2dkit322", kFuncs_972, 2, "simple/game2dkit322.hpp", false},
    {"game2dkit323", "game2dkit323", kFuncs_973, 2, "simple/game2dkit323.hpp", false},
    {"game2dkit324", "game2dkit324", kFuncs_974, 2, "simple/game2dkit324.hpp", false},
    {"game2dkit325", "game2dkit325", kFuncs_975, 2, "simple/game2dkit325.hpp", false},
    {"game2dkit326", "game2dkit326", kFuncs_976, 2, "simple/game2dkit326.hpp", false},
    {"game2dkit327", "game2dkit327", kFuncs_977, 2, "simple/game2dkit327.hpp", false},
    {"game2dkit328", "game2dkit328", kFuncs_978, 2, "simple/game2dkit328.hpp", false},
    {"game2dkit329", "game2dkit329", kFuncs_979, 2, "simple/game2dkit329.hpp", false},
    {"game2dkit330", "game2dkit330", kFuncs_980, 2, "simple/game2dkit330.hpp", false},
    {"game2dkit331", "game2dkit331", kFuncs_981, 2, "simple/game2dkit331.hpp", false},
    {"game2dkit332", "game2dkit332", kFuncs_982, 2, "simple/game2dkit332.hpp", false},
    {"game2dkit333", "game2dkit333", kFuncs_983, 2, "simple/game2dkit333.hpp", false},
    {"game2dkit334", "game2dkit334", kFuncs_984, 2, "simple/game2dkit334.hpp", false},
    {"game2dkit335", "game2dkit335", kFuncs_985, 2, "simple/game2dkit335.hpp", false},
    {"game2dkit336", "game2dkit336", kFuncs_986, 2, "simple/game2dkit336.hpp", false},
    {"game2dkit337", "game2dkit337", kFuncs_987, 2, "simple/game2dkit337.hpp", false},
    {"game2dkit338", "game2dkit338", kFuncs_988, 2, "simple/game2dkit338.hpp", false},
    {"game2dkit339", "game2dkit339", kFuncs_989, 2, "simple/game2dkit339.hpp", false},
    {"game2dkit340", "game2dkit340", kFuncs_990, 2, "simple/game2dkit340.hpp", false},
    {"game2dkit341", "game2dkit341", kFuncs_991, 2, "simple/game2dkit341.hpp", false},
    {"game2dkit342", "game2dkit342", kFuncs_992, 2, "simple/game2dkit342.hpp", false},
    {"game2dkit343", "game2dkit343", kFuncs_993, 2, "simple/game2dkit343.hpp", false},
    {"game2dkit344", "game2dkit344", kFuncs_994, 2, "simple/game2dkit344.hpp", false},
    {"game2dkit345", "game2dkit345", kFuncs_995, 2, "simple/game2dkit345.hpp", false},
    {"game2dkit346", "game2dkit346", kFuncs_996, 2, "simple/game2dkit346.hpp", false},
    {"game2dkit347", "game2dkit347", kFuncs_997, 2, "simple/game2dkit347.hpp", false},
    {"game2dkit348", "game2dkit348", kFuncs_998, 2, "simple/game2dkit348.hpp", false},
    {"game2dkit349", "game2dkit349", kFuncs_999, 2, "simple/game2dkit349.hpp", false},
    {"game2dkit350", "game2dkit350", kFuncs_1000, 2, "simple/game2dkit350.hpp", false},
    {"game2dkit351", "game2dkit351", kFuncs_1001, 2, "simple/game2dkit351.hpp", false},
    {"game2dkit352", "game2dkit352", kFuncs_1002, 2, "simple/game2dkit352.hpp", false},
    {"game2dkit353", "game2dkit353", kFuncs_1003, 2, "simple/game2dkit353.hpp", false},
    {"game2dkit354", "game2dkit354", kFuncs_1004, 2, "simple/game2dkit354.hpp", false},
    {"game2dkit355", "game2dkit355", kFuncs_1005, 2, "simple/game2dkit355.hpp", false},
    {"game2dkit356", "game2dkit356", kFuncs_1006, 2, "simple/game2dkit356.hpp", false},
    {"game2dkit357", "game2dkit357", kFuncs_1007, 2, "simple/game2dkit357.hpp", false},
    {"game2dkit358", "game2dkit358", kFuncs_1008, 2, "simple/game2dkit358.hpp", false},
    {"game2dkit359", "game2dkit359", kFuncs_1009, 2, "simple/game2dkit359.hpp", false},
    {"game2dkit360", "game2dkit360", kFuncs_1010, 2, "simple/game2dkit360.hpp", false},
    {"game2dkit361", "game2dkit361", kFuncs_1011, 2, "simple/game2dkit361.hpp", false},
    {"game2dkit362", "game2dkit362", kFuncs_1012, 2, "simple/game2dkit362.hpp", false},
    {"game2dkit363", "game2dkit363", kFuncs_1013, 2, "simple/game2dkit363.hpp", false},
    {"game2dkit364", "game2dkit364", kFuncs_1014, 2, "simple/game2dkit364.hpp", false},
    {"game2dkit365", "game2dkit365", kFuncs_1015, 2, "simple/game2dkit365.hpp", false},
    {"game2dkit366", "game2dkit366", kFuncs_1016, 2, "simple/game2dkit366.hpp", false},
    {"game2dkit367", "game2dkit367", kFuncs_1017, 2, "simple/game2dkit367.hpp", false},
    {"game2dkit368", "game2dkit368", kFuncs_1018, 2, "simple/game2dkit368.hpp", false},
    {"game2dkit369", "game2dkit369", kFuncs_1019, 2, "simple/game2dkit369.hpp", false},
    {"game2dkit370", "game2dkit370", kFuncs_1020, 2, "simple/game2dkit370.hpp", false},
    {"game2dkit371", "game2dkit371", kFuncs_1021, 2, "simple/game2dkit371.hpp", false},
    {"game2dkit372", "game2dkit372", kFuncs_1022, 2, "simple/game2dkit372.hpp", false},
    {"game2dkit373", "game2dkit373", kFuncs_1023, 2, "simple/game2dkit373.hpp", false},
    {"game2dkit374", "game2dkit374", kFuncs_1024, 2, "simple/game2dkit374.hpp", false},
    {"game2dkit375", "game2dkit375", kFuncs_1025, 2, "simple/game2dkit375.hpp", false},
    {"game2dkit376", "game2dkit376", kFuncs_1026, 2, "simple/game2dkit376.hpp", false},
    {"game2dkit377", "game2dkit377", kFuncs_1027, 2, "simple/game2dkit377.hpp", false},
    {"game2dkit378", "game2dkit378", kFuncs_1028, 2, "simple/game2dkit378.hpp", false},
    {"game2dkit379", "game2dkit379", kFuncs_1029, 2, "simple/game2dkit379.hpp", false},
    {"game2dkit380", "game2dkit380", kFuncs_1030, 2, "simple/game2dkit380.hpp", false},
    {"game2dkit381", "game2dkit381", kFuncs_1031, 2, "simple/game2dkit381.hpp", false},
    {"game2dkit382", "game2dkit382", kFuncs_1032, 2, "simple/game2dkit382.hpp", false},
    {"game2dkit383", "game2dkit383", kFuncs_1033, 2, "simple/game2dkit383.hpp", false},
    {"game2dkit384", "game2dkit384", kFuncs_1034, 2, "simple/game2dkit384.hpp", false},
    {"game2dkit385", "game2dkit385", kFuncs_1035, 2, "simple/game2dkit385.hpp", false},
    {"game2dkit386", "game2dkit386", kFuncs_1036, 2, "simple/game2dkit386.hpp", false},
    {"game2dkit387", "game2dkit387", kFuncs_1037, 2, "simple/game2dkit387.hpp", false},
    {"game2dkit388", "game2dkit388", kFuncs_1038, 2, "simple/game2dkit388.hpp", false},
    {"game2dkit389", "game2dkit389", kFuncs_1039, 2, "simple/game2dkit389.hpp", false},
    {"game2dkit390", "game2dkit390", kFuncs_1040, 2, "simple/game2dkit390.hpp", false},
    {"game2dkit391", "game2dkit391", kFuncs_1041, 2, "simple/game2dkit391.hpp", false},
    {"game2dkit392", "game2dkit392", kFuncs_1042, 2, "simple/game2dkit392.hpp", false},
    {"game2dkit393", "game2dkit393", kFuncs_1043, 2, "simple/game2dkit393.hpp", false},
    {"game2dkit394", "game2dkit394", kFuncs_1044, 2, "simple/game2dkit394.hpp", false},
    {"game2dkit395", "game2dkit395", kFuncs_1045, 2, "simple/game2dkit395.hpp", false},
    {"game2dkit396", "game2dkit396", kFuncs_1046, 2, "simple/game2dkit396.hpp", false},
    {"game2dkit397", "game2dkit397", kFuncs_1047, 2, "simple/game2dkit397.hpp", false},
    {"game2dkit398", "game2dkit398", kFuncs_1048, 2, "simple/game2dkit398.hpp", false},
    {"game2dkit399", "game2dkit399", kFuncs_1049, 2, "simple/game2dkit399.hpp", false},
    {"game2dkit400", "game2dkit400", kFuncs_1050, 2, "simple/game2dkit400.hpp", false},
    {"game2dkit401", "game2dkit401", kFuncs_1051, 2, "simple/game2dkit401.hpp", false},
    {"game2dkit402", "game2dkit402", kFuncs_1052, 2, "simple/game2dkit402.hpp", false},
    {"game2dkit403", "game2dkit403", kFuncs_1053, 2, "simple/game2dkit403.hpp", false},
    {"game2dkit404", "game2dkit404", kFuncs_1054, 2, "simple/game2dkit404.hpp", false},
    {"game2dkit405", "game2dkit405", kFuncs_1055, 2, "simple/game2dkit405.hpp", false},
    {"game2dkit406", "game2dkit406", kFuncs_1056, 2, "simple/game2dkit406.hpp", false},
    {"game2dkit407", "game2dkit407", kFuncs_1057, 2, "simple/game2dkit407.hpp", false},
    {"game2dkit408", "game2dkit408", kFuncs_1058, 2, "simple/game2dkit408.hpp", false},
    {"game2dkit409", "game2dkit409", kFuncs_1059, 2, "simple/game2dkit409.hpp", false},
    {"game2dkit410", "game2dkit410", kFuncs_1060, 2, "simple/game2dkit410.hpp", false},
    {"game2dkit411", "game2dkit411", kFuncs_1061, 2, "simple/game2dkit411.hpp", false},
    {"game2dkit412", "game2dkit412", kFuncs_1062, 2, "simple/game2dkit412.hpp", false},
    {"game2dkit413", "game2dkit413", kFuncs_1063, 2, "simple/game2dkit413.hpp", false},
    {"game2dkit414", "game2dkit414", kFuncs_1064, 2, "simple/game2dkit414.hpp", false},
    {"game2dkit415", "game2dkit415", kFuncs_1065, 2, "simple/game2dkit415.hpp", false},
    {"game2dkit416", "game2dkit416", kFuncs_1066, 2, "simple/game2dkit416.hpp", false},
    {"game2dkit417", "game2dkit417", kFuncs_1067, 2, "simple/game2dkit417.hpp", false},
    {"game2dkit418", "game2dkit418", kFuncs_1068, 2, "simple/game2dkit418.hpp", false},
    {"game2dkit419", "game2dkit419", kFuncs_1069, 2, "simple/game2dkit419.hpp", false},
    {"game2dkit420", "game2dkit420", kFuncs_1070, 2, "simple/game2dkit420.hpp", false},
    {"game2dkit421", "game2dkit421", kFuncs_1071, 2, "simple/game2dkit421.hpp", false},
    {"game2dkit422", "game2dkit422", kFuncs_1072, 2, "simple/game2dkit422.hpp", false},
    {"game2dkit423", "game2dkit423", kFuncs_1073, 2, "simple/game2dkit423.hpp", false},
    {"game2dkit424", "game2dkit424", kFuncs_1074, 2, "simple/game2dkit424.hpp", false},
    {"game2dkit425", "game2dkit425", kFuncs_1075, 2, "simple/game2dkit425.hpp", false},
    {"game2dkit426", "game2dkit426", kFuncs_1076, 2, "simple/game2dkit426.hpp", false},
    {"game2dkit427", "game2dkit427", kFuncs_1077, 2, "simple/game2dkit427.hpp", false},
    {"game2dkit428", "game2dkit428", kFuncs_1078, 2, "simple/game2dkit428.hpp", false},
    {"game2dkit429", "game2dkit429", kFuncs_1079, 2, "simple/game2dkit429.hpp", false},
    {"game2dkit430", "game2dkit430", kFuncs_1080, 2, "simple/game2dkit430.hpp", false},
    {"game2dkit431", "game2dkit431", kFuncs_1081, 2, "simple/game2dkit431.hpp", false},
    {"game2dkit432", "game2dkit432", kFuncs_1082, 2, "simple/game2dkit432.hpp", false},
    {"game2dkit433", "game2dkit433", kFuncs_1083, 2, "simple/game2dkit433.hpp", false},
    {"game2dkit434", "game2dkit434", kFuncs_1084, 2, "simple/game2dkit434.hpp", false},
    {"game2dkit435", "game2dkit435", kFuncs_1085, 2, "simple/game2dkit435.hpp", false},
    {"game2dkit436", "game2dkit436", kFuncs_1086, 2, "simple/game2dkit436.hpp", false},
    {"game2dkit437", "game2dkit437", kFuncs_1087, 2, "simple/game2dkit437.hpp", false},
    {"game2dkit438", "game2dkit438", kFuncs_1088, 2, "simple/game2dkit438.hpp", false},
    {"game2dkit439", "game2dkit439", kFuncs_1089, 2, "simple/game2dkit439.hpp", false},
    {"game2dkit440", "game2dkit440", kFuncs_1090, 2, "simple/game2dkit440.hpp", false},
    {"game2dkit441", "game2dkit441", kFuncs_1091, 2, "simple/game2dkit441.hpp", false},
    {"game2dkit442", "game2dkit442", kFuncs_1092, 2, "simple/game2dkit442.hpp", false},
    {"game2dkit443", "game2dkit443", kFuncs_1093, 2, "simple/game2dkit443.hpp", false},
    {"game2dkit444", "game2dkit444", kFuncs_1094, 2, "simple/game2dkit444.hpp", false},
    {"game2dkit445", "game2dkit445", kFuncs_1095, 2, "simple/game2dkit445.hpp", false},
    {"game2dkit446", "game2dkit446", kFuncs_1096, 2, "simple/game2dkit446.hpp", false},
    {"game2dkit447", "game2dkit447", kFuncs_1097, 2, "simple/game2dkit447.hpp", false},
    {"game2dkit448", "game2dkit448", kFuncs_1098, 2, "simple/game2dkit448.hpp", false},
    {"game2dkit449", "game2dkit449", kFuncs_1099, 2, "simple/game2dkit449.hpp", false},
    {"game2dkit450", "game2dkit450", kFuncs_1100, 2, "simple/game2dkit450.hpp", false},
    {"game2dkit451", "game2dkit451", kFuncs_1101, 2, "simple/game2dkit451.hpp", false},
    {"game2dkit452", "game2dkit452", kFuncs_1102, 2, "simple/game2dkit452.hpp", false},
    {"game2dkit453", "game2dkit453", kFuncs_1103, 2, "simple/game2dkit453.hpp", false},
    {"game2dkit454", "game2dkit454", kFuncs_1104, 2, "simple/game2dkit454.hpp", false},
    {"game2dkit455", "game2dkit455", kFuncs_1105, 2, "simple/game2dkit455.hpp", false},
    {"game2dkit456", "game2dkit456", kFuncs_1106, 2, "simple/game2dkit456.hpp", false},
    {"game2dkit457", "game2dkit457", kFuncs_1107, 2, "simple/game2dkit457.hpp", false},
    {"game2dkit458", "game2dkit458", kFuncs_1108, 2, "simple/game2dkit458.hpp", false},
    {"game2dkit459", "game2dkit459", kFuncs_1109, 2, "simple/game2dkit459.hpp", false},
    {"game2dkit460", "game2dkit460", kFuncs_1110, 2, "simple/game2dkit460.hpp", false},
    {"game2dkit461", "game2dkit461", kFuncs_1111, 2, "simple/game2dkit461.hpp", false},
    {"game2dkit462", "game2dkit462", kFuncs_1112, 2, "simple/game2dkit462.hpp", false},
    {"game2dkit463", "game2dkit463", kFuncs_1113, 2, "simple/game2dkit463.hpp", false},
    {"game2dkit464", "game2dkit464", kFuncs_1114, 2, "simple/game2dkit464.hpp", false},
    {"game2dkit465", "game2dkit465", kFuncs_1115, 2, "simple/game2dkit465.hpp", false},
    {"game2dkit466", "game2dkit466", kFuncs_1116, 2, "simple/game2dkit466.hpp", false},
    {"game2dkit467", "game2dkit467", kFuncs_1117, 2, "simple/game2dkit467.hpp", false},
    {"game2dkit468", "game2dkit468", kFuncs_1118, 2, "simple/game2dkit468.hpp", false},
    {"game2dkit469", "game2dkit469", kFuncs_1119, 2, "simple/game2dkit469.hpp", false},
    {"game2dkit470", "game2dkit470", kFuncs_1120, 2, "simple/game2dkit470.hpp", false},
    {"game2dkit471", "game2dkit471", kFuncs_1121, 2, "simple/game2dkit471.hpp", false},
    {"game2dkit472", "game2dkit472", kFuncs_1122, 2, "simple/game2dkit472.hpp", false},
    {"game2dkit473", "game2dkit473", kFuncs_1123, 2, "simple/game2dkit473.hpp", false},
    {"game2dkit474", "game2dkit474", kFuncs_1124, 2, "simple/game2dkit474.hpp", false},
    {"game2dkit475", "game2dkit475", kFuncs_1125, 2, "simple/game2dkit475.hpp", false},
    {"game2dkit476", "game2dkit476", kFuncs_1126, 2, "simple/game2dkit476.hpp", false},
    {"game2dkit477", "game2dkit477", kFuncs_1127, 2, "simple/game2dkit477.hpp", false},
    {"game2dkit478", "game2dkit478", kFuncs_1128, 2, "simple/game2dkit478.hpp", false},
    {"game2dkit479", "game2dkit479", kFuncs_1129, 2, "simple/game2dkit479.hpp", false},
    {"game2dkit480", "game2dkit480", kFuncs_1130, 2, "simple/game2dkit480.hpp", false},
    {"game2dkit481", "game2dkit481", kFuncs_1131, 2, "simple/game2dkit481.hpp", false},
    {"game2dkit482", "game2dkit482", kFuncs_1132, 2, "simple/game2dkit482.hpp", false},
    {"game2dkit483", "game2dkit483", kFuncs_1133, 2, "simple/game2dkit483.hpp", false},
    {"game2dkit484", "game2dkit484", kFuncs_1134, 2, "simple/game2dkit484.hpp", false},
    {"game2dkit485", "game2dkit485", kFuncs_1135, 2, "simple/game2dkit485.hpp", false},
    {"game2dkit486", "game2dkit486", kFuncs_1136, 2, "simple/game2dkit486.hpp", false},
    {"game2dkit487", "game2dkit487", kFuncs_1137, 2, "simple/game2dkit487.hpp", false},
    {"game2dkit488", "game2dkit488", kFuncs_1138, 2, "simple/game2dkit488.hpp", false},
    {"game2dkit489", "game2dkit489", kFuncs_1139, 2, "simple/game2dkit489.hpp", false},
    {"game2dkit490", "game2dkit490", kFuncs_1140, 2, "simple/game2dkit490.hpp", false},
    {"game2dkit491", "game2dkit491", kFuncs_1141, 2, "simple/game2dkit491.hpp", false},
    {"game2dkit492", "game2dkit492", kFuncs_1142, 2, "simple/game2dkit492.hpp", false},
    {"game2dkit493", "game2dkit493", kFuncs_1143, 2, "simple/game2dkit493.hpp", false},
    {"game2dkit494", "game2dkit494", kFuncs_1144, 2, "simple/game2dkit494.hpp", false},
    {"game2dkit495", "game2dkit495", kFuncs_1145, 2, "simple/game2dkit495.hpp", false},
    {"game2dkit496", "game2dkit496", kFuncs_1146, 2, "simple/game2dkit496.hpp", false},
    {"game2dkit497", "game2dkit497", kFuncs_1147, 2, "simple/game2dkit497.hpp", false},
    {"game2dkit498", "game2dkit498", kFuncs_1148, 2, "simple/game2dkit498.hpp", false},
    {"game2dkit499", "game2dkit499", kFuncs_1149, 2, "simple/game2dkit499.hpp", false},
    {"game2dkit500", "game2dkit500", kFuncs_1150, 2, "simple/game2dkit500.hpp", false},
    {"game3dkit001", "game3dkit001", kFuncs_1151, 3, "simple/game3dkit001.hpp", false},
    {"game3dkit002", "game3dkit002", kFuncs_1152, 2, "simple/game3dkit002.hpp", false},
    {"game3dkit003", "game3dkit003", kFuncs_1153, 2, "simple/game3dkit003.hpp", false},
    {"game3dkit004", "game3dkit004", kFuncs_1154, 2, "simple/game3dkit004.hpp", false},
    {"game3dkit005", "game3dkit005", kFuncs_1155, 2, "simple/game3dkit005.hpp", false},
    {"game3dkit006", "game3dkit006", kFuncs_1156, 3, "simple/game3dkit006.hpp", false},
    {"game3dkit007", "game3dkit007", kFuncs_1157, 3, "simple/game3dkit007.hpp", false},
    {"game3dkit008", "game3dkit008", kFuncs_1158, 2, "simple/game3dkit008.hpp", false},
    {"game3dkit009", "game3dkit009", kFuncs_1159, 2, "simple/game3dkit009.hpp", false},
    {"game3dkit010", "game3dkit010", kFuncs_1160, 2, "simple/game3dkit010.hpp", false},
    {"game3dkit011", "game3dkit011", kFuncs_1161, 2, "simple/game3dkit011.hpp", false},
    {"game3dkit012", "game3dkit012", kFuncs_1162, 3, "simple/game3dkit012.hpp", false},
    {"game3dkit013", "game3dkit013", kFuncs_1163, 3, "simple/game3dkit013.hpp", false},
    {"game3dkit014", "game3dkit014", kFuncs_1164, 2, "simple/game3dkit014.hpp", false},
    {"game3dkit015", "game3dkit015", kFuncs_1165, 2, "simple/game3dkit015.hpp", false},
    {"game3dkit016", "game3dkit016", kFuncs_1166, 2, "simple/game3dkit016.hpp", false},
    {"game3dkit017", "game3dkit017", kFuncs_1167, 2, "simple/game3dkit017.hpp", false},
    {"game3dkit018", "game3dkit018", kFuncs_1168, 3, "simple/game3dkit018.hpp", false},
    {"game3dkit019", "game3dkit019", kFuncs_1169, 3, "simple/game3dkit019.hpp", false},
    {"game3dkit020", "game3dkit020", kFuncs_1170, 2, "simple/game3dkit020.hpp", false},
    {"game3dkit021", "game3dkit021", kFuncs_1171, 2, "simple/game3dkit021.hpp", false},
    {"game3dkit022", "game3dkit022", kFuncs_1172, 2, "simple/game3dkit022.hpp", false},
    {"game3dkit023", "game3dkit023", kFuncs_1173, 2, "simple/game3dkit023.hpp", false},
    {"game3dkit024", "game3dkit024", kFuncs_1174, 3, "simple/game3dkit024.hpp", false},
    {"game3dkit025", "game3dkit025", kFuncs_1175, 3, "simple/game3dkit025.hpp", false},
    {"game3dkit026", "game3dkit026", kFuncs_1176, 2, "simple/game3dkit026.hpp", false},
    {"game3dkit027", "game3dkit027", kFuncs_1177, 2, "simple/game3dkit027.hpp", false},
    {"game3dkit028", "game3dkit028", kFuncs_1178, 2, "simple/game3dkit028.hpp", false},
    {"game3dkit029", "game3dkit029", kFuncs_1179, 2, "simple/game3dkit029.hpp", false},
    {"game3dkit030", "game3dkit030", kFuncs_1180, 3, "simple/game3dkit030.hpp", false},
    {"game3dkit031", "game3dkit031", kFuncs_1181, 3, "simple/game3dkit031.hpp", false},
    {"game3dkit032", "game3dkit032", kFuncs_1182, 2, "simple/game3dkit032.hpp", false},
    {"game3dkit033", "game3dkit033", kFuncs_1183, 2, "simple/game3dkit033.hpp", false},
    {"game3dkit034", "game3dkit034", kFuncs_1184, 2, "simple/game3dkit034.hpp", false},
    {"game3dkit035", "game3dkit035", kFuncs_1185, 2, "simple/game3dkit035.hpp", false},
    {"game3dkit036", "game3dkit036", kFuncs_1186, 3, "simple/game3dkit036.hpp", false},
    {"game3dkit037", "game3dkit037", kFuncs_1187, 3, "simple/game3dkit037.hpp", false},
    {"game3dkit038", "game3dkit038", kFuncs_1188, 2, "simple/game3dkit038.hpp", false},
    {"game3dkit039", "game3dkit039", kFuncs_1189, 2, "simple/game3dkit039.hpp", false},
    {"game3dkit040", "game3dkit040", kFuncs_1190, 2, "simple/game3dkit040.hpp", false},
    {"game3dkit041", "game3dkit041", kFuncs_1191, 2, "simple/game3dkit041.hpp", false},
    {"game3dkit042", "game3dkit042", kFuncs_1192, 3, "simple/game3dkit042.hpp", false},
    {"game3dkit043", "game3dkit043", kFuncs_1193, 3, "simple/game3dkit043.hpp", false},
    {"game3dkit044", "game3dkit044", kFuncs_1194, 2, "simple/game3dkit044.hpp", false},
    {"game3dkit045", "game3dkit045", kFuncs_1195, 2, "simple/game3dkit045.hpp", false},
    {"game3dkit046", "game3dkit046", kFuncs_1196, 2, "simple/game3dkit046.hpp", false},
    {"game3dkit047", "game3dkit047", kFuncs_1197, 2, "simple/game3dkit047.hpp", false},
    {"game3dkit048", "game3dkit048", kFuncs_1198, 3, "simple/game3dkit048.hpp", false},
    {"game3dkit049", "game3dkit049", kFuncs_1199, 3, "simple/game3dkit049.hpp", false},
    {"game3dkit050", "game3dkit050", kFuncs_1200, 2, "simple/game3dkit050.hpp", false},
    {"game3dkit051", "game3dkit051", kFuncs_1201, 2, "simple/game3dkit051.hpp", false},
    {"game3dkit052", "game3dkit052", kFuncs_1202, 2, "simple/game3dkit052.hpp", false},
    {"game3dkit053", "game3dkit053", kFuncs_1203, 2, "simple/game3dkit053.hpp", false},
    {"game3dkit054", "game3dkit054", kFuncs_1204, 3, "simple/game3dkit054.hpp", false},
    {"game3dkit055", "game3dkit055", kFuncs_1205, 3, "simple/game3dkit055.hpp", false},
    {"game3dkit056", "game3dkit056", kFuncs_1206, 2, "simple/game3dkit056.hpp", false},
    {"game3dkit057", "game3dkit057", kFuncs_1207, 2, "simple/game3dkit057.hpp", false},
    {"game3dkit058", "game3dkit058", kFuncs_1208, 2, "simple/game3dkit058.hpp", false},
    {"game3dkit059", "game3dkit059", kFuncs_1209, 2, "simple/game3dkit059.hpp", false},
    {"game3dkit060", "game3dkit060", kFuncs_1210, 3, "simple/game3dkit060.hpp", false},
    {"game3dkit061", "game3dkit061", kFuncs_1211, 3, "simple/game3dkit061.hpp", false},
    {"game3dkit062", "game3dkit062", kFuncs_1212, 2, "simple/game3dkit062.hpp", false},
    {"game3dkit063", "game3dkit063", kFuncs_1213, 2, "simple/game3dkit063.hpp", false},
    {"game3dkit064", "game3dkit064", kFuncs_1214, 2, "simple/game3dkit064.hpp", false},
    {"game3dkit065", "game3dkit065", kFuncs_1215, 2, "simple/game3dkit065.hpp", false},
    {"game3dkit066", "game3dkit066", kFuncs_1216, 3, "simple/game3dkit066.hpp", false},
    {"game3dkit067", "game3dkit067", kFuncs_1217, 3, "simple/game3dkit067.hpp", false},
    {"game3dkit068", "game3dkit068", kFuncs_1218, 2, "simple/game3dkit068.hpp", false},
    {"game3dkit069", "game3dkit069", kFuncs_1219, 2, "simple/game3dkit069.hpp", false},
    {"game3dkit070", "game3dkit070", kFuncs_1220, 2, "simple/game3dkit070.hpp", false},
    {"game3dkit071", "game3dkit071", kFuncs_1221, 2, "simple/game3dkit071.hpp", false},
    {"game3dkit072", "game3dkit072", kFuncs_1222, 3, "simple/game3dkit072.hpp", false},
    {"game3dkit073", "game3dkit073", kFuncs_1223, 3, "simple/game3dkit073.hpp", false},
    {"game3dkit074", "game3dkit074", kFuncs_1224, 2, "simple/game3dkit074.hpp", false},
    {"game3dkit075", "game3dkit075", kFuncs_1225, 2, "simple/game3dkit075.hpp", false},
    {"game3dkit076", "game3dkit076", kFuncs_1226, 2, "simple/game3dkit076.hpp", false},
    {"game3dkit077", "game3dkit077", kFuncs_1227, 2, "simple/game3dkit077.hpp", false},
    {"game3dkit078", "game3dkit078", kFuncs_1228, 3, "simple/game3dkit078.hpp", false},
    {"game3dkit079", "game3dkit079", kFuncs_1229, 3, "simple/game3dkit079.hpp", false},
    {"game3dkit080", "game3dkit080", kFuncs_1230, 2, "simple/game3dkit080.hpp", false},
    {"game3dkit081", "game3dkit081", kFuncs_1231, 2, "simple/game3dkit081.hpp", false},
    {"game3dkit082", "game3dkit082", kFuncs_1232, 2, "simple/game3dkit082.hpp", false},
    {"game3dkit083", "game3dkit083", kFuncs_1233, 2, "simple/game3dkit083.hpp", false},
    {"game3dkit084", "game3dkit084", kFuncs_1234, 3, "simple/game3dkit084.hpp", false},
    {"game3dkit085", "game3dkit085", kFuncs_1235, 3, "simple/game3dkit085.hpp", false},
    {"game3dkit086", "game3dkit086", kFuncs_1236, 2, "simple/game3dkit086.hpp", false},
    {"game3dkit087", "game3dkit087", kFuncs_1237, 2, "simple/game3dkit087.hpp", false},
    {"game3dkit088", "game3dkit088", kFuncs_1238, 2, "simple/game3dkit088.hpp", false},
    {"game3dkit089", "game3dkit089", kFuncs_1239, 2, "simple/game3dkit089.hpp", false},
    {"game3dkit090", "game3dkit090", kFuncs_1240, 3, "simple/game3dkit090.hpp", false},
    {"game3dkit091", "game3dkit091", kFuncs_1241, 3, "simple/game3dkit091.hpp", false},
    {"game3dkit092", "game3dkit092", kFuncs_1242, 2, "simple/game3dkit092.hpp", false},
    {"game3dkit093", "game3dkit093", kFuncs_1243, 2, "simple/game3dkit093.hpp", false},
    {"game3dkit094", "game3dkit094", kFuncs_1244, 2, "simple/game3dkit094.hpp", false},
    {"game3dkit095", "game3dkit095", kFuncs_1245, 2, "simple/game3dkit095.hpp", false},
    {"game3dkit096", "game3dkit096", kFuncs_1246, 3, "simple/game3dkit096.hpp", false},
    {"game3dkit097", "game3dkit097", kFuncs_1247, 3, "simple/game3dkit097.hpp", false},
    {"game3dkit098", "game3dkit098", kFuncs_1248, 2, "simple/game3dkit098.hpp", false},
    {"game3dkit099", "game3dkit099", kFuncs_1249, 2, "simple/game3dkit099.hpp", false},
    {"game3dkit100", "game3dkit100", kFuncs_1250, 2, "simple/game3dkit100.hpp", false},
    {"game3dkit101", "game3dkit101", kFuncs_1251, 2, "simple/game3dkit101.hpp", false},
    {"game3dkit102", "game3dkit102", kFuncs_1252, 3, "simple/game3dkit102.hpp", false},
    {"game3dkit103", "game3dkit103", kFuncs_1253, 3, "simple/game3dkit103.hpp", false},
    {"game3dkit104", "game3dkit104", kFuncs_1254, 2, "simple/game3dkit104.hpp", false},
    {"game3dkit105", "game3dkit105", kFuncs_1255, 2, "simple/game3dkit105.hpp", false},
    {"game3dkit106", "game3dkit106", kFuncs_1256, 2, "simple/game3dkit106.hpp", false},
    {"game3dkit107", "game3dkit107", kFuncs_1257, 2, "simple/game3dkit107.hpp", false},
    {"game3dkit108", "game3dkit108", kFuncs_1258, 3, "simple/game3dkit108.hpp", false},
    {"game3dkit109", "game3dkit109", kFuncs_1259, 3, "simple/game3dkit109.hpp", false},
    {"game3dkit110", "game3dkit110", kFuncs_1260, 2, "simple/game3dkit110.hpp", false},
    {"game3dkit111", "game3dkit111", kFuncs_1261, 2, "simple/game3dkit111.hpp", false},
    {"game3dkit112", "game3dkit112", kFuncs_1262, 2, "simple/game3dkit112.hpp", false},
    {"game3dkit113", "game3dkit113", kFuncs_1263, 2, "simple/game3dkit113.hpp", false},
    {"game3dkit114", "game3dkit114", kFuncs_1264, 3, "simple/game3dkit114.hpp", false},
    {"game3dkit115", "game3dkit115", kFuncs_1265, 3, "simple/game3dkit115.hpp", false},
    {"game3dkit116", "game3dkit116", kFuncs_1266, 2, "simple/game3dkit116.hpp", false},
    {"game3dkit117", "game3dkit117", kFuncs_1267, 2, "simple/game3dkit117.hpp", false},
    {"game3dkit118", "game3dkit118", kFuncs_1268, 2, "simple/game3dkit118.hpp", false},
    {"game3dkit119", "game3dkit119", kFuncs_1269, 2, "simple/game3dkit119.hpp", false},
    {"game3dkit120", "game3dkit120", kFuncs_1270, 3, "simple/game3dkit120.hpp", false},
    {"game3dkit121", "game3dkit121", kFuncs_1271, 3, "simple/game3dkit121.hpp", false},
    {"game3dkit122", "game3dkit122", kFuncs_1272, 2, "simple/game3dkit122.hpp", false},
    {"game3dkit123", "game3dkit123", kFuncs_1273, 2, "simple/game3dkit123.hpp", false},
    {"game3dkit124", "game3dkit124", kFuncs_1274, 2, "simple/game3dkit124.hpp", false},
    {"game3dkit125", "game3dkit125", kFuncs_1275, 2, "simple/game3dkit125.hpp", false},
    {"game3dkit126", "game3dkit126", kFuncs_1276, 3, "simple/game3dkit126.hpp", false},
    {"game3dkit127", "game3dkit127", kFuncs_1277, 3, "simple/game3dkit127.hpp", false},
    {"game3dkit128", "game3dkit128", kFuncs_1278, 2, "simple/game3dkit128.hpp", false},
    {"game3dkit129", "game3dkit129", kFuncs_1279, 2, "simple/game3dkit129.hpp", false},
    {"game3dkit130", "game3dkit130", kFuncs_1280, 2, "simple/game3dkit130.hpp", false},
    {"game3dkit131", "game3dkit131", kFuncs_1281, 2, "simple/game3dkit131.hpp", false},
    {"game3dkit132", "game3dkit132", kFuncs_1282, 3, "simple/game3dkit132.hpp", false},
    {"game3dkit133", "game3dkit133", kFuncs_1283, 3, "simple/game3dkit133.hpp", false},
    {"game3dkit134", "game3dkit134", kFuncs_1284, 2, "simple/game3dkit134.hpp", false},
    {"game3dkit135", "game3dkit135", kFuncs_1285, 2, "simple/game3dkit135.hpp", false},
    {"game3dkit136", "game3dkit136", kFuncs_1286, 2, "simple/game3dkit136.hpp", false},
    {"game3dkit137", "game3dkit137", kFuncs_1287, 2, "simple/game3dkit137.hpp", false},
    {"game3dkit138", "game3dkit138", kFuncs_1288, 3, "simple/game3dkit138.hpp", false},
    {"game3dkit139", "game3dkit139", kFuncs_1289, 3, "simple/game3dkit139.hpp", false},
    {"game3dkit140", "game3dkit140", kFuncs_1290, 2, "simple/game3dkit140.hpp", false},
    {"game3dkit141", "game3dkit141", kFuncs_1291, 2, "simple/game3dkit141.hpp", false},
    {"game3dkit142", "game3dkit142", kFuncs_1292, 2, "simple/game3dkit142.hpp", false},
    {"game3dkit143", "game3dkit143", kFuncs_1293, 2, "simple/game3dkit143.hpp", false},
    {"game3dkit144", "game3dkit144", kFuncs_1294, 3, "simple/game3dkit144.hpp", false},
    {"game3dkit145", "game3dkit145", kFuncs_1295, 3, "simple/game3dkit145.hpp", false},
    {"game3dkit146", "game3dkit146", kFuncs_1296, 2, "simple/game3dkit146.hpp", false},
    {"game3dkit147", "game3dkit147", kFuncs_1297, 2, "simple/game3dkit147.hpp", false},
    {"game3dkit148", "game3dkit148", kFuncs_1298, 2, "simple/game3dkit148.hpp", false},
    {"game3dkit149", "game3dkit149", kFuncs_1299, 2, "simple/game3dkit149.hpp", false},
    {"game3dkit150", "game3dkit150", kFuncs_1300, 3, "simple/game3dkit150.hpp", false},
    {"game3dkit151", "game3dkit151", kFuncs_1301, 3, "simple/game3dkit151.hpp", false},
    {"game3dkit152", "game3dkit152", kFuncs_1302, 2, "simple/game3dkit152.hpp", false},
    {"game3dkit153", "game3dkit153", kFuncs_1303, 2, "simple/game3dkit153.hpp", false},
    {"game3dkit154", "game3dkit154", kFuncs_1304, 2, "simple/game3dkit154.hpp", false},
    {"game3dkit155", "game3dkit155", kFuncs_1305, 2, "simple/game3dkit155.hpp", false},
    {"game3dkit156", "game3dkit156", kFuncs_1306, 3, "simple/game3dkit156.hpp", false},
    {"game3dkit157", "game3dkit157", kFuncs_1307, 3, "simple/game3dkit157.hpp", false},
    {"game3dkit158", "game3dkit158", kFuncs_1308, 2, "simple/game3dkit158.hpp", false},
    {"game3dkit159", "game3dkit159", kFuncs_1309, 2, "simple/game3dkit159.hpp", false},
    {"game3dkit160", "game3dkit160", kFuncs_1310, 2, "simple/game3dkit160.hpp", false},
    {"game3dkit161", "game3dkit161", kFuncs_1311, 2, "simple/game3dkit161.hpp", false},
    {"game3dkit162", "game3dkit162", kFuncs_1312, 3, "simple/game3dkit162.hpp", false},
    {"game3dkit163", "game3dkit163", kFuncs_1313, 3, "simple/game3dkit163.hpp", false},
    {"game3dkit164", "game3dkit164", kFuncs_1314, 2, "simple/game3dkit164.hpp", false},
    {"game3dkit165", "game3dkit165", kFuncs_1315, 2, "simple/game3dkit165.hpp", false},
    {"game3dkit166", "game3dkit166", kFuncs_1316, 2, "simple/game3dkit166.hpp", false},
    {"game3dkit167", "game3dkit167", kFuncs_1317, 2, "simple/game3dkit167.hpp", false},
    {"game3dkit168", "game3dkit168", kFuncs_1318, 3, "simple/game3dkit168.hpp", false},
    {"game3dkit169", "game3dkit169", kFuncs_1319, 3, "simple/game3dkit169.hpp", false},
    {"game3dkit170", "game3dkit170", kFuncs_1320, 2, "simple/game3dkit170.hpp", false},
    {"game3dkit171", "game3dkit171", kFuncs_1321, 2, "simple/game3dkit171.hpp", false},
    {"game3dkit172", "game3dkit172", kFuncs_1322, 2, "simple/game3dkit172.hpp", false},
    {"game3dkit173", "game3dkit173", kFuncs_1323, 2, "simple/game3dkit173.hpp", false},
    {"game3dkit174", "game3dkit174", kFuncs_1324, 3, "simple/game3dkit174.hpp", false},
    {"game3dkit175", "game3dkit175", kFuncs_1325, 3, "simple/game3dkit175.hpp", false},
    {"game3dkit176", "game3dkit176", kFuncs_1326, 2, "simple/game3dkit176.hpp", false},
    {"game3dkit177", "game3dkit177", kFuncs_1327, 2, "simple/game3dkit177.hpp", false},
    {"game3dkit178", "game3dkit178", kFuncs_1328, 2, "simple/game3dkit178.hpp", false},
    {"game3dkit179", "game3dkit179", kFuncs_1329, 2, "simple/game3dkit179.hpp", false},
    {"game3dkit180", "game3dkit180", kFuncs_1330, 3, "simple/game3dkit180.hpp", false},
    {"game3dkit181", "game3dkit181", kFuncs_1331, 3, "simple/game3dkit181.hpp", false},
    {"game3dkit182", "game3dkit182", kFuncs_1332, 2, "simple/game3dkit182.hpp", false},
    {"game3dkit183", "game3dkit183", kFuncs_1333, 2, "simple/game3dkit183.hpp", false},
    {"game3dkit184", "game3dkit184", kFuncs_1334, 2, "simple/game3dkit184.hpp", false},
    {"game3dkit185", "game3dkit185", kFuncs_1335, 2, "simple/game3dkit185.hpp", false},
    {"game3dkit186", "game3dkit186", kFuncs_1336, 3, "simple/game3dkit186.hpp", false},
    {"game3dkit187", "game3dkit187", kFuncs_1337, 3, "simple/game3dkit187.hpp", false},
    {"game3dkit188", "game3dkit188", kFuncs_1338, 2, "simple/game3dkit188.hpp", false},
    {"game3dkit189", "game3dkit189", kFuncs_1339, 2, "simple/game3dkit189.hpp", false},
    {"game3dkit190", "game3dkit190", kFuncs_1340, 2, "simple/game3dkit190.hpp", false},
    {"game3dkit191", "game3dkit191", kFuncs_1341, 2, "simple/game3dkit191.hpp", false},
    {"game3dkit192", "game3dkit192", kFuncs_1342, 3, "simple/game3dkit192.hpp", false},
    {"game3dkit193", "game3dkit193", kFuncs_1343, 3, "simple/game3dkit193.hpp", false},
    {"game3dkit194", "game3dkit194", kFuncs_1344, 2, "simple/game3dkit194.hpp", false},
    {"game3dkit195", "game3dkit195", kFuncs_1345, 2, "simple/game3dkit195.hpp", false},
    {"game3dkit196", "game3dkit196", kFuncs_1346, 2, "simple/game3dkit196.hpp", false},
    {"game3dkit197", "game3dkit197", kFuncs_1347, 2, "simple/game3dkit197.hpp", false},
    {"game3dkit198", "game3dkit198", kFuncs_1348, 3, "simple/game3dkit198.hpp", false},
    {"game3dkit199", "game3dkit199", kFuncs_1349, 3, "simple/game3dkit199.hpp", false},
    {"game3dkit200", "game3dkit200", kFuncs_1350, 2, "simple/game3dkit200.hpp", false},
    {"game3dkit201", "game3dkit201", kFuncs_1351, 2, "simple/game3dkit201.hpp", false},
    {"game3dkit202", "game3dkit202", kFuncs_1352, 2, "simple/game3dkit202.hpp", false},
    {"game3dkit203", "game3dkit203", kFuncs_1353, 2, "simple/game3dkit203.hpp", false},
    {"game3dkit204", "game3dkit204", kFuncs_1354, 3, "simple/game3dkit204.hpp", false},
    {"game3dkit205", "game3dkit205", kFuncs_1355, 3, "simple/game3dkit205.hpp", false},
    {"game3dkit206", "game3dkit206", kFuncs_1356, 2, "simple/game3dkit206.hpp", false},
    {"game3dkit207", "game3dkit207", kFuncs_1357, 2, "simple/game3dkit207.hpp", false},
    {"game3dkit208", "game3dkit208", kFuncs_1358, 2, "simple/game3dkit208.hpp", false},
    {"game3dkit209", "game3dkit209", kFuncs_1359, 2, "simple/game3dkit209.hpp", false},
    {"game3dkit210", "game3dkit210", kFuncs_1360, 3, "simple/game3dkit210.hpp", false},
    {"game3dkit211", "game3dkit211", kFuncs_1361, 3, "simple/game3dkit211.hpp", false},
    {"game3dkit212", "game3dkit212", kFuncs_1362, 2, "simple/game3dkit212.hpp", false},
    {"game3dkit213", "game3dkit213", kFuncs_1363, 2, "simple/game3dkit213.hpp", false},
    {"game3dkit214", "game3dkit214", kFuncs_1364, 2, "simple/game3dkit214.hpp", false},
    {"game3dkit215", "game3dkit215", kFuncs_1365, 2, "simple/game3dkit215.hpp", false},
    {"game3dkit216", "game3dkit216", kFuncs_1366, 3, "simple/game3dkit216.hpp", false},
    {"game3dkit217", "game3dkit217", kFuncs_1367, 3, "simple/game3dkit217.hpp", false},
    {"game3dkit218", "game3dkit218", kFuncs_1368, 2, "simple/game3dkit218.hpp", false},
    {"game3dkit219", "game3dkit219", kFuncs_1369, 2, "simple/game3dkit219.hpp", false},
    {"game3dkit220", "game3dkit220", kFuncs_1370, 2, "simple/game3dkit220.hpp", false},
    {"game3dkit221", "game3dkit221", kFuncs_1371, 2, "simple/game3dkit221.hpp", false},
    {"game3dkit222", "game3dkit222", kFuncs_1372, 3, "simple/game3dkit222.hpp", false},
    {"game3dkit223", "game3dkit223", kFuncs_1373, 3, "simple/game3dkit223.hpp", false},
    {"game3dkit224", "game3dkit224", kFuncs_1374, 2, "simple/game3dkit224.hpp", false},
    {"game3dkit225", "game3dkit225", kFuncs_1375, 2, "simple/game3dkit225.hpp", false},
    {"game3dkit226", "game3dkit226", kFuncs_1376, 2, "simple/game3dkit226.hpp", false},
    {"game3dkit227", "game3dkit227", kFuncs_1377, 2, "simple/game3dkit227.hpp", false},
    {"game3dkit228", "game3dkit228", kFuncs_1378, 3, "simple/game3dkit228.hpp", false},
    {"game3dkit229", "game3dkit229", kFuncs_1379, 3, "simple/game3dkit229.hpp", false},
    {"game3dkit230", "game3dkit230", kFuncs_1380, 2, "simple/game3dkit230.hpp", false},
    {"game3dkit231", "game3dkit231", kFuncs_1381, 2, "simple/game3dkit231.hpp", false},
    {"game3dkit232", "game3dkit232", kFuncs_1382, 2, "simple/game3dkit232.hpp", false},
    {"game3dkit233", "game3dkit233", kFuncs_1383, 2, "simple/game3dkit233.hpp", false},
    {"game3dkit234", "game3dkit234", kFuncs_1384, 3, "simple/game3dkit234.hpp", false},
    {"game3dkit235", "game3dkit235", kFuncs_1385, 3, "simple/game3dkit235.hpp", false},
    {"game3dkit236", "game3dkit236", kFuncs_1386, 2, "simple/game3dkit236.hpp", false},
    {"game3dkit237", "game3dkit237", kFuncs_1387, 2, "simple/game3dkit237.hpp", false},
    {"game3dkit238", "game3dkit238", kFuncs_1388, 2, "simple/game3dkit238.hpp", false},
    {"game3dkit239", "game3dkit239", kFuncs_1389, 2, "simple/game3dkit239.hpp", false},
    {"game3dkit240", "game3dkit240", kFuncs_1390, 3, "simple/game3dkit240.hpp", false},
    {"game3dkit241", "game3dkit241", kFuncs_1391, 3, "simple/game3dkit241.hpp", false},
    {"game3dkit242", "game3dkit242", kFuncs_1392, 2, "simple/game3dkit242.hpp", false},
    {"game3dkit243", "game3dkit243", kFuncs_1393, 2, "simple/game3dkit243.hpp", false},
    {"game3dkit244", "game3dkit244", kFuncs_1394, 2, "simple/game3dkit244.hpp", false},
    {"game3dkit245", "game3dkit245", kFuncs_1395, 2, "simple/game3dkit245.hpp", false},
    {"game3dkit246", "game3dkit246", kFuncs_1396, 3, "simple/game3dkit246.hpp", false},
    {"game3dkit247", "game3dkit247", kFuncs_1397, 3, "simple/game3dkit247.hpp", false},
    {"game3dkit248", "game3dkit248", kFuncs_1398, 2, "simple/game3dkit248.hpp", false},
    {"game3dkit249", "game3dkit249", kFuncs_1399, 2, "simple/game3dkit249.hpp", false},
    {"game3dkit250", "game3dkit250", kFuncs_1400, 2, "simple/game3dkit250.hpp", false},
    {"game3dkit251", "game3dkit251", kFuncs_1401, 2, "simple/game3dkit251.hpp", false},
    {"game3dkit252", "game3dkit252", kFuncs_1402, 3, "simple/game3dkit252.hpp", false},
    {"game3dkit253", "game3dkit253", kFuncs_1403, 3, "simple/game3dkit253.hpp", false},
    {"game3dkit254", "game3dkit254", kFuncs_1404, 2, "simple/game3dkit254.hpp", false},
    {"game3dkit255", "game3dkit255", kFuncs_1405, 2, "simple/game3dkit255.hpp", false},
    {"game3dkit256", "game3dkit256", kFuncs_1406, 2, "simple/game3dkit256.hpp", false},
    {"game3dkit257", "game3dkit257", kFuncs_1407, 2, "simple/game3dkit257.hpp", false},
    {"game3dkit258", "game3dkit258", kFuncs_1408, 3, "simple/game3dkit258.hpp", false},
    {"game3dkit259", "game3dkit259", kFuncs_1409, 3, "simple/game3dkit259.hpp", false},
    {"game3dkit260", "game3dkit260", kFuncs_1410, 2, "simple/game3dkit260.hpp", false},
    {"game3dkit261", "game3dkit261", kFuncs_1411, 2, "simple/game3dkit261.hpp", false},
    {"game3dkit262", "game3dkit262", kFuncs_1412, 2, "simple/game3dkit262.hpp", false},
    {"game3dkit263", "game3dkit263", kFuncs_1413, 2, "simple/game3dkit263.hpp", false},
    {"game3dkit264", "game3dkit264", kFuncs_1414, 3, "simple/game3dkit264.hpp", false},
    {"game3dkit265", "game3dkit265", kFuncs_1415, 3, "simple/game3dkit265.hpp", false},
    {"game3dkit266", "game3dkit266", kFuncs_1416, 2, "simple/game3dkit266.hpp", false},
    {"game3dkit267", "game3dkit267", kFuncs_1417, 2, "simple/game3dkit267.hpp", false},
    {"game3dkit268", "game3dkit268", kFuncs_1418, 2, "simple/game3dkit268.hpp", false},
    {"game3dkit269", "game3dkit269", kFuncs_1419, 2, "simple/game3dkit269.hpp", false},
    {"game3dkit270", "game3dkit270", kFuncs_1420, 3, "simple/game3dkit270.hpp", false},
    {"game3dkit271", "game3dkit271", kFuncs_1421, 3, "simple/game3dkit271.hpp", false},
    {"game3dkit272", "game3dkit272", kFuncs_1422, 2, "simple/game3dkit272.hpp", false},
    {"game3dkit273", "game3dkit273", kFuncs_1423, 2, "simple/game3dkit273.hpp", false},
    {"game3dkit274", "game3dkit274", kFuncs_1424, 2, "simple/game3dkit274.hpp", false},
    {"game3dkit275", "game3dkit275", kFuncs_1425, 2, "simple/game3dkit275.hpp", false},
    {"game3dkit276", "game3dkit276", kFuncs_1426, 3, "simple/game3dkit276.hpp", false},
    {"game3dkit277", "game3dkit277", kFuncs_1427, 3, "simple/game3dkit277.hpp", false},
    {"game3dkit278", "game3dkit278", kFuncs_1428, 2, "simple/game3dkit278.hpp", false},
    {"game3dkit279", "game3dkit279", kFuncs_1429, 2, "simple/game3dkit279.hpp", false},
    {"game3dkit280", "game3dkit280", kFuncs_1430, 2, "simple/game3dkit280.hpp", false},
    {"game3dkit281", "game3dkit281", kFuncs_1431, 2, "simple/game3dkit281.hpp", false},
    {"game3dkit282", "game3dkit282", kFuncs_1432, 3, "simple/game3dkit282.hpp", false},
    {"game3dkit283", "game3dkit283", kFuncs_1433, 3, "simple/game3dkit283.hpp", false},
    {"game3dkit284", "game3dkit284", kFuncs_1434, 2, "simple/game3dkit284.hpp", false},
    {"game3dkit285", "game3dkit285", kFuncs_1435, 2, "simple/game3dkit285.hpp", false},
    {"game3dkit286", "game3dkit286", kFuncs_1436, 2, "simple/game3dkit286.hpp", false},
    {"game3dkit287", "game3dkit287", kFuncs_1437, 2, "simple/game3dkit287.hpp", false},
    {"game3dkit288", "game3dkit288", kFuncs_1438, 3, "simple/game3dkit288.hpp", false},
    {"game3dkit289", "game3dkit289", kFuncs_1439, 3, "simple/game3dkit289.hpp", false},
    {"game3dkit290", "game3dkit290", kFuncs_1440, 2, "simple/game3dkit290.hpp", false},
    {"game3dkit291", "game3dkit291", kFuncs_1441, 2, "simple/game3dkit291.hpp", false},
    {"game3dkit292", "game3dkit292", kFuncs_1442, 2, "simple/game3dkit292.hpp", false},
    {"game3dkit293", "game3dkit293", kFuncs_1443, 2, "simple/game3dkit293.hpp", false},
    {"game3dkit294", "game3dkit294", kFuncs_1444, 3, "simple/game3dkit294.hpp", false},
    {"game3dkit295", "game3dkit295", kFuncs_1445, 3, "simple/game3dkit295.hpp", false},
    {"game3dkit296", "game3dkit296", kFuncs_1446, 2, "simple/game3dkit296.hpp", false},
    {"game3dkit297", "game3dkit297", kFuncs_1447, 2, "simple/game3dkit297.hpp", false},
    {"game3dkit298", "game3dkit298", kFuncs_1448, 2, "simple/game3dkit298.hpp", false},
    {"game3dkit299", "game3dkit299", kFuncs_1449, 2, "simple/game3dkit299.hpp", false},
    {"game3dkit300", "game3dkit300", kFuncs_1450, 3, "simple/game3dkit300.hpp", false},
    {"game3dkit301", "game3dkit301", kFuncs_1451, 3, "simple/game3dkit301.hpp", false},
    {"game3dkit302", "game3dkit302", kFuncs_1452, 2, "simple/game3dkit302.hpp", false},
    {"game3dkit303", "game3dkit303", kFuncs_1453, 2, "simple/game3dkit303.hpp", false},
    {"game3dkit304", "game3dkit304", kFuncs_1454, 2, "simple/game3dkit304.hpp", false},
    {"game3dkit305", "game3dkit305", kFuncs_1455, 2, "simple/game3dkit305.hpp", false},
    {"game3dkit306", "game3dkit306", kFuncs_1456, 3, "simple/game3dkit306.hpp", false},
    {"game3dkit307", "game3dkit307", kFuncs_1457, 3, "simple/game3dkit307.hpp", false},
    {"game3dkit308", "game3dkit308", kFuncs_1458, 2, "simple/game3dkit308.hpp", false},
    {"game3dkit309", "game3dkit309", kFuncs_1459, 2, "simple/game3dkit309.hpp", false},
    {"game3dkit310", "game3dkit310", kFuncs_1460, 2, "simple/game3dkit310.hpp", false},
    {"game3dkit311", "game3dkit311", kFuncs_1461, 2, "simple/game3dkit311.hpp", false},
    {"game3dkit312", "game3dkit312", kFuncs_1462, 3, "simple/game3dkit312.hpp", false},
    {"game3dkit313", "game3dkit313", kFuncs_1463, 3, "simple/game3dkit313.hpp", false},
    {"game3dkit314", "game3dkit314", kFuncs_1464, 2, "simple/game3dkit314.hpp", false},
    {"game3dkit315", "game3dkit315", kFuncs_1465, 2, "simple/game3dkit315.hpp", false},
    {"game3dkit316", "game3dkit316", kFuncs_1466, 2, "simple/game3dkit316.hpp", false},
    {"game3dkit317", "game3dkit317", kFuncs_1467, 2, "simple/game3dkit317.hpp", false},
    {"game3dkit318", "game3dkit318", kFuncs_1468, 3, "simple/game3dkit318.hpp", false},
    {"game3dkit319", "game3dkit319", kFuncs_1469, 3, "simple/game3dkit319.hpp", false},
    {"game3dkit320", "game3dkit320", kFuncs_1470, 2, "simple/game3dkit320.hpp", false},
    {"game3dkit321", "game3dkit321", kFuncs_1471, 2, "simple/game3dkit321.hpp", false},
    {"game3dkit322", "game3dkit322", kFuncs_1472, 2, "simple/game3dkit322.hpp", false},
    {"game3dkit323", "game3dkit323", kFuncs_1473, 2, "simple/game3dkit323.hpp", false},
    {"game3dkit324", "game3dkit324", kFuncs_1474, 3, "simple/game3dkit324.hpp", false},
    {"game3dkit325", "game3dkit325", kFuncs_1475, 3, "simple/game3dkit325.hpp", false},
    {"game3dkit326", "game3dkit326", kFuncs_1476, 2, "simple/game3dkit326.hpp", false},
    {"game3dkit327", "game3dkit327", kFuncs_1477, 2, "simple/game3dkit327.hpp", false},
    {"game3dkit328", "game3dkit328", kFuncs_1478, 2, "simple/game3dkit328.hpp", false},
    {"game3dkit329", "game3dkit329", kFuncs_1479, 2, "simple/game3dkit329.hpp", false},
    {"game3dkit330", "game3dkit330", kFuncs_1480, 3, "simple/game3dkit330.hpp", false},
    {"game3dkit331", "game3dkit331", kFuncs_1481, 3, "simple/game3dkit331.hpp", false},
    {"game3dkit332", "game3dkit332", kFuncs_1482, 2, "simple/game3dkit332.hpp", false},
    {"game3dkit333", "game3dkit333", kFuncs_1483, 2, "simple/game3dkit333.hpp", false},
    {"game3dkit334", "game3dkit334", kFuncs_1484, 2, "simple/game3dkit334.hpp", false},
    {"game3dkit335", "game3dkit335", kFuncs_1485, 2, "simple/game3dkit335.hpp", false},
    {"game3dkit336", "game3dkit336", kFuncs_1486, 3, "simple/game3dkit336.hpp", false},
    {"game3dkit337", "game3dkit337", kFuncs_1487, 3, "simple/game3dkit337.hpp", false},
    {"game3dkit338", "game3dkit338", kFuncs_1488, 2, "simple/game3dkit338.hpp", false},
    {"game3dkit339", "game3dkit339", kFuncs_1489, 2, "simple/game3dkit339.hpp", false},
    {"game3dkit340", "game3dkit340", kFuncs_1490, 2, "simple/game3dkit340.hpp", false},
    {"game3dkit341", "game3dkit341", kFuncs_1491, 2, "simple/game3dkit341.hpp", false},
    {"game3dkit342", "game3dkit342", kFuncs_1492, 3, "simple/game3dkit342.hpp", false},
    {"game3dkit343", "game3dkit343", kFuncs_1493, 3, "simple/game3dkit343.hpp", false},
    {"game3dkit344", "game3dkit344", kFuncs_1494, 2, "simple/game3dkit344.hpp", false},
    {"game3dkit345", "game3dkit345", kFuncs_1495, 2, "simple/game3dkit345.hpp", false},
    {"game3dkit346", "game3dkit346", kFuncs_1496, 2, "simple/game3dkit346.hpp", false},
    {"game3dkit347", "game3dkit347", kFuncs_1497, 2, "simple/game3dkit347.hpp", false},
    {"game3dkit348", "game3dkit348", kFuncs_1498, 3, "simple/game3dkit348.hpp", false},
    {"game3dkit349", "game3dkit349", kFuncs_1499, 3, "simple/game3dkit349.hpp", false},
    {"game3dkit350", "game3dkit350", kFuncs_1500, 2, "simple/game3dkit350.hpp", false},
    {"game3dkit351", "game3dkit351", kFuncs_1501, 2, "simple/game3dkit351.hpp", false},
    {"game3dkit352", "game3dkit352", kFuncs_1502, 2, "simple/game3dkit352.hpp", false},
    {"game3dkit353", "game3dkit353", kFuncs_1503, 2, "simple/game3dkit353.hpp", false},
    {"game3dkit354", "game3dkit354", kFuncs_1504, 3, "simple/game3dkit354.hpp", false},
    {"game3dkit355", "game3dkit355", kFuncs_1505, 3, "simple/game3dkit355.hpp", false},
    {"game3dkit356", "game3dkit356", kFuncs_1506, 2, "simple/game3dkit356.hpp", false},
    {"game3dkit357", "game3dkit357", kFuncs_1507, 2, "simple/game3dkit357.hpp", false},
    {"game3dkit358", "game3dkit358", kFuncs_1508, 2, "simple/game3dkit358.hpp", false},
    {"game3dkit359", "game3dkit359", kFuncs_1509, 2, "simple/game3dkit359.hpp", false},
    {"game3dkit360", "game3dkit360", kFuncs_1510, 3, "simple/game3dkit360.hpp", false},
    {"game3dkit361", "game3dkit361", kFuncs_1511, 3, "simple/game3dkit361.hpp", false},
    {"game3dkit362", "game3dkit362", kFuncs_1512, 2, "simple/game3dkit362.hpp", false},
    {"game3dkit363", "game3dkit363", kFuncs_1513, 2, "simple/game3dkit363.hpp", false},
    {"game3dkit364", "game3dkit364", kFuncs_1514, 2, "simple/game3dkit364.hpp", false},
    {"game3dkit365", "game3dkit365", kFuncs_1515, 2, "simple/game3dkit365.hpp", false},
    {"game3dkit366", "game3dkit366", kFuncs_1516, 3, "simple/game3dkit366.hpp", false},
    {"game3dkit367", "game3dkit367", kFuncs_1517, 3, "simple/game3dkit367.hpp", false},
    {"game3dkit368", "game3dkit368", kFuncs_1518, 2, "simple/game3dkit368.hpp", false},
    {"game3dkit369", "game3dkit369", kFuncs_1519, 2, "simple/game3dkit369.hpp", false},
    {"game3dkit370", "game3dkit370", kFuncs_1520, 2, "simple/game3dkit370.hpp", false},
    {"game3dkit371", "game3dkit371", kFuncs_1521, 2, "simple/game3dkit371.hpp", false},
    {"game3dkit372", "game3dkit372", kFuncs_1522, 3, "simple/game3dkit372.hpp", false},
    {"game3dkit373", "game3dkit373", kFuncs_1523, 3, "simple/game3dkit373.hpp", false},
    {"game3dkit374", "game3dkit374", kFuncs_1524, 2, "simple/game3dkit374.hpp", false},
    {"game3dkit375", "game3dkit375", kFuncs_1525, 2, "simple/game3dkit375.hpp", false},
    {"game3dkit376", "game3dkit376", kFuncs_1526, 2, "simple/game3dkit376.hpp", false},
    {"game3dkit377", "game3dkit377", kFuncs_1527, 2, "simple/game3dkit377.hpp", false},
    {"game3dkit378", "game3dkit378", kFuncs_1528, 3, "simple/game3dkit378.hpp", false},
    {"game3dkit379", "game3dkit379", kFuncs_1529, 3, "simple/game3dkit379.hpp", false},
    {"game3dkit380", "game3dkit380", kFuncs_1530, 2, "simple/game3dkit380.hpp", false},
    {"game3dkit381", "game3dkit381", kFuncs_1531, 2, "simple/game3dkit381.hpp", false},
    {"game3dkit382", "game3dkit382", kFuncs_1532, 2, "simple/game3dkit382.hpp", false},
    {"game3dkit383", "game3dkit383", kFuncs_1533, 2, "simple/game3dkit383.hpp", false},
    {"game3dkit384", "game3dkit384", kFuncs_1534, 3, "simple/game3dkit384.hpp", false},
    {"game3dkit385", "game3dkit385", kFuncs_1535, 3, "simple/game3dkit385.hpp", false},
    {"game3dkit386", "game3dkit386", kFuncs_1536, 2, "simple/game3dkit386.hpp", false},
    {"game3dkit387", "game3dkit387", kFuncs_1537, 2, "simple/game3dkit387.hpp", false},
    {"game3dkit388", "game3dkit388", kFuncs_1538, 2, "simple/game3dkit388.hpp", false},
    {"game3dkit389", "game3dkit389", kFuncs_1539, 2, "simple/game3dkit389.hpp", false},
    {"game3dkit390", "game3dkit390", kFuncs_1540, 3, "simple/game3dkit390.hpp", false},
    {"game3dkit391", "game3dkit391", kFuncs_1541, 3, "simple/game3dkit391.hpp", false},
    {"game3dkit392", "game3dkit392", kFuncs_1542, 2, "simple/game3dkit392.hpp", false},
    {"game3dkit393", "game3dkit393", kFuncs_1543, 2, "simple/game3dkit393.hpp", false},
    {"game3dkit394", "game3dkit394", kFuncs_1544, 2, "simple/game3dkit394.hpp", false},
    {"game3dkit395", "game3dkit395", kFuncs_1545, 2, "simple/game3dkit395.hpp", false},
    {"game3dkit396", "game3dkit396", kFuncs_1546, 3, "simple/game3dkit396.hpp", false},
    {"game3dkit397", "game3dkit397", kFuncs_1547, 3, "simple/game3dkit397.hpp", false},
    {"game3dkit398", "game3dkit398", kFuncs_1548, 2, "simple/game3dkit398.hpp", false},
    {"game3dkit399", "game3dkit399", kFuncs_1549, 2, "simple/game3dkit399.hpp", false},
    {"game3dkit400", "game3dkit400", kFuncs_1550, 2, "simple/game3dkit400.hpp", false},
    {"game3dkit401", "game3dkit401", kFuncs_1551, 2, "simple/game3dkit401.hpp", false},
    {"game3dkit402", "game3dkit402", kFuncs_1552, 3, "simple/game3dkit402.hpp", false},
    {"game3dkit403", "game3dkit403", kFuncs_1553, 3, "simple/game3dkit403.hpp", false},
    {"game3dkit404", "game3dkit404", kFuncs_1554, 2, "simple/game3dkit404.hpp", false},
    {"game3dkit405", "game3dkit405", kFuncs_1555, 2, "simple/game3dkit405.hpp", false},
    {"game3dkit406", "game3dkit406", kFuncs_1556, 2, "simple/game3dkit406.hpp", false},
    {"game3dkit407", "game3dkit407", kFuncs_1557, 2, "simple/game3dkit407.hpp", false},
    {"game3dkit408", "game3dkit408", kFuncs_1558, 3, "simple/game3dkit408.hpp", false},
    {"game3dkit409", "game3dkit409", kFuncs_1559, 3, "simple/game3dkit409.hpp", false},
    {"game3dkit410", "game3dkit410", kFuncs_1560, 2, "simple/game3dkit410.hpp", false},
    {"game3dkit411", "game3dkit411", kFuncs_1561, 2, "simple/game3dkit411.hpp", false},
    {"game3dkit412", "game3dkit412", kFuncs_1562, 2, "simple/game3dkit412.hpp", false},
    {"game3dkit413", "game3dkit413", kFuncs_1563, 2, "simple/game3dkit413.hpp", false},
    {"game3dkit414", "game3dkit414", kFuncs_1564, 3, "simple/game3dkit414.hpp", false},
    {"game3dkit415", "game3dkit415", kFuncs_1565, 3, "simple/game3dkit415.hpp", false},
    {"game3dkit416", "game3dkit416", kFuncs_1566, 2, "simple/game3dkit416.hpp", false},
    {"game3dkit417", "game3dkit417", kFuncs_1567, 2, "simple/game3dkit417.hpp", false},
    {"game3dkit418", "game3dkit418", kFuncs_1568, 2, "simple/game3dkit418.hpp", false},
    {"game3dkit419", "game3dkit419", kFuncs_1569, 2, "simple/game3dkit419.hpp", false},
    {"game3dkit420", "game3dkit420", kFuncs_1570, 3, "simple/game3dkit420.hpp", false},
    {"game3dkit421", "game3dkit421", kFuncs_1571, 3, "simple/game3dkit421.hpp", false},
    {"game3dkit422", "game3dkit422", kFuncs_1572, 2, "simple/game3dkit422.hpp", false},
    {"game3dkit423", "game3dkit423", kFuncs_1573, 2, "simple/game3dkit423.hpp", false},
    {"game3dkit424", "game3dkit424", kFuncs_1574, 2, "simple/game3dkit424.hpp", false},
    {"game3dkit425", "game3dkit425", kFuncs_1575, 2, "simple/game3dkit425.hpp", false},
    {"game3dkit426", "game3dkit426", kFuncs_1576, 3, "simple/game3dkit426.hpp", false},
    {"game3dkit427", "game3dkit427", kFuncs_1577, 3, "simple/game3dkit427.hpp", false},
    {"game3dkit428", "game3dkit428", kFuncs_1578, 2, "simple/game3dkit428.hpp", false},
    {"game3dkit429", "game3dkit429", kFuncs_1579, 2, "simple/game3dkit429.hpp", false},
    {"game3dkit430", "game3dkit430", kFuncs_1580, 2, "simple/game3dkit430.hpp", false},
    {"game3dkit431", "game3dkit431", kFuncs_1581, 2, "simple/game3dkit431.hpp", false},
    {"game3dkit432", "game3dkit432", kFuncs_1582, 3, "simple/game3dkit432.hpp", false},
    {"game3dkit433", "game3dkit433", kFuncs_1583, 3, "simple/game3dkit433.hpp", false},
    {"game3dkit434", "game3dkit434", kFuncs_1584, 2, "simple/game3dkit434.hpp", false},
    {"game3dkit435", "game3dkit435", kFuncs_1585, 2, "simple/game3dkit435.hpp", false},
    {"game3dkit436", "game3dkit436", kFuncs_1586, 2, "simple/game3dkit436.hpp", false},
    {"game3dkit437", "game3dkit437", kFuncs_1587, 2, "simple/game3dkit437.hpp", false},
    {"game3dkit438", "game3dkit438", kFuncs_1588, 3, "simple/game3dkit438.hpp", false},
    {"game3dkit439", "game3dkit439", kFuncs_1589, 3, "simple/game3dkit439.hpp", false},
    {"game3dkit440", "game3dkit440", kFuncs_1590, 2, "simple/game3dkit440.hpp", false},
    {"game3dkit441", "game3dkit441", kFuncs_1591, 2, "simple/game3dkit441.hpp", false},
    {"game3dkit442", "game3dkit442", kFuncs_1592, 2, "simple/game3dkit442.hpp", false},
    {"game3dkit443", "game3dkit443", kFuncs_1593, 2, "simple/game3dkit443.hpp", false},
    {"game3dkit444", "game3dkit444", kFuncs_1594, 3, "simple/game3dkit444.hpp", false},
    {"game3dkit445", "game3dkit445", kFuncs_1595, 3, "simple/game3dkit445.hpp", false},
    {"game3dkit446", "game3dkit446", kFuncs_1596, 2, "simple/game3dkit446.hpp", false},
    {"game3dkit447", "game3dkit447", kFuncs_1597, 2, "simple/game3dkit447.hpp", false},
    {"game3dkit448", "game3dkit448", kFuncs_1598, 2, "simple/game3dkit448.hpp", false},
    {"game3dkit449", "game3dkit449", kFuncs_1599, 2, "simple/game3dkit449.hpp", false},
    {"game3dkit450", "game3dkit450", kFuncs_1600, 3, "simple/game3dkit450.hpp", false},
    {"game3dkit451", "game3dkit451", kFuncs_1601, 3, "simple/game3dkit451.hpp", false},
    {"game3dkit452", "game3dkit452", kFuncs_1602, 2, "simple/game3dkit452.hpp", false},
    {"game3dkit453", "game3dkit453", kFuncs_1603, 2, "simple/game3dkit453.hpp", false},
    {"game3dkit454", "game3dkit454", kFuncs_1604, 2, "simple/game3dkit454.hpp", false},
    {"game3dkit455", "game3dkit455", kFuncs_1605, 2, "simple/game3dkit455.hpp", false},
    {"game3dkit456", "game3dkit456", kFuncs_1606, 3, "simple/game3dkit456.hpp", false},
    {"game3dkit457", "game3dkit457", kFuncs_1607, 3, "simple/game3dkit457.hpp", false},
    {"game3dkit458", "game3dkit458", kFuncs_1608, 2, "simple/game3dkit458.hpp", false},
    {"game3dkit459", "game3dkit459", kFuncs_1609, 2, "simple/game3dkit459.hpp", false},
    {"game3dkit460", "game3dkit460", kFuncs_1610, 2, "simple/game3dkit460.hpp", false},
    {"game3dkit461", "game3dkit461", kFuncs_1611, 2, "simple/game3dkit461.hpp", false},
    {"game3dkit462", "game3dkit462", kFuncs_1612, 3, "simple/game3dkit462.hpp", false},
    {"game3dkit463", "game3dkit463", kFuncs_1613, 3, "simple/game3dkit463.hpp", false},
    {"game3dkit464", "game3dkit464", kFuncs_1614, 2, "simple/game3dkit464.hpp", false},
    {"game3dkit465", "game3dkit465", kFuncs_1615, 2, "simple/game3dkit465.hpp", false},
    {"game3dkit466", "game3dkit466", kFuncs_1616, 2, "simple/game3dkit466.hpp", false},
    {"game3dkit467", "game3dkit467", kFuncs_1617, 2, "simple/game3dkit467.hpp", false},
    {"game3dkit468", "game3dkit468", kFuncs_1618, 3, "simple/game3dkit468.hpp", false},
    {"game3dkit469", "game3dkit469", kFuncs_1619, 3, "simple/game3dkit469.hpp", false},
    {"game3dkit470", "game3dkit470", kFuncs_1620, 2, "simple/game3dkit470.hpp", false},
    {"game3dkit471", "game3dkit471", kFuncs_1621, 2, "simple/game3dkit471.hpp", false},
    {"game3dkit472", "game3dkit472", kFuncs_1622, 2, "simple/game3dkit472.hpp", false},
    {"game3dkit473", "game3dkit473", kFuncs_1623, 2, "simple/game3dkit473.hpp", false},
    {"game3dkit474", "game3dkit474", kFuncs_1624, 3, "simple/game3dkit474.hpp", false},
    {"game3dkit475", "game3dkit475", kFuncs_1625, 3, "simple/game3dkit475.hpp", false},
    {"game3dkit476", "game3dkit476", kFuncs_1626, 2, "simple/game3dkit476.hpp", false},
    {"game3dkit477", "game3dkit477", kFuncs_1627, 2, "simple/game3dkit477.hpp", false},
    {"game3dkit478", "game3dkit478", kFuncs_1628, 2, "simple/game3dkit478.hpp", false},
    {"game3dkit479", "game3dkit479", kFuncs_1629, 2, "simple/game3dkit479.hpp", false},
    {"game3dkit480", "game3dkit480", kFuncs_1630, 3, "simple/game3dkit480.hpp", false},
    {"game3dkit481", "game3dkit481", kFuncs_1631, 3, "simple/game3dkit481.hpp", false},
    {"game3dkit482", "game3dkit482", kFuncs_1632, 2, "simple/game3dkit482.hpp", false},
    {"game3dkit483", "game3dkit483", kFuncs_1633, 2, "simple/game3dkit483.hpp", false},
    {"game3dkit484", "game3dkit484", kFuncs_1634, 2, "simple/game3dkit484.hpp", false},
    {"game3dkit485", "game3dkit485", kFuncs_1635, 2, "simple/game3dkit485.hpp", false},
    {"game3dkit486", "game3dkit486", kFuncs_1636, 3, "simple/game3dkit486.hpp", false},
    {"game3dkit487", "game3dkit487", kFuncs_1637, 3, "simple/game3dkit487.hpp", false},
    {"game3dkit488", "game3dkit488", kFuncs_1638, 2, "simple/game3dkit488.hpp", false},
    {"game3dkit489", "game3dkit489", kFuncs_1639, 2, "simple/game3dkit489.hpp", false},
    {"game3dkit490", "game3dkit490", kFuncs_1640, 2, "simple/game3dkit490.hpp", false},
    {"game3dkit491", "game3dkit491", kFuncs_1641, 2, "simple/game3dkit491.hpp", false},
    {"game3dkit492", "game3dkit492", kFuncs_1642, 3, "simple/game3dkit492.hpp", false},
    {"game3dkit493", "game3dkit493", kFuncs_1643, 3, "simple/game3dkit493.hpp", false},
    {"game3dkit494", "game3dkit494", kFuncs_1644, 2, "simple/game3dkit494.hpp", false},
    {"game3dkit495", "game3dkit495", kFuncs_1645, 2, "simple/game3dkit495.hpp", false},
    {"game3dkit496", "game3dkit496", kFuncs_1646, 2, "simple/game3dkit496.hpp", false},
    {"game3dkit497", "game3dkit497", kFuncs_1647, 2, "simple/game3dkit497.hpp", false},
    {"game3dkit498", "game3dkit498", kFuncs_1648, 3, "simple/game3dkit498.hpp", false},
    {"game3dkit499", "game3dkit499", kFuncs_1649, 3, "simple/game3dkit499.hpp", false},
    {"game3dkit500", "game3dkit500", kFuncs_1650, 2, "simple/game3dkit500.hpp", false},
    {nullptr, nullptr, nullptr, 0, nullptr, false}
};

const std::size_t kSimpleModuleCount = 1651;

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