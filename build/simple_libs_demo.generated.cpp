// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "simple_libs.hpp"
#include "str.hpp"

namespace celsius {
} // namespace celsius

namespace upper {
} // namespace upper

namespace trig {
} // namespace trig

namespace hex {
} // namespace hex

namespace i18n {
} // namespace i18n

namespace quiz {
} // namespace quiz

namespace format {
} // namespace format

namespace celsius {
    double cToF(double c) {
        return afrilang::runtime::celsius::cToF(c);
    }

    double fToC(double f) {
        return afrilang::runtime::celsius::fToC(f);
    }

} // namespace celsius

namespace upper {
    std::string toUpper(std::string s) {
        return afrilang::runtime::upper::toUpper(s);
    }

    std::string toLower(std::string s) {
        return afrilang::runtime::upper::toLower(s);
    }

} // namespace upper

namespace trig {
    double sinDeg(double deg) {
        return afrilang::runtime::trig::sinDeg(deg);
    }

    double cosDeg(double deg) {
        return afrilang::runtime::trig::cosDeg(deg);
    }

} // namespace trig

namespace hex {
    std::string toHex(double n) {
        return afrilang::runtime::hex::toHex(n);
    }

    double fromHex(std::string s) {
        return afrilang::runtime::hex::fromHex(s);
    }

} // namespace hex

namespace i18n {
    std::string greetFr(std::string name) {
        return afrilang::runtime::i18n::greetFr(name);
    }

    std::string greetEn(std::string name) {
        return afrilang::runtime::i18n::greetEn(name);
    }

} // namespace i18n

namespace quiz {
    double scorePercent(double correct, double total) {
        return afrilang::runtime::quiz::scorePercent(correct, total);
    }

    bool isPerfect(double correct, double total) {
        return afrilang::runtime::quiz::isPerfect(correct, total);
    }

} // namespace quiz

namespace format {
    std::string formatNumber(double n, double decimals) {
        return afrilang::runtime::format::formatNumber(n, decimals);
    }

    std::string formatPercent(double n) {
        return afrilang::runtime::format::formatPercent(n);
    }

} // namespace format

using namespace format;
using namespace quiz;
using namespace i18n;
using namespace hex;
using namespace trig;
using namespace upper;
using namespace celsius;

int main() {
    #line 9 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
        #line 10 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
        #line 11 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
        #line 12 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
        #line 13 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
        #line 14 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
        #line 15 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
        #line 17 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
    auto tempF = celsius::cToF(20);
    #line 18 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
    std::cout << format::formatNumber(tempF, 1) << std::endl;
    #line 20 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
    auto greeting = i18n::greetFr("AFRILANG");
    #line 21 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
    std::cout << greeting << std::endl;
    #line 23 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
    auto label = upper::toUpper("bonjour");
    #line 24 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
    std::cout << label << std::endl;
    #line 26 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
    auto angle = trig::sinDeg(90);
    #line 27 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
    std::cout << format::formatNumber(angle, 4) << std::endl;
    #line 29 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
    auto code = hex::toHex(255);
    #line 30 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
    std::cout << code << std::endl;
    #line 32 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
    auto score = quiz::scorePercent(8, 10);
    #line 33 "/home/maxime/AFRILANG/build/../examples/simple_libs_demo.afr"
    std::cout << format::formatNumber(score, 1) << std::endl;
    return 0;
}
