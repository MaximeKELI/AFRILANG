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

// --- Fuseaux nommés (table statique) --------------------------------------
// Zéro-dépendance : offsets STANDARD (heure d'hiver), sans passage automatique
// à l'heure d'été (DST). Pour un décalage exact avec DST, utiliser
// formatIsoOffset avec l'offset voulu. Sentinelle -100000 si zone inconnue.
inline constexpr double kUnknownZone = -100000.0;

inline double zoneOffset(const std::string& name) {
    struct Zone { const char* name; int minutes; };
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
        if (name == z.name) return static_cast<double>(z.minutes);
    }
    return kUnknownZone;
}

// Formate un instant epoch dans une zone nommée (offset standard). Chaîne vide
// si la zone est inconnue.
inline std::string formatInZone(double seconds, const std::string& zoneName) {
    const double off = zoneOffset(zoneName);
    if (off == kUnknownZone) return {};
    return formatIsoOffset(seconds, off);
}

} // namespace afrilang::runtime::datetime
