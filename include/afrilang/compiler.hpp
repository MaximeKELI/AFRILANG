#pragma once

#include "afrilang/ast.hpp"

#include <memory>
#include <string>
#include <unordered_set>

namespace afrilang {

class Compiler {
public:
    explicit Compiler(std::string entryPath);

    std::unique_ptr<ProgramNode> compile();

private:
    std::string entryPath_;
    std::unordered_set<std::string> loadedFiles_;

    static std::string readFile(const std::string& path);
    static std::string resolvePath(const std::string& baseDir, const std::string& importPath);
    static std::string normalizePath(const std::string& path);

    std::unique_ptr<ProgramNode> parseFile(const std::string& path);
    void mergeProgram(ProgramNode& target, ProgramNode& source);
    void resolveImports(ProgramNode& program, const std::string& baseDir);
};

} // namespace afrilang
