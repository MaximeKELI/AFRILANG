// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "str.hpp"
#include "collections.hpp"
#include "str.hpp"

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

    double sumNumbers(std::vector<double> items) {
        return afrilang::runtime::collections::sumNumbers(items);
    }

    std::vector<double> mapNumbers(std::vector<double> items, std::function<double(double)> fn) {
        return afrilang::runtime::collections::mapNumbers(items, fn);
    }

    std::vector<double> filterNumbers(std::vector<double> items, std::function<bool(double)> fn) {
        return afrilang::runtime::collections::filterNumbers(items, fn);
    }

    double reduceNumbers(std::vector<double> items, std::function<double(double, double)> fn, double initial) {
        return afrilang::runtime::collections::reduceNumbers(items, fn, initial);
    }

    std::vector<std::string> mapText(std::vector<std::string> items, std::function<std::string(std::string)> fn) {
        return afrilang::runtime::collections::mapText(items, fn);
    }

    std::vector<std::string> filterText(std::vector<std::string> items, std::function<bool(std::string)> fn) {
        return afrilang::runtime::collections::filterText(items, fn);
    }

    std::string reduceText(std::vector<std::string> items, std::function<std::string(std::string, std::string)> fn, std::string initial) {
        return afrilang::runtime::collections::reduceText(items, fn, initial);
    }

    std::vector<double> flatMapNumbers(std::vector<double> items, std::function<std::vector<double>(double)> fn) {
        return afrilang::runtime::collections::flatMapNumbers(items, fn);
    }

    std::vector<std::string> flatMapText(std::vector<std::string> items, std::function<std::vector<std::string>(std::string)> fn) {
        return afrilang::runtime::collections::flatMapText(items, fn);
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

using namespace str;
using namespace collections;

int main() {
    #line 4 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
        #line 5 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
        #line 7 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::vector<double> nums = {1LL, 2LL, 3LL, 4LL, 5LL};
    #line 9 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::vector<double> doubled = collections::mapNumbers(nums, [&](double x) -> double {
    #line 10 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    return (x * 2LL);
    });
    #line 13 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::cout << doubled[static_cast<size_t>(0LL)] << std::endl;
    #line 14 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::cout << doubled[static_cast<size_t>(4LL)] << std::endl;
    #line 16 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::vector<double> bigOnes = collections::filterNumbers(nums, [&](double x) -> bool {
    #line 21 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    if ((x > 3LL)) {
        #line 18 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
        return true;
    } else {
        #line 20 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
        return false;
    }
    });
    #line 24 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::cout << bigOnes.size() << std::endl;
    #line 25 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::cout << bigOnes[static_cast<size_t>(0LL)] << std::endl;
    #line 26 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::cout << bigOnes[static_cast<size_t>(1LL)] << std::endl;
    #line 28 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    double total = collections::reduceNumbers(nums, [&](double acc, double x) -> double {
    #line 29 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    return (acc + x);
    }, 0LL);
    #line 32 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::cout << total << std::endl;
    #line 34 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::vector<std::string> words = {"hi", "hello", "hey"};
    #line 36 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::vector<std::string> upper = collections::mapText(words, [&](std::string w) -> std::string {
    #line 37 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    return (w + "!");
    });
    #line 40 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::cout << upper[static_cast<size_t>(0LL)] << std::endl;
    #line 41 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::cout << upper[static_cast<size_t>(2LL)] << std::endl;
    #line 43 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::vector<std::string> longWords = collections::filterText(words, [&](std::string w) -> bool {
    #line 48 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    if (str::contains(w, "el")) {
        #line 45 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
        return true;
    } else {
        #line 47 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
        return false;
    }
    });
    #line 51 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::cout << longWords.size() << std::endl;
    #line 52 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::cout << longWords[static_cast<size_t>(0LL)] << std::endl;
    #line 54 "/home/maxime/AFRILANG/build/../examples/list_ops.afr"
    std::cout << "list ops complete" << std::endl;
    return 0;
}
