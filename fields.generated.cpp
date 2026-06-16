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

class Person {
public:
    virtual ~Person() = default;

    std::string name;
    double age;

    Person(std::string aName, double aAge) {
        #line 6 "/home/maxime/AFRILANG/examples/fields.afr"
        name = aName;
        #line 7 "/home/maxime/AFRILANG/examples/fields.afr"
        age = aAge;
    }

    virtual void greet() {
        #line 11 "/home/maxime/AFRILANG/examples/fields.afr"
        std::cout << name << std::endl;
        #line 12 "/home/maxime/AFRILANG/examples/fields.afr"
        std::cout << age << std::endl;
    }

};

int main() {
    #line 16 "/home/maxime/AFRILANG/examples/fields.afr"
    std::unique_ptr<Person> bob = std::make_unique<Person>("Bob", 25LL);
    #line 17 "/home/maxime/AFRILANG/examples/fields.afr"
    bob->greet();
    #line 18 "/home/maxime/AFRILANG/examples/fields.afr"
    std::cout << bob->name << std::endl;
    return 0;
}
