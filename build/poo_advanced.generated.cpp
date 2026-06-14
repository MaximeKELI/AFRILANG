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

class Config final {
public:
    virtual ~Config() {
        #line 10 "/home/maxime/AFRILANG/build/../examples/poo_advanced.afr"
        std::cout << "config destroyed" << std::endl;
    }

    std::string _name;

    std::string getName() const {
        return _name;
    }
    void setName(const std::string& value) {
        _name = value;
    }

    Config(std::string n) {
        #line 6 "/home/maxime/AFRILANG/build/../examples/poo_advanced.afr"
        setName(n);
    }

};

int main() {
    #line 14 "/home/maxime/AFRILANG/build/../examples/poo_advanced.afr"
    std::unique_ptr<Config> cfg = std::make_unique<Config>("app");
    #line 15 "/home/maxime/AFRILANG/build/../examples/poo_advanced.afr"
    std::cout << cfg->getName() << std::endl;
    #line 16 "/home/maxime/AFRILANG/build/../examples/poo_advanced.afr"
    cfg->setName("server");
    #line 17 "/home/maxime/AFRILANG/build/../examples/poo_advanced.afr"
    std::cout << cfg->getName() << std::endl;
    #line 19 "/home/maxime/AFRILANG/build/../examples/poo_advanced.afr"
    std::cout << "poo advanced complete" << std::endl;
    return 0;
}
