// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>

class Person {
public:
    virtual void speak() {
        std::cout << "Bonjour, je suis une Personne" << std::endl;
    }

    virtual void greet() {
        std::cout << "Bienvenue en AFRILANG!" << std::endl;
    }

};

class Dog {
public:
    virtual void speak() {
        std::cout << "Woof!" << std::endl;
    }

};

int main() {
    Person person;
    person.speak();
    person.greet();
    Dog dog;
    dog.speak();
    return 0;
}
