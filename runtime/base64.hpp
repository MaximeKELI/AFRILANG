#pragma once

#include <cstdint>
#include <string>
#include <vector>

namespace afrilang::runtime::base64 {

inline std::string encode(const std::string& data) {
    static const char* kTable =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string out;
    out.reserve(((data.size() + 2) / 3) * 4);
    std::size_t i = 0;
    while (i < data.size()) {
        const std::uint32_t octet_a = static_cast<unsigned char>(data[i++]);
        const std::uint32_t octet_b = i < data.size() ? static_cast<unsigned char>(data[i++]) : 0;
        const std::uint32_t octet_c = i < data.size() ? static_cast<unsigned char>(data[i++]) : 0;
        const std::uint32_t triple = (octet_a << 16) + (octet_b << 8) + octet_c;
        out.push_back(kTable[(triple >> 18) & 0x3F]);
        out.push_back(kTable[(triple >> 12) & 0x3F]);
        out.push_back(i > data.size() + 1 ? '=' : kTable[(triple >> 6) & 0x3F]);
        out.push_back(i > data.size() ? '=' : kTable[triple & 0x3F]);
    }
    return out;
}

inline int decodeValue(char c) {
    if (c >= 'A' && c <= 'Z') return c - 'A';
    if (c >= 'a' && c <= 'z') return c - 'a' + 26;
    if (c >= '0' && c <= '9') return c - '0' + 52;
    if (c == '+') return 62;
    if (c == '/') return 63;
    return -1;
}

inline std::string decode(const std::string& data) {
    std::string out;
    out.reserve(data.size() * 3 / 4);
    std::uint32_t buffer = 0;
    int bits = 0;
    for (char c : data) {
        if (c == '=' || c == '\n' || c == '\r') continue;
        const int val = decodeValue(c);
        if (val < 0) continue;
        buffer = (buffer << 6) | static_cast<std::uint32_t>(val);
        bits += 6;
        if (bits >= 8) {
            bits -= 8;
            out.push_back(static_cast<char>((buffer >> bits) & 0xFF));
        }
    }
    return out;
}

} // namespace afrilang::runtime::base64
