#pragma once

#include <initializer_list>
#include <cctype>
#include <sstream>
#include <string>
#include <vector>

namespace afrilang::runtime::str {

inline std::string toString(const char* value) { return value ? std::string(value) : std::string(); }
inline std::string toString(const std::string& value) { return value; }

inline std::string toString(double value) {
    if (value == static_cast<int>(value)) {
        return std::to_string(static_cast<int>(value));
    }
    return std::to_string(value);
}

inline std::string toString(long long value) { return std::to_string(value); }
inline std::string toString(int value) { return std::to_string(value); }

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

inline bool startsWith(const std::string& text, const std::string& prefix) {
    return text.size() >= prefix.size() && text.compare(0, prefix.size(), prefix) == 0;
}

inline bool endsWith(const std::string& text, const std::string& suffix) {
    return text.size() >= suffix.size() &&
           text.compare(text.size() - suffix.size(), suffix.size(), suffix) == 0;
}

inline std::string toUpper(const std::string& text) {
    std::string out = text;
    for (char& c : out) {
        c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
    }
    return out;
}

inline std::string toLower(const std::string& text) {
    std::string out = text;
    for (char& c : out) {
        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
    }
    return out;
}

inline double byteLen(const std::string& text) {
    return static_cast<double>(text.size());
}

} // namespace afrilang::runtime::str
