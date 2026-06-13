// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include "str.hpp"

double divide(double a, double b) {
    #line 4 "/home/maxime/AFRILANG/examples/exceptions.afr"
    if ((b == 0)) {
        #line 3 "/home/maxime/AFRILANG/examples/exceptions.afr"
        throw std::runtime_error("division by zero");
    }
    #line 5 "/home/maxime/AFRILANG/examples/exceptions.afr"
    return (a / b);
}

int main() {
    #line 11 "/home/maxime/AFRILANG/examples/exceptions.afr"
    try {
        #line 9 "/home/maxime/AFRILANG/examples/exceptions.afr"
        std::cout << divide(10, 2) << std::endl;
        #line 10 "/home/maxime/AFRILANG/examples/exceptions.afr"
        std::cout << divide(10, 0) << std::endl;
    } catch (const std::exception& _afr_ex) {
        std::string e = _afr_ex.what();
        #line 12 "/home/maxime/AFRILANG/examples/exceptions.afr"
        std::cout << "caught:" << std::endl;
        #line 13 "/home/maxime/AFRILANG/examples/exceptions.afr"
        std::cout << e << std::endl;
    }
    #line 16 "/home/maxime/AFRILANG/examples/exceptions.afr"
    std::cout << "program continues" << std::endl;
    return 0;
}
