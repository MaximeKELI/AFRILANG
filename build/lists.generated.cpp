// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>

int main() {
    std::vector<double> nums = {1, 2, 3};
    std::cout << nums[static_cast<size_t>(0)] << std::endl;
    std::cout << nums[static_cast<size_t>(1)] << std::endl;
    std::cout << nums.size() << std::endl;
    nums[static_cast<size_t>(1)] = 99;
    std::cout << nums[static_cast<size_t>(1)] << std::endl;
    nums.push_back(4);
    std::cout << nums.size() << std::endl;
    std::vector<double> bracket = {10, 20, 30};
    std::cout << bracket[static_cast<size_t>(0)] << std::endl;
    std::cout << bracket[static_cast<size_t>(2)] << std::endl;
    std::vector<double> nums2 = {};
    nums2.push_back(42);
    std::cout << nums2.size() << std::endl;
    std::vector<std::string> names = {"Alice", "Bob"};
    for (auto& name : names) {
        std::cout << name << std::endl;
    }
    std::vector<bool> flags = {true, false, true, false};
    std::cout << flags[static_cast<size_t>(0)] << std::endl;
    std::cout << flags[static_cast<size_t>(2)] << std::endl;
    return 0;
}
