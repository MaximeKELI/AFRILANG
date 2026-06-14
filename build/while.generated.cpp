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

int main() {
    #line 1 "/home/maxime/AFRILANG/build/../examples/while.afr"
    double count = 0LL;
    #line 6 "/home/maxime/AFRILANG/build/../examples/while.afr"
    while ((count < 5LL)) {
        #line 4 "/home/maxime/AFRILANG/build/../examples/while.afr"
        std::cout << count << std::endl;
        #line 5 "/home/maxime/AFRILANG/build/../examples/while.afr"
        count = (count + 1LL);
    }
    #line 8 "/home/maxime/AFRILANG/build/../examples/while.afr"
    std::cout << "Done counting" << std::endl;
    #line 10 "/home/maxime/AFRILANG/build/../examples/while.afr"
    double score = 75LL;
    #line 20 "/home/maxime/AFRILANG/build/../examples/while.afr"
    if ((score > 90LL)) {
        #line 13 "/home/maxime/AFRILANG/build/../examples/while.afr"
        std::cout << "Excellent" << std::endl;
    } else {
        #line 19 "/home/maxime/AFRILANG/build/../examples/while.afr"
        if ((score > 60LL)) {
            #line 16 "/home/maxime/AFRILANG/build/../examples/while.afr"
            std::cout << "Passed" << std::endl;
        } else {
            #line 18 "/home/maxime/AFRILANG/build/../examples/while.afr"
            std::cout << "Failed" << std::endl;
        }
    }
    return 0;
}
