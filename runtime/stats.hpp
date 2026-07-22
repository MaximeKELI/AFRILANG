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

// Python math.fsum — Kahan compensated summation
inline double fsum(const std::vector<double>& v) {
    double s = 0.0;
    double c = 0.0;
    for (double x : v) {
        const double y = x - c;
        const double t = s + y;
        c = (t - s) - y;
        s = t;
    }
    return s;
}

inline double product(const std::vector<double>& v) {
    if (v.empty()) return 1.0;
    double p = 1.0;
    for (double x : v) p *= x;
    return p;
}

inline double mean(const std::vector<double>& v) {
    if (v.empty()) return 0.0;
    return sum(v) / static_cast<double>(v.size());
}

// Python statistics.geometric_mean / harmonic_mean
inline double geometricMean(const std::vector<double>& v) {
    if (v.empty()) return 0.0;
    double s = 0.0;
    for (double x : v) {
        if (x <= 0.0) return 0.0;
        s += std::log(x);
    }
    return std::exp(s / static_cast<double>(v.size()));
}

inline double harmonicMean(const std::vector<double>& v) {
    if (v.empty()) return 0.0;
    double s = 0.0;
    for (double x : v) {
        if (x == 0.0) return 0.0;
        s += 1.0 / x;
    }
    return static_cast<double>(v.size()) / s;
}

inline double rms(const std::vector<double>& v) {
    if (v.empty()) return 0.0;
    double s = 0.0;
    for (double x : v) s += x * x;
    return std::sqrt(s / static_cast<double>(v.size()));
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

inline double seMean(const std::vector<double>& v) {
    if (v.size() < 2) return 0.0;
    return stddev(v) / std::sqrt(static_cast<double>(v.size()));
}

inline double cv(const std::vector<double>& v) {
    const double m = mean(v);
    if (m == 0.0) return 0.0;
    return stddev(v) / m;
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
inline double midhinge(const std::vector<double>& v) {
    return (q1(v) + q3(v)) / 2.0;
}

inline double mad(const std::vector<double>& v) {
    if (v.empty()) return 0.0;
    const double med = median(v);
    std::vector<double> dev;
    dev.reserve(v.size());
    for (double x : v) dev.push_back(std::fabs(x - med));
    return median(std::move(dev));
}

inline double trimmedMean(std::vector<double> v, double pct) {
    if (v.empty()) return 0.0;
    if (pct < 0.0) pct = 0.0;
    if (pct > 45.0) pct = 45.0;
    std::sort(v.begin(), v.end());
    const std::size_t k = static_cast<std::size_t>(
        std::floor(static_cast<double>(v.size()) * pct / 100.0));
    if (2 * k >= v.size()) return median(v);
    double s = 0.0;
    for (std::size_t i = k; i < v.size() - k; ++i) s += v[i];
    return s / static_cast<double>(v.size() - 2 * k);
}

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

// Simple OLS slope / intercept (Nim RunningRegress style)
inline double linRegSlope(const std::vector<double>& x, const std::vector<double>& y) {
    if (x.size() != y.size() || x.size() < 2) return 0.0;
    const double vx = variance(x);
    if (vx == 0.0) return 0.0;
    return covariance(x, y) / vx;
}

inline double linRegIntercept(const std::vector<double>& x, const std::vector<double>& y) {
    if (x.size() != y.size() || x.empty()) return 0.0;
    return mean(y) - linRegSlope(x, y) * mean(x);
}

inline double linRegPredict(const std::vector<double>& x, const std::vector<double>& y, double xv) {
    return linRegIntercept(x, y) + linRegSlope(x, y) * xv;
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

inline std::vector<double> cumProd(const std::vector<double>& v) {
    std::vector<double> r;
    r.reserve(v.size());
    double p = 1.0;
    for (double x : v) {
        p *= x;
        r.push_back(p);
    }
    return r;
}

inline std::vector<double> diffs(const std::vector<double>& v) {
    std::vector<double> r;
    if (v.size() < 2) return r;
    r.reserve(v.size() - 1);
    for (std::size_t i = 1; i < v.size(); ++i) r.push_back(v[i] - v[i - 1]);
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

inline std::vector<double> normalize(const std::vector<double>& v) {
    if (v.empty()) return {};
    const double mn = minVal(v);
    const double mx = maxVal(v);
    if (mx == mn) return std::vector<double>(v.size(), 0.0);
    std::vector<double> r;
    r.reserve(v.size());
    for (double x : v) r.push_back((x - mn) / (mx - mn));
    return r;
}

inline std::vector<double> ranks(const std::vector<double>& v) {
    auto t = v;
    std::sort(t.begin(), t.end());
    std::vector<double> r;
    r.reserve(v.size());
    for (double x : v) {
        r.push_back(static_cast<double>(std::lower_bound(t.begin(), t.end(), x) - t.begin()) + 1.0);
    }
    return r;
}

inline std::vector<double> movingAvg(const std::vector<double>& v, double window) {
    std::vector<double> r;
    const int w = static_cast<int>(window);
    if (w <= 0) return r;
    for (std::size_t i = 0; i + static_cast<std::size_t>(w) <= v.size(); ++i) {
        double s = 0.0;
        for (int j = 0; j < w; ++j) s += v[i + static_cast<std::size_t>(j)];
        r.push_back(s / static_cast<double>(w));
    }
    return r;
}

inline std::vector<double> outlierIndices(const std::vector<double>& v) {
    std::vector<double> r;
    if (v.size() < 4) return r;
    const double lo = q1(v) - 1.5 * iqr(v);
    const double hi = q3(v) + 1.5 * iqr(v);
    for (std::size_t i = 0; i < v.size(); ++i) {
        if (v[i] < lo || v[i] > hi) r.push_back(static_cast<double>(i));
    }
    return r;
}

inline double outlierCount(const std::vector<double>& v) {
    return static_cast<double>(outlierIndices(v).size());
}

inline std::vector<double> withoutOutliers(const std::vector<double>& v) {
    const auto idx = outlierIndices(v);
    std::vector<double> r;
    for (std::size_t i = 0; i < v.size(); ++i) {
        bool skip = false;
        for (double d : idx) {
            if (static_cast<std::size_t>(d) == i) {
                skip = true;
                break;
            }
        }
        if (!skip) r.push_back(v[i]);
    }
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
