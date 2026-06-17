#pragma once

#include <cctype>
#include <iomanip>
#include <sstream>
#include <string>

namespace afrilang::runtime::hex {

inline std::string encode(const std::string& data) {
    std::ostringstream out;
    out << std::hex << std::setfill('0');
    for (unsigned char c : data) {
        out << std::setw(2) << static_cast<int>(c);
    }
    return out.str();
}

inline int nibble(char c) {
    if (c >= '0' && c <= '9') return c - '0';
    if (c >= 'a' && c <= 'f') return c - 'a' + 10;
    if (c >= 'A' && c <= 'F') return c - 'A' + 10;
    return -1;
}

inline std::string decode(const std::string& data) {
    std::string out;
    for (std::size_t i = 0; i + 1 < data.size(); i += 2) {
        const int hi = nibble(data[i]);
        const int lo = nibble(data[i + 1]);
        if (hi < 0 || lo < 0) continue;
        out.push_back(static_cast<char>((hi << 4) | lo));
    }
    return out;
}

inline std::string toHex(double n) {
    std::ostringstream os;
    os << std::hex << static_cast<long long>(n);
    return os.str();
}

inline double fromHex(const std::string& s) {
    return static_cast<double>(std::stoll(s, nullptr, 16));
}

} // namespace afrilang::runtime::hex
