#pragma once

#include <string>
#include <vector>

namespace afrilang {

enum class TypeKind {
    Void,
    Number,
    Text,
    Bool,
    List,
    Map,
    Class,
    Record,
    Result,
    Pointer,
    Optional,
    Enum,
    TypeVar,
    Function
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
    static AfrType mapType(AfrType key, AfrType value) {
        AfrType t;
        t.kind = TypeKind::Map;
        t.className = key.toTypeName();
        t.listElementTypeName = value.toTypeName();
        return t;
    }
    static AfrType mapTypeFromNames(std::string keyTypeName, std::string valueTypeName) {
        AfrType t;
        t.kind = TypeKind::Map;
        t.className = std::move(keyTypeName);
        t.listElementTypeName = std::move(valueTypeName);
        return t;
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
    static AfrType typeVar(std::string name) {
        return {TypeKind::TypeVar, std::move(name), {}, {}};
    }
    static AfrType functionType(std::string paramTypeNames, std::string returnTypeName) {
        AfrType t;
        t.kind = TypeKind::Function;
        t.className = std::move(paramTypeNames);
        t.listElementTypeName = std::move(returnTypeName);
        return t;
    }

    std::vector<std::string> functionParamTypeNames() const;
    AfrType functionReturnType() const;

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
            case TypeKind::Map:    return "map " + className + " to " + listElementTypeName;
            case TypeKind::Class:  return className;
            case TypeKind::Record: return recordName;
            case TypeKind::Result: return resultInnerType().toTypeName() + " or error";
            case TypeKind::Optional: return optionalInnerType().toTypeName() + "?";
            case TypeKind::Enum:   return className;
            case TypeKind::TypeVar: return className;
            case TypeKind::Function:
                return "function " + className + " to " + listElementTypeName;
        }
        return "void";
    }

    AfrType listElementType() const;
    AfrType mapKeyType() const;
    AfrType mapValueType() const;
    std::string listElementCpp() const;
    std::string toCppFunctionType() const;

    std::string toCpp() const {
        switch (kind) {
            case TypeKind::Void:   return "void";
            case TypeKind::Number: return "double";
            case TypeKind::Text:   return "std::string";
            case TypeKind::Bool:   return "bool";
            case TypeKind::Pointer: return "void*";
            case TypeKind::List:   return "std::vector<" + listElementCpp() + ">";
            case TypeKind::Map:
                return "std::unordered_map<" + mapKeyType().toCpp() + ", " +
                       mapValueType().toCpp() + ">";
            case TypeKind::Class:  return className;
            case TypeKind::Record: return recordName;
            case TypeKind::Result: return "afrilang::runtime::AfrResult_" + listElementTypeName;
            case TypeKind::Optional:
                return "std::optional<" + optionalInnerType().toCpp() + ">";
            case TypeKind::Enum:   return className;
            case TypeKind::TypeVar: return className;
            case TypeKind::Function: return toCppFunctionType();
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
        if (kind == TypeKind::Map) {
            return className == other.className &&
                   listElementTypeName == other.listElementTypeName;
        }
        if (kind == TypeKind::Result) return listElementTypeName == other.listElementTypeName;
        if (kind == TypeKind::Optional) return listElementTypeName == other.listElementTypeName;
        if (kind == TypeKind::Enum) return className == other.className;
        if (kind == TypeKind::TypeVar) return className == other.className;
        if (kind == TypeKind::Function) {
            return className == other.className &&
                   listElementTypeName == other.listElementTypeName;
        }
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
    if (name.size() > 4 && name.substr(0, 4) == "map ") {
        const std::size_t toPos = name.find(" to ");
        if (toPos != std::string::npos) {
            return AfrType::mapTypeFromNames(name.substr(4, toPos - 4),
                                             name.substr(toPos + 4));
        }
    }
    if (name.size() > 9 && name.rfind("function ", 0) == 0) {
        const std::size_t toPos = name.rfind(" to ");
        if (toPos != std::string::npos) {
            return AfrType::functionType(name.substr(9, toPos - 9), name.substr(toPos + 4));
        }
    }
    return AfrType::classType(name);
}

inline std::vector<std::string> splitTypeList(const std::string& raw) {
    std::vector<std::string> parts;
    std::string current;
    for (char c : raw) {
        if (c == ',') {
            if (!current.empty()) {
                while (!current.empty() && current.front() == ' ') current.erase(current.begin());
                while (!current.empty() && current.back() == ' ') current.pop_back();
                parts.push_back(current);
                current.clear();
            }
        } else {
            current += c;
        }
    }
    if (!current.empty()) {
        while (!current.empty() && current.front() == ' ') current.erase(current.begin());
        while (!current.empty() && current.back() == ' ') current.pop_back();
        parts.push_back(current);
    }
    return parts;
}

inline std::vector<std::string> AfrType::functionParamTypeNames() const {
    return splitTypeList(className);
}

inline AfrType AfrType::functionReturnType() const {
    return typeFromName(listElementTypeName);
}

inline std::string AfrType::toCppFunctionType() const {
    const AfrType ret = functionReturnType();
    std::string sig = ret.toCpp() + "(";
    const auto params = functionParamTypeNames();
    for (std::size_t i = 0; i < params.size(); ++i) {
        if (i > 0) sig += ", ";
        sig += typeFromName(params[i]).toCpp();
    }
    sig += ")";
    return "std::function<" + sig + ">";
}

inline AfrType AfrType::listElementType() const {
    return typeFromName(listElementTypeName);
}

inline std::string AfrType::listElementCpp() const {
    const AfrType elem = listElementType();
    if (elem.kind == TypeKind::Class) {
        return "std::unique_ptr<" + elem.className + ">";
    }
    return elem.toCpp();
}

inline AfrType AfrType::mapKeyType() const {
    return typeFromName(className);
}

inline AfrType AfrType::mapValueType() const {
    return typeFromName(listElementTypeName);
}

inline AfrType AfrType::resultInnerType() const {
    return typeFromName(listElementTypeName);
}

inline AfrType AfrType::optionalInnerType() const {
    return typeFromName(listElementTypeName);
}

} // namespace afrilang
