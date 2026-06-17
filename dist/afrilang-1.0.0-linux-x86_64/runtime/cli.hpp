#pragma once

#include <string>

namespace afrilang::runtime::cli {

inline std::string green(const std::string& text) { return "\033[32m" + text + "\033[0m"; }
inline std::string red(const std::string& text) { return "\033[31m" + text + "\033[0m"; }
inline std::string yellow(const std::string& text) { return "\033[33m" + text + "\033[0m"; }
inline std::string bold(const std::string& text) { return "\033[1m" + text + "\033[0m"; }
inline std::string reset(const std::string& text) { return text + "\033[0m"; }

} // namespace afrilang::runtime::cli
