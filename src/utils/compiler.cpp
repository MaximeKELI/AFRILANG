#include "afrilang/compiler.hpp"

#include "afrilang/error.hpp"
#include "afrilang/i18n.hpp"
#include "afrilang/lexer.hpp"
#include "afrilang/parser.hpp"
#include "afrilang/pkg.hpp"
#include "afrilang/sandbox.hpp"
#include "afrilang/security.hpp"
#include "afrilang/stdlib_registry.hpp"
#include "afrilang/utf8.hpp"

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
    std::error_code ec;
    const auto size = fs::file_size(path, ec);
    if (!ec) {
        validateSourceSize(static_cast<std::size_t>(size), path);
    }

    std::ifstream file(path, std::ios::binary);
    if (!file) {
        throw std::runtime_error("Impossible d'ouvrir le fichier: " + path);
    }
    std::ostringstream buffer;
    buffer << file.rdbuf();
    const std::string content = buffer.str();
    validateSourceContent(content, path);
    return content;
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
    const std::string canonical = normalizePath(resolved.string());
    if (!afrilangRoot_.empty()) {
        const fs::path root = fs::weakly_canonical(fs::path(afrilangRoot_));
        const fs::path proj = fs::weakly_canonical(fs::path(projectDir_));
        if (!isPathInsideRoot(root.string(), canonical) &&
            !isPathInsideRoot(proj.string(), canonical)) {
            throw CompileError("Import hors du projet: " + importPath, 0, 0, entryPath_, {},
                               {}, ErrorCode::ImportNotFound);
        }
    }
    return canonical;
}

void Compiler::handleStdlibImport(ProgramNode& program, const std::string& importPath) {
    const std::string mod = StdlibRegistry::stdlibModuleName(importPath);
    if (!mod.empty()) {
        StdlibRegistry::injectModuleByName(program, mod);
    }
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
    for (auto& iface : source.interfaces) {
        target.interfaces.push_back(std::move(iface));
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

void Compiler::resolveImports(ProgramNode& program, const std::string& baseDir, int depth) {
    const auto limits = securityLimits(SecurityContext::TrustedCompile);
    if (depth > static_cast<int>(limits.maxImportDepth)) {
        securityViolation("Profondeur d'import maximale dépassée (" +
                          std::to_string(limits.maxImportDepth) + ")");
    }
    if (loadedFiles_.size() > limits.maxImportFiles) {
        securityViolation("Nombre maximal de fichiers importés dépassé (" +
                          std::to_string(limits.maxImportFiles) + ")");
    }

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
        resolveImports(*imported, importDir, depth + 1);
        mergeProgram(program, *imported);
    }
}

} // namespace afrilang
