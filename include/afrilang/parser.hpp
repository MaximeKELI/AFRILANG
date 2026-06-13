#pragma once

#include "afrilang/ast.hpp"
#include "afrilang/token.hpp"

#include <memory>
#include <unordered_set>
#include <vector>

namespace afrilang {

class Parser {
public:
    explicit Parser(std::vector<Token> tokens);

    std::unique_ptr<ProgramNode> parse();

private:
    std::vector<Token> tokens_;
    std::size_t current_ = 0;
    std::unordered_set<std::string> enumNames_;

    bool isAtEnd() const;
    const Token& peek() const;
    const Token& previous() const;
    const Token& advance();
    bool check(TokenType type) const;
    bool match(TokenType type);
    bool matchOneOf(TokenType a, TokenType b);
    bool matchOneOf(TokenType a, TokenType b, TokenType c);
    bool matchOneOf(TokenType a, TokenType b, TokenType c, TokenType d);
    const Token& consume(TokenType type, const std::string& message);

    [[noreturn]] void error(const std::string& message) const;
    void synchronize();

    void setLoc(ASTNode& node) const;
    bool matchName(std::string& out);
    const Token& consumeName(const std::string& message);

    std::unique_ptr<ProgramNode> parseProgram();
    std::unique_ptr<ImportNode> parseImport();
    std::unique_ptr<ExternDeclNode> parseExtern();
    std::unique_ptr<ModuleNode> parseModule();
    std::unique_ptr<RecordNode> parseRecord();
    std::unique_ptr<EnumNode> parseEnum();
    std::unique_ptr<InterfaceNode> parseInterface();
    std::unique_ptr<TestNode> parseTest();
    std::unique_ptr<ClassNode> parseClass();
    std::unique_ptr<FunctionNode> parseFunction(bool signatureOnly = false);
    FieldNode parseField();
    std::unique_ptr<StatementNode> parseStatement();
    std::unique_ptr<StatementNode> parseSayStatement();
    std::unique_ptr<StatementNode> parseCreateStatement();
    std::unique_ptr<StatementNode> parseSetStatement();
    std::unique_ptr<StatementNode> parseIfStatement();
    std::unique_ptr<StatementNode> parseWhileStatement();
    std::unique_ptr<StatementNode> parseRepeatStatement();
    std::unique_ptr<StatementNode> parseForEachStatement();
    std::unique_ptr<StatementNode> parseForRangeStatement();
    std::unique_ptr<ExpressionNode> parseLambdaExpression();
    std::unique_ptr<ExpressionNode> parseMapEachExpression();
    std::unique_ptr<ExpressionNode> parseFilterEachExpression();
    std::unique_ptr<ExpressionNode> parseReduceExpression();
    std::unique_ptr<StatementNode> parseMatchStatement();
    std::unique_ptr<StatementNode> parseReturnStatement();
    std::unique_ptr<StatementNode> parseAssertStatement();
    std::unique_ptr<StatementNode> parseAskStatement();
    std::unique_ptr<StatementNode> parseUseStatement();
    std::unique_ptr<StatementNode> parseAddToListStatement();
    std::unique_ptr<StatementNode> parseTryStatement();
    std::unique_ptr<StatementNode> parseRaiseStatement();
    std::unique_ptr<StatementNode> parseExplainStatement();
    std::unique_ptr<StatementNode> parseExpressionStatement();

    bool matchToOrThan();
    void consumeToOrThan(const std::string& message);
    void consumeIntoOrEn(const std::string& message);

    std::vector<std::string> parseTypeParams();
    std::string parseTypeName();
    std::vector<ParameterNode> parseParameters();
    std::vector<std::unique_ptr<StatementNode>> parseBlock();

    std::unique_ptr<ExpressionNode> parseExpression();
    std::unique_ptr<ExpressionNode> parseComparison();
    std::unique_ptr<ExpressionNode> parseTerm();
    std::unique_ptr<ExpressionNode> parseFactor();
    std::unique_ptr<ExpressionNode> parseUnary();
    std::unique_ptr<ExpressionNode> parsePrimary();
    std::unique_ptr<ExpressionNode> parseStringExpression(const std::string& raw);
    std::unique_ptr<ExpressionNode> parsePostfix(std::unique_ptr<ExpressionNode> expr);
    std::unique_ptr<ExpressionNode> finishCall(std::unique_ptr<ExpressionNode> callee);
    std::unique_ptr<ExpressionNode> parseListLiteral();
};

} // namespace afrilang
