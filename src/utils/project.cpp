#include "afrilang/project.hpp"

#include <fstream>
#include <sstream>
#include <string>

namespace afrilang {

static std::string trim(const std::string& s) {
    std::size_t start = 0;
    while (start < s.size() && std::isspace(static_cast<unsigned char>(s[start]))) ++start;
    std::size_t end = s.size();
    while (end > start && std::isspace(static_cast<unsigned char>(s[end - 1]))) --end;
    return s.substr(start, end - start);
}

static std::string unquote(const std::string& s) {
    if (s.size() >= 2 && s.front() == '"' && s.back() == '"') {
        return s.substr(1, s.size() - 2);
    }
    return s;
}

ProjectConfig loadProjectConfig(const std::string& path) {
    ProjectConfig config;
    std::ifstream file(path);
    if (!file) return config;

    std::string line;
    bool inDependencies = false;
    while (std::getline(file, line)) {
        line = trim(line);
        if (line.empty() || line[0] == '#') continue;

        if (line == "[dependencies]") {
            inDependencies = true;
            continue;
        }
        if (!line.empty() && line[0] == '[') {
            inDependencies = false;
        }

        const auto eq = line.find('=');
        if (eq == std::string::npos) continue;

        const std::string key = trim(line.substr(0, eq));
        const std::string value = unquote(trim(line.substr(eq + 1)));

        if (inDependencies) {
            config.dependencies[key] = value;
        } else if (key == "name") config.name = value;
        else if (key == "version") config.version = value;
        else if (key == "main") config.mainFile = value;
        else if (key == "output") config.output = value;
        else if (key == "stdlib") config.stdlibPath = value;
    }
    return config;
}

} // namespace afrilang
