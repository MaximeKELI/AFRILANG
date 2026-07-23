#pragma once

#include "afrilang/ast.hpp"
#include "afrilang/diagnostics.hpp"
#include "afrilang/token.hpp"

#include <memory>
#include <unordered_set>
#include <vector>

namespace afrilang {

class Parser {
public:
    explicit Parser(std::vector<Token> tokens);

    std::unique_ptr<ProgramNode> parse();
    const DiagnosticEngine& diagnostics() const { return diagnostics_; }
    DiagnosticEngine& diagnostics() { return diagnostics_; }
    bool hasErrors() const { return diagnostics_.hasErrors(); }

private:
    std::vector<Token> tokens_;
    std::size_t current_ = 0;
    std::unordered_set<std::string> enumNames_;
    std::unordered_set<std::string> recordNames_;
    DiagnosticEngine diagnostics_;

    bool isAtEnd() const;
    const Token& peek() const;
    const Token& previous() const;
    const Token& advance();
    bool check(TokenType type) const;
    bool checkNext(TokenType type) const;
    bool match(TokenType type);
    bool matchOneOf(TokenType a, TokenType b);
    bool matchOneOf(TokenType a, TokenType b, TokenType c);
    bool matchOneOf(TokenType a, TokenType b, TokenType c, TokenType d);
    const Token& consume(TokenType type, const std::string& message);

    [[noreturn]] void error(const std::string& message) const;
    void synchronize();
    void synchronizeInBlock();
    bool isStatementStart() const;

    void setLoc(ASTNode& node) const;
    bool matchName(std::string& out);
    const Token& consumeName(const std::string& message);
    std::vector<std::string> parseDecorators();

    std::unique_ptr<ProgramNode> parseProgram();
    std::unique_ptr<ImportNode> parseImport();
    std::unique_ptr<ExternDeclNode> parseExtern();
    std::unique_ptr<ModuleNode> parseModule();
    std::unique_ptr<RecordNode> parseRecord();
    std::unique_ptr<EnumNode> parseEnum();
    std::unique_ptr<InterfaceNode> parseInterface();
    std::unique_ptr<TestNode> parseTest();
    std::unique_ptr<ClassNode> parseClass(bool isAbstract = false, bool isFinal = false);
    std::unique_ptr<FunctionNode> parseFunction(bool signatureOnly = false,
                                                    bool isStatic = false,
                                                    bool isAbstract = false,
                                                    bool isFinal = false);
    std::unique_ptr<FunctionNode> parseOperatorMethod();
    std::string parseOperatorSymbol();
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
    std::unique_ptr<ExpressionNode> parseFlatMapEachExpression();
    std::unique_ptr<ExpressionNode> parseFilterEachExpression();
    std::unique_ptr<ExpressionNode> parseListEachExpression();
    std::unique_ptr<ExpressionNode> parseReduceExpression();
    std::unique_ptr<StatementNode> parseMatchStatement();
    std::unique_ptr<ExpressionNode> parseMatchExpression();
    bool startsMatchArmStatement() const;
    // Motif d'un bras de match, partage entre la forme statement et expression.
    struct MatchPattern {
        MatchArmNode::CaseKind caseKind = MatchArmNode::CaseKind::Enum;
        std::string caseName;
        std::vector<std::string> bindNames;
        std::vector<std::string> orValues;
        std::string rangeLow;
        std::string rangeHigh;
    };
    MatchPattern parseMatchPattern();
    std::unique_ptr<StatementNode> parseReturnStatement();
    std::unique_ptr<StatementNode> parseAssertStatement();
    std::unique_ptr<StatementNode> parseAskStatement();
    std::unique_ptr<StatementNode> parseUseStatement();
    std::unique_ptr<StatementNode> parseAddToListStatement();
    std::unique_ptr<StatementNode> parseTryStatement();
    std::unique_ptr<StatementNode> parseRaiseStatement();
    std::unique_ptr<StatementNode> parseExplainStatement();
    std::unique_ptr<StatementNode> parseOpenWindowStatement();
    std::unique_ptr<StatementNode> parseCloseWindowStatement();
    std::unique_ptr<StatementNode> parseShowFrameStatement();
    std::unique_ptr<StatementNode> parseClearBackgroundStatement();
    std::unique_ptr<StatementNode> parseDrawTextStatement();
    std::unique_ptr<StatementNode> parseExpressionStatement();

    bool matchToOrThan();
    void consumeToOrThan(const std::string& message);
    void consumeIntoOrEn(const std::string& message);

    std::vector<std::string> parseTypeParams();
    std::string parseTypeName();
    std::vector<ParameterNode> parseParameters();
    std::vector<std::unique_ptr<StatementNode>> parseBlock();

    std::unique_ptr<ExpressionNode> parseExpression();
    std::unique_ptr<ExpressionNode> parseOperand();
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
