#pragma once

#include "afrilang/security.hpp"

#include <string>
#include <vector>

namespace afrilang {

struct ExecResult {
    int exitCode = -1;
    std::string output;
    bool timedOut = false;
    bool outputTruncated = false;
};

struct ProcessConfig {
    int timeoutSeconds = 5;
    std::size_t maxOutputBytes = 1024 * 1024;
    std::size_t maxMemoryMb = 256;
    std::size_t maxCpuSeconds = 5;
    bool applyResourceLimits = true;
    bool newSession = true;
};

ExecResult execWithTimeout(const std::string& executable,
                           const std::vector<std::string>& args,
                           int timeoutSeconds = 5);

ExecResult execSandboxed(const std::string& executable,
                         const std::vector<std::string>& args,
                         const ProcessConfig& config = {});

int runCommand(const std::vector<std::string>& args,
               const ProcessConfig& config,
               std::string& combinedOutput);

bool isPathInsideRoot(const std::string& root, const std::string& candidate);

} // namespace afrilang
