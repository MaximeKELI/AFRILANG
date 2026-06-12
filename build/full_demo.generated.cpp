// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>

namespace Utils {
} // namespace Utils

namespace Utils {
    double twice(double x) {
        return (x * 2);
    }

} // namespace Utils

double sum2(double a, double b) {
    return (a + b);
}

using namespace Utils;

int main() {
        bool active = true;
    if ((active == true)) {
        std::cout << "System active" << std::endl;
    } else {
        std::cout << "System inactive" << std::endl;
    }
    double counter = 0;
    while ((counter < 3)) {
        std::cout << Utils::twice(counter) << std::endl;
        counter = (counter + 1);
    }
    std::vector<double> items = {1, 2, 3};
    for (auto& item : items) {
        if ((item == 2)) {
            break;
        }
        std::cout << item << std::endl;
    }
    std::cout << sum2(10, 32) << std::endl;
    std::cout << "Full demo complete" << std::endl;
    return 0;
}
