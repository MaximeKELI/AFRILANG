#include "afrilang/stdlib_registry.hpp"
#include "afrilang/stdlib_catalog.hpp"
#include "afrilang/medium_catalog.hpp"
#include "afrilang/complex_catalog.hpp"

#include <vector>

namespace afrilang {

namespace {

std::unique_ptr<FunctionNode> makeStubFunction(
    const std::string& name,
    std::initializer_list<std::pair<std::string, std::string>> params,
    std::string returnType,
    bool isAsync = false) {
    std::vector<ParameterNode> paramNodes;
    paramNodes.reserve(params.size());
    for (const auto& [pname, ptype] : params) {
        paramNodes.emplace_back(pname, ptype, nullptr);
    }
    return std::make_unique<FunctionNode>(
        name, std::move(paramNodes), std::move(returnType), false,
        std::vector<std::unique_ptr<StatementNode>>{},
        std::vector<std::string>{},
        false, false, false, isAsync);
}

bool hasModule(const ProgramNode& program, const std::string& name) {
    for (const auto& mod : program.modules) {
        if (mod->name == name) return true;
    }
    return false;
}

void injectModule(ProgramNode& program, const std::string& name,
                  std::vector<std::unique_ptr<FunctionNode>> functions) {
    if (hasModule(program, name)) return;
    auto module = std::make_unique<ModuleNode>(
        name,
        std::vector<std::unique_ptr<ClassNode>>{},
        std::vector<std::unique_ptr<RecordNode>>{},
        std::vector<std::unique_ptr<EnumNode>>{},
        std::vector<std::unique_ptr<FunctionNode>>{});
    for (auto& fn : functions) {
        module->functions.push_back(std::move(fn));
    }
    program.modules.push_back(std::move(module));
}

std::string normalizeImportPath(const std::string& path) {
    std::string p = path;
    if (p.size() > 4 && p.substr(p.size() - 4) == ".afr") {
        p = p.substr(0, p.size() - 4);
    }
    if (p.rfind("std/", 0) == 0) {
        p = p.substr(4);
    }
    return p;
}

} // namespace

bool StdlibRegistry::isLegacyStdlibModule(const std::string& moduleName) {
    return moduleName == "io" || moduleName == "json" || moduleName == "fs" ||
           moduleName == "http" || moduleName == "str" || moduleName == "logging" ||
           moduleName == "math" || moduleName == "stats" || moduleName == "proba" ||
           moduleName == "chrono" || moduleName == "re" ||
           moduleName == "collections" || moduleName == "args" || moduleName == "path" ||
           moduleName == "sql" ||
           moduleName == "web" || moduleName == "orm" || moduleName == "thread" ||
           moduleName == "bigint" ||
           moduleName == "crypto" || moduleName == "process" || moduleName == "net" ||
           moduleName == "yaml" || moduleName == "datetime" ||
           moduleName == "env" || moduleName == "tempfile" || moduleName == "base64" ||
           moduleName == "url" || moduleName == "random" || moduleName == "hex" ||
           moduleName == "csv" || moduleName == "html" || moduleName == "cli" ||
           moduleName == "email" || moduleName == "uuid" ||
           moduleName == "async" || moduleName == "ui" || moduleName == "game2d" ||
           moduleName == "game3d" || moduleName == "gamestate" || moduleName == "gamenet";
}

bool StdlibRegistry::isStdlibModule(const std::string& moduleName) {
    return isLegacyStdlibModule(moduleName) ||
           stdlibCatalogIsSimpleModule(moduleName) ||
           mediumCatalogIsMediumModule(moduleName) ||
           complexCatalogIsComplexModule(moduleName);
}

bool StdlibRegistry::isStdlibImport(const std::string& path) {
    if (path.rfind("std/", 0) != 0 && path.rfind("std\\", 0) != 0) {
        return false;
    }
    const std::string normalized = normalizeImportPath(path);
    if (isLegacyStdlibModule(normalized) ||
        normalized == "log" || normalized == "time" || normalized == "chrono" ||
        normalized == "logging") {
        return true;
    }
    if (normalized.rfind("m/", 0) == 0) {
        return mediumCatalogFindModule(normalized.substr(2)) != nullptr;
    }
    if (normalized.rfind("c/", 0) == 0) {
        return complexCatalogFindModule(normalized.substr(2)) != nullptr;
    }
    return stdlibCatalogFindModule(normalized) != nullptr;
}

std::string StdlibRegistry::stdlibModuleName(const std::string& path) {
    const std::string normalized = normalizeImportPath(path);

    if (normalized == "json") return "json";
    if (normalized == "http") return "http";
    if (normalized == "math") return "math";
    if (normalized == "stats") return "stats";
    if (normalized == "proba") return "proba";
    if (normalized == "process") return "process";
    if (normalized == "net") return "net";
    if (normalized == "log" || normalized == "logging") return "logging";
    if (normalized == "time" || normalized == "chrono") return "chrono";
    if (normalized == "str") return "str";
    if (normalized == "re") return "re";
    if (normalized == "collections") return "collections";
    if (normalized == "args") return "args";
    if (normalized == "path") return "path";
    if (normalized == "async") return "async";
    if (normalized == "ui") return "ui";
    if (normalized == "game2d") return "game2d";
    if (normalized == "game3d") return "game3d";
    if (normalized == "gamestate") return "gamestate";
    if (normalized == "gamenet") return "gamenet";
    if (normalized == "fs") return "fs";
    if (normalized == "io") return "io";
    if (normalized == "sql") return "sql";
    if (normalized == "web") return "web";
    if (normalized == "orm") return "orm";
    if (normalized == "thread") return "thread";
    if (normalized == "bigint") return "bigint";
    if (normalized == "crypto") return "crypto";
    if (normalized == "yaml") return "yaml";
    if (normalized == "datetime") return "datetime";
    if (normalized == "env") return "env";
    if (normalized == "tempfile") return "tempfile";
    if (normalized == "base64") return "base64";
    if (normalized == "url") return "url";
    if (normalized == "random") return "random";
    if (normalized == "hex") return "hex";
    if (normalized == "csv") return "csv";
    if (normalized == "html") return "html";
    if (normalized == "cli") return "cli";
    if (normalized == "email") return "email";
    if (normalized == "uuid") return "uuid";

    if (normalized.rfind("m/", 0) == 0) {
        if (const StdlibModuleSpec* spec = mediumCatalogFindModule(normalized.substr(2))) {
            return spec->moduleName;
        }
        return "";
    }

    if (normalized.rfind("c/", 0) == 0) {
        if (const StdlibModuleSpec* spec = complexCatalogFindModule(normalized.substr(2))) {
            return spec->moduleName;
        }
        return "";
    }

    if (const StdlibModuleSpec* spec = stdlibCatalogFindModule(normalized)) {
        return spec->moduleName;
    }
    return "";
}

void StdlibRegistry::injectCatalogModule(ProgramNode& program,
                                         const std::string& moduleName) {
    const StdlibModuleSpec* spec = stdlibCatalogFindModule(moduleName);
    if (!spec) spec = mediumCatalogFindModule(moduleName);
    if (!spec) spec = complexCatalogFindModule(moduleName);
    if (!spec) return;

    std::vector<std::unique_ptr<FunctionNode>> fns;
    for (std::size_t i = 0; i < spec->functionCount; ++i) {
        const StdlibFuncSpec& fn = spec->functions[i];
        std::vector<ParameterNode> paramNodes;
        for (std::size_t p = 0; p < fn.paramCount; ++p) {
            paramNodes.emplace_back(fn.params[p].name, fn.params[p].typeName, nullptr);
        }
        fns.push_back(std::make_unique<FunctionNode>(
            fn.name, std::move(paramNodes),
            fn.returnType ? std::string(fn.returnType) : std::string{},
            false, std::vector<std::unique_ptr<StatementNode>>{},
            std::vector<std::string>{}, false, false, false, false));
    }
    injectModule(program, spec->moduleName, std::move(fns));
}

void StdlibRegistry::injectModuleByName(ProgramNode& program,
                                        const std::string& moduleName) {
    if (moduleName == "io") injectIoModule(program);
    else if (moduleName == "json") injectJsonModule(program);
    else if (moduleName == "fs") injectFsModule(program);
    else if (moduleName == "http") injectHttpModule(program);
    else if (moduleName == "str") injectStrModule(program);
    else if (moduleName == "logging") injectLogModule(program);
    else if (moduleName == "math") injectMathModule(program);
    else if (moduleName == "stats") injectStatsModule(program);
    else if (moduleName == "proba") injectProbaModule(program);
    else if (moduleName == "chrono") injectTimeModule(program);
    else if (moduleName == "re") injectReModule(program);
    else if (moduleName == "collections") injectCollectionsModule(program);
    else if (moduleName == "args") injectArgsModule(program);
    else if (moduleName == "path") injectPathModule(program);
    else if (moduleName == "sql") injectSqlModule(program);
    else if (moduleName == "web") injectWebModule(program);
    else if (moduleName == "orm") injectOrmModule(program);
    else if (moduleName == "thread") injectThreadModule(program);
    else if (moduleName == "bigint") injectBigintModule(program);
    else if (moduleName == "crypto") injectCryptoModule(program);
    else if (moduleName == "process") injectProcessModule(program);
    else if (moduleName == "net") injectNetModule(program);
    else if (moduleName == "yaml") injectYamlModule(program);
    else if (moduleName == "datetime") injectDatetimeModule(program);
    else if (moduleName == "env") injectEnvModule(program);
    else if (moduleName == "tempfile") injectTempfileModule(program);
    else if (moduleName == "base64") injectBase64Module(program);
    else if (moduleName == "url") injectUrlModule(program);
    else if (moduleName == "random") injectRandomModule(program);
    else if (moduleName == "hex") injectHexModule(program);
    else if (moduleName == "csv") injectCsvModule(program);
    else if (moduleName == "html") injectHtmlModule(program);
    else if (moduleName == "cli") injectCliModule(program);
    else if (moduleName == "email") injectEmailModule(program);
    else if (moduleName == "uuid") injectUuidModule(program);
    else if (moduleName == "async") injectAsyncModule(program);
    else if (moduleName == "ui") injectUiModule(program);
    else if (moduleName == "game2d") injectGame2dModule(program);
    else if (moduleName == "game3d") injectGame3dModule(program);
    else if (moduleName == "gamestate") injectGamestateModule(program);
    else if (moduleName == "gamenet") injectGamenetModule(program);
    else injectCatalogModule(program, moduleName);
}

void StdlibRegistry::injectIoModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("readFile", {{"path", "text"}}, "text"));
    fns.push_back(makeStubFunction("writeFile", {{"path", "text"}, {"content", "text"}}, ""));
    fns.push_back(makeStubFunction("fileExists", {{"path", "text"}}, "bool"));
    fns.push_back(makeStubFunction("readLine", {}, "text"));
    fns.push_back(makeStubFunction("readFileAsync", {{"path", "text"}}, "text", true));
    injectModule(program, "io", std::move(fns));
}

void StdlibRegistry::injectJsonModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("parse", {{"text", "text"}}, "json"));
    fns.push_back(makeStubFunction("stringify", {{"value", "json"}}, "text"));
    fns.push_back(makeStubFunction("getString", {{"value", "json"}, {"key", "text"}}, "text"));
    fns.push_back(makeStubFunction("getNumber", {{"value", "json"}, {"key", "text"}}, "number"));
    fns.push_back(makeStubFunction("getInt", {{"value", "json"}, {"key", "text"}}, "int"));
    fns.push_back(makeStubFunction("getBool", {{"value", "json"}, {"key", "text"}}, "bool"));
    fns.push_back(makeStubFunction("has", {{"value", "json"}, {"key", "text"}}, "bool"));
    fns.push_back(makeStubFunction("arrayLength", {{"value", "json"}}, "int"));
    fns.push_back(makeStubFunction("arrayGet", {{"value", "json"}, {"index", "number"}}, "json"));
    fns.push_back(makeStubFunction("getPath", {{"value", "json"}, {"path", "text"}}, "json"));
    fns.push_back(makeStubFunction("stringifyPretty", {{"value", "json"}, {"indent", "number"}}, "text"));
    fns.push_back(makeStubFunction("makeObject", {{"key", "text"}, {"value", "text"}}, "json"));
    injectModule(program, "json", std::move(fns));
}

void StdlibRegistry::injectFsModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("listDir", {{"path", "text"}}, "list text"));
    fns.push_back(makeStubFunction("makeDir", {{"path", "text"}}, "bool"));
    fns.push_back(makeStubFunction("removeFile", {{"path", "text"}}, "bool"));
    fns.push_back(makeStubFunction("fileSize", {{"path", "text"}}, "number"));
    injectModule(program, "fs", std::move(fns));
}

void StdlibRegistry::injectHttpModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("httpGet", {{"url", "text"}}, "text"));
    fns.push_back(makeStubFunction("httpPost", {{"url", "text"}, {"body", "text"}}, "text"));
    fns.push_back(makeStubFunction("httpGetAsync", {{"url", "text"}}, "text", true));
    fns.push_back(makeStubFunction("httpPostAsync", {{"url", "text"}, {"body", "text"}}, "text", true));
    injectModule(program, "http", std::move(fns));
}

void StdlibRegistry::injectStrModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("trim", {{"text", "text"}}, "text"));
    fns.push_back(makeStubFunction("contains", {{"text", "text"}, {"needle", "text"}}, "bool"));
    fns.push_back(makeStubFunction("replace", {{"text", "text"}, {"from", "text"}, {"to", "text"}}, "text"));
    fns.push_back(makeStubFunction("split", {{"text", "text"}, {"sep", "text"}}, "list text"));
    fns.push_back(makeStubFunction("join", {{"parts", "list text"}, {"sep", "text"}}, "text"));
    injectModule(program, "str", std::move(fns));
}

void StdlibRegistry::injectLogModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("info", {{"message", "text"}}, ""));
    fns.push_back(makeStubFunction("warn", {{"message", "text"}}, ""));
    fns.push_back(makeStubFunction("error", {{"message", "text"}}, ""));
    injectModule(program, "logging", std::move(fns));
}

void StdlibRegistry::injectMathModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("abs", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("fabs", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("floor", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("ceil", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("trunc", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("round", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("sqrt", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("cbrt", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("isqrt", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("exp", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("exp2", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("expm1", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("log", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("ln", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("log1p", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("log2", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("log10", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("sin", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("cos", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("tan", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("asin", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("acos", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("atan", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("sinh", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("cosh", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("tanh", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("asinh", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("acosh", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("atanh", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("arcsin", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("arccos", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("arctan", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("arcsinh", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("arccosh", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("arctanh", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("sec", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("csc", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("cot", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("sech", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("csch", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("coth", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("arcsec", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("arccsc", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("arccot", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("arcsech", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("arccsch", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("arccoth", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("sign", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("sgn", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("frexpMantissa", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("frexpExp", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("modfInt", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("modfFrac", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("ulp", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("factorial", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("fac", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("erf", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("erfc", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("gamma", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("lgamma", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("classify", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("nextPowerOfTwo", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("deg2rad", {{"degrees", "number"}}, "number"));
    fns.push_back(makeStubFunction("radians", {{"degrees", "number"}}, "number"));
    fns.push_back(makeStubFunction("degToRad", {{"degrees", "number"}}, "number"));
    fns.push_back(makeStubFunction("rad2deg", {{"radians", "number"}}, "number"));
    fns.push_back(makeStubFunction("degrees", {{"radians", "number"}}, "number"));
    fns.push_back(makeStubFunction("radToDeg", {{"radians", "number"}}, "number"));
    fns.push_back(makeStubFunction("pow", {{"base", "number"}, {"exp", "number"}}, "number"));
    fns.push_back(makeStubFunction("atan2", {{"y", "number"}, {"x", "number"}}, "number"));
    fns.push_back(makeStubFunction("arctan2", {{"y", "number"}, {"x", "number"}}, "number"));
    fns.push_back(makeStubFunction("hypot", {{"x", "number"}, {"y", "number"}}, "number"));
    fns.push_back(makeStubFunction("hypot3", {{"x", "number"}, {"y", "number"}, {"z", "number"}}, "number"));
    fns.push_back(makeStubFunction("min", {{"a", "number"}, {"b", "number"}}, "number"));
    fns.push_back(makeStubFunction("max", {{"a", "number"}, {"b", "number"}}, "number"));
    fns.push_back(makeStubFunction("clamp", {{"value", "number"}, {"lo", "number"}, {"hi", "number"}}, "number"));
    fns.push_back(makeStubFunction("lerp", {{"a", "number"}, {"b", "number"}, {"t", "number"}}, "number"));
    fns.push_back(makeStubFunction("fma", {{"x", "number"}, {"y", "number"}, {"z", "number"}}, "number"));
    fns.push_back(makeStubFunction("copysign", {{"mag", "number"}, {"sgn", "number"}}, "number"));
    fns.push_back(makeStubFunction("copySign", {{"x", "number"}, {"y", "number"}}, "number"));
    fns.push_back(makeStubFunction("fmod", {{"x", "number"}, {"y", "number"}}, "number"));
    fns.push_back(makeStubFunction("remainder", {{"x", "number"}, {"y", "number"}}, "number"));
    fns.push_back(makeStubFunction("floorDiv", {{"x", "number"}, {"y", "number"}}, "number"));
    fns.push_back(makeStubFunction("floorMod", {{"x", "number"}, {"y", "number"}}, "number"));
    fns.push_back(makeStubFunction("euclDiv", {{"x", "number"}, {"y", "number"}}, "number"));
    fns.push_back(makeStubFunction("euclMod", {{"x", "number"}, {"y", "number"}}, "number"));
    fns.push_back(makeStubFunction("ldexp", {{"x", "number"}, {"i", "number"}}, "number"));
    fns.push_back(makeStubFunction("nextafter", {{"x", "number"}, {"y", "number"}}, "number"));
    fns.push_back(makeStubFunction("gcd", {{"a", "number"}, {"b", "number"}}, "number"));
    fns.push_back(makeStubFunction("lcm", {{"a", "number"}, {"b", "number"}}, "number"));
    fns.push_back(makeStubFunction("perm", {{"n", "number"}, {"k", "number"}}, "number"));
    fns.push_back(makeStubFunction("comb", {{"n", "number"}, {"k", "number"}}, "number"));
    fns.push_back(makeStubFunction("binom", {{"n", "number"}, {"k", "number"}}, "number"));
    fns.push_back(makeStubFunction("logBase", {{"value", "number"}, {"base", "number"}}, "number"));
    fns.push_back(makeStubFunction("roundPlaces", {{"value", "number"}, {"places", "number"}}, "number"));
    fns.push_back(makeStubFunction("isFinite", {{"value", "number"}}, "bool"));
    fns.push_back(makeStubFunction("isInf", {{"value", "number"}}, "bool"));
    fns.push_back(makeStubFunction("isNan", {{"value", "number"}}, "bool"));
    fns.push_back(makeStubFunction("isNaN", {{"value", "number"}}, "bool"));
    fns.push_back(makeStubFunction("isClose", {{"a", "number"}, {"b", "number"}, {"relTol", "number"}, {"absTol", "number"}}, "bool"));
    fns.push_back(makeStubFunction("almostEqual", {{"a", "number"}, {"b", "number"}}, "bool"));
    fns.push_back(makeStubFunction("isPowerOfTwo", {{"x", "number"}}, "bool"));
    fns.push_back(makeStubFunction("signbit", {{"value", "number"}}, "bool"));
    fns.push_back(makeStubFunction("pi", {}, "number"));
    fns.push_back(makeStubFunction("e", {}, "number"));
    fns.push_back(makeStubFunction("tau", {}, "number"));
    fns.push_back(makeStubFunction("inf", {}, "number"));
    fns.push_back(makeStubFunction("nan", {}, "number"));
    fns.push_back(makeStubFunction("random", {}, "number"));
    fns.push_back(makeStubFunction("fsum", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("sum", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("prod", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("sumprod", {{"a", "list number"}, {"b", "list number"}}, "number"));
    fns.push_back(makeStubFunction("dist", {{"p", "list number"}, {"q", "list number"}}, "number"));
    fns.push_back(makeStubFunction("cumsummed", {{"v", "list number"}}, "list number"));
    fns.push_back(makeStubFunction("cumproded", {{"v", "list number"}}, "list number"));
    injectModule(program, "math", std::move(fns));
}


void StdlibRegistry::injectStatsModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("count", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("sum", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("fsum", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("product", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("mean", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("fmean", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("geometricMean", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("harmonicMean", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("rms", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("median", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("medianLow", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("medianHigh", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("medianGrouped", {{"v", "list number"}, {"interval", "number"}}, "number"));
    fns.push_back(makeStubFunction("mode", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("multimode", {{"v", "list number"}}, "list number"));
    fns.push_back(makeStubFunction("minVal", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("maxVal", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("range", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("variance", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("stddev", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("popVariance", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("popStddev", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("pvariance", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("pstdev", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("varianceS", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("standardDeviation", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("standardDeviationS", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("seMean", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("cv", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("q1", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("q3", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("iqr", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("midhinge", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("mad", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("trimmedMean", {{"v", "list number"}, {"pct", "number"}}, "number"));
    fns.push_back(makeStubFunction("percentile", {{"v", "list number"}, {"p", "number"}}, "number"));
    fns.push_back(makeStubFunction("quantile", {{"v", "list number"}, {"q", "number"}}, "number"));
    fns.push_back(makeStubFunction("quantiles", {{"v", "list number"}, {"n", "number"}}, "list number"));
    fns.push_back(makeStubFunction("skewness", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("kurtosis", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("skewnessS", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("kurtosisS", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("covariance", {{"a", "list number"}, {"b", "list number"}}, "number"));
    fns.push_back(makeStubFunction("covariancePop", {{"a", "list number"}, {"b", "list number"}}, "number"));
    fns.push_back(makeStubFunction("correlation", {{"a", "list number"}, {"b", "list number"}}, "number"));
    fns.push_back(makeStubFunction("pearsonr", {{"a", "list number"}, {"b", "list number"}}, "number"));
    fns.push_back(makeStubFunction("linRegSlope", {{"x", "list number"}, {"y", "list number"}}, "number"));
    fns.push_back(makeStubFunction("linRegIntercept", {{"x", "list number"}, {"y", "list number"}}, "number"));
    fns.push_back(makeStubFunction("linRegPredict", {{"x", "list number"}, {"y", "list number"}, {"xv", "number"}}, "number"));
    fns.push_back(makeStubFunction("cumSum", {{"v", "list number"}}, "list number"));
    fns.push_back(makeStubFunction("cumProd", {{"v", "list number"}}, "list number"));
    fns.push_back(makeStubFunction("diffs", {{"v", "list number"}}, "list number"));
    fns.push_back(makeStubFunction("zScores", {{"v", "list number"}}, "list number"));
    fns.push_back(makeStubFunction("normalize", {{"v", "list number"}}, "list number"));
    fns.push_back(makeStubFunction("ranks", {{"v", "list number"}}, "list number"));
    fns.push_back(makeStubFunction("movingAvg", {{"v", "list number"}, {"window", "number"}}, "list number"));
    fns.push_back(makeStubFunction("outlierIndices", {{"v", "list number"}}, "list number"));
    fns.push_back(makeStubFunction("outlierCount", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("withoutOutliers", {{"v", "list number"}}, "list number"));
    fns.push_back(makeStubFunction("histogram", {{"v", "list number"}, {"bins", "number"}}, "list number"));
    injectModule(program, "stats", std::move(fns));
}


void StdlibRegistry::injectProbaModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("factorial", {{"n", "number"}}, "number"));
    fns.push_back(makeStubFunction("comb", {{"n", "number"}, {"k", "number"}}, "number"));
    fns.push_back(makeStubFunction("perm", {{"n", "number"}, {"k", "number"}}, "number"));
    fns.push_back(makeStubFunction("normalPdf", {{"x", "number"}, {"mu", "number"}, {"sigma", "number"}}, "number"));
    fns.push_back(makeStubFunction("normalCdf", {{"x", "number"}, {"mu", "number"}, {"sigma", "number"}}, "number"));
    fns.push_back(makeStubFunction("normalInv", {{"p", "number"}, {"mu", "number"}, {"sigma", "number"}}, "number"));
    fns.push_back(makeStubFunction("uniformPdf", {{"x", "number"}, {"lo", "number"}, {"hi", "number"}}, "number"));
    fns.push_back(makeStubFunction("uniformCdf", {{"x", "number"}, {"lo", "number"}, {"hi", "number"}}, "number"));
    fns.push_back(makeStubFunction("exponentialPdf", {{"x", "number"}, {"rate", "number"}}, "number"));
    fns.push_back(makeStubFunction("exponentialCdf", {{"x", "number"}, {"rate", "number"}}, "number"));
    fns.push_back(makeStubFunction("binomialPdf", {{"k", "number"}, {"n", "number"}, {"p", "number"}}, "number"));
    fns.push_back(makeStubFunction("binomialCdf", {{"k", "number"}, {"n", "number"}, {"p", "number"}}, "number"));
    fns.push_back(makeStubFunction("poissonPdf", {{"k", "number"}, {"lambda", "number"}}, "number"));
    fns.push_back(makeStubFunction("poissonCdf", {{"k", "number"}, {"lambda", "number"}}, "number"));
    fns.push_back(makeStubFunction("geometricPdf", {{"k", "number"}, {"p", "number"}}, "number"));
    fns.push_back(makeStubFunction("geometricCdf", {{"k", "number"}, {"p", "number"}}, "number"));
    fns.push_back(makeStubFunction("logNormalPdf", {{"x", "number"}, {"mu", "number"}, {"sigma", "number"}}, "number"));
    fns.push_back(makeStubFunction("logNormalCdf", {{"x", "number"}, {"mu", "number"}, {"sigma", "number"}}, "number"));
    fns.push_back(makeStubFunction("gammaPdf", {{"x", "number"}, {"shape", "number"}, {"rate", "number"}}, "number"));
    fns.push_back(makeStubFunction("gammaCdf", {{"x", "number"}, {"shape", "number"}, {"rate", "number"}}, "number"));
    fns.push_back(makeStubFunction("chiSquarePdf", {{"x", "number"}, {"k", "number"}}, "number"));
    fns.push_back(makeStubFunction("chiSquareCdf", {{"x", "number"}, {"k", "number"}}, "number"));
    fns.push_back(makeStubFunction("studentTPdf", {{"x", "number"}, {"nu", "number"}}, "number"));
    fns.push_back(makeStubFunction("studentTCdf", {{"x", "number"}, {"nu", "number"}}, "number"));
    fns.push_back(makeStubFunction("weibullPdf", {{"x", "number"}, {"shape", "number"}, {"scale", "number"}}, "number"));
    fns.push_back(makeStubFunction("weibullCdf", {{"x", "number"}, {"shape", "number"}, {"scale", "number"}}, "number"));
    fns.push_back(makeStubFunction("betaPdf", {{"x", "number"}, {"a", "number"}, {"b", "number"}}, "number"));
    fns.push_back(makeStubFunction("paretoPdf", {{"x", "number"}, {"alpha", "number"}}, "number"));
    fns.push_back(makeStubFunction("paretoCdf", {{"x", "number"}, {"alpha", "number"}}, "number"));
    fns.push_back(makeStubFunction("seed", {{"value", "int"}}, ""));
    fns.push_back(makeStubFunction("randomize", {}, ""));
    fns.push_back(makeStubFunction("sampleUniform", {{"lo", "number"}, {"hi", "number"}}, "number"));
    fns.push_back(makeStubFunction("sampleInt", {{"lo", "number"}, {"hi", "number"}}, "number"));
    fns.push_back(makeStubFunction("rand", {{"maxValue", "number"}}, "number"));
    fns.push_back(makeStubFunction("randint", {{"a", "number"}, {"b", "number"}}, "number"));
    fns.push_back(makeStubFunction("randrange", {{"start", "number"}, {"stop", "number"}}, "number"));
    fns.push_back(makeStubFunction("sampleNormal", {{"mu", "number"}, {"sigma", "number"}}, "number"));
    fns.push_back(makeStubFunction("gauss", {{"mu", "number"}, {"sigma", "number"}}, "number"));
    fns.push_back(makeStubFunction("normalvariate", {{"mu", "number"}, {"sigma", "number"}}, "number"));
    fns.push_back(makeStubFunction("sampleBernoulli", {{"p", "number"}}, "number"));
    fns.push_back(makeStubFunction("sampleBinomial", {{"n", "number"}, {"p", "number"}}, "number"));
    fns.push_back(makeStubFunction("samplePoisson", {{"lambda", "number"}}, "number"));
    fns.push_back(makeStubFunction("sampleExponential", {{"rate", "number"}}, "number"));
    fns.push_back(makeStubFunction("expovariate", {{"lambd", "number"}}, "number"));
    fns.push_back(makeStubFunction("sampleGeometric", {{"p", "number"}}, "number"));
    fns.push_back(makeStubFunction("sampleLogNormal", {{"mu", "number"}, {"sigma", "number"}}, "number"));
    fns.push_back(makeStubFunction("lognormvariate", {{"mu", "number"}, {"sigma", "number"}}, "number"));
    fns.push_back(makeStubFunction("sampleGamma", {{"shape", "number"}, {"rate", "number"}}, "number"));
    fns.push_back(makeStubFunction("gammavariate", {{"alpha", "number"}, {"beta", "number"}}, "number"));
    fns.push_back(makeStubFunction("sampleTriangular", {{"low", "number"}, {"high", "number"}, {"mode", "number"}}, "number"));
    fns.push_back(makeStubFunction("sampleBeta", {{"alpha", "number"}, {"beta", "number"}}, "number"));
    fns.push_back(makeStubFunction("betavariate", {{"alpha", "number"}, {"beta", "number"}}, "number"));
    fns.push_back(makeStubFunction("sampleWeibull", {{"alpha", "number"}, {"beta", "number"}}, "number"));
    fns.push_back(makeStubFunction("weibullvariate", {{"alpha", "number"}, {"beta", "number"}}, "number"));
    fns.push_back(makeStubFunction("samplePareto", {{"alpha", "number"}}, "number"));
    fns.push_back(makeStubFunction("paretovariate", {{"alpha", "number"}}, "number"));
    fns.push_back(makeStubFunction("sampleVonMises", {{"mu", "number"}, {"kappa", "number"}}, "number"));
    fns.push_back(makeStubFunction("vonmisesvariate", {{"mu", "number"}, {"kappa", "number"}}, "number"));
    fns.push_back(makeStubFunction("sampleChoice", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("sampleShuffle", {{"v", "list number"}}, "list number"));
    fns.push_back(makeStubFunction("sampleN", {{"v", "list number"}, {"n", "number"}}, "list number"));
    fns.push_back(makeStubFunction("sampleWeighted", {{"v", "list number"}, {"weights", "list number"}, {"k", "number"}}, "list number"));
    fns.push_back(makeStubFunction("sampleWithoutReplacement", {{"v", "list number"}, {"k", "number"}}, "list number"));
    fns.push_back(makeStubFunction("sampleCdf", {{"v", "list number"}, {"cdf", "list number"}}, "number"));
    injectModule(program, "proba", std::move(fns));
}


void StdlibRegistry::injectTimeModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("now", {}, "number"));
    fns.push_back(makeStubFunction("nowMs", {}, "int"));
    fns.push_back(makeStubFunction("formatTimestamp", {{"seconds", "number"}}, "text"));
    injectModule(program, "chrono", std::move(fns));
}

void StdlibRegistry::injectReModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("matches", {{"text", "text"}, {"pattern", "text"}}, "bool"));
    fns.push_back(makeStubFunction("matchFlags", {{"text", "text"}, {"pattern", "text"}, {"flags", "text"}}, "bool"));
    fns.push_back(makeStubFunction("search", {{"text", "text"}, {"pattern", "text"}}, "bool"));
    fns.push_back(makeStubFunction("find", {{"text", "text"}, {"pattern", "text"}}, "text"));
    fns.push_back(makeStubFunction("findAll", {{"text", "text"}, {"pattern", "text"}}, "list text"));
    fns.push_back(makeStubFunction("captures", {{"text", "text"}, {"pattern", "text"}}, "list text"));
    fns.push_back(makeStubFunction("count", {{"text", "text"}, {"pattern", "text"}}, "int"));
    fns.push_back(makeStubFunction("split", {{"text", "text"}, {"pattern", "text"}}, "list text"));
    fns.push_back(makeStubFunction("replace", {{"text", "text"}, {"pattern", "text"}, {"replacement", "text"}}, "text"));
    fns.push_back(makeStubFunction("replaceFirst", {{"text", "text"}, {"pattern", "text"}, {"replacement", "text"}}, "text"));
    injectModule(program, "re", std::move(fns));
}

void StdlibRegistry::injectCollectionsModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("sortNumbers", {{"items", "list number"}}, "list number"));
    fns.push_back(makeStubFunction("sortText", {{"items", "list text"}}, "list text"));
    fns.push_back(makeStubFunction("reverseNumbers", {{"items", "list number"}}, "list number"));
    fns.push_back(makeStubFunction("reverseText", {{"items", "list text"}}, "list text"));
    fns.push_back(makeStubFunction("containsNumber", {{"items", "list number"}, {"value", "number"}}, "bool"));
    fns.push_back(makeStubFunction("containsText", {{"items", "list text"}, {"value", "text"}}, "bool"));
    fns.push_back(makeStubFunction("indexOfNumber", {{"items", "list number"}, {"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("indexOfText", {{"items", "list text"}, {"value", "text"}}, "number"));
    fns.push_back(makeStubFunction("sumNumbers", {{"items", "list number"}}, "number"));
    fns.push_back(makeStubFunction("mapNumbers", {{"items", "list number"}, {"fn", "function number to number"}}, "list number"));
    fns.push_back(makeStubFunction("filterNumbers", {{"items", "list number"}, {"fn", "function number to bool"}}, "list number"));
    fns.push_back(makeStubFunction("reduceNumbers", {{"items", "list number"}, {"fn", "function number, number to number"}, {"initial", "number"}}, "number"));
    fns.push_back(makeStubFunction("mapText", {{"items", "list text"}, {"fn", "function text to text"}}, "list text"));
    fns.push_back(makeStubFunction("filterText", {{"items", "list text"}, {"fn", "function text to bool"}}, "list text"));
    fns.push_back(makeStubFunction("reduceText", {{"items", "list text"}, {"fn", "function text, text to text"}, {"initial", "text"}}, "text"));
    fns.push_back(makeStubFunction("flatMapNumbers", {{"items", "list number"}, {"fn", "function number to list number"}}, "list number"));
    fns.push_back(makeStubFunction("flatMapText", {{"items", "list text"}, {"fn", "function text to list text"}}, "list text"));
    injectModule(program, "collections", std::move(fns));
}

void StdlibRegistry::injectArgsModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("count", {}, "number"));
    fns.push_back(makeStubFunction("at", {{"index", "number"}}, "text"));
    fns.push_back(makeStubFunction("all", {}, "list text"));
    injectModule(program, "args", std::move(fns));
}

void StdlibRegistry::injectPathModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("join", {{"left", "text"}, {"right", "text"}}, "text"));
    fns.push_back(makeStubFunction("basename", {{"path", "text"}}, "text"));
    fns.push_back(makeStubFunction("dirname", {{"path", "text"}}, "text"));
    fns.push_back(makeStubFunction("extension", {{"path", "text"}}, "text"));
    fns.push_back(makeStubFunction("isAbsolute", {{"path", "text"}}, "bool"));
    injectModule(program, "path", std::move(fns));
}

void StdlibRegistry::injectAsyncModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("sleep", {{"ms", "number"}}, "", true));
    injectModule(program, "async", std::move(fns));
}

void StdlibRegistry::injectSqlModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("query", {{"path", "text"}, {"sql", "text"}}, "text"));
    fns.push_back(makeStubFunction("exec", {{"path", "text"}, {"sql", "text"}}, "bool"));
    injectModule(program, "sql", std::move(fns));
}

void StdlibRegistry::injectWebModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("createRouter", {}, "int"));
    fns.push_back(makeStubFunction("addRoute", {{"router", "int"}, {"method", "text"},
                                                {"path", "text"}, {"body", "text"}}, ""));
    fns.push_back(makeStubFunction("dispatch", {{"router", "int"}, {"method", "text"},
                                                {"path", "text"}}, "text"));
    injectModule(program, "web", std::move(fns));
}

void StdlibRegistry::injectOrmModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("findAll", {{"path", "text"}, {"table", "text"}}, "text"));
    fns.push_back(makeStubFunction("insert", {{"path", "text"}, {"table", "text"},
                                              {"columns", "text"}, {"values", "text"}}, "int"));
    fns.push_back(makeStubFunction("deleteRows", {{"path", "text"}, {"table", "text"},
                                                  {"where", "text"}}, "bool"));
    injectModule(program, "orm", std::move(fns));
}

void StdlibRegistry::injectThreadModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("spawnSleep", {{"ms", "int"}}, "int"));
    fns.push_back(makeStubFunction("join", {{"id", "int"}}, ""));
    fns.push_back(makeStubFunction("sleepMs", {{"ms", "int"}}, ""));
    fns.push_back(makeStubFunction("hardwareConcurrency", {}, "int"));
    fns.push_back(makeStubFunction("mutexNew", {}, "int"));
    fns.push_back(makeStubFunction("mutexLock", {{"id", "int"}}, ""));
    fns.push_back(makeStubFunction("mutexUnlock", {{"id", "int"}}, ""));
    fns.push_back(makeStubFunction("chanNewText", {}, "int"));
    fns.push_back(makeStubFunction("chanNewNumber", {}, "int"));
    fns.push_back(makeStubFunction("chanSendText", {{"id", "int"}, {"value", "text"}}, ""));
    fns.push_back(makeStubFunction("chanSendNumber", {{"id", "int"}, {"value", "number"}}, ""));
    fns.push_back(makeStubFunction("chanRecvText", {{"id", "int"}}, "text"));
    fns.push_back(makeStubFunction("chanRecvNumber", {{"id", "int"}}, "number"));
    fns.push_back(makeStubFunction("chanClose", {{"id", "int"}}, ""));
    injectModule(program, "thread", std::move(fns));
}

void StdlibRegistry::injectBigintModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("fromInt", {{"value", "int"}}, "bigint"));
    fns.push_back(makeStubFunction("toText", {{"value", "bigint"}}, "text"));
    fns.push_back(makeStubFunction("add", {{"a", "bigint"}, {"b", "bigint"}}, "bigint"));
    fns.push_back(makeStubFunction("mul", {{"a", "bigint"}, {"b", "bigint"}}, "bigint"));
    injectModule(program, "bigint", std::move(fns));
}

void StdlibRegistry::injectUiModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("openWindow", {{"title", "text"}, {"width", "number"}, {"height", "number"}}, ""));
    fns.push_back(makeStubFunction("closeWindow", {}, ""));
    fns.push_back(makeStubFunction("isOpen", {}, "bool"));
    fns.push_back(makeStubFunction("beginFrame", {}, ""));
    fns.push_back(makeStubFunction("clearBackground", {{"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("fillRect", {{"x", "number"}, {"y", "number"}, {"width", "number"}, {"height", "number"}, {"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("drawRect", {{"x", "number"}, {"y", "number"}, {"width", "number"}, {"height", "number"}, {"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("drawText", {{"text", "text"}, {"x", "number"}, {"y", "number"}, {"size", "number"}}, ""));
    fns.push_back(makeStubFunction("drawTextColor", {{"text", "text"}, {"x", "number"}, {"y", "number"}, {"size", "number"}, {"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("drawButton", {{"label", "text"}, {"x", "number"}, {"y", "number"}, {"width", "number"}, {"height", "number"}}, "bool"));
    fns.push_back(makeStubFunction("isKeyDown", {{"key", "text"}}, "bool"));
    fns.push_back(makeStubFunction("wasKeyPressed", {{"key", "text"}}, "bool"));
    fns.push_back(makeStubFunction("deltaMs", {}, "number"));
    fns.push_back(makeStubFunction("windowWidth", {}, "number"));
    fns.push_back(makeStubFunction("windowHeight", {}, "number"));
    fns.push_back(makeStubFunction("mouseX", {}, "number"));
    fns.push_back(makeStubFunction("mouseY", {}, "number"));
    fns.push_back(makeStubFunction("isMouseDown", {}, "bool"));
    fns.push_back(makeStubFunction("wasMousePressed", {}, "bool"));
    fns.push_back(makeStubFunction("wasMouseClicked", {}, "bool"));
    fns.push_back(makeStubFunction("fps", {}, "number"));
    fns.push_back(makeStubFunction("showFrame", {}, ""));
    injectModule(program, "ui", std::move(fns));
}

void StdlibRegistry::injectGame2dModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("configureGrid",
        {{"cols", "number"}, {"rows", "number"}, {"cellSize", "number"},
         {"padX", "number"}, {"padY", "number"}}, ""));
    fns.push_back(makeStubFunction("configureViewport",
        {{"viewCols", "number"}, {"viewRows", "number"}}, ""));
    fns.push_back(makeStubFunction("gridWindowWidth", {}, "number"));
    fns.push_back(makeStubFunction("gridWindowHeight", {}, "number"));
    fns.push_back(makeStubFunction("cellPx", {{"col", "number"}}, "number"));
    fns.push_back(makeStubFunction("cellPy", {{"row", "number"}}, "number"));
    fns.push_back(makeStubFunction("cellWorldX", {{"col", "number"}}, "number"));
    fns.push_back(makeStubFunction("cellWorldY", {{"row", "number"}}, "number"));
    fns.push_back(makeStubFunction("isBorderCell", {{"col", "number"}, {"row", "number"}}, "bool"));
    fns.push_back(makeStubFunction("fillCell",
        {{"col", "number"}, {"row", "number"}, {"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("drawCell",
        {{"col", "number"}, {"row", "number"}, {"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("fillBoard", {{"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("drawWalls", {{"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("drawGridLines", {{"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("fillCircleSolid",
        {{"x", "number"}, {"y", "number"}, {"radius", "number"},
         {"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("everyMs",
        {{"name", "text"}, {"delta", "number"}, {"interval", "number"}}, "bool"));
    fns.push_back(makeStubFunction("resetTimer", {{"name", "text"}}, ""));
    fns.push_back(makeStubFunction("animTimeMs", {}, "number"));
    fns.push_back(makeStubFunction("pulse01", {{"period", "number"}}, "number"));
    fns.push_back(makeStubFunction("updateDirection", {{"curDx", "number"}, {"curDy", "number"}}, ""));
    fns.push_back(makeStubFunction("inputDirX", {}, "number"));
    fns.push_back(makeStubFunction("inputDirY", {}, "number"));
    fns.push_back(makeStubFunction("syncDirection", {{"dx", "number"}, {"dy", "number"}}, ""));
    fns.push_back(makeStubFunction("gridHas",
        {{"xs", "list number"}, {"ys", "list number"}, {"count", "number"},
         {"gx", "number"}, {"gy", "number"}}, "bool"));
    fns.push_back(makeStubFunction("rgb", {{"r", "number"}, {"g", "number"}, {"b", "number"}}, "number"));
    fns.push_back(makeStubFunction("redOf", {{"packed", "number"}}, "number"));
    fns.push_back(makeStubFunction("greenOf", {{"packed", "number"}}, "number"));
    fns.push_back(makeStubFunction("blueOf", {{"packed", "number"}}, "number"));
    fns.push_back(makeStubFunction("fillCellRgb", {{"col", "number"}, {"row", "number"}, {"packed", "number"}}, ""));
    fns.push_back(makeStubFunction("drawCenteredText",
        {{"text", "text"}, {"y", "number"}, {"size", "number"},
         {"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("drawHud",
        {{"text", "text"}, {"x", "number"}, {"y", "number"}, {"size", "number"},
         {"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("highScore", {}, "number"));
    fns.push_back(makeStubFunction("updateHighScore", {{"score", "number"}}, ""));
    fns.push_back(makeStubFunction("moveIntervalForScore",
        {{"score", "number"}, {"baseMs", "number"}, {"minMs", "number"}}, "number"));
    fns.push_back(makeStubFunction("setCamera", {{"x", "number"}, {"y", "number"}}, ""));
    fns.push_back(makeStubFunction("cameraX", {}, "number"));
    fns.push_back(makeStubFunction("cameraY", {}, "number"));
    fns.push_back(makeStubFunction("followCamera",
        {{"targetX", "number"}, {"targetY", "number"}, {"smooth", "number"}}, ""));
    fns.push_back(makeStubFunction("loadSprite", {{"name", "text"}, {"path", "text"}}, "bool"));
    fns.push_back(makeStubFunction("hasSprite", {{"name", "text"}}, "bool"));
    fns.push_back(makeStubFunction("spriteWidth", {{"name", "text"}}, "number"));
    fns.push_back(makeStubFunction("spriteHeight", {{"name", "text"}}, "number"));
    fns.push_back(makeStubFunction("drawSprite",
        {{"name", "text"}, {"worldX", "number"}, {"worldY", "number"}}, ""));
    fns.push_back(makeStubFunction("drawSpriteScaled",
        {{"name", "text"}, {"worldX", "number"}, {"worldY", "number"},
         {"width", "number"}, {"height", "number"}}, ""));
    fns.push_back(makeStubFunction("drawSpriteCell",
        {{"name", "text"}, {"col", "number"}, {"row", "number"}}, ""));
    fns.push_back(makeStubFunction("loadSpriteSheet",
        {{"name", "text"}, {"path", "text"}, {"frameW", "number"}, {"frameH", "number"}}, "bool"));
    fns.push_back(makeStubFunction("hasSpriteSheet", {{"name", "text"}}, "bool"));
    fns.push_back(makeStubFunction("sheetCols", {{"name", "text"}}, "number"));
    fns.push_back(makeStubFunction("sheetRows", {{"name", "text"}}, "number"));
    fns.push_back(makeStubFunction("drawSpriteFrame",
        {{"name", "text"}, {"frame", "number"}, {"worldX", "number"}, {"worldY", "number"},
         {"width", "number"}, {"height", "number"}}, ""));
    fns.push_back(makeStubFunction("drawSpriteFrameCell",
        {{"name", "text"}, {"frame", "number"}, {"col", "number"}, {"row", "number"}}, ""));
    fns.push_back(makeStubFunction("loadSound", {{"name", "text"}, {"path", "text"}}, "bool"));
    fns.push_back(makeStubFunction("playSound", {{"name", "text"}}, "bool"));
    fns.push_back(makeStubFunction("playSoundVolume",
        {{"name", "text"}, {"volume", "number"}}, "bool"));
    fns.push_back(makeStubFunction("loadMusic", {{"name", "text"}, {"path", "text"}}, "bool"));
    fns.push_back(makeStubFunction("playMusic", {{"name", "text"}, {"loops", "number"}}, "bool"));
    fns.push_back(makeStubFunction("stopMusic", {}, ""));
    fns.push_back(makeStubFunction("setMusicVolume", {{"volume", "number"}}, ""));
    fns.push_back(makeStubFunction("defineTrigger",
        {{"name", "text"}, {"x", "number"}, {"y", "number"}, {"w", "number"}, {"h", "number"}}, ""));
    fns.push_back(makeStubFunction("setTriggerActive", {{"name", "text"}, {"active", "bool"}}, ""));
    fns.push_back(makeStubFunction("pointInTrigger",
        {{"name", "text"}, {"wx", "number"}, {"wy", "number"}}, "bool"));
    fns.push_back(makeStubFunction("mouseInTrigger", {{"name", "text"}}, "bool"));
    fns.push_back(makeStubFunction("mouseWorldX", {}, "number"));
    fns.push_back(makeStubFunction("mouseWorldY", {}, "number"));
    fns.push_back(makeStubFunction("saveValue",
        {{"path", "text"}, {"key", "text"}, {"value", "number"}}, "bool"));
    fns.push_back(makeStubFunction("loadValue",
        {{"path", "text"}, {"key", "text"}, {"defaultValue", "number"}}, "number"));
    fns.push_back(makeStubFunction("loadHighScore", {{"path", "text"}}, ""));
    fns.push_back(makeStubFunction("saveHighScore", {{"path", "text"}}, "bool"));
    fns.push_back(makeStubFunction("drawFps", {{"x", "number"}, {"y", "number"}}, ""));
    fns.push_back(makeStubFunction("shutdown", {}, ""));
    injectModule(program, "game2d", std::move(fns));
}

void StdlibRegistry::injectGame3dModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("openWindow", {{"title", "text"}, {"width", "number"}, {"height", "number"}}, ""));
    fns.push_back(makeStubFunction("closeWindow", {}, ""));
    fns.push_back(makeStubFunction("shutdown", {}, ""));
    fns.push_back(makeStubFunction("isOpen", {}, "bool"));
    fns.push_back(makeStubFunction("beginFrame", {}, ""));
    fns.push_back(makeStubFunction("showFrame", {}, ""));
    fns.push_back(makeStubFunction("deltaMs", {}, "number"));
    fns.push_back(makeStubFunction("windowWidth", {}, "number"));
    fns.push_back(makeStubFunction("windowHeight", {}, "number"));
    fns.push_back(makeStubFunction("clearScreen", {{"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("isKeyDown", {{"key", "text"}}, "bool"));
    fns.push_back(makeStubFunction("wasKeyPressed", {{"key", "text"}}, "bool"));
    fns.push_back(makeStubFunction("setCamera",
        {{"x", "number"}, {"y", "number"}, {"z", "number"}, {"yaw", "number"}, {"pitch", "number"}}, ""));
    fns.push_back(makeStubFunction("applyCamera", {}, ""));
    fns.push_back(makeStubFunction("updateFlyCamera",
        {{"moveSpeed", "number"}, {"turnSpeed", "number"}}, ""));
    fns.push_back(makeStubFunction("setSceneRotation", {{"angleY", "number"}}, ""));
    fns.push_back(makeStubFunction("applySceneRotation", {}, ""));
    fns.push_back(makeStubFunction("drawCube",
        {{"x", "number"}, {"y", "number"}, {"z", "number"}, {"size", "number"},
         {"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("drawPlane",
        {{"y", "number"}, {"halfSize", "number"}, {"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("drawGrid",
        {{"y", "number"}, {"halfSize", "number"}, {"divisions", "number"}}, ""));
    fns.push_back(makeStubFunction("drawAxis", {{"size", "number"}}, ""));
    fns.push_back(makeStubFunction("drawSphere",
        {{"x", "number"}, {"y", "number"}, {"z", "number"}, {"radius", "number"},
         {"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("loadTexture3d", {{"name", "text"}, {"path", "text"}}, "bool"));
    fns.push_back(makeStubFunction("hasTexture3d", {{"name", "text"}}, "bool"));
    fns.push_back(makeStubFunction("drawPlaneTextured",
        {{"y", "number"}, {"halfSize", "number"}, {"textureName", "text"}}, ""));
    fns.push_back(makeStubFunction("drawCubeTextured",
        {{"x", "number"}, {"y", "number"}, {"z", "number"}, {"size", "number"}, {"textureName", "text"}}, ""));
    fns.push_back(makeStubFunction("loadModel", {{"name", "text"}, {"path", "text"}}, "bool"));
    fns.push_back(makeStubFunction("hasModel", {{"name", "text"}}, "bool"));
    fns.push_back(makeStubFunction("drawModel",
        {{"name", "text"}, {"x", "number"}, {"y", "number"}, {"z", "number"}, {"scale", "number"},
         {"rotY", "number"}, {"textureName", "text"}}, ""));
    fns.push_back(makeStubFunction("drawModelColored",
        {{"name", "text"}, {"x", "number"}, {"y", "number"}, {"z", "number"}, {"scale", "number"},
         {"rotY", "number"}, {"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("createBody",
        {{"name", "text"}, {"x", "number"}, {"y", "number"}, {"z", "number"}, {"radius", "number"}}, ""));
    fns.push_back(makeStubFunction("hasBody", {{"name", "text"}}, "bool"));
    fns.push_back(makeStubFunction("setBodyVelocity",
        {{"name", "text"}, {"vx", "number"}, {"vy", "number"}, {"vz", "number"}}, ""));
    fns.push_back(makeStubFunction("setBodyPosition",
        {{"name", "text"}, {"x", "number"}, {"y", "number"}, {"z", "number"}}, ""));
    fns.push_back(makeStubFunction("bodyX", {{"name", "text"}}, "number"));
    fns.push_back(makeStubFunction("bodyY", {{"name", "text"}}, "number"));
    fns.push_back(makeStubFunction("bodyZ", {{"name", "text"}}, "number"));
    fns.push_back(makeStubFunction("applyImpulse",
        {{"name", "text"}, {"ix", "number"}, {"iy", "number"}, {"iz", "number"}}, ""));
    fns.push_back(makeStubFunction("stepPhysics", {{"deltaMs", "number"}, {"gravity", "number"}}, ""));
    fns.push_back(makeStubFunction("stepPhysicsEx", {{"deltaMs", "number"}, {"gravity", "number"}}, ""));
    fns.push_back(makeStubFunction("removeBody", {{"name", "text"}}, ""));
    fns.push_back(makeStubFunction("drawModelLit",
        {{"name", "text"}, {"x", "number"}, {"y", "number"}, {"z", "number"}, {"scale", "number"},
         {"rotY", "number"}, {"textureName", "text"}}, ""));
    fns.push_back(makeStubFunction("createBoxBody",
        {{"name", "text"}, {"x", "number"}, {"y", "number"}, {"z", "number"},
         {"hx", "number"}, {"hy", "number"}, {"hz", "number"}}, ""));
    fns.push_back(makeStubFunction("setBodyFriction", {{"name", "text"}, {"friction", "number"}}, ""));
    fns.push_back(makeStubFunction("setBodyRestitution", {{"name", "text"}, {"restitution", "number"}}, ""));
    fns.push_back(makeStubFunction("drawBox",
        {{"x", "number"}, {"y", "number"}, {"z", "number"}, {"sx", "number"}, {"sy", "number"}, {"sz", "number"},
         {"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("drawBody", {{"name", "text"}}, ""));
    fns.push_back(makeStubFunction("enableLighting", {{"on", "bool"}}, ""));
    fns.push_back(makeStubFunction("setAmbientLight", {{"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("setSunLight",
        {{"dx", "number"}, {"dy", "number"}, {"dz", "number"}, {"r", "number"}, {"g", "number"}, {"b", "number"}}, ""));
    fns.push_back(makeStubFunction("applyLighting", {}, ""));
    fns.push_back(makeStubFunction("setFog",
        {{"enabled", "bool"}, {"r", "number"}, {"g", "number"}, {"b", "number"},
         {"startDist", "number"}, {"endDist", "number"}}, ""));
    fns.push_back(makeStubFunction("applyFog", {}, ""));
    fns.push_back(makeStubFunction("setWind", {{"x", "number"}, {"y", "number"}, {"z", "number"}}, ""));
    fns.push_back(makeStubFunction("followBody",
        {{"name", "text"}, {"height", "number"}, {"distance", "number"}, {"smooth", "number"}}, ""));
    fns.push_back(makeStubFunction("emitBurst",
        {{"x", "number"}, {"y", "number"}, {"z", "number"}, {"count", "number"}, {"speed", "number"}}, ""));
    fns.push_back(makeStubFunction("updateParticles", {{"deltaMs", "number"}}, ""));
    fns.push_back(makeStubFunction("drawParticles", {}, ""));
    fns.push_back(makeStubFunction("mouseX", {}, "number"));
    fns.push_back(makeStubFunction("mouseY", {}, "number"));
    fns.push_back(makeStubFunction("isMouseDown", {}, "bool"));
    fns.push_back(makeStubFunction("wasMousePressed", {}, "bool"));
    fns.push_back(makeStubFunction("wasMouseClicked", {}, "bool"));
    fns.push_back(makeStubFunction("drawSkyGradient",
        {{"topR", "number"}, {"topG", "number"}, {"topB", "number"},
         {"botR", "number"}, {"botG", "number"}, {"botB", "number"}}, ""));
    fns.push_back(makeStubFunction("loadSkyboxFace", {{"face", "text"}, {"path", "text"}}, "bool"));
    fns.push_back(makeStubFunction("hasSkybox", {}, "bool"));
    fns.push_back(makeStubFunction("drawSkybox", {{"halfSize", "number"}}, ""));
    fns.push_back(makeStubFunction("loadShader",
        {{"name", "text"}, {"vertPath", "text"}, {"fragPath", "text"}}, "bool"));
    fns.push_back(makeStubFunction("hasShader", {{"name", "text"}}, "bool"));
    fns.push_back(makeStubFunction("useShader", {{"name", "text"}}, ""));
    fns.push_back(makeStubFunction("stopShader", {}, ""));
    fns.push_back(makeStubFunction("setShaderFloat",
        {{"shaderName", "text"}, {"uniform", "text"}, {"value", "number"}}, ""));
    fns.push_back(makeStubFunction("setShaderVec3",
        {{"shaderName", "text"}, {"uniform", "text"},
         {"x", "number"}, {"y", "number"}, {"z", "number"}}, ""));
    fns.push_back(makeStubFunction("drawModelShader",
        {{"shaderName", "text"}, {"modelName", "text"}, {"x", "number"}, {"y", "number"}, {"z", "number"},
         {"scale", "number"}, {"rotY", "number"}}, ""));
    fns.push_back(makeStubFunction("loadGltf", {{"name", "text"}, {"path", "text"}}, "bool"));
    fns.push_back(makeStubFunction("hasGltf", {{"name", "text"}}, "bool"));
    fns.push_back(makeStubFunction("drawGltf",
        {{"name", "text"}, {"x", "number"}, {"y", "number"}, {"z", "number"},
         {"scale", "number"}, {"rotY", "number"}}, ""));
    fns.push_back(makeStubFunction("drawGltfLit",
        {{"name", "text"}, {"x", "number"}, {"y", "number"}, {"z", "number"},
         {"scale", "number"}, {"rotY", "number"}, {"textureName", "text"}}, ""));
    fns.push_back(makeStubFunction("loadGlb", {{"name", "text"}, {"path", "text"}}, "bool"));
    fns.push_back(makeStubFunction("gltfAnimCount", {{"modelName", "text"}}, "number"));
    fns.push_back(makeStubFunction("playGltfAnim",
        {{"modelName", "text"}, {"animIndex", "number"}, {"loop", "bool"}}, ""));
    fns.push_back(makeStubFunction("stopGltfAnim", {{"modelName", "text"}}, ""));
    fns.push_back(makeStubFunction("updateGltfAnims", {{"deltaMs", "number"}}, ""));
    fns.push_back(makeStubFunction("gltfAnimRotY", {{"modelName", "text"}}, "number"));
    fns.push_back(makeStubFunction("setEditMode", {{"on", "bool"}}, ""));
    fns.push_back(makeStubFunction("isEditMode", {}, "bool"));
    fns.push_back(makeStubFunction("clearLevel", {}, ""));
    fns.push_back(makeStubFunction("addLevelGltf",
        {{"asset", "text"}, {"x", "number"}, {"y", "number"}, {"z", "number"},
         {"scale", "number"}, {"rotY", "number"}}, ""));
    fns.push_back(makeStubFunction("addLevelModel",
        {{"asset", "text"}, {"x", "number"}, {"y", "number"}, {"z", "number"},
         {"scale", "number"}, {"rotY", "number"}}, ""));
    fns.push_back(makeStubFunction("levelCount", {}, "number"));
    fns.push_back(makeStubFunction("levelType", {{"index", "number"}}, "text"));
    fns.push_back(makeStubFunction("levelAsset", {{"index", "number"}}, "text"));
    fns.push_back(makeStubFunction("levelX", {{"index", "number"}}, "number"));
    fns.push_back(makeStubFunction("levelY", {{"index", "number"}}, "number"));
    fns.push_back(makeStubFunction("levelZ", {{"index", "number"}}, "number"));
    fns.push_back(makeStubFunction("levelScale", {{"index", "number"}}, "number"));
    fns.push_back(makeStubFunction("levelRotY", {{"index", "number"}}, "number"));
    fns.push_back(makeStubFunction("saveLevel", {{"path", "text"}}, "bool"));
    fns.push_back(makeStubFunction("loadLevel", {{"path", "text"}}, "bool"));
    fns.push_back(makeStubFunction("drawLevel", {}, ""));
    fns.push_back(makeStubFunction("pickGround", {{"screenX", "number"}, {"screenY", "number"}}, "bool"));
    fns.push_back(makeStubFunction("pickGroundX", {}, "number"));
    fns.push_back(makeStubFunction("pickGroundY", {}, "number"));
    fns.push_back(makeStubFunction("pickGroundZ", {}, "number"));
    fns.push_back(makeStubFunction("pickGroundHit", {}, "bool"));
    fns.push_back(makeStubFunction("pickBody", {{"screenX", "number"}, {"screenY", "number"}}, "number"));
    fns.push_back(makeStubFunction("pickBodyName", {{"screenX", "number"}, {"screenY", "number"}}, "text"));
    injectModule(program, "game3d", std::move(fns));
}

void StdlibRegistry::injectGamestateModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("setState", {{"name", "text"}}, ""));
    fns.push_back(makeStubFunction("getState", {}, "text"));
    fns.push_back(makeStubFunction("isState", {{"name", "text"}}, "bool"));
    fns.push_back(makeStubFunction("stateTimeMs", {}, "number"));
    fns.push_back(makeStubFunction("wasStateChanged", {}, "bool"));
    fns.push_back(makeStubFunction("tickState", {{"deltaMs", "number"}}, ""));
    injectModule(program, "gamestate", std::move(fns));
}

void StdlibRegistry::injectGamenetModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("hostGame", {{"port", "number"}}, "bool"));
    fns.push_back(makeStubFunction("joinGame", {{"host", "text"}, {"port", "number"}}, "bool"));
    fns.push_back(makeStubFunction("sendPose", {{"x", "number"}, {"y", "number"}, {"z", "number"}, {"rotY", "number"}}, ""));
    fns.push_back(makeStubFunction("pollNet", {{"nowMs", "number"}}, ""));
    fns.push_back(makeStubFunction("hasRemotePlayer", {}, "bool"));
    fns.push_back(makeStubFunction("remoteX", {}, "number"));
    fns.push_back(makeStubFunction("remoteY", {}, "number"));
    fns.push_back(makeStubFunction("remoteZ", {}, "number"));
    fns.push_back(makeStubFunction("remoteRotY", {}, "number"));
    fns.push_back(makeStubFunction("shutdownNet", {}, ""));
    injectModule(program, "gamenet", std::move(fns));
}

void StdlibRegistry::injectCryptoModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("sha256", {{"data", "text"}}, "text"));
    fns.push_back(makeStubFunction("sha512", {{"data", "text"}}, "text"));
    fns.push_back(makeStubFunction("sha1", {{"data", "text"}}, "text"));
    fns.push_back(makeStubFunction("sha3_256", {{"data", "text"}}, "text"));
    fns.push_back(makeStubFunction("sha256File", {{"path", "text"}}, "text"));
    fns.push_back(makeStubFunction("hmacSha256", {{"key", "text"}, {"data", "text"}}, "text"));
    fns.push_back(makeStubFunction("randomBytes", {{"n", "number"}}, "text"));
    fns.push_back(makeStubFunction("randomHex", {{"n", "number"}}, "text"));
    fns.push_back(makeStubFunction("hexEncode", {{"data", "text"}}, "text"));
    fns.push_back(makeStubFunction("hexDecode", {{"hex", "text"}}, "text"));
    fns.push_back(makeStubFunction("aesGcmEncrypt", {{"keyHex", "text"}, {"plaintext", "text"}}, "text"));
    fns.push_back(makeStubFunction("aesGcmDecrypt", {{"keyHex", "text"}, {"packedHex", "text"}}, "text"));
    injectModule(program, "crypto", std::move(fns));
}

void StdlibRegistry::injectProcessModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("run", {{"program", "text"}, {"args", "list text"}}, "int"));
    fns.push_back(makeStubFunction("runCmd", {{"program", "text"}}, "int"));
    fns.push_back(makeStubFunction("captureStdout", {{"program", "text"}, {"args", "list text"}}, "text"));
    fns.push_back(makeStubFunction("captureCombined", {{"program", "text"}, {"args", "list text"}}, "text"));
    fns.push_back(makeStubFunction("runShell", {{"command", "text"}}, "int"));
    fns.push_back(makeStubFunction("getPid", {}, "int"));
    fns.push_back(makeStubFunction("exitWith", {{"code", "int"}}, ""));
    injectModule(program, "process", std::move(fns));
}

void StdlibRegistry::injectNetModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("tcpConnect", {{"host", "text"}, {"port", "number"}}, "number"));
    fns.push_back(makeStubFunction("tcpClose", {{"fd", "number"}}, ""));
    fns.push_back(makeStubFunction("tcpWrite", {{"fd", "number"}, {"data", "text"}}, "number"));
    fns.push_back(makeStubFunction("tcpRead", {{"fd", "number"}, {"maxBytes", "number"}}, "text"));
    fns.push_back(makeStubFunction("tcpListen", {{"port", "number"}}, "number"));
    fns.push_back(makeStubFunction("tcpAccept", {{"listenFd", "number"}}, "number"));
    fns.push_back(makeStubFunction("httpServe", {{"port", "number"}, {"body", "text"}}, "number"));
    fns.push_back(makeStubFunction("httpServeOnce", {{"port", "number"}, {"body", "text"}}, "number"));
    fns.push_back(makeStubFunction("httpServeTlsOnce", {{"port", "number"}, {"certFile", "text"}, {"keyFile", "text"}, {"body", "text"}}, "number"));
    injectModule(program, "net", std::move(fns));
}

void StdlibRegistry::injectYamlModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("parse", {{"text", "text"}}, "json"));
    fns.push_back(makeStubFunction("stringify", {{"value", "json"}}, "text"));
    injectModule(program, "yaml", std::move(fns));
}

void StdlibRegistry::injectDatetimeModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("nowSeconds", {}, "number"));
    fns.push_back(makeStubFunction("nowMs", {}, "int"));
    fns.push_back(makeStubFunction("formatIso", {{"seconds", "number"}}, "text"));
    fns.push_back(makeStubFunction("formatIsoOffset", {{"seconds", "number"}, {"offsetMinutes", "number"}}, "text"));
    fns.push_back(makeStubFunction("parseIso", {{"text", "text"}}, "number"));
    fns.push_back(makeStubFunction("diffSeconds", {{"a", "number"}, {"b", "number"}}, "number"));
    fns.push_back(makeStubFunction("year", {{"seconds", "number"}}, "number"));
    fns.push_back(makeStubFunction("month", {{"seconds", "number"}}, "number"));
    fns.push_back(makeStubFunction("day", {{"seconds", "number"}}, "number"));
    fns.push_back(makeStubFunction("hour", {{"seconds", "number"}}, "number"));
    fns.push_back(makeStubFunction("minute", {{"seconds", "number"}}, "number"));
    fns.push_back(makeStubFunction("second", {{"seconds", "number"}}, "number"));
    fns.push_back(makeStubFunction("weekday", {{"seconds", "number"}}, "number"));
    fns.push_back(makeStubFunction("addSeconds", {{"seconds", "number"}, {"delta", "number"}}, "number"));
    fns.push_back(makeStubFunction("addDays", {{"seconds", "number"}, {"days", "number"}}, "number"));
    injectModule(program, "datetime", std::move(fns));
}

void StdlibRegistry::injectEnvModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("get", {{"name", "text"}}, "text"));
    fns.push_back(makeStubFunction("has", {{"name", "text"}}, "bool"));
    fns.push_back(makeStubFunction("set", {{"name", "text"}, {"value", "text"}}, "bool"));
    injectModule(program, "env", std::move(fns));
}

void StdlibRegistry::injectTempfileModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("createPath", {{"prefix", "text"}}, "text"));
    fns.push_back(makeStubFunction("write", {{"path", "text"}, {"content", "text"}}, "bool"));
    fns.push_back(makeStubFunction("remove", {{"path", "text"}}, "bool"));
    injectModule(program, "tempfile", std::move(fns));
}

void StdlibRegistry::injectBase64Module(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("encode", {{"data", "text"}}, "text"));
    fns.push_back(makeStubFunction("decode", {{"data", "text"}}, "text"));
    injectModule(program, "base64", std::move(fns));
}

void StdlibRegistry::injectUrlModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("encode", {{"text", "text"}}, "text"));
    fns.push_back(makeStubFunction("decode", {{"text", "text"}}, "text"));
    injectModule(program, "url", std::move(fns));
}

void StdlibRegistry::injectRandomModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("seed", {{"value", "int"}}, ""));
    fns.push_back(makeStubFunction("randomize", {}, ""));
    fns.push_back(makeStubFunction("randomInt", {{"minValue", "int"}, {"maxValue", "int"}}, "int"));
    fns.push_back(makeStubFunction("randomFloat", {}, "number"));
    fns.push_back(makeStubFunction("rand", {{"maxValue", "number"}}, "number"));
    fns.push_back(makeStubFunction("randint", {{"a", "number"}, {"b", "number"}}, "number"));
    fns.push_back(makeStubFunction("gauss", {{"mu", "number"}, {"sigma", "number"}}, "number"));
    fns.push_back(makeStubFunction("uniform", {{"a", "number"}, {"b", "number"}}, "number"));
    fns.push_back(makeStubFunction("choice", {{"v", "list number"}}, "number"));
    fns.push_back(makeStubFunction("shuffle", {{"v", "list number"}}, "list number"));
    fns.push_back(makeStubFunction("sample", {{"v", "list number"}, {"k", "number"}}, "list number"));
    injectModule(program, "random", std::move(fns));
}


void StdlibRegistry::injectHexModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("encode", {{"data", "text"}}, "text"));
    fns.push_back(makeStubFunction("decode", {{"data", "text"}}, "text"));
    fns.push_back(makeStubFunction("toHex", {{"n", "number"}}, "text"));
    fns.push_back(makeStubFunction("fromHex", {{"s", "text"}}, "number"));
    injectModule(program, "hex", std::move(fns));
}

void StdlibRegistry::injectCsvModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("splitLine", {{"line", "text"}}, "list text"));
    injectModule(program, "csv", std::move(fns));
}

void StdlibRegistry::injectHtmlModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("escape", {{"text", "text"}}, "text"));
    injectModule(program, "html", std::move(fns));
}

void StdlibRegistry::injectCliModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("green", {{"text", "text"}}, "text"));
    fns.push_back(makeStubFunction("red", {{"text", "text"}}, "text"));
    fns.push_back(makeStubFunction("yellow", {{"text", "text"}}, "text"));
    fns.push_back(makeStubFunction("bold", {{"text", "text"}}, "text"));
    injectModule(program, "cli", std::move(fns));
}

void StdlibRegistry::injectEmailModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("isValid", {{"address", "text"}}, "bool"));
    fns.push_back(makeStubFunction("domain", {{"address", "text"}}, "text"));
    injectModule(program, "email", std::move(fns));
}

void StdlibRegistry::injectUuidModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("v4", {}, "text"));
    injectModule(program, "uuid", std::move(fns));
}

} // namespace afrilang
