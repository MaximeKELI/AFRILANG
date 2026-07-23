#pragma once

#include <string>
#include <unordered_set>

namespace afrilang {

/** Shared FFI library allowlist (analyzer + codegen). Keep intentionally small. */
inline const std::unordered_set<std::string>& ffiAllowedLibraries() {
    static const std::unordered_set<std::string> kAllowed = {
        "m", "libm", "c", "libc", "pthread", "dl", "math", "curl"
    };
    return kAllowed;
}

inline bool isFfiLibraryAllowed(const std::string& library) {
    return ffiAllowedLibraries().count(library) > 0;
}

} // namespace afrilang
