#pragma once

#include <string>

namespace afrilang {

struct CompileCacheEntry {
    std::string sourceHash;
    std::string executablePath;
    bool valid = false;
};

class CompileCache {
public:
    explicit CompileCache(const std::string& projectDir);

    CompileCacheEntry lookup(const std::string& sourcePath) const;
    void store(const std::string& sourcePath, const std::string& sourceHash,
               const std::string& executablePath) const;
    static std::string hashContent(const std::string& content);
    static std::string cacheDir(const std::string& projectDir);

private:
    std::string projectDir_;
};

} // namespace afrilang
