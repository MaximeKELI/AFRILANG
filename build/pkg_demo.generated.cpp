// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include "str.hpp"

namespace Math {
} // namespace Math

namespace Math {
    double square(double x) {
        #line 3 "/home/maxime/AFRILANG/build/../examples/pkg_demo.afr"
        return (x * x);
    }

    double pi() {
        #line 7 "/home/maxime/AFRILANG/build/../examples/pkg_demo.afr"
        return 3.14159;
    }

    double twice(double x) {
        #line 11 "/home/maxime/AFRILANG/build/../examples/pkg_demo.afr"
        return (x * 2);
    }

} // namespace Math

using namespace Math;

int main() {
    #line 3 "/home/maxime/AFRILANG/build/../examples/pkg_demo.afr"
        #line 5 "/home/maxime/AFRILANG/build/../examples/pkg_demo.afr"
    std::cout << Math::square(5) << std::endl;
    #line 6 "/home/maxime/AFRILANG/build/../examples/pkg_demo.afr"
    std::cout << Math::twice(21) << std::endl;
    #line 7 "/home/maxime/AFRILANG/build/../examples/pkg_demo.afr"
    std::cout << Math::pi() << std::endl;
    return 0;
}
