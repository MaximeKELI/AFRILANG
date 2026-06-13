// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "str.hpp"

double afr_add(double a, double b) {
    #line 2 "/home/maxime/AFRILANG/build/../examples/tests.afr"
    return (a + b);
}

static int afr_tests_failed = 0;

void afr_test_addition_works() {
    #line 6 "/home/maxime/AFRILANG/build/../examples/tests.afr"
    auto r = afr_add(2, 3);
    #line 7 "/home/maxime/AFRILANG/build/../examples/tests.afr"
    if (!((r == 5))) {
        std::cerr << "ASSERT FAILED" << std::endl;
        ++afr_tests_failed;
        return;
    }
}

void afr_test_boolean_logic() {
    #line 11 "/home/maxime/AFRILANG/build/../examples/tests.afr"
    bool flag = true;
    #line 12 "/home/maxime/AFRILANG/build/../examples/tests.afr"
    if (!((flag == true))) {
        std::cerr << "ASSERT FAILED" << std::endl;
        ++afr_tests_failed;
        return;
    }
}

int main() {
    #line 15 "/home/maxime/AFRILANG/build/../examples/tests.afr"
    std::cout << "All tests defined" << std::endl;
    afr_test_addition_works();
    afr_test_boolean_logic();
    if (afr_tests_failed > 0) return 1;
    return 0;
}
