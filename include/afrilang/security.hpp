#pragma once

#include "afrilang/diagnostics.hpp"

#include <cstddef>
#include <string>

namespace afrilang {

enum class SecurityContext {
    TrustedCompile,
    UntrustedExec,
    NetworkServe,
};

struct SecurityLimits {
    std::size_t maxSourceBytes = 512 * 1024;
    std::size_t maxOutputBytes = 1024 * 1024;
    std::size_t maxImportDepth = 32;
    std::size_t maxImportFiles = 128;
    std::size_t maxDeclarations = 4096;
    int execTimeoutSeconds = 5;
    int compileTimeoutSeconds = 60;
    std::size_t maxMemoryMb = 256;
    std::size_t maxCpuSeconds = 5;
    std::size_t maxServeBodyBytes = 64 * 1024;
    int maxServeRequestsPerMinute = 30;
};

bool isSecureMode();
bool allowFfi();
bool allowNetworkServe();
bool allowPublicServe();

SecurityLimits securityLimits(SecurityContext ctx);

void validateSourceContent(const std::string& source, const std::string& label,
                           SecurityContext ctx = SecurityContext::TrustedCompile);
void validateSourceSize(std::size_t bytes, const std::string& label,
                        SecurityContext ctx = SecurityContext::TrustedCompile);
void validatePathComponent(const std::string& component);
void validateProgramSize(const struct ProgramNode& program);

[[noreturn]] void securityViolation(const std::string& message,
                                    const std::string& file = "",
                                    int line = 0, int column = 0);

std::string secureSandboxRoot();
std::string secureTempPath(const std::string& name);
void cleanupSecureSandbox();

} // namespace afrilang
