#pragma once

#include "afrilang/diagnostics.hpp"
#include "afrilang/token.hpp"

#include <string>
#include <unordered_map>
#include <vector>

namespace afrilang {

class Lexer {
public:
    explicit Lexer(std::string source, std::size_t errorLimit = DiagnosticEngine::kDefaultErrorLimit);

    std::vector<Token> tokenize();
    const DiagnosticEngine& diagnostics() const { return diagnostics_; }
    DiagnosticEngine& diagnostics() { return diagnostics_; }
    bool hasErrors() const { return diagnostics_.hasErrors(); }

private:
    std::string source_;
    std::size_t current_ = 0;
    int line_ = 1;
    int column_ = 1;
    DiagnosticEngine diagnostics_;

    static const std::unordered_map<std::string, TokenType> keywords_;

    bool isAtEnd() const;
    char peek() const;
    char peekNext() const;
    char advance();
    void skipWhitespace();

    Token makeToken(TokenType type, std::string lexeme) const;
    Token makeTokenAt(TokenType type, std::string lexeme, int line, int column) const;
    void reportLexerError(const std::string& message, int line, int column);

    Token stringLiteral();
    Token numberLiteral();
    Token identifierOrKeyword();
};

} // namespace afrilang
