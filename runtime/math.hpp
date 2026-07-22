#pragma once

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <limits>

namespace afrilang::runtime::math {

inline double abs(double value) { return std::fabs(value); }
inline double floor(double value) { return std::floor(value); }
inline double ceil(double value) { return std::ceil(value); }
inline double pow(double base, double exp) { return std::pow(base, exp); }

inline double sqrt(double value) { return std::sqrt(value); }
inline double cbrt(double value) { return std::cbrt(value); }
inline double exp(double value) { return std::exp(value); }
inline double log(double value) { return std::log(value); }
inline double log10(double value) { return std::log10(value); }
inline double log2(double value) { return std::log2(value); }

inline double sin(double value) { return std::sin(value); }
inline double cos(double value) { return std::cos(value); }
inline double tan(double value) { return std::tan(value); }
inline double asin(double value) { return std::asin(value); }
inline double acos(double value) { return std::acos(value); }
inline double atan(double value) { return std::atan(value); }
inline double atan2(double y, double x) { return std::atan2(y, x); }
inline double sinh(double value) { return std::sinh(value); }
inline double cosh(double value) { return std::cosh(value); }
inline double tanh(double value) { return std::tanh(value); }
inline double hypot(double x, double y) { return std::hypot(x, y); }

inline double min(double a, double b) { return std::fmin(a, b); }
inline double max(double a, double b) { return std::fmax(a, b); }
inline double clamp(double value, double lo, double hi) {
    if (lo > hi) std::swap(lo, hi);
    return std::fmin(hi, std::fmax(lo, value));
}
inline double round(double value) { return std::round(value); }
inline double trunc(double value) { return std::trunc(value); }
inline double sign(double value) {
    if (value > 0.0) return 1.0;
    if (value < 0.0) return -1.0;
    return 0.0;
}
inline double deg2rad(double degrees) {
    return degrees * 3.14159265358979323846 / 180.0;
}
inline double rad2deg(double radians) {
    return radians * 180.0 / 3.14159265358979323846;
}

inline double pi() { return 3.14159265358979323846; }
inline double e() { return 2.71828182845904523536; }
inline double tau() { return 6.28318530717958647692; }

inline double random() {
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seeded = true;
    }
    return static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
}

} // namespace afrilang::runtime::math
