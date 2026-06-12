#pragma once

#include <string>
#include <ostream>

namespace afrilang {

enum class TokenType {
    // Mots-clés
    Class, Function, End, Create, New, If, Then,
    Repeat, Times, Say, Is, Greater, Than, Less, Equal, To,
    And, Or, Not, Extends, Returns, Return,
    TypeNumber, TypeText,

    // Littéraux et identifiants
    Identifier,
    StringLiteral,
    NumberLiteral,

    // Symboles
    Plus, Minus, Star, Slash,
    Dot, Equals, Comma, LeftParen, RightParen,

    // Fin de fichier
    Eof
};

struct Token {
    TokenType type;
    std::string lexeme;
    int line;
    int column;

    Token(TokenType type = TokenType::Eof,
          std::string lexeme = "",
          int line = 0,
          int column = 0)
        : type(type), lexeme(std::move(lexeme)), line(line), column(column) {}

    bool is(TokenType t) const { return type == t; }
    bool isOneOf(TokenType a, TokenType b) const { return type == a || type == b; }
    bool isOneOf(TokenType a, TokenType b, TokenType c) const {
        return type == a || type == b || type == c;
    }
};

inline const char* tokenTypeName(TokenType type) {
    switch (type) {
        case TokenType::Class:          return "class";
        case TokenType::Function:       return "function";
        case TokenType::End:            return "end";
        case TokenType::Create:         return "create";
        case TokenType::New:            return "new";
        case TokenType::If:             return "if";
        case TokenType::Then:           return "then";
        case TokenType::Repeat:         return "repeat";
        case TokenType::Times:          return "times";
        case TokenType::Say:            return "say";
        case TokenType::Is:             return "is";
        case TokenType::Greater:        return "greater";
        case TokenType::Than:           return "than";
        case TokenType::Less:           return "less";
        case TokenType::Equal:          return "equal";
        case TokenType::To:             return "to";
        case TokenType::And:            return "and";
        case TokenType::Or:             return "or";
        case TokenType::Not:            return "not";
        case TokenType::Extends:        return "extends";
        case TokenType::Returns:        return "returns";
        case TokenType::Return:         return "return";
        case TokenType::TypeNumber:     return "number";
        case TokenType::TypeText:       return "text";
        case TokenType::Identifier:     return "identifiant";
        case TokenType::StringLiteral:  return "chaîne";
        case TokenType::NumberLiteral:  return "nombre";
        case TokenType::Plus:           return "+";
        case TokenType::Minus:          return "-";
        case TokenType::Star:           return "*";
        case TokenType::Slash:          return "/";
        case TokenType::Dot:            return ".";
        case TokenType::Equals:         return "=";
        case TokenType::Comma:          return ",";
        case TokenType::LeftParen:      return "(";
        case TokenType::RightParen:     return ")";
        case TokenType::Eof:            return "fin de fichier";
    }
    return "inconnu";
}

inline std::ostream& operator<<(std::ostream& os, const Token& token) {
    os << tokenTypeName(token.type);
    if (!token.lexeme.empty() && token.type != TokenType::Eof) {
        os << "('" << token.lexeme << "')";
    }
    return os;
}

} // namespace afrilang
