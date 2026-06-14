// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
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

int main() {
    #line 6 "/home/maxime/AFRILANG/build/../examples/match_expr_demo.afr"
    Status s = Status::make_Ok();
    #line 7 "/home/maxime/AFRILANG/build/../examples/match_expr_demo.afr"
    Status e = Status::make_Error("failed");
    #line 9 "/home/maxime/AFRILANG/build/../examples/match_expr_demo.afr"
    std::string okLabel = ([&]() -> std::string {
    Status _afr_match = s;
    if (_afr_match.tag == Status::Tag::Ok) {
        return "success";
    }
    else {
        return "unknown";
    }
})();
    #line 16 "/home/maxime/AFRILANG/build/../examples/match_expr_demo.afr"
    std::string errLabel = ([&]() -> std::string {
    Status _afr_match = e;
    if (_afr_match.tag == Status::Tag::Error) {
        std::string msg = _afr_match.message;
        return msg;
    }
    else {
        return "no error";
    }
})();
    #line 23 "/home/maxime/AFRILANG/build/../examples/match_expr_demo.afr"
    double code = ([&]() -> double {
    Status _afr_match = s;
    if (_afr_match.tag == Status::Tag::Ok) {
        return 0;
    }
    else if (_afr_match.tag == Status::Tag::Error) {
        std::string msg = _afr_match.message;
        return 1;
    }
    throw std::runtime_error("match: cas non couvert");
})();
    #line 30 "/home/maxime/AFRILANG/build/../examples/match_expr_demo.afr"
    std::cout << okLabel << std::endl;
    #line 31 "/home/maxime/AFRILANG/build/../examples/match_expr_demo.afr"
    std::cout << errLabel << std::endl;
    #line 32 "/home/maxime/AFRILANG/build/../examples/match_expr_demo.afr"
    std::cout << code << std::endl;
    return 0;
}
