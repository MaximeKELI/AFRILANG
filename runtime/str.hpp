#pragma once

#include <initializer_list>
#include <sstream>
#include <string>
#include <vector>

namespace afrilang::runtime::str {

inline std::string toString(const std::string& value) { return value; }

inline std::string toString(double value) {
    if (value == static_cast<int>(value)) {
        return std::to_string(static_cast<int>(value));
    }
    return std::to_string(value);
}

inline std::string toString(bool value) { return value ? "true" : "false"; }

inline std::string concat(std::initializer_list<std::string> parts) {
    std::string out;
    for (const auto& part : parts) {
        out += part;
    }
    return out;
}

inline std::string trim(const std::string& text) {
    const auto start = text.find_first_not_of(" \t\n\r");
    if (start == std::string::npos) return "";
    const auto end = text.find_last_not_of(" \t\n\r");
    return text.substr(start, end - start + 1);
}

inline bool contains(const std::string& text, const std::string& needle) {
    return text.find(needle) != std::string::npos;
}

inline std::string replace(const std::string& text, const std::string& from,
                           const std::string& to) {
    if (from.empty()) return text;
    std::string out = text;
    std::size_t pos = 0;
    while ((pos = out.find(from, pos)) != std::string::npos) {
        out.replace(pos, from.size(), to);
        pos += to.size();
    }
    return out;
}

inline std::vector<std::string> split(const std::string& text, const std::string& sep) {
    std::vector<std::string> parts;
    if (sep.empty()) {
        parts.push_back(text);
        return parts;
    }
    std::size_t start = 0;
    while (true) {
        const std::size_t pos = text.find(sep, start);
        if (pos == std::string::npos) {
            parts.push_back(text.substr(start));
            break;
        }
        parts.push_back(text.substr(start, pos - start));
        start = pos + sep.size();
    }
    return parts;
}

inline std::string join(const std::vector<std::string>& parts, const std::string& sep) {
    std::ostringstream out;
    for (std::size_t i = 0; i < parts.size(); ++i) {
        if (i > 0) out << sep;
        out << parts[i];
    }
    return out.str();
}

} // namespace afrilang::runtime::str
