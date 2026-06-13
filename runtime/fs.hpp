#pragma once

#include <cstdint>
#include <filesystem>
#include <string>
#include <vector>

namespace afrilang {
namespace runtime {
namespace fs {

inline std::vector<std::string> listDir(const std::string& path) {
    std::vector<std::string> entries;
    std::error_code ec;
    if (!std::filesystem::exists(path, ec) || !std::filesystem::is_directory(path, ec)) {
        return entries;
    }
    for (const auto& entry : std::filesystem::directory_iterator(path, ec)) {
        if (ec) break;
        entries.push_back(entry.path().filename().string());
    }
    return entries;
}

inline bool makeDir(const std::string& path) {
    std::error_code ec;
    return std::filesystem::create_directories(path, ec);
}

inline bool removeFile(const std::string& path) {
    std::error_code ec;
    return std::filesystem::remove(path, ec);
}

inline double fileSize(const std::string& path) {
    std::error_code ec;
    const auto size = std::filesystem::file_size(path, ec);
    if (ec) return -1;
    return static_cast<double>(size);
}

} // namespace fs
} // namespace runtime
} // namespace afrilang
