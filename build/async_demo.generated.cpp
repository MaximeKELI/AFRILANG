// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "async.hpp"
#include "str.hpp"

namespace async {
} // namespace async

namespace async {
    afrilang::runtime::async::Task<void> sleep(double ms) {
        return afrilang::runtime::async::sleep(ms);
    }

} // namespace async

afrilang::runtime::async::Task<std::string> afr_waitAndReply(double ms) {
    #line 6 "/home/maxime/AFRILANG/build/../examples/async_demo.afr"
    co_await async::sleep(ms);
    #line 7 "/home/maxime/AFRILANG/build/../examples/async_demo.afr"
    co_return "done";
}

afrilang::runtime::async::Task<void> afr_runDemo() {
    #line 11 "/home/maxime/AFRILANG/build/../examples/async_demo.afr"
    std::cout << "starting async demo" << std::endl;
    #line 12 "/home/maxime/AFRILANG/build/../examples/async_demo.afr"
    auto msg = co_await afr_waitAndReply(10);
    #line 13 "/home/maxime/AFRILANG/build/../examples/async_demo.afr"
    std::cout << msg << std::endl;
    #line 14 "/home/maxime/AFRILANG/build/../examples/async_demo.afr"
    co_await async::sleep(5);
    #line 15 "/home/maxime/AFRILANG/build/../examples/async_demo.afr"
    std::cout << "async demo complete" << std::endl;
    co_return;
}

using namespace async;

int main() {
    afrilang::runtime::async::run([]() -> afrilang::runtime::async::Task<void> {
        #line 3 "/home/maxime/AFRILANG/build/../examples/async_demo.afr"
                #line 18 "/home/maxime/AFRILANG/build/../examples/async_demo.afr"
        co_await afr_runDemo();
        co_return;
    }());
    return 0;
}
