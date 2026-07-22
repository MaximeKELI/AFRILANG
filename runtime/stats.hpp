#pragma once

#include <algorithm>
#include <cmath>
#include <cstddef>
#include <map>
#include <numeric>
#include <vector>

namespace afrilang::runtime::stats {

inline double count(const std::vector<double>& v) {
    return static_cast<double>(v.size());
}

inline double sum(const std::vector<double>& v) {
    if (v.empty()) return 0.0;
    return std::accumulate(v.begin(), v.end(), 0.0);
}

inline double mean(const std::vector<double>& v) {
    if (v.empty()) return 0.0;
    return sum(v) / static_cast<double>(v.size());
}

inline double minVal(const std::vector<double>& v) {
    if (v.empty()) return 0.0;
    return *std::min_element(v.begin(), v.end());
}

inline double maxVal(const std::vector<double>& v) {
    if (v.empty()) return 0.0;
    return *std::max_element(v.begin(), v.end());
}

inline double range(const std::vector<double>& v) {
    if (v.empty()) return 0.0;
    return maxVal(v) - minVal(v);
}

inline double median(std::vector<double> v) {
    if (v.empty()) return 0.0;
    std::sort(v.begin(), v.end());
    const std::size_t n = v.size();
    if (n % 2 == 1) return v[n / 2];
    return (v[n / 2 - 1] + v[n / 2]) / 2.0;
}

inline double mode(const std::vector<double>& v) {
    if (v.empty()) return 0.0;
    std::map<long long, int> freq;
    for (double x : v) {
        ++freq[static_cast<long long>(std::llround(x * 1000.0))];
    }
    auto it = std::max_element(freq.begin(), freq.end(),
                               [](const auto& a, const auto& b) {
                                   return a.second < b.second;
                               });
    return static_cast<double>(it->first) / 1000.0;
}

inline double popVariance(const std::vector<double>& v) {
    if (v.empty()) return 0.0;
    const double m = mean(v);
    double s = 0.0;
    for (double x : v) {
        const double d = x - m;
        s += d * d;
    }
    return s / static_cast<double>(v.size());
}

inline double popStddev(const std::vector<double>& v) {
    return std::sqrt(popVariance(v));
}

inline double variance(const std::vector<double>& v) {
    if (v.size() < 2) return 0.0;
    const double m = mean(v);
    double s = 0.0;
    for (double x : v) {
        const double d = x - m;
        s += d * d;
    }
    return s / static_cast<double>(v.size() - 1);
}

inline double stddev(const std::vector<double>& v) {
    return std::sqrt(variance(v));
}

inline double quantile(std::vector<double> v, double q) {
    if (v.empty()) return 0.0;
    if (q < 0.0) q = 0.0;
    if (q > 1.0) q = 1.0;
    std::sort(v.begin(), v.end());
    if (v.size() == 1) return v[0];
    const double pos = q * static_cast<double>(v.size() - 1);
    const std::size_t i = static_cast<std::size_t>(pos);
    const double f = pos - static_cast<double>(i);
    if (i + 1 < v.size()) return v[i] * (1.0 - f) + v[i + 1] * f;
    return v[i];
}

inline double percentile(const std::vector<double>& v, double p) {
    return quantile(v, p / 100.0);
}

inline double q1(const std::vector<double>& v) { return quantile(v, 0.25); }
inline double q3(const std::vector<double>& v) { return quantile(v, 0.75); }
inline double iqr(const std::vector<double>& v) { return q3(v) - q1(v); }

inline double skewness(const std::vector<double>& v) {
    if (v.size() < 3) return 0.0;
    const double m = mean(v);
    double m2 = 0.0;
    double m3 = 0.0;
    for (double x : v) {
        const double d = x - m;
        m2 += d * d;
        m3 += d * d * d;
    }
    const double n = static_cast<double>(v.size());
    m2 /= n;
    m3 /= n;
    if (m2 <= 0.0) return 0.0;
    return m3 / std::pow(m2, 1.5);
}

inline double kurtosis(const std::vector<double>& v) {
    if (v.size() < 4) return 0.0;
    const double m = mean(v);
    double m2 = 0.0;
    double m4 = 0.0;
    for (double x : v) {
        const double d = x - m;
        const double d2 = d * d;
        m2 += d2;
        m4 += d2 * d2;
    }
    const double n = static_cast<double>(v.size());
    m2 /= n;
    m4 /= n;
    if (m2 <= 0.0) return 0.0;
    // Excess kurtosis
    return m4 / (m2 * m2) - 3.0;
}

inline double covariance(const std::vector<double>& a, const std::vector<double>& b) {
    if (a.size() != b.size() || a.size() < 2) return 0.0;
    const double ma = mean(a);
    const double mb = mean(b);
    double s = 0.0;
    for (std::size_t i = 0; i < a.size(); ++i) {
        s += (a[i] - ma) * (b[i] - mb);
    }
    return s / static_cast<double>(a.size() - 1);
}

inline double correlation(const std::vector<double>& a, const std::vector<double>& b) {
    const double sa = stddev(a);
    const double sb = stddev(b);
    if (sa == 0.0 || sb == 0.0) return 0.0;
    return covariance(a, b) / (sa * sb);
}

inline std::vector<double> cumSum(const std::vector<double>& v) {
    std::vector<double> r;
    r.reserve(v.size());
    double s = 0.0;
    for (double x : v) {
        s += x;
        r.push_back(s);
    }
    return r;
}

inline std::vector<double> zScores(const std::vector<double>& v) {
    if (v.empty()) return {};
    const double m = mean(v);
    const double s = stddev(v);
    if (s == 0.0) return v;
    std::vector<double> r;
    r.reserve(v.size());
    for (double x : v) r.push_back((x - m) / s);
    return r;
}

inline std::vector<double> histogram(const std::vector<double>& v, double bins) {
    if (v.empty()) return {};
    int b = static_cast<int>(bins);
    if (b <= 0) return {};
    const double mn = minVal(v);
    const double mx = maxVal(v);
    double w = (mx - mn) / static_cast<double>(b);
    if (w == 0.0) return std::vector<double>(static_cast<std::size_t>(b),
                                             static_cast<double>(v.size()));
    std::vector<double> r(static_cast<std::size_t>(b), 0.0);
    for (double x : v) {
        int i = static_cast<int>((x - mn) / w);
        if (i >= b) i = b - 1;
        if (i < 0) i = 0;
        r[static_cast<std::size_t>(i)] += 1.0;
    }
    return r;
}

} // namespace afrilang::runtime::stats
