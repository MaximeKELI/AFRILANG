#include "afrilang/compiler.hpp"

#include "afrilang/error.hpp"
#include "afrilang/lexer.hpp"
#include "afrilang/parser.hpp"
#include "afrilang/pkg.hpp"
#include "afrilang/stdlib_registry.hpp"

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <stdexcept>

namespace fs = std::filesystem;

namespace afrilang {

Compiler::Compiler(std::string entryPath, std::string afrilangRoot)
    : entryPath_(std::move(entryPath))
    , afrilangRoot_(std::move(afrilangRoot)) {
    fs::path dir = fs::path(entryPath_).parent_path();
    while (!dir.empty() && dir != dir.parent_path()) {
        if (fs::exists(dir / "afrilang.toml")) {
            projectDir_ = dir.string();
            break;
        }
        dir = dir.parent_path();
    }
    if (projectDir_.empty()) {
        projectDir_ = fs::path(entryPath_).parent_path().string();
    }
    if (afrilangRoot_.empty()) {
        if (const char* env = std::getenv("AFRILANG_HOME")) {
            afrilangRoot_ = env;
        }
    }
}

std::unique_ptr<ProgramNode> Compiler::compile() {
    loadedFiles_.clear();
    sources_ = SourceManager{};
    auto program = parseFile(entryPath_);
    const std::string baseDir = fs::path(entryPath_).parent_path().string();
    resolveImports(*program, baseDir);
    return program;
}

std::unique_ptr<ProgramNode> Compiler::compileFromSource(const std::string& source) {
    loadedFiles_.clear();
    sources_ = SourceManager{};
    const std::string normalized = normalizePath(entryPath_);
    loadedFiles_.insert(normalized);
    sources_.addFile(normalized, source);

    Lexer lexer(source);
    const std::vector<Token> tokens = lexer.tokenize();
    Parser parser(tokens);
    auto program = parser.parse();

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

std::string Compiler::resolvePath(const std::string& baseDir,
                                  const std::string& importPath) const {
    if (StdlibRegistry::isStdlibImport(importPath)) {
        return importPath;
    }
    fs::path resolved = fs::path(baseDir) / importPath;
    return normalizePath(resolved.string());
}

void Compiler::handleStdlibImport(ProgramNode& program, const std::string& importPath) {
    const std::string mod = StdlibRegistry::stdlibModuleName(importPath);
    if (mod == "io") StdlibRegistry::injectIoModule(program);
    else if (mod == "json") StdlibRegistry::injectJsonModule(program);
    else if (mod == "fs") StdlibRegistry::injectFsModule(program);
    else if (mod == "http") StdlibRegistry::injectHttpModule(program);
    else if (mod == "str") StdlibRegistry::injectStrModule(program);
    else if (mod == "logging") StdlibRegistry::injectLogModule(program);
    else if (mod == "math") StdlibRegistry::injectMathModule(program);
    else if (mod == "chrono") StdlibRegistry::injectTimeModule(program);
    else if (mod == "re") StdlibRegistry::injectReModule(program);
}

std::unique_ptr<ProgramNode> Compiler::parseFile(const std::string& path) {
    if (StdlibRegistry::isStdlibImport(path)) {
        return std::make_unique<ProgramNode>(
            std::vector<std::unique_ptr<ImportNode>>{},
            std::vector<std::unique_ptr<ModuleNode>>{},
            std::vector<std::unique_ptr<InterfaceNode>>{},
            std::vector<std::unique_ptr<RecordNode>>{},
            std::vector<std::unique_ptr<EnumNode>>{},
            std::vector<std::unique_ptr<ClassNode>>{},
            std::vector<std::unique_ptr<FunctionNode>>{},
            std::vector<std::unique_ptr<TestNode>>{},
            std::vector<std::unique_ptr<ExternDeclNode>>{},
            std::vector<std::unique_ptr<StatementNode>>{});
    }

    const std::string normalized = normalizePath(path);
    if (loadedFiles_.count(normalized)) {
        return std::make_unique<ProgramNode>(
            std::vector<std::unique_ptr<ImportNode>>{},
            std::vector<std::unique_ptr<ModuleNode>>{},
            std::vector<std::unique_ptr<InterfaceNode>>{},
            std::vector<std::unique_ptr<RecordNode>>{},
            std::vector<std::unique_ptr<EnumNode>>{},
            std::vector<std::unique_ptr<ClassNode>>{},
            std::vector<std::unique_ptr<FunctionNode>>{},
            std::vector<std::unique_ptr<TestNode>>{},
            std::vector<std::unique_ptr<ExternDeclNode>>{},
            std::vector<std::unique_ptr<StatementNode>>{});
    }
    loadedFiles_.insert(normalized);

    const std::string source = readFile(normalized);
    sources_.addFile(normalized, source);

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
    for (auto& en : source.enums) {
        target.enums.push_back(std::move(en));
    }
    for (auto& cls : source.classes) {
        target.classes.push_back(std::move(cls));
    }
    for (auto& func : source.functions) {
        target.functions.push_back(std::move(func));
    }
    for (auto& ext : source.externs) {
        target.externs.push_back(std::move(ext));
    }
}

void Compiler::resolveImports(ProgramNode& program, const std::string& baseDir) {
    std::vector<std::unique_ptr<ImportNode>> pending;
    pending.swap(program.imports);

    for (const auto& imp : pending) {
        if (StdlibRegistry::isStdlibImport(imp->path)) {
            handleStdlibImport(program, imp->path);
            continue;
        }

        std::string resolved;
        if (PkgRegistry::isPkgImport(imp->path)) {
            resolved = PkgRegistry::resolvePkgImport(imp->path, projectDir_, afrilangRoot_);
        } else {
            resolved = resolvePath(baseDir, imp->path);
        }
        auto imported = parseFile(resolved);
        const std::string importDir = fs::path(resolved).parent_path().string();
        resolveImports(*imported, importDir);
        mergeProgram(program, *imported);
    }
}

} // namespace afrilang
