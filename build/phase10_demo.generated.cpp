// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include "str.hpp"
#include "math.hpp"
#include "collections.hpp"
#include "str.hpp"

namespace collections {
} // namespace collections

namespace str {
} // namespace str

namespace math {
} // namespace math

namespace collections {
    std::vector<double> sortNumbers(std::vector<double> items) {
        return afrilang::runtime::collections::sortNumbers(items);
    }

    std::vector<std::string> sortText(std::vector<std::string> items) {
        return afrilang::runtime::collections::sortText(items);
    }

    std::vector<double> reverseNumbers(std::vector<double> items) {
        return afrilang::runtime::collections::reverseNumbers(items);
    }

    std::vector<std::string> reverseText(std::vector<std::string> items) {
        return afrilang::runtime::collections::reverseText(items);
    }

    bool containsNumber(std::vector<double> items, double value) {
        return afrilang::runtime::collections::containsNumber(items, value);
    }

    bool containsText(std::vector<std::string> items, std::string value) {
        return afrilang::runtime::collections::containsText(items, value);
    }

    double indexOfNumber(std::vector<double> items, double value) {
        return afrilang::runtime::collections::indexOfNumber(items, value);
    }

    double indexOfText(std::vector<std::string> items, std::string value) {
        return afrilang::runtime::collections::indexOfText(items, value);
    }

    double sum(std::vector<double> items) {
        return afrilang::runtime::collections::sum(items);
    }

} // namespace collections

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

std::string greet(std::string name, std::string prefix = "Hello") {
    #line 10 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    return afrilang::runtime::str::concat({afrilang::runtime::str::toString(prefix), afrilang::runtime::str::toString(" "), afrilang::runtime::str::toString(name), afrilang::runtime::str::toString("!")});
}

using namespace math;
using namespace str;
using namespace collections;

int main() {
    #line 5 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
        #line 6 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
        #line 7 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
        #line 13 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    std::cout << greet("World") << std::endl;
    #line 14 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    std::cout << greet("Africa", "Bonjour") << std::endl;
    #line 16 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    const double PI = 3.14159;
    #line 17 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    std::cout << PI << std::endl;
    #line 19 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    std::vector<double> nums = {3, 1, 4, 1, 5};
    #line 20 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    std::cout << collections::sortNumbers(nums) << std::endl;
    #line 21 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    std::cout << collections::sum(nums) << std::endl;
    #line 22 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    std::cout << collections::reverseNumbers(nums) << std::endl;
    #line 23 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    std::cout << collections::containsNumber(nums, 4) << std::endl;
    #line 24 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    std::cout << collections::indexOfNumber(nums, 5) << std::endl;
    #line 26 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    std::vector<std::string> words = {"zebra", "apple", "mango"};
    #line 27 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    std::cout << collections::sortText(words) << std::endl;
    #line 28 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    std::cout << collections::containsText(words, "apple") << std::endl;
    #line 30 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    double total = 0;
    #line 31 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    for (double i = 1; i <= 5; i += 1.0) {
        #line 32 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
        total = (total + i);
    }
    #line 34 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    std::cout << total << std::endl;
    #line 36 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    for (double n = 0; n <= 10; n += 2) {
        #line 37 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
        std::cout << n << std::endl;
    }
    #line 40 "/home/maxime/AFRILANG/build/../examples/phase10_demo.afr"
    std::cout << "Phase 10 demo complete" << std::endl;
    return 0;
}
