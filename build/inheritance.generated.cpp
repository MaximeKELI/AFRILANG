// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>

class Animal {
public:
    virtual void speak() {
        std::cout << "..." << std::endl;
    }

};

class Dog : public Animal {
public:
    virtual void speak() override {
        std::cout << "Woof!" << std::endl;
    }

    virtual std::string breed() {
        return "Labrador";
    }

};

class Cat : public Animal {
public:
    virtual void speak() override {
        std::cout << "Meow!" << std::endl;
    }

};

int main() {
    Dog animals;
    animals.speak();
    std::cout << animals.breed() << std::endl;
    Cat cat;
    cat.speak();
    Animal animal;
    animal.speak();
    return 0;
}
