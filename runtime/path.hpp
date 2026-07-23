#pragma once

#include <filesystem>
#include <string>

namespace afrilang::runtime::path {

inline std::string join(const std::string& left, const std::string& right) {
    return (std::filesystem::path(left) / right).string();
}

inline std::string basename(const std::string& path) {
    return std::filesystem::path(path).filename().string();
}

inline std::string dirname(const std::string& path) {
    const auto parent = std::filesystem::path(path).parent_path();
    return parent.empty() ? "." : parent.string();
}

inline std::string extension(const std::string& path) {
    return std::filesystem::path(path).extension().string();
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
