#pragma once

#include "afrilang/ast.hpp"
#include "afrilang/semantic.hpp"

#include <string>
#include <unordered_map>
#include <unordered_set>

namespace afrilang {

enum class DependencyKind {
    Version, // registry + semver range
    Git,
    Path,
};

struct DependencySpec {
    DependencyKind kind = DependencyKind::Version;
    std::string version; // range string, e.g. "^1.0.0" or "0.1.0"
    std::string git;
    std::string tag;
    std::string branch;
    std::string path;
};

struct ProjectConfig {
    std::string name = "app";
    std::string version = "0.1.0";
    std::string mainFile = "src/main.afr";
    std::string output = "build/app";
    std::string stdlibPath;
    std::string description;
    std::unordered_map<std::string, DependencySpec> dependencies;
};

DependencySpec parseDependencyValue(const std::string& value);
ProjectConfig loadProjectConfig(const std::string& path);

} // namespace afrilang
