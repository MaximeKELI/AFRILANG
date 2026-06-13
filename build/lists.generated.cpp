// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include "str.hpp"

int main() {
    #line 1 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::vector<double> nums = {1, 2, 3};
    #line 2 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << nums[static_cast<size_t>(0)] << std::endl;
    #line 3 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << nums[static_cast<size_t>(1)] << std::endl;
    #line 4 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << nums.size() << std::endl;
    #line 6 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    nums[static_cast<size_t>(1)] = 99;
    #line 7 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << nums[static_cast<size_t>(1)] << std::endl;
    #line 9 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    nums.push_back(4);
    #line 10 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << nums.size() << std::endl;
    #line 12 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::vector<double> bracket = {10, 20, 30};
    #line 13 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << bracket[static_cast<size_t>(0)] << std::endl;
    #line 14 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << bracket[static_cast<size_t>(2)] << std::endl;
    #line 16 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::vector<double> nums2 = {};
    #line 17 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    nums2.push_back(42);
    #line 18 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << nums2.size() << std::endl;
    #line 20 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::vector<std::string> names = {"Alice", "Bob"};
    #line 21 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    for (auto& name : names) {
        #line 22 "/home/maxime/AFRILANG/build/../examples/lists.afr"
        std::cout << name << std::endl;
    }
    #line 25 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::vector<bool> flags = {true, false, true, false};
    #line 26 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << flags[static_cast<size_t>(0)] << std::endl;
    #line 27 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << flags[static_cast<size_t>(2)] << std::endl;
    return 0;
}
