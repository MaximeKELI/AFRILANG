// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "str.hpp"

double afr_apply(std::function<double(double)> fn, double value) {
    #line 13 "/home/maxime/AFRILANG/examples/lambdas.afr"
    return fn(value);
}

int main() {
    #line 1 "/home/maxime/AFRILANG/examples/lambdas.afr"
    std::function<double(double)> doubleIt = [&](double x) -> double {
    #line 2 "/home/maxime/AFRILANG/examples/lambdas.afr"
    return (x * 2);
    };
    #line 5 "/home/maxime/AFRILANG/examples/lambdas.afr"
    std::function<double(double)> addFive = [&](double x) -> double {
    #line 6 "/home/maxime/AFRILANG/examples/lambdas.afr"
    return (x + 5);
    };
    #line 9 "/home/maxime/AFRILANG/examples/lambdas.afr"
    std::cout << doubleIt(21) << std::endl;
    #line 10 "/home/maxime/AFRILANG/examples/lambdas.afr"
    std::cout << addFive(10) << std::endl;
    #line 16 "/home/maxime/AFRILANG/examples/lambdas.afr"
    std::cout << afr_apply(doubleIt, 10) << std::endl;
    #line 17 "/home/maxime/AFRILANG/examples/lambdas.afr"
    std::cout << afr_apply(addFive, 100) << std::endl;
    #line 19 "/home/maxime/AFRILANG/examples/lambdas.afr"
    std::function<double(double)> pipeline = [&](double x) -> double {
    #line 20 "/home/maxime/AFRILANG/examples/lambdas.afr"
    return afr_apply(addFive, afr_apply(doubleIt, x));
    };
    #line 23 "/home/maxime/AFRILANG/examples/lambdas.afr"
    std::cout << pipeline(3) << std::endl;
    #line 25 "/home/maxime/AFRILANG/examples/lambdas.afr"
    std::function<std::string(std::string)> greet = [&](std::string name) -> std::string {
    #line 26 "/home/maxime/AFRILANG/examples/lambdas.afr"
    return ("Hello, " + name);
    };
    #line 29 "/home/maxime/AFRILANG/examples/lambdas.afr"
    std::cout << greet("AFRILANG") << std::endl;
    #line 31 "/home/maxime/AFRILANG/examples/lambdas.afr"
    std::function<double(std::function<double(double)>, double)> runTwice = [&](std::function<double(double)> fn, double x) -> double {
    #line 32 "/home/maxime/AFRILANG/examples/lambdas.afr"
    return fn(fn(x));
    };
    #line 35 "/home/maxime/AFRILANG/examples/lambdas.afr"
    std::cout << runTwice(doubleIt, 2) << std::endl;
    return 0;
}
