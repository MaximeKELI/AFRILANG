#pragma once

#include <string>

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

} // namespace afrilang
