// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "args.hpp"
#include "path.hpp"
#include "str.hpp"

namespace args {
} // namespace args

namespace path {
} // namespace path

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
    #line 4 "/home/maxime/AFRILANG/examples/args_path_demo.afr"
        #line 5 "/home/maxime/AFRILANG/examples/args_path_demo.afr"
        #line 7 "/home/maxime/AFRILANG/examples/args_path_demo.afr"
    std::cout << args::count() << std::endl;
    #line 8 "/home/maxime/AFRILANG/examples/args_path_demo.afr"
    std::cout << path::join("home", "user") << std::endl;
    #line 10 "/home/maxime/AFRILANG/examples/args_path_demo.afr"
    std::cout << "stdlib args path complete" << std::endl;
    return 0;
}
