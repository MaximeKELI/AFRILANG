#pragma once

#include "afrilang/project.hpp"

#include <string>
#include <unordered_map>
#include <vector>

namespace afrilang {

struct PackageInfo {
    std::string name;
    std::string version;
    std::string description;
    std::string mainFile = "math.afr";
    std::string sha256;
    bool blessed = false;
};

struct LockedPackage {
    std::string name;
    std::string version;
    std::string path;      // relative vendor path
    std::string sha256;
    std::string source;    // registry | git | path
    std::string git;
    std::string tag;
    std::string branch;
    std::string pathSrc;   // original path dep
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
    static int cmdAddGit(const std::string& projectDir, const std::string& packageName,
                         const std::string& gitUrl, const std::string& tag,
                         const std::string& branch, const std::string& afrilangRoot);
    static int cmdAddPath(const std::string& projectDir, const std::string& packageName,
                          const std::string& pathDep, const std::string& afrilangRoot);
    static int cmdInstall(const std::string& projectDir, const std::string& afrilangRoot);
    static int cmdUpdate(const std::string& projectDir, const std::string& afrilangRoot);
    /** Create a library package scaffold at dirOrName (cwd/name if relative). */
    static int cmdInit(const std::string& dirOrName);
    static int cmdList(const std::string& afrilangRoot, bool blessedOnly = false);
    static int cmdSearch(const std::string& afrilangRoot, const std::string& query);
    static int cmdPublish(const std::string& packageDir, const std::string& afrilangRoot);
    static int rebuildIndex(const std::string& afrilangRoot);
    static int syncRemoteRegistry(const std::string& afrilangRoot);
    static std::string registryUrl();

    static std::vector<LockedPackage> readLockFile(const std::string& lockPath);
    static void writeLockFile(const std::string& lockPath,
                              const std::vector<LockedPackage>& packages);
};

} // namespace afrilang
