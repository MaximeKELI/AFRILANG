#pragma once

#include <memory>
#include <string>
#include <utility>
#include <vector>

namespace afrilang {

// ── Source locations ──────────────────────────────────────────────────────────

struct SourceLoc {
    int line = 0;
    int column = 0;
};

// ── Base ──────────────────────────────────────────────────────────────────────

struct ASTNode {
    SourceLoc loc;
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

struct BoolLiteralNode : ExpressionNode {
    bool value;
    explicit BoolLiteralNode(bool value) : value(value) {}
};

struct IdentifierNode : ExpressionNode {
    std::string name;
    explicit IdentifierNode(std::string name) : name(std::move(name)) {}
};

struct ThisExpressionNode : ExpressionNode {};

struct SuperExpressionNode : ExpressionNode {};

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

struct IsErrorCheckNode : ExpressionNode {
    std::unique_ptr<ExpressionNode> value;
    explicit IsErrorCheckNode(std::unique_ptr<ExpressionNode> value)
        : value(std::move(value)) {}
};

struct IsDefinedCheckNode : ExpressionNode {
    std::unique_ptr<ExpressionNode> value;
    explicit IsDefinedCheckNode(std::unique_ptr<ExpressionNode> value)
        : value(std::move(value)) {}
};

struct NothingLiteralNode : ExpressionNode {};

struct EnumCaseExprNode : ExpressionNode {
    std::string enumName;
    std::string caseName;
    std::vector<std::unique_ptr<ExpressionNode>> arguments;

    EnumCaseExprNode(std::string enumName, std::string caseName,
                     std::vector<std::unique_ptr<ExpressionNode>> arguments = {})
        : enumName(std::move(enumName))
        , caseName(std::move(caseName))
        , arguments(std::move(arguments)) {}
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

struct ListLiteralNode : ExpressionNode {
    std::vector<std::unique_ptr<ExpressionNode>> elements;
    explicit ListLiteralNode(std::vector<std::unique_ptr<ExpressionNode>> elements)
        : elements(std::move(elements)) {}
};

struct EmptyListNode : ExpressionNode {
    std::string elementTypeName;
    explicit EmptyListNode(std::string elementTypeName)
        : elementTypeName(std::move(elementTypeName)) {}
};

struct MapPairNode {
    std::unique_ptr<ExpressionNode> key;
    std::unique_ptr<ExpressionNode> value;
};

struct MapLiteralNode : ExpressionNode {
    std::vector<MapPairNode> pairs;
    explicit MapLiteralNode(std::vector<MapPairNode> pairs)
        : pairs(std::move(pairs)) {}
};

struct EmptyMapNode : ExpressionNode {
    std::string keyTypeName;
    std::string valueTypeName;

    EmptyMapNode(std::string keyTypeName, std::string valueTypeName)
        : keyTypeName(std::move(keyTypeName))
        , valueTypeName(std::move(valueTypeName)) {}
};

struct InterpolatedStringNode : ExpressionNode {
    std::vector<std::unique_ptr<ExpressionNode>> parts;
    explicit InterpolatedStringNode(std::vector<std::unique_ptr<ExpressionNode>> parts)
        : parts(std::move(parts)) {}
};

struct IndexExpressionNode : ExpressionNode {
    std::unique_ptr<ExpressionNode> object;
    std::unique_ptr<ExpressionNode> index;

    IndexExpressionNode(std::unique_ptr<ExpressionNode> object,
                        std::unique_ptr<ExpressionNode> index)
        : object(std::move(object)), index(std::move(index)) {}
};

struct LengthExpressionNode : ExpressionNode {
    std::unique_ptr<ExpressionNode> object;
    explicit LengthExpressionNode(std::unique_ptr<ExpressionNode> object)
        : object(std::move(object)) {}
};

// ── Statements ────────────────────────────────────────────────────────────────

struct SayStatementNode : StatementNode {
    std::unique_ptr<ExpressionNode> value;
    explicit SayStatementNode(std::unique_ptr<ExpressionNode> value)
        : value(std::move(value)) {}
};

struct AssignStatementNode : StatementNode {
    std::string name;
    std::string typeName;
    std::unique_ptr<ExpressionNode> value;
    bool isConst = false;

    AssignStatementNode(std::string name,
                        std::string typeName,
                        std::unique_ptr<ExpressionNode> value,
                        bool isConst = false)
        : name(std::move(name))
        , typeName(std::move(typeName))
        , value(std::move(value))
        , isConst(isConst) {}
};

struct SetStatementNode : StatementNode {
    std::unique_ptr<ExpressionNode> target;
    std::unique_ptr<ExpressionNode> value;

    SetStatementNode(std::unique_ptr<ExpressionNode> target,
                     std::unique_ptr<ExpressionNode> value)
        : target(std::move(target)), value(std::move(value)) {}
};

struct IndexAssignStatementNode : StatementNode {
    std::unique_ptr<ExpressionNode> object;
    std::unique_ptr<ExpressionNode> index;
    std::unique_ptr<ExpressionNode> value;

    IndexAssignStatementNode(std::unique_ptr<ExpressionNode> object,
                             std::unique_ptr<ExpressionNode> index,
                             std::unique_ptr<ExpressionNode> value)
        : object(std::move(object))
        , index(std::move(index))
        , value(std::move(value)) {}
};

struct AddToListStatementNode : StatementNode {
    std::unique_ptr<ExpressionNode> value;
    std::unique_ptr<ExpressionNode> list;

    AddToListStatementNode(std::unique_ptr<ExpressionNode> value,
                           std::unique_ptr<ExpressionNode> list)
        : value(std::move(value)), list(std::move(list)) {}
};

struct ReturnStatementNode : StatementNode {
    bool isError = false;
    std::unique_ptr<ExpressionNode> value;
    explicit ReturnStatementNode(std::unique_ptr<ExpressionNode> value, bool isError = false)
        : isError(isError), value(std::move(value)) {}
};

struct IfStatementNode : StatementNode {
    std::unique_ptr<ExpressionNode> condition;
    std::vector<std::unique_ptr<StatementNode>> thenBody;
    std::vector<std::unique_ptr<StatementNode>> elseBody;

    IfStatementNode(std::unique_ptr<ExpressionNode> condition,
                    std::vector<std::unique_ptr<StatementNode>> thenBody,
                    std::vector<std::unique_ptr<StatementNode>> elseBody = {})
        : condition(std::move(condition))
        , thenBody(std::move(thenBody))
        , elseBody(std::move(elseBody)) {}
};

struct WhileStatementNode : StatementNode {
    std::unique_ptr<ExpressionNode> condition;
    std::vector<std::unique_ptr<StatementNode>> body;

    WhileStatementNode(std::unique_ptr<ExpressionNode> condition,
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

struct ForEachStatementNode : StatementNode {
    std::string itemName;
    std::string valueName;
    std::unique_ptr<ExpressionNode> list;
    std::vector<std::unique_ptr<StatementNode>> body;

    ForEachStatementNode(std::string itemName,
                         std::string valueName,
                         std::unique_ptr<ExpressionNode> list,
                         std::vector<std::unique_ptr<StatementNode>> body)
        : itemName(std::move(itemName))
        , valueName(std::move(valueName))
        , list(std::move(list))
        , body(std::move(body)) {}
};

struct ForRangeStatementNode : StatementNode {
    std::string varName;
    std::unique_ptr<ExpressionNode> start;
    std::unique_ptr<ExpressionNode> end;
    std::unique_ptr<ExpressionNode> step;
    std::vector<std::unique_ptr<StatementNode>> body;

    ForRangeStatementNode(std::string varName,
                          std::unique_ptr<ExpressionNode> start,
                          std::unique_ptr<ExpressionNode> end,
                          std::unique_ptr<ExpressionNode> step,
                          std::vector<std::unique_ptr<StatementNode>> body)
        : varName(std::move(varName))
        , start(std::move(start))
        , end(std::move(end))
        , step(std::move(step))
        , body(std::move(body)) {}
};

struct BreakStatementNode : StatementNode {};
struct ContinueStatementNode : StatementNode {};

struct AskStatementNode : StatementNode {
    std::unique_ptr<ExpressionNode> prompt;
    std::string variableName;

    AskStatementNode(std::unique_ptr<ExpressionNode> prompt, std::string variableName)
        : prompt(std::move(prompt)), variableName(std::move(variableName)) {}
};

struct UseStatementNode : StatementNode {
    std::string moduleName;
    explicit UseStatementNode(std::string moduleName) : moduleName(std::move(moduleName)) {}
};

struct ExpressionStatementNode : StatementNode {
    std::unique_ptr<ExpressionNode> expression;
    explicit ExpressionStatementNode(std::unique_ptr<ExpressionNode> expression)
        : expression(std::move(expression)) {}
};

struct ExplainStatementNode : StatementNode {
    std::unique_ptr<StatementNode> statement;
    explicit ExplainStatementNode(std::unique_ptr<StatementNode> statement)
        : statement(std::move(statement)) {}
};

struct MatchArmNode {
    std::string caseName;
    bool isDefault = false;
    std::vector<std::unique_ptr<StatementNode>> body;
};

struct MatchStatementNode : StatementNode {
    std::unique_ptr<ExpressionNode> subject;
    std::vector<MatchArmNode> arms;

    MatchStatementNode(std::unique_ptr<ExpressionNode> subject,
                       std::vector<MatchArmNode> arms)
        : subject(std::move(subject)), arms(std::move(arms)) {}
};

struct AssertStatementNode : StatementNode {
    std::unique_ptr<ExpressionNode> condition;
    std::string label;

    AssertStatementNode(std::unique_ptr<ExpressionNode> condition, std::string label = "")
        : condition(std::move(condition)), label(std::move(label)) {}
};

struct TryStatementNode : StatementNode {
    std::vector<std::unique_ptr<StatementNode>> tryBody;
    std::string catchVarName;
    std::vector<std::unique_ptr<StatementNode>> catchBody;

    TryStatementNode(std::vector<std::unique_ptr<StatementNode>> tryBody,
                     std::string catchVarName,
                     std::vector<std::unique_ptr<StatementNode>> catchBody)
        : tryBody(std::move(tryBody))
        , catchVarName(std::move(catchVarName))
        , catchBody(std::move(catchBody)) {}
};

struct RaiseStatementNode : StatementNode {
    std::unique_ptr<ExpressionNode> message;
    explicit RaiseStatementNode(std::unique_ptr<ExpressionNode> message)
        : message(std::move(message)) {}
};

// ── Déclarations ─────────────────────────────────────────────────────────────

struct ParameterNode {
    std::string name;
    std::string typeName;
    std::unique_ptr<ExpressionNode> defaultValue;

    ParameterNode(std::string name, std::string typeName,
                  std::unique_ptr<ExpressionNode> defaultValue = nullptr)
        : name(std::move(name))
        , typeName(std::move(typeName))
        , defaultValue(std::move(defaultValue)) {}
};

struct LambdaExpressionNode : ExpressionNode {
    std::vector<ParameterNode> parameters;
    std::string returnTypeName;
    bool returnsResult = false;
    std::vector<std::unique_ptr<StatementNode>> body;

    LambdaExpressionNode(std::vector<ParameterNode> parameters,
                           std::string returnTypeName,
                           bool returnsResult,
                           std::vector<std::unique_ptr<StatementNode>> body)
        : parameters(std::move(parameters))
        , returnTypeName(std::move(returnTypeName))
        , returnsResult(returnsResult)
        , body(std::move(body)) {}
};

struct MapEachExpressionNode : ExpressionNode {
    std::string itemName;
    std::unique_ptr<ExpressionNode> list;
    std::vector<std::unique_ptr<StatementNode>> body;
    std::string elementTypeName;
    std::string resultElementTypeName;

    MapEachExpressionNode(std::string itemName,
                          std::unique_ptr<ExpressionNode> list,
                          std::vector<std::unique_ptr<StatementNode>> body)
        : itemName(std::move(itemName))
        , list(std::move(list))
        , body(std::move(body)) {}
};

struct FilterEachExpressionNode : ExpressionNode {
    std::string itemName;
    std::unique_ptr<ExpressionNode> list;
    std::unique_ptr<ExpressionNode> condition;
    std::string elementTypeName;

    FilterEachExpressionNode(std::string itemName,
                             std::unique_ptr<ExpressionNode> list,
                             std::unique_ptr<ExpressionNode> condition)
        : itemName(std::move(itemName))
        , list(std::move(list))
        , condition(std::move(condition)) {}
};

struct ReduceExpressionNode : ExpressionNode {
    std::unique_ptr<ExpressionNode> list;
    std::unique_ptr<ExpressionNode> initial;
    std::string accName;
    std::string itemName;
    std::vector<std::unique_ptr<StatementNode>> body;
    std::string elementTypeName;
    std::string resultTypeName;

    ReduceExpressionNode(std::unique_ptr<ExpressionNode> list,
                         std::unique_ptr<ExpressionNode> initial,
                         std::string accName,
                         std::string itemName,
                         std::vector<std::unique_ptr<StatementNode>> body)
        : list(std::move(list))
        , initial(std::move(initial))
        , accName(std::move(accName))
        , itemName(std::move(itemName))
        , body(std::move(body)) {}
};

enum class FieldVisibility { Public, Private, Protected };

struct FieldNode {
    std::string name;
    std::string typeName;
    FieldVisibility visibility = FieldVisibility::Public;
    bool isStatic = false;

    FieldNode(std::string name, std::string typeName,
              FieldVisibility visibility = FieldVisibility::Public,
              bool isStatic = false)
        : name(std::move(name))
        , typeName(std::move(typeName))
        , visibility(visibility)
        , isStatic(isStatic) {}
};

struct FunctionNode : ASTNode {
    std::string name;
    std::vector<std::string> typeParams;
    std::vector<ParameterNode> parameters;
    std::string returnTypeName;
    bool returnsResult = false;
    bool isStatic = false;
    bool isAbstract = false;
    std::vector<std::unique_ptr<StatementNode>> body;

    FunctionNode(std::string name,
                 std::vector<ParameterNode> parameters,
                 std::string returnTypeName,
                 bool returnsResult,
                 std::vector<std::unique_ptr<StatementNode>> body,
                 std::vector<std::string> typeParams = {},
                 bool isStatic = false,
                 bool isAbstract = false)
        : name(std::move(name))
        , typeParams(std::move(typeParams))
        , parameters(std::move(parameters))
        , returnTypeName(std::move(returnTypeName))
        , returnsResult(returnsResult)
        , isStatic(isStatic)
        , isAbstract(isAbstract)
        , body(std::move(body)) {}
};

struct InterfaceNode : ASTNode {
    std::string name;
    std::vector<std::unique_ptr<FunctionNode>> methods;

    InterfaceNode(std::string name, std::vector<std::unique_ptr<FunctionNode>> methods)
        : name(std::move(name)), methods(std::move(methods)) {}
};

struct TestNode : ASTNode {
    std::string name;
    std::vector<std::unique_ptr<StatementNode>> body;

    TestNode(std::string name, std::vector<std::unique_ptr<StatementNode>> body)
        : name(std::move(name)), body(std::move(body)) {}
};

struct ClassNode : ASTNode {
    std::string name;
    std::string baseClassName;
    std::vector<std::string> interfaceNames;
    std::vector<FieldNode> fields;
    std::vector<std::unique_ptr<FunctionNode>> methods;
    bool isAbstract = false;

    ClassNode(std::string name,
              std::string baseClassName,
              std::vector<std::string> interfaceNames,
              std::vector<FieldNode> fields,
              std::vector<std::unique_ptr<FunctionNode>> methods,
              bool isAbstract = false)
        : name(std::move(name))
        , baseClassName(std::move(baseClassName))
        , interfaceNames(std::move(interfaceNames))
        , fields(std::move(fields))
        , methods(std::move(methods))
        , isAbstract(isAbstract) {}
};

struct RecordNode : ASTNode {
    std::string name;
    std::vector<FieldNode> fields;

    RecordNode(std::string name, std::vector<FieldNode> fields)
        : name(std::move(name)), fields(std::move(fields)) {}
};

struct EnumCaseNode {
    std::string name;
    std::vector<FieldNode> fields;

    EnumCaseNode(std::string name, std::vector<FieldNode> fields = {})
        : name(std::move(name)), fields(std::move(fields)) {}
};

struct EnumNode : ASTNode {
    std::string name;
    std::vector<EnumCaseNode> cases;

    EnumNode(std::string name, std::vector<EnumCaseNode> cases)
        : name(std::move(name)), cases(std::move(cases)) {}
};

struct ModuleNode : ASTNode {
    std::string name;
    std::vector<std::unique_ptr<ClassNode>> classes;
    std::vector<std::unique_ptr<RecordNode>> records;
    std::vector<std::unique_ptr<FunctionNode>> functions;

    ModuleNode(std::string name,
               std::vector<std::unique_ptr<ClassNode>> classes,
               std::vector<std::unique_ptr<RecordNode>> records,
               std::vector<std::unique_ptr<FunctionNode>> functions)
        : name(std::move(name))
        , classes(std::move(classes))
        , records(std::move(records))
        , functions(std::move(functions)) {}
};

struct ImportNode : ASTNode {
    std::string path;
    explicit ImportNode(std::string path) : path(std::move(path)) {}
};

struct ExternDeclNode : ASTNode {
    std::string library;
    std::string name;
    std::vector<ParameterNode> parameters;
    std::string returnTypeName;

    ExternDeclNode(std::string library,
                   std::string name,
                   std::vector<ParameterNode> parameters,
                   std::string returnTypeName)
        : library(std::move(library))
        , name(std::move(name))
        , parameters(std::move(parameters))
        , returnTypeName(std::move(returnTypeName)) {}
};

struct ProgramNode : ASTNode {
    std::vector<std::unique_ptr<ImportNode>> imports;
    std::vector<std::unique_ptr<ModuleNode>> modules;
    std::vector<std::unique_ptr<InterfaceNode>> interfaces;
    std::vector<std::unique_ptr<RecordNode>> records;
    std::vector<std::unique_ptr<EnumNode>> enums;
    std::vector<std::unique_ptr<ClassNode>> classes;
    std::vector<std::unique_ptr<FunctionNode>> functions;
    std::vector<std::unique_ptr<TestNode>> tests;
    std::vector<std::unique_ptr<ExternDeclNode>> externs;
    std::vector<std::unique_ptr<StatementNode>> statements;

    ProgramNode(std::vector<std::unique_ptr<ImportNode>> imports,
                std::vector<std::unique_ptr<ModuleNode>> modules,
                std::vector<std::unique_ptr<InterfaceNode>> interfaces,
                std::vector<std::unique_ptr<RecordNode>> records,
                std::vector<std::unique_ptr<EnumNode>> enums,
                std::vector<std::unique_ptr<ClassNode>> classes,
                std::vector<std::unique_ptr<FunctionNode>> functions,
                std::vector<std::unique_ptr<TestNode>> tests,
                std::vector<std::unique_ptr<ExternDeclNode>> externs,
                std::vector<std::unique_ptr<StatementNode>> statements)
        : imports(std::move(imports))
        , modules(std::move(modules))
        , interfaces(std::move(interfaces))
        , records(std::move(records))
        , enums(std::move(enums))
        , classes(std::move(classes))
        , functions(std::move(functions))
        , tests(std::move(tests))
        , externs(std::move(externs))
        , statements(std::move(statements)) {}
};

} // namespace afrilang
