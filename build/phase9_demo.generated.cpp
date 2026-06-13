// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "str.hpp"
#include "log.hpp"
#include "math.hpp"
#include "time.hpp"
#include "str.hpp"

namespace str {
} // namespace str

namespace logging {
} // namespace logging

namespace math {
} // namespace math

namespace chrono {
} // namespace chrono

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

namespace logging {
    void info(std::string message) {
        afrilang::runtime::log::info(message);
    }

    void warn(std::string message) {
        afrilang::runtime::log::warn(message);
    }

    void error(std::string message) {
        afrilang::runtime::log::error(message);
    }

} // namespace logging

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

namespace chrono {
    double now() {
        return afrilang::runtime::time::now();
    }

    std::string formatTimestamp(double seconds) {
        return afrilang::runtime::time::formatTimestamp(seconds);
    }

} // namespace chrono

using namespace chrono;
using namespace math;
using namespace logging;
using namespace str;

int main() {
    #line 6 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
        #line 7 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
        #line 8 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
        #line 9 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
        #line 11 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
    std::string name = "AFRILANG";
    #line 12 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
    double version = 1;
    #line 13 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
    std::cout << afrilang::runtime::str::concat({afrilang::runtime::str::toString("Welcome to "), afrilang::runtime::str::toString(name), afrilang::runtime::str::toString(" v"), afrilang::runtime::str::toString(version), afrilang::runtime::str::toString("!")}) << std::endl;
    #line 15 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
    logging::info("starting demo");
    #line 16 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
    logging::warn("this is a warning");
    #line 18 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
    auto value = math::pow(2, 10);
    #line 19 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
    std::cout << math::abs(-42) << std::endl;
    #line 20 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
    std::cout << math::floor(3.9) << std::endl;
    #line 21 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
    std::cout << value << std::endl;
    #line 23 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
    auto nowTs = chrono::now();
    #line 24 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
    std::cout << chrono::formatTimestamp(nowTs) << std::endl;
    #line 26 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
    std::cout << str::trim("  hello  ") << std::endl;
    #line 27 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
    std::cout << str::contains("hello world", "world") << std::endl;
    #line 29 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
    auto parts = str::split("a,b,c", ",");
    #line 30 "/home/maxime/AFRILANG/build/../examples/phase9_demo.afr"
    std::cout << str::join(parts, "-") << std::endl;
    return 0;
}
