#include "afrilang/security.hpp"

#include "afrilang/ast.hpp"
#include "afrilang/i18n.hpp"
#include "afrilang/utf8.hpp"

#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <random>
#include <sstream>

namespace fs = std::filesystem;

namespace afrilang {

namespace {

bool envEnabled(const char* name) {
    if (const char* v = std::getenv(name)) {
        return v[0] == '1' || v[0] == 'y' || v[0] == 'Y';
    }
    return false;
}

std::string g_sandboxRoot;

} // namespace

bool isSecureMode() {
    return !envEnabled("AFRILANG_INSECURE");
}

bool allowFfi() {
    return envEnabled("AFRILANG_ALLOW_FFI") || !isSecureMode();
}

bool allowNetworkServe() {
    return envEnabled("AFRILANG_ALLOW_SERVE");
}

bool allowPublicServe() {
    return envEnabled("AFRILANG_SERVE_PUBLIC");
}

SecurityLimits securityLimits(SecurityContext ctx) {
    SecurityLimits limits;
    switch (ctx) {
        case SecurityContext::UntrustedExec:
            limits.execTimeoutSeconds = 5;
            limits.maxMemoryMb = 128;
            limits.maxCpuSeconds = 5;
            limits.maxSourceBytes = 128 * 1024;
            break;
        case SecurityContext::NetworkServe:
            limits.execTimeoutSeconds = 5;
            limits.maxMemoryMb = 128;
            limits.maxCpuSeconds = 5;
            limits.maxSourceBytes = 64 * 1024;
            limits.maxServeBodyBytes = 64 * 1024;
            limits.maxServeRequestsPerMinute = 30;
            break;
        case SecurityContext::TrustedCompile:
            limits.execTimeoutSeconds = 30;
            limits.compileTimeoutSeconds = 120;
            limits.maxMemoryMb = 512;
            limits.maxCpuSeconds = 120;
            break;
    }
    return limits;
}

void validateSourceContent(const std::string& source, const std::string& label) {
    validateSourceSize(source.size(), label);
    if (source.find('\0') != std::string::npos) {
        securityViolation("Octets nuls interdits dans " + label);
    }
    if (!source.empty() && !isValidUtf8(source)) {
        throw CompileError("Encodage UTF-8 invalide dans " + label, 1, 1, label, {},
                           {}, ErrorCode::InvalidUtf8);
    }
}

void validateSourceSize(std::size_t bytes, const std::string& label) {
    const auto limits = securityLimits(SecurityContext::TrustedCompile);
    if (bytes > limits.maxSourceBytes) {
        securityViolation("Source trop volumineuse (" + std::to_string(bytes) +
                          " octets, max " + std::to_string(limits.maxSourceBytes) + "): " + label);
    }
}

void validatePathComponent(const std::string& component) {
    if (component.empty() || component == "." || component == "..") {
        securityViolation("Composant de chemin interdit: '" + component + "'");
    }
    if (component.find("..") != std::string::npos ||
        component.find('\0') != std::string::npos) {
        securityViolation("Chemin suspect: '" + component + "'");
    }
}

void validateProgramSize(const ProgramNode& program) {
    const auto limits = securityLimits(SecurityContext::TrustedCompile);
    const std::size_t total = program.classes.size() + program.functions.size() +
                              program.modules.size() + program.enums.size() +
                              program.records.size() + program.interfaces.size();
    if (total > limits.maxDeclarations) {
        securityViolation("Programme trop complexe (" + std::to_string(total) +
                          " déclarations, max " + std::to_string(limits.maxDeclarations) + ")");
    }
}

[[noreturn]] void securityViolation(const std::string& message,
                                    const std::string& file,
                                    int line, int column) {
    throw CompileError(message, line, column, file, {}, {}, ErrorCode::SecurityViolation);
}

std::string secureSandboxRoot() {
    if (!g_sandboxRoot.empty()) return g_sandboxRoot;

    fs::path base = fs::temp_directory_path();
    if (const char* xdg = std::getenv("XDG_RUNTIME_DIR")) {
        base = xdg;
    } else if (const char* home = std::getenv("HOME")) {
        base = fs::path(home) / ".cache" / "afrilang";
    }

    std::random_device rd;
    std::ostringstream id;
    id << "sandbox-" << rd();
    const fs::path dir = base / id.str();
    fs::create_directories(dir);
    fs::permissions(dir, fs::perms::owner_all, fs::perm_options::replace);
    g_sandboxRoot = dir.string();
    return g_sandboxRoot;
}

std::string secureTempPath(const std::string& name) {
    validatePathComponent(name);
    const fs::path path = fs::path(secureSandboxRoot()) / name;
    return path.string();
}

void cleanupSecureSandbox() {
    if (g_sandboxRoot.empty()) return;
    std::error_code ec;
    fs::remove_all(g_sandboxRoot, ec);
    g_sandboxRoot.clear();
}

} // namespace afrilang
