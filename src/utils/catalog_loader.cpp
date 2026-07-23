// Chargeur paresseux du catalogue « complexe » (std/c/*).
//
// Le catalogue (~5710 modules) était auparavant compilé dans le binaire via
// src/utils/complex_catalog.cpp (~4,7 Mo). Il est désormais externalisé dans
// share/afrilang/catalog/complex.json et chargé à la première résolution d'un
// module std/c/*. Cela réduit fortement la taille du binaire et le temps de
// rebuild, sans dépendance externe (parseur JSON minimal maison).

#include "afrilang/complex_catalog.hpp"

#include <cstdint>
#include <cstdlib>
#include <deque>
#include <fstream>
#include <iostream>
#include <mutex>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

#if defined(__linux__)
#include <unistd.h>
#endif

namespace afrilang {
namespace {

// Chemins injectés par CMake (source pour l'arbre de build, install pour le
// binaire déployé). Peuvent être vides si non définis.
#ifndef AFRILANG_SOURCE_CATALOG
#define AFRILANG_SOURCE_CATALOG ""
#endif
#ifndef AFRILANG_INSTALL_CATALOG
#define AFRILANG_INSTALL_CATALOG ""
#endif

std::string executableDir() {
#if defined(__linux__)
    char buf[4096];
    const ssize_t n = ::readlink("/proc/self/exe", buf, sizeof(buf) - 1);
    if (n > 0) {
        std::string path(buf, static_cast<std::size_t>(n));
        const auto slash = path.find_last_of('/');
        if (slash != std::string::npos) return path.substr(0, slash);
    }
#endif
    return {};
}

bool fileExists(const std::string& path) {
    if (path.empty()) return false;
    std::ifstream f(path);
    return f.good();
}

// Résout le chemin du catalogue selon l'ordre : override explicite, AFRILANG_HOME,
// arbre source (build), préfixe d'install, relatif à l'exécutable.
std::string resolveCatalogPath() {
    if (const char* explicitPath = std::getenv("AFRILANG_CATALOG")) {
        if (fileExists(explicitPath)) return explicitPath;
    }
    if (const char* home = std::getenv("AFRILANG_HOME")) {
        const std::string p = std::string(home) + "/share/afrilang/catalog/complex.json";
        if (fileExists(p)) return p;
    }
    if (fileExists(AFRILANG_SOURCE_CATALOG)) return AFRILANG_SOURCE_CATALOG;
    if (fileExists(AFRILANG_INSTALL_CATALOG)) return AFRILANG_INSTALL_CATALOG;
    const std::string exeDir = executableDir();
    if (!exeDir.empty()) {
        const std::string candidates[] = {
            exeDir + "/../share/afrilang/catalog/complex.json",
            exeDir + "/share/afrilang/catalog/complex.json",
        };
        for (const auto& c : candidates) {
            if (fileExists(c)) return c;
        }
    }
    return {};
}

// --- Parseur JSON minimal (schéma connu, faible empreinte mémoire) ---------
class Scanner {
public:
    explicit Scanner(const std::string& s) : s_(s) {}

    void skipWs() {
        while (i_ < s_.size()) {
            const char c = s_[i_];
            if (c == ' ' || c == '\n' || c == '\t' || c == '\r') ++i_;
            else break;
        }
    }

    bool eat(char c) {
        skipWs();
        if (i_ < s_.size() && s_[i_] == c) { ++i_; return true; }
        return false;
    }

    char peek() {
        skipWs();
        return i_ < s_.size() ? s_[i_] : '\0';
    }

    bool parseString(std::string& out) {
        skipWs();
        if (i_ >= s_.size() || s_[i_] != '"') return false;
        ++i_;
        out.clear();
        while (i_ < s_.size()) {
            const char c = s_[i_++];
            if (c == '"') return true;
            if (c == '\\' && i_ < s_.size()) {
                const char e = s_[i_++];
                switch (e) {
                    case 'n': out += '\n'; break;
                    case 't': out += '\t'; break;
                    case 'r': out += '\r'; break;
                    case 'b': out += '\b'; break;
                    case 'f': out += '\f'; break;
                    case '/': out += '/'; break;
                    case '"': out += '"'; break;
                    case '\\': out += '\\'; break;
                    case 'u': {
                        if (i_ + 4 <= s_.size()) {
                            unsigned cp = 0;
                            for (int k = 0; k < 4; ++k) {
                                const char h = s_[i_ + k];
                                cp <<= 4;
                                if (h >= '0' && h <= '9') cp |= (h - '0');
                                else if (h >= 'a' && h <= 'f') cp |= (h - 'a' + 10);
                                else if (h >= 'A' && h <= 'F') cp |= (h - 'A' + 10);
                            }
                            i_ += 4;
                            if (cp <= 0x7F) {
                                out += static_cast<char>(cp);
                            } else if (cp <= 0x7FF) {
                                out += static_cast<char>(0xC0 | (cp >> 6));
                                out += static_cast<char>(0x80 | (cp & 0x3F));
                            } else {
                                out += static_cast<char>(0xE0 | (cp >> 12));
                                out += static_cast<char>(0x80 | ((cp >> 6) & 0x3F));
                                out += static_cast<char>(0x80 | (cp & 0x3F));
                            }
                        }
                        break;
                    }
                    default: out += e; break;
                }
            } else {
                out += c;
            }
        }
        return false;
    }

    bool parseInt(long& out) {
        skipWs();
        const std::size_t start = i_;
        if (i_ < s_.size() && (s_[i_] == '-' || s_[i_] == '+')) ++i_;
        bool any = false;
        while (i_ < s_.size() && s_[i_] >= '0' && s_[i_] <= '9') { ++i_; any = true; }
        if (!any) return false;
        out = std::stol(s_.substr(start, i_ - start));
        return true;
    }

    // Saute une valeur JSON quelconque (pour les clés inconnues).
    bool skipValue() {
        skipWs();
        if (i_ >= s_.size()) return false;
        const char c = s_[i_];
        if (c == '"') { std::string tmp; return parseString(tmp); }
        if (c == '{' || c == '[') {
            const char open = c;
            const char close = (c == '{') ? '}' : ']';
            ++i_;
            int depth = 1;
            while (i_ < s_.size() && depth > 0) {
                const char d = s_[i_];
                if (d == '"') { std::string tmp; parseString(tmp); continue; }
                if (d == open) ++depth;
                else if (d == close) --depth;
                ++i_;
            }
            return depth == 0;
        }
        // scalaire (nombre/bool/null)
        while (i_ < s_.size()) {
            const char d = s_[i_];
            if (d == ',' || d == '}' || d == ']') break;
            ++i_;
        }
        return true;
    }

private:
    const std::string& s_;
    std::size_t i_ = 0;
};

struct CatalogData {
    bool loaded = false;
    bool ok = false;
    std::deque<std::string> strings;
    std::deque<std::vector<StdlibParamSpec>> paramArrays;
    std::deque<std::vector<StdlibFuncSpec>> funcArrays;
    std::deque<StdlibModuleSpec> modules;
    std::unordered_map<std::string, const StdlibModuleSpec*> index;

    const char* intern(const std::string& v) {
        strings.push_back(v);
        return strings.back().c_str();
    }
};

const char* kRuntimeHeader = "cx/complex_libs.hpp";

// Parse un module : {"import":"..","name":"..","funcs":[...]}
bool parseModule(Scanner& sc, CatalogData& data) {
    if (!sc.eat('{')) return false;
    std::string importName, moduleName;
    std::vector<StdlibParamSpec> params;
    std::vector<StdlibFuncSpec> funcs;
    // structures temporaires (offsets dans `params`) pour relier func→params.
    struct TmpFunc { const char* name; const char* ret; std::size_t off; std::size_t count; };
    std::vector<TmpFunc> tmpFuncs;

    while (true) {
        std::string key;
        if (!sc.parseString(key)) return false;
        if (!sc.eat(':')) return false;
        if (key == "import") {
            std::string v;
            if (!sc.parseString(v)) return false;
            importName = v;
        } else if (key == "name") {
            std::string v;
            if (!sc.parseString(v)) return false;
            moduleName = v;
        } else if (key == "funcs") {
            if (!sc.eat('[')) return false;
            if (sc.peek() != ']') {
                while (true) {
                    if (!sc.eat('{')) return false;
                    std::string fname, ret;
                    std::size_t off = params.size();
                    std::size_t count = 0;
                    while (true) {
                        std::string fk;
                        if (!sc.parseString(fk)) return false;
                        if (!sc.eat(':')) return false;
                        if (fk == "n") {
                            if (!sc.parseString(fname)) return false;
                        } else if (fk == "r") {
                            if (!sc.parseString(ret)) return false;
                        } else if (fk == "p") {
                            if (!sc.eat('[')) return false;
                            if (sc.peek() != ']') {
                                while (true) {
                                    if (!sc.eat('[')) return false;
                                    std::string pn, pt;
                                    if (!sc.parseString(pn)) return false;
                                    if (!sc.eat(',')) return false;
                                    if (!sc.parseString(pt)) return false;
                                    if (!sc.eat(']')) return false;
                                    params.push_back({data.intern(pn), data.intern(pt)});
                                    ++count;
                                    if (sc.eat(',')) continue;
                                    break;
                                }
                            }
                            if (!sc.eat(']')) return false;
                        } else {
                            if (!sc.skipValue()) return false;
                        }
                        if (sc.eat(',')) continue;
                        break;
                    }
                    if (!sc.eat('}')) return false;
                    tmpFuncs.push_back({data.intern(fname), data.intern(ret), off, count});
                    if (sc.eat(',')) continue;
                    break;
                }
            }
            if (!sc.eat(']')) return false;
        } else {
            if (!sc.skipValue()) return false;
        }
        if (sc.eat(',')) continue;
        break;
    }
    if (!sc.eat('}')) return false;

    // Fige le tableau de params du module (plus de resize → pointeurs stables).
    data.paramArrays.push_back(std::move(params));
    const StdlibParamSpec* paramBase = data.paramArrays.back().data();

    funcs.reserve(tmpFuncs.size() + 1);
    for (const auto& tf : tmpFuncs) {
        StdlibFuncSpec fs;
        fs.name = tf.name;
        fs.returnType = tf.ret;
        fs.paramCount = tf.count;
        fs.params = tf.count ? (paramBase + tf.off) : nullptr;
        funcs.push_back(fs);
    }
    const std::size_t funcCount = funcs.size();
    funcs.push_back({nullptr, nullptr, 0, nullptr}); // terminateur défensif
    data.funcArrays.push_back(std::move(funcs));
    const StdlibFuncSpec* funcBase = data.funcArrays.back().data();

    StdlibModuleSpec mod;
    mod.importName = data.intern(importName.empty() ? moduleName : importName);
    mod.moduleName = data.intern(moduleName.empty() ? importName : moduleName);
    mod.functions = funcBase;
    mod.functionCount = funcCount;
    mod.runtimeHeader = kRuntimeHeader;
    mod.needsSpecialCodegen = false;
    data.modules.push_back(mod);
    const StdlibModuleSpec* stored = &data.modules.back();
    data.index[mod.importName] = stored;
    data.index[mod.moduleName] = stored;
    return true;
}

bool parseCatalog(const std::string& text, CatalogData& data) {
    Scanner sc(text);
    if (!sc.eat('{')) return false;
    bool versionChecked = false;
    while (true) {
        std::string key;
        if (!sc.parseString(key)) return false;
        if (!sc.eat(':')) return false;
        if (key == "version") {
            long v = 0;
            if (!sc.parseInt(v)) return false;
            if (v != kComplexCatalogVersion) {
                std::cerr << "AFRILANG: catalogue std/c incompatible (version " << v
                          << ", binaire attend " << kComplexCatalogVersion
                          << "). Régénérez via scripts/gen_complex_stdlib.py.\n";
                return false;
            }
            versionChecked = true;
        } else if (key == "modules") {
            if (!sc.eat('[')) return false;
            if (sc.peek() != ']') {
                while (true) {
                    if (!parseModule(sc, data)) return false;
                    if (sc.eat(',')) continue;
                    break;
                }
            }
            if (!sc.eat(']')) return false;
        } else {
            if (!sc.skipValue()) return false;
        }
        if (sc.eat(',')) continue;
        break;
    }
    return versionChecked;
}

CatalogData& catalog() {
    static CatalogData data;
    static std::once_flag once;
    std::call_once(once, [] {
        data.loaded = true;
        const std::string path = resolveCatalogPath();
        if (path.empty()) {
            std::cerr << "AFRILANG: catalogue std/c introuvable "
                         "(share/afrilang/catalog/complex.json). "
                         "Définissez AFRILANG_HOME ou réinstallez.\n";
            return;
        }
        std::ifstream in(path, std::ios::binary);
        if (!in) return;
        std::ostringstream buf;
        buf << in.rdbuf();
        const std::string text = buf.str();
        data.ok = parseCatalog(text, data);
        if (!data.ok) {
            data.modules.clear();
            data.index.clear();
        }
    });
    return data;
}

} // namespace

const StdlibModuleSpec* complexCatalogFindModule(const std::string& name) {
    CatalogData& data = catalog();
    if (!data.ok) return nullptr;
    const auto it = data.index.find(name);
    return it != data.index.end() ? it->second : nullptr;
}

bool complexCatalogIsComplexModule(const std::string& name) {
    return complexCatalogFindModule(name) != nullptr;
}

} // namespace afrilang
