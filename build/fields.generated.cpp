// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>

class Person {
public:
    std::string name;
    double age;

    Person(std::string aName, double aAge) {
        name = aName;
        age = aAge;
    }

    virtual void greet() {
        std::cout << name << std::endl;
        std::cout << age << std::endl;
    }

};

int main() {
    Person person(std::string{}, double{});
    person.greet();
    Person bob(std::string{}, double{});
    bob.name = "Bob";
    std::cout << bob.name << std::endl;
    return 0;
}
