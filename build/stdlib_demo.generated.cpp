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
#include "async.hpp"
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

    afrilang::runtime::async::Task<std::string> readFileAsync(std::string path) {
        return afrilang::runtime::async::runBlockingTask([path]() { return afrilang::runtime::io::readFile(path); });
    }

} // namespace io

namespace json {
    afrilang::runtime::json::Value parse(std::string text) {
        return afrilang::runtime::json::parseValue(text);
    }

    std::string stringify(afrilang::runtime::json::Value value) {
        return afrilang::runtime::json::stringifyValue(value);
    }

    std::string getString(afrilang::runtime::json::Value value, std::string key) {
        return afrilang::runtime::json::getStringFrom(value, key);
    }

    double getNumber(afrilang::runtime::json::Value value, std::string key) {
        return afrilang::runtime::json::getNumberFrom(value, key);
    }

    std::int64_t getInt(afrilang::runtime::json::Value value, std::string key) {
        return afrilang::runtime::json::getIntFrom(value, key);
    }

    afrilang::runtime::json::Value makeObject(std::string key, std::string value) {
        return afrilang::runtime::json::makeObjectValue(key, value);
    }

} // namespace json

using namespace json;
using namespace io;

int main() {
    afrilang::runtime::async::run([]() -> afrilang::runtime::async::Task<void> {
        #line 4 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
                #line 5 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
                #line 7 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
        afrilang::runtime::json::Value doc = json::makeObject("lang", "AFRILANG");
        #line 8 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
        std::cout << json::getString(doc, "lang") << std::endl;
        #line 10 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
        afrilang::runtime::json::Value roundtrip = json::parse(json::stringify(doc));
        #line 11 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
        std::cout << json::getString(roundtrip, "lang") << std::endl;
        #line 13 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
        afrilang::runtime::json::Value numDoc = json::parse("{\"value\": 42}");
        #line 14 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
        std::cout << json::getNumber(numDoc, "value") << std::endl;
        #line 16 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
        bool ok = io::fileExists("/tmp/afrilang_test.txt");
        #line 19 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
        if ((ok == false)) {
            #line 18 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
            io::writeFile("/tmp/afrilang_test.txt", "Hello from stdlib io");
        }
        #line 21 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
        std::string fileContent = io::readFile("/tmp/afrilang_test.txt");
        #line 22 "/home/maxime/AFRILANG/build/../examples/stdlib_demo.afr"
        std::cout << fileContent << std::endl;
        co_return;
    }());
    return 0;
}
