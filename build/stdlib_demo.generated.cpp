// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "io.hpp"
#include "json.hpp"
#include "str.hpp"

namespace io {
} // namespace io

namespace json {
} // namespace json

namespace io {
    std::string readFile(std::string path) {
        return afrilang::runtime::io::readFile(path);
    }

    void writeFile(std::string path, std::string content) {
        afrilang::runtime::io::writeFile(path, content);
    }

    bool fileExists(std::string path) {
        return afrilang::runtime::io::fileExists(path);
    }

    std::string readLine() {
        return afrilang::runtime::io::readLine();
    }

} // namespace io

namespace json {
    std::string parse(std::string text) {
        return afrilang::runtime::json::parse(text);
    }

    std::string stringify(std::string value) {
        return afrilang::runtime::json::normalize(value);
    }

    std::string getString(std::string text, std::string key) {
        return afrilang::runtime::json::getString(text, key);
    }

    double getNumber(std::string text, std::string key) {
        return afrilang::runtime::json::getNumber(text, key);
    }

    std::string makeObject(std::string key, std::string value) {
        return afrilang::runtime::json::makeObject(key, value);
    }

} // namespace json

using namespace json;
using namespace io;

int main() {
    #line 4 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
        #line 5 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
        #line 7 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
    auto content = json::makeObject("lang", "AFRILANG");
    #line 8 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
    std::cout << content << std::endl;
    #line 10 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
    auto parsed = json::parse(content);
    #line 11 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
    std::cout << json::getString(parsed, "lang") << std::endl;
    #line 13 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
    auto ok = io::fileExists("/tmp/afrilang_test.txt");
    #line 16 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
    if ((ok == false)) {
        #line 15 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
        io::writeFile("/tmp/afrilang_test.txt", "Hello from stdlib io");
    }
    #line 18 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
    auto fileContent = io::readFile("/tmp/afrilang_test.txt");
    #line 19 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
    std::cout << fileContent << std::endl;
    #line 21 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
    std::cout << json::getNumber("{\"value\": 42}", "value") << std::endl;
    return 0;
}
