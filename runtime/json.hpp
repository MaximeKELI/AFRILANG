#pragma once

#include <cctype>
#include <cstdint>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace afrilang {
namespace runtime {
namespace json {

struct Value {
    enum class Kind { Null, Bool, Number, String, Object, Array };
    Kind kind = Kind::Null;
    bool boolVal = false;
    double numberVal = 0;
    std::string stringVal;
    std::unordered_map<std::string, Value> objectVal;
    std::vector<Value> arrayVal;
};

class Parser {
public:
    explicit Parser(std::string input) : input_(std::move(input)) {}

    Value parse() { return parseValue(); }

private:
    std::string input_;
    std::size_t pos_ = 0;

    void skipWs() {
        while (pos_ < input_.size() &&
               std::isspace(static_cast<unsigned char>(input_[pos_]))) ++pos_;
    }

    char peek() const { return pos_ < input_.size() ? input_[pos_] : '\0'; }

    char get() { return pos_ < input_.size() ? input_[pos_++] : '\0'; }

    Value parseValue() {
        skipWs();
        const char c = peek();
        if (c == '"') return parseString();
        if (c == '{') return parseObject();
        if (c == '[') return parseArray();
        if (c == 't' || c == 'f') return parseBool();
        if (c == 'n') return parseNull();
        if (c == '-' || std::isdigit(static_cast<unsigned char>(c))) return parseNumber();
        return Value{};
    }

    static void appendUtf8(std::string& out, unsigned int cp) {
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

    unsigned int parseHex4() {
        unsigned int value = 0;
        for (int i = 0; i < 4 && pos_ < input_.size(); ++i) {
            const char c = get();
            value <<= 4;
            if (c >= '0' && c <= '9') value |= static_cast<unsigned int>(c - '0');
            else if (c >= 'a' && c <= 'f') value |= static_cast<unsigned int>(c - 'a' + 10);
            else if (c >= 'A' && c <= 'F') value |= static_cast<unsigned int>(c - 'A' + 10);
        }
        return value;
    }

    Value parseString() {
        get();
        Value v;
        v.kind = Value::Kind::String;
        while (pos_ < input_.size()) {
            char c = get();
            if (c == '"') break;
            if (c == '\\' && pos_ < input_.size()) {
                char esc = get();
                switch (esc) {
                    case '"': v.stringVal += '"'; break;
                    case '\\': v.stringVal += '\\'; break;
                    case '/': v.stringVal += '/'; break;
                    case 'n': v.stringVal += '\n'; break;
                    case 't': v.stringVal += '\t'; break;
                    case 'b': v.stringVal += '\b'; break;
                    case 'f': v.stringVal += '\f'; break;
                    case 'r': v.stringVal += '\r'; break;
                    case 'u': {
                        unsigned int cp = parseHex4();
                        if (cp >= 0xD800 && cp <= 0xDBFF &&
                            pos_ + 1 < input_.size() && input_[pos_] == '\\' &&
                            input_[pos_ + 1] == 'u') {
                            pos_ += 2;
                            const unsigned int low = parseHex4();
                            cp = 0x10000 + ((cp - 0xD800) << 10) + (low - 0xDC00);
                        }
                        appendUtf8(v.stringVal, cp);
                        break;
                    }
                    default: v.stringVal += esc; break;
                }
            } else {
                v.stringVal += c;
            }
        }
        return v;
    }

    Value parseNumber() {
        std::size_t start = pos_;
        if (peek() == '-') get();
        while (std::isdigit(static_cast<unsigned char>(peek()))) get();
        if (peek() == '.') {
            get();
            while (std::isdigit(static_cast<unsigned char>(peek()))) get();
        }
        if (peek() == 'e' || peek() == 'E') {
            get();
            if (peek() == '+' || peek() == '-') get();
            while (std::isdigit(static_cast<unsigned char>(peek()))) get();
        }
        Value v;
        v.kind = Value::Kind::Number;
        v.numberVal = std::stod(input_.substr(start, pos_ - start));
        return v;
    }

    Value parseBool() {
        Value v;
        v.kind = Value::Kind::Bool;
        if (input_.substr(pos_, 4) == "true") { pos_ += 4; v.boolVal = true; }
        else if (input_.substr(pos_, 5) == "false") { pos_ += 5; v.boolVal = false; }
        return v;
    }

    Value parseNull() {
        if (input_.substr(pos_, 4) == "null") pos_ += 4;
        return Value{};
    }

    Value parseObject() {
        get();
        Value v;
        v.kind = Value::Kind::Object;
        skipWs();
        if (peek() == '}') { get(); return v; }
        while (pos_ < input_.size()) {
            skipWs();
            Value key = parseString();
            skipWs();
            get(); // :
            Value val = parseValue();
            v.objectVal[key.stringVal] = std::move(val);
            skipWs();
            if (peek() == '}') { get(); break; }
            if (peek() == ',') { get(); continue; }
            break; // entrée malformée : on s'arrête plutôt que boucler
        }
        return v;
    }

    Value parseArray() {
        get();
        Value v;
        v.kind = Value::Kind::Array;
        skipWs();
        if (peek() == ']') { get(); return v; }
        while (pos_ < input_.size()) {
            v.arrayVal.push_back(parseValue());
            skipWs();
            if (peek() == ']') { get(); break; }
            if (peek() == ',') { get(); continue; }
            break; // entrée malformée : on s'arrête plutôt que boucler
        }
        return v;
    }
};

inline std::string escape(const std::string& s) {
    std::string out;
    for (char c : s) {
        switch (c) {
            case '"': out += "\\\""; break;
            case '\\': out += "\\\\"; break;
            case '\n': out += "\\n"; break;
            case '\t': out += "\\t"; break;
            case '\b': out += "\\b"; break;
            case '\f': out += "\\f"; break;
            case '\r': out += "\\r"; break;
            default: out += c; break;
        }
    }
    return out;
}

inline std::string stringify(const Value& v) {
    switch (v.kind) {
        case Value::Kind::Null: return "null";
        case Value::Kind::Bool: return v.boolVal ? "true" : "false";
        case Value::Kind::Number: {
            std::ostringstream out;
            if (v.numberVal == static_cast<int>(v.numberVal)) out << static_cast<int>(v.numberVal);
            else out << v.numberVal;
            return out.str();
        }
        case Value::Kind::String: return "\"" + escape(v.stringVal) + "\"";
        case Value::Kind::Array: {
            std::string out = "[";
            for (std::size_t i = 0; i < v.arrayVal.size(); ++i) {
                if (i > 0) out += ", ";
                out += stringify(v.arrayVal[i]);
            }
            return out + "]";
        }
        case Value::Kind::Object: {
            std::string out = "{";
            bool first = true;
            for (const auto& [k, val] : v.objectVal) {
                if (!first) out += ", ";
                first = false;
                out += "\"" + escape(k) + "\": " + stringify(val);
            }
            return out + "}";
        }
    }
    return "null";
}

inline std::string normalize(const std::string& text) {
    Parser parser(text);
    return stringify(parser.parse());
}

inline std::string parse(const std::string& text) {
    return normalize(text);
}

inline std::string getString(const std::string& text, const std::string& key) {
    Parser parser(text);
    Value root = parser.parse();
    if (root.kind != Value::Kind::Object) return "";
    auto it = root.objectVal.find(key);
    if (it == root.objectVal.end() || it->second.kind != Value::Kind::String) return "";
    return it->second.stringVal;
}

inline double getNumber(const std::string& text, const std::string& key) {
    Parser parser(text);
    Value root = parser.parse();
    if (root.kind != Value::Kind::Object) return 0;
    auto it = root.objectVal.find(key);
    if (it == root.objectVal.end() || it->second.kind != Value::Kind::Number) return 0;
    return it->second.numberVal;
}

inline std::string makeObject(const std::string& key, const std::string& value) {
    return "{\"" + escape(key) + "\": \"" + escape(value) + "\"}";
}

inline Value parseValue(const std::string& text) {
    Parser parser(text);
    return parser.parse();
}

inline std::string stringifyValue(const Value& v) {
    return stringify(v);
}

inline std::string getStringFrom(const Value& root, const std::string& key) {
    if (root.kind != Value::Kind::Object) return "";
    auto it = root.objectVal.find(key);
    if (it == root.objectVal.end() || it->second.kind != Value::Kind::String) return "";
    return it->second.stringVal;
}

inline double getNumberFrom(const Value& root, const std::string& key) {
    if (root.kind != Value::Kind::Object) return 0;
    auto it = root.objectVal.find(key);
    if (it == root.objectVal.end() || it->second.kind != Value::Kind::Number) return 0;
    return it->second.numberVal;
}

inline std::int64_t getIntFrom(const Value& root, const std::string& key) {
    return static_cast<std::int64_t>(getNumberFrom(root, key));
}

inline Value makeObjectValue(const std::string& key, const std::string& value) {
    Value v;
    v.kind = Value::Kind::Object;
    Value field;
    field.kind = Value::Kind::String;
    field.stringVal = value;
    v.objectVal[key] = std::move(field);
    return v;
}

inline bool getBoolFrom(const Value& root, const std::string& key) {
    if (root.kind != Value::Kind::Object) return false;
    auto it = root.objectVal.find(key);
    if (it == root.objectVal.end() || it->second.kind != Value::Kind::Bool) return false;
    return it->second.boolVal;
}

inline bool has(const Value& root, const std::string& key) {
    return root.kind == Value::Kind::Object && root.objectVal.count(key) > 0;
}

inline std::int64_t arrayLength(const Value& root) {
    if (root.kind != Value::Kind::Array) return 0;
    return static_cast<std::int64_t>(root.arrayVal.size());
}

inline Value arrayGetFrom(const Value& root, double index) {
    if (root.kind != Value::Kind::Array) return Value{};
    const auto i = static_cast<std::size_t>(index);
    if (i >= root.arrayVal.size()) return Value{};
    return root.arrayVal[i];
}

// Navigue un chemin pointé (ex "a.b.c") sur objets imbriqués.
inline Value getPath(const Value& root, const std::string& path) {
    const Value* cur = &root;
    std::size_t start = 0;
    while (start <= path.size()) {
        std::size_t dot = path.find('.', start);
        const std::string key =
            path.substr(start, dot == std::string::npos ? std::string::npos : dot - start);
        if (cur->kind != Value::Kind::Object) return Value{};
        auto it = cur->objectVal.find(key);
        if (it == cur->objectVal.end()) return Value{};
        cur = &it->second;
        if (dot == std::string::npos) break;
        start = dot + 1;
    }
    return *cur;
}

inline void stringifyPrettyInto(const Value& v, std::string& out, int indentWidth, int depth) {
    const std::string pad(static_cast<std::size_t>(indentWidth * (depth + 1)), ' ');
    const std::string padEnd(static_cast<std::size_t>(indentWidth * depth), ' ');
    switch (v.kind) {
        case Value::Kind::Array: {
            if (v.arrayVal.empty()) { out += "[]"; return; }
            out += "[\n";
            for (std::size_t i = 0; i < v.arrayVal.size(); ++i) {
                out += pad;
                stringifyPrettyInto(v.arrayVal[i], out, indentWidth, depth + 1);
                if (i + 1 < v.arrayVal.size()) out += ",";
                out += "\n";
            }
            out += padEnd + "]";
            return;
        }
        case Value::Kind::Object: {
            if (v.objectVal.empty()) { out += "{}"; return; }
            out += "{\n";
            std::size_t i = 0;
            for (const auto& [k, val] : v.objectVal) {
                out += pad + "\"" + escape(k) + "\": ";
                stringifyPrettyInto(val, out, indentWidth, depth + 1);
                if (++i < v.objectVal.size()) out += ",";
                out += "\n";
            }
            out += padEnd + "}";
            return;
        }
        default:
            out += stringify(v);
            return;
    }
}

inline std::string stringifyPretty(const Value& v, double indent) {
    std::string out;
    int width = static_cast<int>(indent);
    if (width < 0) width = 0;
    stringifyPrettyInto(v, out, width, 0);
    return out;
}

} // namespace json
} // namespace runtime
} // namespace afrilang
