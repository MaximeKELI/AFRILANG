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

} // namespace

bool StdlibRegistry::isStdlibImport(const std::string& path) {
    return path == "std/io" || path == "std/io.afr" ||
           path == "std/json" || path == "std/json.afr" ||
           path == "std/fs" || path == "std/fs.afr" ||
           path == "std/http" || path == "std/http.afr";
}

std::string StdlibRegistry::stdlibModuleName(const std::string& path) {
    if (path.find("io") != std::string::npos && path.find("json") == std::string::npos) {
        return "io";
    }
    if (path.find("json") != std::string::npos) return "json";
    if (path.find("fs") != std::string::npos) return "fs";
    if (path.find("http") != std::string::npos) return "http";
    return "";
}

void StdlibRegistry::injectIoModule(ProgramNode& program) {
    if (hasModule(program, "io")) return;
    auto module = std::make_unique<ModuleNode>(
        "io",
        std::vector<std::unique_ptr<ClassNode>>{},
        std::vector<std::unique_ptr<RecordNode>>{},
        std::vector<std::unique_ptr<FunctionNode>>{});

    module->functions.push_back(makeStubFunction(
        "readFile", {{"path", "text"}}, "text"));
    module->functions.push_back(makeStubFunction(
        "writeFile", {{"path", "text"}, {"content", "text"}}, ""));
    module->functions.push_back(makeStubFunction(
        "fileExists", {{"path", "text"}}, "bool"));
    module->functions.push_back(makeStubFunction(
        "readLine", {}, "text"));
    program.modules.push_back(std::move(module));
}

void StdlibRegistry::injectJsonModule(ProgramNode& program) {
    if (hasModule(program, "json")) return;
    auto module = std::make_unique<ModuleNode>(
        "json",
        std::vector<std::unique_ptr<ClassNode>>{},
        std::vector<std::unique_ptr<RecordNode>>{},
        std::vector<std::unique_ptr<FunctionNode>>{});

    module->functions.push_back(makeStubFunction(
        "parse", {{"text", "text"}}, "text"));
    module->functions.push_back(makeStubFunction(
        "stringify", {{"value", "text"}}, "text"));
    module->functions.push_back(makeStubFunction(
        "getString", {{"text", "text"}, {"key", "text"}}, "text"));
    module->functions.push_back(makeStubFunction(
        "getNumber", {{"text", "text"}, {"key", "text"}}, "number"));
    module->functions.push_back(makeStubFunction(
        "makeObject", {{"key", "text"}, {"value", "text"}}, "text"));
    program.modules.push_back(std::move(module));
}

void StdlibRegistry::injectFsModule(ProgramNode& program) {
    if (hasModule(program, "fs")) return;
    auto module = std::make_unique<ModuleNode>(
        "fs",
        std::vector<std::unique_ptr<ClassNode>>{},
        std::vector<std::unique_ptr<RecordNode>>{},
        std::vector<std::unique_ptr<FunctionNode>>{});

    module->functions.push_back(makeStubFunction(
        "listDir", {{"path", "text"}}, "list text"));
    module->functions.push_back(makeStubFunction(
        "makeDir", {{"path", "text"}}, "bool"));
    module->functions.push_back(makeStubFunction(
        "removeFile", {{"path", "text"}}, "bool"));
    module->functions.push_back(makeStubFunction(
        "fileSize", {{"path", "text"}}, "number"));
    program.modules.push_back(std::move(module));
}

void StdlibRegistry::injectHttpModule(ProgramNode& program) {
    if (hasModule(program, "http")) return;
    auto module = std::make_unique<ModuleNode>(
        "http",
        std::vector<std::unique_ptr<ClassNode>>{},
        std::vector<std::unique_ptr<RecordNode>>{},
        std::vector<std::unique_ptr<FunctionNode>>{});

    module->functions.push_back(makeStubFunction(
        "httpGet", {{"url", "text"}}, "text"));
    program.modules.push_back(std::move(module));
}

} // namespace afrilang
