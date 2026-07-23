#pragma once

// std/unicode — utilitaires UTF-8 zéro-dépendance (WASM-compatible).
// Le module `str` reste orienté octets ; ce module raisonne en points de code.
// La normalisation NFC/NFD et les catégories Unicode complètes nécessitent de
// grosses tables de données et sont hors périmètre (choix zéro-dépendance).

#include <cstdint>
#include <string>
#include <vector>

namespace afrilang::runtime::unicode {

// Décode le point de code à l'octet `i`, avance `i` après lui. Retourne -1 sur
// séquence invalide (et avance d'un octet pour progresser).
inline std::int64_t decodeAt(const std::string& s, std::size_t& i) {
    if (i >= s.size()) return -1;
    const unsigned char c = static_cast<unsigned char>(s[i]);
    if (c < 0x80) { ++i; return c; }
    int extra = 0;
    std::int64_t cp = 0;
    if ((c & 0xE0) == 0xC0) { extra = 1; cp = c & 0x1F; }
    else if ((c & 0xF0) == 0xE0) { extra = 2; cp = c & 0x0F; }
    else if ((c & 0xF8) == 0xF0) { extra = 3; cp = c & 0x07; }
    else { ++i; return -1; }
    for (int k = 1; k <= extra; ++k) {
        if (i + k >= s.size()) { ++i; return -1; }
        const unsigned char cc = static_cast<unsigned char>(s[i + k]);
        if ((cc & 0xC0) != 0x80) { ++i; return -1; }
        cp = (cp << 6) | (cc & 0x3F);
    }
    i += extra + 1;
    return cp;
}

inline void encodeInto(std::string& out, std::int64_t cp) {
    if (cp < 0) return;
    if (cp <= 0x7F) {
        out += static_cast<char>(cp);
    } else if (cp <= 0x7FF) {
        out += static_cast<char>(0xC0 | (cp >> 6));
        out += static_cast<char>(0x80 | (cp & 0x3F));
    } else if (cp <= 0xFFFF) {
        out += static_cast<char>(0xE0 | (cp >> 12));
        out += static_cast<char>(0x80 | ((cp >> 6) & 0x3F));
        out += static_cast<char>(0x80 | (cp & 0x3F));
    } else {
        out += static_cast<char>(0xF0 | (cp >> 18));
        out += static_cast<char>(0x80 | ((cp >> 12) & 0x3F));
        out += static_cast<char>(0x80 | ((cp >> 6) & 0x3F));
        out += static_cast<char>(0x80 | (cp & 0x3F));
    }
}

inline std::int64_t byteLength(const std::string& s) {
    return static_cast<std::int64_t>(s.size());
}

inline std::vector<std::int64_t> codepointVec(const std::string& s) {
    std::vector<std::int64_t> out;
    std::size_t i = 0;
    while (i < s.size()) {
        const std::int64_t cp = decodeAt(s, i);
        if (cp >= 0) out.push_back(cp);
    }
    return out;
}

// Exposé côté langage sous forme de `list number`.
inline std::vector<double> codepoints(const std::string& s) {
    std::vector<double> out;
    for (std::int64_t cp : codepointVec(s)) out.push_back(static_cast<double>(cp));
    return out;
}

inline std::int64_t codepointCount(const std::string& s) {
    std::int64_t n = 0;
    std::size_t i = 0;
    while (i < s.size()) {
        if (decodeAt(s, i) >= 0) ++n;
    }
    return n;
}

// Marque combinante / caractère « étendant » un cluster de graphèmes.
inline bool isExtending(std::int64_t cp) {
    if (cp == 0x200D) return true;                    // ZWJ
    if (cp >= 0x0300 && cp <= 0x036F) return true;    // Combining Diacritical Marks
    if (cp >= 0x1AB0 && cp <= 0x1AFF) return true;    // Combining Diacritical Ext
    if (cp >= 0x1DC0 && cp <= 0x1DFF) return true;    // Combining Diacritical Supp
    if (cp >= 0x20D0 && cp <= 0x20FF) return true;    // Combining Marks for Symbols
    if (cp >= 0xFE20 && cp <= 0xFE2F) return true;    // Combining Half Marks
    if (cp == 0xFE0F || cp == 0xFE0E) return true;    // Variation selectors 15/16
    return false;
}

// Comptage de graphèmes simplifié (base + marques combinantes + ZWJ). Ne couvre
// pas toutes les règles UAX #29 (ex. clusters d'indicateurs régionaux).
inline std::int64_t graphemeCount(const std::string& s) {
    std::int64_t n = 0;
    std::size_t i = 0;
    bool prev = false;
    while (i < s.size()) {
        const std::int64_t cp = decodeAt(s, i);
        if (cp < 0) { ++n; prev = false; continue; }
        if (isExtending(cp)) {
            if (!prev) ++n; // marque en tête : compte comme un cluster
        } else {
            ++n;
        }
        prev = true;
    }
    return n;
}

// Point de code à l'index `index` (en points de code), -1 si hors limites.
inline std::int64_t codepointAt(const std::string& s, double index) {
    const auto target = static_cast<std::int64_t>(index);
    if (target < 0) return -1;
    std::int64_t k = 0;
    std::size_t i = 0;
    while (i < s.size()) {
        const std::int64_t cp = decodeAt(s, i);
        if (cp < 0) continue;
        if (k == target) return cp;
        ++k;
    }
    return -1;
}

// Caractère (UTF-8) à l'index en points de code, chaîne vide si hors limites.
inline std::string charAt(const std::string& s, double index) {
    const std::int64_t cp = codepointAt(s, index);
    if (cp < 0) return {};
    std::string out;
    encodeInto(out, cp);
    return out;
}

// Sous-chaîne [start, end) en points de code (end négatif = jusqu'à la fin).
inline std::string slice(const std::string& s, double start, double end) {
    const auto cps = codepointVec(s);
    std::int64_t a = static_cast<std::int64_t>(start);
    std::int64_t b = static_cast<std::int64_t>(end);
    const std::int64_t n = static_cast<std::int64_t>(cps.size());
    if (a < 0) a = 0;
    if (b < 0 || b > n) b = n;
    std::string out;
    for (std::int64_t k = a; k < b && k < n; ++k) encodeInto(out, cps[k]);
    return out;
}

inline std::string reverse(const std::string& s) {
    const auto cps = codepointVec(s);
    std::string out;
    for (auto it = cps.rbegin(); it != cps.rend(); ++it) encodeInto(out, *it);
    return out;
}

inline bool isValidUtf8(const std::string& s) {
    std::size_t i = 0;
    while (i < s.size()) {
        const std::size_t before = i;
        if (decodeAt(s, i) < 0) return false;
        if (i <= before) return false; // sécurité anti-boucle
    }
    return true;
}

// Prédicats simples sur un point de code.
inline bool isSpace(double codepoint) {
    const auto cp = static_cast<std::int64_t>(codepoint);
    return cp == 0x20 || cp == 0x09 || cp == 0x0A || cp == 0x0D || cp == 0x0B ||
           cp == 0x0C || cp == 0xA0 || cp == 0x2028 || cp == 0x2029 || cp == 0x3000;
}

inline bool isAsciiLetter(double codepoint) {
    const auto cp = static_cast<std::int64_t>(codepoint);
    return (cp >= 'A' && cp <= 'Z') || (cp >= 'a' && cp <= 'z');
}

inline bool isAsciiDigit(double codepoint) {
    const auto cp = static_cast<std::int64_t>(codepoint);
    return cp >= '0' && cp <= '9';
}

} // namespace afrilang::runtime::unicode
