#pragma once

#include <algorithm>
#include <cmath>
#include <functional>
#include <string>
#include <vector>

namespace afrilang::runtime::collections {

inline std::vector<double> sortNumbers(const std::vector<double>& items) {
    std::vector<double> out = items;
    std::sort(out.begin(), out.end());
    return out;
}

inline std::vector<std::string> sortText(const std::vector<std::string>& items) {
    std::vector<std::string> out = items;
    std::sort(out.begin(), out.end());
    return out;
}

inline std::vector<double> reverseNumbers(const std::vector<double>& items) {
    std::vector<double> out = items;
    std::reverse(out.begin(), out.end());
    return out;
}

inline std::vector<std::string> reverseText(const std::vector<std::string>& items) {
    std::vector<std::string> out = items;
    std::reverse(out.begin(), out.end());
    return out;
}

inline bool containsNumber(const std::vector<double>& items, double value) {
    for (double v : items) {
        if (v == value) return true;
    }
    return false;
}

inline bool containsText(const std::vector<std::string>& items, const std::string& value) {
    return std::find(items.begin(), items.end(), value) != items.end();
}

inline double indexOfNumber(const std::vector<double>& items, double value) {
    for (std::size_t i = 0; i < items.size(); ++i) {
        if (items[i] == value) return static_cast<double>(i);
    }
    return -1.0;
}

inline double indexOfText(const std::vector<std::string>& items, const std::string& value) {
    for (std::size_t i = 0; i < items.size(); ++i) {
        if (items[i] == value) return static_cast<double>(i);
    }
    return -1.0;
}

inline double sumNumbers(const std::vector<double>& items) {
    double total = 0.0;
    for (double v : items) total += v;
    return total;
}

inline std::vector<double> mapNumbers(const std::vector<double>& items,
                                      std::function<double(double)> fn) {
    std::vector<double> out;
    out.reserve(items.size());
    for (double v : items) out.push_back(fn(v));
    return out;
}

inline std::vector<double> filterNumbers(const std::vector<double>& items,
                                         std::function<bool(double)> fn) {
    std::vector<double> out;
    for (double v : items) {
        if (fn(v)) out.push_back(v);
    }
    return out;
}

inline double reduceNumbers(const std::vector<double>& items,
                            std::function<double(double, double)> fn,
                            double initial) {
    double acc = initial;
    for (double v : items) acc = fn(acc, v);
    return acc;
}

inline std::vector<std::string> mapText(const std::vector<std::string>& items,
                                        std::function<std::string(std::string)> fn) {
    std::vector<std::string> out;
    out.reserve(items.size());
    for (const auto& s : items) out.push_back(fn(s));
    return out;
}

inline std::vector<std::string> filterText(const std::vector<std::string>& items,
                                           std::function<bool(std::string)> fn) {
    std::vector<std::string> out;
    for (const auto& s : items) {
        if (fn(s)) out.push_back(s);
    }
    return out;
}

inline std::string reduceText(const std::vector<std::string>& items,
                              std::function<std::string(std::string, std::string)> fn,
                              std::string initial) {
    std::string acc = std::move(initial);
    for (const auto& s : items) acc = fn(acc, s);
    return acc;
}

inline std::vector<double> flatMapNumbers(
    const std::vector<double>& items,
    std::function<std::vector<double>(double)> fn) {
    std::vector<double> out;
    for (double v : items) {
        auto mapped = fn(v);
        out.insert(out.end(), mapped.begin(), mapped.end());
    }
    return out;
}

inline std::vector<std::string> flatMapText(
    const std::vector<std::string>& items,
    std::function<std::vector<std::string>(std::string)> fn) {
    std::vector<std::string> out;
    for (const auto& s : items) {
        auto mapped = fn(s);
        out.insert(out.end(), mapped.begin(), mapped.end());
    }
    return out;
}

} // namespace afrilang::runtime::collections
