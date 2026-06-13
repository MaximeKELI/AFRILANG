// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "str.hpp"

class Speakable {
public:
    virtual ~Speakable() = default;
    virtual void speak() = 0;
};

class Named {
public:
    virtual ~Named() = default;
    virtual std::string getName() = 0;
};

class Animal {
public:
    virtual void speak() {
        #line 11 "/home/maxime/AFRILANG/build/../examples/interfaces.afr"
        std::cout << "..." << std::endl;
    }

};

class Dog : public Animal, public Speakable, public Named {
public:
    virtual void speak() override {
        #line 17 "/home/maxime/AFRILANG/build/../examples/interfaces.afr"
        std::cout << "Woof!" << std::endl;
    }

    virtual std::string getName() override {
        #line 21 "/home/maxime/AFRILANG/build/../examples/interfaces.afr"
        return "Rex";
    }

};

int main() {
    #line 25 "/home/maxime/AFRILANG/build/../examples/interfaces.afr"
    Dog dog;
    #line 26 "/home/maxime/AFRILANG/build/../examples/interfaces.afr"
    dog.speak();
    #line 27 "/home/maxime/AFRILANG/build/../examples/interfaces.afr"
    std::cout << dog.getName() << std::endl;
    return 0;
}
