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

bool parseSemVerRange(const std::string& required, SemVerRange& out) {
    if (required.empty()) return false;
    std::string body = required;
    out.kind = SemVerRangeKind::ExactOrMin;
    if (body[0] == '^') {
        out.kind = SemVerRangeKind::Caret;
        body = body.substr(1);
    } else if (body[0] == '~') {
        out.kind = SemVerRangeKind::Tilde;
        body = body.substr(1);
    }
    return parseSemVer(body, out.base);
}

bool semverSatisfies(const std::string& required, const std::string& actual) {
    SemVerRange range;
    SemVer act;
    if (!parseSemVer(actual, act)) return required == actual;
    if (!parseSemVerRange(required, range)) return required == actual;

    if (compareSemVer(act, range.base) < 0) return false;

    if (range.kind == SemVerRangeKind::Caret) {
        SemVer upper = range.base;
        if (upper.major > 0) {
            upper.major += 1;
            upper.minor = 0;
            upper.patch = 0;
        } else if (upper.minor > 0) {
            upper.minor += 1;
            upper.patch = 0;
        } else {
            upper.patch += 1;
        }
        return compareSemVer(act, upper) < 0;
    }

    if (range.kind == SemVerRangeKind::Tilde) {
        SemVer upper = range.base;
        upper.minor += 1;
        upper.patch = 0;
        return compareSemVer(act, upper) < 0;
    }

    // ExactOrMin: actual >= required
    return true;
}

} // namespace afrilang
