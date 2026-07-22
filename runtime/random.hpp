#pragma once

// AFRILANG std/random — surface aligned with Python random + Nim std/random + Crystal Random.
// Clean-room wrappers around std::mt19937 (not a copy of those projects' sources).

#include <algorithm>
#include <chrono>
#include <cstdint>
#include <random>
#include <vector>

namespace afrilang::runtime::random_ {

inline std::mt19937& engine() {
    static std::mt19937 gen{std::random_device{}()};
    return gen;
}

inline void seed(std::int64_t value) {
    engine().seed(static_cast<std::uint32_t>(value));
}

inline void randomize() {
    seed(static_cast<std::int64_t>(
        std::chrono::high_resolution_clock::now().time_since_epoch().count()));
}

inline std::int64_t randomInt(std::int64_t minValue, std::int64_t maxValue) {
    if (minValue > maxValue) std::swap(minValue, maxValue);
    std::uniform_int_distribution<std::int64_t> dist(minValue, maxValue);
    return dist(engine());
}

inline double randomFloat() {
    std::uniform_real_distribution<double> dist(0.0, 1.0);
    return dist(engine());
}

inline double rand(double maxValue) {
    if (maxValue <= 0.0) return 0.0;
    std::uniform_real_distribution<double> dist(0.0, maxValue);
    return dist(engine());
}

inline double randint(double a, double b) {
    return static_cast<double>(randomInt(static_cast<std::int64_t>(a),
                                         static_cast<std::int64_t>(b)));
}

inline double gauss(double mu, double sigma) {
    if (sigma < 0.0) sigma = -sigma;
    if (sigma == 0.0) return mu;
    std::normal_distribution<double> dist(mu, sigma);
    return dist(engine());
}

inline double uniform(double a, double b) {
    if (a > b) std::swap(a, b);
    std::uniform_real_distribution<double> dist(a, b);
    return dist(engine());
}

inline double choice(const std::vector<double>& v) {
    if (v.empty()) return 0.0;
    std::uniform_int_distribution<std::size_t> dist(0, v.size() - 1);
    return v[dist(engine())];
}

inline std::vector<double> shuffle(std::vector<double> v) {
    std::shuffle(v.begin(), v.end(), engine());
    return v;
}

inline std::vector<double> sample(std::vector<double> v, double k) {
    const int n = static_cast<int>(std::floor(k));
    if (n <= 0) return {};
    if (static_cast<std::size_t>(n) >= v.size()) {
        std::shuffle(v.begin(), v.end(), engine());
        return v;
    }
    std::shuffle(v.begin(), v.end(), engine());
    v.resize(static_cast<std::size_t>(n));
    return v;
}

} // namespace afrilang::runtime::random_
