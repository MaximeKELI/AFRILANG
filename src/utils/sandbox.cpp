#include "afrilang/sandbox.hpp"

#include <chrono>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <sstream>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

namespace fs = std::filesystem;

namespace afrilang {

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
    ExecResult result;
    const std::string outPath = executable + ".sandbox.out.txt";

    const pid_t pid = fork();
    if (pid < 0) {
        result.output = "fork failed";
        return result;
    }

    if (pid == 0) {
        std::vector<char*> argv;
        argv.push_back(const_cast<char*>(executable.c_str()));
        for (const auto& arg : args) {
            argv.push_back(const_cast<char*>(arg.c_str()));
        }
        argv.push_back(nullptr);

        int fd = open(outPath.c_str(), O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd >= 0) {
            dup2(fd, STDOUT_FILENO);
            dup2(fd, STDERR_FILENO);
            close(fd);
        }
        execv(executable.c_str(), argv.data());
        _exit(127);
    }

    const auto deadline = std::chrono::steady_clock::now() +
                          std::chrono::seconds(timeoutSeconds);
    int status = 0;
    while (true) {
        const pid_t w = waitpid(pid, &status, WNOHANG);
        if (w == pid) {
            result.exitCode = WIFEXITED(status) ? WEXITSTATUS(status) : 1;
            break;
        }
        if (std::chrono::steady_clock::now() >= deadline) {
            kill(pid, SIGKILL);
            waitpid(pid, &status, 0);
            result.timedOut = true;
            result.exitCode = 124;
            break;
        }
        usleep(50000);
    }

    std::ifstream in(outPath);
    std::ostringstream buffer;
    buffer << in.rdbuf();
    result.output = buffer.str();
    fs::remove(outPath);
    return result;
}

} // namespace afrilang
