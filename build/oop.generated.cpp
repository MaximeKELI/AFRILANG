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

class Person {
public:
    virtual void speak() {
        #line 3 "/home/maxime/AFRILANG/build/../examples/oop.afr"
        std::cout << "Bonjour, je suis une Personne" << std::endl;
    }

    virtual void greet() {
        #line 7 "/home/maxime/AFRILANG/build/../examples/oop.afr"
        std::cout << "Bienvenue en AFRILANG!" << std::endl;
    }

};

class Dog {
public:
    virtual void speak() {
        #line 13 "/home/maxime/AFRILANG/build/../examples/oop.afr"
        std::cout << "Woof!" << std::endl;
    }

};

int main() {
    #line 17 "/home/maxime/AFRILANG/build/../examples/oop.afr"
    std::unique_ptr<Person> person = std::make_unique<Person>();
    #line 18 "/home/maxime/AFRILANG/build/../examples/oop.afr"
    person->speak();
    #line 19 "/home/maxime/AFRILANG/build/../examples/oop.afr"
    person->greet();
    #line 21 "/home/maxime/AFRILANG/build/../examples/oop.afr"
    std::unique_ptr<Dog> dog = std::make_unique<Dog>();
    #line 22 "/home/maxime/AFRILANG/build/../examples/oop.afr"
    dog->speak();
    return 0;
}
