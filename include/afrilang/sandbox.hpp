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
  // 0 = no wall-clock timeout (interactive GUI programs).
  int timeoutSeconds = 5;
  std::size_t maxOutputBytes = 1024 * 1024;
  std::size_t maxMemoryMb = 256;
  std::size_t maxCpuSeconds = 5;
  bool applyResourceLimits = true;
  // Linux: PR_SET_NO_NEW_PRIVS + seccomp deny-list (ptrace/mount/…). No-op elsewhere.
  bool applySeccomp = true;
  // Linux: Landlock FS restrict for sandboxed binaries. No-op if kernel/ABI unsupported.
  bool applyLandlock = true;
  bool newSession = true;
  bool limitProcessCount = false;
  // Keep DISPLAY/Wayland sockets open (required for SDL windows).
  bool interactiveGui = false;
  // Keep stdin/stdout/stderr on the terminal (required for `ask`).
  bool interactiveConsole = false;
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

#if !defined(_WIN32)
/** Strip Flutter/Dart snap dirs from PATH and prefer host /usr/bin. */
std::string sanitizeHostToolchainPath(const char* pathEnv);
/** Filter LD_LIBRARY_PATH / LIBRARY_PATH / … — empty means unset. */
std::string sanitizeColonPathList(const char* value);
/** Apply PATH + lib-path sanitization to the current process environ. */
void ensureHostToolchainPath();
#endif

} // namespace afrilang
