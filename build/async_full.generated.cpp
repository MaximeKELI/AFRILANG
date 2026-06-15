// Code généré par le compilateur AFRILANG
// Ne pas modifier manuellement

#include <iostream>
#include <string>
#include <vector>
#include <cstdint>
#include <unordered_map>
#include <stdexcept>
#include <functional>
#include "async.hpp"
#include "str.hpp"
#include "result.hpp"

namespace async {
    afrilang::runtime::async::Task<void> sleep(double ms) {
        return afrilang::runtime::async::sleep(ms);
    }

} // namespace async

afrilang::runtime::async::Task<afrilang::runtime::AfrResult_number> afr_delayedValue(double ms) {
    #line 8 "/home/maxime/AFRILANG/build/../examples/async_full.afr"
    if ((ms < 0LL)) {
        #line 7 "/home/maxime/AFRILANG/build/../examples/async_full.afr"
        afrilang::runtime::AfrResult_number _result;
        _result.isError = true;
        _result.message = "negative delay";
        co_return _result;
    }
    #line 9 "/home/maxime/AFRILANG/build/../examples/async_full.afr"
    co_await async::sleep(ms);
    #line 10 "/home/maxime/AFRILANG/build/../examples/async_full.afr"
    afrilang::runtime::AfrResult_number _result;
    _result.value = (ms * 2LL);
    co_return _result;
}

afrilang::runtime::async::Task<void> afr_runAll() {
    #line 14 "/home/maxime/AFRILANG/build/../examples/async_full.afr"
    auto r = co_await afr_delayedValue(5LL);
    #line 19 "/home/maxime/AFRILANG/build/../examples/async_full.afr"
    if (r.isError) {
        #line 16 "/home/maxime/AFRILANG/build/../examples/async_full.afr"
        std::cout << r.message << std::endl;
    } else {
        #line 18 "/home/maxime/AFRILANG/build/../examples/async_full.afr"
        std::cout << r.value << std::endl;
    }
    co_return;
}

static int afr_tests_failed = 0;

void afr_test_async_await_in_test() {
    afrilang::runtime::async::run([]() -> afrilang::runtime::async::Task<void> {
        #line 23 "/home/maxime/AFRILANG/build/../examples/async_full.afr"
        auto r = co_await afr_delayedValue(1LL);
        #line 24 "/home/maxime/AFRILANG/build/../examples/async_full.afr"
        if (!((r.value == 2LL))) {
            std::cerr << "ASSERT FAILED" << std::endl;
            ++afr_tests_failed;
            co_return;
        }
        co_return;
    }());
}

using namespace async;

int main() {
    afrilang::runtime::async::run([]() -> afrilang::runtime::async::Task<void> {
        #line 3 "/home/maxime/AFRILANG/build/../examples/async_full.afr"
                #line 27 "/home/maxime/AFRILANG/build/../examples/async_full.afr"
        co_await afr_runAll();
        co_return;
    }());
    afr_test_async_await_in_test();
    if (afr_tests_failed > 0) return 1;
    return 0;
}
