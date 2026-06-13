// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <optional>

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
    #line 6 "/home/maxime/AFRILANG/build/../examples/advanced.afr"
    Status s = Status::make_Ok();
    #line 7 "/home/maxime/AFRILANG/build/../examples/advanced.afr"
    Status e = Status::make_Error("failed");
    #line 16 "/home/maxime/AFRILANG/build/../examples/advanced.afr"
        {
        Status _afr_match = s;
        if (_afr_match.tag == Status::Tag::Ok) {
            #line 11 "/home/maxime/AFRILANG/build/../examples/advanced.afr"
            std::cout << "ok" << std::endl;
        }        else {
            #line 14 "/home/maxime/AFRILANG/build/../examples/advanced.afr"
            std::cout << "other" << std::endl;
        }
    }
    #line 25 "/home/maxime/AFRILANG/build/../examples/advanced.afr"
        {
        Status _afr_match = e;
        if (_afr_match.tag == Status::Tag::Error) {
            #line 20 "/home/maxime/AFRILANG/build/../examples/advanced.afr"
            std::cout << e.message << std::endl;
        }        else {
            #line 23 "/home/maxime/AFRILANG/build/../examples/advanced.afr"
            std::cout << "unexpected" << std::endl;
        }
    }
    #line 27 "/home/maxime/AFRILANG/build/../examples/advanced.afr"
    std::optional<std::string> nickname = std::nullopt;
    #line 32 "/home/maxime/AFRILANG/build/../examples/advanced.afr"
    if (nickname.has_value()) {
        #line 29 "/home/maxime/AFRILANG/build/../examples/advanced.afr"
        std::cout << nickname.value() << std::endl;
    } else {
        #line 31 "/home/maxime/AFRILANG/build/../examples/advanced.afr"
        std::cout << "no nickname" << std::endl;
    }
    return 0;
}
