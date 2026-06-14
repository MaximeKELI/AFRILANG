#include "afrilang/debug.hpp"

#include <iostream>
#include <sys/wait.h>
#include <unistd.h>
#include <vector>

namespace afrilang {

int runDebugger(const std::string& executablePath,
                const std::vector<std::string>& args) {
    const pid_t pid = fork();
    if (pid < 0) {
        std::cerr << "Erreur: fork échoué.\n";
        return 1;
    }
    if (pid == 0) {
        std::vector<std::string> cmdStrings;
        cmdStrings.push_back("gdb");
        cmdStrings.push_back("-q");
        cmdStrings.push_back("--args");
        cmdStrings.push_back(executablePath);
        for (const auto& arg : args) {
            cmdStrings.push_back(arg);
        }
        std::vector<char*> argv;
        for (auto& s : cmdStrings) {
            argv.push_back(s.data());
        }
        argv.push_back(nullptr);
        execvp("gdb", argv.data());
        std::cerr << "Erreur: gdb introuvable. Installez gdb.\n";
        _exit(127);
    }

    int status = 0;
    waitpid(pid, &status, 0);
    return WIFEXITED(status) ? WEXITSTATUS(status) : 1;
}

} // namespace afrilang
