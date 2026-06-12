// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>

int main() {
    double count = 0;
    while ((count < 5)) {
        std::cout << count << std::endl;
        count = (count + 1);
    }
    std::cout << "Done counting" << std::endl;
    double score = 75;
    if ((score > 90)) {
        std::cout << "Excellent" << std::endl;
    } else {
        if ((score > 60)) {
            std::cout << "Passed" << std::endl;
        } else {
            std::cout << "Failed" << std::endl;
        }
    }
    return 0;
}
