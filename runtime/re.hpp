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

// --- Groupes nommés (émulés) ----------------------------------------------
// std::regex (ECMAScript / libstdc++) ne gère pas `(?<name>...)`. On réécrit
// le motif en groupes ordinaires et on retient l'index de chaque nom. Chaque
// `(` capturant non échappé incrémente l'index ; `(?:`, `(?=`, `(?!` ne
// capturent pas. Le lookbehind `(?<=`/`(?<!` reste non supporté par std::regex.
struct NamedPattern {
    std::string pattern;                 // motif réécrit (sans noms)
    std::vector<std::string> groupNames; // nom du groupe i+1 ("" si anonyme)
};

inline NamedPattern stripNames(const std::string& pattern) {
    NamedPattern result;
    std::string& out = result.pattern;
    out.reserve(pattern.size());
    bool inClass = false;
    for (std::size_t i = 0; i < pattern.size(); ++i) {
        const char c = pattern[i];
        if (c == '\\' && i + 1 < pattern.size()) {
            out += c;
            out += pattern[i + 1];
            ++i;
            continue;
        }
        if (c == '[') { inClass = true; out += c; continue; }
        if (c == ']') { inClass = false; out += c; continue; }
        if (c == '(' && !inClass) {
            // Groupe nommé `(?<name>` ou `(?'name'` → groupe capturant + nom.
            if (i + 2 < pattern.size() && pattern[i + 1] == '?' &&
                (pattern[i + 2] == '<' || pattern[i + 2] == '\'') &&
                // exclure lookbehind `(?<=` / `(?<!`
                !(pattern[i + 2] == '<' && i + 3 < pattern.size() &&
                  (pattern[i + 3] == '=' || pattern[i + 3] == '!'))) {
                const char close = pattern[i + 2] == '<' ? '>' : '\'';
                const std::size_t nameStart = i + 3;
                const std::size_t nameEnd = pattern.find(close, nameStart);
                if (nameEnd != std::string::npos) {
                    result.groupNames.push_back(pattern.substr(nameStart, nameEnd - nameStart));
                    out += '(';
                    i = nameEnd;
                    continue;
                }
            }
            // Groupe non capturant / lookaround : pas de nom, pas d'index.
            if (i + 1 < pattern.size() && pattern[i + 1] == '?') {
                out += c;
                continue;
            }
            // Groupe capturant ordinaire.
            result.groupNames.push_back("");
            out += c;
            continue;
        }
        out += c;
    }
    return result;
}

// Contenu du groupe nommé au premier match, ou chaîne vide.
inline std::string captureNamed(const std::string& text, const std::string& pattern,
                                const std::string& name) {
    const NamedPattern np = stripNames(pattern);
    std::size_t index = 0;
    for (std::size_t i = 0; i < np.groupNames.size(); ++i) {
        if (np.groupNames[i] == name) { index = i + 1; break; }
    }
    if (index == 0) return {};
    try {
        std::smatch m;
        if (std::regex_search(text, m, compile(np.pattern)) && index < m.size()) {
            return m[index].str();
        }
    } catch (const std::regex_error&) {
    }
    return {};
}

// 1-based index du groupe nommé (0 si absent). Utile pour introspection.
inline double namedGroupIndex(const std::string& pattern, const std::string& name) {
    const NamedPattern np = stripNames(pattern);
    for (std::size_t i = 0; i < np.groupNames.size(); ++i) {
        if (np.groupNames[i] == name) return static_cast<double>(i + 1);
    }
    return 0;
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
