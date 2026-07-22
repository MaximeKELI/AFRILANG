#pragma once

#include <chrono>
#include <condition_variable>
#include <cstdint>
#include <deque>
#include <map>
#include <memory>
#include <mutex>
#include <string>
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

// --- Mutex utilisateur -----------------------------------------------------

inline std::map<int, std::unique_ptr<std::mutex>>& mutexRegistry() {
    static std::map<int, std::unique_ptr<std::mutex>> mutexes;
    return mutexes;
}

inline int& nextMutexId() {
    static int id = 1;
    return id;
}

inline int mutexNew() {
    std::lock_guard<std::mutex> lock(threadMutex());
    const int id = nextMutexId()++;
    mutexRegistry()[id] = std::make_unique<std::mutex>();
    return id;
}

inline void mutexLock(int id) {
    std::mutex* m = nullptr;
    {
        std::lock_guard<std::mutex> lock(threadMutex());
        auto it = mutexRegistry().find(id);
        if (it == mutexRegistry().end()) return;
        m = it->second.get();
    }
    if (m) m->lock();
}

inline void mutexUnlock(int id) {
    std::mutex* m = nullptr;
    {
        std::lock_guard<std::mutex> lock(threadMutex());
        auto it = mutexRegistry().find(id);
        if (it == mutexRegistry().end()) return;
        m = it->second.get();
    }
    if (m) m->unlock();
}

// --- Canaux (channels) typés, FIFO, thread-safe ----------------------------

template <typename T>
struct Channel {
    std::mutex mutex;
    std::condition_variable cv;
    std::deque<T> queue;
    bool closed = false;
};

inline std::map<int, std::shared_ptr<Channel<std::string>>>& textChannels() {
    static std::map<int, std::shared_ptr<Channel<std::string>>> chans;
    return chans;
}

inline std::map<int, std::shared_ptr<Channel<double>>>& numberChannels() {
    static std::map<int, std::shared_ptr<Channel<double>>> chans;
    return chans;
}

inline int& nextChannelId() {
    static int id = 1;
    return id;
}

inline int chanNewText() {
    std::lock_guard<std::mutex> lock(threadMutex());
    const int id = nextChannelId()++;
    textChannels()[id] = std::make_shared<Channel<std::string>>();
    return id;
}

inline int chanNewNumber() {
    std::lock_guard<std::mutex> lock(threadMutex());
    const int id = nextChannelId()++;
    numberChannels()[id] = std::make_shared<Channel<double>>();
    return id;
}

template <typename Map>
inline auto lookupChannel(Map& map, int id) -> typename Map::mapped_type {
    std::lock_guard<std::mutex> lock(threadMutex());
    auto it = map.find(id);
    if (it == map.end()) return nullptr;
    return it->second;
}

inline void chanSendText(int id, const std::string& value) {
    auto ch = lookupChannel(textChannels(), id);
    if (!ch) return;
    {
        std::lock_guard<std::mutex> lock(ch->mutex);
        ch->queue.push_back(value);
    }
    ch->cv.notify_one();
}

inline void chanSendNumber(int id, double value) {
    auto ch = lookupChannel(numberChannels(), id);
    if (!ch) return;
    {
        std::lock_guard<std::mutex> lock(ch->mutex);
        ch->queue.push_back(value);
    }
    ch->cv.notify_one();
}

inline std::string chanRecvText(int id) {
    auto ch = lookupChannel(textChannels(), id);
    if (!ch) return {};
    std::unique_lock<std::mutex> lock(ch->mutex);
    ch->cv.wait(lock, [&] { return !ch->queue.empty() || ch->closed; });
    if (ch->queue.empty()) return {};
    std::string value = std::move(ch->queue.front());
    ch->queue.pop_front();
    return value;
}

inline double chanRecvNumber(int id) {
    auto ch = lookupChannel(numberChannels(), id);
    if (!ch) return 0;
    std::unique_lock<std::mutex> lock(ch->mutex);
    ch->cv.wait(lock, [&] { return !ch->queue.empty() || ch->closed; });
    if (ch->queue.empty()) return 0;
    double value = ch->queue.front();
    ch->queue.pop_front();
    return value;
}

inline void chanClose(int id) {
    if (auto ch = lookupChannel(textChannels(), id)) {
        {
            std::lock_guard<std::mutex> lock(ch->mutex);
            ch->closed = true;
        }
        ch->cv.notify_all();
    }
    if (auto ch = lookupChannel(numberChannels(), id)) {
        {
            std::lock_guard<std::mutex> lock(ch->mutex);
            ch->closed = true;
        }
        ch->cv.notify_all();
    }
}

} // namespace afrilang::runtime::thread_
