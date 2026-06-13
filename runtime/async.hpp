#pragma once

#include <chrono>
#include <coroutine>
#include <exception>
#include <thread>
#include <utility>

namespace afrilang::runtime::async {

struct SleepAwaitable {
    double ms = 0;

    bool await_ready() const noexcept { return ms <= 0; }

    void await_suspend(std::coroutine_handle<> handle) const {
        const int delayMs = static_cast<int>(ms);
        std::thread([handle, delayMs]() {
            std::this_thread::sleep_for(std::chrono::milliseconds(delayMs));
            handle.resume();
        }).detach();
    }

    void await_resume() const noexcept {}
};

template<typename T>
struct Task;

namespace detail {

struct FinalAwaiter {
    bool await_ready() const noexcept { return false; }

    template<typename Promise>
    std::coroutine_handle<> await_suspend(std::coroutine_handle<Promise> handle) noexcept {
        if (auto continuation = handle.promise().continuation) {
            continuation.resume();
        }
        return std::noop_coroutine();
    }

    void await_resume() const noexcept {}
};

template<typename T>
struct TaskPromise {
    T value{};
    std::exception_ptr exception{};
    std::coroutine_handle<> continuation{};

    Task<T> get_return_object() noexcept;

    std::suspend_always initial_suspend() noexcept { return {}; }

    FinalAwaiter final_suspend() noexcept { return {}; }

    void return_value(T v) { value = std::move(v); }

    void unhandled_exception() { exception = std::current_exception(); }
};

template<>
struct TaskPromise<void> {
    std::exception_ptr exception{};
    std::coroutine_handle<> continuation{};

    Task<void> get_return_object() noexcept;

    std::suspend_always initial_suspend() noexcept { return {}; }

    FinalAwaiter final_suspend() noexcept { return {}; }

    void return_void() noexcept {}

    void unhandled_exception() { exception = std::current_exception(); }
};

} // namespace detail

template<typename T>
struct Task {
    using promise_type = detail::TaskPromise<T>;

    std::coroutine_handle<promise_type> handle{};

    explicit Task(std::coroutine_handle<promise_type> h) : handle(h) {}

    Task(Task&& other) noexcept : handle(other.handle) { other.handle = nullptr; }

    Task& operator=(Task&& other) noexcept {
        if (handle) handle.destroy();
        handle = other.handle;
        other.handle = nullptr;
        return *this;
    }

    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;

    ~Task() {
        if (handle) handle.destroy();
    }

    bool await_ready() const noexcept {
        return !handle || handle.done();
    }

    void await_suspend(std::coroutine_handle<> parent) {
        if (!handle || handle.done()) return;
        handle.promise().continuation = parent;
        handle.resume();
    }

    T await_resume() {
        if (handle.promise().exception) {
            std::rethrow_exception(handle.promise().exception);
        }
        return std::move(handle.promise().value);
    }
};

template<>
struct Task<void> {
    using promise_type = detail::TaskPromise<void>;

    std::coroutine_handle<promise_type> handle{};

    explicit Task(std::coroutine_handle<promise_type> h) : handle(h) {}

    Task(Task&& other) noexcept : handle(other.handle) { other.handle = nullptr; }

    Task& operator=(Task&& other) noexcept {
        if (handle) handle.destroy();
        handle = other.handle;
        other.handle = nullptr;
        return *this;
    }

    Task(const Task&) = delete;
    Task& operator=(const Task&) = delete;

    ~Task() {
        if (handle) handle.destroy();
    }

    bool await_ready() const noexcept {
        return !handle || handle.done();
    }

    void await_suspend(std::coroutine_handle<> parent) {
        if (!handle || handle.done()) return;
        handle.promise().continuation = parent;
        handle.resume();
    }

    void await_resume() {
        if (handle.promise().exception) {
            std::rethrow_exception(handle.promise().exception);
        }
    }
};

template<typename T>
inline Task<T> detail::TaskPromise<T>::get_return_object() noexcept {
    return Task<T>{std::coroutine_handle<TaskPromise<T>>::from_promise(*this)};
}

inline Task<void> detail::TaskPromise<void>::get_return_object() noexcept {
    return Task<void>{std::coroutine_handle<TaskPromise<void>>::from_promise(*this)};
}

inline SleepAwaitable sleepAwaitable(double ms) {
    return SleepAwaitable{ms};
}

inline Task<void> sleep(double ms) {
    co_await sleepAwaitable(ms);
}

template<typename T>
inline T run(Task<T> task) {
    if (task.handle) {
        task.handle.resume();
    }
    while (task.handle && !task.handle.done()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    return task.await_resume();
}

inline void run(Task<void> task) {
    if (task.handle) {
        task.handle.resume();
    }
    while (task.handle && !task.handle.done()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
    task.await_resume();
}

} // namespace afrilang::runtime::async
