#include "afrilang/lexer.hpp"
#include "afrilang/parser.hpp"
#include "afrilang/semantic.hpp"
#include "afrilang/codegen.hpp"
#include "afrilang/error.hpp"

#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace fs = std::filesystem;

static void printUsage(const char* program) {
    std::cerr << "Usage: " << program << " <fichier.afr> [options]\n\n";
    std::cerr << "Options:\n";
    std::cerr << "  --tokens     Afficher les tokens (debug lexer)\n";
    std::cerr << "  --ast        Afficher l'AST (debug parser)\n";
    std::cerr << "  --emit       Générer le C++ sans compiler\n";
    std::cerr << "  -o <fichier> Chemin de l'exécutable de sortie\n";
    std::cerr << "  --run        Exécuter le programme après compilation\n";
}

static std::string readFile(const std::string& path) {
    std::ifstream file(path);
    if (!file) {
        throw std::runtime_error("Impossible d'ouvrir le fichier: " + path);
    }
    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

static void printTokens(const std::vector<afrilang::Token>& tokens) {
    std::cout << "=== Tokens ===\n";
    for (const auto& token : tokens) {
        std::cout << "  L" << token.line << " C" << token.column
                  << "  " << token << "\n";
    }
    std::cout << "==============\n";
}

static void printAST(const afrilang::ProgramNode& program) {
    std::cout << "=== AST ===\n";
    std::cout << "Classes: " << program.classes.size() << "\n";
    for (const auto& cls : program.classes) {
        std::cout << "  class " << cls->name << " (" << cls->methods.size() << " méthodes)\n";
        for (const auto& method : cls->methods) {
            std::cout << "    function " << method->name << "(" << method->parameters.size() << " params)";
            if (!method->returnTypeName.empty()) {
                std::cout << " returns " << method->returnTypeName;
            }
            std::cout << " [" << method->body.size() << " stmts]\n";
        }
    }
    std::cout << "Statements: " << program.statements.size() << "\n";
    std::cout << "===========\n";
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printUsage(argv[0]);
        return 1;
    }

    std::string sourcePath = argv[1];
    bool showTokens = false;
    bool showAST = false;
    bool emitOnly = false;
    bool runAfter = false;
    std::string outputExecutable;

    for (int i = 2; i < argc; ++i) {
        std::string arg = argv[i];
        if (arg == "--tokens") {
            showTokens = true;
        } else if (arg == "--ast") {
            showAST = true;
        } else if (arg == "--emit") {
            emitOnly = true;
        } else if (arg == "--run") {
            runAfter = true;
        } else if (arg == "-o" && i + 1 < argc) {
            outputExecutable = argv[++i];
        } else {
            std::cerr << "Option inconnue: " << arg << "\n";
            printUsage(argv[0]);
            return 1;
        }
    }

    try {
        const std::string source = readFile(sourcePath);
        const fs::path srcPath(sourcePath);
        const std::string baseName = srcPath.stem().string();

        // ── Phase 1 : Lexing ──────────────────────────────────────────────
        afrilang::Lexer lexer(source);
        const std::vector<afrilang::Token> tokens = lexer.tokenize();

        if (showTokens) {
            printTokens(tokens);
        }

        // ── Phase 2 : Parsing ───────────────────────────────────────────
        afrilang::Parser parser(tokens);
        std::unique_ptr<afrilang::ProgramNode> program = parser.parse();

        if (showAST) {
            printAST(*program);
        }

        // ── Phase 3 : Analyse sémantique ──────────────────────────────────
        afrilang::SemanticAnalyzer analyzer(*program);
        const afrilang::SemanticResult semantic = analyzer.analyze();

        // ── Phase 4 : Code generation ─────────────────────────────────────
        afrilang::CodeGenerator codegen(*program, semantic);
        const std::string generatedCpp = baseName + ".generated.cpp";

        if (emitOnly) {
            std::ofstream out(generatedCpp);
            codegen.generate(out);
            std::cout << "Code C++ généré: " << generatedCpp << "\n";
            return 0;
        }

        if (outputExecutable.empty()) {
            outputExecutable = baseName;
        }

        std::cout << "Compilation de " << sourcePath << "...\n";

        if (!codegen.compileToExecutable(generatedCpp, outputExecutable)) {
            std::cerr << "Erreur: la compilation g++ a échoué.\n";
            std::cerr << "Consultez " << generatedCpp << " pour le code généré.\n";
            return 1;
        }

        std::cout << "Exécutable produit: " << outputExecutable << "\n";

        if (runAfter) {
            std::cout << "--- Exécution ---\n";
            const std::string runCmd = "./" + outputExecutable;
            const int runResult = std::system(runCmd.c_str());
            std::cout << "--- Fin (code: " << runResult << ") ---\n";
        }

    } catch (const afrilang::CompileError& e) {
        std::cerr << e.what() << "\n";
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Erreur: " << e.what() << "\n";
        return 1;
    }

    return 0;
}
