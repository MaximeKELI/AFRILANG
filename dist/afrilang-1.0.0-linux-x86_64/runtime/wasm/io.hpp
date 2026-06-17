#pragma once

#include <cstdio>
#include <string>

namespace afrilang::runtime::wasm {

inline void printLine(const std::string& text) {
    std::fputs(text.c_str(), stdout);
    std::fputc('\n', stdout);
    std::fflush(stdout);
}

} // namespace afrilang::runtime::wasm
