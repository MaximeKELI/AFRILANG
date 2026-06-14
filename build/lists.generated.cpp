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

int main() {
    #line 1 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::vector<double> nums = {1LL, 2LL, 3LL};
    #line 2 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << nums[static_cast<size_t>(0LL)] << std::endl;
    #line 3 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << nums[static_cast<size_t>(1LL)] << std::endl;
    #line 4 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << nums.size() << std::endl;
    #line 6 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    nums[static_cast<size_t>(1LL)] = 99LL;
    #line 7 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << nums[static_cast<size_t>(1LL)] << std::endl;
    #line 9 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    nums.push_back(4LL);
    #line 10 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << nums.size() << std::endl;
    #line 12 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::vector<double> bracket = {10LL, 20LL, 30LL};
    #line 13 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << bracket[static_cast<size_t>(0LL)] << std::endl;
    #line 14 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << bracket[static_cast<size_t>(2LL)] << std::endl;
    #line 16 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::vector<double> nums2 = {};
    #line 17 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    nums2.push_back(42LL);
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
    std::cout << flags[static_cast<size_t>(0LL)] << std::endl;
    #line 27 "/home/maxime/AFRILANG/build/../examples/lists.afr"
    std::cout << flags[static_cast<size_t>(2LL)] << std::endl;
    return 0;
}
