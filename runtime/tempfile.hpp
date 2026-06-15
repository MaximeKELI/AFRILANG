#pragma once

#include <filesystem>
#include <fstream>
#include <random>
#include <sstream>
#include <string>

namespace fs = std::filesystem;

namespace afrilang::runtime::tempfile {

inline std::string createPath(const std::string& prefix) {
    const auto dir = fs::temp_directory_path();
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(100000, 999999);
    std::ostringstream name;
    name << prefix << "_" << dist(gen) << ".tmp";
    return (dir / name.str()).string();
}

inline bool write(const std::string& path, const std::string& content) {
    std::ofstream out(path, std::ios::binary);
    if (!out) return false;
    out << content;
    return static_cast<bool>(out);
}

inline bool remove(const std::string& path) {
    std::error_code ec;
    return fs::remove(path, ec);
}

} // namespace afrilang::runtime::tempfile
