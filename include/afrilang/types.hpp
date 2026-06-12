#pragma once

#include <string>

namespace afrilang {

enum class TypeKind {
    Void,
    Number,
    Text,
    Bool,
    List,
    Class,
    Record
};

struct AfrType {
    TypeKind kind = TypeKind::Void;
    std::string className;
    std::string recordName;
    std::string listElementTypeName;

    static AfrType voidType() { return {TypeKind::Void, {}, {}, {}}; }
    static AfrType number() { return {TypeKind::Number, {}, {}, {}}; }
    static AfrType text() { return {TypeKind::Text, {}, {}, {}}; }
    static AfrType boolType() { return {TypeKind::Bool, {}, {}, {}}; }
    static AfrType classType(std::string name) {
        return {TypeKind::Class, std::move(name), {}, {}};
    }
    static AfrType listType(AfrType element) {
        AfrType t;
        t.kind = TypeKind::List;
        t.listElementTypeName = element.toTypeName();
        return t;
    }
    static AfrType listTypeFromName(std::string elementTypeName) {
        return {TypeKind::List, {}, {}, std::move(elementTypeName)};
    }
    static AfrType recordType(std::string name) {
        return {TypeKind::Record, {}, std::move(name), {}};
    }

    std::string toTypeName() const {
        switch (kind) {
            case TypeKind::Void:   return "void";
            case TypeKind::Number: return "number";
            case TypeKind::Text:   return "text";
            case TypeKind::Bool:   return "bool";
            case TypeKind::List:   return "list " + listElementTypeName;
            case TypeKind::Class:  return className;
            case TypeKind::Record: return recordName;
        }
        return "void";
    }

    AfrType listElementType() const;

    std::string toCpp() const {
        switch (kind) {
            case TypeKind::Void:   return "void";
            case TypeKind::Number: return "double";
            case TypeKind::Text:   return "std::string";
            case TypeKind::Bool:   return "bool";
            case TypeKind::List:   return "std::vector<" + listElementType().toCpp() + ">";
            case TypeKind::Class:  return className;
            case TypeKind::Record: return recordName;
        }
        return "void";
    }

    bool operator==(const AfrType& other) const {
        if (kind != other.kind) return false;
        if (kind == TypeKind::Class) return className == other.className;
        if (kind == TypeKind::Record) return recordName == other.recordName;
        if (kind == TypeKind::List) return listElementTypeName == other.listElementTypeName;
        return true;
    }

    bool operator!=(const AfrType& other) const { return !(*this == other); }
};

inline AfrType typeFromName(const std::string& name) {
    if (name == "number") return AfrType::number();
    if (name == "text")   return AfrType::text();
    if (name == "bool")   return AfrType::boolType();
    if (name.size() > 5 && name.substr(0, 5) == "list ") {
        return AfrType::listTypeFromName(name.substr(5));
    }
    return AfrType::classType(name);
}

inline AfrType AfrType::listElementType() const {
    return typeFromName(listElementTypeName);
}

} // namespace afrilang
