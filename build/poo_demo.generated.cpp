// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "str.hpp"

class Animal {
public:
    virtual void speak() {
        #line 3 "/home/maxime/AFRILANG/build/../examples/poo_demo.afr"
        std::cout << "..." << std::endl;
    }

};

class Dog : public Animal {
public:
    std::string name;

    Dog(std::string aName) {
        #line 11 "/home/maxime/AFRILANG/build/../examples/poo_demo.afr"
        name = aName;
    }

    virtual void speak() override {
        #line 15 "/home/maxime/AFRILANG/build/../examples/poo_demo.afr"
        std::cout << (name + " says Woof!") << std::endl;
    }

};

class Cat : public Animal {
public:
    virtual void speak() override {
        #line 21 "/home/maxime/AFRILANG/build/../examples/poo_demo.afr"
        std::cout << "Meow!" << std::endl;
    }

};

int main() {
    #line 25 "/home/maxime/AFRILANG/build/../examples/poo_demo.afr"
    auto rex = Dog("Rex");
    #line 26 "/home/maxime/AFRILANG/build/../examples/poo_demo.afr"
    rex.speak();
    #line 28 "/home/maxime/AFRILANG/build/../examples/poo_demo.afr"
    Cat whiskers;
    #line 29 "/home/maxime/AFRILANG/build/../examples/poo_demo.afr"
    whiskers.speak();
    #line 31 "/home/maxime/AFRILANG/build/../examples/poo_demo.afr"
    std::cout << "POO demo complete" << std::endl;
    return 0;
}
