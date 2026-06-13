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

class Shape {
public:
    virtual ~Shape() = default;

    virtual double area() = 0;

};

class Circle : public Shape {
public:
    virtual ~Circle() = default;

    double radius;

    Circle(double r) {
        #line 9 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
        radius = r;
    }

    virtual double area() override {
        #line 13 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
        return ((3.14159 * radius) * radius);
    }

};

class Counter {
public:
    virtual ~Counter() = default;

    inline static double count = 0;

    static double nextId() {
        #line 21 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
        Counter::count = (Counter::count + 1);
        #line 22 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
        return Counter::count;
    }

};

class Animal {
public:
    virtual ~Animal() = default;

    std::string species;

    Animal(std::string aSpecies) {
        #line 30 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
        species = aSpecies;
    }

    virtual void describe() {
        #line 34 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
        std::cout << species << std::endl;
    }

};

class Dog : public Animal {
public:
    virtual ~Dog() = default;

    std::string name;

    Dog(std::string aSpecies, std::string aName) : Animal(aSpecies) {
        #line 43 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
        name = aName;
    }

    virtual void describe() override {
        #line 47 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
        Animal::describe();
        #line 48 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
        std::cout << (name + " (dog)") << std::endl;
    }

};

int main() {
    #line 52 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
    std::unique_ptr<Circle> circle = std::make_unique<Circle>(5);
    #line 53 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
    std::cout << circle->area() << std::endl;
    #line 55 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
    std::cout << Counter::nextId() << std::endl;
    #line 56 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
    std::cout << Counter::nextId() << std::endl;
    #line 58 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
    std::unique_ptr<Dog> rex = std::make_unique<Dog>("Canis", "Rex");
    #line 59 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
    rex->describe();
    #line 61 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
    std::unique_ptr<Animal> pet = std::make_unique<Dog>("Canis", "Buddy");
    #line 62 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
    pet->describe();
    #line 64 "/home/maxime/AFRILANG/build/../examples/oop_full.afr"
    std::cout << "OOP full demo complete" << std::endl;
    return 0;
}
