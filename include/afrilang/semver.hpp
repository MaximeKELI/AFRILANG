#pragma once

#include <string>
#include <vector>

namespace afrilang {

struct SemVer {
    int major = 0;
    int minor = 0;
    int patch = 0;
};

enum class SemVerRangeKind {
    ExactOrMin, // bare version: actual >= required (compat historique)
    Caret,      // ^1.2.3 → >=1.2.3 <2.0.0
    Tilde,      // ~1.2.3 → >=1.2.3 <1.3.0
};

struct SemVerRange {
    SemVerRangeKind kind = SemVerRangeKind::ExactOrMin;
    SemVer base;
};

bool parseSemVer(const std::string& version, SemVer& out);
int compareSemVer(const SemVer& a, const SemVer& b);
bool parseSemVerRange(const std::string& required, SemVerRange& out);
bool semverSatisfies(const std::string& required, const std::string& actual);

} // namespace afrilang
