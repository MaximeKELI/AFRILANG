// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include <memory>
#include "str.hpp"

namespace Shapes {
} // namespace Shapes

struct Kind {
    enum class Tag { Circle, Square };
    Tag tag;
    static Kind make_Circle() {
        Kind v;
        v.tag = Tag::Circle;
        return v;
    }
    static Kind make_Square() {
        Kind v;
        v.tag = Tag::Square;
        return v;
    }
};

class Speakable {
public:
    virtual ~Speakable() = default;
    virtual void speak() = 0;
};

class Named {
public:
    virtual ~Named() = default;
    virtual std::string getName() = 0;
};

class Dog : public Speakable, public Named {
public:
    virtual ~Dog() = default;

    virtual void speak() override {
        #line 11 "/home/maxime/AFRILANG/build/../examples/traits_demo.afr"
        std::cout << "Woof!" << std::endl;
    }

    virtual std::string getName() override {
        #line 15 "/home/maxime/AFRILANG/build/../examples/traits_demo.afr"
        return "Rex";
    }

};

namespace Shapes {
} // namespace Shapes

int main() {
    #line 19 "/home/maxime/AFRILANG/build/../examples/traits_demo.afr"
    std::unique_ptr<Speakable> pet = std::make_unique<Dog>();
    #line 20 "/home/maxime/AFRILANG/build/../examples/traits_demo.afr"
    pet->speak();
    #line 22 "/home/maxime/AFRILANG/build/../examples/traits_demo.afr"
    std::vector<std::unique_ptr<Speakable>> speakers;
    speakers.push_back(std::unique_ptr<Speakable>(std::make_unique<Dog>()));
    #line 23 "/home/maxime/AFRILANG/build/../examples/traits_demo.afr"
    for (auto& _afr_ptr : speakers) {
        auto& s = *_afr_ptr;
        #line 24 "/home/maxime/AFRILANG/build/../examples/traits_demo.afr"
        s.speak();
    }
    #line 34 "/home/maxime/AFRILANG/build/../examples/traits_demo.afr"
    Kind k = Kind::make_Circle();
    #line 42 "/home/maxime/AFRILANG/build/../examples/traits_demo.afr"
        {
        Kind _afr_match = k;
        if (_afr_match.tag == Kind::Tag::Circle) {
            #line 37 "/home/maxime/AFRILANG/build/../examples/traits_demo.afr"
            std::cout << "circle" << std::endl;
        }        else if (_afr_match.tag == Kind::Tag::Square) {
            #line 40 "/home/maxime/AFRILANG/build/../examples/traits_demo.afr"
            std::cout << "square" << std::endl;
        }
    }
    return 0;
}
