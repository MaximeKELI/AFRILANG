#pragma once

#include <cctype>
#include <string>

namespace afrilang::runtime::email {

inline bool isValid(const std::string& address) {
    const std::size_t at = address.find('@');
    if (at == std::string::npos || at == 0 || at + 1 >= address.size()) return false;
    const std::size_t dot = address.find('.', at + 1);
    if (dot == std::string::npos || dot + 1 >= address.size()) return false;
    for (char c : address) {
        if (!(std::isalnum(static_cast<unsigned char>(c)) || c == '@' || c == '.' ||
              c == '_' || c == '-' || c == '+')) {
            return false;
        }
    }
    return true;
}

inline std::string domain(const std::string& address) {
    const std::size_t at = address.find('@');
    if (at == std::string::npos || at + 1 >= address.size()) return {};
    return address.substr(at + 1);
}

} // namespace afrilang::runtime::email
