#pragma once

#include <cstdlib>
#include <string>

#if defined(_WIN32)
#include <stdlib.h>
#endif

namespace afrilang::runtime::env {

inline std::string get(const std::string& name) {
    if (const char* value = std::getenv(name.c_str())) {
        return value;
    }
    return {};
}

inline bool has(const std::string& name) {
    return std::getenv(name.c_str()) != nullptr;
}

inline bool set(const std::string& name, const std::string& value) {
#if defined(_WIN32)
    return _putenv_s(name.c_str(), value.c_str()) == 0;
#else
    return setenv(name.c_str(), value.c_str(), 1) == 0;
#endif
}

} // namespace afrilang::runtime::env
