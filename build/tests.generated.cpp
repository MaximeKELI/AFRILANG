// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>

double add(double a, double b) {
    return (a + b);
}

static int afr_tests_failed = 0;

void afr_test_addition_works() {
    auto r = add(2, 3);
    if (!((r == 5))) {
        std::cerr << "ASSERT FAILED" << std::endl;
        ++afr_tests_failed;
        return;
    }
}

void afr_test_boolean_logic() {
    bool flag = true;
    if (!((flag == true))) {
        std::cerr << "ASSERT FAILED" << std::endl;
        ++afr_tests_failed;
        return;
    }
}

int main() {
    std::cout << "All tests defined" << std::endl;
    afr_test_addition_works();
    afr_test_boolean_logic();
    if (afr_tests_failed > 0) return 1;
    return 0;
}
