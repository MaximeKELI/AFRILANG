#pragma once

#include <string>

namespace afrilang {

enum class TypeKind {
    Void,
    Number,
    Text,
    Class
};

struct AfrType {
    TypeKind kind = TypeKind::Void;
    std::string className;

    static AfrType voidType() { return {TypeKind::Void, {}}; }
    static AfrType number() { return {TypeKind::Number, {}}; }
    static AfrType text() { return {TypeKind::Text, {}}; }
    static AfrType classType(std::string name) {
        return {TypeKind::Class, std::move(name)};
    }

    std::string toCpp() const {
        switch (kind) {
            case TypeKind::Void:   return "void";
            case TypeKind::Number: return "double";
            case TypeKind::Text:   return "std::string";
            case TypeKind::Class:  return className;
        }
        return "void";
    }

    bool operator==(const AfrType& other) const {
        if (kind != other.kind) return false;
        if (kind == TypeKind::Class) return className == other.className;
        return true;
    }

    bool operator!=(const AfrType& other) const { return !(*this == other); }
};

inline AfrType typeFromName(const std::string& name) {
    if (name == "number") return AfrType::number();
    if (name == "text")   return AfrType::text();
    return AfrType::classType(name);
}

} // namespace afrilang
