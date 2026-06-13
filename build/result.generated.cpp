// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include "result.hpp"

afrilang::runtime::AfrResult_number divide(double a, double b) {
    if ((b == 0)) {
        afrilang::runtime::AfrResult_number _result;
        _result.isError = true;
        _result.message = "Division par zero";
        return _result;
    }
    afrilang::runtime::AfrResult_number _result;
    _result.value = (a / b);
    return _result;
}

int main() {
    auto ok = divide(10, 2);
    if (ok.isError) {
        std::cout << ok.message << std::endl;
    } else {
        std::cout << ok.value << std::endl;
    }
    auto bad = divide(10, 0);
    if (bad.isError) {
        std::cout << bad.message << std::endl;
    } else {
        std::cout << bad.value << std::endl;
    }
    return 0;
}
