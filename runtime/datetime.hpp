#pragma once

#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <mutex>
#include <sstream>
#include <string>
#include <unistd.h>

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

// --- Fuseaux nommés -------------------------------------------------------
// Native (non-WASM) : offsets via zoneinfo POSIX (TZ / localtime_r / tm_gmtoff),
// donc DST inclus pour les zones IANA installées sur le système.
// WASM / fallback : table d'offsets STANDARD (hiver) sans DST.
inline constexpr double kUnknownZone = -100000.0;

inline double zoneOffsetStandard(const std::string& zoneName) {
    struct Zone { const char* id; int minutes; };
    static const Zone zones[] = {
        {"UTC", 0}, {"GMT", 0}, {"Z", 0},
        {"Europe/London", 0}, {"Europe/Lisbon", 0},
        {"Europe/Paris", 60}, {"Europe/Berlin", 60}, {"Europe/Madrid", 60},
        {"Europe/Rome", 60}, {"Europe/Brussels", 60}, {"Europe/Amsterdam", 60},
        {"Europe/Zurich", 60}, {"Europe/Warsaw", 60},
        {"Europe/Athens", 120}, {"Europe/Helsinki", 120}, {"Europe/Bucharest", 120},
        {"Europe/Kiev", 120}, {"Europe/Moscow", 180}, {"Europe/Istanbul", 180},
        {"Africa/Casablanca", 0}, {"Africa/Lagos", 60}, {"Africa/Cairo", 120},
        {"Africa/Johannesburg", 120}, {"Africa/Nairobi", 180},
        {"Asia/Jerusalem", 120}, {"Asia/Dubai", 240}, {"Asia/Karachi", 300},
        {"Asia/Kolkata", 330}, {"Asia/Dhaka", 360}, {"Asia/Bangkok", 420},
        {"Asia/Shanghai", 480}, {"Asia/Singapore", 480}, {"Asia/Hong_Kong", 480},
        {"Asia/Tokyo", 540}, {"Asia/Seoul", 540},
        {"Australia/Sydney", 600}, {"Pacific/Auckland", 720},
        {"America/Sao_Paulo", -180}, {"America/New_York", -300},
        {"America/Toronto", -300}, {"America/Chicago", -360},
        {"America/Denver", -420}, {"America/Los_Angeles", -480},
        {"America/Anchorage", -540}, {"Pacific/Honolulu", -600},
    };
    for (const auto& z : zones) {
        if (zoneName == z.id) return static_cast<double>(z.minutes);
    }
    return kUnknownZone;
}

#if !defined(AFRILANG_WASM)
inline std::mutex& tzMutex() {
    static std::mutex m;
    return m;
}

// Offset minutes east of UTC at the given epoch, using system zoneinfo.
inline double zoneOffsetAt(const std::string& zoneName, double seconds) {
    if (zoneName == "UTC" || zoneName == "GMT" || zoneName == "Z") return 0;
    const double known = zoneOffsetStandard(zoneName);
    const std::string ziPath = "/usr/share/zoneinfo/" + zoneName;
    const bool onDisk = access(ziPath.c_str(), R_OK) == 0;
    if (!onDisk && known == kUnknownZone) return kUnknownZone;

    std::lock_guard<std::mutex> lock(tzMutex());
    const char* old = std::getenv("TZ");
    std::string oldTz = old ? old : "";
    setenv("TZ", zoneName.c_str(), 1);
    tzset();
    const std::time_t t = static_cast<std::time_t>(seconds);
    std::tm tm{};
    localtime_r(&t, &tm);
#if defined(__linux__) || defined(__APPLE__)
    const long offSec = tm.tm_gmtoff;
#else
    std::tm utc = toUtcTm(seconds);
    utc.tm_isdst = -1;
    const std::time_t asLocal = std::mktime(&utc);
    const long offSec = static_cast<long>(t - asLocal);
#endif
    if (old) setenv("TZ", oldTz.c_str(), 1);
    else unsetenv("TZ");
    tzset();
    return static_cast<double>(offSec / 60);
}
#else
inline double zoneOffsetAt(const std::string& zoneName, double /*seconds*/) {
    return zoneOffsetStandard(zoneName);
}
#endif

// Offset at "now" (native DST-aware). On WASM: standard winter table.
inline double zoneOffset(const std::string& zoneName) {
#if !defined(AFRILANG_WASM)
    const double at = zoneOffsetAt(zoneName, nowSeconds());
    if (at != kUnknownZone) return at;
#endif
    return zoneOffsetStandard(zoneName);
}

// Formate un instant epoch dans une zone nommée (DST-aware native). Chaîne vide
// si la zone est inconnue.
inline std::string formatInZone(double seconds, const std::string& zoneName) {
    const double off = zoneOffsetAt(zoneName, seconds);
    if (off == kUnknownZone) return {};
    return formatIsoOffset(seconds, off);
}

} // namespace afrilang::runtime::datetime
