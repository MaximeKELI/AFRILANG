#pragma once

#include <fstream>
#include <sstream>
#include <string>

namespace afrilang {
namespace runtime {
namespace io {

inline std::string readFile(const std::string& path) {
    std::ifstream file(path);
    if (!file) return "";
    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

inline bool writeFile(const std::string& path, const std::string& content) {
    std::ofstream file(path);
    if (!file) return false;
    file << content;
    return true;
}

inline bool fileExists(const std::string& path) {
    std::ifstream file(path);
    return file.good();
}

inline std::string readLine() {
    std::string line;
    std::getline(std::cin, line);
    return line;
}

} // namespace io
} // namespace runtime
} // namespace afrilang
