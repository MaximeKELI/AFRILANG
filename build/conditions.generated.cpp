// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "str.hpp"

int main() {
    #line 1 "/home/maxime/AFRILANG/examples/conditions.afr"
    double age = 25;
    #line 5 "/home/maxime/AFRILANG/examples/conditions.afr"
    if ((age > 18)) {
        #line 4 "/home/maxime/AFRILANG/examples/conditions.afr"
        std::cout << "Adulte" << std::endl;
    }
    #line 9 "/home/maxime/AFRILANG/examples/conditions.afr"
    if ((age < 30)) {
        #line 8 "/home/maxime/AFRILANG/examples/conditions.afr"
        std::cout << "Jeune adulte" << std::endl;
    }
    #line 11 "/home/maxime/AFRILANG/examples/conditions.afr"
    double score = 100;
    #line 15 "/home/maxime/AFRILANG/examples/conditions.afr"
    if ((score == 100)) {
        #line 14 "/home/maxime/AFRILANG/examples/conditions.afr"
        std::cout << "Score parfait!" << std::endl;
    }
    #line 17 "/home/maxime/AFRILANG/examples/conditions.afr"
    double x = 10;
    #line 18 "/home/maxime/AFRILANG/examples/conditions.afr"
    double y = 3;
    #line 20 "/home/maxime/AFRILANG/examples/conditions.afr"
    std::cout << (x + y) << std::endl;
    #line 21 "/home/maxime/AFRILANG/examples/conditions.afr"
    std::cout << (x - y) << std::endl;
    #line 22 "/home/maxime/AFRILANG/examples/conditions.afr"
    std::cout << (x * y) << std::endl;
    #line 23 "/home/maxime/AFRILANG/examples/conditions.afr"
    std::cout << (x / y) << std::endl;
    #line 27 "/home/maxime/AFRILANG/examples/conditions.afr"
    for (int _i = 0; _i < static_cast<int>(2); ++_i) {
        #line 26 "/home/maxime/AFRILANG/examples/conditions.afr"
        std::cout << "Boucle conditionnelle" << std::endl;
    }
    return 0;
}
