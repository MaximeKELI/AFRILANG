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

template<typename T>
class Box {
public:
    virtual ~Box() = default;

    T data;

    Box(const T& v) {
        #line 5 "/home/maxime/AFRILANG/build/../examples/generic_class.afr"
        data = v;
    }

    virtual T get() {
        #line 9 "/home/maxime/AFRILANG/build/../examples/generic_class.afr"
        return data;
    }

};

int main() {
    #line 13 "/home/maxime/AFRILANG/build/../examples/generic_class.afr"
    std::unique_ptr<Box<double>> numbers = std::make_unique<Box<double>>(42);
    #line 14 "/home/maxime/AFRILANG/build/../examples/generic_class.afr"
    std::cout << numbers->get() << std::endl;
    #line 16 "/home/maxime/AFRILANG/build/../examples/generic_class.afr"
    std::unique_ptr<Box<std::string>> label = std::make_unique<Box<std::string>>("hello");
    #line 17 "/home/maxime/AFRILANG/build/../examples/generic_class.afr"
    std::cout << label->get() << std::endl;
    #line 19 "/home/maxime/AFRILANG/build/../examples/generic_class.afr"
    std::cout << "generic class complete" << std::endl;
    return 0;
}
