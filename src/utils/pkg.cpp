#include "afrilang/pkg.hpp"

#include "afrilang/project.hpp"
#include "afrilang/sandbox.hpp"
#include "afrilang/security.hpp"
#include "afrilang/semver.hpp"

#include <algorithm>
#include <cctype>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <sstream>

namespace fs = std::filesystem;

namespace afrilang {

bool PkgRegistry::isPkgImport(const std::string& path) {
    return path.rfind("pkg/", 0) == 0;
}

std::string PkgRegistry::resolvePkgImport(const std::string& importPath,
                                          const std::string& projectDir,
                                          const std::string& afrilangRoot) {
    const std::string relative = importPath.substr(4);
    const fs::path vendorPath = fs::path(projectDir) / "vendor" / relative;
    if (fs::exists(vendorPath)) {
        return fs::weakly_canonical(vendorPath).string();
    }

    const fs::path registryPath = fs::path(afrilangRoot) / "packages" / relative;
    if (fs::exists(registryPath)) {
        return fs::weakly_canonical(registryPath).string();
    }

    return (fs::path(projectDir) / importPath).string();
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

std::vector<PackageInfo> PkgRegistry::listAvailable(const std::string& afrilangRoot) {
    std::vector<PackageInfo> packages;
    const fs::path packagesDir = fs::path(afrilangRoot) / "packages";
    if (!fs::exists(packagesDir)) return packages;

    for (const auto& entry : fs::directory_iterator(packagesDir)) {
        if (!entry.is_directory()) continue;
        PackageInfo info = loadManifest(entry.path().string());
        if (!info.name.empty()) {
            packages.push_back(std::move(info));
        }
    }
    return packages;
}

static void copyDirectory(const fs::path& src, const fs::path& dst) {
    fs::create_directories(dst);
    for (const auto& entry : fs::recursive_directory_iterator(src)) {
        const fs::path rel = fs::relative(entry.path(), src);
        const fs::path target = dst / rel;
        if (entry.is_directory()) {
            fs::create_directories(target);
        } else {
            fs::create_directories(target.parent_path());
            fs::copy_file(entry.path(), target, fs::copy_options::overwrite_existing);
        }
    }
}

static void writeLockEntry(const fs::path& lockPath, const std::string& name,
                           const std::string& version, const std::string& relPath) {
    std::ofstream lock(lockPath, std::ios::app);
    lock << "[[package]]\n";
    lock << "name = \"" << name << "\"\n";
    lock << "version = \"" << version << "\"\n";
    lock << "path = \"" << relPath << "\"\n\n";
}

static void ensureDependencyInToml(const fs::path& tomlPath, const std::string& name,
                                     const std::string& version) {
    std::ifstream in(tomlPath);
    std::ostringstream content;
    content << in.rdbuf();
    std::string text = content.str();

    const std::string depLine = name + " = \"" + version + "\"";
    if (text.find(depLine) != std::string::npos) return;

    if (text.find("[dependencies]") == std::string::npos) {
        if (!text.empty() && text.back() != '\n') text += "\n";
        text += "\n[dependencies]\n";
    }
    text += depLine + "\n";

    std::ofstream out(tomlPath);
    out << text;
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

int PkgRegistry::rebuildIndex(const std::string& afrilangRoot) {
    const fs::path packagesDir = fs::path(afrilangRoot) / "packages";
    const fs::path indexPath = packagesDir / "index.json";
    const auto packages = listAvailable(afrilangRoot);

    std::ostringstream json;
    json << "{\n  \"packages\": [\n";
    for (std::size_t i = 0; i < packages.size(); ++i) {
        const auto& pkg = packages[i];
        json << "    {\"name\":\"" << jsonEscape(pkg.name) << "\","
             << "\"version\":\"" << jsonEscape(pkg.version) << "\","
             << "\"description\":\"" << jsonEscape(pkg.description) << "\"}";
        if (i + 1 < packages.size()) json << ',';
        json << '\n';
    }
    json << "  ]\n}\n";

    std::ofstream out(indexPath);
    if (!out) return 1;
    out << json.str();
    return 0;
}

int PkgRegistry::cmdAdd(const std::string& projectDir, const std::string& packageName,
                        const std::string& afrilangRoot) {
    const fs::path src = fs::path(afrilangRoot) / "packages" / packageName;
    if (!fs::exists(src)) {
        std::cerr << "Erreur: paquet '" << packageName << "' introuvable dans le registre.\n";
        std::cerr << "Utilisez 'afrilang pkg list' pour voir les paquets disponibles.\n";
        return 1;
    }

    PackageInfo info = loadManifest(src.string());
    if (info.name.empty()) info.name = packageName;
    if (info.version.empty()) info.version = "0.1.0";

    const fs::path dst = fs::path(projectDir) / "vendor" / packageName;
    copyDirectory(src, dst);

    const fs::path tomlPath = fs::path(projectDir) / "afrilang.toml";
    if (fs::exists(tomlPath)) {
        ensureDependencyInToml(tomlPath, info.name, info.version);
    }

    const fs::path lockPath = fs::path(projectDir) / "afrilang.lock";
    if (!fs::exists(lockPath)) {
        std::ofstream lock(lockPath);
        lock << "# AFRILANG lockfile\n\n";
    }
    writeLockEntry(lockPath, info.name, info.version, "vendor/" + packageName);

    std::cout << "Paquet '" << info.name << "@" << info.version << "' installé dans vendor/"
              << packageName << "\n";
    return 0;
}

int PkgRegistry::cmdInstall(const std::string& projectDir, const std::string& afrilangRoot) {
    const fs::path tomlPath = fs::path(projectDir) / "afrilang.toml";
    if (!fs::exists(tomlPath)) {
        std::cerr << "Erreur: afrilang.toml introuvable.\n";
        return 1;
    }

    ProjectConfig config = loadProjectConfig(tomlPath.string());
    if (config.dependencies.empty()) {
        std::cout << "Aucune dépendance à installer.\n";
        return 0;
    }

    int failures = 0;
    for (const auto& [name, version] : config.dependencies) {
        const fs::path src = fs::path(afrilangRoot) / "packages" / name;
        if (!fs::exists(src)) {
            std::cerr << "Erreur: paquet '" << name << "' introuvable.\n";
            ++failures;
            continue;
        }
        PackageInfo info = loadManifest(src.string());
        if (info.name.empty()) info.name = name;
        const std::string actualVersion = info.version.empty() ? "0.1.0" : info.version;
        if (!version.empty() && !semverSatisfies(version, actualVersion)) {
            std::cerr << "Erreur: '" << name << "' requiert " << version
                      << " mais le registre fournit " << actualVersion << "\n";
            ++failures;
            continue;
        }
        if (cmdAdd(projectDir, name, afrilangRoot) != 0) {
            ++failures;
        }
    }
    return failures == 0 ? 0 : 1;
}

int PkgRegistry::cmdList(const std::string& afrilangRoot) {
    const auto packages = listAvailable(afrilangRoot);
    if (packages.empty()) {
        std::cout << "Aucun paquet dans le registre (" << afrilangRoot << "/packages).\n";
        return 0;
    }

    std::cout << "Paquets disponibles:\n\n";
    for (const auto& pkg : packages) {
        std::cout << "  " << pkg.name << "@" << pkg.version;
        if (!pkg.description.empty()) {
            std::cout << " — " << pkg.description;
        }
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
            !containsIgnoreCase(pkg.description, query)) {
            continue;
        }
        found = true;
        std::cout << pkg.name << "@" << pkg.version;
        if (!pkg.description.empty()) std::cout << " — " << pkg.description;
        std::cout << "\n";
    }
    if (!found) {
        std::cout << "Aucun paquet trouvé";
        if (!query.empty()) std::cout << " pour '" << query << "'";
        std::cout << ".\n";
    }
    return 0;
}

int PkgRegistry::cmdPublish(const std::string& packageDir, const std::string& afrilangRoot) {
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
    copyDirectory(src, dst);
    rebuildIndex(afrilangRoot);

    std::cout << "Paquet publié: " << info.name << "@" << info.version
              << " → packages/" << info.name << "\n";
    return 0;
}

} // namespace afrilang
