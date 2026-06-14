// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "str.hpp"

struct Point {
    double x;
    double y;
};

int main() {
    #line 6 "/home/maxime/AFRILANG/examples/records.afr"
    double px = 10;
    #line 7 "/home/maxime/AFRILANG/examples/records.afr"
    double py = 20;
    #line 9 "/home/maxime/AFRILANG/examples/records.afr"
    std::cout << px << std::endl;
    #line 10 "/home/maxime/AFRILANG/examples/records.afr"
    std::cout << py << std::endl;
    #line 11 "/home/maxime/AFRILANG/examples/records.afr"
    std::cout << (px + py) << std::endl;
    #line 13 "/home/maxime/AFRILANG/examples/records.afr"
    double dist = ((px * px) + (py * py));
    #line 14 "/home/maxime/AFRILANG/examples/records.afr"
    std::cout << dist << std::endl;
    return 0;
}
