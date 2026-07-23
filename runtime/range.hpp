#pragma once

#include <vector>

// Plages numériques : littéraux `a..b` (inclusif) et `a..<b` (exclusif).
// Zéro-dépendance, compatibles WASM. Renvoient une `list number`
// (std::vector<double>) directement utilisable dans les opérations naturelles.
namespace afrilang::runtime::range {

inline std::vector<double> inclusive(double low, double high) {
    std::vector<double> out;
    if (high < low) return out;
    for (double v = low; v <= high; v += 1.0) {
        out.push_back(v);
    }
    return out;
}

inline std::vector<double> exclusive(double low, double high) {
    std::vector<double> out;
    if (high <= low) return out;
    for (double v = low; v < high; v += 1.0) {
        out.push_back(v);
    }
    return out;
}

} // namespace afrilang::runtime::range
