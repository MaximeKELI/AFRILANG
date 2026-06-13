#pragma once

#include <iostream>
#include <string>

namespace afrilang::runtime::log {

inline void info(const std::string& message) {
    std::cout << "[INFO] " << message << std::endl;
}

inline void warn(const std::string& message) {
    std::cout << "[WARN] " << message << std::endl;
}

inline void error(const std::string& message) {
    std::cerr << "[ERROR] " << message << std::endl;
}

} // namespace afrilang::runtime::log
