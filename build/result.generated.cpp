// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include "result.hpp"

afrilang::runtime::AfrResult_number divide(double a, double b) {
    #line 4 "/home/maxime/AFRILANG/examples/result.afr"
    if ((b == 0)) {
        #line 3 "/home/maxime/AFRILANG/examples/result.afr"
        afrilang::runtime::AfrResult_number _result;
        _result.isError = true;
        _result.message = "Division par zero";
        return _result;
    }
    #line 5 "/home/maxime/AFRILANG/examples/result.afr"
    afrilang::runtime::AfrResult_number _result;
    _result.value = (a / b);
    return _result;
}

int main() {
    #line 8 "/home/maxime/AFRILANG/examples/result.afr"
    auto ok = divide(10, 2);
    #line 13 "/home/maxime/AFRILANG/examples/result.afr"
    if (ok.isError) {
        #line 10 "/home/maxime/AFRILANG/examples/result.afr"
        std::cout << ok.message << std::endl;
    } else {
        #line 12 "/home/maxime/AFRILANG/examples/result.afr"
        std::cout << ok.value << std::endl;
    }
    #line 15 "/home/maxime/AFRILANG/examples/result.afr"
    auto bad = divide(10, 0);
    #line 20 "/home/maxime/AFRILANG/examples/result.afr"
    if (bad.isError) {
        #line 17 "/home/maxime/AFRILANG/examples/result.afr"
        std::cout << bad.message << std::endl;
    } else {
        #line 19 "/home/maxime/AFRILANG/examples/result.afr"
        std::cout << bad.value << std::endl;
    }
    return 0;
}
