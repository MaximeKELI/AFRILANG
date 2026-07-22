#pragma once

// std/re — regex ECMAScript (std::regex). Pas de PCRE2 (aucune dépendance
// externe, compatible WASM). Surface inspirée de Nim `re` / Crystal `Regex`.

#include <regex>
#include <string>
#include <vector>

namespace afrilang::runtime::re {

inline std::regex::flag_type parseFlags(const std::string& flags) {
    std::regex::flag_type f = std::regex::ECMAScript;
    for (char c : flags) {
        if (c == 'i') f |= std::regex::icase;
        else if (c == 'm') f |= std::regex::multiline;
    }
    return f;
}

inline std::regex compile(const std::string& pattern, const std::string& flags = "") {
    return std::regex(pattern, parseFlags(flags));
}

// Ancré : la totalité du texte doit correspondre.
// Note : exposé sous le nom `matches` côté langage (`match` est un mot-clé).
inline bool matches(const std::string& text, const std::string& pattern) {
    try {
        return std::regex_match(text, compile(pattern));
    } catch (const std::regex_error&) {
        return false;
    }
}

inline bool matchFlags(const std::string& text, const std::string& pattern,
                       const std::string& flags) {
    try {
        return std::regex_match(text, compile(pattern, flags));
    } catch (const std::regex_error&) {
        return false;
    }
}

// Non ancré : cherche une sous-chaîne correspondante.
inline bool search(const std::string& text, const std::string& pattern) {
    try {
        return std::regex_search(text, compile(pattern));
    } catch (const std::regex_error&) {
        return false;
    }
}

// Premier match (texte complet du match) ou chaîne vide.
inline std::string find(const std::string& text, const std::string& pattern) {
    try {
        std::smatch m;
        if (std::regex_search(text, m, compile(pattern))) return m[0].str();
    } catch (const std::regex_error&) {
    }
    return {};
}

// Tous les matches (texte complet de chaque match).
inline std::vector<std::string> findAll(const std::string& text, const std::string& pattern) {
    std::vector<std::string> out;
    try {
        const std::regex re = compile(pattern);
        auto begin = std::sregex_iterator(text.begin(), text.end(), re);
        auto end = std::sregex_iterator();
        for (auto it = begin; it != end; ++it) out.push_back((*it)[0].str());
    } catch (const std::regex_error&) {
    }
    return out;
}

// Groupes capturants du premier match (hors groupe 0).
inline std::vector<std::string> captures(const std::string& text, const std::string& pattern) {
    std::vector<std::string> out;
    try {
        std::smatch m;
        if (std::regex_search(text, m, compile(pattern))) {
            for (std::size_t i = 1; i < m.size(); ++i) out.push_back(m[i].str());
        }
    } catch (const std::regex_error&) {
    }
    return out;
}

inline std::size_t count(const std::string& text, const std::string& pattern) {
    return findAll(text, pattern).size();
}

// Découpe le texte sur chaque occurrence du motif.
inline std::vector<std::string> split(const std::string& text, const std::string& pattern) {
    std::vector<std::string> out;
    try {
        const std::regex re = compile(pattern);
        std::sregex_token_iterator it(text.begin(), text.end(), re, -1);
        std::sregex_token_iterator end;
        for (; it != end; ++it) out.push_back(*it);
    } catch (const std::regex_error&) {
        out.push_back(text);
    }
    return out;
}

inline std::string replace(const std::string& text, const std::string& pattern,
                           const std::string& replacement) {
    try {
        return std::regex_replace(text, compile(pattern), replacement);
    } catch (const std::regex_error&) {
        return text;
    }
}

inline std::string replaceFirst(const std::string& text, const std::string& pattern,
                                const std::string& replacement) {
    try {
        return std::regex_replace(text, compile(pattern), replacement,
                                  std::regex_constants::format_first_only);
    } catch (const std::regex_error&) {
        return text;
    }
}

} // namespace afrilang::runtime::re
