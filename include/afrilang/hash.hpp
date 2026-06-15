#pragma once

#include <string>

namespace afrilang {

std::string sha256Hex(const std::string& data);
std::string sha256File(const std::string& path);
std::string sha256Directory(const std::string& dirPath);

} // namespace afrilang
