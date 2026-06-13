#pragma once

#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <string>

namespace afrilang::runtime::time {

inline double now() {
    using Clock = std::chrono::system_clock;
    return static_cast<double>(
        std::chrono::duration_cast<std::chrono::seconds>(Clock::now().time_since_epoch()).count());
}

inline std::string formatTimestamp(double seconds) {
    const std::time_t t = static_cast<std::time_t>(seconds);
    std::tm tm{};
#if defined(_WIN32)
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif
    std::ostringstream out;
    out << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return out.str();
}

} // namespace afrilang::runtime::time
