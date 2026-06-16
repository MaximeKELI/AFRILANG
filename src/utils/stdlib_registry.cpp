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
           moduleName == "math" || moduleName == "chrono" || moduleName == "re" ||
           moduleName == "collections" || moduleName == "args" || moduleName == "path" ||
           moduleName == "sql" ||
           moduleName == "web" || moduleName == "orm" || moduleName == "thread" ||
           moduleName == "bigint" ||
           moduleName == "crypto" || moduleName == "yaml" || moduleName == "datetime" ||
           moduleName == "env" || moduleName == "tempfile" || moduleName == "base64" ||
           moduleName == "url" || moduleName == "random" || moduleName == "hex" ||
           moduleName == "csv" || moduleName == "html" || moduleName == "cli" ||
           moduleName == "email" || moduleName == "uuid" ||
           moduleName == "async" || moduleName == "ui" || moduleName == "game2d" ||
           moduleName == "game3d";
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
    fns.push_back(makeStubFunction("floor", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("ceil", {{"value", "number"}}, "number"));
    fns.push_back(makeStubFunction("pow", {{"base", "number"}, {"exp", "number"}}, "number"));
    fns.push_back(makeStubFunction("random", {}, "number"));
    injectModule(program, "math", std::move(fns));
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
    fns.push_back(makeStubFunction("match", {{"text", "text"}, {"pattern", "text"}}, "bool"));
    fns.push_back(makeStubFunction("replace", {{"text", "text"}, {"pattern", "text"}, {"replacement", "text"}}, "text"));
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
    fns.push_back(makeStubFunction("loadSound", {{"name", "text"}, {"path", "text"}}, "bool"));
    fns.push_back(makeStubFunction("playSound", {{"name", "text"}}, "bool"));
    fns.push_back(makeStubFunction("playSoundVolume",
        {{"name", "text"}, {"volume", "number"}}, "bool"));
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
    injectModule(program, "game3d", std::move(fns));
}

void StdlibRegistry::injectCryptoModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("sha256", {{"data", "text"}}, "text"));
    fns.push_back(makeStubFunction("sha256File", {{"path", "text"}}, "text"));
    injectModule(program, "crypto", std::move(fns));
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
    fns.push_back(makeStubFunction("diffSeconds", {{"a", "number"}, {"b", "number"}}, "number"));
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
    fns.push_back(makeStubFunction("randomInt", {{"minValue", "int"}, {"maxValue", "int"}}, "int"));
    fns.push_back(makeStubFunction("randomFloat", {}, "number"));
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
