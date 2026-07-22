#pragma once

// AFRILANG core math — API surface aligned with Python math + Nim std/math.
// Clean-room C++ wrappers (no copied source from those projects).

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <limits>
#include <numeric>
#include <vector>

namespace afrilang::runtime::math {

// ---- basics ----
inline double abs(double value) { return std::fabs(value); }
inline double fabs(double value) { return std::fabs(value); }
inline double floor(double value) { return std::floor(value); }
inline double ceil(double value) { return std::ceil(value); }
inline double trunc(double value) { return std::trunc(value); }
inline double round(double value) { return std::round(value); }
inline double roundPlaces(double value, double places) {
    const double p = std::pow(10.0, places);
    return std::round(value * p) / p;
}
inline double pow(double base, double exp) { return std::pow(base, exp); }
inline double sqrt(double value) { return std::sqrt(value); }
inline double cbrt(double value) { return std::cbrt(value); }
inline double isqrt(double n) {
    if (n < 0.0) return std::numeric_limits<double>::quiet_NaN();
    return std::floor(std::sqrt(n));
}

// ---- exp / log ----
inline double exp(double value) { return std::exp(value); }
inline double exp2(double value) { return std::exp2(value); }
inline double expm1(double value) { return std::expm1(value); }
inline double log(double value) { return std::log(value); }
inline double ln(double value) { return std::log(value); }
inline double log1p(double value) { return std::log1p(value); }
inline double log2(double value) { return std::log2(value); }
inline double log10(double value) { return std::log10(value); }
inline double logBase(double value, double base) {
    return std::log(value) / std::log(base);
}

// ---- trig ----
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
inline double asinh(double value) { return std::asinh(value); }
inline double acosh(double value) { return std::acosh(value); }
inline double atanh(double value) { return std::atanh(value); }

// Nim-style aliases
inline double arcsin(double value) { return std::asin(value); }
inline double arccos(double value) { return std::acos(value); }
inline double arctan(double value) { return std::atan(value); }
inline double arctan2(double y, double x) { return std::atan2(y, x); }
inline double arcsinh(double value) { return std::asinh(value); }
inline double arccosh(double value) { return std::acosh(value); }
inline double arctanh(double value) { return std::atanh(value); }

// Reciprocal trig (Nim)
inline double sec(double x) { return 1.0 / std::cos(x); }
inline double csc(double x) { return 1.0 / std::sin(x); }
inline double cot(double x) { return 1.0 / std::tan(x); }
inline double sech(double x) { return 1.0 / std::cosh(x); }
inline double csch(double x) { return 1.0 / std::sinh(x); }
inline double coth(double x) { return 1.0 / std::tanh(x); }
inline double arcsec(double x) { return std::acos(1.0 / x); }
inline double arccsc(double x) { return std::asin(1.0 / x); }
inline double arccot(double x) { return std::atan(1.0 / x); }
inline double arcsech(double x) { return std::acosh(1.0 / x); }
inline double arccsch(double x) { return std::asinh(1.0 / x); }
inline double arccoth(double x) { return std::atanh(1.0 / x); }

inline double hypot(double x, double y) { return std::hypot(x, y); }
inline double hypot3(double x, double y, double z) {
    return std::sqrt(x * x + y * y + z * z);
}

// ---- comparisons / misc ----
inline double min(double a, double b) { return std::fmin(a, b); }
inline double max(double a, double b) { return std::fmax(a, b); }
inline double clamp(double value, double lo, double hi) {
    if (lo > hi) std::swap(lo, hi);
    return std::fmin(hi, std::fmax(lo, value));
}
inline double sign(double value) {
    if (value > 0.0) return 1.0;
    if (value < 0.0) return -1.0;
    return 0.0;
}
inline double sgn(double value) { return sign(value); }
inline bool signbit(double value) { return std::signbit(value); }
inline double deg2rad(double degrees) { return degrees * 3.14159265358979323846 / 180.0; }
inline double rad2deg(double radians) { return radians * 180.0 / 3.14159265358979323846; }
inline double degrees(double radians) { return rad2deg(radians); }
inline double radians(double degrees) { return deg2rad(degrees); }
inline double degToRad(double d) { return deg2rad(d); }
inline double radToDeg(double d) { return rad2deg(d); }
inline double lerp(double a, double b, double t) { return a + (b - a) * t; }
inline double fma(double x, double y, double z) { return std::fma(x, y, z); }
inline double copysign(double mag, double sgn) { return std::copysign(mag, sgn); }
inline double copySign(double x, double y) { return std::copysign(x, y); }
inline double fmod(double x, double y) { return std::fmod(x, y); }
inline double remainder(double x, double y) { return std::remainder(x, y); }
inline double floorDiv(double x, double y) { return std::floor(x / y); }
inline double floorMod(double x, double y) {
    return x - y * std::floor(x / y);
}
inline double euclDiv(double x, double y) { return std::floor(x / y); }
inline double euclMod(double x, double y) { return floorMod(x, y); }

// frexp / modf split into scalar accessors (no tuples in AFRILANG core)
inline double frexpMantissa(double x) {
    int exp = 0;
    return std::frexp(x, &exp);
}
inline double frexpExp(double x) {
    int exp = 0;
    std::frexp(x, &exp);
    return static_cast<double>(exp);
}
inline double ldexp(double x, double i) {
    return std::ldexp(x, static_cast<int>(i));
}
inline double modfInt(double x) {
    double ip = 0.0;
    std::modf(x, &ip);
    return ip;
}
inline double modfFrac(double x) {
    double ip = 0.0;
    return std::modf(x, &ip);
}
inline double nextafter(double x, double y) { return std::nextafter(x, y); }
inline double ulp(double x) {
    if (!std::isfinite(x)) return x;
    return std::nextafter(std::fabs(x), std::numeric_limits<double>::infinity()) - std::fabs(x);
}

// ---- number theory (Python / Nim) ----
inline double gcd(double a, double b) {
    long long x = static_cast<long long>(std::llabs(static_cast<long long>(a)));
    long long y = static_cast<long long>(std::llabs(static_cast<long long>(b)));
    while (y != 0) {
        long long t = x % y;
        x = y;
        y = t;
    }
    return static_cast<double>(x);
}
inline double lcm(double a, double b) {
    long long x = static_cast<long long>(std::llabs(static_cast<long long>(a)));
    long long y = static_cast<long long>(std::llabs(static_cast<long long>(b)));
    if (x == 0 || y == 0) return 0.0;
    return static_cast<double>(x / static_cast<long long>(gcd(static_cast<double>(x), static_cast<double>(y))) * y);
}
inline double factorial(double n) {
    if (n < 0.0) return std::numeric_limits<double>::quiet_NaN();
    if (n > 170.0) return std::numeric_limits<double>::infinity();
    const int k = static_cast<int>(std::floor(n));
    double r = 1.0;
    for (int i = 2; i <= k; ++i) r *= static_cast<double>(i);
    return r;
}
inline double fac(double n) { return factorial(n); }
inline double perm(double n, double k) {
    if (n < 0.0 || k < 0.0 || k > n) return 0.0;
    const int nn = static_cast<int>(std::floor(n));
    const int kk = static_cast<int>(std::floor(k));
    double r = 1.0;
    for (int i = 0; i < kk; ++i) {
        r *= static_cast<double>(nn - i);
        if (!std::isfinite(r)) return std::numeric_limits<double>::infinity();
    }
    return r;
}
inline double comb(double n, double k) {
    if (n < 0.0 || k < 0.0 || k > n) return 0.0;
    const int nn = static_cast<int>(std::floor(n));
    int kk = static_cast<int>(std::floor(k));
    if (kk > nn - kk) kk = nn - kk;
    double r = 1.0;
    for (int i = 1; i <= kk; ++i) {
        r *= static_cast<double>(nn - kk + i);
        r /= static_cast<double>(i);
    }
    return std::round(r);
}
inline double binom(double n, double k) { return comb(n, k); }
inline bool isPowerOfTwo(double x) {
    const long long n = static_cast<long long>(x);
    return n > 0 && (n & (n - 1)) == 0;
}
inline double nextPowerOfTwo(double x) {
    long long n = static_cast<long long>(std::ceil(x));
    if (n <= 1) return 1.0;
    --n;
    n |= n >> 1; n |= n >> 2; n |= n >> 4; n |= n >> 8; n |= n >> 16; n |= n >> 32;
    return static_cast<double>(n + 1);
}

// ---- special ----
inline double erf(double value) { return std::erf(value); }
inline double erfc(double value) { return std::erfc(value); }
inline double gamma(double value) { return std::tgamma(value); }
inline double lgamma(double value) { return std::lgamma(value); }

// ---- classify / compare ----
inline bool isFinite(double value) { return std::isfinite(value); }
inline bool isInf(double value) { return std::isinf(value); }
inline bool isNan(double value) { return std::isnan(value); }
inline bool isNaN(double value) { return std::isnan(value); }
inline bool isClose(double a, double b, double relTol, double absTol) {
    if (std::isnan(a) || std::isnan(b)) return false;
    if (a == b) return true;
    const double diff = std::fabs(a - b);
    return diff <= std::fmax(relTol * std::fmax(std::fabs(a), std::fabs(b)), absTol);
}
inline bool almostEqual(double a, double b) {
    return isClose(a, b, 1e-9, 0.0);
}
// Float class codes (Nim classify): 0=fcNormal 1=fcSubnormal 2=fcZero 3=fcNegZero 4=fcNan 5=fcInf 6=fcNegInf
inline double classify(double x) {
    if (std::isnan(x)) return 4.0;
    if (std::isinf(x)) return x > 0 ? 5.0 : 6.0;
    if (x == 0.0) return std::signbit(x) ? 3.0 : 2.0;
    if (std::fpclassify(x) == FP_SUBNORMAL) return 1.0;
    return 0.0;
}

// ---- constants ----
inline double pi() { return 3.14159265358979323846; }
inline double e() { return 2.71828182845904523536; }
inline double tau() { return 6.28318530717958647692; }
inline double inf() { return std::numeric_limits<double>::infinity(); }
inline double nan() { return std::numeric_limits<double>::quiet_NaN(); }

// ---- list helpers (Python math.fsum / prod / sumprod / dist) ----
inline double fsum(const std::vector<double>& v) {
    double s = 0.0, c = 0.0;
    for (double x : v) {
        const double y = x - c;
        const double t = s + y;
        c = (t - s) - y;
        s = t;
    }
    return s;
}
inline double sum(const std::vector<double>& v) {
    return std::accumulate(v.begin(), v.end(), 0.0);
}
inline double prod(const std::vector<double>& v) {
    double p = 1.0;
    for (double x : v) p *= x;
    return p;
}
inline double sumprod(const std::vector<double>& a, const std::vector<double>& b) {
    const std::size_t n = std::min(a.size(), b.size());
    double s = 0.0;
    for (std::size_t i = 0; i < n; ++i) s += a[i] * b[i];
    return s;
}
inline double dist(const std::vector<double>& p, const std::vector<double>& q) {
    const std::size_t n = std::min(p.size(), q.size());
    double s = 0.0;
    for (std::size_t i = 0; i < n; ++i) {
        const double d = p[i] - q[i];
        s += d * d;
    }
    return std::sqrt(s);
}
inline std::vector<double> cumsummed(const std::vector<double>& v) {
    std::vector<double> r;
    r.reserve(v.size());
    double s = 0.0;
    for (double x : v) { s += x; r.push_back(s); }
    return r;
}
inline std::vector<double> cumproded(const std::vector<double>& v) {
    std::vector<double> r;
    r.reserve(v.size());
    double p = 1.0;
    for (double x : v) { p *= x; r.push_back(p); }
    return r;
}

inline double random() {
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seeded = true;
    }
    return static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
}

} // namespace afrilang::runtime::math
