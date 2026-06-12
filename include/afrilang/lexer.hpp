#pragma once

#include "afrilang/token.hpp"

#include <string>
#include <unordered_map>
#include <vector>

namespace afrilang {

class Lexer {
public:
    explicit Lexer(std::string source);

    std::vector<Token> tokenize();

private:
    std::string source_;
    std::size_t current_ = 0;
    int line_ = 1;
    int column_ = 1;

    static const std::unordered_map<std::string, TokenType> keywords_;

    bool isAtEnd() const;
    char peek() const;
    char peekNext() const;
    char advance();
    void skipWhitespace();

    Token makeToken(TokenType type, std::string lexeme) const;
    Token errorToken(const std::string& message) const;

    Token stringLiteral();
    Token numberLiteral();
    Token identifierOrKeyword();
};

} // namespace afrilang
