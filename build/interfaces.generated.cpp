// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>

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
        std::cout << "..." << std::endl;
    }

};

class Dog : public Animal, public Speakable, public Named {
public:
    virtual void speak() override {
        std::cout << "Woof!" << std::endl;
    }

    virtual std::string getName() override {
        return "Rex";
    }

};

int main() {
    Dog dog;
    dog.speak();
    std::cout << dog.getName() << std::endl;
    return 0;
}
