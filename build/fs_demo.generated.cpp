// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "io.hpp"
#include "fs.hpp"
#include "async.hpp"
#include "str.hpp"

namespace fs {
    std::vector<std::string> listDir(std::string path) {
        return afrilang::runtime::fs::listDir(path);
    }

    bool makeDir(std::string path) {
        return afrilang::runtime::fs::makeDir(path);
    }

    bool removeFile(std::string path) {
        return afrilang::runtime::fs::removeFile(path);
    }

    double fileSize(std::string path) {
        return afrilang::runtime::fs::fileSize(path);
    }

} // namespace fs

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

using namespace io;
using namespace fs;

int main() {
    afrilang::runtime::async::run([]() -> afrilang::runtime::async::Task<void> {
        #line 4 "/home/maxime/AFRILANG/build/../examples/fs_demo.afr"
                #line 5 "/home/maxime/AFRILANG/build/../examples/fs_demo.afr"
                #line 7 "/home/maxime/AFRILANG/build/../examples/fs_demo.afr"
        std::string dir = "/tmp/afrilang_fs_demo";
        #line 11 "/home/maxime/AFRILANG/build/../examples/fs_demo.afr"
        if ((io::fileExists(dir) == true)) {
            #line 10 "/home/maxime/AFRILANG/build/../examples/fs_demo.afr"
            fs::removeFile((dir + "/sample.txt"));
        }
        #line 13 "/home/maxime/AFRILANG/build/../examples/fs_demo.afr"
        std::cout << fs::makeDir(dir) << std::endl;
        #line 14 "/home/maxime/AFRILANG/build/../examples/fs_demo.afr"
        io::writeFile((dir + "/sample.txt"), "filesystem demo");
        #line 16 "/home/maxime/AFRILANG/build/../examples/fs_demo.afr"
        std::cout << fs::fileSize((dir + "/sample.txt")) << std::endl;
        #line 18 "/home/maxime/AFRILANG/build/../examples/fs_demo.afr"
        for (auto& name : fs::listDir(dir)) {
            #line 19 "/home/maxime/AFRILANG/build/../examples/fs_demo.afr"
            std::cout << name << std::endl;
        }
        #line 22 "/home/maxime/AFRILANG/build/../examples/fs_demo.afr"
        std::cout << io::readFile((dir + "/sample.txt")) << std::endl;
        co_return;
    }());
    return 0;
}
