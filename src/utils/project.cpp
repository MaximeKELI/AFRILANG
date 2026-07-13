#include "afrilang/project.hpp"

#include <cctype>
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

DependencySpec parseDependencyValue(const std::string& value) {
    DependencySpec spec;
    const std::string v = trim(value);
    if (v.empty()) return spec;

    if (v.front() != '{') {
        spec.kind = DependencyKind::Version;
        spec.version = unquote(v);
        return spec;
    }

    // Inline table: { git = "...", tag = "..." } or { path = "..." }
    std::string inner = v.substr(1);
    if (!inner.empty() && inner.back() == '}') {
        inner.pop_back();
    }
    inner = trim(inner);

    std::size_t pos = 0;
    while (pos < inner.size()) {
        while (pos < inner.size() && (std::isspace(static_cast<unsigned char>(inner[pos])) ||
                                      inner[pos] == ',')) {
            ++pos;
        }
        if (pos >= inner.size()) break;

        const std::size_t eq = inner.find('=', pos);
        if (eq == std::string::npos) break;
        const std::string key = trim(inner.substr(pos, eq - pos));

        std::size_t valueStart = eq + 1;
        while (valueStart < inner.size() &&
               std::isspace(static_cast<unsigned char>(inner[valueStart]))) {
            ++valueStart;
        }

        std::string rawVal;
        if (valueStart < inner.size() && inner[valueStart] == '"') {
            const std::size_t endQ = inner.find('"', valueStart + 1);
            if (endQ == std::string::npos) break;
            rawVal = inner.substr(valueStart + 1, endQ - valueStart - 1);
            pos = endQ + 1;
        } else {
            std::size_t end = valueStart;
            while (end < inner.size() && inner[end] != ',') ++end;
            rawVal = trim(inner.substr(valueStart, end - valueStart));
            pos = end;
        }

        if (key == "git") {
            spec.kind = DependencyKind::Git;
            spec.git = rawVal;
        } else if (key == "path") {
            spec.kind = DependencyKind::Path;
            spec.path = rawVal;
        } else if (key == "tag") {
            spec.tag = rawVal;
        } else if (key == "branch") {
            spec.branch = rawVal;
        } else if (key == "version") {
            spec.version = rawVal;
            if (spec.kind != DependencyKind::Git && spec.kind != DependencyKind::Path) {
                spec.kind = DependencyKind::Version;
            }
        }
    }

    if (spec.kind == DependencyKind::Version && spec.version.empty() && !spec.git.empty()) {
        spec.kind = DependencyKind::Git;
    }
    if (spec.kind == DependencyKind::Version && spec.version.empty() && !spec.path.empty()) {
        spec.kind = DependencyKind::Path;
    }
    return spec;
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
        const std::string value = trim(line.substr(eq + 1));

        if (inDependencies) {
            config.dependencies[key] = parseDependencyValue(value);
        } else if (key == "name") config.name = unquote(value);
        else if (key == "version") config.version = unquote(value);
        else if (key == "main") config.mainFile = unquote(value);
        else if (key == "output") config.output = unquote(value);
        else if (key == "description") config.description = unquote(value);
        else if (key == "stdlib") config.stdlibPath = unquote(value);
    }
    return config;
}

} // namespace afrilang
