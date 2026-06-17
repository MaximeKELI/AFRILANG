#pragma once

#include <cmath>
#include <cstdlib>
#include <ctime>

namespace afrilang::runtime::math {

inline double abs(double value) { return std::fabs(value); }
inline double floor(double value) { return std::floor(value); }
inline double ceil(double value) { return std::ceil(value); }
inline double pow(double base, double exp) { return std::pow(base, exp); }

inline double random() {
    static bool seeded = false;
    if (!seeded) {
        std::srand(static_cast<unsigned>(std::time(nullptr)));
        seeded = true;
    }
    return static_cast<double>(std::rand()) / static_cast<double>(RAND_MAX);
}

} // namespace afrilang::runtime::math
