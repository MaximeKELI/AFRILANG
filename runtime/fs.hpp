#pragma once

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <sstream>
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

inline bool exists(const std::string& path) {
    std::error_code ec;
    return std::filesystem::exists(path, ec);
}

inline bool isFile(const std::string& path) {
    std::error_code ec;
    return std::filesystem::is_regular_file(path, ec);
}

inline bool isDir(const std::string& path) {
    std::error_code ec;
    return std::filesystem::is_directory(path, ec);
}

inline std::string readText(const std::string& path) {
    std::ifstream file(path);
    if (!file) return "";
    std::ostringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

inline bool writeText(const std::string& path, const std::string& content) {
    std::ofstream file(path);
    if (!file) return false;
    file << content;
    return true;
}

inline bool copyFile(const std::string& from, const std::string& to) {
    std::error_code ec;
    std::filesystem::copy_file(from, to, std::filesystem::copy_options::overwrite_existing, ec);
    return !ec;
}

inline bool renameFile(const std::string& from, const std::string& to) {
    std::error_code ec;
    std::filesystem::rename(from, to, ec);
    return !ec;
}

} // namespace fs
} // namespace runtime
} // namespace afrilang
