#pragma once

#include <filesystem>
#include <string>

namespace afrilang::runtime::path {

// Strip trailing separators so basename("/tmp/") → "tmp" (pathlib-like).
inline std::filesystem::path trimmed(const std::string& path) {
    auto p = std::filesystem::path(path);
    while (!p.empty() && p.filename().empty() && p.has_parent_path()) {
        p = p.parent_path();
    }
    return p;
}

inline std::string join(const std::string& left, const std::string& right) {
    return (std::filesystem::path(left) / right).string();
}

inline std::string basename(const std::string& path) {
    return trimmed(path).filename().string();
}

inline std::string dirname(const std::string& path) {
    const auto parent = trimmed(path).parent_path();
    return parent.empty() ? "." : parent.string();
}

inline std::string extension(const std::string& path) {
    return trimmed(path).extension().string();
}

inline bool isAbsolute(const std::string& path) {
    return std::filesystem::path(path).is_absolute();
}

inline std::string normalize(const std::string& path) {
    std::error_code ec;
    const auto cleaned = std::filesystem::weakly_canonical(std::filesystem::path(path), ec);
    if (!ec) return cleaned.string();
    return std::filesystem::path(path).lexically_normal().string();
}

inline std::string absolute(const std::string& path) {
    std::error_code ec;
    const auto abs = std::filesystem::absolute(std::filesystem::path(path), ec);
    if (ec) return path;
    return abs.lexically_normal().string();
}

} // namespace afrilang::runtime::path
