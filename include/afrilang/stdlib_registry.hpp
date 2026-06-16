#pragma once

#include "afrilang/ast.hpp"

#include <memory>
#include <string>

namespace afrilang {

class StdlibRegistry {
public:
    static void injectIoModule(ProgramNode& program);
    static void injectJsonModule(ProgramNode& program);
    static void injectFsModule(ProgramNode& program);
    static void injectHttpModule(ProgramNode& program);
    static void injectStrModule(ProgramNode& program);
    static void injectLogModule(ProgramNode& program);
    static void injectMathModule(ProgramNode& program);
    static void injectTimeModule(ProgramNode& program);
    static void injectReModule(ProgramNode& program);
    static void injectCollectionsModule(ProgramNode& program);
    static void injectArgsModule(ProgramNode& program);
    static void injectPathModule(ProgramNode& program);
    static void injectAsyncModule(ProgramNode& program);
    static void injectSqlModule(ProgramNode& program);
    static void injectWebModule(ProgramNode& program);
    static void injectOrmModule(ProgramNode& program);
    static void injectThreadModule(ProgramNode& program);
    static void injectBigintModule(ProgramNode& program);
    static void injectUiModule(ProgramNode& program);
    static void injectGame2dModule(ProgramNode& program);
    static void injectCryptoModule(ProgramNode& program);
    static void injectYamlModule(ProgramNode& program);
    static void injectDatetimeModule(ProgramNode& program);
    static void injectEnvModule(ProgramNode& program);
    static void injectTempfileModule(ProgramNode& program);
    static void injectBase64Module(ProgramNode& program);
    static void injectUrlModule(ProgramNode& program);
    static void injectRandomModule(ProgramNode& program);
    static void injectHexModule(ProgramNode& program);
    static void injectCsvModule(ProgramNode& program);
    static void injectHtmlModule(ProgramNode& program);
    static void injectCliModule(ProgramNode& program);
    static void injectEmailModule(ProgramNode& program);
    static void injectUuidModule(ProgramNode& program);

    static void injectModuleByName(ProgramNode& program, const std::string& moduleName);
    static void injectCatalogModule(ProgramNode& program, const std::string& moduleName);

    static bool isStdlibImport(const std::string& path);
    static std::string stdlibModuleName(const std::string& path);
    static bool isStdlibModule(const std::string& moduleName);
    static bool isLegacyStdlibModule(const std::string& moduleName);
};

} // namespace afrilang
