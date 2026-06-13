#pragma once

#include <regex>
#include <string>

namespace afrilang::runtime::re {

inline bool match(const std::string& text, const std::string& pattern) {
    return std::regex_match(text, std::regex(pattern));
}

inline std::string replace(const std::string& text, const std::string& pattern,
                           const std::string& replacement) {
    return std::regex_replace(text, std::regex(pattern), replacement);
}

} // namespace afrilang::runtime::re
