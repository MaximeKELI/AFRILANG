#pragma once

#include <cstddef>
#include <string>
#include <vector>

namespace afrilang::runtime::args {

inline std::vector<std::string> g_args;

inline void init(int argc, char** argv) {
    g_args.clear();
    for (int i = 1; i < argc; ++i) {
        g_args.emplace_back(argv[i]);
    }
}

inline double count() {
    return static_cast<double>(g_args.size());
}

inline std::string at(double index) {
    const std::size_t i = static_cast<std::size_t>(index);
    if (i >= g_args.size()) return "";
    return g_args[i];
}

inline std::vector<std::string> all() {
    return g_args;
}

} // namespace afrilang::runtime::args
