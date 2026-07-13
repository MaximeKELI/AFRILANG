#pragma once

#include <string>
#include <vector>

namespace afrilang {

struct CompileCacheEntry {
    std::string sourceHash;
    std::string executablePath;
    bool valid = false;
};

struct CacheFingerprintInput {
    std::string sourceContent;
    std::vector<std::string> importContents;
    std::string compilerVersion;
    std::string crossTarget;
    bool debugSymbols = true;
    bool coverageMode = false;
    std::string runtimeDir;
    std::string stdlibStamp;
};

class CompileCache {
public:
    explicit CompileCache(const std::string& projectDir);

    CompileCacheEntry lookup(const std::string& sourcePath) const;
    void store(const std::string& sourcePath, const std::string& fingerprint,
               const std::string& executablePath) const;
    static std::string hashContent(const std::string& content);
    static std::string buildFingerprint(const CacheFingerprintInput& input);
    static std::string runtimeFingerprint(const std::string& runtimeDir);
    static std::string cacheDir(const std::string& projectDir);
    static std::string metaKeyForPath(const std::string& sourcePath);

private:
    std::string projectDir_;
};

} // namespace afrilang
