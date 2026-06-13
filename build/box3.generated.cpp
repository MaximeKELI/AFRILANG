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

    virtual T get() {
        #line 4 "/tmp/box3.afr"
        return 42;
    }

};

int main() {
    return 0;
}
