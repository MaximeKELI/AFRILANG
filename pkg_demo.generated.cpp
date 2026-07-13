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
    double square(double x) {
        #line 3 "/home/admin20/AFRILANG/./examples/pkg_demo.afr"
        return (x * x);
    }

    double pi() {
        #line 7 "/home/admin20/AFRILANG/./examples/pkg_demo.afr"
        return 3.14159;
    }

    double twice(double x) {
        #line 11 "/home/admin20/AFRILANG/./examples/pkg_demo.afr"
        return (x * 2LL);
    }

} // namespace Math

using namespace Math;

int main() {
    #line 3 "/home/admin20/AFRILANG/./examples/pkg_demo.afr"
        #line 5 "/home/admin20/AFRILANG/./examples/pkg_demo.afr"
    std::cout << Math::square(5LL) << std::endl;
    #line 6 "/home/admin20/AFRILANG/./examples/pkg_demo.afr"
    std::cout << Math::twice(21LL) << std::endl;
    #line 7 "/home/admin20/AFRILANG/./examples/pkg_demo.afr"
    std::cout << Math::pi() << std::endl;
    return 0;
}
