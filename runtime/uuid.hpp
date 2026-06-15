#pragma once

#include <iomanip>
#include <random>
#include <sstream>
#include <string>

namespace afrilang::runtime::uuid {

inline std::string v4() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(0, 15);
    std::uniform_int_distribution<int> dist2(8, 11);
    std::ostringstream out;
    out << std::hex << std::setfill('0');
    for (int i = 0; i < 8; ++i) out << std::setw(1) << dist(gen);
    out << '-';
    for (int i = 0; i < 4; ++i) out << std::setw(1) << dist(gen);
    out << "-4";
    for (int i = 0; i < 3; ++i) out << std::setw(1) << dist(gen);
    out << '-';
    out << std::setw(1) << dist2(gen);
    for (int i = 0; i < 3; ++i) out << std::setw(1) << dist(gen);
    out << '-';
    for (int i = 0; i < 12; ++i) out << std::setw(1) << dist(gen);
    return out.str();
}

} // namespace afrilang::runtime::uuid
