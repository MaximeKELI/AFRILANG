// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "str.hpp"
#include "math.hpp"
#include "str.hpp"

namespace math {
} // namespace math

namespace str {
} // namespace str

namespace math {
    double abs(double value) {
        return afrilang::runtime::math::abs(value);
    }

    double floor(double value) {
        return afrilang::runtime::math::floor(value);
    }

    double ceil(double value) {
        return afrilang::runtime::math::ceil(value);
    }

    double pow(double base, double exp) {
        return afrilang::runtime::math::pow(base, exp);
    }

    double random() {
        return afrilang::runtime::math::random();
    }

} // namespace math

namespace str {
    std::string trim(std::string text) {
        return afrilang::runtime::str::trim(text);
    }

    bool contains(std::string text, std::string needle) {
        return afrilang::runtime::str::contains(text, needle);
    }

    std::string replace(std::string text, std::string from, std::string to) {
        return afrilang::runtime::str::replace(text, from, to);
    }

    std::vector<std::string> split(std::string text, std::string sep) {
        return afrilang::runtime::str::split(text, sep);
    }

    std::string join(std::vector<std::string> parts, std::string sep) {
        return afrilang::runtime::str::join(parts, sep);
    }

} // namespace str

double afr_power(double base, double exp = 2) {
    #line 8 "/home/maxime/AFRILANG/examples/defaults.afr"
    return math::pow(base, exp);
}

std::string afr_label(std::string message, std::string tag = "info") {
    #line 15 "/home/maxime/AFRILANG/examples/defaults.afr"
    return afrilang::runtime::str::concat({afrilang::runtime::str::toString(tag), afrilang::runtime::str::toString(" "), afrilang::runtime::str::toString(message)});
}

using namespace str;
using namespace math;

int main() {
    #line 4 "/home/maxime/AFRILANG/examples/defaults.afr"
        #line 5 "/home/maxime/AFRILANG/examples/defaults.afr"
        #line 11 "/home/maxime/AFRILANG/examples/defaults.afr"
    std::cout << afr_power(3) << std::endl;
    #line 12 "/home/maxime/AFRILANG/examples/defaults.afr"
    std::cout << afr_power(2, 10) << std::endl;
    #line 18 "/home/maxime/AFRILANG/examples/defaults.afr"
    std::cout << afr_label(std::string("System ready")) << std::endl;
    #line 19 "/home/maxime/AFRILANG/examples/defaults.afr"
    std::cout << afr_label(std::string("Warning"), std::string("warn")) << std::endl;
    return 0;
}
