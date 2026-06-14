// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "collections.hpp"
#include "str.hpp"

int main() {
    #line 1 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::vector<std::int64_t> nums = {1LL, 2LL, 3LL, 4LL, 5LL};
    #line 3 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::vector<double> doubled = afrilang::runtime::collections::mapNumbers(nums, [&](std::int64_t x) -> double {
    #line 4 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    return (x * 2LL);
    });
    #line 7 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << doubled[static_cast<size_t>(0LL)] << std::endl;
    #line 8 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << doubled[static_cast<size_t>(4LL)] << std::endl;
    #line 10 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::vector<std::int64_t> bigOnes = afrilang::runtime::collections::filterNumbers(nums, [&](std::int64_t x) -> bool {
        return (x > 3LL);
    });
    #line 12 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << bigOnes.size() << std::endl;
    #line 13 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << bigOnes[static_cast<size_t>(0LL)] << std::endl;
    #line 14 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << bigOnes[static_cast<size_t>(1LL)] << std::endl;
    #line 16 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::int64_t total = afrilang::runtime::collections::reduceNumbers(nums, [&](std::int64_t acc, std::int64_t x) -> std::int64_t {
    #line 17 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    return (acc + x);
    }, 0LL);
    #line 20 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << total << std::endl;
    #line 22 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::vector<std::string> words = {"hi", "hello", "hey"};
    #line 24 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::vector<std::string> upper = afrilang::runtime::collections::mapText(words, [&](std::string w) -> std::string {
    #line 25 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    return (w + "!");
    });
    #line 28 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << upper[static_cast<size_t>(0LL)] << std::endl;
    #line 29 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << upper[static_cast<size_t>(2LL)] << std::endl;
    #line 31 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::vector<std::string> longWords = afrilang::runtime::collections::filterText(words, [&](std::string w) -> bool {
        return (w == "hello");
    });
    #line 33 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << longWords.size() << std::endl;
    #line 34 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << longWords[static_cast<size_t>(0LL)] << std::endl;
    #line 36 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::string joined = afrilang::runtime::collections::reduceText(words, [&](std::string acc, std::string w) -> std::string {
    #line 37 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    return ((acc + w) + ",");
    }, "");
    #line 40 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << joined << std::endl;
    #line 42 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::vector<std::int64_t> expanded = afrilang::runtime::collections::flatMapNumbers(nums, [&](std::int64_t n) -> std::vector<std::int64_t> {
    #line 43 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    return std::vector<std::int64_t>{n, (n * 100LL)};
    });
    #line 46 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << expanded.size() << std::endl;
    #line 47 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << expanded[static_cast<size_t>(3LL)] << std::endl;
    #line 49 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << "natural list ops complete" << std::endl;
    return 0;
}
