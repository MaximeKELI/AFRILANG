#pragma once

#include <stdexcept>
#include <string>

namespace afrilang {
namespace runtime {

template<typename T>
struct AfrResult {
    bool isError = false;
    std::string message;
    T value{};

    const T& requireValue() const {
        if (isError) {
            throw std::runtime_error(message.empty() ? "result is error" : message);
        }
        return value;
    }

    T& requireValue() {
        if (isError) {
            throw std::runtime_error(message.empty() ? "result is error" : message);
        }
        return value;
    }
};

using AfrResult_number = AfrResult<double>;
using AfrResult_text = AfrResult<std::string>;
using AfrResult_bool = AfrResult<bool>;

} // namespace runtime
} // namespace afrilang
