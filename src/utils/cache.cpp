#include "afrilang/cache.hpp"

#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <sstream>

namespace fs = std::filesystem;

namespace afrilang {

namespace {

std::uint64_t fnv1a64(const std::string& data) {
    std::uint64_t hash = 1469598103934665603ULL;
    for (unsigned char c : data) {
        hash ^= c;
        hash *= 1099511628211ULL;
    }
    return hash;
}

std::string hashToHex(std::uint64_t hash) {
    std::ostringstream out;
    out << std::hex << std::setw(16) << std::setfill('0') << hash;
    return out.str();
}

} // namespace

CompileCache::CompileCache(const std::string& projectDir) : projectDir_(projectDir) {}

std::string CompileCache::cacheDir(const std::string& projectDir) {
    return (fs::path(projectDir) / ".afrilang" / "cache").string();
}

std::string CompileCache::hashContent(const std::string& content) {
    return hashToHex(fnv1a64(content));
}

CompileCacheEntry CompileCache::lookup(const std::string& sourcePath) const {
    CompileCacheEntry entry;
    const fs::path meta = fs::path(cacheDir(projectDir_)) /
                          (fs::path(sourcePath).filename().string() + ".meta");
    if (!fs::exists(meta)) return entry;

    std::ifstream in(meta);
    std::string hash;
    std::getline(in, hash);
    std::getline(in, entry.executablePath);
    entry.sourceHash = hash;
    entry.valid = !hash.empty() && !entry.executablePath.empty() &&
                  fs::exists(entry.executablePath);
    return entry;
}

void CompileCache::store(const std::string& sourcePath, const std::string& sourceHash,
                         const std::string& executablePath) const {
    const fs::path dir = cacheDir(projectDir_);
    fs::create_directories(dir);
    const fs::path meta = dir / (fs::path(sourcePath).filename().string() + ".meta");
    std::ofstream out(meta);
    out << sourceHash << "\n" << executablePath << "\n";
}

} // namespace afrilang
