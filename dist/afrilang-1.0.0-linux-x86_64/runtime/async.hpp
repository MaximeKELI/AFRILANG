#pragma once

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <coroutine>
#include <cstddef>
#include <exception>
#include <functional>
#include <mutex>
#include <queue>
#include <thread>
#include <type_traits>
#include <utility>
#include <vector>

namespace afrilang::runtime::async {

class Scheduler {
public:
    static Scheduler& instance() {
        static Scheduler sched;
        return sched;
    }

    void scheduleDelayed(std::chrono::milliseconds delay, std::coroutine_handle<> handle) {
        const auto when = std::chrono::steady_clock::now() + delay;
        {
            std::lock_guard<std::mutex> lock(mutex_);
            timers_.push({when, handle});
        }
        cv_.notify_one();
    }

    void schedule(std::coroutine_handle<> handle) {
        scheduleDelayed(std::chrono::milliseconds(0), handle);
    }

private:
    struct TimerEntry {
        std::chrono::steady_clock::time_point when;
        std::coroutine_handle<> handle;

        bool operator>(const TimerEntry& other) const { return when > other.when; }
    };

    Scheduler() : worker_([this] { run(); }) {}

    ~Scheduler() {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            stop_ = true;
        }
        cv_.notify_all();
        if (worker_.joinable()) worker_.join();
    }

    Scheduler(const Scheduler&) = delete;
    Scheduler& operator=(const Scheduler&) = delete;

    void run() {
        while (true) {
            std::unique_lock<std::mutex> lock(mutex_);
            if (stop_) break;
            if (timers_.empty()) {
                cv_.wait(lock);
                continue;
            }

            const auto now = std::chrono::steady_clock::now();
            TimerEntry next = timers_.top();
            if (next.when > now) {
                cv_.wait_until(lock, next.when);
                if (stop_) break;
                continue;
            }

            timers_.pop();
            auto handle = next.handle;
            lock.unlock();
            handle.resume();
        }
    }

    std::mutex mutex_;
    std::condition_variable cv_;
    std::priority_queue<TimerEntry, std::vector<TimerEntry>, std::greater<TimerEntry>> timers_;
    std::thread worker_;
    bool stop_ = false;
};

class ThreadPool {
public:
    static ThreadPool& instance() {
        static ThreadPool pool;
        return pool;
    }

    template<typename F>
    void submit(F&& fn) {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            jobs_.push(std::function<void()>(std::forward<F>(fn)));
        }
        cv_.notify_one();
    }

private:
    ThreadPool() {
        const std::size_t count = std::max<std::size_t>(2, std::thread::hardware_concurrency());
        workers_.reserve(count);
        for (std::size_t i = 0; i < count; ++i) {
            workers_.emplace_back([this] { workerLoop(); });
        }
    }

    ~ThreadPool() {
        {
            std::lock_guard<std::mutex> lock(mutex_);
            stop_ = true;
        }
        cv_.notify_all();
        for (auto& worker : workers_) {
            if (worker.joinable()) worker.join();
        }
    }

    ThreadPool(const ThreadPool&) = delete;
    ThreadPool& operator=(const ThreadPool&) = delete;

    void workerLoop() {
        while (true) {
            std::function<void()> job;
            {
                std::unique_lock<std::mutex> lock(mutex_);
                cv_.wait(lock, [this] { return stop_ || !jobs_.empty(); });
                if (stop_ && jobs_.empty()) return;
                job = std::move(jobs_.front());
                jobs_.pop();
            }
            job();
        }
    }

    std::vector<std::thread> workers_;
    std::queue<std::function<void()>> jobs_;
    std::mutex mutex_;
    std::condition_variable cv_;
    bool stop_ = false;
};

struct SleepAwaitable {
    double ms = 0;

    bool await_ready() const noexcept { return ms <= 0; }

    void await_suspend(std::coroutine_handle<> handle) const {
        Scheduler::instance().scheduleDelayed(
            std::chrono::milliseconds(static_cast<int>(ms)), handle);
    }

    void await_resume() const noexcept {}
};

template<typename F>
struct RunBlockingAwaitable {
    F fn;
    using Result = std::invoke_result_t<F>;

    Result result{};
    std::exception_ptr exception{};
    std::atomic<bool> finished{false};

    bool await_ready() const noexcept { return false; }

    void await_suspend(std::coroutine_handle<> handle) {
        ThreadPool::instance().submit([this, handle]() {
            try {
                result = fn();
            } catch (...) {
                exception = std::current_exception();
            }
            finished = true;
            Scheduler::instance().schedule(handle);
        });
    }

    Result await_resume() {
        if (exception) std::rethrow_exception(exception);
        return std::move(result);
    }
};

template<typename F>
RunBlockingAwaitable<F> runBlocking(F&& fn) {
    return RunBlockingAwaitable<F>{std::forward<F>(fn)};
}

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

template<typename F>
Task<std::invoke_result_t<F>> runBlockingTask(F&& fn) {
    co_return co_await runBlocking(std::forward<F>(fn));
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
