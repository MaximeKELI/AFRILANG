#pragma once

#include <cstdint>
#include <random>

namespace afrilang::runtime::random_ {

inline std::mt19937& engine() {
    static std::mt19937 gen{std::random_device{}()};
    return gen;
}

inline void seed(std::int64_t value) {
    engine().seed(static_cast<std::uint32_t>(value));
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

} // namespace afrilang::runtime::random_
