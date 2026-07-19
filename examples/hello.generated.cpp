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
    #line 1 "/home/admin20/AFRILANG/examples/hello.afr"
    std::cout << afrilang::runtime::str::toString("Bonjour depuis AFRILANG!") << std::endl;
    #line 2 "/home/admin20/AFRILANG/examples/hello.afr"
    std::cout << afrilang::runtime::str::toString("Le compilateur fonctionne.") << std::endl;
    #line 6 "/home/admin20/AFRILANG/examples/hello.afr"
    for (int _i = 0; _i < static_cast<int>(3LL); ++_i) {
        #line 5 "/home/admin20/AFRILANG/examples/hello.afr"
        std::cout << afrilang::runtime::str::toString("Hello") << std::endl;
    }
    return 0;
}
