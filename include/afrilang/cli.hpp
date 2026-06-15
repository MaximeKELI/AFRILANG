#pragma once

#include "afrilang/diagnostics.hpp"

#include <string>

namespace afrilang {

struct CompileOptions {
    bool showTokens = false;
    bool showAST = false;
    bool emitOnly = false;
    bool runAfter = false;
    bool watchMode = false;
    bool profileMode = false;
    bool coverageMode = false;
    bool debugSymbols = true;
    bool useCache = true;
    std::string outputExecutable;
    std::string runtimeDir;
    std::string sourcePath;
    std::string crossTarget = "native";
};

struct CompileResult {
    bool success = false;
    std::string generatedCpp;
    std::string executable;
};

class Pipeline {
public:
    static CompileResult compileFile(const std::string& sourcePath,
                                     const CompileOptions& options = {});

    static bool checkFile(const std::string& sourcePath);
    static int runTests(const std::string& afrilangRoot, bool coverage = false);

    static bool formatFile(const std::string& sourcePath, bool writeBack);
    static bool evalReplSource(const std::string& source, std::string& errorOut);
    static bool inferReplExpressionType(const std::string& session,
                                        const std::string& expression,
                                        std::string& typeOut,
                                        std::string& errorOut);
};

int runCli(int argc, char* argv[]);
int runRepl();

std::string detectAfrilangRoot();

} // namespace afrilang
