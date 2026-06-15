#pragma once

#include <chrono>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

namespace afrilang::runtime::datetime {

inline double nowSeconds() {
    using Clock = std::chrono::system_clock;
    return static_cast<double>(
        std::chrono::duration_cast<std::chrono::seconds>(Clock::now().time_since_epoch()).count());
}

inline std::int64_t nowMs() {
    using Clock = std::chrono::system_clock;
    return std::chrono::duration_cast<std::chrono::milliseconds>(
               Clock::now().time_since_epoch())
        .count();
}

inline std::string formatIso(double seconds) {
    const std::time_t t = static_cast<std::time_t>(seconds);
    std::tm tm{};
#if defined(_WIN32)
    gmtime_s(&tm, &t);
#else
    gmtime_r(&t, &tm);
#endif
    std::ostringstream out;
    out << std::put_time(&tm, "%Y-%m-%dT%H:%M:%SZ");
    return out.str();
}

inline double diffSeconds(double a, double b) {
    return std::fabs(a - b);
}

} // namespace afrilang::runtime::datetime
