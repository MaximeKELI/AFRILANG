// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>

int main() {
    auto age = 25;
    if ((age > 18)) {
        std::cout << "Adulte" << std::endl;
    }
    if ((age < 30)) {
        std::cout << "Jeune adulte" << std::endl;
    }
    auto score = 100;
    if ((score == 100)) {
        std::cout << "Score parfait!" << std::endl;
    }
    auto x = 10;
    auto y = 3;
    std::cout << (x + y) << std::endl;
    std::cout << (x - y) << std::endl;
    std::cout << (x * y) << std::endl;
    std::cout << (x / y) << std::endl;
    for (int _i = 0; _i < static_cast<int>(2); ++_i) {
        std::cout << "Boucle conditionnelle" << std::endl;
    }
    return 0;
}
