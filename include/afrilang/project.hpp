#pragma once

#include "afrilang/ast.hpp"
#include "afrilang/semantic.hpp"

#include <string>
#include <unordered_set>

namespace afrilang {

struct ProjectConfig {
    std::string name = "app";
    std::string version = "0.1.0";
    std::string mainFile = "src/main.afr";
    std::string output = "build/app";
    std::string stdlibPath;
};

ProjectConfig loadProjectConfig(const std::string& path);

} // namespace afrilang
