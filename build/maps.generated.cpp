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
    #line 1 "/home/maxime/AFRILANG/examples/maps.afr"
    std::unordered_map<std::string, double> scores = {{"alice", 95}, {"bob", 88}, {"carol", 91}};
    #line 3 "/home/maxime/AFRILANG/examples/maps.afr"
    std::cout << scores["alice"] << std::endl;
    #line 4 "/home/maxime/AFRILANG/examples/maps.afr"
    std::cout << scores.size() << std::endl;
    #line 6 "/home/maxime/AFRILANG/examples/maps.afr"
    scores["dave"] = 76;
    #line 7 "/home/maxime/AFRILANG/examples/maps.afr"
    std::cout << scores["dave"] << std::endl;
    #line 9 "/home/maxime/AFRILANG/examples/maps.afr"
    for (auto& _afr_pair : scores) {
        auto& name = _afr_pair.first;
        auto& score = _afr_pair.second;
        #line 10 "/home/maxime/AFRILANG/examples/maps.afr"
        std::cout << name << std::endl;
        #line 11 "/home/maxime/AFRILANG/examples/maps.afr"
        std::cout << score << std::endl;
    }
    #line 14 "/home/maxime/AFRILANG/examples/maps.afr"
    std::unordered_map<std::string, double> emptyMap = {};
    #line 15 "/home/maxime/AFRILANG/examples/maps.afr"
    std::cout << emptyMap.size() << std::endl;
    return 0;
}
