// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "str.hpp"

int main() {
    #line 1 "/home/maxime/AFRILANG/build/../examples/natural.afr"
    std::cout << "Hello from AFRILANG natural syntax!" << std::endl;
    #line 7 "/home/maxime/AFRILANG/build/../examples/natural.afr"
    if ((42 > 40)) {
        #line 4 "/home/maxime/AFRILANG/build/../examples/natural.afr"
        std::cout << "The condition is true" << std::endl;
    } else {
        #line 6 "/home/maxime/AFRILANG/build/../examples/natural.afr"
        std::cout << "Impossible" << std::endl;
    }
    #line 11 "/home/maxime/AFRILANG/build/../examples/natural.afr"
    for (int _i = 0; _i < static_cast<int>(3); ++_i) {
        #line 10 "/home/maxime/AFRILANG/build/../examples/natural.afr"
        std::cout << "Hello" << std::endl;
    }
    return 0;
}
