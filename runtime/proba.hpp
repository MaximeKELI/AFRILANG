#pragma once

#include "random.hpp"

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <limits>
#include <numeric>
#include <random>
#include <vector>

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

inline double normalCdf(double x, double mu, double sigma) {
    if (sigma <= 0.0) return x < mu ? 0.0 : 1.0;
    const double z = (x - mu) / (sigma * std::sqrt(2.0));
    return 0.5 * (1.0 + std::erf(z));
}

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

// Geometric: number of failures before first success (Python / R style, support 0,1,2,...)
inline double geometricPdf(double k, double p) {
    if (p <= 0.0 || p > 1.0) return 0.0;
    const int kk = static_cast<int>(std::floor(k));
    if (kk < 0) return 0.0;
    return p * std::pow(1.0 - p, kk);
}

inline double geometricCdf(double k, double p) {
    if (p <= 0.0 || p > 1.0) return 0.0;
    const int kk = static_cast<int>(std::floor(k));
    if (kk < 0) return 0.0;
    return 1.0 - std::pow(1.0 - p, kk + 1);
}

inline double logNormalPdf(double x, double mu, double sigma) {
    if (x <= 0.0 || sigma <= 0.0) return 0.0;
    const double z = (std::log(x) - mu) / sigma;
    return (1.0 / (x * sigma * std::sqrt(2.0 * 3.14159265358979323846))) *
           std::exp(-0.5 * z * z);
}

inline double logNormalCdf(double x, double mu, double sigma) {
    if (x <= 0.0) return 0.0;
    return normalCdf(std::log(x), mu, sigma);
}

// Gamma(shape, rate) — rate parameterization (Python scipy / R)
inline double gammaPdf(double x, double shape, double rate) {
    if (x < 0.0 || shape <= 0.0 || rate <= 0.0) return 0.0;
    if (x == 0.0) return shape < 1.0 ? std::numeric_limits<double>::infinity()
                                    : (shape == 1.0 ? rate : 0.0);
    return std::exp(shape * std::log(rate) + (shape - 1.0) * std::log(x) -
                    rate * x - std::lgamma(shape));
}

inline double gammaCdf(double x, double shape, double rate) {
    if (x <= 0.0) return 0.0;
    if (shape <= 0.0 || rate <= 0.0) return 0.0;
    // Lower incomplete gamma via series for moderate values
    const double a = shape;
    const double z = rate * x;
    if (z < a + 1.0) {
        double sum = 1.0 / a;
        double term = sum;
        for (int n = 1; n < 200; ++n) {
            term *= z / (a + n);
            sum += term;
            if (std::fabs(term) < 1e-12 * std::fabs(sum)) break;
        }
        return sum * std::exp(-z + a * std::log(z) - std::lgamma(a));
    }
    // Continued fraction for upper incomplete, then 1 - Q
    double b = z + 1.0 - a;
    double c = 1e30;
    double d = 1.0 / b;
    double h = d;
    for (int i = 1; i <= 200; ++i) {
        const double an = -i * (i - a);
        b += 2.0;
        d = an * d + b;
        if (std::fabs(d) < 1e-30) d = 1e-30;
        c = b + an / c;
        if (std::fabs(c) < 1e-30) c = 1e-30;
        d = 1.0 / d;
        const double delta = d * c;
        h *= delta;
        if (std::fabs(delta - 1.0) < 1e-12) break;
    }
    const double q = std::exp(-z + a * std::log(z) - std::lgamma(a)) * h;
    return 1.0 - q;
}

inline double chiSquarePdf(double x, double k) {
    return gammaPdf(x, k / 2.0, 0.5);
}

inline double chiSquareCdf(double x, double k) {
    return gammaCdf(x, k / 2.0, 0.5);
}

inline double studentTPdf(double x, double nu) {
    if (nu <= 0.0) return 0.0;
    const double half = (nu + 1.0) / 2.0;
    const double c = std::exp(std::lgamma(half) - std::lgamma(nu / 2.0)) /
                     (std::sqrt(nu * 3.14159265358979323846));
    return c * std::pow(1.0 + (x * x) / nu, -half);
}

// Approximate Student-t CDF via Hill's approximation (adequate for tests / teaching)
inline double studentTCdf(double x, double nu) {
    if (nu <= 0.0) return 0.0;
    if (nu > 1e8) return normalCdf(x, 0.0, 1.0);
    // Relation to incomplete beta: P(T<=x) = 1 - 0.5 * I_{nu/(nu+x^2)}(nu/2, 1/2) for x>0
    // Use gamma CDF of F = T^2 when possible via chi-square approx for large nu
    const double z = x;
    // Simple series for small |x|, else map through normal with correction
    const double a = nu / 2.0;
    const double xx = nu / (nu + z * z);
    // Regularized incomplete beta I_x(a, 0.5) via continued fraction (Abramowitz)
    auto betacf = [](double aa, double bb, double xxv) {
        const double qab = aa + bb;
        const double qap = aa + 1.0;
        const double qam = aa - 1.0;
        double c = 1.0;
        double d = 1.0 - qab * xxv / qap;
        if (std::fabs(d) < 1e-30) d = 1e-30;
        d = 1.0 / d;
        double h = d;
        for (int m = 1; m <= 200; ++m) {
            const int m2 = 2 * m;
            double aa2 = m * (bb - m) * xxv / ((qam + m2) * (aa + m2));
            d = 1.0 + aa2 * d;
            if (std::fabs(d) < 1e-30) d = 1e-30;
            c = 1.0 + aa2 / c;
            if (std::fabs(c) < 1e-30) c = 1e-30;
            d = 1.0 / d;
            h *= d * c;
            aa2 = -(aa + m) * (qab + m) * xxv / ((aa + m2) * (qap + m2));
            d = 1.0 + aa2 * d;
            if (std::fabs(d) < 1e-30) d = 1e-30;
            c = 1.0 + aa2 / c;
            if (std::fabs(c) < 1e-30) c = 1e-30;
            d = 1.0 / d;
            const double del = d * c;
            h *= del;
            if (std::fabs(del - 1.0) < 1e-10) break;
        }
        return h;
    };
    const double bt = std::exp(std::lgamma(a + 0.5) - std::lgamma(a) - std::lgamma(0.5) +
                               a * std::log(xx) + 0.5 * std::log(std::fmax(1.0 - xx, 1e-300)));
    double ib;
    if (xx < (a + 1.0) / (a + 1.5)) {
        ib = bt * betacf(a, 0.5, xx) / a;
    } else {
        ib = 1.0 - bt * betacf(0.5, a, 1.0 - xx) / 0.5;
    }
    if (z >= 0.0) return 1.0 - 0.5 * ib;
    return 0.5 * ib;
}

inline void seed(std::int64_t value) {
    random_::seed(value);
}

inline double sampleUniform(double lo, double hi) {
    if (lo > hi) std::swap(lo, hi);
    std::uniform_real_distribution<double> dist(lo, hi);
    return dist(random_::engine());
}

inline double sampleInt(double lo, double hi) {
    std::int64_t a = static_cast<std::int64_t>(std::floor(lo));
    std::int64_t b = static_cast<std::int64_t>(std::floor(hi));
    if (a > b) std::swap(a, b);
    std::uniform_int_distribution<std::int64_t> dist(a, b);
    return static_cast<double>(dist(random_::engine()));
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

inline double sampleGeometric(double p) {
    if (p <= 0.0) return std::numeric_limits<double>::infinity();
    if (p >= 1.0) return 0.0;
    std::geometric_distribution<int> dist(p);
    return static_cast<double>(dist(random_::engine()));
}

inline double sampleLogNormal(double mu, double sigma) {
    if (sigma < 0.0) sigma = -sigma;
    if (sigma == 0.0) return std::exp(mu);
    std::lognormal_distribution<double> dist(mu, sigma);
    return dist(random_::engine());
}

inline double sampleGamma(double shape, double rate) {
    if (shape <= 0.0 || rate <= 0.0) return 0.0;
    // std::gamma_distribution uses scale = 1/rate
    std::gamma_distribution<double> dist(shape, 1.0 / rate);
    return dist(random_::engine());
}

inline double sampleChoice(const std::vector<double>& v) {
    if (v.empty()) return 0.0;
    std::uniform_int_distribution<std::size_t> dist(0, v.size() - 1);
    return v[dist(random_::engine())];
}

inline std::vector<double> sampleShuffle(std::vector<double> v) {
    std::shuffle(v.begin(), v.end(), random_::engine());
    return v;
}

inline std::vector<double> sampleN(const std::vector<double>& v, double n) {
    std::vector<double> r;
    const int count = static_cast<int>(std::floor(n));
    if (count <= 0 || v.empty()) return r;
    r.reserve(static_cast<std::size_t>(count));
    for (int i = 0; i < count; ++i) r.push_back(sampleChoice(v));
    return r;
}

// ---- Python random module surface (clean-room) ----
inline void randomize() {
    random_::seed(static_cast<std::int64_t>(
        std::chrono::high_resolution_clock::now().time_since_epoch().count()));
}
inline double rand(double maxValue) {
    if (maxValue <= 0.0) return 0.0;
    return sampleUniform(0.0, maxValue);
}
inline double randint(double a, double b) { return sampleInt(a, b); }
inline double randrange(double start, double stop) {
    // Python randrange(start, stop) → [start, stop)
    std::int64_t lo = static_cast<std::int64_t>(std::floor(start));
    std::int64_t hi = static_cast<std::int64_t>(std::floor(stop)) - 1;
    if (hi < lo) return static_cast<double>(lo);
    return sampleInt(static_cast<double>(lo), static_cast<double>(hi));
}
inline double gauss(double mu, double sigma) { return sampleNormal(mu, sigma); }
inline double normalvariate(double mu, double sigma) { return sampleNormal(mu, sigma); }
inline double lognormvariate(double mu, double sigma) { return sampleLogNormal(mu, sigma); }
inline double expovariate(double lambd) { return sampleExponential(lambd); }
inline double gammavariate(double alpha, double beta) {
    // Python: beta is scale; our sampleGamma uses rate = 1/scale
    if (beta <= 0.0) return 0.0;
    return sampleGamma(alpha, 1.0 / beta);
}

inline double sampleTriangular(double low, double high, double mode) {
    if (low > high) std::swap(low, high);
    // Inverse CDF
    const double u = sampleUniform(0.0, 1.0);
    const double c = (mode - low) / (high - low);
    if (u < c) return low + std::sqrt(u * (high - low) * (mode - low));
    return high - std::sqrt((1.0 - u) * (high - low) * (high - mode));
}

inline double sampleBeta(double alpha, double beta) {
    if (alpha <= 0.0 || beta <= 0.0) return 0.0;
    const double x = sampleGamma(alpha, 1.0);
    const double y = sampleGamma(beta, 1.0);
    const double s = x + y;
    return s == 0.0 ? 0.0 : x / s;
}
inline double betavariate(double alpha, double beta) { return sampleBeta(alpha, beta); }

inline double sampleWeibull(double alpha, double beta) {
    // Python weibullvariate(alpha, beta): alpha=scale, beta=shape
    if (alpha <= 0.0 || beta <= 0.0) return 0.0;
    const double u = sampleUniform(0.0, 1.0);
    return alpha * std::pow(-std::log(u), 1.0 / beta);
}
inline double weibullvariate(double alpha, double beta) { return sampleWeibull(alpha, beta); }

inline double samplePareto(double alpha) {
    if (alpha <= 0.0) return 0.0;
    const double u = sampleUniform(0.0, 1.0);
    return 1.0 / std::pow(u, 1.0 / alpha);
}
inline double paretovariate(double alpha) { return samplePareto(alpha); }

inline double sampleVonMises(double mu, double kappa) {
    if (kappa <= 1e-6) return sampleUniform(mu - 3.14159265358979323846,
                                            mu + 3.14159265358979323846);
    // Best–Fisher algorithm
    const double a = 1.0 + std::sqrt(1.0 + 4.0 * kappa * kappa);
    const double b = (a - std::sqrt(2.0 * a)) / (2.0 * kappa);
    const double r = (1.0 + b * b) / (2.0 * b);
    while (true) {
        const double u1 = sampleUniform(0.0, 1.0);
        const double z = std::cos(3.14159265358979323846 * u1);
        const double f = (1.0 + r * z) / (r + z);
        const double c = kappa * (r - f);
        const double u2 = sampleUniform(0.0, 1.0);
        if (u2 < c * (2.0 - c) || u2 <= c * std::exp(1.0 - c)) {
            const double u3 = sampleUniform(0.0, 1.0);
            return u3 > 0.5 ? mu + std::acos(f) : mu - std::acos(f);
        }
    }
}
inline double vonmisesvariate(double mu, double kappa) { return sampleVonMises(mu, kappa); }

inline double weibullPdf(double x, double shape, double scale) {
    if (x < 0.0 || shape <= 0.0 || scale <= 0.0) return 0.0;
    const double z = x / scale;
    return (shape / scale) * std::pow(z, shape - 1.0) * std::exp(-std::pow(z, shape));
}
inline double weibullCdf(double x, double shape, double scale) {
    if (x < 0.0) return 0.0;
    if (shape <= 0.0 || scale <= 0.0) return 0.0;
    return 1.0 - std::exp(-std::pow(x / scale, shape));
}
inline double betaPdf(double x, double a, double b) {
    if (x <= 0.0 || x >= 1.0 || a <= 0.0 || b <= 0.0) return 0.0;
    const double B = std::exp(std::lgamma(a) + std::lgamma(b) - std::lgamma(a + b));
    return std::pow(x, a - 1.0) * std::pow(1.0 - x, b - 1.0) / B;
}
inline double paretoPdf(double x, double alpha) {
    if (x < 1.0 || alpha <= 0.0) return 0.0;
    return alpha / std::pow(x, alpha + 1.0);
}
inline double paretoCdf(double x, double alpha) {
    if (x < 1.0) return 0.0;
    if (alpha <= 0.0) return 0.0;
    return 1.0 - std::pow(x, -alpha);
}

inline std::vector<double> sampleWeighted(const std::vector<double>& v,
                                          const std::vector<double>& weights,
                                          double k) {
    std::vector<double> r;
    const int n = static_cast<int>(std::floor(k));
    if (n <= 0 || v.empty() || v.size() != weights.size()) return r;
    double total = 0.0;
    for (double w : weights) total += std::fmax(0.0, w);
    if (total <= 0.0) return sampleN(v, k);
    for (int i = 0; i < n; ++i) {
        double u = sampleUniform(0.0, total);
        for (std::size_t j = 0; j < v.size(); ++j) {
            u -= std::fmax(0.0, weights[j]);
            if (u <= 0.0) {
                r.push_back(v[j]);
                break;
            }
        }
        if (r.size() == static_cast<std::size_t>(i)) r.push_back(v.back());
    }
    return r;
}

inline std::vector<double> sampleWithoutReplacement(std::vector<double> v, double k) {
    const int n = static_cast<int>(std::floor(k));
    if (n <= 0) return {};
    if (static_cast<std::size_t>(n) >= v.size()) {
        std::shuffle(v.begin(), v.end(), random_::engine());
        return v;
    }
    std::shuffle(v.begin(), v.end(), random_::engine());
    v.resize(static_cast<std::size_t>(n));
    return v;
}

inline double sampleCdf(const std::vector<double>& v, const std::vector<double>& cdf) {
    if (v.empty() || v.size() != cdf.size()) return 0.0;
    const double u = sampleUniform(0.0, cdf.back());
    for (std::size_t i = 0; i < cdf.size(); ++i) {
        if (u <= cdf[i]) return v[i];
    }
    return v.back();
}

} // namespace afrilang::runtime::proba
