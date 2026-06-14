#include "afrilang/semver.hpp"

#include <cctype>

namespace afrilang {

bool parseSemVer(const std::string& version, SemVer& out) {
    int parts[3] = {0, 0, 0};
    int idx = 0;
    int current = 0;
    bool hasDigit = false;

    for (char c : version) {
        if (std::isdigit(static_cast<unsigned char>(c))) {
            hasDigit = true;
            current = current * 10 + (c - '0');
        } else if (c == '.') {
            if (!hasDigit || idx >= 2) return false;
            parts[idx++] = current;
            current = 0;
            hasDigit = false;
        } else if (c == '-' || c == '+') {
            break;
        } else {
            return false;
        }
    }
    if (!hasDigit) return false;
    parts[idx] = current;
    out.major = parts[0];
    out.minor = parts[1];
    out.patch = parts[2];
    return true;
}

int compareSemVer(const SemVer& a, const SemVer& b) {
    if (a.major != b.major) return a.major < b.major ? -1 : 1;
    if (a.minor != b.minor) return a.minor < b.minor ? -1 : 1;
    if (a.patch != b.patch) return a.patch < b.patch ? -1 : 1;
    return 0;
}

bool semverSatisfies(const std::string& required, const std::string& actual) {
    SemVer req;
    SemVer act;
    if (!parseSemVer(required, req) || !parseSemVer(actual, act)) return required == actual;
    return compareSemVer(act, req) >= 0;
}

} // namespace afrilang
