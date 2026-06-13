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
        #line 3 "/home/maxime/AFRILANG/build/../examples/polymorphic_list.afr"
        std::cout << "..." << std::endl;
    }

};

class Dog : public Animal {
public:
    virtual ~Dog() = default;

    virtual void speak() override {
        #line 9 "/home/maxime/AFRILANG/build/../examples/polymorphic_list.afr"
        std::cout << "Woof!" << std::endl;
    }

};

class Cat : public Animal {
public:
    virtual ~Cat() = default;

    virtual void speak() override {
        #line 15 "/home/maxime/AFRILANG/build/../examples/polymorphic_list.afr"
        std::cout << "Meow!" << std::endl;
    }

};

int main() {
    #line 19 "/home/maxime/AFRILANG/build/../examples/polymorphic_list.afr"
    std::vector<std::unique_ptr<Animal>> pets;
    pets.push_back(std::unique_ptr<Animal>(std::make_unique<Dog>()));
    pets.push_back(std::unique_ptr<Animal>(std::make_unique<Cat>()));
    #line 21 "/home/maxime/AFRILANG/build/../examples/polymorphic_list.afr"
    std::cout << pets.size() << std::endl;
    #line 23 "/home/maxime/AFRILANG/build/../examples/polymorphic_list.afr"
    for (auto& _afr_ptr : pets) {
        auto& pet = *_afr_ptr;
        #line 24 "/home/maxime/AFRILANG/build/../examples/polymorphic_list.afr"
        pet.speak();
    }
    #line 27 "/home/maxime/AFRILANG/build/../examples/polymorphic_list.afr"
    pets.push_back(std::unique_ptr<Animal>(std::make_unique<Dog>()));
    #line 29 "/home/maxime/AFRILANG/build/../examples/polymorphic_list.afr"
    std::cout << pets.size() << std::endl;
    #line 31 "/home/maxime/AFRILANG/build/../examples/polymorphic_list.afr"
    std::cout << "polymorphic lists complete" << std::endl;
    return 0;
}
