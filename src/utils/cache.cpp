#include "afrilang/cache.hpp"

#include <algorithm>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>

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

std::string CompileCache::metaKeyForPath(const std::string& sourcePath) {
    const std::string abs = fs::absolute(sourcePath).string();
    return hashContent(abs) + ".meta";
}

std::string CompileCache::runtimeFingerprint(const std::string& runtimeDir) {
    if (runtimeDir.empty() || !fs::exists(runtimeDir)) {
        return "no-runtime";
    }
    std::ostringstream acc;
    std::error_code ec;
    std::vector<std::string> parts;
    for (const auto& entry : fs::recursive_directory_iterator(
             runtimeDir, fs::directory_options::skip_permission_denied, ec)) {
        if (!entry.is_regular_file(ec)) continue;
        const auto ext = entry.path().extension().string();
        if (ext != ".hpp" && ext != ".h" && ext != ".inl") continue;
        const fs::path rel = fs::relative(entry.path(), runtimeDir, ec);
        std::ostringstream one;
        one << (ec ? entry.path().filename().string() : rel.generic_string()) << ':';
        one << entry.file_size(ec) << ':';
        one << entry.last_write_time(ec).time_since_epoch().count();
        parts.push_back(one.str());
    }
    std::sort(parts.begin(), parts.end());
    for (const auto& p : parts) {
        acc << p << ';';
    }
    return hashContent(acc.str());
}

std::string CompileCache::buildFingerprint(const CacheFingerprintInput& input) {
    std::ostringstream acc;
    acc << "v=" << input.compilerVersion << '\n';
    acc << "target=" << input.crossTarget << '\n';
    acc << "debug=" << (input.debugSymbols ? '1' : '0') << '\n';
    acc << "cov=" << (input.coverageMode ? '1' : '0') << '\n';
    acc << "runtime=" << runtimeFingerprint(input.runtimeDir) << '\n';
    acc << "stdlib=" << input.stdlibStamp << '\n';
    acc << "opt=" << input.optStamp << '\n';
    acc << "source=" << hashContent(input.sourceContent) << '\n';
    for (const auto& imp : input.importContents) {
        acc << "import=" << hashContent(imp) << '\n';
    }
    return hashContent(acc.str());
}

CompileCacheEntry CompileCache::lookup(const std::string& sourcePath) const {
    CompileCacheEntry entry;
    const fs::path meta = fs::path(cacheDir(projectDir_)) / metaKeyForPath(sourcePath);
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

void CompileCache::store(const std::string& sourcePath, const std::string& fingerprint,
                         const std::string& executablePath) const {
    const fs::path dir = cacheDir(projectDir_);
    fs::create_directories(dir);
    const fs::path meta = dir / metaKeyForPath(sourcePath);
    std::ofstream out(meta);
    out << fingerprint << "\n" << executablePath << "\n";
}

} // namespace afrilang
