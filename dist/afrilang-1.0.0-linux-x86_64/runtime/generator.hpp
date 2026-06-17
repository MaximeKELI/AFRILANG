#pragma once

#include <coroutine>
#include <cstddef>
#include <exception>
#include <stdexcept>
#include <utility>
#include <vector>

namespace afrilang::runtime::generator {

template<typename T>
class Generator {
public:
    struct promise_type {
        T current{};
        bool hasValue = false;
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
            hasValue = true;
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

    bool pullNext() {
        if (!handle_ || handle_.done()) return false;
        handle_.promise().hasValue = false;
        handle_.resume();
        if (handle_.promise().exception) {
            std::rethrow_exception(handle_.promise().exception);
        }
        return handle_.promise().hasValue;
    }

    bool hasNext() {
        if (!handle_ || handle_.done()) return false;
        if (!handle_.promise().hasValue) {
            return pullNext();
        }
        return true;
    }

    T next() {
        if (!hasNext()) {
            throw std::runtime_error("generator: fin de séquence");
        }
        T value = std::move(handle_.promise().current);
        handle_.promise().hasValue = false;
        return value;
    }

    T at(std::size_t index) {
        if (index < cache_.size()) {
            return cache_[index];
        }
        if (!handle_ && cache_.empty()) {
            throw std::runtime_error("generator: index hors limites");
        }
        while (cache_.size() <= index) {
            if (!pullNext()) {
                throw std::runtime_error("generator: index hors limites");
            }
            cache_.push_back(handle_.promise().current);
            handle_.promise().hasValue = false;
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
