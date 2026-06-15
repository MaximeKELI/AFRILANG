#pragma once

#include <chrono>
#include <cstdint>
#include <map>
#include <mutex>
#include <thread>

namespace afrilang::runtime::thread_ {

inline std::mutex& threadMutex() {
    static std::mutex m;
    return m;
}

inline std::map<int, std::thread>& threadRegistry() {
    static std::map<int, std::thread> threads;
    return threads;
}

inline int& nextThreadId() {
    static int id = 1;
    return id;
}

inline int spawnSleep(int ms) {
    std::lock_guard<std::mutex> lock(threadMutex());
    const int id = nextThreadId()++;
    threadRegistry()[id] = std::thread([ms]() {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    });
    return id;
}

inline void join(int id) {
    std::thread worker;
    {
        std::lock_guard<std::mutex> lock(threadMutex());
        auto it = threadRegistry().find(id);
        if (it == threadRegistry().end()) return;
        worker = std::move(it->second);
        threadRegistry().erase(it);
    }
    if (worker.joinable()) worker.join();
}

inline void sleepMs(int ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

inline int hardwareConcurrency() {
    return static_cast<int>(std::thread::hardware_concurrency());
}

} // namespace afrilang::runtime::thread_
