// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>

class Calculator {
public:
    virtual double compute(double x, double y) {
        return (x + (y * 2));
    }

};

double add(double a, double b) {
    return (a + b);
}

std::string greet(std::string name) {
    return ("Bonjour, " + name);
}

double square(double n) {
    return (n * n);
}

int main() {
    auto result = add(10, 32);
    std::cout << result << std::endl;
    auto message = greet("AFRILANG");
    std::cout << message << std::endl;
    auto squared = square(7);
    std::cout << squared << std::endl;
    Calculator calc;
    std::cout << calc.compute(5, 3) << std::endl;
    return 0;
}
