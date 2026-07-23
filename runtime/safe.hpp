#pragma once

#include <optional>
#include <stdexcept>
#include <utility>

namespace afrilang {
namespace runtime {

template<typename T>
T optionalRequire(const std::optional<T>& opt) {
    if (!opt.has_value()) {
        throw std::out_of_range("optional value is nothing");
    }
    return *opt;
}

template<typename T>
T optionalRequire(std::optional<T>&& opt) {
    if (!opt.has_value()) {
        throw std::out_of_range("optional value is nothing");
    }
    return *std::move(opt);
}

} // namespace runtime
} // namespace afrilang
