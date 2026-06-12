#pragma once

#include <cctype>
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
                    case 'n': v.stringVal += '\n'; break;
                    case 't': v.stringVal += '\t'; break;
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
        while (true) {
            skipWs();
            Value key = parseString();
            skipWs();
            get(); // :
            Value val = parseValue();
            v.objectVal[key.stringVal] = std::move(val);
            skipWs();
            if (peek() == '}') { get(); break; }
            get(); // ,
        }
        return v;
    }

    Value parseArray() {
        get();
        Value v;
        v.kind = Value::Kind::Array;
        skipWs();
        if (peek() == ']') { get(); return v; }
        while (true) {
            v.arrayVal.push_back(parseValue());
            skipWs();
            if (peek() == ']') { get(); break; }
            get();
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

inline std::string parse(const std::string& text) {
    Parser parser(text);
    return stringify(parser.parse());
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

} // namespace json
} // namespace runtime
} // namespace afrilang
