#pragma once

#include <string>
#include <unordered_map>
#include <vector>

namespace afrilang {

struct PackageInfo {
    std::string name;
    std::string version;
    std::string description;
    std::string mainFile = "math.afr";
};

class PkgRegistry {
public:
    static bool isPkgImport(const std::string& path);
    static std::string resolvePkgImport(const std::string& importPath,
                                        const std::string& projectDir,
                                        const std::string& afrilangRoot);

    static std::vector<PackageInfo> listAvailable(const std::string& afrilangRoot);
    static PackageInfo loadManifest(const std::string& packageDir);
    static int cmdAdd(const std::string& projectDir, const std::string& packageName,
                      const std::string& afrilangRoot);
    static int cmdInstall(const std::string& projectDir, const std::string& afrilangRoot);
    static int cmdList(const std::string& afrilangRoot);
    static int cmdSearch(const std::string& afrilangRoot, const std::string& query);
    static int cmdPublish(const std::string& packageDir, const std::string& afrilangRoot);
    static int rebuildIndex(const std::string& afrilangRoot);
};

} // namespace afrilang
