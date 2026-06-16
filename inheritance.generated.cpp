// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include <memory>
#include "str.hpp"

class Animal {
public:
    virtual ~Animal() = default;

    virtual void speak() {
        #line 3 "/home/maxime/AFRILANG/examples/inheritance.afr"
        std::cout << "..." << std::endl;
    }

};

class Dog : public Animal {
public:
    virtual ~Dog() = default;

    virtual void speak() override {
        #line 9 "/home/maxime/AFRILANG/examples/inheritance.afr"
        std::cout << "Woof!" << std::endl;
    }

    virtual std::string breed() {
        #line 13 "/home/maxime/AFRILANG/examples/inheritance.afr"
        return "Labrador";
    }

};

class Cat : public Animal {
public:
    virtual ~Cat() = default;

    virtual void speak() override {
        #line 19 "/home/maxime/AFRILANG/examples/inheritance.afr"
        std::cout << "Meow!" << std::endl;
    }

};

int main() {
    #line 23 "/home/maxime/AFRILANG/examples/inheritance.afr"
    std::unique_ptr<Dog> animals = std::make_unique<Dog>();
    #line 24 "/home/maxime/AFRILANG/examples/inheritance.afr"
    animals->speak();
    #line 25 "/home/maxime/AFRILANG/examples/inheritance.afr"
    std::cout << animals->breed() << std::endl;
    #line 27 "/home/maxime/AFRILANG/examples/inheritance.afr"
    std::unique_ptr<Cat> cat = std::make_unique<Cat>();
    #line 28 "/home/maxime/AFRILANG/examples/inheritance.afr"
    cat->speak();
    #line 30 "/home/maxime/AFRILANG/examples/inheritance.afr"
    std::unique_ptr<Animal> animal = std::make_unique<Animal>();
    #line 31 "/home/maxime/AFRILANG/examples/inheritance.afr"
    animal->speak();
    return 0;
}
