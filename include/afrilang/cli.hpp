#pragma once

#include "afrilang/diagnostics.hpp"

#include <string>

namespace afrilang {

struct CompileOptions {
    bool showTokens = false;
    bool showAST = false;
    bool emitOnly = false;
    bool runAfter = false;
    std::string outputExecutable;
    std::string runtimeDir;
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
    static int runTests(const std::string& afrilangRoot);
};

int runCli(int argc, char* argv[]);

std::string detectAfrilangRoot();

} // namespace afrilang
