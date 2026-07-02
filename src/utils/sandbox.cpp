#include "afrilang/sandbox.hpp"
#include "afrilang/security.hpp"

#include <chrono>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <fcntl.h>
#include <filesystem>
#include <fstream>
#include <signal.h>
#include <sstream>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>

namespace fs = std::filesystem;

namespace afrilang {

namespace {

void closeAllFdsExcept(int keep1, int keep2) {
    const long maxFd = sysconf(_SC_OPEN_MAX);
    const long limit = maxFd > 0 ? maxFd : 1024;
    for (long fd = 3; fd < limit; ++fd) {
        if (fd != keep1 && fd != keep2) {
            close(static_cast<int>(fd));
        }
    }
}

void applyChildLimits(const ProcessConfig& config) {
    if (!config.applyResourceLimits) return;

    struct rlimit rl{};
    if (config.maxMemoryMb > 0) {
        const rlim_t bytes = static_cast<rlim_t>(config.maxMemoryMb) * 1024 * 1024;
        rl.rlim_cur = bytes;
        rl.rlim_max = bytes;
        setrlimit(RLIMIT_AS, &rl);
    }
    if (config.maxCpuSeconds > 0) {
        rl.rlim_cur = config.maxCpuSeconds;
        rl.rlim_max = config.maxCpuSeconds;
        setrlimit(RLIMIT_CPU, &rl);
    }
    if (!config.interactiveGui && !config.relaxFileSizeLimit) {
        rl.rlim_cur = 16 * 1024 * 1024;
        rl.rlim_max = 16 * 1024 * 1024;
        setrlimit(RLIMIT_FSIZE, &rl);
    }
    rl.rlim_cur = 64;
    rl.rlim_max = 64;
    setrlimit(RLIMIT_NOFILE, &rl);
    if (config.limitProcessCount) {
        rl.rlim_cur = 32;
        rl.rlim_max = 32;
        setrlimit(RLIMIT_NPROC, &rl);
    }
}

std::string readOutputCapped(const std::string& path, std::size_t maxBytes, bool& truncated) {
    std::ifstream in(path, std::ios::binary);
    if (!in) return {};
    std::string data;
    data.resize(maxBytes);
    in.read(data.data(), static_cast<std::streamsize>(maxBytes));
    const auto got = static_cast<std::size_t>(in.gcount());
    data.resize(got);
    truncated = in.peek() != std::ifstream::traits_type::eof();
    return data;
}

ExecResult waitAndCollect(pid_t pid, int timeoutSeconds, const std::string& outPath,
                          std::size_t maxOutputBytes) {
    ExecResult result;
    const bool noTimeout = timeoutSeconds <= 0;
    const auto deadline = std::chrono::steady_clock::now() +
                          std::chrono::seconds(timeoutSeconds);
    int status = 0;
    while (true) {
        const pid_t w = waitpid(pid, &status, WNOHANG);
        if (w == pid) {
            result.exitCode = WIFEXITED(status) ? WEXITSTATUS(status) : 1;
            break;
        }
        if (!noTimeout && std::chrono::steady_clock::now() >= deadline) {
            kill(-pid, SIGKILL);
            waitpid(pid, &status, 0);
            result.timedOut = true;
            result.exitCode = 124;
            break;
        }
        usleep(50000);
    }
    result.output = readOutputCapped(outPath, maxOutputBytes, result.outputTruncated);
    fs::remove(outPath);
    return result;
}

pid_t spawnProcess(const std::string& executable,
                   const std::vector<std::string>& args,
                   const std::string& outPath,
                   const ProcessConfig& config) {
    const pid_t pid = fork();
    if (pid != 0) return pid;

    if (config.newSession && !config.interactiveGui) {
        setsid();
    }
    applyChildLimits(config);

    const char* sinkPath = config.interactiveGui ? "/dev/null" : outPath.c_str();
    const int fd = open(sinkPath, O_WRONLY | O_CREAT | O_TRUNC, 0600);
    if (fd >= 0) {
        dup2(fd, STDOUT_FILENO);
        dup2(fd, STDERR_FILENO);
        close(fd);
    }
    if (!config.interactiveGui) {
        closeAllFdsExcept(STDOUT_FILENO, STDERR_FILENO);
    }

    std::vector<char*> argv;
    argv.push_back(const_cast<char*>(executable.c_str()));
    for (const auto& arg : args) {
        argv.push_back(const_cast<char*>(arg.c_str()));
    }
    argv.push_back(nullptr);

    execvp(executable.c_str(), argv.data());
    _exit(127);
}

} // namespace

bool isPathInsideRoot(const std::string& root, const std::string& candidate) {
    try {
        const fs::path rootPath = fs::weakly_canonical(fs::path(root));
        const fs::path candPath = fs::weakly_canonical(fs::path(candidate));
        const auto [rootEnd, candEnd] = std::mismatch(rootPath.begin(), rootPath.end(),
                                                      candPath.begin(), candPath.end());
        return rootEnd == rootPath.end();
    } catch (...) {
        return false;
    }
}

ExecResult execWithTimeout(const std::string& executable,
                           const std::vector<std::string>& args,
                           int timeoutSeconds) {
    ProcessConfig config;
    config.timeoutSeconds = timeoutSeconds;
    return execSandboxed(executable, args, config);
}

ExecResult execSandboxed(const std::string& executable,
                         const std::vector<std::string>& args,
                         const ProcessConfig& config) {
    ExecResult result;
    const std::string outPath = executable + ".sandbox.out.txt";
    const pid_t pid = spawnProcess(executable, args, outPath, config);
    if (pid < 0) {
        result.output = "fork failed";
        return result;
    }
    return waitAndCollect(pid, config.timeoutSeconds, outPath, config.maxOutputBytes);
}

int runCommand(const std::vector<std::string>& args,
               const ProcessConfig& config,
               std::string& combinedOutput) {
    if (args.empty()) return 127;
    const std::string outPath = secureTempPath("cmd.out.txt");
    const pid_t pid = spawnProcess(args[0], std::vector<std::string>(args.begin() + 1, args.end()),
                                   outPath, config);
    if (pid < 0) return 127;
    const ExecResult result = waitAndCollect(pid, config.timeoutSeconds, outPath,
                                             config.maxOutputBytes);
    combinedOutput = result.output;
    if (result.timedOut) return 124;
    return result.exitCode;
}

} // namespace afrilang
