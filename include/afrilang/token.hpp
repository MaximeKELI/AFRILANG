#pragma once

#include <string>
#include <ostream>

namespace afrilang {

enum class TokenType {
    // Mots-clés
    Class, Function, End, Create, New, If, Then, Else,
    Repeat, Times, Say, Is, Greater, Than, Less, Equal, To,
    And, Or, Not, Extends, Returns, Return,
    TypeNumber, TypeInt, TypeBigInt, TypeText, TypeBool, TypeJson,
    Yield, Generator, Setup, Teardown, Spawn,
    While, Do, For, Each, In, Stop, Skip,
    Module, Use, Import, Export, Record, Field, Public, Private,
    Set, This, Ask, Into, As, At, Add, Length, Of, Empty, List,
    True, False, Yes, No,
    Interface, Implements, Test, Assert, ErrorKw,
    Extern, From,
    Explain,
    Enum, Case, Match, Default, With, Nothing, Defined,
    Union, Operator,
    Map, Try, Catch, Raise, Finally, Macro,
    Const, Step,
    Filter, Reduce, Where, FlatMap,
    Super, Static, Abstract, Protected, Final, Property, Destroy,
    Async, Await, Task,
    Open, Window, Titled, Draw, Button, Clicked, Background, Frame, Color,
    Width, Height, Size, Close, Show, Clear,
    Identifier,
    StringLiteral,
    NumberLiteral,

    // Symboles
    AtSign,
    Plus, Minus, Star, Slash,
    Dot, Equals, Comma, LeftParen, RightParen,
    LeftBracket, RightBracket,
    Question,
    QuestionDot,
    DotDot, DotDotLess,
    AngleOpen, AngleClose,
    Bang,

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
        case TokenType::Else:           return "else";
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
        case TokenType::TypeInt:        return "int";
        case TokenType::TypeBigInt:     return "bigint";
        case TokenType::TypeText:       return "text";
        case TokenType::Yield:          return "yield";
        case TokenType::Generator:      return "generator";
        case TokenType::Setup:          return "setup";
        case TokenType::Teardown:       return "teardown";
        case TokenType::Spawn:          return "spawn";
        case TokenType::TypeBool:       return "bool";
        case TokenType::TypeJson:       return "json";
        case TokenType::While:          return "while";
        case TokenType::Do:             return "do";
        case TokenType::For:            return "for";
        case TokenType::Each:           return "each";
        case TokenType::In:             return "in";
        case TokenType::Stop:           return "stop";
        case TokenType::Skip:           return "skip";
        case TokenType::Module:         return "module";
        case TokenType::Use:            return "use";
        case TokenType::Import:         return "import";
        case TokenType::Export:         return "export";
        case TokenType::Record:         return "record";
        case TokenType::Field:          return "field";
        case TokenType::Public:         return "public";
        case TokenType::Private:        return "private";
        case TokenType::Set:            return "set";
        case TokenType::This:           return "this";
        case TokenType::Ask:            return "ask";
        case TokenType::Into:           return "into";
        case TokenType::As:             return "as";
        case TokenType::At:             return "at";
        case TokenType::Add:            return "add";
        case TokenType::Length:         return "length";
        case TokenType::Of:             return "of";
        case TokenType::Empty:          return "empty";
        case TokenType::List:           return "list";
        case TokenType::True:           return "true";
        case TokenType::False:          return "false";
        case TokenType::Yes:            return "yes";
        case TokenType::No:             return "no";
        case TokenType::Interface:      return "interface";
        case TokenType::Implements:     return "implements";
        case TokenType::Test:           return "test";
        case TokenType::Assert:         return "assert";
        case TokenType::ErrorKw:        return "error";
        case TokenType::Extern:         return "extern";
        case TokenType::From:           return "from";
        case TokenType::Explain:        return "explain";
        case TokenType::Enum:           return "enum";
        case TokenType::Union:          return "union";
        case TokenType::Operator:       return "operator";
        case TokenType::Case:           return "case";
        case TokenType::Match:          return "match";
        case TokenType::Default:        return "default";
        case TokenType::With:           return "with";
        case TokenType::Nothing:        return "nothing";
        case TokenType::Defined:        return "defined";
        case TokenType::Map:            return "map";
        case TokenType::Try:            return "try";
        case TokenType::Catch:          return "catch";
        case TokenType::Raise:          return "raise";
        case TokenType::Finally:        return "finally";
        case TokenType::Macro:          return "macro";
        case TokenType::Const:          return "const";
        case TokenType::Step:           return "step";
        case TokenType::Filter:         return "filter";
        case TokenType::Reduce:         return "reduce";
        case TokenType::Where:          return "where";
        case TokenType::FlatMap:        return "flatMap";
        case TokenType::Super:          return "super";
        case TokenType::Static:         return "static";
        case TokenType::Abstract:       return "abstract";
        case TokenType::Protected:      return "protected";
        case TokenType::Final:          return "final";
        case TokenType::Property:       return "property";
        case TokenType::Destroy:        return "destroy";
        case TokenType::Async:          return "async";
        case TokenType::Await:          return "await";
        case TokenType::Task:           return "task";
        case TokenType::Open:           return "open";
        case TokenType::Window:         return "window";
        case TokenType::Titled:         return "titled";
        case TokenType::Draw:           return "draw";
        case TokenType::Button:         return "button";
        case TokenType::Clicked:        return "clicked";
        case TokenType::Background:     return "background";
        case TokenType::Frame:          return "frame";
        case TokenType::Color:          return "color";
        case TokenType::Width:          return "width";
        case TokenType::Height:         return "height";
        case TokenType::Size:           return "size";
        case TokenType::Close:          return "close";
        case TokenType::Show:           return "show";
        case TokenType::Clear:          return "clear";
        case TokenType::Question:       return "?";
        case TokenType::QuestionDot:    return "?.";
        case TokenType::DotDot:         return "..";
        case TokenType::DotDotLess:     return "..<";
        case TokenType::Identifier:     return "identifiant";
        case TokenType::StringLiteral:  return "chaîne";
        case TokenType::NumberLiteral:  return "nombre";
        case TokenType::AtSign:         return "@";
        case TokenType::Plus:           return "+";
        case TokenType::Minus:          return "-";
        case TokenType::Star:           return "*";
        case TokenType::Slash:          return "/";
        case TokenType::Dot:            return ".";
        case TokenType::Equals:         return "=";
        case TokenType::Comma:          return ",";
        case TokenType::LeftParen:      return "(";
        case TokenType::RightParen:     return ")";
        case TokenType::LeftBracket:    return "[";
        case TokenType::RightBracket:   return "]";
        case TokenType::AngleOpen:      return "<";
        case TokenType::AngleClose:     return ">";
        case TokenType::Bang:           return "!";
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
