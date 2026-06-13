#include "afrilang/lexer.hpp"

#include "afrilang/error.hpp"

#include <cctype>

namespace afrilang {

const std::unordered_map<std::string, TokenType> Lexer::keywords_ = {
    {"class",    TokenType::Class},
    {"function", TokenType::Function},
    {"end",      TokenType::End},
    {"create",   TokenType::Create},
    {"new",      TokenType::New},
    {"if",       TokenType::If},
    {"then",     TokenType::Then},
    {"else",     TokenType::Else},
    {"repeat",   TokenType::Repeat},
    {"times",    TokenType::Times},
    {"say",      TokenType::Say},
    {"is",       TokenType::Is},
    {"greater",  TokenType::Greater},
    {"than",     TokenType::Than},
    {"less",     TokenType::Less},
    {"equal",    TokenType::Equal},
    {"to",       TokenType::To},
    {"and",      TokenType::And},
    {"or",       TokenType::Or},
    {"not",      TokenType::Not},
    {"extends",  TokenType::Extends},
    {"returns",  TokenType::Returns},
    {"return",   TokenType::Return},
    {"number",   TokenType::TypeNumber},
    {"text",     TokenType::TypeText},
    {"bool",     TokenType::TypeBool},
    {"while",    TokenType::While},
    {"do",       TokenType::Do},
    {"for",      TokenType::For},
    {"each",     TokenType::Each},
    {"in",       TokenType::In},
    {"stop",     TokenType::Stop},
    {"skip",     TokenType::Skip},
    {"module",   TokenType::Module},
    {"use",      TokenType::Use},
    {"import",   TokenType::Import},
    {"record",   TokenType::Record},
    {"field",    TokenType::Field},
    {"public",   TokenType::Public},
    {"private",  TokenType::Private},
    {"set",      TokenType::Set},
    {"this",     TokenType::This},
    {"ask",      TokenType::Ask},
    {"into",     TokenType::Into},
    {"at",       TokenType::At},
    {"add",      TokenType::Add},
    {"length",   TokenType::Length},
    {"of",       TokenType::Of},
    {"empty",    TokenType::Empty},
    {"list",     TokenType::List},
    {"true",     TokenType::True},
    {"false",    TokenType::False},
    {"yes",      TokenType::Yes},
    {"no",       TokenType::No},
    {"interface", TokenType::Interface},
    {"implements", TokenType::Implements},
    {"test",     TokenType::Test},
    {"assert",   TokenType::Assert},
    {"error",    TokenType::ErrorKw},
    {"extern",   TokenType::Extern},
    {"from",     TokenType::From},
    {"explain",  TokenType::Explain},
    {"enum",     TokenType::Enum},
    {"case",     TokenType::Case},
    {"match",    TokenType::Match},
    {"default",  TokenType::Default},
    {"with",     TokenType::With},
    {"nothing",  TokenType::Nothing},
    {"defined",  TokenType::Defined},
};

Lexer::Lexer(std::string source) : source_(std::move(source)) {}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    tokens.reserve(source_.size() / 4);

    while (!isAtEnd()) {
        skipWhitespace();
        if (isAtEnd()) break;

        const int startLine = line_;
        const int startColumn = column_;
        char c = peek();

        if (c == '"') {
            tokens.push_back(stringLiteral());
        } else if (std::isdigit(static_cast<unsigned char>(c))) {
            tokens.push_back(numberLiteral());
        } else if (std::isalpha(static_cast<unsigned char>(c)) || c == '_') {
            tokens.push_back(identifierOrKeyword());
        } else {
            advance();
            switch (c) {
                case '+': tokens.push_back(makeToken(TokenType::Plus, "+")); break;
                case '-': tokens.push_back(makeToken(TokenType::Minus, "-")); break;
                case '*': tokens.push_back(makeToken(TokenType::Star, "*")); break;
                case '/':
                    if (peek() == '/') {
                        while (!isAtEnd() && peek() != '\n') advance();
                    } else {
                        tokens.push_back(makeToken(TokenType::Slash, "/"));
                    }
                    break;
                case '.': tokens.push_back(makeToken(TokenType::Dot, ".")); break;
                case '=': tokens.push_back(makeToken(TokenType::Equals, "=")); break;
                case ',': tokens.push_back(makeToken(TokenType::Comma, ",")); break;
                case '(': tokens.push_back(makeToken(TokenType::LeftParen, "(")); break;
                case ')': tokens.push_back(makeToken(TokenType::RightParen, ")")); break;
                case '[': tokens.push_back(makeToken(TokenType::LeftBracket, "[")); break;
                case ']': tokens.push_back(makeToken(TokenType::RightBracket, "]")); break;
                case '?': tokens.push_back(makeToken(TokenType::Question, "?")); break;
                case '<': tokens.push_back(makeToken(TokenType::AngleOpen, "<")); break;
                case '>': tokens.push_back(makeToken(TokenType::AngleClose, ">")); break;
                default:
                    throw CompileError(
                        std::string("Caractère inattendu '") + c + "'",
                        startLine, startColumn);
            }
        }
    }

    tokens.push_back(makeToken(TokenType::Eof, ""));
    return tokens;
}

bool Lexer::isAtEnd() const {
    return current_ >= source_.size();
}

char Lexer::peek() const {
    if (isAtEnd()) return '\0';
    return source_[current_];
}

char Lexer::peekNext() const {
    if (current_ + 1 >= source_.size()) return '\0';
    return source_[current_ + 1];
}

char Lexer::advance() {
    char c = source_[current_++];
    if (c == '\n') {
        line_++;
        column_ = 1;
    } else {
        column_++;
    }
    return c;
}

void Lexer::skipWhitespace() {
    while (!isAtEnd()) {
        char c = peek();
        if (c == ' ' || c == '\t' || c == '\r' || c == '\n') {
            advance();
        } else {
            break;
        }
    }
}

Token Lexer::makeToken(TokenType type, std::string lexeme) const {
    return Token(type, std::move(lexeme), line_, column_);
}

Token Lexer::errorToken(const std::string& message) const {
    throw CompileError(message, line_, column_);
}

Token Lexer::stringLiteral() {
    const int startLine = line_;
    const int startColumn = column_;
    advance();

    std::string value;
    while (!isAtEnd() && peek() != '"') {
        char c = advance();
        if (c == '\\' && !isAtEnd()) {
            char esc = advance();
            switch (esc) {
                case 'n':  value += '\n'; break;
                case 't':  value += '\t'; break;
                case '"':  value += '"';  break;
                case '\\': value += '\\'; break;
                default:   value += esc;  break;
            }
        } else if (c == '\n') {
            throw CompileError("Chaîne non terminée", startLine, startColumn);
        } else {
            value += c;
        }
    }

    if (isAtEnd()) {
        throw CompileError("Chaîne non terminée", startLine, startColumn);
    }

    advance();
    return Token(TokenType::StringLiteral, std::move(value), startLine, startColumn);
}

Token Lexer::numberLiteral() {
    const int startLine = line_;
    const int startColumn = column_;

    std::string num;
    while (!isAtEnd() && std::isdigit(static_cast<unsigned char>(peek()))) {
        num += advance();
    }

    if (peek() == '.' && std::isdigit(static_cast<unsigned char>(peekNext()))) {
        num += advance();
        while (!isAtEnd() && std::isdigit(static_cast<unsigned char>(peek()))) {
            num += advance();
        }
    }

    return Token(TokenType::NumberLiteral, std::move(num), startLine, startColumn);
}

Token Lexer::identifierOrKeyword() {
    const int startLine = line_;
    const int startColumn = column_;

    std::string text;
    while (!isAtEnd()) {
        char c = peek();
        if (std::isalnum(static_cast<unsigned char>(c)) || c == '_') {
            text += advance();
        } else {
            break;
        }
    }

    auto it = keywords_.find(text);
    TokenType type = (it != keywords_.end()) ? it->second : TokenType::Identifier;
    return Token(type, std::move(text), startLine, startColumn);
}

} // namespace afrilang
