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

namespace Utils {
    double twice(double x) {
        #line 5 "/home/maxime/AFRILANG/examples/full_demo.afr"
        return (x * 2LL);
    }

} // namespace Utils

double afr_sum2(double a, double b) {
    #line 2 "/home/maxime/AFRILANG/examples/full_demo.afr"
    return (a + b);
}

using namespace Utils;

int main() {
    #line 9 "/home/maxime/AFRILANG/examples/full_demo.afr"
        #line 11 "/home/maxime/AFRILANG/examples/full_demo.afr"
    bool active = true;
    #line 17 "/home/maxime/AFRILANG/examples/full_demo.afr"
    if ((active == true)) {
        #line 14 "/home/maxime/AFRILANG/examples/full_demo.afr"
        std::cout << "System active" << std::endl;
    } else {
        #line 16 "/home/maxime/AFRILANG/examples/full_demo.afr"
        std::cout << "System inactive" << std::endl;
    }
    #line 19 "/home/maxime/AFRILANG/examples/full_demo.afr"
    double counter = 0LL;
    #line 23 "/home/maxime/AFRILANG/examples/full_demo.afr"
    while ((counter < 3LL)) {
        #line 21 "/home/maxime/AFRILANG/examples/full_demo.afr"
        std::cout << Utils::twice(counter) << std::endl;
        #line 22 "/home/maxime/AFRILANG/examples/full_demo.afr"
        counter = (counter + 1LL);
    }
    #line 25 "/home/maxime/AFRILANG/examples/full_demo.afr"
    std::vector<double> items = {1LL, 2LL, 3LL};
    #line 26 "/home/maxime/AFRILANG/examples/full_demo.afr"
    for (auto& item : items) {
        #line 29 "/home/maxime/AFRILANG/examples/full_demo.afr"
        if ((item == 2LL)) {
            #line 28 "/home/maxime/AFRILANG/examples/full_demo.afr"
            break;
        }
        #line 30 "/home/maxime/AFRILANG/examples/full_demo.afr"
        std::cout << item << std::endl;
    }
    #line 33 "/home/maxime/AFRILANG/examples/full_demo.afr"
    std::cout << afr_sum2(10LL, 32LL) << std::endl;
    #line 34 "/home/maxime/AFRILANG/examples/full_demo.afr"
    std::cout << "Full demo complete" << std::endl;
    return 0;
}
