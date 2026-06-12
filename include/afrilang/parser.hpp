#pragma once

#include "afrilang/ast.hpp"
#include "afrilang/token.hpp"

#include <memory>
#include <vector>

namespace afrilang {

class Parser {
public:
    explicit Parser(std::vector<Token> tokens);

    std::unique_ptr<ProgramNode> parse();

private:
    std::vector<Token> tokens_;
    std::size_t current_ = 0;

    bool isAtEnd() const;
    const Token& peek() const;
    const Token& previous() const;
    const Token& advance();
    bool check(TokenType type) const;
    bool match(TokenType type);
    bool matchOneOf(TokenType a, TokenType b);
    bool matchOneOf(TokenType a, TokenType b, TokenType c);
    const Token& consume(TokenType type, const std::string& message);

    [[noreturn]] void error(const std::string& message) const;
    void synchronize();

    std::unique_ptr<ProgramNode> parseProgram();
    std::unique_ptr<ClassNode> parseClass();
    std::unique_ptr<FunctionNode> parseFunction();
    std::unique_ptr<StatementNode> parseStatement();
    std::unique_ptr<StatementNode> parseSayStatement();
    std::unique_ptr<StatementNode> parseCreateStatement();
    std::unique_ptr<StatementNode> parseIfStatement();
    std::unique_ptr<StatementNode> parseRepeatStatement();
    std::unique_ptr<StatementNode> parseReturnStatement();
    std::unique_ptr<StatementNode> parseExpressionStatement();

    std::string parseTypeName();
    std::vector<ParameterNode> parseParameters();

    std::unique_ptr<ExpressionNode> parseExpression();
    std::unique_ptr<ExpressionNode> parseComparison();
    std::unique_ptr<ExpressionNode> parseTerm();
    std::unique_ptr<ExpressionNode> parseFactor();
    std::unique_ptr<ExpressionNode> parseUnary();
    std::unique_ptr<ExpressionNode> parsePrimary();
    std::unique_ptr<ExpressionNode> finishCall(std::unique_ptr<ExpressionNode> callee);
};

} // namespace afrilang
