#pragma once

#include <string>

namespace afrilang {
namespace runtime {

template<typename T>
struct AfrResult {
    bool isError = false;
    std::string message;
    T value{};
};

using AfrResult_number = AfrResult<double>;
using AfrResult_text = AfrResult<std::string>;
using AfrResult_bool = AfrResult<bool>;

} // namespace runtime
} // namespace afrilang
