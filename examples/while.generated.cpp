// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include <optional>
#include "str.hpp"

int main() {
    #line 1 "/home/admin20/AFRILANG/examples/while.afr"
    double count = 0LL;
    #line 6 "/home/admin20/AFRILANG/examples/while.afr"
    while ((count < 5LL)) {
        #line 4 "/home/admin20/AFRILANG/examples/while.afr"
        std::cout << afrilang::runtime::str::toString(count) << std::endl;
        #line 5 "/home/admin20/AFRILANG/examples/while.afr"
        count = (count + 1LL);
    }
    #line 8 "/home/admin20/AFRILANG/examples/while.afr"
    std::cout << afrilang::runtime::str::toString("Done counting") << std::endl;
    #line 10 "/home/admin20/AFRILANG/examples/while.afr"
    double score = 75LL;
    #line 20 "/home/admin20/AFRILANG/examples/while.afr"
    if ((score > 90LL)) {
        #line 13 "/home/admin20/AFRILANG/examples/while.afr"
        std::cout << afrilang::runtime::str::toString("Excellent") << std::endl;
    } else {
        #line 19 "/home/admin20/AFRILANG/examples/while.afr"
        if ((score > 60LL)) {
            #line 16 "/home/admin20/AFRILANG/examples/while.afr"
            std::cout << afrilang::runtime::str::toString("Passed") << std::endl;
        } else {
            #line 18 "/home/admin20/AFRILANG/examples/while.afr"
            std::cout << afrilang::runtime::str::toString("Failed") << std::endl;
        }
    }
    return 0;
}
