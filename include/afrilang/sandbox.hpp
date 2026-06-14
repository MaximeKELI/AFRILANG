#pragma once

#include <string>

namespace afrilang {

struct ExecResult {
    int exitCode = -1;
    std::string output;
    bool timedOut = false;
};

ExecResult execWithTimeout(const std::string& executable,
                           const std::vector<std::string>& args,
                           int timeoutSeconds = 5);

bool isPathInsideRoot(const std::string& root, const std::string& candidate);

} // namespace afrilang
