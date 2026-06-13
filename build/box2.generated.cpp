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

    virtual double get() {
        #line 4 "/tmp/box2.afr"
        return 42;
    }

};

int main() {
    return 0;
}
