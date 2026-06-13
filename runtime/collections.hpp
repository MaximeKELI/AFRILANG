#pragma once

#include <algorithm>
#include <cmath>
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

} // namespace afrilang::runtime::collections
