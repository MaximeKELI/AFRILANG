#pragma once

#include "random.hpp"

#include <cmath>
#include <cstdint>
#include <limits>
#include <random>

namespace afrilang::runtime::proba {

inline double factorial(double n) {
    if (n < 0.0) return std::numeric_limits<double>::quiet_NaN();
    if (n > 170.0) return std::numeric_limits<double>::infinity();
    const int k = static_cast<int>(std::floor(n));
    double r = 1.0;
    for (int i = 2; i <= k; ++i) r *= static_cast<double>(i);
    return r;
}

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
        if (!std::isfinite(r)) return std::numeric_limits<double>::infinity();
    }
    return std::round(r);
}

inline double normalPdf(double x, double mu, double sigma) {
    if (sigma <= 0.0) return 0.0;
    const double z = (x - mu) / sigma;
    const double inv = 1.0 / (sigma * std::sqrt(2.0 * 3.14159265358979323846));
    return inv * std::exp(-0.5 * z * z);
}

// Abramowitz & Stegun 7.1.26 approximation via erf
inline double normalCdf(double x, double mu, double sigma) {
    if (sigma <= 0.0) return x < mu ? 0.0 : 1.0;
    const double z = (x - mu) / (sigma * std::sqrt(2.0));
    return 0.5 * (1.0 + std::erf(z));
}

// Acklam's inverse normal CDF approximation for standard normal, then scale
inline double normalInv(double p, double mu, double sigma) {
    if (p <= 0.0) return -std::numeric_limits<double>::infinity();
    if (p >= 1.0) return std::numeric_limits<double>::infinity();
    if (sigma <= 0.0) return mu;

    static const double a1 = -3.969683028665376e+01;
    static const double a2 = 2.209460984245205e+02;
    static const double a3 = -2.759687906487785e+02;
    static const double a4 = 1.383577518672690e+02;
    static const double a5 = -3.066479806614716e+01;
    static const double a6 = 2.506628277459239e+00;

    static const double b1 = -5.447609879822406e+01;
    static const double b2 = 1.615858368580409e+02;
    static const double b3 = -1.556989798598866e+02;
    static const double b4 = 6.680131188771972e+01;
    static const double b5 = -1.328068155288572e+01;

    static const double c1 = -7.784894002430293e-03;
    static const double c2 = -3.223964580411365e-01;
    static const double c3 = -2.400758277161838e+00;
    static const double c4 = -2.549732539343734e+00;
    static const double c5 = 4.374664141464858e+00;
    static const double c6 = 2.938163982698783e+00;

    static const double d1 = 7.784695709041462e-03;
    static const double d2 = 3.224671290700398e-01;
    static const double d3 = 2.445134137142996e+00;
    static const double d4 = 3.754408661907416e+00;

    const double plow = 0.02425;
    const double phigh = 1.0 - plow;
    double q, r, x;

    if (p < plow) {
        q = std::sqrt(-2.0 * std::log(p));
        x = (((((c1 * q + c2) * q + c3) * q + c4) * q + c5) * q + c6) /
            ((((d1 * q + d2) * q + d3) * q + d4) * q + 1.0);
    } else if (p <= phigh) {
        q = p - 0.5;
        r = q * q;
        x = (((((a1 * r + a2) * r + a3) * r + a4) * r + a5) * r + a6) * q /
            (((((b1 * r + b2) * r + b3) * r + b4) * r + b5) * r + 1.0);
    } else {
        q = std::sqrt(-2.0 * std::log(1.0 - p));
        x = -(((((c1 * q + c2) * q + c3) * q + c4) * q + c5) * q + c6) /
            ((((d1 * q + d2) * q + d3) * q + d4) * q + 1.0);
    }
    return mu + sigma * x;
}

inline double uniformPdf(double x, double lo, double hi) {
    if (lo > hi) std::swap(lo, hi);
    if (hi == lo) return 0.0;
    if (x < lo || x > hi) return 0.0;
    return 1.0 / (hi - lo);
}

inline double uniformCdf(double x, double lo, double hi) {
    if (lo > hi) std::swap(lo, hi);
    if (hi == lo) return x < lo ? 0.0 : 1.0;
    if (x <= lo) return 0.0;
    if (x >= hi) return 1.0;
    return (x - lo) / (hi - lo);
}

inline double exponentialPdf(double x, double rate) {
    if (rate <= 0.0 || x < 0.0) return 0.0;
    return rate * std::exp(-rate * x);
}

inline double exponentialCdf(double x, double rate) {
    if (rate <= 0.0) return 0.0;
    if (x < 0.0) return 0.0;
    return 1.0 - std::exp(-rate * x);
}

inline double binomialPdf(double k, double n, double p) {
    if (p < 0.0 || p > 1.0) return 0.0;
    const int kk = static_cast<int>(std::floor(k));
    const int nn = static_cast<int>(std::floor(n));
    if (kk < 0 || kk > nn) return 0.0;
    return comb(nn, kk) * std::pow(p, kk) * std::pow(1.0 - p, nn - kk);
}

inline double binomialCdf(double k, double n, double p) {
    const int kk = static_cast<int>(std::floor(k));
    const int nn = static_cast<int>(std::floor(n));
    if (kk < 0) return 0.0;
    if (kk >= nn) return 1.0;
    double s = 0.0;
    for (int i = 0; i <= kk; ++i) {
        s += binomialPdf(static_cast<double>(i), static_cast<double>(nn), p);
    }
    return s;
}

inline double poissonPdf(double k, double lambda) {
    if (lambda < 0.0) return 0.0;
    const int kk = static_cast<int>(std::floor(k));
    if (kk < 0) return 0.0;
    // Use log-space for stability: exp(k*log(λ) - λ - log(k!))
    double logFact = 0.0;
    for (int i = 2; i <= kk; ++i) logFact += std::log(static_cast<double>(i));
    return std::exp(static_cast<double>(kk) * std::log(lambda) - lambda - logFact);
}

inline double poissonCdf(double k, double lambda) {
    const int kk = static_cast<int>(std::floor(k));
    if (kk < 0) return 0.0;
    double s = 0.0;
    for (int i = 0; i <= kk; ++i) {
        s += poissonPdf(static_cast<double>(i), lambda);
    }
    return s;
}

inline void seed(std::int64_t value) {
    random_::seed(value);
}

inline double sampleUniform(double lo, double hi) {
    if (lo > hi) std::swap(lo, hi);
    std::uniform_real_distribution<double> dist(lo, hi);
    return dist(random_::engine());
}

inline double sampleNormal(double mu, double sigma) {
    if (sigma < 0.0) sigma = -sigma;
    if (sigma == 0.0) return mu;
    std::normal_distribution<double> dist(mu, sigma);
    return dist(random_::engine());
}

inline double sampleBernoulli(double p) {
    if (p <= 0.0) return 0.0;
    if (p >= 1.0) return 1.0;
    std::bernoulli_distribution dist(p);
    return dist(random_::engine()) ? 1.0 : 0.0;
}

inline double sampleBinomial(double n, double p) {
    const int nn = static_cast<int>(std::floor(n));
    if (nn <= 0) return 0.0;
    if (p <= 0.0) return 0.0;
    if (p >= 1.0) return static_cast<double>(nn);
    std::binomial_distribution<int> dist(nn, p);
    return static_cast<double>(dist(random_::engine()));
}

inline double samplePoisson(double lambda) {
    if (lambda <= 0.0) return 0.0;
    std::poisson_distribution<int> dist(lambda);
    return static_cast<double>(dist(random_::engine()));
}

inline double sampleExponential(double rate) {
    if (rate <= 0.0) return 0.0;
    std::exponential_distribution<double> dist(rate);
    return dist(random_::engine());
}

} // namespace afrilang::runtime::proba
