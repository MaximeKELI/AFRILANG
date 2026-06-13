// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include "str.hpp"

template<typename T>
T identity(T x) {
    #line 2 "/home/maxime/AFRILANG/build/../examples/generics.afr"
    return x;
}

template<typename T>
T first(std::vector<T> items) {
    #line 6 "/home/maxime/AFRILANG/build/../examples/generics.afr"
    return items[0];
}

int main() {
    #line 9 "/home/maxime/AFRILANG/build/../examples/generics.afr"
    std::cout << identity(42) << std::endl;
    #line 10 "/home/maxime/AFRILANG/build/../examples/generics.afr"
    std::cout << identity("hello") << std::endl;
    #line 12 "/home/maxime/AFRILANG/build/../examples/generics.afr"
    std::vector<double> nums = {10, 20, 30};
    #line 13 "/home/maxime/AFRILANG/build/../examples/generics.afr"
    std::cout << first(nums) << std::endl;
    #line 15 "/home/maxime/AFRILANG/build/../examples/generics.afr"
    std::vector<std::string> words = {"a", "b", "c"};
    #line 16 "/home/maxime/AFRILANG/build/../examples/generics.afr"
    std::cout << first(words) << std::endl;
    return 0;
}
