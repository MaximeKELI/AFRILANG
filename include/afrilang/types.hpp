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
    Record,
    Result,
    Pointer,
    Optional,
    Enum
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
    static AfrType pointer() { return {TypeKind::Pointer, {}, {}, {}}; }
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
    static AfrType resultType(AfrType inner) {
        AfrType t;
        t.kind = TypeKind::Result;
        t.listElementTypeName = inner.toTypeName();
        return t;
    }
    static AfrType optionalType(AfrType inner) {
        AfrType t;
        t.kind = TypeKind::Optional;
        t.listElementTypeName = inner.toTypeName();
        return t;
    }
    static AfrType enumType(std::string name) {
        return {TypeKind::Enum, std::move(name), {}, {}};
    }

    AfrType resultInnerType() const;
    AfrType optionalInnerType() const;

    std::string toTypeName() const {
        switch (kind) {
            case TypeKind::Void:   return "void";
            case TypeKind::Number: return "number";
            case TypeKind::Text:   return "text";
            case TypeKind::Bool:   return "bool";
            case TypeKind::Pointer: return "pointer";
            case TypeKind::List:   return "list " + listElementTypeName;
            case TypeKind::Class:  return className;
            case TypeKind::Record: return recordName;
            case TypeKind::Result: return resultInnerType().toTypeName() + " or error";
            case TypeKind::Optional: return optionalInnerType().toTypeName() + "?";
            case TypeKind::Enum:   return className;
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
            case TypeKind::Pointer: return "void*";
            case TypeKind::List:   return "std::vector<" + listElementType().toCpp() + ">";
            case TypeKind::Class:  return className;
            case TypeKind::Record: return recordName;
            case TypeKind::Result: return "afrilang::runtime::AfrResult_" + listElementTypeName;
            case TypeKind::Optional:
                return "std::optional<" + optionalInnerType().toCpp() + ">";
            case TypeKind::Enum:   return className;
        }
        return "void";
    }

    static std::string resultCppAlias(const std::string& innerTypeName) {
        return "afrilang::runtime::AfrResult_" + innerTypeName;
    }

    bool operator==(const AfrType& other) const {
        if (kind != other.kind) return false;
        if (kind == TypeKind::Class) return className == other.className;
        if (kind == TypeKind::Record) return recordName == other.recordName;
        if (kind == TypeKind::List) return listElementTypeName == other.listElementTypeName;
        if (kind == TypeKind::Result) return listElementTypeName == other.listElementTypeName;
        if (kind == TypeKind::Optional) return listElementTypeName == other.listElementTypeName;
        if (kind == TypeKind::Enum) return className == other.className;
        return true;
    }

    bool operator!=(const AfrType& other) const { return !(*this == other); }
};

inline AfrType typeFromName(const std::string& name) {
    if (!name.empty() && name.back() == '?') {
        return AfrType::optionalType(typeFromName(name.substr(0, name.size() - 1)));
    }
    if (name == "number") return AfrType::number();
    if (name == "text")   return AfrType::text();
    if (name == "bool")   return AfrType::boolType();
    if (name == "pointer") return AfrType::pointer();
    if (name.size() > 5 && name.substr(0, 5) == "list ") {
        return AfrType::listTypeFromName(name.substr(5));
    }
    return AfrType::classType(name);
}

inline AfrType AfrType::listElementType() const {
    return typeFromName(listElementTypeName);
}

inline AfrType AfrType::resultInnerType() const {
    return typeFromName(listElementTypeName);
}

inline AfrType AfrType::optionalInnerType() const {
    return typeFromName(listElementTypeName);
}

} // namespace afrilang
