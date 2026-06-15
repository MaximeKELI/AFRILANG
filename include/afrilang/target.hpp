#pragma once

#include <string>

namespace afrilang {

inline std::string normalizeCrossTarget(std::string target) {
    if (target.empty() || target == "native" || target == "linux-x64") {
        return "native";
    }
    return target;
}

inline bool isKnownCrossTarget(const std::string& target) {
    const std::string t = normalizeCrossTarget(target);
    return t == "native" || t == "linux-arm64" || t == "wasm32";
}

inline bool isWasmTarget(const std::string& target) {
    return normalizeCrossTarget(target) == "wasm32";
}

} // namespace afrilang
