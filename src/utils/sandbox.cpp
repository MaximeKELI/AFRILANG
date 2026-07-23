#include "afrilang/sandbox.hpp"
#include "afrilang/security.hpp"

#include <chrono>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <errno.h>
#include <fcntl.h>
#include <filesystem>
#include <fstream>
#include <signal.h>
#include <sstream>
#include <sys/resource.h>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

#if defined(__linux__)
#include <linux/audit.h>
#include <linux/filter.h>
#include <linux/landlock.h>
#include <linux/seccomp.h>
#include <stddef.h>
#include <sys/prctl.h>
#include <sys/syscall.h>
#endif

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

#if defined(__linux__)
/** Deny high-risk syscalls; allow everything else (incl. execve for the target). Linux only. */
void applyLinuxSeccompDenylist() {
    // Best-effort: failures must not abort child before exec (fall back to rlimits only).
    if (prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0) != 0) return;

    auto denyEq = [](int nr) {
        return std::vector<sock_filter>{
            BPF_JUMP(BPF_JMP | BPF_JEQ | BPF_K, static_cast<__u32>(nr), 0, 1),
            BPF_STMT(BPF_RET | BPF_K, SECCOMP_RET_ERRNO | (EPERM & SECCOMP_RET_DATA)),
        };
    };

    std::vector<sock_filter> filter;
    filter.push_back(BPF_STMT(BPF_LD | BPF_W | BPF_ABS,
                              static_cast<__u32>(offsetof(struct seccomp_data, arch))));
#if defined(__x86_64__)
    filter.push_back(BPF_JUMP(BPF_JMP | BPF_JEQ | BPF_K, AUDIT_ARCH_X86_64, 1, 0));
    filter.push_back(BPF_STMT(BPF_RET | BPF_K, SECCOMP_RET_ALLOW));
#elif defined(__aarch64__)
    filter.push_back(BPF_JUMP(BPF_JMP | BPF_JEQ | BPF_K, AUDIT_ARCH_AARCH64, 1, 0));
    filter.push_back(BPF_STMT(BPF_RET | BPF_K, SECCOMP_RET_ALLOW));
#else
    filter.push_back(BPF_STMT(BPF_RET | BPF_K, SECCOMP_RET_ALLOW));
    struct sock_fprog prog = {static_cast<unsigned short>(filter.size()), filter.data()};
    (void)prctl(PR_SET_SECCOMP, SECCOMP_MODE_FILTER, &prog);
    return;
#endif

    filter.push_back(BPF_STMT(BPF_LD | BPF_W | BPF_ABS,
                              static_cast<__u32>(offsetof(struct seccomp_data, nr))));

    const int denied[] = {
#ifdef __NR_ptrace
        __NR_ptrace,
#endif
#ifdef __NR_process_vm_readv
        __NR_process_vm_readv,
#endif
#ifdef __NR_process_vm_writev
        __NR_process_vm_writev,
#endif
#ifdef __NR_mount
        __NR_mount,
#endif
#ifdef __NR_umount2
        __NR_umount2,
#endif
#ifdef __NR_reboot
        __NR_reboot,
#endif
#ifdef __NR_kexec_load
        __NR_kexec_load,
#endif
#ifdef __NR_init_module
        __NR_init_module,
#endif
#ifdef __NR_finit_module
        __NR_finit_module,
#endif
#ifdef __NR_delete_module
        __NR_delete_module,
#endif
#ifdef __NR_swapon
        __NR_swapon,
#endif
#ifdef __NR_swapoff
        __NR_swapoff,
#endif
#ifdef __NR_bpf
        __NR_bpf,
#endif
#ifdef __NR_perf_event_open
        __NR_perf_event_open,
#endif
#ifdef __NR_userfaultfd
        __NR_userfaultfd,
#endif
    };
    for (int nr : denied) {
        auto part = denyEq(nr);
        filter.insert(filter.end(), part.begin(), part.end());
    }
    filter.push_back(BPF_STMT(BPF_RET | BPF_K, SECCOMP_RET_ALLOW));

    struct sock_fprog prog{};
    prog.len = static_cast<unsigned short>(filter.size());
    prog.filter = filter.data();
    (void)prctl(PR_SET_SECCOMP, SECCOMP_MODE_FILTER, &prog);
}

/** Best-effort Landlock FS restrict for sandboxed user binaries (Linux 5.13+). */
void applyLinuxLandlock(const std::string& executable) {
    const __u64 readExec =
        LANDLOCK_ACCESS_FS_EXECUTE | LANDLOCK_ACCESS_FS_READ_FILE | LANDLOCK_ACCESS_FS_READ_DIR;
    const __u64 writeTmp = LANDLOCK_ACCESS_FS_WRITE_FILE | LANDLOCK_ACCESS_FS_MAKE_REG |
                           LANDLOCK_ACCESS_FS_REMOVE_FILE | LANDLOCK_ACCESS_FS_READ_FILE |
                           LANDLOCK_ACCESS_FS_READ_DIR;

    struct landlock_ruleset_attr attr{};
    attr.handled_access_fs = readExec | writeTmp;
#ifdef LANDLOCK_ACCESS_FS_TRUNCATE
    attr.handled_access_fs |= LANDLOCK_ACCESS_FS_TRUNCATE;
#endif

    const int ruleset = static_cast<int>(
        syscall(__NR_landlock_create_ruleset, &attr, sizeof(attr), 0));
    if (ruleset < 0) return;

    auto allowPath = [&](const char* path, __u64 access) {
        const int fd = open(path, O_PATH | O_CLOEXEC);
        if (fd < 0) return;
        struct landlock_path_beneath_attr beneath{};
        beneath.allowed_access = access;
        beneath.parent_fd = fd;
        (void)syscall(__NR_landlock_add_rule, ruleset, LANDLOCK_RULE_PATH_BENEATH, &beneath, 0);
        close(fd);
    };

    // Dynamic linker + system libs
    allowPath("/lib", readExec);
    allowPath("/lib64", readExec);
    allowPath("/usr", readExec);
    allowPath("/etc", LANDLOCK_ACCESS_FS_READ_FILE | LANDLOCK_ACCESS_FS_READ_DIR);
    allowPath("/tmp", writeTmp);
    // Executable location (build dir / cwd binaries)
    try {
        const fs::path exePath = fs::absolute(executable);
        if (exePath.has_parent_path()) {
            allowPath(exePath.parent_path().c_str(), readExec);
        }
        allowPath(exePath.c_str(), readExec);
        // Also allow current working directory (tests often run ./bin from project root).
        allowPath(".", readExec);
    } catch (...) {
    }
    (void)prctl(PR_SET_NO_NEW_PRIVS, 1, 0, 0, 0);
    (void)syscall(__NR_landlock_restrict_self, ruleset, 0);
    close(ruleset);
}
#endif

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
    if (!config.interactiveGui && !config.interactiveConsole) {
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

    if (config.newSession && !config.interactiveGui && !config.interactiveConsole) {
        setsid();
    }
    applyChildLimits(config);
#if defined(__linux__)
    // Landlock + seccomp only in secure mode (ASan/LSan need broader FS + ptrace when insecure).
    if (isSecureMode() && !config.interactiveGui && !config.interactiveConsole) {
        if (config.applyLandlock) {
            applyLinuxLandlock(executable);
        }
        if (config.applySeccomp) {
            applyLinuxSeccompDenylist();
        }
    }
#endif

    if (config.interactiveConsole) {
        // Keep the real terminal for ask / readline programs.
    } else {
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
    // Host toolchain (g++/em++) must write temp files — never Landlock the compiler.
    ProcessConfig hostConfig = config;
    hostConfig.applyLandlock = false;
    const std::string outPath = secureTempPath("cmd.out.txt");
    const pid_t pid = spawnProcess(args[0], std::vector<std::string>(args.begin() + 1, args.end()),
                                   outPath, hostConfig);
    if (pid < 0) return 127;
    const ExecResult result = waitAndCollect(pid, hostConfig.timeoutSeconds, outPath,
                                             hostConfig.maxOutputBytes);
    combinedOutput = result.output;
    if (result.timedOut) return 124;
    return result.exitCode;
}

} // namespace afrilang
