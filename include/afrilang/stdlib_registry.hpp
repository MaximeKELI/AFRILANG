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

    static bool isStdlibImport(const std::string& path);
    static std::string stdlibModuleName(const std::string& path);
};

} // namespace afrilang
