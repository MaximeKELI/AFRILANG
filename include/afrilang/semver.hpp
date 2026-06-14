#pragma once

#include <string>
#include <vector>

namespace afrilang {

struct SemVer {
    int major = 0;
    int minor = 0;
    int patch = 0;
};

bool parseSemVer(const std::string& version, SemVer& out);
int compareSemVer(const SemVer& a, const SemVer& b);
bool semverSatisfies(const std::string& required, const std::string& actual);

} // namespace afrilang
