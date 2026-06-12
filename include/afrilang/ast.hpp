#pragma once

#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace afrilang {

// ── Base ──────────────────────────────────────────────────────────────────────

struct ASTNode {
    virtual ~ASTNode() = default;
};

struct ExpressionNode : ASTNode {};
struct StatementNode : ASTNode {};

// ── Expressions ─────────────────────────────────────────────────────────────

struct StringLiteralNode : ExpressionNode {
    std::string value;
    explicit StringLiteralNode(std::string value) : value(std::move(value)) {}
};

struct NumberLiteralNode : ExpressionNode {
    double value;
    explicit NumberLiteralNode(double value) : value(value) {}
};

struct IdentifierNode : ExpressionNode {
    std::string name;
    explicit IdentifierNode(std::string name) : name(std::move(name)) {}
};

struct BinaryOpNode : ExpressionNode {
    std::string op;
    std::unique_ptr<ExpressionNode> left;
    std::unique_ptr<ExpressionNode> right;

    BinaryOpNode(std::string op,
                 std::unique_ptr<ExpressionNode> left,
                 std::unique_ptr<ExpressionNode> right)
        : op(std::move(op))
        , left(std::move(left))
        , right(std::move(right)) {}
};

struct UnaryOpNode : ExpressionNode {
    std::string op;
    std::unique_ptr<ExpressionNode> operand;

    UnaryOpNode(std::string op, std::unique_ptr<ExpressionNode> operand)
        : op(std::move(op)), operand(std::move(operand)) {}
};

struct CallExpressionNode : ExpressionNode {
    std::unique_ptr<ExpressionNode> callee;
    std::vector<std::unique_ptr<ExpressionNode>> arguments;

    CallExpressionNode(std::unique_ptr<ExpressionNode> callee,
                       std::vector<std::unique_ptr<ExpressionNode>> arguments = {})
        : callee(std::move(callee)), arguments(std::move(arguments)) {}
};

struct MemberAccessNode : ExpressionNode {
    std::unique_ptr<ExpressionNode> object;
    std::string member;

    MemberAccessNode(std::unique_ptr<ExpressionNode> object, std::string member)
        : object(std::move(object)), member(std::move(member)) {}
};

struct NewExpressionNode : ExpressionNode {
    std::string className;
    explicit NewExpressionNode(std::string className) : className(std::move(className)) {}
};

// ── Statements ────────────────────────────────────────────────────────────────

struct SayStatementNode : StatementNode {
    std::unique_ptr<ExpressionNode> value;
    explicit SayStatementNode(std::unique_ptr<ExpressionNode> value)
        : value(std::move(value)) {}
};

struct AssignStatementNode : StatementNode {
    std::string name;
    std::unique_ptr<ExpressionNode> value;

    AssignStatementNode(std::string name, std::unique_ptr<ExpressionNode> value)
        : name(std::move(name)), value(std::move(value)) {}
};

struct ReturnStatementNode : StatementNode {
    std::unique_ptr<ExpressionNode> value;
    explicit ReturnStatementNode(std::unique_ptr<ExpressionNode> value)
        : value(std::move(value)) {}
};

struct IfStatementNode : StatementNode {
    std::unique_ptr<ExpressionNode> condition;
    std::vector<std::unique_ptr<StatementNode>> body;

    IfStatementNode(std::unique_ptr<ExpressionNode> condition,
                    std::vector<std::unique_ptr<StatementNode>> body)
        : condition(std::move(condition)), body(std::move(body)) {}
};

struct RepeatStatementNode : StatementNode {
    std::unique_ptr<ExpressionNode> count;
    std::vector<std::unique_ptr<StatementNode>> body;

    RepeatStatementNode(std::unique_ptr<ExpressionNode> count,
                        std::vector<std::unique_ptr<StatementNode>> body)
        : count(std::move(count)), body(std::move(body)) {}
};

struct ExpressionStatementNode : StatementNode {
    std::unique_ptr<ExpressionNode> expression;
    explicit ExpressionStatementNode(std::unique_ptr<ExpressionNode> expression)
        : expression(std::move(expression)) {}
};

// ── Déclarations ─────────────────────────────────────────────────────────────

struct ParameterNode {
    std::string name;
    std::string typeName;

    ParameterNode(std::string name, std::string typeName)
        : name(std::move(name)), typeName(std::move(typeName)) {}
};

struct FunctionNode : ASTNode {
    std::string name;
    std::vector<ParameterNode> parameters;
    std::string returnTypeName;
    std::vector<std::unique_ptr<StatementNode>> body;

    FunctionNode(std::string name,
                 std::vector<ParameterNode> parameters,
                 std::string returnTypeName,
                 std::vector<std::unique_ptr<StatementNode>> body)
        : name(std::move(name))
        , parameters(std::move(parameters))
        , returnTypeName(std::move(returnTypeName))
        , body(std::move(body)) {}
};

struct ClassNode : ASTNode {
    std::string name;
    std::string baseClassName;
    std::vector<std::unique_ptr<FunctionNode>> methods;

    ClassNode(std::string name,
              std::string baseClassName,
              std::vector<std::unique_ptr<FunctionNode>> methods)
        : name(std::move(name))
        , baseClassName(std::move(baseClassName))
        , methods(std::move(methods)) {}
};

struct ProgramNode : ASTNode {
    std::vector<std::unique_ptr<ClassNode>> classes;
    std::vector<std::unique_ptr<FunctionNode>> functions;
    std::vector<std::unique_ptr<StatementNode>> statements;

    ProgramNode(std::vector<std::unique_ptr<ClassNode>> classes,
                std::vector<std::unique_ptr<FunctionNode>> functions,
                std::vector<std::unique_ptr<StatementNode>> statements)
        : classes(std::move(classes))
        , functions(std::move(functions))
        , statements(std::move(statements)) {}
};

} // namespace afrilang
