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
#include <cmath>
#include <cstring>

extern "C" double sin(double x);
extern "C" double sqrt(double x);

int main() {
    #line 4 "/home/maxime/AFRILANG/examples/ffi.afr"
    std::cout << sin((3.14159 / 2LL)) << std::endl;
    #line 5 "/home/maxime/AFRILANG/examples/ffi.afr"
    std::cout << sqrt(16LL) << std::endl;
    return 0;
}
