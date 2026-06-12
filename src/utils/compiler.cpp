#include "afrilang/compiler.hpp"

#include "afrilang/error.hpp"
#include "afrilang/lexer.hpp"
#include "afrilang/parser.hpp"

#include <filesystem>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace fs = std::filesystem;

namespace afrilang {

Compiler::Compiler(std::string entryPath) : entryPath_(std::move(entryPath)) {}

std::unique_ptr<ProgramNode> Compiler::compile() {
    loadedFiles_.clear();
    auto program = parseFile(entryPath_);
    const std::string baseDir = fs::path(entryPath_).parent_path().string();
    resolveImports(*program, baseDir);
    return program;
}

std::string Compiler::readFile(const std::string& path) {
    std::ifstream file(path);
    if (!file) {
        throw std::runtime_error("Impossible d'ouvrir le fichier: " + path);
    }
    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

std::string Compiler::normalizePath(const std::string& path) {
    return fs::weakly_canonical(fs::path(path)).string();
}

std::string Compiler::resolvePath(const std::string& baseDir, const std::string& importPath) {
    fs::path resolved = fs::path(baseDir) / importPath;
    return normalizePath(resolved.string());
}

std::unique_ptr<ProgramNode> Compiler::parseFile(const std::string& path) {
    const std::string normalized = normalizePath(path);
    if (loadedFiles_.count(normalized)) {
        return std::make_unique<ProgramNode>(
            std::vector<std::unique_ptr<ImportNode>>{},
            std::vector<std::unique_ptr<ModuleNode>>{},
            std::vector<std::unique_ptr<RecordNode>>{},
            std::vector<std::unique_ptr<ClassNode>>{},
            std::vector<std::unique_ptr<FunctionNode>>{},
            std::vector<std::unique_ptr<StatementNode>>{});
    }
    loadedFiles_.insert(normalized);

    const std::string source = readFile(normalized);
    Lexer lexer(source);
    const std::vector<Token> tokens = lexer.tokenize();
    Parser parser(tokens);
    return parser.parse();
}

void Compiler::mergeProgram(ProgramNode& target, ProgramNode& source) {
    for (auto& mod : source.modules) {
        target.modules.push_back(std::move(mod));
    }
    for (auto& rec : source.records) {
        target.records.push_back(std::move(rec));
    }
    for (auto& cls : source.classes) {
        target.classes.push_back(std::move(cls));
    }
    for (auto& func : source.functions) {
        target.functions.push_back(std::move(func));
    }
}

void Compiler::resolveImports(ProgramNode& program, const std::string& baseDir) {
    std::vector<std::unique_ptr<ImportNode>> pending;
    pending.swap(program.imports);

    for (const auto& imp : pending) {
        const std::string resolved = resolvePath(baseDir, imp->path);
        auto imported = parseFile(resolved);
        const std::string importDir = fs::path(resolved).parent_path().string();
        resolveImports(*imported, importDir);
        mergeProgram(program, *imported);
    }
}

} // namespace afrilang
