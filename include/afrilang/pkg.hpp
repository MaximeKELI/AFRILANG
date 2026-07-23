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
    // Nimble-style remote metadata
    std::string url;
    std::string method; // "git" | "path" | "local"
    std::string subdir; // monorepo subdirectory inside cloned git repo
    std::string license;
    std::string web;
    std::vector<std::string> tags;
};

struct LockedPackage {
    std::string name;
    std::string version;
    std::string path;      // relative vendor path
    std::string sha256;
    std::string source;    // registry | git | path | remote
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
    /** Lookup package metadata from local packages/ + index + remote-index (Nimble-style). */
    static PackageInfo lookupPackage(const std::string& afrilangRoot, const std::string& name);

    static int cmdAdd(const std::string& projectDir, const std::string& packageName,
                      const std::string& afrilangRoot);
    static int cmdAddGit(const std::string& projectDir, const std::string& packageName,
                         const std::string& gitUrl, const std::string& tag,
                         const std::string& branch, const std::string& afrilangRoot);
    static int cmdAddPath(const std::string& projectDir, const std::string& packageName,
                          const std::string& pathDep, const std::string& afrilangRoot);
    static int cmdInstall(const std::string& projectDir, const std::string& afrilangRoot);
    static int cmdUpdate(const std::string& projectDir, const std::string& afrilangRoot);
    static int cmdInit(const std::string& dirOrName, const std::string& tmpl = "lib");
    static int cmdList(const std::string& afrilangRoot, bool blessedOnly = false);
    static int cmdSearch(const std::string& afrilangRoot, const std::string& query,
                         bool blessedOnly = false);
    /** Local publish into packages/. If remote=true, also POST / print Nimble-style recipe. */
    static int cmdPublish(const std::string& packageDir, const std::string& afrilangRoot,
                          bool remote = false);
    /** Run tests/ for a package (vendors self first). */
    static int cmdTest(const std::string& packageDir, const std::string& afrilangRoot);
    static int rebuildIndex(const std::string& afrilangRoot);
    /** Sign a package's directory hash with an Ed25519 key, recording sig in the index. */
    static int cmdSign(const std::string& packageName, const std::string& privKeyHex,
                       const std::string& afrilangRoot);
    /** Verify a package's checksum and (if a trusted key + sig exist) its signature. */
    static int cmdVerify(const std::string& packageName, const std::string& afrilangRoot);
    static int syncRemoteRegistry(const std::string& afrilangRoot);
    static std::string registryUrl();
    static std::string registryPublishUrl();

    static std::vector<LockedPackage> readLockFile(const std::string& lockPath);
    static void writeLockFile(const std::string& lockPath,
                              const std::vector<LockedPackage>& packages);
};

} // namespace afrilang
