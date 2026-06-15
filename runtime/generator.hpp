#pragma once

#include <coroutine>
#include <cstddef>
#include <exception>
#include <optional>
#include <stdexcept>
#include <utility>
#include <vector>

namespace afrilang::runtime::generator {

template<typename T>
class Generator {
public:
    struct promise_type {
        std::optional<T> current;
        std::exception_ptr exception;

        Generator get_return_object() {
            return Generator{std::coroutine_handle<promise_type>::from_promise(*this)};
        }

        std::suspend_always initial_suspend() noexcept { return {}; }
        std::suspend_always final_suspend() noexcept { return {}; }
        void return_void() noexcept {}
        void unhandled_exception() { exception = std::current_exception(); }

        std::suspend_always yield_value(T value) {
            current = std::move(value);
            return {};
        }
    };

    using handle_type = std::coroutine_handle<promise_type>;

    Generator() = default;
    explicit Generator(handle_type handle) : handle_(handle) {}

    Generator(Generator&& other) noexcept : handle_(other.handle_) { other.handle_ = nullptr; }

    Generator& operator=(Generator&& other) noexcept {
        if (handle_) handle_.destroy();
        handle_ = other.handle_;
        other.handle_ = nullptr;
        return *this;
    }

    ~Generator() {
        if (handle_) handle_.destroy();
    }

    Generator(const Generator&) = delete;
    Generator& operator=(const Generator&) = delete;

    bool advance() {
        if (!handle_ || handle_.done()) return false;
        handle_.promise().current.reset();
        handle_.resume();
        if (handle_.promise().exception) {
            std::rethrow_exception(handle_.promise().exception);
        }
        return handle_.promise().current.has_value() || !handle_.done();
    }

    bool hasNext() {
        if (!handle_ || handle_.done()) return false;
        if (!handle_.promise().current.has_value()) {
            return advance();
        }
        return true;
    }

    T next() {
        if (!hasNext()) {
            throw std::runtime_error("generator: fin de séquence");
        }
        T value = std::move(*handle_.promise().current);
        handle_.promise().current.reset();
        return value;
    }

    T at(std::size_t index) {
        while (cache_.size() <= index) {
            if (!hasNext()) {
                throw std::runtime_error("generator: index hors limites");
            }
            cache_.push_back(next());
        }
        return cache_[index];
    }

    std::vector<T> collect() {
        std::vector<T> out;
        while (hasNext()) {
            out.push_back(next());
        }
        return out;
    }

private:
    handle_type handle_{nullptr};
    std::vector<T> cache_;
};

} // namespace afrilang::runtime::generator
