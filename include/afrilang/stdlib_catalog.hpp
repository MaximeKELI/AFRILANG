#pragma once

#include <cstddef>
#include <string>

namespace afrilang {

struct StdlibParamSpec {
    const char* name;
    const char* typeName;
};

struct StdlibFuncSpec {
    const char* name;
    const char* returnType;
    std::size_t paramCount;
    const StdlibParamSpec* params;
};

struct StdlibModuleSpec {
    const char* importName;
    const char* moduleName;
    const StdlibFuncSpec* functions;
    std::size_t functionCount;
    const char* runtimeHeader;
    bool needsSpecialCodegen;
};

const StdlibModuleSpec* stdlibCatalogModules();
std::size_t stdlibCatalogModuleCount();
const StdlibModuleSpec* stdlibCatalogFindModule(const std::string& name);
bool stdlibCatalogIsSimpleModule(const std::string& name);

} // namespace afrilang
