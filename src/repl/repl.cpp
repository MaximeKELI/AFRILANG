#include "afrilang/cli.hpp"
#include "afrilang/codegen.hpp"
#include "afrilang/formatter.hpp"
#include "afrilang/sandbox.hpp"
#include "afrilang/security.hpp"
#include "afrilang/semantic.hpp"

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace fs = std::filesystem;

namespace afrilang {

static std::string replSessionPath() {
    return secureTempPath("repl_session.afr");
}

static void printReplHelp() {
    std::cout << "Commandes REPL:\n";
    std::cout << "  :help              — afficher cette aide\n";
    std::cout << "  :reset             — effacer la session\n";
    std::cout << "  :show              — afficher le code accumulé\n";
    std::cout << "  :run               — ré-exécuter la session\n";
    std::cout << "  :load <fichier>    — charger un fichier .afr dans la session\n";
    std::cout << "  :type <expression> — inférer le type d'une expression\n";
    std::cout << "  :history           — historique des lignes saisies\n";
    std::cout << "  :paste             — coller un bloc multi-lignes (terminer par :end)\n";
    std::cout << "  :quit              — quitter\n";
    std::cout << "\nChaque ligne valide est compilée et exécutée (sandbox, timeout 5s).\n";
}

bool Pipeline::evalReplSource(const std::string& source, std::string& errorOut) {
    try {
        validateSourceContent(source, "REPL session");
        const std::string sessionPath = replSessionPath();
        SourceManager sources;
        sources.addFile(sessionPath, source);
        auto program = parseSourceProgram(source, sessionPath, &sources);

        SemanticAnalyzer analyzer(*program, &sources, sessionPath);
        const SemanticResult semantic = analyzer.analyze();

        CodeGenerator codegen(*program, semantic);
        codegen.setRuntimeDir((fs::path(detectAfrilangRoot()) / "runtime").string());
        codegen.setSourceFile(sessionPath);
        codegen.setDebugSymbols(true);

        const std::string cppPath = secureTempPath("repl_session.generated.cpp");
        const std::string exePath = secureTempPath("repl_session.bin");

        if (!codegen.compileToExecutable(cppPath, exePath)) {
            errorOut = "Erreur de compilation g++ (voir " + cppPath + ")\n";
            return false;
        }

        ProcessConfig config;
        config.timeoutSeconds = securityLimits(SecurityContext::UntrustedExec).execTimeoutSeconds;
        config.maxMemoryMb = securityLimits(SecurityContext::UntrustedExec).maxMemoryMb;
        config.maxCpuSeconds = securityLimits(SecurityContext::UntrustedExec).maxCpuSeconds;
        config.maxOutputBytes = securityLimits(SecurityContext::UntrustedExec).maxOutputBytes;

        const ExecResult exec = execSandboxed(exePath, {}, config);
        if (!exec.output.empty()) {
            std::cout << exec.output;
        }
        if (exec.timedOut) {
            errorOut = "Exécution interrompue (timeout " +
                       std::to_string(config.timeoutSeconds) + "s)\n";
            return false;
        }
        if (exec.exitCode != 0) {
            errorOut = "Programme terminé avec le code " + std::to_string(exec.exitCode) + "\n";
        }
        return true;
    } catch (const CompileError& e) {
        errorOut = e.format();
        return false;
    }
}

bool Pipeline::inferReplExpressionType(const std::string& session,
                                       const std::string& expression,
                                       std::string& typeOut,
                                       std::string& errorOut) {
    try {
        std::string probe = session;
        if (!probe.empty() && probe.back() != '\n') {
            probe += "\n";
        }
        probe += "create const __repl_probe = " + expression + "\n";

        SourceManager sources;
        sources.addFile(replSessionPath(), probe);
        auto program = parseSourceProgram(probe, replSessionPath(), &sources);

        SemanticAnalyzer analyzer(*program, &sources, replSessionPath());
        const SemanticResult semantic = analyzer.analyze();

        const auto it = semantic.globalVariables.find("__repl_probe");
        if (it == semantic.globalVariables.end()) {
            errorOut = "Impossible d'inférer le type.\n";
            return false;
        }
        typeOut = it->second.toTypeName();
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

static std::string trim(const std::string& s) {
    std::size_t start = 0;
    while (start < s.size() && (s[start] == ' ' || s[start] == '\t')) ++start;
    std::size_t end = s.size();
    while (end > start && (s[end - 1] == ' ' || s[end - 1] == '\t')) --end;
    return s.substr(start, end - start);
}

int runRepl() {
    std::cout << "AFRILANG REPL v2.0 — tapez :help pour l'aide\n\n";
    secureSandboxRoot();

    std::string session;
    bool pasteMode = false;
    std::string pasteBuffer;
    std::vector<std::string> history;

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
                    history.push_back(pasteBuffer);
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
            if (line == ":run") {
                tryEval(session);
                continue;
            }
            if (line == ":history") {
                if (history.empty()) {
                    std::cout << "(historique vide)\n";
                } else {
                    for (std::size_t i = 0; i < history.size(); ++i) {
                        std::cout << i + 1 << ": " << history[i];
                        if (history[i].find('\n') == std::string::npos) std::cout << "\n";
                    }
                }
                continue;
            }
            if (line.rfind(":load", 0) == 0) {
                const std::string path = trim(line.substr(5));
                if (path.empty()) {
                    std::cout << "Usage: :load chemin/vers/fichier.afr\n";
                    continue;
                }
                std::ifstream in(path);
                if (!in) {
                    std::cout << "Fichier introuvable: " << path << "\n";
                    continue;
                }
                std::ostringstream buffer;
                buffer << in.rdbuf();
                const std::string content = buffer.str();
                if (!session.empty() && session.back() != '\n') session += "\n";
                session += content;
                if (!session.empty() && session.back() != '\n') session += "\n";
                history.push_back(":load " + path);
                std::cout << "Chargé: " << path << "\n";
                tryEval(session);
                continue;
            }
            if (line.rfind(":type", 0) == 0) {
                const std::string expr = trim(line.substr(5));
                if (expr.empty()) {
                    std::cout << "Usage: :type <expression>\n";
                    continue;
                }
                std::string typeOut;
                std::string error;
                if (Pipeline::inferReplExpressionType(session, expr, typeOut, error)) {
                    std::cout << typeOut << "\n";
                } else {
                    std::cerr << error;
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

        if (!line.empty()) {
            history.push_back(line);
        }

        if (!session.empty() && session.back() != '\n') {
            session += "\n";
        }
        session += line;

        try {
            SourceManager sources;
            sources.addFile(replSessionPath(), session);
            parseSourceProgram(session, replSessionPath(), &sources);
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
