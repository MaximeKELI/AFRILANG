#include "afrilang/stdlib_registry.hpp"

#include <vector>

namespace afrilang {

namespace {

std::unique_ptr<FunctionNode> makeStubFunction(const std::string& name,
                                               std::vector<ParameterNode> params,
                                               std::string returnType) {
    return std::make_unique<FunctionNode>(
        name, std::move(params), std::move(returnType),
        std::vector<std::unique_ptr<StatementNode>>{});
}

} // namespace

bool StdlibRegistry::isStdlibImport(const std::string& path) {
    return path == "std/io" || path == "std/io.afr" ||
           path == "std/json" || path == "std/json.afr";
}

std::string StdlibRegistry::stdlibModuleName(const std::string& path) {
    if (path.find("io") != std::string::npos) return "io";
    if (path.find("json") != std::string::npos) return "json";
    return "";
}

void StdlibRegistry::injectIoModule(ProgramNode& program) {
    auto module = std::make_unique<ModuleNode>("io");
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
    auto module = std::make_unique<ModuleNode>("json");
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

} // namespace afrilang
