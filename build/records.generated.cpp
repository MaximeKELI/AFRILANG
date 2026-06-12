// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>

struct Point {
    double x;
    double y;
};

int main() {
    double px = 10;
    double py = 20;
    std::cout << px << std::endl;
    std::cout << py << std::endl;
    std::cout << (px + py) << std::endl;
    double dist = ((px * px) + (py * py));
    std::cout << dist << std::endl;
    return 0;
}
