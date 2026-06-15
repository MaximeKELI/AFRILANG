// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include <optional>
#include "str.hpp"

struct Status {
    enum class Tag { Ok, Error };
    Tag tag;
    std::string message;
    static Status make_Ok() {
        Status v;
        v.tag = Tag::Ok;
        return v;
    }
    static Status make_Error(std::string message) {
        Status v;
        v.tag = Tag::Error;
        v.message = message;
        return v;
    }
};

namespace Calcul {
    double add(double a, double b) {
        #line 3 "/home/maxime/AFRILANG/build/../examples/language_demo.afr"
        return (a + b);
    }

    double scale(double x) {
        #line 7 "/home/maxime/AFRILANG/build/../examples/language_demo.afr"
        return (x * 2LL);
    }

    double twice(double x) {
        #line 11 "/home/maxime/AFRILANG/build/../examples/language_demo.afr"
        return Calcul::scale(x);
    }

} // namespace Calcul

template<typename T>
T afr_identity(const T& x) {
    #line 16 "/home/maxime/AFRILANG/build/../examples/language_demo.afr"
    return x;
}

using namespace Calcul;

int main() {
    #line 24 "/home/maxime/AFRILANG/build/../examples/language_demo.afr"
        #line 26 "/home/maxime/AFRILANG/build/../examples/language_demo.afr"
    std::cout << Calcul::add(3LL, 4LL) << std::endl;
    #line 27 "/home/maxime/AFRILANG/build/../examples/language_demo.afr"
    std::cout << Calcul::twice(10LL) << std::endl;
    #line 28 "/home/maxime/AFRILANG/build/../examples/language_demo.afr"
    std::cout << afr_identity<double>(42LL) << std::endl;
    #line 29 "/home/maxime/AFRILANG/build/../examples/language_demo.afr"
    std::cout << afr_identity<std::string>(std::string("bonjour")) << std::endl;
    #line 31 "/home/maxime/AFRILANG/build/../examples/language_demo.afr"
    Status e = Status::make_Error("echec");
    #line 40 "/home/maxime/AFRILANG/build/../examples/language_demo.afr"
        {
        Status _afr_match = e;
        if (_afr_match.tag == Status::Tag::Error) {
            std::string msg = _afr_match.message;
            #line 35 "/home/maxime/AFRILANG/build/../examples/language_demo.afr"
            std::cout << msg << std::endl;
        }        else {
            #line 38 "/home/maxime/AFRILANG/build/../examples/language_demo.afr"
            std::cout << "autre" << std::endl;
        }
    }
    return 0;
}
