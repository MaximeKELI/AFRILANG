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
    std::vector<double> nums = {1, 2, 3, 4, 5};
    #line 3 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::vector<double> doubled = afrilang::runtime::collections::mapNumbers(nums, [&](double x) -> double {
    #line 4 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    return (x * 2);
    });
    #line 7 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << doubled[static_cast<size_t>(0)] << std::endl;
    #line 8 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << doubled[static_cast<size_t>(4)] << std::endl;
    #line 10 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::vector<double> bigOnes = afrilang::runtime::collections::filterNumbers(nums, [&](double x) -> bool {
        return (x > 3);
    });
    #line 12 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << bigOnes.size() << std::endl;
    #line 13 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << bigOnes[static_cast<size_t>(0)] << std::endl;
    #line 14 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << bigOnes[static_cast<size_t>(1)] << std::endl;
    #line 16 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    double total = afrilang::runtime::collections::reduceNumbers(nums, [&](double acc, double x) -> double {
    #line 17 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    return (acc + x);
    }, 0);
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
    std::cout << upper[static_cast<size_t>(0)] << std::endl;
    #line 29 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << upper[static_cast<size_t>(2)] << std::endl;
    #line 31 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::vector<std::string> longWords = afrilang::runtime::collections::filterText(words, [&](std::string w) -> bool {
        return (w == "hello");
    });
    #line 33 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << longWords.size() << std::endl;
    #line 34 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << longWords[static_cast<size_t>(0)] << std::endl;
    #line 36 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::string joined = afrilang::runtime::collections::reduceText(words, [&](std::string acc, std::string w) -> std::string {
    #line 37 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    return ((acc + w) + ",");
    }, "");
    #line 40 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << joined << std::endl;
    #line 42 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::vector<double> expanded = afrilang::runtime::collections::flatMapNumbers(nums, [&](double n) -> std::vector<double> {
    #line 43 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    return std::vector<double>{n, (n * 100)};
    });
    #line 46 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << expanded.size() << std::endl;
    #line 47 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << expanded[static_cast<size_t>(3)] << std::endl;
    #line 49 "/home/maxime/AFRILANG/build/../examples/natural_list_ops.afr"
    std::cout << "natural list ops complete" << std::endl;
    return 0;
}
