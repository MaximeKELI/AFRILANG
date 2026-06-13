// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "collections.hpp"
#include "args.hpp"
#include "path.hpp"
#include <memory>
#include "str.hpp"

namespace args {
} // namespace args

namespace path {
} // namespace path

class Animal {
public:
    virtual ~Animal() = default;

    virtual void speak() {
        #line 3 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
        std::cout << "..." << std::endl;
    }

};

class Dog : public Animal {
public:
    virtual ~Dog() = default;

    virtual void speak() override {
        #line 9 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
        std::cout << "Woof!" << std::endl;
    }

};

template<typename T>
class Box {
public:
    virtual ~Box() = default;

    T data;

    Box(const T& v) {
        #line 17 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
        data = v;
    }

    virtual T get() {
        #line 21 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
        return data;
    }

};

class AppConfig final {
public:
    virtual ~AppConfig() {
        #line 34 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
        std::cout << "config cleanup" << std::endl;
    }

    std::string _title;

    std::string getTitle() const {
        return _title;
    }
    void setTitle(const std::string& value) {
        _title = value;
    }

    AppConfig(std::string t) {
        #line 30 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
        setTitle(t);
    }

};

namespace args {
    double count() {
        return afrilang::runtime::args::count();
    }

    std::string at(double index) {
        return afrilang::runtime::args::at(index);
    }

    std::vector<std::string> all() {
        return afrilang::runtime::args::all();
    }

} // namespace args

namespace path {
    std::string join(std::string left, std::string right) {
        return afrilang::runtime::path::join(left, right);
    }

    std::string basename(std::string path) {
        return afrilang::runtime::path::basename(path);
    }

    std::string dirname(std::string path) {
        return afrilang::runtime::path::dirname(path);
    }

    std::string extension(std::string path) {
        return afrilang::runtime::path::extension(path);
    }

    bool isAbsolute(std::string path) {
        return afrilang::runtime::path::isAbsolute(path);
    }

} // namespace path

using namespace path;
using namespace args;

int main(int argc, char** argv) {
    afrilang::runtime::args::init(argc, argv);
    #line 38 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::vector<double> nums = {1, 2, 3};
    #line 40 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::vector<double> expanded = afrilang::runtime::collections::flatMapNumbers(nums, [&](double n) -> std::vector<double> {
    #line 41 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    return std::vector<double>{n, (n * 10)};
    });
    #line 44 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::cout << expanded.size() << std::endl;
    #line 45 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::cout << expanded[static_cast<size_t>(0)] << std::endl;
    #line 46 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::cout << expanded[static_cast<size_t>(1)] << std::endl;
    #line 47 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::cout << expanded[static_cast<size_t>(2)] << std::endl;
    #line 49 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::vector<std::string> words = {"a", "bb", "ccc"};
    #line 51 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::string joined = afrilang::runtime::collections::reduceText(words, [&](std::string acc, std::string w) -> std::string {
    #line 52 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    return ((acc + w) + "-");
    }, "");
    #line 55 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::cout << joined << std::endl;
    #line 57 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::vector<std::unique_ptr<Animal>> pets;
    pets.push_back(std::unique_ptr<Animal>(std::make_unique<Dog>()));
    pets.push_back(std::unique_ptr<Animal>(std::make_unique<Dog>()));
    #line 59 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    for (auto& _afr_ptr : pets) {
        auto& pet = *_afr_ptr;
        #line 60 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
        pet.speak();
    }
    #line 63 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::unique_ptr<Box<double>> box = std::make_unique<Box<double>>(99);
    #line 64 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::cout << box->get() << std::endl;
    #line 66 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::unique_ptr<AppConfig> cfg = std::make_unique<AppConfig>("AFRILANG");
    #line 67 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::cout << cfg->getTitle() << std::endl;
    #line 71 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
        #line 72 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
        #line 74 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::cout << args::count() << std::endl;
    #line 75 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::cout << path::join("examples", "phase11_demo.afr") << std::endl;
    #line 77 "/home/maxime/AFRILANG/examples/phase11_demo.afr"
    std::cout << "phase 11 complete" << std::endl;
    return 0;
}
