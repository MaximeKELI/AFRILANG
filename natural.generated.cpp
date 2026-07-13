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
    #line 1 "/home/admin20/AFRILANG/./examples/natural.afr"
    std::cout << "Hello from AFRILANG natural syntax!" << std::endl;
    #line 7 "/home/admin20/AFRILANG/./examples/natural.afr"
    if ((42LL > 40LL)) {
        #line 4 "/home/admin20/AFRILANG/./examples/natural.afr"
        std::cout << "The condition is true" << std::endl;
    } else {
        #line 6 "/home/admin20/AFRILANG/./examples/natural.afr"
        std::cout << "Impossible" << std::endl;
    }
    #line 11 "/home/admin20/AFRILANG/./examples/natural.afr"
    for (int _i = 0; _i < static_cast<int>(3LL); ++_i) {
        #line 10 "/home/admin20/AFRILANG/./examples/natural.afr"
        std::cout << "Hello" << std::endl;
    }
    return 0;
}
