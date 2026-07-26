#pragma once

#include <string>
#include <unordered_set>
#include <vector>

namespace afrilang {

/** Normalize CLI --target. `linux-x64` is an alias of host `native` (not a cross). */
inline std::string normalizeCrossTarget(std::string target) {
    if (target.empty() || target == "native" || target == "linux-x64") {
        return "native";
    }
    return target;
}

/** Known values: native, linux-arm64, wasm32. No windows/macos cross targets. */
inline bool isKnownCrossTarget(const std::string& target) {
    const std::string t = normalizeCrossTarget(target);
    return t == "native" || t == "linux-arm64" || t == "wasm32";
}

inline bool isWasmTarget(const std::string& target) {
    return normalizeCrossTarget(target) == "wasm32";
}

/** Modules that require a native OS (sockets, OpenSSL, SDL, threads, …). See docs/WASM_COMPAT.md. */
inline const std::unordered_set<std::string>& wasmNativeOnlyModules() {
    static const std::unordered_set<std::string> mods = {
        "http",     "net",      "process", "crypto", "sql",      "orm",
        "thread",   "web",      "ui",      "game2d", "game3d",   "gamestate",
        "gamenet",  "tempfile",
    };
    return mods;
}

inline bool isWasmNativeOnlyModule(const std::string& moduleName) {
    return wasmNativeOnlyModules().count(moduleName) > 0;
}

/** First native-only module found in `used`, or empty. */
inline std::string firstWasmUnsupportedModule(const std::unordered_set<std::string>& used) {
    for (const auto& m : used) {
        if (isWasmNativeOnlyModule(m)) return m;
    }
    return {};
}

/**
 * Resolve a host binary name for spawn (adds .exe on Windows when present).
 * Prefers a relative "./name" form when `executable` is not absolute.
 */
inline std::string hostRunnablePath(const std::string& executable) {
    if (executable.empty()) return executable;
    std::string name = executable;
#if defined(_WIN32)
    const bool hasSep =
        name.find('\\') != std::string::npos || name.find('/') != std::string::npos;
    if (!hasSep) {
        const bool hasExe = name.size() >= 4 &&
                            (name.compare(name.size() - 4, 4, ".exe") == 0 ||
                             name.compare(name.size() - 4, 4, ".EXE") == 0);
        if (!hasExe) name += ".exe";
    }
#endif
    if (!name.empty() && name[0] != '.' && name[0] != '/' &&
#if defined(_WIN32)
        (name.size() < 2 || name[1] != ':')
#else
        true
#endif
    ) {
        return "./" + name;
    }
    return name;
}

} // namespace afrilang
