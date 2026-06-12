// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>

namespace Math {
} // namespace Math

namespace Math {
    double add(double a, double b) {
        return (a + b);
    }

    double multiply(double a, double b) {
        return (a * b);
    }

} // namespace Math

using namespace Math;

int main() {
        std::cout << Math::add(3, 4) << std::endl;
    std::cout << Math::multiply(5, 6) << std::endl;
    return 0;
}
