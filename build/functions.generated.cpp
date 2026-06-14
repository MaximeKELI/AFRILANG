// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include <memory>
#include "str.hpp"

class Calculator {
public:
    virtual ~Calculator() = default;

    virtual double compute(double x, double y) {
        #line 15 "/home/maxime/AFRILANG/build/../examples/functions.afr"
        return (x + (y * 2));
    }

};

double afr_add(double a, double b) {
    #line 2 "/home/maxime/AFRILANG/build/../examples/functions.afr"
    return (a + b);
}

std::string afr_greet(std::string name) {
    #line 6 "/home/maxime/AFRILANG/build/../examples/functions.afr"
    return ("Bonjour, " + name);
}

double afr_square(double n) {
    #line 10 "/home/maxime/AFRILANG/build/../examples/functions.afr"
    return (n * n);
}

int main() {
    #line 19 "/home/maxime/AFRILANG/build/../examples/functions.afr"
    double result = afr_add(10, 32);
    #line 20 "/home/maxime/AFRILANG/build/../examples/functions.afr"
    std::cout << result << std::endl;
    #line 22 "/home/maxime/AFRILANG/build/../examples/functions.afr"
    std::string message = afr_greet(std::string("AFRILANG"));
    #line 23 "/home/maxime/AFRILANG/build/../examples/functions.afr"
    std::cout << message << std::endl;
    #line 25 "/home/maxime/AFRILANG/build/../examples/functions.afr"
    double squared = afr_square(7);
    #line 26 "/home/maxime/AFRILANG/build/../examples/functions.afr"
    std::cout << squared << std::endl;
    #line 28 "/home/maxime/AFRILANG/build/../examples/functions.afr"
    std::unique_ptr<Calculator> calc = std::make_unique<Calculator>();
    #line 29 "/home/maxime/AFRILANG/build/../examples/functions.afr"
    std::cout << calc->compute(5, 3) << std::endl;
    return 0;
}
