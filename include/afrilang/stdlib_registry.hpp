#pragma once

#include "afrilang/ast.hpp"

#include <memory>
#include <string>

namespace afrilang {

// Injecte les modules stdlib (io, json) dans un programme.
class StdlibRegistry {
public:
    static void injectIoModule(ProgramNode& program);
    static void injectJsonModule(ProgramNode& program);

    static bool isStdlibImport(const std::string& path);
    static std::string stdlibModuleName(const std::string& path);
};

} // namespace afrilang
