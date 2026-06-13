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

} // namespace afrilang::runtime::path
