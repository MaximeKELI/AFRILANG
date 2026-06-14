#pragma once

#include <cstddef>
#include <string>

namespace afrilang {

std::size_t utf8CharLength(unsigned char firstByte);
bool isValidUtf8(const std::string& text);
std::size_t utf8CodepointCount(const std::string& text, std::size_t maxBytes = 0);
std::size_t utf8DisplayWidthBefore(const std::string& line, int byteColumn1Based);

} // namespace afrilang
