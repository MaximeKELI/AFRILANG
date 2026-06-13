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
        #line 6 "/home/maxime/AFRILANG/build/../examples/fields.afr"
        name = aName;
        #line 7 "/home/maxime/AFRILANG/build/../examples/fields.afr"
        age = aAge;
    }

    virtual void greet() {
        #line 11 "/home/maxime/AFRILANG/build/../examples/fields.afr"
        std::cout << name << std::endl;
        #line 12 "/home/maxime/AFRILANG/build/../examples/fields.afr"
        std::cout << age << std::endl;
    }

};

int main() {
    #line 16 "/home/maxime/AFRILANG/build/../examples/fields.afr"
    Person person(std::string{}, double{});
    #line 17 "/home/maxime/AFRILANG/build/../examples/fields.afr"
    person.greet();
    #line 19 "/home/maxime/AFRILANG/build/../examples/fields.afr"
    Person bob(std::string{}, double{});
    #line 20 "/home/maxime/AFRILANG/build/../examples/fields.afr"
    bob.name = "Bob";
    #line 21 "/home/maxime/AFRILANG/build/../examples/fields.afr"
    std::cout << bob.name << std::endl;
    return 0;
}
