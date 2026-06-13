#include "afrilang/stdlib_registry.hpp"

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
        std::vector<std::unique_ptr<StatementNode>>{}, {}, false, false, false, isAsync);
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
           path == "std/logging" || path == "std/logging.afr" ||
           path == "std/math" || path == "std/math.afr" ||
           path == "std/time" || path == "std/time.afr" ||
           path == "std/chrono" || path == "std/chrono.afr" ||
           path == "std/re" || path == "std/re.afr" ||
           path == "std/collections" || path == "std/collections.afr" ||
           path == "std/args" || path == "std/args.afr" ||
           path == "std/path" || path == "std/path.afr" ||
           path == "std/async" || path == "std/async.afr";
}

std::string StdlibRegistry::stdlibModuleName(const std::string& path) {
    if (path.find("json") != std::string::npos) return "json";
    if (path.find("http") != std::string::npos) return "http";
    if (path.find("math") != std::string::npos) return "math";
    if (path.find("logging") != std::string::npos || path.find("std/log") != std::string::npos) {
        return "logging";
    }
    if (path.find("chrono") != std::string::npos || path.find("std/time") != std::string::npos) {
        return "chrono";
    }
    if (path.find("std/str") != std::string::npos || path.find("str.afr") != std::string::npos) {
        return "str";
    }
    if (path.find("std/re") != std::string::npos || path.find("re.afr") != std::string::npos) {
        return "re";
    }
    if (path.find("collections") != std::string::npos) return "collections";
    if (path.find("std/args") != std::string::npos || path.find("args.afr") != std::string::npos) {
        return "args";
    }
    if (path.find("std/path") != std::string::npos || path.find("path.afr") != std::string::npos) {
        return "path";
    }
    if (path.find("std/async") != std::string::npos || path.find("async.afr") != std::string::npos) {
        return "async";
    }
    if (path.find("std/fs") != std::string::npos || path.find("fs.afr") != std::string::npos) {
        return "fs";
    }
    if (path.find("std/io") != std::string::npos || path.find("io.afr") != std::string::npos) {
        return "io";
    }
    return "";
}

void StdlibRegistry::injectIoModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("readFile", {{"path", "text"}}, "text"));
    fns.push_back(makeStubFunction("writeFile", {{"path", "text"}, {"content", "text"}}, ""));
    fns.push_back(makeStubFunction("fileExists", {{"path", "text"}}, "bool"));
    fns.push_back(makeStubFunction("readLine", {}, "text"));
    injectModule(program, "io", std::move(fns));
}

void StdlibRegistry::injectJsonModule(ProgramNode& program) {
    std::vector<std::unique_ptr<FunctionNode>> fns;
    fns.push_back(makeStubFunction("parse", {{"text", "text"}}, "text"));
    fns.push_back(makeStubFunction("stringify", {{"value", "text"}}, "text"));
    fns.push_back(makeStubFunction("getString", {{"text", "text"}, {"key", "text"}}, "text"));
    fns.push_back(makeStubFunction("getNumber", {{"text", "text"}, {"key", "text"}}, "number"));
    fns.push_back(makeStubFunction("makeObject", {{"key", "text"}, {"value", "text"}}, "text"));
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

} // namespace afrilang
