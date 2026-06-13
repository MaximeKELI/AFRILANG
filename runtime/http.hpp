#pragma once

#include <array>
#include <cctype>
#include <cstdio>
#include <memory>
#include <string>

namespace afrilang {
namespace runtime {
namespace http {

inline bool isSafeUrl(const std::string& url) {
    if (url.size() < 8) return false;
    const bool http = url.rfind("http://", 0) == 0;
    const bool https = url.rfind("https://", 0) == 0;
    if (!http && !https) return false;
    for (char c : url) {
        if (std::isalnum(static_cast<unsigned char>(c))) continue;
        if (c == ':' || c == '/' || c == '.' || c == '-' || c == '_' || c == '?' || c == '&' ||
            c == '=') {
            continue;
        }
        return false;
    }
    return true;
}

inline std::string httpGet(const std::string& url) {
    if (!isSafeUrl(url)) return {};

    const std::string cmd = "curl -fsSL \"" + url + "\" 2>/dev/null";
    std::array<char, 4096> buffer{};
    std::string result;

    const std::unique_ptr<FILE, decltype(&pclose)> pipe(popen(cmd.c_str(), "r"), pclose);
    if (!pipe) return {};

    while (true) {
        const std::size_t n = std::fread(buffer.data(), 1, buffer.size(), pipe.get());
        if (n == 0) break;
        result.append(buffer.data(), n);
    }
    return result;
}

} // namespace http
} // namespace runtime
} // namespace afrilang
