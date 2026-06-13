#include "afrilang/stdlib_registry.hpp"

#include <vector>

namespace afrilang {

namespace {

std::unique_ptr<FunctionNode> makeStubFunction(const std::string& name,
                                               std::vector<ParameterNode> params,
                                               std::string returnType) {
    return std::make_unique<FunctionNode>(
        name, std::move(params), std::move(returnType), false,
        std::vector<std::unique_ptr<StatementNode>>{});
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
        std::vector<std::unique_ptr<FunctionNode>>{});
    for (auto& fn : functions) {
        module->functions.push_back(std::move(fn));
    }
    program.modules.push_back(std::move(module));
}

} // namespace

bool StdlibRegistry::isStdlibImport(const std::string& path) {
    return path == "std/io" || path == "std/io.afr" ||
           path == "std/json" || path == "std/json.afr" ||
           path == "std/fs" || path == "std/fs.afr" ||
           path == "std/http" || path == "std/http.afr" ||
           path == "std/str" || path == "std/str.afr" ||
           path == "std/log" || path == "std/log.afr" ||
           path == "std/math" || path == "std/math.afr" ||
           path == "std/time" || path == "std/time.afr" ||
           path == "std/re" || path == "std/re.afr";
}

std::string StdlibRegistry::stdlibModuleName(const std::string& path) {
    if (path.find("json") != std::string::npos) return "json";
    if (path.find("http") != std::string::npos) return "http";
    if (path.find("math") != std::string::npos) return "math";
    if (path.find("time") != std::string::npos) return "time";
    if (path.find("str") != std::string::npos) return "str";
    if (path.find("log") != std::string::npos) return "log";
    if (path.find("fs") != std::string::npos) return "fs";
    if (path.find("io") != std::string::npos) return "io";
    if (path.find("re") != std::string::npos) return "re";
    return "";
}

void StdlibRegistry::injectIoModule(ProgramNode& program) {
    injectModule(program, "io", {
        makeStubFunction("readFile", {{"path", "text"}}, "text"),
        makeStubFunction("writeFile", {{"path", "text"}, {"content", "text"}}, ""),
        makeStubFunction("fileExists", {{"path", "text"}}, "bool"),
        makeStubFunction("readLine", {}, "text"),
    });
}

void StdlibRegistry::injectJsonModule(ProgramNode& program) {
    injectModule(program, "json", {
        makeStubFunction("parse", {{"text", "text"}}, "text"),
        makeStubFunction("stringify", {{"value", "text"}}, "text"),
        makeStubFunction("getString", {{"text", "text"}, {"key", "text"}}, "text"),
        makeStubFunction("getNumber", {{"text", "text"}, {"key", "text"}}, "number"),
        makeStubFunction("makeObject", {{"key", "text"}, {"value", "text"}}, "text"),
    });
}

void StdlibRegistry::injectFsModule(ProgramNode& program) {
    injectModule(program, "fs", {
        makeStubFunction("listDir", {{"path", "text"}}, "list text"),
        makeStubFunction("makeDir", {{"path", "text"}}, "bool"),
        makeStubFunction("removeFile", {{"path", "text"}}, "bool"),
        makeStubFunction("fileSize", {{"path", "text"}}, "number"),
    });
}

void StdlibRegistry::injectHttpModule(ProgramNode& program) {
    injectModule(program, "http", {
        makeStubFunction("httpGet", {{"url", "text"}}, "text"),
        makeStubFunction("httpPost", {{"url", "text"}, {"body", "text"}}, "text"),
    });
}

void StdlibRegistry::injectStrModule(ProgramNode& program) {
    injectModule(program, "str", {
        makeStubFunction("trim", {{"text", "text"}}, "text"),
        makeStubFunction("contains", {{"text", "text"}, {"needle", "text"}}, "bool"),
        makeStubFunction("replace", {{"text", "text"}, {"from", "text"}, {"to", "text"}}, "text"),
        makeStubFunction("split", {{"text", "text"}, {"sep", "text"}}, "list text"),
        makeStubFunction("join", {{"parts", "list text"}, {"sep", "text"}}, "text"),
    });
}

void StdlibRegistry::injectLogModule(ProgramNode& program) {
    injectModule(program, "log", {
        makeStubFunction("info", {{"message", "text"}}, ""),
        makeStubFunction("warn", {{"message", "text"}}, ""),
        makeStubFunction("error", {{"message", "text"}}, ""),
    });
}

void StdlibRegistry::injectMathModule(ProgramNode& program) {
    injectModule(program, "math", {
        makeStubFunction("abs", {{"value", "number"}}, "number"),
        makeStubFunction("floor", {{"value", "number"}}, "number"),
        makeStubFunction("ceil", {{"value", "number"}}, "number"),
        makeStubFunction("pow", {{"base", "number"}, {"exp", "number"}}, "number"),
        makeStubFunction("random", {}, "number"),
    });
}

void StdlibRegistry::injectTimeModule(ProgramNode& program) {
    injectModule(program, "time", {
        makeStubFunction("now", {}, "number"),
        makeStubFunction("formatTimestamp", {{"seconds", "number"}}, "text"),
    });
}

void StdlibRegistry::injectReModule(ProgramNode& program) {
    injectModule(program, "re", {
        makeStubFunction("match", {{"text", "text"}, {"pattern", "text"}}, "bool"),
        makeStubFunction("replace", {{"text", "text"}, {"pattern", "text"}, {"replacement", "text"}}, "text"),
    });
}

} // namespace afrilang
