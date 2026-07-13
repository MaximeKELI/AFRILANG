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

namespace Math {
    double add(double a, double b) {
        #line 3 "/home/admin20/AFRILANG/./examples/modules.afr"
        return (a + b);
    }

    double multiply(double a, double b) {
        #line 7 "/home/admin20/AFRILANG/./examples/modules.afr"
        return (a * b);
    }

} // namespace Math

using namespace Math;

int main() {
    #line 11 "/home/admin20/AFRILANG/./examples/modules.afr"
        #line 13 "/home/admin20/AFRILANG/./examples/modules.afr"
    std::cout << Math::add(3LL, 4LL) << std::endl;
    #line 14 "/home/admin20/AFRILANG/./examples/modules.afr"
    std::cout << Math::multiply(5LL, 6LL) << std::endl;
    return 0;
}
