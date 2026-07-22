#pragma once

// std/process — Go os/exec / Python subprocess style (no shell by default).
// Uses posix_spawn + pipes. Avoids std::system (SECURITY.md).

#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#include <cerrno>
#include <cstdint>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>

#if defined(__APPLE__) || defined(__linux__)
#include <spawn.h>
extern char** environ;
#endif

namespace afrilang::runtime::process {

inline std::vector<char*> buildArgv(const std::string& program,
                                    const std::vector<std::string>& args) {
    std::vector<char*> argv;
    argv.reserve(args.size() + 2);
    argv.push_back(const_cast<char*>(program.c_str()));
    for (const auto& a : args) argv.push_back(const_cast<char*>(a.c_str()));
    argv.push_back(nullptr);
    return argv;
}

inline std::int64_t run(const std::string& program, const std::vector<std::string>& args) {
#if defined(__APPLE__) || defined(__linux__)
    auto argvOwned = args; // keep strings alive
    std::vector<char*> argv;
    argv.push_back(const_cast<char*>(program.c_str()));
    for (auto& a : argvOwned) argv.push_back(a.data());
    argv.push_back(nullptr);

    pid_t pid = 0;
    const int rc = posix_spawnp(&pid, program.c_str(), nullptr, nullptr, argv.data(), environ);
    if (rc != 0) return -1;

    int status = 0;
    if (waitpid(pid, &status, 0) < 0) return -1;
    if (WIFEXITED(status)) return static_cast<std::int64_t>(WEXITSTATUS(status));
    if (WIFSIGNALED(status)) return 128 + static_cast<std::int64_t>(WTERMSIG(status));
    return -1;
#else
    (void)program;
    (void)args;
    return -1;
#endif
}

inline std::int64_t runCmd(const std::string& program) {
    return run(program, {});
}

// Capture stdout (+ optionally merge stderr). Returns empty string on spawn failure.
inline std::string capture(const std::string& program, const std::vector<std::string>& args,
                           bool mergeStderr) {
#if defined(__APPLE__) || defined(__linux__)
    int outPipe[2];
    if (pipe(outPipe) != 0) return {};

    posix_spawn_file_actions_t actions;
    posix_spawn_file_actions_init(&actions);
    posix_spawn_file_actions_addclose(&actions, outPipe[0]);
    posix_spawn_file_actions_adddup2(&actions, outPipe[1], STDOUT_FILENO);
    if (mergeStderr) {
        posix_spawn_file_actions_adddup2(&actions, outPipe[1], STDERR_FILENO);
    }
    posix_spawn_file_actions_addclose(&actions, outPipe[1]);

    auto argvOwned = args;
    std::vector<char*> argv;
    argv.push_back(const_cast<char*>(program.c_str()));
    for (auto& a : argvOwned) argv.push_back(a.data());
    argv.push_back(nullptr);

    pid_t pid = 0;
    const int rc =
        posix_spawnp(&pid, program.c_str(), &actions, nullptr, argv.data(), environ);
    posix_spawn_file_actions_destroy(&actions);
    close(outPipe[1]);
    if (rc != 0) {
        close(outPipe[0]);
        return {};
    }

    std::string out;
    char buf[4096];
    while (true) {
        const ssize_t n = ::read(outPipe[0], buf, sizeof(buf));
        if (n <= 0) break;
        out.append(buf, static_cast<std::size_t>(n));
    }
    close(outPipe[0]);

    int status = 0;
    waitpid(pid, &status, 0);
    return out;
#else
    (void)program;
    (void)args;
    (void)mergeStderr;
    return {};
#endif
}

inline std::string captureStdout(const std::string& program,
                                 const std::vector<std::string>& args) {
    return capture(program, args, false);
}

inline std::string captureCombined(const std::string& program,
                                   const std::vector<std::string>& args) {
    return capture(program, args, true);
}

// Convenience: single-arg program with no argv extras, or shell-like via /bin/sh -c
// only when AFRILANG_INSECURE=1 (documented). Prefer run()/captureStdout().
inline std::int64_t runShell(const std::string& command) {
    const char* insecure = std::getenv("AFRILANG_INSECURE");
    if (!insecure || std::string(insecure) != "1") return -2; // refused
    return run("/bin/sh", std::vector<std::string>{"-c", command});
}

inline std::int64_t getPid() {
    return static_cast<std::int64_t>(::getpid());
}

inline void exitWith(std::int64_t code) {
    std::_Exit(static_cast<int>(code));
}

} // namespace afrilang::runtime::process
