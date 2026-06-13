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

class Animal {
public:
    virtual ~Animal() = default;

    virtual void speak() {
        #line 3 "/home/maxime/AFRILANG/build/../examples/poo_demo.afr"
        std::cout << "..." << std::endl;
    }

};

class Dog : public Animal {
public:
    virtual ~Dog() = default;

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
    virtual ~Cat() = default;

    virtual void speak() override {
        #line 21 "/home/maxime/AFRILANG/build/../examples/poo_demo.afr"
        std::cout << "Meow!" << std::endl;
    }

};

int main() {
    #line 25 "/home/maxime/AFRILANG/build/../examples/poo_demo.afr"
    std::unique_ptr<Dog> rex = std::make_unique<Dog>("Rex");
    #line 26 "/home/maxime/AFRILANG/build/../examples/poo_demo.afr"
    rex->speak();
    #line 28 "/home/maxime/AFRILANG/build/../examples/poo_demo.afr"
    std::unique_ptr<Cat> whiskers = std::make_unique<Cat>();
    #line 29 "/home/maxime/AFRILANG/build/../examples/poo_demo.afr"
    whiskers->speak();
    #line 31 "/home/maxime/AFRILANG/build/../examples/poo_demo.afr"
    std::cout << "POO demo complete" << std::endl;
    return 0;
}
