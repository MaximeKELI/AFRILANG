#pragma once

#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
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

inline std::tm toUtcTm(double seconds) {
    const std::time_t t = static_cast<std::time_t>(seconds);
    std::tm tm{};
#if defined(_WIN32)
    gmtime_s(&tm, &t);
#else
    gmtime_r(&t, &tm);
#endif
    return tm;
}

inline std::time_t timegmPortable(std::tm* tm) {
#if defined(_WIN32)
    return _mkgmtime(tm);
#else
    return timegm(tm);
#endif
}

// Parse ISO-8601 : "YYYY-MM-DDTHH:MM:SS", suffixe optionnel "Z" ou "+HH:MM" / "-HH:MM".
// Retourne les secondes epoch (UTC), ou -1 si le format minimal n'est pas reconnu.
inline double parseIso(const std::string& text) {
    std::tm tm{};
    int year = 0, month = 0, day = 0, hour = 0, minute = 0, second = 0;
    char sep = 'T';
    const int n = std::sscanf(text.c_str(), "%d-%d-%d%c%d:%d:%d", &year, &month, &day, &sep,
                              &hour, &minute, &second);
    if (n < 3) return -1;
    tm.tm_year = year - 1900;
    tm.tm_mon = month - 1;
    tm.tm_mday = day;
    tm.tm_hour = hour;
    tm.tm_min = minute;
    tm.tm_sec = second;
    std::time_t epoch = timegmPortable(&tm);

    // Décalage de fuseau éventuel en fin de chaîne.
    const std::size_t zPos = text.find_first_of("Zz+", 10);
    std::size_t signPos = std::string::npos;
    for (std::size_t i = 19; i < text.size(); ++i) {
        if (text[i] == '+' || text[i] == '-') { signPos = i; break; }
    }
    if (signPos != std::string::npos) {
        int offH = 0, offM = 0;
        if (std::sscanf(text.c_str() + signPos + 1, "%d:%d", &offH, &offM) >= 1) {
            int offsetMinutes = offH * 60 + offM;
            if (text[signPos] == '+') epoch -= offsetMinutes * 60;
            else epoch += offsetMinutes * 60;
        }
    }
    (void)zPos;
    return static_cast<double>(epoch);
}

inline std::string formatIsoOffset(double seconds, double offsetMinutes) {
    const int offMin = static_cast<int>(offsetMinutes);
    const std::time_t shifted = static_cast<std::time_t>(seconds) + offMin * 60;
    std::tm tm = toUtcTm(static_cast<double>(shifted));
    std::ostringstream out;
    out << std::put_time(&tm, "%Y-%m-%dT%H:%M:%S");
    if (offMin == 0) {
        out << "Z";
    } else {
        const int a = offMin < 0 ? -offMin : offMin;
        out << (offMin < 0 ? '-' : '+') << std::setw(2) << std::setfill('0') << (a / 60)
            << ":" << std::setw(2) << std::setfill('0') << (a % 60);
    }
    return out.str();
}

inline double year(double seconds) { return toUtcTm(seconds).tm_year + 1900; }
inline double month(double seconds) { return toUtcTm(seconds).tm_mon + 1; }
inline double day(double seconds) { return toUtcTm(seconds).tm_mday; }
inline double hour(double seconds) { return toUtcTm(seconds).tm_hour; }
inline double minute(double seconds) { return toUtcTm(seconds).tm_min; }
inline double second(double seconds) { return toUtcTm(seconds).tm_sec; }
inline double weekday(double seconds) { return toUtcTm(seconds).tm_wday; }

inline double addSeconds(double seconds, double delta) { return seconds + delta; }
inline double addDays(double seconds, double days) { return seconds + days * 86400.0; }

} // namespace afrilang::runtime::datetime
