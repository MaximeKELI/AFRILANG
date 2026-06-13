#pragma once

#include "afrilang/ast.hpp"
#include "afrilang/diagnostics.hpp"

#include <memory>
#include <string>
#include <unordered_set>

namespace afrilang {

class Compiler {
public:
    Compiler(std::string entryPath, std::string afrilangRoot = "");

    std::unique_ptr<ProgramNode> compile();
    std::unique_ptr<ProgramNode> compileFromSource(const std::string& source);
    const SourceManager& sources() const { return sources_; }

private:
    std::string entryPath_;
    std::string afrilangRoot_;
    std::string projectDir_;
    std::unordered_set<std::string> loadedFiles_;
    SourceManager sources_;

    static std::string readFile(const std::string& path);
    std::string resolvePath(const std::string& baseDir, const std::string& importPath) const;
    static std::string normalizePath(const std::string& path);

    std::unique_ptr<ProgramNode> parseFile(const std::string& path);
    void mergeProgram(ProgramNode& target, ProgramNode& source);
    void resolveImports(ProgramNode& program, const std::string& baseDir);
    void handleStdlibImport(ProgramNode& program, const std::string& importPath);
};

} // namespace afrilang
