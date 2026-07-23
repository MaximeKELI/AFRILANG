#pragma once

// std/yaml — parseur/émetteur YAML (sous-ensemble bloc : mappings et séquences
// imbriqués, scalaires). Zéro dépendance. Réutilise le modèle json::Value.
// Non supporté : flow style ({}/[]) hors vide, ancres/alias, scalaires bloc
// multi-lignes (|/>), documents multiples.

#include "json.hpp"

#include <cctype>
#include <sstream>
#include <string>
#include <vector>

namespace afrilang::runtime::yaml {

struct Line {
    int indent;
    std::string text; // sans espaces de tête, fin élaguée
};

inline std::string ltrimStr(const std::string& s) {
    std::size_t i = 0;
    while (i < s.size() && (s[i] == ' ' || s[i] == '\t')) ++i;
    return s.substr(i);
}

inline std::string rtrimStr(const std::string& s) {
    std::size_t end = s.size();
    while (end > 0 && (s[end - 1] == ' ' || s[end - 1] == '\t' || s[end - 1] == '\r')) --end;
    return s.substr(0, end);
}

inline std::string trimStr(const std::string& s) { return rtrimStr(ltrimStr(s)); }

inline std::string unquote(const std::string& s) {
    if (s.size() >= 2 && ((s.front() == '"' && s.back() == '"') ||
                          (s.front() == '\'' && s.back() == '\''))) {
        return s.substr(1, s.size() - 2);
    }
    return s;
}

inline bool isNumberScalar(const std::string& s) {
    if (s.empty()) return false;
    std::size_t i = 0;
    if (s[i] == '+' || s[i] == '-') ++i;
    bool digits = false, dot = false, exp = false;
    for (; i < s.size(); ++i) {
        const char c = s[i];
        if (std::isdigit(static_cast<unsigned char>(c))) { digits = true; continue; }
        if (c == '.' && !dot && !exp) { dot = true; continue; }
        if ((c == 'e' || c == 'E') && digits && !exp) {
            exp = true;
            if (i + 1 < s.size() && (s[i + 1] == '+' || s[i + 1] == '-')) ++i;
            continue;
        }
        return false;
    }
    return digits;
}

inline json::Value parseScalar(const std::string& raw) {
    const std::string v = trimStr(raw);
    json::Value out;
    if (v.empty() || v == "null" || v == "~" || v == "None") {
        out.kind = json::Value::Kind::Null;
        return out;
    }
    if (v == "true" || v == "false" || v == "yes" || v == "no") {
        out.kind = json::Value::Kind::Bool;
        out.boolVal = (v == "true" || v == "yes");
        return out;
    }
    if (v == "[]") { out.kind = json::Value::Kind::Array; return out; }
    if (v == "{}") { out.kind = json::Value::Kind::Object; return out; }
    if ((v.front() == '"' && v.back() == '"') || (v.front() == '\'' && v.back() == '\'')) {
        out.kind = json::Value::Kind::String;
        out.stringVal = unquote(v);
        return out;
    }
    if (isNumberScalar(v)) {
        out.kind = json::Value::Kind::Number;
        out.numberVal = std::stod(v);
        return out;
    }
    out.kind = json::Value::Kind::String;
    out.stringVal = v;
    return out;
}

// Position du ':' séparateur de clé (suivi d'espace ou fin), hors guillemets.
inline std::size_t findKeyColon(const std::string& s) {
    char quote = 0;
    for (std::size_t i = 0; i < s.size(); ++i) {
        const char c = s[i];
        if (quote) {
            if (c == quote) quote = 0;
            continue;
        }
        if (c == '"' || c == '\'') { quote = c; continue; }
        if (c == ':' && (i + 1 == s.size() || s[i + 1] == ' ')) return i;
    }
    return std::string::npos;
}

inline bool isScalarLine(const Line& l) {
    if (!l.text.empty() && l.text[0] == '-' &&
        (l.text.size() == 1 || l.text[1] == ' ')) {
        return false;
    }
    return findKeyColon(l.text) == std::string::npos;
}

json::Value parseLines(const std::vector<Line>& lines);

inline json::Value parseSequence(const std::vector<Line>& lines) {
    json::Value arr;
    arr.kind = json::Value::Kind::Array;
    const int base = lines[0].indent;
    std::size_t i = 0;
    while (i < lines.size()) {
        if (lines[i].indent != base) { ++i; continue; }
        const std::string rest = ltrimStr(lines[i].text.substr(1)); // après le '-'
        std::vector<Line> item;
        if (!rest.empty()) item.push_back({base + 2, rest});
        ++i;
        while (i < lines.size() && lines[i].indent > base) {
            item.push_back(lines[i]);
            ++i;
        }
        if (item.empty()) {
            json::Value nul;
            arr.arrayVal.push_back(nul);
        } else if (item.size() == 1 && isScalarLine(item[0])) {
            arr.arrayVal.push_back(parseScalar(item[0].text));
        } else {
            arr.arrayVal.push_back(parseLines(item));
        }
    }
    return arr;
}

inline json::Value parseMapping(const std::vector<Line>& lines) {
    json::Value map;
    map.kind = json::Value::Kind::Object;
    const int base = lines[0].indent;
    std::size_t i = 0;
    while (i < lines.size()) {
        if (lines[i].indent != base) { ++i; continue; }
        const std::string& line = lines[i].text;
        const std::size_t colon = findKeyColon(line);
        if (colon == std::string::npos) { ++i; continue; }
        const std::string key = unquote(trimStr(line.substr(0, colon)));
        const std::string valuePart = trimStr(line.substr(colon + 1));
        ++i;
        if (!valuePart.empty()) {
            map.objectVal[key] = parseScalar(valuePart);
            continue;
        }
        std::vector<Line> block;
        while (i < lines.size() && lines[i].indent > base) {
            block.push_back(lines[i]);
            ++i;
        }
        if (block.empty()) {
            json::Value nul;
            map.objectVal[key] = nul;
        } else {
            map.objectVal[key] = parseLines(block);
        }
    }
    return map;
}

inline json::Value parseLines(const std::vector<Line>& lines) {
    if (lines.empty()) return json::Value{};
    if (!lines[0].text.empty() && lines[0].text[0] == '-' &&
        (lines[0].text.size() == 1 || lines[0].text[1] == ' ')) {
        return parseSequence(lines);
    }
    return parseMapping(lines);
}

inline json::Value parseSimple(const std::string& text) {
    std::vector<Line> lines;
    std::istringstream in(text);
    std::string raw;
    while (std::getline(in, raw)) {
        int indent = 0;
        while (indent < static_cast<int>(raw.size()) && raw[indent] == ' ') ++indent;
        std::string content = rtrimStr(raw.substr(indent));
        if (content.empty() || content[0] == '#') continue;
        if (content == "---" || content == "...") continue; // marqueurs de doc
        lines.push_back({indent, content});
    }
    if (lines.empty()) {
        json::Value obj;
        obj.kind = json::Value::Kind::Object;
        return obj;
    }
    return parseLines(lines);
}

// --- Émetteur YAML ---------------------------------------------------------

inline bool scalarNeedsQuote(const std::string& s) {
    if (s.empty()) return true;
    if (s == "null" || s == "true" || s == "false" || s == "yes" || s == "no" ||
        s == "~") {
        return true;
    }
    if (isNumberScalar(s)) return true;
    const char c0 = s.front();
    if (c0 == ' ' || c0 == '-' || c0 == '?' || c0 == '#' || c0 == '&' || c0 == '*' ||
        c0 == '!' || c0 == '|' || c0 == '>' || c0 == '%' || c0 == '@' || c0 == '`' ||
        c0 == '[' || c0 == ']' || c0 == '{' || c0 == '}' || c0 == '"' || c0 == '\'') {
        return true;
    }
    if (s.back() == ' ') return true;
    for (char c : s) {
        if (c == ':' || c == '#' || c == '\n' || c == '\t') return true;
    }
    return false;
}

inline std::string emitScalar(const json::Value& v) {
    switch (v.kind) {
        case json::Value::Kind::Null: return "null";
        case json::Value::Kind::Bool: return v.boolVal ? "true" : "false";
        case json::Value::Kind::Number: {
            std::ostringstream out;
            if (v.numberVal == static_cast<long long>(v.numberVal)) {
                out << static_cast<long long>(v.numberVal);
            } else {
                out << v.numberVal;
            }
            return out.str();
        }
        case json::Value::Kind::String:
        default:
            if (scalarNeedsQuote(v.stringVal)) {
                return "\"" + json::escape(v.stringVal) + "\"";
            }
            return v.stringVal;
    }
}

inline bool isScalarValue(const json::Value& v) {
    return v.kind != json::Value::Kind::Object && v.kind != json::Value::Kind::Array;
}

inline void emitInto(const json::Value& v, int indent, std::string& out) {
    const std::string pad(static_cast<std::size_t>(indent), ' ');
    if (v.kind == json::Value::Kind::Object) {
        if (v.objectVal.empty()) { out += pad + "{}\n"; return; }
        for (const auto& [k, val] : v.objectVal) {
            if (isScalarValue(val)) {
                out += pad + k + ": " + emitScalar(val) + "\n";
            } else if ((val.kind == json::Value::Kind::Array && val.arrayVal.empty())) {
                out += pad + k + ": []\n";
            } else if (val.kind == json::Value::Kind::Object && val.objectVal.empty()) {
                out += pad + k + ": {}\n";
            } else {
                out += pad + k + ":\n";
                emitInto(val, indent + 2, out);
            }
        }
    } else if (v.kind == json::Value::Kind::Array) {
        if (v.arrayVal.empty()) { out += pad + "[]\n"; return; }
        for (const auto& item : v.arrayVal) {
            if (isScalarValue(item)) {
                out += pad + "- " + emitScalar(item) + "\n";
            } else {
                out += pad + "-\n";
                emitInto(item, indent + 2, out);
            }
        }
    } else {
        out += pad + emitScalar(v) + "\n";
    }
}

inline std::string stringifySimple(const json::Value& value) {
    std::string out;
    emitInto(value, 0, out);
    return out;
}

} // namespace afrilang::runtime::yaml
