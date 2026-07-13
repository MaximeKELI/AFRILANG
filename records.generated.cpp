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

struct Point {
    double x;
    double y;
};

int main() {
    #line 6 "/home/admin20/AFRILANG/./examples/records.afr"
    double px = 10LL;
    #line 7 "/home/admin20/AFRILANG/./examples/records.afr"
    double py = 20LL;
    #line 9 "/home/admin20/AFRILANG/./examples/records.afr"
    std::cout << px << std::endl;
    #line 10 "/home/admin20/AFRILANG/./examples/records.afr"
    std::cout << py << std::endl;
    #line 11 "/home/admin20/AFRILANG/./examples/records.afr"
    std::cout << (px + py) << std::endl;
    #line 13 "/home/admin20/AFRILANG/./examples/records.afr"
    double dist = ((px * px) + (py * py));
    #line 14 "/home/admin20/AFRILANG/./examples/records.afr"
    std::cout << dist << std::endl;
    return 0;
}
