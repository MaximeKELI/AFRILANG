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

/** Convertible to any T; always throws. Used when codegen must not emit unchecked []. */
struct IndexingUnsupported {
    template<typename T>
    [[noreturn]] operator T() const {
        throw std::logic_error("indexing unsupported");
    }
};

} // namespace runtime
} // namespace afrilang
