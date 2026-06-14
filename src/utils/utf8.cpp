#include "afrilang/utf8.hpp"

namespace afrilang {

std::size_t utf8CharLength(unsigned char firstByte) {
    if ((firstByte & 0x80) == 0) return 1;
    if ((firstByte & 0xE0) == 0xC0) return 2;
    if ((firstByte & 0xF0) == 0xE0) return 3;
    if ((firstByte & 0xF8) == 0xF0) return 4;
    return 1;
}

bool isValidUtf8(const std::string& text) {
    for (std::size_t i = 0; i < text.size(); ) {
        const unsigned char c = static_cast<unsigned char>(text[i]);
        const std::size_t len = utf8CharLength(c);
        if (len == 1 && c >= 0x80) return false;
        if (i + len > text.size()) return false;
        for (std::size_t j = 1; j < len; ++j) {
            const unsigned char cont = static_cast<unsigned char>(text[i + j]);
            if ((cont & 0xC0) != 0x80) return false;
        }
        i += len;
    }
    return true;
}

std::size_t utf8CodepointCount(const std::string& text, std::size_t maxBytes) {
    const std::size_t limit = maxBytes == 0 ? text.size() : std::min(maxBytes, text.size());
    std::size_t count = 0;
    for (std::size_t i = 0; i < limit; ) {
        const unsigned char c = static_cast<unsigned char>(text[i]);
        i += utf8CharLength(c);
        ++count;
    }
    return count;
}

std::size_t utf8DisplayWidthBefore(const std::string& line, int byteColumn1Based) {
    if (byteColumn1Based <= 1) return 0;
    const std::size_t target = static_cast<std::size_t>(byteColumn1Based - 1);
    std::size_t width = 0;
    for (std::size_t i = 0; i < line.size() && i < target; ) {
        const unsigned char c = static_cast<unsigned char>(line[i]);
        i += utf8CharLength(c);
        ++width;
    }
    return width;
}

} // namespace afrilang
