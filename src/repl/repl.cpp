#include "afrilang/cli.hpp"
#include "afrilang/codegen.hpp"
#include "afrilang/formatter.hpp"
#include "afrilang/semantic.hpp"

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace fs = std::filesystem;

namespace afrilang {

static const char* kReplSessionPath = "/tmp/afrilang_repl_session.afr";

static void printReplHelp() {
    std::cout << "Commandes REPL:\n";
    std::cout << "  :help   — afficher cette aide\n";
    std::cout << "  :reset  — effacer la session\n";
    std::cout << "  :show   — afficher le code accumulé\n";
    std::cout << "  :paste  — coller un bloc multi-lignes (terminer par :end)\n";
    std::cout << "  :quit   — quitter\n";
    std::cout << "\nChaque ligne valide est compilée et exécutée.\n";
}

bool Pipeline::evalReplSource(const std::string& source, std::string& errorOut) {
    try {
        SourceManager sources;
        sources.addFile(kReplSessionPath, source);
        auto program = parseSourceProgram(source, kReplSessionPath, &sources);

        SemanticAnalyzer analyzer(*program, &sources, kReplSessionPath);
        const SemanticResult semantic = analyzer.analyze();

        CodeGenerator codegen(*program, semantic);
        codegen.setRuntimeDir((fs::path(detectAfrilangRoot()) / "runtime").string());
        codegen.setSourceFile(kReplSessionPath);
        codegen.setDebugSymbols(true);

        const std::string cppPath = "/tmp/afrilang_repl_session.generated.cpp";
        const std::string exePath = "/tmp/afrilang_repl_session";

        if (!codegen.compileToExecutable(cppPath, exePath)) {
            errorOut = "Erreur de compilation g++ (voir " + cppPath + ")\n";
            return false;
        }

        const int code = std::system(exePath.c_str());
        if (code != 0) {
            errorOut = "Programme terminé avec le code " + std::to_string(code) + "\n";
        }
        return true;
    } catch (const CompileError& e) {
        errorOut = e.format();
        return false;
    }
}

bool Pipeline::formatFile(const std::string& sourcePath, bool writeBack) {
    try {
        std::ifstream in(sourcePath);
        if (!in) {
            std::cerr << "Erreur: impossible d'ouvrir " << sourcePath << "\n";
            return false;
        }

        std::ostringstream buffer;
        buffer << in.rdbuf();
        const std::string source = buffer.str();

        SourceManager sources;
        sources.addFile(sourcePath, source);
        auto program = parseSourceProgram(source, sourcePath, &sources);
        Formatter formatter(*program);
        const std::string formatted = formatter.format();

        if (writeBack) {
            std::ofstream out(sourcePath);
            if (!out) {
                std::cerr << "Erreur: impossible d'écrire " << sourcePath << "\n";
                return false;
            }
            out << formatted;
            if (!formatted.empty() && formatted.back() != '\n') {
                out << "\n";
            }
        } else {
            std::cout << formatted;
            if (!formatted.empty() && formatted.back() != '\n') {
                std::cout << "\n";
            }
        }
        return true;
    } catch (const CompileError& e) {
        std::cerr << e.format();
        return false;
    }
}

int runRepl() {
    std::cout << "AFRILANG REPL v1.0 — tapez :help pour l'aide\n\n";

    std::string session;
    bool pasteMode = false;
    std::string pasteBuffer;

    auto tryEval = [&](const std::string& source) -> bool {
        if (source.find_first_not_of(" \t\n\r") == std::string::npos) {
            return true;
        }
        std::string error;
        const bool ok = Pipeline::evalReplSource(source, error);
        if (!ok) {
            std::cerr << error;
            return false;
        }
        return true;
    };

    std::string line;
    while (true) {
        if (pasteMode) {
            std::cout << "... ";
        } else {
            std::cout << ">>> ";
        }
        std::cout.flush();

        if (!std::getline(std::cin, line)) {
            std::cout << "\n";
            break;
        }

        if (pasteMode) {
            if (line == ":end") {
                pasteMode = false;
                if (!pasteBuffer.empty()) {
                    if (!session.empty() && session.back() != '\n') session += "\n";
                    session += pasteBuffer;
                    pasteBuffer.clear();
                    tryEval(session);
                }
            } else {
                if (!pasteBuffer.empty()) pasteBuffer += "\n";
                pasteBuffer += line;
            }
            continue;
        }

        if (!line.empty() && line[0] == ':') {
            if (line == ":quit" || line == ":exit") {
                break;
            }
            if (line == ":help") {
                printReplHelp();
                continue;
            }
            if (line == ":reset") {
                session.clear();
                std::cout << "Session réinitialisée.\n";
                continue;
            }
            if (line == ":show") {
                if (session.empty()) {
                    std::cout << "(session vide)\n";
                } else {
                    std::cout << session;
                    if (session.back() != '\n') std::cout << "\n";
                }
                continue;
            }
            if (line == ":paste") {
                pasteMode = true;
                pasteBuffer.clear();
                std::cout << "Mode collage — terminez avec :end\n";
                continue;
            }
            std::cout << "Commande inconnue. Tapez :help\n";
            continue;
        }

        if (!session.empty() && session.back() != '\n') {
            session += "\n";
        }
        session += line;

        try {
            SourceManager sources;
            sources.addFile(kReplSessionPath, session);
            parseSourceProgram(session, kReplSessionPath, &sources);
            tryEval(session);
        } catch (const CompileError& e) {
            const std::string msg = e.what();
            if (msg.find("'end' attendu") != std::string::npos ||
                msg.find("end' attendu") != std::string::npos) {
                std::cout << "... (bloc incomplet, continuez ou :paste)\n";
            } else {
                std::cerr << e.format();
                if (!session.empty() && session.size() >= line.size()) {
                    if (session.size() > line.size() &&
                        session[session.size() - line.size() - 1] == '\n') {
                        session.resize(session.size() - line.size() - 1);
                    } else {
                        session.resize(session.size() - line.size());
                    }
                }
            }
        }
    }

    return 0;
}

} // namespace afrilang
