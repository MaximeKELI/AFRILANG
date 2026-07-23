#include "afrilang/pkg.hpp"

#include "afrilang/hash.hpp"
#include "afrilang/project.hpp"
#include "afrilang/sandbox.hpp"
#include "afrilang/security.hpp"
#include "afrilang/semver.hpp"

#include "../../runtime/crypto.hpp"
#include "../../runtime/http.hpp"

#include <algorithm>
#include <cctype>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

namespace fs = std::filesystem;

namespace afrilang {

bool PkgRegistry::isPkgImport(const std::string& path) {
    return path.rfind("pkg/", 0) == 0;
}

std::string PkgRegistry::resolvePkgImport(const std::string& importPath,
                                          const std::string& projectDir,
                                          const std::string& afrilangRoot) {
    const std::string relative = importPath.substr(4);

    if (const char* envVendor = std::getenv("AFRILANG_VENDOR")) {
        const fs::path envVendorPath = fs::path(envVendor) / relative;
        if (fs::exists(envVendorPath)) {
            return fs::weakly_canonical(envVendorPath).string();
        }
    }

    const fs::path vendorPath = fs::path(projectDir) / "vendor" / relative;
    if (fs::exists(vendorPath)) {
        return fs::weakly_canonical(vendorPath).string();
    }

    const fs::path envVendor = fs::path(projectDir) / ".afrilang" / "env" / "vendor" / relative;
    if (fs::exists(envVendor)) {
        return fs::weakly_canonical(envVendor).string();
    }

    const fs::path registryPath = fs::path(afrilangRoot) / "packages" / relative;
    if (fs::exists(registryPath)) {
        return fs::weakly_canonical(registryPath).string();
    }

    return (fs::path(projectDir) / importPath).string();
}

std::string PkgRegistry::registryUrl() {
    if (const char* url = std::getenv("AFRILANG_REGISTRY_URL")) {
        return url;
    }
    return "https://raw.githubusercontent.com/afrilang/registry/main/index.json";
}

std::string PkgRegistry::registryPublishUrl() {
    if (const char* url = std::getenv("AFRILANG_REGISTRY_PUBLISH_URL")) {
        return url;
    }
    // Same host as index by convention; POST /publish
    std::string index = registryUrl();
    const auto slash = index.rfind('/');
    if (slash == std::string::npos) return "https://registry.afrilang.dev/publish";
    return index.substr(0, slash) + "/publish";
}

int PkgRegistry::syncRemoteRegistry(const std::string& afrilangRoot) {
    const std::string url = registryUrl();
    std::cout << "Synchronisation du registre: " << url << "\n";
    const std::string body = afrilang::runtime::http::httpGet(url);
    if (body.empty()) {
        std::cerr << "Erreur: impossible de télécharger l'index distant.\n";
        std::cerr << "Définissez AFRILANG_REGISTRY_URL ou vérifiez la connexion.\n";
        return 1;
    }
    const fs::path indexPath = fs::path(afrilangRoot) / "packages" / "remote-index.json";
    fs::create_directories(indexPath.parent_path());
    std::ofstream out(indexPath);
    out << body;
    int blessedCount = 0;
    for (std::size_t i = 0; i < body.size(); ++i) {
        if (body.compare(i, 13, "\"blessed\":true") == 0) ++blessedCount;
    }
    std::cout << "Index distant enregistré: " << indexPath;
    if (blessedCount > 0) {
        std::cout << " (" << blessedCount << " paquets blessed)";
    }
    std::cout << "\n";
    return 0;
}

PackageInfo PkgRegistry::loadManifest(const std::string& packageDir) {
    PackageInfo info;
    const fs::path manifest = fs::path(packageDir) / "manifest.toml";
    if (!fs::exists(manifest)) return info;

    ProjectConfig cfg = loadProjectConfig(manifest.string());
    info.name = cfg.name;
    info.version = cfg.version;
    info.description = cfg.description;
    info.mainFile = cfg.mainFile.empty() ? "math.afr" : cfg.mainFile;
    return info;
}

static void enrichPackagesFromIndex(const std::string& afrilangRoot,
                                    std::vector<PackageInfo>& packages);

static void copyDirectory(const fs::path& src, const fs::path& dst) {
    const fs::path canonicalSrc = fs::weakly_canonical(src);
    fs::create_directories(dst);
    static const std::unordered_set<std::string> kSkip = {
        "vendor", ".git", "build", ".afrilang", ".cache",
    };
    for (const auto& entry : fs::recursive_directory_iterator(
             src, fs::directory_options::skip_permission_denied)) {
        const fs::path rel = fs::relative(entry.path(), src);
        bool skip = false;
        for (const auto& part : rel) {
            validatePathComponent(part.string());
            if (kSkip.count(part.string())) {
                skip = true;
                break;
            }
        }
        if (skip) continue;
        const fs::path target = dst / rel;

        if (entry.is_symlink()) {
            const fs::path linkTarget = fs::read_symlink(entry.path());
            const fs::path resolved = linkTarget.is_absolute()
                                          ? fs::weakly_canonical(linkTarget)
                                          : fs::weakly_canonical(entry.path().parent_path() /
                                                                 linkTarget);
            if (!isPathInsideRoot(canonicalSrc.string(), resolved.string())) {
                securityViolation("Lien symbolique hors du paquet: " + entry.path().string());
            }
            continue;
        }

        if (entry.is_directory()) {
            fs::create_directories(target);
        } else if (entry.is_regular_file()) {
            fs::create_directories(target.parent_path());
            fs::copy_file(entry.path(), target, fs::copy_options::overwrite_existing);
        }
    }
}

static fs::path vendorRootFor(const std::string& projectDir, std::string& relPrefixOut) {
    if (const char* envVendor = std::getenv("AFRILANG_VENDOR")) {
        relPrefixOut = ".afrilang/env/vendor/";
        return fs::path(envVendor);
    }
    const fs::path envDst = fs::path(projectDir) / ".afrilang" / "env" / "vendor";
    if (fs::exists(fs::path(projectDir) / ".afrilang" / "env")) {
        relPrefixOut = ".afrilang/env/vendor/";
        return envDst;
    }
    relPrefixOut = "vendor/";
    return fs::path(projectDir) / "vendor";
}

static std::string jsonEscape(const std::string& s) {
    std::string out;
    for (char c : s) {
        switch (c) {
            case '"': out += "\\\""; break;
            case '\\': out += "\\\\"; break;
            default: out += c; break;
        }
    }
    return out;
}

static bool containsIgnoreCase(const std::string& haystack, const std::string& needle) {
    if (needle.empty()) return true;
    auto lower = [](unsigned char c) { return static_cast<char>(std::tolower(c)); };
    std::string h;
    h.resize(haystack.size());
    std::transform(haystack.begin(), haystack.end(), h.begin(), lower);
    std::string n;
    n.resize(needle.size());
    std::transform(needle.begin(), needle.end(), n.begin(), lower);
    return h.find(n) != std::string::npos;
}

static std::unordered_set<std::string> loadBlessedNames(const std::string& afrilangRoot) {
    std::unordered_set<std::string> names;
    const fs::path path = fs::path(afrilangRoot) / "packages" / "blessed.json";
    if (!fs::exists(path)) return names;
    std::ifstream in(path);
    std::ostringstream buf;
    buf << in.rdbuf();
    const std::string body = buf.str();
    for (std::size_t i = 0; i < body.size(); ++i) {
        if (body[i] != '"') continue;
        const std::size_t end = body.find('"', i + 1);
        if (end == std::string::npos) break;
        const std::string name = body.substr(i + 1, end - i - 1);
        if (!name.empty() && name != "packages") {
            names.insert(name);
        }
        i = end;
    }
    return names;
}

// Extrait toutes les chaînes hexadécimales entre guillemets d'un fichier JSON
// simple (utilisé pour trusted_keys.json : tableau de clés publiques hex).
static std::vector<std::string> loadTrustedKeys(const std::string& afrilangRoot) {
    std::vector<std::string> keys;
    const fs::path path = fs::path(afrilangRoot) / "packages" / "trusted_keys.json";
    if (!fs::exists(path)) return keys;
    std::ifstream in(path);
    std::ostringstream buf;
    buf << in.rdbuf();
    const std::string body = buf.str();
    for (std::size_t i = 0; i < body.size(); ++i) {
        if (body[i] != '"') continue;
        const std::size_t end = body.find('"', i + 1);
        if (end == std::string::npos) break;
        const std::string tok = body.substr(i + 1, end - i - 1);
        if (tok.size() == 64) keys.push_back(tok);
        i = end;
    }
    return keys;
}

// signatures.json : objet {"pkgName":"sigHex", ...}
static std::unordered_map<std::string, std::string> loadSignatures(
    const std::string& afrilangRoot) {
    std::unordered_map<std::string, std::string> sigs;
    const fs::path path = fs::path(afrilangRoot) / "packages" / "signatures.json";
    if (!fs::exists(path)) return sigs;
    std::ifstream in(path);
    std::ostringstream buf;
    buf << in.rdbuf();
    const std::string body = buf.str();
    std::size_t i = 0;
    while (i < body.size()) {
        if (body[i] != '"') { ++i; continue; }
        const std::size_t keyEnd = body.find('"', i + 1);
        if (keyEnd == std::string::npos) break;
        const std::string key = body.substr(i + 1, keyEnd - i - 1);
        std::size_t j = body.find(':', keyEnd);
        if (j == std::string::npos) break;
        const std::size_t valStart = body.find('"', j);
        if (valStart == std::string::npos) break;
        const std::size_t valEnd = body.find('"', valStart + 1);
        if (valEnd == std::string::npos) break;
        sigs[key] = body.substr(valStart + 1, valEnd - valStart - 1);
        i = valEnd + 1;
    }
    return sigs;
}

static void writeSignatures(const std::string& afrilangRoot,
                            const std::unordered_map<std::string, std::string>& sigs) {
    const fs::path path = fs::path(afrilangRoot) / "packages" / "signatures.json";
    std::ostringstream out;
    out << "{\n";
    std::size_t i = 0;
    for (const auto& [name, sig] : sigs) {
        out << "  \"" << name << "\": \"" << sig << "\"";
        if (++i < sigs.size()) out << ",";
        out << "\n";
    }
    out << "}\n";
    std::ofstream file(path);
    if (file) file << out.str();
}

static std::string readIndexField(const std::string& body, const std::string& packageName,
                                  const std::string& field) {
    const std::string needle = "\"name\":\"" + packageName + "\"";
    const std::size_t pos = body.find(needle);
    if (pos == std::string::npos) return {};
    const std::string key = "\"" + field + "\":\"";
    const std::size_t shaPos = body.find(key, pos);
    if (shaPos == std::string::npos) {
        if (field == "blessed") {
            const std::size_t boolPos = body.find("\"blessed\":true", pos);
            if (boolPos != std::string::npos && boolPos < body.find('}', pos)) {
                return "true";
            }
        }
        return {};
    }
    const std::size_t start = shaPos + key.size();
    const std::size_t end = body.find('"', start);
    if (end == std::string::npos || end <= start) return {};
    return body.substr(start, end - start);
}

static std::string readIndexSha256(const fs::path& indexPath, const std::string& packageName) {
    if (!fs::exists(indexPath)) return {};
    std::ifstream in(indexPath);
    std::ostringstream buf;
    buf << in.rdbuf();
    return readIndexField(buf.str(), packageName, "sha256");
}

std::vector<PackageInfo> PkgRegistry::listAvailable(const std::string& afrilangRoot) {
    std::vector<PackageInfo> packages;
    const fs::path packagesDir = fs::path(afrilangRoot) / "packages";
    if (fs::exists(packagesDir)) {
        for (const auto& entry : fs::directory_iterator(packagesDir)) {
            if (!entry.is_directory()) continue;
            if (entry.path().filename() == ".cache") continue;
            PackageInfo info = loadManifest(entry.path().string());
            if (!info.name.empty()) {
                packages.push_back(std::move(info));
            }
        }
    }
    enrichPackagesFromIndex(afrilangRoot, packages);
    return packages;
}

static std::string extractJsonObjectForName(const std::string& body, const std::string& packageName) {
    // Find "name" : "packageName" with optional whitespace
    const std::string key = "\"name\"";
    for (std::size_t searchFrom = 0; searchFrom < body.size(); ) {
        const std::size_t pos = body.find(key, searchFrom);
        if (pos == std::string::npos) return {};
        std::size_t j = pos + key.size();
        while (j < body.size() && std::isspace(static_cast<unsigned char>(body[j]))) ++j;
        if (j >= body.size() || body[j] != ':') {
            searchFrom = pos + key.size();
            continue;
        }
        ++j;
        while (j < body.size() && std::isspace(static_cast<unsigned char>(body[j]))) ++j;
        if (j >= body.size() || body[j] != '"') {
            searchFrom = j;
            continue;
        }
        const std::size_t start = j + 1;
        const std::size_t end = body.find('"', start);
        if (end == std::string::npos) return {};
        if (body.substr(start, end - start) != packageName) {
            searchFrom = end + 1;
            continue;
        }
        std::size_t objStart = pos;
        while (objStart > 0 && body[objStart] != '{') --objStart;
        int depth = 0;
        for (std::size_t i = objStart; i < body.size(); ++i) {
            if (body[i] == '{') ++depth;
            else if (body[i] == '}') {
                --depth;
                if (depth == 0) return body.substr(objStart, i - objStart + 1);
            }
        }
        return {};
    }
    return {};
}

static std::string readFieldFromObject(const std::string& obj, const std::string& field) {
    const std::string key = "\"" + field + "\"";
    const std::size_t keyPos = obj.find(key);
    if (keyPos == std::string::npos) {
        if (field == "blessed" && obj.find("\"blessed\":true") != std::string::npos) return "true";
        return {};
    }
    std::size_t i = keyPos + key.size();
    while (i < obj.size() && std::isspace(static_cast<unsigned char>(obj[i]))) ++i;
    if (i >= obj.size() || obj[i] != ':') return {};
    ++i;
    while (i < obj.size() && std::isspace(static_cast<unsigned char>(obj[i]))) ++i;
    if (i < obj.size() && obj.compare(i, 4, "true") == 0) return "true";
    if (i >= obj.size() || obj[i] != '"') return {};
    const std::size_t start = i + 1;
    const std::size_t end = obj.find('"', start);
    if (end == std::string::npos || end <= start) return {};
    return obj.substr(start, end - start);
}

static std::vector<std::string> listPackageNamesInIndex(const std::string& body) {
    std::vector<std::string> names;
    const std::string key = "\"name\"";
    for (std::size_t i = 0; i < body.size(); ) {
        const std::size_t pos = body.find(key, i);
        if (pos == std::string::npos) break;
        std::size_t j = pos + key.size();
        while (j < body.size() && std::isspace(static_cast<unsigned char>(body[j]))) ++j;
        if (j >= body.size() || body[j] != ':') {
            i = pos + key.size();
            continue;
        }
        ++j;
        while (j < body.size() && std::isspace(static_cast<unsigned char>(body[j]))) ++j;
        if (j >= body.size() || body[j] != '"') {
            i = j;
            continue;
        }
        const std::size_t start = j + 1;
        const std::size_t end = body.find('"', start);
        if (end == std::string::npos) break;
        names.push_back(body.substr(start, end - start));
        i = end + 1;
    }
    return names;
}

static std::vector<std::string> readTagsFromObject(const std::string& obj) {
    std::vector<std::string> tags;
    const std::string key = "\"tags\"";
    const std::size_t pos = obj.find(key);
    if (pos == std::string::npos) return tags;
    std::size_t i = pos + key.size();
    while (i < obj.size() && std::isspace(static_cast<unsigned char>(obj[i]))) ++i;
    if (i >= obj.size() || obj[i] != ':') return tags;
    ++i;
    while (i < obj.size() && std::isspace(static_cast<unsigned char>(obj[i]))) ++i;
    if (i >= obj.size() || obj[i] != '[') return tags;
    ++i;
    while (i < obj.size() && obj[i] != ']') {
        if (obj[i] == '"') {
            const std::size_t end = obj.find('"', i + 1);
            if (end == std::string::npos) break;
            tags.push_back(obj.substr(i + 1, end - i - 1));
            i = end + 1;
            continue;
        }
        ++i;
    }
    return tags;
}

static void applyIndexObject(PackageInfo& pkg, const std::string& obj) {
    if (obj.empty()) return;
    const std::string ver = readFieldFromObject(obj, "version");
    if (!ver.empty()) pkg.version = ver;
    const std::string desc = readFieldFromObject(obj, "description");
    if (!desc.empty()) pkg.description = desc;
    const std::string hash = readFieldFromObject(obj, "sha256");
    if (!hash.empty()) pkg.sha256 = hash;
    const std::string url = readFieldFromObject(obj, "url");
    if (!url.empty()) pkg.url = url;
    const std::string method = readFieldFromObject(obj, "method");
    if (!method.empty()) pkg.method = method;
    const std::string license = readFieldFromObject(obj, "license");
    if (!license.empty()) pkg.license = license;
    const std::string web = readFieldFromObject(obj, "web");
    if (!web.empty()) pkg.web = web;
    if (readFieldFromObject(obj, "blessed") == "true" ||
        obj.find("\"blessed\":true") != std::string::npos) {
        pkg.blessed = true;
    }
    auto tags = readTagsFromObject(obj);
    if (!tags.empty()) pkg.tags = std::move(tags);
}

static std::string readIndexFile(const fs::path& indexPath) {
    if (!fs::exists(indexPath)) return {};
    std::ifstream in(indexPath);
    std::ostringstream buf;
    buf << in.rdbuf();
    return buf.str();
}

static void enrichPackagesFromIndex(const std::string& afrilangRoot,
                                    std::vector<PackageInfo>& packages) {
    const auto blessed = loadBlessedNames(afrilangRoot);
    const std::string localBody = readIndexFile(fs::path(afrilangRoot) / "packages" / "index.json");
    const std::string remoteBody =
        readIndexFile(fs::path(afrilangRoot) / "packages" / "remote-index.json");

    std::unordered_map<std::string, std::size_t> byName;
    for (std::size_t i = 0; i < packages.size(); ++i) byName[packages[i].name] = i;

    auto mergeBody = [&](const std::string& body, bool remoteOnlyNew) {
        if (body.empty()) return;
        for (const auto& name : listPackageNamesInIndex(body)) {
            const std::string obj = extractJsonObjectForName(body, name);
            auto it = byName.find(name);
            if (it != byName.end()) {
                applyIndexObject(packages[it->second], obj);
                if (blessed.count(name)) packages[it->second].blessed = true;
            } else if (remoteOnlyNew || !obj.empty()) {
                PackageInfo info;
                info.name = name;
                applyIndexObject(info, obj);
                if (info.method.empty() && !info.url.empty()) info.method = "git";
                if (blessed.count(name)) info.blessed = true;
                byName[name] = packages.size();
                packages.push_back(std::move(info));
            }
        }
    };

    mergeBody(localBody, false);
    mergeBody(remoteBody, true);

    for (auto& pkg : packages) {
        if (blessed.count(pkg.name)) pkg.blessed = true;
    }
}

PackageInfo PkgRegistry::lookupPackage(const std::string& afrilangRoot, const std::string& name) {
    PackageInfo info;
    const fs::path localDir = fs::path(afrilangRoot) / "packages" / name;
    if (fs::exists(localDir / "manifest.toml")) {
        info = loadManifest(localDir.string());
        if (info.name.empty()) info.name = name;
        info.method = info.method.empty() ? "local" : info.method;
    } else {
        info.name = name;
    }
    const std::string localBody = readIndexFile(fs::path(afrilangRoot) / "packages" / "index.json");
    const std::string remoteBody =
        readIndexFile(fs::path(afrilangRoot) / "packages" / "remote-index.json");
    applyIndexObject(info, extractJsonObjectForName(localBody, name));
    applyIndexObject(info, extractJsonObjectForName(remoteBody, name));
    if (info.method.empty() && !info.url.empty()) info.method = "git";
    if (loadBlessedNames(afrilangRoot).count(name)) info.blessed = true;
    return info;
}

int PkgRegistry::rebuildIndex(const std::string& afrilangRoot) {
    const fs::path packagesDir = fs::path(afrilangRoot) / "packages";
    const fs::path indexPath = packagesDir / "index.json";
    // Only local on-disk packages for authoritative local index
    std::vector<PackageInfo> packages;
    if (fs::exists(packagesDir)) {
        for (const auto& entry : fs::directory_iterator(packagesDir)) {
            if (!entry.is_directory()) continue;
            PackageInfo info = loadManifest(entry.path().string());
            if (info.name.empty()) continue;
            packages.push_back(std::move(info));
        }
    }
    const auto blessed = loadBlessedNames(afrilangRoot);
    const auto signatures = loadSignatures(afrilangRoot);

    std::ostringstream json;
    json << "{\n  \"packages\": [\n";
    for (std::size_t i = 0; i < packages.size(); ++i) {
        const auto& pkg = packages[i];
        const bool isBlessed = blessed.count(pkg.name) > 0;
        json << "    {\"name\":\"" << jsonEscape(pkg.name) << "\","
             << "\"version\":\"" << jsonEscape(pkg.version) << "\","
             << "\"description\":\"" << jsonEscape(pkg.description) << "\","
             << "\"method\":\"local\"";
        const std::string hash = sha256Directory((packagesDir / pkg.name).string());
        if (!hash.empty()) {
            json << ",\"sha256\":\"" << jsonEscape(hash) << "\"";
        }
        const auto sigIt = signatures.find(pkg.name);
        if (sigIt != signatures.end() && !sigIt->second.empty()) {
            json << ",\"sig\":\"" << jsonEscape(sigIt->second) << "\"";
        }
        if (isBlessed) {
            json << ",\"blessed\":true";
        }
        json << "}";
        if (i + 1 < packages.size()) json << ',';
        json << '\n';
    }
    json << "  ]\n}\n";

    const std::string payload = json.str();
    std::ofstream out(indexPath);
    if (!out) return 1;
    out << payload;

    const fs::path siteIndex = fs::path(afrilangRoot) / "site" / "packages.json";
    std::ofstream siteOut(siteIndex);
    if (siteOut) siteOut << payload;

    std::cout << "Index régénéré: " << indexPath << " (" << packages.size()
              << " paquets, " << blessed.size() << " blessed)\n";
    return 0;
}

static std::string expectedIndexSha256(const std::string& afrilangRoot,
                                        const std::string& packageName) {
    const fs::path packagesDir = fs::path(afrilangRoot) / "packages";
    std::string hash = readIndexSha256(packagesDir / "index.json", packageName);
    if (!hash.empty()) return hash;
    return readIndexSha256(packagesDir / "remote-index.json", packageName);
}

static std::string unquoteLock(const std::string& s) {
    if (s.size() >= 2 && s.front() == '"' && s.back() == '"') {
        return s.substr(1, s.size() - 2);
    }
    return s;
}

std::vector<LockedPackage> PkgRegistry::readLockFile(const std::string& lockPath) {
    std::vector<LockedPackage> packages;
    std::ifstream in(lockPath);
    if (!in) return packages;

    LockedPackage current;
    bool inPackage = false;
    std::string line;
    auto flush = [&]() {
        if (inPackage && !current.name.empty()) {
            packages.push_back(current);
        }
        current = LockedPackage{};
        inPackage = false;
    };

    while (std::getline(in, line)) {
        // trim
        while (!line.empty() && std::isspace(static_cast<unsigned char>(line.front()))) {
            line.erase(line.begin());
        }
        while (!line.empty() && std::isspace(static_cast<unsigned char>(line.back()))) {
            line.pop_back();
        }
        if (line.empty() || line[0] == '#') continue;
        if (line == "[[package]]") {
            flush();
            inPackage = true;
            continue;
        }
        if (!inPackage) continue;
        const auto eq = line.find('=');
        if (eq == std::string::npos) continue;
        const std::string key = line.substr(0, eq);
        std::string k = key;
        while (!k.empty() && std::isspace(static_cast<unsigned char>(k.back()))) k.pop_back();
        std::string value = unquoteLock(line.substr(eq + 1));
        while (!value.empty() && std::isspace(static_cast<unsigned char>(value.front()))) {
            value.erase(value.begin());
        }
        value = unquoteLock(value);
        if (k == "name") current.name = value;
        else if (k == "version") current.version = value;
        else if (k == "path") current.path = value;
        else if (k == "sha256") current.sha256 = value;
        else if (k == "source") current.source = value;
        else if (k == "git") current.git = value;
        else if (k == "tag") current.tag = value;
        else if (k == "branch") current.branch = value;
        else if (k == "path_src") current.pathSrc = value;
    }
    flush();
    return packages;
}

void PkgRegistry::writeLockFile(const std::string& lockPath,
                                const std::vector<LockedPackage>& packages) {
    std::ofstream lock(lockPath);
    lock << "# AFRILANG lockfile — source of truth for `pkg install`\n\n";
    for (const auto& pkg : packages) {
        lock << "[[package]]\n";
        lock << "name = \"" << pkg.name << "\"\n";
        lock << "version = \"" << pkg.version << "\"\n";
        lock << "path = \"" << pkg.path << "\"\n";
        if (!pkg.source.empty()) lock << "source = \"" << pkg.source << "\"\n";
        if (!pkg.git.empty()) lock << "git = \"" << pkg.git << "\"\n";
        if (!pkg.tag.empty()) lock << "tag = \"" << pkg.tag << "\"\n";
        if (!pkg.branch.empty()) lock << "branch = \"" << pkg.branch << "\"\n";
        if (!pkg.pathSrc.empty()) lock << "path_src = \"" << pkg.pathSrc << "\"\n";
        if (!pkg.sha256.empty()) lock << "sha256 = \"" << pkg.sha256 << "\"\n";
        lock << "\n";
    }
}

static void ensureDependencyInToml(const fs::path& tomlPath, const std::string& name,
                                   const DependencySpec& spec) {
    std::ifstream in(tomlPath);
    std::ostringstream content;
    content << in.rdbuf();
    std::string text = content.str();

    std::string depLine;
    if (spec.kind == DependencyKind::Git) {
        depLine = name + " = { git = \"" + spec.git + "\"";
        if (!spec.tag.empty()) depLine += ", tag = \"" + spec.tag + "\"";
        if (!spec.branch.empty()) depLine += ", branch = \"" + spec.branch + "\"";
        depLine += " }";
    } else if (spec.kind == DependencyKind::Path) {
        depLine = name + " = { path = \"" + spec.path + "\" }";
    } else {
        const std::string ver = spec.version.empty() ? "0.1.0" : spec.version;
        depLine = name + " = \"" + ver + "\"";
    }

    // Replace existing line for this dep if present
    std::istringstream lines(text);
    std::ostringstream rebuilt;
    std::string line;
    bool inDeps = false;
    bool replaced = false;
    bool hasDeps = text.find("[dependencies]") != std::string::npos;
    while (std::getline(lines, line)) {
        std::string trimmed = line;
        while (!trimmed.empty() && std::isspace(static_cast<unsigned char>(trimmed.front()))) {
            trimmed.erase(trimmed.begin());
        }
        if (trimmed == "[dependencies]") {
            inDeps = true;
            rebuilt << line << "\n";
            continue;
        }
        if (!trimmed.empty() && trimmed[0] == '[') {
            if (inDeps && !replaced) {
                rebuilt << depLine << "\n";
                replaced = true;
            }
            inDeps = false;
        }
        if (inDeps) {
            const auto eq = trimmed.find('=');
            if (eq != std::string::npos) {
                std::string key = trimmed.substr(0, eq);
                while (!key.empty() && std::isspace(static_cast<unsigned char>(key.back()))) {
                    key.pop_back();
                }
                if (key == name) {
                    rebuilt << depLine << "\n";
                    replaced = true;
                    continue;
                }
            }
        }
        rebuilt << line << "\n";
    }
    text = rebuilt.str();
    if (!hasDeps) {
        if (!text.empty() && text.back() != '\n') text += "\n";
        text += "\n[dependencies]\n" + depLine + "\n";
    } else if (!replaced) {
        if (!text.empty() && text.back() != '\n') text += "\n";
        // append after [dependencies]
        const auto pos = text.find("[dependencies]");
        const auto nl = text.find('\n', pos);
        if (nl != std::string::npos) {
            text.insert(nl + 1, depLine + "\n");
        } else {
            text += depLine + "\n";
        }
    }

    std::ofstream out(tomlPath);
    out << text;
}

static int runCommand(const std::string& cmd) {
    const int code = std::system(cmd.c_str());
    return code != 0 ? (code > 0 ? code : 1) : 0;
}

static int cloneGit(const std::string& url, const std::string& tag, const std::string& branch,
                    const fs::path& dst) {
    if (fs::exists(dst)) {
        fs::remove_all(dst);
    }
    fs::create_directories(dst.parent_path());
    std::ostringstream cmd;
    cmd << "git clone --quiet --depth 1";
    if (!tag.empty()) {
        cmd << " --branch \"" << tag << "\"";
    } else if (!branch.empty()) {
        cmd << " --branch \"" << branch << "\"";
    }
    cmd << " \"" << url << "\" \"" << dst.string() << "\"";
    const int rc = runCommand(cmd.str());
    if (rc != 0) {
        std::cerr << "Erreur: git clone a échoué pour " << url << "\n";
        return rc;
    }
    // Drop .git to keep vendor clean
    const fs::path gitDir = dst / ".git";
    if (fs::exists(gitDir)) {
        fs::remove_all(gitDir);
    }
    return 0;
}

static fs::path remoteCacheDir(const std::string& afrilangRoot) {
    return fs::path(afrilangRoot) / "packages" / ".cache";
}

static LockedPackage installRegistryPackage(const std::string& projectDir,
                                            const std::string& packageName,
                                            const std::string& requiredRange,
                                            const std::string& afrilangRoot,
                                            bool skipToml) {
    LockedPackage locked;
    fs::path src = fs::path(afrilangRoot) / "packages" / packageName;
    PackageInfo meta = PkgRegistry::lookupPackage(afrilangRoot, packageName);
    bool fetchedRemote = false;

    // Nimble-style: if not on disk locally, fetch via url/method from index
    if (!fs::exists(src) || !fs::exists(src / "manifest.toml")) {
        if (meta.url.empty() || (meta.method != "git" && !meta.method.empty() &&
                                 meta.method != "local")) {
            if (meta.url.empty()) {
                std::cerr << "Erreur: paquet '" << packageName
                          << "' introuvable (local + remote-index).\n";
                std::cerr << "Astuce: afrilang pkg sync  puis réessayez, ou "
                             "pkg add --git <url>\n";
            } else {
                std::cerr << "Erreur: méthode de téléchargement non supportée pour '"
                          << packageName << "': " << meta.method << "\n";
            }
            return locked;
        }
        if (meta.method.empty()) meta.method = "git";
        const fs::path cache = remoteCacheDir(afrilangRoot) / packageName;
        std::cout << "Téléchargement distant '" << packageName << "' depuis " << meta.url
                  << " ...\n";
        if (cloneGit(meta.url, std::string{}, std::string{}, cache) != 0) {
            // try without tag if meta has version as tag
            if (cloneGit(meta.url, "v" + (meta.version.empty() ? "0.1.0" : meta.version),
                         std::string{}, cache) != 0) {
                if (cloneGit(meta.url, std::string{}, std::string{}, cache) != 0) {
                    return locked;
                }
            }
        }
        src = cache;
        fetchedRemote = true;
    }

    PackageInfo info = PkgRegistry::loadManifest(src.string());
    if (info.name.empty()) info.name = packageName;
    if (info.version.empty()) info.version = meta.version.empty() ? "0.1.0" : meta.version;

    if (!requiredRange.empty() && !semverSatisfies(requiredRange, info.version)) {
        std::cerr << "Erreur: '" << packageName << "' requiert " << requiredRange
                  << " mais le registre fournit " << info.version << "\n";
        return locked;
    }

    std::string relPrefix;
    const fs::path vendorRoot = vendorRootFor(projectDir, relPrefix);
    const fs::path dst = vendorRoot / packageName;
    copyDirectory(src, dst);

    const std::string pkgHash = sha256Directory(dst.string());
    if (pkgHash.empty()) {
        std::cerr << "Erreur: impossible de calculer le checksum du paquet.\n";
        return locked;
    }

    const std::string expected = expectedIndexSha256(afrilangRoot, packageName);
    if (!expected.empty() && expected != pkgHash && !fetchedRemote) {
        std::cerr << "Erreur: checksum SHA256 invalide pour '" << packageName << "'.\n";
        std::cerr << "  attendu:  " << expected << "\n";
        std::cerr << "  obtenu:   " << pkgHash << "\n";
        fs::remove_all(dst);
        return locked;
    }

    if (!skipToml) {
        const fs::path tomlPath = fs::path(projectDir) / "afrilang.toml";
        if (fs::exists(tomlPath)) {
            DependencySpec spec;
            spec.kind = DependencyKind::Version;
            spec.version = requiredRange.empty() ? info.version : requiredRange;
            ensureDependencyInToml(tomlPath, info.name, spec);
        }
    }

    locked.name = info.name;
    locked.version = info.version;
    locked.path = relPrefix + packageName;
    locked.sha256 = pkgHash;
    locked.source = fetchedRemote ? "remote" : "registry";
    if (fetchedRemote && !meta.url.empty()) {
        locked.git = meta.url;
    }
    std::cout << "Paquet '" << info.name << "@" << info.version << "' installé dans "
              << dst.string() << (fetchedRemote ? " (distant)" : "") << "\n";
    std::cout << "sha256: " << pkgHash << "\n";
    return locked;
}

static LockedPackage installGitPackage(const std::string& projectDir,
                                       const std::string& packageName,
                                       const DependencySpec& spec) {
    LockedPackage locked;
    std::string relPrefix;
    const fs::path vendorRoot = vendorRootFor(projectDir, relPrefix);
    const fs::path dst = vendorRoot / packageName;
    if (cloneGit(spec.git, spec.tag, spec.branch, dst) != 0) {
        return locked;
    }

    PackageInfo info = PkgRegistry::loadManifest(dst.string());
    locked.name = packageName;
    locked.version = info.version.empty() ? "0.0.0" : info.version;
    locked.path = relPrefix + packageName;
    locked.source = "git";
    locked.git = spec.git;
    locked.tag = spec.tag;
    locked.branch = spec.branch;
    locked.sha256 = sha256Directory(dst.string());
    std::cout << "Paquet git '" << packageName << "' cloné dans " << dst.string() << "\n";
    return locked;
}

static LockedPackage installPathPackage(const std::string& projectDir,
                                        const std::string& packageName,
                                        const DependencySpec& spec) {
    LockedPackage locked;
    fs::path src = fs::path(spec.path);
    if (!src.is_absolute()) {
        src = fs::path(projectDir) / src;
    }
    if (!fs::exists(src)) {
        std::cerr << "Erreur: chemin introuvable pour '" << packageName << "': " << src << "\n";
        return locked;
    }

    std::string relPrefix;
    const fs::path vendorRoot = vendorRootFor(projectDir, relPrefix);
    const fs::path dst = vendorRoot / packageName;
    if (fs::exists(dst)) fs::remove_all(dst);
    copyDirectory(src, dst);

    PackageInfo info = PkgRegistry::loadManifest(dst.string());
    locked.name = packageName;
    locked.version = info.version.empty() ? "0.0.0" : info.version;
    locked.path = relPrefix + packageName;
    locked.source = "path";
    locked.pathSrc = spec.path;
    locked.sha256 = sha256Directory(dst.string());
    std::cout << "Paquet path '" << packageName << "' installé depuis " << src << "\n";
    return locked;
}

static void upsertLock(std::vector<LockedPackage>& lock, const LockedPackage& pkg) {
    if (pkg.name.empty()) return;
    for (auto& existing : lock) {
        if (existing.name == pkg.name) {
            existing = pkg;
            return;
        }
    }
    lock.push_back(pkg);
}

static int installOneDep(const std::string& projectDir, const std::string& name,
                         const DependencySpec& spec, const std::string& afrilangRoot,
                         std::vector<LockedPackage>& lock, bool skipToml,
                         bool resolveTransitive, int depth = 0) {
    if (depth > 32) {
        std::cerr << "Erreur: profondeur de dépendances excessive (cycle?) pour '" << name
                  << "'\n";
        return 1;
    }

    // Conflict / already satisfied check
    for (const auto& p : lock) {
        if (p.name != name) continue;
        if (spec.kind == DependencyKind::Version && !spec.version.empty()) {
            if (!semverSatisfies(spec.version, p.version)) {
                std::cerr << "Erreur: conflit de versions pour '" << name << "': "
                          << "lock=" << p.version << " mais requis " << spec.version << "\n";
                return 1;
            }
        }
        // Already installed and satisfies — skip reinstall, still walk transitive if asked
        if (resolveTransitive) {
            const fs::path vendorPath = fs::path(projectDir) / p.path;
            const fs::path manifest = vendorPath / "manifest.toml";
            if (fs::exists(manifest)) {
                ProjectConfig nested = loadProjectConfig(manifest.string());
                for (const auto& [depName, depSpec] : nested.dependencies) {
                    if (installOneDep(projectDir, depName, depSpec, afrilangRoot, lock, true,
                                      true, depth + 1) != 0) {
                        return 1;
                    }
                }
            }
        }
        return 0;
    }

    LockedPackage installed;
    if (spec.kind == DependencyKind::Git) {
        installed = installGitPackage(projectDir, name, spec);
    } else if (spec.kind == DependencyKind::Path) {
        installed = installPathPackage(projectDir, name, spec);
    } else {
        installed = installRegistryPackage(projectDir, name, spec.version, afrilangRoot, skipToml);
    }
    if (installed.name.empty()) return 1;
    upsertLock(lock, installed);

    if (resolveTransitive) {
        const fs::path vendorPath = fs::path(projectDir) / installed.path;
        const fs::path manifest = vendorPath / "manifest.toml";
        if (fs::exists(manifest)) {
            ProjectConfig nested = loadProjectConfig(manifest.string());
            for (const auto& [depName, depSpec] : nested.dependencies) {
                if (installOneDep(projectDir, depName, depSpec, afrilangRoot, lock, true, true,
                                  depth + 1) != 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int PkgRegistry::cmdAdd(const std::string& projectDir, const std::string& packageName,
                        const std::string& afrilangRoot) {
    std::vector<LockedPackage> lock = readLockFile((fs::path(projectDir) / "afrilang.lock").string());
    DependencySpec spec;
    spec.kind = DependencyKind::Version;
    spec.version = ""; // accept whatever is in registry; pin after install
    if (installOneDep(projectDir, packageName, spec, afrilangRoot, lock, false, true) != 0) {
        return 1;
    }
    // Pin exact version in toml after install
    for (const auto& p : lock) {
        if (p.name == packageName && p.source == "registry") {
            const fs::path tomlPath = fs::path(projectDir) / "afrilang.toml";
            if (fs::exists(tomlPath)) {
                DependencySpec pinned;
                pinned.kind = DependencyKind::Version;
                pinned.version = p.version;
                ensureDependencyInToml(tomlPath, p.name, pinned);
            }
            break;
        }
    }
    writeLockFile((fs::path(projectDir) / "afrilang.lock").string(), lock);
    return 0;
}

int PkgRegistry::cmdAddGit(const std::string& projectDir, const std::string& packageName,
                           const std::string& gitUrl, const std::string& tag,
                           const std::string& branch, const std::string& /*afrilangRoot*/) {
    DependencySpec spec;
    spec.kind = DependencyKind::Git;
    spec.git = gitUrl;
    spec.tag = tag;
    spec.branch = branch;

    const fs::path tomlPath = fs::path(projectDir) / "afrilang.toml";
    if (fs::exists(tomlPath)) {
        ensureDependencyInToml(tomlPath, packageName, spec);
    }

    std::vector<LockedPackage> lock = readLockFile((fs::path(projectDir) / "afrilang.lock").string());
    if (installOneDep(projectDir, packageName, spec, "", lock, true, false) != 0) {
        return 1;
    }
    writeLockFile((fs::path(projectDir) / "afrilang.lock").string(), lock);
    return 0;
}

int PkgRegistry::cmdAddPath(const std::string& projectDir, const std::string& packageName,
                            const std::string& pathDep, const std::string& /*afrilangRoot*/) {
    DependencySpec spec;
    spec.kind = DependencyKind::Path;
    spec.path = pathDep;

    const fs::path tomlPath = fs::path(projectDir) / "afrilang.toml";
    if (fs::exists(tomlPath)) {
        ensureDependencyInToml(tomlPath, packageName, spec);
    }

    std::vector<LockedPackage> lock = readLockFile((fs::path(projectDir) / "afrilang.lock").string());
    if (installOneDep(projectDir, packageName, spec, "", lock, true, false) != 0) {
        return 1;
    }
    writeLockFile((fs::path(projectDir) / "afrilang.lock").string(), lock);
    return 0;
}

int PkgRegistry::cmdInstall(const std::string& projectDir, const std::string& afrilangRoot) {
    const fs::path tomlPath = fs::path(projectDir) / "afrilang.toml";
    const fs::path lockPath = fs::path(projectDir) / "afrilang.lock";
    if (!fs::exists(tomlPath)) {
        std::cerr << "Erreur: afrilang.toml introuvable.\n";
        return 1;
    }

    ProjectConfig config = loadProjectConfig(tomlPath.string());
    auto existingLock = readLockFile(lockPath.string());

    // Lock is source of truth when present and non-empty
    if (!existingLock.empty()) {
        std::cout << "Installation depuis afrilang.lock (" << existingLock.size()
                  << " paquets)...\n";
        std::vector<LockedPackage> newLock;
        int failures = 0;
        for (const auto& entry : existingLock) {
            DependencySpec spec;
            if (entry.source == "git" || !entry.git.empty()) {
                spec.kind = DependencyKind::Git;
                spec.git = entry.git;
                spec.tag = entry.tag;
                spec.branch = entry.branch;
            } else if (entry.source == "path" || !entry.pathSrc.empty()) {
                spec.kind = DependencyKind::Path;
                spec.path = entry.pathSrc;
            } else {
                spec.kind = DependencyKind::Version;
                spec.version = entry.version;
            }
            if (installOneDep(projectDir, entry.name, spec, afrilangRoot, newLock, true,
                              false) != 0) {
                ++failures;
                continue;
            }
            // Prefer locked metadata
            if (!newLock.empty() && newLock.back().name == entry.name) {
                if (!entry.sha256.empty() && !newLock.back().sha256.empty() &&
                    entry.source == "registry" && entry.sha256 != newLock.back().sha256) {
                    std::cerr << "Avertissement: sha256 différent pour '" << entry.name
                              << "' (lock vs install).\n";
                }
                newLock.back().version = entry.version.empty() ? newLock.back().version
                                                               : entry.version;
            }
        }
        writeLockFile(lockPath.string(), newLock);
        return failures == 0 ? 0 : 1;
    }

    if (config.dependencies.empty()) {
        std::cout << "Aucune dépendance à installer.\n";
        return 0;
    }

    std::vector<LockedPackage> lock;
    int failures = 0;
    for (const auto& [name, spec] : config.dependencies) {
        if (installOneDep(projectDir, name, spec, afrilangRoot, lock, true, true) != 0) {
            ++failures;
        }
    }
    writeLockFile(lockPath.string(), lock);
    return failures == 0 ? 0 : 1;
}

int PkgRegistry::cmdUpdate(const std::string& projectDir, const std::string& afrilangRoot) {
    const fs::path tomlPath = fs::path(projectDir) / "afrilang.toml";
    if (!fs::exists(tomlPath)) {
        std::cerr << "Erreur: afrilang.toml introuvable.\n";
        return 1;
    }
    ProjectConfig config = loadProjectConfig(tomlPath.string());
    if (config.dependencies.empty()) {
        std::cout << "Aucune dépendance à mettre à jour.\n";
        return 0;
    }

    std::cout << "Résolution des dépendances (update)...\n";
    std::vector<LockedPackage> lock;
    int failures = 0;
    for (const auto& [name, spec] : config.dependencies) {
        if (installOneDep(projectDir, name, spec, afrilangRoot, lock, true, true) != 0) {
            ++failures;
        }
    }
    writeLockFile((fs::path(projectDir) / "afrilang.lock").string(), lock);
    if (failures == 0) {
        std::cout << "afrilang.lock régénéré (" << lock.size() << " paquets).\n";
    }
    return failures == 0 ? 0 : 1;
}

int PkgRegistry::cmdInit(const std::string& dirOrName) {
    const fs::path dir = dirOrName.empty()
                             ? fs::current_path() / "mylib"
                             : (fs::path(dirOrName).is_absolute()
                                    ? fs::path(dirOrName)
                                    : fs::current_path() / dirOrName);
    const std::string name = dir.filename().string().empty() ? "mylib" : dir.filename().string();

    if (fs::exists(dir)) {
        std::cerr << "Erreur: le dossier '" << dir.string() << "' existe déjà.\n";
        return 1;
    }

    fs::create_directories(dir / "tests");

    {
        std::ofstream man(dir / "manifest.toml");
        man << "name = \"" << name << "\"\n";
        man << "version = \"0.1.0\"\n";
        man << "description = \"Paquet AFRILANG " << name << "\"\n";
        man << "main = \"" << name << ".afr\"\n";
    }

    {
        std::ofstream mod(dir / (name + ".afr"));
        mod << "module " << name << "\n";
        mod << "    function hello() returns text\n";
        mod << "        return \"hello from " << name << "\"\n";
        mod << "    end\n";
        mod << "end\n";
    }

    {
        std::ofstream test(dir / "tests" / "smoke.afr");
        test << "import \"pkg/" << name << "/" << name << ".afr\"\n\n";
        test << "use " << name << "\n\n";
        test << "test \"hello\"\n";
        test << "    create h = hello()\n";
        test << "    assert h is equal to \"hello from " << name << "\"\n";
        test << "end\n";
    }

    {
        std::ofstream readme(dir / "README.md");
        readme << "# " << name << "\n\n";
        readme << "Paquet AFRILANG.\n\n";
        readme << "```bash\n";
        readme << "afrilang pkg test\n";
        readme << "afrilang doc .\n";
        readme << "afrilang pkg publish .\n";
        readme << "afrilang pkg publish . --remote   # recette registre + POST si token\n";
        readme << "```\n";
    }

    {
        std::ofstream gi(dir / ".gitignore");
        gi << "vendor/\nbuild/\n*.o\n.afrilang/\n";
    }

    std::cout << "Paquet '" << name << "' initialisé dans " << dir.string() << "\n";
    std::cout << "  cd " << name << " && afrilang pkg test\n";
    std::cout << "  afrilang pkg publish " << dir.string() << "\n";
    return 0;
}

int PkgRegistry::cmdList(const std::string& afrilangRoot, bool blessedOnly) {
    auto packages = listAvailable(afrilangRoot);
    if (blessedOnly) {
        packages.erase(
            std::remove_if(packages.begin(), packages.end(),
                           [](const PackageInfo& p) { return !p.blessed; }),
            packages.end());
    }
    if (packages.empty()) {
        if (blessedOnly) {
            std::cout << "Aucun paquet blessed dans le registre.\n";
        } else {
            std::cout << "Aucun paquet dans le registre (" << afrilangRoot << "/packages).\n";
        }
        return 0;
    }

    std::cout << (blessedOnly ? "Paquets blessed:\n\n" : "Paquets disponibles:\n\n");
    for (const auto& pkg : packages) {
        if (pkg.blessed) std::cout << "  ★ ";
        else std::cout << "    ";
        std::cout << pkg.name << "@" << pkg.version;
        if (!pkg.description.empty()) {
            std::cout << " — " << pkg.description;
        }
        if (pkg.blessed) std::cout << " [blessed]";
        if (!pkg.url.empty()) std::cout << " [" << (pkg.method.empty() ? "git" : pkg.method)
                                       << ": " << pkg.url << "]";
        std::cout << "\n";
    }
    return 0;
}

int PkgRegistry::cmdSearch(const std::string& afrilangRoot, const std::string& query) {
    const auto packages = listAvailable(afrilangRoot);
    bool found = false;
    for (const auto& pkg : packages) {
        if (!query.empty() &&
            !containsIgnoreCase(pkg.name, query) &&
            !containsIgnoreCase(pkg.description, query) &&
            !containsIgnoreCase(pkg.url, query)) {
            bool tagHit = false;
            for (const auto& tag : pkg.tags) {
                if (containsIgnoreCase(tag, query)) {
                    tagHit = true;
                    break;
                }
            }
            if (!tagHit) continue;
        }
        found = true;
        std::cout << pkg.name << "@" << pkg.version;
        if (!pkg.description.empty()) std::cout << " — " << pkg.description;
        if (!pkg.url.empty()) std::cout << " <" << pkg.url << ">";
        for (const auto& tag : pkg.tags) std::cout << " #" << tag;
        std::cout << "\n";
    }
    if (!found) {
        std::cout << "Aucun paquet trouvé";
        if (!query.empty()) std::cout << " pour '" << query << "'";
        std::cout << ".\n";
    }
    return 0;
}

static int curlPostJson(const std::string& url, const std::string& token,
                         const std::string& bodyPath) {
    std::ostringstream cmd;
    cmd << "curl -fsS -X POST";
    if (!token.empty()) {
        cmd << " -H \"Authorization: Bearer " << token << "\"";
    }
    cmd << " -H \"Content-Type: application/json\"";
    cmd << " --data-binary @" << bodyPath;
    cmd << " \"" << url << "\"";
    return runCommand(cmd.str());
}

int PkgRegistry::cmdPublish(const std::string& packageDir, const std::string& afrilangRoot,
                            bool remote) {
    const fs::path src = fs::absolute(packageDir);
    const fs::path manifest = src / "manifest.toml";
    if (!fs::exists(manifest)) {
        std::cerr << "Erreur: manifest.toml introuvable dans " << src << "\n";
        return 1;
    }

    PackageInfo info = loadManifest(src.string());
    if (info.name.empty()) {
        std::cerr << "Erreur: champ 'name' manquant dans manifest.toml\n";
        return 1;
    }
    if (info.version.empty()) info.version = "0.1.0";

    const fs::path dst = fs::path(afrilangRoot) / "packages" / info.name;
    if (!(fs::exists(dst) && fs::equivalent(src, dst))) {
        copyDirectory(src, dst);
    }
    rebuildIndex(afrilangRoot);

    std::cout << "Paquet publié (local): " << info.name << "@" << info.version
              << " → packages/" << info.name << "\n";

    if (!remote) return 0;

    // Nimble-style registry entry recipe
    const char* gitUrlEnv = std::getenv("AFRILANG_PACKAGE_GIT_URL");
    std::string gitUrl = gitUrlEnv ? gitUrlEnv : "";
    std::ostringstream entry;
    entry << "{\n";
    entry << "  \"name\": \"" << jsonEscape(info.name) << "\",\n";
    entry << "  \"version\": \"" << jsonEscape(info.version) << "\",\n";
    entry << "  \"description\": \"" << jsonEscape(info.description) << "\",\n";
    entry << "  \"method\": \"git\",\n";
    if (!gitUrl.empty()) {
        entry << "  \"url\": \"" << jsonEscape(gitUrl) << "\",\n";
    } else {
        entry << "  \"url\": \"https://github.com/OWNER/" << jsonEscape(info.name) << "\",\n";
    }
    entry << "  \"license\": \"MIT\",\n";
    entry << "  \"tags\": [\"afrilang\"]\n";
    entry << "}\n";

    const fs::path recipePath = src / "registry-entry.json";
    {
        std::ofstream out(recipePath);
        out << entry.str();
    }
    std::cout << "\n=== Publication distante (style Nimble) ===\n";
    std::cout << "1. Poussez le dépôt git et taguez: git tag v" << info.version
              << " && git push --tags\n";
    std::cout << "2. Ajoutez cette entrée à packages.json du registre:\n";
    std::cout << entry.str();
    std::cout << "   (fichier écrit: " << recipePath.string() << ")\n";

    const char* token = std::getenv("AFRILANG_REGISTRY_TOKEN");
    const std::string publishUrl = registryPublishUrl();
    if (token && *token) {
        std::cout << "3. POST vers " << publishUrl << " ...\n";
        if (curlPostJson(publishUrl, token, recipePath.string()) != 0) {
            std::cerr << "Avertissement: POST registre a échoué "
                         "(vérifiez AFRILANG_REGISTRY_PUBLISH_URL / token).\n";
            std::cerr << "La publication locale et la recette restent valides.\n";
            return 0; // local publish succeeded
        }
        std::cout << "Registre distant mis à jour.\n";
    } else {
        std::cout << "3. (optionnel) export AFRILANG_REGISTRY_TOKEN=... puis "
                     "relancez avec --remote pour POST automatique.\n";
    }
    return 0;
}

int PkgRegistry::cmdTest(const std::string& packageDir, const std::string& afrilangRoot) {
    const fs::path src = fs::absolute(packageDir.empty() ? "." : packageDir);
    const fs::path manifest = src / "manifest.toml";
    if (!fs::exists(manifest)) {
        std::cerr << "Erreur: manifest.toml introuvable (lancez depuis un paquet "
                     "ou: afrilang pkg test <dir>).\n";
        return 1;
    }
    PackageInfo info = loadManifest(src.string());
    if (info.name.empty()) {
        std::cerr << "Erreur: champ 'name' manquant dans manifest.toml\n";
        return 1;
    }

    // Install into local registry so `import "pkg/<name>/..."` resolves (Nimble-style).
    const fs::path registryDst = fs::path(afrilangRoot) / "packages" / info.name;
    copyDirectory(src, registryDst);
    // Also vendor under package root for path-style layouts
    std::string relPrefix;
    const fs::path vendorRoot = vendorRootFor(src.string(), relPrefix);
    copyDirectory(src, vendorRoot / info.name);
    std::cout << "Self-install: packages/" << info.name << " (+ vendor)\n";

    const fs::path testsDir = src / "tests";
    if (!fs::exists(testsDir)) {
        std::cerr << "Aucun dossier tests/\n";
        return 1;
    }

    int failures = 0;
    int passed = 0;
    for (const auto& entry : fs::recursive_directory_iterator(
             testsDir, fs::directory_options::skip_permission_denied)) {
        if (!entry.is_regular_file() || entry.path().extension() != ".afr") continue;
        const std::string file = entry.path().string();
        std::cout << "  " << fs::relative(entry.path(), src).string() << " ... ";
        std::cout.flush();
        std::ostringstream cmd;
        try {
            const fs::path selfExe = fs::weakly_canonical(fs::read_symlink("/proc/self/exe"));
            cmd << "AFRILANG_HOME=\"" << afrilangRoot << "\" \"" << selfExe.string()
                << "\" run \"" << file << "\"";
        } catch (...) {
            cmd << "AFRILANG_HOME=\"" << afrilangRoot << "\" afrilang run \"" << file << "\"";
        }
        const int rc = runCommand(cmd.str());
        if (rc == 0) {
            std::cout << "OK\n";
            ++passed;
        } else {
            std::cout << "FAIL\n";
            ++failures;
        }
    }
    if (passed + failures == 0) {
        std::cerr << "Aucun tests/**/*.afr\n";
        return 1;
    }
    std::cout << passed << " réussi(s), " << failures << " échec(s).\n";
    return failures == 0 ? 0 : 1;
}

} // namespace afrilang
